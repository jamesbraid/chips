/* generated from devices/ns-pc87307/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 fdc452855d3492175a63ce3946a9d26e06e456dfb5396f49a49e4e0a4620bb82 */
/* National Semiconductor PC87307 Super I/O (marked NS87307) as wired in the Visual Workstation 320 and 540 */
#ifndef PC87307_GEN_H
#define PC87307_GEN_H

#include <stdint.h>


/*
 * Plug and Play set RD_DATA port, used only by the Plug and Play ISA protocol. Bits 1 and 0 are fixed at 11.
 */
/* pnp_rd_data: w8, space pc87307_card, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27 */
#define PC87307_PNP_RD_DATA_OFFSET                   0x0u /* established */

/*
 * Plug and Play serial isolation, used only by the Plug and Play ISA protocol.
 */
/* pnp_isolation: r8, space pc87307_card, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27 */
#define PC87307_PNP_ISOLATION_OFFSET                 0x1u /* established */

/*
 * Configuration control, write only, self-clearing. Bit 0 resets all logical devices and restores the configuration registers to their reset values (the soft reset); bit 1 returns the cards to the Wait for Key state and bit 2 resets the card select number, both only meaningful in Plug and Play ISA mode.
 */
/* cfg_control: w8, space pc87307_card, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27, 30 */
#define PC87307_CFG_CONTROL_OFFSET                   0x2u /* established */
#define PC87307_CFG_CONTROL_RESET_CSN_SHIFT          2 /* established */
#define PC87307_CFG_CONTROL_RESET_CSN_MASK           0x1u
#define PC87307_CFG_CONTROL_RESET_CSN_INPLACE        (PC87307_CFG_CONTROL_RESET_CSN_MASK << PC87307_CFG_CONTROL_RESET_CSN_SHIFT)
#define PC87307_CFG_CONTROL_WAIT_KEY_SHIFT           1 /* established */
#define PC87307_CFG_CONTROL_WAIT_KEY_MASK            0x1u
#define PC87307_CFG_CONTROL_WAIT_KEY_INPLACE         (PC87307_CFG_CONTROL_WAIT_KEY_MASK << PC87307_CFG_CONTROL_WAIT_KEY_SHIFT)
#define PC87307_CFG_CONTROL_RESET_SHIFT              0 /* established */
#define PC87307_CFG_CONTROL_RESET_MASK               0x1u
#define PC87307_CFG_CONTROL_RESET_INPLACE            (PC87307_CFG_CONTROL_RESET_MASK << PC87307_CFG_CONTROL_RESET_SHIFT)

/*
 * Plug and Play Wake[CSN], write only.
 */
/* pnp_wake: w8, space pc87307_card, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27 */
#define PC87307_PNP_WAKE_OFFSET                      0x3u /* established */

/*
 * Plug and Play resource data, read only.
 */
/* pnp_resource: r8, space pc87307_card, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27 */
#define PC87307_PNP_RESOURCE_OFFSET                  0x4u /* established */

/*
 * Plug and Play status, read only.
 */
/* pnp_status: r8, space pc87307_card, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27 */
#define PC87307_PNP_STATUS_OFFSET                    0x5u /* established */

/*
 * Card select number, used by the Plug and Play ISA protocol.
 */
/* csn: rw8, space pc87307_card, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27, 30 */
#define PC87307_CSN_OFFSET                           0x6u /* established */

/*
 * Logical device number: selects which logical device's registers the indexes 0x30 to 0xff address. The HAL writes 0, 5, 6, 3, 4 and 1 to steer IRQs 1, 3, 4, 6, 7 and 12; the PROM and Linux write 7 and 8 to set the GPIO and power management bases.
 */
/* ldn: rw8, space pc87307_card, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27, 30 */
#define PC87307_LDN_OFFSET                           0x7u /* established */

/*
 * Identification. In the PC87307 bits 7:5 are the chip identification and bits 4:0 the revision, and the register reads 0xc0. In the PC97307 all eight bits are the chip identification and it reads 0xcf. Reset 0xc0 is the PC87307's. The reset of 0xc0 is inferred on the reading that the board part is a PC87307 (the board's documents say NS87307).
 */
/* sid: r8, space pc87307_card, reset 0xc0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 */
#define PC87307_SID_OFFSET                           0x20u /* established */
#define PC87307_SID_CHIP_ID_SHIFT                    5 /* established */
#define PC87307_SID_CHIP_ID_MASK                     0x7u
#define PC87307_SID_CHIP_ID_INPLACE                  (PC87307_SID_CHIP_ID_MASK << PC87307_SID_CHIP_ID_SHIFT)
#define PC87307_SID_REVISION_SHIFT                   0 /* established */
#define PC87307_SID_REVISION_MASK                    0x1fu
#define PC87307_SID_REVISION_INPLACE                 (PC87307_SID_REVISION_MASK << PC87307_SID_REVISION_SHIFT)

/*
 * SuperI/O configuration 1. Reset is 0x04, 0x06, 0x14 or 0x16 depending on the SELCS and CFG1 straps, whose board settings are not known. A soft reset has no effect.
 */
/* sioc1: rw8, space pc87307_card, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34-35 */
#define PC87307_SIOC1_OFFSET                         0x21u /* established */
#define PC87307_SIOC1_SCRATCH_SHIFT                  6 /* established */
#define PC87307_SIOC1_SCRATCH_MASK                   0x3u
#define PC87307_SIOC1_SCRATCH_INPLACE                (PC87307_SIOC1_SCRATCH_MASK << PC87307_SIOC1_SCRATCH_SHIFT)
#define PC87307_SIOC1_LOCK_SCRATCH_SHIFT             5 /* established */
#define PC87307_SIOC1_LOCK_SCRATCH_MASK              0x1u
#define PC87307_SIOC1_LOCK_SCRATCH_INPLACE           (PC87307_SIOC1_LOCK_SCRATCH_MASK << PC87307_SIOC1_LOCK_SCRATCH_SHIFT)
#define PC87307_SIOC1_XDB_SEL_SHIFT                  4 /* established */
#define PC87307_SIOC1_XDB_SEL_MASK                   0x1u
#define PC87307_SIOC1_XDB_SEL_INPLACE                (PC87307_SIOC1_XDB_SEL_MASK << PC87307_SIOC1_XDB_SEL_SHIFT)
#define PC87307_SIOC1_PCAT_MODE_SHIFT                2 /* established */
#define PC87307_SIOC1_PCAT_MODE_MASK                 0x1u
#define PC87307_SIOC1_PCAT_MODE_INPLACE              (PC87307_SIOC1_PCAT_MODE_MASK << PC87307_SIOC1_PCAT_MODE_SHIFT)
#define PC87307_SIOC1_CS0_SEL_SHIFT                  1 /* established */
#define PC87307_SIOC1_CS0_SEL_MASK                   0x1u
#define PC87307_SIOC1_CS0_SEL_INPLACE                (PC87307_SIOC1_CS0_SEL_MASK << PC87307_SIOC1_CS0_SEL_SHIFT)
#define PC87307_SIOC1_ZWS_EN_SHIFT                   0 /* established */
#define PC87307_SIOC1_ZWS_EN_MASK                    0x1u
#define PC87307_SIOC1_ZWS_EN_INPLACE                 (PC87307_SIOC1_ZWS_EN_MASK << PC87307_SIOC1_ZWS_EN_SHIFT)

/*
 * SuperI/O configuration 2. Reset is 0x00 to 0x03: bits 1:0 reflect the base address straps (11 is the 0x2e pair). The datasheet says the BIOS may switch the index and data ports to the Plug and Play addresses by changing these bits. A soft reset has no effect.
 */
/* sioc2: rw8, space pc87307_card, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.35 */
#define PC87307_SIOC2_OFFSET                         0x22u /* established */
#define PC87307_SIOC2_GPIO_BANK_SHIFT                7 /* established */
#define PC87307_SIOC2_GPIO_BANK_MASK                 0x1u
#define PC87307_SIOC2_GPIO_BANK_INPLACE              (PC87307_SIOC2_GPIO_BANK_MASK << PC87307_SIOC2_GPIO_BANK_SHIFT)
#define PC87307_SIOC2_WDO_SEL_SHIFT                  6 /* established */
#define PC87307_SIOC2_WDO_SEL_MASK                   0x1u
#define PC87307_SIOC2_WDO_SEL_INPLACE                (PC87307_SIOC2_WDO_SEL_MASK << PC87307_SIOC2_WDO_SEL_SHIFT)
#define PC87307_SIOC2_GPIO20_PIN_SHIFT               5 /* established */
#define PC87307_SIOC2_GPIO20_PIN_MASK                0x1u
#define PC87307_SIOC2_GPIO20_PIN_INPLACE             (PC87307_SIOC2_GPIO20_PIN_MASK << PC87307_SIOC2_GPIO20_PIN_SHIFT)
#define PC87307_SIOC2_GPIO21_SEL_SHIFT               3 /* established */
#define PC87307_SIOC2_GPIO21_SEL_MASK                0x3u
#define PC87307_SIOC2_GPIO21_SEL_INPLACE             (PC87307_SIOC2_GPIO21_SEL_MASK << PC87307_SIOC2_GPIO21_SEL_SHIFT)
#define PC87307_SIOC2_GPIO22_PIN_SHIFT               2 /* established */
#define PC87307_SIOC2_GPIO22_PIN_MASK                0x1u
#define PC87307_SIOC2_GPIO22_PIN_INPLACE             (PC87307_SIOC2_GPIO22_PIN_MASK << PC87307_SIOC2_GPIO22_PIN_SHIFT)
#define PC87307_SIOC2_BADDR_SHIFT                    0 /* established */
#define PC87307_SIOC2_BADDR_MASK                     0x3u
#define PC87307_SIOC2_BADDR_INPLACE                  (PC87307_SIOC2_BADDR_MASK << PC87307_SIOC2_BADDR_SHIFT)

