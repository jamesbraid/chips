"""generated from devices/tio/registers.toml by defs-gen - do not edit, change the source
defs-gen 2
input sha256 b463b599a6e231ec27eb619f305e4db2b5869fa84254ccd3fe4d207973c9b22e
TIO (NUMAlink I/O node ASIC of the Altix generation), as SGI's Linux platform code names its registers"""

UNIT = 'tio'
REGISTERS = {'node_id': {'offset': 2416316032, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ice_frz_cfg': {'offset': 2952823040, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'itte': {'offset': 2952824832, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ice_pmi_tx_cfg': {'offset': 2952835328, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ice_pmi_tx_dyn_credit_stat_cb3': {'offset': 2952838680, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'node_id': {'nodes_per_bit_pow2': (53, 48), 'node': (45, 32), 'rev': (31, 28), 'part': (27, 12), 'mfg': (11, 1)}, 'ice_frz_cfg': {'disable_conveyor': (61, 61)}, 'itte': {'valid': (16, 16), 'widget': (13, 12), 'offset': (7, 0)}, 'ice_pmi_tx_cfg': {}, 'ice_pmi_tx_dyn_credit_stat_cb3': {'credit_count': (3, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'BIG_WINDOW_SIZE_BITS': {'value': 30, 'count': 1, 'stride': 1}, 'CE_PART_NUMBER': {'value': 52736, 'count': 1, 'stride': 1}, 'CTALK_CHIPLET_SHIFT': {'value': 38, 'count': 1, 'stride': 1}, 'CTALK_NASID_SHIFT': {'value': 40, 'count': 1, 'stride': 1}, 'ERROR_VECTOR': {'value': 54, 'count': 1, 'stride': 1}, 'ERROR_VECTOR_TIOCA': {'value': 53, 'count': 1, 'stride': 1}, 'ERROR_VECTOR_TIOCX': {'value': 55, 'count': 1, 'stride': 1}, 'FPGA_CORELET': {'value': 3, 'count': 1, 'stride': 1}, 'INTR_VECTOR_SHIFT': {'value': 56, 'count': 1, 'stride': 1}, 'KLTYPE_TIO': {'value': 18, 'count': 1, 'stride': 1}, 'SAL_HUB_ERROR_INTERRUPT': {'value': 33554528, 'count': 1, 'stride': 1}, 'SAL_IOIF_INTERRUPT': {'value': 33554506, 'count': 1, 'stride': 1}, 'SMALL_WINDOW_SIZE_BITS': {'value': 28, 'count': 1, 'stride': 1}, 'WIDGET_ID_OFFSET': {'value': 0, 'count': 1, 'stride': 1}}
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
