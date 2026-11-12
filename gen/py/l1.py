"""generated from defs/l1.toml by defs-gen - do not edit, change the source
L1 system controller UART path (node-local window), Origin 3000 family"""

UNIT = 'l1'
REGISTERS = {'uart_data': {'offset': 128, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'uart_ier': {'offset': 136, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'uart_fcr_iir': {'offset': 144, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'uart_lcr': {'offset': 152, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'uart_mcr': {'offset': 160, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'uart_lsr': {'offset': 168, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'uart_intr_clear': {'offset': 8388752, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'uart_intr_pending': {'offset': 8388760, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'uart_data': {}, 'uart_ier': {}, 'uart_fcr_iir': {}, 'uart_lcr': {}, 'uart_mcr': {}, 'uart_lsr': {}, 'uart_intr_clear': {}, 'uart_intr_pending': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'UART_DATA_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'UART_DATA_V_44': {'value': 68, 'count': 1, 'stride': 1}, 'UART_DATA_V_7E': {'value': 126, 'count': 1, 'stride': 1}, 'UART_FCR_IIR_B_1': {'value': 2, 'count': 1, 'stride': 1}, 'UART_FCR_IIR_B_2': {'value': 4, 'count': 1, 'stride': 1}, 'UART_FCR_IIR_B_2_1': {'value': 6, 'count': 1, 'stride': 1}, 'UART_FCR_IIR_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'UART_FCR_IIR_V_7': {'value': 7, 'count': 1, 'stride': 1}, 'UART_IER_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'UART_INTR_PENDING_B_4': {'value': 16, 'count': 1, 'stride': 1}, 'UART_LCR_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'UART_LSR_B_0': {'value': 1, 'count': 1, 'stride': 1}, 'UART_LSR_B_15_0': {'value': 65535, 'count': 1, 'stride': 1}, 'UART_LSR_B_3_2': {'value': 12, 'count': 1, 'stride': 1}, 'UART_LSR_B_3_2_0': {'value': 13, 'count': 1, 'stride': 1}, 'UART_LSR_B_5': {'value': 32, 'count': 1, 'stride': 1}, 'UART_LSR_B_6': {'value': 64, 'count': 1, 'stride': 1}, 'UART_LSR_B_7_0': {'value': 255, 'count': 1, 'stride': 1}}
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
