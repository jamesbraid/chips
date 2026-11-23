"""generated from devices/xframe/registers.toml by defs-gen - do not edit, change the source
defs-gen 3
input sha256 3f1ba58411bf364f6941e22e5f572e709f77f3c0d7ce1256a016fceffaeb02e0
Neterion Xframe 10-Gigabit Ethernet controller (SGI 10-Gigabit Ethernet card), the offsets, bits and layouts the held sources establish"""

UNIT = 'xframe'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'ADAPTER_STATUS_RMAC_LOCAL_FAULT': {'value': 72057594037927936, 'count': 1, 'stride': 1}, 'ADAPTER_STATUS_RMAC_REMOTE_FAULT': {'value': 144115188075855872, 'count': 1, 'stride': 1}, 'DESCRIPTOR_PAGE_BYTES': {'value': 4096, 'count': 1, 'stride': 1}, 'DMA_CHANNELS': {'value': 16, 'count': 1, 'stride': 1}, 'GENERAL_INT_MASK_ENABLE': {'value': 0, 'count': 1, 'stride': 1}, 'MAC_RMAC_ERR_REG_OFFSET': {'value': 8232, 'count': 1, 'stride': 1}, 'MAC_RMAC_LINK_STATE_CHANGE': {'value': 4294967296, 'count': 1, 'stride': 1}, 'PIC_INT_MASK_OFFSET': {'value': 2056, 'count': 1, 'stride': 1}, 'PIC_INT_TX': {'value': 9223372036854775808, 'count': 1, 'stride': 1}, 'RING_MODE_1': {'value': 0, 'count': 1, 'stride': 1}, 'RING_MODE_3': {'value': 1, 'count': 1, 'stride': 1}, 'RING_MODE_5': {'value': 2, 'count': 1, 'stride': 1}, 'RXD_FIVE_BUFFER_BYTES': {'value': 64, 'count': 1, 'stride': 1}, 'RXD_FIVE_BUFFER_CONTROL_WORDS': {'value': 3, 'count': 1, 'stride': 1}, 'RXD_FIVE_BUFFER_POINTERS': {'value': 5, 'count': 1, 'stride': 1}, 'SCHEDULED_INT_CTRL_OFFSET': {'value': 2328, 'count': 1, 'stride': 1}, 'SCHED_INT_CTRL_TIMER_EN': {'value': 9223372036854775808, 'count': 1, 'stride': 1}, 'SWAPPER_CTRL_HIGH_OFFSET': {'value': 2316, 'count': 1, 'stride': 1}, 'SWAPPER_CTRL_HIGH_VALUE': {'value': 4294961919, 'count': 1, 'stride': 1}, 'SWAPPER_CTRL_LOW_OFFSET': {'value': 2312, 'count': 1, 'stride': 1}, 'SWAPPER_CTRL_LOW_VALUE': {'value': 2885664767, 'count': 1, 'stride': 1}, 'TXD_WORDS': {'value': 4, 'count': 1, 'stride': 1}, 'TXPIC_INT_MASK_OFFSET': {'value': 2072, 'count': 1, 'stride': 1}, 'TXPIC_INT_REG_OFFSET': {'value': 2064, 'count': 1, 'stride': 1}, 'WATCHDOG_CHECK_SECONDS': {'value': 1, 'count': 1, 'stride': 1}, 'WATCHDOG_RESET_COUNT': {'value': 15, 'count': 1, 'stride': 1}}
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
