# Audio drivers in IRIX 6.5.30 and 6.5.22

Scope: every audio driver object, master file, configuration line and inventory string found in the IRIX 6.5.30 and 6.5.22
builds held here, which hardware each drives, which builds carry it, and which SGI product shipped with that hardware. Labels as
in [AGENTS.md](../../AGENTS.md): **established**, **inferred**, **unknown**. I read the driver objects named below as a binary
reader (instruction level, with the toolchain's call and argument summary); for these drivers this page is binary-only. Survey
of the options per machine: [survey.md](survey.md). The DM8 board: [dm8.md](dm8.md).

Builds examined: 6.5.30 (`IP27`, `IP30`, `IP32`, `IP35` object directories, linked kernels `unix.IP27`, `unix.IP30`, `unix.IP35`,
the `IP22` directory holds one object) and 6.5.22 (the same plus a full `IP22` directory, linked kernels for IP27, IP30, IP35 and
the `var/sysgen` configuration trees for IP27, IP30, IP35). The linked IP32 and IP22 kernels and the IP22, IP26, IP28 and IP32
configuration trees are **not held**; the 6.5.30 configuration trees are not held for any build.

## Result in one table

PCI IDs are the arguments of the `pciio_driver_register` call in each driver's `*_init` (vendor, device); the "type" column is the
inventory type the driver registers with class 10 (audio) and the one `hinv` switches on (see below).

| Driver | Chip(s) driven | Probe | Builds (6.5.30 / 6.5.22) | Configured by default | hinv text | Type | Shipped with |
|---|---|---|---|---|---|---|---|
| `rad_dd.o` | SGI RAD audio controller | PCI `10a9:0005` (`rad_init` IP35 `0x5110`, IP30 `0x4e9c`, IP27 `0x506c`, IP32 `0x5074`) | IP27, IP30, IP32, IP35 / same four | IP27, IP30, IP35: yes (6.5.22 `audio.sm`); IP32: unknown (tree not held) | `version RAD revision %d.%d, number %d` | 5 | Octane and Octane2 onboard (rev 12.0), Onyx2 and Origin 2000 MediaIO (7.0), PCI board and IP35 base-I/O audio (13.0): captures below |
| `mad_dd.o` | VIA/IC Ensemble ICE1724 on the DM8 board (M-Audio Revolution 7.1 recipe) | PCI `1412:1724` (`mad_init` `0x0`) | IP27, IP30, IP35 / same three (not IP32) | IP27, IP30, IP35: yes | `version MAD revision %d, number %d` | 7 | DM8 option; Fuel, Tezro, Origin 350, Onyx 350 captures |
| `emu_dd.o` | Creative EMU10K2 (Sound Blaster Audigy family) with an AC'97 codec (SigmaTel STAC97 named in strings) | PCI `1102:0004`, no subsystem check (`emu_init` `0x0`) | IP35 only / **absent** | IP35 6.5.30: linked into `unix.IP35` (established); master and system files not held (inferred yes) | `version EMU revision %02X, number %d` | 8 | Creative Audigy cards on Fuel, Tezro, Origin 300, Origin 350, Onyx 350 (captures); no SGI document names it |
| `usbaudio_dd.o` | any USB audio-class device (class 1, subclass 1 or 2); also a HID handler for the control buttons | USB interface class 1, subclass 1 or 2 (`usb_audio_event_handler` `0x0`) | IP35 only / IP35 only | IP35: yes (6.5.22 `audio.sm`) | `USB audio revision %d.%d, number %d` | 6 | Fuel USB Digital Audio Converter (007-4530-001); Griffin iMic per a Usenet post |
| `a3_dd.o` | MACE audio block and its codec | no PCI: fixed MACE window `0xbf300000` (`a3_probe` `0x0`) | IP32 only / IP32 only | IP32: unknown (tree not held) | `version A3 revision %d` | 4 | O2 (13 of 13 O2 captures) |
| A2 driver (HAL2) | HAL2 audio chip | no object held | IP22 family (not held) | unknown | `version A2 revision %d.%d.%d` | 3 | Indy, Indigo2 (captures) |
| `indigo_dd`, `hdsp` | older Indigo and Hollywood DSP audio | no object held; master files only | unknown | unknown | generic `revision %d` and others | 0, 1, 2 | Indigo, Personal IRIS (captures) |
| `kdsp.a` | shared audio framework all of the above link against | n/a | every build | yes (`audio.sm` line `USE: kdsp`) | n/a | n/a | n/a |

## How `hinv` prints audio (established)

`sbin/hinv` (6.5.30, SHA-256 `4f430d6c4da7365641ded906428ba4fa6ad9ee52f420025c9c75043f3841d7e7`) dispatches on the inventory class
word through a table at `0xc274` (28 entries); class 10 enters the audio block at `0x100034fc`, which indexes a nine-entry table
at `0xd668` by the inventory type. The entries, read in order:

| Type | String (file offset) | Arguments |
|---|---|---|
| 0 | `Iris Audio Processor: revision %d` (`0xd690`) | state |
| 1 | `ViGRA 110 Audio %d, base 0x%06X, revision %d` (`0xd878`) | controller, unit, state |
| 2 | `ViGRA 210 Audio %d, base 0x%06X, revision %d` (`0xd848`) | controller, unit, state |
| 3 | `version A2 revision %d.%d.%d` (`0xd7e8`) | state bits 14:12, 7:4, 3:0; a further line when state bits 31:25 are set (inferred from the mask test, not decoded further) |
| 4 | `version A3 revision %d` (`0xd7b8`) | state |
| 5 | `version RAD revision %d.%d, number %d` (`0xd778`) | state bits 7:4 and 3:0, controller |
| 6 | `USB audio revision %d.%d, number %d` (`0xd738`) | state bits 7:4 and 3:0, controller |
| 7 | `version MAD revision %d, number %d` (`0xd6f8`) | state, controller |
| 8 | `version EMU revision %02X, number %d` (`0xd6b8`) | state (two hex digits), controller |

Each driver calls `device_inventory_add` (or `add_to_inventory` in `a3_dd`) with class 10 and its type: RAD type 5 (`rad_create_subsys`),
MAD type 7, EMU type 8 (`emu_create_subsys`, call at `0x344`), USB type 6 with state `0x10` (`usbaudio_create_subsys`), A3 type 4
(`a3_probe`, call at `0xe4`). The table index equals the type word: **established** from the index arithmetic at `0x10003500` (`sltiu` 9,
`sll` 2, load). The HAL2 revision decode is the same as the public Linux driver's (`sound/mips/hal2.c`, board from bits 14:12, major
chip from bits 7:4, minor from 3:0, Linux master read 2026-11-02), which ties the A2 string to HAL2 (**established** as agreement; the A2 driver itself
is not held). The Linux file's header calls the part "A2 audio system", the same name as the IRIX string.

