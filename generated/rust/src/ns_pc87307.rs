// @generated from devices/ns-pc87307/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 fdc452855d3492175a63ce3946a9d26e06e456dfb5396f49a49e4e0a4620bb82
// National Semiconductor PC87307 Super I/O (marked NS87307) as wired in the Visual Workstation 320 and 540
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// Plug and Play set RD_DATA port, used only by the Plug and Play ISA protocol. Bits 1 and 0 are fixed at 11. (established)
pub mod pnp_rd_data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
}
/// Plug and Play serial isolation, used only by the Plug and Play ISA protocol. (established)
pub mod pnp_isolation {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
}
/// Configuration control, write only, self-clearing. Bit 0 resets all logical devices and restores the configuration registers to their reset values (the (established)
pub mod cfg_control {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
    pub mod reset_csn { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wait_key { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reset { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Plug and Play Wake[CSN], write only. (established)
pub mod pnp_wake {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
}
/// Plug and Play resource data, read only. (established)
pub mod pnp_resource {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4;
}
/// Plug and Play status, read only. (established)
pub mod pnp_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x5;
}
/// Card select number, used by the Plug and Play ISA protocol. (established)
pub mod csn {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6;
}
/// Logical device number: selects which logical device's registers the indexes 0x30 to 0xff address. The HAL writes 0, 5, 6, 3, 4 and 1 to steer IRQs 1,  (established)
pub mod ldn {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7;
}
/// Identification. In the PC87307 bits 7:5 are the chip identification and bits 4:0 the revision, and the register reads 0xc0. In the PC97307 all eight b (established)
pub mod sid {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x20;
    pub mod chip_id { // bits 7:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod revision { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// SuperI/O configuration 1. Reset is 0x04, 0x06, 0x14 or 0x16 depending on the SELCS and CFG1 straps, whose board settings are not known. A soft reset h (established)
pub mod sioc1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x21;
    pub mod scratch { // bits 7:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lock_scratch { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xdb_sel { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pcat_mode { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cs0_sel { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod zws_en { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// SuperI/O configuration 2. Reset is 0x00 to 0x03: bits 1:0 reflect the base address straps (11 is the 0x2e pair). The datasheet says the BIOS may switc (established)
pub mod sioc2 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x22;
    pub mod gpio_bank { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wdo_sel { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpio20_pin { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpio21_sel { // bits 4:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpio22_pin { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod baddr { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Programmable chip select configuration index: the second-level index of the chip select register that the data register reaches. Bits 7:4 read 0. (established)
pub mod cs_index {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x23;
}
/// Programmable chip select configuration data: the register named by the index above. (established)
pub mod cs_data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x24;
}
/// Chip revision identification, PC97307 only: incremented on each tapeout. (established)
pub mod srid {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x27;
}
/// Configuration index register. A write selects the configuration register the data port then reaches; a read returns the last index written. Reset: the (established)
pub mod cfg_index {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
}
/// Configuration data register: reads and writes the register selected by the index. Reserved bits must be preserved, so software uses read-modify-write. (established)
pub mod cfg_data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
}
/// CS0, CS1 and CS2 base address, most significant byte (second-level indexes 0x00, 0x04 and 0x08). (established)
pub mod cs_base_msb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 4;
}
/// CS0, CS1 and CS2 base address, least significant byte (indexes 0x01, 0x05, 0x09). (established)
pub mod cs_base_lsb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 4;
}
/// CS0, CS1 and CS2 configuration (indexes 0x02, 0x06, 0x0a). The board's use of the chip selects is not known. (established)
pub mod cs_config {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 4;
    pub mod mask_a11_0 { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ignore_rdwr { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod on_read { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod on_write { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mask_a3 { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mask_a2 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mask_a1 { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mask_a0 { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Port 1 data. A read returns the pin for an input bit and the latch for an output bit; a write latches the value and drives output pins only. The write (established)
pub mod p1_data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub mod board_rev { // bits 6:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Port 1 direction: 0 input, 1 output. (established)
pub mod p1_dir {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
}
/// Port 1 output type: 0 open-drain, 1 push-pull. (established)
pub mod p1_otype {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
}
/// Port 1 pull-up control: 0 none, 1 internal pull-up. (established)
pub mod p1_pullup {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
}
/// Port 2 data, as port 1. (established)
pub mod p2_data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4;
}
/// Port 2 direction. (established)
pub mod p2_dir {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x5;
}
/// Port 2 output type. (established)
pub mod p2_otype {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6;
}
/// Port 2 pull-up control. (established)
pub mod p2_pullup {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7;
}
/// Port 1 lock. Bits 7 and 6 lock the direction and pull-up bits of GPIO17 and GPIO16, and for outputs the pin value and buffer type. Only a hardware (ma (established)
pub mod p1_lock {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub mod lock17 { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lock16 { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Activate (bit 0). The PROM activates it; the HAL selects it to steer IRQ 1. Reset 0 or 1 according to the CFG0 strap (the board's strap is not known); (established)
pub mod ld0_activate {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x30;
    pub mod active { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7: (established)
pub mod ld0_iorc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x31;
    pub mod enable { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Base address bits 15:8. (established)
pub mod ld0_base_msb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x60;
}
/// Base address bits 7:0; the low bits are read only and the decoder ignores them. (established)
pub mod ld0_base_lsb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x61;
}
/// Command window base address bits 15:8. (established)
pub mod ld0_cmd_base_msb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x62;
}
/// Command window base address bits 7:0; bit 2 reads 1. The reset reads 0x64 (the table prints it as 64). (established)
pub mod ld0_cmd_base_lsb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x63;
}
/// Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type regi (established)
pub mod ld0_irq {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x70;
    pub mod line { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are wri (established)
pub mod ld0_irq_type {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x71;
    pub mod polarity { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod level { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// DMA channel select 0: bits 2:0, 4 means none. Read only. (established)
pub mod ld0_dma0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x74;
}
/// DMA channel select 1: bits 2:0, 4 means none. Read only. (established)
pub mod ld0_dma1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x75;
}
/// Keyboard controller configuration: bits 7:6 pick the clock source (00 8 MHz, 01 12 MHz, 10 16 MHz, only with the keyboard controller inactive). (established)
pub mod ld0_config {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xf0;
    pub mod clk { // bits 7:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Activate (bit 0). The HAL selects it to steer IRQ 12. The device is active only when its function enable bit in the power management block is also set (established)
pub mod ld1_activate {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x30;
    pub mod active { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type regi (established)
pub mod ld1_irq {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x70;
    pub mod line { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are wri (established)
pub mod ld1_irq_type {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x71;
    pub mod polarity { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod level { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// DMA channel select 0: bits 2:0, 4 means none. Read only. (established)
pub mod ld1_dma0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x74;
}
/// DMA channel select 1: bits 2:0, 4 means none. Read only. (established)
pub mod ld1_dma1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x75;
}
/// Activate (bit 0). The PROM activates it. Reset 0 or 1 according to the CFG0 strap (the board's strap is not known); the device is active only when its (established)
pub mod ld2_activate {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x30;
    pub mod active { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7: (established)
pub mod ld2_iorc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x31;
    pub mod enable { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Base address bits 15:8. (established)
pub mod ld2_base_msb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x60;
}
/// Base address bits 7:0; the low bits are read only and the decoder ignores them. (established)
pub mod ld2_base_lsb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x61;
}
/// Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type regi (established)
pub mod ld2_irq {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x70;
    pub mod line { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are wri (established)
pub mod ld2_irq_type {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x71;
    pub mod polarity { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod level { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// DMA channel select 0: bits 2:0, 4 means none. Read only. (established)
pub mod ld2_dma0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x74;
}
/// DMA channel select 1: bits 2:0, 4 means none. Read only. (established)
pub mod ld2_dma1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x75;
}
/// Activate (bit 0). The PROM activates it and its ARC tree lists a floppy controller at the usual 0x3f2 window; the HAL selects it to steer IRQ 6. Reset (established)
pub mod ld3_activate {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x30;
    pub mod active { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7: (established)
pub mod ld3_iorc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x31;
    pub mod enable { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Base address bits 15:8. (established)
pub mod ld3_base_msb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x60;
}
/// Base address bits 7:0; the low bits are read only and the decoder ignores them. (established)
pub mod ld3_base_lsb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x61;
}
/// Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type regi (established)
pub mod ld3_irq {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x70;
    pub mod line { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are wri (established)
pub mod ld3_irq_type {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x71;
    pub mod polarity { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod level { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// DMA channel select 0: bits 2:0, 4 means none. (established)
pub mod ld3_dma0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x74;
}
/// DMA channel select 1: bits 2:0, 4 means none. Read only. (established)
pub mod ld3_dma1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x75;
}
/// Floppy configuration: tri-state, DENSEL polarity, TDR mode and four-drive encode. (established)
pub mod ld3_config {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xf0;
    pub mod four_drive { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tdr_enh { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod densel_pol { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tristate { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Drive ID register: drive 0 and drive 1 identification bits reflected in the tape drive register. (established)
pub mod ld3_drive_id {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xf1;
    pub mod drive1 { // bits 3:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod drive0 { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Activate (bit 0). The PROM activates it. Its ARC tree lists the parallel port at the PC's first address 0x378, not the reset base 0x278, so the PROM's (established)
pub mod ld4_activate {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x30;
    pub mod active { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7: (established)
pub mod ld4_iorc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x31;
    pub mod enable { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Base address bits 15:8. (established)
pub mod ld4_base_msb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x60;
}
/// Base address bits 7:0; the low bits are read only and the decoder ignores them. (established)
pub mod ld4_base_lsb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x61;
}
/// Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type regi (established)
pub mod ld4_irq {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x70;
    pub mod line { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are wri (established)
pub mod ld4_irq_type {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x71;
    pub mod polarity { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod level { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// DMA channel select 0: bits 2:0, 4 means none. (established)
pub mod ld4_dma0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x74;
}
/// DMA channel select 1: bits 2:0, 4 means none. Read only. (established)
pub mod ld4_dma1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x75;
}
/// Parallel port configuration. Bits 7:4 must not be changed for normal operation. Reset 0xf2: mode select 111 (IEEE 1284 with EPP selectable), configura (established)
pub mod ld4_config {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xf0;
    pub mod mode { // bits 7:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const SPP: u32 = 0; // established
        pub const SPP_EXT: u32 = 1; // established
        pub const EPP17: u32 = 2; // established
        pub const EPP19: u32 = 3; // established
        pub const IEEE1284: u32 = 4; // established
        pub const IEEE1284_EPP: u32 = 7; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Spp,
            SppExt,
            Epp17,
            Epp19,
            Ieee1284,
            Ieee1284Epp,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Spp,
                    1 => Self::SppExt,
                    2 => Self::Epp17,
                    3 => Self::Epp19,
                    4 => Self::Ieee1284,
                    7 => Self::Ieee1284Epp,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Spp => 0,
                    Self::SppExt => 1,
                    Self::Epp17 => 2,
                    Self::Epp19 => 3,
                    Self::Ieee1284 => 4,
                    Self::Ieee1284Epp => 7,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod cfg_regs { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pnp_spp { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod clk_en { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tristate { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Activate (bit 0). COM2 at 0x2f8, IRQ 3 (the reset values); the PROM activates it. The device is active only when its function enable bit in the power  (established)
pub mod ld5_activate {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x30;
    pub mod active { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7: (established)
pub mod ld5_iorc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x31;
    pub mod enable { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Base address bits 15:8. (established)
pub mod ld5_base_msb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x60;
}
/// Base address bits 7:0; the low bits are read only and the decoder ignores them. (established)
pub mod ld5_base_lsb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x61;
}
/// Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type regi (established)
pub mod ld5_irq {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x70;
    pub mod line { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are wri (established)
pub mod ld5_irq_type {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x71;
    pub mod polarity { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod level { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// DMA channel select 0: bits 2:0, 4 means none. (established)
pub mod ld5_dma0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x74;
}
/// DMA channel select 1: bits 2:0, 4 means none. (established)
pub mod ld5_dma1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x75;
}
/// UART configuration. The datasheet gives reset 0x02 in Sections 2.8.1 and 2.9.1 and 0x00 in its bitmap summary; this unit takes 0x02 (the tables and se (established)
pub mod ld5_config {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xf0;
    pub mod bank_en { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ring_pin { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod busy { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod power { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tristate { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Activate (bit 0). COM1 at 0x3f8, IRQ 4 (the reset values); the PROM's serial console, activated by the boot block and again by the self-test. The devi (established)
pub mod ld6_activate {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x30;
    pub mod active { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7: (established)
pub mod ld6_iorc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x31;
    pub mod enable { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Base address bits 15:8. (established)
pub mod ld6_base_msb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x60;
}
/// Base address bits 7:0; the low bits are read only and the decoder ignores them. (established)
pub mod ld6_base_lsb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x61;
}
/// Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type regi (established)
pub mod ld6_irq {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x70;
    pub mod line { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are wri (established)
pub mod ld6_irq_type {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x71;
    pub mod polarity { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod level { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// DMA channel select 0: bits 2:0, 4 means none. Read only. (established)
pub mod ld6_dma0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x74;
}
/// DMA channel select 1: bits 2:0, 4 means none. Read only. (established)
pub mod ld6_dma1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x75;
}
/// UART configuration. The datasheet gives reset 0x02 in Sections 2.8.1 and 2.9.1 and 0x00 in its bitmap summary; this unit takes 0x02 (the tables and se (established)
pub mod ld6_config {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xf0;
    pub mod bank_en { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ring_pin { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod busy { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod power { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tristate { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Activate (bit 0). The PROM and Linux write the base 0xfc0 and activate it; the board revision is read from its data byte. The device is active only wh (established)
pub mod ld7_activate {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x30;
    pub mod active { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7: (established)
pub mod ld7_iorc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x31;
    pub mod enable { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Base address bits 15:8. (established)
pub mod ld7_base_msb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x60;
}
/// Base address bits 7:0; the low bits are read only and the decoder ignores them. (established)
pub mod ld7_base_lsb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x61;
}
/// DMA channel select 0: bits 2:0, 4 means none. Read only. (established)
pub mod ld7_dma0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x74;
}
/// DMA channel select 1: bits 2:0, 4 means none. Read only. (established)
pub mod ld7_dma1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x75;
}
/// Activate (bit 0). The PROM and Linux write the base 0xfc8 and activate it; Linux and the PROM then write function enable register 2. When clear, the p (established)
pub mod ld8_activate {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x30;
    pub mod active { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7: (established)
pub mod ld8_iorc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x31;
    pub mod enable { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Base address bits 15:8. (established)
pub mod ld8_base_msb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x60;
}
/// Base address bits 7:0; the low bits are read only and the decoder ignores them. (established)
pub mod ld8_base_lsb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x61;
}
/// DMA channel select 0: bits 2:0, 4 means none. Read only. (established)
pub mod ld8_dma0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x74;
}
/// DMA channel select 1: bits 2:0, 4 means none. Read only. (established)
pub mod ld8_dma1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x75;
}
/// Function enable register 1. A logical device is active only while its activate bit and its enable bit here are both set. Hardware resets it to 0xff. (established)
pub mod fer1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub mod uart1 { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uart2 { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pp { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fdc { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod kbc { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Function enable register 2. Linux and the PROM write bit 7 set (Linux's comment: it enables access to the GPIO registers). Hardware resets it to 0xff  (established)
pub mod fer2 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
    pub mod gpio { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cs2 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cs1 { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cs0 { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Power management control 1: tri-state controls for the floppy, parallel and UART pins, ORed with the logical devices' own bits. (established)
pub mod pmc1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
    pub mod uart1_tri { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uart2_tri { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pp_tri { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fdc_tri { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Power management control 2: clock source and clock multiplier. Bits 2:0 follow the CFG3 and CFG2 straps at reset, whose board settings are not known. (established)
pub mod pmc2 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
    pub mod mult_valid { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mult_en { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod clk_src { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const X1_24MHZ: u32 = 0; // established
        pub const X1_48MHZ: u32 = 2; // established
        pub const MULTIPLIER: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            X124mhz,
            X148mhz,
            Multiplier,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::X124mhz,
                    2 => Self::X148mhz,
                    3 => Self::Multiplier,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::X124mhz => 0,
                    Self::X148mhz => 2,
                    Self::Multiplier => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
}
/// Power management control 3: parallel port, UART2 and UART1 clock enables (ANDed with the devices' own bits) and read-only busy flags. (established)
pub mod pmc3 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4;
    pub mod uart1_busy { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uart2_busy { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uart1_clk { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uart2_clk { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pp_clk { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Watchdog time-out in minutes; 0 stops the watchdog. Also cleared when the power management device is activated. (established)
pub mod wdto {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x5;
}
/// Watchdog configuration: which interrupts reload the timer. (established)
pub mod wdcf {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6;
    pub mod uart2 { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uart1 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mouse { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod kbc { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Watchdog status. Bit 0 is the watchdog output (1 inactive). Section 9.1.2 says bit 1; the register description and bitmap say bit 0. Whether the outpu (established)
pub mod wdst {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7;
    pub mod wdo { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Power management index register: selects the register the data port reaches. Bits 7:3 read 0. (established)
pub mod pm_index {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
}
/// Power management data register. (established)
pub mod pm_data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
}
pub const CFG_DATA_PORT: u32 = 0x2f; // established
pub const CFG_INDEX_PORT: u32 = 0x2e; // established
pub const GPIO_BASE: u32 = 0xfc0; // established
pub const PM_BASE: u32 = 0xfc8; // established

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn sid_c0() {
        assert_eq!(sid::chip_id::get(0xc0), 6);
        assert_eq!(sid::revision::get(0xc0), 0);
    }

    #[test]
    fn ld4_config_f2() {
        assert_eq!(ld4_config::tristate::get(0xf2), 0);
        assert_eq!(ld4_config::clk_en::get(0xf2), 1);
        assert_eq!(ld4_config::pnp_spp::get(0xf2), 0);
        assert_eq!(ld4_config::cfg_regs::get(0xf2), 1);
        assert_eq!(ld4_config::mode::get(0xf2), 7);
    }
}
