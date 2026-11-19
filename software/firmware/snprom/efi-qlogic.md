# The EFI QLogic driver: initialisation and the `ql2.c` assert

What the ISP12160 pass-through driver in the SN2 PROM's EFI does to the chip, in order, and why it stops at
`ql2.c(1990)` with `tmp2 & 0x0008` when the chip model does not store bit 3 of bus configuration 1. Image:
`shub1snprom.bin` 10.54 build 70399 (sha256 `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`), EFI component
(FIT type `0x1f`, expands to the IA-64 ELF described in [efi.md](efi.md)). Read in Ghidra with the IA-64 processor
(`re-run --ghidra-export ... --decompile-all`, 2,344 functions) and cross-checked against `ia64-linux-gnu-objdump`. No emulator ran.

**Grades.** *established*: read in the image (code and constants). *inferred*: reasoned from names, call shape or a public
driver. *unknown*: not settled. Addresses are Ghidra-export addresses (ELF address plus `0x100000`, as in efi.md) unless marked
"file offset", which is the offset in the expanded ELF. Ghidra left every function of the driver unnamed except
`ql12160configure` (`0x26d200`) and `ql_entry` (`0x26d2a0`); the names below for the others are this page's.

## 1. The stop

The assert sits in the bus-mode probe, `0x26b710` (established). Its arguments are the source path
`.../efi1_10/edk/Drivers/QlogicPassThru/ql2.c` (string at ELF address `0x1ce260`), line `0x7c6` (1990) and the expression
`tmp2 & 0x0008` (`0x1ce2e0`). A second assert in the same function, line `0x7d6` (2006), checks `tmp2 == tmp1`.

| Item | Value | Grade |
|---|---|---|
| Register | bus configuration 1 (qla1280 `cfg_1`), offset `0x06` | established |
| Access | PCI I/O protocol `Mem.Read` / `Mem.Write`, width 1 (16 bit), BAR index 1, offset = base + `0x06`, count 1; base is 0 (`ha[1]`, zeroed in `0x2685d0`) | established |
| `tmp1` | the value read first | established |
| `tmp2` | the value read back after writing `tmp1 | 0x0008` | established |
| Bit 3 (`0x0008`) | the ISP1020/1040 "SXP register select" bit (`BIU_PCI_CONF1_SXP` in NetBSD `ispreg.h`). Its meaning on the 12160 is **unknown**: NetBSD's 1080/12160 register routines select the SXP banks with bits 9:8 and never use bit 3 | unknown (meaning); established (the driver stores, reads back and restores it) |

The code writes bit 3, reads the register back and asserts the bit stuck. It then reads the register at `0xf6` (the SXP
"DIFF pins" register in the ISP SXP block: Linux names `0xf2` `scsiControlPins`, NetBSD puts DIFF pins four bytes after
control pins), which is only meaningful if bit 3 selected the SXP bank in the window at `0x80` to `0xff`.
Linux `qla1280.c` selects that bank on the 12160 with `0x0100` (`SET_SXP_BANK`) and NetBSD with bits 9:8 (`BIU_PCI1080_CONF1_SXP0`/`SXP1`); the 1040-class bit 3 is not what the 1080 family uses. The driver passing on shipped hardware shows only that bit 3 is a read/write bit that reads back; that it shows an SXP bank is **not** established. No ISP12160 data sheet is in our holdings, and Linux defines `ISP_CFG1_SXP` as bit 0 and never uses it.

The "Firmware Rev 6" line printed before is not firmware. `QlogicScsiPassThruDriverBindingSupported` (`0x188360`) reads the first
64 bytes of PCI configuration space, accepts vendor `0x1077` device `0x1216`, and prints segment, bus, device, function from
`GetLocation` and the byte at configuration offset 8: the PCI revision ID (established). The driver learns the firmware level
from no register at all (below).

## 2. What the driver does before the assert

Call chain (established): `DriverBindingStart` (`0x1886c0`) turns on the device (`Attributes`), calls
`RegisterQlogicScsiPassThru` (`0x188b90`), then `ql12160configure` (`0x26d200`), then `0x2685d0`, which does the following in
order. `Stall(n)` is the boot-services stall in microseconds. A mailbox command is helper `0x268dd0`: poll host-command
(`0xc0`) bit `0x80` clear; save bus control (`0x08`); write the mailboxes; write `0x5000` (set host interrupt); poll
semaphore (`0x0c`) bit 0 set (up to 20 million reads); read mailbox 0 (`0x70`); a value with bit 15 set is an asynchronous
event (`0x8001` marks the bus as reset, others end the command); `0x4001` is an invalid command; other values return the
outputs; then write semaphore 0 and `0x7000` (clear RISC interrupt). The helper's mailbox write switch is a jump table the
decompiler lost, so the mailbox numbers below were read from the callers' argument registers.

