"""generated from defs/seeq_8003.toml by defs-gen - do not edit, change the source
SEEQ 8003 and 80C03 Ethernet data link controller (Indy)"""

UNIT = 'seeq_8003'
REGISTERS = {'station_address': {'offset': 0, 'access': 'w', 'width': 8, 'count': 6, 'stride': 1, 'space': 'bank0', 'reset': 'unknown', 'grade': 'established'}, 'multicast_hash_low': {'offset': 0, 'access': 'w', 'width': 8, 'count': 6, 'stride': 1, 'space': 'bank1', 'reset': 'unknown', 'grade': 'inferred'}, 'multicast_hash_high': {'offset': 0, 'access': 'w', 'width': 8, 'count': 2, 'stride': 1, 'space': 'bank2', 'reset': 'unknown', 'grade': 'inferred'}, 'inter_packet_gap': {'offset': 2, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bank2', 'reset': 'unknown', 'grade': 'inferred'}, 'control': {'offset': 3, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bank2', 'reset': 'unknown', 'grade': 'inferred'}, 'configuration': {'offset': 4, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bank2', 'reset': 'unknown', 'grade': 'inferred'}, 'rx_command': {'offset': 6, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': 'cmd', 'reset': 0, 'grade': 'established'}, 'tx_command': {'offset': 7, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': 'cmd', 'reset': 0, 'grade': 'established'}, 'tx_collisions_low': {'offset': 0, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'rd', 'reset': 0, 'grade': 'inferred'}, 'tx_collisions_high': {'offset': 1, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'rd', 'reset': 0, 'grade': 'inferred'}, 'total_collisions_low': {'offset': 2, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'rd', 'reset': 0, 'grade': 'inferred'}, 'total_collisions_high': {'offset': 3, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'rd', 'reset': 0, 'grade': 'inferred'}, 'test_read': {'offset': 4, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'rd', 'reset': 'unknown', 'grade': 'inferred'}, 'sqe_and_carrier': {'offset': 5, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'rd', 'reset': 'unknown', 'grade': 'inferred'}, 'rx_status': {'offset': 6, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'rd', 'reset': 128, 'grade': 'established'}, 'tx_status': {'offset': 7, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'rd', 'reset': 128, 'grade': 'established'}}
WORDS = {}
FIELDS = {'station_address': {}, 'multicast_hash_low': {}, 'multicast_hash_high': {}, 'inter_packet_gap': {}, 'control': {'no_carrier_flag_enable': (5, 5), 'receive_short_frames': (4, 4), 'multicast_hash_enable': (3, 3), 'sqe_flag_enable': (2, 2), 'total_collision_count_enable': (1, 1), 'tx_collision_count_enable': (0, 0)}, 'configuration': {}, 'rx_command': {'match_mode': (7, 6), 'int_good_frame': (5, 5), 'int_end_of_frame': (4, 4), 'int_short_frame': (3, 3), 'int_dribble_error': (2, 2), 'int_crc_error': (1, 1), 'int_overflow': (0, 0)}, 'tx_command': {'bank': (6, 5), 'int_success': (3, 3), 'int_sixteen_collisions': (2, 2), 'int_collision': (1, 1), 'int_underflow': (0, 0)}, 'tx_collisions_low': {}, 'tx_collisions_high': {'count_bits_10_8': (2, 0)}, 'total_collisions_low': {}, 'total_collisions_high': {}, 'test_read': {}, 'sqe_and_carrier': {'no_carrier_flag': (1, 1), 'sqe_flag': (0, 0)}, 'rx_status': {'old_new': (7, 7), 'good_frame': (5, 5), 'end_of_frame': (4, 4), 'short_frame': (3, 3), 'dribble_error': (2, 2), 'crc_error': (1, 1), 'overflow': (0, 0)}, 'tx_status': {'old_new': (7, 7), 'success': (3, 3), 'sixteen_collisions': (2, 2), 'collision': (1, 1), 'underflow': (0, 0)}}
ENUMS = {'receive_match': {0: 'receiver_off', 1: 'all_frames', 2: 'station_and_broadcast', 3: 'station_broadcast_and_multicast'}, 'bank_select': {0: 'bank0', 1: 'bank1', 2: 'bank2'}}
FIELD_ENUM = {'rx_command.match_mode': 'receive_match', 'tx_command.bank': 'bank_select'}
CONSTANTS = {'FIFO_DEPTH': {'value': 16, 'count': 1, 'stride': 1}, 'SERVICE_INTERVAL_NS': {'value': 800, 'count': 1, 'stride': 1}}
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
