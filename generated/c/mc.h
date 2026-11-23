/* generated from devices/mc/registers.toml by defs-gen - do not edit, change
 * the source */
/* defs-gen 4 */
/* input sha256 dae392f2b3e15a33aee9340388e677b1c60d361b28987e437dd2dd4709e5ba5a */
/* SGI MC memory controller of the R4000 Indigo, Indy and Indigo2: CPU control,
 * GIO arbitration, memory configuration, error reporting and the graphics DMA
 * engine */
#ifndef MC_GEN_H
#define MC_GEN_H

#include <stdint.h>


/*
 * CPU control 0: refresh, parity reporting, watchdog enable, system and
 * graphics reset, interrupt enable, PROM-write bus error, warm resets, the
 * little-endian toggle, the MUX FIFO high-water mark and the bus-error data
 * stall. The Indigo PROM reads this register back after every store to any MC
 * register, as a write-buffer flush, and the kernel's first-revision workaround
 * is a dummy PROM read before each MC store. A qtest can check the reset value,
 * that the stall field and the high-water field read back what was written, and
 * that writing the warm-restart bit restarts the CPU without clearing memory.
 */
/* cpuctrl0: rw32, space mc, reset 0x100012; MC Chip Specification, section 5.1;
 * IRIX sys/mc.h */
#define MC_CPUCTRL0_OFFSET                           0x4u /* established */
#define MC_CPUCTRL0_BUS_RATE_SHIFT                   28 /* established */
#define MC_CPUCTRL0_BUS_RATE_MASK                    0xfu
#define MC_CPUCTRL0_BUS_RATE_INPLACE (MC_CPUCTRL0_BUS_RATE_MASK << MC_CPUCTRL0_BUS_RATE_SHIFT)
#define MC_CPUCTRL0_BACK2_SHIFT                      27 /* established */
#define MC_CPUCTRL0_BACK2_MASK                       0x1u
#define MC_CPUCTRL0_BACK2_INPLACE (MC_CPUCTRL0_BACK2_MASK << MC_CPUCTRL0_BACK2_SHIFT)
#define MC_CPUCTRL0_R4K_CHK_PAR_N_SHIFT              26 /* established */
#define MC_CPUCTRL0_R4K_CHK_PAR_N_MASK               0x1u
#define MC_CPUCTRL0_R4K_CHK_PAR_N_INPLACE (MC_CPUCTRL0_R4K_CHK_PAR_N_MASK << MC_CPUCTRL0_R4K_CHK_PAR_N_SHIFT)
#define MC_CPUCTRL0_BAD_PAR_SHIFT                    25 /* established */
#define MC_CPUCTRL0_BAD_PAR_MASK                     0x1u
#define MC_CPUCTRL0_BAD_PAR_INPLACE (MC_CPUCTRL0_BAD_PAR_MASK << MC_CPUCTRL0_BAD_PAR_SHIFT)
#define MC_CPUCTRL0_MUX_HWM_SHIFT                    20 /* established */
#define MC_CPUCTRL0_MUX_HWM_MASK                     0x1fu
#define MC_CPUCTRL0_MUX_HWM_INPLACE (MC_CPUCTRL0_MUX_HWM_MASK << MC_CPUCTRL0_MUX_HWM_SHIFT)
#define MC_CPUCTRL0_WRST_SHIFT                       19 /* established */
#define MC_CPUCTRL0_WRST_MASK                        0x1u
#define MC_CPUCTRL0_WRST_INPLACE (MC_CPUCTRL0_WRST_MASK << MC_CPUCTRL0_WRST_SHIFT)
#define MC_CPUCTRL0_LITTLE_SHIFT                     18 /* established */
#define MC_CPUCTRL0_LITTLE_MASK                      0x1u
#define MC_CPUCTRL0_LITTLE_INPLACE (MC_CPUCTRL0_LITTLE_MASK << MC_CPUCTRL0_LITTLE_SHIFT)
#define MC_CPUCTRL0_WR_ST_SHIFT                      16 /* established */
#define MC_CPUCTRL0_WR_ST_MASK                       0x1u
#define MC_CPUCTRL0_WR_ST_INPLACE (MC_CPUCTRL0_WR_ST_MASK << MC_CPUCTRL0_WR_ST_SHIFT)
#define MC_CPUCTRL0_PROM_WR_EN_SHIFT                 15 /* established */
#define MC_CPUCTRL0_PROM_WR_EN_MASK                  0x1u
#define MC_CPUCTRL0_PROM_WR_EN_INPLACE (MC_CPUCTRL0_PROM_WR_EN_MASK << MC_CPUCTRL0_PROM_WR_EN_SHIFT)
#define MC_CPUCTRL0_SNOOP_EN_SHIFT                   14 /* established */
#define MC_CPUCTRL0_SNOOP_EN_MASK                    0x1u
#define MC_CPUCTRL0_SNOOP_EN_INPLACE (MC_CPUCTRL0_SNOOP_EN_MASK << MC_CPUCTRL0_SNOOP_EN_SHIFT)
#define MC_CPUCTRL0_INT_EN_SHIFT                     13 /* established */
#define MC_CPUCTRL0_INT_EN_MASK                      0x1u
#define MC_CPUCTRL0_INT_EN_INPLACE (MC_CPUCTRL0_INT_EN_MASK << MC_CPUCTRL0_INT_EN_SHIFT)
#define MC_CPUCTRL0_CMD_PAR_SHIFT                    12 /* established */
#define MC_CPUCTRL0_CMD_PAR_MASK                     0x1u
#define MC_CPUCTRL0_CMD_PAR_INPLACE (MC_CPUCTRL0_CMD_PAR_MASK << MC_CPUCTRL0_CMD_PAR_SHIFT)
#define MC_CPUCTRL0_EN_LOCK_SHIFT                    11 /* established */
#define MC_CPUCTRL0_EN_LOCK_MASK                     0x1u
#define MC_CPUCTRL0_EN_LOCK_INPLACE (MC_CPUCTRL0_EN_LOCK_MASK << MC_CPUCTRL0_EN_LOCK_SHIFT)
#define MC_CPUCTRL0_GRR_SHIFT                        10 /* established */
#define MC_CPUCTRL0_GRR_MASK                         0x1u
#define MC_CPUCTRL0_GRR_INPLACE (MC_CPUCTRL0_GRR_MASK << MC_CPUCTRL0_GRR_SHIFT)
#define MC_CPUCTRL0_SIN_SHIFT                        9 /* established */
#define MC_CPUCTRL0_SIN_MASK                         0x1u
#define MC_CPUCTRL0_SIN_INPLACE (MC_CPUCTRL0_SIN_MASK << MC_CPUCTRL0_SIN_SHIFT)
#define MC_CPUCTRL0_DOG_SHIFT                        8 /* established */
#define MC_CPUCTRL0_DOG_MASK                         0x1u
#define MC_CPUCTRL0_DOG_INPLACE (MC_CPUCTRL0_DOG_MASK << MC_CPUCTRL0_DOG_SHIFT)
#define MC_CPUCTRL0_CPR_SHIFT                        7 /* established */
#define MC_CPUCTRL0_CPR_MASK                         0x1u
#define MC_CPUCTRL0_CPR_INPLACE (MC_CPUCTRL0_CPR_MASK << MC_CPUCTRL0_CPR_SHIFT)
#define MC_CPUCTRL0_MPR_SHIFT                        6 /* established */
#define MC_CPUCTRL0_MPR_MASK                         0x1u
#define MC_CPUCTRL0_MPR_INPLACE (MC_CPUCTRL0_MPR_MASK << MC_CPUCTRL0_MPR_SHIFT)
#define MC_CPUCTRL0_GPR_SHIFT                        5 /* established */
#define MC_CPUCTRL0_GPR_MASK                         0x1u
#define MC_CPUCTRL0_GPR_INPLACE (MC_CPUCTRL0_GPR_MASK << MC_CPUCTRL0_GPR_SHIFT)
#define MC_CPUCTRL0_RFE_SHIFT                        4 /* established */
#define MC_CPUCTRL0_RFE_MASK                         0x1u
#define MC_CPUCTRL0_RFE_INPLACE (MC_CPUCTRL0_RFE_MASK << MC_CPUCTRL0_RFE_SHIFT)
#define MC_CPUCTRL0_REFS_SHIFT                       0 /* established */
#define MC_CPUCTRL0_REFS_MASK                        0xfu
#define MC_CPUCTRL0_REFS_INPLACE (MC_CPUCTRL0_REFS_MASK << MC_CPUCTRL0_REFS_SHIFT)

