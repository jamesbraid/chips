"""generated from defs/r10000_secondary_cache_ecc.toml by defs-gen - do not edit, change the source
R10000 family CP0 CacheErr fields for secondary-cache errors"""

UNIT = 'r10000_secondary_cache_ecc'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'R10K_CACHEERR_D_MASK': {'value': 201326592, 'count': 1, 'stride': 1}, 'R10K_CACHEERR_D_SHIFT': {'value': 26, 'count': 1, 'stride': 1}, 'R10K_CACHEERR_SIDX_MASK': {'value': 8388544, 'count': 1, 'stride': 1}, 'R10K_CACHEERR_SIDX_SHIFT': {'value': 6, 'count': 1, 'stride': 1}, 'R10K_CACHEERR_TA_MASK': {'value': 50331648, 'count': 1, 'stride': 1}, 'R10K_CACHEERR_TA_SHIFT': {'value': 24, 'count': 1, 'stride': 1}, 'R10K_CACHEERR_UNIT_SECONDARY': {'value': 2, 'count': 1, 'stride': 1}, 'R10K_CACHEERR_UNIT_SHIFT': {'value': 30, 'count': 1, 'stride': 1}}
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
