"""generated from devices/shub/registers.shub2.toml by defs-gen - do not edit, change the source
SHub 2 registers outside the I/O interface, differences from SHub 1"""

UNIT = 'shub2'
REGISTERS = {'ipi_int': {'offset': 268436352, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'rtc_int_config': {'offset': 268440704, 'access': 'rw', 'width': 64, 'count': 3, 'stride': 256, 'space': None, 'reset': 0, 'grade': 'established'}, 'rtc_int_enable': {'offset': 268440832, 'access': 'rw', 'width': 64, 'count': 3, 'stride': 256, 'space': None, 'reset': 0, 'grade': 'established'}, 'event_occurred': {'offset': 268500992, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'event_occurred_alias': {'offset': 268501000, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ipi_access': {'offset': 268831744, 'access': 'rw', 'width': 64, 'count': 4, 'stride': 128, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_cmp': {'offset': 270205056, 'access': 'rw', 'width': 64, 'count': 3, 'stride': 128, 'space': None, 'reset': 0, 'grade': 'established'}, 'pio_write_status': {'offset': 537330176, 'access': 'r', 'width': 64, 'count': 4, 'stride': 128, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pio_write_status_alias': {'offset': 537330184, 'access': 'w', 'width': 64, 'count': 4, 'stride': 128, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'bt_eng_csr': {'offset': 805568512, 'access': 'rw', 'width': 64, 'count': 4, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bt_eng_src': {'offset': 805568640, 'access': 'rw', 'width': 64, 'count': 4, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bt_eng_dest': {'offset': 805568768, 'access': 'rw', 'width': 64, 'count': 4, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bt_eng_notify': {'offset': 805568896, 'access': 'rw', 'width': 64, 'count': 4, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'junk_bus_led': {'offset': 4026531840, 'access': 'w', 'width': 16, 'count': 4, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ptc': {'offset': 6174015488, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'rtc': {'offset': 8860205056, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'ipi_int': {'send': (63, 63), 'idx': (59, 52), 'base': (49, 21), 'pid': (19, 4), 'agent': (3, 3), 'type': (2, 0)}, 'rtc_int_config': {'idx': (59, 52), 'base': (49, 21), 'pid': (19, 4), 'agent': (3, 3), 'type': (2, 0)}, 'rtc_int_enable': {'enable': (0, 0)}, 'event_occurred': {'ii_int1': (30, 30), 'ii_int0': (29, 29), 'ipi_int': (28, 28), 'rtc3_int': (26, 26), 'rtc2_int': (25, 25), 'rtc1_int': (24, 24), 'rtc0_int': (23, 23), 'bit21': (21, 21), 'uart_int': (20, 20), 'bit8': (8, 8), 'bit5': (5, 5), 'bit3': (3, 3)}, 'event_occurred_alias': {}, 'ipi_access': {}, 'int_cmp': {'compare': (54, 0)}, 'pio_write_status': {'pending_write_count': (61, 56), 'write_deadlock': (1, 1)}, 'pio_write_status_alias': {}, 'bt_eng_csr': {'error_code': (41, 36), 'notify': (28, 28), 'zero_fill': (24, 24), 'busy': (20, 20), 'error': (16, 16), 'length': (15, 0)}, 'bt_eng_src': {}, 'bt_eng_dest': {}, 'bt_eng_notify': {}, 'junk_bus_led': {}, 'ptc': {'start': (63, 63), 'address': (60, 12), 'ps': (3, 2), 'type_bit': (0, 0)}, 'rtc': {'counter': (54, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'EVENT_OCCURRED_EXTIO_INT2': {'value': 8589934592, 'count': 1, 'stride': 1}, 'EVENT_OCCURRED_EXTIO_INT3': {'value': 17179869184, 'count': 1, 'stride': 1}, 'IPI_BASE_VALUE': {'value': 4078, 'count': 1, 'stride': 1}, 'PIO_WRITE_STATUS_ALIAS_CLEAR': {'value': 7, 'count': 1, 'stride': 1}, 'PIO_WRITE_STATUS_IDLE': {'value': 0, 'count': 1, 'stride': 1}, 'PI_CAM_WAR_VALUE': {'value': 9223372036854775824, 'count': 1, 'stride': 1}, 'RTC_CONFIG_MASK': {'value': 1149543804885270527, 'count': 1, 'stride': 1}, 'RTC_ENABLE_MASK': {'value': 1, 'count': 1, 'stride': 1}, 'RTC_MASK': {'value': 36028797018963967, 'count': 1, 'stride': 1}, 'SHUB_1_1_MAX_REVISION': {'value': 2, 'count': 1, 'stride': 1}}
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
