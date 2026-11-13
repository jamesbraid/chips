"""generated from devices/isp2200/registers.toml by defs-gen - do not edit, change the source
QLogic ISP2200 Fibre Channel host adapter (PCI 1077:2200), the host interface the public drivers use"""

UNIT = 'isp2200'
REGISTERS = {'csr': {'offset': 6, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'icr': {'offset': 8, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'isr': {'offset': 10, 'access': 'r', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'sema': {'offset': 12, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'nvram': {'offset': 14, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mailbox': {'offset': 16, 'access': 'rw', 'width': 16, 'count': 8, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'hccr': {'offset': 192, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mailbox_hi': {'offset': 224, 'access': 'rw', 'width': 16, 'count': 16, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'csr': {'bank': (5, 4), 'soft_reset': (0, 0)}, 'icr': {'global_enable': (15, 15), 'risc_enable': (3, 3)}, 'isr': {'any_pending': (15, 15), 'risc_pending': (3, 3)}, 'sema': {'status': (1, 1), 'lock': (0, 0)}, 'nvram': {'data_from_eeprom': (3, 3), 'data_to_eeprom': (2, 2), 'select': (1, 1), 'clock': (0, 0)}, 'mailbox': {}, 'hccr': {'cmd': (15, 12), 'host_int': (7, 7), 'risc_reset': (6, 6), 'risc_paused': (5, 5)}, 'mailbox_hi': {}}
ENUMS = {'hccr_cmd': {0: 'noop', 1: 'reset_risc', 2: 'pause_risc', 3: 'release_risc', 4: 'parity', 5: 'set_host_int', 6: 'clear_host_int', 7: 'clear_risc_int'}}
FIELD_ENUM = {'hccr.cmd': 'hccr_cmd'}
CONSTANTS = {'ASYNC_EVENT_FIRST': {'value': 32768, 'count': 1, 'stride': 1}, 'ASYNC_EVENT_LAST': {'value': 49151, 'count': 1, 'stride': 1}, 'ASYNC_LIP': {'value': 32784, 'count': 1, 'stride': 1}, 'ASYNC_LOOP_DOWN': {'value': 32786, 'count': 1, 'stride': 1}, 'ASYNC_LOOP_UP': {'value': 32785, 'count': 1, 'stride': 1}, 'ASYNC_PORT_DB_CHANGE': {'value': 32788, 'count': 1, 'stride': 1}, 'ASYNC_RESET': {'value': 32769, 'count': 1, 'stride': 1}, 'ASYNC_RSCN': {'value': 32789, 'count': 1, 'stride': 1}, 'CMD_ENTRY_32': {'value': 17, 'count': 1, 'stride': 1}, 'CMD_ENTRY_64': {'value': 25, 'count': 1, 'stride': 1}, 'CONT_ENTRY_32': {'value': 2, 'count': 1, 'stride': 1}, 'CONT_ENTRY_64': {'value': 10, 'count': 1, 'stride': 1}, 'CPL_ABORTED': {'value': 5, 'count': 1, 'stride': 1}, 'CPL_COMPLETE': {'value': 0, 'count': 1, 'stride': 1}, 'CPL_DATA_OVERRUN': {'value': 7, 'count': 1, 'stride': 1}, 'CPL_DATA_UNDERRUN': {'value': 21, 'count': 1, 'stride': 1}, 'CPL_DMA_ERROR': {'value': 2, 'count': 1, 'stride': 1}, 'CPL_INCOMPLETE': {'value': 1, 'count': 1, 'stride': 1}, 'CPL_PORT_BUSY': {'value': 43, 'count': 1, 'stride': 1}, 'CPL_PORT_CONFIG_CHANGED': {'value': 42, 'count': 1, 'stride': 1}, 'CPL_PORT_LOGGED_OUT': {'value': 41, 'count': 1, 'stride': 1}, 'CPL_PORT_UNAVAILABLE': {'value': 40, 'count': 1, 'stride': 1}, 'CPL_QUEUE_FULL': {'value': 28, 'count': 1, 'stride': 1}, 'CPL_RESET': {'value': 4, 'count': 1, 'stride': 1}, 'CPL_TIMEOUT': {'value': 6, 'count': 1, 'stride': 1}, 'CPL_TRANSPORT_ERROR': {'value': 3, 'count': 1, 'stride': 1}, 'ENTRY_BYTES': {'value': 64, 'count': 1, 'stride': 1}, 'FIRMWARE_LENGTH_WORD_INDEX': {'value': 3, 'count': 1, 'stride': 1}, 'ICB_BYTES': {'value': 96, 'count': 1, 'stride': 1}, 'ICB_VERSION': {'value': 1, 'count': 1, 'stride': 1}, 'MAILBOXES_TOTAL': {'value': 24, 'count': 1, 'stride': 1}, 'MARKER_ENTRY': {'value': 4, 'count': 1, 'stride': 1}, 'MBOX0_BUSY': {'value': 4, 'count': 1, 'stride': 1}, 'MBOX_COMPLETION_LAST': {'value': 32767, 'count': 1, 'stride': 1}, 'NVRAM_IMAGE_BYTES': {'value': 256, 'count': 1, 'stride': 1}, 'OP_ABOUT_FIRMWARE': {'value': 8, 'count': 1, 'stride': 1}, 'OP_DUMP_RAM': {'value': 3, 'count': 1, 'stride': 1}, 'OP_EXECUTE_FIRMWARE': {'value': 2, 'count': 1, 'stride': 1}, 'OP_FIRMWARE_STATUS': {'value': 31, 'count': 1, 'stride': 1}, 'OP_GET_FIRMWARE_OPTIONS': {'value': 40, 'count': 1, 'stride': 1}, 'OP_INIT_FIRMWARE': {'value': 96, 'count': 1, 'stride': 1}, 'OP_LOAD_RAM_32': {'value': 1, 'count': 1, 'stride': 1}, 'OP_LOAD_RAM_DMA': {'value': 9, 'count': 1, 'stride': 1}, 'OP_LOAD_RAM_EXT': {'value': 11, 'count': 1, 'stride': 1}, 'OP_MAILBOX_TEST': {'value': 6, 'count': 1, 'stride': 1}, 'OP_NOOP': {'value': 0, 'count': 1, 'stride': 1}, 'OP_READ_RAM_WORD': {'value': 5, 'count': 1, 'stride': 1}, 'OP_SET_FIRMWARE_OPTIONS': {'value': 56, 'count': 1, 'stride': 1}, 'OP_VERIFY_CHECKSUM': {'value': 7, 'count': 1, 'stride': 1}, 'OP_WRITE_RAM_WORD': {'value': 4, 'count': 1, 'stride': 1}, 'PCI_BAR_IO_CONFIG_OFFSET': {'value': 16, 'count': 1, 'stride': 1}, 'PCI_BAR_MEM_CONFIG_OFFSET': {'value': 20, 'count': 1, 'stride': 1}, 'PCI_CONFIG_BUS_MASTER_BIT': {'value': 4, 'count': 1, 'stride': 1}, 'PCI_DEVICE_ID': {'value': 8704, 'count': 1, 'stride': 1}, 'PCI_VENDOR_ID': {'value': 4215, 'count': 1, 'stride': 1}, 'PRODUCT_ID_MAILBOX1': {'value': 18771, 'count': 1, 'stride': 1}, 'PRODUCT_ID_MAILBOX2': {'value': 20512, 'count': 1, 'stride': 1}, 'PRODUCT_ID_MAILBOX3': {'value': 8224, 'count': 1, 'stride': 1}, 'REGISTER_WINDOW_BYTES': {'value': 256, 'count': 1, 'stride': 1}, 'RISC_CODE_ORIGIN_WORD': {'value': 4096, 'count': 1, 'stride': 1}, 'ROM_VERSION_MAILBOX7': {'value': 4, 'count': 1, 'stride': 1}, 'SEGMENT_LIST_ENTRY': {'value': 21, 'count': 1, 'stride': 1}, 'STATUS_COMMAND_ERROR': {'value': 16389, 'count': 1, 'stride': 1}, 'STATUS_COMPLETE': {'value': 16384, 'count': 1, 'stride': 1}, 'STATUS_CONT_ENTRY': {'value': 16, 'count': 1, 'stride': 1}, 'STATUS_ENTRY': {'value': 3, 'count': 1, 'stride': 1}, 'STATUS_HOST_INTERFACE_ERROR': {'value': 16386, 'count': 1, 'stride': 1}, 'STATUS_INVALID_COMMAND': {'value': 16385, 'count': 1, 'stride': 1}, 'STATUS_PARAMETER_ERROR': {'value': 16390, 'count': 1, 'stride': 1}, 'STATUS_TEST_FAILED': {'value': 16387, 'count': 1, 'stride': 1}}
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
