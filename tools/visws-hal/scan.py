#!/usr/bin/env python3
"""Disassembly-level facts and function matching for x86 PE HALs.

    scan.py facts IMAGE EXPORT.json            fs: offsets, pointer stores, imports used per function
    scan.py fp    IMAGE EXPORT.json OUT.json   per-function shape fingerprints (input to match)
    scan.py match A.fp.json B.fp.json          how each function of A matches B
    scan.py hw    IMAGE EXPORT.json            functions that use a board-specific address or port

EXPORT.json is the decompile.json that `re-run --ghidra-export` wrote for IMAGE; only its function
ranges and names are read, never its C. Every fact comes from capstone's reading of the image bytes.
Run in the toolchain image: re-run python3 -I tools/visws-hal/scan.py ...

A function's shape is its instruction sequence with the mnemonic and the operand kinds kept and every
immediate, displacement, branch target and call target of 0x1000 or more masked, so two builds of the same
source with different link addresses give the same shape. `match` reports a shape-equal function as
'exact', otherwise the best mnemonic-trigram Jaccard score over 0.80 with a length ratio over 0.7 as
'near', otherwise the best string-set Jaccard score of 0.5 or more (strings the function points at)
as 'strings', otherwise 'none'.
"""
import collections
import hashlib
import json
import sys
import zlib

import capstone
import pefile
from capstone import x86

FS = x86.X86_REG_FS


def load(image, export):
    pe = pefile.PE(image)
    base = pe.OPTIONAL_HEADER.ImageBase
    fns = json.load(open(export))['functions']
    for f in fns:
        f['va'] = int(f['address'], 16)
        f['end_va'] = int(f['end'], 16)
    fns.sort(key=lambda f: f['va'])
    sections = [(s.VirtualAddress + base, s.VirtualAddress + base + max(s.Misc_VirtualSize, s.SizeOfRawData),
                 bool(s.Characteristics & 0x20000000), s.Name.rstrip(b'\0').decode()) for s in pe.sections]
    return pe, base, fns, sections


def read(pe, base, va, n):
    return pe.get_data(va - base, n)


def disasm(pe, base, f):
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    n = f['end_va'] - f['va'] + 1
    return list(md.disasm(read(pe, base, f['va'], n), f['va']))


def iat_map(pe, base):
    m = {}
    for d in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', []):
        for i in d.imports:
            m[i.address] = i.name.decode() if i.name else 'ord%d' % i.ordinal
    return m


def operand_token(op, insn):
    if op.type == x86.X86_OP_REG:
        return 'r' + insn.reg_name(op.reg)
    if op.type == x86.X86_OP_IMM:
        v = op.imm & 0xffffffff
        return 'i%x' % v if v < 0x1000 or v >= 0xfffff000 else 'iA'
    m = op.mem
    seg = insn.reg_name(m.segment) + ':' if m.segment else ''
    b = insn.reg_name(m.base) if m.base else ''
    i = insn.reg_name(m.index) + '*%d' % m.scale if m.index else ''
    d = m.disp & 0xffffffff
    ds = '%x' % d if d < 0x1000 or d >= 0xfffff000 else 'A'
    return 'm%s[%s+%s+%s]' % (seg, b, i, ds)


def shape(insns):
    toks = []
    for i in insns:
        if i.mnemonic in ('call', 'jmp') or i.mnemonic.startswith('j') or i.mnemonic.startswith('loop'):
            toks.append(i.mnemonic + (' A' if i.op_str.startswith('0x') else ' ' + ','.join(operand_token(o, i) for o in i.operands)))
            continue
        toks.append(i.mnemonic + ' ' + ','.join(operand_token(o, i) for o in i.operands))
    return toks


def trigrams(insns):
    ms = [i.mnemonic for i in insns]
    return sorted({zlib.crc32(' '.join(ms[k:k + 3]).encode()) for k in range(max(0, len(ms) - 2))}) or [0]


