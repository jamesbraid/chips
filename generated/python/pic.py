"""generated from devices/pic/registers.toml by defs-gen - do not edit, change the source
defs-gen 2
input sha256 3d439cd5a9c6040f4c489f3ad4fdb170d8de283af94a577d7c9668ef96e26cc9
PIC (dual-head PCI-X bridge), Origin 3000 family"""

UNIT = 'pic'
REGISTERS = {'pcibr_bridge_ptr': {'offset': 0, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bus_err': {'offset': 24, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ssram_size': {'offset': 32, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'req_timeout': {'offset': 40, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'intr_dst_target_id': {'offset': 56, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'cmdword_err': {'offset': 64, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'llp_cfg': {'offset': 72, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'tflush': {'offset': 80, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'linkside_err': {'offset': 88, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'resp_err_buf': {'offset': 96, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'resp_err': {'offset': 104, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'linkside_err_addr': {'offset': 120, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'dirmap_wid': {'offset': 128, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ssram_parity': {'offset': 144, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'arbitration': {'offset': 160, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'parity_err': {'offset': 176, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'timeout': {'offset': 192, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'type1_cntr': {'offset': 200, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pci_bus_addr': {'offset': 216, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'intr_status': {'offset': 256, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'intr_enable': {'offset': 264, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'intr_reset': {'offset': 272, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'intr_mode': {'offset': 280, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'intr_device': {'offset': 288, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'intr_host_err': {'offset': 296, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'intr_addr_vect': {'offset': 304, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'intr_view': {'offset': 368, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'intr_multiple': {'offset': 376, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'force_always': {'offset': 384, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'force_intr': {'offset': 448, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'device': {'offset': 512, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wrb_flush': {'offset': 576, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'rrb': {'offset': 640, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'rrb_status': {'offset': 656, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'rrb_clear': {'offset': 664, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_bus_err_addr': {'offset': 1536, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_bus_err_attr': {'offset': 1544, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_bus_err_data': {'offset': 1552, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_pio_split_addr': {'offset': 1560, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_pio_split_attr': {'offset': 1568, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_req_err_attr': {'offset': 1576, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pcix_req_err_addr': {'offset': 1584, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_ate': {'offset': 65536, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pic_attach2': {'offset': 98304, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pic_attach2_18800': {'offset': 100352, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pic_attach2_19000': {'offset': 102400, 'access': 'w', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ext_ate': {'offset': 524288, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'pcibr_bridge_ptr': {}, 'bus_err': {}, 'ssram_size': {}, 'req_timeout': {}, 'intr_dst_target_id': {}, 'cmdword_err': {}, 'llp_cfg': {}, 'tflush': {}, 'linkside_err': {}, 'resp_err_buf': {}, 'resp_err': {}, 'linkside_err_addr': {}, 'dirmap_wid': {}, 'ssram_parity': {}, 'arbitration': {}, 'parity_err': {}, 'timeout': {}, 'type1_cntr': {}, 'pci_bus_addr': {}, 'intr_status': {}, 'intr_enable': {}, 'intr_reset': {}, 'intr_mode': {}, 'intr_device': {}, 'intr_host_err': {}, 'intr_addr_vect': {}, 'intr_view': {}, 'intr_multiple': {}, 'force_always': {}, 'force_intr': {}, 'device': {}, 'wrb_flush': {}, 'rrb': {}, 'rrb_status': {}, 'rrb_clear': {}, 'pcix_bus_err_addr': {}, 'pcix_bus_err_attr': {}, 'pcix_bus_err_data': {}, 'pcix_pio_split_addr': {}, 'pcix_pio_split_attr': {}, 'pcix_req_err_attr': {}, 'pcix_req_err_addr': {}, 'int_ate': {}, 'pic_attach2': {}, 'pic_attach2_18800': {}, 'pic_attach2_19000': {}, 'ext_ate': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'INTR_ADDR_VECT_B_10_0': {'value': 2047, 'count': 1, 'stride': 1}, 'INTR_ADDR_VECT_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'INTR_DST_TARGET_ID_V_A5A5': {'value': 42405, 'count': 1, 'stride': 1}, 'INTR_DST_TARGET_ID_V_A5A50000': {'value': 2779054080, 'count': 1, 'stride': 1}, 'INT_ATE_B_10_0': {'value': 2047, 'count': 1, 'stride': 1}, 'LINKSIDE_ERR_ADDR_V_BEEF': {'value': 48879, 'count': 1, 'stride': 1}, 'PCIBR_BRIDGE_PTR_B_10_0': {'value': 2047, 'count': 1, 'stride': 1}, 'PCIBR_BRIDGE_PTR_B_15_0': {'value': 65535, 'count': 1, 'stride': 1}, 'RRB_B_10_0': {'value': 2047, 'count': 1, 'stride': 1}, 'SSRAM_SIZE_B_5_4': {'value': 48, 'count': 1, 'stride': 1}}
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
