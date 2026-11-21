<!-- generated from devices/tiocp/registers-extra.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 11f87d67648250748efa0557e3091fcd29937fc879c35edb7bda8e7a07b6c989 -->

# TIOCP registers and constants outside the census

SGI's Linux Altix platform code (v5.3) defines the TIOCP register block as struct tiocp. The census unit holds the offsets the shipped IRIX accessors reach; this unit holds what the header defines beyond them and the constants of the provider. Names, offsets and layouts are software definitions.

Unit `tiocp_extra`, macro prefix `TIOCP`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `stat` | 0x8 | rw | 64 |  |  | unknown | established |  |
| `err_upper` | 0x10 | rw | 64 |  |  | unknown | established |  |
| `intr_upper` | 0x30 | rw | 64 |  |  | unknown | established |  |
| `tst_pin_ctrl` | 0x70 | rw | 64 |  |  | unknown | established |  |
| `pci_err_upper` | 0xd0 | rw | 64 |  |  | unknown | established |  |
| `buf_addr_match_upper` | 0x300 | rw | 64 | 16 |  | unknown | established |  |
| `buf_addr_match_lower` | 0x308 | rw | 64 | 16 |  | unknown | established |  |
| `buf_count_flush_w_touch` | 0x400 | rw | 64 | 8 |  | unknown | established |  |
| `buf_count_flush_wo_touch` | 0x408 | rw | 64 | 8 |  | unknown | established |  |
| `buf_count_inflight` | 0x410 | rw | 64 | 8 |  | unknown | established |  |
| `buf_count_prefetch` | 0x418 | rw | 64 | 8 |  | unknown | established |  |
| `buf_count_total_pci_retry` | 0x420 | rw | 64 | 8 |  | unknown | established |  |
| `buf_count_max_pci_retry` | 0x428 | rw | 64 | 8 |  | unknown | established |  |
| `buf_count_max_latency` | 0x430 | rw | 64 | 8 |  | unknown | established |  |
| `buf_count_clear_all` | 0x438 | rw | 64 | 8 |  | unknown | established |  |
| `pcix_timeout` | 0x638 | rw | 64 |  |  | unknown | established |  |
| `ct_debug_ctl` | 0x700 | rw | 64 |  |  | unknown | established |  |
| `br_debug_ctl` | 0x708 | rw | 64 |  |  | unknown | established |  |
| `mux3_debug_ctl` | 0x710 | rw | 64 |  |  | unknown | established |  |
| `mux4_debug_ctl` | 0x718 | rw | 64 |  |  | unknown | established |  |
| `mux5_debug_ctl` | 0x720 | rw | 64 |  |  | unknown | established |  |
| `mux6_debug_ctl` | 0x728 | rw | 64 |  |  | unknown | established |  |
| `mux7_debug_ctl` | 0x730 | rw | 64 |  |  | unknown | established |  |
| `pcix_read_buf_64_cp_buf_addr` | 0xa00 | rw | 64 | 16 |  | unknown | established |  |
| `pcix_read_buf_64_cp_buf_attr` | 0xa08 | rw | 64 | 16 |  | unknown | established |  |
| `pcix_write_buf_64_cp_buf_addr` | 0xb00 | rw | 64 | 8 |  | unknown | established |  |
| `pcix_write_buf_64_cp_buf_attr` | 0xb08 | rw | 64 | 8 |  | unknown | established |  |
| `pcix_write_buf_64_cp_buf_valid` | 0xb10 | rw | 64 | 8 |  | unknown | established |  |
| `int_ate_mp` | 0x14000 | rw | 64 | 1024 |  | unknown | established |  |
| `wr_req_lower` | 0x18000 | rw | 64 | 256 |  | unknown | established |  |
| `wr_req_upper` | 0x18800 | rw | 64 | 256 |  | unknown | established |  |
| `wr_req_parity` | 0x19000 | rw | 64 | 256 |  | unknown | established |  |
| `rd_resp_lower` | 0x1c000 | rw | 64 | 512 |  | unknown | established |  |
| `rd_resp_upper` | 0x1d000 | rw | 64 | 512 |  | unknown | established |  |
| `rd_resp_parity` | 0x1e000 | rw | 64 | 512 |  | unknown | established |  |

### Register `stat`

Widget status (`cp_stat`), second word of the standard widget block. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `err_upper`

Widget error address, upper word (`cp_err_upper`); the lower word is the census register `bus_err`. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `intr_upper`

Widget interrupt destination, upper word (`cp_intr_upper`); the lower word is the census register `intr_dst_target_id`. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `tst_pin_ctrl`

