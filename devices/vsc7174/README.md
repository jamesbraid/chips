# Vitesse VSC 7174 four-port SATA controller

Mode: **no-spec**. No Vitesse data sheet or programming guide is held; a search of the held documents turns up only the
public PCI ID list. Everything below comes from the Linux driver `sata_vsc.c`. That driver is
not a hardware reference: a register offset it uses is only as good as the driver's use of it. The driver does not say
which machines it was tested on.

Driver sources, read in full for the probe path and the interrupt and mask code:

- Linux 2.6.18 (git tag `v2.6.18`): `drivers/scsi/sata_vsc.c`, version string `2.0`.
- Linux current (git `HEAD` `3eb40771c00a`, 7.2 era): `drivers/ata/sata_vsc.c`. The file moved to `drivers/ata` and the
  offsets, the PCI table entry and the configuration write at `0x98` are unchanged.

Labels follow [AGENTS.md](../../AGENTS.md): **established**, **inferred**, **unknown**. What the driver file contains (its PCI
table, its constants, its comments) is established; a register's behaviour in the chip, read only from how the driver
uses it, is inferred, because no specification or SGI source confirms it.

## Short answer

| Question | Answer | Grade |
|---|---|---|
| PCI vendor and device | `1725:7174` (Vitesse Semiconductor, device 7174) | established (`pci_ids.h` at v2.6.18 and current; the public pci.ids list) |
| Driver match class | `0x010600` (SATA controller) | established (the driver's PCI table) |
| Second ID in the same driver | Intel `8086:3200`, matched by the same driver | established as a table entry; what that device is: unknown here |
| Ports | Four SATA ports; the driver calls the part "4 port DPA SATA" | established as the driver's header comment; inferred for the chip |
| BARs used | BAR 0 only, memory-mapped; no I/O BAR and no other BAR touched | inferred |
| DMA addressing | 32-bit DMA mask, set because the driver author found 64-bit address support poor | inferred |
| Interrupt | One shared line (`IRQF_SHARED`) for all four ports | inferred |
| Revision, subsystem IDs, BAR sizes | not read by the driver | unknown |
| Data sheet | none held | unknown |

## PCI identity

The driver's PCI table has two rows (v2.6.18 `drivers/scsi/sata_vsc.c`, `vsc_sata_pci_tbl`; current
`drivers/ata/sata_vsc.c`, the same table):

- `PCI_VENDOR_ID_VITESSE` (`0x1725`), device `0x7174`, any subsystem, class `0x010600`, class mask `0xffffff`.
- `PCI_VENDOR_ID_INTEL` (`0x8086`), device `0x3200`, any subsystem, the same class and mask.

The IDs are in `include/linux/pci_ids.h` at both tags (v2.6.18 line 2001 and 2002; current line 2383 and 2384).
The public pci.ids list names `1725` as Vitesse Semiconductor. The driver
does not read the revision register and does not check the subsystem IDs, so neither is known from it.

