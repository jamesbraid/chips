"""generated from devices/mace/registers-extra.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 490c88a36f70908dd2b884bf6a6cb452f78c4406765832d4e82eb4098f24c841
MACE register bits the census does not name"""

UNIT = 'mace_extra'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'ISA_MISC_FLASH_WRITE_ENABLE': {'value': 1, 'count': 1, 'stride': 1}, 'ISA_MISC_NIC_DEASSERT': {'value': 4, 'count': 1, 'stride': 1}, 'ISA_MISC_NIC_SAMPLE': {'value': 8, 'count': 1, 'stride': 1}}
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