/*
 * CPU control 1: the CPU address/command FIFO high-water mark, GIO bus timeout
 * enable and the fixed-endianness selects for the HPC and the two GIO slots.
 * The HPC fixed bit must be set for an HPC1.5, which every Indigo uses, and
 * clear for an HPC3. A qtest can check the reset value and that bits outside
 * the defined ones read back as written or as zero (the source does not say
 * which).
 */
/* cpuctrl1: rw32, space mc, reset 0xc; MC Chip Specification, section 5.2; IRIX
 * sys/mc.h */
#define MC_CPUCTRL1_OFFSET                           0xcu /* established */
#define MC_CPUCTRL1_EXP1_LITTLE_SHIFT                17 /* established */
#define MC_CPUCTRL1_EXP1_LITTLE_MASK                 0x1u
#define MC_CPUCTRL1_EXP1_LITTLE_INPLACE (MC_CPUCTRL1_EXP1_LITTLE_MASK << MC_CPUCTRL1_EXP1_LITTLE_SHIFT)
#define MC_CPUCTRL1_EXP1_FX_SHIFT                    16 /* established */
#define MC_CPUCTRL1_EXP1_FX_MASK                     0x1u
#define MC_CPUCTRL1_EXP1_FX_INPLACE (MC_CPUCTRL1_EXP1_FX_MASK << MC_CPUCTRL1_EXP1_FX_SHIFT)
#define MC_CPUCTRL1_EXP0_LITTLE_SHIFT                15 /* established */
#define MC_CPUCTRL1_EXP0_LITTLE_MASK                 0x1u
#define MC_CPUCTRL1_EXP0_LITTLE_INPLACE (MC_CPUCTRL1_EXP0_LITTLE_MASK << MC_CPUCTRL1_EXP0_LITTLE_SHIFT)
#define MC_CPUCTRL1_EXP0_FX_SHIFT                    14 /* established */
#define MC_CPUCTRL1_EXP0_FX_MASK                     0x1u
#define MC_CPUCTRL1_EXP0_FX_INPLACE (MC_CPUCTRL1_EXP0_FX_MASK << MC_CPUCTRL1_EXP0_FX_SHIFT)
#define MC_CPUCTRL1_HPC_LITTLE_SHIFT                 13 /* established */
#define MC_CPUCTRL1_HPC_LITTLE_MASK                  0x1u
#define MC_CPUCTRL1_HPC_LITTLE_INPLACE (MC_CPUCTRL1_HPC_LITTLE_MASK << MC_CPUCTRL1_HPC_LITTLE_SHIFT)
#define MC_CPUCTRL1_HPC_FX_SHIFT                     12 /* established */
#define MC_CPUCTRL1_HPC_FX_MASK                      0x1u
#define MC_CPUCTRL1_HPC_FX_INPLACE (MC_CPUCTRL1_HPC_FX_MASK << MC_CPUCTRL1_HPC_FX_SHIFT)
#define MC_CPUCTRL1_ABORT_EN_SHIFT                   4 /* established */
#define MC_CPUCTRL1_ABORT_EN_MASK                    0x1u
#define MC_CPUCTRL1_ABORT_EN_INPLACE (MC_CPUCTRL1_ABORT_EN_MASK << MC_CPUCTRL1_ABORT_EN_SHIFT)
#define MC_CPUCTRL1_MC_HWM_SHIFT                     0 /* established */
#define MC_CPUCTRL1_MC_HWM_MASK                      0xfu
#define MC_CPUCTRL1_MC_HWM_INPLACE (MC_CPUCTRL1_MC_HWM_MASK << MC_CPUCTRL1_MC_HWM_SHIFT)

/*
 * Watchdog timer. A read returns the 20-bit counter, which counts refresh
 * bursts and so wraps in about 67 seconds at the 62 microsecond refresh
 * interval; any write clears it. When CPUCTRL0 enables the watchdog, a wrap
 * resets the machine. IRIX names the read and the write DOGC and DOGR.
 */
/* dogc: rw32, space mc, reset 0x0; MC Chip Specification, section 5.3; IRIX
 * sys/mc.h */
#define MC_DOGC_OFFSET                               0x14u /* established */
#define MC_DOGC_COUNT_SHIFT                          0 /* established */
#define MC_DOGC_COUNT_MASK                           0xfffffu
#define MC_DOGC_COUNT_INPLACE (MC_DOGC_COUNT_MASK << MC_DOGC_COUNT_SHIFT)

/*
 * MC revision and EISA-present bit. The specification gives revision A as 0 and
 * revision B as 1; IRIX code treats revisions 0 and 1 specially and refers to a
 * 'revision C' part for large DRAM, which is inferred to read 3.
 */
/* sysid: r32, space mc, reset unknown; MC Chip Specification, section 5.4; IRIX
 * sys/mc.h */
#define MC_SYSID_OFFSET                              0x1cu /* established */
#define MC_SYSID_EISA_SHIFT                          4 /* established */
#define MC_SYSID_EISA_MASK                           0x1u
#define MC_SYSID_EISA_INPLACE (MC_SYSID_EISA_MASK << MC_SYSID_EISA_SHIFT)
#define MC_SYSID_CHIP_REV_SHIFT                      0 /* established */
#define MC_SYSID_CHIP_REV_MASK                       0xfu
#define MC_SYSID_CHIP_REV_INPLACE (MC_SYSID_CHIP_REV_MASK << MC_SYSID_CHIP_REV_SHIFT)

/*
 * Divider and increment for the RPSS counter. The counter adds the increment
 * each time the CPU clock has been divided by the divider plus one. At a 50 MHz
 * CPU clock the reset value (divide by five, add one) counts every 100
 * nanoseconds; for a 33 MHz clock the specification says divide by ten and add
 * three. IRIX kernels write a different value (divide by two, add one).
 */
/* rpss_divider: rw32, space mc, reset 0x104; MC Chip Specification, section
 * 5.5; IRIX sys/mc.h */
#define MC_RPSS_DIVIDER_OFFSET                       0x2cu /* established */
#define MC_RPSS_DIVIDER_INC_SHIFT                    8 /* established */
#define MC_RPSS_DIVIDER_INC_MASK                     0xffu
#define MC_RPSS_DIVIDER_INC_INPLACE (MC_RPSS_DIVIDER_INC_MASK << MC_RPSS_DIVIDER_INC_SHIFT)
#define MC_RPSS_DIVIDER_DIV_SHIFT                    0 /* established */
#define MC_RPSS_DIVIDER_DIV_MASK                     0xffu
#define MC_RPSS_DIVIDER_DIV_INPLACE (MC_RPSS_DIVIDER_DIV_MASK << MC_RPSS_DIVIDER_DIV_SHIFT)

/*
 * Bit-banged serial interface to the 93C56-class EEPROM that holds the R4000
 * mode stream. The first three EEPROM bits are read by the MC itself at reset:
 * byte order, HPC bus width and a reserved bit. Software rewrites the EEPROM
 * through this register and then restarts the CPU to change byte order. The
 * data-in bit cannot be written. A qtest can check that data-in follows the
 * modelled EEPROM and that chip-select and clock read back.
 */
/* eerom: rw32, space mc, reset 0x0; MC Chip Specification, section 5.6; IRIX
 * sys/mc.h */
#define MC_EEROM_OFFSET                              0x34u /* established */
#define MC_EEROM_SDATA_IN_SHIFT                      4 /* established */
#define MC_EEROM_SDATA_IN_MASK                       0x1u
#define MC_EEROM_SDATA_IN_INPLACE (MC_EEROM_SDATA_IN_MASK << MC_EEROM_SDATA_IN_SHIFT)
#define MC_EEROM_SDATA_OUT_SHIFT                     3 /* established */
#define MC_EEROM_SDATA_OUT_MASK                      0x1u
#define MC_EEROM_SDATA_OUT_INPLACE (MC_EEROM_SDATA_OUT_MASK << MC_EEROM_SDATA_OUT_SHIFT)
#define MC_EEROM_SCK_SHIFT                           2 /* established */
#define MC_EEROM_SCK_MASK                            0x1u
#define MC_EEROM_SCK_INPLACE (MC_EEROM_SCK_MASK << MC_EEROM_SCK_SHIFT)
#define MC_EEROM_CS_SHIFT                            1 /* established */
#define MC_EEROM_CS_MASK                             0x1u
#define MC_EEROM_CS_INPLACE (MC_EEROM_CS_MASK << MC_EEROM_CS_SHIFT)
#define MC_EEROM_PRE_SHIFT                           0 /* inferred */
#define MC_EEROM_PRE_MASK                            0x1u
#define MC_EEROM_PRE_INPLACE (MC_EEROM_PRE_MASK << MC_EEROM_PRE_SHIFT)

