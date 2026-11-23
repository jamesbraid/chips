"""generated from devices/r12000a_variant/registers.toml by defs-gen - do not edit, change the source
defs-gen 3
input sha256 4df134dc1016e8cf057c55413f2b161f333b9b165e5097b4b0016efb318a1b37
R12000A mode-bit fields and performance control 0 syndrome field"""

UNIT = 'r12000a_variant'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'R12KA_MODE_HSTL_MASK': {'value': 1610612736, 'count': 1, 'stride': 1}, 'R12KA_MODE_HSTL_SHIFT': {'value': 29, 'count': 1, 'stride': 1}, 'R12KA_MODE_SCCLKDIV_MASK': {'value': 3670016, 'count': 1, 'stride': 1}, 'R12KA_MODE_SCCLKDIV_SHIFT': {'value': 19, 'count': 1, 'stride': 1}, 'R12KA_MODE_SCCLKDIV_TEST_CODE': {'value': 7, 'count': 1, 'stride': 1}, 'R12KA_MODE_SYSCLKDIV_CODE_A_ONLY': {'value': 12, 'count': 1, 'stride': 1}, 'R12KA_MODE_SYSCLKDIV_MASK': {'value': 7680, 'count': 1, 'stride': 1}, 'R12KA_MODE_SYSCLKDIV_SHIFT': {'value': 9, 'count': 1, 'stride': 1}, 'R12KA_PERF_CTL0_SYNDROME_MASK': {'value': 4286578688, 'count': 1, 'stride': 1}, 'R12KA_PERF_CTL0_SYNDROME_SHIFT': {'value': 23, 'count': 1, 'stride': 1}}
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
