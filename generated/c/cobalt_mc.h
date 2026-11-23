/* generated from devices/cobalt_mc/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 73f90f85d2cdc65dda9e1c8485d018d0bbc17dbb41d1f46b9ab0ab950e2b71a5 */
/* Cobalt memory controller of the SGI Visual Workstation 320 and 540: ECC control, error reporting and the bank registers */
#ifndef COBALT_MC_GEN_H
#define COBALT_MC_GEN_H

#include <stdint.h>


/*
 * Memory controller control. At timer set-up the HAL also stores 0 here and 0 in the error status. The PROM self-test sets bit 0 with a full-word store of 1 and clears it with a store of 0; the main module clears bit 0 by read-modify-write before it sizes memory; none depends on a value read before the first write. The NT HAL clears it at start-up and sets bit 0, together with the CPU block's control bit 0, to turn ECC checking on (halborg.dll 1.3, HalpEccControl). Other bits are not touched by any software read.
 */
/* ecc_control: rw32, space mc, reset unknown */
#define COBALT_MC_ECC_CONTROL_OFFSET                 0x0u /* established */
#define COBALT_MC_ECC_CONTROL_ECC_ENABLE_SHIFT       0 /* established */
#define COBALT_MC_ECC_CONTROL_ECC_ENABLE_MASK        0x1u
#define COBALT_MC_ECC_CONTROL_ECC_ENABLE_INPLACE     (COBALT_MC_ECC_CONTROL_ECC_ENABLE_MASK << COBALT_MC_ECC_CONTROL_ECC_ENABLE_SHIFT)

/*
 * Read by the PROM self-test between its probe writes; half of it is the delay threshold for the counter register (delay_counter). Compared as a signed value. The meaning is from that use only.
 */
/* delay_period: r32, space mc, reset unknown */
#define COBALT_MC_DELAY_PERIOD_OFFSET                0x8u /* inferred */

/*
 * Counter the PROM self-test polls (signed compares) until it is at or below, then at or above, half the value of delay_period, as a delay between probe writes, in every probe step. Whether it counts up or down is not shown.
 */
/* delay_counter: r32, space mc, reset unknown */
#define COBALT_MC_DELAY_COUNTER_OFFSET               0x10u /* inferred */

/*
 * Memory error status. The NT HAL's error handler reads it, treats the error as non-fatal when bit 16 is set or when bit 17 is set and the syndrome is zero, and clears the register by writing zero. The meaning of the bits is inferred from the messages the handler selects with them (invalid address, hard ECC, soft ECC, multiple errors).
 */
/* error_status: rw32, space mc, reset unknown */
#define COBALT_MC_ERROR_STATUS_OFFSET                0x18u /* established */
#define COBALT_MC_ERROR_STATUS_SYNDROME_ONLY_SHIFT   17 /* inferred */
#define COBALT_MC_ERROR_STATUS_SYNDROME_ONLY_MASK    0x1u
#define COBALT_MC_ERROR_STATUS_SYNDROME_ONLY_INPLACE (COBALT_MC_ERROR_STATUS_SYNDROME_ONLY_MASK << COBALT_MC_ERROR_STATUS_SYNDROME_ONLY_SHIFT)
#define COBALT_MC_ERROR_STATUS_NONFATAL_SHIFT        16 /* inferred */
#define COBALT_MC_ERROR_STATUS_NONFATAL_MASK         0x1u
#define COBALT_MC_ERROR_STATUS_NONFATAL_INPLACE      (COBALT_MC_ERROR_STATUS_NONFATAL_MASK << COBALT_MC_ERROR_STATUS_NONFATAL_SHIFT)

/*
 * Memory error address, printed by the HAL as the address of the error.
 */
/* error_address: r32, space mc, reset unknown */
#define COBALT_MC_ERROR_ADDRESS_OFFSET               0x28u /* established */

/*
 * Memory error ECC syndrome. A nonzero syndrome with a correctable error sends the HAL to HalpCorrectSoftEccError, which computes a quadword offset from the syndrome byte that is nonzero but performs no write-back; a model must not depend on a HAL write.
 */
/* error_syndrome: r32, space mc, reset unknown */
#define COBALT_MC_ERROR_SYNDROME_OFFSET              0x30u /* established */

/*
 * Read once by the PROM self-test's DIMM speed check (check 0x0d, prom-console-path.md), on every Cobalt revision. The check passes only when bit 16 reads 1; otherwise it reports a soft failure and the main module waits for a key before booting. What the bit reports is inferred from the check's name only. On revisions 0xa0 and 0xa8 this address is bank register 0 (see bank), whose codes never have bit 16, so the check always fails there. Off the Lite revisions the firmware never writes it; on 0xa0 and 0xa8 the self-test writes bank register 0 here (addresses in the memory controller README).
 */
/* dimm_speed_check: r32, space mc, reset unknown */
#define COBALT_MC_DIMM_SPEED_CHECK_OFFSET            0x48u /* inferred */
#define COBALT_MC_DIMM_SPEED_CHECK_SPEED_OK_SHIFT    16 /* inferred */
#define COBALT_MC_DIMM_SPEED_CHECK_SPEED_OK_MASK     0x1u
#define COBALT_MC_DIMM_SPEED_CHECK_SPEED_OK_INPLACE  (COBALT_MC_DIMM_SPEED_CHECK_SPEED_OK_MASK << COBALT_MC_DIMM_SPEED_CHECK_SPEED_OK_SHIFT)

/*
 * Bank register of each of sixteen 128 MiB address slots (slot i decodes from i * 128 MiB), on every revision except 0xa0 and 0xa8, whose registers start eight bytes lower at 0x48. The sixteenth is the limit of the PROM's decode loop. The PROM self-test probes each slot with write and read-back patterns and stores a code: 3 (a full 128 MiB module: each 16 MiB test block reads back its own pattern), 2 (the blocks alias, a 32 MiB-class module, or a partial result) or 0 (nothing there; slot 0 is never stored as 0). It reads all sixteen back into CMOS, and the main module counts only slots at 3 as 128 MiB banks. The registers must read back what was written. Whether any bit has a hardware meaning beyond those three codes is unknown: an earlier reading of bit 0 as populated, bit 1 as 128 MiB and bit 2 as absent or bad does not fit the stored code 2, so only the codes are stated. The write side is inferred; the read side is established as a value the main module compares.
 */
/* bank: rw32, space mc, reset unknown */
#define COBALT_MC_BANK_OFFSET                        0x50u /* inferred */
#define COBALT_MC_BANK_COUNT                         16
#define COBALT_MC_BANK_STRIDE                        8

#define COBALT_MC_BANK_ABSENT                        0x0u /* inferred */
#define COBALT_MC_BANK_FIRST_LITE                    0x48u /* inferred */
#define COBALT_MC_BANK_FULL                          0x3u /* inferred */
#define COBALT_MC_BANK_PARTIAL                       0x2u /* inferred */
#define COBALT_MC_BANK_SLOTS                         0x10u /* inferred */
#define COBALT_MC_BANK_SPAN                          0x8000000u /* inferred */
#define COBALT_MC_BASE                               0xc6000000u /* established */

#endif /* COBALT_MC_GEN_H */
