"""generated from devices/bedrock_ii/registers.toml by defs-gen - do not edit, change the source
Bedrock I/O interface (II) registers: field layouts, block transfer engines and reset values"""

UNIT = 'bedrock_ii'
REGISTERS = {'widget_id': {'offset': 4194304, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'local_access_protection': {'offset': 4194560, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 18446744073709551615, 'grade': 'established'}, 'protection_override': {'offset': 4194568, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'outbound_widget_access': {'offset': 4194576, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'inbound_widget_access': {'offset': 4194584, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'inbound_device_error_mask': {'offset': 4194592, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'link_control': {'offset': 4194600, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'interrupt_destination': {'offset': 4194616, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pio_request_buffer_w0': {'offset': 4194712, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pio_request_buffer_w8': {'offset': 4194720, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'misc_error_mask': {'offset': 4194792, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 273, 'grade': 'inferred'}, 'error_clear': {'offset': 4194808, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pio_read_address': {'offset': 4195080, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'request_buffer_management': {'offset': 4195240, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'request_buffer_control': {'offset': 4195248, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'crb_a': {'offset': 4195328, 'access': 'r', 'width': 64, 'count': 15, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'crb_b': {'offset': 4195336, 'access': 'r', 'width': 64, 'count': 15, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'crb_c': {'offset': 4195344, 'access': 'r', 'width': 64, 'count': 15, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bte_length_status': {'offset': 4259840, 'access': 'rw', 'width': 64, 'count': 2, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bte_source': {'offset': 4259848, 'access': 'rw', 'width': 64, 'count': 2, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bte_destination': {'offset': 4259856, 'access': 'rw', 'width': 64, 'count': 2, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bte_control': {'offset': 4259864, 'access': 'rw', 'width': 64, 'count': 2, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bte_notification_address': {'offset': 4259872, 'access': 'rw', 'width': 64, 'count': 2, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bte_interrupt_address': {'offset': 4259880, 'access': 'rw', 'width': 64, 'count': 2, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'widget_id': {'revision': (31, 28), 'part': (27, 12), 'manufacturer': (11, 1)}, 'local_access_protection': {'region_enable': (63, 0)}, 'protection_override': {}, 'outbound_widget_access': {'widgets_8_to_f': (15, 8), 'widget_0': (0, 0)}, 'inbound_widget_access': {'widgets_8_to_f': (15, 8), 'widget_0': (0, 0)}, 'inbound_device_error_mask': {'widget_15': (63, 56), 'widget_14': (55, 48), 'widget_13': (47, 40), 'widget_12': (39, 32), 'widget_11': (31, 24), 'widget_10': (23, 16), 'widget_9': (15, 8), 'widget_8': (7, 0)}, 'link_control': {'max_burst': (41, 32), 'data_available_select': (27, 26), 'max_retry': (25, 16), 'remote_power': (14, 14), 'link_status': (13, 12), 'eight_bit_mode': (11, 11), 'link_enable': (10, 10), 'warm_reset': (8, 8), 'null_timeout': (5, 0)}, 'interrupt_destination': {'forwarded_pi1': (33, 33), 'forwarded_pi0': (32, 32), 'sent': (28, 28), 'enable': (24, 24), 'node': (16, 9), 'pi_select': (8, 8), 'level': (6, 0)}, 'pio_request_buffer_w0': {'multiple_errors': (63, 63), 'spurious_read': (51, 51), 'spurious_write': (50, 50), 'read_timeout': (49, 49), 'error': (48, 48), 'overflow_count': (47, 43), 'fire_and_forget': (42, 42), 'mode': (41, 40), 'nack_counter_b': (37, 24), 'nack_counter_a': (21, 8), 'credits': (7, 0)}, 'pio_request_buffer_w8': {'multiple_errors': (63, 63), 'spurious_read': (51, 51), 'spurious_write': (50, 50), 'read_timeout': (49, 49), 'error': (48, 48), 'overflow_count': (47, 43), 'fire_and_forget': (42, 42), 'mode': (41, 40), 'nack_counter_b': (37, 24), 'nack_counter_a': (21, 8), 'credits': (7, 0)}, 'misc_error_mask': {'clear_precise': (12, 12), 'bte_1_enable': (8, 8), 'bte_0_enable': (4, 4), 'widget_0_enable': (0, 0)}, 'error_clear': {'forwarded_pi1': (31, 31), 'forwarded_pi0': (30, 30), 'spurious_read_header': (29, 29), 'internal': (28, 28), 'bte_1': (18, 18), 'bte_0': (17, 17), 'crazy': (16, 16), 'request_buffers_8_to_f': (15, 8), 'request_buffer_0': (0, 0)}, 'pio_read_address': {'valid': (63, 63), 'timeout_count': (62, 58), 'widget': (57, 54), 'source': (51, 44), 'initiator': (43, 41), 'address': (40, 3)}, 'request_buffer_management': {'precise': (52, 52), 'marks': (49, 35), 'valid_bits': (34, 20), 'flow_control_count': (19, 16), 'clear_pending_bit_13': (13, 13), 'clear_pending_bit_12': (12, 12), 'count': (7, 4), 'read_header': (1, 1), 'spurious_message': (0, 0)}, 'request_buffer_control': {'pending': (16, 16), 'command': (15, 8), 'entry': (3, 0)}, 'crb_a': {'bit55': (55, 55), 'type': (54, 52), 'bit51': (51, 51), 'bit50': (50, 50), 'bit49': (49, 49), 'bit0': (0, 0)}, 'crb_b': {'engine_alt': (58, 58), 'sub': (42, 41), 'kind': (32, 30)}, 'crb_c': {'bit48': (48, 48)}, 'bte_length_status': {'busy': (20, 20), 'error': (16, 16), 'length_lines': (15, 0)}, 'bte_source': {'address': (39, 7)}, 'bte_destination': {'address': (39, 7)}, 'bte_control': {'poison': (8, 8), 'notify': (4, 4), 'zero_fill': (0, 0)}, 'bte_notification_address': {'address': (39, 7)}, 'bte_interrupt_address': {'level': (22, 16), 'node': (8, 1), 'pi_select': (0, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'II_WINDOW_BASE': {'value': 29360128, 'count': 1, 'stride': 1}, 'MANUFACTURER_BEDROCK': {'value': 54, 'count': 1, 'stride': 1}, 'PART_BEDROCK': {'value': 49424, 'count': 1, 'stride': 1}, 'PI0_INTERRUPT_PENDING_MODIFY': {'value': 25165968, 'count': 1, 'stride': 1}, 'PI1_INTERRUPT_PENDING_MODIFY': {'value': 27263120, 'count': 1, 'stride': 1}, 'WIDGET_PART_C104': {'value': 49412, 'count': 1, 'stride': 1}, 'WIDGET_PART_C105': {'value': 49413, 'count': 1, 'stride': 1}}
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
