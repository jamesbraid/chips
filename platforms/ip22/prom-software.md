# Indigo2 (IP22) PROM 5.3 Rev E: what its own software does

This page records what the shipped IP22 PROM image `SGI Version 5.3 Rev E IP22 Jan 29, 1996 (BE)` does: part 070-1367-012, 524288 bytes,
sha256 `7b3eb33889bcc40c3dadc7093c06d3e221b6e2a5073acc556f62932b08b6cd8a`. The image is listed in
[prom-images.md](../../references/prom-images.md). It is read from the image alone, as MIPS code loaded at virtual `0xbfc00000`
(image offset = address minus `0xbfc00000`). Addresses below are image addresses in that window. The `0x9fc` and `0xbfc` windows are the
same bytes.

Grades: **established** (read in full in the disassembly), **inferred** (reasoned from a partial read, a name or a public header),
**unknown**. Disassembly is from the MIPS objdump in the toolchain container; the decompiler was used for navigation only. Register
names for the memory controller (MC) come from the public Linux `arch/mips/include/asm/sgi/mc.h`. The component class and type numbers
come from the public NetBSD `arcbios.h`, whose SGI branch carries SGI's own numbering.

The environment store layout, checksum and write order are on [prom-environment.md](prom-environment.md) for the 5.1 Rev B image. The
5.3 Rev E table below has the same offsets and lengths, so that page's layout applies. The checks made here are in the first section.

## Images and differences from 5.1 Rev B

Held IP22 and IP24 images (sha256 prefix, part, version):

| Image | Part | Version | Note |
|---|---|---|---|
| `be6b22c3…` | 070-8127-002 | IP22 5.1 Rev B, Sep 16 1993 | also circulates under the file name 070-1367-002 |
| `7b3eb338…` | 070-1367-012 | IP22 5.3 Rev E, Jan 29 1996 | this page |
| `ea680082…` | 070-9101-007 | IP24 5.0 Rev B6, Sep 28 1994 | |
| `333a0b2e…` | 070-9101-011 | IP24 5.3 Rev B10, Feb 12 1996 | |
| `d7ffc8e1…` | not recorded | IP24 5.3 Rev B10 | the previous row with each 16-bit pair swapped; swapping back gives `333a0b2e…` exactly |

Strings that Rev E has and Rev B does not (established, string set difference): the Impact (MGRAS) board names ("Solid Impact",
"High Impact", "High-AA Impact", "Maximum Impact"), a startup tune stage, `NVRam=Locked`, `PASSWD JUMPER MISSING--forced to g.`,
`ConsoleWarning`, `R4600_PARITY`, an `initstate` variable read, an `ide` boot path `bootp()mgras.ide.IP22`, an ELF loader with
diagnostics, an I2C driver for the Impact board, and a memory test that requires a bank of at most 128 MB. Rev B's NVRAM debug
strings (`get_nvreg`, `nvchecksum`) are gone. The environment record table, command table and ARCS vector layout are the same shape.

## Reset path and the Config.BE test (established)

The first word at `0xbfc00000` is `j 0xbfc003c0`, and the slots that follow (`0xbfc00008`, `0xbfc00010`, and so on) jump to `0xbfc007d8`; a few later slots (for example offset `0x200`) jump elsewhere. The reset routine at `0xbfc003c0`:

```
bfc003c0  lui   v0,0x3041        ; Status = 0x30410000
bfc003c4  mtc0  v0,c0_sr
bfc003c8  mtc0  zero,c0_cause
bfc003cc  mtc0  zero,c0_pagemask
bfc003d0  mtc0  zero,c0_watchlo
bfc003d4  mtc0  zero,c0_watchhi
bfc003d8  li    v0,2             ; Config = 2 (K0 field = 2, rest zero)
bfc003dc  mtc0  v0,c0_config
bfc003e0  mfc0  v0,c0_config     ; read back
bfc003e8  andi  v0,v0,0x8000     ; Config bit 15, the BE bit
bfc003ec  bnez  v0,0xbfc003fc    ; big endian: skip the flip
bfc003f4  jal   0xbfc01f00       ; little endian: flip routine
bfc003fc  ...                    ; carry on with memory controller setup
```

