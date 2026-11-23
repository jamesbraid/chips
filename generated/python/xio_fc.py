"""generated from devices/xio_fc/registers.toml by defs-gen - do not edit, change the source
defs-gen 3
input sha256 57e8737a3343b26b5b9baa63badf937ee000b92384357355a269d98dd44823d0
XIO Fibre Channel adapter (Adaptec AIC-1160 board), command and register contract"""

UNIT = 'xio_fc'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'BANK_CODE_STEP': {'value': 17, 'count': 1, 'stride': 1}, 'CLOCK_STATUS_DIV_1': {'value': 190, 'count': 1, 'stride': 1}, 'CLOCK_STATUS_DIV_2_A': {'value': 46, 'count': 1, 'stride': 1}, 'CLOCK_STATUS_DIV_2_B': {'value': 254, 'count': 1, 'stride': 1}, 'CLOCK_STATUS_DIV_4': {'value': 110, 'count': 1, 'stride': 1}, 'CLOCK_STATUS_MASK': {'value': 252, 'count': 1, 'stride': 1}, 'CLOCK_STATUS_OR': {'value': 2, 'count': 1, 'stride': 1}, 'DONE_HANDLE': {'value': 0, 'count': 1, 'stride': 1}, 'DONE_PASS': {'value': 3, 'count': 1, 'stride': 1}, 'DONE_STATUS': {'value': 2, 'count': 1, 'stride': 1}, 'HOST_CTRL_MASTER_IRQ_EN': {'value': 4, 'count': 1, 'stride': 1}, 'HOST_CTRL_PAUSE': {'value': 64, 'count': 1, 'stride': 1}, 'HOST_CTRL_PAUSE_AT_TOP': {'value': 128, 'count': 1, 'stride': 1}, 'HOST_CTRL_RESET_WRITE': {'value': 67, 'count': 1, 'stride': 1}, 'INT_BREAKPOINT': {'value': 512, 'count': 1, 'stride': 1}, 'INT_HARDWARE_ERROR': {'value': 16384, 'count': 1, 'stride': 1}, 'INT_HOST_COMPLETION': {'value': 1024, 'count': 1, 'stride': 1}, 'INT_LOOP_ATTENTION': {'value': 8, 'count': 1, 'stride': 1}, 'INT_PCI_ERROR': {'value': 32768, 'count': 1, 'stride': 1}, 'INT_SEQ_COMPLETION': {'value': 4096, 'count': 1, 'stride': 1}, 'INT_SEQ_READY_FOR_LIP': {'value': 256, 'count': 1, 'stride': 1}, 'INT_SOFTWARE_ERROR': {'value': 8192, 'count': 1, 'stride': 1}, 'LINK_CTRL_LINK_ENABLE': {'value': 64, 'count': 1, 'stride': 1}, 'LINK_CTRL_LINK_RESET': {'value': 32, 'count': 1, 'stride': 1}, 'LINK_CTRL_LOSS_OF_SIGNAL': {'value': 1, 'count': 1, 'stride': 1}, 'LINK_CTRL_LOSS_OF_SYNC': {'value': 2, 'count': 1, 'stride': 1}, 'PLOGI_ACC_CLASS1_PARAMS': {'value': 36, 'count': 1, 'stride': 1}, 'PLOGI_ACC_CLASS2_PARAMS': {'value': 52, 'count': 1, 'stride': 1}, 'PLOGI_ACC_CLASS3_PARAMS': {'value': 68, 'count': 1, 'stride': 1}, 'PLOGI_ACC_CODE': {'value': 0, 'count': 1, 'stride': 1}, 'PLOGI_ACC_COMMON_PARAMS': {'value': 4, 'count': 1, 'stride': 1}, 'PLOGI_ACC_LENGTH': {'value': 116, 'count': 1, 'stride': 1}, 'PLOGI_ACC_NODE_NAME': {'value': 28, 'count': 1, 'stride': 1}, 'PLOGI_ACC_PORT_NAME': {'value': 20, 'count': 1, 'stride': 1}, 'PLOGI_ACC_RESERVED': {'value': 84, 'count': 1, 'stride': 1}, 'PLOGI_ACC_VENDOR_VERSION': {'value': 100, 'count': 1, 'stride': 1}, 'PLOGI_REJECT_EXPLANATION': {'value': 6, 'count': 1, 'stride': 1}, 'PLOGI_REJECT_REASON': {'value': 5, 'count': 1, 'stride': 1}, 'PRLI_ACC_CODE': {'value': 0, 'count': 1, 'stride': 1}, 'PRLI_ACC_FLAGS': {'value': 6, 'count': 1, 'stride': 1}, 'PRLI_ACC_LENGTH': {'value': 20, 'count': 1, 'stride': 1}, 'PRLI_ACC_ORIGINATOR_ASSOC': {'value': 8, 'count': 1, 'stride': 1}, 'PRLI_ACC_PAGE_LENGTH': {'value': 1, 'count': 1, 'stride': 1}, 'PRLI_ACC_PAYLOAD_LENGTH': {'value': 2, 'count': 1, 'stride': 1}, 'PRLI_ACC_RESPONDER_ASSOC': {'value': 12, 'count': 1, 'stride': 1}, 'PRLI_ACC_SERVICE_BYTE': {'value': 19, 'count': 1, 'stride': 1}, 'PRLI_ACC_TYPE': {'value': 4, 'count': 1, 'stride': 1}, 'REG_BANK_SELECT': {'value': 44, 'count': 1, 'stride': 1}, 'REG_CLOCK_STATUS': {'value': 99, 'count': 1, 'stride': 1}, 'REG_HOST_CONTROL': {'value': 34, 'count': 1, 'stride': 1}, 'REG_LINK_CONTROL': {'value': 225, 'count': 1, 'stride': 1}, 'REG_SEQ_CONTROL': {'value': 0, 'count': 1, 'stride': 1}, 'REG_SERDES_STATUS': {'value': 235, 'count': 1, 'stride': 1}, 'RESID_SEGMENT_RESIDUAL': {'value': 8, 'count': 1, 'stride': 1}, 'RESID_SG_ELEMENT_INDEX': {'value': 12, 'count': 1, 'stride': 1}, 'RESID_SG_PAGE_PTR': {'value': 0, 'count': 1, 'stride': 1}, 'RESP_FCP_STATUS_FLAGS': {'value': 10, 'count': 1, 'stride': 1}, 'RESP_PAYLOAD': {'value': 24, 'count': 1, 'stride': 1}, 'RESP_RESIDUAL': {'value': 12, 'count': 1, 'stride': 1}, 'RESP_RESIDUAL_INFO': {'value': 128, 'count': 1, 'stride': 1}, 'RESP_RESPONSE_LEN': {'value': 20, 'count': 1, 'stride': 1}, 'RESP_SCSI_STATUS': {'value': 11, 'count': 1, 'stride': 1}, 'RESP_SENSE_LEN': {'value': 16, 'count': 1, 'stride': 1}, 'SEQ_CTRL_RAM_LOAD': {'value': 1, 'count': 1, 'stride': 1}, 'SEQ_CTRL_RESET_PC': {'value': 2, 'count': 1, 'stride': 1}, 'SEQ_CTRL_RUN': {'value': 64, 'count': 1, 'stride': 1}, 'SEQ_CTRL_START': {'value': 66, 'count': 1, 'stride': 1}, 'SERDES_FAULT': {'value': 16, 'count': 1, 'stride': 1}, 'SERDES_LOCK_NOT_IN_USE': {'value': 8, 'count': 1, 'stride': 1}, 'SERDES_MEDIA_SENSE_MASK': {'value': 3, 'count': 1, 'stride': 1}, 'TCB_CONTROL': {'value': 33, 'count': 1, 'stride': 1}, 'TCB_DATA_LEN': {'value': 96, 'count': 1, 'stride': 1}, 'TCB_DATA_PTR': {'value': 76, 'count': 1, 'stride': 1}, 'TCB_DELIMITER': {'value': 9, 'count': 1, 'stride': 1}, 'TCB_DESC_MODE': {'value': 35, 'count': 1, 'stride': 1}, 'TCB_D_ID': {'value': 4, 'count': 1, 'stride': 1}, 'TCB_FCP_CDB': {'value': 48, 'count': 1, 'stride': 1}, 'TCB_FCP_CNTL': {'value': 44, 'count': 1, 'stride': 1}, 'TCB_FCP_DL': {'value': 64, 'count': 1, 'stride': 1}, 'TCB_FCP_LUN': {'value': 36, 'count': 1, 'stride': 1}, 'TCB_F_CTL0': {'value': 16, 'count': 1, 'stride': 1}, 'TCB_F_CTL1': {'value': 17, 'count': 1, 'stride': 1}, 'TCB_F_CTL2': {'value': 14, 'count': 1, 'stride': 1}, 'TCB_HANDLE_COPY': {'value': 104, 'count': 1, 'stride': 1}, 'TCB_LOOP_FLAGS': {'value': 28, 'count': 1, 'stride': 1}, 'TCB_NEXT': {'value': 68, 'count': 1, 'stride': 1}, 'TCB_OX_ID': {'value': 0, 'count': 1, 'stride': 1}, 'TCB_RESP_PTR': {'value': 88, 'count': 1, 'stride': 1}, 'TCB_RX_ID': {'value': 2, 'count': 1, 'stride': 1}, 'TCB_R_CTL': {'value': 7, 'count': 1, 'stride': 1}, 'TCB_SEQ_CNT': {'value': 20, 'count': 1, 'stride': 1}, 'TCB_SEQ_ID': {'value': 19, 'count': 1, 'stride': 1}, 'TCB_TYPE': {'value': 15, 'count': 1, 'stride': 1}, 'TCB_UNKNOWN_64': {'value': 100, 'count': 1, 'stride': 1}, 'TCB_XFER_LEN': {'value': 84, 'count': 1, 'stride': 1}}
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
