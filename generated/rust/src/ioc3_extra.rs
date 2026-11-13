// generated from devices/ioc3/registers-extra.toml by defs-gen - do not edit, change the source
// IOC3 registers outside the census
#![allow(dead_code)]

/// The 32-bit microlan control register the shipped IRIX one-wire access routine drives: it writes the pulse width shifted left 10 ORed with the sample t (established)
pub mod one_wire_ctl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
    pub mod pulse { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sample { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod done { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod result { // bits 0:0, established
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
/// (established)
pub mod plp_a_addr_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80;
}
/// (established)
pub mod plp_a_addr_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x84;
}
/// (established)
pub mod plp_a_count {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x88;
}
/// (established)
pub mod plp_ctl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8c;
}
/// (established)
pub mod plp_b_addr_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x90;
}
/// (established)
pub mod plp_b_addr_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x94;
}
/// (established)
pub mod plp_b_count {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x98;
}
/// (established)
pub mod km_rx_kbd {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa0;
}
/// (established)
pub mod km_rx_mouse {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa4;
}
/// (established)
pub mod km_tx_kbd {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa8;
}
/// (established)
pub mod km_tx_mouse {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xac;
}
/// Layout of the general-purpose control set alias, gpcr_s (offset 0x34), as the shipped IRIX one-wire routine writes it. Before reading the address part (inferred)
pub mod gpcr_s_format {
    pub const WIDTH: u32 = 32;
    pub mod nic_enable { // bits 21:21, inferred
        pub const SHIFT: u32 = 21;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const GPCR_S_MICROLAN_ROUTE_BIT: u32 = 0x200000; // inferred
pub const GPCR_S_NIC_ENABLE_WORD: u32 = 0x200000; // established
pub const GPPR_LIGHTBAR_RED_PIN: u32 = 0x1; // inferred
pub const GPPR_LIGHTBAR_WHITE_PIN: u32 = 0x0; // inferred
pub const GPPR_MEANINGFUL_MASK: u32 = 0x1ff; // inferred
pub const GPPR_MICROLAN_PIN: u32 = 0x8; // inferred
pub const GPPR_PHY_RESET_PIN: u32 = 0x5; // inferred
pub const GPPR_UARTA_MODESEL_PIN: u32 = 0x7; // inferred
pub const GPPR_UARTB_MODESEL_PIN: u32 = 0x6; // inferred
pub const INT_OUT_COUNT_MASK: u32 = 0xffff; // inferred
pub const INT_OUT_DIAG_BIT: u32 = 0x40000000; // inferred
pub const INT_OUT_MODE_HIGH: u32 = 0x4; // inferred
pub const INT_OUT_MODE_LOW: u32 = 0x0; // inferred
pub const INT_OUT_MODE_MASK: u32 = 0x70000; // inferred
pub const INT_OUT_MODE_ONE_PULSE: u32 = 0x5; // inferred
pub const INT_OUT_MODE_PULSE_TRAIN: u32 = 0x6; // inferred
pub const INT_OUT_MODE_SQUARE: u32 = 0x7; // inferred
pub const INT_OUT_PIN0_ROUTE_BIT: u32 = 0x100000; // inferred
pub const INT_OUT_PULSE_TICKS: u32 = 0x3; // inferred
pub const INT_OUT_STATE_BIT: u32 = 0x80000000; // inferred
pub const INT_OUT_TICK_NS: u32 = 0x1e78; // inferred
pub const PORT_CTL_CARRIER_REQ_BIT: u32 = 0x40000; // inferred
pub const PORT_CTL_CTS_REQ_BIT: u32 = 0x80000; // inferred
pub const PORT_CTL_FLOW_CTL_BIT: u32 = 0x20000; // inferred
pub const PORT_CTL_HIGH_WATER_MASK: u32 = 0x1ff; // inferred
pub const PORT_CTL_QUAD_SPEED_BIT: u32 = 0x100000; // inferred
pub const PORT_CTL_RING_DMA_EN_BIT: u32 = 0x10000000; // inferred
pub const SIO_CR_ARBITER_IDLE_BIT: u32 = 0x400000; // inferred
pub const SIO_CR_REQUESTER_MASK: u32 = 0x380000; // inferred
pub const SIO_CR_RESET_BIT: u32 = 0x1; // inferred
pub const SIO_CR_SER_A_BASE_MASK: u32 = 0xfe; // inferred
pub const SIO_CR_SER_B_BASE_MASK: u32 = 0x7f00; // inferred
pub const SIO_CR_STROBE_MASK: u32 = 0x78000; // inferred
pub const SIO_IR_SRC_A_CARRIER: u32 = 0x10; // inferred
pub const SIO_IR_SRC_A_CTS: u32 = 0x20; // inferred
pub const SIO_IR_SRC_A_PCI_ERR: u32 = 0x100; // inferred
pub const SIO_IR_SRC_A_RX_FULL: u32 = 0x2; // inferred
pub const SIO_IR_SRC_A_RX_HIGH: u32 = 0x4; // inferred
pub const SIO_IR_SRC_A_RX_TIMER: u32 = 0x8; // inferred
pub const SIO_IR_SRC_A_TX_DONE: u32 = 0x80; // inferred
pub const SIO_IR_SRC_A_TX_EMPTY: u32 = 0x1; // inferred
pub const SIO_IR_SRC_A_UART: u32 = 0x40; // inferred
pub const SIO_IR_SRC_B_CARRIER: u32 = 0x2000; // inferred
pub const SIO_IR_SRC_B_CTS: u32 = 0x4000; // inferred
pub const SIO_IR_SRC_B_PCI_ERR: u32 = 0x20000; // inferred
pub const SIO_IR_SRC_B_RX_FULL: u32 = 0x400; // inferred
pub const SIO_IR_SRC_B_RX_HIGH: u32 = 0x800; // inferred
pub const SIO_IR_SRC_B_RX_TIMER: u32 = 0x1000; // inferred
pub const SIO_IR_SRC_B_TX_DONE: u32 = 0x10000; // inferred
pub const SIO_IR_SRC_B_TX_EMPTY: u32 = 0x200; // inferred
pub const SIO_IR_SRC_B_UART: u32 = 0x8000; // inferred
pub const SIO_IR_SRC_KBD: u32 = 0x400000; // inferred
pub const SIO_IR_SRC_PP_PASSTHRU: u32 = 0x40000; // inferred
pub const SIO_IR_SRC_PP_PCI_ERR: u32 = 0x200000; // inferred
pub const SIO_IR_SRC_RT_IN_PULSE: u32 = 0x10000000; // inferred
pub const SIO_IR_SRC_RT_OUT_PULSE: u32 = 0x8000000; // inferred
