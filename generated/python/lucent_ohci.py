"""generated from devices/lucent_ohci/registers.toml by defs-gen - do not edit, change the source
AT&T/Lucent 11C1:5802 two-port OHCI USB host controller (Origin 300 IO-8), the register and identity facts the held sources establish"""

UNIT = 'lucent_ohci'
REGISTERS = {'hc_interrupt_enable': {'offset': 16, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'hc_fm_interval': {'offset': 52, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 11999, 'grade': 'established'}, 'hc_fm_number': {'offset': 60, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'hc_rh_descriptor_a': {'offset': 72, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 268437762, 'grade': 'established'}, 'hc_rh_descriptor_b': {'offset': 76, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 393216, 'grade': 'established'}}
WORDS = {}
FIELDS = {'hc_interrupt_enable': {}, 'hc_fm_interval': {'frame_interval_toggle': (31, 31), 'fs_largest_data_packet': (30, 16), 'frame_interval': (13, 0)}, 'hc_fm_number': {'frame_number': (15, 0)}, 'hc_rh_descriptor_a': {'power_on_to_power_good_time': (31, 24), 'no_over_current_protection': (12, 12), 'over_current_protection_mode': (11, 11), 'no_power_switching': (9, 9), 'power_switching_mode': (8, 8)}, 'hc_rh_descriptor_b': {'port_power_control_mask': (31, 16), 'device_removable': (15, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'FM_NUMBER_WRITE_MASK': {'value': 65535, 'count': 1, 'stride': 1}, 'FRAME_INTERVAL_RESET': {'value': 11999, 'count': 1, 'stride': 1}, 'HCLSTHRESHOLD_RESET': {'value': 1576, 'count': 1, 'stride': 1}, 'MAX_LAT': {'value': 86, 'count': 1, 'stride': 1}, 'MIN_GNT': {'value': 3, 'count': 1, 'stride': 1}, 'PCI_DEVICE_ID': {'value': 22530, 'count': 1, 'stride': 1}, 'PCI_VENDOR_ID': {'value': 4545, 'count': 1, 'stride': 1}, 'SUBSYSTEM_ID': {'value': 22530, 'count': 1, 'stride': 1}, 'SUBSYSTEM_VENDOR_ID': {'value': 4545, 'count': 1, 'stride': 1}}
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
