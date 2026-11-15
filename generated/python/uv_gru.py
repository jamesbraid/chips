"""generated from devices/uv_gru/registers.toml by defs-gen - do not edit, change the source
UV global reference unit (GRU): chiplet memory map, handles and instruction word"""

UNIT = 'uv_gru'
REGISTERS = {}
WORDS = {'CBE_DW7': {'width': 64, 'grade': 'inferred'}, 'CB_DW0': {'width': 64, 'grade': 'established'}, 'CCH_DW0': {'width': 64, 'grade': 'inferred'}, 'TFH_DW0': {'width': 64, 'grade': 'inferred'}, 'TFH_DW2': {'width': 64, 'grade': 'inferred'}, 'TFH_DW3': {'width': 64, 'grade': 'inferred'}, 'TGH_DW0': {'width': 64, 'grade': 'inferred'}, 'TGH_DW2': {'width': 64, 'grade': 'inferred'}, 'TGH_DW3': {'width': 64, 'grade': 'inferred'}}
FIELDS = {'CBE_DW7': {'cbrexecstatus': (63, 56), 'cbrstate': (55, 52), 'ecause': (51, 32)}, 'CB_DW0': {'tlb_fault_color': (63, 63), 'isubstatus': (61, 58), 'istatus': (57, 56), 'tri0': (53, 32), 'exopc': (31, 24), 'opc': (23, 16), 'iaa1': (14, 13), 'iaa0': (12, 11), 'xtype': (10, 8), 'ima': (3, 1), 'icmd': (0, 0)}, 'CCH_DW0': {'dsr_allocation_map': (63, 32), 'tfm_done_bit_enable': (28, 28), 'cause': (27, 24), 'state': (19, 18), 'status': (17, 16), 'tlb_int_select': (15, 12), 'tfm_fault_bit_enable': (11, 11), 'tlb_int_enable': (10, 10), 'cb_int_enable': (9, 9), 'req_slice': (8, 7), 'req_slice_set_enable': (6, 6), 'unmap_enable': (5, 5), 'opc': (4, 2), 'delresp': (1, 1), 'cmd': (0, 0)}, 'TFH_DW0': {'ctxnum': (51, 48), 'indexway': (43, 32), 'cb_int': (30, 30), 'cause': (29, 24), 'state': (22, 20), 'status': (17, 16), 'opc': (6, 4), 'delresp': (1, 1), 'cmd': (0, 0)}, 'TFH_DW2': {'gaa': (58, 57), 'dirty': (56, 56), 'fillasid': (55, 32), 'missasid': (23, 0)}, 'TFH_DW3': {'pagesize': (52, 48), 'pfn': (40, 0)}, 'TGH_DW0': {'cause': (26, 24), 'state': (22, 20), 'status': (17, 16), 'opc': (2, 2), 'delresp': (1, 1), 'cmd': (0, 0)}, 'TGH_DW2': {'global': (48, 48), 'pagesize': (36, 32), 'asid': (23, 0)}, 'TGH_DW3': {'n': (57, 48), 'vaddrmask': (38, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'CACHE_LINE': {'value': 64, 'count': 1, 'stride': 1}, 'CBE_BASE': {'value': 67174400, 'count': 1, 'stride': 1}, 'CBR_AU_SIZE': {'value': 2, 'count': 1, 'stride': 1}, 'CBS_ACTIVE': {'value': 2, 'count': 1, 'stride': 1}, 'CBS_CALL_OS': {'value': 3, 'count': 1, 'stride': 1}, 'CBS_EXCEPTION': {'value': 1, 'count': 1, 'stride': 1}, 'CBS_IDLE': {'value': 0, 'count': 1, 'stride': 1}, 'CB_BASE': {'value': 0, 'count': 1, 'stride': 1}, 'CCHOP_ALLOCATE': {'value': 2, 'count': 1, 'stride': 1}, 'CCHOP_DEALLOCATE': {'value': 4, 'count': 1, 'stride': 1}, 'CCHOP_INTERRUPT': {'value': 3, 'count': 1, 'stride': 1}, 'CCHOP_INTERRUPT_SYNC': {'value': 5, 'count': 1, 'stride': 1}, 'CCHOP_START': {'value': 1, 'count': 1, 'stride': 1}, 'CCH_BASE': {'value': 67239936, 'count': 1, 'stride': 1}, 'CHIPLETS_PER_HUB': {'value': 2, 'count': 1, 'stride': 1}, 'CHIPLET_SIZE': {'value': 134217728, 'count': 1, 'stride': 1}, 'DSR_AU_BYTES': {'value': 1024, 'count': 1, 'stride': 1}, 'DS_BASE': {'value': 131072, 'count': 1, 'stride': 1}, 'GAA_MMIO': {'value': 1, 'count': 1, 'stride': 1}, 'GAA_NCRAM': {'value': 2, 'count': 1, 'stride': 1}, 'GAA_RAM': {'value': 0, 'count': 1, 'stride': 1}, 'GAA_REGISTER': {'value': 3, 'count': 1, 'stride': 1}, 'GRU_PADDR_SHIFT': {'value': 12, 'count': 1, 'stride': 1}, 'GSEG_PAGESIZE': {'value': 262144, 'count': 1, 'stride': 1}, 'GSEG_STRIDE': {'value': 4194304, 'count': 1, 'stride': 1}, 'HANDLE_BYTES': {'value': 64, 'count': 1, 'stride': 1}, 'HANDLE_STRIDE': {'value': 256, 'count': 1, 'stride': 1}, 'IAA_MMIO': {'value': 1, 'count': 1, 'stride': 1}, 'IAA_NCRAM': {'value': 2, 'count': 1, 'stride': 1}, 'IAA_RAM': {'value': 0, 'count': 1, 'stride': 1}, 'IAA_REGISTER': {'value': 3, 'count': 1, 'stride': 1}, 'MCS_BASE': {'value': 67108864, 'count': 1, 'stride': 1}, 'NUM_CB': {'value': 128, 'count': 1, 'stride': 1}, 'NUM_CCH': {'value': 16, 'count': 1, 'stride': 1}, 'NUM_DSR_BYTES': {'value': 32768, 'count': 1, 'stride': 1}, 'NUM_TFM': {'value': 16, 'count': 1, 'stride': 1}, 'NUM_TGH': {'value': 24, 'count': 1, 'stride': 1}, 'OP_BCOPY': {'value': 1, 'count': 1, 'stride': 1}, 'OP_BSTORE': {'value': 14, 'count': 1, 'stride': 1}, 'OP_GAMER': {'value': 12, 'count': 1, 'stride': 1}, 'OP_GAMERR': {'value': 13, 'count': 1, 'stride': 1}, 'OP_GAMIR': {'value': 10, 'count': 1, 'stride': 1}, 'OP_GAMIRR': {'value': 11, 'count': 1, 'stride': 1}, 'OP_GAMXR': {'value': 9, 'count': 1, 'stride': 1}, 'OP_IVLOAD': {'value': 3, 'count': 1, 'stride': 1}, 'OP_IVSET': {'value': 7, 'count': 1, 'stride': 1}, 'OP_IVSTORE': {'value': 5, 'count': 1, 'stride': 1}, 'OP_MESQ': {'value': 8, 'count': 1, 'stride': 1}, 'OP_NOP': {'value': 0, 'count': 1, 'stride': 1}, 'OP_VFLUSH': {'value': 15, 'count': 1, 'stride': 1}, 'OP_VLOAD': {'value': 2, 'count': 1, 'stride': 1}, 'OP_VSET': {'value': 6, 'count': 1, 'stride': 1}, 'OP_VSTORE': {'value': 4, 'count': 1, 'stride': 1}, 'SUPPORTED_BELOW_HUB_REVISION': {'value': 5, 'count': 1, 'stride': 1}, 'TFHOP_EXCEPTION': {'value': 4, 'count': 1, 'stride': 1}, 'TFHOP_NOOP': {'value': 0, 'count': 1, 'stride': 1}, 'TFHOP_RESTART': {'value': 1, 'count': 1, 'stride': 1}, 'TFHOP_USER_POLLING_MODE': {'value': 7, 'count': 1, 'stride': 1}, 'TFHOP_WRITE_ONLY': {'value': 2, 'count': 1, 'stride': 1}, 'TFHOP_WRITE_RESTART': {'value': 3, 'count': 1, 'stride': 1}, 'TFH_BASE': {'value': 67207168, 'count': 1, 'stride': 1}, 'TFM_BASE': {'value': 67108864, 'count': 1, 'stride': 1}, 'TGHOP_TLBINV': {'value': 1, 'count': 1, 'stride': 1}, 'TGH_BASE': {'value': 67141632, 'count': 1, 'stride': 1}, 'XTYPE_B': {'value': 0, 'count': 1, 'stride': 1}, 'XTYPE_CL': {'value': 6, 'count': 1, 'stride': 1}, 'XTYPE_DW': {'value': 3, 'count': 1, 'stride': 1}, 'XTYPE_S': {'value': 1, 'count': 1, 'stride': 1}, 'XTYPE_W': {'value': 2, 'count': 1, 'stride': 1}}
TESTS = []


def decode(name, value):
    """Field name -> value for a register or word."""
    return {f: (value >> lo) & ((1 << (hi - lo + 1)) - 1) for f, (hi, lo) in FIELDS[name].items()}


def encode(name, **fields):
    v = 0
    for f, x in fields.items():
        hi, lo = FIELDS[name][f]
        if x >> (hi - lo + 1):
            raise ValueError('%s.%s: %d does not fit' % (name, f, x))
        v |= x << lo
    return v


def describe(name, value):
    """decode, with enum labels where the field has an enum."""
    out = {}
    for f, x in decode(name, value).items():
        e = ENUMS.get(FIELD_ENUM.get('%s.%s' % (name, f)))
        out[f] = e.get(x, x) if e else x
    return out


def selftest():
    for name, value, expect in TESTS:
        got = decode(name, value)
        for f, want in expect.items():
            assert got[f] == want, (name, hex(value), f, got[f], want)
    return len(TESTS)


if __name__ == '__main__':
    print('%s: %d vectors ok' % (UNIT, selftest()))
