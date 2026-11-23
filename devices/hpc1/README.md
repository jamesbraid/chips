# HPC1: the Indigo's peripheral controller

The first-generation peripheral controller (HPC1, and the HPC1.5 revision) of the SGI Indigo, on both the R3000 board (IP12) and the R4000
board (IP20). It moves data between main memory and the Ethernet, SCSI and parallel-port channels and the DSP audio block, and it
decodes the peripheral windows behind it: the Ethernet chip, the WD33C93 SCSI chip, the Z85C30 serial chips, the real-time clock, the
interrupt controller, the boot PROM and the DSP SRAM. It holds the one-byte register that bit-bangs the serial EEPROM. The register
map is in [registers.md](registers.md) and [registers.toml](registers.toml). Labels as in [AGENTS.md](../../AGENTS.md): **established**,
**inferred**, **unknown**.

Not in this page: the internals of the Ethernet chip ([seeq_8003](../seeq_8003/README.md)), the WD33C93, the Z85C30, the real-time
clock, the interrupt controller and the DSP firmware interface. This page records only what the HPC1 wires to them.

## Evidence and its limits

- **No HPC1 specification is held.** The HPC3 specification is a different part; the HPC1 differs in descriptor word order,
  flag bits, register map and control bits (table below), so it supplies nothing here except as a hint.
- **Shipped IRIX 6.5 IP20 objects** read in full where cited: the kernel object `kernel.o` (`mlreset`, `get_nvreg`, `set_nvram`, the
  checksum routine, `wd93_go`, `wd93dma_flush`, `board_rev`, `lcl_intrd`), the Ethernet driver `if_ec2.o` (`ec_init`, `ec_reset`,
  `seeq_init`, `ec_transmit`, `if_ecintr`, `ec_watchdog`, `idbg_ec2_dump`), the SCSI driver `wd93.o`, the parallel driver `hpcplp.o` and the
  serial driver archive `sduart.a`. Addresses below are object-relative (for example `if_ec2.o+0x5c8`). Not a single object accesses
  the DSP register block at its own HPC offsets other than by pointer, so those registers stay inferred.
- **The shipped developer headers** (IP20 board header, HPC1 header, NVRAM header). They name the registers and the descriptor
  bitfields; each is read as a software expectation and checked against object code where the table says so.
- **Indigo PROMs.** IP20 4.0.5D Rev A (070-8116-004) was disassembled over the whole image; the 4.0.5G Rev B image (070-8116-005, sha256
  `ae35c097...`) is listed but **was not on the host for this reading**, so every PROM address below is a 4.0.5D address. The
  IP12 images 070-8086-002 and 070-8088-xxx (4.0.1 Rev C) were scanned for the accesses they make to the HPC1 window.
- **Public drivers.** NetBSD sgimips (`hpcreg.h`, `hpc.c`, `if_sq.c`, `sqvar.h`, `haudreg.h`) is level 3 and agrees with the IRIX objects wherever
  both are read. NetBSD's offsets for byte-wide devices are not raw addresses (its `wdsc.c` says so, and it attaches the WD33C93 of the
  IP12 at `0x11f` where the IRIX header and both PROMs use `0x122`): never take a byte-device offset from it.
- An independent emulator model of the HPC1 was read as a cross-check only; nothing below rests on it.
- Nothing was measured on a board.

## Which parts shipped

| Item | Finding | Label |
|---|---|---|
| IP20 on-board HPC | One at physical `0x1fb80000`. Up to two more at `0x1fb00000` and `0x1f980000` in GIO slots; the header says "may not be present". | established (shipped header; `if_ec2.o` probes three slots) |
| IP20 revision | The IP20 PROM reads the endian register at `+0xc0` as its first HPC access and the header names its bits 7:6 the revision, "01 for HPC1.5". The PROM never reads the revision bits. An OpenBSD boot log of an R4000 Indigo (published console capture, OpenBSD 5.1 on a 100 MHz R4000, imc revision 1) prints "SGI HPC1 (onboard)", from a driver that prints ".5" when it reads revision 1 in bits 7:6 of the endian register and "HPC1" when the read fails or reads anything else. So that board's on-board part was not an HPC1.5 by that test; whether it lacks the register or reports another revision is not visible. | the log line: observed; "this IP20 board's part is an HPC1": inferred; whether any shipped IP20 carries an HPC1.5: **unknown** |
| IP12 on-board HPC | At `0x1fb80000` too (Hollywood HPC-1 in the header comments). A NetBSD 2.0 boot log of an R3000 Indigo prints "SGI HPC1" (no ".5"). The 4.0.1 Rev C image 070-8088-xxx stores zero to `+0xc0` once at start-up (`0xbfc0022c`); image 070-8086-002 never touches `+0xc0`. | the log line: observed; PROM accesses: established; reading the PROM difference as a part difference: inferred |
| Second and third HPC | The kernel's Ethernet driver reaches a unit in a GIO slot through `setgiovector` and the on-board one through the local interrupt vector (`if_ec2.o+0x2e0`, `+0x31c`). | established |

