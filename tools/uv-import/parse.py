#!/usr/bin/env python3
"""Mechanical import of the UV MMR header into per-generation maps.
usage: parse.py v5.4-header v6.6-header out.json ; then gen.py out.json devices/uvN/registers.toml N"""
import re, sys, json

RENAME = {
    'UVH_RH_GAM_CONFIG': 'UVH_RH_GAM_ADDR_MAP_CONFIG',
    'UVH_RH_GAM_ALIAS210_OVERLAY_CONFIG_0': 'UVH_RH_GAM_ALIAS_0_OVERLAY_CONFIG',
    'UVH_RH_GAM_ALIAS210_OVERLAY_CONFIG_1': 'UVH_RH_GAM_ALIAS_1_OVERLAY_CONFIG',
    'UVH_RH_GAM_ALIAS210_OVERLAY_CONFIG_2': 'UVH_RH_GAM_ALIAS_2_OVERLAY_CONFIG',
    'UVH_RH_GAM_ALIAS210_REDIRECT_CONFIG_0': 'UVH_RH_GAM_ALIAS_0_REDIRECT_CONFIG',
    'UVH_RH_GAM_ALIAS210_REDIRECT_CONFIG_1': 'UVH_RH_GAM_ALIAS_1_REDIRECT_CONFIG',
    'UVH_RH_GAM_ALIAS210_REDIRECT_CONFIG_2': 'UVH_RH_GAM_ALIAS_2_REDIRECT_CONFIG',
    'UVH_RH_GAM_MMIOH_OVERLAY_CONFIG0': 'UVH_RH_GAM_MMIOH_OVERLAY_CONFIG0',
}
def norm(n):
    if n.endswith('_MMR'):
        n = n[:-4]
    return RENAME.get(n, n)

def blocks(text):
    text = re.sub(r'\\\n', ' ', text)
    parts = re.split(r'/\* =+ \*/\n/\*\s+(\w+)\s+\*/\n/\* =+ \*/\n', text)
    return [(parts[i], parts[i + 1]) for i in range(1, len(parts), 2)]

def structs(body):
    out = {}
    for m in re.finditer(r'struct\s+(\w+)\s*\{(.*?)\}\s*(s\w*)\s*;', body, re.S):
        pos, fields = 0, []
        for fm in re.finditer(r'unsigned long\s+(\w+)\s*:\s*(\d+)\s*;\s*(?:/\*\s*([\w ]+?)\s*\*/)?', m.group(2)):
            name, w, acc = fm.group(1), int(fm.group(2)), fm.group(3) or 'RW'
            if not name.startswith('rsvd') and acc != 'Undefined':
                fields.append((name, pos + w - 1, pos, acc))
            pos += w
        out[m.group(3)] = fields
    return out

def conds(g):
    s = {g}
    if g in ('2', '3', '4', '4A'): s |= {'X'}
    if g == '5': s |= {'Y'}
    return s

def resolve(expr, gen, defs, depth=0):
    expr = expr.strip()
    expr = re.sub(r'/\*\s*is_uv\w*\s*\*/', '', expr)
    if depth > 6: return None
    m = re.fullmatch(r'\(?\s*(0x[0-9a-fA-F]+|\d+)U?L?\s*\)?', expr)
    if m: return int(m.group(1), 0)
    if re.fullmatch(r'\w+', expr):
        return resolve(defs[expr], gen, defs, depth + 1) if expr in defs else None
    e = expr.strip('() \t')
    pat = re.compile(r'is_uv\((\w+)\)\s*\?\s*([\w]+)\s*:|is_uv(\d)(a?)_hub\(\)\s*\?\s*(\w+)\s*:')
    pos = 0
    tail = None
    for c in pat.finditer(e):
        if c.group(1):
            cond, val = c.group(1)[2:], c.group(2)
        else:
            cond, val = c.group(3) + ('A' if c.group(4) else ''), c.group(5)
        pos = c.end()
        if gen in ('4A',) or cond != '4A':
            if cond in conds(gen):
                return resolve(val, gen, defs, depth + 1)
    tail = e[pos:].strip('() \t')
    tail = re.sub(r'^/\*.*?\*/', '', tail).strip()
    if gen == '4A' and False: pass
    return resolve(tail, gen, defs, depth + 1) if tail else None

