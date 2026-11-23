"""generated from devices/dp83843/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 8d5ca437e90248734cb54e922a124cf2ba5d1c698e8782ae4e9c09b4cb04c693
National DP83843 PHYTER 10/100 Mb/s transceiver, MII registers (Origin 300 IO-8)"""

UNIT = 'dp83843'
REGISTERS = {'bmcr': {'offset': 0, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 1, 'space': 'mii', 'reset': 'unknown', 'grade': 'inferred'}, 'bmsr': {'offset': 1, 'access': 'r', 'width': 16, 'count': 1, 'stride': 1, 'space': 'mii', 'reset': 30793, 'grade': 'inferred'}, 'aner': {'offset': 6, 'access': 'r', 'width': 16, 'count': 1, 'stride': 1, 'space': 'mii', 'reset': 4, 'grade': 'inferred'}, 'lbr': {'offset': 23, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 1, 'space': 'mii', 'reset': 0, 'grade': 'established'}, 'btscr': {'offset': 24, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 1, 'space': 'mii', 'reset': 0, 'grade': 'established'}}
WORDS = {}
FIELDS = {'bmcr': {'loopback': (14, 14), 'speed_100': (13, 13), 'an_enable': (12, 12), 'power_down': (11, 11), 'isolate': (10, 10), 'restart_an': (9, 9), 'duplex': (8, 8), 'collision_test': (7, 7)}, 'bmsr': {'preamble_suppression': (6, 6), 'an_complete': (5, 5), 'link_status': (2, 2)}, 'aner': {'next_page_able': (2, 2)}, 'lbr': {'data_path_100': (9, 7), 'tw_loopback': (5, 5), 'endec_10_loopback': (4, 4)}, 'btscr': {'full_duplex_or_repeater_readback': (7, 7)}}
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
