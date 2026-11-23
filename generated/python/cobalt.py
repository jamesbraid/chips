"""generated from devices/cobalt/registers.toml by defs-gen - do not edit, change the source
defs-gen 2
input sha256 20f482005a324addbb08bda15ddc0986046d26510e25bccbbd22bdfb507c0ee3
Cobalt (system ASIC of the SGI Visual Workstation 320 and 540): the CPU block with its timer, and the interrupt controller"""

UNIT = 'cobalt'
REGISTERS = {'apic_lo': {'offset': 0, 'access': 'rw', 'width': 32, 'count': 30, 'stride': 16, 'space': 'apic', 'reset': 'unknown', 'grade': 'established'}, 'apic_hi': {'offset': 4, 'access': 'rw', 'width': 32, 'count': 30, 'stride': 16, 'space': 'apic', 'reset': 'unknown', 'grade': 'established'}, 'apic_id': {'offset': 4092, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'apic', 'reset': 'unknown', 'grade': 'established'}, 'cpu_rev': {'offset': 8, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'cpu', 'reset': 'unknown', 'grade': 'established'}, 'cpu_ctrl': {'offset': 16, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'cpu', 'reset': 'unknown', 'grade': 'established'}, 'cpu_reset': {'offset': 24, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'cpu', 'reset': 'unknown', 'grade': 'established'}, 'cpu_stat': {'offset': 32, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'cpu', 'reset': 'unknown', 'grade': 'established'}, 'cpu_timeval': {'offset': 48, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'cpu', 'reset': 'unknown', 'grade': 'established'}, 'cpu_timecur': {'offset': 56, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'cpu', 'reset': 'unknown', 'grade': 'established'}, 'cpu_cacheop_ctl': {'offset': 64, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'cpu', 'reset': 'unknown', 'grade': 'inferred'}, 'cpu_cacheop_addr': {'offset': 72, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': 'cpu', 'reset': 'unknown', 'grade': 'inferred'}, 'cpu_cacheop_busy': {'offset': 80, 'access': 'r', 'width': 32, 'count': 1, 'stride': 4, 'space': 'cpu', 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'apic_lo': {'bit17': (17, 17), 'mask': (16, 16), 'level': (15, 15), 'remote_irr': (14, 14), 'dest_mode': (11, 11), 'delivery_mode': (10, 8), 'vector': (7, 0)}, 'apic_hi': {'dest': (31, 24)}, 'apic_id': {'id': (27, 24), 'enable': (8, 8)}, 'cpu_rev': {}, 'cpu_ctrl': {'timer_mask': (3, 3), 'timer_run': (2, 2), 'page_close': (1, 1), 'ecc_enable': (0, 0)}, 'cpu_reset': {'reset': (0, 0)}, 'cpu_stat': {'timer_intr': (1, 1), 'cacheop_intr': (0, 0)}, 'cpu_timeval': {}, 'cpu_timecur': {}, 'cpu_cacheop_ctl': {}, 'cpu_cacheop_addr': {}, 'cpu_cacheop_busy': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'APIC_8259': {'value': 12, 'count': 1, 'stride': 1}, 'APIC_AS': {'value': 24, 'count': 1, 'stride': 1}, 'APIC_CPU': {'value': 28, 'count': 1, 'stride': 1}, 'APIC_IDE0': {'value': 4, 'count': 1, 'stride': 1}, 'APIC_IDE1': {'value': 2, 'count': 1, 'stride': 1}, 'APIC_LINES': {'value': 30, 'count': 1, 'stride': 1}, 'APIC_LI_AUDIO': {'value': 22, 'count': 1, 'stride': 1}, 'APIC_MEM_ERR0': {'value': 26, 'count': 1, 'stride': 1}, 'APIC_MEM_ERR1': {'value': 27, 'count': 1, 'stride': 1}, 'APIC_NMI': {'value': 29, 'count': 1, 'stride': 1}, 'APIC_PCIA_BASE0': {'value': 0, 'count': 1, 'stride': 1}, 'APIC_PCIA_BASE123': {'value': 5, 'count': 1, 'stride': 1}, 'APIC_PCIB_BASE0': {'value': 8, 'count': 1, 'stride': 1}, 'APIC_PCIB_BASE123': {'value': 13, 'count': 1, 'stride': 1}, 'APIC_PHYS': {'value': 3288334336, 'count': 1, 'stride': 1}, 'APIC_PIIX4_USB': {'value': 7, 'count': 1, 'stride': 1}, 'APIC_RE': {'value': 25, 'count': 1, 'stride': 1}, 'APIC_VIDIN0': {'value': 18, 'count': 1, 'stride': 1}, 'APIC_VIDIN1': {'value': 19, 'count': 1, 'stride': 1}, 'APIC_VIDOUT0': {'value': 16, 'count': 1, 'stride': 1}, 'APIC_VIDOUT1': {'value': 17, 'count': 1, 'stride': 1}, 'CPU_MAX': {'value': 4, 'count': 1, 'stride': 1}, 'CPU_NUM_PHYS': {'value': 7680, 'count': 1, 'stride': 1}, 'CPU_PHYS': {'value': 3254779904, 'count': 1, 'stride': 1}, 'TIME_HZ': {'value': 100000000, 'count': 1, 'stride': 1}}
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
