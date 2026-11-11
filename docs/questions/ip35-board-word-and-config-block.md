# IP35 PROM: the board-identification word, the processor configuration table and the flash configuration block

Question. A Bedrock node board carries a 64-bit identification word that the PROM and the kernel read to tell
the board families apart. What do its low bits select, which values do the PROM and the kernel accept, how does
the PROM turn the word into a processor configuration and compare it with the 80-byte block stored in flash
(including the machine-type field), what do the PROM and kernel read from the network-interface port status
register when no router is attached, and which other node set-up reads can differ on hardware?

Method: disassembly of the shipped IP35 PROM image (SGI Version 6.210, built Aug 26 2004; container segment
`ip35prom`, load and entry 0xc00000001fc00000, length 0x1686a8, unpacked segment sha256
554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b). The segment carries a second, compressed
segment named `io7prom` at segment offset 0x8abb0 (load and entry base 0xc000000013000000, 1,468,990 bytes after
inflation, additive checksum verified, sha256 f903b3ce33b86c286f168ba43395f36a0073c24b1d4e703adce240f683b8c2d7).
That nested segment holds the summary printer and the comparison described in section 2. Addresses are image
addresses: "outer" means the first segment (offset = address - 0x1fc00000) and "nested" the second (offset =
address - 0x13000000 after the 0xc000000000000000 prefix). Constants were folded by hand from the global
pointer table. Nothing was run. Kernel citations are to the IRIX 6.5.30 IP35 kernel and are detailed in the
kudzu repository's `docs/ip35-node-class-and-link-checks.md`.

Sources outside the binaries, used afterwards to report agreement: Linux 2.5.40 `include/asm-ia64/sn/sn1/ip27config.h`
and `hubni.h` / `hubni_next.h` (SN1 headers); OpenBSD `sys/arch/sgi/sgi/ip27_machdep.c`, `sgi/ip27.h` and
`xbow/hub.h`; a public Fuel `flash -f` console transcript and the same page's list of shipped processor options
(a public page of notes on updating Fuel firmware; message text only, no copy kept here).

## Answer

### 1. The board-identification word

1. **Established: where it is read.** One 64-bit load from the uncached window address 0x9000000014000000
   (the local node) or from 0x9000000034000000 plus the node number shifted left 33 (an explicit node). The
   two pool words are at 0xc00000001fd677d0 and 0xc00000001fd677b8 in the outer segment. The two addresses
   differ only in address bit 29, the local-versus-node-addressed alias, as for the other register windows in
   [Bedrock](../../chips/bedrock/README.md#window-and-how-it-is-reached). The register sits at offset
   0x4000000 of the node's local register space, far above the blocks the
   [Bedrock census](../../chips/bedrock/README.md) lists (they end at 0x7e0040); no census block covers it. Agreement: OpenBSD reads the same address as register 0 of the first of two "synergy" blocks
   (`HSPEC_SYNERGY0` = 0x04000000), through the remote alias, and calls it a 16-bit identification register.
2. **Established: which bits software examines.** Every load site found masks the word with 0xf000 and
   compares the result with a class value. The exceptions are one routine in each segment (outer 0x1fc1f3a0,
   nested 0xc0000000130d6550; same code, section 1.4). Method for the count: every `ld` from either pool word
   and every `lui 0x1400` / `lui 0x3400` address build was followed for the next dozen instructions in both
   listings; masks 0x7f, 0xef and 0x10/0x20/0x40 occur nearby but belong to other values (node numbers and
   flags, read case by case for several sites, not for all). Bits 63:16 and, in the Fuel class, bits 11:4 are
   never examined by either PROM segment or by the kernel (the kernel census is in
   the kudzu repository, `docs/klconfig.md`, "The IP35 node class nibble").
3. **Established: class values.** The PROM compares bits 15:12 with 0x2000, 0x4000, 0x8000 and 0xc000; any other
   value takes the default path. The kernel compares with 0x4, 0x8 and 0xc (kudzu). OpenBSD names 0 (the Origin
   3000 C-brick default), 2, 4 and 8; its value 4 is the Fuel class and the value 8 the Origin 300 class.
   The meaning of class 0xc is not named by OpenBSD; the kernel treats it as the PE-brick class (kudzu). The
   PROM's class 0x2000 has a processor table (below) and agrees with OpenBSD's value 2.
4. **Established: the low bits.** Only the processor-configuration fallback reads them (outer 0x1fc1f3a0, nested
   copy 0xc0000000130d6550, whose index table at nested offset 0x164490 and first 29 rows at nested offset
   0x11f2b8 are byte-identical to the outer copy). It builds a table index:
   - class 0x4000 (Fuel): index = 0x20 + bits 3:0;
   - class 0x2000: index = 0x30 + bits 3:0;
   - class 0x8000: index = 0x10 + bits 7:0 (bytes above 0x2f index past the 64-entry table; not examined);
   - any other class: bits 3:0 as the index; if that nibble is 0xf, bits 7:4 are tried instead, for two
     iterations at most.
   The 64 signed words at 0x1fd51f20 map the index to a row number (-1 = none). The 16-byte rows start at
   0x1fd52020. A row supplies the processor mode word, processor and bus clocks, the flash-timing bytes and the
   machine type (section 2). Bits 3:0 select the row; the name the PROM prints for the fallback is "board/PIMM
   PSC" (outer string, established as a string), so the nibble is the processor module's own code. That the
   nibble is driven by the processor module and not by a strap on the node board is **inferred** from that
   name, from the same field's use by the system controller (a public repair account quotes the controller
   reporting an unknown PSC value) and from the table's content (it tracks the shipped processor options).
