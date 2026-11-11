# Datasheet: SGI XIO Fibre Channel board (XT-FC-2P / X9-FC-2P family, Adaptec AIC-1160)

Status: **research draft, not independently reviewed.** This sheet records what
reverse engineering of the shipped IRIX driver (disassembly of the `fcadp` objects)
and public evidence establish about **SGI's native XIO Fibre Channel host adapter**,
a general SGI part used by any IRIX machine fitted with the board. The Discreet Stone
framestore is one consumer of it. There is no public programming manual for the
controller, so the register and command contract below is derived from the shipped
`fcadp` driver.

This is the native XIO board (Adaptec AIC-1160, IRIX `fcadp` driver). It is a
**different controller** from the QLogic PCI FC card that IRIX reports as "Fibre
Channel QL2200A"; the two are not interchangeable.

## Evidence and grading

Labels: **E** established (public source cited, or directly observed in the
disassembled driver), **I** inferred (from a cited fact or observed code plus general
public knowledge), **U** unknown (names what would settle it). Two evidence classes
feed this sheet. Captured real-hardware behaviour (`hinv`, `/etc/ioconfig.conf`, kernel
syslog and board markings) reported by owners on public `comp.sys.sgi.*` newsgroups
establishes identity and IRIX-visible behaviour. Binary RE of the shipped `fcadp`
driver objects establishes the PCI front door, register map, firmware-load handshake
and command path.

Every statement rests on one of three things: the shipped 6.5.30 `fcadp` objects
(`hwutil.o:sh_loadnrun_lip`, `hwlip.o:sh_start_lip_sequencer`,
 `fcadp.o:fill_lip_tcb`, `fcadp.o:fcadp_ctlrinit` and
the routines named in place, each cited with its offset), a public document, or a
(a reason for a driver choice, a name for a register bit, how the chip itself behaves),
the sheet says so and marks it unknown or inferred with the binary read that would settle it.
Symbol names quoted below (for example `sh_load_sequencer`) and strings quoted from
the objects are what the shipped objects contain, cited as locators. Layouts are
described in prose in this sheet's own words. Names for register bits and fields that
do not appear in the objects are this sheet's role labels, not vendor names.

### Sources

| Tag | Source | Used for |
|---|---|---|
| U1 | comp.sys.sgi `4197CA17.AF164514@kpp.kiev.ua` | "2-port XIO FC card (AIC-1160) - copper"; `hinv`; `fcadp` loop-init syslog |
| U2 | comp.sys.sgi `3BE73104.DDD0B052@sgi.com`, `3BE7154D.6D18F0F3@structbio.vanderbilt.edu` | `/hw/module/N/slot/ioM/fibre_channel/pci/{0,1}/scsi_ctlr/0` hardware-graph paths |
| U3 | comp.sys.sgi `3A0602C2.9D1C6F58@al.com.au` | Octane (IP30) `hinv` with two `AIC-1160` controllers |
| U4 | comp.sys.sgi `3ADB3AC0.D64D9952@xiotech.com`, `lIEB6.468$g3.52088@news7.onvoy.net` | Board markings assy `030-0927003E`, FAB `034-0927-002 rev B`, "Adaptec AIC-11606", SOL 04-20-99; fabric-login behaviour |
| U5 | comp.sys.sgi `3fafc818.0304010217.1b59be6e@posting.google.com` | Marketing name "XT-FC-2P … 2 port Fibre Channel XIO controller for SGI Origin/Onyx2, DB9 copper" |
| U6 | comp.sys.sgi `nicoya-9688D8.14274812022006@shawnews…`, quoting SGI techpubs *Octane2 Duo Installation Guide* | XIO device map; device 13 = PCI module; FC board occupies an XIO quadrant |
| U9 | comp.sys.sgi `362276F0.10A8855F@csd.sgi.com`, `7psh8j$pos$1@nnrp1.deja.com`, `89sdal$42k$1@nnrp1.deja.com` | FC disks/LUNs presented as SCSI targets on an `AIC-1160` controller; multi-board use; O2000/O2100 |
| D1 | Discreet *Smoke 5.0 Installation Guide* pp. 103, 106 | "SGI XIO Fibre Channel board" in the Octane2 XIO slot for the R-series; `hinv` "AIC-1160, revision 2"; `xt_fc_2p_O` product |
| M1 | SGI *Fibre Channel PCI Option Board and XIO Option Board Owner's Guide*, part 007-3633-006 (SGI techpubs; earlier issues -002 to -005 also exist; later boards in 007-4240-001/-002). Table 1-4 (printed p. 10), printed pp. 10-17 | Marketing codes, board part numbers, supported platforms, required IRIX, connectors, the no-fabric and Class 3 / FC-AL-only limits. It does not name the controller chip and gives no registers |
| B1 | Shipped IRIX `fcadp` driver archive `usr/cpu/sysgen/IP30boot/fcadp.a` (6.5.30; cross-checked `IP27boot` and `IP35boot`), members `fcadp.o hwconfig.o hwutil.o hwintr.o hwtrans.o hwlip.o ulmutil.o` — ELF64 big-endian MIPS, not stripped. Disassembled clean-room. | PCI vendor/device match, BAR/PIO windows, bridge/DMA/interrupt path, chip register offsets, reset and firmware-load sequence, TCB command path, loop/login behaviour |
| B2 | Device-registration config `var/sysgen/master.d/fcadp` (`$Revision: 1.9 $`, readable config, not source) | Driver prefix `fcadp`, SCSI thread class and `scsi` dependency, default loop host-id tunable `fcadp_hostid = 125` |

The SGI owner's guide for these boards (M1, part 007-3633-006) is a published SGI document
and anchors identity, part numbers, platforms and the loop-only limit. It gives
no registers and does not name the controller chip, so the chip identification
still rests on the driver and the newsgroup posts (U1, U4). No AIC-1160
programming document was found. The techpubs reference in U6 is the Octane2
install guide quoted verbatim by the poster. With no public register document, the
disassembled driver (B1) is the sole source for the register and command contract
below.

### Corrections (2026-11-10)

A re-check against the shipped driver and the owner's guide changed the following. Readers who relied on the earlier text should note:

- **Reset on attach.** Earlier text said `sh_initialize` resets the chip with a 0x43
  write to host-control 0x22. It does not. The attach path (`fcadp_ctlrinit`, then
  `sh_initialize`, then `sh_prepare_config`) writes only the pause value 0x40 to 0x22.
  The 0x43 reset is issued only by the error-recovery routine `fc_reset_controller`
  (timeouts, LIP and reset requests). The chip comes up on first attach from a paused,
  never-reset state, with no 0x43 write before it.
- **Multi-segment TCB.** Earlier text said 0x54 holds a scatter-gather entry count in
  list mode (0x0b). The driver zeroes 0x54 in list mode; no count is written. The list
  ends at the descriptor whose length byte 3 is 0x01. 0x54 is a byte count only in
  single-buffer mode (0x08).
- **TCB 0x44** is the link to the next TCB slot in the driver's circular TCB queue, not
  a response buffer. The unsolicited-TCB text already called it that.
- **No byte-swapping of control blocks in the shipped driver.** `fc_swapctl`, and
  `ulm_swap8` which forwards to it, are empty 8-byte stubs in the shipped objects
  (IP27, IP30, IP35), because the driver is built with the big-endian-host swap
  disabled. Descriptor lists, TCBs, the LIP result and the 16-byte residual block are
  plain little-endian fields exactly as the chip wrote or reads them. Earlier text that
  told readers to byte-reverse the residual block per 8-byte unit, or the list
  per 16-byte stride, was wrong. Whether the host bridge swaps in hardware (the driver
  asks for byte-stream DMA mapping) is a host property, not a property of this driver.
- **No fabric.** Earlier text said the driver handles fabric login and works against
  switches. The shipped driver has no fabric login, and the owner's guide states the
  dual-channel XT-FC-2P and X9-FC-2P boards do not support fabric and run Class 3 and
  FC-AL only. The newsgroup anecdotes (U4, U9) behind the old claim cannot override
  either.
- **Board identity.** XT-FC-2P (030-0927-00x) is the Origin 2000, Origin 200 and
  Onyx2 copper board. The Octane copper board is a separate code, X9-FC-2P
  (013-2119-00x), functionally identical and mechanically different. The optical
  dual-channel boards XT-FC-2POPT-B (013-4048-00x) and X9-FC-2POPT-B (013-4046-00x,
  Octane and Octane2) are different boards (LC connectors, 133 MHz, 200 MB/s, IRIX
  6.5.16 or later), not a DB-9 board with a media adapter. That they carry an AIC-1160
  is **not established**. This sheet describes the driver's `0x9004:0x1160` match and
  the copper boards the posts describe.
- **Two ports.** The driver attaches once per PCI function and keeps a separate state
  block for each, and the hardware graph shows two `scsi_ctlr` nodes (`pci/0`, `pci/1`,
  Bridge slot numbers). Whether the two are two chips or two functions of one chip is unknown;
  a PCI configuration dump of the board, or the board photographs, would settle it.
- **Invalid WWN** only prints a warning and skips reading the media-type word; the
  port is still brought up (media type 0) and presents the invalid name.
- **LIP TCB layout.** The loop-map buffer address is at LIP-TCB offset 0x38, not 0x58,
  and the frame header starts at 0x08 (details in the LIP section).
- **TCB byte 0x07** (value 0x01 for a SCSI command) is regraded inferred: it is a chip
  encoding, not the on-wire R_CTL (FCP_CMND is 0x06 on the wire).
- **BAR type** is regraded inferred (inference from the command-register value 0x55); nothing else confirms it.
- Spot-checked and left as written: done-queue entry byte positions (the 6.5.30
  back-end interrupt routine reads bytes 0, 1, 2, 3 directly), and the PLOGI/PRLI/ADISC
  codes. ADISC is issued only when a target's flag asks for it; the abort builder is a
  print stub and never fills a TCB. Register-to-bank assignments were sampled (bank 4
  for the size-select, status-block, interrupt-enable and host-command registers) but
  not every row was re-verified.

## Product identity

| Item | Value | Label |
|---|---|---|
| Marketing name | XT-FC-2P (2-port Fibre Channel XIO controller, "for SGI Origin/Onyx2"), part number 030-0927-00x, for Origin 2000, Origin 200 GIGAchannel and Onyx2. X9-FC-2P (013-2119-00x) is the identical Octane variant | established (M1 Table 1-4; U5). IRIX product `xt_fc_2p_O` is from D1 and was not re-checked |
| Related optical boards (not covered by this sheet) | XT-FC-2POPT-B (013-4048-00x: Origin 2000, Onyx2, Origin 3000 X-brick) and X9-FC-2POPT-B (013-4046-00x: Octane, Octane2); LC connectors, 133 MHz, 200 MB/s, IRIX 6.5.16 or later | established for the product facts (M1); unknown for whether they use this chip |
| Bus | XIO | established (U1/U5/U6) |
| Controller ASIC | Adaptec AIC-1160 (chip marking "AIC-11606") | established (U4) |
| Ports | 2, DB-9 copper; an optional pluggable optical media adapter (MIA) fits the DB-9 | established (M1; U1/U5) |
| Topology limits | Class 3 and FC-AL (arbitrated loop) only, as an L_Port; **no fabric / switch support** | established (M1 p. 13) |
| Required IRIX | IRIX 6.5 or later, or 6.4.1 with the June 1999 patch set | established (M1 p. 12) |
| IRIX `hinv` string | `Integral SCSI controller N: Version Fibre Channel AIC-1160, revision 2` (rev 1 also seen) | established (U1/U2/U3/U9) |
| IRIX driver | `fcadp` ("Adaptec Fibrechannel driver"; syslog `fcadp6 (0):`; nodes `fcadp3t1l0`) | established (U1/U4, B2) |
| PCI vendor : device ID | `0x9004 : 0x1160` (Adaptec : AIC-1160) | established (B1; identical in IP27/IP30/IP35) |
| Board assembly (one sample) | assy `030-0927003E`, FAB `034-0927-002 rev B`, build 04-20-99 | established for that sample, inferred for the family (U4) |
| Host machines | XT-FC-2P: Origin 2000, Origin 200 GIGAchannel, Onyx2. X9-FC-2P: Octane. The guide lists Octane2 only with the optical X9-FC-2POPT-B, while a post and the Smoke guide (D1) tie Octane2 to the XIO FC board; which board an Octane2 carries is not settled here | established (M1) for the table; U1/U3/U9/D1 reports not reconciled with it |
| On-chip firmware | two sequencer microcode images shipped inside the driver and downloaded at init: a mainline image and a loop-init (LIP) image | established (B1) |
| Firmware version string on the board | — | unknown (no version string in the driver objects). Settled by: a printable-string scan of the two downloaded sequencer images once they are extracted from the driver (not done; the driver object is not in the held set of this clone), or the controller's own version register if the databook names one |

## Composition

