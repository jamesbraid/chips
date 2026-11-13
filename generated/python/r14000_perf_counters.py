"""generated from devices/r14000_perf_counters/registers.toml by defs-gen - do not edit, change the source
R14000 CP0 performance counters: selectors, control fields and event numbers"""

UNIT = 'r14000_perf_counters'
REGISTERS = {}
WORDS = {}
FIELDS = {}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'R14KPC_CNT_BITS': {'value': 32, 'count': 1, 'stride': 1}, 'R14KPC_CNT_OVERFLOW_BIT': {'value': 31, 'count': 1, 'stride': 1}, 'R14KPC_CP0_REG': {'value': 25, 'count': 1, 'stride': 1}, 'R14KPC_CTL_EVENT_MASK': {'value': 992, 'count': 1, 'stride': 1}, 'R14KPC_CTL_EVENT_SHIFT': {'value': 5, 'count': 1, 'stride': 1}, 'R14KPC_CTL_EXL': {'value': 1, 'count': 1, 'stride': 1}, 'R14KPC_CTL_IE': {'value': 16, 'count': 1, 'stride': 1}, 'R14KPC_CTL_K': {'value': 2, 'count': 1, 'stride': 1}, 'R14KPC_CTL_S': {'value': 4, 'count': 1, 'stride': 1}, 'R14KPC_CTL_U': {'value': 8, 'count': 1, 'stride': 1}, 'R14KPC_EV_CYCLES': {'value': 0, 'count': 1, 'stride': 1}, 'R14KPC_EV_DECODED_INSTR': {'value': 1, 'count': 1, 'stride': 1}, 'R14KPC_EV_FAILED_SC': {'value': 5, 'count': 1, 'stride': 1}, 'R14KPC_EV_MISPREDICT': {'value': 24, 'count': 1, 'stride': 1}, 'R14KPC_EV_PREFETCH_EXEC': {'value': 16, 'count': 1, 'stride': 1}, 'R14KPC_EV_RETIRED_FP': {'value': 21, 'count': 1, 'stride': 1}, 'R14KPC_EV_RETIRED_INSTR': {'value': 15, 'count': 1, 'stride': 1}, 'R14KPC_EV_SCACHE_ECC_CORRECTABLE': {'value': 8, 'count': 1, 'stride': 1}, 'R14KPC_EV_TLB_MISS': {'value': 23, 'count': 1, 'stride': 1}, 'R14KPC_EV_UNIMPLEMENTED': {'value': 14, 'count': 1, 'stride': 1}, 'R14KPC_PAIR0_CNT_SEL': {'value': 1, 'count': 1, 'stride': 1}, 'R14KPC_PAIR0_CTL_SEL': {'value': 0, 'count': 1, 'stride': 1}, 'R14KPC_PAIR1_CNT_SEL': {'value': 3, 'count': 1, 'stride': 1}, 'R14KPC_PAIR1_CTL_SEL': {'value': 2, 'count': 1, 'stride': 1}, 'R14KPC_PAIR2_CNT_SEL': {'value': 5, 'count': 1, 'stride': 1}, 'R14KPC_PAIR2_CTL_SEL': {'value': 4, 'count': 1, 'stride': 1}, 'R14KPC_PAIR3_CNT_SEL': {'value': 7, 'count': 1, 'stride': 1}, 'R14KPC_PAIR3_CTL_SEL': {'value': 6, 'count': 1, 'stride': 1}, 'R14KPC_PAIRS': {'value': 4, 'count': 1, 'stride': 1}, 'R14KPC_R12K_CTL0_TRIGGER_MASK': {'value': 98304, 'count': 1, 'stride': 1}, 'R14KPC_R12K_CTL3_LEVEL_BIT': {'value': 32768, 'count': 1, 'stride': 1}, 'R14KPC_R12K_CTL_COND_MASK': {'value': 31744, 'count': 1, 'stride': 1}}
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
