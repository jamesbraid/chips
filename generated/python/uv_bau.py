"""generated from devices/uv_bau/registers.toml by defs-gen - do not edit, change the source
defs-gen 3
input sha256 2daabcb00ca4cf0ccb9e7ae19034116a669196719e08dfd2559a070a278bfaa3
UV broadcast assist unit (BAU): descriptor, payload queue and constants"""

UNIT = 'uv_bau'
REGISTERS = {}
WORDS = {'DESC_HDR_HI': {'width': 64, 'grade': 'established'}, 'DESC_HDR_LO': {'width': 64, 'grade': 'established'}}
FIELDS = {'DESC_HDR_HI': {'command': (63, 56), 'multilevel': (31, 31), 'chaining': (30, 30), 'sequence': (29, 14), 'fairness': (13, 11)}, 'DESC_HDR_LO': {'swack_flag': (52, 52), 'canceled': (25, 25), 'msg_type': (24, 22), 'replied_to': (21, 21), 'dest_subnodeid': (19, 15), 'base_dest_nasid': (14, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'DESC_BYTES': {'value': 64, 'count': 1, 'stride': 1}, 'DESC_QUALIFIER': {'value': 5457737, 'count': 1, 'stride': 1}, 'DISTRIBUTION_BITS': {'value': 256, 'count': 1, 'stride': 1}, 'DS_ACTIVE': {'value': 1, 'count': 1, 'stride': 1}, 'DS_DESTINATION_TIMEOUT': {'value': 2, 'count': 1, 'stride': 1}, 'DS_IDLE': {'value': 0, 'count': 1, 'stride': 1}, 'DS_SOURCE_TIMEOUT': {'value': 3, 'count': 1, 'stride': 1}, 'ITEMS_PER_SET': {'value': 8, 'count': 1, 'stride': 1}, 'LB_SUBNODEID': {'value': 16, 'count': 1, 'stride': 1}, 'MSG_NOOP': {'value': 0, 'count': 1, 'stride': 1}, 'MSG_REGULAR': {'value': 1, 'count': 1, 'stride': 1}, 'MSG_RETRY': {'value': 2, 'count': 1, 'stride': 1}, 'NUM_SETS': {'value': 64, 'count': 1, 'stride': 1}, 'PAYLOADQ_GNODE_SHIFT': {'value': 49, 'count': 1, 'stride': 1}, 'PAYLOAD_QUEUE_ENTRIES': {'value': 20, 'count': 1, 'stride': 1}, 'PAYLOAD_QUEUE_ENTRY_BYTES': {'value': 32, 'count': 1, 'stride': 1}, 'SW_ACK_RESOURCES': {'value': 8, 'count': 1, 'stride': 1}, 'UV1_ENDPOINT_COMMAND': {'value': 56, 'count': 1, 'stride': 1}, 'UV1_SOFT_ACK_PERIOD': {'value': 9, 'count': 1, 'stride': 1}, 'UV2_DESC_BUSY': {'value': 2, 'count': 1, 'stride': 1}, 'UV2_DESC_DEST_PUT_ERR': {'value': 7, 'count': 1, 'stride': 1}, 'UV2_DESC_DEST_STRONG_NACK': {'value': 5, 'count': 1, 'stride': 1}, 'UV2_DESC_DEST_TIMEOUT': {'value': 4, 'count': 1, 'stride': 1}, 'UV2_DESC_IDLE': {'value': 0, 'count': 1, 'stride': 1}, 'UV2_DESC_SOURCE_TIMEOUT': {'value': 6, 'count': 1, 'stride': 1}, 'UV2_ENDPOINT_COMMAND': {'value': 40, 'count': 1, 'stride': 1}, 'UV2_SOFT_ACK_PERIOD': {'value': 15, 'count': 1, 'stride': 1}}
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
