"""generated from devices/hpc3_enet/registers.toml by defs-gen - do not edit, change the source
defs-gen 2
input sha256 2c7abbcb1c2985fa52c20dcda340386f2c9f75c597cf6a1b52429578511083c2
SGI HPC3 Ethernet DMA channels (Indy)"""

UNIT = 'hpc3_enet'
REGISTERS = {'rx_cbp': {'offset': 81920, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'rx_nbdp': {'offset': 81924, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'rx_bc': {'offset': 86016, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'rx_cntl': {'offset': 86020, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'rx_gio': {'offset': 86024, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'rx_dev': {'offset': 86028, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'enet_reset': {'offset': 86036, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'dmacfg': {'offset': 86040, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'piocfg': {'offset': 86044, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'tx_cbp': {'offset': 90112, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'tx_nbdp': {'offset': 90116, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'tx_bc': {'offset': 94208, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'tx_cntl': {'offset': 94212, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'tx_gio': {'offset': 94216, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'tx_dev': {'offset': 94220, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'rx_cur_desc': {'offset': 98304, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'tx_first_cur': {'offset': 106496, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}, 'tx_first_prev': {'offset': 106500, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'hpc3', 'reset': 'unknown', 'grade': 'established'}}
WORDS = {'RX_DESC_CTL': {'width': 32, 'grade': 'established'}, 'TX_DESC_CTL': {'width': 32, 'grade': 'established'}}
FIELDS = {'rx_cbp': {}, 'rx_nbdp': {}, 'rx_bc': {'eox': (31, 31), 'xie': (29, 29), 'count': (13, 0)}, 'rx_cntl': {'rbo': (11, 11), 'ch_active_mask': (10, 10), 'ch_active': (9, 9), 'endian': (8, 8), 'status_7': (7, 7), 'status_6': (6, 6), 'status': (5, 0)}, 'rx_gio': {}, 'rx_dev': {}, 'enet_reset': {'loopback': (2, 2), 'clrint': (1, 1), 'ch_reset': (0, 0)}, 'dmacfg': {'fix_timeout': (17, 16), 'fix_intr': (15, 15), 'fix_eop': (14, 14), 'fix_rxdc': (13, 13), 'wr_ctrl': (12, 12), 'd3': (11, 8), 'd2': (7, 4), 'd1': (3, 0)}, 'piocfg': {'fifo_ram_test': (12, 12), 'p3': (11, 8), 'p2': (7, 4), 'p1': (3, 0)}, 'tx_cbp': {}, 'tx_nbdp': {}, 'tx_bc': {'eox': (31, 31), 'eoxp': (30, 30), 'xie': (29, 29), 'eox_sampled': (28, 28), 'count': (13, 0)}, 'tx_cntl': {'ch_active_mask': (10, 10), 'ch_active': (9, 9), 'endian': (8, 8), 'status_7_5': (7, 5), 'status_4': (4, 4), 'status': (3, 0)}, 'tx_gio': {}, 'tx_dev': {}, 'rx_cur_desc': {}, 'tx_first_cur': {}, 'tx_first_prev': {}, 'RX_DESC_CTL': {'eox': (31, 31), 'eoxp': (30, 30), 'xie': (29, 29), 'own': (14, 14), 'count': (13, 0)}, 'TX_DESC_CTL': {'eox': (31, 31), 'eoxp': (30, 30), 'xie': (29, 29), 'ipg': (23, 16), 'txd': (15, 15), 'count': (13, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {}
TESTS = [('dmacfg', 196646, {'d1': 6, 'd2': 2, 'd3': 0, 'wr_ctrl': 0, 'fix_rxdc': 0, 'fix_eop': 0, 'fix_intr': 0, 'fix_timeout': 3}), ('dmacfg', 253990, {'d1': 6, 'd2': 2, 'd3': 0, 'wr_ctrl': 0, 'fix_rxdc': 1, 'fix_eop': 1, 'fix_intr': 1, 'fix_timeout': 3}), ('piocfg', 353, {'p1': 1, 'p2': 6, 'p3': 1, 'fifo_ram_test': 0})]


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
