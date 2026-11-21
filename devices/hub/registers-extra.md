<!-- generated from devices/hub/registers-extra.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 7704657248a0fc8036bec883c4fcec87a565d969ba87cc19c1e9bc8d2ae9aa05 -->

# Hub block transfer engine registers and control bits outside the census

Unit `hub_extra`, macro prefix `HUB`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `iio_wid` | 0x400000 | r | 64 |  |  | 0x1c101048 (established) | established |  |
| `iio_wstat` | 0x400008 | r | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (r, indexed) |
| `iio_wcr` | 0x400020 | r | 64 |  |  | 0x4001 (established) | established | census: 2 sites, 2 routines |
| `iio_ilapr` | 0x400100 | rw | 64 |  |  | 0xffffffffffffffff (established) | established |  |
| `iio_ilapo` | 0x400108 | w | 64 |  |  | unknown | established |  |
| `iio_iowa` | 0x400110 | rw | 64 |  |  | 0x0 (established) | established | census: 6 sites, 3 routines |
| `iio_iiwa` | 0x400118 | r | 64 |  |  | 0x0 (established) | established | census: 2 sites, 2 routines |
| `iio_ilcsr` | 0x400128 | rw | 64 |  |  | 0x3fc03ff000a (established) | established | census: 2 sites, 1 routines (rw); census: 6 sites, 4 routines (rw, indexed) |
| `iio_illr` | 0x400130 | rw | 64 |  |  | 0x0 (established) | established | census: 2 sites, 1 routines (rw); census: 3 sites, 2 routines (rw, indexed) |
| `iio_iidsr` | 0x400138 | rw | 64 |  |  | 0x0 (established) | established | census: 12 sites, 5 routines |
| `iio_igfx_0` | 0x400140 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `iio_igfx_1` | 0x400148 | rw | 64 |  |  | unknown | inferred |  |
| `iio_scratch_reg0` | 0x400150 | rw | 64 |  |  | 0x0 (established) | established |  |
| `iio_scratch_reg1` | 0x400158 | rw | 64 |  |  | 0x0 (established) | established |  |
| `iio_itte` | 0x400160 | rw | 64 | 7 |  | 0x0 (established) | established |  |
| `iio_imem` | 0x4001e8 | rw | 64 |  |  | unknown | established | census: 4 sites, 3 routines |
| `iio_ieclr` | 0x4001f8 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines (w); census: 5 sites, 4 routines (rw, indexed) |
| `iio_iibuserr` | 0x400208 | r | 64 |  |  | unknown | inferred | public Linux SN0 Hub I/O header: IIO_IIBUSERR (offset and name; the header lists it as 0x1400208 in the local I/O window, which is this offset past the 0x1000000 window base) |
| `iio_ipdr` | 0x400388 | rw | 64 |  |  | 0x0 (established) | established | census: 5 sites, 2 routines |
| `iio_icdr` | 0x400390 | rw | 64 |  |  | 0x0 (established) | established | census: 3 sites, 1 routines |
| `iio_ifdr` | 0x400398 | rw | 64 |  |  | 0x0 (established) | established | census: 8 sites, 3 routines |
| `iio_icmr` | 0x4003a8 | rw | 64 |  |  | 0x0 (established) | established | census: 6 sites, 3 routines |
| `iio_iccr` | 0x4003b0 | rw | 64 |  |  | 0x0 (established) | established | census: 7 sites, 1 routines |
| `iio_ibls_0` | 0x410000 | rw | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (w, indexed) |
| `iio_ibct_0` | 0x410018 | r | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `iio_ibna_0` | 0x410020 | rw | 64 |  |  | 0x0 (established) | established |  |
| `iio_ibia_0` | 0x410028 | rw | 64 |  |  | 0x0 (established) | established |  |
| `iio_ibls_1` | 0x420000 | rw | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines (r); census: 3 sites, 1 routines (rw, indexed) |
| `iio_ibct_1` | 0x420018 | rw | 64 |  |  | 0x0 (established) | established | census: 3 sites, 1 routines |
| `iio_ibia_1` | 0x420028 | rw | 64 |  |  | 0x0 (established) | established |  |
| `iio_ipcr` | 0x430000 | rw | 64 |  |  | unknown | established | census: 4 sites, 2 routines |
| `iio_ippr` | 0x430008 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |

