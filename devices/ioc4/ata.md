# IOC4 ATA channel: registers, DMA engine, interrupts, and who drives them

The ATA/ATAPI channel of the IOC4 as three software consumers use it: the SLES 9 SP3 ia64 kernel (2.6.5-7.244) and its
installer, the later public Linux drivers, and the SHub 1 PROM's EFI. It adds to the chip page ([README.md](README.md)),
which reads the IRIX `ide.o` path, and to [linux-driver-notes.md](linux-driver-notes.md) and [coverage.md](coverage.md);
those pages hold the register-field names. Labels are the repository's: **established**, **inferred**, **unknown**
([AGENTS.md](../../AGENTS.md)). A driver shows what software expects, never what the silicon does for other inputs.

Sources, all read for this page:

- Linux 2.6.5 `drivers/ide/pci/sgiioc4.c` and `include/asm-ia64/sn/ioc4.h` (Linux history tree, tag `v2.6.5`).
  The 2.6.5 tree has no IOC4 core driver and no IOC4 serial driver.
- Linux 2.6.33-era `drivers/ide/sgiioc4.c` (same root, merge `981a2edd1922`) and the Linux 7.3 IA-64 tree's
  `drivers/ata/pata_sgiioc4.c`, `drivers/misc/ioc4.c`, `include/linux/ioc4.h` (a local mirror of a 7.3 IA-64 port).
- The SLES 9 SP3 ia64 CD 1 (`SU90SP3.P01`): the boot image's installer ramdisk, with its `linuxrc`, `modules.pcimap` and the
  modules `ioc4.ko`, `sgiioc4.ko` (vermagic `2.6.5-7.244-default`), read with `strings` and a Ghidra export; and the held SN2
  kernel `config` for 2.6.5-7.244. The kernel module bodies were decompiled, so the readings below are of shipped code.
- The PROM's EFI component (SHub 1 snprom 10.54, `shub1snprom.bin` sha256 `51ccf9ad...`, EFI ELF as in
  [efi.md](../../software/firmware/snprom/efi.md)), the `Ioc4AtapiScsiPassThru*` functions `0x158450` to `0x15b730` in the
  Ghidra-export address space (ELF address plus `0x100000`).
- External URL read: `https://raw.githubusercontent.com/openSUSE/linuxrc/master/auto2.c` (current linuxrc, not the SLES 9
  era; it settled nothing, see the installer section).

## 1. Identity and BAR layout

| Item | Value | Grade |
|---|---|---|
| PCI id, class | vendor `0x10a9`, device `0x100a`, class code `0x0b4000` (the 2.6.5 IDE driver's id table and `ioc4.ko`'s pci alias match on class `0x0b4000`, mask `0xffffff`) | established |
| Minimum revision | the 2.6.5 IDE driver and `sgiioc4.ko` refuse a revision below 46 ("firmware is obsolete"); the revision byte is the standard one at config offset 8 | established (driver), what a revision means in silicon unknown |
| PROM check | the EFI driver reads the first 64 bytes of configuration space as dwords and compares vendor and device only; it prints the revision byte and never tests it | established |
| ATA registers live in | BAR 0, memory space (EFI uses the PCI-IO memory accessors with BAR index 0; Linux uses `pci_resource_start(dev, 0)` plus the offset) | established |
| BAR 0 contents | misc and interrupt block `0x0`-`0x5c`, ATA task file `0x100`, ATA control `0x120`, ATA DMA `0x140`-`0x160`, keyboard/mouse `0x200`, serial `0x300`-`0x3a0`, byte-bus device windows `0x80000`, `0xa0000`, `0xc0000`, `0xe0000` (the 2.6.5 SN header names the four byte-bus bases and says they are addressed through BAR 0) | established as offsets |
| BAR 0 size | at least `0x100000`: the highest byte-bus window ends at or after `0xe0000` plus its size. The IRIX attach maps only 928 bytes, which is a mapping length, not the BAR size. The PCI size mask is unread | inferred |
| Config-space writes at probe | `ioc4.ko` ORs `0x140` into the PCI command word (parity and system-error response), enables the device and bus master (inferred to add memory and master, `0x6`, giving `0x146`); the IDE error path writes `0x146` back to clear an error | `0x140` established from the module, the sum inferred |

## 2. ATA task-file registers

The IOC4 spaces the eight task-file registers one per 32-bit word, and the control block is another word. Software reads and
writes each as a byte at the word's base address (status, error, count, LBA bytes, device, command and control) and the data
register as a 16-bit access. The EFI driver's offset table (ELF `0x200880`, twelve halfwords) and the Linux 2.6.5
`sgiioc4_init_hwif_ports` (register `i` at `base + 4 * i`) give the same map.

