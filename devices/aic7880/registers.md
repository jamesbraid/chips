<!-- generated from devices/aic7880/registers.toml by defs-gen - do not edit, change the source -->

# Adaptec AIC-7880 SCSI controller on the O2: host DMA and SCB register contract

The O2 onboard SCSI controller's host-DMA window, its DMA control and FIFO status registers, the SCB page pointer, byte counter and window, and the SCSI bus signal, transfer-control and PIO registers. Offsets and widths come from the cited Adaptec AIC-7870 data book, applied to the AIC-7880 as its sibling. Every item is inferred until an AIC-7880 book or a measurement settles it.

Unit `aic7880`, macro prefix `AIC7880`.
Default source: Adaptec AIC-7870 Data Book (sibling, applied to AIC-7880).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `scsiseq` | 0x0 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 72-73 (printed 4-3 and 4-4); sibling |
| `sxfrctl0` | 0x1 | rw | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF pp. 74-75 (printed 4-5 and 4-6); sibling |
| `sxfrctl1` | 0x2 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 75-76 (printed 4-6 and 4-7); sibling |
| `scsisig` | 0x3 | rw | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF pp. 77-78 (printed 4-8 and 4.9); sibling |
| `scsirate` | 0x4 | rw | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF pp. 79 and 97; sibling |
| `scsiid` | 0x5 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF p. 80; sibling |
| `scsidatl` | 0x6 | rw | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF p. 81 (printed 4-12); sibling |
| `clrsint1` | 0xc | w | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF pp. 78 and 86; sibling; Linux aic7xxx.reg (db2ddb87143519e20a95aa36c60b36107b736a58) |
| `simode0` | 0x10 | rw | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF p. 91 (printed 4-22); sibling |
| `simode1` | 0x11 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF p. 92 (printed 4-23); sibling |
| `scsibusl` | 0x12 | r | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF p. 93 (printed 4-24); sibling |
| `shaddr` | 0x14 | r | 8 | 4 |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 58-59 and 93 (printed 4-24); sibling |
| `selid` | 0x19 | r | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 59 and 95 (printed 4-26); sibling |
| `sblkctl` | 0x1f | rw | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF pp. 80 and 96-97; sibling |
| `seqctl` | 0x60 | rw | 8 |  |  | 0x90 | inferred | Adaptec AIC-7870 Data Book, PDF p. 98 (printed 4-29); sibling |
| `seqaddr0` | 0x62 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF p. 99 (printed 4-30); sibling |
| `seqaddr1` | 0x63 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF p. 99 (printed 4-30); sibling |
| `accum` | 0x64 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 60 and 100 (printed 4-31); sibling |
| `sindex` | 0x65 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 60 and 100; sibling |
| `dindex` | 0x66 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 60 and 101; sibling |
| `brkaddr0` | 0x67 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 60 and 101; sibling |
| `brkaddr1` | 0x68 | rw | 8 |  |  | 0x80 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 60 and 102 (printed 4-33); sibling |
| `allones` | 0x69 | r | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF p. 102 (printed 4-33); sibling |
| `allzeros` | 0x6a | rw | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF pp. 102-103 (printed 4-33 to 4-34); sibling |
| `flags` | 0x6b | r | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF p. 103 (printed 4-34); sibling |
| `sindir` | 0x6c | r | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF p. 103 (printed 4-34); sibling |
| `dindir` | 0x6d | w | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF p. 104 (printed 4-35); sibling |
| `function1` | 0x6e | rw | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF p. 104 (printed 4-35); sibling |
| `stack` | 0x6f | r | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 60 (printed 3-6) and 105 (printed 4-36); sibling |
| `dspcistatus` | 0x86 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 61 and 136 (printed 4-67); sibling |
| `hcntrl` | 0x87 | rw | 8 |  |  | 0x5 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 61 and 137-138 (printed 4-68 and 4-69); sibling |
| `lhaddr` | 0x88 | rw | 32 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF pp. 139-140 (printed 4-70 to 4-71); sibling |
| `hcnt` | 0x8c | rw | 8 | 3 |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF pp. 139-140 (printed 4-70 to 4-71); sibling |
| `scbptr` | 0x90 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 53, 63-64, 153 and 180; sibling |
| `intstat` | 0x91 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 141-142 (printed 4-72 and 4-73); sibling |
| `clrint` | 0x92 | w | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF pp. 143-144 (printed 4-74 and 4-75); sibling |
| `dfcntrl` | 0x93 | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 139, 145-148 (printed 4-70, 4-76 to 4-79); sibling |
| `dfstatus` | 0x94 | r | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF pp. 145-148 (printed 4-76 to 4-79); sibling |
| `dfdat` | 0x99 | rw | 8 |  |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF p. 63; sibling |
| `scbcnt` | 0x9a | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 63-64, 153-154, 176-177 and 180; sibling |
| `qinfifo` | 0x9b | rw | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF p. 69 (layout), p. 63 (lists it at M98, which the layout does not match); sibling |
| `qincnt` | 0x9c | r | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF pp. 63 and 69; sibling |
| `qoutcnt` | 0x9e | r | 8 |  |  | 0x0 | inferred | Adaptec AIC-7870 Data Book, PDF p. 61; sibling |
| `scbwin` | 0xa0 | rw | 8 | 32 |  | unknown | inferred | Adaptec AIC-7870 Data Book, PDF pp. 63-64, 153-154 and 176-177; sibling |

