"""generated from devices/hub/registers-extra.toml by defs-gen - do not edit, change the source
Hub block transfer engine registers and control bits outside the census"""

UNIT = 'hub_extra'
REGISTERS = {'iio_wid': {'offset': 4194304, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 470814792, 'grade': 'inferred'}, 'iio_ilapr': {'offset': 4194560, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 18446744073709551615, 'grade': 'inferred'}, 'iio_ilapo': {'offset': 4194568, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'iio_igfx_1': {'offset': 4194632, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'iio_scratch_reg0': {'offset': 4194640, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'iio_scratch_reg1': {'offset': 4194648, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'iio_itte': {'offset': 4194656, 'access': 'rw', 'width': 64, 'count': 7, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'iio_icrb_a': {'offset': 4195328, 'access': 'rw', 'width': 64, 'count': 15, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'iio_icrb_b': {'offset': 4195336, 'access': 'rw', 'width': 64, 'count': 15, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'iio_icrb_c': {'offset': 4195344, 'access': 'r', 'width': 64, 'count': 15, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'iio_icrb_d': {'offset': 4195352, 'access': 'r', 'width': 64, 'count': 15, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'iio_ibna_0': {'offset': 4259872, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'iio_ibia_0': {'offset': 4259880, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'iio_ibia_1': {'offset': 4325416, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 0, 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'iio_wid': {'rev': (31, 28), 'part': (27, 12), 'mfg': (11, 1)}, 'iio_ilapr': {}, 'iio_ilapo': {}, 'iio_igfx_1': {'valid': (20, 20), 'processor': (16, 16), 'node': (12, 4), 'widget': (3, 0)}, 'iio_scratch_reg0': {}, 'iio_scratch_reg1': {}, 'iio_itte': {'iospace': (12, 12), 'widget': (11, 8), 'slice': (4, 0)}, 'iio_icrb_a': {}, 'iio_icrb_b': {}, 'iio_icrb_c': {}, 'iio_icrb_d': {}, 'iio_ibna_0': {}, 'iio_ibia_0': {'level': (22, 16), 'node': (8, 0)}, 'iio_ibia_1': {'level': (22, 16), 'node': (8, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'IIO_IBCT_NOTIFY': {'value': 16, 'count': 1, 'stride': 1}, 'IIO_IBCT_POISON': {'value': 256, 'count': 1, 'stride': 1}, 'IIO_IBCT_ZFIL_MODE': {'value': 1, 'count': 1, 'stride': 1}, 'IIO_IBLS_BUSY': {'value': 1048576, 'count': 1, 'stride': 1}, 'IIO_IECLR_BTE0': {'value': 131072, 'count': 1, 'stride': 1}, 'IIO_IECLR_BTE1': {'value': 262144, 'count': 1, 'stride': 1}, 'IIO_IIDSR_ENB': {'value': 16777216, 'count': 1, 'stride': 1}, 'IIO_IIDSR_LVL_MASK': {'value': 63, 'count': 1, 'stride': 1}, 'IIO_IIDSR_NODE_MASK': {'value': 65280, 'count': 1, 'stride': 1}, 'IIO_IIDSR_SENT': {'value': 268435456, 'count': 1, 'stride': 1}, 'IIO_ILCSR_BM8': {'value': 2048, 'count': 1, 'stride': 1}, 'IIO_ILCSR_LLP_EN': {'value': 1024, 'count': 1, 'stride': 1}, 'IIO_ILCSR_MAX_BURST_MASK': {'value': 4393751543808, 'count': 1, 'stride': 1}, 'IIO_ILCSR_MAX_RETRY_MASK': {'value': 67043328, 'count': 1, 'stride': 1}, 'IIO_ILCSR_NULL_TO_MASK': {'value': 63, 'count': 1, 'stride': 1}, 'IIO_ILCSR_WARM_RESET': {'value': 256, 'count': 1, 'stride': 1}, 'IIO_ILLR_CB_CNT_MASK': {'value': 4294901760, 'count': 1, 'stride': 1}, 'IIO_ILLR_SN_CNT_MASK': {'value': 65535, 'count': 1, 'stride': 1}, 'IIO_ITTE_BASE': {'value': 4194656, 'count': 1, 'stride': 1}, 'IIO_ITTE_INVALID_WIDGET': {'value': 3, 'count': 1, 'stride': 1}, 'IIO_ITTE_IOSP': {'value': 4096, 'count': 1, 'stride': 1}, 'IIO_LLP_CSR_IS_UP': {'value': 8192, 'count': 1, 'stride': 1}, 'IIO_LLP_CSR_LLP_STAT_MASK': {'value': 12288, 'count': 1, 'stride': 1}, 'IIO_WCR_DIR_CON': {'value': 131072, 'count': 1, 'stride': 1}, 'IIO_WCR_WIDGET_ID_MASK': {'value': 15, 'count': 1, 'stride': 1}, 'IIO_WID_PART_HUB': {'value': 49409, 'count': 1, 'stride': 1}, 'IIO_WSTAT_ECRAZY': {'value': 4294967296, 'count': 1, 'stride': 1}, 'IIO_WSTAT_TXRETRY': {'value': 512, 'count': 1, 'stride': 1}, 'IIO_WSTAT_TXRETRY_MASK': {'value': 8323072, 'count': 1, 'stride': 1}, 'LNK_STAT_WORKING': {'value': 2, 'count': 1, 'stride': 1}}
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
