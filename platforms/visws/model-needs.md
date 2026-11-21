# What an emulator needs to boot Linux on a Visual Workstation

A list drawn from what the Linux platform code touches ([boot-and-detection.md](boot-and-detection.md),
[interrupts.md](interrupts.md), [cobalt](../../devices/cobalt/README.md), [lithium](../../devices/lithium/README.md)).
It is the minimum that Linux 2.6.33 to 3.14 reads and writes, so a model that supplies it can be tested against that
code. It is **not** a hardware specification and carries no claim that a real machine's firmware, NT or other software
needs only this. Nothing here has been run: no model was built or booted for this list.

## Boot with the stock PC-style entry (what Linux needs)

1. **A kernel loaded by a PC-compatible boot path** with a boot parameter block that holds the memory size in the
   alternate-memory field. There is no firmware memory map; the kernel makes one. The loader the real machine used
   is unknown.
2. **The processor table**: a 16-bit count at physical `0x1e00` and MP-table processor entries from `0x1e02`, the first marked
   as the boot processor and enabled. Local APIC at `0xfee00000`, version non-zero.
3. **Board identification**: port `0xfb2` returning a byte with bits 4, 5 and 7 clear (reads as board type 0, the 320);
   Super I/O at `0x2e`/`0x2f` with logical devices 7 and 8 and their enable and base registers, a GPIO byte at `0xfc0`
   (value below 6 for revision 4, 6 to 11 for 5, 12 or more for 6), a Super I/O power-management index/data pair at
   `0xfc8`/`0xfc9` accepting the enable write. To get the 320 revision 6 path use a GPIO value of 12 or more.
4. **Lithium bridge windows** at `0xfc000000` and `0xfd000000`: vendor `0x10a9` and device `0x1002` readable as 16-bit words at
   offsets 0 and 2; the bus-number word at `0x44` (low byte: the bus the kernel scans) and interrupt-enable word at `0x46`,
   accessed as 16-bit.
5. **PCI type 1 configuration** through `0xcf8` and `0xcfc` reaching two root buses with the bus numbers the bridge
   windows report; the kernel scans each. Bus B holds the PIIX4 at device 4 (IDE, USB, power management and the ISA
   bridge function); bus A holds an Ethernet device at device 3 (an Intel 82557 in the 2.4 configuration, driver in
   port I/O mode; the generic network configuration selects PIO for this machine).
6. **Cobalt**: CPU block at `0xc2000000` (revision, control, status, time value) and the interrupt controller at `0xc4000000`
   (thirty entries, enable in the identification word at `0xffc`). The timer fires a level interrupt on line 28 every
   `time value / 100 MHz` seconds; the kernel then sees irq 0 at vector `0x20`. To satisfy 2.2/2.4, clear the pending
   bit on a status write of 0; to satisfy 2.5 and later also drop the line when the mask bit is set or when the local APIC is
   acknowledged, because those kernels never clear the status ([cobalt](../../devices/cobalt/README.md)).
7. **PIIX4 and Super I/O** as an ordinary PC would have them: the 8259 pair with poll mode and specific EOI, output
   to Cobalt line 12; IDE on lines 4 (320 rev 5: 5) and 2; USB on line 7; the 87307's serial, floppy and parallel on
   the 8259. Reset control at `0xcf9` (write 6 restarts); power-management status, enable and control words at `0xf80`,
   `0xf82` and `0xf84` (a write of `0x2000` to control is the sleep request) plus the stop-grant special cycle at
   `0xcfc`.
8. **Local APIC** per processor, with the usual IPIs, timers not used by the boot processor's tick.
9. **Memory** reserved: the top 8 MB the kernel marks as the frame buffer need only be ordinary RAM for a text console.

## What can be left out for a text-console boot

The 3D engine, video in and out, the audio engine (nothing probes it unless the sound driver is loaded), Arsenic, and
every register the kernel never touches. A kernel configured for this platform also boots on an ordinary PC
(2.6.24 and later), so it will not check chip identities except the two Lithium words (2.6.33 and later only log
a mismatch).

## Risks that a model inherits

- The board type expression cannot return 1; do not model a 540 on the assumption that Linux detects it ([boot and detection](boot-and-detection.md)).
- The PCI interrupt map for bus B is inconsistent; test Ethernet on bus A with the usual line 3, the PIIX4 USB on line 7,
  IDE on line 4.
- The timer acknowledge differs between kernel generations.
- Which bus is bus 0 is unconfirmed.

Everything the unknown tables in the linked pages list stays unknown; the emulator's choice for each is a model decision,
not a hardware fact, until a PROM image, an NT HAL or a real boot log is read.
