"""generated from devices/bedrock/registers-extra.toml by defs-gen - do not edit, change the source
defs-gen 2
input sha256 66f55031d6b9d645d30480ba1e0a6af5318d45684c099683530c5dd69e1b2d79
Hub and Bedrock network-controller registers outside the census"""

UNIT = 'bedrock_extra'
REGISTERS = {'node_region_mask': {'offset': 16777240, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mem_bank_config': {'offset': 33030152, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'node_region_mask': {}, 'mem_bank_config': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'II_CREDIT_TIMEOUT': {'value': 4194784, 'count': 1, 'stride': 1}, 'II_READ_RESP_PRESCALE_B_54_32': {'value': 36028792723996672, 'count': 1, 'stride': 1}, 'II_READ_RESP_TIMEOUT_B_59_55': {'value': 1116892707587883008, 'count': 1, 'stride': 1}, 'II_TAIL_TIMEOUT': {'value': 4194800, 'count': 1, 'stride': 1}, 'MEM_BANK_CONFIG_BANK_SELECT': {'value': 12884901888, 'count': 1, 'stride': 1}, 'MEM_BANK_CONFIG_B_58_56': {'value': 504403158265495552, 'count': 1, 'stride': 1}, 'MEM_BANK_CONFIG_LANE_ENABLE': {'value': 3, 'count': 1, 'stride': 1}, 'MEM_BANK_CONFIG_LANE_SIZE': {'value': 240, 'count': 1, 'stride': 1}, 'NIC_ACCESS_HUB_PHYS_LOW': {'value': 31473712, 'count': 1, 'stride': 1}, 'NODE_SHIFT': {'value': 33, 'count': 1, 'stride': 1}, 'PI_ERROR_SPOOL_SIZE_BASE': {'value': 4096, 'count': 1, 'stride': 1}}
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
