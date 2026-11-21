"""generated from devices/lithium/registers.toml by defs-gen - do not edit, change the source
defs-gen 2
input sha256 1f9ce5d9b4c876c11bf7a33b65f387d185e256610a122c7325864fb43c537002
Lithium (I/O ASIC of the SGI Visual Workstation 320 and 540): the PCI bridge window and the audio engine, as SGI's Linux platform code names them"""

UNIT = 'lithium'
REGISTERS = {'host_ctl': {'offset': 0, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'intr_status': {'offset': 16, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'intr_mask': {'offset': 20, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'codec_command': {'offset': 24, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'codec_data': {'offset': 28, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'comm1_base': {'offset': 256, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'comm1_ctl': {'offset': 260, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'comm1_cfg': {'offset': 264, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'comm2_base': {'offset': 268, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'comm2_ctl': {'offset': 272, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'comm2_cfg': {'offset': 276, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'ust_low': {'offset': 512, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'ust_high': {'offset': 516, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'audio1_ust': {'offset': 768, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'audio1_msc': {'offset': 772, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'audio2_ust': {'offset': 776, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'audio2_msc': {'offset': 780, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'bus_number': {'offset': 68, 'access': 'r', 'width': 16, 'count': 1, 'stride': 2, 'space': 'bridge', 'reset': 'unknown', 'grade': 'established'}, 'int_enable': {'offset': 70, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': 'bridge', 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'host_ctl': {'reset': (15, 15), 'link_enable': (14, 14), 'link_failure': (2, 2), 'link_codec': (1, 1), 'link_ready': (0, 0)}, 'intr_status': {'link_err': (15, 15), 'comm2_trig': (3, 3), 'comm2_underflow': (2, 2), 'comm1_trig': (1, 1), 'comm1_overflow': (0, 0)}, 'intr_mask': {}, 'codec_command': {'busy': (15, 15), 'dir': (7, 7), 'addr': (6, 0)}, 'codec_data': {}, 'comm1_base': {}, 'comm1_ctl': {'reset': (31, 31), 'size': (30, 28), 'dma_enable': (27, 27), 'tmask': (26, 24), 'tptr': (23, 16), 'rptr': (15, 8), 'wptr': (7, 0)}, 'comm1_cfg': {'lock': (15, 15), 'slot': (6, 4), 'direction': (3, 3), 'mode': (2, 2), 'format': (1, 0)}, 'comm2_base': {}, 'comm2_ctl': {}, 'comm2_cfg': {}, 'ust_low': {}, 'ust_high': {}, 'audio1_ust': {}, 'audio1_msc': {}, 'audio2_ust': {}, 'audio2_msc': {}, 'bus_number': {'subordinate': (15, 8), 'primary': (7, 0)}, 'int_enable': {'intd': (7, 7), 'intc': (6, 6), 'intb': (5, 5), 'inta_4': (4, 4), 'inta_3': (3, 3), 'inta_2': (2, 2), 'inta_1': (1, 1), 'inta_0': (0, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'AUDIO_PAGE1': {'value': 4278251520, 'count': 1, 'stride': 1}, 'AUDIO_PAGE2': {'value': 4278255616, 'count': 1, 'stride': 1}, 'AUDIO_PHYS': {'value': 4278194176, 'count': 1, 'stride': 1}, 'DEVICE_ID': {'value': 4098, 'count': 1, 'stride': 1}, 'DMA_CHUNK': {'value': 32, 'count': 1, 'stride': 1}, 'PCI_A_PHYS': {'value': 4227858432, 'count': 1, 'stride': 1}, 'PCI_B_PHYS': {'value': 4244635648, 'count': 1, 'stride': 1}, 'VENDOR_ID': {'value': 4265, 'count': 1, 'stride': 1}}
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
