# Audio options of the Fuel, Tezro and Octane

Scope: which audio hardware the SGI documents and the IRIX 6.5.30 IP30 and IP35 driver objects tie to the Fuel (IP35 build), the Tezro (IP35 build) and the Octane/Octane2 (IP30 build). Labels as in [AGENTS.md](../../AGENTS.md):
**established**, **inferred**, **unknown**. Document citations are title, number, printed page. "(pdf n)" gives the file page
where the printed page differs. I read the binaries named below; for those drivers this workspace's reading is binary-only.
The DM8 board has its own page: [dm8.md](dm8.md). The per-driver audit (every audio driver in 6.5.30 and 6.5.22, configuration, inventory strings, hinv captures,
the Audigy question) is [drivers.md](drivers.md); where this page disagrees with it, drivers.md is later.

## Audio drivers in the 6.5.30 builds

Read from the object files in `root/<build>/usr/cpu/sysgen/<build>boot/` (symbol tables and the `init` routines' arguments).

| Object | Builds | PCI probe or bus | Hinv text | Established? | Page |
|---|---|---|---|---|---|
| `mad_dd.o` | IP27, IP30, IP35 | PCI `1412:1724` (`mad_init`, IP35 `0x0`) | `version MAD revision %d, number %d` | probe established | [chips/ice1724](../../chips/ice1724/README.md) |
| `rad_dd.o` | IP27, IP30, IP32, IP35 | PCI `10a9:0005` (`rad_init`, IP35 `0x5110`) | `version RAD revision %d.%d, number %d` | probe established | [chips/rad](../../chips/rad/README.md) |
| `emu_dd.o` | IP35 only, 6.5.30 (absent in 6.5.22) | PCI `1102:0004` (`emu_init`, `0x0`) | `version EMU revision %02X, number %d` | probe established | [chips/emu10k2](../../chips/emu10k2/README.md) |
| `usbaudio_dd.o` | IP35 only (not in IP30, IP27, IP32) | USB audio class, no PCI | `USB audio revision %d.%d, number %d` | strings established | this page |
| `a3_dd.o` | IP32 only | MACE audio, not PCI | `version A3 revision %d` | out of scope (O2) | none |

The hinv strings are in `sbin/hinv` (6.5.30, SHA-256 `4f430d6c4da7365641ded906428ba4fa6ad9ee52f420025c9c75043f3841d7e7`,
offsets `0xd690`..`0xd848`). `sndrv.o` in the IP35 build is not audio: its imports are system-controller packet routines.
The IP35 build's drivers are also linked into the IP35 kernel image (it holds the same driver strings), which a reader of the
relocatable objects alone does not see.

## Fuel (IP35 build)

The Fuel's hardware guide lists no onboard audio in its system-board features (007-4480-001, p. 28 (pdf 48), "system board
features": two serial, parallel, PS/2, Ethernet, SCSI, two USB-A, four PCI slots). **Established** as SGI's statement. The base
machine therefore has no audio device of its own; every audio device below is an option.

| Option | Evidence | Chips and bus | Grade |
|---|---|---|---|
| DMediaPro DM8 PCI audio | Fuel guide pp. 39 and 42 list a "Digital Audio I/O board" without a product name. A Fuel owner's hinv in a Usenet post (`V1UGh.52430$Da4.30732@newsfe6-gui.ntli.net`) shows `Iris Audio Processor: version MAD revision 1, number 1` and calls it a DM8 | PCI; ICE1724 plus two AKM DACs, see [dm8.md](dm8.md) | Fuel use: 13 of 36 published Fuel hinv captures show MAD revision 1 (drivers.md); SGI support statement: none. The SGI DM8 note (007-4077-001, p. 1) does not list the Fuel among tested hosts. Board identity: see dm8.md |
| SGI Fuel USB Digital Audio Converter | 007-4530-001 (2002), pp. 1 to 3: a USB-A converter with a 3.5 mm output for powered speakers; needs IRIX 6.5.16, or patches 4579/4580 and 4583 on 6.5.15 | USB audio class; the IRIX class driver `usbaudio_dd.o` | established as a product; the chip inside is **unknown** |
| PCI Digital Audio Board (RAD-based) | 007-3502-003 (2000) p. 8, Table 1-2: boards 030-1649-001 and 030-1441-001 are "all platforms, except as noted" and no list names the Fuel (the guide predates the Fuel) | PCI `10a9:0005` | Fuel support: **unknown**. |
| DMediaPro DM10 (IEEE 1394 audio/video) | `sbin/hinv` has the text `DMediaPro DM10 FW option: unit %d, revision %d.%d.%d` (`0xc8a8`) and the Fuel hinv post shows `revision 1.1.0` | PCI/FireWire; it carries digital audio over AV/C but is not an audio card | listed for completeness; not read further |

The word "Audio" with "Analog" and "Digital" in the drawings of 007-4480-001 pp. 74 and 76 sits in the removable-media drive
figures with "Host Interface" and "CSM SLA"; it is **inferred** to label the tape drive's indicator lights, and is not treated
as onboard audio.

## Tezro (IP35 build)

Two guides: the tower, 007-4564-001 (2003), and the rackmount, 007-4643-003 (2003 to 2004).

| Option | Evidence | Chips and bus | Grade |
|---|---|---|---|
| Tower: onboard analog audio on the I/O daughtercard | 007-4564-001 p. 32: four RCA audio jacks (two in, two out), a 2.5 mm powered-speaker connector, one 3.5 mm stereo in and one out. Diagnostics test "audio and I/O daughtercard" (p. 117). The rear view labels "Line in and Line out", "MIC", "Audio jacks" (p. 7, pdf 29) | unknown bus and chips. The `emu_dd` guess is **withdrawn**: see [drivers.md](drivers.md); captures show a RAD (`10a9:0005`, revision 13.0) beside the IO9's IOC4 on Tezro, so a RAD at board 13 is the **inferred** onboard part. The Audigy (`emu_dd`) is a PCI option card | onboard audio presence: established; chip: inferred RAD |
| Tower: "8-channel Digital Audio I/O board" | p. 42 (options list) | likely the DM8 | inferred |
| Rackmount: "optional audio" | 007-4643-003 p. 27 block diagram labels "Optional audio"; p. 42 marks "Bus 2, slot 2 (optional audio)"; p. 34 lists "DMediaPro DM8 Audio I/O PCI option" among media boards | PCI DM8, see [dm8.md](dm8.md) | established (SGI statement) |
| Rackmount: DM10 FireWire, DM6 video | p. 34 | PCI | listed for completeness |
| Duo | p. 147 (pdf 167): audio is not supported while the dual-user (Duo) setup is on; disconnect speakers | none | established as an operating limit |

A rackmount audio count: one slot is marked for audio; whether it is also usable for a second card is **unknown**.
The 6.5.30 media has one build directory for this family, `IP35boot`; the linked IP35 kernel carries the board-name strings
`IP34` and `IP53`, so the Fuel and the Tezro boards both run the IP35 build (**inferred** from the strings; which string is
which product is not read here). The `emu_dd` link to the Tezro tower's onboard audio is withdrawn (drivers.md).

## Octane and Octane2 (IP30 build)

| Option | Evidence | Chips and bus | Grade |
|---|---|---|---|
| Onboard audio on the system module | *Octane2 Workstation Owner's Guide*, 007-4207-002: the back view (p. 3, pdf 27) shows microphone, speakers/headphone, speaker power, analog line level, coaxial digital audio in/out, optical digital in and out; text pp. 150 to 155; Table B-24 (p. 244): line level -10 dBV, line out maximum 6.5 dBV +/- 0.5 dB | the IP30 build's `rad_dd.o` and PCI `10a9:0005`: the onboard controller is RAD **inferred** from the build's driver set and the interface strings below | presence: established; chips beyond the controller: unknown |
| RAD driver interface set | `rad_dd.o` strings: Analog In/Out, AES In/Out (AES3-id coaxial), ADAT In/Out (optical), subcode channels, "Video Clock" master clocks, microphone, headphone/speaker | n/a | established (strings); hardware meaning inferred |
| PCI Digital Audio Board (030-0950-001/-002, 030-1649-001, 030-1441-001) in the Octane PCI module | 007-3502-003 pp. 4 to 5 and Table 1-2 (p. 8): O2, Octane, Octane2 supported by 030-0950-001/-002; 030-1649-001 and -1441-001 "all platforms"; hinv line `Iris Audio Processor: version RAD revision 12.0, number 1` (p. 11); ADAT optical in and out, AES-3id breakout, video ref loop | PCI `10a9:0005` | established |
| DA1100 Digital Audio Card | 007-3873-001 (1999): the Windows NT (320/540) version of the same board class; "compatible with all IRIX-based platforms if the required software is installed" per 007-3502-003 Table 1-2 for 030-1441-001 | PCI, RAD | inferred to be the same part family |
| DM8 | `mad_dd.o` is in the IP30 build; the DM8 note does not list the Octane | PCI | unknown |

The Octane's onboard controller identity (PCI `10a9:0005`, revision `0xc0`, board 12) is the same PCI ID the PCI board uses; the board number
is not the same: captures of a RAD in a PCI slot read 13.0 (drivers.md), and the 12.0 in 007-3502-003 is an Octane-class value: `rad_attach` takes the board number from bits 7:4 of the PCI revision and gives board 12 a different PCI
priority ([chips/rad](../../chips/rad/README.md)); **established** as driver behaviour. That the Octane onboard device is
revision `0xc0` is not in the driver and is not evidence here.

## Not audio but found while following the DM thread

- **DM7 (PCI Graphics to Video Out, GVO).** hinv prints `DMediaPro DM7 GVO option: unit %d, revision %d.%d.%d` (`sbin/hinv` `0xe4b0`)
  and the media carries a JTAG vector file named `dm7` (extension of the JTAG vector format) in the system-controller firmware directory (5,611,084 bytes in 6.5.30, SHA-256
  `b736a814947630a2e2b4bb21cd756b236554e97c19f3fa99bda5d63922936c3b`). Its header says `IDTAG DM7 PROMS <1.0>`, "Created using
  Xilinx iMPACT [srvcpack - 5.2.03i]", and its JTAG script verifies the IDCODE `?5036093` (mask `0ffeffff`) before erasing and
  programming a configuration PROM (the Xilinx XC18V series; the sibling system-controller workspace records it as XC18V04,
  not re-derived here). It is the video-out board's configuration image, **not an audio board**; no DM8 image exists in the
  media (no file or string "DM8" in the 6.5.30 tree), which is expected for a part whose configuration is an I2C EEPROM.
- The sibling I/O-board vector file carries `IDTAG IO9 IOC4 0.83`: the I/O board's own PROM, not audio.

## Gaps

- No capture of any DM8, Tezro or Fuel audio hinv in `-vm` form; no board part numbers other than those for the RAD boards.
- The Tezro tower's onboard audio chip is inferred to be a RAD, not read from a document ([open-questions](../open-questions.md)).
- USB audio converter chip unknown (no teardown or USB descriptors).
- The RAD register contract is not read in full here (stub).
