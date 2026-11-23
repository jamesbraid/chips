"""generated from devices/bedrock_lb/registers.toml by defs-gen - do not edit, change the source
defs-gen 3
input sha256 b37d365dbb57af8f38c2d786617250b65c049cb8d901dc94e622247577944aba
Bedrock local block (LB) registers: field layouts, reset statements and the vector engine"""

UNIT = 'bedrock_lb'
REGISTERS = {'rev_id': {'offset': 6291456, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 587276361, 'grade': 'established'}, 'cpu_permission': {'offset': 6307840, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 1152921504606846975, 'grade': 'established'}, 'cpu_permission_override': {'offset': 6307848, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'io_permission': {'offset': 6307856, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'soft_reset': {'offset': 6307864, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'region_present': {'offset': 6307872, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 1152921504606846975, 'grade': 'established'}, 'nodes_absent': {'offset': 6307880, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'microlan_ctl': {'offset': 6307888, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 13391364098, 'grade': 'established'}, 'error_bits': {'offset': 6307904, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'error_mask_clr': {'offset': 6307912, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'error_hdr1': {'offset': 6307920, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'error_hdr2': {'offset': 6307928, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'error_data': {'offset': 6307936, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'debug_select': {'offset': 6308096, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'debug_pins': {'offset': 6308104, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'rt_local_ctrl': {'offset': 6308352, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 4294968896, 'grade': 'established'}, 'rt_filter_ctrl': {'offset': 6308360, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'scratch0': {'offset': 6324224, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'scratch1': {'offset': 6324232, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'scratch2': {'offset': 6324240, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'scratch3': {'offset': 6324248, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'scratch4': {'offset': 6324256, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'scratch0_wz': {'offset': 6324288, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'scratch1_wz': {'offset': 6324296, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'scratch2_wz': {'offset': 6324304, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'scratch3_rz': {'offset': 6324312, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'scratch4_rz': {'offset': 6324320, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'vector_parms': {'offset': 6340608, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'vector_route': {'offset': 6340616, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'vector_data': {'offset': 6340624, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'vector_status': {'offset': 6340640, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'vector_return': {'offset': 6340648, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'vector_read_data': {'offset': 6340656, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'vector_status_clear': {'offset': 6340664, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}}
WORDS = {}
FIELDS = {'rev_id': {'region_size': (47, 46), 'node_id': (39, 32), 'revision': (31, 28), 'part_number': (27, 12), 'manufacturer': (11, 1)}, 'cpu_permission': {'region_enable': (63, 0)}, 'cpu_permission_override': {}, 'io_permission': {'region_enable': (63, 0)}, 'soft_reset': {'soft_reset': (0, 0)}, 'region_present': {'present': (63, 0)}, 'nodes_absent': {'entry3_valid': (63, 63), 'entry3_node': (55, 48), 'entry2_valid': (47, 47), 'entry2_node': (39, 32), 'entry1_valid': (31, 31), 'entry1_node': (23, 16), 'entry0_valid': (15, 15), 'entry0_node': (7, 0)}, 'microlan_ctl': {'clkdiv_phi1': (33, 27), 'clkdiv_phi0': (26, 20), 'low_pulse': (19, 10), 'sample_offset': (9, 2), 'done': (1, 1), 'read_data': (0, 0)}, 'error_bits': {'gclk_drop': (10, 10), 'rq_bad_inval': (9, 9), 'rq_bad_addr': (8, 8), 'rp_bad_data': (7, 7), 'rq_bad_data': (6, 6), 'rp_long': (5, 5), 'rq_long': (4, 4), 'rp_short': (3, 3), 'rq_short': (2, 2), 'rp_bad_cmd': (1, 1), 'rq_bad_cmd': (0, 0)}, 'error_mask_clr': {'clear': (10, 0)}, 'error_hdr1': {'valid': (44, 44), 'overrun': (40, 40), 'err_type': (35, 32), 'source': (30, 20), 'suppl': (18, 8), 'command': (6, 0)}, 'error_hdr2': {'address': (37, 0)}, 'error_data': {'flit': (63, 0)}, 'debug_select': {'select': (5, 0)}, 'debug_pins': {'pins': (31, 0)}, 'rt_local_ctrl': {'use_internal': (32, 32), 'gclk': (28, 28), 'gclk_counter': (25, 16), 'max_count': (13, 4), 'gclk_enable': (0, 0)}, 'rt_filter_ctrl': {'error_counter': (57, 48), 'dropout_threshold': (45, 36), 'dropout_counter': (33, 24), 'mask_enable': (20, 20), 'mask_counter': (19, 8), 'offset': (4, 0)}, 'scratch0': {'bits': (63, 0)}, 'scratch1': {'bits': (63, 0)}, 'scratch2': {'bits': (63, 0)}, 'scratch3': {'bit': (0, 0)}, 'scratch4': {'bit': (0, 0)}, 'scratch0_wz': {'bits': (63, 0)}, 'scratch1_wz': {'bits': (63, 0)}, 'scratch2_wz': {'bits': (63, 0)}, 'scratch3_rz': {'bit': (0, 0)}, 'scratch4_rz': {'bit': (0, 0)}, 'vector_parms': {'busy': (63, 63), 'pio_id': (50, 40), 'write_id': (39, 32), 'address': (23, 3), 'type': (1, 0)}, 'vector_route': {}, 'vector_data': {}, 'vector_status': {'valid': (63, 63), 'overrun': (62, 62), 'source': (61, 51), 'pio_id': (50, 40), 'write_id': (39, 32), 'address': (23, 3), 'type_or_error': (2, 0)}, 'vector_return': {}, 'vector_read_data': {}, 'vector_status_clear': {'valid': (63, 63), 'overrun': (62, 62), 'source': (61, 51), 'pio_id': (50, 40), 'write_id': (39, 32), 'address': (23, 3), 'type_or_error': (2, 0)}}
ENUMS = {'region_size': {0: 'fine', 1: 'coarse', 2: 'nmode', 3: 'invalid'}, 'vector_op': {0: 'read', 1: 'write', 2: 'undefined', 3: 'exchange'}, 'vector_reply_type': {0: 'read', 1: 'write', 2: 'undefined', 3: 'exchange', 4: 'address_error', 5: 'command_error', 6: 'protection_error', 7: 'unknown_error'}}
FIELD_ENUM = {'rev_id.region_size': 'region_size', 'vector_parms.type': 'vector_op', 'vector_status.type_or_error': 'vector_reply_type', 'vector_status_clear.type_or_error': 'vector_reply_type'}
CONSTANTS = {'CHIP_PART_BEDROCK': {'value': 12306, 'count': 1, 'stride': 1}, 'ERROR_PI_PEND1_BIT': {'value': 55, 'count': 1, 'stride': 1}, 'REVISION_1_0': {'value': 1, 'count': 1, 'stride': 1}, 'REVISION_1_1': {'value': 2, 'count': 1, 'stride': 1}, 'RTC_FREQ_KHZ_CONFIG': {'value': 1250, 'count': 1, 'stride': 1}}
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
