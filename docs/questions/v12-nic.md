# Odyssey (VPro V10/V12) board NIC and the "NULL nic_info" alert

Clean note for an implementer. Own words; binary addresses and public datasheets only.
Grades: **established** (read from shipped binaries or a public datasheet), **inferred**
(follows from established facts, not seen directly), **unknown**, and **model choice**
(a proposal, not hardware evidence).

Binaries: IRIX 6.5.30 `IP30boot/odyssey.a(odsy_init.o)` and `IP35boot/odyssey.a(odsy_init.o)`
(driver), `IP30boot|IP35boot/nic.o` (host one-wire code, linked into `unix.IP30`/`unix.IP35`).
Public: Dallas DS2505 (family 0x0B), DS2502 (family 0x09), Dallas 1-Wire/MicroLAN book of
standards (ROM commands, CRC-8 and CRC-16); Linux `drivers/net/ethernet/sgi/ioc3-eth.c`
(same MCR bit layout and pulse timings, public).

## Short answer

1. The NIC is a Dallas 1-Wire (MicroLAN) memory part, not I2C. The driver gives the host the
   address `board + 0x10dc` and the host's generic one-wire code bit-bangs it through a
   32-bit control register there. (established)
2. `nic_info` is the text label (name `_nic`) on the board's hardware-graph vertex. The driver
   does not read it itself. The host routine that fills the label stores it **even when the
   bus read fails**, so a bad or absent part gives a text like "not present", never NULL.
   (established)
3. So the alert cannot come from a failed bit-level read. It means the label is missing on that
   vertex at the moment the name routine runs. Candidates are a failed allocation or a failed
   label add in the host routine, or (Tezro only, inferred) the other registration path. The
   cause on a given run is **unknown** and needs one breakpoint run (see the last section).
4. Both messages are non-fatal; attach goes on. (established)

## What the board NIC is

- Part: a Dallas 1-Wire memory part. The host reads family 0x0B (DS2505-class: 64 pages of
  32 bytes, with a page redirection map) and, on IP35 only, family 0x09 (DS2502-class). The IP30
  host code reads family 0x0B only and ignores any other family. (established, `nic_mfg_next`,
  IP30 `nic.o` 0x1124 and IP35 `nic.o` 0x1158.)
- Which family a real V12 carries is **unknown**. IP30 reads only 0x0B and V10/V12 report text
  on IP30, so 0x0B is **inferred**.
- The same bus type is used on the node, I/O, router and Ethernet boards (the part is called a
  "number in a can"); only the access routine and register address differ per board.

## How the driver reaches it

- Gate: attach reads the word at board `+0x4`. Bits 31:28 below 2 skip the NIC and the name
  routine entirely. V10/V12 present widget revision 10 (>= 2), so they take it. V6/V8 are
  revision 2, so they take it too. (established; IP30 `odsy_attach` 0x524, IP35 0x71c.)
- IP30: one path. It calls the host `nic_vertex_info_set(access = nic_access_mcr32,
  arg = board + 0x10dc, vertex = the board's crossbar vertex)`, then `odsy_set_gfx_mfg_nic_name`.
  (established; relocation to `nic_access_mcr32` in IP30 `odsy_init.o` .sdata +0x28, call at
  0x648, name routine call at 0x650.)
- IP35 (Tezro, Onyx 350, Fuel): two paths, chosen before the call. If a host platform word has
  bits 15:12 equal to 4, or the host `get_chimera_type` for the node is nonzero, the driver
  calls `eeprom_vertex_info_set` instead, which builds the same `_nic` label from the
  **node's** EEPROM text and never touches `board + 0x10dc`. Otherwise it calls
  `nic_vertex_info_set` with `board + 0x10dc` as above. (established: IP35 `odsy_attach`
  0x8dc to 0x968.) Which branch a Tezro takes is **unknown**; "CHIM_ODY" in the name list
  below suggests a chimera-type host uses the first, **inferred only**.
- Registers: only `board + 0x10dc` is passed. Nothing in the driver touches `+0x10d8`. Any
  second register is **unknown** (the host code never takes a second address).
- The driver does not write the GPIO enable (bit 21 of a general-purpose set register) that
  the Ethernet-controller variant writes before reading. (established)

## Register and wire protocol (host one-wire code)

