"""generated from defs/ioc4_extra.toml by defs-gen - do not edit, change the source
IOC4 registers outside the census"""

UNIT = 'ioc4_extra'
REGISTERS = {'km_rx_kbd': {'offset': 516, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_rx_mouse': {'offset': 520, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_tx_kbd': {'offset': 524, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_tx_mouse': {'offset': 528, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'km_rx_kbd': {}, 'km_rx_mouse': {}, 'km_tx_kbd': {}, 'km_tx_mouse': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'ATA_DMA_CONTROL': {'value': 348, 'count': 1, 'stride': 1}, 'ATA_DMA_CONTROL_ACTIVE': {'value': 8, 'count': 1, 'stride': 1}, 'ATA_DMA_CONTROL_DIR_TO_MEMORY': {'value': 4, 'count': 1, 'stride': 1}, 'ATA_DMA_CONTROL_ERROR': {'value': 16, 'count': 1, 'stride': 1}, 'ATA_DMA_CONTROL_START': {'value': 1, 'count': 1, 'stride': 1}, 'ATA_DMA_CONTROL_STOP': {'value': 2, 'count': 1, 'stride': 1}, 'ATA_DMA_COUNT_DEVICE': {'value': 340, 'count': 1, 'stride': 1}, 'ATA_DMA_COUNT_MEMORY': {'value': 344, 'count': 1, 'stride': 1}, 'ATA_DMA_CURRENT_HIGH': {'value': 336, 'count': 1, 'stride': 1}, 'ATA_DMA_CURRENT_LOW': {'value': 332, 'count': 1, 'stride': 1}, 'ATA_DMA_END_AREA': {'value': 352, 'count': 1, 'stride': 1}, 'ATA_DMA_LIST_HIGH': {'value': 328, 'count': 1, 'stride': 1}, 'ATA_DMA_LIST_LOW': {'value': 324, 'count': 1, 'stride': 1}, 'ATA_DMA_TIMING': {'value': 320, 'count': 1, 'stride': 1}, 'SIO_CR_CMD_PULSE': {'value': 15, 'count': 1, 'stride': 1}, 'SIO_CR_SIO_DIAG_IDLE': {'value': 128, 'count': 1, 'stride': 1}}
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
