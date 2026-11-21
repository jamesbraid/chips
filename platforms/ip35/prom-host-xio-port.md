# IP35 PROM 6.210: how the node's own crossbar (XIO) port is chosen

Question. Which input fixes the host-side widget number of a Bedrock node: the L1 brick type, the module class, the board, a configuration field or a register read?

Method. objdump of the unpacked segment (SGI Version 6.210, sha256 `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`; image addresses), the Bedrock register pages
of this repository and the model's source for the register. Nothing was run. Grades: **established** (routine read in full), **inferred**, **unknown**.
Related: [stall note](prom-l1-link-and-delay-loop.md), [lead test](prom-lead-test-and-shared-uart.md).

## Answer

**The PROM does not choose the host port. It reads it from the hub: the low four bits of the I/O interface's widget control register (`II_WCR`, node offset `+0x400020`, seen as `+0x1400020` locally and `+0x1c00020` through the node alias), and then configures the crossbar around that number.** No brick-type, board-class or KLCONFIG table that maps to a port number was found. (Established for the reads and the use; "no table exists" is inferred, since a table-driven reset write of the register is not excluded, see 3.)

## 1. Where the number is read and used

| Fact | Grade | Where |
| --- | --- | --- |
| `0x1fc53208(nasid)` returns `*(node alias(nasid) + 0x1c00020) & 0xf`: the hub's widget id. Twelve callers. The local variant is the load at `0x1fc454f4` (`+0x1400020 & 0xf`), which builds a word with the id in bits 23:20 for a configuration record (`0x1fc45474` family, stored at record `+132`). | established | `0x1fc53208`, `0x1fc454f4` |
| The routine that sets up a node's crossbar, `0x1fc4dcd8(nasid)`, first reads the widget at the node's local-block base `+4` (part number in bits 27:12). If the part is `0xd000` or `0xd100` it takes the "arbitration" path `0x1fc4d65c(nasid, hub widget, other port)` where *other port* is 11 if the hub widget is 10, else 10. Otherwise it sets link `(hub widget & 7)` handling itself. In both paths the link control word is at `xbow + 284 + (port & 7) * 64`, and the PROM ORs 5 (bit 0 enable, bit 2 master) into the **hub's own** link. | established | `0x1fc4dcd8` to `0x1fc4dffc`, `0x1fc4d7b4` to `0x1fc4d7ec`, `0x1fc4da74` |
| `0x1fc4c440` ("Check_master: link %d is master") scans links 8 to 15 for the first whose control word has bit 2 set and returns it, 0 if none: it reads the master port back from the crossbar rather than computing it. | established | `0x1fc4c440` to `0x1fc4c4b8` |
| The only special case in the PROM on the hub's id is "equal to 10". A hub id of 10 makes port 11 the other one; any other id makes port 10 the other one. The code assumes the hub sits at 10 or 11, the ports that "face the hosts" of a crossbar brick ([P-brick page](../bricks/pbrick.md)). | established for the code; inferred for the assumption | `0x1fc4dd38` to `0x1fc4dd50`, `0x1fc4ded8` to `0x1fc4def4` |
| The other branch label strings "%s Nbrick. master is 0x%x", "%s %d PEBRICK master is 0x%x", "%s %d SN[012] master is 0x%x" and "%s %d. master is 0x%x" are chosen by the **attached** I/O widget: `0x1fc4ec80` maps a widget part to a brick letter (I, X, N, V, ...), and `0x1fc4d800` tests the part nibble at `+0x3400000` (`0xc000` = PE brick). They set which links of that I/O brick's crossbar are enabled and master; they do not move the hub. | established | `0x1fc4d65c` to `0x1fc4dc00`, `0x1fc4ec80` |

## 2. What the L1 brick type does (it is not the port)

`0x1fc68ba0(nasid)` is a brick classifier. If the widget part nibble at `+0x3400000` is `0x8000`, `0x4000` or `0xc000` it returns 0 (an I/O-class node). Otherwise it asks the L1 for rack, bay and brick type (code `0x0003`, wrapper `0x1fc44ba4`) and maps the type character: `'7'` gives 1, `'8'` 2, `'9'` 3, `'0'` 4, `'Q'` 5, anything else 0, caching the result in local-block scratch 1 (bits 61 and 62; `0x1fc68c1c` to `0x1fc68ca0`). The result is a coarse node class used elsewhere (the memory, partition and discovery paths): **no use of it in the crossbar set-up of section 1 was found.** So `'7'` (2U server: Origin 350, Onyx4 host) is class 1 and does not by itself select a port; `'8'` (Onyx 350 graphics blade), `'9'` (Tezro) and `'A'` (Fuel) do not either. For the IP53 board nothing in the PROM tests the board by name on this path.

## 3. Who sets the register, and what a model must answer

- No store to `II_WCR` was found: direct-address search (`0x1400020`, `0x1c00020`, `0x400020`) finds reads only (`0x1fc454f4`, `0x1fc431b8`, `0x1fc53208`). The PROM's reset-value table lists `II_WCR` with reset `0x4011` (widget id 1), which matches none of the observed ids (0xb on the Onyx 350, 0xa on Tezro and Fuel); a table walk that wrote it would have to be followed by a restore. That the id is latched from board strapping is therefore **inferred**, not read. Whether any reset path writes it is **unknown**.
- A model therefore owes the PROM a value for `+0x400020` bits 3:0 (and the same register through the node alias) before the crossbar step. The value the PROM then uses as the hub's port is whatever that read returns: the model's choice is final.
- The graphics page (Voyager `ip35-prom-graphics.md`) reports that the master port must equal the hub's widget id and that a G2 sits at widget 10: consistent with section 1, since the PROM makes the hub's own link the master (`|= 5`) and, for hub id 10, treats port 11 as the other port. A host at id 10 with a G2 at widget 10 would be configured as master on the G2's port.