Test pin control (`cp_tst_pin_ctrl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `pci_err_upper`

PCI error address, upper word (`cp_pci_err_upper`); the lower word is the census register `pci_bus_addr`. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `buf_addr_match_upper`

Buffer address match registers: sixteen pairs, upper word then lower word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 16 registers, stride 16.

### Register `buf_addr_match_lower`

Buffer address match, lower words (second word of each pair). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 16 registers, stride 16.

### Register `buf_count_flush_w_touch`

Performance monitor word `flush_w_touch` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_count_flush_wo_touch`

Performance monitor word `flush_wo_touch` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_count_inflight`

Performance monitor word `inflight` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_count_prefetch`

Performance monitor word `prefetch` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_count_total_pci_retry`

Performance monitor word `total_pci_retry` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_count_max_pci_retry`

Performance monitor word `max_pci_retry` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_count_max_latency`

Performance monitor word `max_latency` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_count_clear_all`

Performance monitor word `clear_all` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `pcix_timeout`

PCI-X timeout (`cp_pcix_timeout`), eighth word of the PCI-X block. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `ct_debug_ctl`

Coretalk debug control (`cp_ct_debug_ctl`). The debug registers exist on the TIOCP only; the PIC leaves this range as padding. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `br_debug_ctl`

Bridge debug control (`cp_br_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `mux3_debug_ctl`

Debug mux control (`cp_mux3_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `mux4_debug_ctl`

Debug mux control (`cp_mux4_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `mux5_debug_ctl`

Debug mux control (`cp_mux5_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `mux6_debug_ctl`

Debug mux control (`cp_mux6_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `mux7_debug_ctl`

Debug mux control (`cp_mux7_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

### Register `pcix_read_buf_64_cp_buf_addr`

PCI-X read buffer n, address word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 16 registers, stride 16.

### Register `pcix_read_buf_64_cp_buf_attr`

PCI-X read buffer n, attribute word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 16 registers, stride 16.

### Register `pcix_write_buf_64_cp_buf_addr`

PCI-X write buffer n, address word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 8 registers, stride 32.

### Register `pcix_write_buf_64_cp_buf_attr`

PCI-X write buffer n, attribute word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 8 registers, stride 32.

### Register `pcix_write_buf_64_cp_buf_valid`

PCI-X write buffer n, valid word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 8 registers, stride 32.

### Register `int_ate_mp`

Internal translation entries with manual parity generation (`cp_int_ate_ram_mp`); the automatic-parity copy is the census register `int_ate`. No IRIX routine reaches it. Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 1024 registers, stride 8.

### Register `wr_req_lower`

Write request RAM, lower data bank (`cp_wr_req_lower`). Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 256 registers, stride 8.

### Register `wr_req_upper`

Write request RAM, upper data bank (`cp_wr_req_upper`). Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 256 registers, stride 8.

### Register `wr_req_parity`

Write request RAM, parity bank (`cp_wr_req_parity`). Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 256 registers, stride 8.

### Register `rd_resp_lower`

Read response RAM, lower data bank (`cp_rd_resp_lower`). The PIC has no read response RAM. Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 512 registers, stride 8.

### Register `rd_resp_upper`

Read response RAM, upper data bank. Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 512 registers, stride 8.

### Register `rd_resp_parity`

Read response RAM, parity bank. Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.

Array of 512 registers, stride 8.

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `ATE` | 64 | established |  |
| `CONTROL_BITS` | 64 | established |  |
| `DEVICE_BITS` | 64 | established |  |
| `ID` | 32 | established |  |
| `INT_ADDR` | 64 | established |  |
| `INT_PIN_BITS` | 64 | established |  |
| `PCI32_MAPPED_ADDR` | 32 | established |  |
| `PCI64_DMA_ADDR` | 64 | established |  |

### Word `ATE`

Low flag bits of an internal address translation entry, the 64-bit word the provider stores at the translation RAM (the internal translation RAM). The page address is the physical page number placed at bit 12 (PCI32_ATE_ADDR_SHFT is 12; the kernel ORs the page-aligned address in directly). The top of the address field and any other bits are not defined by the code (unknown). Bit 1 is a different property on the PIC (coherent).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `bar` | established |  |  | BAR attribute, set for consistent mappings; the code does not expand the name. |
| 3 | `pref` | established |  |  | Prefetch. The kernel clears it in PCI-X mode. |
| 2 | `msi` | established |  |  | Mapping is for a message-signalled interrupt. |
| 1 | `pio` | established |  |  | TIOCP only: programmed I/O. Set together with msi when the mapping is for a message-signalled interrupt. |
| 0 | `valid` | established |  |  | Entry valid. |

### Word `CONTROL_BITS`

The one bit of the control register (census register at 0x20, `cp_control`) that the Linux provider sets by name; no other control field is defined by code read for this page.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21 | `page_size` | established |  |  | I/O page size: the provider clears it for kernel pages below 16 KiB (4 KiB I/O pages) and sets it otherwise (16 KiB). |

### Word `DEVICE_BITS`

The one bit of a device register (`cp_device[n]`) the Linux provider tests. It tests a copy the firmware supplied, not a read of the register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19 | `swap_dir` | established |  |  | Direct-mapped swap: when set the provider sets the swap bit in the 32-bit mapped address it hands out. |

### Word `ID`

Widget identification word as the Linux code splits every Crosstalk-style widget id: the same layout the PIC page records. The TIOCP's own part number is not named by the v5.3 code (unknown here; the IRIX accessors accept two, see the chip page). Bit 0 and the layout of the upper half of the 64-bit register are not defined by the code.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `rev` | established |  |  | Revision. The flush workaround is keyed by the revision of the TIO, not of this widget. |
| 27:12 | `part` | established |  |  |  |
| 11:1 | `mfg` | established |  |  |  |

### Word `INT_ADDR`

Per-pin interrupt address register (`cp_int_addr[n]`). The provider clears the destination field, then ORs in the Crosstalk address the pin's interrupt write goes to, masked to the field. Other bits are preserved and not defined by the code.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 53:0 | `addr` | established |  |  | Destination address of the interrupt write; 48 bits on the PIC. |

### Word `INT_PIN_BITS`

Layout of the interrupt enable register: one bit per bridge interrupt pin (the status register is likely to use the same pin bits, inferred; no code read tests it), numbered as the pin's per-pin address register (`cp_int_addr[n]`) and force register (`cp_force_pin[n]`). The provider sets and clears bit n of the enable register with the pin number from the firmware-supplied interrupt record. Upper bits (error interrupts) are not named by the code (unknown).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `pin` | established |  |  | Pin n at bit n, n from 0 to 7 (the arrays have eight entries). |

### Word `PCI32_MAPPED_ADDR`

A 32-bit bus address the provider hands out for a translation-entry mapping: 0x40000000 plus the offset in the page plus the I/O page size times the entry index, with bit 29 set when the device's endian swap is on. Addresses from 0x80000000 are the 2 GiB direct window (PCI32_DIRECT_BASE) instead. The kernel refuses the 2 GiB direct window in PCI-X mode on either chip and refuses entry mappings in PCI-X mode on the PIC only, so the TIOCP maps 32-bit addresses through entries there.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 29 | `swap` | established |  |  | Swap on: set by the provider when the device register has its direction-swap bit. |

### Word `PCI64_DMA_ADDR`

The 64-bit direct DMA address a device is given: the DMA view of the memory address with attribute bits ORed in. On the PIC bits 63:60 name the target widget instead of the command type. Memory address width and the meaning of bits 63:62 are not defined by the code (unknown).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61:60 | `cmdtype` | established |  |  | Command type: 1 memory, 3 message-signalled interrupt (constants PCI64_CMDTYPE_MEM and _MSI). |
| 59 | `pref` | established |  |  | Prefetch. The kernel clears it in PCI-X mode. |
| 58 | `prec` | established |  |  | PREC attribute. Declared; no code read sets it. |
| 57 | `virtual` | established |  |  | Virtual channel 1. The kernel sets it in conventional PCI mode for functions other than zero. |
| 56 | `bar` | established |  |  | BAR attribute, set for consistent mappings; the code does not expand the name. |
| 55 | `swap` | established |  |  | Byte swap. Declared; no code read sets it. |
| 54 | `virtual1` | established |  |  | Second virtual-channel bit. Declared; no code read sets it. |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ATE_MSI` | 0x4 | established |  | Bit 2 of a translation entry: message-signalled interrupt. |
| `ATE_PIO` | 0x2 | established |  | Bit 1 of a translation entry on the TIOCP: programmed I/O. The kernel sets it together with the MSI bit when mapping for a message-signalled interrupt. The same bit is "coherent" on the PIC. |
| `CFG_TYPE0_BASE` | 0x21000 | established |  | Base of seven type-0 configuration windows of 0x1000 bytes (eight functions of 0x100 each); the 0x1000 bytes just below it are the host device window, marked not used. The PIC has eight windows from the lower base. |
| `CFG_TYPE1_BASE` | 0x28000 | established |  | Base of the 0x1000-byte type-1 configuration window. |
| `DEVIO_BASE` | 0x200000 | established |  | Six device I/O spaces of 1 MiB from here to 0x7fffff. Device n uses raw window 2n for n below 2 and n + 2 otherwise, so devices 0 to 3 are windows 0, 2, 4, 5. |
| `DEVIO_FLUSH_BASE` | 0xa00000 | established |  | The same six spaces again with flush, 1 MiB each from here to 0xbfffff, same window numbering. |
| `HOST_INTR_ADDR_MASK` | 0x3fffffffffffff | established |  | Mask of the destination address field of a per-pin interrupt address register: 54 bits on the TIOCP, 48 on the PIC. |
| `PCI64_CMDTYPE_MEM` | 0x1000000000000000 | established |  | Command type 1, memory, in bits 61:60 of a 64-bit direct address. Instead of the PIC's target widget field. |
| `PCI64_CMDTYPE_MSI` | 0x3000000000000000 | established |  | Command type 3, message-signalled interrupt, in bits 61:60. |
| `PCIX_SPECIAL_CYCLE_BASE` | 0x40000 | established |  | Eight-byte PCI-X special cycle window. |
| `PCI_IACK_BASE` | 0x30000 | established |  | Eight-byte PCI interrupt acknowledge window. |
| `WAR_PV907516` | 0x2 | established |  | Workaround mask keyed by the TIO's revision number (one bit per revision): on revision 1 the kernel must not read the per-device write-request flush register (cp_wr_req_buf) for read-ordering. On other revisions that read is the ordering primitive. |