/*
 * Refresh counter preload. The counter counts down at the CPU clock and, on
 * reaching zero, reloads from this register and requests a refresh burst. It
 * should hold the number of CPU clocks in 62.5 microseconds.
 */
/* ctrld: rw32, space mc, reset 0xc30; MC Chip Specification, section 5.7; IRIX
 * sys/mc.h */
#define MC_CTRLD_OFFSET                              0x44u /* established */
#define MC_CTRLD_REF_SHIFT                           0 /* established */
#define MC_CTRLD_REF_MASK                            0xffffu
#define MC_CTRLD_REF_INPLACE (MC_CTRLD_REF_MASK << MC_CTRLD_REF_SHIFT)

/*
 * Current value of the refresh counter.
 */
/* ref_ctr: r32, space mc, reset unknown; MC Chip Specification, section 5.8;
 * IRIX sys/mc.h */
#define MC_REF_CTR_OFFSET                            0x4cu /* established */
#define MC_REF_CTR_REFC_SHIFT                        0 /* established */
#define MC_REF_CTR_REFC_MASK                         0xffffu
#define MC_REF_CTR_REFC_INPLACE (MC_REF_CTR_REFC_MASK << MC_REF_CTR_REFC_SHIFT)

/*
 * GIO arbitration parameters: per-device bus width, real-time or long-burst
 * class, bus-master ability and pipelining. Real-time devices are served in
 * fixed priority; long-burst devices round-robin with the CPU between each. The
 * IRIX kernel comments that reads of this register and of the two time
 * registers can return corrupted values, so it writes from a software copy and
 * never reads back. A qtest can check the reset value and that every defined
 * bit stores.
 */
/* gio64_arb: rw32, space mc, reset 0x400; MC Chip Specification, section 5.9;
 * IRIX sys/mc.h */
#define MC_GIO64_ARB_OFFSET                          0x84u /* established */
#define MC_GIO64_ARB_EXP1_PIPED_SHIFT                15 /* established */
#define MC_GIO64_ARB_EXP1_PIPED_MASK                 0x1u
#define MC_GIO64_ARB_EXP1_PIPED_INPLACE (MC_GIO64_ARB_EXP1_PIPED_MASK << MC_GIO64_ARB_EXP1_PIPED_SHIFT)
#define MC_GIO64_ARB_EXP0_PIPED_SHIFT                14 /* established */
#define MC_GIO64_ARB_EXP0_PIPED_MASK                 0x1u
#define MC_GIO64_ARB_EXP0_PIPED_INPLACE (MC_GIO64_ARB_EXP0_PIPED_MASK << MC_GIO64_ARB_EXP0_PIPED_SHIFT)
#define MC_GIO64_ARB_EXP1_MST_SHIFT                  13 /* established */
#define MC_GIO64_ARB_EXP1_MST_MASK                   0x1u
#define MC_GIO64_ARB_EXP1_MST_INPLACE (MC_GIO64_ARB_EXP1_MST_MASK << MC_GIO64_ARB_EXP1_MST_SHIFT)
#define MC_GIO64_ARB_EXP0_MST_SHIFT                  12 /* established */
#define MC_GIO64_ARB_EXP0_MST_MASK                   0x1u
#define MC_GIO64_ARB_EXP0_MST_INPLACE (MC_GIO64_ARB_EXP0_MST_MASK << MC_GIO64_ARB_EXP0_MST_SHIFT)
#define MC_GIO64_ARB_GRX_MST_SHIFT                   11 /* established */
#define MC_GIO64_ARB_GRX_MST_MASK                    0x1u
#define MC_GIO64_ARB_GRX_MST_INPLACE (MC_GIO64_ARB_GRX_MST_MASK << MC_GIO64_ARB_GRX_MST_SHIFT)
#define MC_GIO64_ARB_ONE_GIO_SHIFT                   10 /* established */
#define MC_GIO64_ARB_ONE_GIO_MASK                    0x1u
#define MC_GIO64_ARB_ONE_GIO_INPLACE (MC_GIO64_ARB_ONE_GIO_MASK << MC_GIO64_ARB_ONE_GIO_SHIFT)
#define MC_GIO64_ARB_EISA_MST_SHIFT                  9 /* established */
#define MC_GIO64_ARB_EISA_MST_MASK                   0x1u
#define MC_GIO64_ARB_EISA_MST_INPLACE (MC_GIO64_ARB_EISA_MST_MASK << MC_GIO64_ARB_EISA_MST_SHIFT)
#define MC_GIO64_ARB_EXP1_RT_SHIFT                   8 /* established */
#define MC_GIO64_ARB_EXP1_RT_MASK                    0x1u
#define MC_GIO64_ARB_EXP1_RT_INPLACE (MC_GIO64_ARB_EXP1_RT_MASK << MC_GIO64_ARB_EXP1_RT_SHIFT)
#define MC_GIO64_ARB_EXP0_RT_SHIFT                   7 /* established */
#define MC_GIO64_ARB_EXP0_RT_MASK                    0x1u
#define MC_GIO64_ARB_EXP0_RT_INPLACE (MC_GIO64_ARB_EXP0_RT_MASK << MC_GIO64_ARB_EXP0_RT_SHIFT)
#define MC_GIO64_ARB_GRX_RT_SHIFT                    6 /* established */
#define MC_GIO64_ARB_GRX_RT_MASK                     0x1u
#define MC_GIO64_ARB_GRX_RT_INPLACE (MC_GIO64_ARB_GRX_RT_MASK << MC_GIO64_ARB_GRX_RT_SHIFT)
#define MC_GIO64_ARB_HPC_EXP_SIZE_64_SHIFT           5 /* established */
#define MC_GIO64_ARB_HPC_EXP_SIZE_64_MASK            0x1u
#define MC_GIO64_ARB_HPC_EXP_SIZE_64_INPLACE (MC_GIO64_ARB_HPC_EXP_SIZE_64_MASK << MC_GIO64_ARB_HPC_EXP_SIZE_64_SHIFT)
#define MC_GIO64_ARB_EISA_SIZE_64_SHIFT              4 /* established */
#define MC_GIO64_ARB_EISA_SIZE_64_MASK               0x1u
#define MC_GIO64_ARB_EISA_SIZE_64_INPLACE (MC_GIO64_ARB_EISA_SIZE_64_MASK << MC_GIO64_ARB_EISA_SIZE_64_SHIFT)
#define MC_GIO64_ARB_EXP1_SIZE_64_SHIFT              3 /* established */
#define MC_GIO64_ARB_EXP1_SIZE_64_MASK               0x1u
#define MC_GIO64_ARB_EXP1_SIZE_64_INPLACE (MC_GIO64_ARB_EXP1_SIZE_64_MASK << MC_GIO64_ARB_EXP1_SIZE_64_SHIFT)
#define MC_GIO64_ARB_EXP0_SIZE_64_SHIFT              2 /* established */
#define MC_GIO64_ARB_EXP0_SIZE_64_MASK               0x1u
#define MC_GIO64_ARB_EXP0_SIZE_64_INPLACE (MC_GIO64_ARB_EXP0_SIZE_64_MASK << MC_GIO64_ARB_EXP0_SIZE_64_SHIFT)
#define MC_GIO64_ARB_GRX_SIZE_64_SHIFT               1 /* established */
#define MC_GIO64_ARB_GRX_SIZE_64_MASK                0x1u
#define MC_GIO64_ARB_GRX_SIZE_64_INPLACE (MC_GIO64_ARB_GRX_SIZE_64_MASK << MC_GIO64_ARB_GRX_SIZE_64_SHIFT)
#define MC_GIO64_ARB_HPC_SIZE_64_SHIFT               0 /* established */
#define MC_GIO64_ARB_HPC_SIZE_64_MASK                0x1u
#define MC_GIO64_ARB_HPC_SIZE_64_INPLACE (MC_GIO64_ARB_HPC_SIZE_64_MASK << MC_GIO64_ARB_HPC_SIZE_64_SHIFT)

/*
 * Length of the CPU's arbitration slot in GIO clocks. The CPU holds the bus for
 * the whole period even if idle. IRIX writes 43 (about 1.3 microseconds at 33
 * MHz).
 */
