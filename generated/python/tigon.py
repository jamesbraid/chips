"""generated from devices/tigon/registers.toml by defs-gen - do not edit, change the source
Alteon Tigon PCI/Gigabit Ethernet controller (SGI IRIS Gigabit Ethernet board)"""

UNIT = 'tigon'
REGISTERS = {'misc_host_ctl': {'offset': 64, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'pci_state': {'offset': 92, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 0, 'grade': 'established'}, 'dma_write_state': {'offset': 160, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'dma_read_state': {'offset': 176, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'mailbox_0_low': {'offset': 1284, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'misc_host_ctl': {'gate_array_revision': (31, 28), 'mask_pci_interrupt': (6, 6), 'endian_word_swap': (5, 5), 'endian_byte_swap': (4, 4), 'hard_reset': (3, 3), 'clear_interrupt': (1, 1), 'interrupt_state': (0, 0)}, 'pci_state': {'default_pci_write_command': (31, 28), 'default_pci_read_command': (27, 24), 'assert_all_pbe_on_writes': (23, 23), 'pci_rom_retry': (22, 22), 'pci_rom_desired': (21, 21), 'bus_32bit': (20, 20), 'pci_66mhz_bus': (19, 19), 'no_word_swap_dma': (18, 18), 'use_mem_read_multiple': (17, 17), 'dma_write_max': (7, 5), 'dma_read_max': (4, 2), 'force_reset': (0, 0)}, 'dma_write_state': {'force_32bit_pci': (3, 3), 'dma_active': (2, 2), 'dma_no_swap': (1, 1), 'dma_reset': (0, 0)}, 'dma_read_state': {'force_32bit_pci': (3, 3), 'dma_active': (2, 2), 'dma_no_swap': (1, 1), 'dma_reset': (0, 0)}, 'mailbox_0_low': {}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {}
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
