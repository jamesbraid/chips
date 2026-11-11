# IP35 PROM: entering POD mode, and what its configuration report shows for the processor

Question. The IP35 boot PROM carries a low-level diagnostic monitor ("POD mode"). How does a user or the firmware
get into it on an Origin 300, Origin 350, Fuel or Tezro class node? What does it print for a processor's Config
register, and which secondary-cache clock tap does that report show for the live register? Does a live read of
Config return the tap the flash record carries?

Short answer.

- POD mode is entered by setting bits in the system controller's virtual debug switches (L1 command `debug <hex>`:
  0x8 stops at the global POD, 0x10 at the local POD, 0x18 before memory is tested) and resetting or powering up;
  by any unexpected exception or NMI in PROM or standalone code; and by a console prompt for the switch value when the
  controller's switches cannot be read. No PROM-monitor command and no NVRAM variable enters it.
- The POD command `cfg` prints two things for the local node: the 80-byte record in boot flash, with a full field
  decode including the secondary-cache clock tap, and the live CP0 Config register, decoded only through the
  secondary-cache clock divisor and the DDR bit. **The report never decodes a tap from the live register.** Both
  PROM builds do the same; the live call and the flash call share one decoder, and a flag argument stops the live
  call before the tap, open-drain and cache-test-mode fields.
- The tap the inventory prints (`hinv`-style "Tap 0x..") is built by the CPU PROM from the flash word, not from
  Config. Bits 28:25 of a live Config read are the primary-cache size field and a reserved zero, so decoding a tap
  from a live word would show 0x6 on every R10000-family part whose caches are 32 KB. That is the hardware contract,
  not a mismatch with the flash tap (0xc for a 700 MHz R16000, 0x15 for a 1 GHz one).

Sources. The shipped IP35 PROM, SGI Version 6.210 (built Aug 26 2004), container segment `ip35prom`, load address
0xc00000001fc00000, length 0x1686a8; unpacked segment sha256
`554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`; and SGI Version 6.211 (built Jan 25 2008, from
IRIX 6.5.30 patch 7208), sha256 `25f60c7f0bae9cf32611e04205b7d0c8cf08adfddbfc1bfe433facd95b5ce271`. Offsets are
6.210 image offsets; the segment is linear, so address = 0x1fc00000 + offset for code, strings and tables. Method: Capstone disassembly with the retools decoder and byte searches; nothing
was run. Published: SGI L1 and L2 Controller Software User's Guide 007-3938-006, the `debug` command, printed pages
63 and 64 (Table 3-2); the IRIX 6.5.30 `prom(1M)` manual page, "Virtual Debug Switch Settings"; MIPS R10000
Microprocessor User's Manual version 2.0, section 14.14 (Table 14-15, Figure 14-16) and Table 8-1 (mode bits);
NEC VR12000 User's Manual U10278EJ3V0UM00 (3rd edition), section 13.14 (Table 13-15 and its footnotes), and the
VR12000A edition U10278EJ4V0UM, section 11.14 (Table 11-15, Figure 11-16); OpenBSD
`sys/arch/mips64/mips64/cache_r10k.c` (`Mips10k_ConfigCache`, tree 2df91d80c104); published console captures
(counts below).

## 1. How POD mode is entered

Established (published manual and PROM).

- **Virtual debug switches.** 007-3938-006 Table 3-2 (printed page 64) lists the 16-bit "virtual debug switch"
  word the L1 holds and the `debug` command reads and sets (`debug` shows it, `debug <hex>` sets it; the guide says
  these commands apply to C-bricks). The boot-stop field is `0x8` global POD, `0x10` local POD, `0x18` memoryless
  POD; `0x1`, `0x2`, `0x3` pick the diagnostic level, `0x4` verbose output, `0x20` ignore environment variables,
  `0x100` override disabled CPU or memory, `0x200` output prefixes, `0x1000` hardware-error dump, `0x2000` ignore
  autoboot. The IRIX 6.5.30 `prom(1M)` page repeats the table and adds that the value can be shown or changed from
  POD mode with the `dbg` POD command.