/* cpu_time: rw32, space mc, reset 0x100; MC Chip Specification, section 5.10;
 * IRIX sys/mc.h */
#define MC_CPU_TIME_OFFSET                           0x8cu /* established */
#define MC_CPU_TIME_TIME_SHIFT                       0 /* established */
#define MC_CPU_TIME_TIME_MASK                        0xffffu
#define MC_CPU_TIME_TIME_INPLACE (MC_CPU_TIME_TIME_MASK << MC_CPU_TIME_TIME_SHIFT)

/*
 * Length of the long-burst devices' arbitration slot in GIO clocks. Unlike the
 * CPU's, a long-burst slot ends when the device stops using the bus. IRIX
 * writes 847 (about 25 microseconds at 33 MHz).
 */
/* lb_time: rw32, space mc, reset 0x200; MC Chip Specification, section 5.11;
 * IRIX sys/mc.h */
#define MC_LB_TIME_OFFSET                            0x9cu /* established */
#define MC_LB_TIME_TIME_SHIFT                        0 /* established */
#define MC_LB_TIME_TIME_MASK                         0xffffu
#define MC_LB_TIME_TIME_INPLACE (MC_LB_TIME_TIME_MASK << MC_LB_TIME_TIME_SHIFT)

/*
 * Memory configuration for banks 0 (high half) and 1 (low half). Each bank is
 * four 36-bit SIMMs of one size. The base is compared with physical address
 * bits 29 to 22, so it is in 4 MiB units and must be a multiple of the bank
 * size; larger banks go at lower bases. A zero half means no usable bank. The
 * specification gives only the valid bits a reset value of 0. If two valid
 * banks overlap, accesses raise a bus error and do not complete.
 */
/* memcfg0: rw32, space mc, reset unknown; MC Chip Specification, section 5.12;
 * IRIX sys/mc.h and the IRIX kernel's bank code */
#define MC_MEMCFG0_OFFSET                            0xc4u /* established */
#define MC_MEMCFG0_BNK0_SHIFT                        30 /* established */
#define MC_MEMCFG0_BNK0_MASK                         0x1u
#define MC_MEMCFG0_BNK0_INPLACE (MC_MEMCFG0_BNK0_MASK << MC_MEMCFG0_BNK0_SHIFT)
#define MC_MEMCFG0_VLD0_SHIFT                        29 /* established */
#define MC_MEMCFG0_VLD0_MASK                         0x1u
#define MC_MEMCFG0_VLD0_INPLACE (MC_MEMCFG0_VLD0_MASK << MC_MEMCFG0_VLD0_SHIFT)
#define MC_MEMCFG0_MSIZE0_SHIFT                      24 /* established */
#define MC_MEMCFG0_MSIZE0_MASK                       0x1fu
#define MC_MEMCFG0_MSIZE0_INPLACE (MC_MEMCFG0_MSIZE0_MASK << MC_MEMCFG0_MSIZE0_SHIFT)
#define MC_MEMCFG0_BASE0_SHIFT                       16 /* established */
#define MC_MEMCFG0_BASE0_MASK                        0xffu
#define MC_MEMCFG0_BASE0_INPLACE (MC_MEMCFG0_BASE0_MASK << MC_MEMCFG0_BASE0_SHIFT)
#define MC_MEMCFG0_BNK1_SHIFT                        14 /* established */
#define MC_MEMCFG0_BNK1_MASK                         0x1u
#define MC_MEMCFG0_BNK1_INPLACE (MC_MEMCFG0_BNK1_MASK << MC_MEMCFG0_BNK1_SHIFT)
#define MC_MEMCFG0_VLD1_SHIFT                        13 /* established */
#define MC_MEMCFG0_VLD1_MASK                         0x1u
#define MC_MEMCFG0_VLD1_INPLACE (MC_MEMCFG0_VLD1_MASK << MC_MEMCFG0_VLD1_SHIFT)
#define MC_MEMCFG0_MSIZE1_SHIFT                      8 /* established */
#define MC_MEMCFG0_MSIZE1_MASK                       0x1fu
#define MC_MEMCFG0_MSIZE1_INPLACE (MC_MEMCFG0_MSIZE1_MASK << MC_MEMCFG0_MSIZE1_SHIFT)
#define MC_MEMCFG0_BASE1_SHIFT                       0 /* established */
#define MC_MEMCFG0_BASE1_MASK                        0xffu
#define MC_MEMCFG0_BASE1_INPLACE (MC_MEMCFG0_BASE1_MASK << MC_MEMCFG0_BASE1_SHIFT)

/*
 * Memory configuration for banks 2 (high half) and 3 (low half); the layout is
 * that of the first configuration register.
 */
/* memcfg1: rw32, space mc, reset unknown; MC Chip Specification, section 5.12;
 * IRIX sys/mc.h and the IRIX kernel's bank code */
#define MC_MEMCFG1_OFFSET                            0xccu /* established */
#define MC_MEMCFG1_BNK2_SHIFT                        30 /* established */
#define MC_MEMCFG1_BNK2_MASK                         0x1u
#define MC_MEMCFG1_BNK2_INPLACE (MC_MEMCFG1_BNK2_MASK << MC_MEMCFG1_BNK2_SHIFT)
#define MC_MEMCFG1_VLD2_SHIFT                        29 /* established */
#define MC_MEMCFG1_VLD2_MASK                         0x1u
#define MC_MEMCFG1_VLD2_INPLACE (MC_MEMCFG1_VLD2_MASK << MC_MEMCFG1_VLD2_SHIFT)
#define MC_MEMCFG1_MSIZE2_SHIFT                      24 /* established */
#define MC_MEMCFG1_MSIZE2_MASK                       0x1fu
#define MC_MEMCFG1_MSIZE2_INPLACE (MC_MEMCFG1_MSIZE2_MASK << MC_MEMCFG1_MSIZE2_SHIFT)
#define MC_MEMCFG1_BASE2_SHIFT                       16 /* established */
#define MC_MEMCFG1_BASE2_MASK                        0xffu
#define MC_MEMCFG1_BASE2_INPLACE (MC_MEMCFG1_BASE2_MASK << MC_MEMCFG1_BASE2_SHIFT)
#define MC_MEMCFG1_BNK3_SHIFT                        14 /* established */
#define MC_MEMCFG1_BNK3_MASK                         0x1u
#define MC_MEMCFG1_BNK3_INPLACE (MC_MEMCFG1_BNK3_MASK << MC_MEMCFG1_BNK3_SHIFT)
#define MC_MEMCFG1_VLD3_SHIFT                        13 /* established */
#define MC_MEMCFG1_VLD3_MASK                         0x1u
#define MC_MEMCFG1_VLD3_INPLACE (MC_MEMCFG1_VLD3_MASK << MC_MEMCFG1_VLD3_SHIFT)
#define MC_MEMCFG1_MSIZE3_SHIFT                      8 /* established */
#define MC_MEMCFG1_MSIZE3_MASK                       0x1fu
#define MC_MEMCFG1_MSIZE3_INPLACE (MC_MEMCFG1_MSIZE3_MASK << MC_MEMCFG1_MSIZE3_SHIFT)
#define MC_MEMCFG1_BASE3_SHIFT                       0 /* established */
#define MC_MEMCFG1_BASE3_MASK                        0xffu
#define MC_MEMCFG1_BASE3_INPLACE (MC_MEMCFG1_BASE3_MASK << MC_MEMCFG1_BASE3_SHIFT)

/*
 * DRAM timing used for CPU accesses, in CPU clocks. The Indigo PROM writes
 * 0x11453433 and tests the register by walking a one bit through the low 28
 * bits, then restoring the old value. A qtest can check the reset value and
 * that bits 27 to 0 store.
 */
/* cpu_memacc: rw32, space mc, reset 0x1454333; MC Chip Specification, section
 * 5.13; IRIX sys/mc.h */
