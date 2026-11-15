#!/usr/bin/env python3
"""Write devices/uvN/registers.toml from the parse.py output (see parse.py)."""
import json, sys, re
d = json.load(open(sys.argv[1]))
out = sys.argv[2]

TITLE = {'1': 'UV1 (UV 1000 generation)', '2': 'UV2 (UV 2000 and 3000 generation)', '3': 'UV3 (UV 300 generation)',
         '4': 'UV4 (UV 400 generation, includes the UV4A revision)', '5': 'UV5 (UV 500 generation)'}
ROLE = {
 'NODE_ID': 'Hub identity: part number, revision, manufacturer and the node id the hub was given. Software reads it at offset 0 to tell the hub generation.',
 'EVENT_OCCURRED0': 'Pending hub events (error and interrupt summary bits). The ALIAS register at +8 clears bits when written.',
 'EVENT_OCCURRED1': 'Second event word (UV4 and UV5 only).',
 'EVENT_OCCURRED2': 'Third event word. UV2 to UV4 carry the real-time clock comparator interrupt here.',
 'IPI_INT': 'Send an inter-processor interrupt: the sender writes the target apic id, vector and a send bit in the target hub global MMR window.',
 'RTC': 'Real-time clock counter, replicated across the cache lines of its page from UV2 on so sockets can read it in parallel.',
 'RTC1_INT_CONFIG': 'Delivery configuration (vector, apic id) for the RTC comparator interrupt.',
 'INT_CMPB': 'RTC comparator B: the timer interrupt fires when the clock reaches this value.',
 'SCRATCH5': 'Scratch register firmware and kernel share: carries the TSC sync state and the NMI request bit.',
 'BAU_DATA_CONFIG': 'Where the hub sends a broadcast assist unit message interrupt: vector, delivery mode and apic id.',
 'BAU_DATA_BROADCAST': 'Enable broadcast of BAU message interrupts to both sockets of the hub (UV2 and later).',
 'LB_BAU_SB_DESCRIPTOR_BASE': 'Base of the 64 sets of selective-broadcast descriptors in memory: page address and the home node id.',
 'LB_BAU_SB_ACTIVATION_CONTROL': 'Start a broadcast: a push bit plus the index of the descriptor set.',
 'LB_BAU_MISC_CONTROL': 'BAU mode control: software acknowledge mode, acknowledge timeout period and per-generation workarounds.',
 'RH_GAM_MMR_OVERLAY_CONFIG': 'Base and enable of the global MMR window.',
 'RH_GAM_GRU_OVERLAY_CONFIG': 'Base and enable of the GRU window.',
 'RH_GAM_ADDR_MAP_CONFIG': 'Address map shape: number of node-offset (m) and node-number (n) bits.',
}
def role(n):
    b = re.sub(r'^UV\w*?H_', '', n)
    return ROLE.get(b)
gen = sys.argv[3]
lines = []
lines.append(f'unit = "uv{gen}"')
lines.append(f'prefix = "UV{gen}"')
lines.append(f'title = "{TITLE[gen]} hub MMR map"')
lines.append('doc = "Offsets are relative to the hub local MMR window (or the pnode-indexed global window). Offsets, field positions and access letters are definitions in SGI-written Linux platform code. Field positions are the header bitfield structs read least-significant first; reserved and undefined bits are omitted. Role text is a paraphrase of how the kernel uses the register and is inferred. Reset values are unknown: the header states none."')
lines.append('from = "Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header"')
lines.append('public_from = ["Linux v5.4 SGI UV platform", "Linux v6.6 SGI UV platform"]')
lines.append('')
lines.append('[c]')
lines.append('offset_macro = "bare"')
lines.append('')
seen = {}
for k, r in sorted(d.items(), key=lambda kv: (kv[1].get(gen, {}).get('addr', 1 << 60), kv[0])):
    if gen not in r: continue
    v = r[gen]
    if v['addr'] == 0 and not k.endswith('NODE_ID'): continue
    if k == 'UVH_RH_GAM_MMIOH_OVERLAY_CONFIG1' and gen == '3': continue
    name = re.sub(r'^UV\w*?H_', '', k).lower()
    if name in seen: continue
    seen[name] = 1
    f = v['fields']
    if k == 'UVH_LB_BAU_SB_DESCRIPTOR_BASE':
        f = [('page_address', 45 if gen == '4' else 42, 12, 'RW'), ('node_id', 62, 49, 'RW')]
    acc = 'r' if f and all(x[3] in ('RO',) for x in f) else 'rw'
    lines.append(f'[registers.{name}]')
    lines.append(f'offset = 0x{v["addr"]:x}')
    lines.append(f'access = "{acc}"')
    lines.append('width = 64')
    lines.append('grade = "established"')
    if v['depth']:
        lines.append(f'count = {v["depth"]}')
        lines.append('stride = 8')
    doc = role(k)
    d_ = f'Header name {k}.' + (' ' + doc if doc else '')
    if k.endswith('_ALIAS') or k.endswith('_ALIAS_2'):
        d_ += ' Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.'
    lines.append(f'doc = "{d_}"')
    if f:
        lines.append(f'[registers.{name}.fields]')
        used = set()
        for fn, hi, lo, a in f:
            if fn in used: continue
            used.add(fn)
            lines.append(f'{fn} = {{ bits = [{hi}, {lo}], grade = "established", doc = "Access {a} in the header." }}')
    lines.append('')
if gen == '3':
    c0 = d['UVH_RH_GAM_MMIOH_OVERLAY_CONFIG0']['3']
    lines.append('[registers.rh_gam_mmioh_overlay_config1]')
    lines.append('offset = 0x1604000')
    lines.append('access = "rw"')
    lines.append('width = 64')
    lines.append('grade = "established"')
    lines.append('doc = "Second MMIOH overlay register. The v5.4 header gives it the same address as the first (0x1603000), a copy error; the v6.6 header gives 0x1604000, which is used. Fields are the header struct for this register."')
    lines.append('[registers.rh_gam_mmioh_overlay_config1.fields]')
    for fn, hi, lo, a in d['UVH_RH_GAM_MMIOH_OVERLAY_CONFIG1']['3']['fields']:
        lines.append(f'{fn} = {{ bits = [{hi}, {lo}], grade = "established", doc = "Access {a} in the header." }}')
    lines.append('')
open(out, 'w').write('\n'.join(lines))
print(gen, len(seen))