- **The PROM reads the same table.** The PROM prints the same switch list (strings at 0x70020 to 0x700c0: `01`
  no diag, `02` heavy, `03` mfg, `04` verbose, `08` global pod, `10` local pod, `18` no mem pod, `20` default env,
  `40` bypass io7, `80` no global master) and keeps the switch word in the upper half of a boot-flags value held in
  floating-point register 0 (before RAM exists): the word sits at bits 63:48 (set from the console prompt at
  0x1fc6b318 to 0x1fc6b340: shift by 48 and store through 0x1fc03a14). The boot-stop level is extracted at
  0x1fc6a3d0 to 0x1fc6a3f4 as bit 51 (switch 0x08) times two plus bit 52 (switch 0x10), giving 0 never, 1 local,
  2 global, 3 no-memory, and is reported as "Boot stop requested at" the named level. A non-zero word also prints
  a warning with the word (0x1fc6a468 to 0x1fc6a470).
- **Exceptions and NMI.** The software entry points at 0x1fc01524, 0x1fc0156c, 0x1fc01c28, 0x1fc020bc,
  0x1fc02680 and 0x1fc05758, and the common entry 0x1fc05608, carry reason texts for soft reset, NMI in PROM, NMI
  in the kernel (memory inaccessible, vectors corrupt, no vector installed), a second NMI, a cache-error or general
  exception, and a slave stopped by a console interrupt (the "Control-C" text). Two published captures (a Fuel under
  PROM 6.170 and another IP35 node) show the consequence: an unexpected exception in
  standalone code ends at a "Press ENTER to continue" line and then the POD prompt, and the `why` command prints the
  saved registers and a numeric reason (244, unexpected TLB refill, in both).
- **The prompt.** The prompt format (0x71b68) is an optional cpu/nasid prefix (switch 0x200), the word POD, the console
  in use (`SysCt` system-controller UART, `IOC3`, `Junk`, `MSC`, `EfiCB`), and the memory mode `Cac`, `Unc` or `Dex`.

Established for the console route (PROM). When the system controller's switches cannot be read (typically a raw
console), the early boot code at 0x1fc6b2d8 to 0x1fc6b348 prints a notice that the controller switches are
unavailable, lists the table above and prompts for a hexadecimal value (default 0000), which it stores as the
switch word. So typing `18` there has the same effect as `debug 0x18` at the L1.

Inferred. The PROM takes the switch word from the controller on a normal boot (the POD `dips` command reads the
"controller debug switches" as two bytes and `dbg [VIRT PHYS]` reads and writes them; the published captures print
the word as "debug switches are non-zero (0x10d)", and the same word is shown by the L1 `debug` command). The routine
that fetches it was not traced.

Unknown. The "POD key pressed" reason text (0x870d0) exists, and no code path that names a key was found; the
console-interrupt route above is the nearest. Which byte a user would type is not established. No Tezro or Origin 350
owner's guide documents POD entry (the Tezro tower guide 007-4564-001 uses "power-on diagnostics" for something
else); the Tezro L1 is assumed to accept `debug` as the Fuel and Origin 350 L1 does, which is not shown for an IP53.

Public captures (verbose PROM captures of an Origin 300, an Origin 350, a Fuel under PROM 6.210 and a Fuel under
6.211; four captures). Each sets the switches to 0x10d and powers up: "debug switches set to 0x010d" (L1), the PROM warning, "Diag level set to None",
"Info level set to verbose", "Boot stop requested at Global (2)", and finally "*** Entering POD mode on node 0"
with the prompt `POD SysCt Cac>`. 0x10d is 0x100 (override disables) + 0x8 (global POD) + 0x4 (verbose) + 0x1 (no
diagnostics); the printed levels agree with the table. After POD the owner clears the word with `debug 0x0` and uses
POD `reset`.

## 2. What POD can show for the processor

Established (command table in the 6.210 image).

- The command table is an array of 24-byte entries: a pointer to the name, the command number in the high half of
  the second doubleword, and a pointer to the help text. Handlers are in a pointer array at 0x167bc0, indexed by the
  command number minus 0x80. `cfg` is command 0x173 (table entry at 0x13f768); its handler is entry 243 at 0x168358,
  address 0x1fc1e034.
