"""generated from devices/bridge/registers-extra.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 d79809f695c80a0f37db113eb9f4cd966cf14bc3f14cab4c534195c46a2ac4f8
Bridge-family registers and bits outside the census"""

UNIT = 'bridge_extra'
REGISTERS = {}
WORDS = {'WID_ID_FORMAT': {'width': 32, 'grade': 'established'}}
FIELDS = {'WID_ID_FORMAT': {'part': (27, 12), 'manufacturer': (11, 1)}}
ENUMS = {'WID_ID_FORMAT.part': {49154: 'bridge', 53250: 'xbridge', 53506: 'pic_bus0', 53522: 'pic_bus1', 57344: 'tiocp_a', 57360: 'tiocp_b'}, 'WID_ID_FORMAT.manufacturer': {36: 'mfr_36', 54: 'mfr_54'}}
FIELD_ENUM = {'WID_ID_FORMAT.part': 'WID_ID_FORMAT.part', 'WID_ID_FORMAT.manufacturer': 'WID_ID_FORMAT.manufacturer'}
CONSTANTS = {'CFG_FUNC_SHIFT': {'value': 8, 'count': 1, 'stride': 1}, 'CFG_SLOTS_32': {'value': 8, 'count': 1, 'stride': 1}, 'CFG_SLOT_BIAS_64': {'value': 1, 'count': 1, 'stride': 1}, 'CFG_SLOT_SHIFT': {'value': 12, 'count': 1, 'stride': 1}, 'CFG_WINDOW32_OFFSET': {'value': 131072, 'count': 1, 'stride': 1}, 'CONTROL_FLASH_WR_EN': {'value': 2147483648, 'count': 1, 'stride': 1}, 'CONTROL_RST_PIN_N': {'value': 251658240, 'count': 1, 'stride': 1}, 'CONTROL_WIDGET_NUMBER': {'value': 15, 'count': 1, 'stride': 1}, 'DEVICE_BARRIER': {'value': 32768, 'count': 1, 'stride': 1}, 'DEVICE_PRECISE': {'value': 131072, 'count': 1, 'stride': 1}, 'DEVICE_PREFETCH': {'value': 262144, 'count': 1, 'stride': 1}, 'DEVICE_REALTIME': {'value': 2097152, 'count': 1, 'stride': 1}, 'DEVICE_SIZE_64': {'value': 4194304, 'count': 1, 'stride': 1}, 'DEVICE_SWAP_PAIR': {'value': 1572864, 'count': 1, 'stride': 1}, 'DEVICE_SWAP_PROGRAMMED': {'value': 8192, 'count': 1, 'stride': 1}, 'DEVICE_WRITE_GATHER_EN': {'value': 25165824, 'count': 1, 'stride': 1}, 'INTR_ADDR32_HI': {'value': 17, 'count': 1, 'stride': 1}, 'INTR_ADDR32_LO': {'value': 8, 'count': 1, 'stride': 1}, 'INTR_ADDR32_OFFSET': {'value': 308, 'count': 1, 'stride': 1}, 'INTR_ADDR32_SRC_HI': {'value': 47, 'count': 1, 'stride': 1}, 'INTR_ADDR32_SRC_LO': {'value': 38, 'count': 1, 'stride': 1}, 'INTR_ADDR64_OFFSET': {'value': 304, 'count': 1, 'stride': 1}, 'INTR_COUNT': {'value': 8, 'count': 1, 'stride': 1}, 'INTR_STRIDE': {'value': 8, 'count': 1, 'stride': 1}, 'INT_STATUS_INVALID_ADDRESS': {'value': 16777216, 'count': 1, 'stride': 1}, 'STATUS_FLASH_SELECT': {'value': 64, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL': {'value': 112, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL_DATA_OUT': {'value': 3840, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL_SELECT0': {'value': 3, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL_SELECT1': {'value': 12, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL_SELECT2': {'value': 48, 'count': 1, 'stride': 1}, 'TEST_PIN_CONTROL_SELECT3': {'value': 192, 'count': 1, 'stride': 1}, 'WID_OFFSET': {'value': 4, 'count': 1, 'stride': 1}, 'WINDOW_BIT_A': {'value': 63, 'count': 1, 'stride': 1}, 'WINDOW_BIT_B': {'value': 60, 'count': 1, 'stride': 1}, 'WINDOW_BIT_C': {'value': 57, 'count': 1, 'stride': 1}, 'XBRIDGE_TEST_PIN_CONTROL_DATA_OUT': {'value': 16711680, 'count': 1, 'stride': 1}}
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
