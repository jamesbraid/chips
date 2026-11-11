# IP35 PROM: the board class of IP53 and IP59 node boards, the machine-type word, and the early flash check

Question. Which class (bits 15:12 of the board-identification word) do IP53 and IP59 node boards carry; what do the low bits
do on them; how does the PROM obtain the machine-type word of the flash block it compares against; how are the processor-table
rows for R16000 parts reached; and where does the early flash check's mismatch arm at 0x1fc006fc end?

Method: disassembly of the shipped IP35 PROM 6.210 (container segment `ip35prom`, unpacked sha256
`554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`) and of its nested BaseIO segment (inflated sha256
`f903b3ce33b86c286f168ba43395f36a0073c24b1d4e703adce240f683b8c2d7`), with the PROM 6.211 image
(`25f60c7f0bae9cf32611e04205b7d0c8cf08adfddbfc1bfe433facd95b5ce271`) checked for the same routines. Addresses follow
[ip35-board-word-and-config-block.md](ip35-board-word-and-config-block.md): outer = offset + 0x1fc00000, nested = offset +
0x13000000. Kernel facts are from `6.5.30/unix.IP35` as described in the kudzu repository's
`docs/ip35-node-class-and-link-checks.md`. Agreement sources, used afterwards: OpenBSD `sys/arch/sgi/sgi/ip27.h` and
`ip27_machdep.c` (the 2026 tree, subtype names from the 2009 change that introduced them); three published PROM console
captures of a deskside Tezro, an Origin 350 and a Fuel (counts below). Nothing was run.

## Answer

### 1. The class of IP53 and IP59 boards

1. **Established: it is not 0x4, 0x8 or 0xc.** The start-up banner routine (outer 0x1fc69b0c to 0x1fc6a1c0, string use at 0x1fc6b350 to
   0x1fc6b470) reads the class and
   - for 0x8000 prints the IP45-mode line, for 0x4000 the IP34-mode line followed by the DDR or SDR line;
   - for every other class prints none of those and asks for the node's brick type (routine 0x1fc68ba0), printing one of four
     brick banners for types 1, 2, 3 and 5.
   Routine 0x1fc68ba0 returns 0 without a system-controller request for classes 0x8000, 0x4000 and 0xc000 and otherwise asks the
   controller for the brick-type character, mapping '7' to 1, '8' to 2, '9' to 3, '0' to 4 and 'Q' to 5 (0x1fc68c54 to 0x1fc68cec).
   Agreement with captures: the Origin 300 console capture prints the IP45 line; the Fuel capture prints the IP34 line and
   the DDR line; a four-processor 1.0 GHz R16000 Tezro (IP59 board, PROM 6.210) prints the workstation brick banner and neither of the other
   lines, and an Origin 350 prints the graphics-blade banner and neither. All four brick banners need a type that the gate returns only for
   classes outside 4, 8 and c. 6.211 has the same routines (strings 0x10 lower).
2. **Established: the kernel has the same gate.** `set_sn12_type` and `get_chimera_type` return type 0 for classes 0x4, 0x8 and 0xc
   (kudzu `docs/klconfig.md`, "The IP35 node class nibble"). The kernel's workstation-specific system-controller path depends on type 3.
   Together with item 1 this excludes 4, 8 and c for any board whose controller reports a Chimera brick type.