- Commands that touch the processor description: `cfg [n:NODE]` (below), `pcfg [n:NODE] [v]` (the topology
  structure), `pr`/`pf`/`sr`/`sf` (print or store a register; the register-name table at 0x71650 to 0x71790 holds
  Config and PRId, and a string says they are shown "as saved on POD entry"), `cpu` (switch to another processor),
  `cpufreq` (computes the processor frequency), `version`, `why`, `dmc` (memory configuration), `setmodebits` /
  `fflash` / `flash` (program mode bits or flash on a node). The printing path of `pr` and `cpufreq` was not traced.

### The `cfg` report

Established (0x1fc1e034 to 0x1fc1e1fc, decoder 0x1fc1dc74 to 0x1fc1df74; 6.211: decoder 0x1fc1dc78, callers
0x1fc1e020 and 0x1fc1e1c0, same instructions).

1. It copies the 80-byte configuration record from `0x9000000038000060 + (nasid << 33)` (the node's boot flash)
   and prints a header for the flashed values, the CPU and hub speeds (record +0x10 and +0x18 in Hz, divided by
   1,000,000), then a line for register 16 with the record word (record +4) and the full decode (decoder with flag
   0).
2. If the nasid asked for is the local node it then reads the processor's own CP0 register 16 through the indexed
   move-from-coprocessor-0 table at 0x1fc03c40 (a 64-bit read, register 16 = Config), prints a header naming the
   nasid and processor letter (letter = 'A' plus the slice number), the register line with the raw 64-bit value,
   and the decode with flag 1.
3. For a remote node it calls the board EEPROM loader (0x1fc1f4dc) and prints that record, or falls to the
   power-supply-controller table lookup (0x1fc1f3a0); both print with flag 0.

The decoder prints, in order, bits 2:0 (cache algorithm for kseg0), 4:3 device number, 5 coherent-request target,
6 processor-eliminate request, 8:7 maximum requests, 12:9 system clock divisor, 13 secondary-cache block size,
14 corrector enable, 15 endianness, 18:16 secondary-cache size, 21:19 secondary-cache clock divisor, and bit 23
(named DDR by the PROM). It then tests the saved flag: **for flag 1 it returns here; for flag 0 it continues with the
tap, built as (word >> 25) & 0xf with bit 22 as bit 4 (instructions at 0x1fc1def0 to 0x1fc1defc), then bit 30
(open-drain system interface) and bit 31 (cache test mode).** The flag is stored at 0x1fc1dc94, reloaded at
0x1fc1decc and tested at 0x1fc1ded8. The decoder has exactly two callers (6.210: 0x1fc1e01c with flag 0, 0x1fc1e1bc
with flag 1; the first runs for the flashed, EEPROM and table records, the second for the live register), so the
live report ends after the DDR line.

So the answer to "which tap does the live Config decode to" is: none is printed. The routine would read bits 28:25
and bit 22 if it were asked, and the PROM's author did not ask it to for the live register.

## 3. What a live Config read holds in bits 31:22

Established (specifications).

- R10000 manual section 14.14: bits 24:0 of Config are "taken directly from the mode bit settings during a reset
  sequence"; bits 28:26 are the primary data cache size, hardwired to 0b011 (32 KB); bits 31:29 the primary
  instruction cache size, hardwired to 0b011; bit 25 and the other reserved bits read zero. Table 8-1 defines the
  secondary-cache clock tap as mode bits SysAD[28:25], with SysAD[29] reserved, [30] open drain and [31] cache test
  mode. Only bits 24:0 reach Config, so the tap, open-drain and test-mode inputs are not readable there.
- NEC VR12000 manual section 13.14 (Table 13-15; VR12000A: Table 11-15): the same layout for the R12000, with three
  of the R10000's reserved bits now mode bits: 22 secondary-cache data and tag corrector disable, 23 processor
  coherency data response, 24 delay speculative dirty. Bits 31:26 are still hardwired 32 KB/32 KB and bit 25 is
  reserved zero.
- Result for the decoder's arithmetic: a live word with IC = DC = 3 and bit 25 = 0 has (word >> 25) & 0xf = 0b0110 =
  0x6. That value is the hardwired cache-size field, not a tap. With bit 22 as bit 4 the same decode would add 0x10
  when bit 22 is set.

Established (public drivers and a capture). OpenBSD's `Mips10k_ConfigCache` (used for every IP27/IP30/IP35 R10000-family
CPU) reads the primary instruction and data cache sizes from live Config bits 31:29 and 28:26, and the secondary-cache
size and block size from bits 18:16 and 13. A published boot transcript of an Origin 350 with a 1 GHz R16000
(revision 3.0, 16 MB secondary cache) prints "L1-I 32KB D 32KB 2 way, L2 16384KB 2 way", so on that part
Config bits 31:26 read 0b011011 (the print was made by an OpenBSD of 2009; the current file above is the one read).
Linux `arch/mips/mm/c-r4k.c` reads the same fields for `CPU_R10000`, `CPU_R12000`, `CPU_R14000` and
`CPU_R16000` in a current tree.