5. **Established: the Fuel-class rows.** Decoded with the public SN1 field layout (agreement only; see section 2):

   | nibble | row | mode word | CPU MHz | bus MHz | cache MB | tap | machine type |
   |---|---|---|---|---|---|---|---|
   | 0, 5, f | none | | | | | | |
   | 1 | 27 | 0x569baf85 | 800 | 200 | 4 | 0xb | 2 |
   | 2 | 28 | 0x569cb185 | 900 | 200 | 8 | 0xb | 2 |
   | 3 | 26 | 0x589bad85 | 700 | 200 | 4 | 0xc | 2 |
   | 4, 6 | 9 | 0x549aa985 | 500 | 200 | 2 | 0xa | 2 |
   | 7, 8 | 12, 23 | 0x549bab85 | 600 | 200 | 4 | 0xa | 2 |
   | 9 | 17 | 0x549bad85 | 700 | 200 | 4 | 0xa | 2 |
   | a | 18 | 0x549cad85 | 700 | 200 | 8 | 0xa | 2 |
   | b | 19 | 0x549dad85 | 700 | 200 | field 5 | 0xa | 2 |
   | c | 20 | 0x549baf85 | 800 | 200 | 4 | 0xa | 2 |
   | d | 21 | 0x549caf85 | 800 | 200 | 8 | 0xa | 2 |
   | e | 22 | 0x549daf85 | 800 | 200 | field 5 | 0xa | 2 |

   The "tap" is the secondary-cache clock tap, bits 28:25 of the mode word; "cache" is the three-bit size field,
   bits 18:16 (1, 2, 3, 4 = 1, 2, 4, 8 MB by the public rows; the value 5 has no public row).
   **Agreement with a real Fuel:** the public transcript of a Fuel's processor listings shows 500 MHz / 2 MB /
   tap 0xa, 600 / 4 / 0xa, 700 R16000 / 4 / 0xc, 800 / 4 / 0xa and 900 / 8 / 0xb; those are nibbles 4 or 6, 7
   or 8, 3, c and 2. The same page's `flash -f` run for 800 MHz, 200 MHz bus and 4 MB prints the mode word
   0x549baf85, which is row 20 (nibble c). Independent of the PROM table, so the table is not merely self-consistent.
6. **Established: failure path.** An index with row -1 makes the fallback return zero. The report routine
   (outer 0x1fc1e104) then does not print the "board/PIMM PSC" report and takes its other branch; that branch
   prints a message saying the PIMM/PSC type is unknown or the board has no EEPROM values (the string is at outer
   offset 0x798e0; that this is the branch's text is **inferred** from the call structure, the branch itself not
   followed to the print).
7. **Unknown.** What a real processor module presents in bits 3:0 for each shipped option (the rows above bound
   the answer; they do not say which of the two aliases, 4 or 6, 7 or 8, a real 500 or 600 MHz module drives);
   whether bits 11:4 and 63:16 read zero on a Fuel; what class 0xc is on the hardware side. Route that would settle
   them: a raw read from a running Fuel, or a service manual for the node board.

### 2. The 80-byte configuration block and its machine-type field

