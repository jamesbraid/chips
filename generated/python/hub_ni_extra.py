"""generated from devices/hub_ni/registers-extra.toml by defs-gen - do not edit, change the source
Hub network interface field layouts, port and vector fields, and register offsets outside the census"""

UNIT = 'hub_ni_extra'
REGISTERS = {'ni_return_vector': {'offset': 6292232, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ni_io_protect': {'offset': 6292480, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 18446744073709551615, 'grade': 'established'}, 'ni_io_prot_ovrrd': {'offset': 6292488, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ni_age_cpu0_pio': {'offset': 6292744, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_cpu1_pio': {'offset': 6292760, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_gbr_memory': {'offset': 6292768, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_gbr_pio': {'offset': 6292776, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_io_memory': {'offset': 6292784, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_age_io_pio': {'offset': 6292792, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'established'}, 'ni_port_parms': {'offset': 6324224, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 7152, 'grade': 'established'}, 'ni_meta_entry': {'offset': 6520840, 'access': 'rw', 'width': 64, 'count': 31, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'ni_local_entry': {'offset': 6521096, 'access': 'rw', 'width': 64, 'count': 15, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {'NI_AGE_FORMAT': {'width': 64, 'grade': 'established'}, 'NI_DIAG_PARMS_FORMAT': {'width': 64, 'grade': 'established'}, 'NI_GLOBAL_PARMS_FORMAT': {'width': 64, 'grade': 'established'}, 'NI_PORT_ERROR_FORMAT': {'width': 64, 'grade': 'established'}, 'NI_PORT_RESET_FORMAT': {'width': 64, 'grade': 'established'}, 'NI_PROTECTION_FORMAT': {'width': 64, 'grade': 'established'}, 'NI_STATUS_FORMAT': {'width': 64, 'grade': 'established'}, 'NI_VECTOR_PARMS_FORMAT': {'width': 64, 'grade': 'established'}, 'NI_VECTOR_STATUS_FORMAT': {'width': 64, 'grade': 'established'}}
FIELDS = {'ni_return_vector': {}, 'ni_io_protect': {}, 'ni_io_prot_ovrrd': {}, 'ni_age_cpu0_pio': {}, 'ni_age_cpu1_pio': {}, 'ni_age_gbr_memory': {}, 'ni_age_gbr_pio': {}, 'ni_age_io_memory': {}, 'ni_age_io_pio': {}, 'ni_port_parms': {'null_timeout': (15, 10), 'max_burst': (9, 0)}, 'ni_meta_entry': {}, 'ni_local_entry': {}, 'NI_AGE_FORMAT': {'vchannel': (11, 10), 'congestion': (9, 8), 'age': (7, 0)}, 'NI_DIAG_PARMS_FORMAT': {'port_timeout_reset': (18, 18), 'llp_8bit_mode': (12, 12), 'port_disable': (6, 6), 'send_error': (0, 0)}, 'NI_GLOBAL_PARMS_FORMAT': {'max_retry': (57, 48), 'tail_timeout_wrap': (47, 32), 'credit_timeout': (19, 16), 'tail_timeout': (7, 4)}, 'NI_PORT_ERROR_FORMAT': {'link_reset': (37, 37), 'internal_error': (36, 36), 'bad_message': (35, 35), 'bad_destination': (34, 34), 'queue_overflow': (33, 33), 'credit_timeout_count': (31, 28), 'tail_timeout_count': (27, 24), 'retry_count': (23, 16), 'check_bit_error_count': (15, 8), 'sequence_error_count': (7, 0)}, 'NI_PORT_RESET_FORMAT': {'warm_reset': (7, 7), 'link_reset': (1, 1), 'local_reset': (0, 0)}, 'NI_PROTECTION_FORMAT': {'reset_ok': (0, 0)}, 'NI_STATUS_FORMAT': {'eightbit_mode': (30, 30), 'link_up': (29, 29), 'down_reason': (28, 28), 'more_nodes': (18, 18), 'region_size': (17, 17), 'node_id': (16, 8), 'chip_rev': (7, 4), 'chip_id': (3, 0)}, 'NI_VECTOR_PARMS_FORMAT': {'pio_id': (49, 40), 'write_id': (39, 32), 'address': (19, 3), 'pio_type': (1, 0)}, 'NI_VECTOR_STATUS_FORMAT': {'valid': (63, 63), 'overrun': (62, 62), 'target': (60, 51), 'pio_id': (49, 40), 'write_id': (39, 32), 'address': (31, 3), 'pio_type': (2, 0)}}
ENUMS = {'ni_vchannel': {0: 'channel_a', 1: 'channel_b', 2: 'any'}, 'ni_node_mode': {0: 'more_memory', 1: 'more_nodes'}, 'ni_region_size': {0: 'coarse', 1: 'fine'}, 'ni_pio_request_type': {0: 'read', 1: 'write', 2: 'undefined', 3: 'exchange'}, 'ni_pio_type': {0: 'read', 1: 'write', 2: 'undefined', 3: 'exchange', 4: 'address_error', 5: 'command_error', 6: 'protection_error', 7: 'unknown'}}
FIELD_ENUM = {'NI_AGE_FORMAT.vchannel': 'ni_vchannel', 'NI_STATUS_FORMAT.more_nodes': 'ni_node_mode', 'NI_STATUS_FORMAT.region_size': 'ni_region_size', 'NI_VECTOR_PARMS_FORMAT.pio_type': 'ni_pio_request_type', 'NI_VECTOR_STATUS_FORMAT.pio_type': 'ni_pio_type'}
CONSTANTS = {'NI_LOCAL_ENTRIES': {'value': 16, 'count': 1, 'stride': 1}, 'NI_META_ENTRIES': {'value': 32, 'count': 1, 'stride': 1}, 'NI_PORT_ERROR_COUNT_MAX': {'value': 255, 'count': 1, 'stride': 1}, 'NI_PORT_PARMS_DEFAULTS': {'value': 7152, 'count': 1, 'stride': 1}, 'NI_PORT_PARMS_HUB20_DEFAULTS': {'value': 2032, 'count': 1, 'stride': 1}}
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
