"""generated from devices/xbow/registers.toml by defs-gen - do not edit, change the source
Xbow (crossbar)"""

UNIT = 'xbow'
REGISTERS = {'xb_id': {'offset': 0, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_stat': {'offset': 8, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_err_upper': {'offset': 16, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_err_lower': {'offset': 24, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_ctrl': {'offset': 32, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_pkt_to': {'offset': 40, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_int_upper': {'offset': 48, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_int_lower': {'offset': 56, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_err_cmdword': {'offset': 64, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_llp_ctrl': {'offset': 72, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_stat_clr': {'offset': 80, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_arb_reload': {'offset': 88, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'reserved': {'offset': 128, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'reserved_88': {'offset': 136, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'reserved_90': {'offset': 144, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'reserved_98': {'offset': 152, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'reserved_a0': {'offset': 160, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'reserved_a8': {'offset': 168, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'reserved_b0': {'offset': 176, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'reserved_b8': {'offset': 184, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_ctrl': {'offset': 264, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_stat': {'offset': 272, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_arb_upper': {'offset': 280, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_arb_lower': {'offset': 288, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_stat_clr': {'offset': 296, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_reset': {'offset': 304, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_aux_stat': {'offset': 312, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_ctrl_148': {'offset': 328, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_stat_150': {'offset': 336, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_stat_clr_168': {'offset': 360, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_aux_stat_178': {'offset': 376, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_arb_upper_198': {'offset': 408, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'xb_link_arb_upper_1d8': {'offset': 472, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'xb_id': {}, 'xb_stat': {}, 'xb_err_upper': {}, 'xb_err_lower': {}, 'xb_ctrl': {}, 'xb_pkt_to': {}, 'xb_int_upper': {}, 'xb_int_lower': {}, 'xb_err_cmdword': {}, 'xb_llp_ctrl': {}, 'xb_stat_clr': {}, 'xb_arb_reload': {}, 'reserved': {}, 'reserved_88': {}, 'reserved_90': {}, 'reserved_98': {}, 'reserved_a0': {}, 'reserved_a8': {}, 'reserved_b0': {}, 'reserved_b8': {}, 'xb_link_ctrl': {}, 'xb_link_stat': {}, 'xb_link_arb_upper': {}, 'xb_link_arb_lower': {}, 'xb_link_stat_clr': {}, 'xb_link_reset': {}, 'xb_link_aux_stat': {}, 'xb_link_ctrl_148': {}, 'xb_link_stat_150': {}, 'xb_link_stat_clr_168': {}, 'xb_link_aux_stat_178': {}, 'xb_link_arb_upper_198': {}, 'xb_link_arb_upper_1d8': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'RESERVED_V_FF': {'value': 255, 'count': 1, 'stride': 1}, 'XB_CTRL_20_B_3_0': {'value': 15, 'count': 1, 'stride': 1}, 'XB_CTRL_20_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'XB_CTRL_20_V_24': {'value': 36, 'count': 1, 'stride': 1}, 'XB_CTRL_20_V_80000000': {'value': 2147483648, 'count': 1, 'stride': 1}, 'XB_CTRL_B_3_0': {'value': 15, 'count': 1, 'stride': 1}, 'XB_CTRL_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'XB_CTRL_V_24': {'value': 36, 'count': 1, 'stride': 1}, 'XB_CTRL_V_80000000': {'value': 2147483648, 'count': 1, 'stride': 1}, 'XB_ID_0_B_10_0': {'value': 2047, 'count': 1, 'stride': 1}, 'XB_ID_0_B_15_0': {'value': 65535, 'count': 1, 'stride': 1}, 'XB_ID_0_B_2_0': {'value': 7, 'count': 1, 'stride': 1}, 'XB_ID_B_10_0': {'value': 2047, 'count': 1, 'stride': 1}, 'XB_ID_B_15_0': {'value': 65535, 'count': 1, 'stride': 1}, 'XB_ID_B_2_0': {'value': 7, 'count': 1, 'stride': 1}, 'XB_INT_UPPER_B_15_0': {'value': 65535, 'count': 1, 'stride': 1}, 'XB_LINK_ARB_UPPER_1D8_V_9': {'value': 9, 'count': 1, 'stride': 1}, 'XB_LINK_AUX_STAT_138_B_5': {'value': 32, 'count': 1, 'stride': 1}, 'XB_LINK_AUX_STAT_138_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'XB_LINK_AUX_STAT_178_B_5': {'value': 32, 'count': 1, 'stride': 1}, 'XB_LINK_AUX_STAT_B_5': {'value': 32, 'count': 1, 'stride': 1}, 'XB_LINK_AUX_STAT_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'XB_LINK_CTRL_108_B_3': {'value': 8, 'count': 1, 'stride': 1}, 'XB_LINK_CTRL_108_V_80000': {'value': 524288, 'count': 1, 'stride': 1}, 'XB_LINK_CTRL_148_B_3': {'value': 8, 'count': 1, 'stride': 1}, 'XB_LINK_CTRL_B_3': {'value': 8, 'count': 1, 'stride': 1}, 'XB_LINK_CTRL_V_80000': {'value': 524288, 'count': 1, 'stride': 1}, 'XB_STAT_8_B_5_2': {'value': 36, 'count': 1, 'stride': 1}, 'XB_STAT_8_B_9_6': {'value': 960, 'count': 1, 'stride': 1}, 'XB_STAT_B_5_2': {'value': 36, 'count': 1, 'stride': 1}, 'XB_STAT_B_9_6': {'value': 960, 'count': 1, 'stride': 1}}
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
