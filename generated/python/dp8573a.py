"""generated from devices/dp8573a/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 3d5cf3c64ca396076a616c64c2650a09e803487e15909b32eb1f6fd64cc9c1d7
National DP8573A real-time clock and battery-backed RAM (Indigo, R3000 and R4000 boards)"""

UNIT = 'dp8573a'
REGISTERS = {'status': {'offset': 3, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'hundredths': {'offset': 23, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'seconds': {'offset': 27, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'minutes': {'offset': 31, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'hours': {'offset': 35, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'day_of_month': {'offset': 39, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'month': {'offset': 43, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'year': {'offset': 47, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'ram_0c': {'offset': 51, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'reg_0d': {'offset': 55, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'unknown'}, 'day_of_week': {'offset': 59, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'cmp_seconds': {'offset': 79, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'cmp_minutes': {'offset': 83, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'cmp_hours': {'offset': 87, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'cmp_day_of_month': {'offset': 91, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'cmp_month': {'offset': 95, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'cmp_day_of_week': {'offset': 99, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'save_seconds': {'offset': 103, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'save_minutes': {'offset': 107, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'save_hours': {'offset': 111, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'save_day_of_month': {'offset': 115, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'save_month': {'offset': 119, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'ram_1e': {'offset': 123, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'ram_test': {'offset': 127, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_common', 'reset': 'unknown', 'grade': 'established'}, 'periodic_flag': {'offset': 15, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_rs0', 'reset': 'unknown', 'grade': 'established'}, 'timesave_ctl': {'offset': 19, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_rs0', 'reset': 'unknown', 'grade': 'established'}, 'rt_mode': {'offset': 7, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_rs1', 'reset': 'unknown', 'grade': 'established'}, 'output_mode': {'offset': 11, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_rs1', 'reset': 'unknown', 'grade': 'established'}, 'int0_ctl': {'offset': 15, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_rs1', 'reset': 'unknown', 'grade': 'established'}, 'int1_ctl': {'offset': 19, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'dp8573a_rs1', 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'status': {'ram7': (7, 7), 'register_select': (6, 6), 'ram5': (5, 5), 'ram4': (4, 4), 'alarm': (3, 3), 'periodic': (2, 2), 'power_fail': (1, 1), 'interrupt_status': (0, 0)}, 'hundredths': {}, 'seconds': {}, 'minutes': {}, 'hours': {}, 'day_of_month': {}, 'month': {}, 'year': {}, 'ram_0c': {}, 'reg_0d': {}, 'day_of_week': {}, 'cmp_seconds': {}, 'cmp_minutes': {}, 'cmp_hours': {}, 'cmp_day_of_month': {}, 'cmp_month': {}, 'cmp_day_of_week': {}, 'save_seconds': {}, 'save_minutes': {}, 'save_hours': {}, 'save_day_of_month': {}, 'save_month': {}, 'ram_1e': {}, 'ram_test': {}, 'periodic_flag': {'test_enable': (7, 7), 'osc_fail_or_single_supply': (6, 6), 'ms': (5, 5), 'ten_ms': (4, 4), 'hundred_ms': (3, 3), 'second': (2, 2), 'ten_second': (1, 1), 'minute': (0, 0)}, 'timesave_ctl': {'enable': (7, 7), 'absent': (6, 6), 'ram': (5, 0)}, 'rt_mode': {'ram': (7, 5), 'int_standby': (4, 4), 'run': (3, 3), 'hour12': (2, 2), 'leap': (1, 0)}, 'output_mode': {'mfo_oscillator': (7, 7), 'ram': (6, 0)}, 'int0_ctl': {'ram': (7, 6), 'ms': (5, 5), 'ten_ms': (4, 4), 'hundred_ms': (3, 3), 'second': (2, 2), 'ten_second': (1, 1), 'minute': (0, 0)}, 'int1_ctl': {'power_fail_int_enable': (7, 7), 'alarm_int_enable': (6, 6), 'cmp_day_of_week': (5, 5), 'cmp_month': (4, 4), 'cmp_day_of_month': (3, 3), 'cmp_hours': (2, 2), 'cmp_minutes': (1, 1), 'cmp_seconds': (0, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'BAD_CLOCK_FLAG': {'value': 1, 'count': 1, 'stride': 1}, 'EPOCH_YEAR': {'value': 1970, 'count': 1, 'stride': 1}, 'INT1_INIT': {'value': 128, 'count': 1, 'stride': 1}, 'LANE_OFFSET': {'value': 3, 'count': 1, 'stride': 1}, 'RAM_TEST_A': {'value': 165, 'count': 1, 'stride': 1}, 'RAM_TEST_B': {'value': 90, 'count': 1, 'stride': 1}, 'RT_RS': {'value': 64, 'count': 1, 'stride': 1}, 'RT_RUN': {'value': 24, 'count': 1, 'stride': 1}, 'RT_TIMSAV_ON': {'value': 128, 'count': 1, 'stride': 1}, 'WINDOW_SIZE': {'value': 128, 'count': 1, 'stride': 1}}
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