## Configuration (master files, system files)

6.5.22 `var/sysgen.IP27|IP30|IP35`: `system/audio.sm` contains `NOPROBE: 0`, `USE: kdsp`, then `VECTOR: module=rad_dd` and
`VECTOR: module=mad_dd` (IP27, IP30) or `rad_dd`, `usbaudio_dd`, `mad_dd` (IP35). `master.d/` has `rad_dd`, `mad_dd`,
`usbaudio_dd` (flags `cso`, depends on `kdsp`, and on `usb` for `usbaudio_dd`), plus `a2_dd`, `a3_dd`, `indigo_dd`, `hdsp` and `kdsp`
(`hdsp`'s comment is "Hollywood DSP"; `kdsp`'s says "use instead of hdsp") in every one of the three builds. The master files of the
IP22 and IP32 drivers are therefore present in IP27, IP30 and IP35 trees, but no `audio.sm` there names them, and their objects are
not in those builds: **established** (the master file alone does not configure a driver). `mtune/kdsp` has one tunable,
`kdsp_pro_audio_subcode` (0 consumer S/PDIF, 1 professional AES3, 2 default by hardware). The IP27 `irix.sm` additionally has
`USE: rad1pci` under a "Psitech RAD1" comment: `rad1pci.a` (IP27 only) is **not audio**; its strings carry a Permedia 2 mode table and
tport routines, so it is a graphics-card driver that shares the letters "rad". **Established** as not audio, device not identified.

