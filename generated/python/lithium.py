"""generated from devices/lithium/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 d89a40d75ef24f16f59d754d766f813b993b5cd21cff1d1fa6052589fef38dcd
Lithium (I/O ASIC of the SGI Visual Workstation 320 and 540): the PCI bridge window and the audio engine, as SGI's Linux platform code names them"""

UNIT = 'lithium'
REGISTERS = {'host_ctl': {'offset': 0, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'intr_status': {'offset': 16, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'inferred'}, 'intr_mask': {'offset': 20, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'inferred'}, 'codec_command': {'offset': 24, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'codec_data': {'offset': 28, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'comm1_base': {'offset': 256, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'comm1_ctl': {'offset': 260, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'inferred'}, 'comm1_cfg': {'offset': 264, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'inferred'}, 'comm2_base': {'offset': 268, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'comm2_ctl': {'offset': 272, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'inferred'}, 'comm2_cfg': {'offset': 276, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'inferred'}, 'ust_low': {'offset': 512, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'ust_high': {'offset': 516, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'audio1_ust': {'offset': 768, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'audio1_msc': {'offset': 772, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'audio2_ust': {'offset': 776, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'audio2_msc': {'offset': 780, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio', 'reset': 'unknown', 'grade': 'established'}, 'silence_word': {'offset': 1280, 'access': 'w', 'width': 32, 'count': 1, 'stride': 4, 'space': 'audio_page1', 'reset': 'unknown', 'grade': 'inferred'}, 'dma_pointer_copy': {'offset': 152, 'access': 'w', 'width': 32, 'count': 2, 'stride': 4, 'space': 'audio_page2', 'reset': 'unknown', 'grade': 'inferred'}, 'bridge_cmd': {'offset': 4, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': 'bridge', 'reset': 'unknown', 'grade': 'inferred'}, 'bridge_status': {'offset': 6, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': 'bridge', 'reset': 'unknown', 'grade': 'inferred'}, 'bridge_rev': {'offset': 8, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'bridge', 'reset': 'unknown', 'grade': 'established'}, 'bridge_40': {'offset': 64, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'bridge', 'reset': 'unknown', 'grade': 'inferred'}, 'bus_number': {'offset': 68, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': 'bridge', 'reset': 'unknown', 'grade': 'inferred'}, 'int_enable': {'offset': 70, 'access': 'rw', 'width': 16, 'count': 1, 'stride': 2, 'space': 'bridge', 'reset': 'unknown', 'grade': 'established'}, 'err_status': {'offset': 72, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'bridge', 'reset': 'unknown', 'grade': 'inferred'}, 'bridge_58': {'offset': 88, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'bridge', 'reset': 'unknown', 'grade': 'inferred'}, 'dma_ctl': {'offset': 96, 'access': 'rw', 'width': 32, 'count': 32, 'stride': 4, 'space': 'bridge', 'reset': 'unknown', 'grade': 'inferred'}, 'cfg_addr': {'offset': 248, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'bridge', 'reset': 'unknown', 'grade': 'established'}, 'cfg_data': {'offset': 252, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'bridge', 'reset': 'unknown', 'grade': 'established'}, 'build_stamp': {'offset': 4, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'stamp', 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'host_ctl': {'reset': (15, 15), 'link_enable': (14, 14), 'prom_bit8': (8, 8), 'link_failure': (2, 2), 'link_codec': (1, 1), 'link_ready': (0, 0)}, 'intr_status': {'link_err': (15, 15), 'comm2_trig': (3, 3), 'comm2_underflow': (2, 2), 'comm1_trig': (1, 1), 'comm1_overflow': (0, 0)}, 'intr_mask': {}, 'codec_command': {'busy': (15, 15), 'dir': (7, 7), 'addr': (6, 0)}, 'codec_data': {}, 'comm1_base': {}, 'comm1_ctl': {'reset': (31, 31), 'size': (30, 28), 'dma_enable': (27, 27), 'tmask': (26, 24), 'tptr': (23, 16), 'rptr': (15, 8), 'wptr': (7, 0)}, 'comm1_cfg': {'lock': (15, 15), 'slot': (6, 4), 'direction': (3, 3), 'mode': (2, 2), 'format': (1, 0)}, 'comm2_base': {}, 'comm2_ctl': {'reset': (31, 31), 'size': (30, 28), 'dma_enable': (27, 27), 'tmask': (26, 24), 'tptr': (23, 16), 'rptr': (15, 8), 'wptr': (7, 0)}, 'comm2_cfg': {'lock': (15, 15), 'slot': (6, 4), 'direction': (3, 3), 'mode': (2, 2), 'format': (1, 0)}, 'ust_low': {}, 'ust_high': {}, 'audio1_ust': {}, 'audio1_msc': {}, 'audio2_ust': {}, 'audio2_msc': {}, 'silence_word': {}, 'dma_pointer_copy': {}, 'bridge_cmd': {}, 'bridge_status': {}, 'bridge_rev': {}, 'bridge_40': {}, 'bus_number': {'subordinate': (15, 8), 'primary': (7, 0)}, 'int_enable': {'intd': (7, 7), 'intc': (6, 6), 'intb': (5, 5), 'inta_4': (4, 4), 'inta_3': (3, 3), 'inta_2': (2, 2), 'inta_1': (1, 1), 'inta_0': (0, 0)}, 'err_status': {}, 'bridge_58': {}, 'dma_ctl': {}, 'cfg_addr': {}, 'cfg_data': {}, 'build_stamp': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'AUDIO_DMA_CHANNELS': {'value': 7, 'count': 1, 'stride': 1}, 'AUDIO_PAGE1': {'value': 4278251520, 'count': 1, 'stride': 1}, 'AUDIO_PAGE2': {'value': 4278255616, 'count': 1, 'stride': 1}, 'AUDIO_PHYS': {'value': 4278194176, 'count': 1, 'stride': 1}, 'BRIDGE_A_PCI_MEM_PHYS': {'value': 4026531840, 'count': 1, 'stride': 1}, 'BRIDGE_B_PCI_MEM_PHYS': {'value': 4093640704, 'count': 1, 'stride': 1}, 'BRIDGE_WINDOW_MAP_SIZE': {'value': 4096, 'count': 1, 'stride': 1}, 'BUILD_STAMP_GENERATION_5': {'value': 913063419, 'count': 1, 'stride': 1}, 'CFG_ENABLE': {'value': 2147483648, 'count': 1, 'stride': 1}, 'DEVICE_ID': {'value': 4098, 'count': 1, 'stride': 1}, 'DMA_CHUNK': {'value': 32, 'count': 1, 'stride': 1}, 'DMA_LIMIT': {'value': 2147483648, 'count': 1, 'stride': 1}, 'PCI_A_PHYS': {'value': 4227858432, 'count': 1, 'stride': 1}, 'PCI_B_PHYS': {'value': 4244635648, 'count': 1, 'stride': 1}, 'PCI_IO_SIZE': {'value': 65536, 'count': 1, 'stride': 1}, 'PCI_IO_SPLIT': {'value': 32768, 'count': 1, 'stride': 1}, 'PCI_MEM_BUS_BASE': {'value': 2147483648, 'count': 1, 'stride': 1}, 'PCI_MEM_SIZE': {'value': 67108864, 'count': 1, 'stride': 1}, 'STAMP_PHYS': {'value': 4278304768, 'count': 1, 'stride': 1}, 'STATUS_MASTER_ABORT': {'value': 8192, 'count': 1, 'stride': 1}, 'TABLE_WINDOW_PHYS': {'value': 4278288384, 'count': 1, 'stride': 1}, 'TABLE_WINDOW_SIZE': {'value': 16384, 'count': 1, 'stride': 1}, 'VENDOR_ID': {'value': 4265, 'count': 1, 'stride': 1}}
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
