"""generated from defs/r10000_config.toml by defs-gen - do not edit, change the source
R10000 family CP0 Config register field positions and hardwired primary-cache codes"""

UNIT = 'r10000_config'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'R10KCFG_BE_BIT': {'value': 15, 'count': 1, 'stride': 1}, 'R10KCFG_BE_MASK': {'value': 32768, 'count': 1, 'stride': 1}, 'R10KCFG_CACHE_32K_CODE': {'value': 3, 'count': 1, 'stride': 1}, 'R10KCFG_DC_MASK': {'value': 469762048, 'count': 1, 'stride': 1}, 'R10KCFG_DC_SHIFT': {'value': 26, 'count': 1, 'stride': 1}, 'R10KCFG_DSD_BIT': {'value': 24, 'count': 1, 'stride': 1}, 'R10KCFG_DSD_MASK': {'value': 16777216, 'count': 1, 'stride': 1}, 'R10KCFG_EC_MASK': {'value': 7680, 'count': 1, 'stride': 1}, 'R10KCFG_EC_SHIFT': {'value': 9, 'count': 1, 'stride': 1}, 'R10KCFG_IC_MASK': {'value': 3758096384, 'count': 1, 'stride': 1}, 'R10KCFG_IC_SHIFT': {'value': 29, 'count': 1, 'stride': 1}, 'R10KCFG_MODE_BITS_MASK': {'value': 33554431, 'count': 1, 'stride': 1}, 'R10KCFG_PM_MASK': {'value': 384, 'count': 1, 'stride': 1}, 'R10KCFG_PM_SHIFT': {'value': 7, 'count': 1, 'stride': 1}, 'R10KCFG_SC_MASK': {'value': 3670016, 'count': 1, 'stride': 1}, 'R10KCFG_SC_SHIFT': {'value': 19, 'count': 1, 'stride': 1}, 'R10KCFG_SK_BIT': {'value': 14, 'count': 1, 'stride': 1}, 'R10KCFG_SK_MASK': {'value': 16384, 'count': 1, 'stride': 1}}
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