The revision values in the IRIX header (bits 7:6 = 1 for the 1.5) and NetBSD's (`HPC1_REV15`) agree. HPC1.5 hardware is documented on GIO option
boards (the public driver comment lists "additional HPC1.5" parts in slots 0 and 1 of the Indigo and Indy). How the revisions differ beyond
the endian register is **unknown**. A model that identifies as an HPC1 (no endian register effect) matches both public boot logs.

## Address window

One HPC1 window is 0x80000 bytes. Registers are 32-bit slots; a one-byte or two-byte register uses a lane of its slot. The IRIX header
gives two addresses for the same register, one per CPU byte order, and they name the same lane: for example the auxiliary byte is `+0x1bf`
big-endian and `+0x1bc` little-endian (bits 7:0 of the word at `+0x1bc`), the WD33C93 address port is `+0x122` and `+0x121` (bits 15:8 of
`+0x120`), and the parallel status is `+0x135` and `+0x136` (bits 23:16 of `+0x134`). Hence [registers.md](registers.md) lists words and
names lanes in field bits. **Established** (header, both orders; kernel and PROM use the big-endian addresses).

| Offset | Block | Label |
|---|---|---|
| `+0x00` | window base, probed for presence | established |
| `+0x08` to `+0x5c` | Ethernet transmit and receive DMA | established for the named ones, see below |
| `+0x88` to `+0x9c` | SCSI DMA channel | established |
| `+0xa8` to `+0xbc` | parallel-port DMA channel | established |
| `+0xc0` | endian and revision | established |
| `+0x100` to `+0x11c` | Ethernet chip, eight registers at stride 4 | established |
| `+0x120`, `+0x124` | WD33C93 address and data ports | established |
| `+0x134` | parallel status/remote byte | established |
| `+0x180` to `+0x1b4` | DSP interface | inferred (header only) |
| `+0x1bc` | auxiliary byte: console LED, serial EEPROM | established |
| `+0x1c0` to `+0x1ff` | interrupt controller and 8254 timer window | established; the registers belong to the interrupt controller |
| `+0xd00` to `+0xd3f` | four serial blocks of 16 bytes | established |
| `+0xe00` to `+0xe7f` | real-time clock, one byte register per word | established |
| `+0x50000` | board revision word (physical `0x1fbd0000`) | established that it is read; that the HPC itself decodes it is unknown |
| `+0x60000` to `+0x7ffff` | DSP SRAM, 24-bit words in 32-bit slots, 128 KB | established (header, PROM load routine) |
| PROM at `0x1fc00000` | the boot PROM follows the window | established |

Absent controllers must fail a guarded access: the kernel Ethernet driver does a guarded write of `0xaaaa` to `+0x10` of each slot
before it attaches (`wbadaddr_val`, `if_ec2.o+0x2ec`), and the parallel driver a guarded word read of `+0x00` (`badaddr`, `hpcplp.o+0x1ec0`).
**Established.**

## Endian and revision byte (`+0xc0`)

Bits 0 to 4 give the byte order of the CPU and of each channel's DMA, one bit each: CPU, Ethernet, SCSI, parallel, DSP (bit set means
little-endian). Bits 7:6 are the revision. The kernel sets all five bits for a little-endian kernel (OR `0x1f`) and clears them (AND
`0xe0`) for a big-endian one. The kernel and PROM both do this as a byte access at the big-endian address `+0xc3` inside a guarded store
(`kernel.o` helper at `+0x2338`, called from `mlreset`; PROM `0xbfc08e00`, helper `0xbfc2a5b0`). **Established.** The IP20 PROM's first access
(`0xbfc003fc`, before it touches memory) reads the word and, if bit 0 is set, stores zero, so that every channel is big-endian even when the
CPU came out of reset little-endian. **Established.** Reset value, and whether bit 0 is a read-only strap or a writable bit that the zero
store clears, are **unknown**; the word-wide store implies that bits 7:6 also take the zero, so a model should keep the revision bits
read-only. **Inferred.**

QEMU qtest hooks: a write of `0x1f` to `+0xc0` and a read back; a write of zero followed by a read; that bits 7:6 survive a zero store
(inferred: read-only revision).

## Descriptor format and byte order

The descriptors are chained in main memory, each in a 16-byte slot. The HPC reads three words; the fourth word is software storage (the IRIX
Ethernet driver keeps the owning mbuf pointer there, the SCSI driver keeps a physical address for memory above 128 MiB). All words are
32-bit and are in the byte order that the endian register selects for the channel (the header declares the same bitfields twice, once per
byte order, so the field positions below are the positions in the 32-bit value, not in memory bytes). **Established** (header).

