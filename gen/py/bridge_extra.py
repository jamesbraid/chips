"""generated from defs/bridge_extra.toml by defs-gen - do not edit, change the source
Bridge-family registers and bits outside the census"""

UNIT = 'bridge_extra'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'CONTROL_RST_PIN_N': {'value': 251658240, 'count': 1, 'stride': 1}, 'CONTROL_WIDGET_NUMBER': {'value': 15, 'count': 1, 'stride': 1}, 'DEVICE_BARRIER': {'value': 32768, 'count': 1, 'stride': 1}, 'DEVICE_PRECISE': {'value': 131072, 'count': 1, 'stride': 1}, 'DEVICE_PREFETCH': {'value': 262144, 'count': 1, 'stride': 1}, 'DEVICE_REALTIME': {'value': 2097152, 'count': 1, 'stride': 1}, 'DEVICE_SIZE_64': {'value': 4194304, 'count': 1, 'stride': 1}, 'DEVICE_SWAP_PAIR': {'value': 1572864, 'count': 1, 'stride': 1}, 'DEVICE_SWAP_PROGRAMMED': {'value': 8192, 'count': 1, 'stride': 1}, 'DEVICE_WRITE_GATHER_EN': {'value': 25165824, 'count': 1, 'stride': 1}, 'INT_STATUS_INVALID_ADDRESS': {'value': 16777216, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL': {'value': 112, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL_DATA_OUT': {'value': 3840, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL_SELECT0': {'value': 3, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL_SELECT1': {'value': 12, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL_SELECT2': {'value': 48, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL_SELECT3': {'value': 192, 'count': 1, 'stride': 1}, 'XBRIDGE_TEST_PIN_CONTROL_DATA_OUT': {'value': 16711680, 'count': 1, 'stride': 1}}
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