def referenced_strings(pe, base, ins, sections):
    """ASCII strings of 4 or more characters that the instructions point at (immediate or displacement)."""
    out = set()
    for i in ins:
        for o in i.operands:
            v = o.imm & 0xffffffff if o.type == x86.X86_OP_IMM else (o.mem.disp & 0xffffffff if o.type == x86.X86_OP_MEM else 0)
            if v < base or not any(a <= v < b and not x for a, b, x, _ in sections):
                continue
            try:
                raw = pe.get_data(v - base, 80)
            except Exception:
                continue
            t = raw.split(b'\0')[0]
            if len(t) >= 4 and all(32 <= c < 127 or c in (9, 10) for c in t):
                out.add(t.decode())
    return sorted(out)


def cmd_fp(image, export, out):
    pe, base, fns, sections = load(image, export)
    rows = []
    for f in fns:
        ins = disasm(pe, base, f)
        sh = shape(ins)
        rows.append({'strs': referenced_strings(pe, base, ins, sections), 'name': f['name'], 'named': f['name_source'] != 'DEFAULT', 'va': f['va'],
                     'size': f['end_va'] - f['va'] + 1, 'n': len(ins),
                     'shape': hashlib.sha1('\n'.join(sh).encode()).hexdigest()[:16], 'tri': trigrams(ins)})
    json.dump(rows, open(out, 'w'))
    print('%d functions' % len(rows))


def jac(a, b):
    sa, sb = set(a), set(b)
    return len(sa & sb) / len(sa | sb)


def cmd_match(pa, pb):
    A, B = json.load(open(pa)), json.load(open(pb))
    by_shape = collections.defaultdict(list)
    for r in B:
        by_shape[r['shape']].append(r)
    out = []
    for r in A:
        if r['n'] < 3:
            res = ('exact', by_shape[r['shape']][0]) if by_shape.get(r['shape']) else ('none', None)
        elif by_shape.get(r['shape']):
            res = ('exact', by_shape[r['shape']][0])
        else:
            best, bs = None, 0.0
            for c in B:
                if min(c['n'], r['n']) / max(c['n'], r['n']) < 0.7:
                    continue
                s = jac(r['tri'], c['tri'])
                if s > bs:
                    best, bs = c, s
            res = ('near', best) if bs > 0.80 else ('none', None)
            if res[0] == 'none' and r['strs']:
                best, bs = None, 0.0
                for c in B:
                    if c['strs']:
                        t = jac(r['strs'], c['strs'])
                        if t > bs:
                            best, bs = c, t
                if bs >= 0.5:
                    res = ('strings', best)
        out.append({'name': r['name'], 'va': r['va'], 'n': r['n'], 'kind': res[0],
                    'to': res[1]['name'] if res[1] else None, 'to_va': res[1]['va'] if res[1] else None,
                    'to_named': res[1]['named'] if res[1] else None})
    json.dump(out, sys.stdout)
    print()


