#!/usr/bin/env python3
"""Stage 2: extract MMIO register accesses from a MIPS disassembly.

Usage: scan.py CONFIG.json [--out DIR]

Input is the text objdump wrote in stage 1 (see disasm.sh), one file per image,
named in the config. The scan is a forward data-flow over each function's basic
blocks. A register holds one of:

  ('B', off, idx)  a pointer into the ASIC window: window base + off, plus an
                   unknown index when idx is true (array stride arithmetic)
  ('K', value)     a known constant (lui/ori/dli/daddiu chains)
  ('T',)           the chip-type discriminator the kernel loads from its own
                   record (config "discriminators.type")
  ('IDW',) ('PART',) the widget identification word, and the part number cut
                   out of it; comparing PART with a constant selects a variant

Every load/store whose base register holds B (or a K inside a configured
constant window) is one access site. Branches that compare the discriminator
with a constant refine the variant on the taken edge, so one accessor that
serves several chips gives each chip its own rows.

Nothing is guessed: a pointer that reaches a call the config does not seed is
written to unresolved.tsv with the site, and an index we cannot see is kept as
idx=1 with the constant part only.
"""
import argparse
import collections
import json
import os
import re
import sys

M64 = (1 << 64) - 1
STATE_CAP = 48

FUNC_RE = re.compile(r'^([0-9a-f]+) <(.+)>:$')
INSN_RE = re.compile(r'^\s*([0-9a-f]+):\t(\S+)(?:\t(.*))?$')
MEM_RE = re.compile(r'^(-?(?:0x[0-9a-f]+|\d+))\((\$\d+)\)$')

LOADS = {'lb': 1, 'lbu': 1, 'lh': 2, 'lhu': 2, 'lw': 4, 'lwu': 4, 'ld': 8, 'll': 4, 'lld': 8,
         'lwl': 4, 'lwr': 4, 'ldl': 8, 'ldr': 8, 'lwc1': 4, 'ldc1': 8}
STORES = {'sb': 1, 'sh': 2, 'sw': 4, 'sd': 8, 'sc': 4, 'scd': 8, 'swl': 4, 'swr': 4, 'sdl': 8,
          'sdr': 8, 'swc1': 4, 'sdc1': 8}
PARTIAL = {'lwl', 'lwr', 'ldl', 'ldr', 'swl', 'swr', 'sdl', 'sdr'}
RD_WRITERS = {'add', 'addu', 'sub', 'subu', 'and', 'or', 'xor', 'nor', 'slt', 'sltu', 'dadd', 'daddu',
              'dsub', 'dsubu', 'dsllv', 'dsrlv', 'dsrav', 'sllv', 'srlv', 'srav', 'mfhi', 'mflo',
              'movz', 'movn', 'mul', 'sll', 'srl', 'sra', 'dsll', 'dsrl', 'dsra', 'dsll32',
              'dsrl32', 'dsra32', 'jalr', 'dmul', 'dmulu', 'dsllv'}
RT_WRITERS = {'addi', 'addiu', 'daddi', 'daddiu', 'slti', 'sltiu', 'andi', 'ori', 'xori', 'lui', 'mfc0',
              'dmfc0', 'mfc1', 'dmfc1', 'cfc1', 'sc', 'scd', 'dli', 'li'} | set(LOADS) - {'lwc1', 'ldc1'}
CALLER_SAVED = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25]
COND = {'beq', 'bne', 'beql', 'bnel', 'blez', 'bgtz', 'bltz', 'bgez', 'blezl', 'bgtzl', 'bltzl',
        'bgezl', 'bc1t', 'bc1f', 'bc1tl', 'bc1fl', 'bltzal', 'bgezal', 'bltzall', 'bgezall'}
LIKELY = {'beql', 'bnel', 'blezl', 'bgtzl', 'bltzl', 'bgezl', 'bc1tl', 'bc1fl', 'bltzall', 'bgezall'}
UNCOND = {'b', 'j', 'jr'}
CALLS = {'jal', 'jalr', 'bal', 'bltzal', 'bgezal', 'bltzall', 'bgezall'}


def to_int(s):
    return int(s, 0)


def sx32(v):
    v &= 0xffffffff
    return v - (1 << 32) if v & 0x80000000 else v


def parse_ops(text):
    text = (text or '').split('#')[0]
    sym = None
    m = re.search(r'<([^>+]+)(?:\+0x[0-9a-f]+)?>', text)
    if m:
        sym = m.group(1)
    text = re.sub(r'\s*<[^>]*>', '', text).strip()
    return [o.strip() for o in text.split(',')] if text else [], sym


