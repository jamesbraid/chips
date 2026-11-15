"""generated from devices/tiocp/registers-extra.toml by defs-gen - do not edit, change the source
TIOCP registers and constants outside the census"""

UNIT = 'tiocp_extra'
REGISTERS = {'stat': {'offset': 8, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'err_upper': {'offset': 16, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'intr_upper': {'offset': 48, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'tst_pin_ctrl': {'offset': 112, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pci_err_upper': {'offset': 208, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_addr_match_upper': {'offset': 768, 'access': 'rw', 'width': 64, 'count': 16, 'stride': 16, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_addr_match_lower': {'offset': 776, 'access': 'rw', 'width': 64, 'count': 16, 'stride': 16, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_count_flush_w_touch': {'offset': 1024, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_count_flush_wo_touch': {'offset': 1032, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_count_inflight': {'offset': 1040, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_count_prefetch': {'offset': 1048, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_count_total_pci_retry': {'offset': 1056, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_count_max_pci_retry': {'offset': 1064, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_count_max_latency': {'offset': 1072, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_count_clear_all': {'offset': 1080, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_timeout': {'offset': 1592, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ct_debug_ctl': {'offset': 1792, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'br_debug_ctl': {'offset': 1800, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mux3_debug_ctl': {'offset': 1808, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mux4_debug_ctl': {'offset': 1816, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mux5_debug_ctl': {'offset': 1824, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mux6_debug_ctl': {'offset': 1832, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mux7_debug_ctl': {'offset': 1840, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_read_buf_64_cp_buf_addr': {'offset': 2560, 'access': 'rw', 'width': 64, 'count': 16, 'stride': 16, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_read_buf_64_cp_buf_attr': {'offset': 2568, 'access': 'rw', 'width': 64, 'count': 16, 'stride': 16, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_write_buf_64_cp_buf_addr': {'offset': 2816, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_write_buf_64_cp_buf_attr': {'offset': 2824, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_write_buf_64_cp_buf_valid': {'offset': 2832, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_ate_mp': {'offset': 81920, 'access': 'rw', 'width': 64, 'count': 1024, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wr_req_lower': {'offset': 98304, 'access': 'rw', 'width': 64, 'count': 256, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wr_req_upper': {'offset': 100352, 'access': 'rw', 'width': 64, 'count': 256, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wr_req_parity': {'offset': 102400, 'access': 'rw', 'width': 64, 'count': 256, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'rd_resp_lower': {'offset': 114688, 'access': 'rw', 'width': 64, 'count': 512, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'rd_resp_upper': {'offset': 118784, 'access': 'rw', 'width': 64, 'count': 512, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'rd_resp_parity': {'offset': 122880, 'access': 'rw', 'width': 64, 'count': 512, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {'ATE': {'width': 64, 'grade': 'established'}, 'CONTROL_BITS': {'width': 64, 'grade': 'established'}, 'DEVICE_BITS': {'width': 64, 'grade': 'established'}, 'ID': {'width': 32, 'grade': 'established'}, 'INT_ADDR': {'width': 64, 'grade': 'established'}, 'INT_PIN_BITS': {'width': 64, 'grade': 'established'}, 'PCI32_MAPPED_ADDR': {'width': 32, 'grade': 'established'}, 'PCI64_DMA_ADDR': {'width': 64, 'grade': 'established'}}
FIELDS = {'stat': {}, 'err_upper': {}, 'intr_upper': {}, 'tst_pin_ctrl': {}, 'pci_err_upper': {}, 'buf_addr_match_upper': {}, 'buf_addr_match_lower': {}, 'buf_count_flush_w_touch': {}, 'buf_count_flush_wo_touch': {}, 'buf_count_inflight': {}, 'buf_count_prefetch': {}, 'buf_count_total_pci_retry': {}, 'buf_count_max_pci_retry': {}, 'buf_count_max_latency': {}, 'buf_count_clear_all': {}, 'pcix_timeout': {}, 'ct_debug_ctl': {}, 'br_debug_ctl': {}, 'mux3_debug_ctl': {}, 'mux4_debug_ctl': {}, 'mux5_debug_ctl': {}, 'mux6_debug_ctl': {}, 'mux7_debug_ctl': {}, 'pcix_read_buf_64_cp_buf_addr': {}, 'pcix_read_buf_64_cp_buf_attr': {}, 'pcix_write_buf_64_cp_buf_addr': {}, 'pcix_write_buf_64_cp_buf_attr': {}, 'pcix_write_buf_64_cp_buf_valid': {}, 'int_ate_mp': {}, 'wr_req_lower': {}, 'wr_req_upper': {}, 'wr_req_parity': {}, 'rd_resp_lower': {}, 'rd_resp_upper': {}, 'rd_resp_parity': {}, 'ATE': {'bar': (4, 4), 'pref': (3, 3), 'msi': (2, 2), 'pio': (1, 1), 'valid': (0, 0)}, 'CONTROL_BITS': {'page_size': (21, 21)}, 'DEVICE_BITS': {'swap_dir': (19, 19)}, 'ID': {'rev': (31, 28), 'part': (27, 12), 'mfg': (11, 1)}, 'INT_ADDR': {'addr': (53, 0)}, 'INT_PIN_BITS': {'pin': (7, 0)}, 'PCI32_MAPPED_ADDR': {'swap': (29, 29)}, 'PCI64_DMA_ADDR': {'cmdtype': (61, 60), 'pref': (59, 59), 'prec': (58, 58), 'virtual': (57, 57), 'bar': (56, 56), 'swap': (55, 55), 'virtual1': (54, 54)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'ATE_MSI': {'value': 4, 'count': 1, 'stride': 1}, 'ATE_PIO': {'value': 2, 'count': 1, 'stride': 1}, 'CFG_TYPE0_BASE': {'value': 135168, 'count': 1, 'stride': 1}, 'CFG_TYPE1_BASE': {'value': 163840, 'count': 1, 'stride': 1}, 'DEVIO_BASE': {'value': 2097152, 'count': 1, 'stride': 1}, 'DEVIO_FLUSH_BASE': {'value': 10485760, 'count': 1, 'stride': 1}, 'HOST_INTR_ADDR_MASK': {'value': 18014398509481983, 'count': 1, 'stride': 1}, 'PCI64_CMDTYPE_MEM': {'value': 1152921504606846976, 'count': 1, 'stride': 1}, 'PCI64_CMDTYPE_MSI': {'value': 3458764513820540928, 'count': 1, 'stride': 1}, 'PCIX_SPECIAL_CYCLE_BASE': {'value': 262144, 'count': 1, 'stride': 1}, 'PCI_IACK_BASE': {'value': 196608, 'count': 1, 'stride': 1}, 'WAR_PV907516': {'value': 2, 'count': 1, 'stride': 1}}
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