def cmd_facts(image, export):
    pe, base, fns, sections = load(image, export)
    iat = iat_map(pe, base)
    text = [(a, b) for a, b, x, _ in sections if x]
    entry = {f['va']: f['name'] for f in fns}

    def in_code(v):
        return any(a <= v < b for a, b in text)

    fsacc = collections.defaultdict(lambda: collections.defaultdict(lambda: [0, 0]))   # off -> fn -> [r, w]
    tagged = collections.defaultdict(lambda: collections.defaultdict(lambda: [0, 0]))  # (tag, off) -> fn -> [r, w]
    pcrabs = collections.defaultdict(lambda: collections.defaultdict(lambda: [0, 0]))  # PCR offset -> fn -> [r, w]
    stores = []      # (fn, import name or None, base reg, disp, target va, target name)
    imports_used = collections.defaultdict(set)
    for f in fns:
        regs = {}    # register -> import name, or '@PCR' / '@PRCB' after a load of fs:[0x1c] / fs:[0x20]
        for i in disasm(pe, base, f):
            ops = i.operands
            for o in ops:
                if o.type != x86.X86_OP_MEM:
                    continue
                m = o.mem
                if m.segment == FS and not m.base and not m.index:
                    c = fsacc[m.disp & 0xffffffff][f['name']]
                elif not m.segment and not m.base and 0xffdff000 <= (m.disp & 0xffffffff) < 0xffe00000:
                    # the uniprocessor kernel keeps its one PCR at a fixed address: same fields, absolute
                    c = pcrabs[(m.disp & 0xffffffff) - 0xffdff000][f['name']]
                elif m.base and regs.get(m.base) in ('@PCR', '@PRCB') and not m.segment:
                    c = tagged[(regs[m.base], m.disp & 0xffffffff)][f['name']]
                else:
                    c = None
                if c is not None:
                    c[1] += bool(o.access & 2)
                    c[0] += bool(o.access & 1)
                d = m.disp & 0xffffffff
                if not m.base and not m.index and d in iat:
                    imports_used[iat[d]].add(f['name'])
            if i.mnemonic == 'mov' and len(ops) == 2:
                d, s = ops
                if d.type == x86.X86_OP_REG:
                    sm = s.mem if s.type == x86.X86_OP_MEM else None
                    if sm is not None and not sm.base and not sm.index and (sm.disp & 0xffffffff) in iat:
                        regs[d.reg] = iat[sm.disp & 0xffffffff]
                    elif sm is not None and sm.segment == FS and not sm.base and (sm.disp & 0xffffffff) in (0x1c, 0x20):
                        regs[d.reg] = '@PCR' if sm.disp == 0x1c else '@PRCB'
                    else:
                        regs.pop(d.reg, None)
                elif d.type == x86.X86_OP_MEM and d.mem.base and s.type == x86.X86_OP_IMM:
                    v = s.imm & 0xffffffff
                    if in_code(v):
                        stores.append((f['name'], regs.get(d.mem.base), insn_reg(i, d.mem.base), d.mem.disp, v,
                                       entry.get(v)))
            else:
                for o in ops:
                    if o.type == x86.X86_OP_REG and o.access & 2:
                        regs.pop(o.reg, None)
            if i.mnemonic == 'call':
                for r in (x86.X86_REG_EAX, x86.X86_REG_ECX, x86.X86_REG_EDX):
                    regs.pop(r, None)
    json.dump({'fs': {hex(o): fs for o, fs in sorted(fsacc.items())},
               'pcr_abs': {hex(o): fs for o, fs in sorted(pcrabs.items())},
               'tagged': {'%s+%#x' % k: v for k, v in sorted(tagged.items())},
               'stores': stores,
               'imports_used': {k: sorted(v) for k, v in imports_used.items()}}, sys.stdout, indent=0)
    print()


def insn_reg(i, reg):
    return i.reg_name(reg)


# Board-specific constants (physical blocks from the Cobalt and Lithium pages, and the power-management ports):
# the three Cobalt blocks, the two Lithium bridge windows as the system sees them, the PIIX4 power-management
# block, the power-management latch ports and the NS87307 GPIO and power-management bases.
HW = {0xc2000000: 'cobalt-cpu', 0xc4000000: 'cobalt-apic', 0xc6000000: 'cobalt-mem',
      0x70000000: 'lithium-A', 0x74000000: 'lithium-B', 0xf80: 'piix4-pm', 0xf84: 'piix4-pm-ctl',
      0xfb0: 'pm-nmi-port', 0xfb5: 'pm-port', 0xff0: 'pm-latch', 0xfc0: 'ns307-gpio', 0xfc8: 'ns307-pm'}


def cmd_hw(image, export):
    pe, base, fns, _ = load(image, export)
    out = {}
    for f in fns:
        hit = set()
        for i in disasm(pe, base, f):
            for o in i.operands:
                v = o.imm & 0xffffffff if o.type == x86.X86_OP_IMM else (o.mem.disp & 0xffffffff if o.type == x86.X86_OP_MEM else None)
                if v is None:
                    continue
                for k, name in HW.items():
                    if (k >= 0x1000 and (v & 0xffff0000) == k) or (k < 0x1000 and v == k and i.mnemonic in ('in', 'out', 'mov', 'push', 'cmp', 'add', 'sub') and o.type == x86.X86_OP_IMM):
                        hit.add(name)
        if hit:
            out[f['name']] = sorted(hit)
    json.dump(out, sys.stdout)
    print()


if __name__ == '__main__':
    c = sys.argv[1]
    {'facts': cmd_facts, 'fp': cmd_fp, 'match': cmd_match, 'hw': cmd_hw}[c](*sys.argv[2:])
