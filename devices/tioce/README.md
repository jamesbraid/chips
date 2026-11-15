# TIOCE

Mode: **no-spec**. The TIOCE is a dual-port **PCI Express bridge** of the TIO generation: widget part number `0xce00`, source id 1, revision A = 1.
No specification is held. What the register header calls the CE ("CE Programmer's Reference Overview" is its source document) and the provider code
show the following. All facts are SGI's Linux Altix platform code (linux-5.3 pin 4d856f72c10e), so they are **established** as software definitions, never as
measurements. Registers: [registers.md](registers.md) (262 register entries, 20 of them with field layouts, and 32 named constants).

## What the code says it is

- **A PCIe root: two ports, each with a virtual PCI-to-PCI bridge (established).** The header defines a "CE Host Bridge" (vendor `0x10a9`, device `0x4001`) and a "CE Virtual
  PPB" (`0x10a9`, `0x4002`) and an array of two for every per-port resource (`TIOCE_NUM_PORTS`). The provider finds which port a device is on by reading
  the secondary bus number of the port-2 logical bridge at device 2 and comparing bus numbers. Each port has its own "LSI" link block (link
  layer, PHY receive and transmit, LTSSM, gearbox), its own downstream and upstream credit logic ("DTL" and "UTL"), and four INTx pins (A to D).
- **Blocks (established, register names).** `adm` administration (credits, interrupt status, mask, destination and force, error summary, timeouts, debug
  select), `lsi` link blocks at two bases, `crm` and `cxm` coretalk request and transmit modules, `dtl` and `utl`, `ure` the upstream request engine (credit,
  page map, direct maps, address translation entries, response and buffer flush registers), `dre` the downstream request engine, and several large
  diagnostic buffer windows (maintenance views of the upstream and downstream data and header buffers, 0x24000 and up).
- **It sits on a TIO widget (established).** The FPGA-port driver reads widget 3's identification word and treats part `0xce00` as a TIOCE to be left alone
  ([TIOCX](../tiocx/README.md)). The provider shares the PCI bridge error interrupt, vector `0x33`, with the PIC and TIOCP.

## DMA modes (established, provider)

Five flavours; the first two need no translation entry. Bus addresses are PCI Express addresses.

| mode | bus address window | mechanism |
|---|---|---|
| D64 | bit 63 set | bits 53:0 the coretalk address, bit 62 barrier, bit 61 message-signalled interrupt |
| D32 | `0x80000000` to `0xffffffff` | per-port direct map register holds the upper bits of the coretalk address with the low 30 bits cleared; low 30 bits from the bus address; a second user needs the same upper part |
| M32 | `0x0` to `0x7fffffff` | 32/40-bit translation entries 64 up (the first 64 are reserved for super pages), 256 KiB pages; interrupt-capable |
| M40 | `0x4000000000` to `0x7fffffffff` | 4096 entries of 64 MiB; not interrupt-capable |
| M40S | `0x8000000000` to `0xffffffffff` | 32 entries per port of 16 GiB (super pages); not interrupt-capable |