| Offset | Read | Write | Notes | Grade |
|---|---|---|---|---|
| `0x100` | data | data | 16-bit accesses (EFI `Ioc4ReadPortW`/`WritePortW`) | established |
| `0x104` | error | features | EFI writes 0 to features before PACKET; reads error bit 2 (abort) when status ERR is set | established |
| `0x108` | sector count (interrupt reason for ATAPI) | same | not used by EFI | established as slot |
| `0x10c` | LBA low | same | not used by EFI | established as slot |
| `0x110` | LBA mid (ATAPI byte count low) | same | EFI writes `0xfe`, then reads the drive's count back | established |
| `0x114` | LBA high (ATAPI byte count high) | same | EFI writes `0xff` (limit `0xfffe`), reads the count back | established |
| `0x118` | device/head | device/head | `0xa0 | (target << 4)` selects master or slave | established |
| `0x11c` | status | command | the PACKET command is `0xa0`; DEVICE RESET `0x08` | established |
| `0x120` | alternate status | device control | `0x0a` (nIEN set) during EFI commands, `0x06` (SRST plus nIEN) then `0x02` for a channel reset | established |

- One channel only, master and slave on it. EFI offers targets 0 and 1 and LUN 0, nothing else.
- **Status read is also the interrupt acknowledge in software.** The 2.6.5 driver's byte-read hook, applied when the port low
  12 bits are `0x11c`, reads `other_ir` at `0x0c` (the port minus `0x110`) after a status read whose bits `0x51` (2.6.5-specific; the 3.2.78 IDE driver tests the busy bit instead) are not all
  clear; if bits 1:0 are set it writes 3 to `0x0c` and reads it back. The decompiled `sgiioc4_INB` in `sgiioc4.ko` has the same
  mask, offset and write. Whether the chip also clears the bit when the drive status is read is **unknown**: a model that
  clears nothing itself is consistent with every driver, because each acknowledges with the write.
- The IOC4-specific words are the DMA block (section 3) and the status words `0x0`-`0x1c` (section 4).

## 3. DMA engine

DMA block, word `n` at `0x140 + 4n`. Roles and bits: [coverage.md](coverage.md) and
[registers-extra.md](registers-extra.md); only the sequences are given here.

| Word | Offset | Role | Touched by | Grade |
|---|---|---|---|---|
| 0 | `0x140` | timing | nobody | unknown |
| 1, 2 | `0x144`, `0x148` | table address, low and high | low: Linux and SLES 9; high: IRIX packet path only | established |
| 3, 4 | `0x14c`, `0x150` | current memory address | nobody | unknown |
| 5, 6 | `0x154`, `0x158` | byte count at the device, at memory | read at completion | established |
| 7 | `0x15c` | control and status: bit 0 start, 1 stop, 2 direction, 3 active, 4 error | all drivers | established |
| 8 | `0x160` | bus address of the 128-byte ending area | all drivers | established |

