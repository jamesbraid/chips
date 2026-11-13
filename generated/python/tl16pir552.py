"""generated from devices/tl16pir552/registers.toml by defs-gen - do not edit, change the source
TI TL16PIR552 dual UART and IEEE 1284 parallel port, parallel-port register contract (Fuel and Origin 200 board part)"""

UNIT = 'tl16pir552'
REGISTERS = {'cnfgb': {'offset': 1, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'ecpcs', 'reset': 'unknown', 'grade': 'established'}, 'ecr': {'offset': 2, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'ecpcs', 'reset': 'unknown', 'grade': 'established'}, 'cnfga': {'offset': 0, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'ecpcs_cfg', 'reset': 31, 'grade': 'established'}, 'pp_fifo': {'offset': 0, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'ecpcs_cfifo', 'reset': 'unknown', 'grade': 'established'}, 'ecp_dfifo': {'offset': 0, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'ecpcs_ecp', 'reset': 'unknown', 'grade': 'established'}, 'test_fifo': {'offset': 0, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'ecpcs_tfifo', 'reset': 'unknown', 'grade': 'established'}, 'data': {'offset': 0, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'ppcs', 'reset': 'unknown', 'grade': 'established'}, 'dsr': {'offset': 1, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': 'ppcs', 'reset': 'unknown', 'grade': 'established'}, 'dcr': {'offset': 2, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'ppcs', 'reset': 'unknown', 'grade': 'established'}, 'epp_addr': {'offset': 3, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': 'ppcs', 'reset': 'unknown', 'grade': 'established'}, 'epp_data': {'offset': 4, 'access': 'rw', 'width': 8, 'count': 4, 'stride': 1, 'space': 'ppcs', 'reset': 'unknown', 'grade': 'established'}, 'ecp_afifo': {'offset': 0, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': 'ppcs_ecp', 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'cnfgb': {'compression': (7, 7), 'irq_line_sample': (6, 6), 'irq_select': (5, 3), 'dma_select': (2, 0)}, 'ecr': {'mode': (7, 5), 'ecp_fault_irq_disable': (4, 4), 'dma_enable': (3, 3), 'service_intr_disable': (2, 2), 'fifo_full': (1, 1), 'fifo_empty': (0, 0)}, 'cnfga': {'impl_id': (7, 4), 'reserved_low': (3, 0)}, 'pp_fifo': {}, 'ecp_dfifo': {}, 'test_fifo': {}, 'data': {}, 'dsr': {}, 'dcr': {'direction': (5, 5), 'irq_on_ack': (4, 4), 'select_ctl': (3, 3), 'init_ctl': (2, 2), 'autofd_ctl': (1, 1), 'strobe_ctl': (0, 0)}, 'epp_addr': {}, 'epp_data': {}, 'ecp_afifo': {}}
ENUMS = {'cnfgb_irq_select': {1: 'irq7'}, 'cnfgb_dma_select': {3: 'dma3'}, 'ecr_mode': {0: 'standard', 1: 'bidirectional', 2: 'parallel_fifo', 3: 'ecp', 4: 'epp', 5: 'reserved', 6: 'test_fifo', 7: 'configuration'}}
FIELD_ENUM = {'cnfgb.irq_select': 'cnfgb_irq_select', 'cnfgb.dma_select': 'cnfgb_dma_select', 'ecr.mode': 'ecr_mode'}
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