/*
 * Programmable chip select configuration index: the second-level index of the chip select register that the data register reaches. Bits 7:4 read 0.
 */
/* cs_index: rw8, space pc87307_card, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.35-36 */
#define PC87307_CS_INDEX_OFFSET                      0x23u /* established */

/*
 * Programmable chip select configuration data: the register named by the index above.
 */
/* cs_data: rw8, space pc87307_card, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36 */
#define PC87307_CS_DATA_OFFSET                       0x24u /* established */

/*
 * Chip revision identification, PC97307 only: incremented on each tapeout.
 */
/* srid: r8, space pc87307_card, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36 */
#define PC87307_SRID_OFFSET                          0x27u /* established */

/*
 * Configuration index register. A write selects the configuration register the data port then reaches; a read returns the last index written. Reset: the part wakes in the Config state in PnP motherboard mode, so no key sequence is needed. The PROM and Linux write ports 0x2e and 0x2f directly. The reset value is unknown: no source states it and no PROM read of the index port before its first write is held.
 */
/* cfg_index: rw8, space pc87307_cfgport, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.24-25 */
#define PC87307_CFG_INDEX_OFFSET                     0x0u /* established */

/*
 * Configuration data register: reads and writes the register selected by the index. Reserved bits must be preserved, so software uses read-modify-write.
 */
/* cfg_data: rw8, space pc87307_cfgport, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.24-25 */
#define PC87307_CFG_DATA_OFFSET                      0x1u /* established */

/*
 * CS0, CS1 and CS2 base address, most significant byte (second-level indexes 0x00, 0x04 and 0x08).
 */
/* cs_base_msb: rw8, space pc87307_cs, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 */
#define PC87307_CS_BASE_MSB_OFFSET                   0x0u /* established */
#define PC87307_CS_BASE_MSB_COUNT                    3
#define PC87307_CS_BASE_MSB_STRIDE                   4

/*
 * CS0, CS1 and CS2 base address, least significant byte (indexes 0x01, 0x05, 0x09).
 */
/* cs_base_lsb: rw8, space pc87307_cs, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 */
#define PC87307_CS_BASE_LSB_OFFSET                   0x1u /* established */
#define PC87307_CS_BASE_LSB_COUNT                    3
#define PC87307_CS_BASE_LSB_STRIDE                   4

/*
 * CS0, CS1 and CS2 configuration (indexes 0x02, 0x06, 0x0a). The board's use of the chip selects is not known.
 */
/* cs_config: rw8, space pc87307_cs, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 */
#define PC87307_CS_CONFIG_OFFSET                     0x2u /* established */
#define PC87307_CS_CONFIG_COUNT                      3
#define PC87307_CS_CONFIG_STRIDE                     4
#define PC87307_CS_CONFIG_MASK_A11_0_SHIFT           7 /* established */
#define PC87307_CS_CONFIG_MASK_A11_0_MASK            0x1u
#define PC87307_CS_CONFIG_MASK_A11_0_INPLACE         (PC87307_CS_CONFIG_MASK_A11_0_MASK << PC87307_CS_CONFIG_MASK_A11_0_SHIFT)
#define PC87307_CS_CONFIG_IGNORE_RDWR_SHIFT          6 /* established */
#define PC87307_CS_CONFIG_IGNORE_RDWR_MASK           0x1u
#define PC87307_CS_CONFIG_IGNORE_RDWR_INPLACE        (PC87307_CS_CONFIG_IGNORE_RDWR_MASK << PC87307_CS_CONFIG_IGNORE_RDWR_SHIFT)
#define PC87307_CS_CONFIG_ON_READ_SHIFT              5 /* established */
#define PC87307_CS_CONFIG_ON_READ_MASK               0x1u
#define PC87307_CS_CONFIG_ON_READ_INPLACE            (PC87307_CS_CONFIG_ON_READ_MASK << PC87307_CS_CONFIG_ON_READ_SHIFT)
#define PC87307_CS_CONFIG_ON_WRITE_SHIFT             4 /* established */
#define PC87307_CS_CONFIG_ON_WRITE_MASK              0x1u
#define PC87307_CS_CONFIG_ON_WRITE_INPLACE           (PC87307_CS_CONFIG_ON_WRITE_MASK << PC87307_CS_CONFIG_ON_WRITE_SHIFT)
#define PC87307_CS_CONFIG_MASK_A3_SHIFT              3 /* established */
#define PC87307_CS_CONFIG_MASK_A3_MASK               0x1u
#define PC87307_CS_CONFIG_MASK_A3_INPLACE            (PC87307_CS_CONFIG_MASK_A3_MASK << PC87307_CS_CONFIG_MASK_A3_SHIFT)
#define PC87307_CS_CONFIG_MASK_A2_SHIFT              2 /* established */
#define PC87307_CS_CONFIG_MASK_A2_MASK               0x1u
#define PC87307_CS_CONFIG_MASK_A2_INPLACE            (PC87307_CS_CONFIG_MASK_A2_MASK << PC87307_CS_CONFIG_MASK_A2_SHIFT)
#define PC87307_CS_CONFIG_MASK_A1_SHIFT              1 /* established */
#define PC87307_CS_CONFIG_MASK_A1_MASK               0x1u
#define PC87307_CS_CONFIG_MASK_A1_INPLACE            (PC87307_CS_CONFIG_MASK_A1_MASK << PC87307_CS_CONFIG_MASK_A1_SHIFT)
#define PC87307_CS_CONFIG_MASK_A0_SHIFT              0 /* established */
#define PC87307_CS_CONFIG_MASK_A0_MASK               0x1u
#define PC87307_CS_CONFIG_MASK_A0_INPLACE            (PC87307_CS_CONFIG_MASK_A0_MASK << PC87307_CS_CONFIG_MASK_A0_SHIFT)

/*
 * Port 1 data. A read returns the pin for an input bit and the latch for an output bit; a write latches the value and drives output pins only. The write latch resets to 0xff. The firmware and Linux read this byte at the GPIO base after enabling the block.
 */
/* p1_data: rw8, space pc87307_gpio0, reset 0xff; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170 */
#define PC87307_P1_DATA_OFFSET                       0x0u /* established */
#define PC87307_P1_DATA_BOARD_REV_SHIFT              0 /* inferred */
#define PC87307_P1_DATA_BOARD_REV_MASK               0x7fu
#define PC87307_P1_DATA_BOARD_REV_INPLACE            (PC87307_P1_DATA_BOARD_REV_MASK << PC87307_P1_DATA_BOARD_REV_SHIFT)

/*
 * Port 1 direction: 0 input, 1 output.
 */
/* p1_dir: rw8, space pc87307_gpio0, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 */
#define PC87307_P1_DIR_OFFSET                        0x1u /* established */

/*
 * Port 1 output type: 0 open-drain, 1 push-pull.
 */
/* p1_otype: rw8, space pc87307_gpio0, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 */
#define PC87307_P1_OTYPE_OFFSET                      0x2u /* established */

/*
 * Port 1 pull-up control: 0 none, 1 internal pull-up.
 */
/* p1_pullup: rw8, space pc87307_gpio0, reset 0xff; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 */
#define PC87307_P1_PULLUP_OFFSET                     0x3u /* established */

/*
 * Port 2 data, as port 1.
 */
/* p2_data: rw8, space pc87307_gpio0, reset 0xff; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 */
#define PC87307_P2_DATA_OFFSET                       0x4u /* established */

/*
 * Port 2 direction.
 */
/* p2_dir: rw8, space pc87307_gpio0, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 */
#define PC87307_P2_DIR_OFFSET                        0x5u /* established */

/*
 * Port 2 output type.
 */
/* p2_otype: rw8, space pc87307_gpio0, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 */
#define PC87307_P2_OTYPE_OFFSET                      0x6u /* established */

/*
 * Port 2 pull-up control.
 */
/* p2_pullup: rw8, space pc87307_gpio0, reset 0xff; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 */
#define PC87307_P2_PULLUP_OFFSET                     0x7u /* established */

/*
 * Port 1 lock. Bits 7 and 6 lock the direction and pull-up bits of GPIO17 and GPIO16, and for outputs the pin value and buffer type. Only a hardware (master) reset clears them. Bits 5:0 are reserved; offsets 0x01 to 0x07 of this bank are reserved.
 */
/* p1_lock: rw8, space pc87307_gpio1, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.171 */
#define PC87307_P1_LOCK_OFFSET                       0x0u /* established */
#define PC87307_P1_LOCK_LOCK17_SHIFT                 7 /* established */
#define PC87307_P1_LOCK_LOCK17_MASK                  0x1u
#define PC87307_P1_LOCK_LOCK17_INPLACE               (PC87307_P1_LOCK_LOCK17_MASK << PC87307_P1_LOCK_LOCK17_SHIFT)
#define PC87307_P1_LOCK_LOCK16_SHIFT                 6 /* established */
#define PC87307_P1_LOCK_LOCK16_MASK                  0x1u
#define PC87307_P1_LOCK_LOCK16_INPLACE               (PC87307_P1_LOCK_LOCK16_MASK << PC87307_P1_LOCK_LOCK16_SHIFT)

