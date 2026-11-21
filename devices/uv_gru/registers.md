<!-- generated from devices/uv_gru/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 9fd998eb93a63f0428f5eca34e50f2c7058b2d23a787c4039f35569109e1a020 -->

# UV global reference unit (GRU): chiplet memory map, handles and instruction word

The GRU is reached through memory-mapped handles, not a flat register file. Constants are the driver's layout numbers. Words are the handle and control-block dwords; positions come from the driver's bitfield structs read least-significant first within each 64-bit dword, which the driver's own comments and shift macros confirm for the control-block word and are otherwise inferred from the declared field order and widths under the x86-64 and ia64 ABIs. Role text paraphrases the driver and is inferred.

Unit `uv_gru`, macro prefix `UV_GRU`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `CBE_DW7` | 64 | inferred |  |
| `CB_DW0` | 64 | established |  |
| `CCH_DW0` | 64 | inferred |  |
| `TFH_DW0` | 64 | inferred |  |
| `TFH_DW2` | 64 | inferred |  |
| `TFH_DW3` | 64 | inferred |  |
| `TGH_DW0` | 64 | inferred |  |
| `TGH_DW2` | 64 | inferred |  |
| `TGH_DW3` | 64 | inferred |  |

### Word `CBE_DW7`

Control block extended handle, dword 7: the hardware's view of the active control block.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `cbrexecstatus` | inferred |  |  | Bits: 0 abort occurred, 1 interrupt occurred, 2 pending, 3 queued, 4 TLB invalidate, 5 exception, 6 CB interrupt pending. |
| 55:52 | `cbrstate` | inferred |  |  | 0 inactive, 1 idle, 2 PE check, 3 queued, 4 wait response, 5 interrupted, 6 to 9 interrupted or busy on a TLB miss, 10 request issue, 11 busy interrupt. |
| 51:32 | `ecause` | inferred |  |  | Bit mask of exception causes: bit 0 named RI in the driver (meaning not stated), 1 invalid instruction, 2 unmapped mode forbidden, 3 PE check data error, 4 IAA/GAA mismatch, 5 data segment limit, 6 OS-fatal TLB fault, 7 execution hardware error, 8 TLB hardware error, 9 and 10 request timeouts, 11 to 14 response errors, 15 address decode error, 16 to 18 data errors, 19 forced error. |

### Word `CB_DW0`

First dword of a control block (the instruction word). Software fills dwords 1 to 7 first, then stores this one with the start bit set and flushes the line; the hardware overwrites status and substatus on completion. Positions agree with the driver's own shift macros for the low fields; the high fields follow the bitfield order.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `tlb_fault_color` | inferred |  |  | Toggles to distinguish successive TLB faults of one control block. |
| 61:58 | `isubstatus` | inferred |  |  | Substatus: low 3 bits are the message queue result (0 none, 1 overflow, 2 queue limit, 3 page overflow, 4 AMO nacked, 5 put nacked), bit 3 implicit abort active. |
| 57:56 | `istatus` | established |  |  | Status written by the hardware, see CBS constants. |
| 53:32 | `tri0` | inferred |  |  | Data segment byte offset operand (idef2). The driver's mask for the field is 18 bits while the struct declares 22; the struct width is used and the difference is open. |
| 31:24 | `exopc` | established |  |  | Extended opcode: the atomic operation for the GAM opcodes. |
| 23:16 | `opc` | established |  |  | Opcode, see the OP constants. |
| 14:13 | `iaa1` | established |  |  | Access attribute of the second address. |
| 12:11 | `iaa0` | established |  |  | Access attribute of the first address. |
| 10:8 | `xtype` | established |  |  | Element type, see the XTYPE constants. |
| 3:1 | `ima` | established |  |  | Instruction mode: bit 0 delay read responses until status changes, bit 1 unmapped (bypass TLB, OS only), bit 2 interrupt on completion. |
| 0 | `icmd` | established |  |  | Start: set when the instruction is issued. |

### Word `CCH_DW0`

Context configuration handle, dword 0: allocates control blocks and data segment to a context and routes its interrupts. Dword 1 is the control block allocation map, dwords 2 to 5 the eight address space ids, dwords 6 and 7 the eight page size availability masks.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `dsr_allocation_map` | inferred |  |  |  |
| 28 | `tfm_done_bit_enable` | inferred |  |  |  |
| 27:24 | `cause` | inferred |  |  | 1 to 12: region register write error, illegal opcode, invalid start, invalid allocation, invalid deallocation, invalid interrupt, handle busy, no CBRs to allocate, bad TFM config, CBR oversubscribed, DSR oversubscribed, CBR deallocation error. |
| 19:18 | `state` | inferred |  |  | 0 inactive, 1 mapped, 2 active, 3 interrupted. |
| 17:16 | `status` | inferred |  |  |  |
| 15:12 | `tlb_int_select` | inferred |  |  | Which of the 16 TLB interrupt configuration registers the context's faults use. |
| 11 | `tfm_fault_bit_enable` | inferred |  |  |  |
| 10 | `tlb_int_enable` | inferred |  |  |  |
| 9 | `cb_int_enable` | inferred |  |  |  |
| 8:7 | `req_slice` | inferred |  |  |  |
| 6 | `req_slice_set_enable` | inferred |  |  |  |
| 5 | `unmap_enable` | inferred |  |  |  |
| 4:2 | `opc` | inferred |  |  | CCHOP opcode. |
| 1 | `delresp` | inferred |  |  |  |
| 0 | `cmd` | inferred |  |  |  |

