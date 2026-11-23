# O2 PROM memory sizing: how the first stage probes, orders and programs the CRIME banks

The O2 (IP32) PROM sizes RAM in its first stage, before any DRAM is trusted. It programs the eight CRIME
bank-control registers itself, probes each bank with four doubleword stores and loads, then rewrites all eight
registers into a packed layout. This page records the sequence, what a probe needs from absent and short banks,
the smallest memory the PROM tolerates and how the later firmware and the kernel read the result. Layout of the
images and the load map are in [prom-software.md](prom-software.md).

Sources and grades. Images: PROM 4.18 (`11230c35…`, IRIX 6.5.30 media) and PROM 4.8 (`820585be…`, IRIX 6.5 base
media), read as MIPS code from the shipped files. The sizing routine was also compared in PROM 2.3 (`32f131cd…`) and
in the raw 4.18 flash dump (`a60e19b6…`). Kernel: the 6.5.30 IP32 kernel object, through
the kernel function readings in the CRIME workspace (`software/kernel/functions.md`: `szmem`, `last_phys_pfn`, `bank_size`,
`addr_to_ibank`). **Established**: read in full in the listing. **Inferred**: reasoned. **Unknown**: not settled.
Addresses are flash addresses (`0xbfc00000` base) for the first stage and run-time addresses for the firmware
segment. Where two builds differ the 4.8 address follows in brackets.

## Where the code is

| Item | 4.18 | 4.8 |
|---|---|---|
| bank sizing routine (the strings call it `SizeMEM`; entered from the `post1` driver at `0xbfc0447c`) | `0xbfc05ad4`..`0xbfc06090` | `0xbfc05ab4` |
| four-entry uncached TLB setup used by the probe | `0xbfc05a2c` | same shape |
| first-4 KiB DRAM test | `0xbfc05110`..`0xbfc05348` | same shape |
| memory-transfer-engine clear of the first 32 KiB | `0xbfc061f0` | `0xbfc061d0` |
| firmware total-size routine | `0x81003cec` | `0x81003b4c` |
| firmware clear of RAM above 20 MiB | `0x81007010` | same shape |