/*
 * Activate (bit 0). The PROM activates it; the HAL selects it to steer IRQ 1. Reset 0 or 1 according to the CFG0 strap (the board's strap is not known); the device is active only when its function enable bit in the power management block is also set.
 */
/* ld0_activate: rw8, space pc87307_ld0, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 */
#define PC87307_LD0_ACTIVATE_OFFSET                  0x30u /* established */
#define PC87307_LD0_ACTIVATE_ACTIVE_SHIFT            0 /* established */
#define PC87307_LD0_ACTIVATE_ACTIVE_MASK             0x1u
#define PC87307_LD0_ACTIVATE_ACTIVE_INPLACE          (PC87307_LD0_ACTIVATE_ACTIVE_MASK << PC87307_LD0_ACTIVATE_ACTIVE_SHIFT)

/*
 * I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.
 */
/* ld0_iorc: rw8, space pc87307_ld0, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 */
#define PC87307_LD0_IORC_OFFSET                      0x31u /* established */
#define PC87307_LD0_IORC_ENABLE_SHIFT                1 /* established */
#define PC87307_LD0_IORC_ENABLE_MASK                 0x1u
#define PC87307_LD0_IORC_ENABLE_INPLACE              (PC87307_LD0_IORC_ENABLE_MASK << PC87307_LD0_IORC_ENABLE_SHIFT)
#define PC87307_LD0_IORC_VALUE_SHIFT                 0 /* established */
#define PC87307_LD0_IORC_VALUE_MASK                  0x1u
#define PC87307_LD0_IORC_VALUE_INPLACE               (PC87307_LD0_IORC_VALUE_MASK << PC87307_LD0_IORC_VALUE_SHIFT)

/*
 * Base address bits 15:8.
 */
/* ld0_base_msb: rw8, space pc87307_ld0, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 */
#define PC87307_LD0_BASE_MSB_OFFSET                  0x60u /* established */

/*
 * Base address bits 7:0; the low bits are read only and the decoder ignores them.
 */
/* ld0_base_lsb: rw8, space pc87307_ld0, reset 0x60; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 */
#define PC87307_LD0_BASE_LSB_OFFSET                  0x61u /* established */

/*
 * Command window base address bits 15:8.
 */
/* ld0_cmd_base_msb: rw8, space pc87307_ld0, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 */
#define PC87307_LD0_CMD_BASE_MSB_OFFSET              0x62u /* established */

/*
 * Command window base address bits 7:0; bit 2 reads 1. The reset reads 0x64 (the table prints it as 64).
 */
/* ld0_cmd_base_lsb: rw8, space pc87307_ld0, reset 0x64; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 */
#define PC87307_LD0_CMD_BASE_LSB_OFFSET              0x63u /* established */

/*
 * Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.
 */
/* ld0_irq: rw8, space pc87307_ld0, reset 0x1; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 */
#define PC87307_LD0_IRQ_OFFSET                       0x70u /* established */
#define PC87307_LD0_IRQ_LINE_SHIFT                   0 /* established */
#define PC87307_LD0_IRQ_LINE_MASK                    0xfu
#define PC87307_LD0_IRQ_LINE_INPLACE                 (PC87307_LD0_IRQ_LINE_MASK << PC87307_LD0_IRQ_LINE_SHIFT)

/*
 * Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.
 */
/* ld0_irq_type: rw8, space pc87307_ld0, reset 0x2; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 */
#define PC87307_LD0_IRQ_TYPE_OFFSET                  0x71u /* established */
#define PC87307_LD0_IRQ_TYPE_POLARITY_SHIFT          1 /* established */
#define PC87307_LD0_IRQ_TYPE_POLARITY_MASK           0x1u
#define PC87307_LD0_IRQ_TYPE_POLARITY_INPLACE        (PC87307_LD0_IRQ_TYPE_POLARITY_MASK << PC87307_LD0_IRQ_TYPE_POLARITY_SHIFT)
#define PC87307_LD0_IRQ_TYPE_LEVEL_SHIFT             0 /* established */
#define PC87307_LD0_IRQ_TYPE_LEVEL_MASK              0x1u
#define PC87307_LD0_IRQ_TYPE_LEVEL_INPLACE           (PC87307_LD0_IRQ_TYPE_LEVEL_MASK << PC87307_LD0_IRQ_TYPE_LEVEL_SHIFT)

/*
 * DMA channel select 0: bits 2:0, 4 means none. Read only.
 */
/* ld0_dma0: r8, space pc87307_ld0, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 */
#define PC87307_LD0_DMA0_OFFSET                      0x74u /* established */

/*
 * DMA channel select 1: bits 2:0, 4 means none. Read only.
 */
/* ld0_dma1: r8, space pc87307_ld0, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 */
#define PC87307_LD0_DMA1_OFFSET                      0x75u /* established */

/*
 * Keyboard controller configuration: bits 7:6 pick the clock source (00 8 MHz, 01 12 MHz, 10 16 MHz, only with the keyboard controller inactive).
 */
/* ld0_config: rw8, space pc87307_ld0, reset 0x40; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36 */
#define PC87307_LD0_CONFIG_OFFSET                    0xf0u /* established */
#define PC87307_LD0_CONFIG_CLK_SHIFT                 6 /* established */
#define PC87307_LD0_CONFIG_CLK_MASK                  0x3u
#define PC87307_LD0_CONFIG_CLK_INPLACE               (PC87307_LD0_CONFIG_CLK_MASK << PC87307_LD0_CONFIG_CLK_SHIFT)

/*
 * Activate (bit 0). The HAL selects it to steer IRQ 12. The device is active only when its function enable bit in the power management block is also set.
 */
/* ld1_activate: rw8, space pc87307_ld1, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 */
#define PC87307_LD1_ACTIVATE_OFFSET                  0x30u /* established */
#define PC87307_LD1_ACTIVATE_ACTIVE_SHIFT            0 /* established */
#define PC87307_LD1_ACTIVATE_ACTIVE_MASK             0x1u
#define PC87307_LD1_ACTIVATE_ACTIVE_INPLACE          (PC87307_LD1_ACTIVATE_ACTIVE_MASK << PC87307_LD1_ACTIVATE_ACTIVE_SHIFT)

/*
 * Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.
 */
/* ld1_irq: rw8, space pc87307_ld1, reset 0xc; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 */
#define PC87307_LD1_IRQ_OFFSET                       0x70u /* established */
#define PC87307_LD1_IRQ_LINE_SHIFT                   0 /* established */
#define PC87307_LD1_IRQ_LINE_MASK                    0xfu
#define PC87307_LD1_IRQ_LINE_INPLACE                 (PC87307_LD1_IRQ_LINE_MASK << PC87307_LD1_IRQ_LINE_SHIFT)

/*
 * Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.
 */
/* ld1_irq_type: rw8, space pc87307_ld1, reset 0x2; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 */
#define PC87307_LD1_IRQ_TYPE_OFFSET                  0x71u /* established */
#define PC87307_LD1_IRQ_TYPE_POLARITY_SHIFT          1 /* established */
#define PC87307_LD1_IRQ_TYPE_POLARITY_MASK           0x1u
#define PC87307_LD1_IRQ_TYPE_POLARITY_INPLACE        (PC87307_LD1_IRQ_TYPE_POLARITY_MASK << PC87307_LD1_IRQ_TYPE_POLARITY_SHIFT)
#define PC87307_LD1_IRQ_TYPE_LEVEL_SHIFT             0 /* established */
#define PC87307_LD1_IRQ_TYPE_LEVEL_MASK              0x1u
#define PC87307_LD1_IRQ_TYPE_LEVEL_INPLACE           (PC87307_LD1_IRQ_TYPE_LEVEL_MASK << PC87307_LD1_IRQ_TYPE_LEVEL_SHIFT)

/*
 * DMA channel select 0: bits 2:0, 4 means none. Read only.
 */
/* ld1_dma0: r8, space pc87307_ld1, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 */
#define PC87307_LD1_DMA0_OFFSET                      0x74u /* established */

/*
 * DMA channel select 1: bits 2:0, 4 means none. Read only.
 */
/* ld1_dma1: r8, space pc87307_ld1, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 */
#define PC87307_LD1_DMA1_OFFSET                      0x75u /* established */

/*
 * Activate (bit 0). The PROM activates it. Reset 0 or 1 according to the CFG0 strap (the board's strap is not known); the device is active only when its function enable bit in the power management block is also set.
 */
/* ld2_activate: rw8, space pc87307_ld2, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 */
#define PC87307_LD2_ACTIVATE_OFFSET                  0x30u /* established */
#define PC87307_LD2_ACTIVATE_ACTIVE_SHIFT            0 /* established */
#define PC87307_LD2_ACTIVATE_ACTIVE_MASK             0x1u
#define PC87307_LD2_ACTIVATE_ACTIVE_INPLACE          (PC87307_LD2_ACTIVATE_ACTIVE_MASK << PC87307_LD2_ACTIVATE_ACTIVE_SHIFT)

/*
 * I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.
 */
