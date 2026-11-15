# Altix 350 and Prism: reset to the EFI console in SAL 5.04

What the SHub 1 firmware image SGI's `README.snprom` names for the Altix 350 and both Prism models does from processor
reset to the EFI console, and the minimum answer each hardware access needs for an emulated node to proceed. Image:
`shub1snprom.bin`, SAL 5.04 (banner "SGI SAL Version 5.04 rel081111 IP41 built ... Nov 11, 2008"), package snprom-10.54-70399,
sha256 `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`, read with the retools
`ia64-linux-gnu-objdump`. Layout, FIT and the component tables are in the [firmware page](README.md); SAL 4.43 and the
SHub 2 builds are compared where noted.

**Grades.** *established*: the whole function or table was read. *inferred*: built from a call list, a constant, a name
carried by the sibling SAL runtime (the runtime component is symbolised, SAL_B is not; names below that come from the
runtime are marked "runtime name"), or a function not read in full. *unknown*: not settled. Nothing here was run. The
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
jumping to EFI, 0x49 to 0x4f EFI start-up ("Installing EFI memory map", "base EFI devices", "console drivers",
"SN-specific EFI devices", "EFI initialization complete"), 0x50 EFI idle loop, 0x51 and 0x52 flashing. Fatal codes 0x80
to 0x90 include 0x80 no memory on node, 0x81 write to system controller timed out, 0x83 local master arbitration failed,
0x85 cannot initialise klconfig, 0x89 system controller communication init failed, 0x8d critical system controller
transaction failed, 0x8f NUMAlink discovery failed. Codes 0xb0 to 0xb4 (176 to 180) are written by SAL_A and the SAL_B
entry and are not in the table.

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
   Not reached unless PAL reports a fault in `r35`.
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

**Minimum answers for SAL_A.** Nothing needs a particular value except `0x81_101d_0080`: after the write to
`0x81_101d_0088` the read must return the same value for the single processor (a plain read/write register does), and
`0x81_101d_0100` must hold what was written (bits 41:39 = 7), since the UART bring-up checks them (below). All the
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
- **PAL procedures the firmware calls (direct index immediates in SAL_B, established):** 1, 2, 3, 8, 12, 16, 22, 29, 32,
  41, 42, 48, 64, 76, 224, 384, 530, 608, 1040, 1072, 1088, 2472, 3088. Architected names, from recollection of the public Linux `pal.h` and not checked against it: 1 cache flush, 2 cache info, 3 cache init, 8 VM summary, 12 fixed address, 16 platform address,
  22 MC drain, 29 halt light, 32 PMI entry point, 41 prefetch visibility, 42 logical to physical, 48 get hardware policy.
  The others are not mapped here (implementation-specific or unnamed; 528 in SAL_A is also one). Calls through the
  wrapper `cpu_MakeStaticPALCall`, `Stacked` and `Phys` variants take their index from the caller and were not
  enumerated, so this list is a lower bound.
- **PAL data the firmware reads:** `cpuid[3]` (masked `0xffffff0000` for the family and model, full value for the stepping
  table), `cpuid[2]` (the signature below), `cr.lid`, and the processor ID layout above (slice in bits 26:23).
- **CPU ID signature (fact only).** `cpuid[2] == 0xaeeeeeee8badbeef` is tested at 65 sites in SAL_B and in the runtime;
  with it the firmware skips the L1 UART, returns built-in board data, and makes `sysctl_cmd_command_timeout` fail at
  once with -24. It is not recommended here.

## Node board identification (IP41, IP57, others)

- **The PROM does not branch on a board name for the compute board (established for `hwcfg_node_init`).** The
  klconfig builder passes the fixed string "IP41" as the compute board's name (inferred: the helper that receives it was not read to its copy). The
  string `Part:030-1604-001;Name:IP41;Serial:KHD563;Revision:-D;` in SAL_B is used only when `cpuid[2]` carries the
  signature above (read in `init_klcfg_hub`); otherwise the record comes from the board EEPROM through the system
  controller. An IP57 node is therefore handled as "IP41" in klconfig unless the EEPROM read fails (error "Could not
  retrieve EEPROM info on nasid %d", which is non-fatal there).
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
  bits above 38. `sc_uart_init` waits for line-status bit 6 (transmitter empty) with a 100000-tick limit before
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
- **First exchanges (inferred).** Each request is `sysctl_cmd_open` (target `0x0ffff000`), `sysctl_cmd_construct_req`
  (class 6 and a command id), `sysctl_cmd_command`, `sysctl_cmd_close`, `sysctl_cmd_interpret_resp`. The command ids
  the SAL_B wrappers pass are 1, 3, 4, 8, 9, 10, 14, 18, 19, 21, `0x1005`, `0x1007`, `0x100a`, `0x100b`, `0x200d`, `0x200e`, `0x200f` (list in the
  call sites at `0xffa7ca9c` to `0xffa7fbbc`, not mapped to names; the repository's controller pages own the protocol).
  The requests carry a 4-byte big-endian code and status; status 0 is success, -106 selects a second code field.
- **Minimum answer.** A UART at the junk-bus offset that implements the 16550 registers (scratch loopback, line status
  with transmitter-empty set) plus a peer that answers the requests with success. Without a peer the PROM dies at 0x8d (0x89 is raised when its buffer allocation fails, not for a silent L1).
  Which responses make the boot continue to the console is the work of the sysco pages, not read here.

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
- **DIMM data and a memory-test pass are required (inferred).** If the L1 reports no DIMM the PROM stops with 0x80 ("This
  node has no memory"). The memory test (MBIST) polls registers; the exact completion bits were not read, so the
  minimum answer is unknown beyond "the controller registers read back what was written and completion bits read as set".
  This is the most likely first place an emulated memory controller stalls.
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
3. The SHub registers `main_two` reads for the node interconnect (progress 0x1c, `0xffa47870` and friends), with no
   router: the single-node case was not read.
4. PIC and a console device in discovery.
5. The CPU ID signature path avoids 1 and 2 and the board EEPROM read; stated as fact, not recommended.

## What is not read

The ordered MMR list of the memory controller, interconnect and I/O discovery phases, the single-node route skip, the
L1 command-id names, the contents of the I/O-widget register reads, what the PAL index 528 call does, and the `node id`
install write. Each is listed in [questions/sn2-prom-open.md](../../../questions/sn2-prom-open.md).
