"""generated from devices/r5000_cp0/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 6a9b39abb11b3b99b791300a4de226fd477602f6718575488b04e14313a7ffdf
MIPS R5000 CP0 Config, Status, PageMask and LLAddr field positions, and FCR31 flags"""

UNIT = 'r5000_cp0'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'R5KCFG_BE_MASK': {'value': 32768, 'count': 1, 'stride': 1}, 'R5KCFG_CACHE_32K_CODE': {'value': 3, 'count': 1, 'stride': 1}, 'R5KCFG_DB_MASK': {'value': 16, 'count': 1, 'stride': 1}, 'R5KCFG_DC_MASK': {'value': 448, 'count': 1, 'stride': 1}, 'R5KCFG_DC_SHIFT': {'value': 6, 'count': 1, 'stride': 1}, 'R5KCFG_EB_MASK': {'value': 8192, 'count': 1, 'stride': 1}, 'R5KCFG_EC_DIVISOR_BASE': {'value': 2, 'count': 1, 'stride': 1}, 'R5KCFG_EC_MASK': {'value': 1879048192, 'count': 1, 'stride': 1}, 'R5KCFG_EC_SHIFT': {'value': 28, 'count': 1, 'stride': 1}, 'R5KCFG_EM_MASK': {'value': 16384, 'count': 1, 'stride': 1}, 'R5KCFG_EP_MASK': {'value': 251658240, 'count': 1, 'stride': 1}, 'R5KCFG_EP_SHIFT': {'value': 24, 'count': 1, 'stride': 1}, 'R5KCFG_EW_MASK': {'value': 786432, 'count': 1, 'stride': 1}, 'R5KCFG_EW_SHIFT': {'value': 18, 'count': 1, 'stride': 1}, 'R5KCFG_FIXED_ONE_MASK': {'value': 65536, 'count': 1, 'stride': 1}, 'R5KCFG_IB_MASK': {'value': 32, 'count': 1, 'stride': 1}, 'R5KCFG_IC_MASK': {'value': 3584, 'count': 1, 'stride': 1}, 'R5KCFG_IC_SHIFT': {'value': 9, 'count': 1, 'stride': 1}, 'R5KCFG_K0_MASK': {'value': 7, 'count': 1, 'stride': 1}, 'R5KCFG_K0_SHIFT': {'value': 0, 'count': 1, 'stride': 1}, 'R5KCFG_SB_MASK': {'value': 12582912, 'count': 1, 'stride': 1}, 'R5KCFG_SB_SHIFT': {'value': 22, 'count': 1, 'stride': 1}, 'R5KCFG_SC_BIT': {'value': 17, 'count': 1, 'stride': 1}, 'R5KCFG_SC_MASK': {'value': 131072, 'count': 1, 'stride': 1}, 'R5KCFG_SE_MASK': {'value': 4096, 'count': 1, 'stride': 1}, 'R5KCFG_SS_MASK': {'value': 3145728, 'count': 1, 'stride': 1}, 'R5KCFG_SS_SHIFT': {'value': 20, 'count': 1, 'stride': 1}, 'R5KFCR_CAUSE_MASK': {'value': 258048, 'count': 1, 'stride': 1}, 'R5KFCR_CAUSE_SHIFT': {'value': 12, 'count': 1, 'stride': 1}, 'R5KFCR_CC0_MASK': {'value': 8388608, 'count': 1, 'stride': 1}, 'R5KFCR_CC_HI_MASK': {'value': 4261412864, 'count': 1, 'stride': 1}, 'R5KFCR_CC_HI_SHIFT': {'value': 25, 'count': 1, 'stride': 1}, 'R5KFCR_ENABLE_MASK': {'value': 3968, 'count': 1, 'stride': 1}, 'R5KFCR_ENABLE_SHIFT': {'value': 7, 'count': 1, 'stride': 1}, 'R5KFCR_FLAG_MASK': {'value': 124, 'count': 1, 'stride': 1}, 'R5KFCR_FLAG_SHIFT': {'value': 2, 'count': 1, 'stride': 1}, 'R5KFCR_FS_MASK': {'value': 16777216, 'count': 1, 'stride': 1}, 'R5KFCR_RM_MASK': {'value': 3, 'count': 1, 'stride': 1}, 'R5KFCR_RSVD_MASK': {'value': 8126464, 'count': 1, 'stride': 1}, 'R5KLL_MASK': {'value': 4294967295, 'count': 1, 'stride': 1}, 'R5KLL_SHIFT': {'value': 4, 'count': 1, 'stride': 1}, 'R5KPM_FIELD_MASK': {'value': 33546240, 'count': 1, 'stride': 1}, 'R5KPM_FIELD_SHIFT': {'value': 13, 'count': 1, 'stride': 1}, 'R5KPM_PAGE_16K': {'value': 24576, 'count': 1, 'stride': 1}, 'R5KPM_PAGE_16M': {'value': 33546240, 'count': 1, 'stride': 1}, 'R5KPM_PAGE_1M': {'value': 2088960, 'count': 1, 'stride': 1}, 'R5KPM_PAGE_256K': {'value': 516096, 'count': 1, 'stride': 1}, 'R5KPM_PAGE_4K': {'value': 0, 'count': 1, 'stride': 1}, 'R5KPM_PAGE_4M': {'value': 8380416, 'count': 1, 'stride': 1}, 'R5KPM_PAGE_64K': {'value': 122880, 'count': 1, 'stride': 1}, 'R5KST_BEV_MASK': {'value': 4194304, 'count': 1, 'stride': 1}, 'R5KST_CE_MASK': {'value': 131072, 'count': 1, 'stride': 1}, 'R5KST_CU_MASK': {'value': 1879048192, 'count': 1, 'stride': 1}, 'R5KST_DE_MASK': {'value': 65536, 'count': 1, 'stride': 1}, 'R5KST_ERL_MASK': {'value': 4, 'count': 1, 'stride': 1}, 'R5KST_EXL_MASK': {'value': 2, 'count': 1, 'stride': 1}, 'R5KST_FR_MASK': {'value': 67108864, 'count': 1, 'stride': 1}, 'R5KST_IE_MASK': {'value': 1, 'count': 1, 'stride': 1}, 'R5KST_IMPLEMENTED_MASK': {'value': 4132700159, 'count': 1, 'stride': 1}, 'R5KST_IM_MASK': {'value': 65280, 'count': 1, 'stride': 1}, 'R5KST_IM_SHIFT': {'value': 8, 'count': 1, 'stride': 1}, 'R5KST_KSU_MASK': {'value': 24, 'count': 1, 'stride': 1}, 'R5KST_KSU_SHIFT': {'value': 3, 'count': 1, 'stride': 1}, 'R5KST_KX_MASK': {'value': 128, 'count': 1, 'stride': 1}, 'R5KST_RE_MASK': {'value': 33554432, 'count': 1, 'stride': 1}, 'R5KST_SR_MASK': {'value': 1048576, 'count': 1, 'stride': 1}, 'R5KST_SX_MASK': {'value': 64, 'count': 1, 'stride': 1}, 'R5KST_UX_MASK': {'value': 32, 'count': 1, 'stride': 1}, 'R5KST_XX_MASK': {'value': 2147483648, 'count': 1, 'stride': 1}}
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