/* ld2_iorc: rw8, space pc87307_ld2, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 */
#define PC87307_LD2_IORC_OFFSET                      0x31u /* established */
#define PC87307_LD2_IORC_ENABLE_SHIFT                1 /* established */
#define PC87307_LD2_IORC_ENABLE_MASK                 0x1u
#define PC87307_LD2_IORC_ENABLE_INPLACE              (PC87307_LD2_IORC_ENABLE_MASK << PC87307_LD2_IORC_ENABLE_SHIFT)
#define PC87307_LD2_IORC_VALUE_SHIFT                 0 /* established */
#define PC87307_LD2_IORC_VALUE_MASK                  0x1u
#define PC87307_LD2_IORC_VALUE_INPLACE               (PC87307_LD2_IORC_VALUE_MASK << PC87307_LD2_IORC_VALUE_SHIFT)

/*
 * Base address bits 15:8.
 */
/* ld2_base_msb: rw8, space pc87307_ld2, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 */
#define PC87307_LD2_BASE_MSB_OFFSET                  0x60u /* established */

/*
 * Base address bits 7:0; the low bits are read only and the decoder ignores them.
 */
/* ld2_base_lsb: rw8, space pc87307_ld2, reset 0x70; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 */
#define PC87307_LD2_BASE_LSB_OFFSET                  0x61u /* established */

/*
 * Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.
 */
/* ld2_irq: rw8, space pc87307_ld2, reset 0x8; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 */
#define PC87307_LD2_IRQ_OFFSET                       0x70u /* established */
#define PC87307_LD2_IRQ_LINE_SHIFT                   0 /* established */
#define PC87307_LD2_IRQ_LINE_MASK                    0xfu
#define PC87307_LD2_IRQ_LINE_INPLACE                 (PC87307_LD2_IRQ_LINE_MASK << PC87307_LD2_IRQ_LINE_SHIFT)

/*
 * Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device.
 */
/* ld2_irq_type: rw8, space pc87307_ld2, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 */
#define PC87307_LD2_IRQ_TYPE_OFFSET                  0x71u /* established */
#define PC87307_LD2_IRQ_TYPE_POLARITY_SHIFT          1 /* established */
#define PC87307_LD2_IRQ_TYPE_POLARITY_MASK           0x1u
#define PC87307_LD2_IRQ_TYPE_POLARITY_INPLACE        (PC87307_LD2_IRQ_TYPE_POLARITY_MASK << PC87307_LD2_IRQ_TYPE_POLARITY_SHIFT)
#define PC87307_LD2_IRQ_TYPE_LEVEL_SHIFT             0 /* established */
#define PC87307_LD2_IRQ_TYPE_LEVEL_MASK              0x1u
#define PC87307_LD2_IRQ_TYPE_LEVEL_INPLACE           (PC87307_LD2_IRQ_TYPE_LEVEL_MASK << PC87307_LD2_IRQ_TYPE_LEVEL_SHIFT)

/*
 * DMA channel select 0: bits 2:0, 4 means none. Read only.
 */
/* ld2_dma0: r8, space pc87307_ld2, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 */
#define PC87307_LD2_DMA0_OFFSET                      0x74u /* established */

/*
 * DMA channel select 1: bits 2:0, 4 means none. Read only.
 */
/* ld2_dma1: r8, space pc87307_ld2, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 */
#define PC87307_LD2_DMA1_OFFSET                      0x75u /* established */

/*
 * Activate (bit 0). The PROM activates it and its ARC tree lists a floppy controller at the usual 0x3f2 window; the HAL selects it to steer IRQ 6. Reset 0 or 1 according to the CFG0 strap (the board's strap is not known); the device is active only when its function enable bit in the power management block is also set.
 */
/* ld3_activate: rw8, space pc87307_ld3, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 */
#define PC87307_LD3_ACTIVATE_OFFSET                  0x30u /* established */
#define PC87307_LD3_ACTIVATE_ACTIVE_SHIFT            0 /* established */
#define PC87307_LD3_ACTIVATE_ACTIVE_MASK             0x1u
#define PC87307_LD3_ACTIVATE_ACTIVE_INPLACE          (PC87307_LD3_ACTIVATE_ACTIVE_MASK << PC87307_LD3_ACTIVATE_ACTIVE_SHIFT)

/*
 * I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.
 */
/* ld3_iorc: rw8, space pc87307_ld3, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 */
#define PC87307_LD3_IORC_OFFSET                      0x31u /* established */
#define PC87307_LD3_IORC_ENABLE_SHIFT                1 /* established */
#define PC87307_LD3_IORC_ENABLE_MASK                 0x1u
#define PC87307_LD3_IORC_ENABLE_INPLACE              (PC87307_LD3_IORC_ENABLE_MASK << PC87307_LD3_IORC_ENABLE_SHIFT)
#define PC87307_LD3_IORC_VALUE_SHIFT                 0 /* established */
#define PC87307_LD3_IORC_VALUE_MASK                  0x1u
#define PC87307_LD3_IORC_VALUE_INPLACE               (PC87307_LD3_IORC_VALUE_MASK << PC87307_LD3_IORC_VALUE_SHIFT)

/*
 * Base address bits 15:8.
 */
/* ld3_base_msb: rw8, space pc87307_ld3, reset 0x3; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 */
#define PC87307_LD3_BASE_MSB_OFFSET                  0x60u /* established */

/*
 * Base address bits 7:0; the low bits are read only and the decoder ignores them.
 */
/* ld3_base_lsb: rw8, space pc87307_ld3, reset 0xf2; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 */
#define PC87307_LD3_BASE_LSB_OFFSET                  0x61u /* established */

/*
 * Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.
 */
/* ld3_irq: rw8, space pc87307_ld3, reset 0x6; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 */
#define PC87307_LD3_IRQ_OFFSET                       0x70u /* established */
#define PC87307_LD3_IRQ_LINE_SHIFT                   0 /* established */
#define PC87307_LD3_IRQ_LINE_MASK                    0xfu
#define PC87307_LD3_IRQ_LINE_INPLACE                 (PC87307_LD3_IRQ_LINE_MASK << PC87307_LD3_IRQ_LINE_SHIFT)

/*
 * Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.
 */
/* ld3_irq_type: rw8, space pc87307_ld3, reset 0x3; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 */
#define PC87307_LD3_IRQ_TYPE_OFFSET                  0x71u /* established */
#define PC87307_LD3_IRQ_TYPE_POLARITY_SHIFT          1 /* established */
#define PC87307_LD3_IRQ_TYPE_POLARITY_MASK           0x1u
#define PC87307_LD3_IRQ_TYPE_POLARITY_INPLACE        (PC87307_LD3_IRQ_TYPE_POLARITY_MASK << PC87307_LD3_IRQ_TYPE_POLARITY_SHIFT)
#define PC87307_LD3_IRQ_TYPE_LEVEL_SHIFT             0 /* established */
#define PC87307_LD3_IRQ_TYPE_LEVEL_MASK              0x1u
#define PC87307_LD3_IRQ_TYPE_LEVEL_INPLACE           (PC87307_LD3_IRQ_TYPE_LEVEL_MASK << PC87307_LD3_IRQ_TYPE_LEVEL_SHIFT)

/*
 * DMA channel select 0: bits 2:0, 4 means none.
 */
/* ld3_dma0: rw8, space pc87307_ld3, reset 0x2; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 */
#define PC87307_LD3_DMA0_OFFSET                      0x74u /* established */

/*
 * DMA channel select 1: bits 2:0, 4 means none. Read only.
 */
/* ld3_dma1: r8, space pc87307_ld3, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 */
#define PC87307_LD3_DMA1_OFFSET                      0x75u /* established */

/*
 * Floppy configuration: tri-state, DENSEL polarity, TDR mode and four-drive encode.
 */
/* ld3_config: rw8, space pc87307_ld3, reset 0x20; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36-37 */
#define PC87307_LD3_CONFIG_OFFSET                    0xf0u /* established */
#define PC87307_LD3_CONFIG_FOUR_DRIVE_SHIFT          7 /* established */
#define PC87307_LD3_CONFIG_FOUR_DRIVE_MASK           0x1u
#define PC87307_LD3_CONFIG_FOUR_DRIVE_INPLACE        (PC87307_LD3_CONFIG_FOUR_DRIVE_MASK << PC87307_LD3_CONFIG_FOUR_DRIVE_SHIFT)
#define PC87307_LD3_CONFIG_TDR_ENH_SHIFT             6 /* established */
#define PC87307_LD3_CONFIG_TDR_ENH_MASK              0x1u
#define PC87307_LD3_CONFIG_TDR_ENH_INPLACE           (PC87307_LD3_CONFIG_TDR_ENH_MASK << PC87307_LD3_CONFIG_TDR_ENH_SHIFT)
#define PC87307_LD3_CONFIG_DENSEL_POL_SHIFT          5 /* established */
#define PC87307_LD3_CONFIG_DENSEL_POL_MASK           0x1u
#define PC87307_LD3_CONFIG_DENSEL_POL_INPLACE        (PC87307_LD3_CONFIG_DENSEL_POL_MASK << PC87307_LD3_CONFIG_DENSEL_POL_SHIFT)
#define PC87307_LD3_CONFIG_TRISTATE_SHIFT            0 /* established */
#define PC87307_LD3_CONFIG_TRISTATE_MASK             0x1u
#define PC87307_LD3_CONFIG_TRISTATE_INPLACE          (PC87307_LD3_CONFIG_TRISTATE_MASK << PC87307_LD3_CONFIG_TRISTATE_SHIFT)

/*
 * Drive ID register: drive 0 and drive 1 identification bits reflected in the tape drive register.
 */