### Register `iio_wid`

Widget identification register of the Hub widget. Offset and field layout are from the public header. The header gives no access type and no reset value, so the The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `rev` | established |  |  | Revision number, bits 31:28, in the header's identification structure. |
| 27:12 | `part` | established |  |  | Widget part number, bits 27:12, in the header's identification structure. The header comment gives the Hub's value, IIO_WID_PART_HUB. |
| 11:1 | `mfg` | established |  |  | Manufacturer number, bits 11:1, in the header's identification structure. The header comment names a manufacturer; the name is not imported here, and the value is unknown. |

### Register `iio_wstat`

The rsvd mask is the members the header's structure names reserved (rsvd1 to rsvd4); the header gives no read or write behaviour for them, so the mask is the header's naming, graded established as a header fact only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `crazy` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Hub gone crazy, bit 32 (IIO_WSTAT_ECRAZY and the structure's crazy member). |
| 23:16 | `llp_tx_cnt` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Link transmit retry counter. The structure gives eight bits at 23:16; the same header's IIO_WSTAT_TXRETRY_MASK gives seven. |
| 9 | `tx_max_rtry` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Link retry timeout signal, bit 9 (IIO_WSTAT_TXRETRY and the structure's tx_max_rtry member). |
| 6 | `xt_tail_to` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Crosstalk tail timeout. Position from the structure's member order, counted down from the top; the structure holds 63 bits, so this assumes the spare bit is bit 0. |
| 5 | `xt_crd_to` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Crosstalk credit timeout. Position as for xt_tail_to. |
| 4:1 | `pending` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Pending requests, four bits. Position as for xt_tail_to; the structure may instead place them at 3:0. |

### Register `iio_wcr`

The rsvd mask is the structure's rsvd and rsvd1 members; header naming only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:18 | `e_thresh` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Elasticity threshold, five bits. |
| 17 | `dir_con` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Widget direct connect (IIO_WCR_DIR_CON). |
| 16 | `f_bad_pkt` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Force bad link packet enable. |
| 15:13 | `xbar_crd` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Link crossbar credit, three bits. |
| 4 | `tag_mode` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Tag mode. |
| 3:0 | `widget_id` | established |  | public Linux SN0 Hub I/O header: field layout and masks | The Hub's own widget number, four bits (read with a 0xf mask in the header). |

### Register `iio_ilapr`

Local access protection register, named and placed by the public header. The header gives no fields, access type or reset. The IRIX register table confirms the access.

### Register `iio_ilapo`

Protection override register, named and placed by the public header. The header gives no unlock value or behaviour, so none is imported. The IRIX register table confirms the access.

### Register `iio_iowa`

The rsvd mask is the structure's rsvd and rsvd1 members; header naming only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `wxoac` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Outbound access bits for widgets 8 to 15, one bit each, as the structure's xtalk widget access bits. |
| 0 | `w0oac` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Outbound access bit for widget 0. |

### Register `iio_iiwa`

The rsvd mask is the structure's rsvd and rsvd1 members; header naming only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `wxiac` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Inbound access bits for widgets 8 to 15, one bit each. |
| 0 | `w0iac` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Inbound access bit for widget 0. |

### Register `iio_ilcsr`

The rsvd mask is the structure's rsvd, rsvd2, rsvd3 and rsvd4 members (the two bits at 7:6 are named rsvd1 and described as the data ready offset, so they are a field here); header naming only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41:32 | `max_burst` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Maximum burst, ten bits at 41:32. |
| 25:16 | `max_retry` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Maximum retry, ten bits at 25:16. |
| 13:12 | `lnk_stat` | established | iio_lnk_stat (working=2) | public Linux SN0 Hub I/O header: field layout and masks | Link status. The header names only the value 2 (LNK_STAT_WORKING). |
| 11 | `bm8` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Eight-bit mode. |
| 10 | `llp_en` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Link enable. |
| 8 | `wrm_reset` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Warm reset bit (ILCSR_WARM_RESET 0x100). |
| 7:6 | `data_ready_offset` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Data ready offset, two bits. The structure names the member reserved and gives the offset only in its comment. |
| 5:0 | `null_to` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Null timeout, six bits. |

### Register `iio_illr`

The rsvd mask is the structure's rsvd member (bits 63:32); header naming only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:16 | `cb_cnt` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Check-bit error count. |
| 15:0 | `sn_cnt` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Sequence-number error count. |

### Register `iio_iidsr`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 28 | `sent` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Interrupt sent (IIO_IIDSR_SENT). |
| 24 | `enable` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Interrupt enable (IIO_IIDSR_ENB). |
| 16:8 | `node` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Destination node, nine bits. The structure gives nine bits at 16:8; the mask macro IIO_IIDSR_NODE_MASK covers eight (15:8). |
| 6:0 | `level` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Interrupt level, seven bits. The structure gives seven bits at 6:0; the mask macro IIO_IIDSR_LVL_MASK covers six. |

### Register `iio_igfx_0`

The layout is the same as iio_igfx_1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `valid` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Valid. |
| 16 | `processor` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Processor number, one bit. |
| 12:4 | `node` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Node number, nine bits. |
| 3:0 | `widget` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Widget number, four bits. |

### Register `iio_igfx_1`

Graphics node and widget register 1, the twin of iio_igfx_0 in the census. The header gives both the same field layout: widget number in bits 3:0, node number in bits 12:4, processor number at bit 16 and a valid bit at bit 20. The header gives no access type, so rw is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `valid` | established |  |  | Valid: one bit at shift 20 in the header. |
| 16 | `processor` | established |  |  | Processor number: one bit at shift 16 in the header. |
| 12:4 | `node` | established |  |  | Node number: nine bits at shift 4 in the header. |
| 3:0 | `widget` | established |  |  | Widget number: four bits at shift 0 in the header. |

### Register `iio_scratch_reg0`

Scratch register 0. The header names its bit uses for software only and gives a mask of the bits that exist, 0x0000000f00f11fff. The IRIX register table confirms the access. Only the bits in the header's IIO_SCRATCH_MASK, 0x0000000f00f11fff, exist; the rsvd mask is its complement. Established as the header's statement that not all bits are available; whether the missing bits read zero is not stated.

### Register `iio_scratch_reg1`

Scratch register 1, the twin of register 0. The IRIX register table confirms the access. Only the bits in the header's IIO_SCRATCH_MASK, 0x0000000f00f11fff, exist; the rsvd mask is its complement. Established as the header's statement that not all bits are available; whether the missing bits read zero is not stated.

### Register `iio_itte`

Big-window translation entry n, for n from 0 to 6. Entry 0 is at the register offset and each later entry is eight bytes further on. The IRIX register table confirms the access.

Array of 7 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12 | `iospace` | established |  |  | I/O space bit, bit 12 (IIO_ITTE_IOSP). Set selects the widget's I/O space, clear its memory space. |
| 11:8 | `widget` | established |  |  | Target widget number, bits 11:8 (IIO_ITTE_WIDGET_MASK, shift 8). |
| 4:0 | `slice` | established |  |  | Slice field, bits 4:0 (IIO_ITTE_OFFSET_MASK in the public header). |

### Register `iio_imem`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `b1esd` | established |  | public Linux SN0 Hub I/O header: field layout and masks | BTE 1 shut down due to error (IIO_IMEM_B1ESD). |
| 4 | `b0esd` | established |  | public Linux SN0 Hub I/O header: field layout and masks | BTE 0 shut down due to error (IIO_IMEM_B0ESD). |
| 0 | `w0esd` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Widget 0 shut down due to error (IIO_IMEM_W0ESD). |

### Register `iio_ieclr`

The header calls each bit a clear bit; whether the register is write-1-to-clear is not stated, so no w1c mask is recorded.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 18 | `bte1` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Clear BTE 1 error. The header's comment is marked uncertain. |
| 17 | `bte0` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Clear BTE 0 error. The header's comment is marked uncertain. |
| 16 | `crazy` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Clear the crazy bit in iio_wstat. |
| 15 | `prb_f` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Clear the error bit in the PRB F register. |
| 14 | `prb_e` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Clear the error bit in the PRB E register. |
| 13 | `prb_d` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Clear the error bit in the PRB D register. |
| 12 | `prb_c` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Clear the error bit in the PRB C register. |
| 11 | `prb_b` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Clear the error bit in the PRB B register. |
| 10 | `prb_a` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Clear the error bit in the PRB A register. |
| 9 | `prb_9` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Clear the error bit in the PRB 9 register. |
| 8 | `prb_8` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Clear the error bit in the PRB 8 register. |
| 0 | `prb_0` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Clear the error bit in the PRB 0 register. |

### Register `iio_iibuserr`

Reads here cause a bus error, per the header's comment. The header gives no layout and no reset. The access letter is the comment's reading and is graded inferred.

### Register `iio_ipdr`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `pnd` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Pending (IIO_IPDR_PND). |

### Register `iio_icdr`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `pnd` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Pending (IIO_ICDR_PND). |

### Register `iio_ifdr`

The rsvd mask is the structure's rsvd and rsvd1 members; header naming only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 14:8 | `maxrp` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Maximum reply queue depth, seven bits. |
| 6:0 | `maxrq` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Maximum request queue depth, seven bits. |

### Register `iio_icmr`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52 | `precise` | established |  | public Linux SN0 Hub I/O header: field layout and masks | IIO_ICMR_PRECISE. |
| 50:36 | `pc_vld` | established |  | public Linux SN0 Hub I/O header: field layout and masks | IIO_ICMR_PC_VLD, fifteen bits. |
| 34:20 | `crb_vld` | established |  | public Linux SN0 Hub I/O header: field layout and masks | IIO_ICMR_CRB_VLD, fifteen bits, one per CRB entry. |
| 19:16 | `fc_cnt` | established |  | public Linux SN0 Hub I/O header: field layout and masks | IIO_ICMR_FC_CNT. |
| 13 | `clr_rppd` | established |  | public Linux SN0 Hub I/O header: field layout and masks | IIO_ICMR_CLR_RPPD. |
| 12 | `clr_rqpd` | established |  | public Linux SN0 Hub I/O header: field layout and masks | IIO_ICMR_CLR_RQPD. |
| 7:4 | `c_cnt` | established |  | public Linux SN0 Hub I/O header: field layout and masks | IIO_ICMR_C_CNT. |
| 3:0 | `p_cnt` | established |  | public Linux SN0 Hub I/O header: field layout and masks | IIO_ICMR_P_CNT. |

### Register `iio_iccr`

The header gives the commands as values already in place (0x100, 0x200, 0x400, 0x800) next to a command mask of 0xff at shift 7, which disagree; they are recorded here as single bits, graded inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 16 | `pending` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Command pending (IIO_ICCR_PENDING 0x10000). |
| 11 | `flush` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Command: flush (IIO_ICCR_CMD_FLUSH 0x800). |
| 10 | `eject` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Command: write the entry's contents to memory (IIO_ICCR_CMD_EJECT 0x400). |
| 9 | `timeout` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Command: make the CRB time out and mark it invalid (IIO_ICCR_CMD_TIMEOUT 0x200). |
| 8 | `wake` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Command: reactivate the CRB entry and process it (IIO_ICCR_CMD_WAKE 0x100). |

### Register `iio_ibls_0`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `busy` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Busy (IBLS_BUSY). |
| 16 | `error` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Error (IBLS_ERROR). |
| 15:0 | `length` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Length. |

### Register `iio_ibct_0`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `poison` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Poison (IBCT_POISON). |
| 4 | `notify` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Notify (IBCT_NOTIFY). |
| 0 | `zfil_mode` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Zero-fill mode (IBCT_ZFIL_MODE). |

### Register `iio_ibna_0`

Notification address of engine 0, the twin of the engine 1 slot in the census. Offset and name are from the public header. The IRIX register table confirms the access.

### Register `iio_ibia_0`

Interrupt address of engine 0. Offset and name are from the public header. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:16 | `level` | established |  |  | Interrupt level: mask 0x7f shifted to bits 22:16 in the public header. |
| 8:0 | `node` | established |  |  | Destination node number: mask 0x1ff in the public header. |

### Register `iio_ibls_1`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `busy` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Busy (IBLS_BUSY). |
| 16 | `error` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Error (IBLS_ERROR). |
| 15:0 | `length` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Length. |

### Register `iio_ibct_1`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `poison` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Poison (IBCT_POISON). |
| 4 | `notify` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Notify (IBCT_NOTIFY). |
| 0 | `zfil_mode` | established |  | public Linux SN0 Hub I/O header: field layout and masks | Zero-fill mode (IBCT_ZFIL_MODE). |

### Register `iio_ibia_1`

Interrupt address of engine 1. Offset and name are from the public header. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:16 | `level` | established |  |  | Interrupt level: mask 0x7f shifted to bits 22:16 in the public header. |
| 8:0 | `node` | established |  |  | Destination node number: mask 0x1ff in the public header. |

### Register `iio_ipcr`

Layout is the header's performance-select structure, io_perf_sel; which register that structure belongs to is inferred from the register names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `icct` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Selection for the CRB counter. |
| 7:4 | `ippr1` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Selection for counter group 1. |
| 3:0 | `ippr0` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Selection for counter group 0. |

### Register `iio_ippr`

Layout is the header's performance-count structure; its offset equals the header's IIO_PERF_CNT, 0x430008.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:0 | `count` | inferred |  | public Linux SN0 Hub I/O header: field layout and masks | Performance count, twenty bits. The header notes a hardware problem leaves one counter, not two. |

## Enums

### Enum `iio_lnk_stat`

| Label | Value | Grade | Source |
|---|---|---|---|
| `working` | 2 | established |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `HUB_NUM_WIDGET` | 0x9 | established |  | Widgets the Hub supports, from the header. |
| `HUB_WIDGET_ID_MAX` | 0xf | established |  | Highest widget number, from the header. |
| `HUB_WIDGET_ID_MIN` | 0x8 | established |  | Lowest widget number, from the header. |
| `IIO_BASE` | 0x400000 | established |  | Start of the I/O interface registers, from the header. |
| `IIO_BASE_BTE0` | 0x410000 | established |  | Start of the registers of block transfer engine 0. |
| `IIO_BASE_BTE1` | 0x420000 | established |  | Start of the registers of block transfer engine 1. |
| `IIO_BASE_PERF` | 0x430000 | established |  | Start of the performance registers. |
| `IIO_IBCT_NOTIFY` | 0x10 | established |  | Notify bit of the control/terminate register, named NOTIFY in the public header. The census has the same value as an inferred constant. |
| `IIO_IBCT_POISON` | 0x100 | established |  | Poison bit of the control/terminate register, named POISON in the public header. The Theory of Operations calls directory poisoning a proposed feature, so its effect on shipped hardware is unknown. |
| `IIO_IBCT_ZFIL_MODE` | 0x1 | established |  | Zero-fill mode bit of the control/terminate register, named ZFIL_MODE in the public header. The header gives no behaviour for it. |
| `IIO_IBLS_BUSY` | 0x100000 | established |  | Busy bit of the length/status register, named IBLS_BUSY in the public header. |
| `IIO_IECLR_BTE0` | 0x20000 | inferred |  | Clears engine 0's latched error, per the public header's name. The header's comment on the bit is marked uncertain, so the meaning is inferred. The IRIX header defines the same bit and marks its comment with question marks, so the meaning stays inferred. |
| `IIO_IECLR_BTE1` | 0x40000 | inferred |  | Clears engine 1's latched error, per the public header's name. The header's comment on the bit is marked uncertain, so the meaning is inferred. The IRIX header defines the same bit and marks its comment with question marks, so the meaning stays inferred. |
| `IIO_IIDSR_ENB` | 0x1000000 | established |  | Interrupt enable bit, bit 24 of the interrupt destination register, from the public header's mask. |
| `IIO_IIDSR_LVL_MASK` | 0x3f | established |  | Interrupt number field, bits 5:0 of the interrupt destination register, from the public header's mask. |
| `IIO_IIDSR_SENT` | 0x10000000 | established |  | Interrupt-sent bit, bit 28 of the interrupt destination register, from the public header's mask. |
| `IIO_ILCSR_BM8` | 0x800 | established |  | Eight-bit mode bit, bit 11 of the link control register, named bm8 in the public header's structure. |
| `IIO_ILCSR_LLP_EN` | 0x400 | established |  | Link enable bit, bit 10 of the link control register, named llp_en in the public header's structure. |
| `IIO_ILCSR_WARM_RESET` | 0x100 | established |  | Warm reset bit of the link control register, bit 8, named ILCSR_WARM_RESET in the public header. The census carries the same value as an inferred constant. The header gives no behaviour for it. |
| `IIO_ITTE_BASE` | 0x400160 | established |  | Offset of big-window translation entry 0, from the public header. Entry n sits at this value plus 8 times n. The census has entry 0 under an inferred name and entry 6 as a write-only register, which overlaps the header's entry 6. |
| `IIO_ITTE_INVALID_WIDGET` | 0x3 | established |  | Widget value the public header's disable routine writes to park a translation entry. |
| `IIO_ITTE_IOSP` | 0x1000 | established |  | I/O space bit of a translation entry, bit 12, from the public header. |
| `IIO_LLP_CSR_IS_UP` | 0x2000 | established |  | Link-up bit, bit 13 of the link control and status register, named IS_UP in the public header. The header names the bit only; what the other values of the status field mean is not imported. |
| `IIO_LLP_CSR_LLP_STAT_MASK` | 0x3000 | established |  | Two-bit link status field, bits 13:12, named LLP_STAT_MASK in the public header. |
| `IIO_NUM_CRBS` | 0xf | established |  | CRB entries. |
| `IIO_NUM_IPRBS` | 0x9 | established |  | Partial-request buffer entries. |
| `IIO_NUM_ITTES` | 0x7 | established |  | Big-window translation entries, numbered 0 to 6 in the header (the hardware manuals number them 1 to 7). |
| `IIO_NUM_NORMAL_CRBS` | 0xc | established |  | Regular CRB entries. |
| `IIO_NUM_PC_CRBS` | 0x4 | established |  | Partial-cache CRB entries. The header's counts, 12 and 4, add to 16, one more than IIO_NUM_CRBS. |
| `IIO_NUM_PRTES` | 0x8 | established |  | PIO read address table entries. |
| `IIO_PROTECT_OVRRD_KEY` | 0x53474972756c6573 | established |  | Key the protection override register accepts, from the header (an eight-byte ASCII string). |
| `IIO_SCRATCH_MASK` | 0xf00f11fff | established |  | Bits of each scratch register that exist, from the header. |
| `IIO_WCR_DIR_CON` | 0x20000 | established |  | Widget direct-connect bit, bit 17 of the widget control register, named in the public header's structure. |
| `IIO_WID_PART_HUB` | 0xc101 | established |  | Widget part number the public header's comment assigns to the Hub (hub=c101). |
| `IIO_WSTAT_ECRAZY` | 0x100000000 | established |  | Crazy bit of the widget status register, bit 32, named ECRAZY in the public header ('Hub gone crazy'). The header gives no behaviour for it. |
| `IIO_WSTAT_TXRETRY` | 0x200 | established |  | Transmit retry timeout bit of the widget status register, bit 9, from the public header's mask. |
| `IIO_WSTAT_TXRETRY_MASK` | 0x7f0000 | established |  | Transmit retry counter, bits 22:16: mask 0x7f at shift 16 in the public header. The same header's bit-field structure gives eight bits at 23:16, so the width is disputed inside the header and not settled here. |
| `LNK_STAT_WORKING` | 0x2 | established |  | Value of the link status field the public header names WORKING. The name is the driver's expectation. The header names no other value of the field. The IRIX header defines the name with this value. |