**HPC1 puts the flags and byte count first and the buffer address second.** The HPC3 does the opposite. NetBSD's header says so and the IRIX
Ethernet driver agrees: its ring set-up (`if_ec2.o+0x654`) writes the size and flags into word 0 and the physical buffer address into word 1.
**Established.**

SCSI and parallel descriptor (header bitfields, kernel flush routine `kernel.o+0x4790`, which masks the count with `0x1fff`, the buffer with
`0x0fffffff`):

| Word | Bits | Meaning | Label |
|---|---|---|---|
| 0 | 12:0 | transfer byte count, at most 8191 | established |
| 1 | 31 | end of chain (`HPC1_EOX_VALUE` is `0x80000000`) | established |
| 1 | 30:28 | unused | established (header: fill) |
| 1 | 27:0 | buffer physical address, 256 MiB reach | established |
| 2 | 27:0 | next descriptor physical address | established |
| 3 | all | software only | established |

Ethernet descriptor (`ENET_DESC_W0` to `W2` in the register file): same address fields as the SCSI one. Word 0 flags: bit 31 end of packet,
bit 30 ownership, bit 15 interrupt when finished, 12:0 count. A receive descriptor is posted with end-of-packet, ownership and interrupt all set
and the buffer size in the count (NetBSD `SQ_INIT_RXDESC`; IRIX `ec_reset` sets bit 31 and the size `0x632`). The last descriptor of a
queue has bit 31 set in **word 1** (end of chain). The IRIX receive path treats a clear bit 31 in word 0 as "frame received"; the NetBSD path
treats a clear bit 30 as "frame received"; the IRIX transmit path treats a set bit 30 as "still queued". So the bits are established as
flags and their hardware set and clear rules are **inferred only**: which bit the HPC clears on completion, and whether it writes the
unused count back over the size field, is **unknown** without a model run or a read of the channel logic. A model should clear both bit 31 and
bit 30 of word 0 on a completed receive and clear bit 30 on a completed transmit, which satisfies both public drivers; this is an
approximation, not a fact.

Both drivers pass physical addresses with bits 31:29 clear (`and 0x1fffffff`, `if_ec2.o+0xf8`) and keep the top nibble of word 1 for the flag
that they set separately (`and 0xf0000000` at `if_ec2.o+0x1ac`). Whether memory above 128 MiB is reachable at all is **unknown**; the SCSI
driver bounces transfers through low memory when more than 128 MiB is installed (header comment on the fourth word) and the IP20 PROM page
lists the same limit.

QEMU qtest hooks: build a two-descriptor chain, write the first descriptor's address to the next-descriptor register, set the channel's start
bit, check both buffers are consumed, the end-of-chain flag stops the channel and the active bit reads back zero.

### How the HPC1 differs from the HPC1.5 and the HPC3

| | HPC1 / HPC1.5 | HPC3 | Label |
|---|---|---|---|
| Descriptor word order | flags and count, then buffer, then next | buffer, then flags and count, then next | established (NetBSD header, IRIX driver) |
| Byte count width | 13 bits (`0x1fff`) | 14 bits (`0x3fff`) | established |
| End-of-chain | bit 31 of the buffer word | bit 31 of the flags word | established |
| Receive/transmit flags | end-of-packet 31, own 30, interrupt 15 | end-of-packet 30, interrupt 29, transmit-done 15, own 14 | established |
| SCSI control | reset 0x01, flush 0x02, direction 0x10, start 0x80 | irq 0x01, endian 0x02, direction 0x04, flush 0x08, active 0x10 | established |
| Ethernet registers | 0x10 to 0x5c, in-window Seeq at 0x100 | separate channel pages, Seeq at 0x54000 | established |
| Endian | one register for all channels (HPC1.5; HPC1 revision 0 unknown) | per-channel bits | inferred for HPC1 |
| Between HPC1 and HPC1.5 | the 1.5 adds the endian register and revision field; nothing else is known | | inferred |

## Ethernet DMA

Registers and bits are in [registers.md](registers.md). The names come from the register dump routine in the IRIX Ethernet driver
(`idbg_ec2_dump`, which prints twenty-two registers in an order that fixes their offsets: the dump reads `+0x08` through `+0x5c` then
`+0x118` and `+0x11c` against the label strings in order). **Established** for every offset; the meaning of `xcount`, `cxbp`, `xpntr`, `xfifo`,
`rcount` and the two FIFO ports is **unknown** (nothing writes them).

Sequence that the IRIX driver issues, which is what the receive and transmit channels must support:

1. `ec_reset` (`if_ec2.o+0x574`): writes zero to `+0x38` and `+0x34` (stop both channels), writes 7 to `+0x3c` (reset the chip and the channel,
   clear any interrupt, normal mode), waits 10 microseconds, writes 4 (normal mode, out of reset).
2. `seeq_init` (`+0x35c`): station address bytes one per slot at `+0x100`..`+0x114` (each store a word, byte in bits 7:0), the transmit
   command at `+0x11c`, the inter-packet gap value at `+0x108`, and `0x01000000` to `+0x2c` to disable the receive interrupt delay. The writes
   to the chip window are word stores and each store reaches one chip register.
