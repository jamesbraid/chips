# Visual Workstation: detection, board revision, processors, memory, reboot and power-off

What the Linux platform code does at start-up and shutdown, in the order it does it, and what the hardware has to answer.
Source and grading as on the [platform page](README.md); all of it is Linux's behaviour (a software expectation of Linux, not of the shipped system; see [Sources by origin](README.md#sources-by-origin)) unless a
line says otherwise. "2.2" is the first form of the code, "2.6" the later one.

## 1. Board type and revision

1. **Type.** The kernel reads one byte from I/O port `0xfb2` (the PIIX4 power-management block at `0xf80`, plus `0x30`,
   plus 2: general-purpose input byte 2), masks it, shifts it right by 2, and treats the result as the board type: 0 is
   the 320 and 1 the 540. The four board id inputs are the PIIX4's general-purpose inputs 18 to 21, which are bits 2 to 5
   of that byte. The firmware must already have enabled the PIIX4 power-management block at `0xf80`.
   **A defect in the expression (inferred from reading it):** the mask is the port number `0xfb2`, not the four-bit board id
   mask the header defines next to it. As written only bits 1, 4, 5 and 7 of the byte survive, so after the shift the
   result can never be 1. So on a real 540 the kernel would report the type as unknown and a negative result (bit 7
   set) is treated as "not a Visual Workstation". The same text is in 2.2 and 3.14. Whether the machines' bit patterns made it
   work (the 540's id may differ) is unknown. An emulator that wants Linux to see a 320 returns a byte whose bits 4, 5 and 7
   are zero; for a 540 no value gives 1.
2. **Super I/O set-up for the GPIO block.** On the NS87307 at index `0x2e`, data `0x2f`: select logical device 7 (GPIO)
   by writing `0x07` to the index then 7 to data; write the base address `0x0fc0` into registers `0x60` and `0x61` (high
   and low byte), enable the device with register `0x30` set to 1. Then select logical device 8 (power management),
   base `0x0fc8` the same way, enable it. Then write register 1 of the power-management block (index port `0x0fc8`) with
   bit 7 set, "which enables access to the GPIO registers" (the comment's words).
3. **Revision.** Read the byte at `0x0fc0`, keep seven bits. For a 320: below 6 is revision 4, below 12 revision 5,
   otherwise 6. For a 540 the revision is always 2. For anything else the revision is the raw value. The kernel
   prints "Silicon Graphics Visual Workstation 320 (rev N) detected".

The **board revision** matters afterwards in two places: the 2.2 interrupt wiring tables (below) and the 320 revision 5 IDE
interrupt line in 2.6 ([interrupts.md](interrupts.md)).

**Required by this section:** a PIIX4 power-management block at `0xf80` with general-purpose input byte 2 at `0xfb2`; a
Super I/O at `0x2e`/`0x2f` that accepts the logical-device writes above; a GPIO byte at `0xfc0` and a power-management
index/data pair at `0xfc8`/`0xfc9`.

## 2. Processors and the "MP table"

The machine is Intel MP compliant "in the hardware sense, but it doesn't have a BIOS configuration table"
(the kernel's comment). Instead the kernel reads, from physical memory, a 16-bit processor count at `0x1e00` and that
many standard MP-table processor entries from `0x1e02` (twenty bytes each: type, local APIC id, local APIC version, flags,
signature, feature flags). It caps the count at 4. Per entry it keeps only those with the enabled flag, takes the
boot-processor flag as the boot CPU, rejects an APIC id of 15 or above (or 255 and above when the version is 0x14 or
more), and substitutes version `0x10` if the version is 0. The local APIC address is the Intel default `0xfee00000`.
It writes no IO-APIC configuration and **skips IO-APIC set-up entirely**; interrupts go through Cobalt. Who fills in the
table and the count (the PROM, the boot loader) is unknown. The kernel also warns when the count is above 4.

SMP start-up is the stock one: the warm-reset vector is written through the CMOS shutdown byte (`0x0f` set to `0x0a`) and the
BIOS trampoline words, then the usual inter-processor interrupt sequence (stock x86 code; the visws hooks do nothing
else). Broadcast inter-processor interrupts are not used. No VISWS-specific bring-up of processors beyond the table is
in the code, so the second processor's start follows from the table and the local APICs working normally.

## 3. Memory

- The loader supplies the memory size (the kernel reads the BIOS-style "alternate memory size" field of the boot
  parameters). If it is zero the kernel warns that the "Bootloader didn't set memory size, upgrade it" and assumes 128 MB.
  So there is a purpose-written boot loader on the machine, whose name and format we do not know.
- The kernel reserves the top 8 MB (default; hard-coded unless the framebuffer driver sets another size, rounded down to
  1 MB) as the frame buffer and marks it reserved in the memory map. The memory map is built by the kernel itself, with
  no firmware map: RAM from 0 up to the low-memory limit, then RAM from the 1 MB mark up to the frame buffer, then the
  reserved block. It labels the map source "PROM". In 2.6 the same value is used as both a byte count and a kilobyte count in
  one place (the frame buffer's start is computed as size minus 8 MB with the size in kilobytes). That is a kernel quirk and
  is not a hardware fact: nothing here says where the frame buffer really sits (it is the "top 8 MB" only as far as
  the kernel's own arithmetic goes).
- The kernel never programs a memory controller register.

## 4. Fixed mappings and start-up order (2.6)

At trap-initialisation time the kernel:

1. maps the Lithium bridge windows (`0xfc000000`, `0xfd000000`) and reads the vendor and device words of each (they should be
   `0x10a9`, `0x1002`); a mismatch is a panic in 2.6.20 ("This machine is not SGI Visual Workstation 320/540"), only logged
   in 2.6.33 and later, and not checked in 2.2;
2. writes the interrupt enable word of each bridge ([lithium](../../devices/lithium/README.md));
3. maps and sets up the boot processor's local APIC at `0xfee00000`, reads its version and id;
4. maps the Cobalt CPU block and interrupt controller, prints the Cobalt revision and the controller's id, and sets the
   interrupt controller's enable bit without changing the id.

At time initialisation: load the Cobalt timer, start it and unmask it ([cobalt](../../devices/cobalt/README.md)).

## 5. Reboot and power off

- **Restart:** write the value 6 to I/O port `0xcf9` (the PIIX4 reset control: reset the processor and the whole system).
  No other action. The comment says "Visual Workstations restart after this register is poked on the PIIX4".
- **Power off:** (a) while the power-management status word at `0xf80` has its bit 8 (power button) set, write the value
  back to clear it; (b) write `0x2000` (the suspend-enable bit) to the control word at `0xf84`; (c) wait 10 ms; (d) in
  2.6.20 and earlier, write a PCI type 1 configuration address to port `0xcf8` for the PIIX4's bus, the device and function
  value `0xff` (device 31, function 7) and register 0 (the combination that makes a host bridge generate a special cycle), then write the stop-grant
  special cycle data `0x00120002` to `0xcfc`. In 2.6.33 and later the address write is commented out, so the data goes to
  whatever address the last configuration access left. The comment says the PIIX4 "insists on seeing" the stop grant
  special cycle "before it will power down a system".
  So power-off needs a PIIX4 that sleeps on that control write, and a host bridge that turns a special cycle into a PCI
  special cycle seen by the PIIX4. Whether an emulator may power off on the control write alone is a model choice: it
  is enough to satisfy both kernels.
- **Halt:** the kernel does nothing.

## Unknown

| Unknown | Route |
|---|---|
| What fills in the processor table and count, and when | A PROM image or the NT boot files |
| What the boot loader passes (its parameter block, the memory size's units) | The loader; a kernel boot log from a real machine |
| The board id bit patterns for the 540 and the other revisions | A boot log from a 540; the PROM |
| Reset state of the Super I/O and PIIX4 as the firmware leaves them | PROM |
| The firmware's memory map above the kernel's view | PROM |