6.5.30 configuration trees are not held. The kernels are: the symbol table of 6.5.30 `unix.IP35` contains 15 `emu_*` text and data
symbols (`emu_init` `0xc00000000018c894`, `emu_attach` `0xc00000000018c8c4`, `emu_cdevsw`), 8 `usbaudio_*`, 21 `mad_*`, 43 `rad_*`
and about 100 `kdsp_*`; `unix.IP30` and `unix.IP27` contain `rad_*`, `mad_*` and `kdsp_*` and no `emu_*` or `usbaudio_*`. The 6.5.22
`unix.IP35` has `rad_*`, `mad_*`, `usbaudio_*` and `kdsp_*`, no `emu_*`. **Established**: `emu_dd` is linked into the shipped 6.5.30
IP35 kernel and was not in 6.5.22. **Inferred**: the shipped kernel is the default configuration, so `emu_dd` is selected by default
on IP35 in 6.5.30 (the `audio.sm` that would say so is not held). **Established**: the 6.5.30 `dmedia_eoe.sw.audio` package ships
`master.d/emu_dd`, `a2_dd`, `a3_dd`, `indigo_dd`, `hdsp`, `kdsp`, `mad_dd`, `rad_dd`, `usbaudio_dd`, `system/audio.sm` and
`mtune/kdsp` (a file listing printed by `versions` on an IRIX 6.5.30 O2; that machine has no audio driver loaded).

The driver objects differ byte-for-byte between 6.5.22 and 6.5.30 (rebuilds). I re-ran the probe and inventory calls on the 6.5.22
`rad_dd`, `mad_dd`, `usbaudio_dd` and `a3_dd` objects: same PCI IDs, same inventory class and type. The only release-level change in
the audio set is that `emu_dd.o` and its master file appear after 6.5.22. Which release added it is **unknown**: no 6.5.23 to 6.5.29
IP35 object directory is held, and the update guides 007-3897-022 to -030 do not mention audio hardware.

## Per-driver notes

**`emu_dd.o` (IP35, 6.5.30).** SHA-256 `621698b1da9928b6262022021e17d53d4a86b50e3f637ca6c5f8d4b422d817b4`.
- `emu_init` registers vendor `0x1102`, device `0x0004` once (a0 `0x1102`, a1 `0x4`), then `kdsp_idbg_emu_addfuncs`. No other ID, so it
  claims every `1102:0004` function: pci.ids names it "EMU10k2/CA0100/CA0102/CA10200 [Sound Blaster Audigy Series]". **Established.**
- `emu_attach` (`0x30`): `pciio_piotrans_addr` on window space 8, 32 bytes, flag 8192; config byte `0x0d` set to `0xff`; PCI priority 1;
  then `emu_create_subsys`. **Established.**
- `emu_create_subsys` (`0x258`): reads the PCI revision ID with one byte at config offset 8; stores revision plus `0xa0` (`daddiu a3,a3,160`
  at `0x2f0`); registers the character device `emu_subsys`; `device_inventory_add(class 10, type 8, controller -1, unit 0, state = (revision + 0xa0) & 0xff)`;
  initialises the AC'97 mixer (`emu_ac97_write` registers `0x00`, `0x18`, `0x1a`, `0x0e`, `0x1c`, `0x20`). No subsystem vendor or device
  read, so it does not distinguish Audigy boards. **Established.** The `+0xa0` bias is established as code; why it is there is unknown.
- Interfaces named in strings: `AnalogIn`, `AnalogOut`, "Microphone", "Line In", "Line Out", clock generators `CG0`, `CG1`, "CrystalMclk",
  "Internal Clock". No digital, S/PDIF or FireWire interface string. Debug text names a "STAC97 GPIO Register". **Established** (strings);
  the effects processor is programmed through `emu_init_efx` and `emu_wrefx` (not read in full).