1. **Established: layout.** The block is 80 bytes at offset 0x60 of the boot flash. A processor reads the local
   copy through the boot-space window (0x9000000018000060) and any node's copy at 0x9000000038000060 plus the node
   number shifted left 33. The fallback in section 1.4 fills a record of this shape, which fixes the offsets:

   | offset | width | content (value the fallback writes) | public header field |
   |---|---|---|---|
   | 0x00 | 4 | 0x15 | time constant |
   | 0x04 | 4 | row word 0: processor mode word | processor boot mode bits |
   | 0x08 | 8 | 0x69703237636f6e66 (ASCII `ip27conf`) | magic |
   | 0x10 | 8 | row word 1: processor clock in Hz | CPU frequency |
   | 0x18 | 8 | row word 2: bus clock in Hz | hub frequency |
   | 0x20 | 8 | 0x1312d0 (1,250,000) | real-time clock frequency |
   | 0x28 | 4 | 1 | ECC enable |
   | 0x2c | 4 | row byte 12 (0x10 in every row) | flash-timing setting |
   | 0x30 | 4 | row byte 13: 0, 1 or 2 | machine type |
   | 0x34 | 4 | 0 | checksum adjustment |
   | 0x3c | 4 | row byte 14 (0x10 in every row) | flash write-timing setting |
   | 0x38, 0x40, 0x44, 0x48 | 4 | not written by the fallback | flash count, PROM version and revision, config type |

   The names are from the public SN1 header; the offsets and the values the fallback stores match it field for
   field (agreement). The early reset path separately reads the word at 0x64 (the mode word) from the local
   flash copy and compares its low 16 bits and bits 24:16 with CP0 Config after writing it (outer 0x1fc006a8 to 0x1fc006f4;
   a mismatch takes the branch at 0x1fc006fc, which stores code 0xb4 in the real-time compare register).
