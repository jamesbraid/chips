<!-- generated from devices/pic/registers-extra.toml by defs-gen - do not edit, change the source -->

# PIC bits outside the census

Unit `pic_extra`, macro prefix `PIC`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `wid_stat` | 0x8 | rw | 64 |  |  | unknown | established |  |
| `wid_err_upper` | 0x10 | rw | 64 |  |  | unknown | established |  |
| `wid_int_upper` | 0x30 | rw | 64 |  |  | unknown | established |  |
| `wid_tst_pin_ctrl` | 0x70 | rw | 64 |  |  | unknown | established |  |
| `pci_err_upper` | 0xd0 | rw | 64 |  |  | unknown | established |  |
| `buf_addr_match` | 0x300 | rw | 64 | 32 |  | unknown | established |  |
| `buf_flush_w_touch` | 0x400 | rw | 64 | 8 |  | unknown | established |  |
| `buf_flush_wo_touch` | 0x408 | rw | 64 | 8 |  | unknown | established |  |
| `buf_inflight` | 0x410 | rw | 64 | 8 |  | unknown | established |  |
| `buf_prefetch` | 0x418 | rw | 64 | 8 |  | unknown | established |  |
| `buf_total_pci_retry` | 0x420 | rw | 64 | 8 |  | unknown | established |  |
| `buf_max_pci_retry` | 0x428 | rw | 64 | 8 |  | unknown | established |  |
| `buf_max_latency` | 0x430 | rw | 64 | 8 |  | unknown | established |  |
| `buf_clear_all` | 0x438 | rw | 64 | 8 |  | unknown | established |  |
| `pcix_timeout` | 0x638 | rw | 64 |  |  | unknown | established |  |
| `pcix_read_buf_addr` | 0xa00 | rw | 64 | 16 |  | unknown | established |  |
| `pcix_read_buf_attr` | 0xa08 | rw | 64 | 16 |  | unknown | established |  |
| `pcix_write_buf_addr` | 0xb00 | rw | 64 | 8 |  | unknown | established |  |
| `pcix_write_buf_attr` | 0xb08 | rw | 64 | 8 |  | unknown | established |  |
| `pcix_write_buf_valid` | 0xb10 | rw | 64 | 8 |  | unknown | established |  |
| `int_ate_mp` | 0x12000 | rw | 64 | 1024 |  | unknown | established |  |

### Register `wid_stat`

