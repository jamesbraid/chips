"""generated from defs/r5000_identity.toml by defs-gen - do not edit, change the source
MIPS R5000 family processor identity, reset entries, cache geometry and TLB size"""

UNIT = 'r5000_identity'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'R5K_COLD_RANDOM': {'value': 47, 'count': 1, 'stride': 1}, 'R5K_COLD_WIRED': {'value': 0, 'count': 1, 'stride': 1}, 'R5K_FCR0_OBSERVED': {'value': 8976, 'count': 1, 'stride': 1}, 'R5K_IMP_VR5000': {'value': 35, 'count': 1, 'stride': 1}, 'R5K_PHYS_ADDR_BITS': {'value': 36, 'count': 1, 'stride': 1}, 'R5K_PRID_IMP_MASK': {'value': 65280, 'count': 1, 'stride': 1}, 'R5K_PRID_IMP_SHIFT': {'value': 8, 'count': 1, 'stride': 1}, 'R5K_PRID_OBSERVED': {'value': 8993, 'count': 1, 'stride': 1}, 'R5K_PRID_REV_MASK': {'value': 255, 'count': 1, 'stride': 1}, 'R5K_PRIMARY_CACHE_BYTES': {'value': 32768, 'count': 1, 'stride': 1}, 'R5K_PRIMARY_LINE_BYTES': {'value': 32, 'count': 1, 'stride': 1}, 'R5K_PRIMARY_SETS': {'value': 512, 'count': 1, 'stride': 1}, 'R5K_PRIMARY_WAYS': {'value': 2, 'count': 1, 'stride': 1}, 'R5K_RESET_VECTOR': {'value': 18446744072631615488, 'count': 1, 'stride': 1}, 'R5K_SECONDARY_LINE_BYTES': {'value': 32, 'count': 1, 'stride': 1}, 'R5K_SECONDARY_WAYS': {'value': 1, 'count': 1, 'stride': 1}, 'R5K_SYSCLK_MAX_MHZ': {'value': 100, 'count': 1, 'stride': 1}, 'R5K_TLB_ENTRIES': {'value': 48, 'count': 1, 'stride': 1}, 'R5K_USER_ADDR_BITS': {'value': 40, 'count': 1, 'stride': 1}, 'R5K_WARM_STATUS_SET': {'value': 5242884, 'count': 1, 'stride': 1}}
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
