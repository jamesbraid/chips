"""generated from devices/ioc4/registers-extra.toml by defs-gen - do not edit, change the source
IOC4 registers outside the census"""

UNIT = 'ioc4_extra'
REGISTERS = {'gpdr': {'offset': 56, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_rx_kbd': {'offset': 516, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_rx_mouse': {'offset': 520, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_tx_kbd': {'offset': 524, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'km_tx_mouse': {'offset': 528, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {'ATA_DMA_CONTROL_WORD': {'width': 32, 'grade': 'established'}, 'ATA_PRD_LENGTH_WORD': {'width': 32, 'grade': 'established'}, 'GPCR_WORD': {'width': 32, 'grade': 'established'}, 'GPDR_WORD': {'width': 32, 'grade': 'established'}, 'GPPR_WORD': {'width': 32, 'grade': 'established'}, 'INT_OUT_WORD': {'width': 32, 'grade': 'established'}, 'OTHER_IR_WORD': {'width': 32, 'grade': 'established'}, 'PCI_ERR_ADDR_L_WORD': {'width': 32, 'grade': 'established'}, 'RX_STATUS_BYTE_WORD': {'width': 8, 'grade': 'established'}, 'SBBR_L_WORD': {'width': 32, 'grade': 'established'}, 'SERIAL_PTR_WORD': {'width': 32, 'grade': 'established'}, 'SHADOW_WORD': {'width': 32, 'grade': 'established'}, 'SIO_CR_WORD': {'width': 32, 'grade': 'established'}, 'SIO_IR_PORT_WORD': {'width': 8, 'grade': 'established'}, 'SRCIR_WORD': {'width': 32, 'grade': 'established'}, 'SRTR_WORD': {'width': 32, 'grade': 'established'}, 'SSCR_WORD': {'width': 32, 'grade': 'established'}, 'TX_CONTROL_BYTE_WORD': {'width': 8, 'grade': 'established'}}
FIELDS = {'gpdr': {}, 'km_rx_kbd': {}, 'km_rx_mouse': {}, 'km_tx_kbd': {}, 'km_tx_mouse': {}, 'ATA_DMA_CONTROL_WORD': {'error': (4, 4), 'active': (3, 3), 'dir': (2, 2), 'stop': (1, 1), 'start': (0, 0)}, 'ATA_PRD_LENGTH_WORD': {'eol': (31, 31), 'length': (15, 0)}, 'GPCR_WORD': {'int_out_en': (20, 20), 'edge': (15, 8), 'dir': (7, 0)}, 'GPDR_WORD': {'gen_pin': (7, 0)}, 'GPPR_WORD': {'gen_pin': (0, 0)}, 'INT_OUT_WORD': {'int_out': (31, 31), 'diag': (30, 30), 'mode': (18, 16), 'count': (15, 0)}, 'OTHER_IR_WORD': {'gen_int': (31, 24), 'rt_int': (23, 23), 'kbd_int': (6, 6), 'ser_memerr': (5, 2), 'ata_memerr': (1, 1), 'ata_int': (0, 0)}, 'PCI_ERR_ADDR_L_WORD': {'addr': (31, 6), 'mul_err': (5, 5), 'master_id': (4, 1), 'valid': (0, 0)}, 'RX_STATUS_BYTE_WORD': {'data_valid': (7, 7), 'modem_valid': (6, 6), 'dcd': (5, 5), 'cts': (4, 4), 'brk': (3, 3), 'frame_err': (2, 2), 'par_err': (1, 1), 'overrun': (0, 0)}, 'SBBR_L_WORD': {'size': (0, 0)}, 'SERIAL_PTR_WORD': {'ptr': (11, 3)}, 'SHADOW_WORD': {'loop': (28, 28), 'out2': (27, 27), 'out1': (26, 26), 'rts': (25, 25), 'dtr': (24, 24), 'dcd': (23, 23), 'cts': (20, 20), 'ddcd': (19, 19), 'dcts': (16, 16), 'rfce': (7, 7), 'temt': (6, 6), 'thre': (5, 5), 'bi': (4, 4), 'fe': (3, 3), 'pe': (2, 2), 'oe': (1, 1), 'dr': (0, 0)}, 'SIO_CR_WORD': {'ata_diag_active': (9, 9), 'ata_diag_idle': (8, 8), 'sio_diag_idle': (7, 7), 'arb_diag': (6, 4), 'cmd_pulse': (3, 0)}, 'SIO_IR_PORT_WORD': {'tx_explicit': (7, 7), 'intr_pass': (6, 6), 'delta_cts': (5, 5), 'delta_dcd': (4, 4), 'rx_timer': (3, 3), 'rx_high': (2, 2), 'rx_full': (1, 1), 'tx_mt': (0, 0)}, 'SRCIR_WORD': {'arm': (31, 31), 'ptr': (11, 3)}, 'SRTR_WORD': {'current': (27, 16), 'reload': (11, 0)}, 'SSCR_WORD': {'reset': (31, 31), 'pause_state': (30, 30), 'dma_pause': (29, 29), 'dma_en': (28, 28), 'rx_drain': (27, 27), 'diag': (21, 21), 'rx_ring_cts': (19, 19), 'rx_ring_dcd': (18, 18), 'hfc_en': (17, 17), 'tx_timer_busy': (16, 16), 'rx_threshold': (8, 0)}, 'TX_CONTROL_BYTE_WORD': {'type': (7, 6), 'int_when_done': (5, 5)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'ATA_DMA_CONTROL': {'value': 348, 'count': 1, 'stride': 1}, 'ATA_DMA_CONTROL_ACTIVE': {'value': 8, 'count': 1, 'stride': 1}, 'ATA_DMA_CONTROL_DIR_TO_MEMORY': {'value': 4, 'count': 1, 'stride': 1}, 'ATA_DMA_CONTROL_ERROR': {'value': 16, 'count': 1, 'stride': 1}, 'ATA_DMA_CONTROL_START': {'value': 1, 'count': 1, 'stride': 1}, 'ATA_DMA_CONTROL_STOP': {'value': 2, 'count': 1, 'stride': 1}, 'ATA_DMA_COUNT_DEVICE': {'value': 340, 'count': 1, 'stride': 1}, 'ATA_DMA_COUNT_MEMORY': {'value': 344, 'count': 1, 'stride': 1}, 'ATA_DMA_CURRENT_HIGH': {'value': 336, 'count': 1, 'stride': 1}, 'ATA_DMA_CURRENT_LOW': {'value': 332, 'count': 1, 'stride': 1}, 'ATA_DMA_END_AREA': {'value': 352, 'count': 1, 'stride': 1}, 'ATA_DMA_LIST_HIGH': {'value': 328, 'count': 1, 'stride': 1}, 'ATA_DMA_LIST_LOW': {'value': 324, 'count': 1, 'stride': 1}, 'ATA_DMA_TIMING': {'value': 320, 'count': 1, 'stride': 1}, 'EXTINT_COUNT_DIVISOR': {'value': 520, 'count': 1, 'stride': 1}, 'GPCR_DIR_MASK': {'value': 255, 'count': 1, 'stride': 1}, 'GPCR_EDGE_MASK': {'value': 65280, 'count': 1, 'stride': 1}, 'GPCR_INT_OUT_EN': {'value': 1048576, 'count': 1, 'stride': 1}, 'GPIO_PIN_EXT_INT_OUT': {'value': 0, 'count': 1, 'stride': 1}, 'GPIO_PIN_SERIAL_MODE_0': {'value': 4, 'count': 1, 'stride': 1}, 'INT_OUT_COUNT_MASK': {'value': 65535, 'count': 1, 'stride': 1}, 'INT_OUT_DIAG': {'value': 1073741824, 'count': 1, 'stride': 1}, 'INT_OUT_MODE_MASK': {'value': 458752, 'count': 1, 'stride': 1}, 'INT_OUT_MODE_TOGGLE': {'value': 458752, 'count': 1, 'stride': 1}, 'INT_OUT_VALUE': {'value': 2147483648, 'count': 1, 'stride': 1}, 'KM_CSR_AUX_CLOCK_LINE': {'value': 512, 'count': 1, 'stride': 1}, 'KM_CSR_AUX_DATA_LINE': {'value': 256, 'count': 1, 'stride': 1}, 'KM_CSR_AUX_WRITE_PENDING': {'value': 2, 'count': 1, 'stride': 1}, 'KM_CSR_IDLE_B_15_14': {'value': 49152, 'count': 1, 'stride': 1}, 'KM_CSR_KBD_CLOCK_LINE': {'value': 32, 'count': 1, 'stride': 1}, 'KM_CSR_KBD_DATA_LINE': {'value': 16, 'count': 1, 'stride': 1}, 'KM_CSR_KBD_WRITE_PENDING': {'value': 1, 'count': 1, 'stride': 1}, 'KM_CSR_LAST_WRITE_LINE_B_3_2': {'value': 12, 'count': 1, 'stride': 1}, 'OTHER_IR_ATA_INT': {'value': 1, 'count': 1, 'stride': 1}, 'OTHER_IR_ATA_MEMERR': {'value': 2, 'count': 1, 'stride': 1}, 'OTHER_IR_GEN_INT': {'value': 4278190080, 'count': 1, 'stride': 1}, 'OTHER_IR_KBM': {'value': 64, 'count': 1, 'stride': 1}, 'OTHER_IR_RT_INT': {'value': 8388608, 'count': 1, 'stride': 1}, 'OTHER_IR_SER_MEMERR_0': {'value': 4, 'count': 1, 'stride': 1}, 'OTHER_IR_SER_MEMERR_1': {'value': 8, 'count': 1, 'stride': 1}, 'OTHER_IR_SER_MEMERR_2': {'value': 16, 'count': 1, 'stride': 1}, 'OTHER_IR_SER_MEMERR_3': {'value': 32, 'count': 1, 'stride': 1}, 'PCI_CLASS_CODE': {'value': 737280, 'count': 1, 'stride': 1}, 'SERIAL_RING_PTR_B_9_3': {'value': 1016, 'count': 1, 'stride': 1}, 'SERIAL_RX_TIMER_COUNT_B_27_16': {'value': 268369920, 'count': 1, 'stride': 1}, 'SERIAL_RX_TIMER_RELOAD_B_11_0': {'value': 4095, 'count': 1, 'stride': 1}, 'SERIAL_SHADOW_CTS_V_100000': {'value': 1048576, 'count': 1, 'stride': 1}, 'SERIAL_SHADOW_DCD_V_800000': {'value': 8388608, 'count': 1, 'stride': 1}, 'SERIAL_SHADOW_DCTS_V_10000': {'value': 65536, 'count': 1, 'stride': 1}, 'SERIAL_SHADOW_DDCD_V_80000': {'value': 524288, 'count': 1, 'stride': 1}, 'SERIAL_SHADOW_OUTPUTS_B_28_24': {'value': 520093696, 'count': 1, 'stride': 1}, 'SERIAL_SHADOW_RX_FLAGS_B_7_0': {'value': 255, 'count': 1, 'stride': 1}, 'SERIAL_SRCIR_TIMER_ARM_V_80000000': {'value': 2147483648, 'count': 1, 'stride': 1}, 'SIO_CR_ARB_DIAG': {'value': 112, 'count': 1, 'stride': 1}, 'SIO_CR_ATA_DIAG_ACTIVE': {'value': 512, 'count': 1, 'stride': 1}, 'SIO_CR_ATA_DIAG_IDLE': {'value': 256, 'count': 1, 'stride': 1}, 'SIO_CR_CMD_PULSE': {'value': 15, 'count': 1, 'stride': 1}, 'SIO_CR_SIO_DIAG_IDLE': {'value': 128, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_UART_0': {'value': 64, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_UART_1': {'value': 16384, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_UART_2': {'value': 4194304, 'count': 1, 'stride': 1}, 'SIO_IR_SRC_UART_3': {'value': 1073741824, 'count': 1, 'stride': 1}}
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
