"""generated from devices/cobalt_mc/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 73f90f85d2cdc65dda9e1c8485d018d0bbc17dbb41d1f46b9ab0ab950e2b71a5
Cobalt memory controller of the SGI Visual Workstation 320 and 540: ECC control, error reporting and the bank registers"""

UNIT = 'cobalt_mc'
REGISTERS = {'ecc_control': {'offset': 0, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'mc', 'reset': 'unknown', 'grade': 'established'}, 'delay_period': {'offset': 8, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'mc', 'reset': 'unknown', 'grade': 'inferred'}, 'delay_counter': {'offset': 16, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'mc', 'reset': 'unknown', 'grade': 'inferred'}, 'error_status': {'offset': 24, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'mc', 'reset': 'unknown', 'grade': 'established'}, 'error_address': {'offset': 40, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'mc', 'reset': 'unknown', 'grade': 'established'}, 'error_syndrome': {'offset': 48, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'mc', 'reset': 'unknown', 'grade': 'established'}, 'dimm_speed_check': {'offset': 72, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'mc', 'reset': 'unknown', 'grade': 'inferred'}, 'bank': {'offset': 80, 'access': 'rw', 'width': 32, 'count': 16, 'stride': 8, 'space': 'mc', 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'ecc_control': {'ecc_enable': (0, 0)}, 'delay_period': {}, 'delay_counter': {}, 'error_status': {'syndrome_only': (17, 17), 'nonfatal': (16, 16)}, 'error_address': {}, 'error_syndrome': {}, 'dimm_speed_check': {'speed_ok': (16, 16)}, 'bank': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'BANK_ABSENT': {'value': 0, 'count': 1, 'stride': 1}, 'BANK_FIRST_LITE': {'value': 72, 'count': 1, 'stride': 1}, 'BANK_FULL': {'value': 3, 'count': 1, 'stride': 1}, 'BANK_PARTIAL': {'value': 2, 'count': 1, 'stride': 1}, 'BANK_SLOTS': {'value': 16, 'count': 1, 'stride': 1}, 'BANK_SPAN': {'value': 134217728, 'count': 1, 'stride': 1}, 'BASE': {'value': 3321888768, 'count': 1, 'stride': 1}}
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