### Register `scsiseq`

SCSI sequence control. Each bit enables one hardware selection or reselection sequence, or drives SCSI RESET#. A SCSI bus reset clears every bit except SCSIRSTO. The register reads back, so software can set and clear bits without a scratch copy.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `temodeo` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 72-73 (printed 4-3 and 4-4); sibling | 0 makes ENSELO start a selection out; 1 makes it start a reselection out |
| 6 | `enselo` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 72-73 (printed 4-3 and 4-4); sibling | starts a selection (initiator) or reselection (target) sequence; SSTAT0 reports the wait for BSY |
| 5 | `enseli` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 72-73 (printed 4-3 and 4-4); sibling | lets the logic answer a selection by an initiator; sets SSTAT0 SELDI and TARGET |
| 4 | `enrseli` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 72-73 (printed 4-3 and 4-4); sibling | lets the logic answer a reselection by a target; sets SSTAT0 SELDI and clears TARGET |
| 3 | `enautoatno` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 72-73 (printed 4-3 and 4-4); sibling | asserts ATN during a selection out; ATN clears on a one written to CLRATNO or at bus free, and a zero written here does not clear it |
| 2 | `enautoatni` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 72-73 (printed 4-3 and 4-4); sibling | asserts ATN after a reselection; ATN clears as for ENAUTOATNO |
| 1 | `enautoatnp` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 72-73 (printed 4-3 and 4-4); sibling | asserts ATN on a parity error in data in, message in or status in, only with SXFRCTL1 ENSPCHK set; ATN clears as for ENAUTOATNO |
| 0 | `scsirsto` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 72-73 (printed 4-3 and 4-4); sibling | drives SCSI RESET# while set; software clears it with a zero write |

### Register `sxfrctl0`

SCSI transfer control 0, the first of two transfer-control registers. Bits 5 and 0 are not used and read zero. The two self-clearing controls, CLRSTCNT and CLRCHN, read back as zero. The reset value is not stated in the cited pages.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `dfon` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 74-75 (printed 4-5 and 4-6); sibling | digital filtering on for the incoming REQ and ACK signals; the filter period depends on the SCSI transfer rate and on the DFPEXP bit (bit 6) |
| 4 | `clrstcnt` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 74-75 (printed 4-5 and 4-6); sibling | self-clearing; zeroes the SCSI transfer counter and the host address counter, and leaves the host count and the FIFO alone |
| 3 | `spioen` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 74-75 (printed 4-5 and 4-6); sibling | enables automatic PIO on the SCSI bus; it must stay set for the whole PIO transfer, and each transfer is triggered by a SCSIDATL access; clearing it stops further PIO transfers without corrupting valid SCSIDATL data; it may stay set in DMA mode because the SCSI DMA enables override it |
| 1 | `clrchn` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 74-75 (printed 4-5 and 4-6); sibling | self-clearing; clears the SCSI FIFO and the synchronous REQ/ACK offset counter and returns the transfer control logic to its reset state; leaves the SCSI transfer counters unchanged |

### Register `sxfrctl1`