The board is an **XIO→PCI bridge with the Fibre Channel controller(s) on PCI
behind it**, now confirmed from the driver (established, B1). `fcadp` is a pure PCI driver:
it registers through the IRIX `pciio` interface (`pciio_driver_register` with the
vendor/device key `0x9004 / 0x1160`), maps its register windows with
`pciio_piotrans_addr` / `pciio_pio_addr`, translates DMA addresses with
`pcibr_dmatrans_addr`, allocates Bridge read-response buffers with
`pcibr_rrb_alloc`, and connects its interrupt with `pciio_intr_alloc` /
`pciio_intr_connect`. The `pcibr_*` symbols are SGI's Bridge/XBridge-class PCI
bridge layer, so the controller sits on PCI behind an SGI Bridge reached over XIO;
IRIX's generic bridge code does the XIO↔PCI translation and the driver never
touches XIO directly (established, B1). This matches the hardware graph, which enumerates
the XIO widget as `fibre_channel` with two PCI devices under it (`pci/0`, `pci/1`,
IRIX's Bridge slot naming), each a `scsi_ctlr` (established, U2).

Each port is attached independently: `fcadpattach` runs once per PCI function (whether
that is one chip per port is unknown, see the corrections above),
allocating one ~1920-byte per-controller state block each (`kmem_zalloc(0x780, …)`),
so the two ports are two independent softc instances (established, B1). The driver also recognises an optical
media-interface adapter (MIA) module on a port (`sh_read_mia_type`; syslog
"Optical MIA attached", "MIA Fault or Optical Loss of Signal") — the DB-9 copper
boards take an optional pluggable optical MIA (established, B1/M1). The optical dual-channel
`-B` boards are different boards with LC connectors, not a DB-9 board plus MIA (M1).

Still unknown: the exact SGI bridge revision used on each host board; and the XIO widget ID and XIO
address decode, which are a property of the host machine's bridge, not of this
board, and are supplied by the generic IRIX bridge layer rather than by `fcadp`
(unknown).

## How IRIX drives it (behaviour contract, not a register contract)

- Each FC port is a separate "Integral SCSI controller"; Fibre Channel is a SCSI
  transport, so attached drives appear as `Disk drive: unit M on SCSI controller
  N` and RAID LUNs as `RAID lun: unit M, lun L` (established, U9).
- The `fcadp` driver performs FC-AL loop init / LIP and per-target port login; it
  works against JBODs, FC RAID (Clariion-class) and hubs on an arbitrated loop (established,
  M1/B1; U1/U9 for what owners saw). It does **not** log in to a fabric: the shipped
  driver has no fabric login, and the owner's guide says these boards do not support
  fabric (switches) and run Class 3 and FC-AL only (established, M1 p. 13, B1).
- Controller numbers are persisted in `/etc/ioconfig.conf`; `scsiha -lp <ctlr>;
  ioconfig -f /hw` rebuilds the graph (established, U2/U9).

## Register and command contract

Reverse-engineered from the shipped `fcadp` objects (B1). The AIC-1160 is a
**scripted-sequencer controller**: a microsequencer executes downloaded microcode
from an on-chip RAM, much as Adaptec's contemporary AIC-7xxx SCSI parts do, but
here adapted to Fibre Channel. The driver's event-string table names the chip's
internal blocks — a microcode engine the driver calls MTPE, a command/message
controller "CMC" that posts interrupts and runs DMA to and from PCI, send/receive
path blocks, a SERDES for the FC serial link, and the optical MIA — which fixes the chip's functional decomposition (established, B1).

### PCI front door

| Item | Value | Label |
|---|---|---|
| PCI vendor : device | `0x9004 : 0x1160` (the exact `pciio_driver_register` match key, `fcadp.o:fcadpinit`) | established (B1) |
| Chip revision | read from PCI config space and printed as "Adaptec AIC 1160 rev. %d found"; owners report revisions 1 and 2 | established (B1, U1/D1) |
| BAR type — **I/O space, not memory** | The chip's register windows are **I/O-space BARs** (the BAR's low bit is set), **not** memory BARs. The driver enables the chip by writing the PCI command register with **0x55** (I/O-space-enable 0x01 + bus-master 0x04 + memory-write-and-invalidate 0x10 + parity-response 0x40); **memory-space-enable (0x02) is deliberately never set** (`fcadp.o:fcadpattach`). IRIX enables only I/O space, so BARs that were memory BARs would stay disabled and the first register access would fault. The 0x55 command write is observed in the driver; that the BAR type bit is I/O is an inference from it, because the driver never reads the type bit. | established for the 0x55 write (B1); inferred for the I/O-space BAR type |
| PIO windows mapped | three 256-byte windows per function, mapped in `fcadp.o:fcadpattach`. Two are I/O-space PCI base-address registers and one is the chip's own PCI configuration space, requested as `pciio` spaces 7, 8 and 11: **space 7 is PCI config space** (not a BAR), **space 8 is BAR 0** and **space 11 is BAR 3** (the numeric arguments passed to the PIO mapping call). BAR 1 and BAR 2 exist on the chip but the driver zeroes them and never uses them (why it does so is unknown); IRIX still sizes all six BAR slots during enumeration. The driver stores the three pointers in a handle block at softc+0x80 in the order BAR 0, BAR 3, config (offsets 0, 8, 16). **BAR 0 (space 8) is the primary chip-register window**; **BAR 3 (space 11) is the sequencer-RAM window** (on-chip scratch RAM, TCB SRAM, scatter/gather RAM — "RAM" names what the window exposes, not a memory-space BAR); the third pointer is the chip's PCI config registers | established, including the BAR↔space mapping (B1) |
| PCI command / config setup at attach | `fcadp.o:fcadpattach` writes command register 0x55 (above), cache-line size 32 (128-byte lines), latency timer 0xf0 (240 clocks), and **OR-sets config register 0x40 bit 0x04 = Dual-Address-Cycle enable** (arms 64-bit PCI DMA addressing). It also writes 0 to BAR 1 and BAR 2 (reason unknown). Config 0x40 is a writable device-config register whose bit 0x04 enables 64-bit DMA | established (B1) |
| DMA | kernel buffers are run through `kvtophys` then `pcibr_dmatrans_addr`; the chip DMAs to/from the resulting PCI bus addresses. Descriptor and queue addresses are carried as **8-byte little-endian** fields, and 64-bit addressing is armed (config 0x40 bit 0x04 Dual-Address-Cycle enable, and the 64-bit DMA flag on the bridge translation), so the DMA path is **64-bit**, not 32-bit as an earlier draft guessed | established (B1) |
| Interrupt | one level-style interrupt per function via `pciio_intr_alloc`/`_connect`, handler `fcadpintr` | established (B1) |
| PCI error handling | the driver reads the PCI status register and logs master/target abort, parity and system-error bits (`hwintr.o` strings "PCI STATUS1 - …", "Signal Target Abort not set in PCI status register") | established (B1) |

### Chip host-register map (primary window, BAR 0)

Offsets below are on the primary register window (BAR 0, `pciio` space 8). Access
width is as the driver uses it: byte accessors do 8-bit loads/stores, "word"
accessors do **16-bit** loads/stores (`ulmutil.o` `inMemByte`/`outMemByte` =
`lbu`/`sb`, `inMemWord`/`outMemWord` = `lhu`/`sh`). The register file is
**bank-switched**: the byte at **0x2c** selects which of several overlapping register
sets is visible, so an offset can carry different functions in different banks. Offsets
are **established**; roles are read from the driver's use (routine cited). A note like "(bank 4)" gives the
bank the driver selects before touching that register.
The Grade column is filled only for the rows re-read against one machine build's driver objects; the other rows
keep the statement above and are not re-graded.