1. PCI configuration: read 64 bytes at offset 0; if the latency timer (`0x0d`) is not `0x40` write `0x40`; if the cache line
   size (`0x0c`) is not `0x80` write `0x80`.
2. Allocate the host structure, two 0x180b0-byte channel records (two buses) with defaults, and two 2 KiB rings.
3. **Reset and firmware load** (`0x267910`, called by `0x2683e0`):
   - bus control (`0x08`) = `0x0005` (soft reset, RISC interrupt enable), `Stall(50)`;
   - host command = `0x1000` (reset RISC), then `0x3000` (release), `Stall(50)`; bus control = `0x0004`;
   - mailbox register test: mailbox 0 = `6`, mailboxes 1 to 7 = `0x1111`, `0x2222`, ... `0x7777`; eight in, eight out; the
     outputs must echo the inputs, else the driver prints a mismatch and goes on;
   - host command = `0x2000` (pause), bus configuration 1 = `0x0044`, semaphore = 0, `Stall(100)`, host command = `0x3000`, `Stall(50)`;
   - **firmware download**: for each of the 13,853 words of the driver's own image, mailbox 0 = `4` (write RAM word),
     mailbox 1 = load address + index (start `0x1000`), mailbox 2 = the word (three in, three out);
   - mailbox 0 = `2` (execute firmware), mailbox 1 = `0x1000` (two in, one out);
   - mailbox 0 = `8` (about firmware), one in, three out; the result is not read.
4. **Initialisation** (`0x2667f0`):
   - bus control = 0; host command = `0x2000`; poll host command bit `0x20` set (10,000 reads, `Stall(100)` each);
   - bus control = 1 (soft reset); poll host command bit `0x40` clear (10,000 reads);
   - bus configuration 1 |= `0x0300` (DMA bank), write `0x000e` to `0x82`, `0xa2`, `0xc2`, set bit 1 in `0x80` and in `0xc0`
     (bank registers; their meaning is not read), restore bus configuration 1; poll mailbox 0 while it reads `4` (busy;
     up to 1,000 reads at 1 ms);
   - bus configuration 1 = `0x0044`, semaphore = 0, host command = `0x3000`, `Stall(50)`, bus control = `0x0004`;
   - mailbox `2` (execute firmware, address `0x1000`) again, so the image survives the soft reset in chip RAM;
   - mailboxes `0x37` (set PCI control), `0x34` (set clock rate, `0x50`), then the two ring set-ups through `Map`, `0x52`
     (initialise request queue, 64-bit) and `0x53` (initialise response queue), eight in and out each;
   - for each bus: `0x18` (SCSI bus reset; delay 3, bus number);
   - `0x30` (set initiator ID), `0x31` (selection timeout), `0x32` (retry count), `0x33` (tag age limit, 8), `0x35` (active
     negation, `0x30`), `0x36` (async data setup, 9), `0x3a` (reset delay), `0x45` (system parameter, 1), `0x4a` (firmware
     features, `0x322`), `0x5a` (data overrun recovery, 2). The numbers are established from the argument registers;
     which parameter each carries was matched to the Linux `qla1280.h` names (inferred).
5. **Bus-mode probe** (`0x26b710`), once per bus, both calls issuing the same register sequence: the assert.

There is **no NVRAM access** (register `0x0e` is not referenced in steps 3 to 5) and no `VERIFY_CHECKSUM` or `LOAD_RAM`
command (established for these functions; the SCSI command path `ql_entry` was not searched for NVRAM use). The probe is
skipped (returns 0) when CPUID register 2 holds `0xaeeeeeee8badbeef`, the simulator signature of
[efi.md](efi.md) (the simulator-signature paragraph); the same test makes the driver's `Supported` function decline.

The firmware level is not read from the chip: the driver downloads its own RISC image, 13,853 words (27,706 bytes, ELF address
`0x205ad0`, load address `0x1000`; the 16-bit words sum to zero modulo 65,536, the usual QLogic checksum) and runs it. The image
is not reproduced here. It is the driver's, not the chip's, so a model need not run it: it only has to accept the mailbox
commands and report success.

## 3. Verdict