#define MC_CPU_MEMACC_OFFSET                         0xd4u /* established */
#define MC_CPU_MEMACC_BIG_ALIAS_SHIFT                29 /* established */
#define MC_CPU_MEMACC_BIG_ALIAS_MASK                 0x1u
#define MC_CPU_MEMACC_BIG_ALIAS_INPLACE (MC_CPU_MEMACC_BIG_ALIAS_MASK << MC_CPU_MEMACC_BIG_ALIAS_SHIFT)
#define MC_CPU_MEMACC_CAS_HALF_SHIFT                 28 /* established */
#define MC_CPU_MEMACC_CAS_HALF_MASK                  0x1u
#define MC_CPU_MEMACC_CAS_HALF_INPLACE (MC_CPU_MEMACC_CAS_HALF_MASK << MC_CPU_MEMACC_CAS_HALF_SHIFT)
#define MC_CPU_MEMACC_CBR_SHIFT                      24 /* established */
#define MC_CPU_MEMACC_CBR_MASK                       0xfu
#define MC_CPU_MEMACC_CBR_INPLACE (MC_CPU_MEMACC_CBR_MASK << MC_CPU_MEMACC_CBR_SHIFT)
#define MC_CPU_MEMACC_RASL_SHIFT                     20 /* established */
#define MC_CPU_MEMACC_RASL_MASK                      0xfu
#define MC_CPU_MEMACC_RASL_INPLACE (MC_CPU_MEMACC_RASL_MASK << MC_CPU_MEMACC_RASL_SHIFT)
#define MC_CPU_MEMACC_RCASL_SHIFT                    16 /* established */
#define MC_CPU_MEMACC_RCASL_MASK                     0xfu
#define MC_CPU_MEMACC_RCASL_INPLACE (MC_CPU_MEMACC_RCASL_MASK << MC_CPU_MEMACC_RCASL_SHIFT)
#define MC_CPU_MEMACC_RASH_SHIFT                     12 /* established */
#define MC_CPU_MEMACC_RASH_MASK                      0xfu
#define MC_CPU_MEMACC_RASH_INPLACE (MC_CPU_MEMACC_RASH_MASK << MC_CPU_MEMACC_RASH_SHIFT)
#define MC_CPU_MEMACC_ROW_SHIFT                      8 /* established */
#define MC_CPU_MEMACC_ROW_MASK                       0xfu
#define MC_CPU_MEMACC_ROW_INPLACE (MC_CPU_MEMACC_ROW_MASK << MC_CPU_MEMACC_ROW_SHIFT)
#define MC_CPU_MEMACC_RD_COL_SHIFT                   4 /* established */
#define MC_CPU_MEMACC_RD_COL_MASK                    0xfu
#define MC_CPU_MEMACC_RD_COL_INPLACE (MC_CPU_MEMACC_RD_COL_MASK << MC_CPU_MEMACC_RD_COL_SHIFT)
#define MC_CPU_MEMACC_WR_COL_SHIFT                   0 /* established */
#define MC_CPU_MEMACC_WR_COL_MASK                    0xfu
#define MC_CPU_MEMACC_WR_COL_INPLACE (MC_CPU_MEMACC_WR_COL_MASK << MC_CPU_MEMACC_WR_COL_SHIFT)

/*
 * DRAM timing used for GIO accesses, in GIO clocks. The specification
 * recommends write and read column 2, row 3 and precharge 2; the Indigo PROM
 * writes read column 3, the Indy and Indigo2 PROMs read column 2.
 */
/* gio_memacc: rw32, space mc, reset 0x4333; MC Chip Specification, section
 * 5.13; IRIX sys/mc.h */
#define MC_GIO_MEMACC_OFFSET                         0xdcu /* established */
#define MC_GIO_MEMACC_BIG_ALIAS_SHIFT                29 /* established */
#define MC_GIO_MEMACC_BIG_ALIAS_MASK                 0x1u
#define MC_GIO_MEMACC_BIG_ALIAS_INPLACE (MC_GIO_MEMACC_BIG_ALIAS_MASK << MC_GIO_MEMACC_BIG_ALIAS_SHIFT)
#define MC_GIO_MEMACC_ADDR_HALF_SHIFT                17 /* established */
#define MC_GIO_MEMACC_ADDR_HALF_MASK                 0x1u
#define MC_GIO_MEMACC_ADDR_HALF_INPLACE (MC_GIO_MEMACC_ADDR_HALF_MASK << MC_GIO_MEMACC_ADDR_HALF_SHIFT)
#define MC_GIO_MEMACC_CAS_HALF_SHIFT                 16 /* established */
#define MC_GIO_MEMACC_CAS_HALF_MASK                  0x1u
#define MC_GIO_MEMACC_CAS_HALF_INPLACE (MC_GIO_MEMACC_CAS_HALF_MASK << MC_GIO_MEMACC_CAS_HALF_SHIFT)
#define MC_GIO_MEMACC_RASH_SHIFT                     12 /* established */
#define MC_GIO_MEMACC_RASH_MASK                      0xfu
#define MC_GIO_MEMACC_RASH_INPLACE (MC_GIO_MEMACC_RASH_MASK << MC_GIO_MEMACC_RASH_SHIFT)
#define MC_GIO_MEMACC_ROW_SHIFT                      8 /* established */
#define MC_GIO_MEMACC_ROW_MASK                       0xfu
#define MC_GIO_MEMACC_ROW_INPLACE (MC_GIO_MEMACC_ROW_MASK << MC_GIO_MEMACC_ROW_SHIFT)
#define MC_GIO_MEMACC_RD_COL_SHIFT                   4 /* established */
#define MC_GIO_MEMACC_RD_COL_MASK                    0xfu
#define MC_GIO_MEMACC_RD_COL_INPLACE (MC_GIO_MEMACC_RD_COL_MASK << MC_GIO_MEMACC_RD_COL_SHIFT)
#define MC_GIO_MEMACC_WR_COL_SHIFT                   0 /* established */
#define MC_GIO_MEMACC_WR_COL_MASK                    0xfu
#define MC_GIO_MEMACC_WR_COL_INPLACE (MC_GIO_MEMACC_WR_COL_MASK << MC_GIO_MEMACC_WR_COL_SHIFT)

/*
 * Address of the last CPU parity or bus error; valid only while an error bit is
 * set in the CPU error status. For a parity error the low three bits are
 * meaningless and the status byte field gives the failing byte lane. The
 * specification's revision B fix list says revision A could latch the wrong
 * address when a write follows a read that failed parity.
 */
/* cpu_err_addr: r32, space mc, reset 0x0; MC Chip Specification, section 5.14;
 * IRIX sys/mc.h */
#define MC_CPU_ERR_ADDR_OFFSET                       0xe4u /* established */
#define MC_CPU_ERR_ADDR_ADDR_SHIFT                   0 /* established */
#define MC_CPU_ERR_ADDR_ADDR_MASK                    0xffffffffu
#define MC_CPU_ERR_ADDR_ADDR_INPLACE (MC_CPU_ERR_ADDR_ADDR_MASK << MC_CPU_ERR_ADDR_ADDR_SHIFT)

/*
 * CPU error status. Any write clears it (the PROM and the kernel write zero).
 * The bits are sticky. A qtest can check that a write of any value clears every
 * bit and that a CPU read of an unmapped address sets the address-error bit.
 */
/* cpu_err_stat: rw32, space mc, reset 0x0; MC Chip Specification, section 5.15;
 * IRIX sys/mc.h */
#define MC_CPU_ERR_STAT_OFFSET                       0xecu /* established */
#define MC_CPU_ERR_STAT_BAD_DATA_SHIFT               13 /* established */
#define MC_CPU_ERR_STAT_BAD_DATA_MASK                0x1u
#define MC_CPU_ERR_STAT_BAD_DATA_INPLACE (MC_CPU_ERR_STAT_BAD_DATA_MASK << MC_CPU_ERR_STAT_BAD_DATA_SHIFT)
#define MC_CPU_ERR_STAT_SYSCMD_PAR_SHIFT             12 /* established */
#define MC_CPU_ERR_STAT_SYSCMD_PAR_MASK              0x1u
#define MC_CPU_ERR_STAT_SYSCMD_PAR_INPLACE (MC_CPU_ERR_STAT_SYSCMD_PAR_MASK << MC_CPU_ERR_STAT_SYSCMD_PAR_SHIFT)
#define MC_CPU_ERR_STAT_SYSAD_PAR_SHIFT              11 /* established */
#define MC_CPU_ERR_STAT_SYSAD_PAR_MASK               0x1u
#define MC_CPU_ERR_STAT_SYSAD_PAR_INPLACE (MC_CPU_ERR_STAT_SYSAD_PAR_MASK << MC_CPU_ERR_STAT_SYSAD_PAR_SHIFT)
#define MC_CPU_ERR_STAT_ADDR_SHIFT                   10 /* established */
#define MC_CPU_ERR_STAT_ADDR_MASK                    0x1u
#define MC_CPU_ERR_STAT_ADDR_INPLACE (MC_CPU_ERR_STAT_ADDR_MASK << MC_CPU_ERR_STAT_ADDR_SHIFT)
#define MC_CPU_ERR_STAT_PAR_SHIFT                    9 /* established */
#define MC_CPU_ERR_STAT_PAR_MASK                     0x1u
#define MC_CPU_ERR_STAT_PAR_INPLACE (MC_CPU_ERR_STAT_PAR_MASK << MC_CPU_ERR_STAT_PAR_SHIFT)
#define MC_CPU_ERR_STAT_RD_SHIFT                     8 /* established */
#define MC_CPU_ERR_STAT_RD_MASK                      0x1u
#define MC_CPU_ERR_STAT_RD_INPLACE (MC_CPU_ERR_STAT_RD_MASK << MC_CPU_ERR_STAT_RD_SHIFT)
#define MC_CPU_ERR_STAT_BYTE_SHIFT                   0 /* established */
#define MC_CPU_ERR_STAT_BYTE_MASK                    0xffu
#define MC_CPU_ERR_STAT_BYTE_INPLACE (MC_CPU_ERR_STAT_BYTE_MASK << MC_CPU_ERR_STAT_BYTE_SHIFT)

