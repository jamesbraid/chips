"""generated from defs/bedrock_ni.toml by defs-gen - do not edit, change the source
Bedrock network interface (NI) registers: field layouts, port error bits and routing tables"""

UNIT = 'bedrock_ni'
REGISTERS = {'port_status': {'offset': 6815744, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port_reset': {'offset': 6815752, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'reset_enable': {'offset': 6815760, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'diag_parms': {'offset': 6815768, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'channel_control': {'offset': 6815776, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'channel_test': {'offset': 6815784, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port_parms': {'offset': 6815792, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'channel_age': {'offset': 6815800, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port_errors': {'offset': 6816000, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port_header_a': {'offset': 6816008, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port_header_b': {'offset': 6816016, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port_sideband': {'offset': 6816024, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port_error_clear': {'offset': 6816032, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'local_table': {'offset': 6819840, 'access': 'rw', 'width': 64, 'count': 128, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'global_table': {'offset': 6823936, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'port_status': {'remote_power': (2, 2), 'link_up': (1, 1), 'status_bit0': (0, 0)}, 'port_reset': {'local_reset': (2, 2), 'port_reset': (1, 1), 'link_reset_out': (0, 0)}, 'reset_enable': {'reset_ok': (0, 0)}, 'diag_parms': {'send_err_off': (2, 2), 'port_disable': (1, 1), 'send_data_error': (0, 0)}, 'channel_control': {'send_vch_sel': (8, 8), 'vch_vector_reply': (7, 7), 'vch_nine_reply': (6, 6), 'vch_two_reply': (5, 5), 'vch_one_reply': (4, 4), 'vch_vector_request': (3, 3), 'vch_nine_request': (2, 2), 'vch_two_request': (1, 1), 'vch_one_request': (0, 0)}, 'channel_test': {'test_errcapture': (54, 54), 'test_clear': (53, 53), 'test_flit': (52, 50), 'test_cberr': (49, 49), 'test_valid': (48, 48), 'test_data': (47, 28), 'test_mask': (27, 20), 'test_seed': (19, 0)}, 'port_parms': {'vch_err_enable': (34, 31), 'squash_err_enable': (30, 30), 'first_err_enable': (29, 29), 'd_avail_sel': (27, 26), 'max_retry': (25, 16), 'null_timeout': (15, 10), 'max_burst': (9, 0)}, 'channel_age': {'reply_inject_age': (15, 8), 'request_inject_age': (7, 0)}, 'port_errors': {'link_reset_in': (52, 52), 'internal_long': (51, 48), 'internal_short': (47, 44), 'external_bad_header': (43, 40), 'external_long': (39, 36), 'external_short': (35, 32), 'fifo_overflow': (31, 28), 'tail_timeout': (27, 24), 'retry_count': (23, 16), 'cb_error_count': (15, 8), 'sn_error_count': (7, 0)}, 'port_header_a': {'pha_address_b': (61, 35), 'pha_prexsel': (34, 32), 'pha_command': (31, 24), 'pha_destination': (20, 13), 'pha_direction': (12, 9), 'pha_age': (8, 1), 'pha_v': (0, 0)}, 'port_header_b': {'phb_address_c': (45, 38), 'phb_address_a': (37, 35), 'phb_source': (26, 16), 'phb_supplemental': (10, 0)}, 'port_sideband': {'vch_active': (19, 16), 'send_error': (15, 15), 'cb_status': (14, 14), 'sn_status': (13, 13), 'squash': (12, 12), 'bad_message': (11, 11), 'rcv_error': (10, 10), 'bad_prexsel': (9, 9), 'bad_dest': (8, 8), 'sideband': (7, 0)}, 'port_error_clear': {'pec_link_reset_in': (52, 52), 'pec_internal_long': (51, 48), 'pec_internal_short': (47, 44), 'pec_external_bad_header': (43, 40), 'pec_external_long': (39, 36), 'pec_external_short': (35, 32), 'pec_fifo_overflow': (31, 28), 'pec_tail_timeout': (27, 24), 'pec_retry_count': (23, 16), 'pec_cb_error_count': (15, 8), 'pec_sn_error_count': (7, 0)}, 'local_table': {'next_vch_lsb': (4, 4), 'next_exit_port': (3, 0)}, 'global_table': {'next_vch_lsb': (4, 4), 'next_exit_port': (3, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'NI_ERROR_LATCHED_HI': {'value': 52, 'count': 1, 'stride': 1}, 'NI_ERROR_LATCHED_LO': {'value': 24, 'count': 1, 'stride': 1}, 'NI_ERROR_LINK_RESET_BIT': {'value': 52, 'count': 1, 'stride': 1}, 'PORT_PARMS_HEADER_DEFAULT': {'value': 32816176112, 'count': 1, 'stride': 1}}
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
