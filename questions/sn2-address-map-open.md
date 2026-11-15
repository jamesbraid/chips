# SN2 address map: SHub 2 values, memory layout and the GET space

Question. What are the NASID mask and shift SHub 2 firmware reports, how does SHub 2 split local and global MMR space, how is physical memory laid out inside a node's address range, and what is address space 1 (GET)?

Status: **partly answered** (the SHub 2 shift and mask formula is read from the PROM; which V a chip reports is unknown).

- SHub 2: the kernel never states values. The SHub 2 PROM computes shift `40 - V` and mask `(1 << (V + 10)) - 1` from the register at `0x2_2011_0000` (V 0 to 4) and the local and global windows are bit 33 and bits 33:32 ([shub2.md](../devices/shub/shub2.md)); what is open is the V a real chip reports. SHub 2's local and global MMR offsets (0x2_0000_0000, 0x3_0000_0000) are below any NASID field the fallback would give, so the SHub 1 reading (the node field value 2 selects local MMR space) cannot apply; the kernel's TIO address macro uses bit (shift minus 2). Route: any SHub 2 run record (a /proc topology line prints `nasid_bits` and `shubtype`), or a SHub 2 PROM.
- Memory layout: how much memory a node has, where it starts inside the 64 GiB offset and whether the PROM interleaves banks are not in the code read. The EFI memory map and ACPI SRAT carry the answer on a running system.
- GET space (address space 1): defined, no use in the files read.
- The 11-bit mask and shift 38 are the old-PROM fallback; whether any real SHub 1 PROM reports other values is unknown.

Routes tried: addrs.h and arch.h and every user of the NASID macros in the v5.3 SN2 tree.