/*
 * Address of the last GIO parity or bus error, valid while a GIO error bit is
 * set. Low two bits are meaningless for 32-bit devices, low three for 64-bit.
 */
/* gio_err_addr: r32, space mc, reset 0x0; MC Chip Specification, section 5.16;
 * IRIX sys/mc.h */
#define MC_GIO_ERR_ADDR_OFFSET                       0xf4u /* established */
#define MC_GIO_ERR_ADDR_ADDR_SHIFT                   0 /* established */
#define MC_GIO_ERR_ADDR_ADDR_MASK                    0xffffffffu
#define MC_GIO_ERR_ADDR_ADDR_INPLACE (MC_GIO_ERR_ADDR_ADDR_MASK << MC_GIO_ERR_ADDR_ADDR_SHIFT)

/*
 * GIO error status. Any write clears it. The bits are sticky.
 */
/* gio_err_stat: rw32, space mc, reset 0x0; MC Chip Specification, section 5.17;
 * IRIX sys/mc.h */
#define MC_GIO_ERR_STAT_OFFSET                       0xfcu /* established */
#define MC_GIO_ERR_STAT_PIO_WR_PAR_SHIFT             15 /* established */
#define MC_GIO_ERR_STAT_PIO_WR_PAR_MASK              0x1u
#define MC_GIO_ERR_STAT_PIO_WR_PAR_INPLACE (MC_GIO_ERR_STAT_PIO_WR_PAR_MASK << MC_GIO_ERR_STAT_PIO_WR_PAR_SHIFT)
#define MC_GIO_ERR_STAT_PIO_RD_PAR_SHIFT             14 /* established */
#define MC_GIO_ERR_STAT_PIO_RD_PAR_MASK              0x1u
#define MC_GIO_ERR_STAT_PIO_RD_PAR_INPLACE (MC_GIO_ERR_STAT_PIO_RD_PAR_MASK << MC_GIO_ERR_STAT_PIO_RD_PAR_SHIFT)
#define MC_GIO_ERR_STAT_BC_SHIFT                     13 /* established */
#define MC_GIO_ERR_STAT_BC_MASK                      0x1u
#define MC_GIO_ERR_STAT_BC_INPLACE (MC_GIO_ERR_STAT_BC_MASK << MC_GIO_ERR_STAT_BC_SHIFT)
#define MC_GIO_ERR_STAT_ADDR_SHIFT                   12 /* established */
#define MC_GIO_ERR_STAT_ADDR_MASK                    0x1u
#define MC_GIO_ERR_STAT_ADDR_INPLACE (MC_GIO_ERR_STAT_ADDR_MASK << MC_GIO_ERR_STAT_ADDR_SHIFT)
#define MC_GIO_ERR_STAT_PROM_SHIFT                   11 /* established */
#define MC_GIO_ERR_STAT_PROM_MASK                    0x1u
#define MC_GIO_ERR_STAT_PROM_INPLACE (MC_GIO_ERR_STAT_PROM_MASK << MC_GIO_ERR_STAT_PROM_SHIFT)
#define MC_GIO_ERR_STAT_TIME_SHIFT                   10 /* established */
#define MC_GIO_ERR_STAT_TIME_MASK                    0x1u
#define MC_GIO_ERR_STAT_TIME_INPLACE (MC_GIO_ERR_STAT_TIME_MASK << MC_GIO_ERR_STAT_TIME_SHIFT)
#define MC_GIO_ERR_STAT_WR_PAR_SHIFT                 9 /* established */
#define MC_GIO_ERR_STAT_WR_PAR_MASK                  0x1u
#define MC_GIO_ERR_STAT_WR_PAR_INPLACE (MC_GIO_ERR_STAT_WR_PAR_MASK << MC_GIO_ERR_STAT_WR_PAR_SHIFT)
#define MC_GIO_ERR_STAT_RD_PAR_SHIFT                 8 /* established */
#define MC_GIO_ERR_STAT_RD_PAR_MASK                  0x1u
#define MC_GIO_ERR_STAT_RD_PAR_INPLACE (MC_GIO_ERR_STAT_RD_PAR_MASK << MC_GIO_ERR_STAT_RD_PAR_SHIFT)
#define MC_GIO_ERR_STAT_BYTE_SHIFT                   0 /* established */
#define MC_GIO_ERR_STAT_BYTE_MASK                    0xffu
#define MC_GIO_ERR_STAT_BYTE_INPLACE (MC_GIO_ERR_STAT_BYTE_MASK << MC_GIO_ERR_STAT_BYTE_SHIFT)

/*
 * System semaphore, in the privileged register page. A read returns the bit and
 * sets it to one; a write stores bit 0.
 */
/* sys_semaphore: rw32, space mc, reset 0x0; MC Chip Specification, sections
 * 2.6.1 and 5.18; IRIX sys/mc.h */
#define MC_SYS_SEMAPHORE_OFFSET                      0x104u /* established */
#define MC_SYS_SEMAPHORE_SEM_SHIFT                   0 /* established */
#define MC_SYS_SEMAPHORE_SEM_MASK                    0x1u
#define MC_SYS_SEMAPHORE_SEM_INPLACE (MC_SYS_SEMAPHORE_SEM_MASK << MC_SYS_SEMAPHORE_SEM_SHIFT)

/*
 * Writing 0 locks every device except the CPU out of main memory, for a locked
 * CPU sequence; 1 releases.
 */
/* lock_memory: rw32, space mc, reset 0x1; MC Chip Specification, section 5.19;
 * IRIX sys/mc.h */
#define MC_LOCK_MEMORY_OFFSET                        0x10cu /* established */
#define MC_LOCK_MEMORY_LOCK_N_SHIFT                  0 /* established */
#define MC_LOCK_MEMORY_LOCK_N_MASK                   0x1u
#define MC_LOCK_MEMORY_LOCK_N_INPLACE (MC_LOCK_MEMORY_LOCK_N_MASK << MC_LOCK_MEMORY_LOCK_N_SHIFT)

/*
 * Writing 0 asserts the EISA lock output. The Indigo has no EISA bus, so the
 * register has no effect there (inferred from the absent bus).
 */
/* eisa_lock: rw32, space mc, reset 0x1; MC Chip Specification, section 5.20;
 * IRIX sys/mc.h */
#define MC_EISA_LOCK_OFFSET                          0x114u /* established */
#define MC_EISA_LOCK_LOCK_SHIFT                      0 /* established */
#define MC_EISA_LOCK_LOCK_MASK                       0x1u
#define MC_EISA_LOCK_LOCK_INPLACE (MC_EISA_LOCK_LOCK_MASK << MC_EISA_LOCK_LOCK_SHIFT)

/*
 * Mask applied to the GIO address of a graphics DMA to translate it, with the
 * substitution register. The kernel and the Indigo PROM store zero in both,
 * which leaves the address unchanged. The bit layout is not stated by any
 * source held.
 */
/* dma_gio_mask: rw32, space mc, reset unknown; IRIX sys/mc.h (name and role);
 * IRIX VDMA initialisation (writes zero) */
#define MC_DMA_GIO_MASK_OFFSET                       0x154u /* inferred */

/*
 * Substitution bits for the GIO address translation; see the mask register.
 */
/* dma_gio_sub: rw32, space mc, reset unknown; IRIX sys/mc.h (name and role);
 * IRIX VDMA initialisation (writes zero) */