3. `ec_init` (`+0x0`): stores the physical addresses of the transmit descriptors to `+0x20` and `+0x10` and of the receive ring to `+0x54` and
   `+0x50`, writes the receive command to `+0x118` (a mode byte of `0x40`, `0x80` or `0xc0`, ORed with `0x3e`), starts the receiver with `0x4000`
   to `+0x38`, then writes the receive command again with bit 0 also set (`0x3f`).
4. Transmit (`ec_transmit`): writes the queue head to `+0x10`, `+0x20`, `+0x24` and starts transmit by writing `0x400000` to `+0x34`.
5. Interrupt (`if_ecintr`): reads `+0x3c` bit 1 (pending), reads `+0x38` and `+0x34` for the channel state, acknowledges by writing 6 to
   `+0x3c` (clear interrupt, normal mode), clears a receive overflow by writing 12 (`0x0c`), and sets `+0x2c` to its delay value.

The kernel and the PROM write the same registers at the same offsets. The PROM's reset writes 5 to `+0x3c` where the kernel writes 7 (the PROM sets
reset and normal mode, without clearing an interrupt). **Established.**

**Unknown:** what `+0x34` and `+0x38` return above the channel bit (public drivers and the dump treat them as the Ethernet chip's status
shifted up; no decision of the IRIX driver depends on it); whether `+0x2c` counts anything the model needs; the effect of reading `+0x3c`.

QEMU qtest hooks: write 7 then 4 to `+0x3c` and read bit 1; start a receive with a descriptor ring and a frame injected on the chip side;
`+0x34` bit 22 reading one while a transmit is queued and zero after.

## SCSI DMA channel and the WD33C93 window

The IRIX driver (`wd93_go`, `kernel.o+0x4550`) loads the physical address of the first descriptor into `+0x90` and then writes `+0x94`: `0x90` for a
transfer to memory, `0x80` for a transfer to the device. The channel then follows the chain by itself. **Established.** To finish or to cut
a transfer short, `wd93dma_flush` (`kernel.o+0x46e4`) sets bit 1 (flush) with a read-modify-write and polls the control register until bit 7 reads
zero, 512 times at most, before it reads how much was moved from the descriptors; the PROM's version prints "SCSI DMA in progress bit never cleared" if
the poll runs out. A bus reset writes 1 to `+0x94`, waits 25 microseconds and writes zero (`kernel.o+0x4500`). The PROM does the same in
its flush routine (`0xbfc27794`) and clears the control register at `0xbfc00974`. **Established.**

A descriptor moves at most 8191 bytes (13-bit count). The flush routine walks the chain in 4096-byte steps when it works out how much was
moved (`kernel.o+0x47b8` to `+0x48b0`), so the driver evidently builds descriptors per page; that is **inferred** from the walk, the builder was not read.

The WD33C93 chip registers are reached through two 32-bit slots: the address port at `+0x120` and the data port at `+0x124`, both on the 15:8 byte lane
(IRIX header addresses `+0x122`, `+0x126`). The PROM power-on test (`0xbfc02960`) writes 0x17 to the address port, then 0x02, then 0xa5 to the data
port and reads it back, expecting the same value. **Established.** The chip's own registers are not covered here.

Interrupt: the SCSI chip's interrupt line goes to the interrupt controller as local source 2; HPC1 itself raises none for SCSI. **Established**
(`wd93_init`, `setlclvector(2, wd93intr)`).

**Unknown:** the reset value of `+0x94`; whether the channel raises an interrupt of its own at end of chain (the driver takes completion from the
chip); what `+0x98` and `+0x9c` do (no driver code touches them).

QEMU qtest hooks: flush bit self-clears and start bit reads back; the address/data ports pass a byte to the chip model; `+0x94` write 1 resets
the chip.

## Parallel-port DMA

Offsets `+0xa8` to `+0xbc`, with the status byte at `+0x134`. The driver (`hpcplp.o`, `plp_dma` at `+0x1be8`) stores a placeholder to the byte
count and to the current pointer, writes the descriptor address to `+0xb0`, stores 1 (read) or 3 (write) into the status byte, and writes the
control register with `0x90` (port to memory) or `0x80` (memory to port). `plp_stop_dma` (`+0x1cd0`) reads bit 4 of the control register (direction); for a port-to-memory transfer it reads bits 22:16 of `+0xb8`
(bytes still in the port FIFO) and copies them out by hand when the count is one to three; otherwise it sets flush (bit 6) and polls bit 7 clear,
100 times at most, then clears bits 7:6. `plp_reset` (`+0x1ef0`) sets reset (bit 0), clears it, waits 400 microseconds,
clears the status byte, stores 3 into it and pulses soft-ack (bit 3). **Established.** The port's interrupt arrives as local source 1.

