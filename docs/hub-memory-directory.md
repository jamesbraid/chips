# Hub memory and directory

The Hub's memory and directory unit is its memory controller and the keeper of the coherence
directory. It sits at offsets `0x200000` to `0x2000ff` in the Hub register space, with the
performance counters at `0x210000` and the microcontroller/UART blocks, slot identity and indicator
registers at `0x220000`. The register list, the census reach and the reset-value status are in
[devices/hub/registers.md](../devices/hub/registers.md). The field layouts added here are in
[devices/hub_md/registers-extra.md](../devices/hub_md/registers-extra.md), built from
[devices/hub_md/registers-extra.toml](../devices/hub_md/registers-extra.toml).

## Added from the public header

The field layouts, bank-size codes and default constants come from the public Linux SN0 Hub
memory and directory header (Linux v7.2-rc7). The header
gives names, masks and shifts. It gives no access types and no reset values, so the reset of each
register stays unknown and the header's default constants are graded inferred.

- **Memory configuration.** Eight three-bit bank size codes at bits 23:0, a four-bit reply
  guarantee at 27:24, the directory format bit at 28 and the ignore-ECC bit at 29. Bit 30 has a
  name and no stated meaning. The I/O protection enable is bit 31. The header also gives a DIMM 0
  select at 33:32 and four five-bit timing fields: the write and cycle timings of the boot flash at
  48:44 and 53:49, and a second pair the header calls UCTLR at 38:34 and 43:39. Their meanings are
  inferred from the names.
- **Bank size codes.** Code 0 is empty. Codes 1 to 10 are 8 MB, 16 MB, 32 MB, 64 MB, 128 MB, 256
  MB, 512 MB, 1 GB, 2 GB and 4 GB. The bank size in bytes is 4 MB shifted left by the code. The
  header annotates codes 0, 4, 5 and 7 as valid in the memory configuration register, and code 3
  as broken in the first Hub revision. Codes 8 to 10 do not fit a three-bit bank field, so the
  table is wider than the register can store.
- **Default constant of the memory configuration.** The header's default composite is
  `0x001e_7fbc_3fff_ffff`. It is a value software writes as a starting point, so it is inferred
  and is not a reset read from hardware.
- **Bank granule and build modes.** The header's bank index is address bits 31:29, a 512 MB
  granule. Its build modes give four banks in N mode and eight in M mode.
- **Directory format.** Clear selects the standard format and set the premium format. The
  directory state values are shared 0, poisoned 1, exclusive 2, busy shared 3, busy exclusive 4,
  wait 5 and unowned 7.
- **Refresh control.** Enable at bit 63, a twelve-bit counter at 23:12 and a twelve-bit threshold
  at 11:0. The header's default is `0x400`.
- **Outgoing queue size.** Reply queue size at 13:8 and request queue size at 4:0. The header's
  default is `0x3212`.
- **One-wire control.** Two seven-bit phase fields, a ten-bit pulse field at 19:10, an eight-bit
  sample field at 9:2, a done bit at 1 and a read-data bit at 0. The header's own mask for the
  first phase field contradicts its shift, so the position of the second phase field (26:20) is
  inferred from its shift constant.
- **Slot identity and status.** A flash PROM ready bit at 4, an I2C interrupt bit at 3, a slot ID
  at 2:0 and three clock and sync bits at 7 to 5. The header also defines a PIMM field at 7:4 and
  an SN00 slot bit at 7, both overlapping bits above. They are left out.
- **Error latches.** The directory, memory, protocol and miscellaneous error registers each have a
  valid bit and an overrun bit. The directory latch has a valid bit for uncorrectable, protection
  and correctable errors at 63, 62 and 61. Its syndrome is at 38:32, its bad-access field at 41:39
  and its entry address at 29:3. The memory latch has a syndrome at 39:32 and an address at 31:3.
  The protocol latch has an initiator at 60:50, a message type at 47:40, a directory state at 36:33
  and an address at 31:3. The miscellaneous latch has five two-bit fields in bits 9:0. These come
  from the header's structures and masks, so they are established as layouts. Access types and
  reset values are not stated.
- **Migration thresholds.** Both thresholds have a valid bit at 63 and a twenty-bit value at 19:0.
  The candidate register has valid, type and overrun bits at 63, 30 and 29. Its initiator and
  node-number masks overlap at 28:20, so those fields are not imported.
- **Performance counters.** The select register has an enable bit at 3 and a three-bit event select
  at 2:0. Each counter holds twenty bits at 19:0. These bit positions follow the order in which the
  header's structures list fields, so they are inferred.
- **DIMM initialisation.** Both registers have a four-bit select at 35:32 and a twelve-bit mode field
  at 11:0.

## One-wire control in the IRIX kernel

The IRIX kernel's one-wire accessor at `0x6a4d0` drives the control register at `0x2000a8`
(see [devices/hub/registers.md](../devices/hub/registers.md)). Its reads and writes are eight bytes wide (established,
census context). The write is built from shifted fields and stored in one doubleword. The reads then
loop until bit 1 is set (established, census context, the loop at `0x6a564` to `0x6a5a4`). Bit 1
is the done bit and bit 0 is the sampled level. Two consequences follow:

- Starting a slot has to clear the done bit, or a poll could not tell the new slot from the last
  one. This is inferred from the loop, not read from a trace.
- The done bit's reset value is unknown. The header's reset constant sets only the two phase fields,
  and no held source sets the done bit. A test should check that the done bit reads clear after a
  start, not what it holds out of reset.

On the wire, the header and this repository's sources give no electrical description. For a
one-wire line with a pull-up, an idle line reads high. A bit slot with no part attached would then
sample one. This is inferred from the general one-wire convention, not from a document cited for
this part.

The part on the bus is not identified by any held source. Its family code, its identity read and
whether it is an add-only memory are unknown. One-wire parts on other chips are neighbouring rows
and are not evidence for this bus.

## What stays open

- The access type and reset value of every register in this unit. The census reads most of them and
  the header states neither.
- The reset value of the one-wire done bit, the physical meaning of the one-wire phase, pulse and
  sample fields, and the part class on the one-wire bus.
- The meaning of bit 30 of the memory configuration, the DIMM 0 select values and the timing fields
  beyond their names.
- The meaning of the candidate initiator and node fields, which overlap in the header.
- Whether the header's default constants match a hardware reset. They describe what software writes.

## Left out

The following were checked against the source material and not imported. They rest on sources the
reference rules do not allow here: vendor kernel and PROM source text, a firmware disassembly that
this repository does not hold, a published manual whose copy was not available to check at this
step, and behaviour that is not evidence from hardware.

- The bank population of the Origin 200 board, its DIMM pairs and the mandatory bank 0.
- The premium-directory probe at boot, the firmware's writes to the memory configuration and the
  reading of the directory-format bit back.
- The read-miss, write and invalidation sequences of the directory protocol.
- The boot flash address decode and its uncached and cached views.
- The one-wire responder roles and the PIMM record.
- The junk-bus UART behaviour and the boot flash command interface.
- The error-clear and read-to-clear semantics of the error aliases beyond what the census shows.
