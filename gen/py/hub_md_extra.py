"""generated from defs/hub_md_extra.toml by defs-gen - do not edit, change the source
Hub memory and directory register layouts and constants outside the census"""

UNIT = 'hub_md_extra'
REGISTERS = {}
WORDS = {'MD_DIMM_INIT_FORMAT': {'width': 64, 'grade': 'established'}, 'MD_DIR_ERROR_FORMAT': {'width': 64, 'grade': 'established'}, 'MD_MEMORY_CONFIG_FORMAT': {'width': 64, 'grade': 'established'}, 'MD_MEM_ERROR_FORMAT': {'width': 64, 'grade': 'established'}, 'MD_MIG_CANDIDATE_FORMAT': {'width': 64, 'grade': 'established'}, 'MD_MIG_THRESH_FORMAT': {'width': 64, 'grade': 'established'}, 'MD_MISC_ERROR_FORMAT': {'width': 64, 'grade': 'established'}, 'MD_MLAN_CTL_FORMAT': {'width': 64, 'grade': 'established'}, 'MD_MOQ_SIZE_FORMAT': {'width': 64, 'grade': 'established'}, 'MD_PERF_CNT_FORMAT': {'width': 64, 'grade': 'inferred'}, 'MD_PERF_SEL_FORMAT': {'width': 64, 'grade': 'inferred'}, 'MD_PROTOCOL_ERROR_FORMAT': {'width': 64, 'grade': 'established'}, 'MD_REFRESH_CONTROL_FORMAT': {'width': 64, 'grade': 'established'}, 'MD_SLOTID_USTAT_FORMAT': {'width': 64, 'grade': 'established'}}
FIELDS = {'MD_DIMM_INIT_FORMAT': {'select': (35, 32), 'mode': (11, 0)}, 'MD_DIR_ERROR_FORMAT': {'uce_vld': (63, 63), 'ae_vld': (62, 62), 'ce_vld': (61, 61), 'bad_prot': (41, 39), 'bad_syn': (38, 32), 'hspec_addr': (29, 3), 'uce_ovr': (2, 2), 'ae_ovr': (1, 1), 'ce_ovr': (0, 0)}, 'MD_MEMORY_CONFIG_FORMAT': {'fprom_cyc': (53, 49), 'fprom_wr': (48, 44), 'uctlr_cyc': (43, 39), 'uctlr_wr': (38, 34), 'dimm0_sel': (33, 32), 'io_prot_en': (31, 31), 'arb_mlss': (30, 30), 'ignore_ecc': (29, 29), 'dir_premium': (28, 28), 'reply_guar': (27, 24), 'bank7': (23, 21), 'bank6': (20, 18), 'bank5': (17, 15), 'bank4': (14, 12), 'bank3': (11, 9), 'bank2': (8, 6), 'bank1': (5, 3), 'bank0': (2, 0)}, 'MD_MEM_ERROR_FORMAT': {'uce_vld': (63, 63), 'ce_vld': (62, 62), 'bad_syn': (39, 32), 'address': (31, 3), 'uce_ovr': (1, 1), 'ce_ovr': (0, 0)}, 'MD_MIG_CANDIDATE_FORMAT': {'valid': (63, 63), 'type': (30, 30), 'overrun': (29, 29)}, 'MD_MIG_THRESH_FORMAT': {'valid': (63, 63), 'value': (19, 0)}, 'MD_MISC_ERROR_FORMAT': {'ill_msg': (9, 8), 'ill_rev': (7, 6), 'long_pack': (5, 4), 'short_pack': (3, 2), 'bad_data': (1, 0)}, 'MD_MLAN_CTL_FORMAT': {'phi1': (33, 27), 'phi0': (26, 20), 'pulse': (19, 10), 'sample': (9, 2), 'done': (1, 1), 'rd_data': (0, 0)}, 'MD_MOQ_SIZE_FORMAT': {'rp_size': (13, 8), 'rq_size': (4, 0)}, 'MD_PERF_CNT_FORMAT': {'perf_cnt': (19, 0)}, 'MD_PERF_SEL_FORMAT': {'perf_en': (3, 3), 'perf_sel': (2, 0)}, 'MD_PROTOCOL_ERROR_FORMAT': {'valid': (63, 63), 'initiator': (60, 50), 'backoff': (49, 48), 'msg_type': (47, 40), 'access': (39, 38), 'priority': (37, 37), 'dir_state': (36, 33), 'pointer_me': (32, 32), 'address': (31, 3), 'overrun': (0, 0)}, 'MD_REFRESH_CONTROL_FORMAT': {'enable': (63, 63), 'counter': (23, 12), 'threshold': (11, 0)}, 'MD_SLOTID_USTAT_FORMAT': {'core_clk_test': (7, 7), 'core_clk': (6, 6), 'net_sync': (5, 5), 'fprom_ready': (4, 4), 'i2c_intr': (3, 3), 'sn0_slot_id': (2, 0)}}
ENUMS = {}
FIELD_ENUM = {}
CONSTANTS = {'HUB_MD_BANK_MASK': {'value': 3758096384, 'count': 1, 'stride': 1}, 'HUB_MD_BANK_SHIFT': {'value': 29, 'count': 1, 'stride': 1}, 'HUB_MD_DIRTYPE_PREMIUM': {'value': 1, 'count': 1, 'stride': 1}, 'HUB_MD_DIRTYPE_STANDARD': {'value': 0, 'count': 1, 'stride': 1}, 'HUB_MD_DIR_BUSY_EXCL': {'value': 4, 'count': 1, 'stride': 1}, 'HUB_MD_DIR_BUSY_SHARED': {'value': 3, 'count': 1, 'stride': 1}, 'HUB_MD_DIR_EXCLUSIVE': {'value': 2, 'count': 1, 'stride': 1}, 'HUB_MD_DIR_POISONED': {'value': 1, 'count': 1, 'stride': 1}, 'HUB_MD_DIR_SHARED': {'value': 0, 'count': 1, 'stride': 1}, 'HUB_MD_DIR_UNOWNED': {'value': 7, 'count': 1, 'stride': 1}, 'HUB_MD_DIR_WAIT': {'value': 5, 'count': 1, 'stride': 1}, 'HUB_MD_MEMORY_CONFIG_RESET_DEFAULTS': {'value': 8584695805640703, 'count': 1, 'stride': 1}, 'HUB_MD_MEM_BANKS_M_MODE': {'value': 8, 'count': 1, 'stride': 1}, 'HUB_MD_MEM_BANKS_N_MODE': {'value': 4, 'count': 1, 'stride': 1}, 'HUB_MD_MLAN_CTL_ACCESS_BYTES': {'value': 8, 'count': 1, 'stride': 1}, 'HUB_MD_MLAN_CTL_RESET_DEFAULTS': {'value': 6628048896, 'count': 1, 'stride': 1}, 'HUB_MD_MOQ_SIZE_RESET_DEFAULTS': {'value': 12818, 'count': 1, 'stride': 1}, 'HUB_MD_REFRESH_CONTROL_RESET_DEFAULTS': {'value': 1024, 'count': 1, 'stride': 1}, 'HUB_MD_SIZE_128MB': {'value': 5, 'count': 1, 'stride': 1}, 'HUB_MD_SIZE_16MB': {'value': 2, 'count': 1, 'stride': 1}, 'HUB_MD_SIZE_1GB': {'value': 8, 'count': 1, 'stride': 1}, 'HUB_MD_SIZE_256MB': {'value': 6, 'count': 1, 'stride': 1}, 'HUB_MD_SIZE_2GB': {'value': 9, 'count': 1, 'stride': 1}, 'HUB_MD_SIZE_32MB': {'value': 3, 'count': 1, 'stride': 1}, 'HUB_MD_SIZE_4GB': {'value': 10, 'count': 1, 'stride': 1}, 'HUB_MD_SIZE_512MB': {'value': 7, 'count': 1, 'stride': 1}, 'HUB_MD_SIZE_64MB': {'value': 4, 'count': 1, 'stride': 1}, 'HUB_MD_SIZE_8MB': {'value': 1, 'count': 1, 'stride': 1}, 'HUB_MD_SIZE_EMPTY': {'value': 0, 'count': 1, 'stride': 1}}
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
