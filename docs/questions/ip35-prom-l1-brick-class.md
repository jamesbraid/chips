# IP35 PROM: what it does with the system controller's brick type, and which board names it knows

Question. The IP35 boot PROM asks the node's system controller (the L1) for the brick type. What does it do with the
answer, which types does it recognise, which board names are in the PROM itself, and what does a real tower
workstation (Tezro) print that shows the answer? This page is the PROM side only. The controller's own side, which
decides the type character from the board names in its EEPROMs, is in the sysco repository
(`docs/l1/personalities.md` and `docs/l1/ip53-eeprom-record-tables-1.44.0.md`).

Sources. IP35 PROM SGI Version 6.210 (built Aug 26 2004), unpacked segment sha256
`554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`, and IP35 PROM SGI Version 6.211 (built Jan 25 2008,
IRIX 6.5.30 patch 7208), unpacked segment sha256 `25f60c7f0bae9cf32611e04205b7d0c8cf08adfddbfc1bfe433facd95b5ce271`.
Offsets are into the unpacked segment; address = 0x1fc00000 + offset. The nested BaseIO image in the 6.210 container
(sha256 `f903b3ce33b86c286f168ba43395f36a0073c24b1d4e703adce240f683b8c2d7`, load address 0xc000000013000000) was searched
for strings only. Method: Capstone-based routine facts (`retools/tools/hostfacts.py`, flat MIPS IV) and byte searches.
Nothing was run. One public console capture is cited for agreement: a verbose PROM boot of a four-processor tower
Tezro with 1.0 GHz R16000 processors under PROM 6.210, posted to a public IRIX forum.

## Answer

### 1. The classifier

1. **Established: the routine.** In 6.210 the routine at `0x1fc68ba0` returns a small class from the brick type. It
   sends the request the PROM's general wrapper at `0x1fc44ba4` builds (function 6, code 3; the wrapper passes 6 and 3
   to the request writer at `0x1fc63e78`), takes the second integer of the reply as the type character, and maps it:

   | type | character | class returned |
   |---|---|---|
   | `0x37` | `7` | 1 |
   | `0x38` | `8` | 2 |
   | `0x39` | `9` | 3 |
   | `0x30` | `0` | 4 |
   | `0x51` | `Q` | 5 |
   | anything else | | 0 |

   A failed request returns 0 after a diagnostic print (the path at `0x1fc68cf0`). The same compare ladder is at
   `0x1fc68c50` in 6.211 (the routine start was not separately read there; the constants and the ladder order match).
   A second routine at `0x1fc24cc8` sends the same request (function 6, code 3) and reads the same field; it was not read
   further. The classifier's caller at `0x1fc1cfac` (call at `0x1fc1d098`) also calls the board-register reader at
   `0x1fc6b5d0`.
2. **Established: it does not always ask.** Before the request the routine loads the 64-bit board word from
   `0x9000000034000000` plus the node number shifted left 33, and returns 0 without sending anything when bits 15:12
   are `0x8`, `0x4` or `0xc` (compares at `0x1fc68bd8`, `0x1fc68bec`, `0x1fc68c00`). So Origin 300, Fuel and the
   processor-element class never ask; class `0x2000` and class 0 do. It then loads the 64-bit register at
   `0x9200000001608008` and returns 0 without asking only when bit 61 is set and bit 62 is clear (the tests at
   `0x1fc68c24` and `0x1fc68c38`); every other combination asks. **Unknown:** what that register is and what the
   two bits mean. The question page [ip35-reset-window.md](ip35-reset-window.md) lists the register as written by the
   reset code and unexplained; no routine that names it was found. Route: the Bedrock block layout around
   `+0x1600000` and a read on running hardware.