2. **Established: the mismatch check.** After the diagnostics the nested segment's summary routine
   (0xc0000000130e1f78) walks the modules and calls a comparison (0xc0000000130d6808). The comparison builds a
   reference record, first by asking for the board's configuration text record through the EEPROM request
   (selector 0x100; routine at 0xc0000000130d66bc, the same shape as the outer EEPROM routine at 0x1fc1f4dc and
   not read in full) and, if that fails, from the fallback of section 1.4
   (0xc0000000130d6550); it then reads the flash copy (80 bytes at the node's 0x...38000060 address) and compares
   the two, field by field, for exactly these offsets: 0x00, 0x04, 0x08, 0x10, 0x18, 0x28, 0x2c, 0x30 and 0x3c.
   Offsets 0x20, 0x34, 0x38 and 0x40 to 0x48 are not compared. Any difference makes the module count in the
   "CPU configuration values from board EEPROM/PSC did not match" message (nested offsets 0xed480 and 0xed4b9;
   the text asks for a reflash). The block therefore has to carry the same machine type as the reference, as well
   as the same mode word, clocks, ECC flag and both timing settings.
3. **Established: the machine-type value set the PROM carries.** Across all 29 rows of the table the byte at +13
   is 0, 1 or 2: 0 for the rows reached from class 0x0 and class 0x2000 (200 to 800 MHz options), 1 for the rows
   reached from class 0x8000 indices 0x10 to 0x14 (four rows), 2 for every row reached from class 0x4000. So the
   Fuel class is type 2 and the Origin 300 class type 1. **Inferred, with agreement:**
   0 = "SN1", 1 = "SN10", 2 = "SN11", 3 = "SN12" is the naming of the user-space flash utility's prompt in the
   public transcript ("Enter machine type (0)SN1 (1)SN10 (2)SN11 (3)SN12"); that utility is not held, so
   the mapping from the table's 0, 1, 2 to those names rests on the transcript, where a real Fuel's owner enters 2.
   The public SN1 header defines only type 0 ("only type defined"); it predates these boards.
4. **What else reads the field.** Established: the comparison in 2.2 reads it. Not searched: other PROM readers
   of offset 0x30 of the flash copy, so a later use is not excluded. Established for the kernel: the only loads
   of the node-addressed pool word for 0x9000000038000060 are in the system-call code that copies the 80 bytes
   out to user space unchanged (selector 1200; kudzu `docs/syssgi.md`) and the boot-space base routine
   (`hubdev_prombase_get`, which returns the 0x...38000000 base, not the block); the local 0x...18000060 form has
   no pool word in the kernel. The kernel was not found to interpret the field. Its message that names the
   machine variant at boot ("Selecting SN11", kernel string at file offset 0x4db4f0) was not traced to its
   source; whether it derives from this field is unknown.
5. **Unknown.** Whether a real Fuel's reference is the EEPROM record (and what machine type that record carries)
   or the table; the raw flash block of any physical Fuel; the checksum rule behind offset 0x34 (the fallback
   writes zero and the comparison ignores it, so the PROM's own checksum routine, not read here, sets it).

### 3. The network-interface port status register

1. **Established.** NI port status is the first register of the network block, offset 0x680000 (local alias
   0x9200000001680000, pool word at outer 0xc00000001fd67878). The PROM reads it in two helpers only:
   - outer 0x1fc34b50 returns bit 1 (shift right 1, mask 1): "the link is up". It has seven call sites, among
     them the link wait (below), the router vector access (0x1fc34b70) and 0x1fc5f798;
   - outer 0x1fc343bc returns bits 1:0 as a two-bit value; its one caller is a link-reset diagnostic that
     prints one of two failure texts according to whether the value is nonzero after the reset.
   No other bit is read. Bit 0 is never read on its own.
2. **Established: link wait.** The routine at outer 0x1fc587a8 polls bit 1 until the timer helper at 0x1fc6b73c
   has advanced by 1,000,000 units (a second if the unit is a microsecond, **inferred**; the helper was not
   read), then prints the "local hub NUMAlink is down" text and goes on into the discovery call
   anyway (the branch at 0x1fc588bc returns to 0x1fc58800). If discovery then fails it prints the router
   did-not-answer text and records code 0x9c through the status helpers at 0x1fc69728 and 0x1fc6967c. A node with no peer therefore spends one second here and
   continues; nothing aborts the boot.
3. **Agreement.** The public SN1 header defines the register as a two-bit "port status" field in bits 1:0 and a
   "remote power" bit 2, with the link-up mask on bit 1 (`NPS_LINKUP`), the only field a public driver tests.
   The kernel reads bit 1 only: its router-probe code starts by calling a small helper at
   0xc000000000051b04 (`(*(0x9200000001680000) >> 1) & 1`) and skips the probe when it is zero (kudzu
   `docs/ip35-node-class-and-link-checks.md`). Established.
4. **Unknown.** What bit 0 means (the PROM's one two-bit read treats zero and nonzero as the two cases and gives
   no name), what bit 2 reads, and the full word on a Fuel with no router attached. Software needs only bit 1 = 0
   there. A capture of this register from a running Fuel or Origin 300 would settle it; none is held.

### 4. Other node set-up reads

- **Processor interface.** Readers of the slice number (PI + 0x20), the slot-fitted words (PI + 0x40 and 0x48)
  and the per-slice publication bits are already listed in
  [ip35-prom-mp-presence-poll.md](ip35-prom-mp-presence-poll.md). Established there: a processor whose partner
  slot is not fitted skips the rendezvous wait. For a one-processor board (slice A on the first interface) the
  expected, **inferred** reads are slot-fitted word A nonzero, B zero, and zero for both slots of the second
  interface; no source states the reset values of those words.
- **Address-translation entries 512 to 1023.** The kernel's translation-entry allocator draws from a node-owned
  resource map first and falls back to a second one; the entry count that decides which map frees an entry is
  the halfword at +0x70 of the bridge state record, which the attach routine sets to 128 or 1024 by bridge type
  ([bridge page](../../chips/bridge/README.md)). Established: the allocate and free routines (`pcibr_ate_alloc`,
  `pcibr_ate_free`) make no distinction between indices 512 to 1023 and 0 to 511, and the attach routine
  zeroes all of them. Other users of the entries were not searched. Whether silicon returns written values
  from them is the question the bridge page already marks open for the read view.
- **Memory-controller bank fields.** Not traced in this pass. The outer segment carries a refusal text for 256 MB
  DIMM banks "on IP27 node boards" (outer offset 0x86aa8); how it is selected on an IP35 board was not read.
  Unknown; route: read the memory-configuration routine that calls it.

## Not covered

No hardware was read. Class 0xc, bits 11:4 of the Fuel word and the NI status bit 0 are unknown above and have
entries in [open-questions.md](../open-questions.md).
