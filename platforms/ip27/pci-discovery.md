# PCI discovery and the Origin 200 device-number map

Status: imported from published sources, not independently reviewed. Labels follow [AGENTS.md](../../AGENTS.md).
The device-number map rests on the owner's guide and public `hinv` listings. The guest-slot behaviour is a
reading of IRIX software (source not cited) that no chips binary has been checked against yet; it stays **inferred**
until the route in [open questions](../../questions/README.md) settles it.

This page holds no register contract. The Bridge registers are in [bridge-family.md](../../devices/bridge/family.md) and
the configuration-space addressing the kernel uses is in [bridge-pci-driver-windows.md](../../software/kernel/bridge-pci-driver-windows.md)
and [ip27-kernel-bridge-routines.md](../../software/kernel/ip27/bridge-routines.md). The Origin 200 has no BaseIO card: its
base I/O sits on the integrated system board, which [baseio.md](../../devices/baseio/README.md) does not cover.

The Origin 200 Bridge is the rev 4 Bridge at widget 8 ([bridge-family.md](../../devices/bridge/family.md)). A device placed
at a PCI device number that IRIX never probes is invisible to the guest, so the device-number map below matters
for any card or on-board part.

## Device-number map

| PCI device | Role | Evidence | Grade |
|---|---|---|---|
| 0 | On-board QLogic SCSI adapter (`1077:1020`) | Listings of the on-board QLogic at PCI slots 0 and 1 [5][6][7] | observed |
| 1 | On-board QLogic SCSI adapter (`1077:1020`) | Same listings [5][6][7] | observed |
| 2 | Integrated IOC3 (Ethernet, serial, parallel, keyboard and mouse, real-time clock, one-wire identity) | IRIX `hinv` path `xtalk/8/pci/2` [6]; the sub-device list is from the kernel reading in [8] | observed (IOC3 at 2); inferred (sub-device list) |
| 3 | Guest half of the dual-slot pairing with device 2. Skipped before any configuration read, given a bare placeholder record and no driver | IRIX software (source not cited), reading [8] | inferred |
| 4 | Not a chassis slot. Whether anything answers here is not known | The owner's guide lists slots 5, 6 and 7 only [1]; no listing shows a device at 4 | unknown |
| 5 | Option slot, chassis label 5 | Guide: "provide PCI IDs 5, 6, and 7" [1]; a card at `pci id 5` in a PROM listing [2] | established (the label); inferred (that the chassis label is the PCI ID) |
| 6 | Option slot, middle chassis slot | Guide [1]; a card in the middle slot reported at PCI slot 6 [3][4]; a card at device 6 [5] | established (the label); observed (the chassis position) |
| 7 | Option slot, chassis label 7 | Guide [1]; a card at `pci id 7` in a PROM listing [2] | established (the label); inferred (that the chassis label is the PCI ID) |

Consequences:

- The option slots are devices 5, 6 and 7. Devices 0 to 2 are base I/O.
- Device 3 is not an option slot. A card placed there is skipped by the kernel before its configuration space is
  read (see the next section), so it does not attach, whatever it is.
- Device 4 has no chassis slot. The kernel's walk would probe it, and a card there would attach if it answered.
  No listing shows any device at 4, and no source says what, if anything, is wired there. **Unknown.**

The step from the number IRIX prints (`pci id`, PCI slot, or the `pci/N` hardware-graph name) to the Bridge's
IDSEL line is **inferred** to be the identity. No capture prints the IDSEL itself. The numbers are consistent
across every listing that was checked.

For the chassis labels of 5 and 7, the tie between label and device number is the guide's own numbering. One
PROM listing calls a card "SLOT 5" and shows it at `pci id 5`, but that number may be the PROM's count rather
than the chassis count. Only the middle slot's position is tied to a device number by a listing with a stated
chassis position [3][4].

## How IRIX walks the bus

The Bridge attach routine enumerates the bus itself. It does not take its device list from firmware. It visits
device numbers 0 to 7, the range the IP27 and IP30 kernels use for these Bridge parts
([ip27-kernel-bridge-routines.md](../../software/kernel/ip27/bridge-routines.md)). For each device number it does three things,
in order:

1. **Guest skip.** If the platform has marked the device number as a dual-slot guest, it skips the device and
   reads no configuration word. This is the only skip before a read. **Inferred** (kernel reading [8]).
2. **Presence probe.** It reads the vendor and device word through a bus-error-trapping access. Before that read
   it masks the Bridge's PCI master-timeout interrupt and clears any pending PCI error, so an empty slot cannot
   fault the machine or raise a fatal interrupt. A trapped bus error means empty. **Inferred** (kernel reading
   [8]); the trapped-error path is also in the IP35 probe notes ([questions/ip35-boot-probe-registers.md](../../questions/ip35-boot-probe-registers.md)).
3. **Empty-slot check.** If the read completed and the vendor field is all ones, the slot is empty. The
   absent-function rule (vendor halfword `0xffff`) is established in [bridge-pci-driver-windows.md](../../software/kernel/bridge-pci-driver-windows.md).

