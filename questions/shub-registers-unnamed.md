# SHub: what the public header leaves out

Question. SGI's SN2 MMR header names about two dozen SHub registers. Which other SHub registers does a kernel or firmware touch, what are their offsets, fields and reset values, and what do the ones named only by title (PI CAM control, the memory/directory privilege vectors, IPI access, the purge-translation-cache registers) do in hardware?

Status: **unknown**, for all of the below.

- The network interface, the memory controller and directory, and most of the processor interface and local block have no register in the sources read.
- No SHub 2 identification register is named; the SHub 1 one is read only on SHub 1.
- Reset values: none stated. Two registers have an INIT macro of zero (RTC interrupt configuration/enable and the three comparators), graded inferred.
- `ipi_access`: layout and write behaviour unknown; it is read harmlessly by the cross-partition driver.
- `pi_cam_control`: the value 0x8000000000000010 the kernel writes on a revision 2 or lower SHub 1 is unexplained.
- `ptc`: whether the purge reaches the sender's own processors, what the acknowledge is, whether SHub 2's ps field is wider than two bits.
- How a PIC bridge interrupt reaches a processor: the kernel comment says PIC interrupts target a SHub interrupt register while bridges on a TIO do not; the register is not named.
- The mapping from unit to register address block (bits 31:28) is inferred from names.

Routes tried: the Linux v5.3 SN2 platform headers and kernel files read for the register contract (listed in [devices/shub/README.md](../devices/shub/README.md)); we hold no SHub specification, PROM or SAL image (inventory in the program notes, 2026-11-14).

Next routes: (1) SGI ProPack ia64 kernels and modules, if held, carry DWARF for the same headers only, which adds nothing beyond the header; they could confirm shipped structure layouts. (2) A programmer's reference or the Altix hardware diagnostic tools, if they ever surface. (3) The SGI SN2 PROM source or image, which would show every register firmware programs. (4) Hardware reads need the owner's approval and a plan of read-safe registers (AGENTS.md).
