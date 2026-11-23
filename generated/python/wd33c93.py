"""generated from devices/wd33c93/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 9910f5661f6314c737e8fc59355fe020e6e1845f293604aa3a75852ecd0c3cb5
WD33C93/WD33C93A SCSI bus interface controller as wired on the Indigo (R3000 and R4000 boards)"""

UNIT = 'wd33c93'
REGISTERS = {'own_id': {'offset': 0, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'control': {'offset': 1, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'timeout': {'offset': 2, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'cdb': {'offset': 3, 'access': 'rw', 'width': 8, 'count': 12, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'target_lun': {'offset': 15, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'command_phase': {'offset': 16, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'sync_transfer': {'offset': 17, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'transfer_count': {'offset': 18, 'access': 'rw', 'width': 8, 'count': 3, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'dest_id': {'offset': 21, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'source_id': {'offset': 22, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'scsi_status': {'offset': 23, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'command': {'offset': 24, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 0, 'grade': 'established'}, 'data': {'offset': 25, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 'unknown', 'grade': 'established'}, 'queue_tag': {'offset': 26, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_index', 'reset': 'unknown', 'grade': 'inferred'}, 'aux_status': {'offset': 290, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_port_r', 'reset': 128, 'grade': 'established'}, 'data_port': {'offset': 294, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_port_r', 'reset': 'unknown', 'grade': 'established'}, 'address': {'offset': 290, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': 'wd33c93_port_w', 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'own_id': {'fs': (7, 6), 'eih_raf': (5, 5), 'ehp': (4, 4), 'eaf': (3, 3), 'id': (2, 0)}, 'control': {'dma_mode': (7, 5), 'hhp': (4, 4), 'edi': (3, 3), 'idi': (2, 2), 'ha': (1, 1), 'hsp': (0, 0)}, 'timeout': {}, 'cdb': {}, 'target_lun': {'tlv': (7, 7), 'dok': (6, 6), 'lun': (2, 0)}, 'command_phase': {}, 'sync_transfer': {'fast': (7, 7), 'period': (6, 4), 'offset': (3, 0)}, 'transfer_count': {}, 'dest_id': {'scc': (7, 7), 'dpd': (6, 6), 'df': (5, 5), 'id': (2, 0)}, 'source_id': {'er': (7, 7), 'es': (6, 6), 'dsp': (5, 5), 'siv': (3, 3), 'id': (2, 0)}, 'scsi_status': {}, 'command': {'sbt': (7, 7), 'code': (6, 0)}, 'data': {}, 'queue_tag': {}, 'aux_status': {'int': (7, 7), 'lci': (6, 6), 'bsy': (5, 5), 'cip': (4, 4), 'pe': (1, 1), 'dbr': (0, 0)}, 'data_port': {}, 'address': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'CMD_ABORT': {'value': 1, 'count': 1, 'stride': 1}, 'CMD_ASSERT_ATN': {'value': 2, 'count': 1, 'stride': 1}, 'CMD_DISCONNECT': {'value': 4, 'count': 1, 'stride': 1}, 'CMD_NEGATE_ACK': {'value': 3, 'count': 1, 'stride': 1}, 'CMD_RESELECT': {'value': 5, 'count': 1, 'stride': 1}, 'CMD_RESET': {'value': 0, 'count': 1, 'stride': 1}, 'CMD_SBT': {'value': 128, 'count': 1, 'stride': 1}, 'CMD_SELECT': {'value': 7, 'count': 1, 'stride': 1}, 'CMD_SELECT_ATN': {'value': 6, 'count': 1, 'stride': 1}, 'CMD_SELECT_ATN_XFER': {'value': 8, 'count': 1, 'stride': 1}, 'CMD_SELECT_XFER': {'value': 9, 'count': 1, 'stride': 1}, 'CMD_TRANSFER_INFO': {'value': 32, 'count': 1, 'stride': 1}, 'CMD_TRANSLATE': {'value': 24, 'count': 1, 'stride': 1}, 'CONTROL_IRIX_BURST': {'value': 45, 'count': 1, 'stride': 1}, 'CONTROL_IRIX_SINGLE': {'value': 141, 'count': 1, 'stride': 1}, 'CPH_CMD_COMPLETE': {'value': 96, 'count': 1, 'stride': 1}, 'CPH_CMD_START': {'value': 48, 'count': 1, 'stride': 1}, 'CPH_DATA_DONE': {'value': 70, 'count': 1, 'stride': 1}, 'CPH_DISCONNECTED': {'value': 67, 'count': 1, 'stride': 1}, 'CPH_DISCONNECT_MSG': {'value': 66, 'count': 1, 'stride': 1}, 'CPH_IDENTIFY_IN': {'value': 69, 'count': 1, 'stride': 1}, 'CPH_IDENTIFY_SENT': {'value': 32, 'count': 1, 'stride': 1}, 'CPH_RESELECTED': {'value': 68, 'count': 1, 'stride': 1}, 'CPH_SAVE_DP': {'value': 65, 'count': 1, 'stride': 1}, 'CPH_SELECTED': {'value': 16, 'count': 1, 'stride': 1}, 'CPH_STATUS_DONE': {'value': 80, 'count': 1, 'stride': 1}, 'CPH_STATUS_PHASE': {'value': 71, 'count': 1, 'stride': 1}, 'OWNID_IRIX_AF': {'value': 168, 'count': 1, 'stride': 1}, 'OWNID_IRIX_PLAIN': {'value': 128, 'count': 1, 'stride': 1}, 'PHASE_COMMAND': {'value': 2, 'count': 1, 'stride': 1}, 'PHASE_DATA_IN': {'value': 1, 'count': 1, 'stride': 1}, 'PHASE_DATA_OUT': {'value': 0, 'count': 1, 'stride': 1}, 'PHASE_MSG_IN': {'value': 7, 'count': 1, 'stride': 1}, 'PHASE_MSG_OUT': {'value': 6, 'count': 1, 'stride': 1}, 'PHASE_STATUS': {'value': 3, 'count': 1, 'stride': 1}, 'SOURCEID_ENABLE_RESEL': {'value': 128, 'count': 1, 'stride': 1}, 'STATUS_BAD_CMD': {'value': 64, 'count': 1, 'stride': 1}, 'STATUS_BAD_STATUS': {'value': 71, 'count': 1, 'stride': 1}, 'STATUS_DISCONNECT': {'value': 133, 'count': 1, 'stride': 1}, 'STATUS_MSGIN_PAUSED': {'value': 32, 'count': 1, 'stride': 1}, 'STATUS_PARITY': {'value': 67, 'count': 1, 'stride': 1}, 'STATUS_PARITY_ATN': {'value': 68, 'count': 1, 'stride': 1}, 'STATUS_REQ_MSGIN': {'value': 143, 'count': 1, 'stride': 1}, 'STATUS_REQ_MSGOUT': {'value': 142, 'count': 1, 'stride': 1}, 'STATUS_RESELECT': {'value': 128, 'count': 1, 'stride': 1}, 'STATUS_RESELECT_AF': {'value': 129, 'count': 1, 'stride': 1}, 'STATUS_RESET': {'value': 0, 'count': 1, 'stride': 1}, 'STATUS_RESET_AF': {'value': 1, 'count': 1, 'stride': 1}, 'STATUS_SAT_DONE': {'value': 22, 'count': 1, 'stride': 1}, 'STATUS_SAVE_DP': {'value': 33, 'count': 1, 'stride': 1}, 'STATUS_SELECT_DONE': {'value': 17, 'count': 1, 'stride': 1}, 'STATUS_SEL_TIMEOUT': {'value': 66, 'count': 1, 'stride': 1}, 'STATUS_UNEXP_DISC': {'value': 65, 'count': 1, 'stride': 1}, 'STATUS_UNEXP_PHASE': {'value': 72, 'count': 1, 'stride': 1}, 'STATUS_XFER_DONE': {'value': 24, 'count': 1, 'stride': 1}, 'TIMEOUT_IRIX': {'value': 64, 'count': 1, 'stride': 1}}
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
