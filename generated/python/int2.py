"""generated from devices/int2/registers.toml by defs-gen - do not edit, change the source
defs-gen 4
input sha256 ddb7d5c9a928bcccdae1a8a3a03b7439bba8c65460f360e653d4e8612963b52e
INT2 local interrupt controller and 8254 timer block (Indigo, R3000 and R4000 boards)"""

UNIT = 'int2'
REGISTERS = {'local0_status': {'offset': 3, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'local0_mask': {'offset': 7, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'established'}, 'local1_status': {'offset': 11, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'local1_mask': {'offset': 15, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'established'}, 'vme_status': {'offset': 19, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'vme0_mask': {'offset': 23, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'established'}, 'vme1_mask': {'offset': 27, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'established'}, 'port_config': {'offset': 31, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'timer_ack': {'offset': 35, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'error_status': {'offset': 39, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'unknown'}, 'timer0': {'offset': 51, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'timer1': {'offset': 55, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'timer2': {'offset': 59, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'established'}, 'timer_control': {'offset': 63, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'established'}}
WORDS = {}
FIELDS = {'local0_status': {}, 'local0_mask': {}, 'local1_status': {}, 'local1_mask': {}, 'vme_status': {}, 'vme0_mask': {}, 'vme1_mask': {}, 'port_config': {'power': (4, 4), 'vr_interrupt_latch': (3, 3), 'ser1_rts': (2, 2), 'ser0_rts': (1, 1), 'parity_or_ext_clock': (0, 0)}, 'timer_ack': {'timer1': (1, 1), 'timer0': (0, 0)}, 'error_status': {}, 'timer0': {}, 'timer1': {}, 'timer2': {}, 'timer_control': {'counter': (7, 6), 'rw': (5, 4), 'mode': (3, 1), 'bcd': (0, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'ACK_TIMER0': {'value': 1, 'count': 1, 'stride': 1}, 'ACK_TIMER1': {'value': 2, 'count': 1, 'stride': 1}, 'LOCAL0_CENTR': {'value': 2, 'count': 1, 'stride': 1}, 'LOCAL0_DUART': {'value': 32, 'count': 1, 'stride': 1}, 'LOCAL0_ENET': {'value': 8, 'count': 1, 'stride': 1}, 'LOCAL0_FIFO': {'value': 1, 'count': 1, 'stride': 1}, 'LOCAL0_GDMA': {'value': 16, 'count': 1, 'stride': 1}, 'LOCAL0_GIO1': {'value': 64, 'count': 1, 'stride': 1}, 'LOCAL0_SCSI': {'value': 4, 'count': 1, 'stride': 1}, 'LOCAL0_VME0': {'value': 128, 'count': 1, 'stride': 1}, 'LOCAL1_ACFAIL': {'value': 32, 'count': 1, 'stride': 1}, 'LOCAL1_DSP': {'value': 16, 'count': 1, 'stride': 1}, 'LOCAL1_GIO2': {'value': 128, 'count': 1, 'stride': 1}, 'LOCAL1_GR1MODE': {'value': 2, 'count': 1, 'stride': 1}, 'LOCAL1_VIDEO': {'value': 64, 'count': 1, 'stride': 1}, 'LOCAL1_VME1': {'value': 8, 'count': 1, 'stride': 1}, 'TIMER_MASTER_HZ': {'value': 1000000, 'count': 1, 'stride': 1}}
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
