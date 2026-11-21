"""generated from devices/hub_ni/registers-extra.toml by defs-gen - do not edit, change the source
defs-gen 2
input sha256 491bd24195abfc81c22b65262321f9a32808de8e8b25ffb6d0b0aa6ce3827496
Hub network interface field layouts, port and vector fields, and register offsets outside the census"""

UNIT = 'hub_ni_extra'
REGISTERS = {'ni_status_rev_id': {'offset': 6291456, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 131104, 'grade': 'established'}, 'ni_port_reset': {'offset': 6291464, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ni_protection': {'offset': 6291472, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 1, 'grade': 'established'}, 'ni_global_parms': {'offset': 6291480, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 288230367562760432, 'grade': 'established'}, 'ni_diag_parms': {'offset': 6291728, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ni_vector_parms': {'offset': 6291968, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ni_vector_status': {'offset': 6292224, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ni_return_vector': {'offset': 6292232, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ni_vector_clear': {'offset': 6292352, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ni_io_protect': {'offset': 6292480, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 18446744073709551615, 'grade': 'established'}, 'ni_io_prot_ovrrd': {'offset': 6292488, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ni_age_cpu0_memory': {'offset': 6292736, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_cpu0_pio': {'offset': 6292744, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_cpu1_memory': {'offset': 6292752, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_cpu1_pio': {'offset': 6292760, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_gbr_memory': {'offset': 6292768, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_gbr_pio': {'offset': 6292776, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_io_memory': {'offset': 6292784, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_io_pio': {'offset': 6292792, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_port_parms': {'offset': 6324224, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 7152, 'grade': 'established'}, 'ni_port_error': {'offset': 6324232, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ni_port_error_clear': {'offset': 6324360, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ni_meta_entry': {'offset': 6520840, 'access': 'rw', 'width': 64, 'count': 31, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'ni_local_entry': {'offset': 6521096, 'access': 'rw', 'width': 64, 'count': 15, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'ni_status_rev_id': {'eightbit_mode': (30, 30), 'link_up': (29, 29), 'down_reason': (28, 28), 'more_nodes': (18, 18), 'region_size': (17, 17), 'node_id': (16, 8), 'chip_rev': (7, 4), 'chip_id': (3, 0)}, 'ni_port_reset': {'warm_reset': (7, 7), 'link_reset': (1, 1), 'local_reset': (0, 0)}, 'ni_protection': {'reset_ok': (0, 0)}, 'ni_global_parms': {'max_retry': (57, 48), 'tail_timeout_wrap': (47, 32), 'credit_timeout': (19, 16), 'tail_timeout': (7, 4)}, 'ni_diag_parms': {'port_timeout_reset': (18, 18), 'llp_8bit_mode': (12, 12), 'port_disable': (6, 6), 'send_error': (0, 0)}, 'ni_vector_parms': {'pio_id': (49, 40), 'write_id': (39, 32), 'address': (19, 3), 'pio_type': (1, 0)}, 'ni_vector_status': {'valid': (63, 63), 'overrun': (62, 62), 'target': (60, 51), 'pio_id': (49, 40), 'write_id': (39, 32), 'address': (31, 3), 'pio_type': (2, 0)}, 'ni_return_vector': {}, 'ni_vector_clear': {}, 'ni_io_protect': {}, 'ni_io_prot_ovrrd': {}, 'ni_age_cpu0_memory': {'vchannel': (11, 10), 'congestion': (9, 8), 'age': (7, 0)}, 'ni_age_cpu0_pio': {'vchannel': (11, 10), 'congestion': (9, 8), 'age': (7, 0)}, 'ni_age_cpu1_memory': {'vchannel': (11, 10), 'congestion': (9, 8), 'age': (7, 0)}, 'ni_age_cpu1_pio': {'vchannel': (11, 10), 'congestion': (9, 8), 'age': (7, 0)}, 'ni_age_gbr_memory': {'vchannel': (11, 10), 'congestion': (9, 8), 'age': (7, 0)}, 'ni_age_gbr_pio': {'vchannel': (11, 10), 'congestion': (9, 8), 'age': (7, 0)}, 'ni_age_io_memory': {'vchannel': (11, 10), 'congestion': (9, 8), 'age': (7, 0)}, 'ni_age_io_pio': {'vchannel': (11, 10), 'congestion': (9, 8), 'age': (7, 0)}, 'ni_port_parms': {'null_timeout': (15, 10), 'max_burst': (9, 0)}, 'ni_port_error': {'link_reset': (37, 37), 'internal_error': (36, 36), 'bad_message': (35, 35), 'bad_destination': (34, 34), 'queue_overflow': (33, 33), 'credit_timeout_count': (31, 28), 'tail_timeout_count': (27, 24), 'retry_count': (23, 16), 'check_bit_error_count': (15, 8), 'sequence_error_count': (7, 0)}, 'ni_port_error_clear': {'link_reset': (37, 37), 'internal_error': (36, 36), 'bad_message': (35, 35), 'bad_destination': (34, 34), 'queue_overflow': (33, 33), 'credit_timeout_count': (31, 28), 'tail_timeout_count': (27, 24), 'retry_count': (23, 16), 'check_bit_error_count': (15, 8), 'sequence_error_count': (7, 0)}, 'ni_meta_entry': {}, 'ni_local_entry': {}}
ENUMS = {'ni_node_mode': {0: 'more_memory', 1: 'more_nodes'}, 'ni_region_size': {0: 'coarse', 1: 'fine'}, 'ni_pio_request_type': {0: 'read', 1: 'write', 2: 'undefined', 3: 'exchange'}, 'ni_pio_type': {0: 'read', 1: 'write', 2: 'undefined', 3: 'exchange', 4: 'address_error', 5: 'command_error', 6: 'protection_error', 7: 'unknown'}, 'ni_vchannel': {0: 'channel_a', 1: 'channel_b', 2: 'any'}}
FIELD_ENUM = {'ni_status_rev_id.more_nodes': 'ni_node_mode', 'ni_status_rev_id.region_size': 'ni_region_size', 'ni_vector_parms.pio_type': 'ni_pio_request_type', 'ni_vector_status.pio_type': 'ni_pio_type', 'ni_age_cpu0_memory.vchannel': 'ni_vchannel', 'ni_age_cpu0_pio.vchannel': 'ni_vchannel', 'ni_age_cpu1_memory.vchannel': 'ni_vchannel', 'ni_age_cpu1_pio.vchannel': 'ni_vchannel', 'ni_age_gbr_memory.vchannel': 'ni_vchannel', 'ni_age_gbr_pio.vchannel': 'ni_vchannel', 'ni_age_io_memory.vchannel': 'ni_vchannel', 'ni_age_io_pio.vchannel': 'ni_vchannel'}
CONSTANTS = {'NI_BASE': {'value': 6291456, 'count': 1, 'stride': 1}, 'NI_BASE_TABLES': {'value': 6488064, 'count': 1, 'stride': 1}, 'NI_LOCAL_ENTRIES': {'value': 16, 'count': 1, 'stride': 1}, 'NI_META_ENTRIES': {'value': 32, 'count': 1, 'stride': 1}, 'NI_NASID_TO_COARSEREG_SHIFT': {'value': 3, 'count': 1, 'stride': 1}, 'NI_NASID_TO_FINEREG_SHIFT': {'value': 0, 'count': 1, 'stride': 1}, 'NI_PORT_ERROR_COUNT_MAX': {'value': 255, 'count': 1, 'stride': 1}, 'NI_PORT_PARMS_DEFAULTS': {'value': 7152, 'count': 1, 'stride': 1}, 'NI_PORT_PARMS_HUB20_DEFAULTS': {'value': 2032, 'count': 1, 'stride': 1}}
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
