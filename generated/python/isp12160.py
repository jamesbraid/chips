"""generated from devices/isp12160/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 76b80bad40a1f9ab19f16c3d95e98399a2589c9f44ea0003211709b2b5ea1212
QLogic ISP12160 dual-channel Ultra3 SCSI host adapter (PCI 1077:1216), the constants the held sources establish"""

UNIT = 'isp12160'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'BUSES': {'value': 2, 'count': 1, 'stride': 1}, 'BUS_RESET_DELAY_DEFAULT_S': {'value': 5, 'count': 1, 'stride': 1}, 'BUS_RESET_DELAY_MAX_S': {'value': 15, 'count': 1, 'stride': 1}, 'CONTROLLER_PROGRAM_WORDS': {'value': 13853, 'count': 1, 'stride': 1}, 'DRIVER_SELECTION_TIMEOUT_DEFAULT': {'value': 250, 'count': 1, 'stride': 1}, 'OP_ABORT_DEVICE': {'value': 22, 'count': 1, 'stride': 1}, 'OP_BUS_RESET': {'value': 24, 'count': 1, 'stride': 1}, 'OP_DUMP_RAM': {'value': 3, 'count': 1, 'stride': 1}, 'OP_LOAD_RAM': {'value': 1, 'count': 1, 'stride': 1}, 'OP_SET_SELECTION_TIMEOUT': {'value': 49, 'count': 1, 'stride': 1}, 'PCI_BUS_WIDTH_BITS': {'value': 64, 'count': 1, 'stride': 1}, 'PCI_CLOCK_MHZ': {'value': 66, 'count': 1, 'stride': 1}, 'PCI_DEVICE_ID': {'value': 4630, 'count': 1, 'stride': 1}}
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
