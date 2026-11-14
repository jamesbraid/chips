# Synergy: what is beyond the interrupt mask and performance registers

Question. The SN1 IA-64 node puts a Synergy ASIC between each Bedrock processor interface and the Itanium bus. SGI's Linux
port touches eight interrupt-mask registers and eight performance registers. What are the rest of the Synergy's registers,
their reset values, and the layout of the performance control word?

Known: [platforms/sn1-ia64/synergy.md](../platforms/sn1-ia64/synergy.md) records everything the port defines, graded. That now includes a
ninth register read from SGI's fake PROM: offset `0x450` (`FSB_CONFIG`), written with `(nasid << 16) | (synergy << 9)`. The Synergy's
function and its Itanium (first generation) are settled to the grades on that page; the register file beyond the 17 offsets is not.

Routes tried: Library mail 2000 to 2005 and the public web (Computerworld, HPCwire, Linux Journal, Slashdot, ESJ; no page names the chip); every file under `arch/ia64/sn/` and `include/asm-ia64/sn/` in the Linux v2.5.0 snapshot, and a probe of
`synergy.h` and `synergy.c` at v2.5.7 to v2.5.72 (the same register set). The IRIX tree for the MIPS machine does not
carry Synergy because the MIPS node has none.

Unknown and why it matters: the remote write path splits a value into four 16-bit stores at `reg << 2` while a remote read
uses `reg` unshifted. Which is right for hardware (and whether the simulator, the only machine the code was run on, shares the
hardware behaviour) decides how an emulator must decode Synergy accesses.

Next route: a Synergy specification or an SN1 IA-64 PROM image, neither held. A rule applies to what an emulator may rely on: for the
simulator path the 17 known offsets are all the kernel and the fake PROM touch, so a first model needs no more
([bring-up.md](../platforms/sn1-ia64/bring-up.md)). A Linux tree older than v2.5.0 (the ia64 patch
series of 2000) is not in the Library; its Synergy code may differ. Mail from SGI staff in the ia64 list around
December 2000 to mid-2001 might name more registers.
