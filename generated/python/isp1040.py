"""generated from devices/isp1040/registers.toml by defs-gen - do not edit, change the source
QLogic ISP1040 family SCSI host adapter (PCI 1077:1020), register and mailbox contract"""

UNIT = 'isp1040'
REGISTERS = {'id_l': {'offset': 0, 'access': 'r', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'id_h': {'offset': 2, 'access': 'r', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'cfg_0': {'offset': 4, 'access': 'r', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'cfg_1': {'offset': 6, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'ictrl': {'offset': 8, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'istatus': {'offset': 10, 'access': 'r', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'semaphore': {'offset': 12, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'nvram': {'offset': 14, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'flash_data': {'offset': 16, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'flash_address': {'offset': 18, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'mailbox': {'offset': 112, 'access': 'rw', 'width': 16, 'count': 8, 'stride': 2, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'id_l': {}, 'id_h': {}, 'cfg_0': {'hw_revision': (3, 0)}, 'cfg_1': {}, 'ictrl': {'flash_upper': (9, 9), 'flash_enable': (8, 8), 'risc_int_enable': (2, 2), 'int_enable': (1, 1), 'soft_reset': (0, 0)}, 'istatus': {}, 'semaphore': {}, 'nvram': {}, 'flash_data': {}, 'flash_address': {}, 'mailbox': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'ASYNC_BUS_RESET': {'value': 32769, 'count': 1, 'stride': 1}, 'BUSES': {'value': 1, 'count': 1, 'stride': 1}, 'DRIVER_SELECTION_TIMEOUT_DEFAULT': {'value': 250, 'count': 1, 'stride': 1}, 'OP_BUS_RESET': {'value': 24, 'count': 1, 'stride': 1}, 'OP_DUMP_RAM_64': {'value': 10, 'count': 1, 'stride': 1}, 'OP_GET_TARGET_PARAMS': {'value': 40, 'count': 1, 'stride': 1}, 'OP_LOAD_RAM_64': {'value': 9, 'count': 1, 'stride': 1}, 'OP_SET_RESET_DELAY_PARAMS': {'value': 58, 'count': 1, 'stride': 1}, 'OP_SET_RETRY_COUNT': {'value': 50, 'count': 1, 'stride': 1}, 'OP_SET_SELECTION_TIMEOUT': {'value': 49, 'count': 1, 'stride': 1}, 'OP_SET_TARGET_PARAMS': {'value': 56, 'count': 1, 'stride': 1}, 'PCI_REV_1040': {'value': 2, 'count': 1, 'stride': 1}, 'PCI_REV_1040A': {'value': 3, 'count': 1, 'stride': 1}, 'PCI_REV_1040B': {'value': 4, 'count': 1, 'stride': 1}, 'PCI_REV_1040C': {'value': 5, 'count': 1, 'stride': 1}, 'SCSI2_SELECTION_ABORT_US': {'value': 200, 'count': 1, 'stride': 1}, 'SCSI2_SELECTION_TIMEOUT_MS': {'value': 250, 'count': 1, 'stride': 1}, 'STATE_GOT_BUS': {'value': 256, 'count': 1, 'stride': 1}, 'STATE_GOT_SENSE': {'value': 8192, 'count': 1, 'stride': 1}, 'STATE_GOT_TARGET': {'value': 512, 'count': 1, 'stride': 1}, 'STATUS_COMP_INCOMPLETE': {'value': 1, 'count': 1, 'stride': 1}, 'STATUS_COMP_RESET': {'value': 4, 'count': 1, 'stride': 1}, 'STATUS_ENTRY_COMP_STATUS_OFFSET': {'value': 10, 'count': 1, 'stride': 1}, 'STATUS_ENTRY_SENSE_LENGTH_OFFSET': {'value': 18, 'count': 1, 'stride': 1}, 'STATUS_ENTRY_STATE_FLAGS_OFFSET': {'value': 12, 'count': 1, 'stride': 1}, 'STATUS_ENTRY_STATUS_FLAGS_OFFSET': {'value': 14, 'count': 1, 'stride': 1}, 'STATUS_FLAG_SELECTION_TIMEOUT': {'value': 64, 'count': 1, 'stride': 1}}
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