- Register `+0x10dc`: 32-bit control word, the same layout as the IOC3 MicroLAN control
  register. Write: pulse width and sample time packed as in Linux `mcr_pack`, with bit 10
  marking the pulse and bit 2 the sample (as the host composes them). Read back: bit 1 = done,
  bit 0 = sampled bus level. The host polls bit 1 with no limit, then waits the requested
  delay, then takes bit 0. A model that never sets done hangs attach. (established,
  `nic_access_mcr32` IP30 `nic.o` 0x1018, and Linux ioc3-eth.c. The field widths of the packed
  pulse and sample values are Linux's and were not re-derived here.)
- Bit operations (microseconds, pulse / sample / delay after): reset+presence 520/65/500
  (level 0 = a part answered); read slot 6/13/100; write 1 = 6/110/0; write 0 = 80/30/0.
  (established)
- Command sequence: reset; ROM Search (0xF0) 64 times reading a bit and its complement, then
  CRC-8 over the 8 ROM bytes (nonzero = fail); then reset, Match ROM (0x55) + ROM; then for
  family 0x0B: Read Status (0xAA) at 0x0100 for the 64-byte redirection map in eight groups
  of 8 bytes each followed by a CRC-16; then Read Memory (0xF0) + 16-bit address (page x 32,
  low byte first) and 32 data bytes of page 0, again for page 1. Each page ends with an
  inverted CRC-16 (reflected, polynomial 0xA001; residue 0xB001 over all 32 bytes). Redirection
  entry 0xFF = not redirected, else page = complement. (established; DS2505 datasheet
  matches; `nic_read_one_page` 0x6e8, `nic_read_mfg` 0x878.)
  Family 0x09: no redirection map, one extra byte (command CRC) after the address.
- ROM layout as the host consumes it: byte 0 family, bytes 1..6 the 48-bit serial (stored most
  significant first in the host's buffer), byte 7 CRC-8 (Dallas x^8+x^5+x^4+1). (established)

## Data format

Memory layout the host expects (family 0x0B), 64 bytes in two pages (page A then page B),
each page 30 data bytes + 2 CRC bytes:

| Field | Location | Grade |
|---|---|---|
| validity | page A byte 0 must be 1, else text "NIC:page A data not available" | established |
| serial (printable) | page A bytes 1..10 | established |
| part number | page A bytes 11..29 plus page B bytes 0..5 (25 chars) | established |
| revision | page B bytes 6..9 | established |
| group | page B byte 10 (printed hex) | established |
| capability | page B bytes 11..14 (hex) | established |
| variety | page B byte 15 (hex) | established |
| name | page B bytes 16..29 (14 chars) | established |

Text the host builds (the label): `Part:<part>;Name:<name>;Serial:<serial>;Revision:<rev>;Group:<hh>;`
`Capability:<hhhhhhhh>;Variety:<hh>;Laser:<12 hex digits of ROM serial>;`. Printable fields drop
spaces, turn `:` and `;` into `?`, turn 0xFF into space, other non-printables into `.`, and a
field that comes out empty becomes one space. (established, `nic_mfg_next`, `chars2print`
0xc98.)

Failure texts (also stored as the label, never NULL): "NIC:Failure reading interface;Laser:
unreadable;" (2), "NIC:CRC failure reading interface;..." (3), "NIC:Not present on interface;..."
(4), "NIC:Mfg part with redirection loop;..." (5), "NIC:Called with invalid parameter;..." (6),
"NIC:Can't access part;..." (7+). An empty bus gives the (4) text. (established)

## What `odsy_set_gfx_mfg_nic_name` parses

(IP30 `odsy_init.o` 0x3d0, 340 bytes; IP35 0x5c4, 344 bytes.) It only wants the value after a
`Name` token.

1. Fetch the `_nic` label on the board's vertex. No vertex handle: clear the board's name
   buffer first byte, return 1, no message. Label NULL: log "odsy_set_gfx_mfg_nic_name fail: NULL
   nic_info" (severity 1, alert), clear the byte, return 1. (established)
2. Copy at most 1023 characters, split on `:` and `;` (consecutive separators collapse, so an
   empty value is skipped and the next token is taken as the value), compare each token to the
   exact string `Name`; the following token is the name. A later `Name` replaces an earlier one.
   No `Name` token: empty name, still return 0. (established)
3. Copy the name into the board record (IP30 +0xb4b8, IP35 +0xb4d0) with no length bound
   beyond the token, and terminate it. Return 0. (established)
4. The only reader of the name is the timing-table loader, which compares its start with
   `ODY128B1_2` (10 chars), `CHIM_ODY` (8) and `CHIODY` (6), and on a match programs the DVI
   output registers (a failure there is an error). Names seen in published `hinv -m` output
   for V12: `ODY128VERSIONB` (030-1611-001 rev C; also -002, -003 rev A), `ODY128B1_2`
   (030-1945-002), `ASTODY` on IP35 hosts. (established from published captures; whether those
   hinv strings are the same field as `Name:` is **inferred**; `ODY128VERSIONB` is exactly 14
   characters, the Name field width, which supports it.)

## What a real V12 returns

- Name and part: published captures give board name `ODY128VERSIONB` and part
  `030-1611-001` with revision `C` (14 of 81 V12 dumps), others listed in the odsy board
  document. (established as published output)
- Serial, ROM family, ROM serial, group, capability, variety bytes: **unknown**. No public
  capture carries a raw dump.
- Whether the real board's label is built from board NIC (IP30, non-chimera IP35) or node EEPROM
  (chimera IP35): unknown (see the gate above).

## Why nic_info is NULL

- The label is created by the host routine immediately before the name routine, on the same
  vertex (the vertex stored in the board record is the one passed to it; established). The
  host routine ignores the result of the bus read, allocates a 2048-byte buffer, fills it,
  copies it to an exact-size string, adds it as label `_nic`, re-reads the label, and returns
  the stored string. (established, `nic_vertex_info_set` IP30 0x164c, IP35 0x167c)
- Therefore: never-read is excluded (it is always called when the gate passes), and a failed
  read is excluded (it yields a failure text). The remaining ways to get NULL are (a) the
  buffer allocation fails, (b) the label add fails and the re-read finds nothing, (c) on
  IP35 the node-EEPROM path leaves nothing. All are failures in host kernel state, not in a
  board register. Which one happens on a given boot is **unknown**.
- Not verified: whether a real V12 Tezro logs the alert. No capture of this boot message from
  real hardware was found.

## Model choice (not hardware evidence)

If the label is produced by the bus path, a model that makes attach quiet:

- Present a MicroLAN part with ROM family 0x0B, a 48-bit serial, valid Dallas CRC-8 in ROM byte 7.
- Memory: page A byte 0 = 1, bytes 1..10 serial text, bytes 11..29 + page B bytes 0..5 part
  `030-1611-001` (space padded), page B 6..9 revision `C`, 10..15 group/capability/variety
  zero, 16..29 name `ODY128VERSIONB`; each page ends with the inverted CRC-16 of its 30 bytes
  (residue 0xB001). Redirection map all 0xFF with CRC-16 per eight-byte group.
- Done bit set at once; pulse/sample timing may be ignored. Presence = level 0 after the reset.
- A model that returns "no part" is also valid for attach: the label becomes the "not present"
  text and the name stays empty (alert free). Only the name `ODY128B1_2`, `CHIM_ODY`, `CHIODY`
  would trigger the DVI register path, so avoid them unless the output option needs it.

## One experiment to settle the NULL

On a guest boot, break at `nic_vertex_info_get` and `nic_vertex_info_set` (IP35 `unix`:
0xc000000000095590 and 0xc0000000000955bc), or `eeprom_vertex_info_set`, and log v0 on
return and whether `nic_access_mcr32` (0xc000000000094f58) is ever called and what `+0x10dc`
reads. That tells which of (a), (b), (c) applies. Emulator output is model evidence only.

## IP35 EEPROM path

Source: IRIX 6.5.30 `unix.IP35` (symbols present, text addresses `0xc000000000...`) and
`IP35boot/odyssey.a(odsy_init.o)`. Grades: E established (read in the binary), I inferred, U unknown,
M model choice. Nothing here is hardware evidence for what a real V12 board holds. Disassembly was
done with capstone; addresses below are kernel text unless named.

### What the driver calls (E)

- `odsy_init.o` 0x8dc to 0x8fc: after the gate (board +4 bits 31:28 >= 2), if the platform word class is
  0x4000 or `get_chimera_type(nasid)` is nonzero, it calls
  `eeprom_vertex_info_set(0x800, nasid, vertex, 0, 0)`. Otherwise (0x960) `nic_vertex_info_set` on
  board +0x10dc. `nasid` is the node that masters the graphics widget (`xwidget_info_masterid_get`).
- A Tezro's L1 reports brick type 0x39. `set_sn12_type` (0x41550) maps 0x39 to chimera type 3, so a Tezro
  takes the EEPROM path. (E for the mapping; that a real Tezro L1 replies 0x39 is I, see
  `l1-eeprom-names.md`.)

### Q1. Which component and area (E for the kernel, U for the L1 side)

- `eeprom_vertex_info_set` (0x91fac) returns early if the vertex already
  has a `_nic` label, allocates 2048 bytes, and with flags 0x800 (no 0x200 bit) calls `eeprom_str`
  (0x9175c, which is the common routine at 0x915f8 with text mode 0). Flag nibble 0xf00 selects the
  reader: 0x100 C-brick, 0x400 I/O brick, 0x800 graphics; anything else returns 6.
- Graphics reader `gbrick_eeprom_read` (0x93cc8): it needs flag 0x800. It opens the L1 channel of the
  node (`get_elsc()` when the nasid is the local one, otherwise the node's own channel) and calls
  `read_board_ia(sc, fd, component, out)` (0x931ec). The component is a **fixed constant, not derived
  from widget or slot**: 2 on a chimera host (0x93d78 to 0x93d7c), 3 when the platform class is 0x4000
  (0x93dd8). The last non-chimera branch reads an uninitialised stack word (0x93d70); not relevant here.
- `read_board_ia` asks for **area 2** (the board area; `read_ia` 0x929b8 puts the component at message
  +4 and the area at +0x14 and reads 64-byte chunks at rising offsets until a chunk shorter than 64
  comes back). The same reader for the C-brick on a chimera host uses component 0 (0x9355c), which is the
  node board the `/node` hinv line comes from. I/O-brick reads use components 1, 2 or 4 depending on
  flag and peer case (0x93a30 to 0x93a9c); those are the I/O path, not graphics. (E for the numbers, I
  for which caller of the I/O path the iris model's refusals of 1 and 4 belong to.)
- So for the V12 the model must answer **component 2, area 2**. Its refusal of component 2 is exactly
  what stops attach. The refusals of 1 and 4 are not on the graphics path.

### Q2. Does a refusal leave `_nic` unset? (E)

- `sc_interpret_resp` (0xd4e0c) returns the reply's first word, the status, when it is nonzero. `read_ia`
  (0x92a6c to 0x92af4) turns any nonzero return or negative status into 1. `read_board_ia` returns that 1
  and `eeprom_str` passes it up (0x916f0).
- In `eeprom_vertex_info_set`, a nonzero result frees the 2 KB buffer (0x92060) and returns 0 **without adding any label** (the add is at 0x920a0,
  reached only when the read returned 0). So -104 never becomes a failure text; the label stays absent
  and `nic_vertex_info_get` yields NULL, which `odsy_set_gfx_mfg_nic_name` reports as the alert.
  This differs from the 1-Wire path, which stores "not present" text. (E)
- -104 is the L1's "EEPROM not present" (sysco `board-records.md`, the Origin 300 firmware analogue:
  an entry whose probe failed answers -104; a bad header or area checksum answers -107). (E for that
  firmware, I for the Tezro image.)

### Q3. Board area to `_nic` text (E)

Decode order, `eeprom_decode_ipmi_fields` 0x92d54 and `eeprom_decode_sgi_fields` 0x92e44, then the
formatter at 0x90af4 (called `fawlty_disk+0x90` in the symbol table; the symbol is wrong). Public layout:
Intel/DMTF IPMI Platform Management FRU Information Storage Definition, board info area. The kernel
reads it like this:

| bytes | field | goes to |
|---|---|---|
| 0, 1 | format version, length in 8-byte units | version < 2 selects the plain tail; length checked by checksum |
| 2, 3 to 5 | language, manufacture date | ignored by the label |
| next | manufacturer (type/length, data) | not in the label |
| next | product name | `Name` |
| next | serial number | `Serial` |
| next | part number | `Part` |
| next | **one byte skipped** (the FRU file ID slot) | none |
| next | SGI field 1 (type/length, data) | `Revision` |
| next | two raw bytes, then SGI field 3 (type/length, data) | read, not used by the label |
| next | for version < 2: `0xC1` ends it; anything else makes the kernel also decode crypt and net fields | |
| last | checksum: the whole area, length*8 bytes, must sum to 0 mod 256, else status 3 | |

- Type/length bytes: top two bits 0xc0 (ASCII), low six bits the length; `read_board_ia` checks
  nothing else. (E)
- Label text: `Part:<part>;Name:<name>;Serial:<serial>;Revision:<rev>;Group:ff;Capability:ffffffff;Variety:ff;Laser:<hex>;`
  (strings at the kernel string base 0xc000000000499098 + 0x178 to 0x190; group, capability and variety
  are constant text here, not record fields). (E)
- `copy_ascii_field` (0x912cc): `:` and `;` become `?`, bytes 0xff become a space, bytes below 0x20 or
  above 0x7e become `.`, and with the dash flag (set for part, serial, revision, not for name) `_`
  becomes `-`. So `ODY128VERSIONB` and `030-1611-001` pass unchanged. (E)
- `odsy_set_gfx_mfg_nic_name` takes the token after `Name:` (see above); not re-read.
- Which byte a real board has in the skipped slot, and what the two raw bytes and SGI field 3 hold:
  U. A real board's Revision may sit in a different field; the printed hinv rev C is consistent with
  SGI field 1 but that is I.

### Q4. Does a real Tezro L1 answer components 1, 2 and 4 with a V12 fitted? (partly E, answer I/U)

- The type-9 (tower) L1 image registers an ODYSSEY EEPROM device (table entry 2, wire address 0xac,
  bus selector 4) with INTERFACE 0, IO9 1, SNOWBALL 3, NODE 4 around it
  (sysco `docs/l1/ip53-eeprom-record-tables-1.44.0.md`). So the firmware has a graphics-board record
  slot, and the kernel's component 2 equals that table position. (E)
- The same table puts NODE at 4 and INTERFACE at 0, yet the kernel reads the node board as component 0 on
  a chimera host. So component numbers are not simply table positions, or the host remaps. Which
  numbers the 0x0006 handler accepts, and how it maps them: **U** (sysco open question; the handler
  was not read). Because of this the claim "component 1 and 4 answer on a real tower" cannot be made.
- Answer: component 2 is expected to answer when the board is fitted and its EEPROM probe succeeded
  (**I**, from the table slot and the kernel's component 2); -104 is the not-present reply, so a
  real tower with a V12 answers it, otherwise the real kernel would also print the alert on every
  V12 Tezro, which the hinv captures with `ODY128VERSIONB` contradict (I). Components 1 and 4: **U**.
  Settles it: `l1cmd serial all` or a component read from a V12 tower; or reading the 0x0006 handler
  from the compare chain at 0xffe145f8 in the package-2 image.

### Model choice (M, not hardware evidence)

Answer component 2, area 2 (board) on the local node's L1. Area bytes (56, version 1, length 7):

```
01 07 00 00 00 00 c3 53 47 49 ce 4f 44 59 31 32 38 56 45 52 53 49 4f 4e 42
c6 45 4d 55 30 30 31 cc 30 33 30 2d 31 36 31 31 2d 30 30 31 c0 c1 43 ff ff
c0 c1 00 00 00 01
```

Manufacturer `SGI` (placeholder), name `ODY128VERSIONB`, serial `EMU001` (placeholder), part
`030-1611-001`, skipped slot 0xc0, SGI field 1 `C`, raw bytes 0xff 0xff, empty field 3, 0xc1 end, three
pad zeros, checksum 0x01 (sum of the 56 bytes is 0 mod 256). Reply chunks as the kernel requests: at most
the 64 bytes asked, a short final chunk (the 56-byte area ends the loop). A decode of this record by an
independent port of the rules above yields part `030-1611-001`, name `ODY128VERSIONB`, rev `C`
(own script, not the kernel). Keep the name away from `ODY128B1_2`, `CHIM_ODY`, `CHIODY` unless the
DVI register path is wanted. Also still answer component 0 as today.