A real ISP12160 does not depend on firmware the driver loaded for this assert. Bit 3 of bus configuration 1 is a plain register
bit on the chip (read/write; whether it selects an SXP bank on this chip is unknown, see section 1): the driver sets it, reads it back and restores the old
value, with the RISC paused and no mailbox command in flight. The model keeps only bits 9:8 of that register, so bit 3 never
sticks. **Model fix:** store bit 3 of bus configuration 1 (established as the requirement of the driver's two checks); what the window at `0x80` shows with it set is unknown, and the driver accepts any value read at `0xf6`.

The sequence a faithful model must produce for the probe to pass (all 16-bit accesses to BAR 1):

1. write `0xc0` = `0x2000`; reads of `0xc0` return bit `0x20` set within 10,000 polls.
2. read `0x06` = `tmp1`; write `0x06` = `tmp1 | 0x0008`; read `0x06`: bit 3 set (line 1990).
3. read `0xf6`: the driver returns bus mode 2 when bit `0x1000` is set, 1 when it is clear and `0x0800` is set, else 0 (the page's earlier "4, 2 or 1" and a `0x0400` test do not exist). Any value is accepted. Whether a real Altix 350 cable reads as LVD
   or single-ended is **unknown**; LVD is the chip's native mode.
4. write `0x06` = `tmp1`; read `0x06` equals `tmp1` (line 2006), so bit 3 must clear again.
5. `Stall(100)`, write `0xc0` = `0x3000`; reads of `0xc0` return bit `0x20` clear within 10,000 polls.

Not checked: the SCSI command path (`ql_entry`, `0x26d2a0`), the response-ring decoder `0x26ab30`/`0x26ac50`/`0x269c80`, and
the meaning of the DMA-bank writes in step 4.

## Sources

Public: Linux `drivers/scsi/qla1280.c` and `qla1280.h` (Linux history tree); NetBSD `sys/dev/ic/ispreg.h` (NetBSD source tree); the QEMU `sgi-origami` page `docs/system/mips/sgi/hardware/qlogic-isp.rst`. No external URL was fetched.

## Review

Independent re-read of `f81a3c0` against `shub1snprom.bin` 10.54 (sha256 `51ccf9ad...`): the EFI ELF was re-extracted from the FIT type `0x1f` entry (`0xffca5ec0`, gunzip, 2,495,544 bytes), read with `ia64-linux-gnu-objdump -d` and with the retools Ghidra export (`--no-analysis`, decompile of `0x26b710` and `0x2685d0`). Linux `qla1280.h` (Linux history tree) and NetBSD `ispreg.h`, `isp_pci.c` (`netbsd-src`).

**Confirmed.**
- `0x26b710`: asserts `ql2.c` line `0x7c6` with `tmp2 & 0x0008` (strings at ELF `0x1ce260`, `0x1ce2e0`; the `and` that feeds it is at file offset `0x17b9f6`, ELF `0x16b9f6`) and line `0x7d6` with `tmp2 == tmp1`; skipped when CPUID register 2 is `0xaeeeeeee8badbeef`.
- The five-step sequence and every access: PCI I/O `Mem.Read`/`Mem.Write`, width 1, BAR 1; HCCR `0xc0` = `0x2000` with `Stall(100)` before each read and a 10,000-read poll for bit `0x20` set; read `0x06`, write `tmp1 | 8`, read back; read `0xf6`; write `tmp1`, read back, compare; `Stall(100)`; HCCR = `0x3000` and poll bit `0x20` clear. A timeout in either poll returns -1.
- "Firmware Rev 6": the argument is the byte at configuration offset 8 of the 64 bytes read in `QlogicScsiPassThruDriverBindingSupported` (vendor `0x1077`, device `0x1216` compares at `0x884dc`, `0x8859c`); the format is the "Qlogic 12160 SCSI Controller detected: Firmware Rev %d" string.
- Linux `ISP_CFG1_SXP` is bit 0 (`qla1280.h` line 141); NetBSD `BIU_PCI_CONF1_SXP` is `0x0008`.
- The opening of the earlier init (bus control `5`, `Stall(50)`, host command `0x1000`, `0x3000`) and the mailbox echo constants `0x1111`..`0x7777`; the driver image is 27,706 bytes of 13,853 words at ELF `0x205ad0` and its words sum to zero modulo 65,536.

**Changed (fixed above).** Bit 3's meaning: NetBSD uses it as the SXP select only for the 1020/1040 and selects banks with bits 9:8 on the 1080 family, so the earlier "inferred SXP select on the 12160" is regraded unknown; the model requirement (store the bit) stands. The bus-mode return value is 2, 1 or 0 from `0xf6` bits `0x1000`, `0x0800`; there is no `0x0400` test and no value 4.

**Not checked.** The 13,853-word loop bound and mailbox numbers of the download, `EXECUTE_FIRMWARE`, `ABOUT_FIRMWARE`, the set-parameter and queue mailboxes and the DMA-bank writes of section 2 (only the image extent, its checksum and the first reset steps were re-read); no emulator ran.