**Unknown:** the strobe timing fields (header only); what `+0xbc` does; the reset values.

## DSP audio interface

The registers at `+0x180` to `+0x1b4` and the SRAM at `+0x60000` are the host side of the DSP56001 block. The register meanings are
**inferred** from the shipped header alone; the audio page [hollywood-dsp](../hollywood-dsp/README.md) lists them. What the IP20 PROM does is
**established** from its code: at start-up it stores 9 (reset and 32K-word SRAM) to `+0x1b0` (`0xbfc0089c`), clears the two headphone gain
converters at `+0xd30` and `+0xd34`, and later (`0xbfc01f5c`) stores 1, writes -1 to SRAM word 0, copies two tables into SRAM (one at
`+0x68000`, one interleaved at `+0x78000`), stores 8 (run), waits 50 microseconds, reads SRAM word 0 under a 24-bit mask expecting 1 or 2 and
bit 7 of word 1 clear, then reports the low byte of word 1 as the audio revision (the `hinv` text "Iris Audio Processor: revision %d" prints the same value). That fixes the reset
and run handshake and nothing more. The DSP-to-host interrupt is local interrupt source 12 (`VECTOR_DSP`, header).

**Unknown:** every DMA, handshake and burst field (open question in [questions/hpc1.md](../../questions/hpc1.md)). The chips page for the DSP says the
driver object is not held; the IP20 `kdsp` archive in this reading reaches the block only through a pointer table and was not decoded.

## Serial windows, keyboard and mouse, clock

The four 16-byte blocks at `+0xd00`, `+0xd10`, `+0xd20`, `+0xd30` hold one Z85C30 each for the first three (control B at +0, data B at +4,
control A at +8, data A at +0xc, each in its own word with the byte in bits 7:0, so a big-endian access is at offset +3), and the fourth
block's two words are the headphone gain converters (`+0xd30`, `+0xd34`). **Established** (header; serial driver port table in `sduart.a`
lists twelve addresses, `0xbfb80d03` to `0xbfb80d2f` by 4; the IP20 PROM table at `0xbfc44710` lists the same twelve). The interrupts of the
serial blocks are OR-ed into local source 5.

Which port is the keyboard and the mouse: the serial driver exports `du_keyboard_port` and `du_mouse_port`; the NetBSD driver attaches its
console to the block at `+0xd10` channel 1 and the blocks at `+0xd00` as the other serial ports on an IP20 and IP12 (boot logs for both). The
mapping of keyboard and mouse to channels within the blocks is **inferred** and belongs with the Z85C30 reading. The PROM's early Z85C30 write (`0xbfc008e8`, 5 then `0x6a` to `+0xd0b`) is a chip matter, not an HPC1 one.

The real-time clock window at `+0xe00` is read and written as words (`kernel.o` time-of-day routine, `lw` and `sw` at `+0xe00` to `+0xe6c`). The PROM
tests two bytes at `+0xe57` and `+0xe5b` (it writes 0xa5 then 0x5a and compares) as a "RTC path test" (string in the PROM). **Established.** The
clock chip's registers are not covered here.

## Auxiliary byte and the serial EEPROM

`+0x1bc` (byte at `+0x1bf` big-endian) drives a serial EEPROM, an FM93CS56 or compatible 2 Kbit part wired as 128 words of 16 bits. The four
wires are bits 1 to 4 and bit 0 is the part's PRE pin, shared with the console LED. IRIX names the bits `CONSOLE_LED`/`NVRAM_PRE` (0x01),
`CONSOLE_CS` (0x02), `SERCLK` (0x04), `CPU_TO_SER` (0x08) and `SER_TO_CPU` (0x10). **Established** (header, kernel `get_nvreg` and `set_nvram`,
PROM routines `0xbfc2a7c8` to `0xbfc2b300`). The fifth control, bit 4, is read-only.

**Cycle** (PROM `0xbfc2aa78`, `0xbfc2aac8`, `0xbfc2ab18`; kernel `+0x5364`, `+0x53e8`, `+0x5450`). All established.

1. Start: keep bit 0, clear the others, set CS, set SK.
2. Instruction: shift a 16-bit word out MSB first for **11 bits**, one bit per cycle: set or clear DI, clear SK, set SK (the part latches DI on the
   rising edge). The word is `opcode | (address << 5)`. After the last bit, clear DI.
3. Read: for 16 bits, clear SK, set SK, then sample bit 4 and shift it in, MSB first. The part's dummy zero bit is skipped by the first
   rising edge. A word read leaves SK high.
4. Write: send write-enable `0x9800`, drop CS (clear SK, clear CS, set SK), start, send `0xa000 | (address << 5)`, shift 16 data bits MSB first,
   clear DI, drop CS, raise CS and poll bit 4 until it reads one (up to 200 reads, 100 microsecond apart, PROM `0xbfc2abcc`), drop CS, send
   write-disable `0x8000`.