def reg(o):
    return int(o[1:]) if o and o.startswith('$') and o[1:].isdigit() else None


RELOC_RE = re.compile(r'^\s+([0-9a-f]+):\s+(R_MIPS_\w+)\s+(\S+)')


class Insn:
    __slots__ = ('addr', 'mn', 'ops', 'sym', 'reloc')

    def __init__(self, addr, mn, ops, sym):
        self.addr, self.mn, self.ops, self.sym = addr, mn, ops, sym
        self.reloc = None

    def target(self):
        for o in reversed(self.ops):
            if re.fullmatch(r'(?:0x)?[0-9a-f]{6,16}', o) and self.mn not in LOADS and self.mn not in STORES \
                    and self.mn not in ('lui', 'dli', 'li', 'ori', 'andi', 'daddiu', 'addiu'):
                return int(o, 16)
        return None


def read_functions(path, split=None):
    """[(name, start, [Insn])]. A raw image has no symbols: split='jr31' starts a new
    pseudo-function after every return and its delay slot, named prom_<address>."""
    funcs = []
    cur = None
    since_ret = None
    with open(path, encoding='utf-8', errors='replace') as f:
        for ln in f:
            ln = ln.rstrip('\n')
            m = FUNC_RE.match(ln)
            if m:
                if split:
                    continue
                cur = (m.group(2), int(m.group(1), 16), [])
                funcs.append(cur)
                continue
            m = RELOC_RE.match(ln)
            if m:
                # relocatable object: the symbol a call or an address half names
                prev = (cur[2][-1] if cur and cur[2] else None)
                if prev is not None and prev.addr == int(m.group(1), 16) and m.group(2) != 'R_MIPS_NONE':
                    prev.reloc = m.group(2)
                    prev.sym = re.sub(r'[+-]0x[0-9a-f]+$', '', m.group(3))
                continue
            m = INSN_RE.match(ln)
            if not m:
                continue
            ops, sym = parse_ops(m.group(3))
            ins = Insn(int(m.group(1), 16), m.group(2), ops, sym)
            if split:
                if cur is None or since_ret == 2:
                    cur = ('prom_%x' % ins.addr, ins.addr, [])
                    funcs.append(cur)
                    since_ret = None
                if ins.mn == 'jr' and ops == ['$31']:
                    since_ret = 0
                if since_ret is not None:
                    since_ret += 1
                cur[2].append(ins)
            elif cur is not None:
                cur[2].append(ins)
    return funcs


def load_literals(path):
    """{address: bytes} from `objdump -s` text for read-only literal sections."""
    mem = {}
    if not path or not os.path.exists(path):
        return mem
    for ln in open(path, encoding='utf-8', errors='replace'):
        m = re.match(r'^ ([0-9a-f]+) ((?:[0-9a-f]{1,8} ?){1,4})', ln)
        if m:
            a = int(m.group(1), 16)
            for part in m.group(2).split():
                b = bytes.fromhex(part.rjust(8, '0')) if len(part) == 8 else bytes.fromhex(part)
                if len(part) == 8:
                    for k in range(4):
                        mem[a + k] = b[k]
                a += 4
    return mem


class Config:
    def __init__(self, path):
        self.raw = json.load(open(path))
        c = self.raw
        self.asic = c['asic']
        self.seed_args = [(re.compile(s['functions']), int(s['reg']), s.get('off', 0))
                          for s in c.get('seeds', {}).get('args', [])]
        self.seed_calls = [(s['callee'], re.compile(s.get('in', '.*')), s.get('off_arg'))
                           for s in c.get('seeds', {}).get('calls', [])]
        self.seed_returns = {s['callee']: s.get('off', 0) for s in c.get('seeds', {}).get('returns', [])}
        self.field_rules = [dict(r, _fn=re.compile(r['functions'])) for r in c.get('field_rules', [])]
        d = c.get('discriminators', {})
        self.type_disc = d.get('type')
        self.part_disc = d.get('part')
        v = c.get('variants', {})
        self.type_variants = {int(k): n for k, n in v.get('type', {}).items()}
        self.part_variants = {to_int(k): n for k, n in v.get('part', {}).items()}
        self.report_fn = re.compile(c.get('report_functions', '.*'))
        self.probe = c.get('seeds', {}).get('probe')
        ac = c.get('accessor_calls')
        self.accessor_calls = re.compile(ac) if ac else None
        self.suspect_range = tuple(to_int(x) for x in c.get('suspect_range', ['0x100', '0x300']))
        self.type_const_in = re.compile(c.get('type_const_in', '$^'))