SCSI transfer control 1. Holds the bit-bucket and wrap controls, the parity check enable, the selection timer and its interval, active negation and the termination power enable. Every bit reads zero after reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `bitbucket` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 75-76 (printed 4-6 and 4-7); sibling | initiator mode only: read and discard bus data, or drive zeros on writes, with no stops on FIFO full or empty |
| 6 | `swrapen` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 75-76 (printed 4-6 and 4-7); sibling | lets STCNT wrap past zero so a transfer can exceed 24 bits; SWRAP status is set at each wrap |
| 5 | `enspchk` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 75-76 (printed 4-6 and 4-7); sibling | enables SCSI parity checking in selection, reselection and information transfer; an error sets SSTAT1 SCSIPERR |
| 4:3 | `stimesel` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 75-76 (printed 4-6 and 4-7); sibling | selection time-out interval: 01 is 128 ms, 10 is 64 ms, 11 is 32 ms; the value for 00 is not legible in the source text and stays unknown |
| 2 | `enstimer` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 75-76 (printed 4-6 and 4-7); sibling | enables the hardware selection timer; on expiry SEL is released and SSTAT1 SELTO is set; when clear, SEL stays on until the sequencer clears it |
| 1 | `actnegen` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 75-76 (printed 4-6 and 4-7); sibling | enables active negation on REQ, ACK and the data outputs during information transfer |
| 0 | `stpwen` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 75-76 (printed 4-6 and 4-7); sibling | drives the termination power control output to the level STPWLEVEL selects in DEVCONFIG |

### Register `scsisig`

SCSI control signals. The read side returns the state of the bus control signals. The write side sets the initiator output levels, and its three upper bits are the phase the chip expects on the next REQ pulse. The two sides share one offset and the same bit positions. Every write-side bit is cleared by chip reset, by a SCSI bus reset and by Bus Free. The read side has no reset value in the cited pages. The book's own register description gives the read side as a stale copy of the bus, which reads as the bus state.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `cd` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 77-78 (printed 4-8 and 4.9); sibling | read: CD# on the bus; write: CD# expected on the next REQ in initiator mode |
| 6 | `io` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 77-78 (printed 4-8 and 4.9); sibling | read: I/O# on the bus; write: I/O# expected on the next REQ in initiator mode |
| 5 | `msg` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 77-78 (printed 4-8 and 4.9); sibling | read: MSG# on the bus; write: MSG# expected on the next REQ in initiator mode |
| 4 | `atn` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 77-78 (printed 4-8 and 4.9); sibling | read: ATN# on the bus; write 1 asserts ATN# in initiator mode and write 0 has no effect; ATN# is cleared by writing one to the CLRATNO bit of CLRSINT1, not by a zero here |
| 3 | `sel` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 77-78 (printed 4-8 and 4.9); sibling | read: SEL# on the bus; write 1 asserts SEL#, and write 0 negates it |
| 2 | `bsy` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 77-78 (printed 4-8 and 4.9); sibling | read: BSY# on the bus; write 1 asserts BSY#, and write 0 negates it |
| 1 | `req` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 77-78 (printed 4-8 and 4.9); sibling | read: REQ# on the bus; write: REQO, which has no effect in initiator mode |
| 0 | `ack` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 77-78 (printed 4-8 and 4.9); sibling | read: ACK# on the bus; write: ACKO, which sets ACK# in initiator mode and has no effect in target mode |

### Register `scsirate`

SCSI rate control for DATA. Wide DATA needs this register's WIDEXFER bit and the SBLKCTL SELWIDE bit both set. Bits 6 to 4 are not in the cited pages and the reset value is not stated, so both stay unknown. Read-back is not stated.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `wide` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 79 and 97; sibling | WIDEXFER: sixteen-bit DATA transfer, which also needs SELWIDE set in SBLKCTL |
| 3:0 | `sofs` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 79 and 97; sibling | SOFS: synchronous offset that sets DATA timing |

### Register `scsiid`

Target ID in bits 7:4 and own ID in bits 3:0. Both are four-bit fields, so the sibling addresses IDs 0 to 15 on the wide connection. Chip and PCI reset clear both nibbles. The own ID is the initiator's address during Selection Out. Public drivers commonly write own ID 7 after reset. That is software configuration, not a reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:4 | `tid` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 80; sibling | target ID for Selection Out |
| 3:0 | `oid` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 80; sibling | own ID presented as the initiator's address during Selection Out |

### Register `scsidatl`

SCSI data latch used for automatic and manual PIO, one byte per access. The book says an access drives the SCSI ACK (as initiator) or REQ (as target) active as it happens. The value after chip reset is unknown, and valid data loads after the first REQ and ACK. The high byte in 16-bit mode is a separate register and is not described here.

