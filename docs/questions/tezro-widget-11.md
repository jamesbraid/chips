# Tezro: how the PROM discovers the second PIC at widget 0xb

Question. On a Tezro (IP53 node board, IP35 platform, PROM 6.210) the PROM and the operating system report two
PIC bridges, at crosstalk widgets 0xb and 0xf. Public inventories list the same interface board at widgets 11
and 15. What does the shipped PROM read to learn that widget 0xb exists, what must those registers return, and
which crossbar is it behind?

Method: static reading of the shipped IP35 PROM image (SGI Version 6.210, built Aug 26 2004, SHA-256
d74b4b7ef9c11c66692019db9af698104595be7a0573a86feae8a83441921318, container segment loaded at
0xc00000001fc00000; addresses below are the payload offset, the image minus its first 4096-byte header, plus 0x1fc00000) and of the shipped IP35 kernel crossbar
attach object. Nothing was run. Corroboration from one public deskside Tezro verbose PROM capture (a forum post
titled "Tezro IO9/Configuration Oddities") and public Tezro hinv captures that list the interface board at
xtalk/11 and xtalk/15.

## Answer

1. **Established.** Discovery goes through the crossbar at widget 0 of the node's XIO port, not through the
   Bedrock's internal crossbar. The PROM first reads the Bedrock I/O interface link control and status register
   (local offset 0x400128) and continues only if bit 13 (up) and bit 10 (enabled) are both set (routine at
   0x1fc66b08, tests at 0x1fc66b9c and 0x1fc66ba8). It then reads the 32-bit identity word of widget 0 (offset 4).
   Parts 0, 0xd000 and 0xd100 send it down the crossbar path (0x1fc66c48, bring-up at 0x1fc4c5e4); parts 0xc002
   and 0xd002 mean a bridge directly at widget 0 and no walk. The public capture runs the crossbar diagnostic at base 0x9200000000000000, whose identity check accepts only
   parts 0, 0xd000 and 0xd100, so widget 0 of a deskside Tezro is crossbar-class (established). Which of the
   three is **unknown**.
2. **Established.** The per-link test is the same in the PROM (0x1fc4f3ec) and in the kernel's crossbar attach
   (a widget-present helper and a link-alive helper). For link n = 8..15 it reads the register block at
   0x100 + (n-8)*0x40 on widget 0: link status at +0x14 bit 31 (alive) and link auxiliary status at +0x3c bit 5
   (widget present). A link is usable when both are set. Exception, PROM: if widget 0's part is 0xd100, link 0xf
   is usable regardless of the two bits (they are read and ignored; manufacturer is not tested). Exception,
   kernel: only the present bit is waived, and only for part 0xd100 with manufacturer 0 on link 0xf; link alive
   (status bit 31) is still required. A link with
   present set and alive clear prints a "widget present, but link not alive" warning and is skipped. For link 0xb
   the words read are at 0x1d4 and 0x1fc.
3. **Established** (public capture). The Bedrock itself is crossbar port 0xa ("HUB at 0x0 attached as widget
   0xa", "Check_master: link 10 is master"). The PICs are ports 0xb and 0xf. The capture runs the bridge
   diagnostic at base 0x920000000b000000 and then 0x920000000f000000, so the PROM treats widget 0xb as a bridge.
4. **Established.** For each usable non-hub link the PROM reads the widget's identity word at window offset 4
   (widget n at n<<24), and for bridge-class parts (0xc002, 0xd002, 0xd102, 0xd112) runs the link reset routine
   (0x1fc4bd30): read the link's status-clearing register (+0x2c), write link control (+0x0c) 0x00080000, write
   the two arbitration registers (+0x1c, +0x24) zero, then poll link status bit 31 up to 100 times. It then writes
   the widget credit field (control bits 22:18) from a per-part table and the target widget's own control word at
   +0x24 (and +0x800024 for a PIC part). The bridge diagnostic requires identity bit 0 set and one of the four
   bridge-class parts (0x1fc421a0 to 0x1fc4222c). The credit comes from a table of 16-byte entries at 0x1fd63ad8 (part, credit, mask, shift): part 0xd102 has
   credit 3 (established). The +0x800024 write happens only for part 0xd102 exactly; 0xd112, 0xd002 and 0xc002
   get none. Bit 0 of a link's arbitration-upper register (+0x1c) is the PROM's "already claimed" marker: if it
   is set before probing, the identity read and the whole bridge path for that link are skipped (0x1fc4c6f4 via
   0x1fc4bdd4), so it must read 0 at reset (established).
5. **Inferred.** The second PIC is one more link (port 0xb) on the same widget-0 crossbar, with link status bit
   31 and auxiliary bit 5 set at PROM time and a bridge-class identity (0xd102 most likely) at widget 0xb. Discovery
   (0x1fc66b08, 0x1fc66c48, 0x1fc4c5e4) reads no Bedrock internal crossbar register. The image does read them
   elsewhere: a hub error collector at 0x1fc631a4 to 0x1fc631ac loads the crossbar first-error register
   (offset 0x700090), reached from 0x1fc0b7b0 and 0x1fc67b5c. Scan method: linear disassembly of the payload,
   lui immediates 0x70..0x7f, 0x1f0..0x1f7 and 0x40..0x4f, each hit read by hand.
6. **Unknown.** Widget 0's part on a Tezro; the exact part at widget 0xb; whether the second PIC has its own
   crossbar in front of it; link 0xb auxiliary bits other than bit 5; whether the PROM's explicit link 0xa/0xb handling (0x1fc4d65c, called
   from 0x1fc4def0, which writes the register value or'ed with 5 or 9 into arbitration-upper registers in some
   topologies) runs on a Tezro; which register the inventory reader uses
   to name the board at widget 0xb. The PROM's discovery does not depend on the last three.

What would settle the unknowns: one 32-bit read each of 0x9200000000000004 (widget 0 identity) and
0x920000000b000004 (widget 0xb identity) from the PROM monitor on a Tezro, plus reads of link 0xb's status,
auxiliary and arbitration words (0x1d4, 0x1fc, 0x1dc). A public capture that prints widget 0's revision would
also settle the first.