/* ld3_drive_id: rw8, space pc87307_ld3, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37 */
#define PC87307_LD3_DRIVE_ID_OFFSET                  0xf1u /* established */
#define PC87307_LD3_DRIVE_ID_DRIVE1_SHIFT            2 /* established */
#define PC87307_LD3_DRIVE_ID_DRIVE1_MASK             0x3u
#define PC87307_LD3_DRIVE_ID_DRIVE1_INPLACE          (PC87307_LD3_DRIVE_ID_DRIVE1_MASK << PC87307_LD3_DRIVE_ID_DRIVE1_SHIFT)
#define PC87307_LD3_DRIVE_ID_DRIVE0_SHIFT            0 /* established */
#define PC87307_LD3_DRIVE_ID_DRIVE0_MASK             0x3u
#define PC87307_LD3_DRIVE_ID_DRIVE0_INPLACE          (PC87307_LD3_DRIVE_ID_DRIVE0_MASK << PC87307_LD3_DRIVE_ID_DRIVE0_SHIFT)

/*
 * Activate (bit 0). The PROM activates it. Its ARC tree lists the parallel port at the PC's first address 0x378, not the reset base 0x278, so the PROM's configuration writes the base (inferred: the 26 Super I/O writes are not decoded). The device is active only when its function enable bit in the power management block is also set.
 */
/* ld4_activate: rw8, space pc87307_ld4, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 */
#define PC87307_LD4_ACTIVATE_OFFSET                  0x30u /* established */
#define PC87307_LD4_ACTIVATE_ACTIVE_SHIFT            0 /* established */
#define PC87307_LD4_ACTIVATE_ACTIVE_MASK             0x1u
#define PC87307_LD4_ACTIVATE_ACTIVE_INPLACE          (PC87307_LD4_ACTIVATE_ACTIVE_MASK << PC87307_LD4_ACTIVATE_ACTIVE_SHIFT)

/*
 * I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.
 */
/* ld4_iorc: rw8, space pc87307_ld4, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 */
#define PC87307_LD4_IORC_OFFSET                      0x31u /* established */
#define PC87307_LD4_IORC_ENABLE_SHIFT                1 /* established */
#define PC87307_LD4_IORC_ENABLE_MASK                 0x1u
#define PC87307_LD4_IORC_ENABLE_INPLACE              (PC87307_LD4_IORC_ENABLE_MASK << PC87307_LD4_IORC_ENABLE_SHIFT)
#define PC87307_LD4_IORC_VALUE_SHIFT                 0 /* established */
#define PC87307_LD4_IORC_VALUE_MASK                  0x1u
#define PC87307_LD4_IORC_VALUE_INPLACE               (PC87307_LD4_IORC_VALUE_MASK << PC87307_LD4_IORC_VALUE_SHIFT)

/*
 * Base address bits 15:8.
 */
/* ld4_base_msb: rw8, space pc87307_ld4, reset 0x2; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 */
#define PC87307_LD4_BASE_MSB_OFFSET                  0x60u /* established */

/*
 * Base address bits 7:0; the low bits are read only and the decoder ignores them.
 */
/* ld4_base_lsb: rw8, space pc87307_ld4, reset 0x78; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 */
#define PC87307_LD4_BASE_LSB_OFFSET                  0x61u /* established */

/*
 * Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.
 */
/* ld4_irq: rw8, space pc87307_ld4, reset 0x7; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 */
#define PC87307_LD4_IRQ_OFFSET                       0x70u /* established */
#define PC87307_LD4_IRQ_LINE_SHIFT                   0 /* established */
#define PC87307_LD4_IRQ_LINE_MASK                    0xfu
#define PC87307_LD4_IRQ_LINE_INPLACE                 (PC87307_LD4_IRQ_LINE_MASK << PC87307_LD4_IRQ_LINE_SHIFT)

/*
 * Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.
 */
/* ld4_irq_type: rw8, space pc87307_ld4, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 */
#define PC87307_LD4_IRQ_TYPE_OFFSET                  0x71u /* established */
#define PC87307_LD4_IRQ_TYPE_POLARITY_SHIFT          1 /* established */
#define PC87307_LD4_IRQ_TYPE_POLARITY_MASK           0x1u
#define PC87307_LD4_IRQ_TYPE_POLARITY_INPLACE        (PC87307_LD4_IRQ_TYPE_POLARITY_MASK << PC87307_LD4_IRQ_TYPE_POLARITY_SHIFT)
#define PC87307_LD4_IRQ_TYPE_LEVEL_SHIFT             0 /* established */
#define PC87307_LD4_IRQ_TYPE_LEVEL_MASK              0x1u
#define PC87307_LD4_IRQ_TYPE_LEVEL_INPLACE           (PC87307_LD4_IRQ_TYPE_LEVEL_MASK << PC87307_LD4_IRQ_TYPE_LEVEL_SHIFT)

/*
 * DMA channel select 0: bits 2:0, 4 means none.
 */
/* ld4_dma0: rw8, space pc87307_ld4, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 */
#define PC87307_LD4_DMA0_OFFSET                      0x74u /* established */

/*
 * DMA channel select 1: bits 2:0, 4 means none. Read only.
 */
/* ld4_dma1: r8, space pc87307_ld4, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 */
#define PC87307_LD4_DMA1_OFFSET                      0x75u /* established */

/*
 * Parallel port configuration. Bits 7:4 must not be changed for normal operation. Reset 0xf2: mode select 111 (IEEE 1284 with EPP selectable), configuration bits in the port accessible, clock enabled.
 */
/* ld4_config: rw8, space pc87307_ld4, reset 0xf2; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37-38 */
#define PC87307_LD4_CONFIG_OFFSET                    0xf0u /* established */
#define PC87307_LD4_CONFIG_MODE_SHIFT                5 /* established */
#define PC87307_LD4_CONFIG_MODE_MASK                 0x7u
#define PC87307_LD4_CONFIG_MODE_INPLACE              (PC87307_LD4_CONFIG_MODE_MASK << PC87307_LD4_CONFIG_MODE_SHIFT)
#define PC87307_LD4_CONFIG_MODE_SPP                  0 /* established */
#define PC87307_LD4_CONFIG_MODE_SPP_EXT              1 /* established */
#define PC87307_LD4_CONFIG_MODE_EPP17                2 /* established */
#define PC87307_LD4_CONFIG_MODE_EPP19                3 /* established */
#define PC87307_LD4_CONFIG_MODE_IEEE1284             4 /* established */
#define PC87307_LD4_CONFIG_MODE_IEEE1284_EPP         7 /* established */
#define PC87307_LD4_CONFIG_CFG_REGS_SHIFT            4 /* established */
#define PC87307_LD4_CONFIG_CFG_REGS_MASK             0x1u
#define PC87307_LD4_CONFIG_CFG_REGS_INPLACE          (PC87307_LD4_CONFIG_CFG_REGS_MASK << PC87307_LD4_CONFIG_CFG_REGS_SHIFT)
#define PC87307_LD4_CONFIG_PNP_SPP_SHIFT             3 /* established */
#define PC87307_LD4_CONFIG_PNP_SPP_MASK              0x1u
#define PC87307_LD4_CONFIG_PNP_SPP_INPLACE           (PC87307_LD4_CONFIG_PNP_SPP_MASK << PC87307_LD4_CONFIG_PNP_SPP_SHIFT)
#define PC87307_LD4_CONFIG_CLK_EN_SHIFT              1 /* established */
#define PC87307_LD4_CONFIG_CLK_EN_MASK               0x1u
#define PC87307_LD4_CONFIG_CLK_EN_INPLACE            (PC87307_LD4_CONFIG_CLK_EN_MASK << PC87307_LD4_CONFIG_CLK_EN_SHIFT)
#define PC87307_LD4_CONFIG_TRISTATE_SHIFT            0 /* established */
#define PC87307_LD4_CONFIG_TRISTATE_MASK             0x1u
#define PC87307_LD4_CONFIG_TRISTATE_INPLACE          (PC87307_LD4_CONFIG_TRISTATE_MASK << PC87307_LD4_CONFIG_TRISTATE_SHIFT)

/*
 * Activate (bit 0). COM2 at 0x2f8, IRQ 3 (the reset values); the PROM activates it. The device is active only when its function enable bit in the power management block is also set.
 */
/* ld5_activate: rw8, space pc87307_ld5, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 */
#define PC87307_LD5_ACTIVATE_OFFSET                  0x30u /* established */
#define PC87307_LD5_ACTIVATE_ACTIVE_SHIFT            0 /* established */
#define PC87307_LD5_ACTIVATE_ACTIVE_MASK             0x1u
#define PC87307_LD5_ACTIVATE_ACTIVE_INPLACE          (PC87307_LD5_ACTIVATE_ACTIVE_MASK << PC87307_LD5_ACTIVATE_ACTIVE_SHIFT)

/*
 * I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.
 */
/* ld5_iorc: rw8, space pc87307_ld5, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 */
#define PC87307_LD5_IORC_OFFSET                      0x31u /* established */
#define PC87307_LD5_IORC_ENABLE_SHIFT                1 /* established */
#define PC87307_LD5_IORC_ENABLE_MASK                 0x1u
#define PC87307_LD5_IORC_ENABLE_INPLACE              (PC87307_LD5_IORC_ENABLE_MASK << PC87307_LD5_IORC_ENABLE_SHIFT)
#define PC87307_LD5_IORC_VALUE_SHIFT                 0 /* established */
#define PC87307_LD5_IORC_VALUE_MASK                  0x1u
#define PC87307_LD5_IORC_VALUE_INPLACE               (PC87307_LD5_IORC_VALUE_MASK << PC87307_LD5_IORC_VALUE_SHIFT)

