"""generated from defs/ice1724.toml by defs-gen - do not edit, change the source
VIA/IC Ensemble ICE1724 (Envy24HT) PCI audio controller registers"""

UNIT = 'ice1724'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'CCS_AC97_CONF': {'value': 5, 'count': 1, 'stride': 1}, 'CCS_GPIO_DATA': {'value': 20, 'count': 1, 'stride': 1}, 'CCS_GPIO_DATA_HI': {'value': 30, 'count': 1, 'stride': 1}, 'CCS_GPIO_DIR': {'value': 24, 'count': 1, 'stride': 1}, 'CCS_GPIO_MASK': {'value': 22, 'count': 1, 'stride': 1}, 'CCS_GPIO_MASK_HI': {'value': 31, 'count': 1, 'stride': 1}, 'CCS_I2C_BYTE_ADDR': {'value': 17, 'count': 1, 'stride': 1}, 'CCS_I2C_CTRL': {'value': 19, 'count': 1, 'stride': 1}, 'CCS_I2C_DATA': {'value': 18, 'count': 1, 'stride': 1}, 'CCS_I2C_DEV_ADDR': {'value': 16, 'count': 1, 'stride': 1}, 'CCS_I2S_FEATURES': {'value': 6, 'count': 1, 'stride': 1}, 'CCS_IRQ_MASK': {'value': 1, 'count': 1, 'stride': 1}, 'CCS_IRQ_STATUS': {'value': 2, 'count': 1, 'stride': 1}, 'CCS_SPDIF_CONF': {'value': 7, 'count': 1, 'stride': 1}, 'CCS_SYSCONF': {'value': 4, 'count': 1, 'stride': 1}, 'MT_BURST': {'value': 25, 'count': 1, 'stride': 1}, 'MT_CAPTURE_ADDR': {'value': 32, 'count': 1, 'stride': 1}, 'MT_CAPTURE_SIZE': {'value': 36, 'count': 1, 'stride': 1}, 'MT_CONVERTER_RESET': {'value': 5, 'count': 1, 'stride': 1}, 'MT_DMA_CONTROL': {'value': 24, 'count': 1, 'stride': 1}, 'MT_DMA_INT_MASK': {'value': 3, 'count': 1, 'stride': 1}, 'MT_IRQ_STATUS': {'value': 0, 'count': 1, 'stride': 1}, 'MT_MCLK_128X': {'value': 2, 'count': 1, 'stride': 1}, 'MT_PLAYBACK_ADDR': {'value': 16, 'count': 1, 'stride': 1}, 'MT_PLAYBACK_SIZE': {'value': 20, 'count': 1, 'stride': 1}, 'MT_RATE': {'value': 1, 'count': 1, 'stride': 1}, 'MT_SPDIF_OUT_ADDR': {'value': 64, 'count': 1, 'stride': 1}, 'MT_SPDIF_OUT_SIZE': {'value': 68, 'count': 1, 'stride': 1}}
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