### Word `TFH_DW0`

TLB fault handle, dword 0. The OS reads the cause here after a TLB miss and issues an opcode to fill the TLB.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 51:48 | `ctxnum` | inferred |  |  |  |
| 43:32 | `indexway` | inferred |  |  | TLB index and way to replace. |
| 30 | `cb_int` | inferred |  |  |  |
| 29:24 | `cause` | inferred |  |  | 0 none, 1 TLB miss, 2 TLB modify, 3 to 6 hardware errors, 7 instruction exception, 8 uncorrectable error. |
| 22:20 | `state` | inferred |  |  | 0 inactive, 1 idle, 2 miss user polling, 3 miss FMM, 4 hardware error, 5 write TLB, 6 restart CBR. |
| 17:16 | `status` | inferred |  |  | 0 idle, 1 exception, 2 active. |
| 6:4 | `opc` | inferred |  |  | TFHOP opcode. |
| 1 | `delresp` | inferred |  |  |  |
| 0 | `cmd` | inferred |  |  |  |

### Word `TFH_DW2`

TLB fault handle, dword 2: the missing address space id on read, the fill address space id and attributes on write.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 58:57 | `gaa` | inferred |  |  | See the GAA constants. |
| 56 | `dirty` | inferred |  |  |  |
| 55:32 | `fillasid` | inferred |  |  |  |
| 23:0 | `missasid` | inferred |  |  |  |

### Word `TFH_DW3`