/*
 * Base address bits 15:8.
 */
/* ld5_base_msb: rw8, space pc87307_ld5, reset 0x2; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 */
#define PC87307_LD5_BASE_MSB_OFFSET                  0x60u /* established */

/*
 * Base address bits 7:0; the low bits are read only and the decoder ignores them.
 */
/* ld5_base_lsb: rw8, space pc87307_ld5, reset 0xf8; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 */
#define PC87307_LD5_BASE_LSB_OFFSET                  0x61u /* established */

/*
 * Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.
 */
/* ld5_irq: rw8, space pc87307_ld5, reset 0x3; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 */
#define PC87307_LD5_IRQ_OFFSET                       0x70u /* established */
#define PC87307_LD5_IRQ_LINE_SHIFT                   0 /* established */
#define PC87307_LD5_IRQ_LINE_MASK                    0xfu
#define PC87307_LD5_IRQ_LINE_INPLACE                 (PC87307_LD5_IRQ_LINE_MASK << PC87307_LD5_IRQ_LINE_SHIFT)

/*
 * Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.
 */
/* ld5_irq_type: rw8, space pc87307_ld5, reset 0x3; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 */
#define PC87307_LD5_IRQ_TYPE_OFFSET                  0x71u /* established */
#define PC87307_LD5_IRQ_TYPE_POLARITY_SHIFT          1 /* established */
#define PC87307_LD5_IRQ_TYPE_POLARITY_MASK           0x1u
#define PC87307_LD5_IRQ_TYPE_POLARITY_INPLACE        (PC87307_LD5_IRQ_TYPE_POLARITY_MASK << PC87307_LD5_IRQ_TYPE_POLARITY_SHIFT)
#define PC87307_LD5_IRQ_TYPE_LEVEL_SHIFT             0 /* established */
#define PC87307_LD5_IRQ_TYPE_LEVEL_MASK              0x1u
#define PC87307_LD5_IRQ_TYPE_LEVEL_INPLACE           (PC87307_LD5_IRQ_TYPE_LEVEL_MASK << PC87307_LD5_IRQ_TYPE_LEVEL_SHIFT)

/*
 * DMA channel select 0: bits 2:0, 4 means none.
 */
/* ld5_dma0: rw8, space pc87307_ld5, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 */
#define PC87307_LD5_DMA0_OFFSET                      0x74u /* established */

/*
 * DMA channel select 1: bits 2:0, 4 means none.
 */
/* ld5_dma1: rw8, space pc87307_ld5, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 */
#define PC87307_LD5_DMA1_OFFSET                      0x75u /* established */

/*
 * UART configuration. The datasheet gives reset 0x02 in Sections 2.8.1 and 2.9.1 and 0x00 in its bitmap summary; this unit takes 0x02 (the tables and sections agree).
 */
/* ld5_config: rw8, space pc87307_ld5, reset 0x2; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 */
#define PC87307_LD5_CONFIG_OFFSET                    0xf0u /* established */
#define PC87307_LD5_CONFIG_BANK_EN_SHIFT             7 /* established */
#define PC87307_LD5_CONFIG_BANK_EN_MASK              0x1u
#define PC87307_LD5_CONFIG_BANK_EN_INPLACE           (PC87307_LD5_CONFIG_BANK_EN_MASK << PC87307_LD5_CONFIG_BANK_EN_SHIFT)
#define PC87307_LD5_CONFIG_RING_PIN_SHIFT            3 /* established */
#define PC87307_LD5_CONFIG_RING_PIN_MASK             0x1u
#define PC87307_LD5_CONFIG_RING_PIN_INPLACE          (PC87307_LD5_CONFIG_RING_PIN_MASK << PC87307_LD5_CONFIG_RING_PIN_SHIFT)
#define PC87307_LD5_CONFIG_BUSY_SHIFT                2 /* established */
#define PC87307_LD5_CONFIG_BUSY_MASK                 0x1u
#define PC87307_LD5_CONFIG_BUSY_INPLACE              (PC87307_LD5_CONFIG_BUSY_MASK << PC87307_LD5_CONFIG_BUSY_SHIFT)
#define PC87307_LD5_CONFIG_POWER_SHIFT               1 /* established */
#define PC87307_LD5_CONFIG_POWER_MASK                0x1u
#define PC87307_LD5_CONFIG_POWER_INPLACE             (PC87307_LD5_CONFIG_POWER_MASK << PC87307_LD5_CONFIG_POWER_SHIFT)
#define PC87307_LD5_CONFIG_TRISTATE_SHIFT            0 /* established */
#define PC87307_LD5_CONFIG_TRISTATE_MASK             0x1u
#define PC87307_LD5_CONFIG_TRISTATE_INPLACE          (PC87307_LD5_CONFIG_TRISTATE_MASK << PC87307_LD5_CONFIG_TRISTATE_SHIFT)

/*
 * Activate (bit 0). COM1 at 0x3f8, IRQ 4 (the reset values); the PROM's serial console, activated by the boot block and again by the self-test. The device is active only when its function enable bit in the power management block is also set.
 */
/* ld6_activate: rw8, space pc87307_ld6, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 */
#define PC87307_LD6_ACTIVATE_OFFSET                  0x30u /* established */
#define PC87307_LD6_ACTIVATE_ACTIVE_SHIFT            0 /* established */
#define PC87307_LD6_ACTIVATE_ACTIVE_MASK             0x1u
#define PC87307_LD6_ACTIVATE_ACTIVE_INPLACE          (PC87307_LD6_ACTIVATE_ACTIVE_MASK << PC87307_LD6_ACTIVATE_ACTIVE_SHIFT)

/*
 * I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.
 */
/* ld6_iorc: rw8, space pc87307_ld6, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 */
#define PC87307_LD6_IORC_OFFSET                      0x31u /* established */
#define PC87307_LD6_IORC_ENABLE_SHIFT                1 /* established */
#define PC87307_LD6_IORC_ENABLE_MASK                 0x1u
#define PC87307_LD6_IORC_ENABLE_INPLACE              (PC87307_LD6_IORC_ENABLE_MASK << PC87307_LD6_IORC_ENABLE_SHIFT)
#define PC87307_LD6_IORC_VALUE_SHIFT                 0 /* established */
#define PC87307_LD6_IORC_VALUE_MASK                  0x1u
#define PC87307_LD6_IORC_VALUE_INPLACE               (PC87307_LD6_IORC_VALUE_MASK << PC87307_LD6_IORC_VALUE_SHIFT)

/*
 * Base address bits 15:8.
 */
/* ld6_base_msb: rw8, space pc87307_ld6, reset 0x3; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 */
#define PC87307_LD6_BASE_MSB_OFFSET                  0x60u /* established */

/*
 * Base address bits 7:0; the low bits are read only and the decoder ignores them.
 */
/* ld6_base_lsb: rw8, space pc87307_ld6, reset 0xf8; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 */
#define PC87307_LD6_BASE_LSB_OFFSET                  0x61u /* established */

/*
 * Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.
 */
/* ld6_irq: rw8, space pc87307_ld6, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 */
#define PC87307_LD6_IRQ_OFFSET                       0x70u /* established */
#define PC87307_LD6_IRQ_LINE_SHIFT                   0 /* established */
#define PC87307_LD6_IRQ_LINE_MASK                    0xfu
#define PC87307_LD6_IRQ_LINE_INPLACE                 (PC87307_LD6_IRQ_LINE_MASK << PC87307_LD6_IRQ_LINE_SHIFT)

/*
 * Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.
 */
/* ld6_irq_type: rw8, space pc87307_ld6, reset 0x3; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 */
#define PC87307_LD6_IRQ_TYPE_OFFSET                  0x71u /* established */
#define PC87307_LD6_IRQ_TYPE_POLARITY_SHIFT          1 /* established */
#define PC87307_LD6_IRQ_TYPE_POLARITY_MASK           0x1u
#define PC87307_LD6_IRQ_TYPE_POLARITY_INPLACE        (PC87307_LD6_IRQ_TYPE_POLARITY_MASK << PC87307_LD6_IRQ_TYPE_POLARITY_SHIFT)
#define PC87307_LD6_IRQ_TYPE_LEVEL_SHIFT             0 /* established */
#define PC87307_LD6_IRQ_TYPE_LEVEL_MASK              0x1u
#define PC87307_LD6_IRQ_TYPE_LEVEL_INPLACE           (PC87307_LD6_IRQ_TYPE_LEVEL_MASK << PC87307_LD6_IRQ_TYPE_LEVEL_SHIFT)

/*
 * DMA channel select 0: bits 2:0, 4 means none. Read only.
 */
/* ld6_dma0: r8, space pc87307_ld6, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 */
#define PC87307_LD6_DMA0_OFFSET                      0x74u /* established */

/*
 * DMA channel select 1: bits 2:0, 4 means none. Read only.
 */
/* ld6_dma1: r8, space pc87307_ld6, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 */
#define PC87307_LD6_DMA1_OFFSET                      0x75u /* established */

/*
 * UART configuration. The datasheet gives reset 0x02 in Sections 2.8.1 and 2.9.1 and 0x00 in its bitmap summary; this unit takes 0x02 (the tables and sections agree).
 */
