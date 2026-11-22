# Lithium audio engine and the AD1843 codec: what a Windows driver needs

Mode: **no-spec** for the Lithium (no specification is held), spec-backed for the codec (the AD1843 data sheet, revision 0,
1996). The register map and the DMA ring are on the [Lithium page](README.md#audio-engine-the-linux-driver-the-nt-driver-is-checked-below)
and in [registers.md](registers.md); this page adds what a person writing or hosting an NT-family audio driver needs on top:
the codec programming, the per-period traffic, the ordering rules and what the driver asks of the HAL. Open points:
[questions/visws-audio-open.md](../../questions/visws-audio-open.md).

Sources, each read in Ghidra with the vendor's symbol file applied, whole functions:

- `sgisound.sys` 5.2.2 for Windows 2000 (27,168 bytes, build time 2001-10-29 01:43 UTC, sha-256 `289a9c5f7104...`), the build an
  XP port would start from. Addresses below are this build's, image base `0x10000`.
- The same driver for NT 4.0 (25,360 bytes, 2001-10-29 02:05 UTC, `e791a846d7a1...`) and the 1999 build from the recovery
  disc (28,720 bytes, 1999-04-27, `396c0f4daf6d...`). In both, `HwInitializeCodec` and `sndStopDMA` were read in full and make the same
  register writes in the same order as the Windows 2000 build; the rest of those two builds was not re-read for this page.
- The AD1843 data sheet, revision 0, 1996 (pages 28-29, 32, 37, 41-42, 45-49), for register names and reset values.
- Linux 2.6.33, `sound/oss/vwsnd.c` (the Visual Workstation driver) and `Documentation/sound/oss/vwsnd`; `sound/mips/ad1843.c` and
  `include/sound/ad1843.h` (a later user of the same codec on another machine, used only as a second reading of the codec
  start-up). Linux is a software expectation, as everywhere in this repository.

Grades: established, inferred, unknown, as in the [rules](../../AGENTS.md).

## 1. Where the engine sits

| Fact | Grade | Source |
|---|---|---|
| The engine is a block of registers at fixed physical addresses, not a PCI function. The driver never calls a PCI or bus-data routine; it maps three 4 KiB pages at `0xff001000`, `0xff010000` and `0xff00f000` as non-cached with `MmMapIoSpace` and uses nothing else to find the device. | established (as the driver's behaviour) | `HwInitialize` `0x10fdf`, all three builds |
| The three pages lie outside both bridge windows (`0xfc000000`, `0xfd000000`). That the audio engine therefore appears in no PCI configuration space is a reading from absence: neither the driver, the Linux code nor the NT HAL's slot tables mention an audio function. | inferred | the same, plus [nt-hal.md](../../software/visws/nt-hal.md) |
| Page `0xff001000` holds every register the driver uses except three undocumented words: host control `+0x00` (16-bit), interrupt status `+0x10` and mask `+0x14`, codec command `+0x18` (16-bit) and data `+0x1c` (16-bit), DMA register sets from `+0x100` (12 bytes each, seven rows in the driver's table, two used), time stamp `+0x200` and `+0x204`, time-stamp and counter pairs from `+0x300`. | established for the offsets the driver uses; interrupt words inferred (it never touches them) | [registers.md](registers.md), `HwAssignDmaOffsets` `0x11210` |
| Page `0xff00f000`: the word at `+0x500` is written with the silence sample before DMA starts. Page `0xff010000`: the words at `+0x98` and `+0x9c` are zeroed when output starts (Linux zeroes them when output stops). The registers' meaning is a name in a Linux comment ("undocumented"); behaviour unknown. | established as accesses, unknown as hardware | `sndStartDMA` `0x10b62`; Linux `li_deactivate_dma`, `li_shutdown_dma` |
| Windows 2000 and NT 4.0 hard-code these addresses; there is no resource list, no `HalTranslateBusAddress`, and the driver treats the processor's physical address as the engine's bus address. | established | imports and `HwInitialize` |

## 2. How the AD1843 is reached, and what the driver programs

The codec sits behind a serial link controlled from the engine. A codec register access is two 16-bit accesses to the command
and data words, no indirect window of any other kind (`CODECRegisterWrite` `0x10ef2`, `CODECRegisterRead` `0x10f4a`,
`CODECWaitForReady` `0x10e96`; established):

- Write: wait until command bit 15 (busy) is clear, store the data word at `+0x1c`, then store the register number (0 to 28
  used; bit 7 clear) at `+0x18`.
- Read: wait for busy clear, store `0x80 | register` at `+0x18`, wait for busy clear again, read the data word at `+0x1c`.
- The wait polls the halfword at `+0x18`, one initial read, then one read per 10 microseconds of `KeStallExecutionProcessor`, at most 36,000 more; on
  timeout the driver sets a flag and never waits again, and every later codec access is skipped. The driver keeps a copy of every
  register it writes and never reads codec registers back except register 0.

Start-up (`HwInitializeCodec` `0x1109c`, established; register names from the data sheet):

| Step | Access | Value | Meaning |
|---|---|---|---|
| 1 | host control `+0x00`, 16-bit: write, wait 1 ms, write, write | `0x8000`, then `0`, then `0x4000` | codec reset, release, link enable; link good when bit 2 of `+0x00` reads 0 (`HwCheckLink` `0x10fc2`) |
| 2 | codec reg 0 (read-only status) | until bit 15 (INIT, clocks not stable) is 0; up to 3 reads, 1 ms apart | data sheet: INIT clears 400 to 800 microseconds after reset |
| 3 | reg 26 write | `0x0195` | ADC left and right format 16-bit signed, ADC transmit lock, SCLK 16.384 MHz, DAC1 format 16-bit signed; DAC1 stereo |
| 4 | wait 6 ms; reg 28 write | `0x4400` | clears converter power-down (PDNI), keeps autocalibration and clock-output enable |
| 5 | wait 480 ms; reg 0 read | bit 14 (PDNO) must be 0, else wait 100 ms and read once more, else fail | data sheet: about 470 ms to leave power-down |
| 6 | input ring base `+0x100` | the input ring's address shifted right 8, bit 29 set | needed even for output-only use (Linux documents the same) |
| 7 | reg 27 write | `0x01d3` | DAC1, analog channels, headphone, analog mix, ADC left and right on; DAC2 and the DAC2-to-DAC1 mix off |
| 8 | reg 28 write | `0x5c00` | clock generators 1 and 2 enabled; generator 3 off |
| 9 | reg 15 write | `0x0205` | ADC left and right take clock generator 1, DAC1 takes clock generator 2, DAC2 stays on the fixed 48 kHz |
| 10 | reg 9 write; reg 8 write | `0x0808`; `0x8848` | DAC1 output level 0 dB and unmuted; headphone unmuted, mono output left muted |

Around the table:

- `HwInitialize` reads the host control halfword (`HwCheckLink` `0x10fc2`) before the `0x8000`, `0`, `0x4000` sequence and
  fails the load if bit 2 is set, so a model must not hold bit 2 set before link enable. It ignores the return value of
  `HwInitializeCodec`: if INIT never clears, the driver still loads, without codec set-up; only the busy-timeout flag fails the load.
- After the table, `SoundCardInstanceInit` `0x116a5` calls `SoundMixerInit` `0x11b40`, which always runs `HwInitMixerControl` for the
  ADC source: with no stored settings that is two writes of register 2 with the value 0. If a `Mixer Settings` registry value exists,
  every control is replayed (regs 4, 5, 7, 9, the mutes, reg 25, reg 2), including a two-step write of reg 9 that overwrites the `0x0808` above.
- `DriverEntry` does nothing unless `Services\sgisound\Parameters` has at least one subkey (it returns an error otherwise).
- `SoundDelay` is `KeDelayExecutionThread` and does nothing at IRQL 2 or above; each wait is a minimum, quantised to clock ticks.

The driver's own initial copy of the register file equals the data sheet's reset values wherever the data sheet gives one
(register 0 `0xc001`, mix registers `0x8888`, clock generator rates `0xbb80`, channel power `0x00c0`), so a reset codec model
meets its assumptions. Linux's Visual Workstation driver gives DAC1 clock generator 1 and the ADC generator 2, the opposite of the NT driver, and sets the
speaker swing bit; its later O2 helper uses all three generators. Each is valid against the data sheet, so a codec model must honour
any assignment (inferred; the engine paces itself from whichever generator register 15 selects).

Run-time writes (`established`, from the functions named):

| When | Register and value | Source |
|---|---|---|
| sample rate change | reg 17 (generator 1) for input, reg 20 (generator 2) for output; the value is the rate in hertz, written only when rate, size or channels changed and the stream is not already started | `HwSetWaveFormat` `0x1155e`; data sheet p. 39 (reg 17) and p. 42 (reg 20): one LSB is one hertz |
| the engine converts 8-bit and mono | register 26 is never rewritten after step 3, so the codec always runs 16-bit stereo and the engine's configuration word (format, stereo bit) does the conversion | whole-driver search for writes to 26 |
| mixer volume, mute | regs 4, 5, 7 (mix gain and mute for the three inputs), 9 (DAC1 level); mute is bits 7 and 15 | `MixSetVolume` `0x102e0`, `MixSetMute` `0x1051e` |
| record source and gain | reg 2: source `0x4040`, `0x6060` or `0x2020` (both channels: auxiliary 1, auxiliary 2, microphone); gain in bits 11:8 and 3:0; microphone boost toggles bits 12 and 4; reg 25: `0x00a0` is digital loopback from DAC1. The selector writes reg 2 as the absolute value, so it also clears microphone boost, and writes reg 25 as `0` for the three analog sources | `MixSetADCSelector` `0x1071e`, `MixSetADCHardware` `0x1043e`, `MixSetMicBoost` `0x106e0`; `sndIoctlSetLoopbackMode` `0x107b6` only writes reg 25 = `0x00a0` and ignores its input |
| video-locked sampling (only when an application selects a sync source) | reg 16 (input) or 19 (output): top two bits set, low byte a base-rate and divisor code (NTSC rates 8000, 11025, 16000, 22050, 32000, 44056, 44100, 48000; 44056 only in mode 0) | `HwSetClkSyncSrc` `0x11282`, `HwSetClkVideoLockRate` `0x1130c`; data sheet pp. 37-38 (reg 16) and p. 41 (reg 19) |

Data sheet registers the driver never touches: 1 (channel status and overrange), 3, 6, 10 to 14, 18, 21 to 24. Reading
register 1 clears it on any access (data sheet p. 28), which is moot since nothing reads it.

## 3. DMA: ring format and addressing

Everything here is already on the [Lithium page](README.md#the-dma-engine-as-the-nt-driver-programs-it-second-reading); only the
additions are listed (all established, `sndInitializeWaveSpec` `0x11954`, `sndStartDMA` `0x10b62`):

- Each channel has one ring, flat and contiguous, 8 KiB (`0x2000`) fixed: the driver sets the size unconditionally, so the
  size code written is always 7. The 4 KiB branch in `sndStartDMA` is dead code in the shipped configuration.
- The ring comes from `MmAllocateContiguousMemory` with a ceiling of `0xffffffff`, so it is below 4 GiB, and is moved up to a 256-byte boundary by adding `0x100` minus its low byte in the Windows 2000 and NT 4.0 builds, so an
  already aligned block moves by `0x100` (the 1999 build's arithmetic differs but its odd branch is never reached). The base register gets that physical address shifted right 8 with bit 29 set. The register can hold more (Linux's
  comment: a 40-bit address, bit 37 selecting coherence), but the NT driver never uses it, so the engine's reach above 4 GiB is unknown.
- There is no descriptor list: the engine reads (output) or writes (input) the ring between two byte-wide pointers in 32-byte
  steps, wrapping at the ring size. Hardware owns one pointer, software the other.
- Data for output is copied into the ring by the CPU (`memmove` from the caller's buffer). There is no scatter-gather and no
  second buffer.
- The configuration word's serial-slot field (bits 6:4) is never set by the NT driver: its register copy starts at zero and no
  code path writes the field, so it stays 0 for both channels. Linux writes 2. Both drivers work on hardware, so either the field
  is unused for these channels or the engine ignores it (unknown; question 1).

## 4. Interrupts

| Fact | Grade | Source |
|---|---|---|
| The NT driver never connects an interrupt in any of the three builds: no interrupt-connect call is imported, it never reads `+0x10` or `+0x14`, and it never sets the trigger pointer or mask. | established | import tables, whole-driver search |
| It is timer driven instead: when a stream starts it arms a periodic kernel timer (due almost at once, period 4 ms) whose DPC does the copy; a periodic timer cannot fire faster than the clock tick, which the HAL sets to 10 ms by default, so about 100 DPCs per second per running stream. | established for the call; the 10 ms is the HAL's default | `sndStartTransferDpc` `0x13160`; [nt-hal.md](../../software/visws/nt-hal.md) |
| The engine's interrupt is Cobalt controller line 22 (Linux's constant; that this is the audio line is a reading of Linux plus the HAL table index, not seen in any NT use). Cause is `+0x10` (bits: input trigger, input overflow, output trigger, output underflow, link error), enable `+0x14`; Linux reads the status then writes ones back to clear, and re-arms by clearing then or-ing the mask. | line, bit roles and write-one-to-clear: inferred | Linux `vwsnd_audio_intr`, `li_enable_interrupts`; [registers.md](registers.md) |
| In the NT HAL the vector for line 22 is `0xb2`, (entry 22 of the HAL's vector table, which has the same value in all three generations' tables). A driver would obtain it with `HalGetInterruptVector` on the internal bus with level 22; for lines 16 and up the HAL only writes the controller's redirection entry and touches no bridge enable. | vector table value: established; that it is the audio line or that a driver doing so works: inferred | `CobaltInt2Vec` in `halborg.dll` 1.3; [nt-hal.md](../../software/visws/nt-hal.md#interrupt-level-to-cobalt-entry) |

A polling model is enough for the shipped driver. A new driver that wants real interrupts would have to find out what the
engine actually raises, which no software read here does (questions 2 and 3).

## 5. Per-period traffic and ordering (the cost of hosting)

Per DPC with a stream running (`SoundOutTransferDpc` `0x12e10`, `sndLoadDMABuffer` `0x122be`, `GetCurrentWaveOutPosition`
`0x12f48`, `SoundInTransferDpc` `0x12dd4`, `sndFillInputBuffers` `0x127b4`; established):

| Stream | Register accesses per DPC | Width |
|---|---|---|
| output | read of the hardware read pointer (control `+1`), once for the free-space test; when buffers are outstanding, two more pointer reads for the position; one write of the software pointer (control `+0`) after data was copied; the position ioctl, the peak meter and `GetCurrentWaveOutPosition` also read the pointers | all 1 byte |
| input | read of the hardware write pointer (control `+0`) and of the software pointer (control `+1`); one write of the software pointer (control `+1`) after data was copied | all 1 byte |

So three to four byte accesses per stream per tick, about 400 per second for playback alone at the default 10 ms clock, none of
them to the codec. Under a hypervisor where each access leaves the guest, that is a few hundred exits a second; the cost is
dominated by the byte-wide pointer accesses, not the codec. The ring is 8 KiB, which is about 43 ms of 48 kHz 16-bit stereo,
so a DPC late by a few tens of milliseconds underflows.

One-off traffic:

- Start of a stream (`sndStartDMA`): for output, a control-word write to clear enable, two writes to page `0xff010000`
  (`+0x98`, `+0x9c`); then for both directions the base, the configuration, the control word (size and enable in one store), the
  silence word at `0xff00f000 + 0x500` before that store. The counter zeroing (`+0x30c` output, `+0x304` input) and the four
  reads of the time-stamp pair happen in the first DPC that moves data (`sndLoadDMABuffer`, `sndFillInputBuffers`), not in
  `sndStartDMA`. All 32-bit except the pointers.
- The shadow copy of the control word has its low 16 bits (both pointers) and trigger fields always 0, and every 32-bit control
  store sends the whole shadow. So the output start, the output clear-enable before it and the input stop each reset both
  pointer bytes to 0; the pointers are otherwise written only as single bytes. A model must treat a 32-bit control write as
  setting the pointers. Linux first writes the channel-reset bit (`0x80000000`); the NT driver never does.
- Stop: `sndStopDMA` first runs one more fill or load pass (for input that reads the hardware pointer and writes the software
  pointer); then input clears the enable bit with one control-word write; output writes nothing to the engine, it only cancels the
  timer. The output channel therefore keeps its enable bit until the next start clears it (`sndStopDMA` `0x10d24`, all three
  builds). What the engine does with an enabled channel whose pointers are equal is unknown (the Linux comment says it repeats
  the last sample after an underflow).
- Codec accesses (`CODECRegisterWrite`): one status read, two writes, per register: `HwInitializeCodec` makes 7 writes and 2 to 5 reads of
  register 0 and spends about 490 ms of guest time in waits; a rate change makes 1; a volume change 1 to 4.

Ordering that matters (established unless marked):

1. The link-enable write (`+0x00`) must precede every codec access.
2. The configuration and base must be written before the control word, which carries the size and the enable together; the silence word before the
   enable; the input channel's base before anything starts, even for output.
3. The data copy into the ring precedes the software-pointer write; the driver issues no barrier. On x86 the stores arrive in
   program order, so a model may read the ring at or after the pointer write (inferred).
4. A time-stamp pair is read as the channel's counter word first, then its time-stamp word; the high word of the system
   time stamp (`+0x204`) is read before and after and the sequence repeated until equal. Linux's comment says the hardware keeps the two reads consistent when taken in that order; the NT
   order is the same (`GetLiUstMscPair` `0x1393a`).
5. The busy flag must clear on its own: the driver never clears it. A model that never sets it satisfies the driver.

## 6. What the driver needs from the HAL and the NT driver model

| Need | Grade | Source |
|---|---|---|
| Kernel exports, all long-standing: `MmMapIoSpace`, `MmAllocateContiguousMemory`, `MmGetPhysicalAddress`, `MmMapLockedPages`, `IoCreateDevice`, `IoCreateSymbolicLink`, `IoRegisterShutdownNotification`, `IoSetShareAccess`, `IoReportResourceUsage` (once, on unload, with an empty list), `KeInitializeTimerEx`, `KeSetTimerEx`, `KeCancelTimer`, `KeInitializeDpc`, `KeInitializeMutex`, `RtlQueryRegistryValues`, `Zw` registry calls, `ExAllocatePoolWithTag`, `_allshr`. From the HAL: `KeGetCurrentIrql`, `KeStallExecutionProcessor`, `KfAcquireSpinLock`, `KfReleaseSpinLock`. | established (import table) | all three builds |
| All of these exist in Windows XP's kernel and HAL interfaces. Not checked against an XP image. | inferred | n/a |
| Nothing from the bus layer: no `HalGetBusData`, `HalAssignSlotResources`, `HalTranslateBusAddress`, `HalGetInterruptVector`, `IoConnectInterrupt` or `HalGetAdapter`. So the HAL needs only to leave `0xff001000`, `0xff00f000` and `0xff010000` unclaimed by RAM and mappable, to provide a working microsecond stall, and to tick the clock. | established | imports |
| Legacy model, not WDM: `DriverEntry` (`0x1165c`) installs create, close, read, write, device-control, cleanup and shutdown handlers and an unload routine; no `AddDevice`, no PnP or power handlers. It reads `Services\sgisound\Parameters` subkeys, creates `\Device\SGIMixer`, `\Device\SGIWaveOut` and `\Device\SGIWaveIn` (per device) and links under `\DosDevices`, and keeps its mixer settings in the registry. Windows XP still starts such a driver as an automatic or boot-start service with no PnP stack involvement (a general property of the driver model, not read from XP). | handlers and names established; XP behaviour inferred | `entry`, `SoundCardInstanceInit` `0x116a5`, `sndCreateDevice` `0x118da` |
| Both builds are 32-bit x86. The kernel of XP x64 cannot load them; a driver for it is a rewrite from the register contract above. | established (PE machine type) | file headers |
| The user side is `sgisound.dll`, a legacy multimedia driver that issues `DeviceIoControl` calls against the device names and whose imports include `CreateService`, `StartService`, `ChangeServiceConfig` and `mmTaskCreate`; it creates the kernel service when installed. Whether Windows XP's multimedia layer accepts it, and what its install entry creates, were not read (the DLL was inspected for imports and strings only). | imports established; XP behaviour unknown | `sgisound.dll` 5.2.2, Windows 2000 build |
| It would load without the SGI HAL in principle: nothing in it asks the HAL for a bus or an interrupt. What it does need from a machine is the engine at those addresses and a codec that answers register 0. | inferred | follows from the rows above |

## What a host model has to provide for the shipped driver

The minimum set for `sgisound.sys` to initialise and play (all of this is established from the code except where marked):

- Host control: accept the `0x8000`, `0`, `0x4000` sequence; bit 2 reads 0 before and after. Linux's probe also wants the value after
  link enable to differ from a plain `0x4000` (it treats exactly `0x4000`, or bit 1 set, as no codec), so set a ready bit.
- Codec port: command word busy bit that is 0 (or clears at once), 16-bit write and read of data and command; register 0 reads
  `0xc001` for a short time after link enable, then bit 15 clears (within 2 ms: the driver reads at 0, 1 and 2 ms), then after the clear of PDNI in register 28
  bit 14 clears within 580 ms (a model may clear it at once). The value of registers 1 to 28 can be a plain array with the
  data sheet reset values; no reads except register 0.
- DMA channels one and two: the three registers each, byte-granular access to the control word's two low bytes, the enable bit;
  the engine consumes or fills the ring at the sample rate of the selected clock generator (inferred) and advances its pointer.
- The two time-stamp words and counters, and the three odd words in pages 1 and 2, as plain storage (inferred; the driver only
  writes them and the pairs read back).
- A 32-bit write to a channel's control register must load both pointer bytes (see above).
- Registry: `Services\sgisound\Parameters` with at least one device subkey, or the driver does not start.
- No interrupt, no PCI function.
