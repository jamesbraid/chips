"""generated from devices/hub_windows/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 433dec6921b0152c218127b867a36172e0ae5ba71149fa793336f17dac3023f3
Hub register arrays whose extent is a fact of its own"""

UNIT = 'hub_windows'
REGISTERS = {'pi_gfx_window': {'offset': 768, 'access': 'rw', 'width': 64, 'count': 10, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'md_perf_cnt': {'offset': 2162704, 'access': 'rw', 'width': 64, 'count': 6, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'md_ureg0': {'offset': 2228224, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'md_ureg1': {'offset': 2228352, 'access': 'rw', 'width': 64, 'count': 16, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'iio_ioprb': {'offset': 4194712, 'access': 'rw', 'width': 64, 'count': 9, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'iio_prte': {'offset': 4195080, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'ni_age': {'offset': 6292736, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'ni_meta_table': {'offset': 6520832, 'access': 'rw', 'width': 64, 'count': 32, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'ni_local_table': {'offset': 6521088, 'access': 'rw', 'width': 64, 'count': 16, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'pi_gfx_window': {}, 'md_perf_cnt': {}, 'md_ureg0': {}, 'md_ureg1': {}, 'iio_ioprb': {'error': (48, 48), 'ovflow': (47, 43), 'fire_and_forget': (42, 42), 'mode': (41, 40), 'bnakctr': (37, 24), 'anakctr': (21, 8), 'xtalkctr': (7, 0)}, 'iio_prte': {'valid': (56, 56), 'srcnode': (54, 46), 'initiator': (45, 44), 'addr': (40, 3)}, 'ni_age': {}, 'ni_meta_table': {'exit_port': (3, 0)}, 'ni_local_table': {'exit_port': (3, 0)}}
ENUMS = {'iio_prb_mode': {0: 'normal', 1: 'collect_a', 2: 'service_a', 3: 'service_b'}}
FIELD_ENUM = {'iio_ioprb.mode': 'iio_prb_mode'}
CONSTANTS = {'BWIN_INDEX_BITS': {'value': 3, 'count': 1, 'stride': 1}, 'BWIN_SIZE_BITS_M_MODE': {'value': 29, 'count': 1, 'stride': 1}, 'BWIN_SIZE_BITS_N_MODE': {'value': 28, 'count': 1, 'stride': 1}, 'HUB_REGISTER_WIDGET': {'value': 1, 'count': 1, 'stride': 1}, 'HUB_REGISTER_WINDOW_SIZE': {'value': 8388608, 'count': 1, 'stride': 1}, 'NASID_BITS_M_MODE': {'value': 8, 'count': 1, 'stride': 1}, 'NASID_BITS_N_MODE': {'value': 9, 'count': 1, 'stride': 1}, 'NASID_LOCAL_BITS': {'value': 4, 'count': 1, 'stride': 1}, 'NASID_SHIFT_M_MODE': {'value': 32, 'count': 1, 'stride': 1}, 'NASID_SHIFT_N_MODE': {'value': 31, 'count': 1, 'stride': 1}, 'NODE_SIZE_BITS_M_MODE': {'value': 32, 'count': 1, 'stride': 1}, 'NODE_SIZE_BITS_N_MODE': {'value': 31, 'count': 1, 'stride': 1}, 'SWIN_SIZE_BITS': {'value': 24, 'count': 1, 'stride': 1}}
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
