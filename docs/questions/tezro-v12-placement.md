# Tezro: where the V12 sits, and what differs on the one-processor board

Question. On a Tezro workstation (IP53 node board, IP35 platform, PROM 6.210), which crossbar widget does the V12
graphics board take, how is it reached, what do the PROM and the operating system read for it, and does a
one-processor board differ from the two- and four-processor boards?

Method: the SGI Tezro tower hardware user's guide (document 007-4564-001, printed pp. 26, 29-30, 38, 43, 81, 88);
a set of published `hinv` and `gfxinfo` captures (2,939 store entries searched); static reading of the shipped IP35
PROM image (SGI Version 6.210, built Aug 26 2004, SHA-256 d74b4b7ef9c11c66692019db9af698104595be7a0573a86feae8a83441921318;
addresses are the payload offset after the 4096-byte header plus 0x1fc00000); and one public deskside Tezro verbose
PROM capture (forum post "Tezro IO9/Configuration Oddities", July 2022). Nothing was run.

## Captures

Thirteen captures that list the interface board (name WS_INT_53, assembly 030-1881-006 or -007) report data: eight
four-processor IP53 nodes, three two-processor IP53 nodes, two four-processor IP59 nodes. All thirteen list that
board at widgets 11 and 15 and the graphics board at widget 12 (twelve V12, one V10). Two list a digital-video
board (XT-DIGVID, 030-1927-003) at widget 13. Six carry a `gfxinfo` capture: all report an ODYSSEY board with
128 MB, five BUZZ B.2 and one B.1. No capture in the store has a one-processor node board (no IP53_1CPU or
IP59_1CPU name anywhere).

## Answer

1. **Established.** The guide puts the XIO slots on the interface board. The node board attaches to the interface
   board by two connectors. The two- and four-processor interface board has two XIO slots (VPro graphics, one
   optional XIO board) and eight PCI-X slots in four buses; the one-processor one has one XIO slot and four PCI-X
   slots in two buses. Optional XIO boards are supported only on two- and four-processor workstations, and a
   one-processor workstation cannot take a larger node board.
2. **Established** (13 of 13 captures). On two- and four-processor boards the V12 is at widget 12; the optional
   digital-video board, when fitted, is at widget 13 (2 captures).
3. **Inferred.** Widget numbers equal crossbar port numbers, so the V12 is port 12 and the optional board port 13,
   next to the PICs at ports 11 and 15 and the hub at port 10. The PROM reaches a graphics board only through the
   widget-0 crossbar's per-link status (offsets 0x214 and 0x23c for link 12) and then reads the board's identity at
   its own widget window; the PIC bridge at widget 15 is not on that path. Established for the PROM paths read
   (walk 0x1fc4b17c, graphics attach 0x1fc4ab14, board creation 0x1fc44d7c); the physical location of the
   crossbar (inside the widget-15 PIC or separate) is **unknown**.
4. **Established.** For identity part 0xc013 the PROM's graphics path assigns board type 0x54, reads a
   manufacturing-ID location at widget offset +0x10d8 (role inferred from the surrounding calls) and writes the
   widget control word at +0x24. Board creation stores the widget number and tests none. No branch on processor
   count was found in the walk or the graphics path; the only count-dependent datum is a six-entry node-board
   name table (IP53 and IP59 by 4, 2 and 1 CPU, masks 0xf, 0x5, 0x1 at 0x1fc8a970 to 0x1fc8a9c0) whose users were
   not traced (inferred: no effect on graphics).
5. **Established** (one four-processor capture). The PROM prints, after loading the base-I/O PROM: "Graphics
   diagnostics", "Odyssey board #0 found on nasid 0", "Running Odyssey xtalk sanity diag...", a register dump
   (request timeout 0x000fffff, interrupt destination zero, FLCTL_CONFIG 0x0001c000), "Board version 1 - Buzz
   revision 3B", SDRAM 128 Mb, CAS 3, four banks, and "Device passed diagnostics"; later "graphics install:
   searching for pipe 0". The same capture prints "Found PIC at 0x920000000b000000" and "...0f000000": the PROM
   prints that name only for part 0xd102 or 0xd112 with manufacturer 0x24 (0x1fc4b748 to 0x1fc4b778), so widget 0xb is
   a PIC (established).
6. **Inferred.** The one-processor board has two PCI buses, which fit one PIC (two heads); the four-bus board
   needs two. So a one-processor board likely has only the widget-15 PIC, no widget 11. On the larger board
   widget 15 carries bus indexes 0 and 1 in the captures, leaving buses 3 and 4 to widget 11.
7. **Established** for two- and four-processor boards: the graphics assembly does not follow the node board.
   ODY128B1_2 030-1884-002 (rev D) is on one two- and three four-processor nodes; 030-1884-005 (rev B) on two
   two-, two four- and two IP59 nodes; older names (ASTODY 030-1726-004 and -006, ASTODYV10 030-1826-003) on three
   four-processor captures. Interface board assemblies -006 and -007 both appear on two- and four-processor boards.
8. **Unknown.** The one-processor widget (12 is likely, by elimination: the only slot must be the VPro slot), its
   PROM text, its interface-board assembly, and whether the manufacturing-ID data behind the graphics board differ by
   board.

What would settle the unknowns: one capture from any one-processor Tezro with VPro (`hinv -mv`, `gfxinfo -vv`, a
verbose PROM boot showing the "Found PIC" and Odyssey lines); and one 32-bit read each of widget 0's identity word
(0x9200000000000004) and link 12's status and auxiliary words from the PROM monitor on a Tezro.