class Analyser:
    def __init__(self, cfg, label, windows=(), hint=None, gp=None, literals=None):
        self.cfg, self.label, self.hint = cfg, label, hint
        self.gp = gp
        self.lit = literals or {}
        self.windows = [(to_int(w['lo']), to_int(w['hi']), w['name']) for w in windows]
        self.sites = []
        self.calls = []
        self.suspects = []
        self.unres = []
        self.stats = collections.Counter()

    # ---- state helpers -------------------------------------------------
    @staticmethod
    def rd(st, r):
        if r == 0:
            return ('K', 0)
        return st.get(r)

    @staticmethod
    def wr(st, r, v):
        if r is None or r == 0:
            return
        if v is None:
            st.pop(r, None)
        else:
            st[r] = v

    def dest_of(self, ins):
        mn, ops = ins.mn, ins.ops
        if mn in RD_WRITERS and ops:
            if mn == 'jalr':
                return 31 if len(ops) == 1 else reg(ops[0])
            return reg(ops[0])
        if mn in RT_WRITERS and ops:
            return reg(ops[0])
        return None

    # ---- transfer function ----------------------------------------------
    def step(self, fn, ins, st, record):
        cfg = self.cfg
        mn, ops = ins.mn, ins.ops
        if mn in LOADS or mn in STORES:
            m = MEM_RE.match(ops[1]) if len(ops) == 2 else None
            if not m:
                return
            disp, base = to_int(m.group(1)), int(m.group(2)[1:])
            bv = self.rd(st, base)
            rt = reg(ops[0])
            if base == 28 and mn in ('ld', 'lw', 'lwu') and self.gp is not None and self.lit:
                n = 8 if mn == 'ld' else 4
                a = self.gp + disp
                if all((a + k) in self.lit for k in range(n)):
                    val = int.from_bytes(bytes(self.lit[a + k] for k in range(n)), 'big')
                    if mn == 'lw':
                        val = sx32(val) & M64
                    self.wr(st, rt, ('K', val))
                    return
            if base == 29:
                key = 'S%d' % disp
                if mn in STORES:
                    v = self.rd(st, rt)
                    if v is not None and mn in ('sd', 'sw') and v[0] in ('B', 'K', 'T', 'KI'):
                        st[key] = v
                    else:
                        st.pop(key, None)
                else:
                    self.wr(st, rt, st.get(key) if mn in ('ld', 'lw') else None)
                return
            # field rules: a load of a record field that holds a pointer or a discriminator
            if mn in LOADS and bv is not None and bv[0] == 'B' and not bv[2]:
                for r in cfg.field_rules:
                    if r['_fn'].search(fn) and r['load'] == mn and r['disp'] == disp and bv[1] == r.get('base_off', 0):
                        if r['kind'] == 'pointer':
                            self.wr(st, rt, ('B', r.get('off', 0), False))
                        elif r['kind'] == 'type':
                            self.wr(st, rt, ('T',))
                        else:
                            self.wr(st, rt, None)
                        return
            if bv is not None and bv[0] == 'B':
                off = bv[1] + disp
                if record:
                    self.record(fn, ins, mn, off, bv[2], st, 'window')
                if mn in LOADS:
                    nv = None
                    c = cfg.part_disc
                    if c and mn == 'lw' and off == c['id_disp'] and not bv[2]:
                        nv = ('IDW',)
                    self.wr(st, rt, nv)
                return
            if bv is not None and bv[0] == 'KI' and self.windows:
                addr = (bv[1] + disp) & M64
                hit = self.window_of(bv[1])
                if hit:
                    if record:
                        self.record(fn, ins, mn, addr - hit[0], True, st, hit[2])
                    if mn in LOADS:
                        self.wr(st, rt, None)
                    return
            if bv is not None and bv[0] == 'K' and self.windows:
                addr = (bv[1] + disp) & M64
                for lo, hi, name in self.windows:
                    if lo <= addr < hi:
                        if record:
                            self.record(fn, ins, mn, addr - lo, False, st, name)
                        break
            if record and bv is None and base not in (28, 29) and cfg.report_fn.search(fn):
                lo, hi = cfg.suspect_range
                if lo <= disp < hi and (disp & 7) in (0, 4):
                    self.suspects.append({'image': self.label, 'function': fn, 'addr': '%x' % ins.addr,
                                          'insn': mn, 'disp': disp, 'base': '$%d' % base})
            if mn in LOADS:
                self.wr(st, rt, None)
            return

        rdv = self.rd
        if ins.reloc and ins.reloc != 'R_MIPS_26':
            # an immediate the linker fills in: not a value we know
            d = self.dest_of(ins)
            if d is not None:
                self.wr(st, d, None)
            return
        if mn == 'lui' and len(ops) == 2:
            self.wr(st, reg(ops[0]), ('K', (sx32(to_int(ops[1]) << 16)) & M64))
        elif mn in ('dli', 'li') and len(ops) == 2:
            self.wr(st, reg(ops[0]), ('K', to_int(ops[1]) & M64))
        elif mn in ('addiu', 'daddiu', 'addi', 'daddi') and len(ops) == 3:
            s, imm = rdv(st, reg(ops[1])), to_int(ops[2])
            if reg(ops[1]) == 29:
                v = None
            elif s and s[0] == 'K':
                v = ('K', (s[1] + imm) & M64)
                if mn in ('addiu', 'addi'):
                    v = ('K', sx32(s[1] + imm) & M64)
            elif s and s[0] == 'B' and mn in ('daddiu', 'daddi'):
                v = ('B', s[1] + imm, s[2])
            else:
                v = None
            self.wr(st, reg(ops[0]), v)
        elif mn == 'ori' and len(ops) == 3:
            s = rdv(st, reg(ops[1]))
            self.wr(st, reg(ops[0]), ('K', s[1] | to_int(ops[2])) if s and s[0] == 'K' else None)
        elif mn == 'andi' and len(ops) == 3:
            s = rdv(st, reg(ops[1]))
            c = self.cfg.part_disc
            if s and s[0] == 'PART' and c and to_int(ops[2]) == to_int(c.get('mask', '0xffff')):
                v = ('PART',)
            elif s and s[0] == 'K':
                v = ('K', s[1] & to_int(ops[2]))
            else:
                v = None
            self.wr(st, reg(ops[0]), v)
        elif mn in ('or', 'addu', 'daddu') and len(ops) == 3:
            a, b = rdv(st, reg(ops[1])), rdv(st, reg(ops[2]))
            if mn == 'or' and reg(ops[2]) == 0:
                v = a
            elif mn == 'or' and reg(ops[1]) == 0:
                v = b
            elif mn in ('addu', 'daddu') and reg(ops[2]) == 0:
                v = a
            elif a and b and a[0] == 'K' and b[0] == 'K' and mn != 'or':
                v = ('K', (a[1] + b[1]) & M64)
            elif mn == 'daddu' and a and a[0] == 'B' and b and b[0] == 'K':
                v = ('B', a[1] + b[1], a[2])
            elif mn == 'daddu' and b and b[0] == 'B' and a and a[0] == 'K':
                v = ('B', b[1] + a[1], b[2])
            elif mn == 'daddu' and a and a[0] == 'K' and not (b and b[0] in ('K', 'B')) and reg(ops[2]) not in (29, 28) \
                    and self.window_of(a[1]):
                v = ('KI', a[1])        # a window constant plus an index (node number, array slot)
            elif mn == 'daddu' and b and b[0] == 'K' and not (a and a[0] in ('K', 'B')) and reg(ops[1]) not in (29, 28) \
                    and self.window_of(b[1]):
                v = ('KI', b[1])
            elif mn == 'daddu' and a and a[0] == 'B' and not (b and b[0] == 'B') and reg(ops[2]) not in (29, 28):
                v = ('B', a[1], True)
            elif mn == 'daddu' and b and b[0] == 'B' and not (a and a[0] == 'B') and reg(ops[1]) not in (29, 28):
                v = ('B', b[1], True)
            else:
                v = None
            self.wr(st, reg(ops[0]), v)
        elif mn == 'dsubu' and len(ops) == 3:
            a, b = rdv(st, reg(ops[1])), rdv(st, reg(ops[2]))
            if a and b and a[0] == 'K' and b[0] == 'K':
                v = ('K', (a[1] - b[1]) & M64)
            elif a and a[0] == 'B' and b and b[0] == 'K':
                v = ('B', a[1] - b[1], a[2])
            else:
                v = None
            self.wr(st, reg(ops[0]), v)
        elif mn in ('sll', 'srl', 'sra', 'dsll', 'dsrl', 'dsra', 'dsll32', 'dsrl32', 'dsra32') and len(ops) == 3:
            s, sh = rdv(st, reg(ops[1])), to_int(ops[2])
            v = None
            if s and s[0] == 'K':
                x = s[1]
                if mn == 'sll':
                    v = ('K', sx32(x << sh) & M64)
                elif mn == 'srl':
                    v = ('K', sx32((x & 0xffffffff) >> sh) & M64)
                elif mn == 'dsll':
                    v = ('K', (x << sh) & M64)
                elif mn == 'dsll32':
                    v = ('K', (x << (sh + 32)) & M64)
                elif mn == 'dsrl':
                    v = ('K', x >> sh)
                elif mn == 'dsrl32':
                    v = ('K', x >> (sh + 32))
            elif s and s[0] == 'IDW' and mn == 'srl' and self.cfg.part_disc and sh == self.cfg.part_disc.get('shift', 12):
                v = ('PART',)
            self.wr(st, reg(ops[0]), v)
        else:
            d = self.dest_of(ins)
            if d is not None:
                self.wr(st, d, None)

    def record(self, fn, ins, mn, off, idx, st, window):
        w = LOADS.get(mn) or STORES.get(mn)
        variant = self.variant(st)
        basis = 'refined' if variant != '?' else 'direct'
        if variant == '?' and self.hint:
            variant, basis = self.hint, 'image-hint'
        if getattr(self, 'auto', None) and not any(rx.search(fn) for rx, _, _ in self.cfg.seed_args):
            basis = 'probe-seed'
            if variant == '?':
                variant = 'probe?'      # window pointer guessed from an identity probe, chip unknown
        self.sites.append({
            'image': self.label, 'function': fn, 'addr': '%x' % ins.addr, 'insn': mn,
            'rw': 'r' if mn in LOADS else 'w', 'width': w, 'partial': int(mn in PARTIAL),
            'window': window, 'offset': off, 'idx': int(bool(idx)), 'variant': variant,
            'basis': basis,
        })

    def window_of(self, addr):
        for lo, hi, name in self.windows:
            if lo <= addr < hi:
                return (lo, hi, name)
        return None

    def record_addr(self, fn, ins, v, st):
        """The function hands back a pointer into the window: its offset is a register this
        ASIC exposes, reached through the caller. Kept as an access of kind 'a'."""
        if v[1] == 0:
            self.stats['returned_base_pointers'] += 1
            return
        variant = self.variant(st)
        basis = 'returned-pointer'
        if variant == '?' and self.hint:
            variant = self.hint
        self.sites.append({
            'image': self.label, 'function': fn, 'addr': '%x' % ins.addr, 'insn': 'ret-addr', 'rw': 'a',
            'width': 0, 'partial': 0, 'window': 'window', 'offset': v[1], 'idx': int(bool(v[2])),
            'variant': variant, 'basis': basis})

    def variant(self, st):
        v = st.get('@v')
        return '|'.join(sorted(v)) if v else '?'

    # ---- one function ------------------------------------------------------
    def entry_state(self, fn):
        st = {}
        for rx, r, off in self.cfg.seed_args:
            if rx.search(fn):
                st[r] = ('B', off, False)
        for r, v in getattr(self, 'auto', {}).items():
            st.setdefault(r, v)
        return st

    @staticmethod
    def join(a, b):
        if a is None:
            return dict(b)
        out = {k: v for k, v in a.items() if b.get(k) == v}
        # a null pointer on the error path that rejoins the main flow does not make the
        # pointer unknown: the access still happens only on the non-null path
        for k, v in a.items():
            w = b.get(k)
            if isinstance(k, int) and v != w and v and w:
                if v[0] == 'B' and w == ('K', 0):
                    out[k] = v
                elif w[0] == 'B' and v == ('K', 0):
                    out[k] = w
        # variants merge as a union: a block two dispatch paths share belongs to both
        if '@v' in a and '@v' in b:
            out['@v'] = a['@v'] | b['@v']
        return out

    def probe_seeds(self, insns):
        """Registers that hold a widget base on entry, found from the identification probe the
        driver makes before anything else: `lw X,4(Y)` then `srl Z,X,12`, with Y never written in
        the function. Y is then the caller's window pointer. Used where no accessor name seeds it."""
        pr = self.cfg.probe
        if not pr:
            return {}
        written = set()
        for i in insns:
            d = self.dest_of(i)
            if d is not None:
                written.add(d)
        out = {}
        for k, i in enumerate(insns):
            if i.mn == 'lw' and len(i.ops) == 2:
                m = MEM_RE.match(i.ops[1])
                if m and to_int(m.group(1)) == pr.get('disp', 4):
                    y, x = int(m.group(2)[1:]), reg(i.ops[0])
                    if y in (0, 28, 29) or y in written:
                        continue
                    for n in insns[k + 1:k + 4]:
                        if n.mn == 'srl' and len(n.ops) == 3 and reg(n.ops[1]) == x and to_int(n.ops[2]) == pr.get('shift', 12):
                            out[y] = ('B', 0, False)
        return out

    def relevant(self, name, insns):
        cfg = self.cfg
        self.auto = self.probe_seeds(insns)
        if self.auto:
            return True
        if cfg.accessor_calls and any(i.sym and cfg.accessor_calls.search(i.sym) for i in insns):
            return True
        if any(rx.search(name) for rx, _, _ in cfg.seed_args):
            return True
        callees = {c for c, rx, _ in cfg.seed_calls if rx.search(name)} | set(cfg.seed_returns)
        if callees and any(i.sym in callees for i in insns):
            return True
        if self.windows and self.lit:
            for i in insns:
                if i.mn in ('ld', 'lw') and len(i.ops) == 2 and i.ops[1].endswith('($28)'):
                    return True
        if self.windows:
            for i in insns:
                if i.mn in ('lui', 'dli', 'li') and len(i.ops) == 2:
                    try:
                        v = to_int(i.ops[1]) << (16 if i.mn == 'lui' else 0)
                    except ValueError:
                        continue
                    v &= M64
                    if i.mn == 'lui':
                        v = sx32(v) & M64
                    for lo, hi, _ in self.windows:
                        # a constant built in pieces first shows its top half in a lui or dli
                        if (lo >> 16) <= (v >> 16) <= (hi >> 16) or (lo >> 32) == (v >> 32) and v != 0:
                            return True
        return False

    def analyse(self, name, start, insns, record_fn):
        self.cur_fn = name
        if not self.relevant(name, insns):
            return
        n = len(insns)
        if n == 0:
            return
        index = {ins.addr: i for i, ins in enumerate(insns)}
        leaders = {0}
        for i, ins in enumerate(insns):
            mn = ins.mn
            if mn in COND or mn in UNCOND or mn in CALLS:
                if mn in CALLS and mn not in COND:
                    continue
                leaders.add(i + 2)
                t = ins.target() if mn not in ('jr',) else None
                if t is not None and t in index:
                    leaders.add(index[t])
        starts = sorted(x for x in leaders if x < n)
        blocks = [(s, starts[k + 1] if k + 1 < len(starts) else n) for k, s in enumerate(starts)]
        bidx = {s: k for k, (s, e) in enumerate(blocks)}
        # Path-sensitive: each block keeps the distinct states that reach it, so the chip-type
        # dispatch of an accessor is followed down each of its paths. Past STATE_CAP states a
        # block falls back to the intersection of all of them.
        IN = [dict() for _ in blocks]
        e0 = self.entry_state(name)
        IN[0][self.key(e0)] = e0
        work = [(0, e0)]
        steps = 0
        while work and steps < 40000:
            steps += 1
            k, st0 = work.pop()
            for succ, st in self.run_block(name, insns, blocks[k], index, bidx, dict(st0), False):
                key = self.key(st)
                tab = IN[succ]
                if key in tab:
                    continue
                if len(tab) >= STATE_CAP:
                    merged = st
                    for o in tab.values():
                        merged = self.join(merged, o)
                    self.stats['capped_blocks'] += 1
                    tab.clear()
                    tab[self.key(merged)] = merged
                    work.append((succ, merged))
                    continue
                tab[key] = st
                work.append((succ, st))
        if not record_fn:
            return
        seen = set()
        for k, (s, e) in enumerate(blocks):
            states = list(IN[k].values())
            if not states:
                states = [self.entry_state(name)]
                if self.cfg.report_fn.search(name):
                    self.stats['orphan_blocks'] += 1
            for st in states:
                n0 = len(self.sites)
                self.run_block(name, insns, (s, e), index, bidx, dict(st), True)
                # one site per instruction, offset and variant however many paths reach it
                keep = []
                for site in self.sites[n0:]:
                    sk = (site['addr'], site['offset'], site['idx'], site['variant'], site['rw'])
                    if sk not in seen:
                        seen.add(sk)
                        keep.append(site)
                self.sites[n0:] = keep

    @staticmethod
    def key(st):
        return tuple(sorted((str(k), repr(sorted(v)) if isinstance(v, frozenset) else repr(v)) for k, v in st.items()))

    def run_block(self, fn, insns, blk, index, bidx, st, record):
        s, e = blk
        succs = []
        i = s
        while i < e:
            ins = insns[i]
            mn = ins.mn
            if mn in COND or mn in UNCOND or mn in CALLS:
                delay = insns[i + 1] if i + 1 < len(insns) else None
                if mn in CALLS and mn not in COND:
                    # call: arguments are read before the delay slot runs
                    if delay is not None:
                        self.step(fn, delay, st, record)
                    self.argsnap = {r: st.get(r) for r in range(4, 12)}
                    self.cur_fn = fn
                    if record:
                        self.note_call(fn, ins, st)
                    self.after_call(ins, st)
                    i += 2
                    continue
                ops = ins.ops
                pre = dict(st)
                taken, fall = self.refine(ins, pre)
                if delay is not None:
                    if mn in LIKELY:
                        if taken is not None:
                            tmp = dict(taken)
                            self.step(fn, delay, tmp, record)
                            taken = tmp
                        # the delay slot is annulled on the fall edge
                    else:
                        live = taken if taken is not None else fall
                        self.step(fn, delay, live, record)
                        if taken is not None and fall is not None:
                            self.step(fn, delay, fall, False)
                t = ins.target()
                if mn in ('b', 'j') or (mn in ('beq', 'beql') and ops[0] == ops[1]) or \
                        (mn in ('bgez', 'bgezl') and ops[0] == '$0'):
                    if t is not None and t in index and index[t] in bidx:
                        succs.append((bidx[index[t]], taken))
                    return succs
                if mn == 'jr':
                    if record and ops == ['$31']:
                        v = st.get(2) if delay is None else (taken or fall or st).get(2)
                        if v and v[0] == 'B':
                            self.record_addr(fn, ins, v, taken or fall or st)
                    return succs
                if taken is not None and t is not None and t in index and index[t] in bidx:
                    succs.append((bidx[index[t]], taken))
                if fall is not None and i + 2 < len(insns) and (i + 2) in bidx:
                    succs.append((bidx[i + 2], fall))
                return succs
            self.step(fn, ins, st, record)
            i += 1
        if e in bidx:
            succs.append((bidx[e], st))
        return succs

    def refine(self, ins, st):
        taken, fall = dict(st), dict(st)
        mn, ops = ins.mn, ins.ops
        if mn in ('beq', 'bne', 'beql', 'bnel') and len(ops) >= 3:
            a, b = self.rd(st, reg(ops[0])), self.rd(st, reg(ops[1]))
            if a and b and a[0] == 'K' and b[0] == 'K':
                same = (a[1] & M64) == (b[1] & M64)
                if same and ops[0] != ops[1] and self.cfg.type_const_in.search(self.cur_fn) and sx64(a[1]) in self.cfg.type_variants:
                    # the part-number path ended by loading the type as a constant; the compare
                    # chain that follows then names the variant just as a loaded type would
                    lab = frozenset([self.cfg.type_variants[sx64(a[1])]])
                    (taken if mn in ('beq', 'beql') else fall)['@v'] = lab
                if (mn in ('beq', 'beql')) == same:
                    return taken, None     # always taken: the fall-through edge cannot happen
                return None, fall          # never taken
            for x, y in ((a, b), (b, a)):
                if x and y and y[0] == 'K':
                    key = {'T': '@type', 'PART': '@part'}.get(x[0])
                    if key:
                        val = y[1] if key == '@part' else sx64(y[1])
                        names = self.cfg.part_variants if key == '@part' else self.cfg.type_variants
                        label = names.get(val, 'other(%s=%s)' % (key[1:], hex(val) if key == '@part' else val))
                        (taken if mn in ('beq', 'beql') else fall)['@v'] = frozenset([label])
                        break
        return taken, fall

    def note_call(self, fn, ins, st):
        cfg = self.cfg
        if cfg.accessor_calls and ins.sym and cfg.accessor_calls.search(ins.sym):
            args = []
            for r in range(5, 9):          # a1..a4: a0 is the window pointer
                v = st.get(r)
                args.append(hex(v[1]) if v and v[0] == 'K' else '-')
            self.calls.append({'image': self.label, 'caller': fn, 'addr': '%x' % ins.addr,
                               'callee': ins.sym, 'a1': args[0], 'a2': args[1], 'a3': args[2], 'a4': args[3]})
        if not cfg.report_fn.search(fn):
            return
        for r in range(4, 12):
            v = st.get(r)
            if v and v[0] == 'B' and ins.sym not in self.known_callees and ins.sym not in cfg.raw.get('no_pointer_args', []):
                self.unres.append({'image': self.label, 'function': fn, 'addr': '%x' % ins.addr,
                                   'callee': ins.sym or '(indirect)', 'arg': 'a%d' % (r - 4),
                                   'offset': v[1], 'idx': int(v[2]), 'why': 'window pointer passed to unseeded callee'})

    def after_call(self, ins, st):
        cfg = self.cfg
        callee = ins.sym
        for r in CALLER_SAVED:
            st.pop(r, None)
        st.pop(31, None)
        if callee in cfg.seed_returns:
            st[2] = ('B', cfg.seed_returns[callee], False)
        for cal, rx, off_arg in cfg.seed_calls:
            if callee == cal and rx.search(self.cur_fn):
                off = 0
                if off_arg:
                    # the offset argument as it stood at the call; unknown means we only know the base
                    v = self.argsnap.get(off_arg)
                    off = v[1] if v and v[0] == 'K' else 0
                st[2] = ('B', off, False)

    known_callees = set()
    cur_fn = ''
    argsnap = {}


