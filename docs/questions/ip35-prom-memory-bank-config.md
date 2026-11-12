# IP35 PROM: how the memory-controller bank configuration word is read, written and sized

Question. The Bedrock memory controller has one 64-bit configuration word that holds, per pair of DIMM banks, the
enables and a size code, plus a bank-select field. How does the shipped IP35 PROM decode that word into up to eight
banks, how does it write the bank-select field, how does it size a bank (and what does a 256 MB bank do on that
path), and do the two shipped PROM builds (6.210 and 6.211) differ in any of it?

Method: disassembly of the shipped IP35 PROM image (SGI Version 6.210, built Aug 26 2004; container segment
`ip35prom`, load and entry 0xc00000001fc00000, length 0x1686a8, unpacked segment sha256
554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b) and of the 6.211 image (built Jan 25 2008,
length 0x168648, sha256 25f60c7f0bae9cf32611e04205b7d0c8cf08adfddbfc1bfe433facd95b5ce271). Addresses are 6.210
image addresses in the style of [ip35-reset-window.md](ip35-reset-window.md); the 6.211 address of each routine is
in the last table. Constants come from the global pointer table (gp = 0xc00000001fd6f740). Nothing was run. The
kernel citation is to the IRIX 6.5.30 IP35 kernel (`unix.IP35`, link addresses). Public Linux and OpenBSD sources
were not consulted for any fact here.

## Answer

1. **The word, and where the PROM reaches it. Established.**
   The PROM reads and writes the configuration word at node-alias offset +0x1f80008: table word
   0x9200000001f80000 (segment offset 0x1679d8) plus the node number shifted left 33, plus 8
   (routines 0x1fc56e2c and 0x1fc56d94 below). This is the same word the [Bedrock page](../../chips/bedrock/README.md)
   lists at +0x1f80000 to +0x1f80008; the local-form address is +0x780008 (the kernel's own load of that local form,
   table word 0x9200000001780008, is in item 4).

2. **Decode into eight banks. Established (whole routine 0x1fc56e2c read, 0x6c bytes).**
   The routine takes a node number and a pointer to eight bytes and fills the bytes from the word:
   for index i from 0 to 7, lane = (i >> 1) & 3; enable bit = word bit (8 x lane + (i & 1)); size code = word bits
   (8 x lane + 7) down to (8 x lane + 4); byte i = size code when the enable bit is set, else 0. So the word is four
   byte lanes; in each lane bits 1:0 enable the lane's two banks, bits 7:4 carry **one size code shared by both
   banks of the lane** (bits 3:2 are not read here), and "software bank" i is the lane's bank (i & 1) of lane
   (i >> 1). Eight software banks come out of four lanes. A console message about two banks whose sizes differ
   exists (text at 0x1fc7af68); which two banks it compares was not traced.