The sizing routine is instruction for instruction the same in 4.8 and 4.18 apart from the relocation of the pointers
to its strings and patterns (16 instructions differ, all of that kind). The firmware size routine is also identical.
All 18 catalogued IP32 PROMs share this routine (**established** for 2.3, 4.8, 4.18 and the raw dump by comparison;
the rest by the catalogue's identical build family, **inferred**). The one difference is the mask of the first write
to the CRIME control register at `0x14000008`: 2.3 and 4.3 clear bit 4, while 3.3, 4.0 and 4.4 to 4.18 clear bit 0
(**established** for the mask; why it changed is **unknown**). 2.3 is the same algorithm in a different build. The raw 4.18 dump differs from the shipped image in 120 bytes at flash
`0x4040`..`0x43ff`; the sizing code at `0x5ad4` is byte-identical.

## The sequence

1. **Clear a control bit first** (established). A read-modify-write of the 64-bit CRIME control register at
   `0x14000008` (the register at `+0x8`, not the memory-control register at `+0x200`) clears bit 0 before any bank is
   touched. The PROM's own message for this step says "ECC off", and that string (`0xbfc06c54`) is the only basis
   for reading the bit as an ECC switch, so the ECC meaning is **inferred**. It conflicts with the CRIME register
   page, where `ecc_enable` is bit 0 of memory control at `+0x200`, not of `+0x8`; the conflict is open. The same
   bit is cleared again at the start of the routine that jumps to the RAM copy of the later tests (`0xbfc060fc`).
   No store that sets the bit was found in the first stage or in the loaded firmware (**inferred**: a scan of the
   firmware's `0xb4000000` constructions found none touching offset 8 except one read that discards its result).
   The kernel's early reset code does a read-modify-write of the same `+0x8` register that clears bit 9, or bits
   13, 12 and 9, and ORs in `0x3000`; it never sets bit 0. The kernel's write of 1 to enable ECC goes to `+0x200`.
2. **Probe loop, banks 0 to 7** (established). For bank `i` the routine keeps a running address `A = i * 128 MiB`.
   - It installs four uncached TLB entries, each mapping 32 MiB, so that `A` .. `A + 128 MiB - 1` in the user
     segment reaches physical `0x40000000 + A`, the CRIME full-RAM window. Every probe access is uncached.
   - It writes the bank controls of banks `i` through `7` (not just `i`) with the same value, `0x100 | ((A >> 25) &
     0x1f)`: 64 Mbit geometry, selector `4 * i`. Writes go out low bank number first, as 64-bit stores. Because every
     bank from `i` up now matches `A`, and (**inferred**, from the specification's priority rule, not from PROM code) the lowest match wins, bank `i` is the one under test, and the access can
     never fall in an unmatched hole (so it never reaches the memory-address-error path). Banks below `i` keep the
     values written on earlier passes.
   - It stores four doublewords at offsets `0`, `32 MiB - 8`, `32 MiB` and `128 MiB - 8` from `A`. Each value is the
     offset's complement in the high word and the offset in the low word (the offset-0 value is the all-ones high
     word with a zero low word). It then stores zero to three doublewords at offsets `0x10`, `0x18` and `0x20`.
   - It reads the four offsets back as 64-bit loads and classifies:
     *32 MiB* if offset 0 returns the value stored for offset `32 MiB`, offset `32 MiB - 8` returns the value stored
     for offset `128 MiB - 8`, and the other two read back as stored (a 32 MiB part wraps modulo 32 MiB under the
     128 MiB decode); *128 MiB* if all four read back as stored; *absent* otherwise.
   - It records 32, 128 or 0 for the bank and prints a line. After each bank it invalidates the four TLB entries
     (established, `0xbfc05998`) and moves `A` up by 128 MiB, whatever the size found.
   - Bank 0 absent is fatal: the routine prints "Error, no SIMM in bank0" and then toggles the two bits at `0x1f310008`
     (`0x30`) forever, with a delay loop between toggles.
3. **Final programming, in three passes over the recorded sizes** (established). A new running address starts at 0.
   Every 128 MiB bank, in ascending bank number, gets `0x100 | ((addr >> 25) & 0x1f)` and the address advances by
   128 MiB. Then every 32 MiB bank, again in ascending bank number, gets `(addr >> 25) & 0x1f` (geometry bit clear)
   and the address advances by 32 MiB. Then every absent bank gets a copy of bank 0's final control value. The total
   returned and printed ("MEM Size = ... bytes") is the final address.

So the result is dense: all 128 MiB banks first at the bottom of the decode space, then the 32 MiB banks, then
nothing. Bank number does not decide position, size does. If bank 0 holds 32 MiB parts and bank 1 holds 128 MiB parts,
bank 1 ends at offset 0 and bank 0 at 128 MiB. **Inferred** consequence: the public Linux sizing loop skips any bank
other than 0 whose base is 0, and counts a bank with the base of bank 0 twice; that loop assumes bank 0 sits at
offset 0 and is only exact when it does.

## Question 1: control-register encoding and total

Each control register is 64-bit, at `0x14000208 + 8 * n`. Bit 8 selects the part: set for 64 Mbit parts (128 MiB per
external bank), clear for 16 Mbit parts (32 MiB per bank). Bits 4:0 are the selector, compared with request-address
bits 29:25 (32 MiB mode) or, with the low two selector bits ignored, bits 29:27 (128 MiB mode). There is no valid
bit and no sub-bank field. A bank counts as populated by software only because its register differs from bank 0's
(the PROM writes absent banks as a copy of bank 0, so an absent bank can never be told apart from bank 0 itself, and
bank 0 is always counted). The size a program reads from a register is 128 MiB if bit 8 is set, else 32 MiB (the
kernel routine `bank_size`, the PROM firmware routine and the monitor's size routine all do exactly this; all
established). The total is bank 0's size plus the size of every later bank whose full 64-bit value differs from bank
0's. Nothing multiplies by DIMM count or reads another field. All established for the PROM; the kernel and monitor
side is in the CRIME workspace readings.

There is no 64 MiB bank size. A fitted 64 MiB bank cannot be sized correctly: the 32 MiB test fails and all four
128 MiB reads match (the 128 MiB-minus-8 store aliases to 64 MiB minus 8, a location nothing else uses), so the
routine would record 128 MiB (**inferred**; relies on the memory wrapping modulo its size, not observed).

## Question 2: absent and short banks during the probe

- The probe never expects a bus error and cannot survive one (established). The first-stage general exception vector
  (`0xbfc00380`) either parks in a one-instruction loop or, when `$30` is nonzero, jumps through it, and the sizing
  routine happens to hold the constant 128 in `$30` (the compiler's choice, not a handler address), so an exception
  there would jump to address `0x80`. There is no handler for bus errors. The probe also never reads or
  writes the memory-error status or address registers.
- A matched bank with no DIMMs must complete the stores and loads and must return something that does not equal the
  stored values. Zero, all-ones or noise all work. It must not store the patterns (that would read back as 128 MiB or
  32 MiB present) and must not alias another bank's contents, including bank 0's, because the probe writes real
  patterns there. All established from the compare logic. Which of these a real absent bank gives is **unknown**.
- The probe sees the full 64-bit data path. A bank where only one DIMM of a pair is fitted, or any data bit stuck,
  fails the 64-bit compare and is reported as absent (inferred from the compare width; no fitted-hardware evidence).
- Short banks: only the two sizes above are recognised. Missing and "short" are not otherwise told apart.
- The first-4 KiB DRAM test (below) reads the CRIME ID word at `0x14000000` between store and load only in its
  walking-one and walking-zero loops over the first 32 bytes (`0xbfc051b8`, `0xbfc051f8`), so a floating bus cannot
  return the stored value there (established). The later pattern passes and the bank probe have no such read.

## Question 3: the smallest accepted configuration

- Bank 0 populated, with 32 MiB or 128 MiB (established). Banks 1 to 7 may all be empty.
- Total RAM at least 20 MiB, and in practice 32 MiB (established from the load map). The firmware text, data and
  stack occupy physical `0x1000000`..`0x13fffc0` (stack top `0x13fc000`) and the descriptors reserve
  `0xd50000`..`0x1400000`. The smallest legal bank is 32 MiB, so this is always met.
- The first-stage memory test (established, `0xbfc05110`..`0xbfc05348`) runs after sizing over physical `0`..`0xfff`
  through the uncached alias: walking-one and walking-zero doubleword tests at four offsets, alternating `0x5a5a5a5a`
  and its complement words, an address-in-address pattern and its complement, each read back and compared. Failure
  blinks the same two LED bits as the bank 0 error, with no message.
- Order after sizing (established): the memory-transfer-engine clear, then the 4 KiB test, then the stack handover
  and the copy of the later tests.
- Stack: before sizing, the first 4 KiB at `0x80000000` is made into RAM by writing cache tags (see
  [prom-software.md](prom-software.md)) and the stack lives there. After the test the routine copies that page
  through the uncached alias into real DRAM at physical 0 (`0xbfc060a0`, 4104 bytes). The caller then moves the stack
  pointer to the uncached alias, saving the old pointer at physical `0x1008` (`0xbfc0449c`..`0xbfc044ac`). A model
  that returns correct data for physical 0..0xfff before the first write must still keep those lines coherent: the
  page goes to DRAM only through that copy.
- Copier chain (established): `0xbfc060f8` copies a 28-byte copier from flash to physical `0x10000`, runs it cached at
  `0x80010000`, and that copier copies flash `0xbfc06fd0`..`0xbfc09120` to physical `0x4000`, which is then entered
  uncached at `0xa0004000`. Both ranges must be real DRAM.
- The memory-transfer-engine clear (`0xbfc061f0`) fills 32 KiB at full-window address `0x40000000` with zeros. It is
  skipped entirely when the CRIME revision (the ID register's low nibble) is 0; the firmware's twin does the same
  through `0x81004d9c`. Otherwise it writes the engine's page-translation words and then, with these register
  offsets inside the CRIME block (names **inferred**): `0x3030` start address, `0x3038` inclusive end, `0x3018` fill
  value 0, `0x3008` byte mask `0xffffffff`, and mode `0x11` written through the `0x3800` alias, which starts it
  (mode: clear, destination ECC bit). The routine does not wait for completion: the status test at
  `0xbfc06400`..`0xbfc06480` ANDs bit 25 of a status word into a 0 or 1 and never loops on it. The only real wait is
  the check for space in the page-translation FIFO at `0xbfc065f8`, which a status of zero or all-ones passes. So a
  model needs the registers to accept the writes, not to complete a transfer (**inferred** purpose of the fill: make
  the first 32 KiB valid under ECC).
- The firmware repeats the same clear for physical `0x1400000` up to the total size (`0x81007010`, called with
  `0x41400000` and total minus `0x1400000`), in chunks of at most 128 KiB (established). That is the only ECC-aware
  clear of the rest of RAM in the PROM, and its length follows the size. What initialises `0x8000`..`0x1400000`
  beyond the loader's own copies and the firmware entry stub's zeroing of `0x105ffe0`..`0x13fffc0` is **unknown**.
- The PROM describes at most the first 256 MiB to the ARCS memory list: one free area from physical `0x2000` for
  `min(total, 256 MiB)` bytes minus two pages, then it carves out the exception-block page, the parameter-block page
  and three firmware ranges (established; the min helper is `0x81045484`). Memory above 256 MiB is not listed. The
  firmware configuration tree reports the total in pages from the same routine.

## Question 4: mixed sizes and refusal

- Any mix of 32 MiB and 128 MiB banks in any slot order passes the probe (the probe has no ordering rule).
- The programmed layout is by size then bank number, as in the sequence above (established). A bank's slot does not
  fix its address.
- Refusals: bank 0 absent or failing, and the first-4 KiB test failing. Both end in the LED loop. A bank that fails
  the 32/128 test is silently dropped, with a log line "no simm installed" (the strings are reachable only on a
  serial or debug console, **unknown** whether the normal console shows them).
- `hinv` and the monitor report the total only: the PROM's configuration entry carries the total in pages and the
  printed text is `Memory size: <n> Mbytes`. No per-bank report is made by the PROM (established). How IRIX `hinv`
  builds its figure from the kernel total is in the CRIME workspace; the kernel does not read selectors to size.

## Question 5: sockets

The PROM prints bank numbers only (the strings carry "bank%d", "BANK%d" and a debug line "Bank0 = %dM" through
"Bank7 = %dM" listing the recorded sizes); no string names a socket, a DIMM label or a slot (all `.rodata` and flash
strings searched in 2.3, 4.8 and 4.18). The mapping from physical sockets to banks is **unknown** from firmware. The
stand-alone diagnostic monitor carries a drawn memory diagram, but it is the drawing of an earlier,
EISA-backplane system class and says nothing about O2 sockets.

## Not read

The remaining first-stage tests (`mem_scache1` .. `mem_scache10`, `pcache_init`, `scache_init`, `mem_init` and the
verify routines) are not read here. The first-stage reset branch and what each test does after sizing stay as listed
in [prom-software.md](prom-software.md).