#define MC_DMA_GIO_SUB_OFFSET                        0x15cu /* inferred */

/*
 * Sticky cause bits of the graphics DMA engine, the same bits the run register
 * shows below the running bit. Software writes zero to clear them and to drop
 * the DMA-done interrupt. Whether a write of any value clears them is not
 * stated; IRIX only writes zero.
 */
/* dma_cause: rw32, space mc, reset unknown; IRIX VDMA header and kernel VDMA
 * code; IRIX sys/mc.h */
#define MC_DMA_CAUSE_OFFSET                          0x164u /* established */
#define MC_DMA_CAUSE_BPTE_SHIFT                      5 /* established */
#define MC_DMA_CAUSE_BPTE_MASK                       0x1u
#define MC_DMA_CAUSE_BPTE_INPLACE (MC_DMA_CAUSE_BPTE_MASK << MC_DMA_CAUSE_BPTE_SHIFT)
#define MC_DMA_CAUSE_BMEM_SHIFT                      4 /* established */
#define MC_DMA_CAUSE_BMEM_MASK                       0x1u
#define MC_DMA_CAUSE_BMEM_INPLACE (MC_DMA_CAUSE_BMEM_MASK << MC_DMA_CAUSE_BMEM_SHIFT)
#define MC_DMA_CAUSE_COMPLETE_SHIFT                  3 /* established */
#define MC_DMA_CAUSE_COMPLETE_MASK                   0x1u
#define MC_DMA_CAUSE_COMPLETE_INPLACE (MC_DMA_CAUSE_COMPLETE_MASK << MC_DMA_CAUSE_COMPLETE_SHIFT)
#define MC_DMA_CAUSE_CLEAN_SHIFT                     2 /* established */
#define MC_DMA_CAUSE_CLEAN_MASK                      0x1u
#define MC_DMA_CAUSE_CLEAN_INPLACE (MC_DMA_CAUSE_CLEAN_MASK << MC_DMA_CAUSE_CLEAN_SHIFT)
#define MC_DMA_CAUSE_UTLBMISS_SHIFT                  1 /* established */
#define MC_DMA_CAUSE_UTLBMISS_MASK                   0x1u
#define MC_DMA_CAUSE_UTLBMISS_INPLACE (MC_DMA_CAUSE_UTLBMISS_MASK << MC_DMA_CAUSE_UTLBMISS_SHIFT)
#define MC_DMA_CAUSE_PAGEFAULT_SHIFT                 0 /* established */
#define MC_DMA_CAUSE_PAGEFAULT_MASK                  0x1u
#define MC_DMA_CAUSE_PAGEFAULT_INPLACE (MC_DMA_CAUSE_PAGEFAULT_MASK << MC_DMA_CAUSE_PAGEFAULT_SHIFT)

/*
 * Graphics DMA control. The kernel initialises it to a constant that also
 * carries fields no source names (the kernel's comment lists a TLB limit of
 * 512, a slave limit of 4, a 32-word cache line and the page size); only the
 * three named bits are defined here. The Indigo PROM writes zero to turn
 * translation off for its memory-clear DMA.
 */
/* dma_ctl: rw32, space mc, reset unknown; IRIX VDMA header and kernel VDMA code
 */
#define MC_DMA_CTL_OFFSET                            0x16cu /* established */
#define MC_DMA_CTL_DECSLV_SHIFT                      9 /* established */
#define MC_DMA_CTL_DECSLV_MASK                       0x1u
#define MC_DMA_CTL_DECSLV_INPLACE (MC_DMA_CTL_DECSLV_MASK << MC_DMA_CTL_DECSLV_SHIFT)
#define MC_DMA_CTL_XLATE_SHIFT                       8 /* established */
#define MC_DMA_CTL_XLATE_MASK                        0x1u
#define MC_DMA_CTL_XLATE_INPLACE (MC_DMA_CTL_XLATE_MASK << MC_DMA_CTL_XLATE_SHIFT)
#define MC_DMA_CTL_IE_SHIFT                          4 /* established */
#define MC_DMA_CTL_IE_MASK                           0x1u
#define MC_DMA_CTL_IE_INPLACE (MC_DMA_CTL_IE_MASK << MC_DMA_CTL_IE_SHIFT)

/*
 * DMA TLB entry high word, four entries. Holds the virtual address of one
 * segment (the span one page of page-table entries maps), aligned to that span.
 * Software clears unused entries by writing zero.
 */
/* dma_tlb_hi: rw32, space mc, reset unknown; IRIX kernel VDMA code (uTLB
 * handling) */
#define MC_DMA_TLB_HI_OFFSET                         0x184u /* established */
#define MC_DMA_TLB_HI_COUNT                          4
#define MC_DMA_TLB_HI_STRIDE                         16

/*
 * DMA TLB entry low word, four entries. Names the physical page of page-table
 * entries for the segment in the matching high word. Bits 25 to 6 are the
 * physical address divided by 64.
 */
/* dma_tlb_lo: rw32, space mc, reset unknown; IRIX kernel VDMA code (uTLB
 * handling) */
#define MC_DMA_TLB_LO_OFFSET                         0x18cu /* established */
#define MC_DMA_TLB_LO_COUNT                          4
#define MC_DMA_TLB_LO_STRIDE                         16
#define MC_DMA_TLB_LO_PT_ADDR_SHIFT                  6 /* established */
#define MC_DMA_TLB_LO_PT_ADDR_MASK                   0xfffffu
#define MC_DMA_TLB_LO_PT_ADDR_INPLACE (MC_DMA_TLB_LO_PT_ADDR_MASK << MC_DMA_TLB_LO_PT_ADDR_SHIFT)
#define MC_DMA_TLB_LO_VALID_SHIFT                    1 /* established */
#define MC_DMA_TLB_LO_VALID_MASK                     0x1u
#define MC_DMA_TLB_LO_VALID_INPLACE (MC_DMA_TLB_LO_VALID_MASK << MC_DMA_TLB_LO_VALID_SHIFT)

/*
 * RPSS counter: 32 bits, read only, rolls over without an interrupt. It
 * advances by the divider register's increment every divider-plus-one CPU
 * clocks; at reset that is one every 100 nanoseconds at 50 MHz. The page is
 * mappable by user processes. A qtest can check that two reads differ and that
 * a write is ignored.
 */
/* rpss_ctr: r32, space mc, reset 0x0; MC Chip Specification, sections 2.6.2 and
 * 5.21; IRIX sys/mc.h */
#define MC_RPSS_CTR_OFFSET                           0x1004u /* established */

/*
 * DMA memory address, virtual or physical according to the translate bit. It
 * advances as the DMA runs, so after a stop or fault it names the next byte;
 * software reads it to find the faulting address.
 */
/* dma_memadr: rw32, space mc, reset unknown; IRIX sys/mc.h; IRIX kernel VDMA
 * code */
#define MC_DMA_MEMADR_OFFSET                         0x2004u /* established */

/*
 * Writes the memory address register and also sets default values for the other
 * DMA parameters. Which defaults is not stated by any source held, and no held
 * code writes it.
 */
/* dma_memadrd: w32, space mc, reset unknown; IRIX sys/mc.h (name and note:
 * memory address and set defaults) */
#define MC_DMA_MEMADRD_OFFSET                        0x200cu /* inferred */

/*
 * DMA line width in bytes and line count. The kernel splits transfers over
 * 65535 bytes into lines of 32768.
 */
/* dma_size: rw32, space mc, reset unknown; IRIX kernel VDMA code; Indigo PROM
 * memory clear */
#define MC_DMA_SIZE_OFFSET                           0x2014u /* established */
#define MC_DMA_SIZE_HEIGHT_SHIFT                     16 /* established */
#define MC_DMA_SIZE_HEIGHT_MASK                      0xffffu
#define MC_DMA_SIZE_HEIGHT_INPLACE (MC_DMA_SIZE_HEIGHT_MASK << MC_DMA_SIZE_HEIGHT_SHIFT)
#define MC_DMA_SIZE_WIDTH_SHIFT                      0 /* established */
#define MC_DMA_SIZE_WIDTH_MASK                       0xffffu
#define MC_DMA_SIZE_WIDTH_INPLACE (MC_DMA_SIZE_WIDTH_MASK << MC_DMA_SIZE_WIDTH_SHIFT)

/*
 * Signed byte distance from the end of one line to the start of the next, and
 * the vertical zoom factor (how many times each line repeats, at most 1023).
 * The kernel forces the stride to zero when there is one line to avoid a
 * TLB-miss quirk.
 */
