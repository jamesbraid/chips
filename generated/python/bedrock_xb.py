"""generated from devices/bedrock_xb/registers.toml by defs-gen - do not edit, change the source
Bedrock internal crossbar (XB) registers outside the census"""

UNIT = 'bedrock_xb'
REGISTERS = {'xb_parms': {'offset': 7340032, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 2251801961168929, 'grade': 'inferred'}, 'xb_slow_gnt': {'offset': 7340040, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_spew_control': {'offset': 7340048, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_ioq_arb_trigger': {'offset': 7340056, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 5, 'grade': 'inferred'}, 'xb_poq0_error': {'offset': 7340064, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_piq0_error': {'offset': 7340072, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_poq1_error': {'offset': 7340080, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_piq1_error': {'offset': 7340088, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_mp0_error': {'offset': 7340096, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_mp1_error': {'offset': 7340104, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_mmq_error': {'offset': 7340112, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_miq_error': {'offset': 7340120, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_noq_error': {'offset': 7340128, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_niq_error': {'offset': 7340136, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_ioq_error': {'offset': 7340144, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_iiq_error': {'offset': 7340152, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_loq_error': {'offset': 7340160, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_liq_error': {'offset': 7340168, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_first_error': {'offset': 7340176, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_debug_data_ctl': {'offset': 7340184, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_debug_arb_ctl': {'offset': 7340192, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'xb_poq0_error_clear': {'offset': 7340320, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_piq0_error_clear': {'offset': 7340328, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_poq1_error_clear': {'offset': 7340336, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_piq1_error_clear': {'offset': 7340344, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_mp0_error_clear': {'offset': 7340352, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_mp1_error_clear': {'offset': 7340360, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_mmq_error_clear': {'offset': 7340368, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_miq_error_clear': {'offset': 7340376, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_noq_error_clear': {'offset': 7340384, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_niq_error_clear': {'offset': 7340392, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_ioq_error_clear': {'offset': 7340400, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_iiq_error_clear': {'offset': 7340408, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_loq_error_clear': {'offset': 7340416, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_liq_error_clear': {'offset': 7340424, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'xb_first_error_clear': {'offset': 7340432, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'xb_parms': {'tail_wrap': (51, 32), 'deadlock_wrap': (31, 12), 'age_wrap': (11, 4), 'byp_en': (0, 0)}, 'xb_slow_gnt': {'pi0': (31, 28), 'pi1': (27, 24), 'mp0': (23, 20), 'mp1': (19, 16), 'mmq': (15, 12), 'ni': (11, 8), 'ii': (7, 4), 'lb': (3, 0)}, 'xb_spew_control': {'snoop_poq0': (10, 10), 'snoop_mp0': (9, 9), 'snoop_mmq': (8, 8), 'snoop_noq': (7, 7), 'snoop_ioq': (6, 6), 'snoop_loq': (5, 5), 'snoop_piq0': (4, 4), 'snoop_miq': (3, 3), 'snoop_niq': (2, 2), 'snoop_iiq': (1, 1), 'snoop_liq': (0, 0)}, 'xb_ioq_arb_trigger': {'clocks': (3, 0)}, 'xb_poq0_error': {'tail_timeout': (13, 12), 'underflow': (9, 8), 'overflow': (5, 4), 'invalid_xsel': (1, 0)}, 'xb_piq0_error': {'deadlock_timeout': (5, 4), 'overflow': (1, 0)}, 'xb_poq1_error': {'tail_timeout': (13, 12), 'underflow': (9, 8), 'overflow': (5, 4), 'invalid_xsel': (1, 0)}, 'xb_piq1_error': {'deadlock_timeout': (5, 4), 'overflow': (1, 0)}, 'xb_mp0_error': {'tail_timeout': (13, 12), 'underflow': (9, 8), 'overflow': (5, 4)}, 'xb_mp1_error': {'tail_timeout': (13, 12), 'underflow': (9, 8), 'overflow': (5, 4)}, 'xb_mmq_error': {}, 'xb_miq_error': {'deadlock_timeout': (7, 4)}, 'xb_noq_error': {'tail_timeout': (15, 12), 'underflow': (11, 8), 'overflow': (7, 4)}, 'xb_niq_error': {}, 'xb_ioq_error': {}, 'xb_iiq_error': {}, 'xb_loq_error': {'tail_timeout': (13, 12), 'underflow': (9, 8), 'invalid_xsel': (1, 0)}, 'xb_liq_error': {'deadlock_timeout': (4, 4), 'overflow': (0, 0)}, 'xb_first_error': {'valid': (12, 12), 'source': (11, 8), 'channel': (7, 4), 'err_type': (3, 0)}, 'xb_debug_data_ctl': {'observe_lodata': (15, 15), 'observe_source_field': (14, 14), 'observe_poq0': (13, 13), 'observe_poq1': (12, 12), 'observe_mmq': (11, 11), 'observe_mp0': (10, 10), 'observe_mp1': (9, 9), 'observe_noq': (8, 8), 'observe_ioq': (7, 7), 'observe_loq': (6, 6), 'observe_piq0': (5, 5), 'observe_piq1': (4, 4), 'observe_miq': (3, 3), 'observe_niq': (2, 2), 'observe_iiq': (1, 1), 'observe_liq': (0, 0)}, 'xb_debug_arb_ctl': {'select': (2, 0)}, 'xb_poq0_error_clear': {}, 'xb_piq0_error_clear': {}, 'xb_poq1_error_clear': {}, 'xb_piq1_error_clear': {}, 'xb_mp0_error_clear': {}, 'xb_mp1_error_clear': {}, 'xb_mmq_error_clear': {}, 'xb_miq_error_clear': {}, 'xb_noq_error_clear': {}, 'xb_niq_error_clear': {}, 'xb_ioq_error_clear': {}, 'xb_iiq_error_clear': {}, 'xb_loq_error_clear': {}, 'xb_liq_error_clear': {}, 'xb_first_error_clear': {}}
ENUMS = {'first_error_source': {2: 'liq', 3: 'loq', 4: 'iiq', 5: 'ioq', 6: 'niq', 7: 'noq', 8: 'miq', 9: 'mmq', 10: 'mp1', 11: 'mp0', 12: 'piq1', 13: 'poq1', 14: 'piq0', 15: 'poq0'}}
FIELD_ENUM = {'xb_first_error.source': 'first_error_source'}
CONSTANTS = {'XB_PARMS_ACTIVE_DEFAULTS': {'value': 2251804108648481, 'count': 1, 'stride': 1}, 'XB_PARMS_RESET_DEFAULTS': {'value': 2251801961168929, 'count': 1, 'stride': 1}}
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