Because the probe accepts either a trapped bus error or an all-ones vendor value as empty, a Bridge model can
represent an empty slot either way. Returning all ones without raising a master abort is enough for the walk to
skip the slot cleanly. **Software expectation, so inferred**: this follows from what the kernel accepts, not
from a Bridge specification.

### Guest placeholders

After the probe walk the kernel creates a bare device record for each device number that produced no information.
A guest slot gets one too. That record has no vendor ID and no device ID. It is linked to its host device number
by host and guest graph edges. Its configuration space is never read, and no driver binds to it. **Inferred**
(kernel reading [8]).

### Origin 200 platform marking

When the platform setup recognises the base I/O as an Origin 200 I/O board, it marks device 3 as the guest of
device 2. It also declares the IOC3's sub-functions on device 2. This is the only dual-slot marking the Origin
200 platform code makes. Every other device number is left to the walk. **Inferred** from IRIX software (source not cited)
reading [8]. The IP27 and IP30 kernels both call the guest-information routine that marks a slot's guest
(`pcibr_slot_guest_info_init` is named in [ip27-kernel-bridge-routines.md](../../software/kernel/ip27/bridge-routines.md) and
[ip30-kernel-bridge-routines.md](../../software/kernel/ip30/bridge-routines.md)). Its body has not been read against an
Origin 200 build. The pairing is also described as a reading of IRIX software (source not cited) only, so a second IRIX 6.5.x release is
needed before it is treated as stable across that line.

The reason given for the pairing is that the IOC3 and device 3 share one Bridge slot's request, grant and
interrupt lines. No source in this repository states that wiring, so it is **unknown**.

## Open questions

These are listed in [open questions](../../questions/README.md) with routes:

- Whether the guest marking and placeholder record match the IP27 kernel's Origin 200 path, by reading the
  guest-information routine and its caller in the IP27 build.
- Whether a second IRIX 6.5.x release marks the same pairing.
- The chassis position of the card at PCI device 5 and 7, which the PROM listing may number differently.
- Whether anything answers at device 4, and what is wired there.

## Sources

Verification note: [1] was re-read in the published guide and matches, including Figure 1-6, which draws the three option slots at the rear of the system labelled 7, 6 and 5. The Usenet posts and forum listings in [2] to [7] were not reachable when this page was checked, so each "observed" grade that rests only on them is unverified until the message is read again.

[1] Origin200 Owner's Guide, 007-3415-003, chapter 1, "PCI Backplane and Expansion Slots", printed page 12
    ("The slots provide PCI IDs 5, 6, and 7") and Figure 1-6, "PCI Backplane and Slot IDs", printed page 13.
    The same sentence is in 007-3415-002. **Established.**

[2] Public Usenet post on comp.sys.sgi.hardware, 2004-07-12, message `<956d16c2.0407120902.7fbb917a@posting.google.com>`:
    a PROM `hinv -v` listing with `pci id` 0, 1, 2, 5, 6 and 7, and an option card at `pci id 5`. **Observed**
    (public hardware listing; the "SLOT 5" label is the poster's and is not a chassis count).

[3] Public Usenet posts on comp.sys.sgi.hardware, 2002, messages `<3D480E52.6070006@yahoo.com>` and
    `<3D184B3F.8090704@yahoo.com>`: a card reported at PCI slot 6. **Observed.**

[4] Public Usenet post on comp.sys.sgi.hardware, 2003-02-09, message `<4406cb19.0302091548.54d8be53@posting.google.com>`:
    a card in the middle chassis slot reported at PCI slot 6. **Observed.** This is the only listing that ties a
    chassis position to a device number.

[5] Public Usenet post on comp.sys.sgi.hardware, 2005, message `<44275a8d$0$9710$6d36acad@titian.nntpserver.com>`:
    on-board QLogic adapters at PCI slots 0 and 1, the IOC3 at 2 and an option card at 6. **Observed.**

[6] Public IRIX `hinv -vm` posted to the nekonomicon forum, 2012-11-27,
    https://nekonomicon.irixnet.org/forum/14/16727211/1.html: QLogic adapters at PCI slots 0 and 1, the IOC3 at
    `xtalk/8/pci/2`. **Observed.**

[7] Public PROM `hinv` posted to the nekonomicon forum, 2015-05-01,
    https://nekonomicon.irixnet.org/forum/14/16729597/1.html: PCI-SCSI at `pci id` 0 and 1, the IOC3 at 2 and an
    option SCSI card at 6. **Observed.**

[8] IRIX software (source not cited), Bridge PCI attach and the Origin 200 platform setup, as a reading of the kernel code. The
    routines are the ones named in [ip27-kernel-bridge-routines.md](../../software/kernel/ip27/bridge-routines.md). No address in a
    chips binary is cited yet. **Inferred** (software expectation, not checked against a chips binary).
