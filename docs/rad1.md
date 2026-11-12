# RAD1 audio ASIC: facts outside the register file

The register contract is [defs/rad1.toml](../defs/rad1.toml), published as
[gen/docs/rad1.md](../gen/docs/rad1.md), with each entry graded. This page keeps
the facts that are not register entries: where the part sits, what its PCI
configuration shows, and how software reaches it.

## Placement

- On Octane and Octane2 the onboard RAD is PCI `10a9:0005` at device 3,
  function 0, behind the onboard Bridge, with revision `0xc0` (board 12).
  **Established**, from a published OpenBSD/sgi boot transcript of an Octane,
  which prints the RAD1 line. That transcript shows no status or configuration
  words.
- The *OCTANE Technical Report* places built-in audio behind the Bridge. It says
  the baseline audio generates the shared media timeline clock and that RAD
  associates UST with media sample counts (PDF pages 58 to 60 and 65 to 66,
  printed pages 3-3 to 3-5 and 3-10 to 3-11). **Established** as to what the
  report says. The report gives neither the tick period nor any register
  behaviour.

## PCI configuration

- The class code (config offset `0x08`, bits 31:8) reads zero. See
  `PCI_CLASS_OCTANE` in the register file. **Established**, from one public
  Linux `lspci` dump of the onboard RAD (linux-pci-list message
  `20170213224512.GA8080@bhelgaas-glaptop.roam.corp.google.com`, 2017-02-13).
- The same dump's Status word has FastB2B (bit 7) and DEVSEL slow (bits 10:9,
  value `10b`) set, and target abort signalled (bit 11). SERR, PERR and INTx are
  clear. **Established** for those bits in that dump. Bit 11 is a
  write-one-to-clear error bit, so the dump records a target abort that had
  happened, not a reset value. No public source gives a reset value or a
  post-firmware Status value for board 12. Both are **unknown**.

## Access and byte order

- The IP30 driver reads and writes the registers it uses (the counter at `0x30`
  and the enable stores at `0x40`, among others) with ordinary aligned 32-bit
  loads and stores, and does no byte swap of its own. **Established** from the
  IP30 `rad_dd.o` object.
- OpenBSD's Bridge code gives `10a9:0005` the native, non-swapping bus space tag,
  and its resource setup keeps the programmed-I/O swap bit the PROM left in
  place while it changes the DMA swap bits. **Established** as a public driver's
  choice (`sys/arch/sgi/xbow/xbridge.c` on the `sgi-is-alive-at-7.9` branch,
  lines 1138 to 1150 and 2445 to 2509). OpenBSD attaches no audio driver on the
  captured Octane, so the tag is a driver choice and not a read of the chip.
- The Bridge's rule for narrow and aligned accesses through a device window is in
  [bridge-family.md](bridge-family.md). Whether the RAD itself maps each PCI
  byte to the same register byte is **unknown**.

## DMA request

- The IP30 driver's memory-to-PCI helper (`Mem_to_PCI_DMA`, `.text` `0x7268` to
  `0x72ac`) takes a physical buffer address, asks the PCI I/O layer for a DMA
  translation with flags `0x50`, and writes the returned PCI address into the
  descriptor's low and high words. **Established** from the IP30 `rad_dd.o`
  object. The Bridge decides the translation that actually applies (direct,
  ATE-translated or 64-bit), as [bridge-family.md](bridge-family.md) describes.

## Not settled

- The IP30 object's board 7 and board 13 `4` then `0` writes to `0x40` are
  attributed to the enable routine in the register file, `rad_enable_ust`. A
  second reading of the same object places them in the reset routine instead,
  and says the board 12 reset routine writes nothing to `0x40`. The attribution
  in `defs/rad1.toml` stays as it is until those routines are read again. The
  next step is to read the reset routine and its callers in the IP30 `rad_dd.o`.