**Table entry (established).** 16 bytes, four words stored in memory in big-endian order (the drivers store
`cpu_to_be32`, with the table allocated as consistent memory; byte order across the PIC is in
[README.md](README.md#ioc4-behind-a-pic-how-its-dma-bytes-are-numbered-public-linux)):

| Word | Content |
|---|---|
| 0 | zero |
| 1 | bus address, low 32 bits |
| 2 | zero (the high half of the address; no driver ever sets it, so 64-bit addressing is untested) |
| 3 | bit 31 end of list; bits 15:0 length; the driver's own comment calls bits 30:16 unused |

Entries never cross a 64 KiB boundary of the address (the drivers split there). The table holds one fourth of a page of
entries (`PAGE_SIZE / 64`; 256 on a 16 KiB page). A full 64 KiB entry is written as length 0 by the 2.6.5 driver (masked to
16 bits) and as `0x10000` by the later trees (bit 16 set, outside the field). Hardware use of the 7.3 port is not supported, so reading the field as
its low 16 bits with 0 meaning 64 KiB is consistent with both: **inferred**. A list without an end flag, an unaligned address,
and an entry longer than the drive transfers are **unknown**.

**Setup, as the SLES 9 module and 2.6.5 source do it (established).**
1. Read word 7. If active is set, or error is set, write stop (2) and poll word 7 until bit 1 reads clear (at most 200
   reads, 1 microsecond apart).
2. Write the table's bus address to word 1 (low half only), clear the 128-byte ending area, write its bus address to word 8,
   write the direction to word 7: `0x4` when the chip writes memory (a disk read), `0` when it reads memory.
3. Send the drive command (for ATAPI, the PACKET command and its twelve-byte packet over the data register).
4. Start: read word 7, OR in bit 0, write it back. (The IRIX packet path writes 1, or 5 for the memory-write direction, in
   one store after writing words 1, 2 and 8.)

**Completion (established).** The driver writes stop to word 7 and polls bit 1 clear. It then reads the sixteen 8-byte
words of the ending area for up to 200 microseconds until any is nonzero: the chip writes ones there once its last data write
has reached memory, because a register read can overtake a DMA write on an Altix. The driver then reads words 5 and 6 and,
only when either has a low-nine-bit remainder and the device count exceeds the memory count by more than 8, logs a warning.
It tests nothing else: no status byte and no word-3/4 value. Failures it reports: stop bit still set, ending area still
zero, mismatched counts. An error latched by the chip (word 7 bit 4, `other_ir` bit 1) is found at the next start or in
the interrupt path.

A model therefore needs: the table walk with the end bit; the ending-area write of nonzero data when stop is accepted, after the
last data write; counters in words 5 and 6; the error bit with the address latch (section 4); and nothing for words 0, 3
and 4. **Unknown:** the endpoint of the 64-bit address (word 2 non-zero); the timing; whether stop on an idle engine writes the
ending area; the reset value of any word.

**DMA use by software.** The 2.6.5 and SLES 9 IDE driver allows DMA for ATAPI (multiword DMA mode 2, set with SET FEATURES from
the check routine) and for disks. The 7.3 port forces everything to PIO, with a comment that the chip does not reliably
raise an interrupt at ATAPI DRQ under libata; that is the port author's statement, unmeasured here. The EFI driver never uses
DMA.

## 4. Interrupts

| Register | Offset | ATA-relevant bits | Grade |
|---|---|---|---|
| error address low, high | `0x0`, `0x4` | latched on a DMA error: bit 0 valid, bits 4:1 master id, bit 5 more than one error; master id 8 is the ATA engine in the 7.3 header | established (Linux); the IRIX debug test compares `(low & 0x1e) == 8`, a mismatch with id 8 that only selects a message ([README.md](README.md)) |
| other status | `0xc` | bit 0 drive interrupt pass-through, bit 1 DMA PCI error; written 1 to clear | established |
| other enable set, clear | `0x14`, `0x1c` | writing 3 to `0x14` enables both; all drivers do it at attach | established |
| serial status | `0x8` | none: the ATA bits are not in the serial word | established |

- At attach, the SLES 9 `ioc4.ko` writes all ones to `0x1c`, `0x18`, `0xc` and `0x8` (both enable-clears, both statuses), then
  the IDE submodule writes 3 to `0x14`. These four stores and the enable-set are the whole interrupt set-up (Ghidra
  export of `ioc4_probe` and `ioc4_ide_attach_one`).
- The ATA bit 0 follows the drive's interrupt request. The drive's own nIEN bit in the device control register gates the
  request. A driver sees the line when `(other_ir & other_ies)` has a bit set.
- The error path in Linux: read `0x0` and `0x4`, read the PCI command, log, write `0x146` to the PCI command, write 3 to
  `0xc`.
- **Sharing.** The IOC4 has one PCI interrupt pin. ATA, the four serial ports (serial word and error bits 5:2 of the other
  word), keyboard/mouse (bit 6) and the INT_OUT latch (bit 23) all raise it. The 7.3 port requests the line shared and tests
  `other_ir & 3`. The SLES 9 2.6.5 kernel has no IOC4 serial driver, so ATA is the only consumer of the line there
  (the held `config` has no IOC4 serial option; the SN2 kernel serial is the L1/SNSC console).
- **Route to the CPU.** IOC4 INTx, then a PIC interrupt pin, then an interrupt packet to the SHub II interrupt register, then
  a CPU vector ([PIC README](../pic/README.md#interrupt-packets-edge-only-delivery-recovery-by-software),
  [SHub interrupts](../shub/interrupts.md#where-a-pic-interrupt-lands-on-shub-1)). Which PIC pin the IOC4's
  INTA uses and what the interrupt-device register (`0x120` in the PIC) maps to it is chosen by the PROM and passed to
  the kernel in its per-device interrupt record (the SN2 kernel's own comment says the pin is "set up by prom"): **unknown** for
  the Altix 350, no SAL_B reading of it yet. Route that settles it: the SAL PCI-slot and device-info calls the kernel uses
  (see [the base I/O page](../../platforms/sn2/altix-350-base-io.md)).
- PIC delivery is edge-style; Linux recovers a missed interrupt with a forced interrupt after dispatch. A model should keep the
  IOC4 interrupt level asserted while `other_ir & other_ies` is nonzero.

## 5. ATAPI path (CD)

All established from the EFI driver and the 2.6.5 IDE core's generic ATAPI behaviour (no IOC4 special case beyond the register
spacing).

1. EFI waits for BSY and DRQ clear (status mask `0x88`), polling the status register at 30 microsecond steps; if ERR is set
   with BSY clear it reads the error register and gives up when abort is set.
2. Writes the device/head register (`0xa0 | target << 4`), features 0, byte count low `0xfe`, high `0xff`, device control `0x0a`
   (nIEN), then the PACKET command `0xa0` to `0x11c`.
3. Waits for DRQ with BSY clear (`status & 0x88 == 8`), then writes the twelve packet bytes as six 16-bit writes to `0x100`.
4. Data phase: waits DRQ; reads the byte count from `0x110` (low) and `0x114` (high), halves it, and transfers that many 16-bit
   words through `0x100` until the requested length is done; finally waits for DRQ and BSY clear, then checks status
   (bits 5, 2 and 0 are errors).
5. On failure and when sense is wanted, issues REQUEST SENSE through the same path.

IOC4-specific: only the spacing, the 16-bit data access at `0x100`, and in Linux the optional DMA start between steps 2 and 4.
The interrupt-reason register is not read by EFI.

## 6. What each consumer reads or needs

**SLES 9 SP3 installer and kernel (2.6.5-7.244).**
- `ioc4.ko` (core, a submodule registry): matched by `modules.pcimap` on 10a9:100a class `0x0b4000`. It enables the device,
  sets bus master, claims the misc region, performs the writes in section 4 and calls each registered submodule. It does
  **no** PCI-clock measurement: the module has no calibration messages or counter code; the clock probe from the INT_OUT
  counter (`ioc4: ... pci clock`) is in the later trees only.
- `sgiioc4.ko` (depends on `ioc4`; not in `modules.pcimap`, so `linuxrc` loads it by its own table): reads the revision,
  requires 46 or more, maps `0x100`, `0x120`, `0x140`, `0x0`, writes 3 to `0x14`, allocates the table (`PAGE_SIZE/4` bytes)
  and the 128-byte ending area, and sets mode MW-DMA 2. The probe fails (and the IDE port is skipped) on: revision below 46,
  the I/O region already claimed, or no memory for the DMA maps (the last falls back to PIO).
- The `config` of the held SN2 kernel builds the IOC4 IDE driver, `ide-cd`, `sr_mod` and the QLogic 1280 driver as modules
  (`CONFIG_BLK_DEV_SGIIOC4=m`, `CONFIG_BLK_DEV_IDECD=m`, `CONFIG_BLK_DEV_SR=m`, `CONFIG_SCSI_QLOGIC_1280=m`) and has no IOC4
  serial driver option.

**Later public Linux (7.3 port).** `ioc4.c` does the same enable and clears, plus the INT_OUT toggle test to measure the PCI
clock (63-count square wave, 256 cycles; outside 25 to 75 MHz it assumes 66 MHz) and finds the card variant by the QLogic
ISP12160 or Vitesse VSC7174 at PCI slot 3 of the same bus; the IDE submodule attaches for every variant except one with
neither. Details: [linux-driver-notes.md](linux-driver-notes.md).

**EFI driver (`Ioc4AtapiScsiPassThru`).** It needs only:
- `10a9:100a` visible in configuration space (SAL PCI config calls); `cpuid[2]` not the simulator value (efi.md);
- the Attributes call to enable I/O, memory and bus master (`0x700`) to be honoured;
- BAR 0 memory byte and halfword accesses at `0x100`-`0x120` returning an ATA task file with working BSY/DRQ/ERR;
- a drive that answers the PACKET command with a twelve-byte packet and byte counts through `0x110`/`0x114`.

It never touches `0x0`-`0x5c`, the DMA block or any interrupt (nIEN is set, all waits are timed polls with 30 microsecond
steps and a 31,000-unit reset wait). It has only the PACKET path: no IDENTIFY and no non-packet read, so a plain ATA disk on
the channel is not reachable by this driver (the function set read contains no such command; **inferred** that a disk fails
at PACKET with abort). Device-path, El Torito and file-system details: [efi-boot.md](../../software/firmware/snprom/efi-boot.md).

## 7. Installing SLES 9 from a CD on this channel, or on the ISP12160

- **Boot.** EFI can boot an ATAPI CD on the IOC4 (above, and efi-boot.md) and an ISP12160 SCSI CD through the QLogic
  pass-through ([efi-qlogic.md](../../software/firmware/snprom/efi-qlogic.md)). The CD 1 El Torito image is a FAT image holding
  the boot loader, kernel and installer ramdisk; the ramdisk is then the installer's whole world.
- **Installer drivers.** The CD 1 ramdisk carries `ioc4`, `sgiioc4`, `ide-cd`, `cdrom`, `scsi_mod`, `sr_mod`, `qla1280`
  (the ISP12160 driver) and other QLogic and SATA modules; `linuxrc` has a built-in module list naming `sgiioc4` and
  `qla1280`. Established as files and strings.
- **Where it looks for the installation CD.** The `linuxrc` binary has the messages "Looking for a %s CD...", "Looking for a
  %s CD again...", "Found CD in %s", "Trying to mount the CD-ROM...", "Make sure that CD number %d is in your drive",
  "No further storage devices found; giving up", reads `/proc/sys/dev/cdrom/info`, and builds `scd%d` and `/dev/hd%c` names.
  Reading these as an installer that enumerates every CD-ROM it can find and tries each, ID-checking the medium for an
  installation CD, with a retry after loading more storage modules, is **inferred**: the strings and the module list point
  that way, but the `linuxrc` code path was not read (the 2005 source is not held; the current linuxrc source fetched for
  this question handles repository URLs and says nothing about drive order). It does not state that the boot device is
  special.
- **Verdict (inferred, not verified).** A SCSI CD on the ISP12160 should work as install media, provided the EFI QLogic path boots
  it and `qla1280` plus `sr_mod` load in the ramdisk. The IOC4 ATAPI CD works on both sides (EFI and kernel). Booting from one
  drive and installing from the other is probably fine. What would settle it: decompile the `linuxrc` CD-search routine (the
  function around the "Found CD in %s" string), or run the install in a model with each arrangement.

## Review

Independent review of chips commit `ddbdaf7` (this page and the pointer edits in efi.md and efi-boot.md), 2026-11-16, record shared with [the 3.2 discovery page](../../software/linux/sn2-io-discovery-3.2.md#review).

**Confirmed against public source.** Linux 2.6.5 `drivers/ide/pci/sgiioc4.c` and `include/asm-ia64/sn/ioc4.h`: task file at `0x100` with a 4-byte stride, control `0x120`, DMA block `0x140` with words 0 to 8 as listed, interrupt block at `0x0` with status `0xc`, set `0x14`, clear `0x1c`; byte-bus bases `0x80000` to `0xe0000`; table entry of four big-endian words with address in word 1, length in bits 15:0 and end flag bit 31; entry count `PAGE_SIZE / 64`; a 64 KiB entry written as length 0; direction `0x4` for a disk read; setup and completion order, the 200-read stop poll, the 16-word ending area and the 8-byte count slack; the `0x51` status-read hook writing 3 to `0xc`; revision below 46 refused (also in 3.2.78 and `pata_sgiioc4.c` at 7.3). 3.2.78 `drivers/misc/ioc4.c`: command word `0x140`, calibration and the ISP12160-at-slot-3 test. The error-address layout and master id 8 (`include/linux/ioc4.h`). The 7.3 libata port forces PIO with the ATAPI DRQ comment and writes a 64 KiB entry as `0x10000`.

**Findings (none blocks).**
1. "Both ran on hardware" (the 64 KiB entry paragraph) is unsupported for the 7.3 port; only the 2.6.5 driver is known to have shipped. Fix: drop the clause and keep the length-0 reading inferred from the 2.6.5 driver alone.
2. The `0x51` mask belongs to 2.6.5 and the SLES module. The 3.2.78 IDE driver tests the busy bit instead (`sgiioc4.c:295`). Fix: say the status-read acknowledge differs by driver version, which supports the page's own "unknown whether the chip clears it".
3. The page fetched a linuxrc source file from a public URL; the project rule is to check held sources first. Not a content fault; note for the author.

**Verdict.** Accept. **Not checked:** everything read from the SLES 9 installer media and the shipped modules (`ioc4.ko` writes, `linuxrc` strings and module list), the EFI driver offsets and its polling, and the IRIX-derived rows; I had no access to those artifacts.
