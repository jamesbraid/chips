"""generated from devices/bridge/registers.toml by defs-gen - do not edit, change the source
Bridge (XIO-to-PCI bridge), Origin 2000 and Octane"""

UNIT = 'bridge'
REGISTERS = {'wid_id': {'offset': 0, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_stat': {'offset': 8, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_err_upper': {'offset': 16, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_err_lower': {'offset': 24, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_control': {'offset': 32, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_req_timeout': {'offset': 40, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_int_upper': {'offset': 48, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_int_lower': {'offset': 56, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_err_cmdword': {'offset': 64, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_llp': {'offset': 72, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_tflush': {'offset': 80, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_aux_err': {'offset': 88, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_resp_upper': {'offset': 96, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wid_resp_lower': {'offset': 104, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'dir_map': {'offset': 128, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ram_perr_or_map_fault': {'offset': 144, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'arb': {'offset': 160, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'bus_timeout': {'offset': 192, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pci_cfg': {'offset': 200, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pci_err_upper': {'offset': 208, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pci_err_lower': {'offset': 216, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_status': {'offset': 256, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_enable': {'offset': 264, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_rst_stat': {'offset': 272, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_mode': {'offset': 280, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_device': {'offset': 288, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_host_err': {'offset': 296, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_addr': {'offset': 304, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'device': {'offset': 512, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'wr_req_buf': {'offset': 576, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'rrb_map': {'offset': 640, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'resp_status': {'offset': 656, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'resp_clear': {'offset': 664, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_ate_ram': {'offset': 65536, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ext_ate_ram': {'offset': 524288, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'wid_id': {}, 'wid_stat': {}, 'wid_err_upper': {}, 'wid_err_lower': {}, 'wid_control': {}, 'wid_req_timeout': {}, 'wid_int_upper': {}, 'wid_int_lower': {}, 'wid_err_cmdword': {}, 'wid_llp': {}, 'wid_tflush': {}, 'wid_aux_err': {}, 'wid_resp_upper': {}, 'wid_resp_lower': {}, 'dir_map': {}, 'ram_perr_or_map_fault': {}, 'arb': {}, 'bus_timeout': {}, 'pci_cfg': {}, 'pci_err_upper': {}, 'pci_err_lower': {}, 'int_status': {}, 'int_enable': {}, 'int_rst_stat': {}, 'int_mode': {}, 'int_device': {}, 'int_host_err': {}, 'int_addr': {}, 'device': {}, 'wr_req_buf': {}, 'rrb_map': {}, 'resp_status': {}, 'resp_clear': {}, 'int_ate_ram': {}, 'ext_ate_ram': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'INT_ADDR_B_10_0': {'value': 2047, 'count': 1, 'stride': 1}, 'INT_ADDR_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'INT_STATUS_B_5': {'value': 32, 'count': 1, 'stride': 1}, 'INT_STATUS_B_6': {'value': 64, 'count': 1, 'stride': 1}, 'RRB_MAP_B_10_0': {'value': 2047, 'count': 1, 'stride': 1}, 'WID_ID_B_10_0': {'value': 2047, 'count': 1, 'stride': 1}, 'WID_ID_B_15_0': {'value': 65535, 'count': 1, 'stride': 1}, 'WID_INT_UPPER_B_5_0': {'value': 63, 'count': 1, 'stride': 1}}
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
