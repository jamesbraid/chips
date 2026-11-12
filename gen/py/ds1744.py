"""generated from defs/ds1744.toml by defs-gen - do not edit, change the source
Dallas DS1744 nonvolatile timekeeping SRAM (32 KiB, byte-wide, with clock)"""

UNIT = 'ds1744'
REGISTERS = {'ram': {'offset': 0, 'access': 'rw', 'width': 8, 'count': 32760, 'stride': 1, 'space': 'chip1744', 'reset': 'unknown', 'grade': 'inferred'}, 'clock': {'offset': 32760, 'access': 'rw', 'width': 8, 'count': 8, 'stride': 1, 'space': 'chip1744', 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'ram': {}, 'clock': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {}
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
