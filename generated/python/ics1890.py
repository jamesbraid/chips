"""generated from devices/ics1890/registers.toml by defs-gen - do not edit, change the source
ICS1890 10Base-T/100Base-TX PHYceiver, MII management registers (Octane base I/O)"""

UNIT = 'ics1890'
REGISTERS = {'phy_id1': {'offset': 2, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 1, 'space': 'mii', 'reset': 21, 'grade': 'established'}, 'phy_id2': {'offset': 3, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 1, 'space': 'mii', 'reset': 62499, 'grade': 'established'}, 'ext_ctrl': {'offset': 16, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 1, 'space': 'mii', 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'phy_id1': {'oui_low': (15, 0)}, 'phy_id2': {'oui_high': (15, 10), 'model': (9, 4), 'revision': (3, 0)}, 'ext_ctrl': {'command_override': (15, 15), 'phy_address': (10, 6), 'reserved_ics_4': (4, 4)}}
ENUMS = {'model': {1: 'ics1889', 2: 'ics1890'}, 'revision': {0: 'internal', 1: 'alpha', 2: 'general', 3: 'j_or_later'}}
FIELD_ENUM = {'phy_id2.model': 'model', 'phy_id2.revision': 'revision'}
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