Whether the IO10 card's VSC 7174 reports `1725:7174` is **inferred**, not established. The Linux IO10
detection (see [the IO10 board page](../../platforms/sn2/io10-board.md#pci-position)) finds the chip by that ID, so
a card with a different ID would be read as a PCI-RT card. No document held here shows the ID on a real IO10.

## BAR layout

The probe path (v2.6.18 `vsc_sata_init_one`, lines 336 to 443; current has the same order):

1. `pci_enable_device`, then fail if `pci_resource_len(pdev, 0) == 0`. BAR 0 must be present and non-empty.
2. `pci_request_regions`, then a 32-bit streaming and consistent DMA mask.
3. `pci_iomap(pdev, 0, 0)`. The whole MMIO window is BAR 0. The driver maps no other BAR.
4. Port blocks are addressed from that base (see below).

BAR 0's size, and whether BAR 1 or later exist, are **unknown**. The driver never reads them.

## Global registers (BAR 0 base)

| Offset | Width | Content (driver name) | Grade |
|---|---|---|---|
| `0x00` | 32 bit read | Interrupt status, one byte per port: port `n`'s bits sit at `8n` to `8n+7`. The driver reads the whole word once per interrupt (`VSC_SATA_INT_STAT_OFFSET`). | inferred |
| `0x04 + n` | 8 bit, read-modify-write | Interrupt mask for port `n`, one byte per port. The driver sets or clears bit 7 from `ATA_NIEN` and leaves bits 0 to 6 as read (`VSC_SATA_INT_MASK_OFFSET`). | inferred |

The per-port status bits, using the driver's names (`VSC_SATA_INT_ERROR_*`, `VSC_SATA_INT_PHY_CHANGE`):

| Bit in the port's byte | Driver name | Grade |
|---|---|---|
| 0 | `PHY_CHANGE` | inferred |
| 1 | `M` | inferred |
| 2 | `E` | inferred |
| 3 | `R` | inferred |
| 4 | `P` | inferred |
| 5 | `T` | inferred |
| 6 | `CRC` | inferred |

The driver's comments and names are the only record of what these letters mean. The driver treats any of them as an
error (`is_vsc_sata_int_err`) and passes the rest to the ATA core. What `M`, `E`, `R`, `P` and `T` stand for in the
chip is **unknown** here.

## Port blocks

Port `n` (0 to 3) sits at BAR 0 offset `0x200 * (n + 1)`, so `0x200`, `0x400`, `0x600` and `0x800`. The stride is
the driver's constant `VSC_SATA_PORT_OFFSET`. The block's extent is **unknown**; the driver uses no register above `0x108`. The Altix firmware does: it writes
`0x4000` to offset `0x140` of each of the four blocks (see [the base I/O page](../../platforms/sn2/altix-350-base-io.md#per-device-initialisation)),
and Linux has no name for that register.

Inside a port block (driver probe `vsc_sata_setup_port`, offsets from the block base):

| Offset | Register | Access | Grade |
|---|---|---|---|
| `0x00` | Data (task file) | ATA core accessor | inferred |
| `0x04` | Error | ATA core accessor | inferred |
| `0x06` | Feature | ATA core accessor | inferred |
| `0x08` | Sector count | ATA core accessor | inferred |
| `0x0c` / `0x10` / `0x14` | LBA low / mid / high | ATA core accessor | inferred |
| `0x18` | Device | ATA core accessor | inferred |
| `0x1c` | Status | ATA core accessor | inferred |
| `0x1d` | Command | ATA core accessor | inferred |
| `0x28` | Alternate status | ATA core accessor | inferred |
| `0x29` | Device control | ATA core accessor | inferred |
| `0x64` | Up descriptor | written `0` at setup (`writel`) | inferred |
| `0x6c` | Up data buffer | written `0` at setup (`writel`) | inferred |
| `0x70` | DMA command (bus-master slot) | ATA bus-master hooks | inferred |
| `0x100` / `0x104` / `0x108` | SStatus / SError / SControl (SCR index `* 4`) | `readl` / `writel` | inferred |

The task-file offsets follow the standard ATA layout, so the register names match the ATA meaning. The chip's own
behaviour for each access is what the driver assumes, not what a data sheet states.

## Configuration space

The driver writes three things to PCI configuration space at probe time (v2.6.18 lines 395 to 427; current has the
same writes):

- Cache line size: a byte write of `0x80` (the driver's comment: "Due to a bug in the chip, the default cache line size
  can't be used"). The unit of that register is 32-bit words, so `0x80` is 512 bytes. Inferred.
- Configuration offset `0x98`: a dword write of `0`. The driver comment calls this "Extended Control and Status
  Register 0", with a default of `1 << 28`, and says that in DPA mode all bits except bit 28 are reserved. Bit 28
  set makes LED 0 show all ports' activity; clear gives each port its own LED. What `0x98` reads back as on a
  real part, and whether bit 28 is the power-on default, is **unknown** (the comment states a default; no hardware
  read is held).
- `pci_set_master`, and the 32-bit DMA mask above.

## Interrupts

One PCI interrupt (`pdev->irq`), shared, with `IRQF_SHARED`. The handler reads the global status at `0x00` once, then
walks the four ports (v2.6.18 `vsc_sata_interrupt`, lines 206 to 264). The pin the IO10 wires to the VSC, and which
PIC interrupt input it reaches, are not in the driver: see [the base I/O page](../../platforms/sn2/altix-350-base-io.md).

## Unknown, and what would settle it

- **Data sheet or programming guide** for the VSC 7174, including the meaning of the status and error bits, the DPA
  acronym, the revision register and the power-on value of `0x98`. Settles: a Vitesse document, or a dump of the
  chip's register file on a live IO10 under the physical-test rule (not yet approved).
- **Revision and subsystem IDs** of the IO10's chip. Settles: a `lspci -vnn` capture of an Altix 350 with an IO10,
  or the IO10's own parts list.
- **BAR sizes and whether other BARs exist.** Settles: the same capture, or the chip's data sheet.
- **Real SATA link speed** (1.5 or 3 Gb/s) and the drive count per card. The Altix manual says one or two drives
  (`007-4660-002`, p.115). The link rate is not given anywhere held.
- **Whether `0x8086:0x3200` is a device the IO10 carries.** The driver matches it, so the match is established; the
  card wiring is not. No document held says what that device is.
- **Whether the 32-bit DMA limit is a chip limit or a software choice.** The driver says "64 bit address support is
  poor". Settles: the data sheet, or a driver that uses 64-bit DMA on the same chip.

## Sources

- `drivers/scsi/sata_vsc.c`, Linux v2.6.18 (version `2.0`): PCI table, probe, port setup, interrupt handler, mask
  update, and the configuration writes.
- `drivers/ata/sata_vsc.c`, Linux HEAD `3eb40771c00a`: the same offsets (`0x00`, `0x04`, `0x200` stride, the `0x98`
  write, the PCI table entry), the same probe order, and the 32-bit DMA mask.
- `include/linux/pci_ids.h`, Linux v2.6.18 and HEAD: the vendor and device macros.
- pci.ids (public PCI ID database): the vendor name.

## Review

Independent review, 2026-11-21, by a reviewer who wrote none of these pages. Reviewed chips commits bff4d94, b2e30a2 and 80f1819.

Checked against Linux v2.6.18 `drivers/scsi/sata_vsc.c` and `include/linux/pci_ids.h`.

- Offsets, port stride, interrupt status and mask bytes, bit names, the cache-line and `0x98` writes, the 32-bit DMA mask,
  `IRQF_SHARED`, the Intel table row: confirmed.
- **Fixed.** Line ranges: the probe runs lines 336 to 443 and the `0x98` write is at line 427, not 402.
- **Fixed.** The page says the driver uses nothing above `0x108`; the Altix firmware writes `0x4000` to `+0x140` of each port
  block, so that is now stated and linked.
- **Fixed.** Labels moved to the three-rating set of chips AGENTS.md. Driver-derived register behaviour is inferred.
