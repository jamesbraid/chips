"""generated from devices/pic/registers-extra.toml by defs-gen - do not edit, change the source
PIC bits outside the census"""

UNIT = 'pic_extra'
REGISTERS = {'wid_stat': {'offset': 8, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_err_upper': {'offset': 16, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_int_upper': {'offset': 48, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_tst_pin_ctrl': {'offset': 112, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pci_err_upper': {'offset': 208, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_addr_match': {'offset': 768, 'access': 'rw', 'width': 64, 'count': 32, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_flush_w_touch': {'offset': 1024, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_flush_wo_touch': {'offset': 1032, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_inflight': {'offset': 1040, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_prefetch': {'offset': 1048, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_total_pci_retry': {'offset': 1056, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_max_pci_retry': {'offset': 1064, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_max_latency': {'offset': 1072, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'buf_clear_all': {'offset': 1080, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 64, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_timeout': {'offset': 1592, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_read_buf_addr': {'offset': 2560, 'access': 'rw', 'width': 64, 'count': 16, 'stride': 16, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_read_buf_attr': {'offset': 2568, 'access': 'rw', 'width': 64, 'count': 16, 'stride': 16, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_write_buf_addr': {'offset': 2816, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_write_buf_attr': {'offset': 2824, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_write_buf_valid': {'offset': 2832, 'access': 'rw', 'width': 64, 'count': 8, 'stride': 32, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_ate_mp': {'offset': 73728, 'access': 'rw', 'width': 64, 'count': 1024, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'wid_stat': {}, 'wid_err_upper': {}, 'wid_int_upper': {}, 'wid_tst_pin_ctrl': {}, 'pci_err_upper': {}, 'buf_addr_match': {}, 'buf_flush_w_touch': {}, 'buf_flush_wo_touch': {}, 'buf_inflight': {}, 'buf_prefetch': {}, 'buf_total_pci_retry': {}, 'buf_max_pci_retry': {}, 'buf_max_latency': {}, 'buf_clear_all': {}, 'pcix_timeout': {}, 'pcix_read_buf_addr': {}, 'pcix_read_buf_attr': {}, 'pcix_write_buf_addr': {}, 'pcix_write_buf_attr': {}, 'pcix_write_buf_valid': {}, 'int_ate_mp': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'ATE_ADDR_SHIFT': {'value': 12, 'count': 1, 'stride': 1}, 'ATE_BARRIER': {'value': 16, 'count': 1, 'stride': 1}, 'ATE_COHERENT': {'value': 2, 'count': 1, 'stride': 1}, 'ATE_MSI': {'value': 4, 'count': 1, 'stride': 1}, 'ATE_PREFETCH': {'value': 8, 'count': 1, 'stride': 1}, 'ATE_TARGET_SHIFT': {'value': 8, 'count': 1, 'stride': 1}, 'ATE_VALID': {'value': 1, 'count': 1, 'stride': 1}, 'CFG_TYPE0_BASE': {'value': 131072, 'count': 1, 'stride': 1}, 'CFG_TYPE1_BASE': {'value': 163840, 'count': 1, 'stride': 1}, 'CONTROL_PAGE_SIZE_16K': {'value': 2097152, 'count': 1, 'stride': 1}, 'DEVICE_SWAP_DIRECT': {'value': 524288, 'count': 1, 'stride': 1}, 'DIRECT64_ATTR_BARRIER': {'value': 72057594037927936, 'count': 1, 'stride': 1}, 'DIRECT64_ATTR_PRECISE': {'value': 288230376151711744, 'count': 1, 'stride': 1}, 'DIRECT64_ATTR_PREFETCH': {'value': 576460752303423488, 'count': 1, 'stride': 1}, 'DIRECT64_ATTR_SWAP': {'value': 36028797018963968, 'count': 1, 'stride': 1}, 'DIRECT64_ATTR_TARGET_SHIFT': {'value': 60, 'count': 1, 'stride': 1}, 'DIRECT64_ATTR_VIRTUAL': {'value': 144115188075855872, 'count': 1, 'stride': 1}, 'DIRECT64_ATTR_VIRTUAL1': {'value': 18014398509481984, 'count': 1, 'stride': 1}, 'HOST_INTR_ADDR_MASK': {'value': 281474976710655, 'count': 1, 'stride': 1}, 'INTR_FLUSH_WAIT_VALUE': {'value': 271, 'count': 1, 'stride': 1}, 'INTR_PCIX_MASTER_TIMEOUT': {'value': 17179869184, 'count': 1, 'stride': 1}, 'INTR_PCI_MASTER_TIMEOUT': {'value': 2048, 'count': 1, 'stride': 1}, 'INTR_RESET_MULTIPLE_CLEAR': {'value': 64, 'count': 1, 'stride': 1}, 'PCI32_DIRECT_BASE': {'value': 2147483648, 'count': 1, 'stride': 1}, 'PCI32_MAPPED_BASE': {'value': 1073741824, 'count': 1, 'stride': 1}, 'PCI32_MAPPED_SWAP': {'value': 536870912, 'count': 1, 'stride': 1}, 'PCIX_SPECIAL_CYCLE_BASE': {'value': 262144, 'count': 1, 'stride': 1}, 'PCI_IACK_BASE': {'value': 196608, 'count': 1, 'stride': 1}}
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
