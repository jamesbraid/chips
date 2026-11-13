"""generated from devices/heart/registers.toml by defs-gen - do not edit, change the source
HEART (Octane system controller)"""

UNIT = 'heart'
REGISTERS = {'mode': {'offset': 0, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mem_arb': {'offset': 24, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'memcfg0': {'offset': 32, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'memcfg1': {'offset': 40, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'memcfg2': {'offset': 48, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'memcfg3': {'offset': 56, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'fc_mode': {'offset': 64, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'fc_limit': {'offset': 72, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'fc0_addr': {'offset': 80, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'fc0_count': {'offset': 96, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'status': {'offset': 128, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'berr_addr': {'offset': 136, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'berr_misc': {'offset': 144, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mem_err': {'offset': 152, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bad_mem': {'offset': 160, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'piu_err': {'offset': 168, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'imr0': {'offset': 65536, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'imr1': {'offset': 65544, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'imr2': {'offset': 65552, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'imr3': {'offset': 65560, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'set_isr': {'offset': 65568, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'clr_isr': {'offset': 65576, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'isr': {'offset': 65584, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'imsr': {'offset': 65592, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'cause': {'offset': 65600, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'count': {'offset': 131072, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'trigger': {'offset': 262144, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'prid': {'offset': 327680, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'sync': {'offset': 393216, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_id': {'offset': 1048576, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_err_upper': {'offset': 1048592, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_err_lower': {'offset': 1048600, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_req_timeout': {'offset': 1048616, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_err_cmdword': {'offset': 1048640, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_err_type': {'offset': 1048672, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_err_mask': {'offset': 1048680, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_pio_err_upper': {'offset': 1048688, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_pio_err_lower': {'offset': 1048696, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_pio_rto_addr': {'offset': 1048720, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'mode': {}, 'mem_arb': {}, 'memcfg0': {}, 'memcfg1': {}, 'memcfg2': {}, 'memcfg3': {}, 'fc_mode': {}, 'fc_limit': {}, 'fc0_addr': {}, 'fc0_count': {}, 'status': {}, 'berr_addr': {}, 'berr_misc': {}, 'mem_err': {}, 'bad_mem': {}, 'piu_err': {}, 'imr0': {}, 'imr1': {}, 'imr2': {}, 'imr3': {}, 'set_isr': {}, 'clr_isr': {}, 'isr': {}, 'imsr': {}, 'cause': {}, 'count': {}, 'trigger': {}, 'prid': {}, 'sync': {}, 'wid_id': {}, 'wid_err_upper': {}, 'wid_err_lower': {}, 'wid_req_timeout': {}, 'wid_err_cmdword': {}, 'wid_err_type': {}, 'wid_err_mask': {}, 'wid_pio_err_upper': {}, 'wid_pio_err_lower': {}, 'wid_pio_rto_addr': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'CAUSE_B_0': {'value': 1, 'count': 1, 'stride': 1}, 'CAUSE_B_1': {'value': 2, 'count': 1, 'stride': 1}, 'CAUSE_B_1_0': {'value': 3, 'count': 1, 'stride': 1}, 'CAUSE_V_1': {'value': 1, 'count': 1, 'stride': 1}, 'COUNT_B_11_0': {'value': 4095, 'count': 1, 'stride': 1}, 'FC_MODE_V_45': {'value': 69, 'count': 1, 'stride': 1}, 'IMR3_V_1': {'value': 1, 'count': 1, 'stride': 1}, 'MEM_ARB_V_100000': {'value': 1048576, 'count': 1, 'stride': 1}, 'MODE_B_3_0': {'value': 15, 'count': 1, 'stride': 1}, 'MODE_V_200000': {'value': 2097152, 'count': 1, 'stride': 1}, 'MODE_V_400000': {'value': 4194304, 'count': 1, 'stride': 1}, 'STATUS_B_11': {'value': 2048, 'count': 1, 'stride': 1}, 'STATUS_B_3_0': {'value': 15, 'count': 1, 'stride': 1}, 'STATUS_B_7_4': {'value': 240, 'count': 1, 'stride': 1}, 'WID_ERR_MASK_V_2C07': {'value': 11271, 'count': 1, 'stride': 1}, 'WID_ERR_MASK_V_3FF60000': {'value': 1073086464, 'count': 1, 'stride': 1}, 'WID_REQ_TIMEOUT_V_80': {'value': 128, 'count': 1, 'stride': 1}}
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