5. End: clear SK, clear CS, set SK, with bit 0 restored to the caller's value. Every access saves bit 0 on entry and restores it on exit, and
   clears PRE for the whole cycle except the protect-register operations.

**Opcodes** (the six `SER_*` and `SER_PR*` values of the NVRAM header): read `0xc000`, write-enable `0x9800`, write `0xa000`, write-all `0x8800`,
write-disable `0x8000`, protect-register read `0xc000`, protect-enable `0x9800`, protect-write `0xa000`, protect-clear `0xffff` (clear the
protect register, a one-time lock the PROM sets with PRE high), protect-disable `0x8000`. The address field is 8 bits wide (bits 12:5) but only
0 to 127 are valid words. **Established** for read, write, enable, disable and the protect-clear and protect-write cycle (PROM `0xbfc2b130`: it
writes `0xffff`, then protect-write at address 125, polling ready each time, printing the two "did not complete" strings if not).

**Timing:** software only; the PROM spaces the ready poll at 100 microseconds and nothing else is delayed (a model can take the part as
instant). The write itself completes when DO reads one. **Established** as software behaviour; the part's timings are not read.

**Words and bytes.** Byte `2n` is the high byte of word `n`, byte `2n+1` the low byte (PROM `0xbfc2acac`, kernel `get_nvreg` byte routines). The
PROM caches the 128 words in RAM after the first read. **Established.**

