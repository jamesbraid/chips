# Altix 350 and Prism: reset to the EFI console in SAL 5.04

What the SHub 1 firmware image SGI's `README.snprom` names for the Altix 350 and both Prism models does from processor
reset to the EFI console, and the value each hardware access has to return for the code to proceed. Image:
`shub1snprom.bin`, SAL 5.04 (banner "SGI SAL Version 5.04 rel081111 IP41 built ... Nov 11, 2008"), package snprom-10.54-70399,
sha256 `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`, read with the retools
`ia64-linux-gnu-objdump`. Layout, FIT and the component tables are in the [firmware page](README.md); SAL 4.43 and the
SHub 2 builds are compared where noted.

**Grades.** *established*: the whole function or table was read. *inferred*: built from a call list, a constant, a name
carried by the sibling SAL runtime (the runtime component is symbolised, SAL_B is not; names below that come from the
runtime are marked "runtime name"), a function not read in full, or a result of the interpreter run under [Memory discovery](#memory-discovery-what-is-read-and-what-an-interpreter-run-of-the-image-shows) (a trace of the shipped binary under assumed inputs, not hardware behaviour). *unknown*: not settled. The
SHub 1 register names are mostly unknown; offsets are the local-window addresses the code uses
(`0x81_xxxx_xxxx` = bit 63 for uncached, plus the SHub 1 local offset `0x80_0000_0000` plus the offset; the
[SHub page](../../../devices/shub/README.md) lists the few registers the kernel header names).

**Not a recommendation.** The firmware recognises a CPU ID signature that makes it skip hardware (below); that is stated as
a fact only.

## The path in one table

| Step | Where | Progress code | What it needs from hardware |
|---|---|---|---|
| Reset: PAL_A, PAL_B | PAL components | none | the real PAL (see [PAL boundary](#pal-boundary)) |
| SAL_A, reasons 3 then 0 | `0xffc4e000` | 48 | SHub 1 local MMRs below; no RAM, no L1 |
| SAL_B reset entry | `0xffa01000` | 0x31, 0x35 | RAM at physical `0x1000000` |
| `main()` in flash | `0xffa19a20` | 8 to 0x19 | L1 UART peer, memory controller, DIMM data |
| `main_two` after jump to RAM | `0xffa1ade0` | 0x1a to 0x1e | node interconnect, NASID |
| `main_three` | `0xffad7280` | 0x21 to 0x27 | I/O discovery |
| Load and jump to EFI | `0xffaf8c50` | 0x44 to 0x48 | FIT EFI component, RAM |
| EFI | EFI component | 0x49 to 0x4f | console, flash variable store |

The progress-code meanings are the PROM's own table (a table of code and message pairs at `0xffbd7000`, established): 1
to 7 kernel LED codes, 8 "Execution has reached C code in main()", 9 wait on direct console, 0xa wait on system
controller console, 0xb reset request sent to system controller, 0xc arbitrating local master, 0xd first set of init
routines, 0xe reading debug switches, 0x10 disable CPUs as requested, 0x11 collect error state from before reset, 0x12
second init routines, 0x13 probing for baseio, 0x14 third init routines, 0x15 early hardware tests, 0x16 discovering
memory, 0x17 testing and initialising memory, 0x18 post-memory init, 0x19 beginning jump to RAM, 0x1a jump to RAM
complete, 0x1b late tests, 0x1c discovering node interconnect, 0x1d assigning NASIDs and routes, 0x1e to 0x23 node id
install, 0x24 discovering I/O, 0x25 partitioning info, 0x26 final init, 0x27 "Jumping to next segment (EFI or IOprom)",
0x28 waiting on the EFI callback console, 0x30 calling SAL_B for a reset event, 0x31 SAL_RESET entered, 0x32 and 0x34
cache preload, 0x35 about to call main(), 0x38 entered due to MCA, 0x3b due to INIT, 0x44 copying PROM to RAM, 0x48
jumping to EFI, 0x49 to 0x4f EFI start-up (0x49 "Jump to EFI complete", 0x4a early return, then "Installing EFI memory map", "base EFI devices", "console drivers",
"SN-specific EFI devices", "EFI initialization complete"), 0x50 EFI idle loop, 0x51 and 0x52 flashing. Fatal codes 0x80
to 0x90 include 0x80 no memory on node, 0x81 write to system controller timed out, 0x83 local master arbitration failed,
0x85 cannot initialise klconfig, 0x89 system controller communication init failed, 0x8d critical system controller
transaction failed, 0x8f NUMAlink discovery failed. Codes 0xb0 to 0xb4 (176 to 180) are in the table too: 0xb0 "PAL early self-test failed", 0xb1 "SAL entered with invalid
function code", 0xb2 "SAL invoked for firmware recovery", 0xb3 "SAL_RESET called with bad parameters", 0xb4 "main() returned";
SAL_A and the SAL_B entry write them.

This also fixes the SAL_A reason codes: SAL_A writes 48 (0x30, reset) for reason 0, 56 (0x38, MCA) for reason 1 and 59
(0x3b, INIT) for reason 2, so reason 0 is reset, 1 is machine check, 2 is INIT (established, from the table and the
SAL_A stores). Reason 3 is the PAL-pair query below.

## SAL_A on SHub 1

Read in full (established), SAL 5.04, `0xffc4e000`, 16 KiB. Same control structure as the SHub 2 build described on
the [firmware page](README.md#entry-and-initialisation-order); the differences are the registers. `cr.lid` bits 26:23
(4 bits, not 3) identify the processor here, `r20` holds the reason, `r33` to `r37` hold PAL's words. In order, for
reasons 0 and 3:

1. Set `psr.db` (bit 24). Reason 3 only: call a routine that returns 1 (the SHub 2 build reads `0x2_1003_8200` bit 39 here;
   SHub 1 reads nothing). If bit 3 of `r33` is set, spin forever; otherwise make a static PAL call, index 528, argument
   5. Meaning of the call unknown.
2. Node set-up (both reasons): write `0x15031010` to `0x81_1002_0000`; set bit 24 of `0x81_2001_0100` by
   read-modify-write; read `0x81_5003_1510` and `0x81_5003_1530` and write each value ORed with `0x60` (16-bit) to LED
   registers `0x87_fed1_0000` and `0x87_fed3_0000`. No node-identity table here, unlike the SHub 2 build.
3. Error path: if bit 2 of `r35` is set and its low two bits are not zero: record progress 176, clear bits 29:26 of
   `0x81_5003_1550`, OR `0x280_0000_0000` into `0x81_101d_0080`, write `0x1_0001_0000_0000` to `0x81_2000_0000`, spin.
   Not reached unless PAL reports a fault in `r35`. The condition is `tbit` of `r35` bit 2 at `0xffc4e096`, then `r35` bits 1:0 nonzero at `0xffc4e0b6`; either test failing skips to `0xffc4e2e0`. Progress 0xb0 (176) is written three times in this block: into the per-processor history register `0x81_5003_1500 + 16 * lid[26:23]` at `0xffc4e100`, and as a 16-bit store of `0xb0 | 0x60 * b` (so 0xb0 or 0xf0) to LED registers at `0xffc4e166` (address `0x87_fed0_0000` with bit 16 set to `b = (lid[26:23] >> 1) & 1`) and at `0xffc4e1e0` (address `0x87_fed2_0000` with bit 16 set to `b = ((lid[26:23] >> 1) & 1) ^ 1`) (established, read).
4. Byte 1 of `r20` must be 0 or 7 or the fatal hang (progress 178) follows.
5. Reason 3: pick the PAL pair from `cpuid[3]` (tables at `0xffc51648` and `0xffc51000`), OR a field into `r37`, return
   to PAL through `b6 = r36`. Done.
6. Reason 0: copy PAL's `r33` to `r37`, `r20` into bank-0 registers; set `cr.lid` bits 24:23 from bits 1:0 of `r33`
   (no register read, unlike SHub 2). Election: write `slice + 1` (`cr.lid` bits 26:23, plus one) to `0x81_101d_0088`,
   read `0x81_101d_0080`; on a match, that processor (the winner) zeroes `0x81_5003_1550`, `0x81_5003_1540`,
   `0x81_5003_1560` and writes 1 to `0x81_1006_0480` (`SH1_IPI_ACCESS`). It then re-reads `0x81_101d_0080`, finds its
   value again and sets bits 41:39 of `0x81_101d_0100` to 7.
7. FIT scan as on SHub 2 (same checks, hang 178). Progress 48, 56 or 59 for reason 0, 1, 2; for reasons 1 and 2 (and
   for a reason above 3) read `[0x81_1003_0000 + (slice & 3) * 128]` into `r31`, which reason 0 does not (its branch at
   `0xffc4e4fc` skips the read at `0xffc4e570`); branch to SAL_B offset 0, 0x20 or 0x10.

**Progress display (established).** Every progress code is shifted into a per-processor 64-bit history register at
`0x81_5003_1500 + 16 * cr.lid[26:23]` (shift left 8, new code in the low byte) and written as 16 bits to two LED
registers at `0x87_fed0_0000 + n * 0x10000` (n from the processor number; the odd-numbered register gets the code ORed
with `0x60`). The SHub page lists `0x7_fed0_0000` as the junk-bus LED registers. Neither is read back: the code needs only that
the writes are accepted.

**4.43 comparison (inferred, constants only).** The 4.43 SAL_A touches the same `0x81_...` registers and in addition
has code that switches PSR for virtual mode; it has no read of `0x81_1003_0000` and no `0x81_2000_0000` write. 5.04 added
the error path stores and the `r31` read. The 5.04 list includes 4.43's.

**What SAL_A needs back.** Nothing needs a particular value except two. First, the election: SAL_A writes `0x81_101d_0088` and reads `0x81_101d_0080`, which are different addresses, so a plain read/write register at 0x80 does not satisfy it. The single processor must read back at 0x80 the value it wrote at 0x88; whether 0x88 aliases 0x80 or is a first-writer latch is **unknown** (the reset value is unread; the error path ORs bits into 0x80, so 0x80 is also writable). Second, `0x81_101d_0100` must hold what was written (bits 41:39 = 7), since the UART initialisation checks them (below). All the

### The first three register accesses in SAL_A, in detail

Read from the SAL 5.04 image (`0xffc4e000`), the whole of each routine named. Addresses are the PROM's uncached local-window form (`0x81_xxxx_xxxx` is local offset `0x1_xxxx_xxxx`); a Linux-header offset is the local offset, for example `SH1_SHUB_ID` `0x1_1006_0580` is `0x81_1006_0580`.

**Read-modify-write of `0x81_2001_0100`, bit 24 (`0xffc4e7f6` to `0xffc4e816`).** SAL_A loads the 64-bit value, ORs in `0x100_0000` (bit 24) and stores it back. The load result is used for nothing else in SAL_A: no test, no branch, no other register is derived from it, and the other 63 bits go back unchanged (established). The same register is read-modify-written later in SAL_B at `0xffa318b6` (OR 8, bit 3), `0xffa31d56` (clear bit 3), `0xffaeb276` (OR `0x2_0000`, bit 17), read for bit 3 at `0xffa31ab6`, and in one routine (`0xffa97796` to `0xffa97916`) that reads the original value, writes it back with bit 24 set, then reads `0x81_2000_0000`, ORs in `0x3b03f7` when the SHub ID revision (bits 31:28 of `0x81_1006_0580`) is above 2 and `1009` otherwise, writes that to `0x81_2000_0000`, and finally writes the value it first read back with bit 24 cleared, whatever bit 24 was before (the saved copy is the read value ANDed with `0xfffffffffeffffff` at `0xffa977e0`; established for the sequence, read at `0xffa97780` to `0xffa97946`). A second copy of the revision-split write addresses another node (`0xffa96296` to `0xffa9630c`, global window); it writes only that node's `0x2000_0000` and has no bit-24 bracket. A remote routine at `0xffaeb2e0` reads another node's `0x2001_0100` and returns whether bit 17 is clear, so bit 17, which the local routine at `0xffaeb276` sets, is tested across nodes. So bit 24 brackets writes to `0x81_2000_0000` (inferred: a write-enable for that register, because SAL_A sets it before its own `0x81_2000_0000` write in the error path and the SAL_B routine clears it again afterwards; no test of the bit was found). The Linux v5.3 SN2 headers (`arch/ia64/include/asm/sn/shub_mmr.h`, `shubio.h`) do not define `0x1_2001_0100`; the nearby named SHub 1 registers are `SH1_PI_CAM_CONTROL` `0x1_2005_0300` and `SH1_PIO_WRITE_STATUS_0` `0x1_2007_0200`, so the register is in the same `0x1_2xxx_xxxx` block (processor interface, inferred from those neighbours) but its name and fields are **unknown**. Reset value: **unknown**. The firmware's first access is this read and it keeps whatever it reads, so the code depends on no particular reset value and tolerates any; bit 24 must be writable and read back as written for the later restore sequence above. A plain 64-bit read/write store satisfies every access seen. Revision field: bits 31:28 of `0x81_1006_0580` (`SH1_SHUB_ID_REVISION`, Linux `shub_mmr.h`); Linux treats revision 2 or less as SHub 1.1 (`is_shub_1_1`, `arch/ia64/sn/kernel/setup.c`), and this PROM makes the same split at 2 (compare `2 < rev` at `0xffa978d0` and `0xffa962c6`; established for the compare). The generic widget probe compares a 16-bit part number against 17251 (0x4363) at `0xffa959ac` and extracts the part number as bits 27:12 of a widget ID (`extr.u 12,16`), with revision at 31:28 and manufacturer 11:1, the layout of Linux `ii_wid_u` in `shubio.h` (inferred that the SHub ID register carries the same layout; the SHub ID register read itself extracts only bits 31:28, 45:44 and 42:32 in the sites read).

**History registers `0x81_5003_1510` and `0x81_5003_1530` (`0xffc4e830` to `0xffc4e966`, called at `0xffc4e080` for both reason 0 and reason 3).** Unconditionally, SAL_A reads each as 64 bits, ORs `0x60` into the low 16 bits and stores the 16-bit result to the junk-bus LED registers `0x87_fed1_0000` (from `0x1510`) and `0x87_fed3_0000` (from `0x1530`). The value is used only as the LED data (established). `0x81_5003_1500 + 16 * n` is the progress history of the processor whose `cr.lid` bits 26:23 equal n: every progress write (`0xffc4e596` to `0xffc4e5e0`, `0xffc4ee40` to `0xffc4ef00`, `0xffc4e100`) reads it, shifts it left 8, replaces the low byte with the code and writes it back. So `0x1510` and `0x1530` are the histories of processor positions 1 and 3, not of the processor that is running when only position 0 exists. The code needs no particular value: on a one-processor node the two reads return whatever the registers hold, and the LED writes just need to be accepted. The read-shift-write on the processor's own history register needs the register to return what was last written (a plain 64-bit store satisfies it); a reset value of zero gives histories made only of codes. Reset value: **unknown**; the firmware depends on none (any value is shifted out or shown on an LED). Linux v5.3 does not define `0x1_5003_15xx`. What bits 29:26 of `0x81_5003_1550` mean is below.

**The election: write `0x81_101d_0088`, read `0x81_101d_0080` (`0xffc4e970` to `0xffc4ea6c`, called from `0xffc4e3a0`; second check at `0xffc4e730`, called from `0xffc4e3e0`).** The processor computes v = `cr.lid` bits 26:23 plus 1 (after SAL_A set `cr.lid` from bits 1:0 of PAL's `r33`, so v is 1 to 4), stores v as 64 bits with release ordering to `0x81_101d_0088`, post-decrements the address by 8 and loads `0x81_101d_0080` with acquire ordering, and compares the entire 64-bit value to v. Equal: this processor is the node's winner and writes 0 to `0x81_5003_1550`, `0x81_5003_1540` and `0x81_5003_1560`, then 1 to `0x81_1006_0480` (`SH1_IPI_ACCESS`). Not equal: it skips those stores (established). Later (`0xffc4e730`) it reads `0x81_101d_0080` again, compares to v again, and on a match sets bits 41:39 of `0x81_101d_0100` to 7 (read-modify-write); otherwise leaves it (established). So on a node with one processor the register pair must return exactly v (not v with other bits) from the 0x80 read after the 0x88 write, twice; and a loser never sets `0x81_101d_0100`, which the console UART setup then checks, so a failed election would stop the L1 link (inferred from that check). Other accesses to `0x81_101d_0080`, all read-modify-write with bits kept: the error path in SAL_A (`0xffc4e246`) and the SAL_B reset-exit path (`0xffaf5ed6`) OR in `0x280_0000_0000` (bits 41 and 39) after clearing bits 29:26 of `0x81_5003_1550`; a SAL_B routine at `0xffa0b0f0` ORs in `0x200_0000_0000` (bit 41) after reading `0x81_5003_1550` bits for every other processor position (26 + m) and finding all of them clear, so bit 41 means "no other processor position is flagged" (inferred from that code); and a routine at `0xffa4eba6` addresses the same register on another node (global window, NASID in bits 38 and above), clears bit 40 and sets it again, so the net effect is to set bit 40, which marks bit 40 as a per-node flag (inferred). Two more remote and indirect users exist: `0xffa0aef6` ORs bit 39 (`0x80_0000_0000`) into another node's register, and `0xffa959f6` and `0xffa96946` pass the offset form `0x1_101d_0080` to generic read and write helpers (`0xffa0bd20`, `0xffa0c560`) whose bodies were not read here. So `0x81_101d_0080` carries at least bits 39, 40 and 41 as firmware state plus, at election time, the winner number in the low bits. Bits 29:26 of `0x81_5003_1550` are per-position flags (set by `0xffa0e730`, which also touches `0x81_101d_0200` and `0x81_101d_0208`, tested by `0xffa0eb40`); their meaning beyond "a processor position is flagged" is **unknown**.

Relation of 0x88 to 0x80: **unknown**. Linux v5.3 does not define `0x1_101d_0080`, `0x1_101d_0088` or `0x1_101d_0100`. Linux does show a convention for other SHub 1 and SHub 2 registers (`SH_EVENT_OCCURRED` at `0x1_1001_0000` with `SH_EVENT_OCCURRED_ALIAS` at `+8`, written to clear bits in `irq.c`; `SH_PIO_WRITE_STATUS_0` and its `_ALIAS` at `+8`, used by `ptc_deadlock.S`): the alias sits 8 above the register, which matches 0x88 above 0x80. Under that convention a write to the alias clears set bits, which cannot make a read of 0x80 return v, so this register's alias behaves differently from those two; the code allows (a) a first-writer latch where the alias write is ignored once a winner is stored, (b) an alias write that stores or ORs v into 0x80, or (c) the two being the same storage word. Only (a) makes the election exclusive; the code reads the same register for all three. A model that returns v at 0x80 after a write of v at 0x88, and keeps 0x80's bits 39:41 writable, satisfies every access read. Whether a second writer with a different v loses is the part the code cannot show.
The other SAL_A accesses to these registers are writes that must be accepted. The reads of `0x81_5003_15x0` may return any value. `0x81_1003_0000` is not read for reason 0; reasons 1 and 2 and a reason above 3 read it (step 7 above).

## PAL boundary

What the firmware itself provides and expects of PAL. Architecture-level facts about PAL entry and
exit come from the public IA-64 PAL specification, not this image; marked *architectural*.

- **PAL_A and PAL_B come from the firmware image.** The FIT carries three PAL_B and three processor-specific PAL_A
  entries in this image (PAL_B 7.79, 5.73, 2.25; PAL_A 7.31, 5.37, 1.27; established). Which pair is used is chosen by
  SAL_A, not the SAL runtime. Reason 3, the PAL calls below and
  the firmware's PAL version checks ("Minimum PAL A", version strings) all assume that pair.
- **Order (established for SAL_A's side).** Processor reset runs PAL_A (the FIT address at `0xFFFFFFE0`); PAL hands to
  SAL_A (address at `0xFFFFFFE8`) first with reason 3 (the PAL pair query: SAL_A returns to PAL at the address PAL gave in
  `r36` with a value ORed into `r37`), then PAL_B runs, and PAL enters SAL_A again with reason 0, which scans the FIT and
  enters SAL_B. Reasons 1 (MCA) and 2 (INIT) enter SAL_A later and go straight to SAL_B at offsets 0x20 and 0x10. The
  exact PAL-side sequence is *architectural* and inferred here from the exit registers SAL_A reads.
- **What SAL_A needs in registers on entry:** `r20` (byte 0 reason, byte 1 0 or 7), `r33` to `r37` (bit 3 of `r33`,
  bits 1:0 of `r33` give the processor position; bit 2 and low bits of `r35` flag a fault; `r34` the PAL entry used for
  the static call; `r36` the return address; `r37` returned).
- **PAL procedures the firmware calls:** re-enumerated in [PAL procedures SAL_B calls](#pal-procedures-sal_b-calls) below, which replaces the earlier list (the earlier list mixed structure offsets with indexes).
- **PAL data the firmware reads:** `cpuid[3]` (masked `0xffffff0000` for the family and model, full value for the stepping
  table), `cpuid[2]` (the signature below), `cr.lid`, and the processor ID layout above (slice in bits 26:23).
- **CPU ID signature (fact only).** `cpuid[2] == 0xaeeeeeee8badbeef` appears at 65 sites in SAL_B (the uncompressed part of the image) and 31 in the SAL runtime;
  with it the firmware skips the L1 UART, returns built-in board data, and makes `sysctl_cmd_command_timeout` fail at
  once with -24. It is not recommended here.

## Node board identification (IP41, IP57, others)

- **The PROM does not branch on a board name for the compute board (established for `hwcfg_node_init`).** The
  klconfig builder passes the fixed string "IP41" as the compute board's name (inferred: the helper that receives it was not read to its copy). The
  string `Part:030-1604-001;Name:IP41;Serial:KHD563;Revision:-D;` in SAL_B is used only when `cpuid[2]` carries the
  signature above (read in `init_klcfg_hub`); otherwise the record comes from the board EEPROM through the system
  controller. The klconfig board name is the fixed string either way; the EEPROM supplies only part, serial and revision (a failed EEPROM read prints "Could not
  retrieve EEPROM info on nasid %d" and is non-fatal there). So there is no IP41 or IP57 branch.
- **How it reads the board record (established):** `sysctl_cmd_open`, a request, and `read_board_ia`, which fetches the
  board "info area" from the L1 (checks a length byte and a checksum; messages "eeprom length byte of ZERO", "bad
  checksum", "error reading info area from L1"). Part, name, serial and revision strings are formatted from it. So board
  identity reaches the PROM only through the L1.
- **Chip identity at run time (inferred, partly established).** The NASID comes from bits 42:32 of the SHub ID register
  `0x81_1006_0580` (`chipset_get_nasid`, established, read on almost every call). Bits 52:48 give the region size
  (`GET_SN_INFO`, firmware page), bits 45:44 are used by memory presence. `shub_probe` accepts a part number field of
  17251 (0x4363); the SHub 1.1, 1.2 and "1.x" names and `shub_name` come from the revision field. The part number
  is not read from `0x81_1006_0580`: `chipset_init_chip` reads it from bits 27:12 of the word at node offset
  `0x1_0000_0000` and offers it to four method tables, which accept `0x4363`, `0x3017`, `0x239` and `0x4422`; any other
  value leaves a null table that later calls go through (chips `45fae66`). The revision the PROM expects is not decoded.
- **What an IP57 changes (unknown).** No difference between IP41 and IP57 is visible in the PROM: neither the string
  `IP57` nor a table row for it exists. Differences must be in data the PROM reads (EEPROM, L1 CPU presence, DIMM
  data), not in code paths.

## L1 controller dependency

- **Link (established, runtime names).** The L1 is reached through a 16550-style UART in the SHub junk bus: registers at
  local offset `0x7_fed4_0000 + 8 * n` (n = 16550 register index: 0 data, 1 interrupt enable at `+0x08`, 3 line control
  `+0x18`, 5 line status `+0x28`, 7 scratch `+0x38`); the node-addressed form is `0xf_fed4_0000` with the NASID in
  bits above 38. The two address forms are two windows onto the same registers (inferred): the local window is bit 39 (`0x80_0000_0000`) plus the offset, as SAL_A uses for the LED registers (`0x87_fed1_0000` = window plus `0x7_fed1_0000`); the global window is bit 35 (`0x8_0000_0000`) plus the offset with the NASID at bit 38 and above, as SAL_B and the runtime use (`0xf_fed4_0000` = window plus `0x7_fed4_0000`). Both carry bit 63 for uncached physical access. `sc_uart_init` waits for line-status bit 6 (transmitter empty) with a 100000-tick limit before
  programming divisor and control. `sc_uart_init` and `l1sc_init` check that bits 41:39 of `0x81_101d_0100` read 7 (the
  value SAL_A set), and `sc_shub_state_reg` and `sc_shub_pushed_data_reg` name that register.
- **Probe.** `sysctl_probe` in SAL 5.04 returns 0 on the CPU ID signature and 1 otherwise, with no hardware access
  (established; 4.43 differs, see the [firmware page](README.md#entry-and-initialisation-order)).
- **Does boot stall without an L1? Yes, with a fatal code (established for the transaction path).** The common
  transaction `sysctl_cmd_command_timeout` retries sending up to 50 times (500 ticks between tries) while the send
  answers -26, then waits in `sysctl_cmd_recv` until a deadline for a reply on the subchannel; a receive failure (-24)
  ends in `main_node_die_remote(nasid, 141)`, progress 0x8d "Critical system controller transaction failed". `sysctl_init`
  runs in phase 0xd (`0xffa1f430`), before memory. A DIP-switch fetch that the L1 cannot answer prints "System Controller
  DIP switches unavailable" and asks on the console for values (`0xffad2f10`), which also needs a console.
- **Message frame (established, read in `sysctl_cmd_construct_req` `0xffa81f40` and `sysctl_cmd_interpret_resp` `0xffa82270`; the request side checked against a trace).** Every request is built by `construct_req`, sent by `sysctl_cmd_command` (a wrapper that calls `sysctl_cmd_command_timeout` with a timeout of `0x2dc6c0` ticks), and answered in the same buffer. Request: bytes 0 to 3 big-endian, the target from `sysctl_cmd_open` ORed with the constant 6 (the trace shows `0x0ffff006` for every request but one, and `0x5000_1006` for the one with command id 3 at `0xffa7ca10`; what selects the target is not read); bytes 4 and 5 big-endian, the command id; byte 6 the argument count; arguments from byte 7, each a tag byte then data: tag 0 is a 4-byte big-endian integer, tag 1 a NUL-terminated string, tag `0x80 | n` (n at most 127) n raw bytes. Reply: bytes 0 to 3 big-endian status (0 is success; -106 selects a second status at bytes 6 to 9, the result being that value minus 106000; any other negative value is an error); byte 4 the argument count; arguments from byte 5 in the same tag form. The reader checks the count and every tag against what the caller expects (-32 or -33 if not), so a reply with the wrong argument list is an error, not ignored. A reply with status 0 and no arguments therefore satisfies only requests that expect none.
- **Command ids seen before the memory phase (trace, inferred meaning).** 0x1005 (4101, one string, "Prom starting...", a display text), 0x100b (three integers), then 3, 19, 14, 9 and 1 in that order from `0xffa7ca10`, `0xffa7cbe0`, `0xffa7ce90`, `0xffa7db00` and `0xffa7d040`, 6 for the EEPROM read (below), 0x15 (21, no arguments) after memory. Id 1 is the DIP-switch read (see [Single-node interconnect](#single-node-interconnect-the-skip)). The command ids the SAL_B wrappers pass are 1, 3, 4, 8, 9, 10, 14, 18, 19, 21, `0x1005`, `0x1007`, `0x100a`, `0x100b`, `0x200d`, `0x200e`, `0x200f` and 6 (list from the call sites at `0xffa7ca9c` to `0xffa7fbbc`); the repository's controller pages own the protocol.

### The L1 requests from reset to the end of memory set-up, with arguments

Read from the SAL 5.04 SAL_B (`0xffa81f40`, `sysctl_cmd_construct_req`, 23 call sites; the call-site list is in the first column) with the SAL runtime component's symbols as the cross-check. Every request is task 6 unless stated; the frame is described above. A count of "n ints" means n tag-0 integers; the argument-word count the builder takes is twice that.

| Order | Request | Call site (function) | Arguments | What the PROM needs back |
|---|---|---|---|---|
| 1 | `0x1005` display text | `0xffa7e09c` (`0xffa7df40`, `sysctl_display_text`) | one string ("Prom starting..." is the first text the earlier trace saw) | status 0, no arguments |
| 2 | `0x100b` PROM version | `0xffa90f5c` and `0xffa9115c` (`0xffa90e60`, `0xffa91060`; called from `sysctl_init` `0xffa1f430`, phase 0xd) | three ints: 1, then two single bytes read from the PROM's own data (`gp-2055960`, `gp-2055959`; values not read) | none: the routine reads the reply with zero expected arguments and ignores its status |
| 3 | `0x0003` rack, bay, type | `0xffa7ca9c` (`0xffa7ca10`) | none | status 0, two ints (below) |
| 4 | `0x0013` slot | `0xffa7cc6c` (`0xffa7cbe0`) | none | status 0, two ints |
| 5 | `0x000e` slab | `0xffa7cf1c` (`0xffa7ce90`) | none | status 0, one int |
| 6 | `0x0009` partition | `0xffa7dc7c` (`0xffa7db00`; main `0xffa19dec`) | none | status 0, one int |
| 7 | `0x0001` debug switches | `0xffa7d0dc` (`0xffa7d040`; main `0xffa19e2c`, phase 0xe) | none | status 0, one int (bit 11 selects the single-node skip) |
| 8 | `0x0010` processor presence | `0xffae82fc` (in `0xffae8250`, called from `sysctl_cpu_presence` `0xffae8660`; from `main_early_disable` `0xffad34a0`, phase 0x10) | none | status 0, ints; the presence word PROM uses must have bit 0 set |
| 9 | `0x0006` EEPROM read, sixteen times | `0xffa8450c` (`0xffa843f0`, from `sysctl_eeprom_dimm` `0xffa85470`; "Probing memory DIMMs" `0xffa77bb0`, phase 0x16) | four ints: device id, selector 4, offset 0, length 48 | status 0, one int and one raw byte string, or any negative status for "absent" |
| 10 | `0x0015` sharing mode | `0xffa7fbbc` (`0xffa7fab0`) | none | status 0, one int |

**Order (inferred).** Rows 1 to 7 and 9 to 10 are the order of the earlier interpreter run (above); row 8 sits where the phase numbers put it (phase 0x10 is before 0x16) and the run reported eight requests before memory. The address order of calls inside `main` is not the execution order (the compiler placed blocks out of order), so the order here is not read from the code alone. Two orderings are not settled: whether `0x0013` or `0x000e` comes first (the run says `0x0013`; the first helper chain in the code reads `0x000e` right after `0x0003`), and where the first `0x1005` falls (the run puts it first; the code only shows ten callers of the display routine, from `main`, `main_two`, `main_three` and the interconnect and I/O discovery code, with no proof from the code that one precedes `sysctl_init`). Grade for every row's code, argument list and call site: established. Grade for the order: inferred.

**The replies the PROM's reader accepts, per request (established, `sysctl_cmd_interpret_resp` `0xffa82270` and the callers' expected-argument lists).** Status in bytes 0 to 3, argument count in byte 4, arguments from byte 5. Replies that carry ints are read with tag 0 per int; any other tag or a different count fails (-32 or -33) and the request is treated as failed. For `0x0003` and `0x0013` the second int is the module type character; the PROM compares it against 109 (`m`) and 111 (`o`) in `sysctl_cmd_open` (`0xffa819c0`) and `sysctl_rack_bay_type_get` (`0xffa7d1f0`) only when the open target is `0x4ffff000`; for any other type letter the target stays `0x0ffff000` and, in `0xffa7d1f0`, no node-EEPROM read is issued during cache fill (the EEPROM read there is taken only for type 111, which the Altix 350 module letter below is not).

**Board EEPROM requests after memory (established for the code, inferred for the field meaning).** `sysctl_eeprom_node` (`0x51320` in the runtime) issues two reads with device id 1, selector 1 then 2; `sysctl_eeprom_io_riser` (`0x51470`) one board read with device id 98; `sysctl_eeprom_iobrick` (`0x518a0`) the chassis and board reads with id 1, or 98 when the cached module type says so; `sysctl_eeprom_dimm` selector 4. Selector 1 is read by a function that expects the layout of an IPMI chassis information area (format version, length in 8-byte units, chassis type, then type/length-coded part number and serial number fields, then end marker `0xc1`; checksum over `length * 8` bytes; messages `read_chassis_ia: eeprom length byte of ZERO` and `bad checksum`). Selector 2 is read by `read_board_ia` (runtime `0x50ce0`): format version, length, language, three bytes of manufacture time, then type/length-coded manufacturer, product name, serial number, part number and FRU file id, then further type/length-coded fields until `0xc1`; the lower six bits of each type/length byte are the length, the checksum rule is the same, and a zero length byte or a bad sum fails the read ("error reading info area from L1 %d"). Where each string lands in the klconfig record's `Part:`, `Name:`, `Serial:` and `Revision:` fields: part from the part number, name from the product name, serial from the serial number are inferred from the field order; `Revision:` comes from the first custom field after the FRU file id (inferred; the code stores it separately and no label is carried). The PROM's string template, `Part:%s;Name:%s;Serial:%s;Revision:%s;Laser:%x;`, is in SAL_B at `0xffbbc8b0`.

## Memory discovery

- **Memory is discovered through the L1 and the SHub, not by I2C or SPD from the PROM (established for the path
  names, inferred for the details).** `sysctl_eeprom_dimm` (runtime name) reads a DIMM EEPROM through the system
  controller; the PROM has no I2C driver. `main()` phase 0x16 runs `memctl_get_bank_sizes` (runtime name, `0xffa6ac40`), a
  "Probing memory DIMMs" step (`0xffa77bb0`) and "Initializing memory controller" (`0xffa76bf0`, which reads and writes
  a long list of `0x81_...` memory-controller registers, calls `mdir_create_presence_vec` and
  `mdir_create_privilege_vecs`), then `0xffa782c0` "Initializing memory ... Module %M#%d bank %d", then
  `0xffa6f000` "Testing memory".
- **Memory must exist at physical `0x1000000` from reset (established).** The SAL_B reset entry reads
  `[0x1000010 + 8 * cpu]`, `[0x1000038]` and `[0x1000000 + 8 * (9 + cpu)]` and sets its stack from them, and a pointer
  table builder (`0xffac42d0`) fills the area at `0x1000000` from tables in flash. The PROM preloads cache lines for this
  (progress 0x32 and 0x34), so real DRAM is not initialised yet; on hardware this area is cache preloaded through PAL (inferred), not DRAM.
- **DIMM data and a memory-test pass are required (established for the checks, inferred for the run).** If the L1 reports no DIMM the PROM stops with 0x80 ("No memory on node"). The DIMM request, the SPD bytes used, the memory controller values and the test-completion bits are decoded under [Memory discovery](#memory-discovery-what-is-read-and-what-an-interpreter-run-of-the-image-shows). The firmware waits here for the memory-test engine's completion bits (below).
- **Jump to RAM (established).** Progress 0x19 `main()` calls `0xffac6bb0` "Switching to RAM ... and testing CPU", which
  copies the PROM to RAM (0x44), and continues in `main_two` (`0xffa1ade0`, prints "Reached main_two" in debug mode).

## I/O discovery

- **Reached in `main_three` at progress 0x24 (established as ordering).** The PROM carries PIC support: link-credit
  setting keyed on widget part number `0xd102` (`0xffab0130`), `pcibr_*` bridge code (PCI-X mode checks, slot setup,
  "IOC3/IOC4 devices must be located in one of the first 3 slots of a pci bus"), IOC3 and IOC4 setup, and the IO
  topology print. TIOCP, TIOCA and TIOCE code is also present, so the PROM is the union of the Altix products.
- **I/O riser (established as a name).** `sysctl_eeprom_io_riser` reads an I/O riser board record through the L1, and
  `sysctl_eeprom_iobrick` an IO brick record; the PCI riser is where the Altix 350 guide puts the PIC (the
  [Altix 350 page](../../../platforms/sn2/altix-350.md), 007-4660-001 p.105; not re-read here). This agrees with
  a PIC behind an XIO link from the SHub; recorded on [the cross-check question](../../../questions/altix-io-sn2-cross-check.md).
- **Base I/O probe (inferred).** Phase 0x13 "Probing for baseio" runs before memory; its detail was not read.
- **What lets discovery proceed (inferred).** A widget whose ID register reads part number `0xd102`, a PIC bus with the IOC4 in one of
  the first three slots, and a console UART on the IOC4 if the IOC4 console is chosen. The PROM can finish without any I/O
  device only if discovery tolerates an empty XIO port; not read.

## Console path

- **Candidates (runtime names, established):** the system controller console (`sc_cons_*`, chosen by `sc_cons_probe`, i.e.
  `sysctl_probe`, so selected whenever the signature is absent), the direct console on the SHub junk-bus UART
  (`direct_*`) and the EFI callback console. `direct_probe` writes `0x55` then `0xaa` to the UART scratch register
  (`0xf_fed4_0038`, on the master node only) and reads back the low byte; available when both read back. The PROM log
  shows progress 9, 0xa and 0x28 for the three.
- **Default (inferred):** the system controller console; the kernel's `ttySG` console uses the same path through the SAL
  console calls (`0x02000021` to `0x0200002c`). A junk-bus UART with a working scratch register is the other console path, the direct one;
  the L1 still has to answer (above).

## Hand-off to EFI

- **Established path.** `main_three` (`0xffad7280`) writes progress 0x27 and calls `0xffaf8c50` (prints "Loading EFI
  ..."), which finds the FIT EFI component (type 0x1f), expands it to RAM, writes progress 0x48 "Jumping to EFI", and
  enters it; EFI start-up writes 0x49 to 0x4f. The SAL system table and the SAL entry points are built before the
  jump, and the SAL runtime component (type 0x12) is also copied.
- **What EFI needs:** the SAL runtime calls the PROM answers (table on the firmware page), the console above, and for
  non-volatile variables a CFI flash at the top of the address space; `Syncing EFI var. store` and the checksum code
  are in `0xffaf6640` and `0xffaf6d10`. With the flash read-only, variable writes fail but the console does not.

## What the firmware waits for before the EFI console, in order

1. The L1: without a UART peer that answers the first requests the PROM dies at 0x8d before memory.
2. DIMM reports from the L1 and the memory controller's completion bits, so that 0x16 and 0x17 pass.
3. The single-node interconnect case: L1 command id 1 answered with `0x800` ([above](#single-node-interconnect-the-skip)); the trace then stops in the route-table walk, which needs the system-data-area step the run skipped.
4. PIC and a console device in discovery: `0xffab38b0` and `0xffab15c0` read in full; the PIC register reads and the PCI walk are not.
5. The CPU ID signature path avoids 1 and 2 and the board EEPROM read.

## What is not read

The `0x1_0001_0030` and `0x1_0001_0050` values and the DRAM command meanings, the interconnect registers on the non-skip path, the route-table initialisation, the
L1 command-id names, the contents of the I/O-widget register reads (until the interpreter reaches `main_three`), what the PAL index 528 call does, and the `node id`
install write. Each is listed in [questions/sn2-prom-open.md](../../../questions/sn2-prom-open.md).

## PAL procedures SAL_B calls

Re-enumerated for SAL 5.04 SAL_B (`0xffa01000` to `0xffc4e000`) from every call site of the four PAL wrappers and every immediate loaded into `r28` that reaches a PAL entry. Names are the numbering in Linux `arch/ia64/include/asm/pal.h` (Library root `linux-history`), whose header says it follows the Intel Itanium Architecture Software Developer's Manual rev 2.2. The manual itself is not held, so the names are the kernel's transcription of it (software expectation), not read from the manual. Earlier text listed 8, 32, 48, 64, 76, 224, 384, 608, 1040, 1072, 1088, 2472 and 3088; those are `adds rX=N,rY` structure offsets and are not PAL indexes.

**Wrappers (established, read).** Index is the first argument. `0xffa1d870`: static-register call (sets `r28` to `r31` from its four arguments and enters the inner routine `0xffa1d8c0`, which gets the entry point from `cpu_GetPALProcEntryPoint`, `0xffa1d430`, and branches to it). `0xffa1d960`: stacked-register call. `0xffa1da00`: static call in physical mode (its inner routine is `0xffa1da50`; it turns off translation with a return-from-interrupt when needed). `0xffa1dc20`: stacked call in physical mode. A few routines set `r28` themselves and call an inner routine directly.

| Index | PAL.h name | Where SAL_B asks (call site or routine) | Notes |
|---|---|---|---|
| 1 | PAL_CACHE_FLUSH | `salruntime_cache_flush` `0xffb1643c`; `0xffaeb360`, `0xffaeb400`, `0xffaeb450` | established |
| 2 | PAL_CACHE_INFO | `0xffaec15c`; `0xffa6ac40` (`memctl_get_bank_sizes`); `0xffaeb450` | established |
| 3 | PAL_CACHE_INIT | `0xffaeb3b0`; `0xffaeb7c0` (args -1 and 3) | established |
| 4 | PAL_CACHE_SUMMARY | `0xffb0eb7c`, `0xffb2126c` | established |
| 9 | PAL_BUS_GET_FEATURES | `0xffb10dac`; `0xffa9f9cc` | established |
| 10 | PAL_BUS_SET_FEATURES | `0xffb10e5c` | established |
| 12 | PAL_FIXED_ADDR | `0xffa9af30` | established |
| 14 | PAL_FREQ_RATIOS | `0xffa9edbc` | established |
| 17 | PAL_PROC_GET_FEATURES | `0xffa9c12c`, `0xffb20d9c` | established |
| 18 | PAL_PROC_SET_FEATURES | `0xffa9c2fc` | established |
| 20 | PAL_VERSION | `0xffb214fc` | established |
| 21 | PAL_MC_CLEAR_LOG | `0xffa0742c` (`proc_error_handler`) | established |
| 22 | PAL_MC_DRAIN | `0xffae6fbc`; `0xffb20860` | established |
| 25 | PAL_MC_ERROR_INFO | `0xffa05b1c`, `0xffa05c6c`, `0xffa0605c`, `0xffa3819c` | established |
| 26 | PAL_MC_RESUME | `0xffa37ff6` (`movl r28=0x1a`, then a branch to `b0` returns to PAL) | established |
| 29 | PAL_HALT_LIGHT | `0xffa9acd0`, `0xffaeb8d0` (idle loop) | established |
| 30 | PAL_COPY_INFO | `0xffa9e78c` | established |
| 32 | PAL_PMI_ENTRYPOINT | `0xffa3deec` | established |
| 37 | PAL_MEM_FOR_TEST | `0xffac701c` (in the jump to RAM), `0xffb21a7c` | established |
| 41 | PAL_PREFETCH_VISIBILITY | `0xffb20c40` | established |
| 42 | PAL_LOGICAL_TO_PHYSICAL | `0xffa9ad80`, `0xffa9ae00`, `0xffa9ae80`, `0xffa9af90` | established |
| 99 | not in pal.h | `0xffa9c44c` | unknown; between the architected 51 and 256 |
| 256 | PAL_COPY_PAL | `0xffa9e94c`, `0xffa9ea6c`, `0xffa9eb9c` | established |
| 258 | PAL_TEST_PROC | `0xffb20c1c` | established |
| 259 | PAL_CACHE_READ | `0xffb0ed3c` | established |
| 260 | PAL_CACHE_WRITE | `0xffb0f23c` (`cache_inject`) | established |
| 520 (0x208) | not in pal.h | `0xffa9b586`: arguments `0x1000000` and `0x40000`, from `0xffa9b210` right after the first progress codes | implementation-specific; inferred to be the cache-preload step (progress 0x32 and 0x34): its arguments are `0x1000000` and `0x40000`, the 256 KiB the PROM then uses as RAM; not in pal.h |
| 530 (0x212) | not in pal.h | `0xffaeb560`: one argument, skipped when it is 0 | implementation-specific, unknown meaning |
| 528 (0x210) | not in pal.h | SAL_A reason 3 only (static call, argument 5) | implementation-specific, unknown meaning |

Notes. 99, 520, 528 and 530 are the numbers not in `pal.h`; they are implementation-specific or unnamed here (**unknown**). Index 99 is the first argument of the wrapper call at `0xffa9c44c` (loaded as `mov r36=99` with the pointer in the next argument; the argument position was matched to the caller's frame, not run). The earlier text listed 530 as a direct call; it is reached only through the routine at `0xffaeb560`. Indexes that arrive in a variable (`0xffa9e32c`, `0xffa9fa9c`, and the wrappers themselves) were not resolved, so the list is the static set. The interpreter run described below executed PAL calls 3, 9, 10, 12, 17 (nineteen times), 18, 29, 42 and 520 before the memory phase.

Before the first progress code above 0x15 the firmware calls PAL 520 (any success), 12, 42 (logical-to-physical, one processor), 1 to 3 and 37 (jump to RAM). The rest are reached by error, MCA, idle and late-test paths.

## Memory discovery: what is read, and what an interpreter run of the image shows

**Method and its limit.** The disassembly of SAL_B was executed by a small interpreter written for this reading (integer subset, one processor, no devices) with the SHub ID registers, the real-time clock and the system controller set to the values below. It is a trace of the shipped binary under stated inputs, not hardware behaviour; it shows what the code does with those inputs. Graded **inferred** unless the code was also read.

**Inputs the run needed (each one a value the code needs):**
- SHub identification at node offset `0x1_0000_0000`, read by `chipset_init_chip` (`0xffa0f8c0`) through a bounded read helper: revision in bits 31:28, 16-bit part number from bit 12. The part number must be `0x4363` (17251; the check at `0xffa959a6`). A JTAG-style layout with bit 0 set and a manufacturer in bits 11:1 was used; the manufacturer field is not checked in the paths run (unknown). `0x81_1006_0580` must carry the node id in bits 42:32 (zero used). **Established** (read).
- The real-time clock at `0x1_101c_0000` must advance (delay loops compare it).
- The system controller answers. The PROM made eight requests through `sysctl_cmd_command_timeout` (`0xffa82a10`) before memory; a success status with an all-zero body was enough for all of them except `sysctl_cpu_presence` (`0xffae8660`), whose result is a per-processor presence mask. With a zero mask `main_early_disable` (`0xffad34a0`) treats processor 0 as disabled and stops at progress 0x87 ("Disabled by environment variable"); bit 0 must be set. The disable bitmask is also read from the environment variable `DisabledCpus` (flash variable store).
- Result on this input: 0x13 to 0x15 pass, 0x16 starts.

**Phase 0x16: DIMM discovery (`mdir_fill_node_dimmcfg`, `0xffa77bb0`; name from the string it prints).** Read in full (established); the request and the parse were also checked against the run. For each of four banks and four slots (sixteen DIMMs) it calls `0xffa7bd60`, which calls `sysctl_eeprom_dimm` (`0xffa85470`): open a transaction (target `0x0ffff000`), call the shared EEPROM read `0xffa84680`, close. The read is one request with command id 6 and four integer arguments (each argument occupies two words in the PROM's argument list, which is the eight in the argument array): the device id, the selector 4, the offset 0 and the count 48 (the earlier text of this page had the 4 and the 48 reversed: 48 is the byte count, each request carries at most 64, and 4 is a fixed selector passed to the shared read; that the selector picks the DIMM area is inferred, since the board-record readers pass 1 and 2 to the same routine). The device id is `8 + 8 * (slot & 1) + 2 * bank + (slot >> 1)`, so bank 0 slots 0 to 3 are ids 8, 16, 9, 17 and the sixteen ids run from 8 to 23 (observed in the trace in exactly that order). The reply is status 0, two arguments: an integer (the number of bytes returned) and a raw byte string of that length, which the PROM copies to a 256-byte slot buffer. A success status marks the slot present (bit `slot` of the bank's presence word); any error status marks it absent. A bank must have either all four slots present or none: a presence word other than 0 or 15 prints "DIMM groups must be plugged in sets of 4 DIMMs", names the missing slots, and disables the bank (`0xffa76290`). So the smallest memory the firmware accepts is four identical DIMMs in bank 0.

**SPD bytes the PROM uses (established, read in `0xffa7b1b0`, `0xffa7b310`, `0xffa7b410`, `0xffa7b6c0`, `0xffa7b7e0` and `0xffa7afd0`; byte numbers are those of the JEDEC DDR SDRAM serial-presence-detect layout, which the reads match; the layout itself is not held here).** The PROM asks for 48 bytes from offset 0 and reads only eight positions of them; the rest may be anything. Per DIMM unless said otherwise:

| Byte | Used for |
|---|---|
| 5 | number of ranks ("sides"): 1 gives code 0, 2 gives code 1, anything else is invalid; the four DIMMs of a bank must agree or the PROM warns "DIMMS within bank slot have different number of banks" |
| 31 | density of one rank: 0x10 gives index 0, 0x20 gives 1, 0x40 gives 2, 0x80 gives 3, 0x01 gives 4, 0x02 gives 5, any other value 7 (treated as empty); the smallest of the four DIMMs is taken. By the layout the indexes are 64, 128, 256, 512 MB, 1 GB and 2 GB per rank |
| 9, 18, 23, 25 | CAS latency: byte 18 is the supported-latency bit mask (0x10 for CL 3.0, 0x08 for CL 2.5, 0x04 for CL 2.0) and bytes 9, 23 and 25 the module's minimum clock period at CL 3.0, 2.5 and 2.0; a latency is usable when the bus clock's period (in the byte's own encoding: 0x50 for 5.0 ns at 200 MHz, 0x75 for 7.5 ns at 133 MHz, 0xa0 for 100 MHz, 0x63 for 160 MHz) is not below that minimum, and the PROM takes the lowest usable latency. The result is code 1 for CL 2.0, 2 for CL 2.5, 3 for CL 3.0, the largest over all DIMMs; CL 3.0 is forced ("Forcing max cas latency of CAS3_0") when nothing fits |
| 29 | tRCD in the SPD coding (bits 7:2 whole nanoseconds, bits 1:0 quarter nanoseconds); converted to bus clocks by rounding up and clamped to 2 to 4 with a warning outside that range; the value actually used is always 3 ("INFO: tRCD setting 2 is not supported. Setting tRCD to 3."), and all banks must agree or the PROM stops with "FATAL MEMORY CONFIGURATION ERROR" (`0xffad2c50`, 216) |
| 42 | the layout's auto-refresh-to-activate time (tRFC) in whole nanoseconds, the largest over the four DIMMs of each present bank; the PROM uses `floor(byte / 5)` raised to at least 14 (a floor, not a cap: `0xffa7b6c0` returns 14 when the quotient is 13 or less), and the largest is taken over all present banks, not per bank (the fixed 5 is the 5 ns period of 200 MHz; it does not follow the bus clock) |

Bank size in MB is `64 << (density index + rank code + 2)` (four identical DIMMs of one rank each of 1 GB: index 4, code 0, 4096 MB; two ranks of 512 MB: index 3, code 1, 4096 MB). The PROM prints it as "DIMM0 1024M (DIMMx4 = 4096M) : sides:2". The bus clock comes from bits 1:0 of the register at node offset `0x1_1006_0500` (read at `0xffa77e0c`): 0 gives 200 MHz, 1 gives 160, 2 gives 133, 3 gives 100 (a four-entry table of 16-bit values in flash, read). With the register at 0 the clock is 200 MHz. The timing index that selects the register values below is `0xffa76630`: 100 MHz with CAS code 1 gives 0; 133 MHz with codes 1 and 2 gives 1 and 2; 160 MHz with codes 1 to 3 gives 3 to 5; 200 MHz with codes 1 to 3 gives 6 to 8. Any other combination prints "memory bus speed (%d) and CAS latency (%d) not supported" and the register values are not usable, so a quiet boot needs DIMMs whose SPD gives one of those pairs.

**Phase 0x16/0x17: controller set-up (`0xffa76bf0`, "Initializing memory controller").** Read in full, with the register values from the run for one DIMM set: four DIMMs in bank 0, SPD bytes 0 to 47 as for a registered 1 GB PC3200 module built as two ranks of 512 MB (byte 5 = 2, byte 9 = 0x50, byte 18 = 0x1c, byte 23 = 0x60, byte 25 = 0x75, byte 29 = 0x3c, byte 31 = 0x80, byte 42 = 0x46), bus clock register 0, chip revision field 3 in `0x1_1006_0580` bits 31:28. That set decodes to 4096 MB, 200 MHz, CAS code 3, tRCD 3, timing index 8 (all **inferred**: values are what the code computed under these inputs; the field positions are established). The routine reads `0x1_0001_0008`, `0x1_0001_0048` and `0x1_0001_0040` (node offsets; all zero in the run), merges fields into each, and writes:

| Register (node offset) | Value in the run | Fields (established positions) |
|---|---|---|
| `0x1_0001_0000`, `0x1_0001_0008`, `0x1_0001_0010` | `0x8_6747_270b` | bits 35:32 the timing index (8); then one byte per bank k at bit 8k: bits 2:0 density index (7 = empty), bit 3 rank code, bits 6:5 the bank number k (bank 0 present: `0x0b`; banks 1 to 3 empty: `0x27`, `0x47`, `0x67`) |
| `0x1_0001_0028`, `0x1_0001_0048` | `0x36_4206` | six 4-bit fields at bits 3:0, 7:4, 11:8, 15:12, 19:16, 23:20, taken from the 16-bit words at offsets 14, 16, 18, 20, 22, 24 of the 32-byte timing-table entry for the index (the table is at `0xffbe0650` in flash; values not reproduced here) |
| `0x1_0001_0020`, `0x1_0001_0040` | `0x15_5400_4412_1002` | bits 7:0 are 0x02 (bits 7:2 cleared, bit 1 set); bits 39:8 the low 32 bits of the table entry's first word (`0x44_1210` here); bits 43:40, 47:44, 51:48 the 16-bit words at offsets 8, 10 and 12 of the entry (4, 5, 5); then one of bit 52 (tRCD 3), bit 53 (tRCD 2) or bit 54 (tRCD 4) |
| `0x1_0001_0060` | `0x4047` | `0x4047` if the revision field (bits 31:28 of `0x1_1006_0580`) is above 2, else `0x4045` |
| `0x1_0001_0058`, `0x1_0001_0078` | `0x400_4e20`, `0x24` | constants |
| `0x1_0003_0200` to `0x1_0003_0270` and `0x1_0005_0200` to `0x1_0005_0270` (stride 0x10) | all ones | eight iterations of a loop, one word in each block per iteration (their role is not decoded) |
| `0x1_0003_0400`, `0x1_0005_0400` | `0x1000` | constant |

`mdir_create_presence_vec` (`0xffa79310`) and `mdir_create_privilege_vecs` (`0xffa79960`) then write `0x1_0003_0100` and `0x1_0005_0100` (value 1), `0x110` to `0x130` (0), and the privilege vectors `0x1_0003_0300` to `0x1_0003_0370` and the same in the `0x1_0005_` block: `0x4bfff`, `0xc96f25b`, `0xfffffff`, `0x96ffff`, 0, 0, `0x4803f`, `0x48000` (values from the run for node 0, one processor pair, not decoded; the SHub page names `0x300` of each block as the kernel's privilege vector). Everything is a plain store; the run read back what was stored, with zero before the first store, except `0x1_1006_0580`. The routine at `0xffa775c0` then writes `0x1_0001_0030` and `0x1_0001_0050` (refresh interval 195 in bits 16:8 unless the environment variable `MemoryRefresh` overrides it; the tRFC clock count in bits 22:17; per-bank enable bits) and issues the DRAM initialisation command sequence through the test port described next; the values of `0x30` and `0x50` were not decoded.

**Phase 0x16/0x17: controller set-up (`0xffa76bf0`, "Initializing memory controller"; established as the register list, values depend on the DIMM data).** It takes the nasid and a per-bank configuration record and, in order: reads `0x9_0001_0008`, `0x9_0001_0048`, `0x9_0001_0040` (global window, node `n` in bits 38 and up; node offsets `0x1_0001_0008`, `0x1_0001_0048`, `0x1_0001_0040`) and merges fields from the record into them; writes `0x1_0001_0000`, `0x1_0001_0008`, `0x1_0001_0010`, `0x1_0001_0028`, `0x1_0001_0048`, `0x1_0001_0020`, `0x1_0001_0040`; calls `0xffa0ecd0` (tests a bit of `0x81_5003_1550`, a per-processor bit word whose meaning is inferred) and then, per processor, stores to `0x1_0003_0200`, `0x1_0005_0200` (value `0x4000000000` or 0) and the pair `0x1_0183_0200`, `0x1_0185_0200`, per processor (loop of up to eight); later stores to `0x1_0003_0400` and `0x1_0005_0400`; the SHub page lists `0x1_0003_0300` and `0x1_0005_0300` as the kernel's privilege vectors, so these neighbours are not named there; calls `mdir_create_presence_vec` (`0xffa79310`) and `mdir_create_privilege_vecs` (`0xffa79960`); then reads the node id register (`0x1_1006_0580`) and writes `0x1_0001_0060`, `0x1_0001_0058` (value `0x4004e20`) and `0x1_0001_0078`. These are the MD block registers (bits 31:28 of the offset are 0). Values written are mostly merged fields of the DIMM record and were not decoded; the order above is the order of the stores in the function.

**Phase 0x17: test and initialise (established for the completion logic, read in `0xffa6fb30`, `0xffa6fc60`, `0xffa700d0`, `0xffa70310`, `0xffa72500` and `0xffa6c3a0`).** The memory test and the DRAM initialisation commands share one engine, controlled through the register at node offset `0x1_0002_0088` ("test control") with `0x1_0002_0080`, `0x1_0000_0080` and `0x1_0000_00c0` around it. To start a step the PROM writes `0x1_0002_0080` (the address or command word), zero to `0x1_0000_0080`, all ones to `0x1_0000_00c0`, and then `0x1_0002_0088` with bit 40 set (go), a 7-bit operation code in bits 38:32 and a 31-bit value in bits 30:0. The engine is idle again when bit 40 reads back as zero; bit 41 set means the step failed. The wait loop (`0xffa6fc60`) polls `0x1_0002_0088` until `(value & 0x300_0000_0000) != 0x100_0000_0000`, with a deadline of `0x1312d00` (20,000,000) ticks of the real-time clock at `0x1_101c_0000`; on a timeout it returns -3 and the caller reports "MBIST TIMEOUT Byte Address = %#016lx" from bits 32:0 of `0x1_0000_0080` multiplied by 8, then the suspect DIMM names. After the loop it re-reads the register: if bit 40 is still set it clears it by writing the value back and waits again. The caller then tests bit 41 of the register: set means "MBIST failed" and the error report (`0xffa72500`) reads bit 36 of `0x1_0000_0080` (a compare error) and otherwise prints "MBIST failed other than bist compare error" with `0x1_0000_00b8`. The memory-test operation codes are 48 and 16; the DRAM initialisation commands go through the same register with operation codes 7, 2, 0, 0, 2, 1, 1, 0 in that order for the first bank (the command word in `0x1_0002_0080` for each: `0x200000`, `0x200000`, `0x100`, `0x9c800`, `0x200000`, `0x200000`, `0x200000`, `0x1c800`), which fits a precharge, extended-mode, mode-register, refresh and mode-register sequence (the DRAM meaning is inferred; the run only recorded the order). The code therefore needs: a 64-bit register at `0x1_0002_0088` that stores what is written, clears bit 40 at once (or within the 20,000,000-tick deadline) and leaves bit 41 clear, and plain storage at `0x1_0002_0080`, `0x1_0000_0080` and `0x1_0000_00c0`. With those two behaviours the trace passed "Testing memory" and "Initializing memory" with no fault printed.

A second wait guards the memory test: `memctl_mbist_credit_war` (`0xffa7a960`) uses a block transfer engine. It loads the bank map and the bank-size register, and for a bank that needs it writes the engine registers of node `n` at the global window address `0x8_01c1_0000 + n * 2^38`: the length-and-status register (IBLS0) at that address with bit 20 set and the length in the low bits, then the source (+0x8), destination (+0x10), notification (+0x20) and control (+0x18, value 17: notify and zero fill), and polls bit 20 of IBLS0 until it clears, with a deadline of 2,000,000 ticks. That address is the header offset `0x41_0000` of IIO_IBLS0, taken from the I/O interface block's start at `0x40_0000` and placed `0x1c0_0000` into the node's window, as the [I/O interface page](../../../devices/shub_ii/README.md#where-the-registers-sit) works out (arithmetic, inferred), and the length-and-status layout (busy bit 20) is that page's. A timeout prints "memctl_mbist_credit_war(): BTE TIMEOUT ERROR. IBLS0:0x%lx" with the register's value (the run printed `0x100008`, the stored value, where this page earlier called the register address unidentified). The code needs IBLS0 to clear bit 20 when it is written with it set; whether the engine really zero-fills the bank is not checked by the PROM.

**What the memory phase needs (inferred; the checks are established, the run is a trace).** (a) The L1 answers command id 6 with the frame above for the four ids 8, 16, 9 and 17, with a 48-byte SPD whose bytes 5, 9, 18, 23, 25, 29, 31 and 42 are consistent (the table above; an example set is given in the register table), and with any error status for the other twelve ids. (b) The `0x1_0001_00xx`, `0x1_0003_xxxx` and `0x1_0005_xxxx` registers store what is written and read zero before. (c) `0x1_1006_0500` bits 1:0 give the bus clock (0 for 200 MHz) and `0x1_1006_0580` carries the node id and revision as before. (d) `0x1_0002_0088` clears bit 40 after a write with it set and never sets bit 41. (e) IBLS0 at `0x8_01c1_0000` clears bit 20 after a write with it set. (f) The real-time clock advances. With those the trace went from progress 0x16 through 0x17 and 0x18 to 0x19 ("Switching to RAM"). Not covered: klconfig memory records, which are built after this (the run reached them only through the stand-in allocator described below).

## Single-node interconnect: the skip

`main_two` reaches progress 0x1c ("Discovering node interconnect") and calls `0xffa47870` (named `intcon_*` by the runtime signature). On the master node it prints "Discovering NUMAlink connectivity ........." and enters `0xffa47290`, which builds a configuration record (tag `0x50434647`, "PCFG") and calls a chip routine through a function pointer, then calls `0xffa450e0` and `0xffa975e0`. `0xffa975e0(11)` returns bit 11 of `0x81_5003_1560`; if it is set the PROM prints "*** Skipping NUMAlink discovery" and returns without reading any NI register.

**Source of bit 11 (established, read).** The word at `0x81_5003_1560` holds the **debug switches** in its low 16 bits. `main` writes it in phase 0xe ("reading debug switches"): it calls `sysctl_get`, then `0xffa7d040`, which sends L1 command id 1 with no arguments and parses a reply of status 0 and one integer argument (a request header of `0x0ffff006`, id 1, count 0; reply status 0, count 1, tag 0, four bytes big-endian); the returned value, if not negative, is stored by `0xffa974d0` as a 16-bit field at bit 0 of the word (and echoed as "Debug switches set to 0x%x"). If the read fails the PROM prints "*** System Controller DIP switches unavailable" and asks on the console (`0xffad2f10`), offering a default of "0000" or "0405" depending on the CPU ID signature. SAL_A's zeroing of the word therefore matters only until phase 0xe. So bit 11 of the flags word is bit 11 (value `0x800`) of the DIP-switch word the L1 returns for command id 1. The word is also tested at other bits (bit 8 at `0xffa19e9c` and `0xffa1a2ac`, others in the interconnect, test and EFI code; their meanings were not read). The `0xffa975e0` reader and the `0xffa974d0` writer (which takes the lock at `0x81_101d_0200`) and the field reader `0xffa97660` (shift and width arguments, eight callers) are the only users of the address in SAL_B.

**What lets the PROM skip discovery (inferred from the run).** The L1 replies to command id 1 with `0x800` (any other bits clear). With that the trace printed "*** Skipping NUMAlink discovery", then "Waiting for peers to complete discovery", then a one-entry "Discovery results" ("Entry 0: SHub ... Chiprev=3 Route=0x0", "Module=<0> Slab=0 Partition=0 Space=RESET", "Nasid=-1 Flags=0x100000", "Port 1 connection: Not connected", "Port 2 connection: Not connected"), "Global master is %I", "Partition master is %I", "Tree barrier", "nasid_nlocal_bits = 1", "ftdepth = 0" and "Calculating routes". With the bit clear (DIP word 0) the PROM takes the route that reads NI registers, which the run did not follow; the code of that route is read in [the section below](#numalink-discovery-with-the-skip-bit-clear-and-no-link). In the same run two "shub_port_status: vector 0x0/0 NI0 from %I failed" and "NI1 ... failed" lines appeared much earlier, in `main` before the memory test (`0xffa1a2ac` region), whatever the DIP word was; they are messages, not stops. Where the run then stopped is under [What stopped the interpreter run](#what-stopped-the-interpreter-run).

## NUMAlink discovery with the skip bit clear and no link

What `main_two` does when bit 11 of the debug word is clear, on a node whose network interface has no link (SAL 5.04, `shub1snprom.bin`, SAL_B component; the SHub's two interface ports are called NI0 and NI1 below). Read as disassembly of `0xffa47870`, `0xffa47290`, `0xffa450e0`, `0xffa5d2a0`, `0xffa5cf40`, `0xffa5d6a0`, `0xffa5e0b0` and the object tables they call through; nothing was run. Strings are reached through the SAL_B global pointer `0xffd98000` (so `addl rN=-1995248,r1` is the string at `0xffbb0e10`). Grades: **established** where the routine was read in full and the claim follows, **inferred** where it rests on a reading of part of the code or on a name.

**The skip bit only gates the neighbour crawl (established).** `0xffa47870` prints "Discovering NUMAlink connectivity" and calls `0xffa47290`. Before it tests bit 11 that routine has already built the local chip's entry in the configuration record: it calls the chip-ops entry at table offset 360 (`0xffa959d0`, which reads the 64-bit word at node offset `0x1_101d_0080` into a local), then `0xffa450e0`, which copies the chip descriptor into entry 0 and calls the chip's port-fill routine (ops offset 456, `0xffa5e0b0`). Only then does `0xffa4754c` call `0xffa975e0(11)`. Bit set: print "*** Skipping NUMAlink discovery" and return 0. Bit clear: the loop at `0xffa475b0` walks the entries; so the node's own NI port reads happen in both cases, which is why the two "shub_port_status ... NI0/NI1 ... failed" lines appear with the skip bit set as well.

**What the port-fill does (established for the reads, inferred for what the fields mean).** `0xffa5e0b0` takes the word from `0x1_101d_0080` (its bit layout below) and sets up two port records of 40 bytes each (the array pointer is at entry `+48`, records start at array `+40`). Byte 3 of each record gets bit 0 from the link-up mask: bits 55:54 of that word when its bit 40 is set, or the mask from `shub_port_status` (`0xffa5d6a0`) when bit 40 is clear. When bit 40 is set it also reads `0x1_5000_0010 + (port << 13)` and stores the complement of its bit 0 as bit 1 of the same byte; with bit 40 clear bit 1 is 0. The loop in `0xffa47290` tests only bit 0.

**The NI register reads (established as accesses; the names are unknown).** Per port `p` (0 or 1), `shub_port_status` calls `0xffa5cf40`, which uses node-relative offsets with the port number shifted left 13 (the two ports are `0x2000` apart):

| Offset | Access | What the code does |
|---|---|---|
| `0x1_5000_0048 + p * 0x2000` | read, conditional write, read | If bit 27 is set, write the value back with bit 27 cleared and read again; if bit 27 is still set the port is reported as status 0 (no link bit, no failure message). Bits 7:0 and 15:8 of the same register are read by `0xffa5d5e0` (an ops entry; the two fields look like error counters used by "intcon_chklink: Detected %d %s errors in port %d", inferred) |
| `0x1_5000_0000 + p * 0x2000` | read | Bits 3:0 must equal 9. Any other value returns -1 and the caller prints "shub_port_status: vector 0x%lx/%d NI%d from %I failed: %s" and counts the port as down. The value 9 is "link up" (inferred from use: it is the only value that lets the port continue) |
| `0x1_5000_1040 + p * 0x2000 + 16 * i`, i = 0 to 3 | read, repeated | Reached only with bits 3:0 of the previous register equal to 9: for each i the PROM re-reads while bits 22:16 are zero, at most 128 reads, and fails the port (returns -1) if all 128 still read zero. Not reached with no link |
| `0x1_5000_0010 + p * 0x2000` | read | Only the bit-40-set case above; sets bit 1 of the port record flags |

All of these go through the PROM's remote-register read `0xffa0bd20` (and write `0xffa0c560`) with the node's id taken from the entry, so they are plain register accesses to the node's own SHub. Linux v5.3 `shub_mmr.h` and `shubio.h` (checked by search, headers fetched into the working directory) define no NI register; the PROM's error-report tables hold the names `SH_NI0_LLP_STAT`, `SH_NI0_LLP_ERR` and `SH_NI1_*` (file offsets `0x1ac0f0` to `0x1ac280` in the image) but this reading found no link between those names and the offsets above, so no register is named here.

**"No link" in the PROM's terms (established).** A port is down when the low nibble of the register at `0x1_5000_0000 + p * 0x2000` is not 9. `shub_port_status` (`0xffa5d6a0`) loops p = 0 and 1, builds a 2-bit mask with a bit per port whose `0xffa5cf40` result was 1, prints the failure line for a result of -1 and continues; it never aborts. A result of 0 (bit 27 stuck) gives no bit and no message.

**The word at `0x1_101d_0080` (established as the PROM's use, inferred as meaning).** The routine `0xffa5d2a0` (called from the node-discovery routine `0xffa5df20`, ops offset 448, which prints "shub_discover: sysctl_get_pushed_data failed" on its error path) prepares it: it reads the word; if bits 55:54 are already non-zero it is done. If the word is zero, or has bit 41 or bit 39 set, it goes on at once. Otherwise it waits, polling every 10000 delay units (call `0xffa0db90`) until the real-time clock passes a deadline of the clock at entry plus `0x11e1a300` (300,000,000 ticks), then writes bit 41 and goes on anyway. It then zeroes the scratch words `0x1_5003_1550` and `0x1_5003_1540`, sets bit 39, clears bits 55:54, calls `shub_port_status`, stores the returned mask into bits 55:54, writes the word back (`0xffa96920`) and sets bit 1 of byte 43 of the chip entry. With no link the mask is 0 and bits 55:54 stay 0.

**The crawl does nothing for a node with no peer (established).** `0xffa47290` loops the entries (stride 72 bytes) and, per entry, calls ops offset 392 for the port count (`0xffa5d5b0` returns 2 for the SHub), then for each port tests bit 0 of byte 3 of the port record; a port with the bit clear is skipped without any register access. With both bits clear the loop ends with no neighbour probed, no router read and no vector request. It then prints "DONE" and "Found %d objects (%d chipsets, %d routers, %d iochipsets) in %ld usec" and returns 0.

**What it concludes and records (established for the code, inferred for the counts).** The configuration record keeps one entry: the local SHub, with both ports' link flag clear. The counts in the "Found" line come from the record header (offsets 24, 28 and 32), so for one entry they read one object and one chipset (inferred from the loop that fills them, not from a run). The caller `0xffa47870` takes the return 0 branch (`0xffa47ab0`: negative goes to the retry at `0xffa48380`, which waits `0x989680` ticks and calls `0xffa47290` again; not taken here) and continues at `0xffa47ac0`, the same place the skip path continues. The failure texts "NUMAlink discovery failed" and "Local hub could not do discovery." are on the negative-return path only.

**Same state as the skip path (inferred).** Both paths leave the same one-entry record with both ports marked down and then run the same continuation: the "Waiting for peers" wait (per-chip deadline the clock plus `0x11e1a300`), "Discovery results", `0xffa48560` and the master selection that prints "%s master is %I" (`0xffa42740` region, which walks the entries; for a single local entry it can only choose that entry, inferred from the partial read). The route calculation follows from the single entry. The differences read are the "DONE" and "Found ..." lines, a clock read at each end of the crawl and the extra call time; the bit-11 test itself is the only branch that separates them. This is a reading of the code, not a run.

**Retries and timeouts in the path.** Per port, a failed neighbour read is retried up to three times before the crawl returns an error (counter at `0xffa477e6`); the retry around the whole crawl waits `0x989680` ticks; the "Waiting for peers" loop uses `0x11e1a300` per chip and `2,000,000` in one case (`0xffa48210`); the state-word wait is `0x11e1a300`. The tick rate of the clock at `0x1_101c_0000` was not measured here, so none of these is converted to seconds.

**Not read.** The vector-request routines the crawl uses for linked ports (`0xffa45780`, `0xffa469f0`, `0xffa5b5d0` and the router and TIO ops tables); the meaning of the other bits of the `0x1_101d_0080` word that `0xffa5e0b0` copies into the entry flags (bits 16 to 22, 41, 58); the sibling ops tables at `0xffbd7f98`, `0xffbd8318` and `0xffbd8698` (the table read here is the first of four, selected for the SHub 1 by the `0x1_5000_0000` block and the `0xffa959d0` read, inferred); the master selection routine beyond its first screens; the simulator branch of the fifo loop (the CPU ID signature test at `0xffa5d156`).

## I/O discovery

The interpreter run did not reach `main_three`, so nothing below was run. It is the structure of the code, read from the call graph and the functions named, **inferred** unless it says read in full; the register-level answers for the PIC, the riser EEPROM and the PCI walk are still **unknown**.

- **Where it sits in `main_three` (established, call sites read).** After the progress writes for 0x21 to 0x23 and a long run of per-subsystem initialisers, `main_three` calls `0xffaad6d0` at `0xffad756c`; that is the only caller of `0xffab38b0`, the routine that prints "Discovering local I/O on nasid %d" (and "DONE"). Console selection comes later: `console_probe` at `0xffad76ec`, then `intcon_arbitrate_bmaster`, `sysctl_get`, and `0xffaf8c50` ("Loading EFI") at `0xffad777c`, with the fall-through paths printing "Global POD request" or "Local POD request" before "Running".
- **The per-node routine `0xffab38b0` (read in full).** On a non-master node it returns 1 at once. On the master node it makes an indirect call through the node's operations table (`[struct+32] + 256` in `0xffa99870`, argument 2) and proceeds only if that returns non-zero; it then calls `0xffab15c0`.
- **The widget identification read (`0xffab15c0`, read in full).** It finds the node's klconfig hub record (`0xffaa8a40`), takes a 16-bit nasid field at offset 48, and forms the widget-0 base address `(nasid << 38) + 0x8000_0008_0000_0000` (or `+ 0x8000_0000_0000_0000` when bit 0 of that field is set). It then calls `0xffab0560`, which sets the link credits (through `0xffab0130`, the routine keyed on the widget part number, below), and reads four bytes at that address through the bounded-read helper `0xffaeb170` (which returns 0 when the access faults or times out). The part number is bits 27:12 of the word and the revision bits 31:28. If the part is `0xd000` or `0xd100` (the crossbar types) it calls `0xffab0f10`, the crossbar walk; any other part prints "New Widget %x connected to HUB." and returns 0 without adding a klconfig entry. A read that returns 0 from the helper also returns 0, so an empty or dead XIO port ends discovery cleanly, with no I/O.
- **The crossbar walk (`0xffab0f10`, outline).** It creates the I/O brick record (`0xffab19f0`, "IOBRICK"), gets the link alive state for links 8 to 15 (`0xffab0900`, "Widget present, but link not alive!"), reads each link's widget identification (`0xffab14f0`, the same four-byte bounded read at `(nasid << 38) + link * 2^24` or `link * 2^28` depending on the address form), and branches on the part number: `0xc120` (49440) takes a generic path through `0xffab1b60`, `0xd102` (53506, the PIC) calls `0xffab0c00` twice, once at the widget's base and once 0x80_0000 above it (two register blocks, one per PCI bus: inferred from the offset), and then `0xffabfb10` (the PIC initialiser, not read); any other part prints "New Widget %x connected to HUB." and is skipped. Link credits come from `0xffab0130`, which picks a credit mask and shift from a table keyed on the widget part number and prints "can't find credit entry for wid_type" or "Using default link credit counts for UNKNOWN widget type" when the part is not in the table (the table was not decoded; `0xd102` has an entry, per the compare at `0xffab0260`).
- **Where the riser EEPROM is read (not traced).** `sysctl_eeprom_io_riser` (`0xffa85200` is the neighbouring `sysctl_p0_opus_tio_riser`) and the brick record readers use the same EEPROM read as the board record (command id 6, device id and selector as arguments); which ids and selectors the I/O path passes was not read.
- **A switch that skips all of it (established).** The separate I/O initialisation routine at `0xffaad720` (which has no direct caller in SAL_B and is reached through a table; its brick sequence reads the II register at `0x8_01c0_0128` bits 13:12 and prints "Found I/O brick attached to %I") tests bit 14 of the debug-switch word and, if set, prints "---- DEBUG - skipping I/O initialization on %I -----" and returns -1 without touching the I/O interface. Whether `0xffab38b0` has the same test was not read, so a DIP word with bit 14 set is a candidate for skipping I/O, not a verified way to do so.

## What stopped the interpreter run

The run executed the shipped SAL_B (integer instructions only, one processor, the PAL calls assumed to return success with zero results, the SHub registers as plain storage with the few behaviours named above) from the reset entry to the middle of `main_two`. It is a trace under assumed inputs: **inferred**, not hardware behaviour, and it did not reach `main_three`. What it needed beyond the memory section, each a value the code needs:

- **The jump to RAM (`0xffac6bb0`, progress 0x19) was skipped.** The routine lays out the system data area in the new RAM, copies the flash image there (printing "Shadowing SAL to ..." unless the CPU ID signature is set, in which case "Running under medusa - not shadowing SAL"), re-initialises the L1 link structure in the copy, switches stack and translation through `0xffaf5c80`, and enters `main_two`. The run instead entered `main_two` at `0xffa1ade0` directly, with the data left in the early 256 KB RAM at `0x1000000` and `main_ptov` returning its argument unchanged. Beyond the PAL's `PAL_COPY_PAL`-style calls (256, 37 and 520 returned success) and RAM large enough for the copy, the code needs nothing from this step.
- **A PIO write-error self test (`pio_wt_st_force_err`, `0xffa24cc0`, early in `main_two`).** It stores to `0x1_1005_0608` and spins until bit 0 or bit 2 of the PIO write status register at `0x1_2007_0200` is set; `pio_wt_st_reset` then clears it through the alias at `0x1_2007_0208`. The run set the status to `0x3f00_0000_0000_0005` on the store and back to `0x3f00_0000_0000_0000` (all six pending-count bits set, which is what the kernel treats as idle) on the alias write.
- **Allocation.** With the data in the early RAM the allocator ran out ("Out of memory - cannot allocate hwcfg at hwcfg/common/init.c line 78") because the arenas are sized for the RAM that the skipped step creates. The run substituted a bump allocator for `amalloc` (`0xffac30c0`); anything the PROM leaves in memory at hand-off from that point is therefore not representative.
- **The debug-information FIT entry** (type 0x23, "Debug info", present in the image) is loaded at the start of `main_two` through the FIT reader `0xffafaf50`, which reads the FIT through the top-of-flash window with bit 63 set; the interpreter had to alias that to the flash image. A real memory map needs the flash readable at its uncached alias.
- **The board EEPROM through the L1** (command id 6 again, selector 2, device id 1, count 0 meaning "until an empty reply") is read by `read_board_ia` (`0xffa84990`) as an IPMI-style FRU board information area: byte 0 version, byte 1 length in 8-byte units, byte 2 language, three bytes of manufacture time, then type/length-coded fields (low 6 bits length): manufacturer, product name, serial, part number, then one extra byte, the FRU file id, two more bytes and up to four further fields, ended by a byte `0xc1`; the sum of all bytes of the area must be zero or the PROM prints "read_board_ia: bad checksum". The chassis area is the same with selector 1 (`0xffa846c0`). The reply returns up to 64 bytes per request and the loop ends on a reply of zero bytes, so an end of data has to be reported as a zero count, not as an error; an error status makes the board read fail, which is non-fatal ("Could not retrieve EEPROM info on nasid"). The run used a 40-byte board area with the fixed strings from the built-in record ("SGI", "IP41", a serial, "030-1604-001") and answered every other selector with an error status.
- **Where it stopped.** In the route-table walk of `0xffa5b5d0` ("Distributing routing tables", main_two phase after "Calculating routes"): a loop that follows a 16-bit "next entry" index at offset 40 of each 100-byte-class entry until it reads -1. Entry 0 read 0 there, so the loop was endless. Entry 0's other fields were set (the discovery results above) but this index was not, which points to an initialisation done by the skipped system-data-area step or by the discovery code the skip bypasses; which of the two was not determined. This, not any hardware access, is what stands between the trace and `main_three`.

## Gaps remaining before "Loading EFI"

1. Which SPD sets and which L1 command-id meanings the real controller uses (the SPD positions, reply layout, test-completion bits, IBLS0 address and the source of bit 11 are settled above; what the selector 4 means to the L1 and what the real L1 reports for an empty slot are not).
2. The initialisation of the route-table "next entry" index that stopped the interpreter run, and the interconnect registers on the non-skip path (DIP bit 11 clear; the local node's NI reads are now read, [above](#numalink-discovery-with-the-skip-bit-clear-and-no-link); the linked-port crawl is not).
3. The whole of `main_three`: widget id read, credits, riser EEPROM, PCI walk, console selection (read statically below; not run).
4. PAL 99, 520, 528, 530 meanings.
5. The `0x81_101d_0080` and `0x81_101d_0088` relation.

## Review

Independent review of chips commits `ec38a7e`, `4bb8d3a`, `cb0fe84` and `b8fa253` (this page, the firmware page fixes, `questions/sn2-prom-open.md`, `evidence/irix-files.md`), examined at `b8fa253`. The reviewer did not write the page. Method: parse the FIT of `shub1snprom.bin` (SAL 5.04) and disassemble it with the retools `ia64-linux-gnu-objdump`; decompress the SAL runtime component (type 0x12) and read its dynamic symbols; compare other builds by instruction patterns. Nothing was taken from the page's own tables. PAL numbering was checked against the Linux `arch/ia64/include/asm/pal.h` in the Library `linux-history` root (it says it follows the Intel IA-64 SDM), not from memory.

**Confirmed (re-read in the binary).**

- FIT: PAL_B 7.79, 5.73, 2.25; PAL_A 7.31, 5.37, 1.27; SAL_A `0xffc4e000` (16 KiB), SAL_B `0xffa01000`, runtime, EFI types; reset-vector words at `0xFFFFFFE0` and `0xFFFFFFE8`. SHA-256 matches `root/sn2/SHA256SUMS`.
- SAL_A in full: every register write and value in the SHub 1 list, in the stated order and condition (`0x81_1002_0000` = `0x15031010`; bit 24 of `0x81_2001_0100`; `0x81_5003_1510/1530` ORed with `0x60` into `0x87_fed1_0000` and `0x87_fed3_0000`; election at `0x81_101d_0088` and `0x81_101d_0080`; winner zeroes `0x81_5003_1550/1540/1560`, writes 1 to `0x81_1006_0480`, later sets bits 41:39 of `0x81_101d_0100` to 7; error path with 176; FIT scan; `r31` read at `0x81_1003_0000 + (slice & 3) * 128`). `cr.lid` field is 4 bits at 26:23. Election direction (the processor whose value reads back is the winner and does the writes) is correct. PAL pair is chosen only on reason 3, after the node set-up. Reason 3 has the `psr.db` set, the routine returning 1, the spin on `r33` bit 3 and PAL index 528 with argument 5. Reasons 1 and 2 go to SAL_B at offsets 0x20 and 0x10, above 3 gives 177, the fatal hang is 178.
- Progress table at `0xffbd7000`: read in full (pairs of code and string). Every code and message the page quotes matches, including 0x8d, 0x89, 0x80 to 0x90 and 0x30, 0x38, 0x3b. Reason numbering follows from it.
- Main sequence: SAL_B reset entry at `0xffa01000` branches to `0xffa1de00` (progress 49 then 53, reads `0x1000010 + 8 * cpu`, `0x1000038`, `0x1000000 + 8 * (9 + cpu)`, calls `0xffac42d0` and `main` at `0xffa19a20`); progress writers in main, main_two (`0xffa1ade0`) and main_three (`0xffad7280`) carry the quoted code ranges.
- L1: UART stride 8 and registers (IER `+0x08`, LCR `+0x18`, LSR `+0x28`, scratch `+0x38`) in the runtime's `sc_uart_init`; `direct_probe` writes 0x55 then 0xaa to scratch, master node only; `sc_uart_init` checks bits 41:39 of `0x81_101d_0100` equal 7. `sysctl_probe` in 5.04 (SAL_B `0xffa806d0` and runtime) returns 0 on the signature and 1 otherwise, no hardware access. `sysctl_cmd_command_timeout` (SAL_B `0xffa82a10`): -24 at once on the signature; up to 50 tries, 500-tick wait, retry while -26; on -24 from the receive it calls the die routine with 141 (0x8d). 4.43's probe (2,000,000-tick retry) differs from 5.04's.
- Board identity: the `Part:030-1604-001;Name:IP41...` record is selected only when `cpuid[2]` equals the signature (`0xffaa14f6` to `0xffaa1530`; otherwise the EEPROM branch); "IP41" is a fixed string passed in `hwcfg_node_init` (`0xffaa2040`); `IP57` is absent from SAL_A, SAL_B and the decompressed runtime, ELF and driver components. `chipset_get_nasid` reads bits 42:32 of `0x81_1006_0580`. `shub_probe`-style compare against 17251 exists (`0xffa959a6`).
- PIC: part 0xd102 (53506) compared at `0xffab0260` in the function at `0xffab0130`, and at many later sites.
- Fixes in the earlier commits: SHub 2 region size from `0x2_0003_0000` (constant present in the 10.40 SHub 2 SAL_B), README.snprom contents and the Prism and Altix 350 recommendation, irix-files.md hashes and sizes (all six new rows match the root, `sha256sum -c` clean).

**Mechanical fixes made in this review.**

1. The page said codes 0xb0 to 0xb4 are "not in the table". They are (0xb0 "PAL early self-test failed", 0xb1 "SAL entered with invalid function code", 0xb2 "SAL invoked for firmware recovery", 0xb3 "SAL_RESET called with bad parameters", 0xb4 "main() returned"). This also supports reading `r35` as a PAL-reported fault (176). Text corrected.
2. The signature "is tested at 65 sites in SAL_B and in the runtime": 65 is the SAL_B count; the runtime has 31 more. Text corrected.
3. 0x49 and 0x4a are "Jump to EFI complete" and "Taking early return path from EFI"; the memory-map message is 0x4b. Text corrected.

**Findings not fixed (author to correct before these claims stand).**

1. **PAL index list is wrong and should not be "established".** The 23-number list mixes real PAL indexes with structure offsets: most of 8, 32, 48, 64, 76, 224, 384, 608, 1040, 1072, 1088, 2472 and 3088 occur only as `adds rX=N,rY` field offsets (for example `adds r28=1072,r32`, `adds r28=2472,r32` are pointer arithmetic, not a PAL call). Direct `r28` immediates feeding a PAL entry are fewer (1, 2, 3, 12, 16, 22, 29, 41, 42 and, in SAL_A, 528; 0x208 at `0xffa9b586`, 530 not shown reaching a call). Indexes also reach PAL through the wrappers at `0xffa1d870`, `0xffa1d960`, `0xffa1da00` and `0xffa1dc20`; call sites pass among others 9, 10, 14, 17, 18, 20, 22, 25, 30, 37, 256, 258 and 259. The progress table's own strings (PAL_COPY_INFO, PAL_MEM_FOR_TEST, PAL_TEST_PROC) agree. The names in the page for the architected numbers do match `pal.h` (1 cache flush, 2 cache info, 3 cache init, 8 VM summary, 12 fixed address, 16 platform address, 22 MC drain, 29 halt light, 32 PMI entry point, 41 prefetch visibility, 42 logical to physical, 48 get HW policy); the claim that they were "not checked" can now read "checked against `pal.h`". A PAL boundary list needs a fresh enumeration of the call sites; until then it is inferred, not established, and the lower-bound caveat is understated.
2. **Election read-back.** The page says the read of `0x81_101d_0080` returns the written value "for a plain read/write register". The code writes `0x81_101d_0088` and reads `0x81_101d_0080`, which are different addresses; a plain register at 0x80 does not reflect a write to 0x88. A write to 0x88 has to change what 0x80 reads (alias, or a first-writer latch; the reset value is unread). The error path ORs bits into 0x80, so 0x80 is writable. Grade: the register relation is unknown.
3. **IP57 sentence.** "An IP57 node is therefore handled as IP41 in klconfig unless the EEPROM read fails" is not what the code shows: the klconfig board name is the fixed string either way, and the EEPROM supplies part, serial and revision. The conclusion that no IP41 or IP57 branch exists stands; rewrite the sentence.
4. **Address forms.** SAL_A uses `0x80_0000_0000 + 0x7_fed1_0000` for the LED registers (bit 39) while the runtime's UART form is `0xf_fed4_0000` (bit 35 plus the local offset, with the NASID shifted to bit 38 in `sysctl` code). The page calls the second the "node-addressed form" without reconciling the two windows.
5. **Not verified, so keep as inferred:** the hand-off function at `0xffaf8c50` (its callee writes a progress value 72 only indirectly; the 0x44 to 0x48 stores were not located inside it), the 4.43 comparison sentence, per-build `sysctl_probe` for 3.32 and 4.20 (the 4.43 retry and 5.04, 4.90 compare-only were confirmed; I did not isolate the 3.32 and 4.20 functions), the SAL_B command-id list, memory and I/O discovery paragraphs, and the address-map line about the runtime's global-window constants.

**Grades.** The SAL_A reading, progress table, FIT, UART offsets, probe functions and board-record selection are correctly **established** (read in full). The names of SAL_B functions come from matching the runtime and stay **inferred**, as the page says (the die routine at `0xffad2cb0` is named by the call shape). Memory, I/O, console and EFI hand-off statements are **inferred**.

**Cleared scope:** progress-code table and reason codes; SAL_A on SHub 1 as a register list and order (except the election read-back); FIT and PAL pair listing; L1 death path (0x8d) and UART location, stride and probe; board-identity claim (no IP41 or IP57 branch, built-in record only under the signature); PIC part 0xd102 keying; the README fixes (SHub 2 SAL_A, region size, recommendation, per-build probe for 4.43, 4.90, 5.04, 1.11, 1.40, hashes). **Not cleared:** the PAL index list, the election read-back, the IP57 sentence, memory, I/O and EFI hand-off detail, and per-build probe for 3.32 and 4.20.

### Addressed after the review

The PAL index list was re-enumerated (see [PAL procedures SAL_B calls](#pal-procedures-sal_b-calls)); the election read-back now says the 0x80 and 0x88 relation is unknown; the IP57 sentence was rewritten; and the two address forms are reconciled in the L1 section. The 4.43 comparison, the hand-off function, the command-id list and the per-build probe for 3.32 and 4.20 are still inferred, as the review asked. The memory, interconnect and I/O sections added after the review rest on an interpreter trace of the image and partial reading; only the items marked established were read in full. The memory register decode, the L1 message frame, the DIP-switch source of the single-node skip and the I/O structure outline were added after that and have not been independently reviewed.

## Static reading for one node (SAL 5.04, not independently reviewed)

Added after the review above and **not independently reviewed**. Same image and method (retools `ia64-linux-gnu-objdump` text of `shub1snprom.bin`, SAL 5.04). "Read in full" means every instruction of the named function was read; direct-call reachability was computed over the same disassembly and does not follow calls through function descriptors, so "not reached" below means "not reached by direct calls". Nothing here uses the CPU ID signature path; where the signature or the CPU family would change a branch it is noted. Grades as above.

### 1. The jump to RAM (`0xffac6bb0`, read in full, with `0xffac7400`, `0xffaf5c80`, `0xffa9e730`, `0xfface570`)

Correction to the earlier summary: `0xffac6bb0` does not itself copy the PROM or enter `main_two`. Its argument is a pointer to the continuation's function descriptor (the only caller, `main` at `0xffa1a24c`, passes it; the descriptor the code reaches is `0xffac7400` with gp `0xffd98000`). The sequence, with progress codes written through the LED routine:

- **CacheSize and CPU family (established).** `0xffaebf80` returns 0 unless `cpuid[3]` bits 31:24 equal 0x20; if they do it reads the NVRAM variable `CacheSize` and `atoi`s it. The same family test at `0xffac6c00` skips the PAL shadow block below (taking the existing PAL entry point instead). The processor table in this image (15 rows at `0xffc51000`, keyed by exact `cpuid[3]`, ended by a zero key) carries family 0x1f for every Itanium 2 row (models 0, 1 and 2) and family 0x20 for eight later rows; so a Madison-class part, which the image does not name, takes the PAL-shadow path and only a family 0x20 part skips it. The branch depends on the processor's real `cpuid[3]`.
- **PAL shadow (established, for a family other than 0x20).** Progress 0x40. It sizes two areas by summing even entries of tables at `0xffbe6b78` (7 entries: 4 x 1 MiB and a trailing 6 MiB) and `0xffbe7b48` (16 entries) at `(nasid << 38) + 0x30_0200_0000`, then `0xffa9e730(addr, 0x700000)` calls PAL index 30 (PAL_COPY_INFO per `pal.h`), then PAL 256 (PAL_COPY_PAL) in master-then-others order with node barriers between, and records the copy as the new PAL entry point (`0xffa1d690`). Errors are "PAL_COPY_INFO failed", "PAL_COPY_PAL failed", "Bad PAL shadow address". The block needs only success from PAL 30 and 256 with a size of at most 7 MiB; whether the copied PAL is ever executed is unknown.
- **Layout and transfer area (established).** Progress 0x41. Two more sizing calls (table `0xffbe6c08`, four 1 MiB entries at `+0x30_0300_0000`; table `0xffbe71c8`, one 256 KiB entry after it). Then a 16 KiB "SDA xfer space" at the resulting address (`(addr & 0x7fffffcfffffffff) | 0x8000003000000000`) is filled with copies of records from the early data area: `0xffadffe0` copies pieces named by slots 1, 2, 3, 7 and 14 of the pointer table at physical `0x1000000` (`[0x1000038]` offsets 16, 24, 56 and `[0x1000070]` offset 56), `0xffac7ab0` copies three more (`[0x1000040]+208`, and two per-CPU records at `[0x1000000 + 8*(2+cpu)]` offsets 136 and 224), and `0xffacd5a0` packs the record at per-CPU offset 392 through `0xffa80960`. Overflow prints "SDA xfer space overflowed" (progress code 189). `0xffac7400` later restores the same pieces through `0xffae0500`, `0xffac7d60` and `0xffacd700` (inferred as the inverse; the bodies were not read).
- **CPU test buffer (established).** PAL index 37 (the page's earlier label; the error text calls it PAL_TEST_INFO) returns alignment and size; the buffer is aligned up, offset by `size * cpu_id`, and must end below `0xf800000` ("Bad PAL_TEST_PROC memory address", progress code 185). `0xffaf5c80` runs the test through `0xffb208b0` unless the packed first argument has its low 16 bits equal to 0xfffe (the second call, below, uses that); a non-zero result records the status in `0x81_5003_1500 + 16*cpu`, clears bits 29:26 of `0x81_5003_1550`, ORs `0x280_0000_0000` into `0x81_101d_0080`, writes `0x1_0001_0000_0000` to `0x81_2000_0000` and spins. Success continues with stack and gp switched: `ar.bspstore` at the buffer area plus 16 KiB, `sp` at area + 0x3fff0, gp from `0xffaf4790`, then `br b7` to `0xffac7400`.
- **In RAM (`0xffac7400`, established).** Progress 0x43. Every processor restores as above. If the CPU ID signature is absent: progress 0x44, print "Shadowing SAL to ..." (debug level), `0xfface570` copies `0x600000` bytes from the flash alias `0xffa00000` to `[[0x1000038]+40] + 0xa00000` with bit 40 set (read from `0xfface570`: the destination is its argument, which `0xffac7980` loads from offset 40; the +56 field is only the node-object key), flushes, calls an operation through the node object (`[[node+32]+312]`) and, unless it returns 2, calls `memctl_change_mem_permissions` on the copy. (With the signature the copy is skipped: "Running under medusa - not shadowing SAL"; stated as fact only.) The node's master processor (the one for which `0xffa0ff30` returns non-zero, the same test that gates the "Switching to RAM" message and the copy) first rebuilds the node-window layout (`0xffac42d0(1, nasid, 0)`, `0xffadd540(nasid)`, at `0xffac7a50`); the others skip that. Finally progress 0x45 and `0xffaf5c80` again, with `0xfffe` (no PAL test), a new stack and backing store taken from `[[0x1000000 + 8*(9+cpu)]+16]` (low 36 bits; sp +0x3fff0), gp and entry relocated into the SAL copy by masking with `0x7fffffcfffffffff` (which clears bit 63 and bits 37:36), and the original continuation, `main_two`, as the target. So after this step `main_two` runs from RAM on a new stack.

**What must exist afterwards on one node.**

- Ordinary RAM from physical `0x1000000` from reset (earlier section) and, in the node window, RAM behind `(nasid << 38) + 0x30_0000_0000 + offset` for the layout regions above and the 7 MiB PAL shadow area: at least about 16 MiB from the node's RAM base for the 6 MiB SAL copy at `+0xa00000` (ends at `+0x1000000`), the 1 MiB arenas and the transfer area. Bits 37:36 equal to 3 are an address attribute pair the PROM sets for its data window and strips to form the plain address; the [address map](../../../platforms/sn2/address-map.md) does not describe them for SHub 1 (**unknown**).
- The rebuilt pointer table and arenas at the node window (builder `0xffac42d0`, layout walker `0xffac4230`). Each slot at `0x1000000 + 8*n` names an arena of 0xa000 bytes (early) or 0x100000 bytes (node window) whose first words list sizes (odd entries are markers) and whose offsets array is written at arena +512 or +384; a zero-size entry is stored as 127 (`0x7f`).
- **The route-table puzzle.** The record list the trace stalled in (`0xffa5b5d0`) lives in the "PCFG" area at `ptov([[0x1000038]+48])`. `0xffa47290` zeroes 120 bytes there, writes the tag `0x50434647`, a limit at +40 (area + 0x80000) and **-1 into the 32-bit head index at +12**; the add routine `0xffa450e0` stores each new entry's 16-bit "next" at entry offset +88 (72-byte entries, fields at +48 to +120) from the list tail, so a first entry gets -1 there. Both run before the NUMAlink step. In the stored checkpoint `[[0x1000038]+48]` held `0x7f`, the layout builder's marker for an empty early slot (inferred from the builder, since the checkpoint state was read, not re-run): the area then sat at the unaligned address 0x7f in low memory instead of in a real arena. The likely cause of the endless loop is therefore the missing node-window layout from the skipped step, not an initialiser the PROM lacks. After the jump, `[SDA+48]` has to be a real RAM pointer from the node-window layout; the code then initialises head and next itself. This was not re-run, so it stays **inferred**.

### 2. I/O discovery on one node (`main_three`)

Reachable by direct calls from `main_three`: `0xffaad6d0` -> `0xffab38b0` -> `0xffab15c0` -> `0xffab0560`, `0xffab0f10` -> `0xffab0c00` (twice) and `0xffabfb10`.

- **Gate (`0xffab38b0`, read in full; corrects the earlier text).** Non-master nodes return 1 at once. On the master it fetches the node object (`0xffa0fa00`) and calls `[[node+32]+256](node, 2)`. It proceeds to print "Discovering local I/O" and call `0xffab15c0` only when that returns **zero** (`cmp4.eq p7,p6=0,r8` followed by a branch on `p6`, the return-1 path, for non-zero); the earlier page says non-zero. The routine does **not** test debug-switch bit 14. The only table in the image whose +256 entry is a plausible I/O init is the one holding `0xffaad720` (descriptor `0xffc4bc30`, array slot `0xffbd7ef0`, table base `0xffbd7df0`; no static pointer to the base exists, so the table is attached at run time: **inferred**). `0xffaad720` (read in full) is the real SHub I/O interface set-up and is where bit 14 of the debug-switch word is tested: set means "---- DEBUG - skipping I/O initialization" and a return of -1, which the gate treats as "no I/O". It returns 1 on a non-master node, and 0 or the status of its last step otherwise.
- **What `0xffaad720` does on the master (read in full for the sequence; callees partly).** L1-derived module type byte (`0xffa80430`, default 45, special case 111) then, in order: `0xffab1cc0` (large II/XIO register set-up), `0xffab30e0`, `0xffab2e60` (reads `0x8_01c0_0128`; bits 13:12 pick the brick check; prints "Found I/O brick attached to %I" and returns 0 when no brick, which makes the whole routine return 0 and skip the rest), `0xffab3020`, `0xffab3320`, `0xffab2f80`, `0xffab3640` (bounded read at the widget window), `0xffab33e0`, `0xffa91260`, a read-modify-write that clears bit 0 of `0x8_01c0_0250`, `0xffab14f0` (widget id read) and, if that read is not -1, `0xffab34b0` ("io_llp_setup: WARNING: Use of part 0x%x with SHUB unexpected!" for a part other than the expected set) and `0xffab3780`. **Registers touched by `0xffab1cc0` (addresses only; direction per access and values not decoded, inferred):** under `0x8_01c0_0000`: 0x008, 0x130, 0x140, 0x148, 0x160, 0x198, 0x1f8, 0x220, 0x228, 0x260, 0x3c0, 0x308, 0x348, 0x400 to 0x420; blocks at `0x8_01c1_0000` and `0x8_01c2_0000` (offsets 0x00, 0x08, 0x10, 0x18, 0x20, 0x28) and `0x8_01c3_0000` (0x00, 0x08); the same registers also appear in a second window at `0x40_xxxx` offsets (0x308, 0x348, 0x160, 0x198, 0x1a0, 0x1d8, 0x400 to 0x420) and at `0x9_1007_1080`. The code treats these as plain read/write storage with status bits it polls (not decoded here); no other SHub I/O answers were found on this path.
- **Widget-0 read (`0xffab15c0`, read in full; unchanged).** Four-byte read at `(nasid << 38) + 0x8000_0008_0000_0000` of the XIO widget 0 id; part in bits 27:12; for a one-node Altix 350 the part must be the crossbar types `0xd000` or `0xd100` for `0xffab0f10` to run; any other part prints "New Widget" and stops. Zero from the bounded read ends discovery cleanly.
- **PIC id and its layout (established for the checks, inferred for the rest).** The register helpers (control, direct map, response buffers, link layer, interrupt) all first read the 32-bit id word at the bridge base and classify it: part (bits 27:12) `0xd102` (PIC) or `0xd112` (TIOCP), manufacturer (bits 11:1) must be 0x24 (36) or the helper prints "unknown bridgetype"; parts `0xe000`/`0xe010` select another branch. So the widget id register for the PIC must read `0x?_d102_049` (revision in 31:28, bits 11:0 = 0x049). The PIC offsets the helpers use match `struct pic` in the public SN2 Linux tree (`arch/ia64/include/asm/sn/pic.h`, Library root `linux-history`): control `0x20`, direct map `0x80`, link layer config `0x48`, interrupt enable `0x108`, interrupt reset `0x110`, host error `0x128`, response buffer `0x280` (the even register; the odd one at `0x288` is presumably selected by the bus argument, not read).
- **`0xffab0c00` (PIC initialiser, read in full), called at the widget base (bus 0) and base + 0x80_0000 (bus 1).** Steps: set the low nibble of control (`0x20`) to the widget number taken from the link field of the address (bits 27:24, or bits 29:28 when the nasid is odd); ask the L1 for the module type byte (`0xffa80430`); unless it is 35 ('#') or 61 ('='), clear control bits 27:24, wait 2000 us, set them, wait 1,006,600 us (bridge reset pins; polarity not read); clear control bit 9; on bus 0 only, run the interrupt set-up `0xffabfa80` (writes to `0x108`, `0x110`, `0x128`); write 0 to the direct map (`0x80`); then the direct-map widget field (bits 23:20 cleared and set) from the low byte of the SHub II register at `0x8_01c0_0020` read for the local nasid; write `0x88889999` to the response buffer register for bus 0 and bus 1; set bits 9:0 of the link layer register (`0x48`) to 992 (0x3e0). The delays are `0xffa0db90` (microsecond wait).
- **`0xffabfb10` (bridge discover, read in full).** Reads the id, prints "bridge_discover: Enter" (debug), gets the card's manufacturing string (see 3), and picks the brick name and a type code from the L1 module type byte (61 'IXbrick', 35 'PXbrick', 111 and 109 and 108 'onboardIO', 118 'CGbrick', 107 'IAbrick', 106 'PAbrick', 94 'SAbrick', 98 'GAbrick', 102 'OpusTiobrick', 43 'AthenaBrick', else 'WEIRDIO'; 125 and 46 give 'Extendedbrick'). For `0xd102` or `0xd112` with manufacturer 36 it creates the bridge klconfig component for bus 0 (`0xffabf570`, which parses a `Laser:` field of the string with `strtoull`) and bus 1. With the signature the string is the built-in record "Part:030-1557-002;Name:IBRICK;...".
- **Link credits (`0xffab0130`, scanned, not read in full).** Called from `0xffab0560` per widget; keyed on the part number; for a part with no table entry it prints "xbow_set_link_credits: can't find credit entry for wid_type" and uses a default; it touches widget offsets 0x20 and 0x80_0020 and a SHub II register through `0xffab3580` (`0x8_01c0_0020`). The exact fields written are **unknown**.

### 3. The I/O riser EEPROM (inferred from the call chain; arguments partly read)

`io_mfg_info(nasid, buffer)` (`0xffaf1ee0`, read in full) calls `0xffaeccd0` for an odd nasid or `0xffaecd80` for an even one, then formats the result; on failure it prints "io_mfg_info: Could not retrieve EEPROM info on nasid" and empties the buffer (non-fatal). `0xffaeccd0` uses `0xffa84fd0` (open with mask `0x0ffff000`) and `0xffaecd80` uses `0xffa85550` (open with mask `0x4ffff000`, after a cache check `0xffa81510`; the device id is 1, or 98 when the cached module type byte is 111). Both read the chassis area (selector 1, `0xffa846c0`) and board area (selector 2, `0xffa84990`) as the FRU-style records described under "What stopped the interpreter run", then close the channel (`sysctl_cmd_close`). Per the earlier trace these go out as L1 command id 6 with device id and selector. Fields used: manufacturer, product name, serial, part and the FRU file id are formatted by `0xffaec9d0` into the `Part:...;Name:...;Serial:...;Revision:...;Group:..;Capability:..;Variety:..;Laser:...;` string (format taken from the built-in record at `0xffbb8318`); the only field parsed back is `Laser:` (`0xffabf570`). The brick type used for naming does not come from the EEPROM but from the L1 module type byte (`0xffa80430` or `0xffa80210`, cached through `0xffa81510`/`0xffa81630`). **Not read:** what the L1 command ids for the module type query are.

### 4. PCI behind the PIC, and the console

- **No PCI walk on this path (inferred from reachability and reading).** `0xffab0c00` and `0xffabfb10` write PIC registers and create klconfig records but issue no PCI configuration cycle and read no IOC4 register. The strings "IOC3/IOC4 devices must be located in one of the first 3 slots" and "Unable to set IOC4/IOC3 endianess" are in `0xffb38260` and `0xffb3ef90`, which sit in a driver block (`0xffb1xxxx` to `0xffb6xxxx`) that no direct call from `main_three` reaches. Its entry descriptors are in a table of (descriptor, procedure id) pairs at `0xffc26380` to `0xffc264e0` with ids `0x02000045` to `0x02000066`: SAL procedure handlers called from the OS (the SN SAL id range the kernel uses), not boot code. So the vendor and device ids, BARs and config reads the IOC4 needs belong to what the kernel asks the SAL to do, **not** to reaching "Loading EFI". Whether any of these handlers is also called by the PROM through a descriptor table was not followed (**unknown**).
- **Console selection (read in full: `console_probe` `0xffa1fca0`, its walker `0xffa1fae0`).** The spec string at `0xffbba0a0` is `rpd`; the walker looks each character up in a table of console objects (tag byte at object +104: `p`, `r`, `d`, then `e`), calls the object's probe and counts successes, then `set_console_device` and the object's operation at vtable +8. `d` is the direct console (`0xffaeaff0`, SHub junk-bus UART scratch test at `0xf_fed4_0038`, master only), `p` and `r` go through the system-controller path (`sysctl_get` then `0xffae9890`) and `e` is the EFI callback console, not in the spec. No IOC4 UART is selected on this path. The console therefore needs the L1 peer or the junk-bus UART, as the earlier section said.

### 5. The EFI hand-off (`0xffaf8c50`, scanned for calls and strings, tail read)

Order (read from the call and string list): load the SAL runtime component ("SAL runtime"), load the "Bios Emulator" component (an x86 BIOS emulator for option ROMs, prints "Loading Bios Emulator ..."), then "Loading EFI ..." (each through the FIT loader `0xffafaf50` and the image loader `0xffaf8690`/`0xffaf60b0`; a symbol-file offset mismatch only prints a NOTICE; failure prints "Could not load %s!  Panic..."). Then `0xffafc140` builds the exit state: an 88-byte record allocated and zeroed whose fields include a count from `0xffac8120`, limits `0x1fffc00` (at +16, +56, +64), 16 at +72 and 0x10000 at +80, filled further by `0xffafca90` (+24), `0xffb5c9b0` (+40) and `0xffb5a2f0` (+48); the value in its +48 field is stored at `[[0x1000040]+192]` (read at `0xffafc260`), and the record's address is printed as "SAL->EFI handoff at 0x%llx". Failure prints "ERROR: failed to set up exit state". Then progress 0x48 ("Jumping to EFI") and an indirect call through the loaded image's entry descriptor (`[r38]` instruction pointer, `[r41]` gp, both returned by the loader) with **first argument the 32-bit value 1 and second argument the pointer to the 88-byte hand-off record**. If it returns, the code reports code 190 and goes to the common failure path. The contents of the fields at +24, +40 and +48 and the EFI image's entry address (the image is compressed in the FIT; its entry comes from the loader at run time) were **not decoded**. The memory map and SAL system table that the three helpers build are not enumerated in this reading (**unknown**).

### What still stands before "Loading EFI" (summary of this reading)

1. A real node-window layout after the jump (item 1), re-run with the real jump, or a hand-built layout, so that `main_two` and `main_three` run in the interpreter.
2. The II register set-up in `0xffab1cc0` (addresses listed, behaviour not decoded) and `0xffab2e60`'s brick presence read.
3. The module type byte (and the riser EEPROM) from the L1: command ids not identified.
4. A widget id register of `0x?_d102_049` at the PIC and crossbar part at widget 0 behind the XIO port.
5. A console: the L1 peer or the junk-bus UART.
6. The contents of the hand-off record.

## Review (streams K and L)

Independent review of commits 19c52fb, ce4b54c, 051a79e and d11f205 (the DIMM and memory-controller reading, the single-node skip, the I/O discovery outline, the jump to RAM, I/O discovery, EFI hand-off, the SHub page's PROM-view line and the open-questions page). The reviewer wrote none of it. Method: the same SAL 5.04 image (sha256 `51ccf9ad...3a34617`), a fresh `ia64-linux-gnu-objdump` listing of SAL_B, and every claim below re-read in the listing; the interpreter was not run. Trace results stay **inferred**; an item is **established** here only where the function was read in full in this review.

**Confirmed (re-read in full, established).**
- L1 frame: `construct_req` (`0xffa81f40`) and `interpret_resp` (`0xffa82270`): request bytes 0-3 target OR 6, bytes 4-5 id, byte 6 count, tags 0 (4-byte big-endian), 1 (string), `0x80|n` (raw); reply status, -106 second field minus 106000, count byte, count and tag checks giving -32 and -33. Timeout `0x2dc6c0` in `0xffa82c10`.
- DIMM request: command id 6, arguments device, selector 4, offset 0, count 48 (`0xffa84680` into `0xffa843f0`); device id `8 + 8*(slot&1) + 2*bank + (slot>>1)` (`0xffa7bd60`, `0xffa85470`, caller `0xffa77bb0` passes bank then slot); reply int plus raw bytes.
- The eight SPD bytes (5, 9, 18, 23, 25, 29, 31, 42) and their encodings, including the CAS mask, the period encodings 0x50/0x63/0x75/0xa0, the always-3 tRCD and the fatal mismatch, the timing-index map (`0xffa76630`), and the bus-clock register `0x1_1006_0500` bits 1:0 with the flash table 200, 160, 133, 100. Controller register field positions and constants (`0x4047`/`0x4045`, `0x400_4e20`, `0x24`) match.
- MBIST: `0x1_0002_0088` bit 40 go/busy, bit 41 fail, deadline `0x1312d00` (20,000,000) on the clock at `0x1_101c_0000`, compare error bit 36 of `0x1_0000_0080`, other-error value at `0x1_0000_00b8`. IBLS0 at `0x8_01c1_0000 + (nasid<<38)`, bit 20, 2,000,000-tick deadline.
- Debug switches: word `0x81_5003_1560`, loaded in phase 0xe from L1 command id 1 (`0xffa7d040`: header, id 1, no arguments, reply one integer), bit 11 read by `0xffa975e0(11)`.
- Jump to RAM: `0xffac6bb0` takes the family test on `cpuid[3]` bits 31:24 (0x20 skips the PAL shadow and takes the current entry point); PAL 30 and 256, sizes, `0xf800000` limit, progress 0xb9/0xb8/0xbd, `0xfffe` skips the CPU test, the failure block (history word, clear bits 29:26, OR `0x280_0000_0000`, write `0x1_0001_0000_0000` to `0x81_2000_0000`, spin), stack `+0x3fff0`, `0xfface570` copying `0x600000` bytes with bit 40 set.
- I/O gate `0xffab38b0`: proceeds only when the node operation returns zero; no test of switch bit 14 (that test is in `0xffaad720` via `0xffa975e0(14)`, returning -1). Widget-0 address forms and parts `0xd000`/`0xd100` (`0xffab15c0`); PIC `0xd102`, TIOCP `0xd112`, manufacturer 36 in `0xffab3f40` (`0xe000`/`0xe010` select the other branch); `0xffab0c00` call pair at base and base `+ 0x80_0000`; PIC offsets control 0x20, link layer 0x48, direct map 0x80, even response 0x280 plus 8 per bus, interrupt 0x108/0x110/0x128, all matching `struct pic` in `arch/ia64/include/asm/sn/pic.h` (Library root `linux-history`).
- Riser EEPROM: open masks `0x0ffff000` and `0x4ffff000`, device 1 or 98 (111 selects 98), selectors 1 and 2, count 0 meaning "until empty". Console spec `rpd` passed at `0xffad76c0`; `console_probe` at `0xffad76ec`; hand-off call at `0xffad777c`. EFI record: 88 bytes, `0x1fffc00` at +16/+56/+64, 16 at +72, `0x10000` at +80, arguments 1 and the record pointer.

**Processor table (read from the image, not memory).** The table at `0xffc51000` (copy in SAL_B at `0xffbe0a08`) has 15 rows of `0x60` bytes ended by a zero key, keyed by exact `cpuid[3]`: seven rows with family 0x1f (`0x1f000404`, `504`, `604`, `704`, `0x1f010504`, `0x1f020104`, `204`, i.e. models 0, 1, 2) and eight with family 0x20 (`0x20000104` to `0x20000504`, `0x20000704`, `0x20010004`, `0x20010104`). Every Itanium 2 row carries family 0x1f, so a Madison-class part (a name the image does not carry) takes the PAL-shadow branch. The earlier version of the images page stated eight rows with one family 0x20 row; this image has 15 rows, eight of them family 0x20. [images.md](images.md) and [the firmware page](README.md) now say so.

**Errors found and corrected in place (each re-read in the listing).**
1. tRFC byte 42: the PROM result is `max(floor(byte/5), 14)`, a floor, not a cap (`0xffa7b6c0`); the maximum is over all present banks, not per bank.
2. The debug-switch word has a third accessor: the field reader `0xffa97660` (eight callers) besides `0xffa975e0` and `0xffa974d0`.
3. Jump to RAM, `0xffac7400`: the layout rebuild (`0xffac42d0`, `0xffadd540`) is on the path taken when `0xffa0ff30` returns non-zero, the same predicate that gates the "Switching to RAM" message and the SAL copy; the page had it on non-master nodes.
4. The SAL copy destination is `[[0x1000038]+40] + 0xa00000` (offset 40, no `ptov` inside `0xfface570`); offset 56 only keys the node object.
5. EFI hand-off: `[[0x1000040]+192]` receives the record's +48 field value, not the record's address (the address is printed and passed as the second argument).
6. The Madison family sentence replaced with the table result above.

**Remaining caveats, not edited.**
- `0xffa0ff30` returns 1 when no lower-numbered processor has its bit (26+i) set in `0x81_5003_1550`: the page treats non-zero as master; consistent with the master-only uses, but the bit's meaning is inferred.
- Debug-switch store at `0xffa19e50` also requires `0xffa0ff30` non-zero; the page says only "if not negative". `0xffaf5c80` skips the CPU test only when the low 16 bits are 0xfffe and the size argument is zero.
- SPD byte 31 mapping of 0x01 and 0x02 to 1 GB and 2 GB per rank (and the 64 to 512 MB values) is what the PROM does; the JEDEC layout is not held here, so the sizes in MB stay unverified. The request side does not cap raw-argument length at 127; the reply side masks it to 127 and does not check the 0x80 bit.
- Per-bank value tables and the interpreter-derived register values (for example `0x8_6747_270b`) were not re-run; they stay inferred. The bank-size claim "64 << (index + rank code + 2)" and the PAL area sums (4 MiB plus 6 MiB against a 7 MiB request) were not reconciled.
- `0xffab0f10`, `0xffab0130`, `0xffab1cc0` and the EFI loader were only outlined, as the page says.

**Verdict and cleared scope.** Cleared as static reading with the corrections above: the L1 frame and tagged arguments, the DIMM request and SPD use, the bus-clock register, MBIST and IBLS0 completion logic, the debug-switch source, the jump-to-RAM sequence, the I/O gate direction, widget and PIC id checks and PIC offsets, the riser EEPROM arguments, the console spec and the EFI record shape. Not cleared: anything graded from the interpreter run alone (register values, message sequences), the II register list, and link credits. Open-questions page and the SHub PROM-view line were checked against the page and agree with it.

## Review (stream M)

Independent review of chips commits `63907b1`, `0f33729` and `ccc8fa0` (the first-three-accesses reading, the bit-24 and SHub ID revision correction, and the L1 request table on this page) together with sysco `16abc12`, examined at chips `ccc8fa0`. The reviewer wrote none of it. Method: `ia64-linux-gnu-objdump` through the retools container on `shub1snprom.bin` (SAL 5.04, whole image disassembled at base `0xffa00000`); the ARM L1 program carved from package 4 of `l1-1.62.1.bin` with the sysco CramFS reader (SHA-256 matches the sysco page) and decoded with the container's ARM decoder; Linux v5.3 `shub_mmr.h`, `shubio.h` and `arch/ia64/sn/kernel/setup.c` fetched for the naming claims. Nothing was taken from the page's own tables.

**Confirmed (re-read in the binary).**

- `0xffc4e7f6` to `0xffc4e816`: load, OR `0x100_0000`, store of `0x8000_0081_2001_0100`, nothing else uses the loaded value. The other sites: `0xffa318b6` (OR 8), `0xffa31d56` (AND -9), `0xffa31ab6` (read, bit 3), `0xffaeb276` (OR `0x2_0000`), and the routine from `0xffa97796`. The bracket routine reads the value, writes it with bit 24 set, reads `0x81_2000_0000`, ORs `0x3b03f7` when `2 < revision` (`cmp.ltu` at `0xffa978d0`, revision from `extr.u 28,4` of `0x81_1006_0580`) and `1009` otherwise, writes `0x81_2000_0000`, then writes `0x81_2001_0100` back. The Linux `is_shub_1_1` is `rev <= 2` and `SH1_SHUB_ID` is `0x1_1006_0580`, as stated. Neither v5.3 header defines `0x1_2001_0100`, `0x1_101d_0080`, `0x1_101d_0088`, `0x1_101d_0100` or `0x1_5003_15xx`.
- History registers: `0x1510` and `0x1530` are read as 64 bits, ORed with 96 and stored with `st2` to `0x87_fed1_0000` and `0x87_fed3_0000` in the routine at `0xffc4e7d0`; that routine is entered at `0xffc4e08c` only for reason 0 or 3 (the `cmp.eq` pair at `0xffc4e03c`). Every progress writer (`0xffc4e100`, `0xffc4e596` to `0xffc4e5e0`, `0xffc4ee40` to `0xffc4ef00`) computes `0x81_5003_1500 + 16 * cr.lid[26:23]`, loads, shifts left 8 and deposits the code in the low byte.
- Election: `0xffc4e970` (called at `0xffc4e3a0`) computes `cr.lid[26:23] + 1`, `st8.rel` to `0x80000081101d0088` with post-decrement 8, `ld8.acq` from `0x...0080`, full 64-bit `cmp.eq`; equal: zeroes `0x1550`, `0x1540`, `0x1560`, writes 1 to `0x81_1006_0480`; not equal: skips. `0xffc4e730` (called at `0xffc4e3ec`) reads `0x80` again, compares again, and on a match does `dep 7 at bit 39, 3 wide` into `0x81_101d_0100`. The error path (`0xffc4e216` to `0xffc4e266`) clears bits 29:26 of `0x1550` and ORs `0x280_0000_0000` into `0x80`; `0xffaf5ea6` to `0xffaf5ef6` does the same; `0xffa0b0f0` ORs bit 41 after testing the other positions.
- PROM reply parser `0xffa82270`: status big-endian in bytes 0 to 3, count in byte 4, arguments from byte 5; tag 0 integers, tag 1 strings, `0x80`-flagged raw bytes; wrong type gives -32, wrong count -33, a nonzero status is returned as is (-106 gets a second code word). The 23 call sites of `0xffa81f40` are exactly the list given; the codes `0x1005`, `0x100b`, `0x0003`, `0x0013`, `0x000e`, `0x0009`, `0x0001`, `0x0010`, `0x0006`, `0x0015` and the task number 6 match the register loads before each call; the `0x0006` DIMM call goes through `0xffa84680`, which fixes selector 4, offset 0, length 48.
- ARM L1 reply frame (`syscom_process_outbound_response`, `0xc3f64`, read in full): byte 0 is `0x20 | subchannel`, bytes 1 to 4 the big-endian status, byte 5 the argument count, arguments from byte 6 (integer `0x00` plus 4 bytes, raw `0x80 | n` plus bytes, string `0x01` plus text), at most 127 bytes; a nonzero error code in the packet gives `0xffffffff` plus the code, nine bytes. The node strips byte 0, so the two ends agree. There is no echoed request code.
- Handlers: `0x0001` `0xc8b74` replies status 0 and `nvramGet(3)`; `0x0003` `0xc8bb8` replies `(setting1 << 6) | setting2` and the type character (`=` becomes `#` when a per-slot flag is zero); `0x0009` `0xc9e94` `nvramGet(14)`; `0x0015` `0xccc80` `nvramGet(0xcc) & 0x7f` (read in full here, so established, not inferred); `0x000e` `0xca214` the slab byte of the request tag, with the blade workaround only for types `,` `}` `.` `$` or more than one slot; `0x0013` `0xca2f8` for other types with one slot replies 0 then the type character, and otherwise the blade path with the -106 state check; `0x100b` `0xcb474` replies -100 when the argument count is not 4 and otherwise has no reply call at all. `0x0006` `0xc9658`: -100 for four or fewer arguments including the code, -104, -105 and -107 as stated; the device-id table `0xc7664`/`0xc7fd8` maps 0, 1, 4 to 7, 8 to 13, 16 to 21, 98, 99 to table indices 0, 1, 2 to 5, 6 to 11, 12 to 17, 18, 19 and everything else to -1. The brick-family switch sends `F` to `OpusTio_BrickOpsInit` (`0x3cc74`).

**Mechanical fixes made in this review (this page).**

1. The bit-24 restore does not restore the original: the saved value is the read value ANDed with `~(1 << 24)` (`and r37=r14,r8` at `0xffa977e0`, `r14 = 0xfffffffffeffffff`), so the routine ends with bit 24 clear whatever it was. The earlier text said "bit 24 as it was".
2. The "second copy of the same sequence" at `0xffa96296` is only the revision-split write to another node's `0x2000_0000`; it has no bit-24 bracket. The remote user of `0x2001_0100` is `0xffaeb2e0`, which tests bit 17. Added.
3. The `0x0010` call site `0xffae82fc` is inside `0xffae8250`, which `0xffae8660` (`sysctl_cpu_presence`) calls at `0xffae874c`; it is not inside `0xffae8660`.
4. The list of other `0x81_101d_0080` users omitted `0xffa0aef6` (remote OR of bit 39) and the two offset-form uses at `0xffa959f6` and `0xffa96946`; `0xffa4eba6` clears bit 40 and sets it again, so the net effect is a set. Text corrected.

**Findings not fixed.**

1. The `0x0010` reply order can be pinned from both ends, which the L1 page leaves open: the L1 single-slot handler sends status 0, then the node count, then the CPU count (its log is "slab%d %d CPUs, %d nodes" with those two values in that order), then for each node the presence word and the enable word. The node's reader (`0xffae83c0` onward) takes the first integer as the loop bound and rejects it with -100 if it exceeds the caller's limit, then reads a second integer with its own limit. Established from both routines; the table row still says inferred.
2. Sixteen DIMM reads: the caller loop (`0xffa77c80`) runs four iterations per bank and the device-id mapping gives ids 8 to 13 and 16 to 21 on an `F` brick, so `16` is consistent but the outer bank count was not re-derived.
3. `0x0010` for types `,` `}` `.` `$` or more than one slot goes down a different path (status 0, the integer 1, one more integer, then arrays), which this page and the L1 page do not describe; the `F` brick takes the single-slot path only if `brickNumSlots` is 1 (inferred, not read).
4. Order of requests stays inferred, as graded. Not re-run.

**The `0x0001` debug-switch conflict (state of the evidence, not a resolution).** Two facts, from two images. (a) PROM: the debug word `0x81_5003_1560` is loaded in phase 0xe from the integer in the L1's reply to request `0x0001`, and the single-node skip is taken only when bit 11 (`0x800`) of that word is set (`0xffa975e0(11)`); established. (b) ARM L1 1.62.1: the reply is `nvramGet(3)`, a 16-bit field (bits 23:8 of the word at `+0x1c` of the settings record, `0x303b4`); the `3` is the setting selector, not a value. The code does not fix what the field holds, and no default for it was read. Neither image fixes the value, so the firmware sources do not say the L1 replies 3 and do not say it replies `0x800`. The `0x800` on this page is the input the interpreter run was given to reach the skip (inferred; the run is a trace under assumed inputs). If an implementation returns the integer 3 (bits 1 and 0 set, bit 11 clear), the PROM takes the NUMAlink discovery path that reads NI registers, which is read [above](#numalink-discovery-with-the-skip-bit-clear-and-no-link). **Update:** the L1 settings default table has since been read: a blank or reset ARM L1 1.62.1 holds 0 in that field (sysco `software/firmware/l1/sn2-l1-settings-defaults-1.62.1.md`), so an unconfigured L1 replies 0, bit 11 clear, the same branch. What a deployed Altix 350's L1 holds is still unknown (set by the `debug` console command or a request `0x1001` from the node).

**Cleared scope.** The three `63907b1`, `0f33729`, `ccc8fa0` readings as corrected above: the bit-24 sites and the revision split, the history registers and progress read-modify-write, the election including the second read and the bit 41:39 write, the call-site list with codes and arguments, the PROM reply parser, and the L1 reply bodies for `0x0003`, `0x0013`, `0x000e`, `0x0009`, `0x0001`, `0x0015`, `0x100b`, `0x0006`. Grades stand except as noted (`0x0015` and `0x0010` ordering could move up). Not cleared: the names and meanings of the registers (all unknown, as graded), the order of requests, the `0x0010` reply for other brick types, and what the L1 holds in the debug-switch field.

## Processor reset entry

Where an Itanium 2 (Madison) processor begins executing when it comes out of power-on reset with `shub1snprom.bin`
(SAL 5.04, sha256 `51ccf9ad...3a34617`, 6 MiB, mapped so it ends at physical 4 GiB, base `0xffa00000`), and what that code
expects. Architecture from the Intel Itanium Architecture Software Developer's Manual, Volume 2, revision 2.3, May 2010,
document 245318 (fetched from Intel's public PDF; the Library holds no copy; sha256 `f08296c0...949b029`). Image read with the
retools `ia64-linux-gnu-objdump`, the top 256 bytes of the file and the 32 KiB block at `0xffff8000` taken as bundles.

**Grades.** *established*: stated by the manual, or read in full from the image. *observed*: seen on real hardware by a
third party. *software expectation*: from a public driver. *inferred*: everything else.

### What the manual fixes (established)

- Firmware address space is the 16 MB below 4 GiB. On reset "the processor begins executing code from the PALE_RESET
  entrypoint in the firmware address space" (section 11.2.1, p. 2:289; also section 11.1.3, p. 2:282).
- Top of the space (section 11.1.6, Figure 11-3 and bullets, pp. 2:284 to 2:286): `0xFFFFFFF0` 16 bytes of IA-32 reset
  code; `0xFFFFFFE8` physical address of SALE_ENTRY; `0xFFFFFFE0` physical address of the FIT; `0xFFFFFFD0` the 16-byte
  FIT entry for PAL_A (generic PAL_A in the split model), which "is not part of the actual FIT table" (Table 11-1,
  footnote a, type 0x0F; type 0x0E is processor-specific PAL_A); `0xFFFFFFC8` alternate FIT address (0 if none);
  `0xFFFFFFC0` zero. PAL_A "resides below 0xFFFF_FFC0" and "contains the hardware-triggered entrypoints PALE_RESET,
  PALE_INIT, and PALE_CHECK". The generic PAL_A searches the FIT (and alternate FIT) for the first compatible,
  error-free processor-specific PAL_A and branches to it. PAL_A is therefore found by the fixed `0xFFFFFFD0` entry
  (the block sits at a position the hardware vector reaches without the FIT), and the FIT is used only to find the
  processor-specific part and later components.
- The IA-32 reset vector at `0xFFFFFFF0` is the entry for IA-32 reset code, not the native one. Section 11.2.1 allows PAL
  to execute IA-32 instructions during self-test.
- The manual gives no numeric address for PALE_RESET inside PAL_A, and does not describe the processor state at the
  PALE_RESET entry itself (section 11.2.2 defines only the state when PALE_RESET calls SALE_ENTRY).
  **The entry offset is not an architectural fact in this document.**
- State handed to SALE_ENTRY (section 11.2.2, pp. 2:289 to 2:291; this is PAL's exit state, not its entry state):
  GR20 SALE_ENTRY state parameter (function 3 recovery check, then 0 reset); GR32 = 0; GR33 processor id and LID
  read-only mask; GR34 PAL procedure call address; GR35 self-test state; GR36 return address into PALE_RESET (PAL
  authentication call address on the second call); GR37 self-test control word; GR38 PAL_MEMORY_BUFFER requirement
  (Table 11-2). Other GR, BR, PR, FR undefined. RSC = 0, CFM.sof = 96, PSR.bn = 1 with all other bits 0 (bits df1/dfh
  set if the FPU failed self-test), DCR = 0, IVA 0 for the recovery check, interrupt block pointer `0xFEE00000`,
  caches enabled and invalidated, TLB invalid with translation off.

### What the image has (established, read in full)

| Address | Content |
|---|---|
| `0xFFFFFFF0` | bytes `ea 5b e0 00 f0`: an IA-32 far jump to `f000:e05b`, then `"11/02/99"` at `0xFFFFFFF5`, `00`, `fc`, `31` (x86 BIOS reset vector layout) |
| `0xFFFFFFE8` | `0x80000000ffc4e000`, SALE_ENTRY, equal to the FIT SAL_A entry |
| `0xFFFFFFE0` | `0x80000000ffa00000`, the FIT |
| `0xFFFFFFD0` | FIT-format entry: address `0xffff8000`, size `0x7fc0` (to `0xFFFFFFC0`), version 7.31, type `0x0f` (checksum flag set, byte `0x6e`; the 32,704 bytes plus `0x6e` sum to zero modulo 256, so the checksum holds) |
| `0xFFFFFFC8`, `0xFFFFFFC0` | zero (no alternate FIT) |

So the 32 KiB block at `0xffff8000` is the generic PAL_A, not IA-32 BIOS code: the FIT-format entry at `0xFFFFFFD0`
describes exactly it. It also contains the text "Copyright (C) 2002 Intel Corporation" at `0xffffff00`. The earlier
"no FIT entry describes it" and "IA-32 BIOS layout" readings are superseded; only the last 16 bytes are IA-32. The
FIT proper has 15 entries (header count 15, `0x7f` at the end): PAL_B 7.79 `0xffdc8000`, 5.73 `0xffe78000`, 2.25
`0xfff28000`; processor-specific PAL_A (type `0x0e`) 7.31 `0xfffc2fc0`, 5.37 `0xfffc9ac0`, 1.27 `0xfffd0280`; SAL_A 5.04
`0xffc4e000` (16 KiB); SAL_B 5.04 `0xffa01000`; runtime (0x12), 0x13, EFI (0x1f), 0x22, 0x23. Its header is `_FIT_   `,
15 entries, version 0x0260, checksum flag set; the 240 bytes sum to zero.

The vector bundles sit at 16-byte spacing just below the PAL_A FIT entry:

| Bundle address | Form | Target |
|---|---|---|
| `0xFFFFFF50`, `0xFFFFFF60` | `br.few b0` | return through b0 (no target) |
| `0xFFFFFF70` | `br.few` | `0xFFFF83F0` |
| `0xFFFFFF80` | `br.few` | `0xFFFFDA60` |
| `0xFFFFFF90` | `br.few` | `0xFFFF8A80` |
| `0xFFFFFFA0` | `br.few` | `0xFFFF8DA0` |
| `0xFFFFFFB0` | `[MBB]` `br.cond.spnt.few`, `br.many` (both the same target) | `0xFFFF83A0` |

**Which one is PALE_RESET (inferred).** Three public sources and the image's own layout agree on `0xFFFFFFB0`; none
states it for Itanium 2.

- Intel patent US 7,305,544 B2, "Interleaved boot block to support multiple processor architectures and method of use" (FIG. 6
  description; <https://patents.google.com/patent/US7305544B2/en>). The IA-32 reset vector is "by way of example"
  `0xFFFFFFF0`; the Itanium-processor-family reset vector is "for example" `0xFFFFFFB0`; the processor then runs "a basic
  initialization and check under PAL-A" and passes control to a SAL-A entry point. The FIG. 4 text calls the reset
  vector "a PAL-A entry point", and the FIG. 3 text says the vector locations "may be hardwired into the CPUs". Established
  as Intel's description; the address is given as an example, not as a specification.
- linux-ia64 list, 2001-12-10, thread "[Linux-ia64] Hard hangs with 2.4.16" (Library root `linux-ia64-list`, message
  id `marc-linux-ia64-105590698805668@msgid-missing`). An IBM engineer who had an ITP debugger on Intel Lion (Merced)
  systems corrects an earlier line: `0x80000000FFFFFF90` is PALE_CHECK and `0x80000000FFFFFFB0` is PALE_RESET.
  Observed on Itanium (Merced), not Itanium 2.
- Itanium 2 Processor Hardware Developer's Manual 251109 (Library `docs/library/cache/cpu/itanium/`): after RESET# is
  deasserted "each processor begins execution at the power-on reset vector defined during configuration" (section 3.2.1,
  p. 3-4; PDF page 28), and, unless outputs are tristated during configuration, "the processor begins program execution
  at the reset-vector" (appendix A.1.51, p. A-12; PDF page 64). It gives no address.
- SDM volume 2, revision 2.3, Table 5-6 (p. 2:109): RESET is an abort and takes the PALE_RESET vector.
- Intel's own server BIOS carries the same PAL_A (established, byte comparison; script run for this page). The Intel
  SR870BN4 (Tiger4) BIOS image `S870BN4C.BIN` from package `SR870BN4_1001_SUP3.ZIP` (5,111,342 bytes, sha256
  `fb422439a42e3d06fe5286c68942c03293868cdde07891758437d4f98642d252`; taken from a Wayback capture of Intel's
  download) ends at physical 4 GiB like the SGI image. The 0x70 bytes of SGI's vector region (`0xFFFFFF50` to
  `0xFFFFFFBF`) occur byte for byte exactly once in it, at file offset `0x4dfd7e`, its own top-of-flash vector region.
  Of the 511 aligned 64-byte windows of SGI's generic PAL_A (`0xffff8000` to `0xffffffbf`), 510 occur in the Intel
  image; the one that does not is the first, at `0xffff8000`. In the top 64 bytes (`0xFFFFFFC0` to `0xFFFFFFFF`) the
  two images differ only in the alternate FIT address, the PAL_A FIT entry's version and checksum bytes, the FIT and
  SALE_ENTRY pointers, the date string ("11/02/99" on SGI, "01/01/01" on Intel) and the final byte. So the generic
  PAL_A and its hardware entry vectors are Intel's common code, the same on SGI and Intel platforms. That makes
  Intel's patent and the ITP trace evidence about this PAL_A's vector layout; the reset address for Madison stays
  inferred, because neither names Madison silicon.
- The image's layout: `0xFFFFFF90` and `0xFFFFFFA0` hand off to PAL_B and are the CHECK and INIT pair, and
  `0xFFFFFFB0` is the only two-branch bundle, as in the patent's vector. Taking `0xFFFFFFB0` as the entry: the
  processor's first bundle is the one at physical `0xFFFFFFB0` (the PROM's own pointers carry bit 63 for uncached; the
  vectors are not read through them).

### The code at the entry (established decode, inferred meaning)

`0xFFFFFFB0` branches to `0xFFFF83A0`, inside generic PAL_A. That code, in order:

```
movl r3 = 0x80000000ffffffe0
mov  r40 = 1225 ; mov r42 = 212
mov  msr[r42] = r0 ; mov b0 = r3 ; mov r41 = 4
mov  msr[r40] = r41 ; srlz.d ; mov r5 = 1
br.ia.sptk b0
```

It reads no general or branch register: every source is an immediate or a register it wrote. It writes two
model-specific registers (numbers 212 and 1225; their meaning is unknown, these are processor-specific `msr` accesses
the SDM does not define) and executes `br.ia`, the switch to the IA-32 instruction set, with `b0` set to
`0xffffffe0`. The architectural effect is the IA-32 transition, but the target holds no IA-32 code and the reset-time effect is unknown: see [the br.ia sites](#the-bria-sites-what-they-are-not-established-and-what-they-might-be-inferred)
and the conclusion. Whether code at the `br.ia` target exists, and where control goes afterwards, is read in [the vector map](#the-vector-map) below: the target holds the two pointers, not instructions.

The native path the architecture describes is at `0xFFFF83F0` (entered from the `0xFFFFFF70` bundle): `alloc
r1=ar.pfs,96,0,0`, `mov pr=r0,...`, `mov r3=3`, `mov r71=cpuid[3]`, reads `cr.ifs`, loads `cr.ipsr = 0x100800000000`
(bits 44 and 35, so `psr.bn` is 1) and `cr.iip = 0xffff8470`, and executes `rfi` to move to physical addressing; then at
`0xffff8470` clears `cr.iva`, zeroes `r73` to `r78` and `r94` to `r96`, sets `r81` to the text `_FIT_   `, and reads the
FIT pointer from `0xFFFFFFE0` (alternate from `0xFFFFFFC8`), walks 16-byte entries comparing types against 0x0e and
`cpuid[3]` fields (family, revision, model), which is the generic PAL_A search the manual describes in section 11.1.6.
Its only inputs are `cpuid[3]`, `cr.ifs` and the FIT; it reads no GR or BR given at reset. (Established for these
instructions as read; whether hardware starts here or at `0xFFFFFFB0` first is the open point above.)

### Answer for an IA-64 CPU model

1. The first instruction fetched is the bundle at physical `0xFFFFFFB0` (inferred; the SDM gives no address, Intel's patent and a Merced trace do),
   uncached firmware space, executing in place from flash.
2. It branches to `0xFFFF83A0` in the generic PAL_A (`0xffff8000` to `0xffffffbf`, FIT entry at `0xFFFFFFD0`, type 0x0f).
3. No register is read at entry; the processor's reset state (PSR bits, ITC, IP) is only the processor manual's
   business and is not given by the SDM. A model must reset to a state in which `br.ia` and the two `msr` writes
   execute, then reach `0xFFFF83F0` for the native path (not settled how).
4. The SDM's register list (GR20, GR32 to GR38, CFM, PSR, IVA) is what SALE_ENTRY receives (SAL_A reads r20 and r33
   to r37, see [SAL_A on SHub 1](#sal_a-on-shub-1)), not what PALE_RESET receives.

### The vector map

All of generic PAL_A (`0xffff8000` to `0xffffffbf`, 32 KiB) was disassembled and every function reachable from the
vector bundles was read to its end, except the register-save variants noted below. The whole 6 MiB image was also
disassembled and searched for any immediate or data word equal to `0xFFFFFF70`, `0xFFFFFF80`, `0xFFFFFF90`,
`0xFFFFFFA0` or `0xFFFFFFB0`: none exists. Only the vector bundles themselves branch to the five targets (the one other
reference is a call to the `0xFFFFFF80` target from inside generic PAL_A, below). The FIT-format entries are the table
read above; their reserved byte is zero in every entry.

| Vector | Target | What the target does | Reading |
|---|---|---|---|
| `0xFFFFFF50`, `0xFFFFFF60` | none | return through `b0` | stubs; no hardware use is visible (inferred) |
| `0xFFFFFF70` | `0xFFFF83F0` | the cold-start path: sets `cr.ipsr`, `rfi`, validates and searches the FIT, hands over to processor-specific PAL_A | the only code in the image that reaches processor-specific PAL_A (established) |
| `0xFFFFFF80` | `0xFFFFDA60` | a function with a normal prologue (`alloc r1=ar.pfs,96,0,96`) taking an argument in `r32`; also called by `br.call` from `0xFFFF881C` with `r32 = -2` | not a hardware path; software-callable PAL_A routine that works on FIT/PAL_A contents (inferred; not read in full) |
| `0xFFFFFF90` | `0xFFFF8A80` | saves `r30` into `msr` 0, `r31` into 1641, `pr` into 1642 and `r29` into 1643 (guarding each with a NaT test), tests bit 56 of `msr` 1640, finds a PAL_B (FIT type 1) entry, jumps to PAL_B plus `0x10080` | machine-check or INIT entry (inferred) |
| `0xFFFFFFA0` | `0xFFFF8DA0` | the same code with the same saves, jumps to PAL_B plus `0x10070` | the other of the pair (inferred) |
| `0xFFFFFFB0` | `0xFFFF83A0` | two `msr` writes and `br.ia` (below); nothing after it | see the conclusion |

Established detail for the PAL_B hand-off at `0xFFFF8A80` and `0xFFFF8DA0`: both fall into one search loop (the two
copies differ only in the pre-save variant chosen by predicate `p1`, and in the offset). The loop reads the FIT
through `0xFFFFFFE0`, walks entries until type 1, and accepts the first entry whose dword at image offset `0x10114`
gives the same CPUID family and model as `cpuid[3]` and a revision byte not below byte 1 of `msr` 1715 (the
processor's own value, meaning unknown), then adds `0x10080` or
`0x10070` to the image address (bit 63 set) and branches there with the old `b0` kept in `r31`. If `msr` 1640 bit 56
is clear it takes the generic error path at `0xFFFF8120` with `r30 = 2`; a FIT type above 1 gives `r30 = 12`. Which
of the two vectors is machine check and which is INIT is not decided by the code: a 2001 linux-ia64 post, from
an ITP on Merced systems, calls `0xFFFFFF90` PALE_CHECK (observed on Itanium, see above), which would make
`0xFFFFFFA0` PALE_INIT.

### The generic PAL_A search and the hand-off (established)

From `0xFFFF83F0` (entered by the `0xFFFFFF70` bundle):

1. Reads `cpuid[3]`, sets `cr.ipsr` and `cr.iip` and executes `rfi` to `0xFFFF8470`, which clears `cr.iva` and
   prepares the search registers (`r84 = 1` selects the primary FIT; the alternate is tried later).
2. The FIT address is read from `0xFFFFFFE0` (primary) or `0xFFFFFFC8` (alternate; a zero there ends the search). The
   first 8 bytes at that address must read `_FIT_   `. If the FIT entry's checksum-valid bit is set, the FIT is summed
   by the routine at `0xFFFF9120` (a byte sum over sixteen-byte units; zero is valid).
3. It then walks the 16-byte entries for type 0x0e. A match needs the processor-specific PAL_A image's dword at image
   offset `0x14` to carry the running CPUID family and model, and the highest revision byte of those that match wins.
   In the three images the dword reads revision minor, revision major, model, family: model 0, 1 and 2 with family
   `0x1f` (the Itanium 2 family; model numbers 0 to 2 are McKinley, Madison, Madison 9M by the CPUID model field,
   inferred). So `0xfffc2fc0` is the model 0 image, `0xfffc9ac0` model 1, `0xfffd0280` model 2.
4. For a chosen image, with the FIT entry's reserved bit 24 clear (it is clear in every entry), it calls through
   `br.ia` with the image address in `r2` and the image size in `r3`, `r5 = 1` and `b0 = 0xFFFF8730`; the code at
   `0xFFFF8730` is native, restores the predicates and tests `r1`: nonzero rejects the image and the loop continues,
   zero accepts it.
5. The hand-off is a branch to the image address plus `0x300` (`0xfffc32c0`, `0xfffc9dc0`, `0xfffd0580`), reached
   through `b2` (set at `0xFFFF890C`), with `msr` 1643 set to zero (success) or to a status 9 to 15 for the alternate-FIT and
   error cases. Failures with nothing usable go to `0xFFFF8A10`, which also uses `br.ia`, with `b0 = 0xFFFF8A60`
   and `r2`, `r3`, `r5` zero, and then to the error path.

### The br.ia sites: what they are not (established) and what they might be (inferred)

Generic PAL_A has three `br.ia` instructions: `0xFFFF83EC` (the reset site), `0xFFFF872C` and `0xFFFF8A5C`. Each
site set `b0` to the address of
a native bundle that begins with an `alloc` and expects to be entered afterwards: `0xFFFF8730` (which then checks `r1`
as a result) and `0xFFFF8A60` (which then branches to the error path); the reset site instead sets `b0` to
`0xFFFFFFE0`. Decoded as IA-32 in either the 32-bit or 16-bit default size, the bytes at `0xFFFF8730` and
`0xFFFF8A60` are not code (they are native bundles), so `br.ia` in PAL_A is not an ordinary switch to IA-32 code
whose target is `b0`. Reading the second site as a call whose argument registers are `r2`, `r3`, `r5` and whose result
is `r1`, returning at `b0`, fits all three sites; what the callee is (the sixteen leading bytes of each
processor-specific PAL_A look like an authentication value and the SDM names a PAL authentication call) is inferred,
not shown by the code. The `msr` writes before the reset site (212 to 0, 1225 to 4) and their effect are unknown.

**What the SDM defines for `br.ia` (established; rev 2.3 page numbers checked against the rev 2.3 PDFs after the review).**
`br.ia` is an unconditional indirect branch that sets PSR.is to 1 and begins IA-32 instruction execution at the virtual
linear address in the branch register named by the B4 field `b2` (`b2` is 0 here, so `br.ia b0`; checked in the bundle
bits), with EIP{31:0} = BR b2{31:0} minus CSD.base (volume 3, instruction `br`, rev 2.3 pp. 3:21 to 3:22; volume 2,
section 9.1.2, p. 2:596). It raises Illegal Operation if the qualifying predicate is not PR0 or the register stack
holds dirty registers, raises Disabled Instruction Set Transition if PSR.di is 1, clears PSR.da, id, ia, dd and ed
before the first IA-32 instruction, sets the current register stack frame size to zero, and leaves the high
registers and the ALAT undefined; software must have loaded CSD and CS and must set PSR properly, otherwise the
operation is undefined. None of this says what a processor does at reset, and the SDM has no `mov msr[...]`
instruction (its indirect register moves are cpuid, dbr, ibr, pkr, pmc, pmd and rr). Intel's Itanium 2 reference
manual 251110, section 2.8, says IA-32 support is "achieved using hardware circuitry on the Itanium 2 processors",
and the specification update 251141, erratum 70, says `br.ia` may miss the Illegal Operation fault when BSPSTORE and
BSP differ. Neither names MSR 212 or 1225, a reset entry address or the entry state.

The SDM's own description of PALE_RESET (volume 2, section 11.2.1, p. 2:289) says PAL "may optionally perform
authentication of the PAL firmware" and that "PAL may execute IA-32 instructions to fully test and initialize the
processor"; section 11.2.2 lists "an implementation-specific PAL procedure for PAL authentication" among the calls
available to SALE_ENTRY at the recovery check (established, as Intel's description of PAL in general, not of this
image). So IA-32 execution and an implementation-specific authentication step are both part of the architected
reset flow. That supports reading the `br.ia` sites that pass an image address and size in `r2` and `r3` as entry to
an implementation-specific authentication or self-test mechanism (inferred); the SDM does not say how it is entered,
and what the reset-site `br.ia` runs stays unknown.

Intel describes such a mechanism in patent US 6,542,981 B1, "Microcode upgrade and special function support by
executing RISC instruction to invoke resident microcode" (filed 1999-12-28). Software sets "one MSR to a special
value", one branch register to a function number and another to a return address, then executes `br.ia`. When the
MSR is set, the instruction "does not necessarily branch" and "rather invokes resident microcode instructions", which
authenticate the supplied code by a one-way hash and load it. An invalid function or a failed check sets an error
code, and execution continues at the return address in either case. The patent places this in firmware run after
power-on. It names no MSR, no register numbers and no PAL (established, as the patent's description). The two
non-reset sites match it closely: image address and size in `r2` and `r3`, `r5 = 1`, `b0` pointing to native code
that tests `r1` and rejects the image when it is nonzero. So those sites are read as this microcode service, used
to authenticate the processor-specific PAL_A (inferred). The `msr` writes before the reset site (212 to 0, 1225 to
4) fit "set one MSR to a special value", but which MSR is the gate and what the value selects are not disclosed
(unknown). The reset site's `b0` is `0xFFFFFFE0`, which holds pointers rather than code, so the return-address part
does not fit there and the reset-site effect stays unknown. Public source checks found no index for these MSRs: the
GNU binutils ia64 tables define the `msr[]` operand only, with an index-dependent dependency rule, and the ski
simulator stops on any `msr` access.

For the reset site specifically (established): the 32 bytes at `0xFFFFFFE0` are the FIT pointer `0x80000000ffa00000`
and the SALE_ENTRY pointer `0x80000000ffc4e000`, then the IA-32 far jump at `0xFFFFFFF0`. They do not form code in
either default size. A straight decode from `0xFFFFFFE0` gives an `add` through `eax` (or `bx+si`), a load of `al` from
an absolute address, more `add`s and a bad opcode, and in both sizes the instruction boundaries run past
`0xFFFFFFF0` rather than landing on it, so a straight run does not reach the far jump. No `jmpe` (opcode `0F B8` or
`0F 00 /6`) occurs in those 32 bytes, and the far jump itself goes to physical `0xFE05B`, below the firmware window
(established that nothing in this image is mapped there). Executed as IA-64, the bundle at `0xFFFFFFE0` is also data.
So nothing in the image gives an IA-32 return path to IA-64 code, and nothing in the image decides what the processor
does after the reset-site `br.ia`.

### Processor-specific PAL_A: header and entry table (established)

Each of the three type-0x0e images (`0xfffc2fc0`, `0xfffc9ac0`, `0xfffd0280`) begins with 16 bytes that are not code, a
dword whose bytes are not used by the search (offset `0x10`), the version, model and family dword at `0x14` (the search
key), eight bytes of zero, and native code from offset `0x20` (a `mov r28=psr` bundle that is the same code as the
generic error entry at `0xFFFF8120`). There is no entry table and no header field naming a reset entry: the only
entry offset is the `0x300` constant inside the generic PAL_A search (`0xFFFF88F0`), and the only other fixed offset a
caller uses is the `0x14` key. The images do not reference the `0xFFFFFF70` or `0xFFFFFFB0` vectors (none of the
constants above appear in the image). The `0x300` entry begins by writing `msr` 1632 and then masks feature bits
by CPUID revision before continuing; that part is not read further here.

### Conclusion: which vector is the hardware reset entry

- *Established*: `0xFFFFFF70` is the only entry whose code reaches processor-specific PAL_A and so the SAL; `0xFFFFFFB0`
  is a short bundle sequence that ends in `br.ia` with a data address as its target and no instruction after it; no
  other code branches or points to either one.
- *Established*: the vector bundles `0xFFFFFF90` and `0xFFFFFFA0` are the two entries that hand off to PAL_B.
  *Inferred*: they are what the SDM calls PALE_CHECK and PALE_INIT (the names are the SDM's, the pairing is from what
  the code does).
- *Inferred, strongly supported*: PALE_RESET is at `0xFFFFFFB0` for Madison, from Intel's patent, the Merced trace and
  this image's vector layout, with `0xFFFFFF90` and `0xFFFFFFA0` as the PAL_B hand-offs (sources above). The SDM's three
  hardware entrypoints (PALE_RESET, PALE_INIT, PALE_CHECK) then map to `0xFFFFFFB0`, `0xFFFFFFA0` and `0xFFFFFF90`, and
  `0xFFFFFF70` would be reached only through the `0xFFFFFFB0` stub, not directly by the processor.
- *Established architecture, unknown reset-time effect*: the SDM defines `br.ia` as the transition to the IA-32
  instruction set, entering at EIP = `b2`{31:0} minus CSD.base (here `b0`, so `0xffffffe0` less the code segment base).
  See [the architectural definition](#the-bria-sites-what-they-are-not-established-and-what-they-might-be-inferred)
  below. Elsewhere in this PAL_A the two other `br.ia` sites are used as a call (arguments `r2`, `r3`, `r5`, result
  `r1`, continue at `b0`; inferred from the code, not from a document). The `0xFFFFFFB0` stub passes `r5 = 1` with `b0 =
  0xffffffe0`, the address of the FIT pointer. What the processor does at reset with the two `msr` writes is unknown; continuation into the
  `0xFFFFFF70` cold-start path is the consistent inferred reading, since that is the only code that reaches
  processor-specific PAL_A.
- *Inferred*: the entry instruction set is IA-64. Entry register and PSR state is not stated in any public source read
  (the SDM defines only the state handed to SALE_ENTRY).
- A software model gets the same SAL-visible result by starting at `0xFFFFFF70`, which needs only `cpuid[3]`, `cr.ifs`
  and a readable FIT, and by not depending on the `msr` writes or `br.ia` semantics at `0xFFFFFFB0`.

**Leads.** An HP zx2000 emulator at <https://thebrokenpipe.com/ia64/zx2000/> reportedly boots real zx2000 firmware
(binary only; another project's work, so confirmation only, not a source).


## Review (reset entry and no-link route)

Independent review of chips commits `ce97073` (NUMAlink discovery with the skip bit clear and no link), `d70228b` and `cc9b993` (processor reset entry, PAL_A vectors) and `f910147` (reset entry grounded in Intel and hardware sources, which supersedes parts of the two before it), plus `bd69911` (IA-64 reference submodules), examined at chips `f910147`. The reviewer wrote none of it. Method: `ia64-linux-gnu-objdump` through the retools container on `shub1snprom.bin` (SAL 5.04, sha256 matches the page and `root/sn2/SHA256SUMS`), the top 64 KiB at `0xffff0000` for PAL_A and `0xffa40000` to `0xffa60000` for SAL_B; a script re-read the FIT, the PAL_A FIT entry and its checksum, and compared the image with Intel's `S870BN4C.BIN` (sha256 and size match the page); the 2001 linux-ia64 thread was read in the Library; the Intel patent was fetched from Google Patents; the submodule URLs and pins were checked with `git ls-remote`. SDM rev 2.3 and the Itanium 2 hardware developer's manual could not be opened (see "Not checked"); SDM text was re-read in revision 1.1 (245318-002 and the volume 3 instruction reference), which the reviewer had.

**Confirmed (re-read in the binary).**

- Top of the image: FIT pointer at `0xFFFFFFE0` is `0x80000000ffa00000`, SALE_ENTRY at `0xFFFFFFE8` is `0x80000000ffc4e000`, alternate FIT at `0xFFFFFFC8` is zero, IA-32 far jump at `0xFFFFFFF0` to `f000:e05b` with the date string after it. The PAL_A FIT entry at `0xFFFFFFD0` is address `0xffff8000`, size `0x7fc0`, version 7.31, type `0x0f`, checksum byte `0x6e`; the 32,704 bytes plus the checksum sum to zero. The FIT proper has 15 entries, header version `0x0260`, and sums to zero; PAL_B 7.79, 5.73 and 2.25 are at `0xffdc8000`, `0xffe78000`, `0xfff28000`; the three type `0x0e` PAL_A images are at `0xfffc2fc0`, `0xfffc9ac0`, `0xfffd0280` with family `0x1f` and models 0, 1, 2 in the dword at image offset `0x14`; SAL_A is `0xffc4e000` (16 KiB), SAL_B `0xffa01000`.
- Vector bundles: `0xFFFFFF50` and `0xFFFFFF60` are `br.few b0`; `0xFF70`, `0xFF80`, `0xFF90`, `0xFFA0` branch to `0xFFFF83F0`, `0xFFFFDA60`, `0xFFFF8A80`, `0xFFFF8DA0`; `0xFFB0` is the only MBB bundle and both its branches go to `0xFFFF83A0`. The stub at `0xFFFF83A0` is as listed: `r3 = 0x80000000ffffffe0`, `msr[212] = 0`, `msr[1225] = 4`, `b0 = r3`, `srlz.d`, `r5 = 1`, `br.ia.sptk b0`. The `br.ia` encodings at `0xFFFF83EC`, `0xFFFF872C` and `0xFFFF8A5C` all have B4 field `b2 = 0`, so `br.ia b0`.
- The `0xFFFF83F0` path (`cpuid[3]`, `cr.ipsr = 0x100800000000`, `cr.iip = 0xffff8470`, `rfi`, `cr.iva = 0`, the `_FIT_   ` search with primary at `0xFFFFFFE0` and alternate at `0xFFFFFFC8`, type `0x0e` match on family and model and highest revision, the `0x300` entry offset, `b2` set at `0xFFFF890C`, `msr` 1643 cleared on success), the PAL_B hand-offs (type 1 entry, dword at `0x10114`, `msr` 1715 revision byte, `msr` 1640 bit 56 test with `r30 = 2`, FIT type above 1 giving `r30 = 12`, offsets `0x10080` for `0xFF90` and `0x10070` for `0xFFA0`), and the second `br.ia` site's `b0 = 0xFFFF8730` with a test of `r1` afterwards.
- Byte comparison with the Intel image: the 112-byte vector region (`0xFFFFFF50` to `0xFFFFFFBF`) occurs exactly once, at file offset `0x4dfd7e`, which maps to `0xFFFFFF50` with the image ending at 4 GiB; 510 of the 511 aligned 64-byte windows of the generic PAL_A (excluding the top 64 bytes) occur in the Intel image and the miss is window 0 (`0xffff8000`). The top 64 bytes differ only in the alternate FIT address (Intel's is non-zero), the PAL_A FIT entry's version and checksum, the FIT pointer, the SALE_ENTRY pointer (Intel's has no bit 63), four date-string bytes ("11/02/99" against "01/01/01") and the last byte.
- Quoted sources: the patent (title with "and method of use"; `0xFFFFFFF0` "by way of example", `0xFFFFFFB0` "for example", "a basic initialization and check under PAL-A", "may be hardwired into the CPUs", "a PAL-A entry point") is as quoted; the FIG. 6 flow is where the `0xFFFFFFB0` sentence sits. The linux-ia64 message is Chris McDermott's own correction (`lcm@us.ibm.com`, 2001-12-10) of his earlier line that put the reset vector at `0xFFFFFF90`, with the ITP observation in the first post. SDM revision 1.1 has the PALE_RESET sentence quoted from section 11.2.1 and lists RESET as an abort taking the PALE_RESET vector, and says PAL_A "resides below 0xFFFF_FFC0" with the hardware-triggered entrypoints.
- ce97073: the NI accesses are `0x1_5000_0048 + p * 0x2000` (test bit 27, write back with it cleared only if set, read again), `0x1_5000_0000 + p * 0x2000` (low nibble must be 9, else -1), `0x1_5000_1040 + p * 0x2000 + 16 * i` for i = 0 to 3 (at most 128 reads each, skipped when a CPU ID test selects the simulator), `0x1_5000_0010 + p * 0x2000` in the port fill; `0xffa450e0` runs before the `0xffa975e0(11)` test; the constants `0x11e1a300`, `0x989680`, `0x1_5003_1550`, `0x1_5003_1540`, bits 55:54 and the bit 41 and bit 39 masks are as listed.
- bd69911: the four URLs resolve, `linux-sn2` tag `v7.3-rc3-epic1-sn2-gpu` is `69571599c577`, `linux-ia64` `master-epic` is `076c06dc04ba`, `ski` master is `dfc2902ea142`, `elilo` master is `4e5817767696`. `setup-clone.sh --submodules "NAME"` and `all` exist in the retools script as the index says.

**Mechanical fixes made in this review (this page).**

1. The `0x1_5000_1040` loop had its polarity backwards. The code re-reads while bits 22:16 are zero (`cmp.eq` of the field against zero sends a non-zero field out of the loop to the success path) and fails the port only if all 128 reads are zero. The table said "until zero ... still non-zero".
2. The `br.call` to `0xFFFFDA60` is at `0xFFFF881C` (slot 2 of the bundle at `0xFFFF8810`), not `0xFFFF8818`.
3. The `0xFF90` hand-off saves four values into four registers, not three: `r30` into `msr` 0, `r31` into 1641, `pr` into 1642, `r29` into 1643. The page named `r29`, `r30`, `r31`, `pr` but only the registers 1641 to 1643.
4. The patent title is "Interleaved boot block to support multiple processor architectures and method of use".
5. The `br.ia` reading. `f910147` withdrew the IA-32 reading of the `0xFFFFFFB0` stub and described `br.ia` as "a processor-internal service call" with no architectural citation. The architecture defines `br.ia` as the transition to IA-32 (PSR.is set to 1, EIP{31:0} = `b2`{31:0} minus CSD.base, faults, PSR bits cleared, frame size zero; volume 3 instruction `br`, rev 2.3 pp. 3:21 to 3:22, and volume 2 section 9.1.2, p. 2:596, as supplied by a separate reader and not opened by this reviewer; the same text is in rev 1.1 at volume 3 `br` and volume 2 section 20.1.2). The page now states that definition, keeps the "service call" reading only as an inference for the two other sites, and keeps the reset-time effect unknown. The sentence "the reading as an IA-32 hand-off is superseded" now says the target holds no IA-32 code.

**Findings not fixed.**

1. `br.ia` target. The decode of the bytes at `0xFFFFFFE0` as IA-32 is a straight decode only; it shows no ordinary IA-32 code there, not that IA-32 is not entered. With CSD.base unknown at reset, EIP is `0xffffffe0` minus the base, and PSR.is, PSR.di, CSD and CS at reset are processor business. Intel's Itanium 2 reference manual 251110 section 2.8 (TOC p. 23) says IA-32 is "achieved using hardware circuitry"; spec update 251141 erratum 70 (p. 44) says `br.ia` may miss the Illegal Operation fault when BSPSTORE differs from BSP. Neither names MSR 212 or 1225, a reset entry address or entry state (cited by document number, revision and page from a separate reader; not re-read here). The SDM has no `mov msr[...]`, so those two writes are implementation-specific, as graded.
2. The `0xFFFF83F0` path also writes `msr` 0 (`mov msr[r0] = r0`), as do the PAL_B hand-offs when the NaT test passes. The page says the path "reads no general or branch register" and does not mention this write.
3. The "Merced" label on the Lion trace is an inference. The post says "Intel Lion SDVs" with B3 and C0 steppings and gives no processor name. The ITP also showed the processors at `0xFFFFFF90`, which the correction calls PALE_CHECK, so the trace is of a machine check or reset path in a hung system, not of a power-on entry. The page's "observed" grade is for the label, not for a first instruction at power-on.
4. The patent text containing "a PAL-A entry point" is in the paragraph of the interleaved-block discussion that this review could not tie to FIG. 3 or FIG. 4; the page says FIG. 4.
5. `elilo` is pinned at the master head; the index calls it 3.16 but the repository has no tags, so the version label cannot be checked from the pin.
6. Grades hold: PALE_RESET at `0xFFFFFFB0` for Madison stays inferred (patent example plus a Merced-era label plus shared Intel code), the `br.ia` effect unknown, and there is no Linux KVM reference left on the page.

**Not checked.** SDM rev 2.3 itself (Intel's download refused the request and the Library holds no copy in the roots this review could search), so the rev 2.3 page numbers on this page (2:109, 2:282 to 2:291, 2:596, 3:21 to 3:22) and its sha256 are unverified; the quoted sentences were found in rev 1.1 at different pagination, and the "Table 5-6" number is Table 5-5 there. The Itanium 2 hardware developer's manual 251109 (sections 3.2.1 and A.1.51 and their quotations) was not obtainable, so those two quotes are unverified. SAL specification 245359 was not opened. In ce97073 the bit layout of the `0x1_101d_0080` word beyond the bits listed above, the `0xffa5d6a0` mask loop and the master selection were not re-read.

**Cleared scope.** The image facts at the top of memory (pointers, FIT, PAL_A entry and checksum, vector bundles, stub, native search, PAL_B hand-off offsets), the byte comparison with the Intel image, the patent and linux-ia64 quotations, the NI register accesses, polarity as corrected, and constants of the no-link route, and the four submodule pins. Not cleared: the rev 2.3 and hardware manual citations, the meaning of MSR 212 and 1225, and any claim about what the processor does after the reset `br.ia`.

**Post-review check of the manual citations.** Against the rev 2.3 PDFs (volume 2, 245318; volume 3, 323207): Table 5-6, "Interruption Priorities", is on p. 2:109; the `br.ia` text in section 9.1.2 is on p. 2:596 and the `br` instruction's `ia` text on p. 3:21; PALE_RESET (section 11.2.1) and its exit state (section 11.2.2) are on pp. 2:289 to 2:290. Against the Itanium 2 hardware developer's manual 251109-001: "defined during configuration" is in section 3.2.1 (PDF p. 28) and "begins program execution at the reset-vector" in A.1.51 (PDF p. 64). All quoted as the page says. The SAL specification 245359 was not reopened.