def macro_fields(body, base, g):
    pres = {'1': ['UV1H'], '2': ['UVXH', 'UV2H'], '3': ['UVXH', 'UV3H'], '4': ['UVXH', 'UV4H'],
            '4A': ['UVXH', 'UV4H', 'UV4AH'], '5': ['UVYH', 'UV5H']}[g]
    pres = ['UVH'] + pres
    out = {}
    for pre in pres:
        stem = f'{pre}_{base}_'
        masks = {}
        for m in re.finditer(r'^#define\s+' + re.escape(stem) + r'(\w+?)_MASK\s+(0x[0-9a-fA-F]+)UL', body, re.M):
            masks[m.group(1)] = int(m.group(2), 16)
        if pre in ('UV4AH',) or masks:
            for k, v in masks.items(): out[k] = v
    res = []
    for k, v in out.items():
        lo = (v & -v).bit_length() - 1
        hi = v.bit_length() - 1
        res.append((k.lower(), hi, lo))
    res.sort(key=lambda x: x[2])
    return res

def parse(text, gens):
    out = {}
    for name, body in blocks(text):
        defs = {m.group(1): m.group(2).strip() for m in re.finditer(r'^#define (\w+)\s+(.+)$', body, re.M)}
        st = structs(body)
        pre = re.match(r'UV(\d?A?[XY]?)H_', name).group(1)
        base = name[name.index('H_') + 2:]
        base = norm(base) if False else base
        reg = {}
        for g in gens:
            ok = {'': True, 'X': g in ('2', '3', '4', '4A'), 'Y': g == '5'}.get(pre, pre == g or (pre == '4' and g == '4A'))
            if not ok: continue
            cands = [f'UV{g}H_{base}'] + ([f'UV4H_{base}'] if g == '4A' else []) + \
                    ([f'UVXH_{base}'] if g in ('2', '3', '4', '4A') else [f'UVYH_{base}']) + [f'UVH_{base}']
            a = None
            for c in cands:
                if c in defs:
                    a = resolve(defs[c], g, defs)
                    if a is not None: break
            if a is None: continue
            d = None
            for c in [f'UV{g}H_{base}_DEPTH', f'UVH_{base}_DEPTH', f'UVXH_{base}_DEPTH']:
                if c in defs:
                    d = resolve(defs[c], g, defs); break
            tags = {'1': ['s1'], '2': ['s2', 'sx'], '3': ['s3', 'sx'], '4': ['s4', 'sx'], '4A': ['s4a', 's4', 'sx'], '5': ['s5', 'sy', 's']}[g] + ['s', 'sn']
            fl = next((st[t] for t in tags if t in st), [])
            mf = macro_fields(body, base, g)
            if mf:
                acc = {n: a for n, h, l, a in fl}
                fl2 = [(n, h, l, acc.get(n, 'RW')) for n, h, l in mf]
                if len(fl2) >= len(fl):
                    fl = fl2
            reg[g] = {'addr': a, 'depth': d, 'fields': fl}
        if reg:
            out[norm(name if pre == '' else name)] = reg  # key by block name
            # canonical key
    return out

if __name__ == '__main__':
    t54 = open(sys.argv[1]).read(); t66 = open(sys.argv[2]).read()
    a = parse(t54, ['1', '2', '3', '4', '4A'])
    b = parse(t66, ['4', '4A', '5'])
    res = {}
    for src, tag, gens in ((a, 'v5.4', ['1', '2', '3', '4', '4A']), (b, 'v6.6', ['5'])):
        for k, r in src.items():
            nk = norm(k)
            for g, v in r.items():
                if g not in gens: continue
                v['src'] = tag
                res.setdefault(nk, {})[g] = v
    # keep v6.6 4/4A only if absent
    for k, r in b.items():
        nk = norm(k)
        for g, v in r.items():
            if g in ('4', '4A') and g not in res.get(nk, {}):
                v['src'] = 'v6.6'; res.setdefault(nk, {})[g] = v
    json.dump(res, open(sys.argv[3], 'w'), indent=1)
    from collections import Counter
    c = Counter(g for r in res.values() for g in r)
    print(len(res), dict(c))