### Register `clrsint1`

Write-only SCSI interrupt clears. Only CLRATNO, bit 6, is listed here; the bit positions of the other clears (CLRREQINIT, CLRPHASECHG, CLRBUSFREE) are not in the cited extract. Writing one to CLRATNO clears the initiator ATN output set through SCSISIGO. Read-back is not stated.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `clratno` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 78 and 86; sibling; Linux aic7xxx.reg (db2ddb87143519e20a95aa36c60b36107b736a58) | writing one clears ATN# asserted in initiator mode; a zero write has no effect |

### Register `simode0`

SCSI interrupt mask 0. Setting a bit enables the matching SSTAT0 status to assert the SCSI interrupt. Only the bit this unit uses is listed here.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `enspiordy` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 91 (printed 4-22); sibling | enables the SPIORDY status in SSTAT0 to assert the SCSI interrupt |

### Register `simode1`

SCSI interrupt mask 1. Each set bit lets the matching SSTAT1 status assert SCSIINT on IRQA#.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `enseltimo` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 92 (printed 4-23); sibling | SELTO status |
| 6 | `enatntarg` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 92 (printed 4-23); sibling | ATNTARG status |
| 5 | `enscsirst` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 92 (printed 4-23); sibling | SCSI reset status |
| 4 | `enphasemis` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 92 (printed 4-23); sibling | PHASEMIS status |
| 3 | `enbusfree` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 92 (printed 4-23); sibling | bus-free status |
| 2 | `enscsiperr` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 92 (printed 4-23); sibling | latched SCSI parity error status |
| 1 | `enphasechg` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 92 (printed 4-23); sibling | PHASECHG status |
| 0 | `enreqinit` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 92 (printed 4-23); sibling | REQINIT status |

### Register `scsibusl`