| Offset | Width | Role | Cite | Grade |
|---|---|---|---|---|
| 0x00 | 8 | Sequencer control: `0x01` enters RAM-load, `0x40` releases and runs the sequencer, **bit `0x02` = reset the sequencer program counter to its entry (address 0)**. After loading the mainline microcode the driver writes **`0x42`** (run + reset) to start it at the entry point, then unpauses at 0x22 — `0x42` means "(re)start the microcode from the top" | `hwutil.o:sh_load_sequencer`, `sh_start_mainline_sequencer` | established (values `0x01`, `0x40` and `0x42` written, in the order described, by `sh_load_sequencer` and `sh_start_mainline_sequencer`, re-read); inferred (that bit `0x02` alone resets the program counter: it is only seen inside `0x42`) |
| 0x02 | 16 | Sequencer-RAM address pointer. Set to 0 before a transfer; **auto-advances on both write and read** (set once, stream the data port; set to 0 again, read back) | `hwutil.o:sh_load_sequencer` | not re-read in this pass (see the lead-in) |
| 0x14 | 16 | Sequencer-RAM data port — 16-bit microcode words streamed in and read back to verify | `hwutil.o:sh_load_sequencer` | not re-read in this pass (see the lead-in) |
| 0x22 | 8 | **Host control.** Bit `0x04` = master interrupt enable (set enables the interrupt line, clear disables it); bit `0x40` = pause sequencer (poll the same bit for pause-ack); bit `0x80` = pause-at-top (poll for ack); unpause clears `0x40` and `0x80`. **Reset** is also driven here, but only on the error-recovery path: `sh_reset_chip` (called from `fc_reset_controller`, never from attach) sets the pause bit, waits for ack, then writes `0x43` (pause + FC-datapath reset bit `0x02` + chip-reset bit `0x01`); the chip-reset bit returns the sequencer, banks and internal state to power-on. Attach writes only `0x40` here (`sh_prepare_config`) | `hwutil.o:sh_enable_irq`/`sh_disable_irq`/`sh_pause_sequencer`/`sh_unpause_sequencer`/`sh_reset_chip`, `hwconfig.o:sh_prepare_config` | established (`0x04` set and cleared by the enable and disable routines, `0x40` and `0x80` polled by the two pause routines, unpause clears `0xc0`, reset writes `0x43` after a pause, attach writes `0x40`; all re-read); inferred (the effect named for the `0x02` and `0x01` bits of `0x43`: the driver only writes them) |
| 0x23 | 8 | Error-status register (parity / illegal-opcode flags). Read by the ISR on a hardware-error interrupt; reading it clears it | `hwintr.o:sh_frontend_isr`, `sh_load_sequencer` | not re-read in this pass (see the lead-in) |
| 0x24 | 8 | Interrupt-status byte 0; bit `0x08` = loop/attention interrupt. Handled bits are cleared by writing them back here | `hwutil.o:sh_interrupt_pending`, `hwintr.o:sh_frontend_isr` | not re-read in this pass (see the lead-in) |
| 0x25 | 8 | Interrupt-status byte 1: `0x80` PCI error, `0x40` hardware error, `0x20` software error, `0x10` sequencer/completion, `0x04` host-completion, `0x02` breakpoint, `0x01` sequencer-ready-for-LIP. Cleared by writing back here | `hwintr.o:sh_frontend_isr` | not re-read in this pass (see the lead-in) |
| 0x24 | 16 | Read as a 16-bit pair, the pending test masks with **0xff08** — all of byte 1 (0x25) plus bit `0x08` of byte 0 (0x24) | `hwutil.o:sh_interrupt_pending` | not re-read in this pass (see the lead-in) |
| 0x28–0x29 | 8 | (bank 4) Host completion-reporting control; `0x29` bit `0x20` **arms completion/interrupt DMA posting**, set at init after the status-block address is programmed | `hwconfig.o:sh_init_hardware` | not re-read in this pass (see the lead-in) |
| 0x2a | 16 | **New-TCB producer index / command doorbell.** `sh_deliver_tcb` increments the driver's 16-bit posted-command count and writes it here; the chip then fetches the newly-posted TCBs | `hwtrans.o:sh_deliver_tcb` | not re-read in this pass (see the lead-in) |
| 0x2c | 8 | **Register-bank select** (not a reset). **Eight banks**, selected by `0x00/0x11/0x22/0x33/0x44/0x55/0x66/0x77` (banks 0–7); e.g. `0x44`→bank 4 (DMA/clock/interrupt-enable), `0x11`→bank 1 (loop/SERDES), `0x22`→bank 2 (scatter/gather data port, host-DMA path). The named register sets live in banks 0–5; banks 6 and 7 carry only their own per-bank scratch cells (below) and have no distinct documented register set, but the RAM test still walks all eight | `hwconfig.o:sh_initialize`, throughout | established (bank codes `0x00`, `0x11`, `0x22`, `0x33`, `0x44`, `0x55` written as immediates, and the RAM test steps the code by `0x11` up to `0x77`; re-read); unknown (what the single write of `0xff` in `sh_setup_emerald_software` selects, and whether the two nibbles select banks separately: the error routine selects `0x22` before reading `0xe1`, while attach writes `0xe1` under `0x33`) |
| 0x34 | 8 | Sequencer-scratch page select: chooses which 128-byte scratch-RAM page is visible through the sequencer-RAM window | `hwconfig.o:sh_init_1160_ram`, the `hwutil.o` software-setup routine | not re-read in this pass (see the lead-in) |
| 0x40–0x5f | 8/16 | **Per-bank scratch cells** (32 bytes). The RAM test writes and reads these under **all eight bank selects** (0x00…0x77) with incrementing and `0x55aa` patterns; they are backed in every bank | `hwconfig.o:sh_init_1160_ram` | not re-read in this pass (see the lead-in) |
| 0x60–0x61 | 8 | (bank 2) **Scatter/gather-element RAM data port.** The RAM test resets the index at 0x8b to 0, writes 128 bytes (values 0…0x7f, then 0xa5) to 0x60 for each TCB slot, then reads 128 bytes back and compares — a chip that does not echo this fails the driver's RAM test (init failure −3). The port auto-advances through the selected TCB slot's 128-byte scatter/gather area | `hwconfig.o:sh_init_1160_ram` | not re-read in this pass (see the lead-in) |
| 0x8b | 8 | (bank 2) Scatter/gather cache pointer — written 0 to rewind the 0x60 data port to the start of the current TCB's scatter/gather area before filling or reading | `hwconfig.o:sh_init_1160_ram` | not re-read in this pass (see the lead-in) |
| 0x63 | 8 | (bank 4) **Clock-generator / link-speed status — an attach-blocking gate.** At config collection the driver reads this register, masks off the low two bits (transmit-clock control) with `0xfc`, OR-s in `0x02`, and requires the result to be one of **0xbe (divisor 1), 0x2e or 0xfe (divisor 2), or 0x6e (divisor 4)**; any other value makes the routine return a failure and config collection fails (see the config-collection note below; the phrase "cannot find link speed" is not a string in the shipped objects). The top six bits are the clock-source/lock configuration the driver checks; only a recognised value is accepted (a reset default of 0 reads back as 0x02 and is rejected) | `hwconfig.o:sh_read_link_speed` | established (read under bank `0x44`; masked with `0xfc`, OR-ed with `0x02`, compared with `0xbe`, `0x2e`, `0xfe`, `0x6e`, which select a stored divisor, and any other value makes the routine return a failure code; re-read); inferred (the clock-source reading of the top six bits and the divisor names) |
| 0x64–0x65 | 16 | **TCB index** (16-bit): selects which on-chip TCB slot is exposed — both to the TCB-data bytes in the sequencer-RAM window (BAR 3) and to the bank-2 scatter/gather data port at 0x60 | `hwconfig.o:sh_init_1160_ram` | not re-read in this pass (see the lead-in) |
| 0x68–0x6b | 8 | **Serial-SEEPROM controller** (command-driven, not bit-banged): `0x6a` = word address, `0x6b` = opcode + start / busy status, `0x68`/`0x69` = read-data low/high (see the SEEPROM subsection) | `hwutil.o:sh_read_seeprom`, `sh_write_seeprom` | not re-read in this pass (see the lead-in) |
| 0x70–0x77 | 8 | (bank 4) **Status-block DMA address** — 8-byte PCI bus address of the host interrupt-status block | `hwconfig.o:sh_init_hardware` | not re-read in this pass (see the lead-in) |
| 0x7c | 8 | (bank 4) Host-command register: parity-check enables, DMA-channel/hold controls (init default enables master + data parity checking) | `hwconfig.o:sh_initialize` | not re-read in this pass (see the lead-in) |
| 0x98–0x99 | 8 | (bank 4) Per-source interrupt-posting enable masks, initialised so loop and error sources post | `hwconfig.o:sh_init_hardware` | not re-read in this pass (see the lead-in) |
| 0xa1–0xa3 | 8 | (bank 1) Loop-state status: `0xa1` bits `0x80` LIP received, `0x40` bypass received, `0x20` enable received, low nibble = loop-port state; read after a 0x24 bit-3 interrupt to classify the loop event | `hwintr.o:sh_backend_isr` | not re-read in this pass (see the lead-in) |
| 0xd0 | 8 | (bank 1) Ordered-set / loop-primitive transmit control (LIP, idle) | `hwconfig.o:sh_initialize` | not re-read in this pass (see the lead-in) |
| 0xe1 | 8 | (bank 3 for the writes, bank 2 for the error routine's read) Link-error / link control: loss-of-signal `0x01`, loss-of-sync `0x02`, link reset `0x20`, link enable `0x40` | `hwconfig.o:sh_initialize` | established (written `0x20` then `0x40` under bank `0x33` by `sh_initialize`; read by the error routine, OR-ed with a byte of sequencer scratch RAM, bit `0x01` then raising the "Loss of Signal" notice and bit `0x02` the "Loss of Synchronization" notice; re-read); inferred (the register names for the other uses). Correction: the error routine selects bank `0x22`, not `0x33`, immediately before its read |
| 0xeb | 8 | (bank 1) SERDES status: fault `0x10`, lock-not-in-use `0x08`; low 2 bits sense the optical-module (MIA) type | `hwconfig.o:sh_initialize`, `hwutil.o:sh_read_mia_type` | established (read under bank `0x11`; the error routine tests bit `0x10` and raises the "MIA Fault or Optical Loss of Signal" notice, and tests bit `0x08` only when bit `0x10` of `0xea` is set, raising "SERDES: controller link not usable"; init masks the low two bits twice; re-read); inferred (the names "fault" and "lock-not-in-use") |

The **sequencer-RAM window (BAR 3, space 11)** carries the sequencer's 128-byte
scratch-RAM pages (paged by register 0x34) and the on-chip TCB data bytes (TCB slot
indexed by register 0x64). The on-chip RAM test (`hwconfig.o:sh_init_1160_ram`) is
**wider than this window alone** — it exercises several RAM regions, and all of them
must echo their writes or the test fails (init failure −3). The regions and where each is
reached:

| RAM region | Reached through | Index | Pattern |
|---|---|---|---|
| Scratch-RAM pages | BAR 3 window | page select 0x34 | incrementing + `0x55aa` across 0x00–0x7e |
| Per-bank scratch cells | primary 0x40–0x5f under **all 8 banks** | bank select 0x2c | incrementing + `0x55aa`, 32 bytes/bank |
| TCB data | BAR 3 window (TCB bytes) | TCB index 0x64 | incrementing + `0x55aa`, 128 bytes/TCB |
| **Scatter/gather RAM** | **primary bank-2 port 0x60** | TCB index 0x64, rewind 0x8b | incrementing then `0xa5`, 128 bytes/TCB |
| Global cells | primary 0x38 | — | `0x55aa`, 8 bytes |
| Command-channel buffer | bank-4 data 0x20 | address 0x9e | `0x55aa`, 128 bytes |

The scatter/gather region (bank-2 register 0x60) is the one an earlier draft missed by
placing the whole TCB-SRAM test in BAR 3; it is a distinct primary-window test and is the
step that fails if only the BAR 3 window is implemented. (A separate, earlier check
during config collection sizes the TCB count by writing the `0x66 dd 55 aa` pattern to the
TCB data **through the BAR 3 window** — that one touches only the BAR 3 window, which is
why the two checks must be kept distinct.) The queue base addresses and the done-queue
pass byte (next section) live in
this scratch RAM, **not** in primary registers: the value the prior pass recorded as a
"done-queue control register at 0x45" is scratch-RAM offset 0x45 in this window (the
done-queue pass byte), reached by selecting scratch page 0 with register 0x34 and
accessing the window at 0x45. The **config-space window (space 7)** carries the chip's
PCI configuration registers; the BIST byte the prior pass placed at a "third window
+0x0f" is PCI config offset 0x0f (`hwconfig.o:sh_run_bist`), and the chip revision,
command and status bytes are read from the same config window. All three window maps
are established (established, B1).

**Endianness.** The chip is a little-endian PCI device. The driver byte-swaps
16-bit quantities on the register path — the microcode stream is swapped
word-by-word (`ULM_SWAP_SHORT`) on the way to the RAM port — while single-register
byte accesses are endian-neutral (established, B1). The control-block swap routines
(`ulm_swap8`, `fc_swapctl`) are **empty stubs in the shipped objects** (8 bytes each,
IP27, IP30 and IP35): descriptor lists, TCBs and the residual block are not swapped
before or after the chip. Treat them as plain little-endian fields in host memory
(established, B1). Why the build empties them is unknown; the 8-byte bodies are what the objects contain.
Whether the host bridge byte-swaps in hardware depends on the host, not on `fcadp`.

### Config collection (the first chip access after attach — gates before any reset)

Before any reset, SEEPROM read or microcode load, the driver collects configuration
once per PCI function with `hwconfig.o:sh_get_configuration`. This is the **first
register traffic the chip sees**, and two of its steps gate attach. The sequence is:

1. Pause the sequencer — poll the host-control register 0x22 for the pause-ack bit
   (0x40), writing the pause bit until it reads back set. The chip must return 0x40 on
   read-back here.
2. Clear interrupt status — write 0xff to 0x24 and 0x25 — and clear the PCI error bits.
3. Select bank 4 (write 0x44 to 0x2c) and write **0x81 to the bank-4 size-select
   register 0x62** (eight-byte DMA addressing, four scratch pages). The driver does
   **not** read 0x62 back, so no particular read value is required there.
4. Re-select bank 4 and **read the clock/link-speed register 0x63**. This is the gate:
   the driver masks the value with `0xfc`, OR-s `0x02`, and
   accepts only 0xbe / 0x2e / 0xfe / 0x6e. **A value of 0 is rejected** (0 →
   0x02) and the routine returns a failure (the phrase "cannot find link speed" is not a string in the shipped objects) — reported to the kernel as
   **"error -2 in getting config"** and, per `scsi_ctlr` node, **"Adapter fatal error —
   unuseable"**, with no microcode load, SEEPROM read or TCB attempted.
5. **Size the TCB count.** Config collection then writes a candidate last-TCB index to
   register 0x64/0x65, writes the four-byte pattern (0x66, 0xdd, 0x55, 0xaa) into the TCB
   data bytes **through the BAR 3 window**, reads it back, and steps down through
   candidate sizes until the pattern verifies (else "no SRAM"). This check touches only
   the BAR 3 window. The chip revision (config offset 0x08) is read here but is
   not a gate.

A fatal here (step 4) is purely the link-speed read — **not** a SEEPROM or config-query
failure. The SEEPROM read happens later, in the per-controller init below.

**A second, wider RAM test runs during reset-and-init (`sh_init_1160_ram`), and it is a
separate gate** that fails the whole init with **"initialization failure −3"** on any
RAM mismatch. Unlike
the TCB-count probe above, it is not confined to the BAR 3 window: it also tests the
per-bank cells under all eight banks and the **scatter/gather RAM through the primary
bank-2 data port at register 0x60** (rewound by 0x8b, TCB-indexed by 0x64) — see the RAM
test table in the register-map section. A chip with only the BAR 3 window backed
would pass config collection but fail here at the bank-2 0x60 scatter/gather test. All of
the RAM regions must echo their writes (established, B1; the 0x63 gate, the 0x62 = 0x81 write and the
bank-2 0x60/0x8b/0x64 scatter/gather test are read from the binary).

### Reset and firmware (sequencer) load

`fcadp.o:fcadp_ctlrinit` runs per controller: read the SEEPROM for the WWN and
board parameters, call `sh_initialize` to reset and bring up the chip, read the
MIA type, then start I/O. `hwconfig.o:sh_initialize` does **not** reset the chip: it
pauses it (`sh_prepare_config` writes `0x40` to host-control 0x22) and, on power-up
initialisation, runs `sh_init_1160_ram` to test/clear the internal RAM
(the `0x55aa`/`0xa5` patterns), invalidates the command-block table, and loads the
sequencer. The `0x43` reset exists only in error recovery (`fcadp.o:fc_reset_controller`, via
`hwutil.o:sh_reset_chip`). The microcode download (`hwutil.o:sh_load_sequencer`) is: disable
interrupts; write sequencer-control 0x00 = `0x01` and address 0x02 = `0`; stream
each 16-bit microcode word (byte-swapped) to the data port 0x14; reset the address
and read the words back through 0x14 to verify; write control 0x00 = `0x40` to run;
restore interrupts. The two microcode images are shipped **inside the driver**, as
static arrays: the mainline image `sh_mainline_code` (3912 bytes, `.data` of
`hwutil.o`) and the loop-init image `sh_lip_code` (1644 bytes, `.data` of
`hwlip.o`); `sh_reload_mainline_firmware` reloads the mainline image after a loop
event, and `sh_loadnrun_lip` swaps in the LIP image to drive a loop
initialisation, then restores mainline (established, B1).

### Queue and status-block setup (how the chip finds the rings)

This is the piece the command path was missing. The producer index at control-block
offset 0x82 only *counts* posted commands; the chip learns *where* the rings live from
addresses the driver writes at init. The controller software-setup routine in `hwutil.o`
(called from `sh_initialize`) programmes three host-memory regions and
`hwconfig.o:sh_init_hardware` a fourth. The ring **base addresses go into the sequencer's scratch RAM**, not into
primary registers: the driver selects scratch page 0 (register 0x34 = 0) and writes
each 8-byte little-endian PCI bus address into the sequencer-RAM window one byte at
a time (`sh_output_paddr`).

| Region | How the chip is told | Cite | Grade |
|---|---|---|---|
| **New-TCB ring base** | 8-byte host PCI address of the TCB ring written to scratch offset **0x1c** | software-setup in `hwutil.o` → `sh_output_paddr` | established |
| New-TCB ring stride / count | Entries are **128-byte TCBs**; the ring holds as many entries as the probed TCB count — taken from the on-chip TCB-SRAM capacity and capped at 512. The producer index (register 0x2a, control-block offset 0x82) and the chip's consumer index (bank-4 register 0x6a, zeroed at init) wrap at that count | `fcadpattach` (allocates count × 128 bytes), `sh_init_hardware` | established |
| **Done-queue base** | 8-byte host PCI address of the done queue written to scratch offset **0x08** | software-setup in `hwutil.o` → `sh_output_paddr` | established |
| **Done-queue size** | Negative entry count (the negated TCB count) written to scratch offset **0x48** (two's-complement, so the sequencer counts up to zero); entries are 4 bytes, one per TCB | software-setup in `hwutil.o` | established |
| **Done-queue pass byte** | Scratch offset **0x45** written `0xff` and read back — the "0x45" the prior pass read as a primary register is this scratch byte, reached through the sequencer-RAM window | `sh_setup_doneq` | established |
| **Host status block** | 8-byte host PCI address written to the bank-4 status-block DMA registers at **0x70–0x77** | `sh_init_hardware` | established |
| **Completion arming** | Bank-4 register **0x29 bit `0x20`** arms completion/interrupt DMA posting. With the done-queue scratch set up, the per-source masks at 0x98/0x99 enabled, and the master interrupt enable at 0x22 bit `0x04`, this is what lets the chip post completions and raise interrupts; a doorbell write to 0x2a then starts command fetch | `sh_init_hardware`, `sh_deliver_tcb` | established |

**Done-queue tag / toggle rule (exact).** Each 4-byte done-queue entry is
`{ TCB handle (2, little-endian), status (1), pass-count (1) }`. At setup every
entry's pass-count byte (+3) is initialised to **0xff**, and the driver holds an
expected pass value starting at **0**. The chip writes into the pass-count byte the
**number of laps it has made around the ring, modulo 256**, starting at 0 on the first
lap. The ISR consumes an entry while its pass-count **equals** the expected value; when
it reaches the end of the ring it bumps the expected value by one, so the chip's
0→1→2… lap counter and the driver's expected counter stay in step. The `0xff` sentinel
guarantees no not-yet-written slot matches the initial expected value 0. (Front-end and
back-end ISRs keep separate expected counters over the same ring.) This is **not** a
one-bit toggle — it is a wrapping lap counter (`hwintr.o:sh_frontend_isr`,
`sh_backend_isr`; established, B1).

**Status-block mirroring.** The host status block is an 8-byte area whose first two
bytes mirror interrupt-status bytes 0x24 and 0x25. When an interrupt condition arises
the chip DMAs those bytes into the block, so the ISR reads interrupt status from host
memory without a PCI read; it then clears handled bits by writing them back to the chip
at 0x24/0x25 and clears its host-memory copy. A separate sequencer transfer-count area
is DMA'd for residual computation (established, B1).

### Serial SEEPROM (identity store)

The board SEEPROM is read through a **command-driven controller** — four cells in the
bank-0 register set, not a bit-banged clock/chip-select/data-in/data-out interface
(this corrects the earlier reading). Offset **0x6a** takes the 16-bit word address,
offset **0x6b** takes the opcode and start bit and reports busy, and offsets
**0x68/0x69** return the read-data low/high byte. A word read writes the address to
0x6a, writes the read opcode (`0x61`, read-opcode bits + start) to 0x6b, spins on the
busy bit (`0x01`) at 0x6b, then reads 0x68 and 0x69. The sequencer must be paused for
the access (`hwutil.o:sh_read_seeprom`, `sh_write_seeprom`; established, B1).

| SEEPROM word(s) | Contents | Cite | Grade |
|---|---|---|---|
| 0 | Control / speed word. The driver checks its **low nibble (`word0 & 0xF`) against the expected multi-host-speed value `0xF`**; if it differs it tries to **reprogram** the SEEPROM (logs "reprogramming adapter for multi-host uses"). A word 0 with low nibble `0xF` (e.g. `0x000F`) avoids the reprogram path; a word 0 of 0 drives it (below), which fails harmlessly but is noisy | `fcadp.o:fcadpattach` | established |
| 2 | Media-interface (MIA) sense word. Only bits 8 and 7 are tested (`word2 & 0x180`): **`0x180` = a media module is described and it is read by current sensing; `0x100` = described and read by voltage sensing; anything else (`0x000`, `0x080`) prints "WARNING: SEEPROM MIA information incorrect - media_type == 0x…" and skips the media read.** See the media-sense note below. The warning is **not fatal**: attach continues, and a word of zero merely leaves the media type at 0. It is only looked at when the WWN in words 3–6 is valid. A word of 0 produces exactly the warning and nothing else | `fcadp.o:fcadp_ctlrinit` (the word-2 read at `0x507c`, mask/compare at `0x5084`–`0x5098`) | established |
| 3–6 | **World-Wide Name** — 8 bytes (four 16-bit words) read starting at word 3, assembled most-significant-word first into the 64-bit port name. A WWN is **valid** when it is non-zero, not all-ones, and not the unprogrammed signature (top 60 bits `0x2000_0800_6900_000`). A WWN of 0 gets the warning "invalid wwname 0x0", the media-type word 2 is not read (media type stays 0), and bring-up continues regardless with that invalid port name, which targets may reject at login | `fcadpattach` (`sh_read_seeprom(…,3,4)`) | established |

**Media-sense note (what word 2 selects, and what "copper" and "optical" mean to the
driver).** The driver has no copper-versus-optical switch. Word 2 only says *which of two
samples of the SERDES status register to trust* (see the loop-phase register table):
bit 7 set picks the sample taken after the lock-to-reference bit is also set (current
sensing), bit 7 clear picks the earlier sample taken with only the sync-enable bit set
(voltage sensing); bit 8 says the word is meaningful at all. The two low bits of that sample
are the **media-module type: 0 = no module sensed, 1 = multimode optical, 2 = single-mode
optical, 3 = unknown** (`hwutil.o:sh_read_mia_type`; established for the codes, read from the code and
checked against the two `0xeb` reads and `&3` masks in `hwconfig.o:sh_initialize`). Only a
non-zero type prints "Information: Optical MIA attached(N)". A board with a sensed optical
module therefore has word 2 = `0x0100` or `0x0180` and a SERDES status whose low
two bits are 1 or 2 in the selected sample; a **copper (DB9) board** has the same word with the
low two bits 0 (the copper port has no sensed module, so type 0 and no "Optical MIA" line)
(inferred — the code cannot tell a copper port from an empty optical socket, and the XT-FC-2P
syslog quoted in U1 is not held with that line either way). **Which of `0x100` or `0x180` a
real copper or optical board's SEEPROM actually carries is unknown**; the driver is satisfied by
either. A SEEPROM image dump from a real board
would settle it.

The **loop host-id is not stored in the SEEPROM.** The driver sets the host-id to an
invalid value at attach and the real AL_PA is settled during loop initialisation; the
only host-id input is the driver tunable `fcadp_hostid` (default 125, B2), used as the
preferred loop address (established, B1/B2).

**SEEPROM reprogram path and the "Signal Target Abort" check.** When word 0's low nibble
is wrong the driver enters its SEEPROM-write path (`fcadp.o:write_seeprom`). That path
begins by **deliberately provoking a PCI target abort**: it does a four-byte read of the
bank-0 register at **0x1c** (which the bus presents as two 16-bit accesses at 0x1c and
0x1e) expecting the chip to answer with a target abort, then reads the chip's PCI
configuration status byte (config offset 0x07) and requires the **Signal-Target-Abort bit
(0x08)** to have set — if not, it prints "Signal Target Abort not set in PCI status
register" and gives up on the write. A valid word 0 (low nibble 0xF) keeps this path from being entered; if it is entered, a read of
bank-0 register 0x1c has to raise a target abort and set config-status bit 0x08. This
diagnostic is only reached on the reprogram path, not during normal init (established, B1).

### PCI class, XIO widget and bridge

| Item | Value | Grade |
|---|---|---|
| PCI class / subclass / prog-if | Held in the chip's PCI config space (offsets 0x0b/0x0a/0x09). The driver binds purely on the vendor/device key `0x9004 / 0x1160` (`pciio_driver_register`) and never reads the class, and the IRIX Bridge PCI layer enumerates and attaches by vendor/device, not class — so IRIX does not gate attach on the class value (the conventional Fibre Channel class is 0x0c / 0x04). The chip's actual class bytes are still not established from the driver | inferred that attach does not depend on it; unknown for the exact bytes — a config-space dump of real hardware settles them |
| XIO widget ID and address decode | A property of the host machine's XIO→PCI bridge, supplied by IRIX's generic bridge layer; `fcadp` never touches XIO or the widget directly | unknown — a host hardware-graph / widget-ID capture settles it |
| SGI bridge revision | Likewise a host-board property, not readable from `fcadp` | unknown — host bridge identification settles it |

### The same board on an Octane (IP30, IRIX 6.5.21)

Checked against the 6.5.21 IP30 kernel and `fcadp` archive (kernel SHA-256 `c5cb4521…`;
`usr/cpu/sysgen/IP30boot/fcadp.a`, 203,988 bytes, SHA-256 `6d8f8c6b…`).

| Question | Answer | Grade |
|---|---|---|
| Does the 6.5.21 IP30 driver take a different value list, mask or width at bank-4 0x63 than 6.5.30 IP27? | **No.** `hwconfig.o`, `hwutil.o`, `hwintr.o`, `hwlip.o`, `hwtrans.o` and `ulmutil.o` of the 6.5.21 IP30 archive have the same code bytes as the 6.5.30 IP30 and IP27 archives (only the compiler option note and the line table differ). `fcadp.o` matches the 6.5.30 IP30 build and differs from the IP27 build in one routine, `fcadp_mapbp` (frame size and register allocation; a DMA-mapping routine off the config path, not traced instruction by instruction). In every build `hwconfig.o:sh_read_link_speed` (text offset 0x2a4, 168 bytes) writes 0x44 to register 0x2c, does one byte read of 0x63, forms `(value & 0xfc) \| 0x02`, and accepts exactly 0xbe, 0x2e, 0xfe or 0x6e (stored divisors 1, 2, 2, 4); anything else returns 1 | established (disassembly; sections compared byte for byte) |
| Can "error -2 in getting config" come from anywhere else? | No. The only −2 return in `sh_get_configuration` (text offset 0, 676 bytes; at offset 0xe8) is the non-zero return of the link-speed routine; the TCB-count probe fails with −1. So a −2 means the byte read of BAR 0 + 0x63, after the 0x44 write to BAR 0 + 0x2c, returned a value outside the list | established |
| What touches widget offset `0xc00000` on an Octane? | The IP30 kernel's Bridge flash driver (`srflash_attach`), not `fcadp`. The Bridge map has registers at 0, type-0 config space for devices 0 to 7 at 0x20000, device PIO windows at 0x200000 (device 0, 2 MB), 0x400000 (device 1, 2 MB) and 0x600000 to 0xbfffff (1 MB each), and the external flash, two 2 MB chip selects, at 0xc00000. The driver registers for the Bridge widget identity (part 0xc002, manufacturer 0x36), so the kernel runs it for **every** Bridge, including this board's. It maps the register block; returns quietly unless Status bit 5 (PCI mode) is set; maps flash offset 0xc00000, size 8; sets Control bit 31 (flash write enable); stores 0x9090; reads the halfwords at offsets 0 and 2 and wants 0x00b0 and 0x66a8; on a mismatch repeats at 0xe00000; then clears Control bit 31 and gives up without a message. It sets up no fault handler. The 6.5.21 IP27 kernel has no such driver (no `srflash` symbol or string), so the board never touches the flash window on an Origin 2000 | established for the IP30 routine and the IP27 kernel; inferred that the 6.5.30 IP30 kernel does the same (not read) |
| What must the board's Bridge do? | Real X9-FC-2P boards attach on Octanes (U3, D1) without a bus error, so on the real board either a flash is fitted or an empty select reads without faulting. The probe needs the reads of 0xc00000 and 0xe00000 and the 16-bit store to complete, and the reads must not be 0x00b0 / 0x66a8 (all ones passes). What the real board returns is not known | established for what the probe needs; unknown for the board. A read of flash offset 0 on a real X9-FC-2P settles it |

#### How the IRIX 6.5.21 kernel places the board's BARs

Read from the 6.5.21 IP30 kernel and the 6.5.21 Origin kernel (the Bridge slot set-up and address
allocator functions).

| Question | Answer | Grade |
|---|---|---|
| Where does the kernel allocate an I/O BAR? | From a per-Bridge pool, not from the device window. At Bridge attach it builds three pools: **I/O space starts at 0x200000, runs to about 0x10000000, in 1 MB units**; one memory range starts at 0x4000 and is 0xfc000 long in 16 KB units; the other 32-bit memory range starts at 0x200000 in 1 MB units. The pool is chosen from the BAR's recorded type. Every I/O BAR therefore takes a whole 1 MB unit, first fit, shared by all slots on the Bridge. Origin 2000 placements (BAR 0 = 0x200000, BAR 3 = 0x300000) follow from this | established (disassembly; the allocator and pool set-up are the same code in both kernels) |
| Does it keep an address firmware already assigned? | It tries. The slot set-up reads each BAR; if the command register's I/O-decode bit is set it takes the BAR's address as firmware's assignment and asks the pool to reserve it. Later, only a BAR whose recorded address is below its size (unassigned) is given a fresh allocation | established for the mechanism; unknown for what the reserved size is in practice and when the reserve is skipped |
| Does the kernel treat the AIC-1160 specially? | Yes: when it turns decoding on it enables bus master and **I/O decode only** for vendor 0x9004 device 0x1160, and I/O plus memory decode for other devices | established |
| What BARs does the real chip present? | Measured on a PCI AHA-F950 (AIC-1160 rev 02): `lspci -v` posted to the Linux kernel mailing list by Mark Watts on 2004-06-18, subject "Adaptec AHA-F950 FC card". Region 0 is I/O, 256 bytes; region 1 is 64-bit non-prefetchable memory, 4 KiB (it occupies BARs 1 and 2); region 3 is I/O, 256 bytes; the expansion ROM is 64 KiB; there is no BAR 4 or 5. It agrees with the driver (BAR 0 and 3 used as 256-byte windows, BARs 1 and 2 cleared) and the kernel's I/O-only decode | E for the chip on that card; I for the XIO board (same chip and revision) |

#### The firmware-placed BAR 0 and the kernel's reserve

With command word 0x7 and BAR 0 reading 0x200001 / 0x400001, the 6.5.21 IP30 kernel's slot set-up masks the
type bit off, takes the lowest set bit of the address as the size (2 MB / 4 MB) and asks the I/O pool to
reserve that range; the range fits the pool, so the type bit is not what defeats the reserve (established). All slots
do this before any slot allocates its unassigned BARs (established). Which pool the reserve targets comes from a stack
value that static reading does not resolve (unknown), and a failed reserve is silent. Whether a real board plus the
real PROM ends with the same BAR 0 / BAR 3 overlap is therefore not settled (unknown); a config-space dump of a
real board, or the pool and result of the reserve call in a run, settles it.

#### Firmware-placed BAR 0 and the 6.5.21 reserve defect

The 6.5.21 IP30 kernel reserves a firmware-placed I/O BAR using a space code read from a stack slot that nothing
initialises on the I/O path (the only other writer stores a memory-space code), so the reserve misses the I/O pool
and a later allocation of the unassigned BAR 3 can land on BAR 0; the 6.5.30 kernel passes the recorded code.
Established from both kernels and a breakpoint run. What a real board does depends on whether the real firmware
places BAR 0 at the first free I/O unit (0x200000) or at all: unknown, and settled by reading a real board's BAR 0
or the firmware's PCI scan. The IRIX-side description is in the kudzu repository (`docs/ip35-pci-bridge.md`).

#### What the IP30 PROM does with a PCI card on an XIO Bridge

From the 6.5.30 IP30 PROM (SHA-256 `ee4722ca…`, routine at 0x1fc53218, started from the bridge set-up at
0x1fc52a38) and the 6.5-base PROM (SHA-256 `73bf1087…`, same routine at 0x1fc54560 to 0x1fc54a20). It runs for
every XBridge widget, and for a Bridge widget whose status bit 0x20 (PCI mode) is set, whether or not the
widget is the boot path (E). For each slot with a non-zero ID word it clears the command word, walks BARs at
offsets 0x10 to 0x24, and for each: clears it, sizes it with all-ones, rounds the running I/O or memory cursor up
to the slot's window granule (2 MB for slots 0 and 1, 1 MB for the rest) before the slot's first BAR, places the BAR at
the cursor rounded to the larger of its size and 0x4000, and advances the cursor (E). The walk **stops at the
first BAR that sizes to zero**, then sizes the expansion ROM, so BARs after an absent one are left unassigned
(E). After BAR 0 it writes the slot's Device register (window base = BAR 0 address >> 20) and finally ORs 7 into the command word (E).
Only the IOC3 ID (device 3, vendor 0x10a9) is special-cased (BAR 0 only); the class code is never read (E).
Hence a 256-byte I/O BAR 0 in slot 0 lands at 0x200000 and in slot 1 at 0x400000 (E). A 64-bit memory BAR is
recognised from the type bits read back after clearing (0x1fc534b8 to 0x1fc534c0): only its low dword is sized, the
upper dword is written 0 and the walk steps over it to the next BAR (0x1fc53554) (E). With the measured layout
(see above) slot 0 gets BAR 0 I/O 0x200000, BAR 1 memory 0x200000 (memory space is separate), BAR 3 I/O 0x204000
(I/O cursor after BAR 0, 0x4000 minimum alignment) and the 64 KiB expansion ROM address 0x210000, written with the
enable bit clear (E for the routine, I for the board, which has the same chip). The 6.5.21 kernel treats a placed
64-bit BAR like a 32-bit one and also steps over its upper half, so BAR 3 counts as assigned (E).

### Command / response path

Commands are **transfer control blocks (TCBs)** built in host memory and handed to
the chip by doorbell; completions come back as fixed-size entries the chip writes
into a **done queue** in host memory, flagged by an interrupt. The layout below is
from the IP30 objects and was cross-checked identical on IP27 and IP35: the command
doorbell offset, the producer-index location and the CDB offset match byte-for-byte,
with identical argument wiring in `fill_normal_tcb` (established, B1).

All offsets are from the start of the TCB (the block `fill_normal_tcb` fills through
the pointer the driver's command-block header carries). **Endianness matters and is
mixed**: the TCB's own control fields — the handle, the buffer addresses and the
transfer lengths — are stored **little-endian** by three helper routines that write
one byte at a time, low byte first (`fcadp.o:assign_int16`/`assign_int32`/
`assign_int64`), because the chip is a little-endian PCI device; but the embedded
FCP command fields that travel on the wire are stored in **big-endian / FC network
order** (the data length at 0x40 is written with an unaligned `swl`/`swr` pair, and
the SCSI CDB is copied through verbatim), exactly as Fibre Channel requires (established, B1).

#### TCB byte layout (built by `fcadp.o:fill_normal_tcb`)

The block carries, in order, a **32-byte FC frame header at 0x00–0x1f**, four TCB
control bytes at 0x20–0x23 (the data direction/class at 0x21 and the data-descriptor
mode at 0x23), a standard 32-byte FCP_CMND information unit at 0x24, and then a TCB
descriptor area with the DMA addresses and lengths. The frame-header byte roles are
pinned above (the earlier "FC header at 0x0c–0x23" reading was off by the header's
start): OX_ID at 0x00, D_ID/AL_PA at 0x04, R_CTL at 0x07, TYPE at 0x0f, F_CTL around
0x0e–0x11. The FCP_CMND interpretation is anchored by the CDB landing at 0x30: an
FCP_CMND unit of FCP_LUN(8) + FCP_CNTL(4) + FCP_CDB(16) + FCP_DL(4) places its CDB at
0x30 only if the unit starts at 0x24, and every field the driver writes lines up with
that (LUN bytes at 0x24, a direction byte at 0x2f, CDB at 0x30, data length at 0x40).
The chip-control fields after 0x40 are written by the little-endian helpers and by the
scatter-gather mapper.

| Offset | Width / order | Field (meaning) | Cite / grade |
|---|---|---|---|
| 0x00 | 2, LE | **Originator exchange ID (OX_ID) = the TCB handle / command tag.** The same value is written again at 0x68 and echoed in the done-queue entry, so it is the chip's command identifier | `fill_normal_tcb` via `assign_int16`; established |
| 0x02 | 2 | Responder exchange ID (RX_ID), set to 0xffff (unassigned) on an outbound command | `fill_normal_tcb`; established |
| 0x04 | 3 | **Destination ID (D_ID)** of the target; on a loop its low byte (0x04) is the target AL_PA, looked up in the target-id→AL_PA table. The chip fills the source ID itself from its own loop address, so the TCB has no S_ID | `fill_normal_tcb`; established |
| 0x07 | 1 | **R_CTL byte** (chip encoding, not the wire value): **0x01** for a SCSI (FCP) command; 0x22 for a link-service request, 0x23 on the expected reply. The wire R_CTL of FCP_CMND is 0x06, so 0x01 (FC "solicited data") is not the on-wire category; it is not the on-wire value. 0x22/0x23 match the real ELS values | `fill_normal_tcb`/`fill_plogi_tcb`; established that the bytes are written, inferred for their meaning |
| 0x09 | 1 | Frame delimiter: **0x05** = class-3 normal | `fill_normal_tcb`; established |
| 0x0e–0x11 | 4 | **F_CTL / TYPE.** 0x0e = F_CTL2 (0x29 for a SCSI command); **0x0f = FC-4 TYPE: 0x08 = FCP (SCSI), 0x01 = extended link service**; 0x10 = F_CTL0 (0x08); 0x11 = F_CTL1 | `fill_normal_tcb`; established for the stores at 0x0e (0x29), 0x0f (0x08) and 0x10 (0x08), re-read in the IP27 object; **the normal builder does not store at 0x11**, so F_CTL1's value for a SCSI command is whatever the block held before (unknown), and its name is inferred. The link-service builders (`fill_plogi_tcb`, `fill_adisc_tcb`) store a four-byte big-endian word at 0x10 to 0x13 (PLOGI constant `0x000100f4`): established that the word is written; the field split inside it is inferred |
| 0x13–0x15 | 3 | Sequence ID (0x13) and sequence count (0x14–0x15) | **inferred.** Re-read: `fill_normal_tcb` has no store to 0x13 to 0x15 (an earlier version of this row cited it as established). The only store reaching 0x13 in the builders read is the link-service word above. The names follow the FC frame-header layout, not a store |
| 0x1c | 1 | Loop open / fairness flags: **0x18** when host-unfair is set (open half-duplex), **0x40** otherwise (open half-duplex, arbitrate fair) | `fill_normal_tcb`; established |
| 0x21 | 1 | **TCB control byte — command-type discriminator.** 0x00 = SCSI read / no-data initiator command, **0x01 = unsolicited-receive buffer** (a posted receive TCB, below), **0x02 = SCSI write** (data-out direction bit), **0x0a = send-link-command / receive-link-reply** (every PLOGI / PRLI / ADISC). This is a primary way the sequencer tells a link service / receive buffer from a SCSI command | `fill_normal_tcb`/`fill_unsol_tcb`/`fill_plogi_tcb`; established |
| 0x23 | 1 | Data-descriptor mode: **0x08** = one directly-addressed data buffer, **0x0b** = scatter-gather list, **0x0c** = no data. Set by the mapper, overwriting an earlier value | `fcadp_map` / `fcadp_maplist`; established |
| 0x24 | 8, FC order | FCP_LUN. The driver writes the request's LUN bytes here (first two bytes from the SCSI request) | `fill_normal_tcb`; established that LUN data lands here, inferred for full 8-byte LUN form |
| 0x2c | 4 | FCP_CNTL. Byte at **0x2f** carries the transfer-direction control: **0x02 = read** (data to host), **0x01 = write** (data from host) | `fill_normal_tcb`; established for the 0x2f direction byte, inferred for the rest of FCP_CNTL |
| 0x30 | 16 | FCP_CDB — the SCSI CDB, `bcopy`'d in from the request, length taken from the request's CDB-length field. **Confirmed at 0x30 on IP27/IP30/IP35** | `fill_normal_tcb` `bcopy(dst=tcb+0x30, …)`; established |
| 0x40 | 4, **big-endian** | FCP_DL — the FCP data length, in FC network byte order (`swl`/`swr`) | `fill_normal_tcb`; established |
| 0x44 | 8, LE | **Next-TCB link:** PCI bus address of the next slot in the driver's circular TCB queue (`fc_next_rrtcb` returns a TCB slot, not a data or response buffer). The unsolicited and LIP TCBs carry the same link | `fill_normal_tcb` via `assign_int64`; established for the address, inferred that the chip uses it as a chain link |
| 0x4c | 8, LE | **Data DMA pointer.** For mode 0x08 it is the PCI bus address of the single data buffer; for mode 0x0b it is the PCI bus address of the scatter-gather list | `fcadp_map` / `fcadp_maplist` via `assign_int64`; established |
| 0x54 | 4, LE | **Transfer length** (byte count) for a single buffer (mode 0x08). In list mode (0x0b) the driver writes **zero** here; no entry count exists, and the list is terminated by the end flag in its last descriptor | `fcadp_map` / `fcadp_maplist` (`assign_int32` single, zero-store list); established |
| 0x58 | 8, LE | PCI bus address of the 256-byte FCP response / sense buffer (the driver's per-command sense area) | `fill_normal_tcb` via `assign_int64`; established |
| 0x60 | 4, LE | Data length (copy of the transfer length) | `fill_normal_tcb` via `assign_int32`; established |
| 0x68 | 2, LE | TCB handle, repeated | `fill_normal_tcb` via `assign_int16`; inferred |

The sibling builders produce the link-service frames through the same mechanism:
`fcadp.o:fill_plogi_tcb` (N-port login), `fill_prli_tcb` (process login),
`fill_adisc_tcb`, `fill_abts_tcb` (abort), `fill_lip_tcb`, `fill_unsol_tcb` and
`fill_prim_tcb` (loop primitives). They differ in the FC/FCP framing bytes, not in the
posting or completion path; the link-service framing and the loop-discovery flow are
detailed in the link-service section below (established, B1).

#### Scatter-gather descriptor format

A scatter-gather descriptor is **16 bytes on a 16-byte stride**: an 8-byte
little-endian PCI bus address at +0, a 4-byte little-endian byte count at +8, then
**4 reserved bytes at +12**. The list has a **16-byte stride**
(the earlier "12-byte" reading undercounted the entry). Per entry the driver writes
only the first 12 bytes — the address with `assign_int64` and the count with
`assign_int32` — and does not write the reserved tail in the per-entry loop; the driver then calls the control-block swap routine over the list, but that routine
is an empty stub in the shipped objects, so nothing is reordered and the reserved bytes
come from the zero-initialised backing buffer. The **last descriptor is flagged** by setting the top byte of its
length word (entry byte +11, the most-significant byte of the little-endian count) to
`0x01`; real segment lengths are a page or less, so that high byte is free for the
end-of-list marker. For a single-segment transfer the descriptor is embedded in the
TCB at 0x4c/0x54 (mode 0x08). For a multi-segment transfer, `fcadp.o:fcadp_maplist`
walks the kernel address/length list, translates each segment through the PCI bridge
(`pcibr_dmatrans_addr`), writes the 16-byte descriptors into a separate list buffer,
and points the TCB at that list (mode 0x0b), zeroing the 0x54 word (there is no entry count; the end flag in the last descriptor terminates the list). The stride is the
size of the driver's scatter/gather descriptor (8 + 4 + 4
bytes), confirmed by the per-entry indexing in `fcadp.o:fcadp_maplist`/`fcadp_map`
and by the allocation size. DMA addresses are
real PCI-bus addresses produced by the Bridge DMA path, not raw physical addresses
(established, B1).

#### Posting: producer index and command doorbell

`hwtrans.o:sh_deliver_tcb` posts a built TCB. It reads a **16-bit producer index**
the chip keeps in the host-resident control block (at control-block offset 0x82),
increments it, masks it to 16 bits, writes the new value back to that location, and
writes the **same value to the command doorbell at register 0x2a** as a 16-bit
little-endian store (`outMemWord`). So the doorbell value handed to the chip is the
post-increment producer index, i.e. the count of commands ever posted modulo 2^16;
the chip consumes command blocks from a circular queue up to that index. This is
identical on IP27/IP30/IP35 (established, B1).

#### Done queue and consumer index

`hwutil.o:sh_setup_doneq` lays out the done queue in host memory and resets the
driver's expected pass counters. It initialises the queue entries by writing **0xff
into byte +3 and byte +7 of each 8-byte stride**, which makes each **done-queue entry
4 bytes** (the pass byte is at +3) with the initialisation loop unrolled by two. It
also writes 0xff to, and reads back, the done-queue pass byte at **sequencer
scratch-RAM offset 0x45** (reached through the sequencer-RAM window, not a primary
register — see the queue-setup section for the full mechanism and the exact pass-count
rule) (established, B1).

A done-queue entry, as read by `hwintr.o:sh_backend_isr`, is:

| Offset | Width | Field | Grade |
|---|---|---|---|
| 0x00 | 2, LE | Completed TCB handle (OX_ID) — the same tag written to TCB 0x00 | established |
| 0x02 | 1 | Completion status byte (see the code table below) | established |
| 0x03 | 1 | Pass byte. Initialised to 0xff; the chip writes the ring-lap number (mod 256) and the ISR consumes while it equals the expected value (full rule in the queue-setup section) | established |

The backend ISR pulls the handle out of entry bytes 0–1, stores it where the
completion layer reads it, advances the consumer, and calls `ulm_tcb_complete`
(established, B1).

**Completion status-byte codes** (entry byte 0x02; the sequencer sets them). For a
normal command these are transfer/frame outcomes; a LIP-TCB completion overloads a few
of the same values with loop-init meanings, and a successful LIP instead returns the
negotiated host AL_PA here.

| Code | Meaning (normal command) | Grade |
|---|---|---|
| 0x00 | Success, no error | established |
| 0x01 | Data overrun | established |
| 0x02 | Data underrun (short transfer; residual follows) | established |
| 0x03 | TCB parity error | established |
| 0x04 | Error response — the target returned an FCP_RSP with status/sense (the driver then parses the response buffer) | established |
| 0x05 | Frame received out of order | established |
| 0x06 | Frame-format error | established |
| 0x07 | Count overflow (sequence ID / count / relative offset) | established |
| 0x08 | Frame came back undelivered — target not reachable (the "no device" case) | established |
| 0x09 / 0x0a | Bad start-of-frame / end-of-frame delimiter | established |
| 0x0b | Aborted | established |
| 0x0f | Primitive timed out | established |

For a LIP-TCB completion the same byte instead carries, on failure, 0x05 timeout,
0x06 non-participating, 0x07 hardware error, 0x09 old-port-state, 0x0a unexpected
close; on success it is the loop address the host negotiated (`fcadp.o:fc_lip_complete`,
`hwintr.o:sh_backend_isr`; established, B1).

#### Completion and the FCP response

`fcadp.o:ulm_tcb_complete` takes the completed handle, looks the command block up in
the driver's handle-indexed table (an inactive command is flagged by the low bit of
its table pointer), reads the command type, and dispatches on it. The type codes are
read straight out of the dispatch: **5 → SCSI** (`fc_scsi_complete`), 1 → LIP,
2 → ADISC, 3 → PLOGI, 4 → PRLI, 6 → unsolicited, 7 → ABTS (abort). Each has its own
completion routine (established, B1).

A command that completes cleanly needs none of this: the whole FCP_RSP path runs
**only when the completion status byte is 0x04 (error response)**. In that case
`fcadp.o:fc_scsi_complete` reads the FCP_RSP information unit the chip DMA'd into the
256-byte response/sense buffer (the `bzero(buf, 256)` before reuse fixes the buffer
size). It is a standard FCP_RSP IU:

| Response-buffer offset | Width / order | Field | Grade |
|---|---|---|---|
| 0x0a | 1 | FCP status flags (the FCP_STATUS byte). Bits the driver tests: **0x01 = response-length valid, 0x02 = sense-length valid, 0x04 = residual overrun, 0x08 = residual underrun** (the earlier sheet mislabelled these and invented a "confirm" bit) | established |
| 0x0b | 1 | SCSI status byte (passed up as the command's SCSI status; 0x28 = queue-full is handled specially) | established |
| 0x0c | 4, big-endian | FCP residual byte count. On underrun the driver takes this as the command residual; on overrun it is reported as a CDB/data-length mismatch | established |
| 0x10 | 4 | FCP sense-data length | established |
| 0x14 | 4 | FCP response-data length | established |
| 0x18… | — | Response-info then sense-info payload | established (the completion routine reads the byte at 0x1b; IP27 build `fcadp.o:fc_scsi_complete`, re-read); inferred (that it is the response code, and that the sense data follows the response info, from the standard unit layout) |
| 0x80 | 16 | **Adapter residual-info block.** The chip writes it little-endian and the driver reads it as written (its swap call is an empty stub in the shipped objects), so every field is plain **little-endian**: an 8-byte little-endian bus pointer to the current scatter-gather page at +0, a 3-byte little-endian current-segment residual (low byte first) at +8, and the current scatter-gather element index (high nibble) at +12. `hwutil.o:sh_get_residual_length` walks it plus the remaining scatter-gather entries to compute the untransferred byte count, and **cross-checks it against the FCP_RSP residual**; a mismatch is a hard error. So the FCP_RSP residual is the primary figure and this block is the independent check — not a plain bytes-moved counter. The fields are plain little-endian as listed, with no per-unit byte reversal | established (the 8-byte value at +0x80, three single-byte loads at +0x88 to +0x8a and a byte load at +0x8c in `hwutil.o:sh_get_residual_length`, IP27 build; re-read); inferred (the roles of the pointer and the nibble, from how the routine uses them) |

TCB bookkeeping uses a free list (`fc_get_rrtcb`/`fc_next_rrtcb`), and the driver
guards against "TCB maximum count exceeded" and checksum/parity errors on TCBs
(established, B1). With the TCB layout, the producer/doorbell post, the done-queue entry format
and the FCP response fields above all mapped, the command path is mapped end to end — see the end-of-sheet items for what remains open.

### Interrupt-status register (0x24) and the host status block

The interrupt-status register at **0x24 is 16-bit** and is read whole by
`hwutil.o:sh_interrupt_pending` (`inMemWord`). "An interrupt is pending" is decided by
masking the register with **0xff08** — that is, the whole high byte (bits 8–15) plus
**bit 3** of the low byte count as real interrupt sources; the other low-byte bits are
ignored for the pending test (established, B1).

The chip also mirrors the status into a **two-byte status block in host memory** (the
address the driver hands it as the interrupt-status block, dereferenced in
`hwintr.o:sh_frontend_isr` from the control block's status pointer). The low mirror
byte corresponds to register 0x24 and the high mirror byte to 0x25. The front-end ISR
reads the mirror, accumulates the bits, acts on them, and **clears handled bits by
writing them back to the chip as byte writes to 0x24 and 0x25** (`outMemByte`). Reads
and writes to these registers go through the little-endian address swizzle the MMIO
accessors apply (halfword accesses XOR the address with 2, byte accesses with 3), so
the register file is seen little-endian from the big-endian host (established, B1).

Bits the ISRs actually test (meanings inferred from the branch each guards):

| Register.bit | Mask | What the driver does with it | Grade |
|---|---|---|---|
| 0x24 bit 3 | 0x0008 | **Loop / attention interrupt.** When set, the back-end ISR selects bank 1, reads the loop-state register at 0xa1 and raises loop events (below), plus sync-spindle/sync-clock events from 0xa2 | established |
| 0x25 bit 7 | 0x8000 | PCI error interrupt | established |
| 0x25 bit 6 | 0x4000 | Hardware error interrupt — the ISR reads and latches the error-status register at 0x23 | established |
| 0x25 bit 5 | 0x2000 | Software error interrupt | established |
| 0x25 bit 4 | 0x1000 | **Sequencer / completion interrupt** — this is the done-queue completion bit (**not** 0x25 bit 2, the completion-reporting-counter interrupt, which the driver does not rely on) | established |
| 0x25 bit 0 | 0x0100 | **Sequencer-ready-for-LIP ("LIP READY")** — the chip raises it when it has run loop initialisation far enough to accept the host's LIP TCB. The back-end ISR then suspends the sequencer and posts the LIP TCB (see the loop bring-up handshake). The chip must raise this after the driver requests a LIP, or loop init times out | established |

**What actually gates the completion drain.** The front-end ISR does **not** gate the
done-queue drain on any status bit: it scans the done-queue pass bytes directly on
every interrupt (the driver deliberately avoids waiting for the completion bit, which
the hardware does not always post). When it finds entries it sets the sequencer /
completion bit (0x25 bit 4) in software and drains them. The chip posts 0x25
bit 4 and raises the interrupt when it writes a completion, but the driver harvests
the completion from the pass byte regardless. **0x24 bit 3 is a separate thing** — the
loop/attention interrupt, for link events, not completions (established, B1).

**Loop up / down / error, corrected.** The loop state is not read from the interrupt
high byte; it is decoded from the loop-state register at **0xa1** after a 0x24 bit-3
loop/attention interrupt: bit `0x80` = LIP received, bit `0x40` = bypass received (loop
**down** / port bypassed), bit `0x20` = enable received (loop **up** / on loop). The
back-end ISR passes these up as events `0x01` (LIP), `0x03` (bypass/loop-down) and
`0x04` (on-loop/loop-up). The event codes `0x2a`, `0x2b` and `0x05` the prior pass read
as "loop up / down / error" are in fact **sync-spindle (0x2a)**, **sync-clock (0x2b)**
and **sequencer-ready-for-a-LIP-TCB (0x05)**; confirmed against the binary's
immediates and the strings "Spindle Sync" and "Clock Sync" in `hwintr.o`. Error notifications are a separate block of event
codes (parity, PCI abort, loss-of-signal and loss-of-sync, SERDES fault) raised from
the 0x25 error bits and from the link/SERDES status at 0xe1/0xeb; the back-end ISR
pauses the sequencer and reloads the mainline microcode on the recoverable ones (established, B1).

Register **0x23** is the error-status register (parity / illegal-opcode flags) the ISR
latches on a hardware-error interrupt; the `0x11` written to **0x2c** in the back-end
path is a bank select (bank 1 for the loop registers), not a reset; and **0x45** is the
done-queue pass byte in the sequencer scratch RAM, reached through the sequencer-memory
window, not a primary register. The driver's own `intr_state` software field takes the
values 0 (clear), 2 (loss of signal), 3 (reset-retry) and 4 (fatal) while handling these
events; that is driver state, not a hardware register (established, B1).

### Link-service and loop-discovery path (what finds the disks)

A SCSI round trip only reaches a disk once the loop has been initialised and each
target logged in. This section pins that path — the blocker set that stops IRIX from
finding its disks.

#### Telling a link service from a SCSI command

The outbound TCB does **not** carry the 1–7 numeric type code seen on completion
(5 = SCSI, 1 = LIP, 2 = ADISC, 3 = PLOGI, 4 = PRLI, 6 = unsolicited, 7 = ABTS). That
code is **driver software bookkeeping**: the driver keeps a per-command record indexed
by the handle (OX_ID), stamps it with the type when it issues the command, and reads it
back on completion by looking the returned handle up in its own table — the chip never
returns a type code. What the sequencer itself sees in the TCB is:

- the **control byte at 0x21**: `0x00`/`0x02` for a SCSI read/write initiator command,
  `0x0a` ("send link command, receive link reply") for every PLOGI / PRLI / ADISC;
- the **FC-4 TYPE at 0x0f**: `0x08` (FCP) for SCSI, `0x01` (extended link service) for
  the logins;
- the **R_CTL byte at 0x07**: `0x01` (SCSI command; a chip encoding, the wire value of FCP_CMND is 0x06) vs `0x22` (unsolicited control / ELS
  request); the expected reply frame is set up at TCB **0x26** with R_CTL `0x23`.

PLOGI, PRLI and ADISC build **identical TCB framing** (R_CTL 0x22, TYPE 0x01, control
0x0a); they differ only in the **ELS command code in the first payload byte** (written
big-endian in the top byte of the first word): **PLOGI = 0x03, PRLI = 0x20,
ADISC = 0x52**. The payload is pointed to by the data pointer at 0x4c with its length at
0x54, and the driver sets up an expected-reply frame header at 0x26 (target AL_PA,
R_CTL 0x23, TYPE 0x01, the same OX_ID) so the chip matches the returning accept. Each
expects back an ELS accept frame DMA'd into the response buffer: PLOGI returns the
target's service parameters and its port/node names (its WWN); PRLI returns the FCP
service parameters that confirm the target speaks FCP; ADISC returns the target's hard
address and port ID (used to detect a target that moved). `fcadp.o:fill_abts_tcb` is a
print-only stub in the shipped driver: an abort request reaches the TCB dispatch but
the builder fills nothing (established, B1).

#### Loop bring-up handshake (before the LIP map)

Loop initialisation is a handshake. The driver's attempt looks like this:

- **It posts three unsolicited-receive TCBs through the normal doorbell** (handles
  1, 2, 3). These are built by `fcadp.o:fill_unsol_tcb` with **control byte 0x21 = 1** and
  every FC-header field zero; the three 8-byte little-endian addresses are the receive
  buffer at 0x24, the next-reply-TCB link at 0x44 and the status/header buffer at 0x58,
  and the handle sits at **TCB 0x68** (the OX_ID at 0x00 is left 0). They are **receive
  buffers**, not commands: the chip holds them and only completes one when an unsolicited
  frame actually arrives. The chip completes one only when an unsolicited frame arrives. Completing one with
  handle 0 is read as a completion of the reserved slot-0 (primitive) TCB and produces
  "primitive completed, but not active"; any completion must echo the
  handle from **TCB 0x68**, not from 0x00.
- **It sends the LIP primitive out of band**, not through the doorbell: it writes the
  loop-init request to the PCI config register at **0x4b** (alternating the request/close
  bits each time) and waits. No LIP TCB with destination 0xef is posted yet.
- **The chip must then raise "LIP READY"** — the sequencer-ready-for-LIP interrupt
  (interrupt-status byte 0x25, **bit 0x01**). On that interrupt the back-end ISR suspends
  the sequencer and **posts the actual LIP TCB** (`fcadp.o:perform_lip`, destination 0xef,
  the distinct LIP layout from the loop-discovery section). Until this interrupt arrives
  the driver's loop-wait flag stays set, and after a timeout it prints **"Loop init
  timeout: LIP READY not received"** and retries (three receive TCBs per attempt).

So the chip holds the three control-byte-1 receive TCBs and does not complete handle 0; when the driver requests a LIP by writing config 0x4b, it runs loop init and raises interrupt-status 0x25 bit 0x01 ("LIP READY") so the driver posts the LIP TCB. The LIP TCB then completes with the negotiated AL_PA and the loop-position map, as covered next (established, B1; the receive-TCB layout, the config-0x4b primitive path and the 0x25-bit-0 gate are from the init and completion routines, binary-cross-checked).

#### LIP and loop discovery

The driver runs FC-AL loop initialisation itself (`fcadp.o:perform_lip` →
`fill_lip_tcb`), delivered through the **special-TCB path rather than the normal
doorbell** — that path, not a TCB field, is what marks the request as a LIP: it swaps in
the loop-init microcode and runs it, and the driver tags its own software command record
as a LIP. The hardware LIP TCB uses a distinct layout from a SCSI/login TCB: its frame
header sets the destination loop address to 0xef, R_CTL 0x22, TYPE 0x01 and a
LIP-specific F_CTL2 of 0x38; it carries a selector telling the sequencer the loop
position table lives in **scratch-RAM page 1**; and it **names the loop-map result buffer
in a 64-bit host-address field at LIP-TCB offset 0x38** (this corrects an earlier reading
that put it at the SCSI TCB's 0x58: the LIP TCB has its own layout, given in the next
subsection). The
host's preferred loop address is encoded as a bit position in the AL_PA bitmap from the
tunable `fcadp_hostid` (default 125, B2) or the previously held address. The chip DMAs a
**loop-position map** (up to 132 bytes) into that buffer.

`fcadp.o:fc_lip_complete` reads that map in one of two forms (**in the shipped big-endian
build the driver does not byte-swap the buffer** — the call list of `fc_lip_complete` has no
swap call and byte 0 is loaded directly; so the chip writes the map in logical byte order, inferred from the missing swap):

- **Position list (LIRP):** byte 0 is the device count N, and bytes 1…N are the present
  AL_PAs in loop-position order. Used when the loop reported positions.
- **Presence bitmap (LISA, the fallback when byte 0 is zero):** a 128-bit AL_PA-present
  bitmap begins at map offset 4 (16 bytes); the driver walks the set bits to synthesise
  the same count-prefixed list.

**The host's own AL_PA is not in the discovered-target list.** In the bitmap form the
driver explicitly clears its own loop position (the top bit of the first 64-bit word)
before walking the bitmap, and the position list likewise yields only other ports. The
host's own negotiated address is reported separately as the **completion status byte**,
not as a map entry — so the host's AL_PA appears in the LIP completion status
and the host is left out of the map the chip DMAs. The completion's status byte carries that
negotiated host AL_PA (unless it is one of the LIP error codes), from which the driver
sets its own host loop-id. Each present
AL_PA is converted to a SCSI target id through the fixed FC-AL arbitrated-loop-address
priority table (the AL_PA↔target-id mapping). The syslog "LIRP complete @ …: N devices,
host id H" / "LISA complete @ …" reports the two map forms.

Order of events for discovery: issue the LIP TCB → the chip drives the loop-init
phases and DMAs the position map → it posts a LIP completion (status = negotiated host
AL_PA) → the back-end ISR flags a valid loop address, records it, reloads the mainline
microcode and marks the map valid → the driver walks target ids 0…126, and for each
present target issues **PLOGI then PRLI** (and ADISC as needed) and a LUN-0 INQUIRY to
bring it into the SCSI graph. Loop state during all this is read from the loop-state
register at 0xa1 after a 0x24-bit-3 (attention) interrupt: LIP received `0x80`, bypass
`0x40`, enable/on-loop `0x20`, with the low nibble giving the loop-port state (the
loop-init "open" state is `0x09`). The driver also handles loss-of-signal/sync and
loop-primitive bypass/enable (established, B1). It has no fabric login or fabric-port handling.

SCSI then rides on top: each FC port is a separate "Integral SCSI controller", loop
disks appear as SCSI targets and RAID LUNs as LUNs, exactly as owners report (established, U9).
The generic contract a loop target must satisfy for the driver to log it in and accept
it as a disk is pinned in the next section. Product-specific INQUIRY vendor/product
strings are not a property of this HBA driver.

#### LIP TCB delivery, execution and completion (what the chip must do)

This is what the chip must do after the driver's "ready for LIP TCB" step. Nothing here is mainline command traffic: a LIP
TCB is **not** posted through the new-TCB ring and **not** announced with the producer
doorbell (0x2a). It is loaded straight into the chip's on-chip TCB RAM, the loop
microcode image replaces the mainline image, and the sequencer is started. The driver then
sleeps on a timer and a completion interrupt. All of it is `hwutil.o:sh_loadnrun_lip`
(entered from `hwtrans.o:sh_special_tcb` with the "deliver LIP TCB" function, itself called
by `fcadp.o:perform_lip` from the back-end ISR on the "ready for LIP" event); established, B1 for the
sequence and immediates; the stage names are this sheet's labels.

**LIP TCB layout (128 bytes, as the chip receives it in TCB RAM; established, B1 `fill_lip_tcb`
stores; names are roles).**

| Offset | Size | Value the driver writes | Role |
|---|---|---|---|
| 0x00 | 4 | 132 | Size of the position map to return (a count, not a flag) |
| 0x04 | 1 | `0x11` | Host-block configuration byte (the same value as the bank-1 select; its use by the microcode is unknown) |
| 0x06 | 1 | bit 0 clear | "Resume I/O after the LIP" request; the driver never sets it here |
| 0x07 | 1 | 1 | Scratch page that holds the valid-AL_PA list (step 6) |
| 0x08–0x27 | 32 | frame header | Starts at 0x08 (not 0): X_ID words `ffff ffff` at 0x08–0x0b, destination AL_PA **0xef** at 0x0c, R_CTL **0x22** at 0x0f, delimiter **0x05** at 0x11, F_CTL byte **0x38** at 0x16, TYPE **0x01** at 0x17, sequence-config byte **0x02** at 0x24 |
| 0x2a–0x2b | 2 | 0 | Fabric-address preference (index, mask); not used by the driver |
| 0x2c–0x2d | 2 | (index, mask) or 0 | **Previously held AL_PA**: byte index into the LISA bitmap (`4 + p/8`) and bit mask (`0x80 >> p%8`), with p = 127 − host id; set when the driver already has an id |
| 0x2e–0x2f | 2 | (index, mask) or 0 | **Hard-assigned AL_PA** from the host-id tunable, same encoding; for the default 125, p = 2, so (0x04, 0x20) |
| 0x30–0x37 | 8 | port name | The board's WWN (SEEPROM words 3–6), copied from the driver's state |
| 0x38–0x3f | 8 | host address | **Map buffer** (bus address) |
| 0x44–0x4b | 8 | host address | Address of the next free new-TCB ring entry; the driver rewrites it into scratch 0x1c (the new-TCB pointer) when it reloads the mainline image, so I/O resumes after the LIP |
| 0x4c–0x7f | 52 | 0 | Reserved |

The other bytes are zero. All byte-order statements about the map buffer and TCB are about
host memory as the big-endian CPU reads it; the driver performs no software byte swap on
either (`fc_swapctl` is an empty routine in the shipped build), so any byte-order swap is the
bridge's and the net layout is the same. The fields the driver relies on are the map-buffer
address, the next-ring address (to restore scratch 0x1c, which the mainline image
re-reads), and optionally the AL_PA preference fields.

**Order of the register traffic in `sh_loadnrun_lip` (established, B1; offsets in `hwutil.o` in
parentheses, and `hwtrans.o:sh_special_tcb` for the entry).** The TCB number *N* is the number of the driver's reserved LIP TCB: the first
TCB after the unsolicited receive TCBs, so **N = 4** (TCBs 1–3 are the
receive buffers, TCB 0 the primitive TCB). Mode/bank values below are the 0x2c selects.

1. Config byte `0x4b` (PCI config space) ← `0x00`: releases the sequencer from the
   host's LIP-primitive request (the earlier request wrote 1; see the handshake above). (`0x25a8`).
2. `0x28` ← `0x0a`; `0x29` ← `0xa0` (written with no bank select first; the table above lists
   them under bank 4, and whether they are visible in every bank is unknown) — a host real-time-clock period and its enable (`0x80`), with the
   completion-posting bit `0x20` kept set. By its use it is a roughly 10 ms timer the driver
   polls at 0x25 bit 2 and clears by writing the bit back, to watch for loop failure while
   the sequencer is paused.
3. Pause the sequencer (0x22 ← pause, poll the ack, as everywhere) and write `0x00` to
   scratch page-0 byte `0x47`, the mainline image's link-error status byte (`0x25e8`). The
   loop image keeps the same byte at `0x45`, which the driver does not clear here (unknown — the
   microcode's own use).
4. For each of **six register banks in this order — 0, 2, 1, 5, 4, 3 — select the bank,
   quiesce that block's engine and write the 16-bit TCB pointer at 0x64/0x65 ← N**
   (`0x262c`–`0x2744`). The quiesce writes are: banks 0 and 2, `0x8c` ← 0 (host
   send/receive DMA control off); bank 1, `0xc4` ← 0, `0x6b` ← 0 (address-valid off), then `0xf0` ← 2 (clear the
   send-side frame buffer), `0xb6` ← `0xff`, `0xb7` ← `0xff`; bank 5, `0xc4` ← 0; bank 4,
   `0x8e` ← 0 (all DMA engines off), then `0x99` OR-ed with `0x40` (re-arm the hardware-error
   interrupt enable); bank 3, only the pointer. **These are not the scatter/gather port
   (0x60 / 0x8b) and not the doorbell** — the TCB pointer is written to every block.
5. Copy the 128-byte LIP TCB image to the TCB RAM window: **`N`-th TCB RAM slot, BAR 3
   offsets `0x80`…`0xff`, 128 byte writes** (`0x276c`–`0x2794`). *These bytes are the LIP
   TCB.* The window's slot is the one the 0x64 pointer selects, so the TCB is read
   back from the BAR 3 TCB-data bytes for index *N* (the same storage the config-collection
   size probe and the RAM test use).
6. Select scratch page 1 (0x34 ← 1), write **128 bytes to BAR 3 offsets `0x00`…`0x7f`**
   (`0x27b0`–`0x27e8`): the fixed ascending table of the 127 valid FC-AL AL_PAs
   (`0x00, 0x01, 0x02, 0x04, 0x08, 0x0f, 0x10, 0x17 … 0xe8, 0xef`) with `0x00` appearing
   twice at the front (index 0 and 1); the 128 bytes in `hwutil.o`'s data are
   exactly this sorted set. This is the FC-AL valid-AL_PA list the loop microcode consults
   (the LIP TCB's page selector says "the list is in page 1"). **It supersedes the earlier
   statement that page 1 holds a loop-position table the microcode fills in**: the host
   fills page 1 here; whether the microcode also scribbles on it is unknown. Then 0x34 ← 0
   (page 0).
7. If the loop image is not the one resident (`sh_load_sequencer` type 2): stream it as
   described in "Reset and firmware load" — **822 sixteen-bit words (1644 bytes) plus four
   zero padding words**, versus 1956 words (3912 bytes) for the mainline image — verify,
   `0x00` ← `0x40`. The images are told apart by length (established, B1; the sizes are the
   `.data` sizes of `sh_lip_code` and `sh_mainline_code`).
8. `0x29` ← `0x20`: the real-time timer is switched off again and completion/interrupt
   DMA posting stays armed (`0x2850`).
9. **Re-initialise the done queue (`sh_setup_doneq`)**: every host done-queue entry's
   pass byte ← `0xff`, the driver's consume position ← slot 0, expected pass ← 0, and
   scratch page-0 byte `0x45` ← `0xff` (read back). *This is the signal that the chip's
   done-queue write position and lap counter restart too* (inferred — the driver restarts its
   own at slot 0, pass 0, here and again at the mainline reload, so the chip cannot
   keep counting from where it was and still be consumed; so the chip's write index and lap count must restart at 0 on this write).
10. Bank 1: `0xa0` AND-ed with `0xdf` (the "cannot be loop master until an AL_PA is held" bit
    cleared).
11. **Only if the driver sent a LIP primitive first** (its own "primitive sent" state flag; true
    for every attach-time and retry LIP): scratch page 0 `0x4a` ← `0x42` (arbitrate,
    participating, unfair), `0x4b` ← the primitive's second-word byte (`0x10` =
    initialise, non-participating; `0x50` participating; `0x14`/`0x54` for the reset
    variant), `0x4c` ← the destination AL_PA (0 for the plain LIP). These tell the loop
    microcode which LIP to put on the wire first (`hwlip.o:sh_send_lip_primitive_in_lip`,
    established, B1; the meaning of the individual values is unknown — they are the microcode's own codes).
12. **Start the loop image** (`hwlip.o:sh_start_lip_sequencer`): `0x00` ← `0x40`, then
    - if the primitive was sent first: `0x00` ← **`0x42`** (reset program counter, start at the
      image's entry);
    - otherwise (a LIP seen on the wire during loop init): 16-bit writes of `0x09` then `0x0a`
      to the sequencer address register 0x02 (start at word 10 of the image).

    then unpause (0x22 AND-ed with `~0xc0`) and read 0x22 back. **This unpause starts the
    loop microcode running.**

**What the sequencer does with it, and the completion the driver expects (established for the
driver's expectations, B1; unknown for how the chip computes them).** The loop
microcode performs FC-AL loop initialisation (select master, fabric/previous/hard/soft
AL_PA claim using the three address preferences in the LIP TCB, position map), then:

1. DMA-writes the **loop-position map** (up to 132 bytes; the driver reads 128) to the host
   buffer named in the LIP TCB at offset `0x38`. Layout: see the discovery text above. The
   driver clears the first 20 bytes before the TCB is issued and reads the buffer **without any
   byte reordering**, so memory byte 0 is the position-list count N (zero selects the
   bitmap form), bytes 1…N the AL_PAs in loop order, or in the bitmap form 16 bytes at
   offset 4. Bitmap bit numbering (established, B1: `fc_lip_complete` copies 16 bytes from offset 4, masks the top bit of the first 8, and scans the second 8 then the first, counting target ids up from the low bit of the last byte): count
   bits from the most significant bit of byte 4 as position 0; position *p* stands for target
   id 127 − *p*, i.e. position 1 is id 126 = AL_PA 0x00 and position 127 is id 0 = AL_PA 0xef
   (through the fixed id-to-AL_PA table); position 0 (id 127) is ignored. The host's own AL_PA
   must not be in the list.
2. Writes **one done-queue entry**: the TCB number *N* in the first two bytes
   (little-endian), the **status byte = the host's negotiated AL_PA**, and the pass byte =
   the current lap number (0 on the first entry after step 9). The entry is consumed
   exactly like any other completion. The status is the host's AL_PA — the driver
   prefers the address its tunable names (default id 125, which the driver's fixed id-to-AL_PA table maps to **AL_PA 0x01**; the id is
   converted by the table in the discovery text) but accepts any valid AL_PA; it must not
   equal a target's AL_PA, and must not be one of the LIP error codes
   (`0x05`, `0x06`, `0x07`, `0x09`, `0x0a` — none is a valid AL_PA, so no collision) (established, B1;
   `fcadp.o:fc_lip_complete`, `hwintr.o:sh_backend_isr`).
3. Raises the completion interrupt: **interrupt-status 0x25 bit 4** (sequencer/completion),
   mirrored into the host status block if the status-block DMA is armed (established; see the
   interrupt-status table). Whether the real chip also needs the per-source enable at 0x99
   bit 4 set is unknown: the driver's init value for 0x99 does not have that bit, yet the driver
   treats 0x25 bit 4 as the completion interrupt. Settling test: a published AIC-1160 interrupt-enable table, or a read-back of 0x99 after init on a real board. The line is to be raised for the
   completion regardless. **An interrupt is mandatory here.** During the LIP phase
   the driver has no command in flight, and its 50 Hz missed-interrupt poll
   (`fcadp.o:fc_timeout_check`) only calls the interrupt routine when at least one SCSI/login
   command is outstanding — the LIP TCB is not counted. A done-queue entry without an
   interrupt is never seen and the driver times out (inferred from the poll's gate, the failure shows as
   "LIP TCB not completed").

**What the driver then does on seeing the entry (established, B1).** The back-end ISR notices
tcb number *N* ≠ 0 while loop init is in process, and: if it had sent a LIP primitive
first, **synthesises its own primitive completion** (so no TCB-0
completion is expected, and one that finds no primitive pending produces the "primitive
completed, but not active" notice); records the status byte as the host AL_PA unless it is one
of the LIP error codes; **reloads the mainline image** (`hwutil.o:sh_reload_mainline_firmware`: the `0x28`/`0x29` timer
writes again, pause, **done queue re-initialised a second time (slot 0, lap 0)**, the 8 bytes
from LIP-TCB `0x44` written back to scratch `0x1c`, the empty-queue heads set to `0xff`,
mainline stream-in and `0x00` ← `0x40` then `0x42`, and — when the status was a valid AL_PA —
bank 1 `0xa0` ← `0x5f` and `0x6b` ← 1 so the chip keeps the AL_PA it won); and calls the
completion routine, which reads the map and starts PLOGI/PRLI. The done
queue therefore restarts at slot 0, lap 0 a second time right after the LIP completion; the next
completion (a PLOGI or a receive buffer) lands in slot 0 with pass 0 again.

**What the driver waits for between the LIP start and a reset (the answer to "what is it
waiting on").** Nothing is polled or spun on. At `perform_lip` (and, if not already armed, at
the original primitive request) the driver arms a **single 3-second callout** (300 ticks,
`fcadp.o:perform_lip` `0x3ef4`) and returns. Three things can end the wait:

- *the completion above* — an interrupt followed by the front-end ISR scanning the **host
  done queue** (host memory, found through the done-queue base programmed at scratch 0x08)
  for an entry whose pass byte equals its expected value (0 for the first entry), then
  looking at the host **interrupt-status block** (host memory, mirrored from 0x24/0x25) and,
  only if that shows nothing, doing **one 16-bit PIO read of 0x24**  — the fall-back read when no work is found (established, B1; `hwintr.o:sh_frontend_isr`);
- *another ready-for-LIP, loop-failure or error interrupt* handled as usual;
- *the callout firing.* With the LIP TCB issued the message is "Loop init timeout: LIP TCB
  not completed"; if the TCB had not been issued yet it is "…LIP READY not received".
  The driver then **resets the chip** (pause, then 0x22 ← `0x43`), reinitialises it completely (RAM test, queue setup, microcode, SEEPROM-derived
  parameters) and re-sends a plain LIP; every sixth try it sends the reset-all variant. It
  gives up after **15 attempts when no SCSI command is waiting (60 if one is, 2 if the last
  failure was loss of signal)**, marks the port off line and fails queued commands — the
  "giving up [15]" message (established, B1; the 15, 60, 2 and six-try constants are compare immediates in `fcadp.o:fc_lip_error`; `fcadp.o:fc_lip_error`, `fc_lip_timeout`).

**Corrections to earlier text.** (0) Interrupt-status 0x25 bit 2, listed above as
"host-completion", is the **host real-time-clock expiry** (step 2); it is not a completion
source. (b) The driver's own
timer covers *both* the READY interrupt and the TCB completion from the first LIP request, so
the chip has 3 s in total, not 3 s per phase. (c) The status block mirror is only an
optimisation: the driver still works through the 0x24 PIO read without it.

#### Registers touched around a LIP, decoded bank by bank

These are the registers written around a LIP. Almost none of them is the LIP TCB:
the LIP TCB is the BAR 3 byte copy above. The bank-1 and bank-3 writes at `0xea`, `0xeb`,
`0xba`, `0xc4`, `0xc8`, `0xa4`, `0xd2` and `0xd3` are the **chip re-initialisation that follows
every loop-init timeout** (the reset to 0x22 = `0x43`, then the full bring-up again:
`hwconfig.o:sh_initialize` → `sh_init_hardware` at `0x10a0`–`0x1164` and `sh_initialize` at
`0xc44`–`0xdfc`), and the same registers are written on the first attach. The bank selects are
the 0x2c values (0x11 = bank 1 … 0x33 = bank 3). Grade: established for offsets, values and order
(binary); roles are established where the driver reads them back or branches on them and inferred where only
the register's use in the loop-init sequence suggests the role.

| Bank | Reg | Written / read by the driver | Role |
|---|---|---|---|
| 1 | 0xa0 | init: `0x4d` (request enable, participating) when the driver holds an AL_PA, else `0x0d`; LIP load: AND `0xdf`; after LIP: `0x5f`; loop-failure path: OR `0x80` | Loop-port-state-machine command. Bit `0x80` reset the state machine, `0x40` "I participate (hold an AL_PA)", `0x20` "loop master", low five bits the request (`0x0d` enable, `0x10` initialise, `0x1f` non-active). inferred |
| 1 | 0xa1 | read in the attention ISR | LPSM status 1 (LIP/bypass/enable received; low nibble the state, `0x09` = open-init). Already described above. established |
| 1 | 0xa4 | init: the driver's loop-init timeout setting, `0x60` | Loop-init watchdog; the time unit is not established (unknown — a chip databook or a timed hardware run would settle it). inferred |
| 1 | 0xc4 | init `0x08`; later AND `~0x08` (the end of `sh_initialize`); LIP load `0x00` (banks 1 and 5) | Send-frame-control command byte. Bit `0x08` = hand the loop-port state machine to the host (set until the link is brought up, then cleared), `0x20` repeat frame. inferred |
| 1 | 0xc8 | init `0x00` | Count of free receive buffers the send side may advertise. inferred |
| 1 | 0xd2 | init `0x00` | Arbitrated-loop latency timer (disabled; why the driver leaves it off is unknown). inferred |
| 1 | 0xd3 | init `0x00` | Acknowledge wait time (class 1/2 only). inferred |
| 1 | 0x68–0x6b, 0x6c–0x6f | 0x68–0x6a = the board's AL_PA (`0xef 00 00` before a real one is known, else the driver's chosen address) and 0x6b ← 1 "valid"; 0x6c–0x6f (second address) ← 0 | Own source address, A and B. 0x6b ← 0 at LIP load; ← 1 again after a good LIP. established |
| 1 | 0xd0 | init `0x80` (continuous idles); only on the loop-failure recovery path the driver writes `0x80 + 0x28` (LIP F7,F7) or `0x80 + 0x2a` (LIP F7,AL_PS) | Ordered-set transmit control. established |
| 1 | 0xea | init sequence (below) ending `0x0a`, then OR `0x20` | **SERDES control.** `0x20` fault-interrupt enable, `0x10` lock-not-in-use interrupt enable, `0x08` lock to reference clock (low), `0x04` LRC enable, `0x02` sync enable, `0x01` internal loopback. established for the bits it sets and clears (B1); the bit names are this sheet's role labels (inferred) |
| 1 | 0xeb | read twice during init (`&3` each time); read in the error ISR for `0x10` and `0x08` | **SERDES status.** `0x10` fault, `0x08` lock-not-in-use, low 2 bits the media-module sense (above). **Keep 0x10 clear** or the error ISR reports "MIA Fault or Optical Loss of Signal" and resets. established |
| 1 | 0xf0 | `0x02` at LIP load and at mainline reload | Send-side frame buffer control: `0x02` = clear the buffer. inferred |
| 1 | 0xb6, 0xb7 | `0xff`/`0xff` at LIP load; `0x02`/`0x00` after (the mainline restart) | Sequencer-config bytes 0 and 2. `0x02` in 0xb6 = "disable full-duplex" (reason for the setting unknown). inferred |
| 3 | 0xe0 | read in the loop-failure check; `0x08` written back to clear | Receive-frame-control status A; `0x08` = link error latched. established |
| 3 | 0xe1 | `0x20` then `0x40` after the SERDES sequence; read in the error ISR (`0x01` loss of signal, `0x02` loss of sync), under bank `0x22` rather than `0x33` | Link-error status when read, link control when written: `0x20` link reset, `0x40` link enable. Already in the main table. established |
| 3 | 0xea | init `0x9e` | **Data-frame mask C** — which frame-header events the receive block flags for the sequencer (the value masks off sequence-initiative, end-of-sequence, last, first and context bits). inferred |
| 3 | 0xeb | init `0xc0` | **Data-frame mask D** (reserved bit and the F_CTL offset-present bit masked). inferred |
| 3 | 0xba | init `0xd4` | **Receive-frame-control mode**; `0x01` internal loopback, `0x10` hold, `0x04` clear; init value is the driver's default. inferred |
| 0,2 | 0x8c | `0x00` at LIP load | Host send (bank 2) and host receive (bank 0) DMA control; 0 = off. established |
| 5 | 0xc4 | `0x00` at LIP load and at reload | Send-frame-control command, second copy. established |
| 4 | 0x8e | `0x00` at LIP load | Completion/command DMA control; 0 = engines off. established |
| 4 | 0x99 | OR `0x40` at LIP load and at mainline reload (init value `0xe7`) | Interrupt-posting enables for status byte 1. `0x40` is the hardware-error interrupt, re-armed because the error ISR clears it. established |
| any | 0x64/0x65 | the LIP TCB number *N*, written to every bank in turn | TCB pointer. established |

**SERDES bring-up sequence (bank 1, `sh_initialize`, established):** clear the sync-enable bit if set;
sample 0xeb low two bits as the **voltage-sensing media type**; 0xea ← `0x02`; delay 1 ms;
0xea ← `0x0a`; delay 1 ms; sample 0xeb low two bits as the **current-sensing media type**; then
(bank 3) 0xe1 ← `0x20`, 0xe1 ← `0x40` (reset then enable the link) and (bank 1) 0xea ORed with
`0x20`. The per-board "which sample" choice is SEEPROM word 2 bit 7.

**Reset-side init values (established, B1):** bank 3 0xea = `0x9e`, 0xeb =
`0xc0`, 0xba = `0xd4`; bank 1 0xc8 = 0, 0xc4 = `0x08`, 0xa4 = `0x60`, 0x6d–0x6f = 0, 0xd3 = 0,
0xd2 = 0 — written in that order (`hwconfig.o:0x10a0`–`0x115c`).

#### Reset and scratch-RAM layout

A chip reset (host-control register 0x22 written `0x43`; error recovery only, never on attach) returns the sequencer, register
banks and internal state to power-on: it clears the loaded microcode, the sequencer
scratch variables and the interrupt enables, so after a reset the driver reloads the
microcode and reprogrammes the queue bases, status-block address and interrupt masks
(the full init sequence). The sequencer scratch RAM is paged: the driver selects a
**4-page** scratch layout (128 bytes per page) through the bank-4 size-select register
at 0x62, and the RAM test exercises pages 0–2 while **page 3 is reserved** (left for
firmware/BIOS expansion). Page 0 holds the queue-control variables (the ring bases,
done-queue pass byte and size described in the queue-setup section, all in its lower
half); **page 1 holds the valid-AL_PA list** the host loads for loop initialisation (the LIP
TCB points the sequencer at page 1 for it). The exact contents of the upper half of
page 0 and of page 2 are not all enumerated (**partly unknown**) (established, B1).

### What a loop target must present (general FC-AL target contract)

This is the HBA-side contract: what any Fibre Channel loop disk must return so the
driver logs it in and enumerates it as a SCSI disk. It is a property of the HBA driver,
true for any FC target, not of a particular drive. For a link-service TCB the chip DMAs
the reply frame into the buffer addressed by **TCB offset 0x58**, so the accept payloads
below land there (the outbound request payload sits at the buffer addressed by TCB
0x4c). An accept that fails a check is retried (PLOGI, up to two retries) or fails the
target with a hard error.

#### PLOGI accept (port login)

`fcadp.o:fc_plogi_complete` requires a good completion status and the first 32-bit word
of the reply to be a **link-service accept (0x02 in its top byte)**; a reject carries
0x01 in that byte, and the driver logs the reject reason code and explanation from reply
bytes +5 and +6. The accept is a 116-byte port-login payload:

| Reply offset | Bytes | Field | Grade |
|---|---|---|---|
| 0x00 | 4 | Link-service code — **0x02 (accept)** in the top byte; the driver gates login on this | established (`fcadp.o:fc_plogi_complete`, IP27 build, re-read: an unaligned word load of bytes 0 to 3, bytes +5 and +6 logged on reject, and a 0x74-byte copy of the whole reply) |
| 0x04 | 16 | Common service parameters: FC-PH version, buffer-to-buffer credit, common features, receive-data field size, max concurrent sequences, relative offset, error-detect timeout | inferred (the standard login-payload shape: the driver copies the 116 bytes whole and reads only the code word and bytes +5 and +6 on a reject, so it never reads this field) |
| 0x14 | 8 | **Port-name WWN** of the target | inferred (the standard login-payload shape: the driver copies the 116 bytes whole and reads only the code word and bytes +5 and +6 on a reject, so it never reads this field) |
| 0x1c | 8 | **Node-name WWN** of the target | inferred (the standard login-payload shape: the driver copies the 116 bytes whole and reads only the code word and bytes +5 and +6 on a reject, so it never reads this field) |
| 0x24 | 16 | Class-1 service parameters | inferred (the standard login-payload shape: the driver copies the 116 bytes whole and reads only the code word and bytes +5 and +6 on a reject, so it never reads this field) |
| 0x34 | 16 | Class-2 service parameters | inferred (the standard login-payload shape: the driver copies the 116 bytes whole and reads only the code word and bytes +5 and +6 on a reject, so it never reads this field) |
| 0x44 | 16 | Class-3 service parameters | inferred (the standard login-payload shape: the driver copies the 116 bytes whole and reads only the code word and bytes +5 and +6 on a reject, so it never reads this field) |
| 0x54 | 16 | Reserved | inferred (the standard login-payload shape: the driver copies the 116 bytes whole and reads only the code word and bytes +5 and +6 on a reject, so it never reads this field) |
| 0x64 | 16 | Vendor version | inferred (the standard login-payload shape: the driver copies the 116 bytes whole and reads only the code word and bytes +5 and +6 on a reject, so it never reads this field) |

For login to succeed the driver needs only the accept code and a good status; it stores
the whole payload (including the two WWNs) for later use but does **not** validate the
service parameters or WWNs at login time. The accept must carry the accept code; a real target also returns well-formed service
parameters and its WWNs, with the class-3 service parameters marked valid.

#### PRLI accept (process login — the FCP capability check)

`fcadp.o:fc_prli_complete` is stricter: it requires a good status, a **process-login
accept (code byte 0x02)** (0x01 = reject, logged with reason/explanation), **and** the
single FCP service-parameter byte at **reply offset 0x13 to equal 0x12** — the
target-function bit (0x10) plus the read-transfer-ready-disabled bit (0x02). The host
sent 0x22 (initiator function 0x20 + the same transfer-ready bit) and demands 0x12 back;
any other value is rejected as "incorrect service parameters" and the target fails. This
is what makes the target an FCP **disk** rather than just a logged-in port. The accept is
a 20-byte process-login payload:

| Reply offset | Bytes | Field | Grade |
|---|---|---|---|
| 0x00 | 1 | Link-service code — **0x02 (accept)**; the driver gates on this | established (the first byte of the reply is loaded and tested in `fc_prli_complete`, re-read; the 20-byte copy of the whole reply is also seen) |
| 0x01 | 1 | Page length | inferred (the standard process-login page shape: the driver copies 20 bytes whole and reads only the code byte, the byte at 0x13, and bytes +5 and +6 on a reject) |
| 0x02 | 2 | Payload length | inferred (the standard process-login page shape: the driver copies 20 bytes whole and reads only the code byte, the byte at 0x13, and bytes +5 and +6 on a reject) |
| 0x04 | 1 | Type code — **0x08 (FCP)** | inferred (the standard process-login page shape: the driver copies 20 bytes whole and reads only the code byte, the byte at 0x13, and bytes +5 and +6 on a reject) |
| 0x05 | 1 | Type-code extension | inferred (the standard process-login page shape: the driver copies 20 bytes whole and reads only the code byte, the byte at 0x13, and bytes +5 and +6 on a reject) |
| 0x06 | 2 | Flags: originator/responder process valid, established image pair, response code | inferred (the standard process-login page shape: the driver copies 20 bytes whole and reads only the code byte, the byte at 0x13, and bytes +5 and +6 on a reject) |
| 0x08 | 4 | Originator process associator | inferred (the standard process-login page shape: the driver copies 20 bytes whole and reads only the code byte, the byte at 0x13, and bytes +5 and +6 on a reject) |
| 0x0c | 4 | Responder process associator | inferred (the standard process-login page shape: the driver copies 20 bytes whole and reads only the code byte, the byte at 0x13, and bytes +5 and +6 on a reject) |
| 0x10 | 3 | Reserved | inferred (the standard process-login page shape: the driver copies 20 bytes whole and reads only the code byte, the byte at 0x13, and bytes +5 and +6 on a reject) |
| 0x13 | 1 | **FCP service-parameter byte — must be 0x12** (target function 0x10 + read-transfer-ready-disabled 0x02) | established (`fcadp.o:fc_prli_complete`, IP27 build, re-read: a byte load at +0x13 compared with 0x12; the meanings of the 0x10 and 0x02 bits are inferred) |

#### ADISC accept (address discovery)

The driver issues ADISC but its completion handler `fcadp.o:fc_adisc_complete` is a stub
in the shipped driver — it does not parse the reply, so the ADISC accept content gates nothing. The ADISC payload nominally carries
the target's hard address, port and node WWNs and N_Port ID; none of it is checked here
(established, B1).

#### LUN-0 INQUIRY (accepting the target as a disk)

Once logged in, `fcadp.o:fcadpinfo` issues a standard 6-byte INQUIRY (opcode 0x12,
no vital-product-data, page 0) to LUN 0 and reads the standard inquiry data. The target
must:

- complete the command with good transport status **and SCSI status GOOD (0x00)**; and
- return an inquiry **byte 0** that is not a "device not present" peripheral qualifier.
  The driver checks `byte0 & 0xC0`: if it is 0x40 (peripheral qualifier 2 or 3 — the LUN
  type is known but no device is connected) and the LUN is not a failover candidate, the
  LUN is treated as not valid and skipped. A normal disk returns **byte 0 = 0x00**:
  device type 0x00 (direct-access block device) with peripheral qualifier 0 (connected).

The `fcadp` driver itself inspects only byte 0 here; it hands the full inquiry data to
the generic IRIX SCSI mid-layer, which reads the response-data format, additional-length
and the vendor / product / revision strings. No vital-product-data pages or unit serial
number are read at this stage. Any vendor/product string matching is done by upper-layer tools, not by this HBA driver. After LUN 0 the driver
enumerates the remaining LUNs. The AL_PA a target answers at must be one of the entries
in the standard FC-AL arbitrated-loop-address priority table (target id 0 maps to the
highest-priority AL_PA, descending); the driver converts between AL_PA and SCSI target id
through that fixed table (established, B1; binary-confirmed accept codes 0x02 and the 0x12 service
byte, INQUIRY opcode 0x12).

### Settled and open items

| Item | Status |
|---|---|
| PCI vendor/device, BAR/PIO windows, bridge/DMA/interrupt path | established |
| Primary register offsets and bit-level semantics for pause (0x22=0x40 on attach; reset 0x22=0x43 only on error recovery), bank select (0x2c), sequencer load, doorbell (0x2a), interrupt status (0x24/0x25) and enable (0x22 bit 0x04), SEEPROM | established |
| BAR type: BAR 0 and BAR 3 are **I/O-space** BARs (not memory) by inference; the driver enables command register 0x55 (I/O + master, never memory-space 0x02, established); config 0x40 bit 0x04 arms 64-bit DMA | established for the writes, inferred for the BAR type |
| Config-collection gates (bank-4 0x63 link-speed must read 0xbe/0x2e/0xfe/0x6e, else "error -2 in getting config"; then TCB-count probe echoes 0x66dd55aa through BAR 3) | established |
| Init RAM test (`sh_init_1160_ram`) covers scratch pages (BAR 3), per-bank cells under all 8 banks, TCB data (BAR 3), **scatter/gather RAM at bank-2 register 0x60** (rewind 0x8b, index 0x64), global cells 0x38, command buffer bank-4 0x20/0x9e | established |
| SEEPROM word 0 low nibble must read 0xF (else reprogram path); WWN at words 3–6 must be non-zero / not all-ones / not the unprogrammed signature | established |
| Loop bring-up handshake: three control-byte-1 receive TCBs (handle at 0x68) held not auto-completed; LIP primitive sent via config 0x4b; chip must raise interrupt-status 0x25 bit 0x01 ("LIP READY") to make the driver post the LIP TCB | established |
| Window roles: BAR 0 = primary registers, BAR 3 = sequencer RAM (scratch/TCB/SG RAM), config space = PCI config | established |
| Queue and status-block setup: ring base addresses in sequencer scratch (new-TCB 0x1c, done-queue 0x08, size 0x48, pass byte 0x45), status block at 0x70–0x77, completion arming at 0x29 bit 0x20 | established |
| SEEPROM access (command controller at 0x6a/0x6b/0x68/0x69) and layout (control word 0, media sense 2, WWN words 3–6; host-id is a tunable, not in SEEPROM) | established |
| Remaining bit fields of lightly-used control registers in each bank | partly unknown |
| TCB byte layout (handle, FCP_CMND with CDB at 0x30, FCP_DL at 0x40, next-TCB link at 0x44, data pointer at 0x4c, length at 0x54 for a single buffer only, sense at 0x58); the LIP TCB has its own layout | established (offsets + widths + endianness, IP27/IP30/IP35; byte 0x07 meaning inferred) |
| Scatter-gather descriptor format (16-byte stride: 8-byte PCI address + 4-byte length + 4 reserved; last entry flagged by length top byte = 1, no entry count; single vs list mode at 0x23) | established |
| Producer index and command doorbell (16-bit index at control-block 0x82, doorbell 0x2a) | established |
| Done-queue entry format (4-byte entry: handle, status, pass byte) and the exact pass-count rule (init 0xff; chip writes the ring-lap number mod 256; ISR consumes while pass == expected) | established |
| FCP response fields (SCSI status, validity flags, residual in the 256-byte response buffer) | established |
| Interrupt-status bits: pending mask 0xff08; 0x24 bit 3 = loop/attention; 0x25 bits = PCI/HW/SW/sequencer/ready-for-LIP; loop up/down decoded from the 0xa1 loop-state register (not from the event codes 0x2a/0x2b/0x05, which are sync/ready events) | established |
| FC-header byte roles (OX_ID 0x00, RX_ID 0x02, D_ID/AL_PA 0x04, R_CTL-encoding byte 0x07, delimiter 0x09, F_CTL/TYPE 0x0e–0x11, fairness 0x1c, control 0x21, mode 0x23) and the read/write direction byte at 0x2f | established |
| Link-service discrimination (control 0x0a + TYPE 0x01 + R_CTL 0x22; ELS code PLOGI 0x03 / PRLI 0x20 / ADISC 0x52; 1–7 dispatch is driver software keyed by handle) | established |
| Loop discovery (LIP map: LIRP count-list or LISA 128-bit bitmap at +4; status = negotiated AL_PA; AL_PA→target via the FC-AL priority table) | established |
| Completion status-byte codes (0x00 ok, 0x02 underrun, 0x04 error-response, 0x08 undelivered/no-device, 0x0b aborted, …; LIP overloads 5/6/7/9/0x0a) | established |
| Done-queue completion interrupt bit (0x25 bit 4); drain is by pass-byte scan, not gated on a status bit | established |
| LIP TCB delivery: loaded as 128 bytes into TCB RAM slot *N* (BAR 3 `0x80`…`0xff`) with the TCB pointer (0x64) aimed at every bank, valid-AL_PA list to scratch page 1, loop image (822 words) loaded, started by `0x00` ← `0x42` (primitive sent) or address `0x0a` (not), then unpause | established |
| LIP completion: map (count-then-AL_PAs, or bitmap) to the buffer at LIP-TCB `0x38` in logical byte order, one done-queue entry {*N*, host AL_PA, lap}, 0x25 bit 4 and an interrupt; done queue restarts at slot 0 / lap 0 at the loop start and again at the mainline reload | established for what the driver needs; inferred that the chip restarts its write position on the 0x45 ← `0xff` write |
| Whether the real chip needs 0x99 bit 4 to deliver the completion interrupt (the driver's init value for 0x99 lacks it) | unknown — a hardware run or the chip databook |
| Time unit of the loop-init watchdog (0xa4 = `0x60`) and the meaning of the individual LIP-primitive codes scratch `0x4a`/`0x4b`/`0x4c` carry | unknown. Settled by: the controller's public databook for the watchdog unit and the primitive codes, or a timed loop-init on a real board with the watchdog set to two values; the driver gives only the stored values |
| SEEPROM word 2 value on real optical and copper boards (driver accepts `0x100` or `0x180`) | unknown. Settled by: a dump of the SEEPROM from one real copper board and one real optical board (the driver only reads it) |
| Sequencer microcode semantics (what the downloaded code does on-chip) | out of scope / unknown |
| Fabric login | Not present in the driver; boards are Class 3 / FC-AL only per the owner's guide (established, M1/B1) |
| Whether the -B optical boards use this controller | unknown. Settled by: the PCI vendor and device identifiers from a hinv or PCI listing of an optical -B board; the driver table already lists one identifier, so a board that reports the same pair is the same controller |
| Generic loop-target login contract (PLOGI accept code 0x02; PRLI accept + FCP service byte 0x12 at reply 0x13; ADISC not parsed; INQUIRY byte 0 = 0x00 for a disk, SCSI status GOOD) | established |

The command path is mapped end to end: the PCI identity, window map, reset and
firmware-load handshake, and interrupt wiring are established, and so are the TCB byte
layout, the scatter-gather descriptor format, the producer index and command doorbell,
the done-queue entry format and the FCP response fields (`fill_*_tcb`,
`fcadp_map`/`fcadp_maplist`, `sh_deliver_tcb`, `sh_setup_doneq`, `sh_backend_isr`,
`ulm_tcb_complete`, `fc_scsi_complete`). What remains open is the on-chip sequencer
behaviour (what the downloaded microcode does), the full per-bit decode of the
loop/error interrupt events, and the items marked unknown above.

## Related controllers

The QLogic PCI Fibre Channel controller that IRIX reports as "Fibre Channel QL2200A"
is a different family and is not this board.

## Scope

Establishes the board's identity, composition, PCI front door, chip register map,
reset and firmware-load handshake, and command, loop and login behaviour from binary
RE of the shipped driver. The command and completion path (TCB layout, scatter-gather
descriptors, producer/doorbell post, done-queue entries and the FCP response) is
mapped from the binary. Facts are graded established, inferred or unknown throughout; the remaining unknown items are
listed above.