**Layout** (NVRAM header revision 6, 256 bytes; the PROM's 25-record table at `0xbfc45760` carries the same offsets and lengths):

| Offset | Length | Variable |
|---|---|---|
| 0 | 1 | checksum |
| 1 | 1 | layout revision, 6 |
| 2 | 2 | `console` |
| 4 | 48 | `SystemPartition` |
| 52 | 18 | `OSLoader` |
| 70 | 28 | `OSLoadFilename` |
| 98 | 12 | `OSLoadOptions` |
| 110 | 6 | `pagecolor` |
| 116 | 5 | `dbaud` |
| 121 | 1 | `diskless` |
| 122 | 6 | old Ethernet address, kept for old PROMs |
| 128 | 8 | `TimeZone` |
| 136 | 48 | `OSLoadPartition` |
| 184 | 1 | `AutoLoad` |
| 185 | 2 | `diagmode` |
| 187 | 4 | `netaddr` |
| 191 | 1 | `nogfxkbd` |
| 192 | 5 | `keybd` |
| 197 | 6 | `lang` |
| 203 | 17 | `passwd_key` |
| 220 | 17 | `netpasswd_key` |
| 237 | 1 | `scsiretries` |
| 238 | 3 | `volume` |
| 241 | 1 | `scsihostid` |
| 242 | 1 | `sgilogo` |
| 243 | 1 | `nogui` |
| 244 | 1 | `rbaud` (x 1200) |
| 245 | 5 | free |
| 250 | 6 | Ethernet address, write-protected |

All **established** (header offsets and PROM record table agree). The write-protected tail is words 125 to 127, the protect-register value
written at address 125. **Checksum:** start with `0xa5`; for word 0 take only its low byte (the layout revision), for words 1 to 127 take
the high byte XOR the low byte; XOR it into the accumulator and rotate the 8-bit accumulator left by one bit after each word; the result is
byte 0. **Established** (`kernel.o+0x5788` and PROM `0xbfc2a6d0`, identical). The PROM tests it twice before it declares the store invalid
and re-initialises from the defaults (string "NVRAM checksum is incorrect: reinitializing the NVRAM.").

Open point: the R4000 start-up flip routine (see the [Indigo PROM page](../../platforms/ip20/prom-software.md)) reads word 0, XORs `0x8400` into
it and writes it back through the MC's EEPROM register. Word 0's high byte is this layout's checksum byte, which the checksum itself does not
include, so after a flip the stored byte no longer equals the computed one and the PROM's next check would report the NVRAM invalid. Whether
the PROM or IRIX rewrites it, or the flip is only for a boot that is about to be redone, is **unknown** (question filed).

QEMU qtest hooks: write the EEPROM instruction stream bit by bit through `+0x1bf` and read word 0; a write without write-enable must not stick; the
checksum of an image the PROM wrote validates; the protected tail rejects writes once the protect register is set.

## Interrupt status

The HPC1 has no interrupt-status register of its own for the DMA channels. Per-channel flags are bit 1 of `+0x3c` (Ethernet pending),
bit 1 of `+0xb4` (parallel pending) and the three bits of `+0x1a0` (DSP). They are aggregated by the interrupt controller into local sources
(header): 0 FIFO or GIO 0, 1 parallel, 2 SCSI, 3 Ethernet, 4 graphics DMA, 5 serial, 6 GIO 1 and the second HPC, 7 VME 0, and in the second
register 12 DSP and 13 AC-fail. A second or third HPC reaches the CPU through the GIO slot interrupts (`setgiovector`) rather than through the on-board local
vector. **Established** (header, `if_ec2.o+0x31c`, `wd93.o` and `hpcplp.o` vector numbers).

## What the IP20 PROM touches in the HPC1 window, and who owns each register

Every constant-address access of the 4.0.5D image (a scan of all `lui`/`ori` address pairs with the access width; indirect accesses through
the SCSI chip table at `0xbfc52f80` and the serial port table at `0xbfc44710` are in the table's last rows). Owner means the page that
holds the register's contents.

| Offset (from `0xbfb80000`) | Access (PROM address) | Owner | Grade |
|---|---|---|---|
| `+0x05b`, `+0x05f` | byte read of `+0x5f`, then store `0x5a` to `+0x5b` (`0xbfc029e4`, `0xbfc029f4`), inside the power-on peripheral check | HPC1 (Ethernet receive FIFO pointer and data slots by the driver's dump labels); the check's purpose is **unknown**. Only the store is ever made; no value is compared. | access: established; role: unknown |
| `+0x094` | one word store of 0 (`0xbfc00974`) | HPC1, SCSI control: clears reset, flush, direction, start | established |
| `+0x0ac` | walking one from bit 27 down to bit 0 written to `+0xac` and read back (`0xbfc02910`..`0xbfc02948`; the same test on MC `+0xd4` at `0xbfc028b0`) | HPC1, parallel current buffer pointer | established: a mismatch jumps to a failure stub, so the register must hold the 28 low bits |
| `+0x0c0` (`+0xc3`) | word read, bit 0 test, word store 0 (`0xbfc003fc`..); later a guarded byte store and a masked store (`0xbfc08e00`) | HPC1, endian and revision byte | established |
| `+0x122`, `+0x126` | WD33C93 address and data bytes (`0xbfc02960`; 0x17 written to the address port, a read of the data port to clear it, 0x02 to the address port, 0xa5 to data, readback compare) | WD33C93 behind HPC1 | established |
| `+0x1b0` | word stores 9 (`0xbfc0089c`), 1 and 8 (`0xbfc01f78`, `0xbfc02040`) | HPC1, DSP miscellaneous control | established values; field meanings inferred |
| `+0x1bf` | byte read-modify-write of bit 0 (LED), and the whole EEPROM cycle | HPC1, auxiliary byte | established |
| `+0x1c3` to `+0x1df`, `+0x1e3`, `+0x1f0` to `+0x1ff` | local interrupt status and mask, VME masks, port config, timer acknowledge, 8254 counters and control | not HPC1: interrupt controller and 8254 timer, see [int2](../int2/README.md) | established there |
| `+0xd03` to `+0xd2b` (every fourth byte), `+0xd33`, `+0xd37` | Z85C30 control and data bytes; the console is the block at `+0xd10` (`+0xd13` control, `+0xd17` data) by the NetBSD log; headphone converters written zero | Z85C30 and headphone converters; the window is HPC1's, the chip registers belong to a serial-controller page not yet written | window established |
| `+0xe00` to `+0xe74` | clock block: word read/write at `+0xe00 + 4n`, byte test at `+0xe57`, `+0xe5b` (`0xbfc02a00`) | the real-time clock behind HPC1 (the shipped header's clock structure is `dp8573_clk`, NetBSD's `dp8573areg.h`; the prior-art survey says DP8572A); the chip's register meanings belong to a clock page not yet written | window established |
| `+0x50000` (`0xbfbd0000`) | word read of the board revision | board, see [address map](../../platforms/ip20/address-map.md) | established |
| `+0x60000`.. (`0xbfbe0000`, `0xbfbe8000`..`0xbfbe8e2c`, `0xbfbf8000`..) | DSP SRAM: word 0 written -1, tables copied into SRAM at `0xbfbe8000` (a 1584-byte table, then 80 pairs whose first word goes after it and whose second word goes 64 KiB higher), words 0 and 1 read back after the DSP is released | HPC1 window, DSP SRAM: this is the DSP's memory, not Seeq or SCSI buffer RAM and not a second HPC. The 4.0.5D copy loop ends near `0xbfbe8770`; a model run that stops at `0xbfbe8e2c` is running different table lengths and is a lead to check, not a PROM fact | window established; purpose of the tables: unknown (DSP code or sample data) |
| SCSI chip table at `0xbfc52f80` | one entry: address `+0x122`, data `+0x126`, control `+0x94`, count `+0x88`, current pointer `+0x8c`, next descriptor `+0x90`, pointer `+0x98`, FIFO `+0x9c`, flags `0x60800000` | HPC1 SCSI channel; the PROM has one channel entry, so it never uses a second HPC's SCSI | established |

**SCSI channel reset as the PROM performs it** (the "controller didn't reset correctly" message, `0xbfc14940`). The PROM's chip reset routine
(`0xbfc147e4`) does, through the chip table: poll the address port (`+0x120` lane) until bit 4 (chip busy) reads zero; the first time only, write
address 0x11 and read the data port; write address 0x00 (the chip's own-ID register, bits from the table) with the host ID; if bit 7 of the
address port reads one (an interrupt is pending) write address 0x17 and read the data port to clear it; write address 0x18 (command register)
with 0 (the chip's reset command); wait in `0xbfc168cc` for bit 7 of the address port (interrupt pending), polling every 8 microseconds for at most the given count divided by
eight after first waiting out bit 4, then read the status register through address 0x17; if the wait timed out the routine ORs `0x1000` into
the status and the caller prints "scN controller didn't reset correctly". The chip then answers with status 0 or 1 (reset, with or without the advanced
features bit), which the PROM records. **Established for the order of accesses and the register numbers** (they are the WD33C93's own register
file, which the WD33C93 page covers). The HPC1 contributes only the byte lane, the wait on the address port's status bits and, before this
routine, the control register clear at `+0x94` that happens once at power-on (`0xbfc00974`). The PROM never writes the control register's reset
bit; the kernel's bus reset does (above). **Established.**

**Clock wait:** the PROM's clock start routine (`0xbfc2c878`) writes zero to `+0xe00`, reads the byte at `+0xe14` (register 5, the 1/100 s counter by
the NetBSD register header: `DP8573A_SUBSECOND`), and then polls the same byte until it differs from the first read, at most 999 999 times
(`0xf423f`), returning 0 when the value moved and 1 on a timeout. It is bounded, not infinite; a model that holds the byte constant makes the
PROM report the clock path as failed ("RTC path test *FAILED*") after about a million reads. The clock initialisation routine (`0xbfc2c740`)
zeroes registers 25 to 29 (`+0xe64` to `+0xe74`), writes 0x80 then 0 to register 4 (`+0xe10`) and zero to register 0. **Established** for the
accesses; the register names are NetBSD's (**inferred** for the part wired here).

## Misc, reset and unexplored

- **Reset values:** none established. The PROM clears `+0x94` and writes the Ethernet and DSP controls before it uses them, which rules out
  relying on a power-on state; no PROM or kernel path reads a register before first writing it.
- **PROM power-on probes:** the IP20 PROM walks one bit through the parallel current-buffer pointer (`+0xac`) and the Ethernet receive FIFO pointer
  and port at `+0x5b`/`+0x5f` and through several peripheral registers, to check the HPC's own paths. The bytes it checks establish the
  registers hold written values; nothing more is read from them.
- **Unreached:** `+0x00` content, `+0x04`, `+0x30`, `+0x40`, `+0x60` to `+0x84`, `+0xc4` to `+0xfc` (other than the Seeq window and the
  WD33C93 pair) show no software access.

## Register-contract test hooks, one line per block

| Register or block | A test that tells a right model from a wrong one |
|---|---|
| `+0xc0` endian | write `0x1f`, read it back; write 0, read it back; bits 7:6 unchanged by either |
| `+0x10`..`+0x5c` Ethernet DMA | after a start write (`+0x34` bit 22, `+0x38` bit 14) the bit reads 1 until the chain ends, then 0; a chain ending in a descriptor with word-1 bit 31 stops the channel |
| `+0x3c` | 7 then 4 resets the channel and chip; bit 1 reads 1 only with an interrupt pending and clears on a write of bit 1 |
| `+0x2c` | `0x01000000` and any other value read back unchanged |
| `+0x100`..`+0x11c` | eight words, byte in bits 7:0, reach the Ethernet chip registers n at 4n |
| `+0x88`..`+0x94` | next-descriptor write plus control `0x80`/`0x90` starts a chain; control bit 7 clears at the end of the chain; flush bit 1 forces it clear; control 1 then 0 resets the chip |
| `+0x120`, `+0x124` | a byte written to the data port after 0x02 in the address port reads back; 0x17 then 0xa5 in the same way |
| `+0xa8`..`+0xb8` parallel | the same descriptor chain and start/flush behaviour with control `0x90`/`0x80`; `+0xac` holds 28 bits; control bit 1 reads pending and clears on write |
| `+0x134` | byte in bits 23:16, no side effect |
| `+0x180`..`+0x1b4` | stores and loads of the DSP registers; misc bit 0 holds the DSP in reset; SRAM at `+0x60000` reads back what was written, 24 bits, upper 8 bits zero (inferred) |
| `+0x1bc` | EEPROM: the read cycle returns word 0; a write without enable does not stick; bit 4 reads 1 when the write completes; bit 0 is preserved |
| `+0x1c0`..`+0x1ff`, `+0xd00`.., `+0xe00`.. | window decode only; see the INT2 page and the serial and clock pages |
| `+0xe14` | the clock's 1/100 s counter changes between two reads taken a few thousand instructions apart (the PROM's clock probe) |
| `+0x50000` | reads the board revision word; the PROM treats `~word & 0x7000` as the revision |