## 4. What public captures say about the host id

Hub id as printed by the PROM ("HUB at 0x0 attached as widget 0x%x", string at `0x1fc84ea8`; also `%M/0x%x/xbow_arb:` at `0x1fc88740` and "Check_master: link %d is master" at `0x1fc88718`). All need L1 `debug 0x10d`.

| Machine | PROM banner | Hub id | Grade |
| --- | --- | --- | --- |
| Onyx 350 graphics blade (IP53 family, L1 type `'8'`) | "SN12 Graphics Blade." | 0xb | observed (one capture) |
| Tezro deskside (IP53, `'9'`) | "SN12 Workstation." | 0xa | observed (one capture) |
| Origin 300 (IP45) and Fuel | n/a | 0xa | observed, other boards |

No verbose trace exists for a plain Origin 350 ("SN12 2U Server.", `0x1fc70318`) or an Onyx4 host. Layout evidence from IRIX `hinv` (a device's `xtalk/N` is its own widget, so the hub cannot be N):

- The same part, IP53_4CPU 030-1868-001 rev C, sits in a Tezro (bridges at xtalk/11 and 15, Odyssey at 12; hub 0xa in the separate deskside Tezro trace) and an Origin 350. So the hub id is not fixed by the board part.
- Onyx4 hosts appear on two node boards. One Onyx4 listing shows IP53_4CPU 030-1868-001 rev C and 030-1868-002 rev A, each with a CG brick at xtalk/10. Others show IP59_4CPU 030-1989-003 (rev C and D): the "Artemis" Onyx 350 prototype/Onyx4 (CG brick bridge at xtalk/15 in that capture) and a NUMAlinked Onyx/Origin 350 system mixing IP59 and IP53 nodes. The IP35 PROM serves both boards, so the Onyx4 conclusion rests on the shared PROM code, not on one board part.
- Onyx4 hosts list the CG brick at xtalk/10 beside the IXbrick bridge at 15. Onyx 350 with InfiniteReality4 lists KTOWN2 at xtalk/10 and, on a second module, a video board at xtalk/12. The hub is therefore not 10 there.

Sources (public captures): the Onyx 350 graphics blade trace at just.graphica.com.au/tips/sgi-o350-chimera-notes/; the Tezro trace at forums.irixnet.org/thread-3613.html; the Origin 300 at forums.irixnet.org/thread-2737.html; the Fuel at forums.irixnet.org/thread-3238.html; hinv listings at just.graphica.com.au/tips/what-is-inside-that-box-sgi-hinv/ (quad Tezro, Onyx 350 with InfiniteReality4, NUMAlinked Onyx/Origin 350), wiki.preterhuman.net/SGI_Onyx4, forums.irixnet.org/thread-2263.html (Artemis) and nekonomicon.irixnet.org/forum/14/16728909/1.html (32-CPU Onyx4).

**Verdict.** Onyx4 host: not 10; **inferred 0xb**, because the PROM only anticipates 10 or 11 and the only IP53 id seen with a graphics widget at 10 is 0xb. Plain Origin 350: **unknown, inferred 0xb** by the same module layout (an IRIXnet poster describes the Onyx4 expansion module as the same as an Origin 350 module with a different front plate). Both stay inferred until a verbose PROM trace or a read of `II_WCR` exists. The Tezro stays 10.

Console strings that would settle it. `hinv` paths and the kernel messages need IRIX; the rest need the PROM: IRIX `hinv -vm` paths `/hw/module/<m>/<brick>/xtalk/<N>` (a device's own widget); 6.5.30 kernel (`kernel.o`) "hub widget %d, skipping xbow graph" and "Hub nasid %d got a PIO Write error from widget %d, cleaning up and continuing" (they print the hub's own id when they fire; trigger not traced); PROM `hubii_link_good: %c-brick attached to module %M.` (`0x1fc852b8`, brick letter from L1: 4 Origin 300, 8 graphics blade, 9 Tezro, A Fuel; `'7'` expected for Origin 350 and Onyx4); POD command `dgxbow` (`XBow Diagnostic`) and POD memory reads of `II_WCR` through the node alias.

## Not settled

| Item | Route |
| --- | --- |
| What fixes `II_WCR[3:0]` in hardware (strap, L1, reset write) | a read of the register on the Origin 350 or Onyx 350 before and after PROM start, or the Bedrock pin description; only James's hardware can give the first |
| The widget id of a real Origin 350 or Onyx4 host | a verbose PROM trace (`debug 0x10d`) or the register read; `hinv` alone gives only the other widgets (section 4) |
| Whether the crossbar branch for part `0xd000`/`0xd100` is the Bedrock's internal crossbar | the register page of the XB block |
| Who uses the class from `0x1fc68ba0` | its callers (`0x1fc694e4`, `0x1fc0f7d4` and others) |
