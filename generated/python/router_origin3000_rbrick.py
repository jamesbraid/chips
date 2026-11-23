"""generated from devices/router_origin3000_rbrick/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 5be86454e6c098bd3031660190833330588ae9a2328ee39958e21d60c7e0f456
Origin 3000 R-brick router registers outside the census (vector space)"""

UNIT = 'router_origin3000_rbrick'
REGISTERS = {'status': {'offset': 0, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'prot_conf': {'offset': 16, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'position': {'offset': 80, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'scratch3': {'offset': 280, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'scratch3_setzero': {'offset': 1304, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'error_link1': {'offset': 65544, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'reset_mask_link1': {'offset': 65560, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'error_link2': {'offset': 67592, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'reset_mask_link2': {'offset': 67608, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'error_link3': {'offset': 131080, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'reset_mask_link3': {'offset': 131096, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'error_link4': {'offset': 133128, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'reset_mask_link4': {'offset': 133144, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'error_link5': {'offset': 196616, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'reset_mask_link5': {'offset': 196632, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'error_link6': {'offset': 198664, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'reset_mask_link6': {'offset': 198680, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'error_link7': {'offset': 262152, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'reset_mask_link7': {'offset': 262168, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'error_link8': {'offset': 264200, 'access': 'r', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}, 'reset_mask_link8': {'offset': 264216, 'access': 'rw', 'width': 64, 'count': 1, 'stride': 8, 'space': 'vector', 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'status': {'link8_state': (51, 50), 'link7_state': (49, 48), 'link6_state': (47, 46), 'link5_state': (45, 44), 'link4_state': (43, 42), 'link3_state': (41, 40), 'link2_state': (39, 38), 'link1_state': (37, 36), 'rev': (31, 28), 'chip': (27, 12)}, 'prot_conf': {'dir_compare_off': (13, 13), 'force_local': (12, 12), 'meta_id': (11, 8), 'reset_ok': (7, 0)}, 'position': {'repeater_flag': (21, 21), 'meta_flag': (20, 20)}, 'scratch3': {'lock': (0, 0)}, 'scratch3_setzero': {'lock': (0, 0)}, 'error_link1': {'power_not_ok': (38, 38), 'deadlock': (37, 37), 'warm_reset_rx': (36, 36), 'link_reset_rx': (35, 35), 'retry_rx_illegal': (34, 32)}, 'reset_mask_link1': {'reset_ok': (7, 0)}, 'error_link2': {'power_not_ok': (38, 38), 'deadlock': (37, 37), 'warm_reset_rx': (36, 36), 'link_reset_rx': (35, 35), 'retry_rx_illegal': (34, 32)}, 'reset_mask_link2': {'reset_ok': (7, 0)}, 'error_link3': {'power_not_ok': (38, 38), 'deadlock': (37, 37), 'warm_reset_rx': (36, 36), 'link_reset_rx': (35, 35), 'retry_rx_illegal': (34, 32)}, 'reset_mask_link3': {'reset_ok': (7, 0)}, 'error_link4': {'power_not_ok': (38, 38), 'deadlock': (37, 37), 'warm_reset_rx': (36, 36), 'link_reset_rx': (35, 35), 'retry_rx_illegal': (34, 32)}, 'reset_mask_link4': {'reset_ok': (7, 0)}, 'error_link5': {'power_not_ok': (38, 38), 'deadlock': (37, 37), 'warm_reset_rx': (36, 36), 'link_reset_rx': (35, 35), 'retry_rx_illegal': (34, 32)}, 'reset_mask_link5': {'reset_ok': (7, 0)}, 'error_link6': {'power_not_ok': (38, 38), 'deadlock': (37, 37), 'warm_reset_rx': (36, 36), 'link_reset_rx': (35, 35), 'retry_rx_illegal': (34, 32)}, 'reset_mask_link6': {'reset_ok': (7, 0)}, 'error_link7': {'power_not_ok': (38, 38), 'deadlock': (37, 37), 'warm_reset_rx': (36, 36), 'link_reset_rx': (35, 35), 'retry_rx_illegal': (34, 32)}, 'reset_mask_link7': {'reset_ok': (7, 0)}, 'error_link8': {'power_not_ok': (38, 38), 'deadlock': (37, 37), 'warm_reset_rx': (36, 36), 'link_reset_rx': (35, 35), 'retry_rx_illegal': (34, 32)}, 'reset_mask_link8': {'reset_ok': (7, 0)}}
ENUMS = {'link_state': {0: 'wentdown', 1: 'resetfail', 2: 'linkup', 3: 'notused'}}
FIELD_ENUM = {'status.link8_state': 'link_state', 'status.link7_state': 'link_state', 'status.link6_state': 'link_state', 'status.link5_state': 'link_state', 'status.link4_state': 'link_state', 'status.link3_state': 'link_state', 'status.link2_state': 'link_state', 'status.link1_state': 'link_state'}
CONSTANTS = {'L1_ROUTER_TYPE_META': {'value': 14, 'count': 1, 'stride': 1}, 'L1_ROUTER_TYPE_ORDINARY': {'value': 15, 'count': 1, 'stride': 1}, 'L1_ROUTER_TYPE_REPEATER': {'value': 12, 'count': 1, 'stride': 1}, 'L1_SETTING_ROUTER_TYPE': {'value': 60, 'count': 1, 'stride': 1}, 'ROUTER_CHIP_PART': {'value': 12311, 'count': 1, 'stride': 1}, 'ROUTER_DEST_IDS': {'value': 512, 'count': 1, 'stride': 1}, 'ROUTER_ENABLED_PORTS_SIX': {'value': 6, 'count': 1, 'stride': 1}, 'ROUTER_LOCAL_TABLE_ENTRIES': {'value': 16, 'count': 1, 'stride': 1}, 'ROUTER_PORTS': {'value': 8, 'count': 1, 'stride': 1}, 'ROUTER_REMOTE_TABLE_ENTRIES': {'value': 32, 'count': 1, 'stride': 1}, 'ROUTER_USB_PORT_FIRST': {'value': 2, 'count': 1, 'stride': 1}, 'ROUTER_USB_PORT_LAST': {'value': 5, 'count': 1, 'stride': 1}, 'ROUTER_VCS_PER_PORT': {'value': 4, 'count': 1, 'stride': 1}}
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
