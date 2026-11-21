"""generated from devices/router_sn1/registers.toml by defs-gen - do not edit, change the source
defs-gen 2
input sha256 b70f66625e769d9712121c425a33c1e848b0297d809537cea42eec8674d89524
SN1 network router: port block, local routing table and remote reset mask (public header positions)"""

UNIT = 'router_sn1'
REGISTERS = {'reset_mask': {'offset': 24, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'local_table': {'offset': 512, 'access': 'rw', 'width': 64, 'count': 128, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'reset_mask': {}, 'local_table': {'link8': (30, 28), 'link7': (26, 24), 'link6': (22, 20), 'link5': (18, 16), 'link4': (14, 12), 'link3': (10, 8), 'link2': (6, 4), 'link1': (2, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'LOCAL_ENTRIES': {'value': 128, 'count': 1, 'stride': 1}, 'MAX_PORTS': {'value': 8, 'count': 1, 'stride': 1}, 'META_ENTRIES': {'value': 16, 'count': 1, 'stride': 1}, 'RTABLE_FIELD_BITS': {'value': 3, 'count': 1, 'stride': 1}, 'RTABLE_FIELD_STRIDE_BITS': {'value': 4, 'count': 1, 'stride': 1}}
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
