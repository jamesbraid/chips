# SGI Visual Workstation 320 and 540: open questions

Open points from the Cobalt, Lithium and platform pages ([platform](../platforms/visws/README.md),
[Cobalt](../devices/cobalt/README.md), [Lithium](../devices/lithium/README.md)). The only register-level source held is
the public Linux platform code; no BIOS image, NT driver or chip specification is held ([sources](../references/visws-sources.md)).
Each entry: question, routes tried, next route.

## Which Lithium bridge is bus 0

[missing source] Linux 2.6 takes bridge B's bus-number word as the PIIX4's bus and bridge A's as the other; the 2.4
scan reads only bridge B's word and scans bus 0 and that bus. An SGI engineer's post says "the second PCI bus,
normally bus one". Routes tried: all Linux versions read in full; no boot log with the printed bus numbers found in the
held news and mail archives. The NT HAL addresses bridge B's window first and numbers each bus from its bus handler, so it is consistent with B as the PIIX4's bus but never states which number a bridge holds ([nt-hal.md](../software/visws/nt-hal.md)). Next: a boot log from a real machine.

## Cobalt timer pending bit

[missing source] Linux 2.2 and 2.4 clear the timer interrupt pending bit on every tick; 2.5 to 3.14 never do. Either the
pending bit self-clears or the later kernels never ran correctly. Routes tried: read the start-up and interrupt code of
every version. Next: a real machine, or the NT HAL's timer routine.

## Cobalt interrupt controller: in-service tracking, reset state, identification field

[missing source] Whether the controller keeps a per-line in-service state, whether it is enabled at reset, and where the
identification field of its id word lies. Linux's mask-before-EOI and enable-once sequence hides all three. Next: PROM or HAL,
or a boot log (the kernel prints the id word before and after enabling).

## Board type probe cannot return the 540's value

[missing source] The type expression masks the byte at port `0xfb2` with the port number, so after the shift the result can
never be 1; the 540 branch is unreachable as written (inferred from the text, same in 2.2 and 3.14). Next: a boot log
from a 540, or the PROM's own board-id use.

## PCI interrupt map for Lithium bridge B

[missing source] The 2.6 map sends bridge B's shared pins to lines 4 to 9 (the base of bridge A), with duplicate lines, and
leaves lines 13 to 15 unused; the 2.4 map is not in any tree held. Which pins really reach which Cobalt lines is unknown. Next: the NT HAL's
interrupt table; a card in a bus-B slot on a real machine, if any exist.

## Memory controller and frame buffer placement

[missing source] No code programs the memory controller. The frame buffer's position is computed by the kernel with mixed
units (bytes and kilobytes); where the frame buffer really is, how banks decode and ECC is reported are unknown. Next: PROM,
the Cobalt graphics driver, the specification.

## 320 revision 5 legacy interrupts in 2.6

[missing source] The 2.2 kernel disables the Super I/O's UART 1 interrupt on 320 revision 5, whose legacy devices reach
Cobalt directly; the 2.6 code drops that and the direct wiring. How revision 5 works in 2.6 is unknown. Next: a rev 5
machine running 2.6, or the 2.4 code for that board.

## Lithium: errors, type 1 decode across two bridges, the rest of the audio register file

[missing source] No code reads an error register; how configuration cycles pick a bridge, what the bridges decode for
memory and I/O, and the undocumented audio words are unknown. Next: PROM, HAL, the Lithium specification, the NT audio driver.

## Processor table producer

[missing source] The kernel reads a processor count and table at low physical memory that firmware leaves; nothing says
what writes them or when. Next: a PROM or the boot loader (also unknown, the memory-size field comes from it).
