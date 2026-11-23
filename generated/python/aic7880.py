"""generated from devices/aic7880/registers.toml by defs-gen - do not edit, change the source
defs-gen 3
input sha256 ac8f8281afc714636b4ace8e210fce455439bfb20a364794f5b732f8998e4655
Adaptec AIC-7880 SCSI controller on the O2: host DMA and SCB register contract"""

UNIT = 'aic7880'
REGISTERS = {'scsiseq': {'offset': 0, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'sxfrctl0': {'offset': 1, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'sxfrctl1': {'offset': 2, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'scsisig': {'offset': 3, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'scsirate': {'offset': 4, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'scsiid': {'offset': 5, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'scsidatl': {'offset': 6, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'clrsint1': {'offset': 12, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'simode0': {'offset': 16, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'simode1': {'offset': 17, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'scsibusl': {'offset': 18, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'shaddr': {'offset': 20, 'access': 'r', 'width': 8, 'count': 4, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'selid': {'offset': 25, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'sblkctl': {'offset': 31, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'seqctl': {'offset': 96, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 144, 'grade': 'inferred'}, 'seqaddr0': {'offset': 98, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'seqaddr1': {'offset': 99, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'accum': {'offset': 100, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'sindex': {'offset': 101, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'dindex': {'offset': 102, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'brkaddr0': {'offset': 103, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'brkaddr1': {'offset': 104, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 128, 'grade': 'inferred'}, 'allones': {'offset': 105, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'allzeros': {'offset': 106, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'flags': {'offset': 107, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'sindir': {'offset': 108, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'dindir': {'offset': 109, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'function1': {'offset': 110, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'stack': {'offset': 111, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'dspcistatus': {'offset': 134, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'hcntrl': {'offset': 135, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 5, 'grade': 'inferred'}, 'lhaddr': {'offset': 136, 'access': 'rw', 'width': 32, 'count': 1, 'stride': 4, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'hcnt': {'offset': 140, 'access': 'rw', 'width': 8, 'count': 3, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'scbptr': {'offset': 144, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'intstat': {'offset': 145, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'clrint': {'offset': 146, 'access': 'w', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'dfcntrl': {'offset': 147, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'dfstatus': {'offset': 148, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'dfdat': {'offset': 153, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}, 'scbcnt': {'offset': 154, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'qinfifo': {'offset': 155, 'access': 'rw', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'qincnt': {'offset': 156, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'qoutcnt': {'offset': 158, 'access': 'r', 'width': 8, 'count': 1, 'stride': 1, 'space': None, 'reset': 0, 'grade': 'inferred'}, 'scbwin': {'offset': 160, 'access': 'rw', 'width': 8, 'count': 32, 'stride': 1, 'space': None, 'reset': 'unknown', 'grade': 'inferred'}}
WORDS = {}
FIELDS = {'scsiseq': {'temodeo': (7, 7), 'enselo': (6, 6), 'enseli': (5, 5), 'enrseli': (4, 4), 'enautoatno': (3, 3), 'enautoatni': (2, 2), 'enautoatnp': (1, 1), 'scsirsto': (0, 0)}, 'sxfrctl0': {'dfon': (7, 7), 'clrstcnt': (4, 4), 'spioen': (3, 3), 'clrchn': (1, 1)}, 'sxfrctl1': {'bitbucket': (7, 7), 'swrapen': (6, 6), 'enspchk': (5, 5), 'stimesel': (4, 3), 'enstimer': (2, 2), 'actnegen': (1, 1), 'stpwen': (0, 0)}, 'scsisig': {'cd': (7, 7), 'io': (6, 6), 'msg': (5, 5), 'atn': (4, 4), 'sel': (3, 3), 'bsy': (2, 2), 'req': (1, 1), 'ack': (0, 0)}, 'scsirate': {'wide': (7, 7), 'sxfr': (6, 4), 'sofs': (3, 0)}, 'scsiid': {'tid': (7, 4), 'oid': (3, 0)}, 'scsidatl': {}, 'clrsint1': {'clratno': (6, 6)}, 'simode0': {'enspiordy': (1, 1)}, 'simode1': {'enseltimo': (7, 7), 'enatntarg': (6, 6), 'enscsirst': (5, 5), 'enphasemis': (4, 4), 'enbusfree': (3, 3), 'enscsiperr': (2, 2), 'enphasechg': (1, 1), 'enreqinit': (0, 0)}, 'scsibusl': {}, 'shaddr': {}, 'selid': {'selid': (7, 4), 'onebit': (3, 3)}, 'sblkctl': {'diagled': (7, 6), 'autoflushdis': (5, 5), 'selbusb': (3, 3), 'selwide': (1, 1)}, 'seqctl': {'pausedis': (6, 6), 'fastmode': (4, 4), 'step': (2, 2), 'seqreset': (1, 1), 'loadram': (0, 0)}, 'seqaddr0': {}, 'seqaddr1': {'addr8': (0, 0)}, 'accum': {}, 'sindex': {}, 'dindex': {}, 'brkaddr0': {}, 'brkaddr1': {'brkdis': (7, 7), 'brkaddr8': (0, 0)}, 'allones': {}, 'allzeros': {}, 'flags': {'zero': (1, 1), 'carry': (0, 0)}, 'sindir': {}, 'dindir': {}, 'function1': {'select': (6, 4)}, 'stack': {}, 'dspcistatus': {'dfthrsh': (7, 6), 'pcistatus': (5, 0)}, 'hcntrl': {'powrdn': (6, 6), 'swint': (4, 4), 'hcntrl3': (3, 3), 'pause': (2, 2), 'inten': (1, 1), 'chiprst': (0, 0)}, 'lhaddr': {}, 'hcnt': {}, 'scbptr': {}, 'intstat': {'intcode': (7, 4), 'brkadrint': (3, 3), 'scsiint': (2, 2), 'cmdcmplt': (1, 1), 'seqint': (0, 0)}, 'clrint': {'clrparerr': (4, 4), 'clrbrkadrint': (3, 3), 'clrscsiint': (2, 2), 'clrcmdint': (1, 1), 'clrseqint': (0, 0)}, 'dfcntrl': {'wideodd': (6, 6), 'scsien': (5, 5), 'sdmaen': (4, 4), 'hdmaen': (3, 3), 'direction': (2, 2), 'fifoflush': (1, 1), 'fiforeset': (0, 0)}, 'dfstatus': {'dfthrsh': (2, 2)}, 'dfdat': {}, 'scbcnt': {'scbauto': (7, 7), 'scbofs': (4, 0)}, 'qinfifo': {}, 'qincnt': {}, 'qoutcnt': {}, 'scbwin': {}}
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