3. **Writing the bank-select field. Established (whole routine 0x1fc56d94 read, 0x98 bytes).**
   The routine takes a node number and a selector. It reads the word, ANDs it with the table constant
   0xfffffffcffffffff (clears bits 33:32 only), ORs in the selector shifted left 32 (not masked to two bits by this
   routine) and ORs in 7 shifted left 56, and stores the result back at +8 of the node alias as its last
   instruction. It also reads one other word of the node (node alias +0x1e08008, bits 58:43) and passes it to the
   console printer; that word is not named here. Three call sites in the memory
   initialisation routine (0x1fc65aa4 selector 3, 0x1fc65b38 selector 1, 0x1fc65b4c selector 2) are the bank-0
   swap path; the text printed on that path names a swap of bank 0 with another bank and says the other banks of
   the node are remapped too. Whether bank 0 is swapped depends on tests in the memory initialisation routine
   (0x1fc6587c) that this pass did not follow: **unknown**, route: trace the branch ahead of 0x1fc65aa4 against the
   per-bank sizes.
   Bits 58:56 of the word are set to 7 by this store and by the other two writers listed in
   [ip35-prom-mp-presence-poll.md](ip35-prom-mp-presence-poll.md#answer) item 3; nothing here clears them.

4. **What the bank-select field does to addresses. Established for the kernel's reading; inferred for the chip.**
   The kernel routine that turns a memory-error address into a DIMM name (6.5.30 IP35 kernel, link addresses
   0xc00000000006b9ec, 0xc00000000006ba90, 0xc00000000006bb10) loads the local-form word, takes bits 33:32 as S,
   forms (address & 0x1ffffffff) XOR (S << 30), and takes bits 32:31 of the result as the DIMM-pair index; the
   within-pair bank is then bit 30 of the same swizzled value (the first routine adds a syndrome bit to it). Address
   bits 31:30 are therefore XORed with S and bit 32 is not: a node's eight 1 GB software slots are permuted only
   inside the two groups of four that share bit 32. Inferred (from this one consumer): that the chip applies the
   same XOR on the access path. The kernel also uses the matching value when it sizes memory: its slot-size
   routine for the IP35 (link address 0xc00000000004f408) reads bank sizes from the node's memory component and
   XORs the slot number with a signed halfword at +58 of that component, with no condition. Where the PROM puts
   that halfword (probably the selector it wrote above) was not traced: **inferred**, route: find the PROM store
   to component offset +58.

5. **Sizing one bank: the probe. Established (re-read in full for the return mapping).**
   Routine 0x1fc2d18c (0x398 bytes) takes a bank base address (bits 32:30 of it, `a0 >> 30 & 7`, pick the software
   bank: 1 GB per bank, eight banks per node) and an output pointer.
   - It first reads two per-bank override strings from the PROM's saved settings, one character per software bank
     (the character minus '0' is an override; one string is for the directory type, one for the size). When both
     overrides are present the probe skips the hardware measurement and uses the digit as the size code (a lone size override
     does not skip it; see the tail below). The console warnings for the two variables are printed only when the bank base is 0
     (the branches at 0x1fc2d1e8 and 0x1fc2d25c to 0x1fc2d4d8 and 0x1fc2d4fc); 0x1fc2d250 is the size lookup.
   - Without an override it works on the memory controller's directory carriers (address transform: node bits
     39:33 kept, address bits shifted right 3 and masked, the carrier window 0x90000001c0000408, built from the constants at 0x1fc2d2c0 to 0x1fc2d2f4) and not on the data
     RAM. Phase 1 writes sixteen 64-bit patterns at 64 MB spacing, descending from base + 960 MB to base; the
     pattern for the sample at offset X MB is the 16-bit value (X xor 0x5a5a) replicated four times; each write is
     read back at once and compared under a mask. Established (0x1fc2d2ac to 0x1fc2d2f8): the mask is one of two 32-bit lane masks, `0x0000ffff0000ffff`
     when bit 30 of the bank base is clear and `0xffff0000ffff0000` when it is set; it does not depend on the directory type, and no phase
     compares the whole word under it. Any mismatch ends the probe with 0 (the bank is treated as empty).
   - Phase 2 then tests five offsets in turn, 0, 64, 128, 256 and 512 MB (the count i = 0 to 4 gives offset
     32 MB shifted left i, i = 0 being offset 0), reading the carrier for that offset and comparing it with the
     pattern phase 1 wrote at the **same** offset. A bank that is smaller than an offset has the high address bits
     missing, so a phase-1 write at that offset landed on a lower location and a later (lower) write overwrote it:
     the read-back is the lower pattern and the compare fails. The loop stops at the first failing i; if all five pass
     it ends with 5.
   - So the count that comes out is 0 for an empty bank, 1 for a bank of 64 MB or less, 2 for 128 MB, 3 for 256 MB,
     4 for 512 MB and 5 for 1 GB: the size is 32 MB shifted left by the count. **Established** (the whole routine
     read, 0x1fc2d18c to 0x1fc2d4f8): the loop shape, spacing, offsets and patterns, and the routing below.
   - The tail (0x1fc2d370 to 0x1fc2d3f8) reduces to two flags and a count. A phase 2 compare that matches the whole 64-bit pattern at every
     tested offset marks the bank type 1 (the "Premium" setting named below); one that matches only under the lane mask marks it 0; a bank
     whose offsets mix the two, or that fails phase 1, gets type -1 and count 0 (0x1fc2d4c0, 0x1fc2d4cc, 0x1fc2d368). The count is the
     number of offsets that passed before the first failure, 5 when all did. The two override strings are read first (0x1fc2d1a8 to
     0x1fc2d27c): the character for the bank in `MemCfgPremium` (promlog variable, text at 0x1fc7ae38) gives override type 0 for '0', 1 for '1',
     -1 for any other character, and -2 when the variable is absent; the character in `MemCfgBankSize` (0x1fc7ae90) gives the override
     size code (character minus '0'), or none when the variable is absent or the character is '/'.
   - With both variables present the routine skips the measurement: it returns the size digit and stores the override type through its output
     pointer (0x1fc2d28c, 0x1fc2d3fc), even when the type is -1. Otherwise it measures, then returns
     `(type == -1) ? 0 : (size override if present, else count)` and stores `type` through the output pointer, where `type` is the override
     type when the variable is present and the measured type when it is not (0x1fc2d380 to 0x1fc2d3f8). A size override alone therefore still
     runs the measurement, because its effect is only on the returned code. So an un-overridden bank returns 0 for an empty or
     inconsistent bank and 1, 2, 3, 4, 5 for 64 MB or less, 128, 256, 512 MB and 1 GB, and reports type 1, 0 or -1. The routine then
     zeroes the sixteen pattern locations and reads sixteen locations back (0x1fc2d39c to 0x1fc2d3f4) before it returns. What type 1 and
     type 0 mean physically is **inferred** from the variable's name only (premium and standard directory); the text of the console warnings is
     "directory types taken from MemCfgPremium promlog variable" and "memory sizes taken from MemCfgBankSize promlog variable".
   - Nothing in this routine singles out 256 MB: a 256 MB bank gives count 3 like any other size.