/* ld6_config: rw8, space pc87307_ld6, reset 0x2; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 */
#define PC87307_LD6_CONFIG_OFFSET                    0xf0u /* established */
#define PC87307_LD6_CONFIG_BANK_EN_SHIFT             7 /* established */
#define PC87307_LD6_CONFIG_BANK_EN_MASK              0x1u
#define PC87307_LD6_CONFIG_BANK_EN_INPLACE           (PC87307_LD6_CONFIG_BANK_EN_MASK << PC87307_LD6_CONFIG_BANK_EN_SHIFT)
#define PC87307_LD6_CONFIG_RING_PIN_SHIFT            3 /* established */
#define PC87307_LD6_CONFIG_RING_PIN_MASK             0x1u
#define PC87307_LD6_CONFIG_RING_PIN_INPLACE          (PC87307_LD6_CONFIG_RING_PIN_MASK << PC87307_LD6_CONFIG_RING_PIN_SHIFT)
#define PC87307_LD6_CONFIG_BUSY_SHIFT                2 /* established */
#define PC87307_LD6_CONFIG_BUSY_MASK                 0x1u
#define PC87307_LD6_CONFIG_BUSY_INPLACE              (PC87307_LD6_CONFIG_BUSY_MASK << PC87307_LD6_CONFIG_BUSY_SHIFT)
#define PC87307_LD6_CONFIG_POWER_SHIFT               1 /* established */
#define PC87307_LD6_CONFIG_POWER_MASK                0x1u
#define PC87307_LD6_CONFIG_POWER_INPLACE             (PC87307_LD6_CONFIG_POWER_MASK << PC87307_LD6_CONFIG_POWER_SHIFT)
#define PC87307_LD6_CONFIG_TRISTATE_SHIFT            0 /* established */
#define PC87307_LD6_CONFIG_TRISTATE_MASK             0x1u
#define PC87307_LD6_CONFIG_TRISTATE_INPLACE          (PC87307_LD6_CONFIG_TRISTATE_MASK << PC87307_LD6_CONFIG_TRISTATE_SHIFT)

/*
 * Activate (bit 0). The PROM and Linux write the base 0xfc0 and activate it; the board revision is read from its data byte. The device is active only when its function enable bit in the power management block is also set.
 */
/* ld7_activate: rw8, space pc87307_ld7, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 */
#define PC87307_LD7_ACTIVATE_OFFSET                  0x30u /* established */
#define PC87307_LD7_ACTIVATE_ACTIVE_SHIFT            0 /* established */
#define PC87307_LD7_ACTIVATE_ACTIVE_MASK             0x1u
#define PC87307_LD7_ACTIVATE_ACTIVE_INPLACE          (PC87307_LD7_ACTIVATE_ACTIVE_MASK << PC87307_LD7_ACTIVATE_ACTIVE_SHIFT)

/*
 * I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.
 */
/* ld7_iorc: rw8, space pc87307_ld7, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 */
#define PC87307_LD7_IORC_OFFSET                      0x31u /* established */
#define PC87307_LD7_IORC_ENABLE_SHIFT                1 /* established */
#define PC87307_LD7_IORC_ENABLE_MASK                 0x1u
#define PC87307_LD7_IORC_ENABLE_INPLACE              (PC87307_LD7_IORC_ENABLE_MASK << PC87307_LD7_IORC_ENABLE_SHIFT)
#define PC87307_LD7_IORC_VALUE_SHIFT                 0 /* established */
#define PC87307_LD7_IORC_VALUE_MASK                  0x1u
#define PC87307_LD7_IORC_VALUE_INPLACE               (PC87307_LD7_IORC_VALUE_MASK << PC87307_LD7_IORC_VALUE_SHIFT)

/*
 * Base address bits 15:8.
 */
/* ld7_base_msb: rw8, space pc87307_ld7, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 */
#define PC87307_LD7_BASE_MSB_OFFSET                  0x60u /* established */

/*
 * Base address bits 7:0; the low bits are read only and the decoder ignores them.
 */
/* ld7_base_lsb: rw8, space pc87307_ld7, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 */
#define PC87307_LD7_BASE_LSB_OFFSET                  0x61u /* established */

/*
 * DMA channel select 0: bits 2:0, 4 means none. Read only.
 */
/* ld7_dma0: r8, space pc87307_ld7, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 */
#define PC87307_LD7_DMA0_OFFSET                      0x74u /* established */

/*
 * DMA channel select 1: bits 2:0, 4 means none. Read only.
 */
/* ld7_dma1: r8, space pc87307_ld7, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 */
#define PC87307_LD7_DMA1_OFFSET                      0x75u /* established */

/*
 * Activate (bit 0). The PROM and Linux write the base 0xfc8 and activate it; Linux and the PROM then write function enable register 2. When clear, the power management registers are not accessible but are kept.
 */
/* ld8_activate: rw8, space pc87307_ld8, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 */
#define PC87307_LD8_ACTIVATE_OFFSET                  0x30u /* established */
#define PC87307_LD8_ACTIVATE_ACTIVE_SHIFT            0 /* established */
#define PC87307_LD8_ACTIVATE_ACTIVE_MASK             0x1u
#define PC87307_LD8_ACTIVATE_ACTIVE_INPLACE          (PC87307_LD8_ACTIVATE_ACTIVE_MASK << PC87307_LD8_ACTIVATE_ACTIVE_SHIFT)

/*
 * I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.
 */
/* ld8_iorc: rw8, space pc87307_ld8, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 */
#define PC87307_LD8_IORC_OFFSET                      0x31u /* established */
#define PC87307_LD8_IORC_ENABLE_SHIFT                1 /* established */
#define PC87307_LD8_IORC_ENABLE_MASK                 0x1u
#define PC87307_LD8_IORC_ENABLE_INPLACE              (PC87307_LD8_IORC_ENABLE_MASK << PC87307_LD8_IORC_ENABLE_SHIFT)
#define PC87307_LD8_IORC_VALUE_SHIFT                 0 /* established */
#define PC87307_LD8_IORC_VALUE_MASK                  0x1u
#define PC87307_LD8_IORC_VALUE_INPLACE               (PC87307_LD8_IORC_VALUE_MASK << PC87307_LD8_IORC_VALUE_SHIFT)

/*
 * Base address bits 15:8.
 */
/* ld8_base_msb: rw8, space pc87307_ld8, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 */
#define PC87307_LD8_BASE_MSB_OFFSET                  0x60u /* established */

/*
 * Base address bits 7:0; the low bits are read only and the decoder ignores them.
 */
/* ld8_base_lsb: rw8, space pc87307_ld8, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 */
#define PC87307_LD8_BASE_LSB_OFFSET                  0x61u /* established */

/*
 * DMA channel select 0: bits 2:0, 4 means none. Read only.
 */
/* ld8_dma0: r8, space pc87307_ld8, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 */
#define PC87307_LD8_DMA0_OFFSET                      0x74u /* established */

/*
 * DMA channel select 1: bits 2:0, 4 means none. Read only.
 */
/* ld8_dma1: r8, space pc87307_ld8, reset 0x4; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 */
#define PC87307_LD8_DMA1_OFFSET                      0x75u /* established */

/*
 * Function enable register 1. A logical device is active only while its activate bit and its enable bit here are both set. Hardware resets it to 0xff.
 */
/* fer1: rw8, space pc87307_pm, reset 0xff; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173 */
#define PC87307_FER1_OFFSET                          0x0u /* established */
#define PC87307_FER1_UART1_SHIFT                     6 /* established */
#define PC87307_FER1_UART1_MASK                      0x1u
#define PC87307_FER1_UART1_INPLACE                   (PC87307_FER1_UART1_MASK << PC87307_FER1_UART1_SHIFT)
#define PC87307_FER1_UART2_SHIFT                     5 /* established */
#define PC87307_FER1_UART2_MASK                      0x1u
#define PC87307_FER1_UART2_INPLACE                   (PC87307_FER1_UART2_MASK << PC87307_FER1_UART2_SHIFT)
#define PC87307_FER1_PP_SHIFT                        4 /* established */
#define PC87307_FER1_PP_MASK                         0x1u
#define PC87307_FER1_PP_INPLACE                      (PC87307_FER1_PP_MASK << PC87307_FER1_PP_SHIFT)
#define PC87307_FER1_FDC_SHIFT                       3 /* established */
#define PC87307_FER1_FDC_MASK                        0x1u
#define PC87307_FER1_FDC_INPLACE                     (PC87307_FER1_FDC_MASK << PC87307_FER1_FDC_SHIFT)
#define PC87307_FER1_RTC_SHIFT                       2 /* established */
#define PC87307_FER1_RTC_MASK                        0x1u
#define PC87307_FER1_RTC_INPLACE                     (PC87307_FER1_RTC_MASK << PC87307_FER1_RTC_SHIFT)
#define PC87307_FER1_KBC_SHIFT                       0 /* established */
#define PC87307_FER1_KBC_MASK                        0x1u
#define PC87307_FER1_KBC_INPLACE                     (PC87307_FER1_KBC_MASK << PC87307_FER1_KBC_SHIFT)

/*
 * Function enable register 2. Linux and the PROM write bit 7 set (Linux's comment: it enables access to the GPIO registers). Hardware resets it to 0xff according to Table 9-1's bitmap and the text of 9.2.4; the text for bit 7 marks the cleared state as the default, which contradicts that. The PC87317 sibling datasheet resets the bit to 1.
 */
