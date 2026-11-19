# Synergy: what is beyond the interrupt mask and performance registers

Question. The SN1 IA-64 node puts a Synergy ASIC between each Bedrock processor interface and the Itanium bus. SGI's Linux
port touches eight interrupt-mask registers, eight performance registers, the L4 way mask, two write-status registers and `FSB_CONFIG` (20 offsets in all). What are the rest of the Synergy's registers,
their reset values, and the layout of the performance control word?

Known: [platforms/sn1-ia64/synergy.md](../platforms/sn1-ia64/synergy.md) records everything the port defines, graded. That includes
`0x450` (`FSB_CONFIG`) from SGI's fake PROM, written with `(nasid << 16) | (synergy << 9)`, and from the 2.4.16 and 2.4.18 patch series `0xae0` (L4 way disable) and `0x330`/`0x338` (polled as a PIO write barrier). The Synergy's
function and its Itanium (first generation) are settled to the grades on that page; the register file beyond those 20 offsets is not, and the polarity and bits of `0x330`/`0x338` are unsettled: the loop waits for nonzero, the comment says it waits for a status to clear.

Routes tried: mailing list archive 2000 to 2005 and the public web (Computerworld, HPCwire, Linux Journal, Slashdot, ESJ; no page names the chip); every file under `arch/ia64/sn/` and `include/asm-ia64/sn/` in the Linux v2.5.0 snapshot, and a probe of
`synergy.h` and `synergy.c` at v2.5.7 to v2.5.72 (the same register set). The IRIX tree for the MIPS machine does not
carry Synergy because the MIPS node has none.

Unknown and why it matters: the remote write path splits a value into four 16-bit stores at `reg << 2` while a remote read
uses `reg` unshifted. Which is right for hardware (and whether the simulator, the only machine the code was run on, shares the
hardware behaviour) decides how a Synergy access is decoded.

Next route: a Synergy specification or an SN1 IA-64 PROM image, neither held. For the
simulator path the 20 known offsets are all the kernel and the fake PROM touch
([fake-prom.md](../platforms/sn1-ia64/fake-prom.md)). The 2.4.0-test10 (November 2000), 2.4.16, 2.4.17 and 2.4.18 patch series of the Linux/IA-64 project were read for Synergy (2026-11-15); they add `0xae0`, `0x330` and `0x338` and nothing else. Mail from SGI staff in the ia64 list around
December 2000 to mid-2001 might name more registers.
