"""generated from devices/lh28f800su/registers.toml by defs-gen - do not edit, change the source
defs-gen 2
input sha256 71c039ffd5729e496aee717c8dfa100cd9f37ba507e648af391cd31eae7a983a
Sharp LH28F800SU 8 Mbit x16 flash: array geometry, command set, identifier and status registers"""

UNIT = 'lh28f800su'
REGISTERS = {}
WORDS = {'BSR': {'width': 8, 'grade': 'established'}, 'CSR': {'width': 8, 'grade': 'established'}, 'GSR': {'width': 8, 'grade': 'established'}}
FIELDS = {'BSR': {'block_ready': (7, 7), 'lock_cleared': (6, 6), 'op_status': (5, 4), 'queue_full': (3, 3), 'low_vpp': (2, 2)}, 'CSR': {'ready': (7, 7), 'erase_suspended': (6, 6), 'erase_error': (5, 5), 'program_error': (4, 4), 'low_vpp': (3, 3)}, 'GSR': {'write_ready': (7, 7), 'suspended': (6, 6), 'op_status': (5, 4), 'queue_full': (3, 3), 'buffer_available': (2, 2), 'buffer_ready': (1, 1), 'buffer_select': (0, 0)}}
ENUMS = {'bsr_op': {0: 'ok_or_running', 2: 'failure', 3: 'aborted'}, 'gsr_op': {0: 'ok_or_running', 1: 'sleep', 2: 'failure', 3: 'failure_or_abort'}}
FIELD_ENUM = {'BSR.op_status': 'bsr_op', 'GSR.op_status': 'gsr_op'}
CONSTANTS = {'LH28F800SU_ARRAY_BYTES': {'value': 1048576, 'count': 1, 'stride': 1}, 'LH28F800SU_BLOCK_BYTES': {'value': 65536, 'count': 1, 'stride': 1}, 'LH28F800SU_BLOCK_COUNT': {'value': 16, 'count': 1, 'stride': 1}, 'LH28F800SU_BLOCK_ERASE_TYP_MS': {'value': 700, 'count': 1, 'stride': 1}, 'LH28F800SU_BLOCK_WORDS': {'value': 32768, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_BLOCK_LOCK': {'value': 119, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_CLEAR_STATUS': {'value': 80, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_CONFIRM': {'value': 208, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_ERASE_SETUP': {'value': 32, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_EXT_STATUS': {'value': 113, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_IDENTIFY': {'value': 144, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_PROGRAM': {'value': 64, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_PROGRAM_ALT': {'value': 16, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_READ_ARRAY': {'value': 255, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_READ_STATUS': {'value': 112, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_SUSPEND': {'value': 176, 'count': 1, 'stride': 1}, 'LH28F800SU_CMD_UPLOAD_STATUS': {'value': 151, 'count': 1, 'stride': 1}, 'LH28F800SU_ID_WORD0': {'value': 176, 'count': 1, 'stride': 1}, 'LH28F800SU_ID_WORD1': {'value': 26280, 'count': 1, 'stride': 1}, 'LH28F800SU_RP_RECOVERY_NS': {'value': 400, 'count': 1, 'stride': 1}, 'LH28F800SU_WORD_PROGRAM_TYP_US': {'value': 8, 'count': 1, 'stride': 1}}
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
