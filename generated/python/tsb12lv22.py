"""generated from devices/tsb12lv22/registers.toml by defs-gen - do not edit, change the source
defs-gen 2
input sha256 7c0c9c2e3187c6789010517cad60bcc61d96bd60b2a5cd37bd3bb1bc955da983
TI TSB12LV22 PCI-to-IEEE 1394 OHCI 1.00 link controller (I-brick IO7), the register facts the held sources establish"""

UNIT = 'tsb12lv22'
REGISTERS = {'version': {'offset': 0, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 65536, 'grade': 'established'}, 'guid_rom': {'offset': 4, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'retry_counts': {'offset': 8, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'csr_data': {'offset': 12, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'csr_compare': {'offset': 16, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'csr_control': {'offset': 20, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'config_rom_header': {'offset': 24, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bus_id': {'offset': 28, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 825440564, 'grade': 'established'}, 'bus_options': {'offset': 32, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'guid_hi': {'offset': 36, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'guid_lo': {'offset': 40, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'config_rom_map': {'offset': 52, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'posted_write_error': {'offset': 56, 'access': 'r', 'width': 32, 'count': 2, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'vendor_specific_id': {'offset': 64, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'hc_control': {'offset': 80, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'self_id_buffer': {'offset': 100, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'self_id_count': {'offset': 104, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'recv_channel_mask_hi': {'offset': 112, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'recv_channel_mask_lo': {'offset': 120, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_event': {'offset': 128, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_mask': {'offset': 136, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'iso_xmit_event': {'offset': 144, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'iso_xmit_mask': {'offset': 152, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'iso_recv_event': {'offset': 160, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'iso_recv_mask': {'offset': 168, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'fairness_control': {'offset': 220, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'link_control': {'offset': 224, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'node_id': {'offset': 232, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'phy_control': {'offset': 236, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'cycle_timer': {'offset': 240, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'async_filter_hi': {'offset': 256, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'async_filter_lo': {'offset': 264, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'phys_filter_hi': {'offset': 272, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'phys_filter_lo': {'offset': 280, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'phys_upper_bound': {'offset': 288, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}}
WORDS = {}
FIELDS = {'version': {'rom_present': (24, 24), 'major': (23, 16), 'minor': (7, 0)}, 'guid_rom': {'address_reset': (31, 31), 'read_start': (25, 25), 'read_data': (23, 16)}, 'retry_counts': {'dual_phase_retry': (31, 16), 'count_11_8': (11, 8), 'count_7_4': (7, 4), 'count_3_0': (3, 0)}, 'csr_data': {}, 'csr_compare': {}, 'csr_control': {'done': (31, 31), 'resource_select': (1, 0)}, 'config_rom_header': {}, 'bus_id': {}, 'bus_options': {'max_rec': (15, 12), 'link_speed': (2, 0)}, 'guid_hi': {}, 'guid_lo': {}, 'config_rom_map': {}, 'posted_write_error': {}, 'vendor_specific_id': {}, 'hc_control': {'no_byte_swap_data': (30, 30), 'program_phy_enable': (23, 23), 'aphy_enhance_enable': (22, 22), 'lps': (19, 19), 'posted_write_enable': (18, 18), 'link_enable': (17, 17), 'soft_reset': (16, 16)}, 'self_id_buffer': {'address': (31, 11)}, 'self_id_count': {'error': (31, 31), 'generation': (23, 16), 'size': (10, 2)}, 'recv_channel_mask_hi': {}, 'recv_channel_mask_lo': {}, 'int_event': {'phy_reg_received': (19, 19), 'bus_reset': (17, 17), 'self_id_complete': (16, 16), 'iso_recv_summary': (7, 7), 'iso_xmit_summary': (6, 6)}, 'int_mask': {'master_int_enable': (31, 31)}, 'iso_xmit_event': {'contexts': (7, 0)}, 'iso_xmit_mask': {'contexts': (7, 0)}, 'iso_recv_event': {'contexts': (3, 0)}, 'iso_recv_mask': {'contexts': (3, 0)}, 'fairness_control': {'priority_request_limit': (7, 0)}, 'link_control': {'cycle_source': (22, 22), 'cycle_master': (21, 21), 'cycle_timer_enable': (20, 20), 'rcv_phy_packets': (10, 10), 'rcv_self_id_packets': (9, 9)}, 'node_id': {'id_valid': (31, 31), 'root': (30, 30), 'bus_number': (15, 6), 'node_number': (5, 0)}, 'phy_control': {'rd_done': (31, 31), 'rd_addr': (27, 24), 'rd_data': (23, 16), 'rd_reg': (15, 15), 'wr_reg': (14, 14), 'reg_addr': (11, 8), 'wr_data': (7, 0)}, 'cycle_timer': {'seconds': (31, 25), 'count': (24, 12), 'offset': (11, 0)}, 'async_filter_hi': {'nonlocal_enable': (31, 31)}, 'async_filter_lo': {}, 'phys_filter_hi': {}, 'phys_filter_lo': {}, 'phys_upper_bound': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'BUS_ID_TEXT': {'value': 825440564, 'count': 1, 'stride': 1}, 'CYCLE_TIMER_CLOCK_HZ': {'value': 24576000, 'count': 1, 'stride': 1}, 'ISO_CHANNELS': {'value': 64, 'count': 1, 'stride': 1}, 'MAX_REC_DEFAULT': {'value': 10, 'count': 1, 'stride': 1}, 'PCI_DEVICE_ID': {'value': 32777, 'count': 1, 'stride': 1}, 'PCI_REVISION': {'value': 1, 'count': 1, 'stride': 1}, 'PCI_VENDOR_ID': {'value': 4172, 'count': 1, 'stride': 1}, 'PHY_CLOCK_HZ': {'value': 49152000, 'count': 1, 'stride': 1}, 'SELF_ID_BUFFER_ALIGN': {'value': 2048, 'count': 1, 'stride': 1}}
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