def sx64(v):
    v &= M64
    return v - (1 << 64) if v & (1 << 63) else v


def run(cfg, base, outdir):
    sites, unres, scope = [], [], []
    stats = collections.Counter()
    run.scope = scope
    run.calls = []
    run.suspects = []
    for img in cfg.raw['images']:
        path = os.path.join(base, img['dis'])
        funcs = read_functions(path, img.get('split'))
        gp = to_int(img['gp']) if img.get('gp') else None
        lits = load_literals(os.path.join(base, img['literals'])) if img.get('literals') else None
        an = Analyser(cfg, img['label'], img.get('const_windows', []), img.get('variant_hint'), gp, lits)
        an.known_callees = set(f[0] for f in funcs if any(rx.search(f[0]) for rx, _, _ in cfg.seed_args))
        for name, start, insns in funcs:
            an.analyse(name, start, insns, True)
        got = collections.Counter(x['function'] for x in an.sites)
        for name, _, insns in funcs:
            if any(rx.search(name) for rx, _, _ in cfg.seed_args):
                scope.append({'image': img['label'], 'function': name, 'sites': got.get(name, 0),
                              'insns': len(insns)})
        seen_u = set()
        for u in an.unres:
            k = (u['image'], u['function'], u['addr'], u['callee'], u['arg'])
            if k not in seen_u:
                seen_u.add(k)
                unres.append(u)
        sites += an.sites
        seen_c = set()
        for u in an.calls:
            k = (u['image'], u['addr'], u['a1'], u['a2'], u['a3'])
            if k not in seen_c:
                seen_c.add(k)
                run.calls.append(u)
        seen_s = set()
        for u in an.suspects:
            k = (u['image'], u['addr'])
            if k not in seen_s:
                seen_s.add(k)
                run.suspects.append(u)
        stats[img['label'] + ':functions'] = len(funcs)
        stats[img['label'] + ':sites'] = len(an.sites)
        stats[img['label'] + ':orphan_blocks'] = an.stats['orphan_blocks']
    return sites, unres, stats


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('config')
    ap.add_argument('--base', default=os.getcwd())
    ap.add_argument('--out', default=None)
    a = ap.parse_args()
    cfg = Config(a.config)
    out = a.out or os.path.join(a.base, 'work', cfg.asic)
    os.makedirs(out, exist_ok=True)
    sites, unres, stats = run(cfg, a.base, out)
    cols = ['image', 'function', 'addr', 'insn', 'rw', 'width', 'partial', 'window', 'offset', 'idx', 'variant', 'basis']
    with open(os.path.join(out, 'sites.tsv'), 'w') as f:
        f.write('\t'.join(cols) + '\n')
        for s in sites:
            s = dict(s)
            s['offset'] = '0x%x' % s['offset'] if s['offset'] >= 0 else '-0x%x' % -s['offset']
            f.write('\t'.join(str(s[c]) for c in cols) + '\n')
    ucols = ['image', 'function', 'addr', 'callee', 'arg', 'offset', 'idx', 'why']
    with open(os.path.join(out, 'unresolved.tsv'), 'w') as f:
        f.write('\t'.join(ucols) + '\n')
        for u in unres:
            u = dict(u)
            u['offset'] = hex(u['offset'])
            f.write('\t'.join(str(u[c]) for c in ucols) + '\n')
    with open(os.path.join(out, 'accessor-calls.tsv'), 'w') as f:
        f.write('image\tcaller\taddr\tcallee\ta1\ta2\ta3\ta4\n')
        for r in run.calls:
            f.write('\t'.join(r[k] for k in ('image', 'caller', 'addr', 'callee', 'a1', 'a2', 'a3', 'a4')) + '\n')
    with open(os.path.join(out, 'suspects.tsv'), 'w') as f:
        f.write('image\tfunction\taddr\tinsn\tdisp\tbase\n')
        for r in run.suspects:
            f.write('%s\t%s\t%s\t%s\t%#x\t%s\n' % (r['image'], r['function'], r['addr'], r['insn'], r['disp'], r['base']))
    with open(os.path.join(out, 'scope.tsv'), 'w') as f:
        f.write('image\tfunction\tsites\tinsns\n')
        for r in run.scope:
            f.write('%s\t%s\t%d\t%d\n' % (r['image'], r['function'], r['sites'], r['insns']))
    json.dump(dict(stats), open(os.path.join(out, 'scan-stats.json'), 'w'), indent=1)
    print(json.dumps(dict(stats)))


if __name__ == '__main__':
    main()
