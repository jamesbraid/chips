"""generated from devices/ioc3/registers-extra.toml by defs-gen - do not edit, change the source
defs-gen 2
input sha256 c59900e6424ca5a2f7eb294332632d0801a78dc80e6e82309d0f37c86c0b0889
IOC3 registers outside the census"""

UNIT = 'ioc3_extra'
REGISTERS = {'one_wire_ctl': {'offset': 48, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'plp_a_addr_hi': {'offset': 128, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'plp_a_addr_lo': {'offset': 132, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'plp_a_count': {'offset': 136, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'plp_ctl': {'offset': 140, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'plp_b_addr_hi': {'offset': 144, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'plp_b_addr_lo': {'offset': 148, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'plp_b_count': {'offset': 152, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_rx_kbd': {'offset': 160, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_rx_mouse': {'offset': 164, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_tx_kbd': {'offset': 168, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_tx_mouse': {'offset': 172, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {'GPCR_S_FORMAT': {'width': 32, 'grade': 'inferred'}}
FIELDS = {'one_wire_ctl': {'pulse': (10, 10), 'sample': (2, 2), 'done': (1, 1), 'result': (0, 0)}, 'plp_a_addr_hi': {}, 'plp_a_addr_lo': {}, 'plp_a_count': {}, 'plp_ctl': {}, 'plp_b_addr_hi': {}, 'plp_b_addr_lo': {}, 'plp_b_count': {}, 'km_rx_kbd': {}, 'km_rx_mouse': {}, 'km_tx_kbd': {}, 'km_tx_mouse': {}, 'GPCR_S_FORMAT': {'nic_enable': (21, 21)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'GPCR_S_MICROLAN_ROUTE_BIT': {'value': 2097152, 'count': 1, 'stride': 1}, 'GPCR_S_NIC_ENABLE_WORD': {'value': 2097152, 'count': 1, 'stride': 1}, 'GPPR_LIGHTBAR_RED_PIN': {'value': 1, 'count': 1, 'stride': 1}, 'GPPR_LIGHTBAR_WHITE_PIN': {'value': 0, 'count': 1, 'stride': 1}, 'GPPR_MEANINGFUL_MASK': {'value': 511, 'count': 1, 'stride': 1}, 'GPPR_MICROLAN_PIN': {'value': 8, 'count': 1, 'stride': 1}, 'GPPR_PHY_RESET_PIN': {'value': 5, 'count': 1, 'stride': 1}, 'GPPR_UARTA_MODESEL_PIN': {'value': 7, 'count': 1, 'stride': 1}, 'GPPR_UARTB_MODESEL_PIN': {'value': 6, 'count': 1, 'stride': 1}, 'INT_OUT_COUNT_MASK': {'value': 65535, 'count': 1, 'stride': 1}, 'INT_OUT_DIAG_BIT': {'value': 1073741824, 'count': 1, 'stride': 1}, 'INT_OUT_MODE_HIGH': {'value': 4, 'count': 1, 'stride': 1}, 'INT_OUT_MODE_LOW': {'value': 0, 'count': 1, 'stride': 1}, 'INT_OUT_MODE_MASK': {'value': 458752, 'count': 1, 'stride': 1}, 'INT_OUT_MODE_ONE_PULSE': {'value': 5, 'count': 1, 'stride': 1}, 'INT_OUT_MODE_PULSE_TRAIN': {'value': 6, 'count': 1, 'stride': 1}, 'INT_OUT_MODE_SQUARE': {'value': 7, 'count': 1, 'stride': 1}, 'INT_OUT_PIN0_ROUTE_BIT': {'value': 1048576, 'count': 1, 'stride': 1}, 'INT_OUT_PULSE_TICKS': {'value': 3, 'count': 1, 'stride': 1}, 'INT_OUT_STATE_BIT': {'value': 2147483648, 'count': 1, 'stride': 1}, 'INT_OUT_TICK_NS': {'value': 7800, 'count': 1, 'stride': 1}, 'PORT_CTL_CARRIER_REQ_BIT': {'value': 262144, 'count': 1, 'stride': 1}, 'PORT_CTL_CTS_REQ_BIT': {'value': 524288, 'count': 1, 'stride': 1}, 'PORT_CTL_FLOW_CTL_BIT': {'value': 131072, 'count': 1, 'stride': 1}, 'PORT_CTL_HIGH_WATER_MASK': {'value': 511, 'count': 1, 'stride': 1}, 'PORT_CTL_QUAD_SPEED_BIT': {'value': 1048576, 'count': 1, 'stride': 1}, 'PORT_CTL_RING_DMA_EN_BIT': {'value': 268435456, 'count': 1, 'stride': 1}, 'SIO_CR_ARBITER_IDLE_BIT': {'value': 4194304, 'count': 1, 'stride': 1}, 'SIO_CR_REQUESTER_MASK': {'value': 3670016, 'count': 1, 'stride': 1}, 'SIO_CR_RESET_BIT': {'value': 1, 'count': 1, 'stride': 1}, 'SIO_CR_SER_A_BASE_MASK': {'value': 254, 'count': 1, 'stride': 1}, 'SIO_CR_SER_B_BASE_MASK': {'value': 32512, 'count': 1, 'stride': 1}, 'SIO_CR_STROBE_MASK': {'value': 491520, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_A_CARRIER': {'value': 16, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_A_CTS': {'value': 32, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_A_PCI_ERR': {'value': 256, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_A_RX_FULL': {'value': 2, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_A_RX_HIGH': {'value': 4, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_A_RX_TIMER': {'value': 8, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_A_TX_DONE': {'value': 128, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_A_TX_EMPTY': {'value': 1, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_A_UART': {'value': 64, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_B_CARRIER': {'value': 8192, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_B_CTS': {'value': 16384, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_B_PCI_ERR': {'value': 131072, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_B_RX_FULL': {'value': 1024, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_B_RX_HIGH': {'value': 2048, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_B_RX_TIMER': {'value': 4096, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_B_TX_DONE': {'value': 65536, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_B_TX_EMPTY': {'value': 512, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_B_UART': {'value': 32768, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_KBD': {'value': 4194304, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_PP_PASSTHRU': {'value': 262144, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_PP_PCI_ERR': {'value': 2097152, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_RT_IN_PULSE': {'value': 268435456, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_RT_OUT_PULSE': {'value': 134217728, 'count': 1, 'stride': 1}}
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
