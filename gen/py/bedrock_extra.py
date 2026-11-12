"""generated from defs/bedrock_extra.toml by defs-gen - do not edit, change the source
Hub and Bedrock network-controller registers outside the census"""

UNIT = 'bedrock_extra'
REGISTERS = {'ii_widget_status': {'offset': 4194312, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ii_shutdown_status': {'offset': 4194792, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ii_error_header_1': {'offset': 4194848, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ii_error_header_2': {'offset': 4194856, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'node_region_mask': {'offset': 16777240, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mem_bank_config': {'offset': 33030152, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'ii_widget_status': {}, 'ii_shutdown_status': {}, 'ii_error_header_1': {}, 'ii_error_header_2': {}, 'node_region_mask': {}, 'mem_bank_config': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'II_CREDIT_TIMEOUT': {'value': 4194784, 'count': 1, 'stride': 1}, 'II_ERROR_HEADER_1_COMMAND': {'value': 127, 'count': 1, 'stride': 1}, 'II_ERROR_HEADER_1_ERR_TYPE': {'value': 64424509440, 'count': 1, 'stride': 1}, 'II_ERROR_HEADER_1_OVERRUN': {'value': 1099511627776, 'count': 1, 'stride': 1}, 'II_ERROR_HEADER_1_PRINT_GATE': {'value': 17592186044416, 'count': 1, 'stride': 1}, 'II_ERROR_HEADER_1_SOURCE': {'value': 2146435072, 'count': 1, 'stride': 1}, 'II_ERROR_HEADER_1_SUPPLEMENTAL': {'value': 524032, 'count': 1, 'stride': 1}, 'II_ERROR_HEADER_2_ADDRESS': {'value': 274877906943, 'count': 1, 'stride': 1}, 'II_ERROR_HEADER_2_TAIL': {'value': 1099511627776, 'count': 1, 'stride': 1}, 'II_READ_RESP_PRESCALE_B_54_32': {'value': 36028792723996672, 'count': 1, 'stride': 1}, 'II_READ_RESP_TIMEOUT_B_59_55': {'value': 1116892707587883008, 'count': 1, 'stride': 1}, 'II_TAIL_TIMEOUT': {'value': 4194800, 'count': 1, 'stride': 1}, 'II_WIDGET_STATUS_CREDIT_TIMEOUT': {'value': 16, 'count': 1, 'stride': 1}, 'II_WIDGET_STATUS_ERROR': {'value': 4294967296, 'count': 1, 'stride': 1}, 'II_WIDGET_STATUS_RETRY_TIMEOUT': {'value': 512, 'count': 1, 'stride': 1}, 'II_WIDGET_STATUS_TAIL_TIMEOUT': {'value': 32, 'count': 1, 'stride': 1}, 'MEM_BANK_CONFIG_BANK_SELECT': {'value': 12884901888, 'count': 1, 'stride': 1}, 'MEM_BANK_CONFIG_B_58_56': {'value': 504403158265495552, 'count': 1, 'stride': 1}, 'MEM_BANK_CONFIG_LANE_ENABLE': {'value': 3, 'count': 1, 'stride': 1}, 'MEM_BANK_CONFIG_LANE_SIZE': {'value': 240, 'count': 1, 'stride': 1}, 'PI_ERROR_SPOOL_SIZE_BASE': {'value': 4096, 'count': 1, 'stride': 1}}
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