SCSI data bus, read directly. The book says the data is gated from the bus to the internal data bus and is not latched in the SCSI module. A read therefore sees the byte on the bus without taking the latch. Nothing in the cited pages says it acknowledges the byte, and the book ties the ACK drive to SCSIDATL accesses, so this read is taken not to acknowledge (inferred from the book's wording, not stated).

### Register `shaddr`

SCSI-side host address, four bytes at 0x14 to 0x17, least significant byte first, so byte n holds address bits 8n+7 to 8n. Loaded when the host address at 0x88 to 0x8b is written and HADDLDSEL is 0. Counts up while STCNT counts down. Saved by the Save Data Pointers message. Zero after reset.

Array of 4 registers, stride 1.

### Register `selid`

Selection and reselection ID. Holds the ID of the device that selected or reselected this controller on the last such phase.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:4 | `selid` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 59 and 95 (printed 4-26); sibling | ID of the selecting or reselecting device, decoded from the bus bits |
| 3 | `onebit` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 59 and 95 (printed 4-26); sibling | set when one bit was on the lower eight data lines during selection; zero when two were |

### Register `sblkctl`

Block control. The SELWIDE bit selects the physical SCSI connection width. Its reset value follows the wide-select pin WIDEPS# sampled at reset, and the O2's strap state is unknown, so the register has no reset value here. Bits 7 and 6 reset to one, bit 5 resets to zero, and bits 4, 2 and 0 read zero. Bit 3 is not described here.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `diagled` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 80 and 96-97; sibling | diagnostic LED control; resets to one |
| 5 | `autoflushdis` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 80 and 96-97; sibling | resets to zero; the function is not in the cited pages |
| 1 | `selwide` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 80 and 96-97; sibling | 1 configures the wide physical connection with the upper data lines in use; 0 leaves them unused |

### Register `seqctl`

Sequencer control. Bit 4 selects the sequencer clock divider, bit 2 requests one single step, bit 1 resets the sequencer RAM address pointer and bit 0 gives the host access to sequencer RAM. Bit 6 disables the host pause request. Bits 7, 5 and 3 (PERRORDIS, FAILDIS and BRKADRINTEN) are in the book but are not described on this unit. The reset value is the one the book's bit table gives in parentheses, not a value read after initialisation.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `pausedis` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 98 (printed 4-29); sibling | set disables the host PAUSE request. SCSI interrupts, illegal opcode interrupts and sequencer RAM parity error interrupts clear it, and host software may not write it |
| 4 | `fastmode` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 98 (printed 4-29); sibling | 1 divides the input clock by four to give the sequencer clock; 0 divides it by five |
| 2 | `step` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 98 (printed 4-29); sibling | 1 runs one instruction and pauses the sequencer again. It stays set until software clears it, and each further single step clears PAUSE in HCNTRL once more |
| 1 | `seqreset` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 98 (printed 4-29); sibling | resets the sequencer RAM address pointer to zero. Self-clearing. The sequencer must be paused before it is set |
| 0 | `loadram` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 98 (printed 4-29); sibling | 1 lets the host read or write sequencer RAM through SEQRAM. Clear it for normal operation, and clear it before switching between reads and writes |

### Register `seqaddr0`

Low eight bits of the sequencer RAM address that executes on the next clock edge. The driver writes it while the sequencer is paused to change where execution resumes, and uses it as the start address when loading sequencer RAM. While loading, the address steps up after every fourth byte. A write to SEQADDR[1:0] clears that byte index. RST# and CHIPRST clear the address to zero.

### Register `seqaddr1`

Bit 0 is bit 8 of the sequencer RAM address, which covers the 512 instruction words. Bits 7 to 1 are reserved in the book, and their read-back is not stated. RST# and CHIPRST clear the register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `addr8` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 99 (printed 4-30); sibling | bit 8 of the sequencer RAM address |

### Register `accum`

Accumulator: temporary holding place for sequencer ALU operations.

### Register `sindex`

Source index: a temporary value, or the address that the sequencer's indirect source port SINDIR reads. The sequencer increments it after each indirect transfer.

### Register `dindex`

Destination index: a temporary value, or the address that the sequencer's indirect destination port DINDIR writes. The sequencer increments it after each indirect transfer.

### Register `brkaddr0`

Low eight bits of the sequencer breakpoint address. Cleared to zero by reset.

### Register `brkaddr1`

Breakpoint disable and the top address bit. Reset to 0x80, which leaves the breakpoint disabled.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `brkdis` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 60 and 102 (printed 4-33); sibling | 1 disables the compare against the program counter |
| 0 | `brkaddr8` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 60 and 102 (printed 4-33); sibling | bit 8 of the break address |

### Register `allones`

Read-only port that returns 0xff to the host and to the sequencer. It is a source for logical and arithmetic functions. The book gives no write function, so a write is outside the published interface and its effect stays unknown.

### Register `allzeros`

Read returns 0x00 and does not return an earlier write. Written as the destination NONE, the byte is discarded and no location changes. Both directions share the offset, so the write side is described here rather than as a separate register.

### Register `flags`

Sequencer flags, read only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `zero` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 103 (printed 4-34); sibling | zero flag |
| 0 | `carry` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 103 (printed 4-34); sibling | carry flag |

### Register `sindir`

Sequencer-only indirect source port. A read returns the byte SINDEX addresses, then SINDEX increments. The host cannot reach this port.

### Register `dindir`

Sequencer-only indirect destination port. A write stores the byte at the address DINDEX holds, then DINDEX increments. The host cannot reach this port.

### Register `function1`

A write stores the byte. Bits 6:4 form an octal value, and a read returns the one-hot byte with bit N set, where N is that value. The book does not define the meaning of bits 7 and 3:0, whether a write keeps them, or the reset value. Those stay unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6:4 | `select` | inferred |  | Adaptec AIC-7870 Data Book, PDF p. 104 (printed 4-35); sibling | octal value; a read returns 1 << select |

### Register `stack`

Read-only return-stack port. Four return entries, newest first, are read one byte at a time: the low byte of an entry, then its high byte, which carries the high address bit. Each high-byte read advances the read pointer to the next entry, so eight byte reads bring the pointer back to its start. The read value after initialisation is zero. The reset values of the individual backing words are not specified in the cited pages. The book gives no write function, so a write is outside the published interface and its effect stays unknown.

### Register `dspcistatus`

Data FIFO threshold select, with a read-only view of six PCI status bits. Power-on reset forces the threshold select to zero. Writes change only bits 7 and 6.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `dfthrsh` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 61 and 136 (printed 4-67); sibling | threshold select for the FIFO start and stop levels that DFSTATUS DFTHRSH reports |
| 5:0 | `pcistatus` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 61 and 136 (printed 4-67); sibling | live, read-only mirror of PCI status bits, named DSDPR (5, data parity reported), DSDPE (4, detected parity error), DSSSE (3, signaled system error), DSRMA (2, received master abort), DSRTA (1, received target abort) and DSSTA (0, signaled target abort); writes have no effect |

### Register `hcntrl`

Host control. RST# or a CHIPRST write sets it to 0x05: the sequencer is requested paused and chip reset is acknowledged. A write that changes PAUSE is not complete until a read returns the written value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `powrdn` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 61 and 137-138 (printed 4-68 and 4-69); sibling | power down: removes the clock and SCSI inputs, suppresses IRQA# and limits device access to host registers; quiesce transfers and pause first |
| 4 | `swint` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 61 and 137-138 (printed 4-68 and 4-69); sibling | software interrupt on IRQA# when INTEN, MASTEREN, a decode enable are set and POWRDN is clear; leaves INTSTAT alone |
| 3 | `hcntrl3` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 61 and 137-138 (printed 4-68 and 4-69); sibling | spare bit with no assignment |
| 2 | `pause` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 61 and 137-138 (printed 4-68 and 4-69); sibling | write: request a latched pause; read: pause acknowledge. Host access to normally sequencer-only registers opens once PAUSEACK is set |
| 1 | `inten` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 61 and 137-138 (printed 4-68 and 4-69); sibling | lets active INTSTAT causes assert IRQA#, when the PCI command MASTEREN bit is also set |
| 0 | `chiprst` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 61 and 137-138 (printed 4-68 and 4-69); sibling | write 1 resets the chip as RST# does, leaving PCI configuration space alone; read: CHIPRSTACK |

### Register `lhaddr`

Host PCI address for the host DMA transfer, four byte registers at 0x88 to 0x8b. Loading it also loads SHADDR. The byte significance across the four bytes is not in the cited extract and stays unknown. Read-back is not stated.

### Register `hcnt`

24-bit host transfer count in three byte registers at 0x8c to 0x8e. A zero count inhibits host PCI requests. Loading a nonzero count clears HDONE. The byte significance across the three bytes is not in the cited extract and stays unknown. Read-back is not stated.

Array of 3 registers, stride 1.

### Register `scbptr`

SCB page select latch. All eight bits read back as written, whether or not external SRAM is selected and however much of it is fitted, so a read-back of 0xff does not show that page 255 exists. Selects one 32-byte page for the SCB window and for SCBCNT-addressed accesses. Reset is zero as the cited book's reset description gives it, not a value read after initialisation.

### Register `intstat`

Interrupt status. The sequencer writes these causes, and the host reads them without pausing the sequencer. SEQINT, SCSIINT and BRKADRINT pause the sequencer at once; CMDCMPLT does not. Bits 3 to 0 clear individually through CLRINT.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:4 | `intcode` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 141-142 (printed 4-72 and 4-73); sibling | code the sequencer stores in the same write that sets SEQINT; valid only while SEQINT is set |
| 3 | `brkadrint` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 141-142 (printed 4-72 and 4-73); sibling | breakpoint match with the breakpoint enabled, or an error: illegal opcode, sequencer RAM parity, data-path parity or memory parity |
| 2 | `scsiint` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 141-142 (printed 4-72 and 4-73); sibling | SCSI reset, parity error, selection time-out or unexpected bus free, when enabled in SIMODE0 or SIMODE1 |
| 1 | `cmdcmplt` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 141-142 (printed 4-72 and 4-73); sibling | a command completed and its SCB ID was posted to the queue-out FIFO; the sequencer keeps running |
| 0 | `seqint` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 141-142 (printed 4-72 and 4-73); sibling | the sequencer needs the driver; it stops at once, with no instruction after the write that sets it |

### Register `clrint`

Clear interrupt, the write side of offset 0x92. A one written to a bit clears the matching INTSTAT cause; the bits self-clear, and the sequencer cannot write this register. The read side at the same offset is the ERROR register, whose causes (PCIERRSTAT, MPARERR, DPARERR, SQPARERR, ILLOPCODE) are described in the prose page.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `clrparerr` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 143-144 (printed 4-74 and 4-75); sibling | clears the SQPARERR, MPARERR and DPARERR error causes and their latched interrupts; the PCI STATUS bits stay set |
| 3 | `clrbrkadrint` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 143-144 (printed 4-74 and 4-75); sibling | clears BRKADRINT; a BRKADRINT cause from a breakpoint or a sequencer error must be cleared at its source first |
| 2 | `clrscsiint` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 143-144 (printed 4-74 and 4-75); sibling | clears SCSIINT |
| 1 | `clrcmdint` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 143-144 (printed 4-74 and 4-75); sibling | clears CMDCMPLT |
| 0 | `clrseqint` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 143-144 (printed 4-74 and 4-75); sibling | clears SEQINT |

### Register `dfcntrl`

Data FIFO control. Bits 5 and 4 enable SCSI and SCSI-block DMA, bit 3 enables host DMA, bit 2 selects the direction, bit 1 flushes the FIFO and bit 0 resets it and self-clears. Cleared by PCI RST# and by the chip reset in HCNTRL. Read-back is not stated. The reset value is the cleared state the chip reset produces, not a value read after initialisation.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `wideodd` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 139, 145-148 (printed 4-70, 4-76 to 4-79); sibling | has no effect except in a wide transfer with an odd byte count; the public Linux driver labels bit 6 WIDEODD too |
| 5 | `scsien` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 139, 145-148 (printed 4-70, 4-76 to 4-79); sibling | enables transfer between the SCSI bus and the SCSI FIFO |
| 4 | `sdmaen` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 139, 145-148 (printed 4-70, 4-76 to 4-79); sibling | enables transfer between the SCSI block and the data FIFO |
| 3 | `hdmaen` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 139, 145-148 (printed 4-70, 4-76 to 4-79); sibling | enables transfer between the data FIFO and PCI memory; clearing it halts host requests and is acknowledged before the registers are reloaded |
| 2 | `direction` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 139, 145-148 (printed 4-70, 4-76 to 4-79); sibling | 1 moves data from memory or the FIFO toward the SCSI block; changing it needs all transfer enables clear and acknowledged |
| 1 | `fifoflush` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 139, 145-148 (printed 4-70, 4-76 to 4-79); sibling | flushes the FIFO |
| 0 | `fiforeset` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 139, 145-148 (printed 4-70, 4-76 to 4-79); sibling | empties valid FIFO state, resets its word pointers and loads its byte offset from the low three bits of LHADDR; self-clearing |

### Register `dfstatus`

Data FIFO status. Reports FIFOEMP, FIFOFULL, FIFOQWDEMP, MREQPEND and HDONE. Only DFTHRSH, bit 2, has a listed position here; the other bit positions are not in the cited extract and stay unknown. MREQPEND is a pending need, not a PCI request in flight.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `dfthrsh` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 145-148 (printed 4-76 to 4-79); sibling | FIFO start threshold status for the level selected by DSPCISTATUS bits 7:6; FIFO status only, it needs neither PCI decode and mastering nor HDMAEN |

### Register `dfdat`

Data FIFO port, one byte per access. A read takes one valid byte from the FIFO and a write supplies one. The book gives no reset value (init xx).

### Register `scbcnt`

SCB byte counter. Bits 6:5 read zero. With SCBAUTO clear the window offset selects the byte and the counter is not used. With SCBAUTO set the counter replaces the window offset, advances once per completed logical SCB byte access and wraps within the 32-byte page. Reset is zero as the cited book's reset description gives it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `scbauto` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 63-64, 153-154, 176-177 and 180; sibling | 1 makes the counter address the SCB window and advance on each completed byte access; 0 leaves the window offset in control |
| 4:0 | `scbofs` | inferred |  | Adaptec AIC-7870 Data Book, PDF pp. 63-64, 153-154, 176-177 and 180; sibling | byte offset within the 32-byte page, used when SCBAUTO is clear and advanced by the counter when it is set |

### Register `qinfifo`

Queue-in FIFO. The host writes SCB IDs and the sequencer removes them. The address follows the SCB device-register layout on PDF p. 69; the register table on PDF p. 63 prints it as 0x98.

### Register `qincnt`

Queue-in count: entries waiting in the queue-in FIFO. Zero when empty.

### Register `qoutcnt`

Queue-out count, read by the host only. Zero when empty.

### Register `scbwin`

SCB window: 32 byte positions of the page that SCBPTR selects. Sequencer accesses are byte wide. Host reads are byte wide. Host writes are byte wide in either SCBAUTO mode, and a full four-byte write is accepted only with SCBAUTO set, filling four successive positions. Host access needs a paused sequencer or the automatic access pause. Byte order of the four data bytes against the CPU is not in the cited extract and stays unknown.

Array of 32 registers, stride 1.
