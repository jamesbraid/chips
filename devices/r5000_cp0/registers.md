<!-- generated from devices/r5000_cp0/registers.toml by defs-gen - do not edit, change the source -->

# MIPS R5000 CP0 Config, Status, PageMask and LLAddr field positions, and FCR31 flags

Constants for the R5000 processor's CP0 registers and FCR31 as the NEC VR5000 user's manual lays them out: the Config field positions, the Status fields and the bits a warm entry sets, the PageMask field and its legal page sizes, the LLAddr diagnostic layout, and the FCR31 field positions. This unit holds constants only; the reset, write and exception rules are in docs/r5000.md. Grades: established means the cited manual states it; unknown items are listed in the page.

Unit `r5000_cp0`, macro prefix `R5KCP0`.
Default source: NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `R5KCFG_BE_MASK` | 0x8000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Config bit 15, BE. It selects memory endianness at reset. |
| `R5KCFG_CACHE_32K_CODE` | 0x3 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Code 3 in the IC and DC fields, each a 32 KiB primary cache. |
| `R5KCFG_DB_MASK` | 0x10 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Config bit 4, DB. A value of one means a 32-byte primary data line. |
| `R5KCFG_DC_MASK` | 0x1c0 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the DC field, bits 8:6 of Config. |
| `R5KCFG_DC_SHIFT` | 0x6 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the three-bit DC field, bits 8:6, the primary data cache size code. |
| `R5KCFG_EB_MASK` | 0x2000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Config bit 13, EB. For this part the manual requires the value one, which selects sub-block ordering. |
| `R5KCFG_EC_DIVISOR_BASE` | 0x2 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | EC codes 0 to 6 give a divisor of the code plus two, so 2 to 8. Code 7 is reserved. The original overview gives 2, 3 and 4 as the multipliers it describes, so the later ratios are not confirmed by the overview. |
| `R5KCFG_EC_MASK` | 0x70000000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the EC field, bits 30:28 of Config. |
| `R5KCFG_EC_SHIFT` | 0x1c | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the three-bit EC field, bits 30:28, the processor-to-system clock divisor. |
| `R5KCFG_EM_MASK` | 0x4000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Config bit 14, EM. For this part the manual requires the value one, which selects parity mode. |
| `R5KCFG_EP_MASK` | 0xf000000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the EP field, bits 27:24 of Config. |
| `R5KCFG_EP_SHIFT` | 0x18 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the four-bit EP field, bits 27:24. It selects the writeback data timing pattern, codes 0 to 8. It is not a CPU frequency field. |
| `R5KCFG_EW_MASK` | 0xc0000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the EW field, bits 19:18 of Config. |
| `R5KCFG_EW_SHIFT` | 0x12 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the two-bit EW field, bits 19:18, the system bus width. Code 0 is the 64-bit SysAD bus. |
| `R5KCFG_FIXED_ONE_MASK` | 0x10000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Config bit 16. The manual's format marks this bit one. |
| `R5KCFG_IB_MASK` | 0x20 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Config bit 5, IB. A value of one means a 32-byte primary instruction line. |
| `R5KCFG_IC_MASK` | 0xe00 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the IC field, bits 11:9 of Config. |
| `R5KCFG_IC_SHIFT` | 0x9 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the three-bit IC field, bits 11:9, the primary instruction cache size code. |
| `R5KCFG_K0_MASK` | 0x7 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the K0 field, bits 2:0 of Config. |
| `R5KCFG_K0_SHIFT` | 0x0 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the three-bit K0 field, bits 2:0, the kseg0 cache algorithm. Software controlled. Its reset value is not defined by the manual. |
| `R5KCFG_SB_MASK` | 0xc00000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the SB field, bits 23:22 of Config. |
| `R5KCFG_SB_SHIFT` | 0x16 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the two-bit SB field, bits 23:22, the secondary block size. Code 1 is eight words, 32 bytes. Other codes are reserved. |
| `R5KCFG_SC_BIT` | 0x11 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Config bit 17, SC. Zero means a secondary cache is present. One means it is absent. |
| `R5KCFG_SC_MASK` | 0x20000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for Config bit 17, SC. |
| `R5KCFG_SE_MASK` | 0x1000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Config bit 12, SE, the software secondary-cache enable. Its reset value is not defined by the manual. |
| `R5KCFG_SS_MASK` | 0x300000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the SS field, bits 21:20 of Config. |
| `R5KCFG_SS_SHIFT` | 0x14 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the two-bit SS field, bits 21:20, the secondary cache size. Codes 0, 1 and 2 are 512 KiB, 1 MiB and 2 MiB. Code 3 is unresolved, see docs/r5000.md. |
| `R5KFCR_CAUSE_MASK` | 0x3f000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the Cause field, bits 17:12 of FCR31. |
| `R5KFCR_CAUSE_SHIFT` | 0xc | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the six-bit Cause field, bits 17:12. |
| `R5KFCR_CC0_MASK` | 0x800000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | FCR31 bit 23, condition bit CC0. |
| `R5KFCR_CC_HI_MASK` | 0xfe000000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for condition bits CC7 to CC1, bits 31:25 of FCR31. |
| `R5KFCR_CC_HI_SHIFT` | 0x19 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the seven condition bits CC7 to CC1, bits 31:25. |
| `R5KFCR_ENABLE_MASK` | 0xf80 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the Enables field, bits 11:7 of FCR31. |
| `R5KFCR_ENABLE_SHIFT` | 0x7 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the five-bit Enables field, bits 11:7. |
| `R5KFCR_FLAG_MASK` | 0x7c | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the Flags field, bits 6:2 of FCR31. |
| `R5KFCR_FLAG_SHIFT` | 0x2 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the five-bit Flags field, bits 6:2. |
| `R5KFCR_FS_MASK` | 0x1000000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | FCR31 bit 24, FS. |
| `R5KFCR_RM_MASK` | 0x3 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Rounding mode field, bits 1:0 of FCR31. |
| `R5KFCR_RSVD_MASK` | 0x7c0000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | FCR31 bits 22:18, reserved by the manual. |
| `R5KLL_MASK` | 0xffffffff | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | LLAddr is a 32-bit read/write diagnostic register. The mask covers the whole word. |
| `R5KLL_SHIFT` | 0x4 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | LLAddr holds physical address bits 35:4 of the most recent LL read, so the field is shifted right by four. |
| `R5KPM_FIELD_MASK` | 0x1ffe000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the PageMask field, bits 24:13. |
| `R5KPM_FIELD_SHIFT` | 0xd | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the PageMask field, bits 24:13. |
| `R5KPM_PAGE_16K` | 0x6000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | PageMask field value for a 16 KiB page. |
| `R5KPM_PAGE_16M` | 0x1ffe000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | PageMask field value for a 16 MiB page. The page sizes step by four, from 4 KiB to 16 MiB. |
| `R5KPM_PAGE_1M` | 0x1fe000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | PageMask field value for a 1 MiB page. |
| `R5KPM_PAGE_256K` | 0x7e000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | PageMask field value for a 256 KiB page. |
| `R5KPM_PAGE_4K` | 0x0 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | PageMask field value for a 4 KiB page. |
| `R5KPM_PAGE_4M` | 0x7fe000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | PageMask field value for a 4 MiB page. |
| `R5KPM_PAGE_64K` | 0x1e000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | PageMask field value for a 64 KiB page. |
| `R5KST_BEV_MASK` | 0x400000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 22, BEV, boot exception vectors. |
| `R5KST_CE_MASK` | 0x20000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 17, CE. |
| `R5KST_CU_MASK` | 0x70000000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bits 30:28, CU2 to CU0, the coprocessor usable bits. |
| `R5KST_DE_MASK` | 0x10000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 16, DE. |
| `R5KST_ERL_MASK` | 0x4 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 2, ERL. |
| `R5KST_EXL_MASK` | 0x2 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 1, EXL. |
| `R5KST_FR_MASK` | 0x4000000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 26, FR, which selects the FPR register view. |
| `R5KST_IE_MASK` | 0x1 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 0, IE. |
| `R5KST_IMPLEMENTED_MASK` | 0xf653ffff | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Union of the implemented Status fields in the manual's tables. The positions outside it are reserved: 27, 24:23, 21 and 19:18. |
| `R5KST_IM_MASK` | 0xff00 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the IM field, bits 15:8 of Status. |
| `R5KST_IM_SHIFT` | 0x8 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the eight-bit IM field, bits 15:8. IM1 and IM0 are the software interrupts. IM7 to IM2 are the six external inputs. |
| `R5KST_KSU_MASK` | 0x18 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the KSU field, bits 4:3 of Status. |
| `R5KST_KSU_SHIFT` | 0x3 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Lowest bit of the two-bit KSU field, bits 4:3. |
| `R5KST_KX_MASK` | 0x80 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 7, KX. |
| `R5KST_RE_MASK` | 0x2000000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 25, RE, user reverse endian. |
| `R5KST_SR_MASK` | 0x100000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 20, SR, soft reset. |
| `R5KST_SX_MASK` | 0x40 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 6, SX. |
| `R5KST_UX_MASK` | 0x20 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 5, UX. |
| `R5KST_XX_MASK` | 0x80000000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bit 31, XX. It is the user-mode MIPS IV enable. |
