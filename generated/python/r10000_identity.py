"""generated from devices/r10000_identity/registers.toml by defs-gen - do not edit, change the source
defs-gen 3
input sha256 d2842a5c402c77293eed3a25235d7f9e4e9e93075e76f5b4f972fabfc15d48aa
R10000 family processor identity and secondary-cache configuration fields"""

UNIT = 'r10000_identity'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'R10K_CONF_SB_BIT': {'value': 13, 'count': 1, 'stride': 1}, 'R10K_CONF_SB_MASK': {'value': 8192, 'count': 1, 'stride': 1}, 'R10K_CONF_SS_MASK': {'value': 458752, 'count': 1, 'stride': 1}, 'R10K_CONF_SS_SHIFT': {'value': 16, 'count': 1, 'stride': 1}, 'R10K_IMP_R10000': {'value': 9, 'count': 1, 'stride': 1}, 'R10K_IMP_R12000': {'value': 14, 'count': 1, 'stride': 1}, 'R10K_IMP_R14000': {'value': 15, 'count': 1, 'stride': 1}, 'R10K_PRID_IMP_MASK': {'value': 65280, 'count': 1, 'stride': 1}, 'R10K_PRID_IMP_SHIFT': {'value': 8, 'count': 1, 'stride': 1}, 'R10K_PRID_REV_MASK': {'value': 255, 'count': 1, 'stride': 1}, 'R10K_R16000_DISPLAY_MAJOR_OFFSET': {'value': 2, 'count': 1, 'stride': 1}, 'R10K_R16000_PRID_1GHZ': {'value': 3920, 'count': 1, 'stride': 1}, 'R10K_R16000_REV_MAJOR_MIN': {'value': 3, 'count': 1, 'stride': 1}, 'R10K_R16000_TLB_ENTRIES': {'value': 64, 'count': 1, 'stride': 1}, 'R10K_SCACHE_LINE_BASE_BYTES': {'value': 64, 'count': 1, 'stride': 1}, 'R10K_SCACHE_SIZE_UNIT': {'value': 524288, 'count': 1, 'stride': 1}, 'R10K_SCACHE_WAYS': {'value': 2, 'count': 1, 'stride': 1}}
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