/* fer2: rw8, space pc87307_pm, reset 0xff; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173-174 */
#define PC87307_FER2_OFFSET                          0x1u /* established */
#define PC87307_FER2_GPIO_SHIFT                      7 /* established */
#define PC87307_FER2_GPIO_MASK                       0x1u
#define PC87307_FER2_GPIO_INPLACE                    (PC87307_FER2_GPIO_MASK << PC87307_FER2_GPIO_SHIFT)
#define PC87307_FER2_CS2_SHIFT                       2 /* established */
#define PC87307_FER2_CS2_MASK                        0x1u
#define PC87307_FER2_CS2_INPLACE                     (PC87307_FER2_CS2_MASK << PC87307_FER2_CS2_SHIFT)
#define PC87307_FER2_CS1_SHIFT                       1 /* established */
#define PC87307_FER2_CS1_MASK                        0x1u
#define PC87307_FER2_CS1_INPLACE                     (PC87307_FER2_CS1_MASK << PC87307_FER2_CS1_SHIFT)
#define PC87307_FER2_CS0_SHIFT                       0 /* established */
#define PC87307_FER2_CS0_MASK                        0x1u
#define PC87307_FER2_CS0_INPLACE                     (PC87307_FER2_CS0_MASK << PC87307_FER2_CS0_SHIFT)

/*
 * Power management control 1: tri-state controls for the floppy, parallel and UART pins, ORed with the logical devices' own bits.
 */
/* pmc1: rw8, space pc87307_pm, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174 */
#define PC87307_PMC1_OFFSET                          0x2u /* established */
#define PC87307_PMC1_UART1_TRI_SHIFT                 6 /* established */
#define PC87307_PMC1_UART1_TRI_MASK                  0x1u
#define PC87307_PMC1_UART1_TRI_INPLACE               (PC87307_PMC1_UART1_TRI_MASK << PC87307_PMC1_UART1_TRI_SHIFT)
#define PC87307_PMC1_UART2_TRI_SHIFT                 5 /* established */
#define PC87307_PMC1_UART2_TRI_MASK                  0x1u
#define PC87307_PMC1_UART2_TRI_INPLACE               (PC87307_PMC1_UART2_TRI_MASK << PC87307_PMC1_UART2_TRI_SHIFT)
#define PC87307_PMC1_PP_TRI_SHIFT                    4 /* established */
#define PC87307_PMC1_PP_TRI_MASK                     0x1u
#define PC87307_PMC1_PP_TRI_INPLACE                  (PC87307_PMC1_PP_TRI_MASK << PC87307_PMC1_PP_TRI_SHIFT)
#define PC87307_PMC1_FDC_TRI_SHIFT                   3 /* established */
#define PC87307_PMC1_FDC_TRI_MASK                    0x1u
#define PC87307_PMC1_FDC_TRI_INPLACE                 (PC87307_PMC1_FDC_TRI_MASK << PC87307_PMC1_FDC_TRI_SHIFT)

/*
 * Power management control 2: clock source and clock multiplier. Bits 2:0 follow the CFG3 and CFG2 straps at reset, whose board settings are not known.
 */
/* pmc2: rw8, space pc87307_pm, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174 */
#define PC87307_PMC2_OFFSET                          0x3u /* established */
#define PC87307_PMC2_MULT_VALID_SHIFT                7 /* established */
#define PC87307_PMC2_MULT_VALID_MASK                 0x1u
#define PC87307_PMC2_MULT_VALID_INPLACE              (PC87307_PMC2_MULT_VALID_MASK << PC87307_PMC2_MULT_VALID_SHIFT)
#define PC87307_PMC2_MULT_EN_SHIFT                   2 /* established */
#define PC87307_PMC2_MULT_EN_MASK                    0x1u
#define PC87307_PMC2_MULT_EN_INPLACE                 (PC87307_PMC2_MULT_EN_MASK << PC87307_PMC2_MULT_EN_SHIFT)
#define PC87307_PMC2_CLK_SRC_SHIFT                   0 /* established */
#define PC87307_PMC2_CLK_SRC_MASK                    0x3u
#define PC87307_PMC2_CLK_SRC_INPLACE                 (PC87307_PMC2_CLK_SRC_MASK << PC87307_PMC2_CLK_SRC_SHIFT)
#define PC87307_PMC2_CLK_SRC_X1_24MHZ                0 /* established */
#define PC87307_PMC2_CLK_SRC_X1_48MHZ                2 /* established */
#define PC87307_PMC2_CLK_SRC_MULTIPLIER              3 /* established */

/*
 * Power management control 3: parallel port, UART2 and UART1 clock enables (ANDed with the devices' own bits) and read-only busy flags.
 */
/* pmc3: rw8, space pc87307_pm, reset 0xe; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175 */
#define PC87307_PMC3_OFFSET                          0x4u /* established */
#define PC87307_PMC3_UART1_BUSY_SHIFT                7 /* established */
#define PC87307_PMC3_UART1_BUSY_MASK                 0x1u
#define PC87307_PMC3_UART1_BUSY_INPLACE              (PC87307_PMC3_UART1_BUSY_MASK << PC87307_PMC3_UART1_BUSY_SHIFT)
#define PC87307_PMC3_UART2_BUSY_SHIFT                6 /* established */
#define PC87307_PMC3_UART2_BUSY_MASK                 0x1u
#define PC87307_PMC3_UART2_BUSY_INPLACE              (PC87307_PMC3_UART2_BUSY_MASK << PC87307_PMC3_UART2_BUSY_SHIFT)
#define PC87307_PMC3_UART1_CLK_SHIFT                 3 /* established */
#define PC87307_PMC3_UART1_CLK_MASK                  0x1u
#define PC87307_PMC3_UART1_CLK_INPLACE               (PC87307_PMC3_UART1_CLK_MASK << PC87307_PMC3_UART1_CLK_SHIFT)
#define PC87307_PMC3_UART2_CLK_SHIFT                 2 /* established */
#define PC87307_PMC3_UART2_CLK_MASK                  0x1u
#define PC87307_PMC3_UART2_CLK_INPLACE               (PC87307_PMC3_UART2_CLK_MASK << PC87307_PMC3_UART2_CLK_SHIFT)
#define PC87307_PMC3_PP_CLK_SHIFT                    1 /* established */
#define PC87307_PMC3_PP_CLK_MASK                     0x1u
#define PC87307_PMC3_PP_CLK_INPLACE                  (PC87307_PMC3_PP_CLK_MASK << PC87307_PMC3_PP_CLK_SHIFT)

/*
 * Watchdog time-out in minutes; 0 stops the watchdog. Also cleared when the power management device is activated.
 */
/* wdto: rw8, space pc87307_pm, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175 */
#define PC87307_WDTO_OFFSET                          0x5u /* established */

/*
 * Watchdog configuration: which interrupts reload the timer.
 */
/* wdcf: rw8, space pc87307_pm, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175-176 */
#define PC87307_WDCF_OFFSET                          0x6u /* established */
#define PC87307_WDCF_UART2_SHIFT                     3 /* established */
#define PC87307_WDCF_UART2_MASK                      0x1u
#define PC87307_WDCF_UART2_INPLACE                   (PC87307_WDCF_UART2_MASK << PC87307_WDCF_UART2_SHIFT)
#define PC87307_WDCF_UART1_SHIFT                     2 /* established */
#define PC87307_WDCF_UART1_MASK                      0x1u
#define PC87307_WDCF_UART1_INPLACE                   (PC87307_WDCF_UART1_MASK << PC87307_WDCF_UART1_SHIFT)
#define PC87307_WDCF_MOUSE_SHIFT                     1 /* established */
#define PC87307_WDCF_MOUSE_MASK                      0x1u
#define PC87307_WDCF_MOUSE_INPLACE                   (PC87307_WDCF_MOUSE_MASK << PC87307_WDCF_MOUSE_SHIFT)
#define PC87307_WDCF_KBC_SHIFT                       0 /* established */
#define PC87307_WDCF_KBC_MASK                        0x1u
#define PC87307_WDCF_KBC_INPLACE                     (PC87307_WDCF_KBC_MASK << PC87307_WDCF_KBC_SHIFT)

/*
 * Watchdog status. Bit 0 is the watchdog output (1 inactive). Section 9.1.2 says bit 1; the register description and bitmap say bit 0. Whether the output reaches anything on the board is not known.
 */
/* wdst: r8, space pc87307_pm, reset 0x1; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.176 */
#define PC87307_WDST_OFFSET                          0x7u /* established */
#define PC87307_WDST_WDO_SHIFT                       0 /* established */
#define PC87307_WDST_WDO_MASK                        0x1u
#define PC87307_WDST_WDO_INPLACE                     (PC87307_WDST_WDO_MASK << PC87307_WDST_WDO_SHIFT)

/*
 * Power management index register: selects the register the data port reaches. Bits 7:3 read 0.
 */
/* pm_index: rw8, space pc87307_pmport, reset 0x0; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.172 */
#define PC87307_PM_INDEX_OFFSET                      0x0u /* established */

/*
 * Power management data register.
 */
/* pm_data: rw8, space pc87307_pmport, reset unknown; National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.172-173 */
#define PC87307_PM_DATA_OFFSET                       0x1u /* established */

#define PC87307_CFG_DATA_PORT                        0x2fu /* established */
#define PC87307_CFG_INDEX_PORT                       0x2eu /* established */
#define PC87307_GPIO_BASE                            0xfc0u /* established */
#define PC87307_PM_BASE                              0xfc8u /* established */

#endif /* PC87307_GEN_H */