The routine at `0xbfc01f00` saves `ra` in `k1`, then:

```
bfc01f00  move  k1,ra
bfc01f04  jal   0xbfc01ff4       ; v0 = word 0 of the serial EEPROM  (a0 = 0)
bfc01f08  move  a0,zero
bfc01f0c  xori  a1,v0,0x8400     ; toggle bit 15 and bit 10
bfc01f10  jal   0xbfc02070       ; write a1 to word 0                (a0 = 0)
bfc01f14  move  a0,zero
bfc01f18  lui   v0,0xbfa0
bfc01f1c  lui   v1,0x1
bfc01f20  sw    v1,0(v0)         ; store 0x00010000 at 0xbfa00000
bfc01f24  jr    k1
```

So a little-endian result is repaired by reading the 16-bit word 0 of the CPU-mode serial EEPROM, XORing `0x8400` into it, writing it
back, and storing `0x10000` to the MC base. The serial EEPROM is the MC register at `0xbfa00034` (public header: "EEPROM byte reg for
r4k"; bits PRE `1`, CS `2`, SK `4`, data out `8`, data in `0x10`). Established: the code path, the exact words, the bit protocol.

- The read at `0xbfc01ff4` sends the 11 bits `110` plus an 8-bit word address (`a0 = 0xc000`, word number shifted left 5), then clocks
  in 16 bits. The write at `0xbfc02070` sends EWEN (`0x9800`), then WRITE (`0xa000` plus the word number), 16 data bits, waits for
  ready with `0xbfc0212c` (it polls bit `0x10` and toggles a front-panel register at `0xbfbd9870` between `7` and `0x27` while it waits),
  then EWDS (`0x8000`). This is the standard 93C56-family microwire sequence. Established (sequence); the part number is inferred.
- Inferred: bit 15 of the stream is the endianness bit that reaches `Config.BE` after the next CPU reset, and the store of `0x10000`
  to the MC is the reset that makes it take effect. The public header has `0x10000` as `WRESETPMEM` (warm reset, memory preserved), but
  at register offset `+4`; this PROM stores at offset `0`. Why offset 0 works is unknown.
- Unknown: what bit 10 of the `0x8400` mask does. It is XORed together with bit 15 and no other code names it.
- Other callers (checked by a scan of every `jal`): `0xbfc01f00` is called only from the reset routine. `0xbfc02070` is called only from
  `0xbfc01f00`. `0xbfc01ff4` is also called from `0xbfc0ea14`, which reads word `0x11` of the same EEPROM when the CPU is an R4600
  family part (PRId implementation `0x20`) and uses it as a secondary-cache size, see below. No other writer of the MC EEPROM register
  exists: the only six references to `0xbfa00034` are inside `0xbfc01f2c` to `0xbfc0213c`.
- The reset test never writes `Config.BE`. The write of `2` to Config affects only the K0 field.

After that the reset path (established as call order, roles inferred):

1. `0xbfc00404` to `0xbfc00528`: clear MC registers `+0xec` and `+0xfc`; write `CPUCTRL0` (`0xbfa00004`) as
   `0x3c002014 | (((n >> 3) + 4) << 20)`, where `n` is the secondary-cache line size `1 << (Config[23:22] + 4)` when `Config.SC` (bit 17) is clear and
   `32` or `16` (from `Config[5:4]`) when it is set; write `CPUCTRL1` (`0xbfa0000c`) as `0x16`; write memory-timing words at `+0x84`, `+0xd4`, `+0xdc`
   and `0x104` at `+0x2c`.
2. A short busy-wait on the MC refresh counter at `0xbfa01004` (625 ticks).
3. `jal` to `0xbfc00964`, `0xbfc00b2c`, `0xbfc00d4c`, `0xbfc00cb4`: set up peripheral-bus and interrupt-controller registers
   (accesses in `0xbfb9xxxx`, `0xbfbbxxxx`, `0xbfbdxxxx`).
4. `0xbfc03e00`, `0xbfc04200`, then `0xbfc042d0` (it prints the bus path test failures "WD SCSI0 path test", "RTC path test", "INT path test", "Data
   path test"), then `0xbfc00f50` (memory configuration, below).
5. Test of the MC bank words at `0xbfa000c4` and `0xbfa000cc`: if none of the four half-words has bits `0x2200` equal to `0x2000`,
   the low nibble of `CPUCTRL0` is set to `2`.
6. `0xbfc008fc` stores `0xfeeddead` at `0xa87c7d40` (an "initialised" marker, tested later by `0xbfc00638`), puts the stack at `0x087ffff0` in the segment
   the return address came from, calls `0xbfc0195c`, then `j 0xbfc021a0` (the main routine).

## Memory and cache initialisation

Memory (established as flow, inferred as roles). `0xbfc00f50` zeroes the two MC bank configuration registers (`+0xc4`, `+0xcc`), then
for each of four banks probes it (`0xbfc01540`), programs the bank word (`0xbfc01884`) and checks size and data
(`0xbfc04840`, `0xbfc013d0`). It stops with "No usable memory found. Make sure you have a full bank (4 SIMMs)." when no bank is usable,
with "Need at least one bank of memory that is less than or equal to 128M" when none is that small, and with "Memory diagnostic
(address test) *FAILED*" when `0xbfc04be0` fails at `0xa8000000`. Memory therefore starts at physical `0x08000000`. After the test
it programs the MC DMA registers (`0xbfa02004` to `0xbfa0204c`) to clear memory with the virtual DMA engine, printing the error dump on failure (decompiler
reading, inferred), and on success zeroes cache tags at `0x88020000` and each doubled address up to `0x88400000` (cache ops `9`, `8`, `0xb`).

Primary caches (established, `0xbfc0e8e4`): primary I size = `1 << (((Config >> 9) & 7) + 12)`, primary D size =
`1 << (((Config >> 6) & 7) + 12)`; both lines 16 bytes (`0x10`, mask `0xf`), and the values are saved in a table at `0xa87c7d48`.

Secondary cache (established, `0xbfc0eadc`): if Config bit 17 (SC) is set the function returns 0, meaning none. Otherwise it stores
zero tags with cache ops `8`, `9`, `0xb` at `0x88000000`, then loops `size = 0x20000; size <<= 1` up to `0x400000`, issuing cache op `7` at
`0x88000000 + size` and stopping at the first `size` where `TagLo` reads back zero. That size is the secondary cache size, 128 KB to
4 MB. The table at `0xa87c7d5c`/`0xa87c7d6c` gets line size `0x80` and mask `0x7f` when a secondary cache is found and `0x10`/`0xf` when not (decompiler
reading, inferred). For an R4600-family CPU with no secondary cache the code also reads EEPROM word `0x11`, shifts it left 12 to a size, and raises the
line sizes to `0x20` (mask `0x1f`).

Cache mode switching: `0xbfc04c88` sets `Config.K0` to `3` (cached), `0xbfc04cc8` sets it to `2` (uncached). `0xbfc0083c` clears the
first part of RAM at `0xa8740000..0xa87ffffc` with index write-back-invalidate ops (`cache 0x3`) in 64-byte steps. The cache op
numbers are the `rt` field of the `cache` instruction; their names come from the public MIPS R4000 manual (inferred).

## Memory descriptors (established)

Nodes are 20 bytes: `type`, `base page`, `page count`, magic `0x4b45565e` at `+0xc`, `next` at `+0x10`, kept in order of base page, head
pointer at `0xa87416e0`. They are created by `0xbfc1145c`; `0xbfc111e4` splits a node to retype a page range; `GetMemoryDescriptor` is
`0xbfc11160` (null returns the head; any other pointer returns its `next` if the magic matches). Initial list, from `0xbfc111a0`:

1. FreeMemory from physical `0x08002000`, length `min(total bank size below 0x20000000, 0x10000000)` in pages minus 2 (`0xbfc0c4ac`).
2. FreeMemory pages 0 and 1.
3. Page 1 (`0x1000`) retyped to type 1 (system parameter block); page 0 retyped to type 0 (exception block).

Type numbers are the SGI numbering of the public NetBSD header: 0 exception block, 1 SPB, 2 free contiguous, 3 free memory, 4 bad,
5 loaded program, 6 firmware temporary, 7 firmware permanent. Established: the values used; inferred: that these match the shipped IRIX use.
Unknown: how banks above `0x20000000` (the second window) become descriptors; no code that adds them was found.

## ARCS system parameter block and call table (established)

The block is built at `0xa0001000` by `0xbfc37660` (which is also private-vector slot 9). Fields written (offset: value):
`+0` signature `0x53435241`; `+4` length `0x48`; `+8` version `1`; `+10` revision `10`; `+0xc` restart block `0`; `+0x10` debug block `0`;
`+0x14` general-exception vector `0x9fc36350`; `+0x18` UTLB-miss vector `0x9fc364a4`; `+0x1c` firmware vector length `0x8c`;
`+0x20` firmware vector `0xa0001800`; `+0x24` private vector length `0x34`; `+0x28` private vector `0xa0001c00`; `+0x2c` adapter count `0`.
The 35 firmware entries are copied from ROM `0x9fc77770` to `0xa0001800`, the 13 private entries from `0x9fc777fc` to `0xa0001c00`.
Slot numbering and names follow the public ARC layout (NetBSD `struct arcbios_fv`); each name below is checked against the routine's behaviour:

| Offset | Slot | Routine | Name | Grade |
|---|---|---|---|---|
| `0x00` | 0 | `0xbfc377cc` | Load (path, top, &entry, &low) | established |
| `0x04` | 1 | `0xbfc37918` | Invoke | established |
| `0x08` | 2 | `0xbfc37c24` | Execute (Load then Invoke) | established |
| `0x0c` to `0x18` | 3-6 | `0xbfc00618`, `0xbfc00620`, `0xbfc00628`, `0xbfc00630` | Halt, PowerDown, Restart, Reboot: Halt, Restart and Reboot load `s0` = 1, 3, 4 and jump to `0xbfc006cc`; PowerDown jumps to `0xbfc00e40` | inferred |
| `0x1c` | 7 | `0xbfc00638` | EnterInteractiveMode: if the caller is inside the PROM and the `0xfeeddead` marker is set, it re-enters the monitor (`0xbfc43e9c`, or `0xbfc02cf0` with a fresh stack); otherwise it restarts with `s0` = 5 | inferred |
| `0x20` | 8 | none | reserved | established |
| `0x24` to `0x3c` | 9-15 | `0xbfc31fa8`, `31fb4`, `31fd8`, `31fe4`, `32034`, `322f8`, `3a3c0` | GetPeer, GetChild, GetParent, GetConfigurationData, AddChild, DeleteComponent, GetComponent | inferred (AddChild verified by its callers) |
| `0x40` | 16 | `0xbfc32424` | SaveConfiguration | inferred |
| `0x44` | 17 | `0xbfc10ed4` | GetSystemId | inferred |
| `0x48` | 18 | `0xbfc11160` | GetMemoryDescriptor | established |
| `0x4c` | 19 | none | reserved | established |
| `0x50`, `0x54` | 20, 21 | `0xbfc10dfc`, `0xbfc42230` | GetTime, GetRelativeTime | inferred |
| `0x58` | 22 | `0xbfc10d34` | GetDirectoryEntry | inferred |
| `0x5c`, `0x60` | 23, 24 | `0xbfc10360`, `0xbfc10b98` | Open, Close | established (Open used by console setup) |
| `0x64`, `0x68`, `0x6c`, `0x70` | 25-28 | `0xbfc10778`, `0xbfc10ee0`, `0xbfc10a38`, `0xbfc10c68` | Read, GetReadStatus, Write, Seek | established for Write and Seek; inferred for the others |
| `0x74` | 29 | `0xbfc10fa4` | Mount | inferred |
| `0x78`, `0x7c` | 30, 31 | `0xbfc11070`, `0xbfc11050` | GetEnvironmentVariable, SetEnvironmentVariable | established |
| `0x80`, `0x84` | 32, 33 | `0xbfc11090`, `0xbfc11130` | GetFileInformation, SetFileInformation (returns 7) | established |
| `0x88` | 34 | `0xbfc0e898` | FlushAllCaches | inferred |

There is no TestUnicodeCharacter or GetDisplayStatus slot: the vector is 140 bytes. The I/O calls fill a request packet (opcode at `+0`:
`4` write, `6` get-read-status, `10` mount, `0x11` get-file-information), then call the driver through a function pointer in the packet.
Private vector, 13 entries (names unknown): `0x9fc0d1e8`, `0x9fc101f4`, `0x9fc378a4`, `0x9fc37c00` (calls Invoke), `0x9fc37d48`
(sets a flag at `0xa8746004` and calls Execute), `0x9fc39510`, `0x9fc395b0`, `0x9fc16100`, `0x9fc35990`, `0x9fc37660` (builds the SPB),
`0x9fc0c320` (returns 0), `0x9fc42390`, `0x9fc36edc`.

## Environment and NVRAM (established)

`GetEnvironmentVariable` searches a list of arrays whose head is at `0xa8746f90`. `SetEnvironmentVariable` is `0xbfc39cb0(name, value, flag)`.
It first walks a 7-entry table at `0x9fc77880` (count at `0x9fc778d4`; entries are name, RAM cell, flags):

| Name | Flags | Behaviour |
|---|---|---|
| `DEBUG`, `VERBOSE`, `_udpcksum` | 2 | value copied to a RAM integer cell at `0xa8746f30` and following |
| `gfx`, `cpufreq`, `eaddr` | 1 | read-only unless the caller passes flag 1; otherwise returns 2 |
| `NVRam=Locked` | 4 | a value starting with `*` calls `0xbfc02c28(1)` (see below) |

For every name it then calls `0xbfc02bc8` (a jump to `0xbfc0fc98`, the per-record NVRAM writer, which does nothing for a name without a record) and, unless that returned 2, stores the string in the RAM environment with `0xbfc4b694`.
The record table is at `0x69f60`, 44 bytes each: name (28 bytes), default-value pointer at `+0x20`, NVRAM byte offset at `+0x24`, length at
`+0x28`. The same offsets and lengths as [prom-environment.md](prom-environment.md):

`console`@2/2 (default `g`), `SystemPartition`@4/48, `OSLoader`@0x34/18, `OSLoadFilename`@0x46/28, `OSLoadOptions`@0x62/12,
`pagecolor`@0x6e/6, `dbaud`@0x74/5 (`9600`), `diskless`@0x79/1 (`0`), `TimeZone`@0x7a/8 (`PST8PDT`), `OSLoadPartition`@0x82/48,
`AutoLoad`@0xb2/1 (`Yes`), `diagmode`@0xb3/2, `netaddr`@0xb5/4 (default string `192.0.2.1`, stored as 4 bytes), `nogfxkbd`@0xb9/1,
`keybd`@0xba/5, `lang`@0xbf/6, `passwd_key`@0xc5/17, `netpasswd_key`@0xd6/17, `scsiretries`@0xe7/1, `volume`@0xe8/3 (`80`),
`scsihostid`@0xeb/1, `sgilogo`@0xec/1 (`y`), `nogui`@0xed/1, `rbaud`@0xee/1, `autopower`@0xef/1 (`y`), `monitor`@0xf0/1,
`rebound`@0xf1/1, `eaddr`@0xfa/6 (`ff:ff:ff:ff:ff:ff`). Offsets 0 (checksum) and 1 (revision `8`) have no record; `0xf2` to `0xf9` are unused.
Record special cases in `0xbfc0fc98`: `netpasswd_key` and `passwd_key` cannot be set with `setenv`; `AutoLoad` stores a mapped single
byte; `netaddr` is parsed to 4 bytes; `rbaud` stores `baud / 1200` in one byte (divisor `0x4b0`); `autopower` triggers `0xbfc0e1b8` after the write;
`eaddr` is parsed to 6 bytes and refused (return 2) when the lock check `0xbfc02c68` says the store is locked.

NVRAM access (established): the interface is one byte at `0xbfbb000b`, pointer constant at `0x9fc6a460` (SK `4`, CS `2`, data in `8`, data out `0x10`,
bit 0 around erase/write-all). The 128 words are read at `0xbfc11710` with the command `0xc000 | word` and cached in RAM at `0xa87416f0`
(valid flag `0xa87417f0`). `0xbfc11ccc` writes byte ranges: partial words are read-modify-written, and unless the offset is 0 it then rewrites
byte 0 with the checksum from `0xbfc11620`: start `0xa5`; word 0 contributes only its low byte; every other word contributes `high ^ low`;
after each word the accumulator is rotated left one bit. `0xbfc11ee8` checks byte 0 against that and byte 1 against `8`. The erase/write-all
sequence at `0xbfc11fd8` writes `0xffff` everywhere (messages "NVRAM did not complete PRCLEAR cycle" and "PRWRITE cycle") and then
writes word `0x7d`. Inferred: the lock path in `0xbfc02c28(1)` is that sequence; its exact purpose is unknown.
The machine test used to pick between the two peripheral controller bases (`0x1fbd9000` or `0x1fbd9880`) is `0xbfc0b738`. Whether this
image also has the DS1386 path was not checked.

## Console paths (established)

`0xbfc0ce94` opens the console: `GetEnvironmentVariable("ConsoleIn")` and `("ConsoleOut")` must both exist; ConsoleIn is opened mode 0 and
must return handle 0, ConsoleOut mode 1 and must return handle 1. On failure it calls `0xbfc0d048(0)` to rebuild both variables and tries
again; failing that, with `console` not `d` it uses `d` ("CONSOLE OPEN FAILED."), and finally prints "Cannot open any console!". `0xbfc0d048`
sets `ConsoleIn` and `ConsoleOut` from the `console` variable: when it starts with `d`, or no graphics probe in the component
builder table (below) finds a board, both are `serial(0)`; otherwise `ConsoleIn=keyboard()` and `ConsoleOut=video()`. A missing keyboard
prints "Cannot connect to keyboard -- check the cable." The strings are at `0x54c9c` (`video()`), `0x54ca4` (`keyboard()`), `0x54cb0` (`serial(0)`).
`serial(0)` takes its baud from `dbaud`, and `serial(1)` from `rbaud` (`0xbfc499f0`). `gfx` is read-only. A form `g<digit>` of `console` selects the
n-th graphics board (`0xbfc32520`). Unknown: whether the path `serial(1)` is ever a console (no code found that sets it).

## Configuration tree (established)

Component record: class, type, flags, version (`1`), revision (`10`), key, affinity, configuration data size, identifier length, identifier
pointer. The image uses SGI's class numbering: 0 system, 1 processor, 2 cache, 3 memory, 4 adapter, 5 controller, 6 peripheral. Root:
`SGI-IP22` (class 0 type 0, builder `0xbfc0b7b4`, template `0x69d68`). Types observed: processor `1` (`MIPS-R4000`, template `0x69d8c`, with an
`MIPS-R4000FPC` floating-point child), caches (primary I `3`, primary D `4`, secondary `7`, template `0x69dd4`), memory unit `8`
(`main memory`, template `0x69df8`, size set to the page count from `0xbfc0c328`), SCSI adapter `11` (`WD33C93`, `0xbfc1fb00`), network
controller `19` (`ec0`, with a network peripheral type `36` child, `0xbfc1e0ac`), keyboard controller `23` (`pckbd`), pointer controller `22` (`pcms`),
audio controller `24` (`HAL2`, `0xbfc02f90`), monitor peripheral `30` and display controllers. The R4600 and R4700 patch the processor
identifier's digit (`0x34` or `0x36`).

Build order is a table of 12-byte entries (builder, parent key, probe) at `0x5daa0`, walked recursively by `0xbfc32444`; top-level
entries (key `1`) in order: `0xbfc0b800` (cpu, fpu, caches, memory), `0xbfc16588` (Impact/MGRAS graphics), `0xbfc1b554` (GR2/GR3/GR5/GU1 Express
graphics, including "-Extreme", "-Elan", "-XSM", "-XS24"), `0xbfc1dd90` ("Indy 24-bit", "Indy 8-bit" graphics), `0xbfc1e0ac` (ethernet, SEEQ), `0xbfc20158`
(SCSI controller probe), `0xbfc24b38` (serial lines), `0xbfc02f90` (HAL2 audio), `0xbfc25ddc` (PC keyboard and mouse). Entries with key `0`
(`0xbfc26030`, `0xbfc26210`, `0xbfc28e50`) are probed under a parent. The graphics probe at `+8` of an entry is called repeatedly to enumerate boards.
Inferred: the entry order is the order the nodes appear as siblings under the root. Unknown: the exact sibling order of SCSI children, which come from
live bus probing.

## Boot flow, menu and commands

Main flow after reset (`0xbfc021a0`; call order established, roles inferred): wait for the power-switch state, set up the controller,
set Status `0x30410801` then `0x30004801`, cache and memory work (`0xbfc04c88`, `0xbfc0e8e4`, `0xbfc04d9c`, the secondary/primary address and data test),
diagnostics (`0xbfc05900`, which prints the `*FAILED*` lines and "Check or replace" hints), then a test of the low nibble of the MC system ID
(`0xbfa0001c`): when it is 0 the routine calls the print routine and loops forever, and the only matching text is "Fatal Error: Rev A MC detected. Need
rev B or greater." (inferred link). If diagnostics failed and `diagmode` starts `dc` it prints "Continuing with diagmode=dc."; otherwise it stores `ponfailed` and
waits for a key. If diagnostics passed and `diagmode` starts with `M`, `0xbfc024a8` runs a manufacturing autoboot that tries, in order, `boot`,
`ide.IP22`, `bootp()ide.IP22`, `sashIP22`, `bootp()sashIP22`, `unix.IP22`, `bootp()unix.IP22`, `bootp()mgras.ide.IP22`, then prints "Mfg auto boot failed."
Both paths end in `0xbfc10240`.

`0xbfc10240`: if `AutoLoad` is `y` or `Y` and `NoAutoLoad` is unset, it prints "To perform system maintenance instead, press <Esc>" and
calls the loader `0xbfc47fb0(5, 0, ...)`; on failure it prints "Unable to boot; press any key to continue:". In every case it falls into
`0xbfc00638` (enter interactive mode), which reaches the monitor loop below. The loader reads `SystemPartition`, `OSLoadPartition`, `OSLoader` (default `sash`) and `OSLoadFilename`, formatting
`%spartition(%d)` paths.

Monitor loop (`0xbfc02cf0`, established): it builds the menu with `0xbfc13c30`, then repeats: show the menu (`0xbfc43e9c`), then run the command interpreter
`0xbfc48630(commandTable, ">> ", 1, 0)` (prompt string at `0x5332c`). The menu table at `0xa87418b0` (filled by `0xbfc13c30`) pairs each label with a handler:
Start System `0xbfc13d84`, Install System Software `0xbfc13dfc`, Run Diagnostics `0xbfc13ecc`, Recover System `0xbfc14208`, Enter Command Monitor `0xbfc141a0`,
Select Keyboard Layout `0xbfc142d8`.

System Maintenance Menu (`0xbfc13c30`, strings `0x558d0..0x55954`): "Start System", "Install System Software", "Run Diagnostics", "Recover System",
"Enter Command Monitor", and "Select Keyboard Layout" (variable `keybd`). Install and Recover set `OSLoadOptions=mini` (Recover also `initstate=3`)
and load tools from CD-ROM, network (`netinsthost`, `netinstfile`) or tape (`tapedevice`). Diagnostics boots `part(8)sashARCS` or `part(7)/stand/ide.` from the
distribution CD-ROM and falls back to `SystemPartition` `stand/ide` ("Booting installed IDE").

Command table at `0x5d974` (name, handler, help string), 24 entries: `auto` `0xbfc48320`, `boot` `0xbfc46c00`, `.checksum` `0xbfc483e0`, `date` `0xbfc125f8`,
`.dump` `0xbfc12798`, `exit` `0xbfc484b0`, `.fill` `0xbfc13114`, `.g` `0xbfc13310`, `.go` `0xbfc484e0`, `help` and `.?` `0xbfc48b0c`, `init` `0xbfc00800`, `hinv`
`0xbfc48d40`, `ls` `0xbfc499f0`, `.gio` `0xbfc02b28`, `passwd` `0xbfc13540`, `printenv` `0xbfc49f74`, `.p` `0xbfc13434`, `resetenv` `0xbfc10110`,
`resetpw` `0xbfc13674`, `setenv` `0xbfc49d04`, `single` `0xbfc4a040`, `unsetenv` `0xbfc49eac`, `version` `0xbfc02f4c`. The `help` handler
lists only names that do not start with `.` (established), so those are hidden commands. An unknown word is tried as a program to execute via
`0xbfc37c24`, giving "Command not found". `resetenv` (`0xbfc10110`) rewrites every record except `passwd_key`, `netpasswd_key` and `eaddr` with its default
(`Could not reset NVRAM variable %s.` on failure).

## hinv (established)

`0xbfc48d40` takes options `-v`, `-t`, `-p`, `-b` (strings at `0x5c840..0x5c84c`) and walks the configuration tree with `0xbfc49960`. Lines it
can print (strings `0x5c9b4..0x5ce10`): Processor (MHz, with FPU, secondary cache), "Secondary cache size", primary and secondary I/D cache sizes,
"Memory size", "Graphics", "Audio" (HAL2 version and revision), SCSI disk, CD-ROM and tape with controller and ID, and for `-t` the component tree with class,
type, unit, key and flags (Failed, ReadOnly, Removable, ConsoleIn, ConsoleOut, Input, Output). With `-t` a Configuration data dump is
added for `-p`. Unknown: the meaning of `-b` beyond that it selects a different printing path (`0xbfc42390`).

## Unknowns and routes that would settle them

- What bit 10 of the `0x8400` EEPROM mask does, and why the reset store goes to MC offset 0 rather than `+4`: a published mode-stream description of
  the R4000 or the MC reset register map, or the same code in the IP24 image (`333a0b2e…`), which was not compared here.
- Descriptors for memory above `0x20000000`: a trace of `0xbfc1145c` callers on a machine with a second window, or the bank-size routine `0xbfc0b5b4`.
- Private-vector slot names and the other six Halt/Restart variants: read their callers in the PROM's later stages.
- Whether `0xbfc0b738` distinguishes IP22 from IP24 board types and whether a DS1386 path is present: read `0xbfc0b738`.