- No interrupt allocation or connect call exists in the object (imports are PIO, config, DMA translation, error registration), so completion
  is **inferred** to be by polling or the kdsp timer. **Established** (import list).
- Hinv revision: an EMU line shows revision `A3` or `A4` in 14 captures; with the `+0xa0` bias that is PCI revision 3 or 4, the two silicon
  steppings of the Audigy family (3 for the original, 4 for Audigy 2). **Established** (arithmetic) and **inferred** (the stepping names).

**`rad_dd.o` (IP27, IP30, IP32, IP35, both releases).** `rad_init` registers `10a9:0005`; `rad_create_subsys` reads config `0x08` (4 bytes)
and registers type 5; the hinv revision is board number (bits 7:4) and chip revision (bits 3:0), see [chips/rad](../../chips/rad/README.md).
Captures show board numbers 12 (Octane and Octane2), 7 (Onyx2 and Origin 2000 base I/O) and 13 (below). **Established** (code and captures).

**`mad_dd.o` (IP27, IP30, IP35).** `mad_init` registers `1412:1724`; `mad_create_subsys` reads config byte `0x08` and the half-word at `0x2e`
(sub-device ID, compared with `0x3630`) and registers type 7 with controller -1. See [dm8.md](dm8.md). It is not in the IP32 build: the DM8
note's host list (Onyx4, Origin 350, Onyx 350; IRIX 6.5.21 or later) agrees. **Established.**

**`usbaudio_dd.o` (IP35).** `usbaudio_init` makes two `usb_driver_register` calls (names in `.rodata`): `usb_audio_event_handler` and
`uaudio_hid_handler`. In the first, on probe it requires interface class 1 and subclass 1 (audio control) or 2 (audio streaming); other
subclasses (MIDI streaming is 3) are rejected. `usbaudio_create_subsys` adds type 6 with state `0x10`, which `hinv` prints as revision 1.0.
No vendor or product ID is compared in the probe path I read, so any class-compliant device is claimed. **Established** for the class
check and the state; "any class-compliant device is enough" is **inferred** (one handler read, descriptor parsing not).

**`a3_dd.o` (IP32).** `a3_probe` touches `0xffffffffbf300000` (the K1 alias of physical `0x1f300000`) with 64-bit PIO: reads `+0x0`, writes 1,
delays 1 us, writes 0, writes `0x10000` to `+0x8`, delays 168 us, reads `+0x18`; allocates `0x1728` bytes; `add_to_inventory(10, 4, 0, 0,
...)`; strings show a CRIME vector hookup (`setcrimevector`), codec register accessors (`do_read_codec_reg`, `write_codec_reg`), an MVP
(video) I2C probe and A/V timing tables. **Established** (code). That the codec is an Analog Devices AD1843 is **inferred** from the public Linux
O2 audio driver (`sound/mips/sgio2audio.c`, includes `ad1843.h`, Linux master read 2026-11-02); the IRIX object names the codec only by register routine.

**A2, indigo, hdsp.** No object is held for any (they belong in the IP22 and older object directories, which hold only `kdsp.a` members
`kdsp_di.o`, `kdsp_events.o`, `audutil.o`). `kernel.o` of the 6.5.22 IP22 build refers to `hal2.h` in its debug information and carries no
HAL2 symbols. Everything about the A2 driver beyond the inventory string and the master file is **unknown**; route: an IP22 object directory
from the dmedia audio package, not yet held.

**`kdsp.a` (all builds).** Members `kdsp_di.o`, `kdsp_events.o`, `audutil.o`; the framework every driver above links against (resource,
clock-generator and device tables, `kdsp_add_subsys`). Not read beyond the call interfaces.