3. **Established: the banners.** The PROM holds four start-up texts, in this order at 6.210 offsets 0x70318, 0x70330,
   0x70348 and 0x70360 (6.211: 0x70308, 0x70320, 0x70338, 0x70350): "SN12 2U Server.", "SN12 Graphics Blade.", "SN12
   Workstation." and "SN12 Rackmounted Workstation." There is no text for class 4 (type `0`). **Inferred:** they are the
   banners for classes 1, 2, 3 and 5, from their order and from the capture below; the routine that prints them from
   the class was not traced (the strings are reached through the global-pointer table, which this pass did not
   resolve). Whether other code (the base I/O image's console setting) consumes the class was not read in this pass.
4. **Agreement with a real tower.** The public capture above prints "hubii_link_good: 9-brick attached to module 001c01."
   three times (the format string is at 6.210 offset 0x852cb, with a `%c` for the character) and the banner "SN12
   Workstation." on a four-processor, 16 MB-cache, 1.0 GHz Tezro tower. Under the classifier of item 1 that is type
   `0x39`. **Inferred**, because the capture is a console, not an L1 reply, and the banner's derivation from the
   class was not traced; no capture of the reply bytes exists. The same corpus holds an Onyx 350 graphics-module
   capture that prints "8-brick attached to module 001c01" and the graphics-blade banner, which fits type `0x38`, and
   an Origin 300 capture that prints "4-brick", the Origin 300 type. No retained capture of an Origin 350 module shows the
   line (so type `0x37` for it is unconfirmed here; sysco derives it from the controller's board-name test).

### 2. The PROM holds no interface-board or I/O-board name

**Established (string and byte search, both PROMs and the nested BaseIO image).** The text `WS_INT_53`, `2U_INT_53` and
`INTERFACE` occur in none of the three. `IO9` occurs once in the nested image, inside the console text for the
on-board gigabit Ethernet interface, not in a table. So the PROM never decides anything from the interface board's
name: the only board names the PROM compares are the six node-board names of the next section. What the
controller's type reply says about the interface board reaches the PROM only through the type character.

### 3. The node-board names and their socket masks (both PROMs, byte-checked again)

**Established.** Six 16-byte rows at 0x8a970 in both PROMs, each a 64-bit pointer then a mask byte at +8 and seven zero
bytes: `IP53_4CPU` 0x0f, `IP53_2CPU` 0x05, `IP53_1CPU` 0x01, `IP59_4CPU` 0x0f, `IP59_2CPU` 0x05, `IP59_1CPU` 0x01. The
names sit at 6.210 offsets 0x6efa8 to 0x6eff8 (stride 16) and, in 6.211, 0x6ef98 to 0x6efe8. The consumer is the
per-socket routine at `0x1fc66d8c` (6.210). Re-read in this pass: it returns at once when the class in bits 15:12 of the
local board word is `0x4000` (`0x1fc66dc0`); otherwise it walks all six rows (the loop bound is 0x1fc8a9b8, six rows from
0x1fc8a958 stepping 16, with the name pointer at +0x18 and the mask byte at +0x20 from the running pointer), compares the
node's EEPROM product name with each row name, and on a name match leaves the socket alone only if bit (1 << socket) of
the mask is set; a name match with the bit clear returns at once (path `0x1fc66e90`). With no row matching it walks off
the end of the table and goes on to the per-socket bring-up. The earlier page's reading is confirmed; the only change is
that the walk is over six rows from a running pointer, not an indexed table.

### 4. The node-board record fields the PROM reads (offsets re-derived)

**Established.** The text keys the configuration reader requires or reads, with their offsets in the unpacked outer
segment: 6.210 format strings at 0x843a0 (`DataValid`), 0x843c0 (`HubModeBits`), 0x843d1 (`CpuCfg0Reg`), 0x843e1
(`CpuCfg1Reg`), 0x843f1 (`CpuCfg2Reg`), 0x84401 (`CpuCfg3Reg`), 0x84411 (`HubSpeed`), 0x84429 (`CpuSpeed`), 0x84439
(`MinIrixVer`), 0x84449 (`MinPromVer`), 0x84459 (`MinL1Ver`); the name table that goes with them at 0x89438 to 0x894e0.
In 6.211 each is 0x18 lower in the format block (`DataValid` at 0x84388 to `MinL1Ver` at 0x84441) and 0x18 lower in the
name block (0x89420 to 0x894c8). The earlier page's block ranges were rounded; these are the first byte of each key.
The nested image carries its own copies at 0x10aea0 to 0x10aef0 and 0x1168c0 to 0x1168e8. How a binary board record becomes these texts, and the parser's field order, were not re-derived in this pass.

## Not settled

- **Unknown:** the type reply of a real Origin 350 and a real Tezro on the wire (the capture above is the PROM's console).
  Route: an L1 `brick` or request-3 transcript, or a verbose PROM boot of an Origin 350 (its type character in the
  "hubii_link_good" line).
- **Unknown:** the register at `0x9200000001608008` and bits 62:61 (section 1.2).
- **Unknown:** where the banner for class 4 comes from, if it prints one.
