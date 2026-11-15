# UV hubs: open questions

Each item names the route that would settle it. No UV firmware, hub specification or router specification is held;
the Linux platform headers are the only register source.

1. **Reset values and side effects.** The kernel header states none, and no UV firmware is held. Route: a UV BIOS or
   hub datasheet; a UV system capture (needs approval). Status: unknown.
2. **UV3 second MMIOH overlay register address.** Settled in review: the v5.4 header repeats 0x1603000 for both
   overlay registers, the v6.6 header gives the second one 0x1604000, and the UV3 map uses that (established). Kept only
   as a record of the v5.4 discrepancy.
3. **Descriptor layout order.** The header comment places the 16-byte message payload at descriptor bytes 0x20 to 0x2f
   and the header at 0x30 to 0x3f; the descriptor struct declares header first, then payload. Route: the destination
   payload queue layout on hardware, or a manual.
4. **GRU: control block start field.** The driver's mask for the operand field is 18 bits while the struct declares
   22; which the hardware honours is unknown.
5. **UV1 hub behaviour absent from v6.6.** UV1 definitions survive only in v5.4 and v3.10 trees; some fields differ
   between those two (read as one); no UV1 reading beyond the kernel exists.
6. **NUMAlink 5, 6 and 7 physical layer.** The kernel states no link rate, packet format or router table layout. The UV
   manuals held (007-5629, 007-5636) are unread beyond the pages cited in the platform page; route: read the UV
   system controller guide for link and brick wiring facts, and any published NUMAlink patents (none read).
7. **UV BIOS call behaviour.** Only names, numbers and argument shapes are in the kernel; semantics of the object and
   geography calls need a UV BIOS image or the system controller guide.
8. **UV4A differences.** The header marks UV4A through a handful of overrides (descriptor base node id position, MMIOH
   overlay and redirect masks, GRU GAM config absent); other UV4A differences are unknown.
9. **GRU on UV3 and later.** The Linux GRU driver refuses to run on hubs of software revision 5 and above. UV3 and UV4
   define GR0 and GR1 registers and UV5 only a GR0 configuration register; what a UV3 or later GRU does differently, and
   why the driver excludes it, is unknown. Route: the UV3 era Linux history of the driver, or a hub manual.