**Other audio-adjacent objects.** `nsmidi.o` (all builds, `midi.sm` `USE: nsmidi`): MIDI over serial ports, `midi_*` kernel symbols, not a
chip driver. `sndrv.o` (IP35): system-controller packet routines, not audio. `mvp.o` (IP32): the O2 video board, with audio volume I2C
register names; not an audio driver. `io.a` carries an `audio_intr_pri` tunable. `fire.a` matches "audio" only through a table of
IEEE 1394 vendor names.

## Published hinv captures

`gold-new` of the published hinv corpus: 268 captures, 458 records. The counts are captures (a machine posted several times counts once
per capture id) that show the named line; the denominator is captures of that machine class in the corpus.

| Machine | Captures | RAD | MAD (DM8) | EMU | USB audio | A3 | A2 |
|---|---|---|---|---|---|---|---|
| Fuel | 36 | 0 | 13 (rev 1) | 6 (A3 x4, A4 x2) | 1 (rev 1.0) | 0 | 0 |
| Tezro | 17 | 5 (13.0) | 11 | 2 (A4) | 0 | 0 | 0 |
| Origin 350 | 12 | 3 (13.0) | 1 | 1 (A4) | 0 | 0 | 0 |
| Onyx 350 | 10 | 5 (13.0) | 6 | 1 (A4) | 0 | 0 | 0 |
| Origin 300 | 10 | 0 | 0 | 1 (A4) | 0 | 0 | 0 |
| Onyx 300 | 1 | 0 | 0 | 0 | 1 (1.0) | 0 | 0 |
| Onyx4 | 3 | 2 (13.0) | 0 | 0 | 0 | 0 | 0 |
| Octane / Octane2 | 29 / 3 | 24 / 1 (12.0) | 0 | 0 | 0 | 0 | 0 |
| Onyx2 / Origin 2000 | 22 / 5 | 18 / 4 (7.0, one 13.0) | 0 | 0 | 0 | 0 | 0 |
| O2 | 13 | 1 (13.0) | 0 | 0 | 0 | 13 (rev 0) | 0 |
| Indy / Indigo2 | 16 / 11 | 0 | 0 | 0 | 0 | 0 | 14 (4.1.0) / 10 (1.1.0) |
| Indigo | 8 | 0 | 0 | 0 | 0 | 0 | type-0 line (revision 3 or 10) in 7 |

The EMU captures also show `1102:4001` ("SB Audigy FireWire Port") and `1102:7003` ("SB Audigy Game Port", pci.ids 2026.09.23) at the same
PCI slot as `1102:0004` in every capture that lists adapter IDs (nine captures: Fuel x6, Tezro, Origin 300, Onyx 350). **Established.** That is the
three-function layout of a Creative card with a FireWire port; it is **inferred** to be a retail or OEM Creative Audigy with a FireWire
function. A card with those three functions is not the Audigy LS or SE parts (`7005`).

## The Audigy: which SGI product shipped it

**Answer.** No SGI document held names an Audigy or any Creative part. The hardware exists in the field on exactly the IP35-class machines
that offer PCI audio options: Fuel (6 captures), Tezro (2), Origin 300 (1), Origin 350 (1), Onyx 350 (1). All show the same three PCI
functions on one slot (audio, FireWire, game port), on IRIX 6.5.2x or 6.5.30. The onboard audio of the Tezro tower is **not** the Audigy.

What is established:
1. **Driver**: `emu_dd` claims `1102:0004` only, exists in the IP35 build from after 6.5.22, and in no other build.
2. **Field evidence**: the captures above (count in the table). The Fuel has no onboard audio (007-4480-001 p. 28 system board features, as cited in survey.md), so
   those six Fuel EMU lines are an add-in card.
3. **SGI "basic audio" option**: *Onyx 350 Visualization System User's Guide*, 007-4632-001, p. 8 ("2 PCI audio options (basic or professional)")
   and pp. 73 to 74 ("optional base or professional audio cards"; Figure 4-1 "Optional Base Audio", output connector labelled "Digital out");
   *Onyx4 UltimateVision User's Guide*, 007-4634-002, pp. 21 to 23 ("Basic or professional PCI sound card", preferred bus 2 slot 1). The
   professional card is the DM8 (007-4077-001 p. 1 lists Onyx4, Origin 350 and Onyx 350 as the tested hosts). **Established** that SGI
   sold a "basic" PCI audio card for these systems; the guides give no part number, chip or vendor.

