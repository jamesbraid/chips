"""generated from devices/shub/registers.toml by defs-gen - do not edit, change the source
SHub 1 registers outside the I/O interface: interrupts, local block, real-time clock, PIO write status, TLB purge, junk bus LEDs"""

UNIT = 'shub'
REGISTERS = {'md_dqlp_dir_privilege_vector': {'offset': 4295164672, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'md_dqrp_dir_privilege_vector': {'offset': 4295295744, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ipi_int': {'offset': 4563403648, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'rtc_int_config': {'offset': 4563408000, 'access': 'rw', 'width': 64, 'count': 3, 'stride': 256, 'space': None, 'reset': 0, 'grade': 'established'}, 'rtc_int_enable': {'offset': 4563408128, 'access': 'rw', 'width': 64, 'count': 3, 'stride': 256, 'space': None, 'reset': 0, 'grade': 'established'}, 'event_occurred': {'offset': 4563468288, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'event_occurred_alias': {'offset': 4563468296, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ipi_access': {'offset': 4563797120, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'shub_id': {'offset': 4563797376, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ptc': {'offset': 4565106688, 'access': 'w', 'width': 64, 'count': 2, 'stride': 128, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_cmp': {'offset': 4565172352, 'access': 'rw', 'width': 64, 'count': 3, 'stride': 128, 'space': None, 'reset': 0, 'grade': 'established'}, 'rtc': {'offset': 4565237760, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pi_cam_control': {'offset': 4832166656, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pio_write_status': {'offset': 4832297472, 'access': 'r', 'width': 64, 'count': 2, 'stride': 128, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pio_write_status_alias': {'offset': 4832297480, 'access': 'w', 'width': 64, 'count': 2, 'stride': 128, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'junk_bus_led': {'offset': 34339815424, 'access': 'w', 'width': 16, 'count': 4, 'stride': 65536, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'md_dqlp_dir_privilege_vector': {}, 'md_dqrp_dir_privilege_vector': {}, 'ipi_int': {'send': (63, 63), 'idx': (59, 52), 'base': (49, 21), 'pid': (19, 4), 'agent': (3, 3), 'type': (2, 0)}, 'rtc_int_config': {'idx': (59, 52), 'base': (49, 21), 'pid': (19, 4), 'agent': (3, 3), 'type': (2, 0)}, 'rtc_int_enable': {'enable': (0, 0)}, 'event_occurred': {'ii_int1': (30, 30), 'ii_int0': (29, 29), 'ipi_int': (28, 28), 'rtc3_int': (26, 26), 'rtc2_int': (25, 25), 'rtc1_int': (24, 24), 'uart_int': (20, 20)}, 'event_occurred_alias': {}, 'ipi_access': {}, 'shub_id': {'nodes_per_bit': (52, 48), 'revision': (31, 28)}, 'ptc': {'start': (63, 63), 'rid': (62, 8), 'ps': (7, 2), 'type_bit': (0, 0)}, 'int_cmp': {'compare': (54, 0)}, 'rtc': {'counter': (54, 0)}, 'pi_cam_control': {}, 'pio_write_status': {'pending_write_count': (61, 56), 'write_deadlock': (1, 1)}, 'pio_write_status_alias': {}, 'junk_bus_led': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'IPI_BASE_VALUE': {'value': 4078, 'count': 1, 'stride': 1}, 'PIO_WRITE_STATUS_ALIAS_CLEAR': {'value': 7, 'count': 1, 'stride': 1}, 'PIO_WRITE_STATUS_IDLE': {'value': 4539628424389459968, 'count': 1, 'stride': 1}, 'PI_CAM_WAR_VALUE': {'value': 9223372036854775824, 'count': 1, 'stride': 1}, 'RTC_CONFIG_MASK': {'value': 1149543804885270527, 'count': 1, 'stride': 1}, 'RTC_ENABLE_MASK': {'value': 1, 'count': 1, 'stride': 1}, 'RTC_MASK': {'value': 36028797018963967, 'count': 1, 'stride': 1}, 'SHUB_1_1_MAX_REVISION': {'value': 2, 'count': 1, 'stride': 1}}
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
