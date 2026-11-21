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

## 4. Consequences for the Origin 350 and the Onyx4 host

- Both are L1 type `'7'` (class 1). The brick type does not select the port, so there is no PROM-side table row to add for `'7'`.
- The host id must be a model answer for `II_WCR[3:0]`. For an Onyx4 host with a G2 at widget 10 the id has to be **not** 10 (the Voyager finding); 11 is the other value the code anticipates (inferred; no trace of an Onyx4 host exists).
- For the plain Origin 350 the id does not matter to graphics, but the PROM expects 10 or 11 (any other id makes it check port 10 as the peer), so a model value outside 10 and 11 would take an untested branch.

## Not settled

| Item | Route |
| --- | --- |
| What fixes `II_WCR[3:0]` in hardware (strap, L1, reset write) | a read of the register on the Origin 350 or Onyx 350 before and after PROM start, or the Bedrock pin description; only James's hardware can give the first |
| The widget id of a real Origin 350 or Onyx4 host | the same register read, or a `hinv -v` of the module listing the node's widget |
| Whether the crossbar branch for part `0xd000`/`0xd100` is the Bedrock's internal crossbar | the register page of the XB block |
| Who uses the class from `0x1fc68ba0` | its callers (`0x1fc694e4`, `0x1fc0f7d4` and others) |