3. **Inferred: the value is 0x2.** OpenBSD's IP35 subtypes are 0x00 C-brick, 0x02 Origin 350, 0x04 Fuel and 0x08 Origin 300, read from bits
   15:12 of this register; its default arm prints "Unknown IP35 type" so 2 was seen on a running Origin 350. The PROM has one routine that
   names a board family by class (outer 0x1fc35cb4, the CPU and SRAM pin report): class 0x2000 gives the label "Twister", 0x8000 "Speedo2 R14K",
   0x4000 "Asterix R14K" (OpenBSD's codenames for the Origin 300 and the Fuel agree); any other class falls back to the processor's PRId. So 0x2000
   is a class the PROM authors expected on shipping hardware. Why inferred: no capture shows the raw word, OpenBSD names the value after a product
   not a board, and neither the PROM nor the kernel says "IP53".
4. **Unknown: whether IP59 carries the same value.** Established only that a 1.0 GHz IP59 board is outside {4, 8, c} (item 1).
   Route: one 64-bit load at 0x9000000014000000 on each board.
5. **Established: the EEPROM record cannot supply a class.** The text record the PROM parses has the keys DataValid, HubModeBits,
   CpuCfg0Reg to CpuCfg3Reg, HubSpeed, CpuSpeed, MinIrixVer, MinPromVer and MinL1Ver (outer strings 0x84380 to 0x89494). The system controller
   chooses a brick-type character from the board's identification records and never reads the class (sysco `docs/l1/personalities.md`).
6. **Established: per-socket product table is unreachable for class 4.** The routine at outer 0x1fc66d8c returns at once for class 0x4000;
   otherwise it handles per-socket PLL variables, skipping sockets outside the product's mask. The only product names in its table are the
   six `IP53_*` and `IP59_*` rows ([ip35-prom-cpu-config-table.md](ip35-prom-cpu-config-table.md)). Inferred: those products are not class 4.

### 2. The low bits

Established. Every consumer except the processor-configuration fallback masks bits 15:12 only (PROM load sites in both segments, 99 kernel
sites, OpenBSD). The fallback (outer 0x1fc1f3a0, nested 0x130d6550) maps class 0x2000 plus nibble 0 to row 24 and nibbles 1 and 5 to row 25,
both the 400 MHz, 1 MB, tap 0x9 word 0x5219a785; every other nibble finds no row
([ip35-prom-cpu-config-table.md](ip35-prom-cpu-config-table.md)). The nested comparison fetches the board EEPROM text record first (call at
0x130d6818, fallback call at 0x130d68e0), so a board with a record never reaches the nibble. Unknown: the real value of bits 11:0 on IP53 and
IP59, and whether the nibble tracks anything on a board whose processors are soldered on. Route: the same raw read as item 4.

### 3. The machine-type word of the flash block

1. **Established: the PROM derives the reference type from the class, not from a table row, whenever the EEPROM record is present.** The
   record builder (nested 0x130c3570; the same logic in the config-report routine outer 0x1fc1f528, stores at 0x1fc1f5a4, 0x1fc20004 and
   0x1fc2000c) reads the LOCAL class register, even when building a remote node's record, and stores at record +0x30: 2 for class
   0x4000, 1 for class 0x8000, 0 for every other class (nested stores 0x130c35e8 to 0x130c3610). The table fallback stores the row's byte 13
   (0 for classes 0 and 0x2000, 1 for 0x8000, 2 for 0x4000, [section 2.3 of the board-word page](ip35-board-word-and-config-block.md)). Both routes agree.
2. **Established: the comparison** (nested 0x130d6808, called from 0x130e42bc) checks offsets 0x00, 0x04, 0x08, 0x10, 0x18, 0x28, 0x2c, 0x30
   and 0x3c of the flash copy against the reference. A class outside 4 and 8 therefore needs machine type 0 in flash.
3. **Inferred: real Tezro and Origin 350 flash holds 0.** Neither retained PROM 6.210 console capture (a Tezro with flash count 1, an Origin 350
   with flash count 2) shows the module-mismatch notice. The user flash utility offers 0 to 3; a value of 3 can never match a derived type.
   Not established that the comparison ran in those captures. Route: raw read of `flash + 0x30`.

### 4. R16000 speed rows

Established. Rows 26 (700 MHz, 4 MB, tap 0xc), 20, 21 and 22 (800 MHz, tap 0xa) and 28 (900 MHz, tap 0xb) are reached only through class 0x4000
plus nibble 3, 0xc, 0xd, 0xe and 2. Class 0x2000 reaches only the 400 MHz rows 24 and 25. The IP53 600 MHz / 4 MB / tap 0xc board
(part 030-1863-001, one retained module) and every 1.0 GHz IP59 board have no table row. So the table is not where IP53 and IP59 boards get
their words; those come from the EEPROM record and the flash block, neither of which any shipped image holds. Where a printed tuple equals a Fuel row
(700 / 4 / 0xc; 800 / 4 / 0xa; 800 / 8 / 0xa; 700 / 8 / 0xa), the same tuple means the same Config mode bits, which is inferred, not read.

### 5. The early flash check and the 0x1fc006fc arm

Established (6.210; 6.211 has the same code, `jal` target 0x1fc50c2c).
1. 0x1fc00680 to 0x1fc0068c stores 0x5f in the slice's real-time compare register (0x9200000001000108 + 8 x slice). 0x1fc006a8 reads
   flash +0x64, 0x1fc006ac writes it to CP0 Config, 0x1fc006b4 to 0x1fc006bc compares readback bits 15:0, 0x1fc006dc to 0x1fc006f4 compares bits
   24:16. Equality continues at 0x1fc00780, which stores 0x60 and runs on. The PROM sets its global pointer later, at 0x1fc01920.
2. Mismatch, 0x1fc006fc to 0x1fc00778: stores 0xb4 in the same compare register and in a second per-slice register at
   0x9000000010000000 + 0xc0 + 8 x slice, then calls 0x1fc50c34.
3. 0x1fc50c34 loads three pointers from the global-pointer table, clears bit 0x10 << slice of the I/O-block scratch register 0x9200000001400150
   (the present-processors mask of [ip35-prom-mp-presence-poll.md](ip35-prom-mp-presence-poll.md)), prints a permanent-disable notice, zeroes the
   interface's per-processor enable word (0x9200000001800050 + 8 x (slice and 1); 0x9200000001a00050 for slices C and D), stores 0x86 in the
   node-addressed copy of the second progress register, and returns.
4. The call at 0x1fc00778 returns to 0x1fc00780, the first instruction of the match path. **The arm ends by rejoining normal start-up with the
   processor's presence bit and enable word cleared.** Inferred: a processor with a zero enable word is cut off from its interface.
5. Unknown: whether the arm returns on silicon. No instruction sets the global pointer before 0x1fc01920 and R10000-family reset leaves general
   registers undefined, so the callee's first pointer load uses an unknown base. Route: a hardware cold start with a deliberately wrong flash word
   (physical test, not proposed here), or the processor's documented reset register state if a specification gives it.

### 6. 1 GHz parts

Established: neither PROM nor the BaseIO image holds a 1 GHz row, clock or text. A published capture of a 1.0 GHz R16000 Tezro prints cache clock
333 MHz, tap 0x15, 16 MB and processor revision f50. Under the table's own arithmetic that fixes SCClkDiv 5, tap bits 28:25 = 5 with bit 22 set
and SCSize 5; SysClkDiv 9 follows the 27-of-29 rule (clock = hub x (SysClkDiv + 1) / 2), inferred. The word 0x4aedb385 satisfies all of these and no
more is known (unknown fields: DDR, Kseg0CA, PrcReqMax, block size, ECC, drive, CTM; route: a raw `flash + 0x64` or EEPROM dump).

## Not covered

No hardware was read. The PLL environment handling in outer 0x1fc66d8c, what the kernel's "Selecting SN" message derives from, and the R16000's
writable Config bits are unknown here. See [open-questions.md](../open-questions.md).
