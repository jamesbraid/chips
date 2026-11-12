"""generated from defs/aic7880.toml by defs-gen - do not edit, change the source
Adaptec AIC-7880 SCSI controller on the O2: host DMA and SCB register contract"""

UNIT = 'aic7880'
REGISTERS = {'lhaddr': {'offset': 136, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'hcnt': {'offset': 140, 'access': 'rw', 'width': 8, 'count': 3, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'scbptr': {'offset': 144, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'dfcntrl': {'offset': 147, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'dfstatus': {'offset': 148, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'scbcnt': {'offset': 154, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'scbwin': {'offset': 160, 'access': 'rw', 'width': 8, 'count': 32, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'lhaddr': {}, 'hcnt': {}, 'scbptr': {}, 'dfcntrl': {'wideodd': (6, 6), 'scsien': (5, 5), 'sdmaen': (4, 4), 'hdmaen': (3, 3), 'direction': (2, 2), 'fifoflush': (1, 1), 'fiforeset': (0, 0)}, 'dfstatus': {}, 'scbcnt': {'scbauto': (7, 7), 'scbofs': (4, 0)}, 'scbwin': {}}
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