TLB fault handle, dword 3: page frame and page size of the entry to write. Dword 1 holds the missing virtual address, dword 4 the virtual address to fill.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52:48 | `pagesize` | inferred |  |  | Encoded size: 4k=0, 16k=1, 64k=2, 256k=3, 1m=4, 2m=5, 4m=6, 16m=7, 64m=8 (the driver's conversion macro). |
| 40:0 | `pfn` | inferred |  |  | Physical address shifted right by 12, whatever the page size. |

### Word `TGH_DW0`

TLB global handle, dword 0: used to flush GRU TLB entries after the kernel changes a mapping. Dword 1 is the virtual address, dword 4 the context bitmap.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 26:24 | `cause` | inferred |  |  |  |
| 22:20 | `state` | inferred |  |  |  |
| 17:16 | `status` | inferred |  |  |  |
| 2 | `opc` | inferred |  |  | 0 no-op, 1 invalidate. |
| 1 | `delresp` | inferred |  |  |  |
| 0 | `cmd` | inferred |  |  |  |

### Word `TGH_DW2`

TLB global handle, dword 2.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 48 | `global` | inferred |  |  |  |
| 36:32 | `pagesize` | inferred |  |  |  |
| 23:0 | `asid` | inferred |  |  |  |

### Word `TGH_DW3`

TLB global handle, dword 3: address mask and the count of pages to purge.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 57:48 | `n` | inferred |  |  |  |
| 38:0 | `vaddrmask` | inferred |  |  |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `CACHE_LINE` | 0x40 | established |  | GRU cache line, and the unit of data segment indexing. |
| `CBE_BASE` | 0x4010000 | established |  | Offset of the control block extended handles. |
| `CBR_AU_SIZE` | 0x2 | established |  | Control blocks per allocation unit. |
| `CBS_ACTIVE` | 0x2 | established |  | Control block status: executing. |
| `CBS_CALL_OS` | 0x3 | established |  | Control block status: needs operating system help (a TLB miss). |
| `CBS_EXCEPTION` | 0x1 | established |  | Control block status: terminated with an exception. |
| `CBS_IDLE` | 0x0 | established |  | Control block status: idle. |
| `CB_BASE` | 0x0 | established |  | Control blocks start at the segment base, one per handle stride. |
| `CCHOP_ALLOCATE` | 0x2 | established |  | CCH opcode: allocate control blocks and data segment. |
| `CCHOP_DEALLOCATE` | 0x4 | established |  | CCH opcode: release the resources. |
| `CCHOP_INTERRUPT` | 0x3 | established |  | CCH opcode: interrupt the context. |
| `CCHOP_INTERRUPT_SYNC` | 0x5 | established |  | CCH opcode: interrupt and wait. |
| `CCHOP_START` | 0x1 | established |  | CCH opcode: start the context. |
| `CCH_BASE` | 0x4020000 | established |  | Offset of the context configuration handles. |
| `CHIPLETS_PER_HUB` | 0x2 | established |  | Chiplets per hub; chiplet address is base plus chiplet size times (2 times pnode plus chiplet). |
| `CHIPLET_SIZE` | 0x8000000 | established |  | Bytes of address space per GRU chiplet (128 MiB). |
| `DSR_AU_BYTES` | 0x400 | established |  | Allocation unit of data segment space. |
| `DS_BASE` | 0x20000 | established |  | Data segment offset within a user segment. |
| `GAA_MMIO` | 0x1 | established |  | TLB entry global address attribute: MMIO. |
| `GAA_NCRAM` | 0x2 | established |  | TLB entry global address attribute: noncoherent RAM. |
| `GAA_RAM` | 0x0 | established |  | TLB entry global address attribute: RAM. |
| `GAA_REGISTER` | 0x3 | established |  | TLB entry global address attribute: registers. |
| `GRU_PADDR_SHIFT` | 0xc | established |  | Shift for the page frame field of a TLB dropin; not the actual page size. |
| `GSEG_PAGESIZE` | 0x40000 | established |  | Size of the user mapping of one segment: control blocks then data segment. |
| `GSEG_STRIDE` | 0x400000 | established |  | Distance between the user segments (one per context) from the chiplet base. |
| `HANDLE_BYTES` | 0x40 | established |  | Meaningful bytes per handle. |
| `HANDLE_STRIDE` | 0x100 | established |  | Distance between consecutive handles of one kind; each handle uses the first 64 bytes. |
| `IAA_MMIO` | 0x1 | established |  | Access attribute: noncoherent memory-mapped I/O. |
| `IAA_NCRAM` | 0x2 | established |  | Access attribute: noncoherent RAM. |
| `IAA_RAM` | 0x0 | established |  | Access attribute: coherent RAM. |
| `IAA_REGISTER` | 0x3 | established |  | Access attribute: memory-mapped registers. |
| `MCS_BASE` | 0x4000000 | established |  | Offset of the handle area (the memory control section) inside a chiplet. |
| `NUM_CB` | 0x80 | established |  | Control blocks per chiplet (and CBE and TFH handles). |
| `NUM_CCH` | 0x10 | established |  | Contexts per chiplet (one context configuration handle each). |
| `NUM_DSR_BYTES` | 0x8000 | established |  | Data segment bytes per chiplet. |
| `NUM_TFM` | 0x10 | established |  | TLB fault maps per chiplet. |
| `NUM_TGH` | 0x18 | established |  | TLB global handles per chiplet. |
| `OP_BCOPY` | 0x1 | established |  | Block copy. |
| `OP_BSTORE` | 0xe | established |  | Block store. |
| `OP_GAMER` | 0xc | established |  | Atomic operation with explicit operands. |
| `OP_GAMERR` | 0xd | established |  | Registered atomic operation with explicit operands. |
| `OP_GAMIR` | 0xa | established |  | Atomic operation with implicit operands. |
| `OP_GAMIRR` | 0xb | established |  | Registered atomic operation with implicit operands. |
| `OP_GAMXR` | 0x9 | established |  | Masked compare exchange (arithmetic unit). |
| `OP_IVLOAD` | 0x3 | established |  | Indirect vector load. |
| `OP_IVSET` | 0x7 | established |  | Indirect vector set. |
| `OP_IVSTORE` | 0x5 | established |  | Indirect vector store. |
| `OP_MESQ` | 0x8 | established |  | Message queue operation. |
| `OP_NOP` | 0x0 | established |  | Instruction opcode. |
| `OP_VFLUSH` | 0xf | established |  | Vector flush. |
| `OP_VLOAD` | 0x2 | established |  | Vector load. |
| `OP_VSET` | 0x6 | established |  | Vector set. |
| `OP_VSTORE` | 0x4 | established |  | Vector store. |
| `SUPPORTED_BELOW_HUB_REVISION` | 0x5 | established |  | The Linux driver runs the GRU only on hubs with software revision below 5 (UV1 and UV2); UV3 and later never use this driver. |
| `TFHOP_EXCEPTION` | 0x4 | established |  | TFH opcode: fail the control block with an exception. |
| `TFHOP_NOOP` | 0x0 | established |  | TFH opcode. |
| `TFHOP_RESTART` | 0x1 | established |  | TFH opcode: restart the control block. |
| `TFHOP_USER_POLLING_MODE` | 0x7 | established |  | TFH opcode: user polling mode. |
| `TFHOP_WRITE_ONLY` | 0x2 | established |  | TFH opcode: write the TLB entry, do not restart. |
| `TFHOP_WRITE_RESTART` | 0x3 | established |  | TFH opcode: write the TLB entry and restart. |
| `TFH_BASE` | 0x4018000 | established |  | Offset of the TLB fault handles. |
| `TFM_BASE` | 0x4000000 | established |  | Offset of the TLB fault maps. |
| `TGHOP_TLBINV` | 0x1 | established |  | TGH opcode: invalidate TLB entries. |
| `TGH_BASE` | 0x4008000 | established |  | Offset of the TLB global handles. |
| `XTYPE_B` | 0x0 | established |  | Transfer element: byte. |
| `XTYPE_CL` | 0x6 | established |  | Transfer element: one 64-byte cache line. |
| `XTYPE_DW` | 0x3 | established |  | Transfer element: 8 bytes. |
| `XTYPE_S` | 0x1 | established |  | Transfer element: 2 bytes. |
| `XTYPE_W` | 0x2 | established |  | Transfer element: 4 bytes. |