Inferred: the "basic" card is the Creative Audigy that `emu_dd` drives. Reasoning: on the systems that list "basic or professional", the IP35
build has four audio drivers (RAD, MAD, EMU, USB). MAD is the DM8 (professional). USB audio is a converter, not a PCI card. RAD is the PCI
Digital Audio Board with ADAT and AES, also a professional part (007-3502-003). The only IP35 PCI audio driver left is `emu_dd`, and
the captured cards on these systems have the Creative three-function layout. The weak point is timing: the Onyx 350 and Onyx4 guides
(2003 to 2004) predate `emu_dd`, which is absent in 6.5.22; the "basic" card at that time therefore either used another driver (RAD or MAD)
or the Audigy support came later with a different card. **Unknown**: the SGI marketing name and part number, and when the driver was added.

Candidates ruled out:
- **Tezro tower onboard audio** (007-4564-001 p. 32: the I/O daughtercard, an extension of the IO9, carries four RCA jacks, a 2.5 mm
  speaker-power port and two 3.5 mm jacks). In the Tezro captures that list adapter IDs, a RAD board (`10a9:0005`, hinv revision 13.0) shares PCI
  slot 1 with the IO9's IOC4 (`10a9:100a`) in 5 captures; the Audigy trio appears in a different capture. **Inferred** that the tower's
  onboard audio is a RAD at board number 13; the guide names no chip. The existing survey page's guess that it is the `emu_dd` device is
  withdrawn.
- **Prism** (Linux; 007-4701, 007-4772, 007-4774 not read for audio) has no IRIX driver, so it cannot explain `emu_dd`.
- **Onyx4 and Origin 350**: the Onyx4 guide uses the "basic or professional" wording; the Origin 350 guide 007-4566-001 has no audio text at all (searched); EMU is in one Origin 350 and one Onyx 350 capture, none on Onyx4.
- An unrelated source of "Audigy" text in the mail archive is the Windows Visual Workstation 320 family (2001 to 2003 posts) which took retail
  Creative cards; it is not IRIX.

Routes to settle the product: an SGI option list or price list naming the "basic audio" PCI card (not in the held documents); the `master.d`
and `audio.sm` of any 6.5.23 to 6.5.30 IP35 install; a `hinv -vm` of a factory-built system with the card showing subsystem IDs
(`hinv` prints vendor and device only; `emu_dd` does not read the subsystem fields either).

## Corrections to earlier pages

- survey.md: the `emu_dd` candidate for the Tezro tower onboard audio is withdrawn (above); the Audigy is a PCI option card.
- survey.md: the Fuel DM8 post is no longer the only evidence: 13 of 36 Fuel captures show MAD revision 1.
- survey.md and chips/rad: the PCI Digital Audio Board hinv example (007-3502-003 p. 11) reads revision 12.0, but real captures of a RAD in a
  PCI slot (O2, one Origin 2000, the IP35 machines) read 13.0, and 12.0 is the Octane and Octane2 onboard part. The sentence that the Octane's
  onboard controller "is the same part the PCI board uses (hinv revision 12.0)" is **contradicted** for the board number; the PCI ID and driver
  are shared.
- An `emu_dd` hit in an IRIX 6.5.30 O2 console capture is a package file listing, not evidence of an IP35 machine.

## Gaps

- IP22 family (A2, indigo, hdsp) objects and configuration trees; IP32 `audio.sm`; every 6.5.30 `var/sysgen` tree.
- IP35 object directories for 6.5.23 to 6.5.29 (when `emu_dd` appeared).
- Register contract of `emu_dd`, `usbaudio_dd` (descriptor use), `a3_dd`, and `rad_dd` (stub).
- SGI product names and part numbers for the "basic" audio card and the Fuel and Tezro option boards other than those in survey.md.