6. **The 256 MB message. Established that the text and its code exist; unknown where the code is raised.**
   The PROM carries a table of 16-byte records (segment offset 0x160dd0 onward; first doubleword a pointer to a
   description, second doubleword a code in the top byte) that pairs each fatal progress code with a one-line
   description: unexpected processor exceptions, coprocessor 1 unusable, mode-bit mismatch, bad PROM checksum,
   failed copy of the PROM to memory, DIMM memory-test and directory-test failures, memory disabled from the monitor,
   bank 0 unusable (code 0x2f), then code 0x65 (record at 0x160e80, text at 0x1fc86aa8), which says in words that a
   256 MB DIMM bank is not supported on the Origin 2000/Onyx2 node-board family, then Ethernet test failures (0x66
   upward). The same codes are what the PROM writes to its per-slice progress registers (routine 0x1fc6b54c). No instruction that loads 0x65 as an
   immediate was found other than three character compares (0x1fc34170, 0x1fc34264, 0x1fc681f8, all of which test
   the letter `e`), so no site that raises code 0x65 was found: **unknown**. The record may be reached by a computed
   code (for example a base plus a size code); that was not tried. Because the same PROM family boots the
   256 MB-bank Fuel node board (see [ip35-board-word-and-config-block.md](ip35-board-word-and-config-block.md)),
   the message is not an unconditional rejection of 256 MB banks on IP35 hardware. Route: find every store of a
   progress code whose value is computed (not an immediate) in the memory initialisation and node-class code, and
   evaluate it for a 256 MB size code.
   The reset-window page's statement that the image rejects 256 MB banks refers to this same record; this page
   narrows it: the record exists, its raising site is not found.

7. **The default word before probing. Established for the code shape.**
   The producer routine at 0x1fc660b8 builds the word in a loop over the four lanes, ORing into each lane a size
   code of 5 shifted to bits 7:4 plus a per-lane enable value, and stores it at 0x1fc6647c (+8 of the register
   block pointer it was given) before the per-bank probes run; a second store follows after the probes
   replace the codes (0x1fc666a8). Enable value per lane: not traced here.

## Same in 6.211

Matched by comparing the masked instruction words of each routine in both images (jump targets and gp-relative
displacements ignored). Every routine below has zero masked differences except for string-pointer immediates that
all moved by the same 16 bytes (`daddiu ...,0x6fa8` became `...,0x6f98`):

| Routine | 6.210 address | 6.211 address |
|---|---|---|
| configuration word decode | 0x1fc56e2c | 0x1fc56e24 |
| bank-select writer | 0x1fc56d94 | 0x1fc56d8c |
| size probe | 0x1fc2d18c | 0x1fc2d190 |
| memory initialisation | 0x1fc6587c | 0x1fc65874 |
| default-word producer | 0x1fc660b8 | 0x1fc660b0 |

Established for those routines. Not compared: the rest of the image.

## Sites

| What | Image address | Grade |
|---|---|---|
| configuration word at node alias +0x1f80008 | 0x1fc56e2c, 0x1fc56d94 | established |
| bank-select clear mask and 7 << 56 | 0x1fc56de0 to 0x1fc56e28 | established |
| swap-path selectors 3, 1, 2 | 0x1fc65aa4, 0x1fc65b38, 0x1fc65b4c | established (guard unknown) |
| probe loops and patterns | 0x1fc2d2fc to 0x1fc2d364, 0x1fc2d42c to 0x1fc2d4cc | established |
| override lookups | 0x1fc2d1d8, 0x1fc2d24c | established |
| 256 MB progress-code record | segment offset 0x160e80 | established (raising site unknown) |
| kernel error-address decode | 0xc00000000006b9ec, 0xc00000000006ba90, 0xc00000000006bb10 | established |
