"""generated from devices/ds1685/registers.toml by defs-gen - do not edit, change the source
Dallas DS1685/DS1687 real-time clock and battery-backed RAM (Octane and Octane2 system boards)"""

UNIT = 'ds1685'
REGISTERS = {'user_ram': {'offset': 14, 'access': 'rw', 'width': 8, 'count': 114, 'stride': 1, 'space': 'bank0', 'reset': 'unknown', 'grade': 'inferred'}, 'model': {'offset': 64, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bank1', 'reset': 'unknown', 'grade': 'established'}, 'serial': {'offset': 65, 'access': 'r', 'width': 8, 'count': 6, 'stride': 1, 'space': 'bank1', 'reset': 'unknown', 'grade': 'established'}, 'serial_crc': {'offset': 71, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bank1', 'reset': 'unknown', 'grade': 'established'}, 'century': {'offset': 72, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bank1', 'reset': 'unknown', 'grade': 'established'}, 'date_alarm': {'offset': 73, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bank1', 'reset': 'unknown', 'grade': 'established'}, 'ctrl4a': {'offset': 74, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bank1', 'reset': 'unknown', 'grade': 'inferred'}, 'ctrl4b': {'offset': 75, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bank1', 'reset': 'unknown', 'grade': 'inferred'}, 'ext_ram_address': {'offset': 80, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bank1', 'reset': 'unknown', 'grade': 'inferred'}, 'ext_ram_data': {'offset': 83, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bank1', 'reset': 'unknown', 'grade': 'inferred'}, 'seconds': {'offset': 0, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'common', 'reset': 'unknown', 'grade': 'inferred'}, 'alarm_seconds': {'offset': 1, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'common', 'reset': 'unknown', 'grade': 'inferred'}, 'minutes': {'offset': 2, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'common', 'reset': 'unknown', 'grade': 'inferred'}, 'alarm_minutes': {'offset': 3, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'common', 'reset': 'unknown', 'grade': 'inferred'}, 'hours': {'offset': 4, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'common', 'reset': 'unknown', 'grade': 'inferred'}, 'alarm_hours': {'offset': 5, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'common', 'reset': 'unknown', 'grade': 'inferred'}, 'day_of_week': {'offset': 6, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'common', 'reset': 'unknown', 'grade': 'inferred'}, 'date': {'offset': 7, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'common', 'reset': 'unknown', 'grade': 'inferred'}, 'month': {'offset': 8, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'common', 'reset': 'unknown', 'grade': 'inferred'}, 'year': {'offset': 9, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'common', 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'user_ram': {}, 'model': {}, 'serial': {}, 'serial_crc': {}, 'century': {}, 'date_alarm': {}, 'ctrl4a': {'incr': (6, 6), 'pab': (3, 3), 'kickstart_flag': (0, 0)}, 'ctrl4b': {}, 'ext_ram_address': {}, 'ext_ram_data': {}, 'seconds': {}, 'alarm_seconds': {}, 'minutes': {}, 'alarm_minutes': {}, 'hours': {}, 'alarm_hours': {}, 'day_of_week': {}, 'date': {}, 'month': {}, 'year': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'BANK0_RAM_BYTES': {'value': 114, 'count': 1, 'stride': 1}, 'EXT_RAM_BYTES': {'value': 128, 'count': 1, 'stride': 1}, 'RAM_CLEAR_RECOVERY_MS': {'value': 150, 'count': 1, 'stride': 1}, 'RAM_TOTAL_BYTES': {'value': 242, 'count': 1, 'stride': 1}}
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
