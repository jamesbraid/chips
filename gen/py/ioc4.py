"""generated from defs/ioc4.toml by defs-gen - do not edit, change the source
IOC4 (PCI I/O controller, later)"""

UNIT = 'ioc4'
REGISTERS = {'pci_err_addr_l': {'offset': 0, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pci_err_addr_h': {'offset': 4, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'sio_ir': {'offset': 8, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'other_ir': {'offset': 12, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'sio_ies': {'offset': 16, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'other_ies': {'offset': 20, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'sio_iec': {'offset': 24, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'other_iec': {'offset': 28, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'sio_cr': {'offset': 32, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ioc4_attach': {'offset': 36, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'int_out': {'offset': 40, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'gpcr_s': {'offset': 48, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'gpcr_c': {'offset': 52, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'gppr0': {'offset': 64, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_csr': {'offset': 512, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'sbbr01_l': {'offset': 768, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'sbbr01_h': {'offset': 772, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'sbbr23_l': {'offset': 776, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'sbbr23_h': {'offset': 780, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port0_sscr': {'offset': 784, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port0_stpir': {'offset': 788, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port0_stcir': {'offset': 792, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port0_srpir': {'offset': 796, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port0_srcir': {'offset': 800, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port0_srtr': {'offset': 804, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'port0_shadow': {'offset': 808, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'uart0_reg0': {'offset': 896, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'uart0_reg4': {'offset': 900, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'cfg_id': {'offset': 2097152, 'access': 'r', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'cfg_command_status': {'offset': 2097156, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'cfg_revision': {'offset': 2097160, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'pci_err_addr_l': {}, 'pci_err_addr_h': {}, 'sio_ir': {}, 'other_ir': {}, 'sio_ies': {}, 'other_ies': {}, 'sio_iec': {}, 'other_iec': {}, 'sio_cr': {}, 'ioc4_attach': {}, 'int_out': {}, 'gpcr_s': {}, 'gpcr_c': {}, 'gppr0': {}, 'km_csr': {}, 'sbbr01_l': {}, 'sbbr01_h': {}, 'sbbr23_l': {}, 'sbbr23_h': {}, 'port0_sscr': {}, 'port0_stpir': {}, 'port0_stcir': {}, 'port0_srpir': {}, 'port0_srcir': {}, 'port0_srtr': {}, 'port0_shadow': {}, 'uart0_reg0': {}, 'uart0_reg4': {}, 'cfg_id': {}, 'cfg_command_status': {}, 'cfg_revision': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'CFG_COMMAND_STATUS_B_0': {'value': 1, 'count': 1, 'stride': 1}, 'CFG_COMMAND_STATUS_B_1': {'value': 2, 'count': 1, 'stride': 1}, 'CFG_COMMAND_STATUS_B_15_0': {'value': 65535, 'count': 1, 'stride': 1}, 'CFG_COMMAND_STATUS_V_146': {'value': 326, 'count': 1, 'stride': 1}, 'CFG_REVISION_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'GPCR_C_V_2': {'value': 2, 'count': 1, 'stride': 1}, 'GPCR_S_V_200': {'value': 512, 'count': 1, 'stride': 1}, 'GPCR_S_V_FF00': {'value': 65280, 'count': 1, 'stride': 1}, 'OTHER_IR_V_40': {'value': 64, 'count': 1, 'stride': 1}, 'OTHER_IR_V_FF800000': {'value': 4286578688, 'count': 1, 'stride': 1}, 'PCI_ERR_ADDR_L_B_0': {'value': 1, 'count': 1, 'stride': 1}, 'PCI_ERR_ADDR_L_B_1': {'value': 2, 'count': 1, 'stride': 1}, 'PCI_ERR_ADDR_L_B_3_0': {'value': 15, 'count': 1, 'stride': 1}, 'PCI_ERR_ADDR_L_B_3_1': {'value': 14, 'count': 1, 'stride': 1}, 'PCI_ERR_ADDR_L_B_5': {'value': 32, 'count': 1, 'stride': 1}, 'PORT0_SRCIR_V_80000000': {'value': 2147483648, 'count': 1, 'stride': 1}, 'PORT0_SRPIR_B_11_3': {'value': 4088, 'count': 1, 'stride': 1}, 'PORT0_SRTR_V_A0': {'value': 160, 'count': 1, 'stride': 1}, 'PORT0_SSCR_V_20000000': {'value': 536870912, 'count': 1, 'stride': 1}, 'PORT0_SSCR_V_8000000': {'value': 134217728, 'count': 1, 'stride': 1}, 'PORT0_SSCR_V_80000000': {'value': 2147483648, 'count': 1, 'stride': 1}, 'PORT0_STCIR_B_11_3': {'value': 4088, 'count': 1, 'stride': 1}, 'SBBR01_L_V_1': {'value': 1, 'count': 1, 'stride': 1}, 'SBBR23_L_V_1': {'value': 1, 'count': 1, 'stride': 1}, 'SIO_CR_B_7': {'value': 128, 'count': 1, 'stride': 1}, 'SIO_CR_V_F': {'value': 15, 'count': 1, 'stride': 1}, 'SIO_IR_B_0': {'value': 1, 'count': 1, 'stride': 1}, 'UART0_REG0_V_1': {'value': 1, 'count': 1, 'stride': 1}, 'UART0_REG0_V_3': {'value': 3, 'count': 1, 'stride': 1}, 'UART0_REG0_V_4': {'value': 4, 'count': 1, 'stride': 1}, 'UART0_REG0_V_40': {'value': 64, 'count': 1, 'stride': 1}, 'UART0_REG0_V_7': {'value': 7, 'count': 1, 'stride': 1}, 'UART0_REG0_V_80': {'value': 128, 'count': 1, 'stride': 1}, 'UART0_REG4_B_5': {'value': 32, 'count': 1, 'stride': 1}}
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
