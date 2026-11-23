"""generated from devices/r10000_diagnostic/registers.toml by defs-gen - do not edit, change the source
defs-gen 3
input sha256 651edc565a4b7f3c622ffdd35f85c717e6bef176606d4da7a24c00089762d871
R10000 family CP0 Diagnostic register (branch diagnostic): field positions"""

UNIT = 'r10000_diagnostic'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'R10KDIAG_BPIDX_R10K_MASK': {'value': 4088, 'count': 1, 'stride': 1}, 'R10KDIAG_BPIDX_R12K_MASK': {'value': 16376, 'count': 1, 'stride': 1}, 'R10KDIAG_BPMODE_MASK': {'value': 196608, 'count': 1, 'stride': 1}, 'R10KDIAG_BPOP_MASK': {'value': 3, 'count': 1, 'stride': 1}, 'R10KDIAG_BPSTATE_MASK': {'value': 49152, 'count': 1, 'stride': 1}, 'R10KDIAG_DBRC_BIT': {'value': 22, 'count': 1, 'stride': 1}, 'R10KDIAG_DBRC_MASK': {'value': 4194304, 'count': 1, 'stride': 1}, 'R10KDIAG_R12K_BTAC_DIS_BIT': {'value': 27, 'count': 1, 'stride': 1}, 'R10KDIAG_R12K_BTAC_DIS_MASK': {'value': 134217728, 'count': 1, 'stride': 1}, 'R10KDIAG_R12K_GHIST_ALL_BIT': {'value': 26, 'count': 1, 'stride': 1}, 'R10KDIAG_R12K_GHIST_COUNT_MASK': {'value': 58720256, 'count': 1, 'stride': 1}}
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
