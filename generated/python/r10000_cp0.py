"""generated from devices/r10000_cp0/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 ac3e03c75ed94daca87b077b35f60770d6347248765e51833d4b0943ef3eb864
R10000 CP0 Count and Compare timer interrupt and TLB geometry"""

UNIT = 'r10000_cp0'
REGISTERS = {}
WORDS = {'CAUSE_TIMER': {'width': 32, 'grade': 'established'}}
FIELDS = {'CAUSE_TIMER': {'ip7': (15, 15)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'R10K_CP0_COMPARE': {'value': 11, 'count': 1, 'stride': 1}, 'R10K_CP0_COUNT': {'value': 9, 'count': 1, 'stride': 1}, 'R10K_TLB_ASID_BITS': {'value': 8, 'count': 1, 'stride': 1}, 'R10K_TLB_ENTRIES': {'value': 64, 'count': 1, 'stride': 1}}
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
