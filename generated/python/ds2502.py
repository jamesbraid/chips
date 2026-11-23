"""generated from devices/ds2502/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 9941eae5ea6d1a9225c3286c2cb883222d28d7bacbc24cc284abb93703acdb6e
Maxim DS2502 1 Kbit add-only 1-Wire memory: ROM, commands, memory layout and timing"""

UNIT = 'ds2502'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'DS2502_CMD_MATCH_ROM': {'value': 85, 'count': 1, 'stride': 1}, 'DS2502_CMD_READ_DATA_CRC': {'value': 195, 'count': 1, 'stride': 1}, 'DS2502_CMD_READ_MEMORY': {'value': 240, 'count': 1, 'stride': 1}, 'DS2502_CMD_READ_ROM': {'value': 51, 'count': 1, 'stride': 1}, 'DS2502_CMD_READ_STATUS': {'value': 170, 'count': 1, 'stride': 1}, 'DS2502_CMD_SEARCH_ROM': {'value': 240, 'count': 1, 'stride': 1}, 'DS2502_CMD_SKIP_ROM': {'value': 204, 'count': 1, 'stride': 1}, 'DS2502_CMD_WRITE_MEMORY': {'value': 15, 'count': 1, 'stride': 1}, 'DS2502_CMD_WRITE_STATUS': {'value': 85, 'count': 1, 'stride': 1}, 'DS2502_CRC_INIT': {'value': 0, 'count': 1, 'stride': 1}, 'DS2502_CRC_POLY': {'value': 49, 'count': 1, 'stride': 1}, 'DS2502_EPROM_BYTES': {'value': 128, 'count': 1, 'stride': 1}, 'DS2502_FAMILY_CODE': {'value': 9, 'count': 1, 'stride': 1}, 'DS2502_PAGE_BYTES': {'value': 32, 'count': 1, 'stride': 1}, 'DS2502_PROGRAM_PULSE_US': {'value': 480, 'count': 1, 'stride': 1}, 'DS2502_ROM_BITS': {'value': 64, 'count': 1, 'stride': 1}, 'DS2502_SERIAL_BITS': {'value': 48, 'count': 1, 'stride': 1}, 'DS2502_STATUS_BYTES': {'value': 8, 'count': 1, 'stride': 1}, 'DS2502_STATUS_FACTORY_LAST': {'value': 0, 'count': 1, 'stride': 1}, 'DS2502_T_LOW0_MIN_US': {'value': 60, 'count': 1, 'stride': 1}, 'DS2502_T_LOW1_MAX_US': {'value': 15, 'count': 1, 'stride': 1}, 'DS2502_T_LOW1_MIN_US': {'value': 1, 'count': 1, 'stride': 1}, 'DS2502_T_PDH_MAX_US': {'value': 60, 'count': 1, 'stride': 1}, 'DS2502_T_PDH_MIN_US': {'value': 15, 'count': 1, 'stride': 1}, 'DS2502_T_PDL_MAX_US': {'value': 240, 'count': 1, 'stride': 1}, 'DS2502_T_PDL_MIN_US': {'value': 60, 'count': 1, 'stride': 1}, 'DS2502_T_RDV_US': {'value': 15, 'count': 1, 'stride': 1}, 'DS2502_T_REC_MIN_US': {'value': 1, 'count': 1, 'stride': 1}, 'DS2502_T_RSTH_MIN_US': {'value': 480, 'count': 1, 'stride': 1}, 'DS2502_T_RSTL_MAX_US': {'value': 960, 'count': 1, 'stride': 1}, 'DS2502_T_RSTL_MIN_US': {'value': 480, 'count': 1, 'stride': 1}, 'DS2502_T_SLOT_MAX_US': {'value': 120, 'count': 1, 'stride': 1}, 'DS2502_T_SLOT_MIN_US': {'value': 60, 'count': 1, 'stride': 1}}
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