Inferred. Bit 25 of an R14000 or R16000 also reads zero (no public R14000 or R16000 manual exists; the layout is the
R12000's). The sizes are confirmed for the R16000 only through the print above.

Established by the PROM's own boot check (0x1fc006a8 to 0x1fc006f4, see
[ip35-reset-window.md](ip35-reset-window.md)): the PROM writes the flash word to Config, reads it back and compares bits
15:0 and 24:16 with the flash word, disabling the processor on a mismatch. So on every processor that boots, live
Config bits 24:16 (secondary-cache size, clock divisor, bit 22, DDR, bit 24) equal the flash word's. Bit 22, the extra
tap bit, therefore reads back as the flash word's bit 22 on a booted part, while bits 28:25 do not. The flash word's
bits 28:25 are programmed into the mode-bit logic and are not readable.

## 4. Where the printed tap comes from

Established (6.210 code, 0x1fc53e34 to 0x1fc53fac). A routine called from 0x1fc5fd48 reads the flash word of the
node it is given (`0x9000000038000000 + (nasid << 33) + 0x64`, the same record word) and packs a 16-bit field of the
processor entry it builds for the hardware-configuration database: bit 0 = Config bit 23, bits 4:1 = bits 28:25,
bits 8:5 = the secondary-cache clock divisor, bit 9 = bit 14, bits 13:10 = bits 12:9, bit 14 = bit 22. In the same
routine the CPU MHz field is the record's clock in Hz divided by 1,000,000, the cache size MB is
`1 << (bits 18:16 - 1)`, and the secondary-cache clock is derived from the divisor: 700 MHz with divisor 3 gives 350,
1 GHz with divisor 5 gives 333.

Inferred. The `hinv -v -m` style line "Secondary Cache 16MB 333MHz Tap 0x15" in the published Tezro capture is printed by
the BaseIO monitor from that processor entry (the BaseIO image's print code was not read here). The values agree:
333 MHz = 1000 * 2 / 6 and tap 0x15 = bits 28:25 = 5 plus bit 22. Published Origin 350 and Fuel `hinv` lines
agree with the flash-word source for other parts: R14000 500 MHz 2 MB 250 MHz tap 0xa, R14000 600 MHz 4 MB 300 MHz tap
0xa, R16000 700 MHz 4 MB 350 MHz tap 0xc, R16000 800 MHz 4 MB 400 MHz tap 0xa, R16000 900 MHz 8 MB 450 MHz tap
0xb, each equal to the PROM speed-table row for the part (see [ip35-prom-cpu-config-table.md](ip35-prom-cpu-config-table.md)).

## What is left

- Unknown: bit 25 and the exact reset readback of bits 28:25 on an R14000 or R16000, and whether an R16000 returns
  its reset-pin bit 22 in Config. The first has no software consumer (the PROM never decodes a live tap, and no OS
  reads bit 25), so this is a valid end state; the second is covered by the PROM's own readback check above. A
  hardware read would settle both: on an Origin 350 (IP35 PROM 6.210 or 6.211), note the current value with the L1
  `debug` command, run `debug 0x8` (global POD stop), power up, and at the POD prompt run `cfg`. The second block
  prints the processor's raw 64-bit Config; bits 31:22 can be compared against 0x6c0 (IC=DC=3, bit 25 = 0) and the
  flash block's bit 22. Then restore the old `debug` value and enter POD `reset`. It only reads; it writes the L1's
  non-volatile switch word, which is restored. It settles the R14000 or the R16000 the machine carries, not both.
- Unknown: the keystroke behind the "POD key pressed" reason, the routine that fetches the controller's switch word,
  the print path of `pr` and `cpufreq`, and whether the IP53 L1 accepts `debug`.