/* dma_stride: rw32, space mc, reset unknown; IRIX kernel VDMA code; IRIX
 * vdma_args structure */
#define MC_DMA_STRIDE_OFFSET                         0x201cu /* established */
#define MC_DMA_STRIDE_ZOOM_SHIFT                     16 /* established */
#define MC_DMA_STRIDE_ZOOM_MASK                      0xffffu
#define MC_DMA_STRIDE_ZOOM_INPLACE (MC_DMA_STRIDE_ZOOM_MASK << MC_DMA_STRIDE_ZOOM_SHIFT)
#define MC_DMA_STRIDE_STRIDE_SHIFT                   0 /* established */
#define MC_DMA_STRIDE_STRIDE_MASK                    0xffffu
#define MC_DMA_STRIDE_STRIDE_INPLACE (MC_DMA_STRIDE_STRIDE_MASK << MC_DMA_STRIDE_STRIDE_SHIFT)

/*
 * GIO slave address of the DMA, or the constant to write in fill mode. Writing
 * it does not start the DMA.
 */
/* dma_gio_adr: rw32, space mc, reset unknown; IRIX sys/mc.h; IRIX vdma_args
 * structure */
#define MC_DMA_GIO_ADR_OFFSET                        0x2024u /* established */

/*
 * Writes the GIO address (or fill constant) and starts the DMA. The kernel
 * writes it last, after the other parameters.
 */
/* dma_gio_adrs: w32, space mc, reset unknown; IRIX sys/mc.h; IRIX kernel VDMA
 * code; Indigo PROM memory clear */
#define MC_DMA_GIO_ADRS_OFFSET                       0x202cu /* established */

/*
 * DMA mode. The Indigo PROM's memory clear uses long burst, incrementing
 * address, fill and graphics-to-host.
 */
/* dma_mode: rw32, space mc, reset unknown; IRIX VDMA header */
#define MC_DMA_MODE_OFFSET                           0x2034u /* established */
#define MC_DMA_MODE_LBURST_SHIFT                     6 /* established */
#define MC_DMA_MODE_LBURST_MASK                      0x1u
#define MC_DMA_MODE_LBURST_INPLACE (MC_DMA_MODE_LBURST_MASK << MC_DMA_MODE_LBURST_SHIFT)
#define MC_DMA_MODE_SNOOP_SHIFT                      5 /* established */
#define MC_DMA_MODE_SNOOP_MASK                       0x1u
#define MC_DMA_MODE_SNOOP_INPLACE (MC_DMA_MODE_SNOOP_MASK << MC_DMA_MODE_SNOOP_SHIFT)
#define MC_DMA_MODE_INCA_SHIFT                       4 /* established */
#define MC_DMA_MODE_INCA_MASK                        0x1u
#define MC_DMA_MODE_INCA_INPLACE (MC_DMA_MODE_INCA_MASK << MC_DMA_MODE_INCA_SHIFT)
#define MC_DMA_MODE_FILL_SHIFT                       3 /* established */
#define MC_DMA_MODE_FILL_MASK                        0x1u
#define MC_DMA_MODE_FILL_INPLACE (MC_DMA_MODE_FILL_MASK << MC_DMA_MODE_FILL_SHIFT)
#define MC_DMA_MODE_SYNC_SHIFT                       2 /* established */
#define MC_DMA_MODE_SYNC_MASK                        0x1u
#define MC_DMA_MODE_SYNC_INPLACE (MC_DMA_MODE_SYNC_MASK << MC_DMA_MODE_SYNC_SHIFT)
#define MC_DMA_MODE_GTOH_SHIFT                       1 /* established */
#define MC_DMA_MODE_GTOH_MASK                        0x1u
#define MC_DMA_MODE_GTOH_INPLACE (MC_DMA_MODE_GTOH_MASK << MC_DMA_MODE_GTOH_SHIFT)

/*
 * Working counters of the running DMA: the remaining zoom count and byte count.
 * The Indigo PROM writes 1 in the upper half before starting a fill, commenting
 * that the zoom factor is one; the field layout is not stated by any source
 * held.
 */
/* dma_count: rw32, space mc, reset unknown; IRIX sys/mc.h (name: zoom count and
 * byte count); Indigo PROM memory clear */
#define MC_DMA_COUNT_OFFSET                          0x203cu /* inferred */

/*
 * Start or resume the virtual DMA. The kernel writes 1 after fixing a page
 * fault to resume and 0 to stop a timed-out transfer.
 */
/* dma_stdma: rw32, space mc, reset unknown; IRIX kernel VDMA code */
#define MC_DMA_STDMA_OFFSET                          0x2044u /* established */

/*
 * DMA status: the cause bits plus a running bit. The PROM polls the running bit
 * to wait for its memory clear.
 */
/* dma_run: r32, space mc, reset unknown; IRIX VDMA header and kernel VDMA code;
 * Indigo PROM memory clear */
#define MC_DMA_RUN_OFFSET                            0x204cu /* established */
#define MC_DMA_RUN_RUNNING_SHIFT                     6 /* established */
#define MC_DMA_RUN_RUNNING_MASK                      0x1u
#define MC_DMA_RUN_RUNNING_INPLACE (MC_DMA_RUN_RUNNING_MASK << MC_DMA_RUN_RUNNING_SHIFT)
#define MC_DMA_RUN_BPTE_SHIFT                        5 /* established */
#define MC_DMA_RUN_BPTE_MASK                         0x1u
#define MC_DMA_RUN_BPTE_INPLACE (MC_DMA_RUN_BPTE_MASK << MC_DMA_RUN_BPTE_SHIFT)
#define MC_DMA_RUN_BMEM_SHIFT                        4 /* established */
#define MC_DMA_RUN_BMEM_MASK                         0x1u
#define MC_DMA_RUN_BMEM_INPLACE (MC_DMA_RUN_BMEM_MASK << MC_DMA_RUN_BMEM_SHIFT)
#define MC_DMA_RUN_COMPLETE_SHIFT                    3 /* established */
#define MC_DMA_RUN_COMPLETE_MASK                     0x1u
#define MC_DMA_RUN_COMPLETE_INPLACE (MC_DMA_RUN_COMPLETE_MASK << MC_DMA_RUN_COMPLETE_SHIFT)
#define MC_DMA_RUN_CLEAN_SHIFT                       2 /* established */
#define MC_DMA_RUN_CLEAN_MASK                        0x1u
#define MC_DMA_RUN_CLEAN_INPLACE (MC_DMA_RUN_CLEAN_MASK << MC_DMA_RUN_CLEAN_SHIFT)
#define MC_DMA_RUN_UTLBMISS_SHIFT                    1 /* established */
#define MC_DMA_RUN_UTLBMISS_MASK                     0x1u
#define MC_DMA_RUN_UTLBMISS_INPLACE (MC_DMA_RUN_UTLBMISS_MASK << MC_DMA_RUN_UTLBMISS_SHIFT)
#define MC_DMA_RUN_PAGEFAULT_SHIFT                   0 /* established */
#define MC_DMA_RUN_PAGEFAULT_MASK                    0x1u
#define MC_DMA_RUN_PAGEFAULT_INPLACE (MC_DMA_RUN_PAGEFAULT_MASK << MC_DMA_RUN_PAGEFAULT_SHIFT)

/*
 * Writes the memory address, sets the default DMA parameters and starts the
 * DMA. No held code writes it.
 */
/* dma_memadrds: w32, space mc, reset unknown; IRIX sys/mc.h (name and note:
 * memory address, set defaults and start DMA) */
#define MC_DMA_MEMADRDS_OFFSET                       0x2074u /* inferred */

/*
 * Sixteen user semaphores, each in its own 4 KiB page so a page can be mapped
 * into a user process. A read returns the bit and sets it to one; a write
 * stores bit 0.
 */
/* semaphore: rw32, space mc, reset 0x0; MC Chip Specification, sections 2.6.1
 * and 5.18; IRIX sys/mc.h */
#define MC_SEMAPHORE_OFFSET                          0x10004u /* established */
#define MC_SEMAPHORE_COUNT                           16
#define MC_SEMAPHORE_STRIDE                          4096
#define MC_SEMAPHORE_SEM_SHIFT                       0 /* established */
#define MC_SEMAPHORE_SEM_MASK                        0x1u
#define MC_SEMAPHORE_SEM_INPLACE (MC_SEMAPHORE_SEM_MASK << MC_SEMAPHORE_SEM_SHIFT)

#endif /* MC_GEN_H */
