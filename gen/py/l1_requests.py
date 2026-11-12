"""generated from defs/l1_requests.toml by defs-gen - do not edit, change the source
request codes the Origin 3000 kernel sends to the brick controller"""

UNIT = 'l1_requests'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'REQ_ELSC_CONS_NODE': {'value': 4099, 'count': 1, 'stride': 1}, 'REQ_ELSC_CONS_SUBCH': {'value': 4098, 'count': 1, 'stride': 1}, 'REQ_ELSC_DEBUG_GET': {'value': 1, 'count': 1, 'stride': 1}, 'REQ_ELSC_DISPLAY_LINE_1': {'value': 4100, 'count': 1, 'stride': 1}, 'REQ_ELSC_DISPLAY_LINE_2': {'value': 4101, 'count': 1, 'stride': 1}, 'REQ_ELSC_EVT_UNREG': {'value': 4106, 'count': 1, 'stride': 1}, 'REQ_ELSC_LED_SET': {'value': 4105, 'count': 1, 'stride': 1}, 'REQ_ELSC_ODY_EXPANDER_GET': {'value': 8199, 'count': 1, 'stride': 1}, 'REQ_ELSC_ODY_EXPANDER_SET': {'value': 8200, 'count': 1, 'stride': 1}, 'REQ_ELSC_PARTITION_GET': {'value': 9, 'count': 1, 'stride': 1}, 'REQ_ELSC_PARTITION_SET': {'value': 4102, 'count': 1, 'stride': 1}, 'REQ_ELSC_PWR_CYCLE': {'value': 8198, 'count': 1, 'stride': 1}, 'REQ_ELSC_PWR_OFF': {'value': 8197, 'count': 1, 'stride': 1}, 'REQ_ELSC_SLAB_GET': {'value': 14, 'count': 1, 'stride': 1}, 'REQ_ELSC_SYSTEM_RESET': {'value': 8193, 'count': 1, 'stride': 1}, 'REQ_IOBRICK_ATTACHED_BRICKS': {'value': 12, 'count': 1, 'stride': 1}, 'REQ_IOBRICK_GET_SYS_SNUM': {'value': 8, 'count': 1, 'stride': 1}, 'REQ_RACK_BAY_TYPE_GET': {'value': 3, 'count': 1, 'stride': 1}, 'REQ_SC_COMMAND_INTERP': {'value': 0, 'count': 1, 'stride': 1}, 'REQ_SC_PORTSPEED_GET': {'value': 10, 'count': 1, 'stride': 1}, 'REQ_SC_SET_SYSTEM_STATE': {'value': 4108, 'count': 1, 'stride': 1}, 'REQ_SC_VERSION': {'value': 5, 'count': 1, 'stride': 1}}
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
