"""generated from devices/xbow/registers-extra.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 5d0eaa0d4362a4e57ae74a9515b91ea99d1ae0b25cbc4f8dbf94696f4a778ea6
Xbow registers outside the census"""

UNIT = 'xbow_extra'
REGISTERS = {'perf_a': {'offset': 96, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'perf_b': {'offset': 104, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'link_f_arb_upper': {'offset': 728, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'perf_a': {}, 'perf_b': {}, 'link_f_arb_upper': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'FENCE_LINK_8': {'value': 128, 'count': 1, 'stride': 1}, 'FENCE_LINK_9': {'value': 136, 'count': 1, 'stride': 1}, 'FENCE_LINK_A': {'value': 144, 'count': 1, 'stride': 1}, 'FENCE_LINK_B': {'value': 152, 'count': 1, 'stride': 1}, 'FENCE_LINK_C': {'value': 160, 'count': 1, 'stride': 1}, 'FENCE_LINK_D': {'value': 168, 'count': 1, 'stride': 1}, 'FENCE_LINK_E': {'value': 176, 'count': 1, 'stride': 1}, 'FENCE_LINK_F': {'value': 184, 'count': 1, 'stride': 1}, 'FENCE_WIDGET_0': {'value': 120, 'count': 1, 'stride': 1}, 'FLUSH_LINK_8': {'value': 256, 'count': 1, 'stride': 1}, 'FLUSH_LINK_9': {'value': 320, 'count': 1, 'stride': 1}, 'FLUSH_LINK_A': {'value': 384, 'count': 1, 'stride': 1}, 'FLUSH_LINK_B': {'value': 448, 'count': 1, 'stride': 1}, 'FLUSH_LINK_C': {'value': 512, 'count': 1, 'stride': 1}, 'FLUSH_LINK_D': {'value': 576, 'count': 1, 'stride': 1}, 'FLUSH_LINK_E': {'value': 640, 'count': 1, 'stride': 1}, 'FLUSH_LINK_F': {'value': 704, 'count': 1, 'stride': 1}, 'ID_MFR_MASK': {'value': 4094, 'count': 1, 'stride': 1}, 'ID_PART_MASK': {'value': 268431360, 'count': 1, 'stride': 1}, 'ID_REV_MASK': {'value': 4026531840, 'count': 1, 'stride': 1}, 'PART_PXBOW': {'value': 53504, 'count': 1, 'stride': 1}, 'PART_XBOW': {'value': 0, 'count': 1, 'stride': 1}, 'PART_XXBOW': {'value': 53248, 'count': 1, 'stride': 1}, 'PERF_A_B_19_0': {'value': 1048575, 'count': 1, 'stride': 1}, 'PERF_A_B_22_20': {'value': 7340032, 'count': 1, 'stride': 1}, 'PERF_B_B_19_0': {'value': 1048575, 'count': 1, 'stride': 1}, 'PERF_B_B_22_20': {'value': 7340032, 'count': 1, 'stride': 1}, 'PROM_CROSSBAR_LOCK_BIT': {'value': 2, 'count': 1, 'stride': 1}, 'RESOURCE_LOCK': {'value': 192, 'count': 1, 'stride': 1}, 'RESOURCE_LOCK_CLEAR': {'value': 200, 'count': 1, 'stride': 1}, 'REV_CODE_1': {'value': 1, 'count': 1, 'stride': 1}, 'REV_CODE_2': {'value': 2, 'count': 1, 'stride': 1}, 'REV_CODE_3': {'value': 3, 'count': 1, 'stride': 1}, 'REV_CODE_4': {'value': 4, 'count': 1, 'stride': 1}, 'REV_CODE_5': {'value': 5, 'count': 1, 'stride': 1}}
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
