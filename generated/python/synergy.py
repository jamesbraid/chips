"""generated from devices/synergy/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 4c3ea2546f72bcace270f575e55b39b69ccbbb218f4ea2c4bd2699014b6f3a17
Synergy: the Itanium processor-bus ASIC of the SN1 IA-64 node (register offsets the Linux port uses)"""

UNIT = 'synergy'
REGISTERS = {'vec_mask3_a': {'offset': 672, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'vec_mask3_b': {'offset': 680, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'vec_mask2_a': {'offset': 688, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'vec_mask2_b': {'offset': 696, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'vec_mask1_a': {'offset': 704, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'vec_mask1_b': {'offset': 712, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'vec_mask0_a': {'offset': 720, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'vec_mask0_b': {'offset': 728, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'gbl_perf_a': {'offset': 816, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'gbl_perf_b': {'offset': 824, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'fsb_config': {'offset': 1104, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'perf_cntl0_a': {'offset': 2736, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'perf_cntl0_b': {'offset': 2744, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'perf_cntl1_a': {'offset': 2752, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'perf_cntl1_b': {'offset': 2760, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'perf_cntr0_a': {'offset': 2768, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'perf_cntr0_b': {'offset': 2776, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'syn_tag_disable_way': {'offset': 2784, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'perf_cntr1_a': {'offset': 2800, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'perf_cntr1_b': {'offset': 2808, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'vec_mask3_a': {}, 'vec_mask3_b': {}, 'vec_mask2_a': {}, 'vec_mask2_b': {}, 'vec_mask1_a': {}, 'vec_mask1_b': {}, 'vec_mask0_a': {}, 'vec_mask0_b': {}, 'gbl_perf_a': {}, 'gbl_perf_b': {}, 'fsb_config': {'nasid': (23, 16), 'synergy': (9, 9)}, 'perf_cntl0_a': {'enable': (45, 45)}, 'perf_cntl0_b': {}, 'perf_cntl1_a': {}, 'perf_cntl1_b': {}, 'perf_cntr0_a': {}, 'perf_cntr0_b': {}, 'syn_tag_disable_way': {'way_disable': (7, 0)}, 'perf_cntr1_a': {}, 'perf_cntr1_b': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'L4_BLOCK_BYTES': {'value': 512, 'count': 1, 'stride': 1}, 'L4_BYTES': {'value': 67108864, 'count': 1, 'stride': 1}, 'L4_WAYS': {'value': 8, 'count': 1, 'stride': 1}, 'LOCAL_BASE': {'value': 15393162788864, 'count': 1, 'stride': 1}, 'PERF_COUNTER_BITS': {'value': 40, 'count': 1, 'stride': 1}, 'REMOTE_WINDOW_SYN0': {'value': 872415232, 'count': 1, 'stride': 1}, 'REMOTE_WINDOW_SYN1': {'value': 889192448, 'count': 1, 'stride': 1}}
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
