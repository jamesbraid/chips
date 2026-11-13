# R10000 family Diagnostic register (CP0 register 22)

This page covers the CP0 register 22 of the MIPS R10000 family, the branch diagnostic register: its field positions as the R10000 and R12000 manuals give them, the R12000 changes, what the Linux driver does with it, and what is unknown for the R14000 and R16000. The constants are in [devices/r10000_diagnostic/registers.toml](registers.toml), generated to [devices/r10000_diagnostic/registers.md](registers.md). Nothing here was read from silicon or from a running machine.

The family covers the R10000, R12000, R14000 and R16000. The identity word that tells the R14000 from the R16000 is in [devices/r10000_identity/README.md](../r10000_identity/README.md).

## Sources and grades

- NEC, *VR10000 Series 64-/32-bit Microprocessor User's Manual*, fourth edition, March 2001, U10278EJ4V0UM00. The register is described on printed pages 235 to 237. Cited below as "the NEC manual". Established means that manual states the fact for the part it names.
- Linux `arch/mips/include/asm/mipsregs.h` and `arch/mips/kernel/cpu-probe.c` at commit `db2ddb87143519e20a95aa36c60b36107b736a58`, read in full for the register names and the init code. Inferred means a driver's use of a bit is a software expectation, not a statement of what the part does.

The NEC page numbers and field positions were re-read against the manual: Figure 11-21 is on printed p. 235, Table 11-18 on p. 236 and the R12000 additions on p. 237 (printed and PDF page numbers agree).

## Fields on the R10000

- **BPOp, bits 1:0.** The branch-table operation. Read-write. Established (NEC manual, pp. 235-236).
- **BPIdx, bits 11:3.** The branch-table index, given as virtual address bits 11:3. Established (NEC manual, pp. 235-236).
- **BPState, bits 15:14.** The branch state, read and written through the table operation. Established (NEC manual, pp. 235-236).
- **BPMode, bits 17:16.** The branch mode. Read-write, reset to 00. Established (NEC manual, pp. 235-236).
- **DBRC, bit 22.** Set disables the branch return cache. Established (NEC manual, pp. 235-236). The Linux header names it `R10K_DIAG_D_BRC`.
- **Other fields.** The manual describes further fields that report branch-stack, branch-return-cache and ITLB-miss state. Reserved bits read zero and must be written as zero. Established (NEC manual, pp. 235-236).
- **Scope.** The manual calls the register local and says it is subject to change without notice. Established (NEC manual, p. 235).

## Changes on the R12000

- **BPIdx widens to bits 13:3.** Established (NEC manual, pp. 235-237).
- **Global history, bits 26:23.** Bit 26 selects all eight history bits. When bit 26 is clear, bits 25:23 give the count. Established (NEC manual, pp. 235-237). The Linux header names bit 26 `R10K_DIAG_E_GHIST`.
- **Branch target address cache, bit 27.** Set disables it. Established (NEC manual, pp. 235-237). The Linux header names it `R10K_DIAG_D_BTAC`.

## R14000 and R16000

No cited manual describes the Diagnostic register on the R14000 or R16000. What is known comes from the Linux driver and from an assumption.

- **Driver use (inferred).** Linux ORs bit 26 (`R10K_DIAG_E_GHIST`) into the register at init on the R12000 and, in the shared branch for implementation `0x0f`, on the R14000 and R16000 alike (cpu-probe.c, lines 1225 to 1251). Implementation `0x0f` with a revision major above 2 is the R16000 (see [devices/r10000_identity/README.md](../r10000_identity/README.md)). This is a software expectation. It shows the driver's intent, not that the part honours the bit.
- **Layout assumption (inferred).** Assuming the R16000 keeps the R12000 layout, its writable control fields would be BPOp 1:0, BPIdx 13:3, BPState 15:14, BPMode 17:16, DBRC 22, global history 26:23 and branch target address cache disable 27. The only support is that Linux sets bit 26 with the R12000 name on implementation `0x0e` and `0x0f`. Linux defines bit 27 (`R10K_DIAG_D_BTAC`) but never writes it, so the driver says nothing about bit 27 or the other fields on the later parts. The writability of DBRC is inferred from its description as a disable control.
- **Not established.** Whether the R14000 keeps the R12000 layout is not settled by any cited source either.

## Unknown, and what would settle it

- **R16000 writable bits.** Which bits software can change, and which read back as stored. Settled by the R16000 processor manual, or by a write-and-readback test on an R16000 part that compares only the bits the R12000 layout names.
- **R16000 branch-table index width.** Whether the index is 11 bits (13:3, as on the R12000) or narrower. Settled by the R16000 manual, or by the same readback test, which exposes the index width.
- **R16000 reset value.** A read taken after firmware has written the register is not a reset value. Settled only by a read taken at reset, before any firmware write, on an R16000 part. Public sources give no reset value for this register on the R14000 or R16000.
- **R14000 layout.** Whether the R14000 keeps the R12000 layout. Settled by an R14000 processor manual.

Shipped kernel and PROM code also write this register. Those observations are not on this page until the chip census in this repository reads them.