Widget status, the second word of the standard widget configuration block (`p_wid_stat`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `wid_err_upper`

Widget error address, upper word (`p_wid_err_upper`); the lower word is the census register `bus_err`. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `wid_int_upper`

Widget interrupt destination, upper word (`p_wid_int_upper`); the lower word is the census register `intr_dst_target_id`. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `wid_tst_pin_ctrl`

Test pin control (`p_wid_tst_pin_ctrl`), the one slot of the bridge-specific block between the response words and the address-lock error register. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `pci_err_upper`

PCI bus error address, upper word (`p_pci_err_upper`); the lower word is the census register `pci_bus_addr`. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `buf_addr_match`

Buffer address match registers: sixteen pairs, upper word then lower word, sixteen bytes per pair (`p_buf_addr_match[n].upper` and `.lower`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 32 registers, stride 8.

### Register `buf_flush_w_touch`

Performance monitor block n, word 0 (`p_buf_count[n].flush_w_touch`): eight blocks of eight words, 0x40 bytes apart. The header comment marks them even-numbered buffers only. The register names are the only description. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_flush_wo_touch`

Performance monitor block n, word 1 (`flush_wo_touch`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_inflight`

Performance monitor block n, word 2 (`inflight`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_prefetch`

Performance monitor block n, word 3 (`prefetch`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_total_pci_retry`

Performance monitor block n, word 4 (`total_pci_retry`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_max_pci_retry`

Performance monitor block n, word 5 (`max_pci_retry`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_max_latency`

Performance monitor block n, word 6 (`max_latency`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_clear_all`

Performance monitor block n, word 7 (`clear_all`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `pcix_timeout`

PCI-X timeout (`p_pcix_timeout`), the eighth word of the PCI-X register block that follows the seven census registers. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `pcix_read_buf_addr`

PCI-X read buffer n, address word (`p_pcix_read_buf_64[n].p_buf_addr`); the attribute word of the same buffer follows it. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 16 registers, stride 16.

### Register `pcix_read_buf_attr`

PCI-X read buffer n, attribute word (`p_buf_attr`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 16 registers, stride 16.

### Register `pcix_write_buf_addr`

PCI-X write buffer n, address word (`p_pcix_write_buf_64[n].p_buf_addr`); the attribute, valid and one unused word follow at eight-byte steps. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 32.

### Register `pcix_write_buf_attr`

PCI-X write buffer n, attribute word (`p_buf_attr`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 32.

### Register `pcix_write_buf_valid`

PCI-X write buffer n, valid word (`p_buf_valid`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 32.

### Register `int_ate_mp`

Second copy of the internal translation entries with manual parity generation (`p_int_ate_ram_mp`); the census register `int_ate` is the automatic-parity copy. No IRIX routine reaches this range. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 1024 registers, stride 8.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ATE_ADDR_SHIFT` | 0xc | established |  | Translation entry bit 12 is the lowest page-address bit; the kernel stores the page-aligned address in place with the low bits as flags, whatever the I/O page size. |
| `ATE_BARRIER` | 0x10 | established |  | Bit 4: barrier, requested for consistent (coherent-memory) mappings. |
| `ATE_COHERENT` | 0x2 | established |  | Bit 1 of a translation entry on the PIC: coherent. The same bit position is the programmed-I/O bit on the TIOCP. |
| `ATE_MSI` | 0x4 | established |  | Bit 2: the mapping is for a message-signalled interrupt write. |
| `ATE_PREFETCH` | 0x8 | established |  | Bit 3: prefetch. The kernel clears it in PCI-X mode because prefetch is not supported there. |
| `ATE_TARGET_SHIFT` | 0x8 | established |  | Shift of the target widget number in a PIC translation entry: the kernel ORs the hub's Crosstalk widget id left by 8. Entry bits from 12 up carry the page address (shift PCI32_ATE_ADDR_SHFT 12). |
| `ATE_VALID` | 0x1 | established |  | Bit 0 of an internal translation entry: valid. |
| `CFG_TYPE0_BASE` | 0x20000 | established |  | Base of eight type-0 configuration windows of 0x1000 bytes each (eight functions of 0x100 bytes). Internal device n is reached through window n + 1 because the PIC takes device 0: the first device sits one window up. The kernel derives the internal device as PCI slot minus 1. |
| `CFG_TYPE1_BASE` | 0x28000 | established |  | Base of the 0x1000-byte type-1 configuration window. |
| `CONTROL_PAGE_SIZE_16K` | 0x200000 | established |  | Bit 21 of the control register: translation page size. The kernel clears it for 4 KiB I/O pages and sets it when its page size is 16 KiB or more. The shipped IRIX attach sets it unconditionally, which agrees with 16 KiB pages. |
| `DEVICE_SWAP_DIRECT` | 0x80000 | inferred |  | bit 19 of the device register (0x200 plus 8n), named swap_direct in the public PIC header. Set selects the address-preserving byte map for the 32-bit direct window; clear selects the lane-preserving map. The bit position comes from the public SN2 driver's byte-stream flag mapping onto this bit; no PIC measurement confirms the lane sense (open question in open-questions.md) |
| `DIRECT64_ATTR_BARRIER` | 0x100000000000000 | established |  | Bit 56: barrier. Set for consistent mappings. |
| `DIRECT64_ATTR_PRECISE` | 0x400000000000000 | established |  | Bit 58: precise. Defined; no SGI Altix provider code read sets it. |
| `DIRECT64_ATTR_PREFETCH` | 0x800000000000000 | established |  | Bit 59 of a 64-bit direct address: prefetch. Cleared by the kernel in PCI-X mode. Used for streaming mappings. |
| `DIRECT64_ATTR_SWAP` | 0x80000000000000 | established |  | Bit 55: byte swap. Defined, but no SGI Altix provider code read ever sets it. |
| `DIRECT64_ATTR_TARGET_SHIFT` | 0x3c | established |  | Shift of the target widget number in a 64-bit direct PCI address. Same placement as the other PIC page, now also named by the SGI Altix provider. |
| `DIRECT64_ATTR_VIRTUAL` | 0x200000000000000 | established |  | Bit 57: second virtual channel. In conventional PCI mode the kernel sets it for every function except function 0, so function 0 uses channel 0 and other functions channel 1. Not set in PCI-X mode. |
| `DIRECT64_ATTR_VIRTUAL1` | 0x40000000000000 | established |  | Bit 54: defined next to the virtual-channel bit; no provider code read sets it. |
| `HOST_INTR_ADDR_MASK` | 0xffffffffffff | established |  | Mask of the destination address field of a per-pin interrupt address register, 48 bits. The kernel clears this field and ORs the new address in; the TIOCP uses a 54-bit field. |
| `INTR_FLUSH_WAIT_VALUE` | 0x10f | established |  | The value the kernel's read-ordering flush waits to see at the memory word it armed as an interrupt target after forcing a pin interrupt. As a packet shape, 0x100 plus vector 0x0f, it matches the shape the shipped IRIX path is inferred to wait for; the kernel names no meaning for bit 8. |
| `INTR_PCIX_MASTER_TIMEOUT` | 0x400000000 | established |  | bit 34 of the interrupt status register (0x100), the PCI-X master timeout. Which bit a bus in PCI-X mode sets for an unclaimed configuration cycle is not stated by any source read (unknown) |
| `INTR_PCI_MASTER_TIMEOUT` | 0x800 | established |  | bit 11 of the interrupt status register (0x100) and of the error view (0x170). The view records a master timeout whether or not the enable bit is set; status records it only when bit 11 of the enable register (0x108) is also set. An unclaimed configuration cycle is the usual source (inferred, see devices/pic/facts-outside-census.md) |
| `INTR_RESET_MULTIPLE_CLEAR` | 0x40 | established |  | bit 6 of the reset register (0x110), the multiple-error clear. Bits 8:7 and 5:0 have no PIC field. A one written at an error bit's own position clears that bit and rearms the error registers, and any write to 0x110 also clears the error view |
| `PCI32_DIRECT_BASE` | 0x80000000 | established |  | Start of the 2 GiB direct-mapped 32-bit window, offset from the base the direct-map register holds. Not used in PCI-X mode. |
| `PCI32_MAPPED_BASE` | 0x40000000 | established |  | Start of the translated 32-bit window: PCI addresses from here up to PCI32_DIRECT_BASE go through the internal translation entries, index (address minus base) shifted by the I/O page shift. |
| `PCI32_MAPPED_SWAP` | 0x20000000 | established |  | Bit 29 of a translated-window PCI address: the kernel sets it only when the device's Device register copy it was handed already has the swap bit (bit 19) set. |
| `PCIX_SPECIAL_CYCLE_BASE` | 0x40000 | established |  | Eight-byte PCI-X special cycle window. No code read uses it. |
| `PCI_IACK_BASE` | 0x30000 | established |  | Eight-byte PCI interrupt acknowledge cycle window. No code read uses it. |
