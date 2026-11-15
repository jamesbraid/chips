# Altix 350 and Prism: reset to the EFI console in SAL 5.04

What the SHub 1 firmware image SGI's `README.snprom` names for the Altix 350 and both Prism models does from processor
reset to the EFI console, and the minimum answer each hardware access needs for an emulated node to proceed. Image:
`shub1snprom.bin`, SAL 5.04 (banner "SGI SAL Version 5.04 rel081111 IP41 built ... Nov 11, 2008"), package snprom-10.54-70399,
sha256 `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`, read with the retools
`ia64-linux-gnu-objdump`. Layout, FIT and the component tables are in the [firmware page](README.md); SAL 4.43 and the
SHub 2 builds are compared where noted.

**Grades.** *established*: the whole function or table was read. *inferred*: built from a call list, a constant, a name
carried by the sibling SAL runtime (the runtime component is symbolised, SAL_B is not; names below that come from the
runtime are marked "runtime name"), a function not read in full, or a result of the interpreter run under [Memory discovery](#memory-discovery-what-is-read-and-what-an-interpreter-run-of-the-image-shows) (a trace of the shipped binary under stub inputs, not hardware behaviour). *unknown*: not settled. The
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

1. Set `psr.db` (bit 24). Reason 3 only: call a stub that returns 1 (the SHub 2 build reads `0x2_1003_8200` bit 39 here;
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
7. FIT scan as on SHub 2 (same checks, hang 178). Progress 48, 56 or 59 for reason 0, 1, 2; read
   `[0x81_1003_0000 + (slice & 3) * 128]` into `r31`; branch to SAL_B offset 0, 0x20 or 0x10.

**Progress display (established).** Every progress code is shifted into a per-processor 64-bit history register at
`0x81_5003_1500 + 16 * cr.lid[26:23]` (shift left 8, new code in the low byte) and written as 16 bits to two LED
registers at `0x87_fed0_0000 + n * 0x10000` (n from the processor number; the odd-numbered register gets the code ORed
with `0x60`). The SHub page lists `0x7_fed0_0000` as the junk-bus LED registers. A model can take both as plain
storage.

**4.43 comparison (inferred, constants only).** The 4.43 SAL_A touches the same `0x81_...` registers and in addition
has code that switches PSR for virtual mode; it has no read of `0x81_1003_0000` and no `0x81_2000_0000` write. 5.04 added
the error path stores and the `r31` read. A model built for 5.04 covers 4.43's list.

**Minimum answers for SAL_A.** Nothing needs a particular value except two. First, the election: SAL_A writes `0x81_101d_0088` and reads `0x81_101d_0080`, which are different addresses, so a plain read/write register at 0x80 does not satisfy it. The single processor must read back at 0x80 the value it wrote at 0x88; whether 0x88 aliases 0x80 or is a first-writer latch is **unknown** (the reset value is unread; the error path ORs bits into 0x80, so 0x80 is also writable). Second, `0x81_101d_0100` must hold what was written (bits 41:39 = 7), since the UART bring-up checks them (below). All the
others accept writes; reads of `0x81_5003_15x0`, `0x81_1003_0000` may return 0.

## PAL boundary

For the CPU model: what the firmware itself provides and expects of PAL. Architecture-level facts about PAL entry and
exit come from the public IA-64 PAL specification, not this image; marked *architectural*.

- **PAL_A and PAL_B come from the firmware image.** The FIT carries three PAL_B and three processor-specific PAL_A
  entries in this image (PAL_B 7.79, 5.73, 2.25; PAL_A 7.31, 5.37, 1.27; established). Which pair is used is chosen by
  SAL_A, not the SAL runtime. A CPU model that substitutes its own PAL removes reason 3 and the PAL calls below, and
  the firmware's PAL version checks ("Minimum PAL A", version strings).
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
  17251 (0x4363); the SHub 1.1, 1.2 and "1.x" names and `shub_name` come from the revision field. An emulated SHub 1 must
  put a valid node id, part number 0x4363 and a revision (the revision the PROM expects is not decoded here) in `0x81_1006_0580`. The field positions for part number and revision are not decoded here
  (inferred from the SHub page's header-derived layout).
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
  (progress 0x32 and 0x34), so real DRAM is not initialised yet; an emulator provides ordinary RAM there from the first
  instruction.
- **DIMM data and a memory-test pass are required (established for the checks, inferred for the run).** If the L1 reports no DIMM the PROM stops with 0x80 ("No memory on node"). The DIMM request, the SPD bytes used, the memory controller values and the test-completion bits are decoded under [Memory discovery](#memory-discovery-what-is-read-and-what-an-interpreter-run-of-the-image-shows). This is the most likely first place an emulated memory controller stalls.
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
- **Minimum answer (inferred).** A widget whose ID register reads part number `0xd102`, a PIC bus with the IOC4 in one of
  the first three slots, and a console UART on the IOC4 if the IOC4 console is chosen. The PROM can finish without any I/O
  device only if discovery tolerates an empty XIO port; not read.

## Console path

- **Candidates (runtime names, established):** the system controller console (`sc_cons_*`, chosen by `sc_cons_probe`, i.e.
  `sysctl_probe`, so selected whenever the signature is absent), the direct console on the SHub junk-bus UART
  (`direct_*`) and the EFI callback console. `direct_probe` writes `0x55` then `0xaa` to the UART scratch register
  (`0xf_fed4_0038`, on the master node only) and reads back the low byte; available when both read back. The PROM log
  shows progress 9, 0xa and 0x28 for the three.
- **Default (inferred):** the system controller console; the kernel's `ttySG` console uses the same path through the SAL
  console calls (`0x02000021` to `0x0200002c`). An emulated node that implements the junk-bus UART with a scratch register
  and a host serial backend gets the direct console as well; the L1 peer still has to exist (above).

## Hand-off to EFI

- **Established path.** `main_three` (`0xffad7280`) writes progress 0x27 and calls `0xffaf8c50` (prints "Loading EFI
  ..."), which finds the FIT EFI component (type 0x1f), expands it to RAM, writes progress 0x48 "Jumping to EFI", and
  enters it; EFI start-up writes 0x49 to 0x4f. The SAL system table and the SAL entry points are built before the
  jump, and the SAL runtime component (type 0x12) is also copied.
- **What EFI needs:** the SAL runtime calls the PROM answers (table on the firmware page), the console above, and for
  non-volatile variables a CFI flash at the top of the address space; `Syncing EFI var. store` and the checksum code
  are in `0xffaf6640` and `0xffaf6d10`. A model that makes the flash read-only fails variable writes, not the console.

## What blocks reaching the EFI console, in order

1. The L1 peer: without a UART peer that answers the first requests the PROM dies at 0x8d before memory.
2. Memory controller and DIMM reports (L1) so that 0x16 and 0x17 pass.
3. The single-node interconnect case: answer L1 command id 1 with `0x800` ([above](#single-node-interconnect-the-skip)); the trace then stops in the route-table walk, which needs the system-data-area step the run skipped.
4. PIC and a console device in discovery: `0xffab38b0` and `0xffab15c0` read in full; the PIC register reads and the PCI walk are not.
5. The CPU ID signature path avoids 1 and 2 and the board EEPROM read; stated as fact, not recommended.

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

An emulated CPU that supplies its own PAL needs to answer, before the first progress code above 0x15: 520 (any success), 12, 42 (logical-to-physical, one processor), 1 to 3 and 37 (jump to RAM). The rest are reached by error, MCA, idle and late-test paths.

## Memory discovery: what is read, and what an interpreter run of the image shows

**Method and its limit.** The disassembly of SAL_B was executed by a small interpreter written for this reading (integer subset, one processor, no devices) with the SHub ID registers, the real-time clock and a stubbed system controller set to the values below. It is a trace of the shipped binary under stated inputs, not hardware behaviour; it shows what the code does with those inputs. Graded **inferred** unless the code was also read.

**Inputs the run needed (each one a minimum answer):**
- SHub identification at node offset `0x1_0000_0000`, read by `chipset_init_chip` (`0xffa0f8c0`) through a bounded read helper: revision in bits 31:28, 16-bit part number from bit 12. The part number must be `0x4363` (17251; the check at `0xffa959a6`). A JTAG-style layout with bit 0 set and a manufacturer in bits 11:1 was used; the manufacturer field is not checked in the paths run (unknown). `0x81_1006_0580` must carry the node id in bits 42:32 (zero used). **Established** (read).
- The real-time clock at `0x1_101c_0000` must advance (delay loops compare it).
- The system controller answers. The PROM made eight requests through `sysctl_cmd_command_timeout` (`0xffa82a10`) before memory; a success status with an all-zero body was enough for all of them except `sysctl_cpu_presence` (`0xffae8660`), whose result is a per-processor presence mask. With a zero mask `main_early_disable` (`0xffad34a0`) treats processor 0 as disabled and stops at progress 0x87 ("Disabled by environment variable"); bit 0 must be set. The disable bitmask is also read from the environment variable `DisabledCpus` (flash variable store).
- Result on this input: 0x13 to 0x15 pass, 0x16 starts.

**Phase 0x16: DIMM discovery (`mdir_fill_node_dimmcfg`, `0xffa77bb0`; name from the string it prints).** Read in full (established); the request and the parse were also checked against the run. For each of four banks and four slots (sixteen DIMMs) it calls `0xffa7bd60`, which calls `sysctl_eeprom_dimm` (`0xffa85470`): open a transaction (target `0x0ffff000`), call the shared EEPROM read `0xffa84680`, close. The read is one request with command id 6 and four integer arguments (each argument occupies two words in the PROM's argument list, which is the eight in the argument array): the device id, the selector 4, the offset 0 and the count 48 (the earlier text of this page had the 4 and the 48 reversed: 48 is the byte count, each request carries at most 64, and 4 is a fixed selector passed to the shared read; that the selector picks the DIMM area is inferred, since the board-record readers pass 1 and 2 to the same routine). The device id is `8 + 8 * (slot & 1) + 2 * bank + (slot >> 1)`, so bank 0 slots 0 to 3 are ids 8, 16, 9, 17 and the sixteen ids run from 8 to 23 (observed in the trace in exactly that order). The reply is status 0, two arguments: an integer (the number of bytes returned) and a raw byte string of that length, which the PROM copies to a 256-byte slot buffer. A success status marks the slot present (bit `slot` of the bank's presence word); any error status marks it absent. A bank must have either all four slots present or none: a presence word other than 0 or 15 prints "DIMM groups must be plugged in sets of 4 DIMMs", names the missing slots, and disables the bank (`0xffa76290`). So the smallest memory an emulated node can report is four identical DIMMs in bank 0.

**SPD bytes the PROM uses (established, read in `0xffa7b1b0`, `0xffa7b310`, `0xffa7b410`, `0xffa7b6c0`, `0xffa7b7e0` and `0xffa7afd0`; byte numbers are those of the JEDEC DDR SDRAM serial-presence-detect layout, which the reads match; the layout itself is not held here).** The PROM asks for 48 bytes from offset 0 and reads only eight positions of them; the rest may be anything. Per DIMM unless said otherwise:

| Byte | Used for |
|---|---|
| 5 | number of ranks ("sides"): 1 gives code 0, 2 gives code 1, anything else is invalid; the four DIMMs of a bank must agree or the PROM warns "DIMMS within bank slot have different number of banks" |
| 31 | density of one rank: 0x10 gives index 0, 0x20 gives 1, 0x40 gives 2, 0x80 gives 3, 0x01 gives 4, 0x02 gives 5, any other value 7 (treated as empty); the smallest of the four DIMMs is taken. By the layout the indexes are 64, 128, 256, 512 MB, 1 GB and 2 GB per rank |
| 9, 18, 23, 25 | CAS latency: byte 18 is the supported-latency bit mask (0x10 for CL 3.0, 0x08 for CL 2.5, 0x04 for CL 2.0) and bytes 9, 23 and 25 the module's minimum clock period at CL 3.0, 2.5 and 2.0; a latency is usable when the bus clock's period (in the byte's own encoding: 0x50 for 5.0 ns at 200 MHz, 0x75 for 7.5 ns at 133 MHz, 0xa0 for 100 MHz, 0x63 for 160 MHz) is not below that minimum, and the PROM takes the lowest usable latency. The result is code 1 for CL 2.0, 2 for CL 2.5, 3 for CL 3.0, the largest over all DIMMs; CL 3.0 is forced ("Forcing max cas latency of CAS3_0") when nothing fits |
| 29 | tRCD in the SPD coding (bits 7:2 whole nanoseconds, bits 1:0 quarter nanoseconds); converted to bus clocks by rounding up and clamped to 2 to 4 with a warning outside that range; the value actually used is always 3 ("INFO: tRCD setting 2 is not supported. Setting tRCD to 3."), and all banks must agree or the PROM stops with "FATAL MEMORY CONFIGURATION ERROR" (`0xffad2c50`, 216) |
| 42 | the layout's auto-refresh-to-activate time (tRFC) in whole nanoseconds, the largest over the four DIMMs of each present bank; the PROM uses `floor(byte / 5)` capped at 14 (the fixed 5 is the 5 ns period of 200 MHz; it does not follow the bus clock) |

Bank size in MB is `64 << (density index + rank code + 2)` (four identical DIMMs of one rank each of 1 GB: index 4, code 0, 4096 MB; two ranks of 512 MB: index 3, code 1, 4096 MB). The PROM prints it as "DIMM0 1024M (DIMMx4 = 4096M) : sides:2". The bus clock comes from bits 1:0 of the register at node offset `0x1_1006_0500` (read at `0xffa77e0c`): 0 gives 200 MHz, 1 gives 160, 2 gives 133, 3 gives 100 (a four-entry table of 16-bit values in flash, read). With the register at 0 the clock is 200 MHz. The timing index that selects the register values below is `0xffa76630`: 100 MHz with CAS code 1 gives 0; 133 MHz with codes 1 and 2 gives 1 and 2; 160 MHz with codes 1 to 3 gives 3 to 5; 200 MHz with codes 1 to 3 gives 6 to 8. Any other combination prints "memory bus speed (%d) and CAS latency (%d) not supported" and the register values are not usable, so a model that wants a quiet boot must report DIMMs whose SPD gives one of those pairs.

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

`mdir_create_presence_vec` (`0xffa79310`) and `mdir_create_privilege_vecs` (`0xffa79960`) then write `0x1_0003_0100` and `0x1_0005_0100` (value 1), `0x110` to `0x130` (0), and the privilege vectors `0x1_0003_0300` to `0x1_0003_0370` and the same in the `0x1_0005_` block: `0x4bfff`, `0xc96f25b`, `0xfffffff`, `0x96ffff`, 0, 0, `0x4803f`, `0x48000` (values from the run for node 0, one processor pair, not decoded; the SHub page names `0x300` of each block as the kernel's privilege vector). Everything is a plain store; the model only has to return what was stored, with zero before the first store, except `0x1_1006_0580`. The routine at `0xffa775c0` then writes `0x1_0001_0030` and `0x1_0001_0050` (refresh interval 195 in bits 16:8 unless the environment variable `MemoryRefresh` overrides it; the tRFC clock count in bits 22:17; per-bank enable bits) and issues the DRAM initialisation command sequence through the test port described next; the values of `0x30` and `0x50` were not decoded.

**Phase 0x16/0x17: controller set-up (`0xffa76bf0`, "Initializing memory controller"; established as the register list, values depend on the DIMM data).** It takes the nasid and a per-bank configuration record and, in order: reads `0x9_0001_0008`, `0x9_0001_0048`, `0x9_0001_0040` (global window, node `n` in bits 38 and up; node offsets `0x1_0001_0008`, `0x1_0001_0048`, `0x1_0001_0040`) and merges fields from the record into them; writes `0x1_0001_0000`, `0x1_0001_0008`, `0x1_0001_0010`, `0x1_0001_0028`, `0x1_0001_0048`, `0x1_0001_0020`, `0x1_0001_0040`; calls `0xffa0ecd0` (tests a bit of `0x81_5003_1550`, a per-processor bit word whose meaning is inferred) and then, per processor, stores to `0x1_0003_0200`, `0x1_0005_0200` (value `0x4000000000` or 0) and the pair `0x1_0183_0200`, `0x1_0185_0200`, per processor (loop of up to eight); later stores to `0x1_0003_0400` and `0x1_0005_0400`; the SHub page lists `0x1_0003_0300` and `0x1_0005_0300` as the kernel's privilege vectors, so these neighbours are not named there; calls `mdir_create_presence_vec` (`0xffa79310`) and `mdir_create_privilege_vecs` (`0xffa79960`); then reads the node id register (`0x1_1006_0580`) and writes `0x1_0001_0060`, `0x1_0001_0058` (value `0x4004e20`) and `0x1_0001_0078`. These are the MD block registers (bits 31:28 of the offset are 0). Values written are mostly merged fields of the DIMM record and were not decoded; the order above is the order of the stores in the function.

**Phase 0x17: test and initialise (established for the completion logic, read in `0xffa6fb30`, `0xffa6fc60`, `0xffa700d0`, `0xffa70310`, `0xffa72500` and `0xffa6c3a0`).** The memory test and the DRAM initialisation commands share one engine, controlled through the register at node offset `0x1_0002_0088` ("test control") with `0x1_0002_0080`, `0x1_0000_0080` and `0x1_0000_00c0` around it. To start a step the PROM writes `0x1_0002_0080` (the address or command word), zero to `0x1_0000_0080`, all ones to `0x1_0000_00c0`, and then `0x1_0002_0088` with bit 40 set (go), a 7-bit operation code in bits 38:32 and a 31-bit value in bits 30:0. The engine is idle again when bit 40 reads back as zero; bit 41 set means the step failed. The wait loop (`0xffa6fc60`) polls `0x1_0002_0088` until `(value & 0x300_0000_0000) != 0x100_0000_0000`, with a deadline of `0x1312d00` (20,000,000) ticks of the real-time clock at `0x1_101c_0000`; on a timeout it returns -3 and the caller reports "MBIST TIMEOUT Byte Address = %#016lx" from bits 32:0 of `0x1_0000_0080` multiplied by 8, then the suspect DIMM names. After the loop it re-reads the register: if bit 40 is still set it clears it by writing the value back and waits again. The caller then tests bit 41 of the register: set means "MBIST failed" and the error report (`0xffa72500`) reads bit 36 of `0x1_0000_0080` (a compare error) and otherwise prints "MBIST failed other than bist compare error" with `0x1_0000_00b8`. The memory-test operation codes are 48 and 16; the DRAM initialisation commands go through the same register with operation codes 7, 2, 0, 0, 2, 1, 1, 0 in that order for the first bank (the command word in `0x1_0002_0080` for each: `0x200000`, `0x200000`, `0x100`, `0x9c800`, `0x200000`, `0x200000`, `0x200000`, `0x1c800`), which fits a precharge, extended-mode, mode-register, refresh and mode-register sequence (the DRAM meaning is inferred; the run only recorded the order). The model therefore needs: a 64-bit register at `0x1_0002_0088` that stores what is written, clears bit 40 at once (or within the 20,000,000-tick deadline) and leaves bit 41 clear, and plain storage at `0x1_0002_0080`, `0x1_0000_0080` and `0x1_0000_00c0`. With those two behaviours the trace passed "Testing memory" and "Initializing memory" with no fault printed.

A second wait guards the memory test: `memctl_mbist_credit_war` (`0xffa7a960`) uses a block transfer engine. It loads the bank map and the bank-size register, and for a bank that needs it writes the engine registers of node `n` at the global window address `0x8_01c1_0000 + n * 2^38`: the length-and-status register (IBLS0) at that address with bit 20 set and the length in the low bits, then the source (+0x8), destination (+0x10), notification (+0x20) and control (+0x18, value 17: notify and zero fill), and polls bit 20 of IBLS0 until it clears, with a deadline of 2,000,000 ticks. That address is the header offset `0x41_0000` of IIO_IBLS0, taken from the I/O interface block's start at `0x40_0000` and placed `0x1c0_0000` into the node's window, as the [I/O interface page](../../../devices/shub_ii/README.md#where-the-registers-sit) works out (arithmetic, inferred), and the length-and-status layout (busy bit 20) is that page's. A timeout prints "memctl_mbist_credit_war(): BTE TIMEOUT ERROR. IBLS0:0x%lx" with the register's value (the run printed `0x100008`, the stored value, where this page earlier called the register address unidentified). The model needs IBLS0 to clear bit 20 when it is written with it set; whether the engine really zero-fills the bank is not checked by the PROM.

**Minimum answer for memory (inferred; the checks are established, the run is a trace).** (a) The L1 answers command id 6 with the frame above for the four ids 8, 16, 9 and 17, with a 48-byte SPD whose bytes 5, 9, 18, 23, 25, 29, 31 and 42 are consistent (the table above; an example set is given in the register table), and with any error status for the other twelve ids. (b) The `0x1_0001_00xx`, `0x1_0003_xxxx` and `0x1_0005_xxxx` registers store what is written and read zero before. (c) `0x1_1006_0500` bits 1:0 give the bus clock (0 for 200 MHz) and `0x1_1006_0580` carries the node id and revision as before. (d) `0x1_0002_0088` clears bit 40 after a write with it set and never sets bit 41. (e) IBLS0 at `0x8_01c1_0000` clears bit 20 after a write with it set. (f) The real-time clock advances. With those the trace went from progress 0x16 through 0x17 and 0x18 to 0x19 ("Switching to RAM"). Not covered: klconfig memory records, which are built after this (the run reached them only through the allocation stub described below).

## Single-node interconnect: the skip

`main_two` reaches progress 0x1c ("Discovering node interconnect") and calls `0xffa47870` (named `intcon_*` by the runtime signature). On the master node it prints "Discovering NUMAlink connectivity ........." and enters `0xffa47290`, which builds a configuration record (tag `0x50434647`, "PCFG") and calls a chip routine through a function pointer, then calls `0xffa450e0` and `0xffa975e0`. `0xffa975e0(11)` returns bit 11 of `0x81_5003_1560`; if it is set the PROM prints "*** Skipping NUMAlink discovery" and returns without reading any NI register.

**Source of bit 11 (established, read).** The word at `0x81_5003_1560` holds the **debug switches** in its low 16 bits. `main` writes it in phase 0xe ("reading debug switches"): it calls `sysctl_get`, then `0xffa7d040`, which sends L1 command id 1 with no arguments and parses a reply of status 0 and one integer argument (a request header of `0x0ffff006`, id 1, count 0; reply status 0, count 1, tag 0, four bytes big-endian); the returned value, if not negative, is stored by `0xffa974d0` as a 16-bit field at bit 0 of the word (and echoed as "Debug switches set to 0x%x"). If the read fails the PROM prints "*** System Controller DIP switches unavailable" and asks on the console (`0xffad2f10`), offering a default of "0000" or "0405" depending on the CPU ID signature. SAL_A's zeroing of the word therefore matters only until phase 0xe. So bit 11 of the flags word is bit 11 (value `0x800`) of the DIP-switch word the L1 returns for command id 1. The word is also tested at other bits (bit 8 at `0xffa19e9c` and `0xffa1a2ac`, others in the interconnect, test and EFI code; their meanings were not read). The `0xffa975e0` reader and the `0xffa974d0` writer (which takes the lock at `0x81_101d_0200`) are the only users of the address in SAL_B.

**Minimum answer (inferred from the run).** Reply to command id 1 with `0x800` (any other bits clear). With that the trace printed "*** Skipping NUMAlink discovery", then "Waiting for peers to complete discovery", then a one-entry "Discovery results" ("Entry 0: SHub ... Chiprev=3 Route=0x0", "Module=<0> Slab=0 Partition=0 Space=RESET", "Nasid=-1 Flags=0x100000", "Port 1 connection: Not connected", "Port 2 connection: Not connected"), "Global master is %I", "Partition master is %I", "Tree barrier", "nasid_nlocal_bits = 1", "ftdepth = 0" and "Calculating routes". With the bit clear (DIP word 0) the PROM takes the route that reads NI registers, which the run did not follow. In the same run two "shub_port_status: vector 0x0/0 NI0 from %I failed" and "NI1 ... failed" lines appeared much earlier, in `main` before the memory test (`0xffa1a2ac` region), whatever the DIP word was; they are messages, not stops. Where the run then stopped is under [What stopped the interpreter run](#what-stopped-the-interpreter-run).

## I/O discovery

The interpreter run did not reach `main_three`, so nothing below was run. It is the structure of the code, read from the call graph and the functions named, **inferred** unless it says read in full; the register-level answers for the PIC, the riser EEPROM and the PCI walk are still **unknown**.

- **Where it sits in `main_three` (established, call sites read).** After the progress writes for 0x21 to 0x23 and a long run of per-subsystem initialisers, `main_three` calls `0xffaad6d0` at `0xffad756c`; that is the only caller of `0xffab38b0`, the routine that prints "Discovering local I/O on nasid %d" (and "DONE"). Console selection comes later: `console_probe` at `0xffad76ec`, then `intcon_arbitrate_bmaster`, `sysctl_get`, and `0xffaf8c50` ("Loading EFI") at `0xffad777c`, with the fall-through paths printing "Global POD request" or "Local POD request" before "Running".
- **The per-node routine `0xffab38b0` (read in full).** On a non-master node it returns 1 at once. On the master node it makes an indirect call through the node's operations table (`[struct+32] + 256` in `0xffa99870`, argument 2) and proceeds only if that returns non-zero; it then calls `0xffab15c0`.
- **The widget identification read (`0xffab15c0`, read in full).** It finds the node's klconfig hub record (`0xffaa8a40`), takes a 16-bit nasid field at offset 48, and forms the widget-0 base address `(nasid << 38) + 0x8000_0008_0000_0000` (or `+ 0x8000_0000_0000_0000` when bit 0 of that field is set). It then calls `0xffab0560`, which sets the link credits (through `0xffab0130`, the routine keyed on the widget part number, below), and reads four bytes at that address through the bounded-read helper `0xffaeb170` (which returns 0 when the access faults or times out). The part number is bits 27:12 of the word and the revision bits 31:28. If the part is `0xd000` or `0xd100` (the crossbar types) it calls `0xffab0f10`, the crossbar walk; any other part prints "New Widget %x connected to HUB." and returns 0 without adding a klconfig entry. A read that returns 0 from the helper also returns 0, so an empty or dead XIO port ends discovery cleanly, with no I/O.
- **The crossbar walk (`0xffab0f10`, outline).** It creates the I/O brick record (`0xffab19f0`, "IOBRICK"), gets the link alive state for links 8 to 15 (`0xffab0900`, "Widget present, but link not alive!"), reads each link's widget identification (`0xffab14f0`, the same four-byte bounded read at `(nasid << 38) + link * 2^24` or `link * 2^28` depending on the address form), and branches on the part number: `0xc120` (49440) takes a generic path through `0xffab1b60`, `0xd102` (53506, the PIC) calls `0xffab0c00` twice, once at the widget's base and once 0x80_0000 above it (two register blocks, one per PCI bus: inferred from the offset), and then `0xffabfb10` (the PIC initialiser, not read); any other part prints "New Widget %x connected to HUB." and is skipped. Link credits come from `0xffab0130`, which picks a credit mask and shift from a table keyed on the widget part number and prints "can't find credit entry for wid_type" or "Using default link credit counts for UNKNOWN widget type" when the part is not in the table (the table was not decoded; `0xd102` has an entry, per the compare at `0xffab0260`).
- **Where the riser EEPROM is read (not traced).** `sysctl_eeprom_io_riser` (`0xffa85200` is the neighbouring `sysctl_p0_opus_tio_riser`) and the brick record readers use the same EEPROM read as the board record (command id 6, device id and selector as arguments); which ids and selectors the I/O path passes was not read.
- **A switch that skips all of it (established).** The separate I/O initialisation routine at `0xffaad720` (which has no direct caller in SAL_B and is reached through a table; its brick sequence reads the II register at `0x8_01c0_0128` bits 13:12 and prints "Found I/O brick attached to %I") tests bit 14 of the debug-switch word and, if set, prints "---- DEBUG - skipping I/O initialization on %I -----" and returns -1 without touching the I/O interface. Whether `0xffab38b0` has the same test was not read, so a DIP word with bit 14 set is a candidate for skipping I/O, not a verified way to do so.

## What stopped the interpreter run

The run executed the shipped SAL_B (integer instructions only, one processor, the PAL calls stubbed as success with zero results, the SHub registers as plain storage with the few behaviours named above) from the reset entry to the middle of `main_two`. It is a trace under stub inputs: **inferred**, not hardware behaviour, and it did not reach `main_three`. What it needed beyond the memory section, each a minimum answer for a model:

- **The jump to RAM (`0xffac6bb0`, progress 0x19) was skipped.** The routine lays out the system data area in the new RAM, copies the flash image there (printing "Shadowing SAL to ..." unless the CPU ID signature is set, in which case "Running under medusa - not shadowing SAL"), re-initialises the L1 link structure in the copy, switches stack and translation through `0xffaf5c80`, and enters `main_two`. The run instead entered `main_two` at `0xffa1ade0` directly, with the data left in the early 256 KB RAM at `0x1000000` and `main_ptov` returning its argument unchanged. A real model does not have to emulate any of this beyond a CPU that executes the PAL's `PAL_COPY_PAL`-style calls (256, 37 and 520 returned success) and RAM large enough for the copy.
- **A PIO write-error self test (`pio_wt_st_force_err`, `0xffa24cc0`, early in `main_two`).** It stores to `0x1_1005_0608` and spins until bit 0 or bit 2 of the PIO write status register at `0x1_2007_0200` is set; `pio_wt_st_reset` then clears it through the alias at `0x1_2007_0208`. The run set the status to `0x3f00_0000_0000_0005` on the store and back to `0x3f00_0000_0000_0000` (all six pending-count bits set, which is what the kernel treats as idle) on the alias write.
- **Allocation.** With the data in the early RAM the allocator ran out ("Out of memory - cannot allocate hwcfg at hwcfg/common/init.c line 78") because the arenas are sized for the RAM that the skipped step creates. The run substituted a bump allocator for `amalloc` (`0xffac30c0`); anything the PROM leaves in memory at hand-off from that point is therefore not representative.
- **The debug-information FIT entry** (type 0x23, "Debug info", present in the image) is loaded at the start of `main_two` through the FIT reader `0xffafaf50`, which reads the FIT through the top-of-flash window with bit 63 set; the interpreter had to alias that to the flash image. A real memory map needs the flash readable at its uncached alias.
- **The board EEPROM through the L1** (command id 6 again, selector 2, device id 1, count 0 meaning "until an empty reply") is read by `read_board_ia` (`0xffa84990`) as an IPMI-style FRU board information area: byte 0 version, byte 1 length in 8-byte units, byte 2 language, three bytes of manufacture time, then type/length-coded fields (low 6 bits length): manufacturer, product name, serial, part number, then one extra byte, the FRU file id, two more bytes and up to four further fields, ended by a byte `0xc1`; the sum of all bytes of the area must be zero or the PROM prints "read_board_ia: bad checksum". The chassis area is the same with selector 1 (`0xffa846c0`). The reply returns up to 64 bytes per request and the loop ends on a reply of zero bytes, so an end of data has to be reported as a zero count, not as an error; an error status makes the board read fail, which is non-fatal ("Could not retrieve EEPROM info on nasid"). The run used a 40-byte board area with the fixed strings from the built-in record ("SGI", "IP41", a serial, "030-1604-001") and answered every other selector with an error status.
- **Where it stopped.** In the route-table walk of `0xffa5b5d0` ("Distributing routing tables", main_two phase after "Calculating routes"): a loop that follows a 16-bit "next entry" index at offset 40 of each 100-byte-class entry until it reads -1. Entry 0 read 0 there, so the loop was endless. Entry 0's other fields were set (the discovery results above) but this index was not, which points to an initialisation done by the skipped system-data-area step or by the discovery code the skip bypasses; which of the two was not determined. This, not any hardware access, is what stands between the trace and `main_three`.

## Gaps remaining before "Loading EFI"

1. Which SPD sets and which L1 command-id meanings the real controller uses (the SPD positions, reply layout, test-completion bits, IBLS0 address and the source of bit 11 are settled above; what the selector 4 means to the L1 and what the real L1 reports for an empty slot are not).
2. The initialisation of the route-table "next entry" index that stopped the interpreter run, and the interconnect registers on the non-skip path (DIP bit 11 clear).
3. The whole of `main_three`: widget id read, credits, riser EEPROM, PCI walk, console selection (read statically below; not run).
4. PAL 99, 520, 528, 530 meanings.
5. The `0x81_101d_0080` and `0x81_101d_0088` relation.

## Review

Independent review of chips commits `ec38a7e`, `4bb8d3a`, `cb0fe84` and `b8fa253` (this page, the firmware page fixes, `questions/sn2-prom-open.md`, `evidence/irix-files.md`), examined at `b8fa253`. The reviewer did not write the page. Method: parse the FIT of `shub1snprom.bin` (SAL 5.04) and disassemble it with the retools `ia64-linux-gnu-objdump`; decompress the SAL runtime component (type 0x12) and read its dynamic symbols; compare other builds by instruction patterns. Nothing was taken from the page's own tables. PAL numbering was checked against the Linux `arch/ia64/include/asm/pal.h` in the Library `linux-history` root (it says it follows the Intel IA-64 SDM), not from memory.

**Confirmed (re-read in the binary).**

- FIT: PAL_B 7.79, 5.73, 2.25; PAL_A 7.31, 5.37, 1.27; SAL_A `0xffc4e000` (16 KiB), SAL_B `0xffa01000`, runtime, EFI types; reset-vector words at `0xFFFFFFE0` and `0xFFFFFFE8`. SHA-256 matches `root/sn2/SHA256SUMS`.
- SAL_A in full: every register write and value in the SHub 1 list, in the stated order and condition (`0x81_1002_0000` = `0x15031010`; bit 24 of `0x81_2001_0100`; `0x81_5003_1510/1530` ORed with `0x60` into `0x87_fed1_0000` and `0x87_fed3_0000`; election at `0x81_101d_0088` and `0x81_101d_0080`; winner zeroes `0x81_5003_1550/1540/1560`, writes 1 to `0x81_1006_0480`, later sets bits 41:39 of `0x81_101d_0100` to 7; error path with 176; FIT scan; `r31` read at `0x81_1003_0000 + (slice & 3) * 128`). `cr.lid` field is 4 bits at 26:23. Election direction (the processor whose value reads back is the winner and does the writes) is correct. PAL pair is chosen only on reason 3, after the node set-up. Reason 3 has the `psr.db` set, the stub returning 1, the spin on `r33` bit 3 and PAL index 528 with argument 5. Reasons 1 and 2 go to SAL_B at offsets 0x20 and 0x10, above 3 gives 177, the fatal hang is 178.
- Progress table at `0xffbd7000`: read in full (pairs of code and string). Every code and message the page quotes matches, including 0x8d, 0x89, 0x80 to 0x90 and 0x30, 0x38, 0x3b. Reason numbering follows from it.
- Main sequence: SAL_B reset entry stub at `0xffa01000` branches to `0xffa1de00` (progress 49 then 53, reads `0x1000010 + 8 * cpu`, `0x1000038`, `0x1000000 + 8 * (9 + cpu)`, calls `0xffac42d0` and `main` at `0xffa19a20`); progress writers in main, main_two (`0xffa1ade0`) and main_three (`0xffad7280`) carry the quoted code ranges.
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
2. **Election minimum answer.** The page says the read of `0x81_101d_0080` returns the written value "for a plain read/write register". The code writes `0x81_101d_0088` and reads `0x81_101d_0080`, which are different addresses; a plain register at 0x80 does not reflect a write to 0x88. The model needs 0x88 to update what 0x80 reads (alias, or a first-writer latch; the reset value is unread). The error path ORs bits into 0x80, so 0x80 is writable. Grade: the register relation is unknown.
3. **IP57 sentence.** "An IP57 node is therefore handled as IP41 in klconfig unless the EEPROM read fails" is not what the code shows: the klconfig board name is the fixed string either way, and the EEPROM supplies part, serial and revision. The conclusion that no IP41 or IP57 branch exists stands; rewrite the sentence.
4. **Address forms.** SAL_A uses `0x80_0000_0000 + 0x7_fed1_0000` for the LED registers (bit 39) while the runtime's UART form is `0xf_fed4_0000` (bit 35 plus the local offset, with the NASID shifted to bit 38 in `sysctl` code). The page calls the second the "node-addressed form" without reconciling the two windows.
5. **Not verified, so keep as inferred:** the hand-off function at `0xffaf8c50` (its callee writes a progress value 72 only indirectly; the 0x44 to 0x48 stores were not located inside it), the 4.43 comparison sentence, per-build `sysctl_probe` for 3.32 and 4.20 (the 4.43 retry and 5.04, 4.90 compare-only were confirmed; I did not isolate the 3.32 and 4.20 functions), the SAL_B command-id list, memory and I/O discovery paragraphs, and the address-map line about the runtime's global-window constants.

**Grades.** The SAL_A reading, progress table, FIT, UART offsets, probe functions and board-record selection are correctly **established** (read in full). The names of SAL_B functions come from matching the runtime and stay **inferred**, as the page says (the die routine at `0xffad2cb0` is named by the call shape). Memory, I/O, console and EFI hand-off statements are **inferred**.

**Cleared scope:** progress-code table and reason codes; SAL_A on SHub 1 as a register list and order (except the election minimum answer); FIT and PAL pair listing; L1 death path (0x8d) and UART location, stride and probe; board-identity claim (no IP41 or IP57 branch, built-in record only under the signature); PIC part 0xd102 keying; the README fixes (SHub 2 SAL_A, region size, recommendation, per-build probe for 4.43, 4.90, 5.04, 1.11, 1.40, hashes). **Not cleared:** the PAL index list, the election minimum answer, the IP57 sentence, memory, I/O and EFI hand-off detail, and per-build probe for 3.32 and 4.20.

### Addressed after the review

The PAL index list was re-enumerated (see [PAL procedures SAL_B calls](#pal-procedures-sal_b-calls)); the election minimum answer now says the 0x80 and 0x88 relation is unknown; the IP57 sentence was rewritten; and the two address forms are reconciled in the L1 section. The 4.43 comparison, the hand-off function, the command-id list and the per-build probe for 3.32 and 4.20 are still inferred, as the review asked. The memory, interconnect and I/O sections added after the review rest on an interpreter trace of the image and partial reading; only the items marked established were read in full. The memory register decode, the L1 message frame, the DIP-switch source of the single-node skip and the I/O structure outline were added after that and have not been independently reviewed.