Entry format (both entry tables): bit 63 valid, bit 62 message-signalled interrupt, address in the high bits, page-aligned. The page size of the 32/40-bit pool is a field of the
upstream page map register; the provider sets 256 KiB, the largest it uses. A bug-compatible detail to question: the M40S window as written cannot hold the entries of
port 2 ([question](../../questions/altix-io-sn2-cross-check.md#tioce-m40s-window)).

## Register access workaround (established, provider; revision A only)

Erratum PV944642: on revision A, the kernel brackets every access to a register below `0x45000` with dummy reads. Before the access it reads one register chosen by the offset
(offset `0x0` or `0x80`: register `0xc0`; `0x148` or `0x200`: `0x28`; anything else: `0x158`). After it, when the offset is `0x100` it reads `0x38`, and for every offset
below the limit it reads `0xb050`. The header says "reads instead of writes" is acceptable per the hardware group. Software that follows the workaround must find those registers readable.

## Interrupts (established)

Fifteen destination registers `adm_int_dest` indexed by source bit. Sources: bit 0 CE error, 1 and 2 link IP errors, 3 PCIe error, 4 and 5 hot-plug per port, 6 to 9 port 1
INTA to INTD, 10 to 13 port 2 INTA to INTD, 14 to 17 message slots, 22 and 23 power-management events. To retarget a line interrupt the provider sets the mask bit, writes
the destination (vector in bits 63:56, destination coretalk address below), clears the mask bit, then forces the interrupt through `adm_force_int` (bits 0 to 7 are INTA to INTD of each port, 8 forces
always). Revision A hardware cannot do that (erratum PV945826): the provider reads the interrupt status and, if the source is set, writes the interrupt data (`1 << 8` plus the kernel vector)
straight to the destination address with an ordinary store.

## Field layouts (established unless noted)

Bit layouts the header defines are fields of their registers, each graded. Registers with fields: interrupt status and mask (one bit per source, listed above), error summary and mask (62 sources, bits 0 to 61), force interrupt, upstream engine control (write-merge enables and timer, parity and malform disables), page map (enables and a 3-bit page-size code, 0 = 4 KiB through 4 = 256 KiB), the two pipe select and mask registers (three 19-bit selectors at bits 0, 20 and 40, each a traffic class, bus, device and function match), the two PCIe control registers (names follow the slot-capability abbreviations of the public PCIe specification, **inferred**), downstream engine configuration and request status, and the first gearbox configuration register. The status alias, error alias, second pipe registers' sub-selectors and the barrier-flush selectors (4-bit spacing only) are **inferred**. Interrupt destination: the vector at bit 56 and up is inferred; the width of the address part is **unknown**. Whether a set error-mask bit enables or masks a source is **unknown**. The header gives bit layouts for no other register.

The remaining header defines are constants: identifiers, the address windows and the enhanced-configuration bus, device and function masks (bits 27:20, 19:15 and 14:12). The memory window length is defined as a symbol from another header (TIO widget window size, not in the files read) and is **unknown** here.

## Not covered

PCIe configuration space (the header lists a PCI compatible window from `0x04000000` and an enhanced window from `0x10000000`, constants `PIO_*`), the link-training states and every debug register: the
header names them; nothing is read. Reset values and access directions are **unknown**. Which Altix model carries a TIOCE: [question](../../questions/altix-io-sn2-cross-check.md#pic-versus-tio-by-product).

## Review

Independent review on 2026-11-14 by a reviewer who did not write these pages. Revisions: chips commits 4924130..b536f7d, read at main 15a5a4e484. Grading rule: the SN2 paragraph of the evidence order in `retools/tools/README-analysis.md` (SGI's Linux platform code ranks first for this generation, and a fact it defines is `established` as a software definition). Sources: the Linux v5.3 files the page cites, fetched singly from the tagged tree (`drivers/misc/ioc4.c` and `include/linux/ioc4.h` at v4.19, where they still exist).

**Reviewed commits.** b93619a (tioce).

**Checked.** All 262 register entries against the nested `struct tioce` by script: offset, array count and (for the `ce_lsi` and `ce_dtl_utl` blocks) the 0x1000 stride, with the nested buffer windows (`ups_dat1` through `bap_buf`, `ds_head_q` to `us_rsp_q`) checked for offset and element count by hand (512, 64, 258, 32, 256 and 8 entries, as declared). 190 constants against their header values: no mismatch. Prose: the five DMA modes and their bus windows (`TIOCE_D64_MIN` to `TIOCE_M40S_MAX`), per-port ATE pools (first 64 of the 32/40-bit pool reserved, 32 super-page entries per port), entry format (bits 63 and 62), the D32 direct map and its refcount, the revision A register-access workaround offsets (0x45000 limit; 0xc0, 0x28, 0x158; 0x38 after 0x100; 0xb050 after all), the interrupt retarget sequence and the PV945826 force path, the page-map write (256 KiB, encoding 4), the secondary-bus port test, vector 0x33 and the M40S port-2 overflow question (32 entries times 16 GiB per port against a 512 GiB window).

**Findings.**
- Fixed (mechanical): three constants (`E_CONFIG_BUS_SHFT`, `E_CONFIG_DEVICE_SHFT`, `E_CONFIG_FUNC_SHFT`) named the wrong header section ("PCI MEM Space"); they sit under the enhanced-config shifts and masks comment. Fixed. The three array-extent constants claimed a header comment that is not there; reworded.
- Fixed (mechanical): `dre_comp_err_addr` said the provider writes zero at attach; the code ORs zero in (read, then write back unchanged). Also says the alias registers are set, not that errors were cleared first. Generated files regenerated.
- Judgement, left: 37 header defines (besides the include guard) are not in the constants table: the eight `FLUSH_SEL_*_SHFT` shifts, the `_MASK` and page-size macros that are written in terms of another macro (`CE_URE_*_MASK`, `CE_URE_*_PAGESIZE`), `CE_PIO_MEM_SPACE_LEN` (defined as `TIO_HWIN_SIZE`, a symbol not in the files read) and the three `CE_E_CONFIG_*_MASK`. The register file's `doc` says the header's bit masks are listed as constants, which reads as complete; it is not. A model that wants the field widths of those registers will find only the shifts.
- Judgement, left: bit masks are constants tagged with the header's section comment, not fields of their register, so the register-to-field link is by label only. The page says so. Register `access = "rw"` is a stated placeholder.
- No copied comments beyond short section labels quoted as "Header comment: ..." in constant docs; those are two to six words of header text. Acceptable, but a later pass could drop the quoting.

**Cleared scope.** Register names, offsets, counts and strides; the 190 constants; the DMA, workaround and interrupt descriptions. Not cleared: the omitted macros above, reset values, access direction, and the PCIe configuration windows' behaviour (the page marks them not covered).

### Review of the field layouts, 2026-11-15

Independent review by a reviewer who did not write the field work. Revision: chips commit 7d9a943 on main. Sources: `arch/ia64/include/asm/sn/tioce.h` and `arch/ia64/sn/pci/tioce_provider.c` at Linux v5.3, fetched singly. No binaries read, so no Ghidra readings.

**Checked.** By script against the header: the 62 error-source bits (names and positions) on the summary, mask and alias registers; the 20 interrupt-source positions on status, alias and mask (bit 14 doubling as message and slot 0); the nine force-interrupt bits; the eight barrier-flush shifts; the nine gearbox configuration fields; the 16 upstream control bits and the 11-bit write-merge timer at bit 12; page map enables and the 3-bit page-size code with encodings 0 to 4; the three 19-bit pipe selectors and masks at bits 0, 20 and 40 with the 18:16, 15:8, 7:3, 2:0 sub-layout; the 6 and 11 fields of the two PCIe control registers; the downstream configuration and request-status bits. Every one of the 161 constants dropped by the commit maps to a field: each mask has a field of the same bit range and each shift is a field's low bit; no field overlaps another or exceeds bit 63. The three kept enhanced-configuration masks match the header (0xff00000, 0xf8000, 0x7000). Provider facts: attach writes ones to the status and error summary aliases and zero to the completion error address; retarget ORs the vector at shift 56 over the crosstalk address; the page-size field is cleared and set to 256 KiB (4).

**Mechanical fixes.** The page header counted 190 constants; 32 remain. Reworded to the current counts.

**Findings not fixed.**
- The task description counted 37 header defines absent from the map. The commit does not add them as constants: bit masks became fields, the `_SET(n)`, `PIPE_BUS` style helper macros and the `CE_URE_*_PAGESIZE` values (now the enum) are not carried, and `CE_PIO_MEM_SPACE_LEN` (a symbol from another header) is still absent. This is sound for a register map, but the 37 are not literally added.
- `ure_pipe_mask1` and `ure_pipe_mask2` fields `mask1` to `mask3` are graded inferred although the header defines `CE_URE_MASK1_MASK` to `MASK3_MASK` at those exact positions. The bit ranges are established; only the role (applies to the selector of the same index) is inferred. The grade is conservative, not wrong. Likewise `sel2` and `sel3` sub-fields: the header gives only the three whole 19-bit selector masks, and the tc, bus, device and function split at 16/8/3/0 exists only for the first selector, so inferred is right.
- The expansion of ELAL and ELAL1 ("exit latency") is a guess from the names; the PCIe link capability has separate L0s and L1 exit latencies, which would fit ELAL and ELAL1, but nothing in the header says so. It stays inferred and unconfirmed.
- `ure_control` bits 12 to 22 are an 11-bit timer by header mask; the unit of the timer is unknown.

**Cleared scope.** The field positions, widths and grades above; the page-size enum values; the counts. Not cleared: field semantics beyond names, reset values, access direction.
