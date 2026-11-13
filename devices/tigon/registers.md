<!-- generated from devices/tigon/registers.toml by defs-gen - do not edit, change the source -->

# Alteon Tigon PCI/Gigabit Ethernet controller (SGI IRIS Gigabit Ethernet board)

Offsets are byte offsets in the chip's PCI memory window, as the manual's register tables give them. Fields are the bit positions the register descriptions name. Grades say how each item was derived: established means read in the Alteon Tigon/PCI Ethernet Controller manual, revision 1.04; inferred means a public driver's use or a reading the manual does not state. Reset values come only from the manual's reset statements. Nothing here was measured on a board. The prose and the sources the register rules rest on are in devices/tigon/README.md.

Unit `tigon`, macro prefix `TIGON`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `misc_host_ctl` | 0x40 | rw | 32 |  |  | unknown | established |  |
| `pci_state` | 0x5c | rw | 32 |  |  | 0x0 | established |  |
| `dma_write_state` | 0xa0 | rw | 32 |  |  | unknown | established |  |
| `dma_read_state` | 0xb0 | rw | 32 |  |  | unknown | established |  |
| `mailbox_0_low` | 0x504 | rw | 32 |  |  | unknown | inferred |  |

### Register `misc_host_ctl`

Miscellaneous Host Control. The read-write bits sit in the low byte, so a host that writes a byte-wide No Swap value can copy that byte into every lane. The manual gives no reset value for this register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `gate_array_revision` | established |  |  | Read-only. Three for the Chip Express release, four for the LSI gate array release, five for the LSI standard cell release. The field names gate-array releases only; it does not number the Tigon revision. |
| 6 | `mask_pci_interrupt` | established |  |  | Masks the PCI interrupt output. Present from Tigon revision 5. Clear it and any pending interrupt is raised. |
| 5 | `endian_word_swap` | established |  |  | Enables endian word swapping for accesses through the target interface. |
| 4 | `endian_byte_swap` | established |  |  | Enables endian byte swapping for accesses through the target interface. |
| 3 | `hard_reset` | established |  |  | Forces a full hardware reset of everything except the PCI configuration registers (offsets 0x00 to 0x3f) and the PCI State register. |
| 1 | `clear_interrupt` | established |  |  | Write-only. Writing one clears the host PCI interrupt IntA. |
| 0 | `interrupt_state` | established |  |  | Read-only. Reflects the state of the PCI IntA pin. |

### Register `pci_state`

PCI State. All bits are zero at reset. The Miscellaneous Host Control reset does not change this register. Bit 20 and the bits under it are the ones the host-bus rules turn on.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `default_pci_write_command` | established |  |  | Command used for all PCI write transactions. The manual says it should normally be initialized to seven. |
| 27:24 | `default_pci_read_command` | established |  |  | Command used for PCI reads of fewer than three words. The manual says it should normally be initialized to six. |
| 23 | `assert_all_pbe_on_writes` | established |  |  | During DMA writes, drives all byte enables, which forces doubleword alignment without adjusting the channel addresses and lengths. Present from Tigon revision 5. |
| 22 | `pci_rom_retry` | established |  |  | Forces PCI retry for accesses to the ROM region when the region is enabled. Present from Tigon revision 5. |
| 21 | `pci_rom_desired` | established |  |  | Makes the PCI ROM Base Address register visible to the host. Present from Tigon revision 5. |
| 20 | `bus_32bit` | established |  |  | One when on a 32-bit PCI bus, zero for a 64-bit bus. From Tigon revision 5, a write of one forces true 32-bit operation even when the host offered 64-bit. Setting it on a real 64-bit bus causes PCI problems. |
| 19 | `pci_66mhz_bus` | established |  |  | Read-only. One when the bus runs between 33 and 66 MHz, zero for 33 MHz or less. Before Tigon revision 5 this bit behaved like bit 18, for the write DMA channel only. |
| 18 | `no_word_swap_dma` | established |  |  | Disables word swapping for all DMA transactions. Before Tigon revision 5 it affected only the read DMA channel. |
| 17 | `use_mem_read_multiple` | established |  |  | Uses the Memory Read Multiple PCI command in place of Memory Read Line for DMA reads. |
| 7:5 | `dma_write_max` | established |  |  | Forces termination of PCI write operations at a byte boundary. Boundaries the manual lists: disable, 4 or 8 (one bus width), 16, 32, 64, 128, 256, 1k. The manual gives no numeric encodings; the public Linux Alteon driver (v2.4.37) defines the write limits as 0x01 through 0x07 shifted into bits 7 to 5, which puts 128 bytes at encoding five. |
| 4:2 | `dma_read_max` | established |  |  | Forces termination of PCI read operations at a byte boundary, with the same boundary list as the write field. The public Linux Alteon driver (v2.4.37) likewise puts 128 bytes at encoding five. |
| 0 | `force_reset` | established |  |  | Write-only and self-clearing. Forces an immediate reset of the PCI interface and loses its state. |

### Register `dma_write_state`

DMA Write State, the state of the write channel that moves data from the card to the host. The manual gives no reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `force_32bit_pci` | established |  |  | Forces PCI operation as if on a 32-bit bus. |
| 2 | `dma_active` | established |  |  | Starts the channel. The hardware clears the bit when the DMA finishes. |
| 1 | `dma_no_swap` | established |  |  | Disables the endian byte swap on data sent to the PCI bus. The swap is normally applied in groups of four bytes. The table's field text says data 'from the PCI bus', which the section's text contradicts for the write channel; the section text is followed here. |
| 0 | `dma_reset` | established |  |  | Write-only. Clears the write FIFO and the write DMA. |

### Register `dma_read_state`

DMA Read State, the state of the read channel that moves data from the host to the card. The manual gives no reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `force_32bit_pci` | established |  |  | Forces PCI operation as if on a 32-bit bus. |
| 2 | `dma_active` | established |  |  | Starts the channel. The hardware clears the bit when the DMA finishes. |
| 1 | `dma_no_swap` | established |  |  | Disables the endian byte swap on data received from the PCI bus. The swap is normally applied in groups of four bytes. |
| 0 | `dma_reset` | established |  |  | Write-only. Clears the read FIFO and the read DMA. |

### Register `mailbox_0_low`

Word of mailbox 0 that raises the mailbox event, read as the least significant word at the higher address. Inferred: the manual contradicts itself. Section 2.7 says a write to the upper half of one of the 32 eight-byte locations raises the event, and section 9.12.3 says a write to the least significant word does and a write to the most significant word does not. The Linux driver writes its producer indexes to the words at offset 4 of each location, which matches 9.12.3 if the least significant word sits at the higher address. Writing mailbox 0 also deasserts the PCI interrupt pin at once, so a host can clear the interrupt and pass a message in one write. The manual says a mailbox may be read back as often as needed. The same word of mailbox n is eight bytes after that of mailbox n minus one.
