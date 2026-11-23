/* generated from devices/bedrock_xb/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 4 */
/* input sha256 ed209e81bcd3b4c09ee365d6ba1890e8b0e7509d8b2d283d8968ad81ab13d230 */
/* Bedrock internal crossbar (XB) registers outside the census */
#ifndef BEDROCK_GEN_H
#define BEDROCK_GEN_H

#include <stdint.h>


/* enum first_error_source */
#define BEDROCK_FIRST_ERROR_SOURCE_LIQ               2 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_LOQ               3 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_IIQ               4 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_IOQ               5 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_NIQ               6 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_NOQ               7 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_MIQ               8 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_MMQ               9 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_MP1               10 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_MP0               11 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_PIQ1              12 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_POQ1              13 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_PIQ0              14 /* inferred */
#define BEDROCK_FIRST_ERROR_SOURCE_POQ0              15 /* inferred */

/*
 * Crossbar-wide parameters. The header gives the bypass enable and three wrap
 * periods (age, deadlock, tail). It does not say what the periods count or how
 * the crossbar uses them.
 */
/* xb_parms: rw64, reset 0x8000080000021; Linux 2.5.40 public SN1 crossbar
 * register headers: register names, offsets and field layouts, first-error
 * source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_PARMS                             0x700000 /* inferred */
#define BEDROCK_XB_PARMS_TAIL_WRAP_SHIFT             32 /* inferred */
#define BEDROCK_XB_PARMS_TAIL_WRAP_MASK              0xfffffull
#define BEDROCK_XB_PARMS_TAIL_WRAP_INPLACE (BEDROCK_XB_PARMS_TAIL_WRAP_MASK << BEDROCK_XB_PARMS_TAIL_WRAP_SHIFT)
#define BEDROCK_XB_PARMS_DEADLOCK_WRAP_SHIFT         12 /* inferred */
#define BEDROCK_XB_PARMS_DEADLOCK_WRAP_MASK          0xfffffull
#define BEDROCK_XB_PARMS_DEADLOCK_WRAP_INPLACE (BEDROCK_XB_PARMS_DEADLOCK_WRAP_MASK << BEDROCK_XB_PARMS_DEADLOCK_WRAP_SHIFT)
#define BEDROCK_XB_PARMS_AGE_WRAP_SHIFT              4 /* inferred */
#define BEDROCK_XB_PARMS_AGE_WRAP_MASK               0xffull
#define BEDROCK_XB_PARMS_AGE_WRAP_INPLACE (BEDROCK_XB_PARMS_AGE_WRAP_MASK << BEDROCK_XB_PARMS_AGE_WRAP_SHIFT)
#define BEDROCK_XB_PARMS_BYP_EN_SHIFT                0 /* inferred */
#define BEDROCK_XB_PARMS_BYP_EN_MASK                 0x1ull
#define BEDROCK_XB_PARMS_BYP_EN_INPLACE (BEDROCK_XB_PARMS_BYP_EN_MASK << BEDROCK_XB_PARMS_BYP_EN_SHIFT)

/*
 * Wavefront grant period per unit: the number of cycles between grant
 * opportunities. The all-ones value gives no grants, and one less than all ones
 * the slowest rate. Used to apply backpressure to a unit's output queues.
 * Bypass grants are not affected.
 */
/* xb_slow_gnt: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_SLOW_GNT                          0x700008 /* inferred */
#define BEDROCK_XB_SLOW_GNT_PI0_SHIFT                28 /* inferred */
#define BEDROCK_XB_SLOW_GNT_PI0_MASK                 0xfull
#define BEDROCK_XB_SLOW_GNT_PI0_INPLACE (BEDROCK_XB_SLOW_GNT_PI0_MASK << BEDROCK_XB_SLOW_GNT_PI0_SHIFT)
#define BEDROCK_XB_SLOW_GNT_PI1_SHIFT                24 /* inferred */
#define BEDROCK_XB_SLOW_GNT_PI1_MASK                 0xfull
#define BEDROCK_XB_SLOW_GNT_PI1_INPLACE (BEDROCK_XB_SLOW_GNT_PI1_MASK << BEDROCK_XB_SLOW_GNT_PI1_SHIFT)
#define BEDROCK_XB_SLOW_GNT_MP0_SHIFT                20 /* inferred */
#define BEDROCK_XB_SLOW_GNT_MP0_MASK                 0xfull
#define BEDROCK_XB_SLOW_GNT_MP0_INPLACE (BEDROCK_XB_SLOW_GNT_MP0_MASK << BEDROCK_XB_SLOW_GNT_MP0_SHIFT)
#define BEDROCK_XB_SLOW_GNT_MP1_SHIFT                16 /* inferred */
#define BEDROCK_XB_SLOW_GNT_MP1_MASK                 0xfull
#define BEDROCK_XB_SLOW_GNT_MP1_INPLACE (BEDROCK_XB_SLOW_GNT_MP1_MASK << BEDROCK_XB_SLOW_GNT_MP1_SHIFT)
#define BEDROCK_XB_SLOW_GNT_MMQ_SHIFT                12 /* inferred */
#define BEDROCK_XB_SLOW_GNT_MMQ_MASK                 0xfull
#define BEDROCK_XB_SLOW_GNT_MMQ_INPLACE (BEDROCK_XB_SLOW_GNT_MMQ_MASK << BEDROCK_XB_SLOW_GNT_MMQ_SHIFT)
#define BEDROCK_XB_SLOW_GNT_NI_SHIFT                 8 /* inferred */
#define BEDROCK_XB_SLOW_GNT_NI_MASK                  0xfull
#define BEDROCK_XB_SLOW_GNT_NI_INPLACE (BEDROCK_XB_SLOW_GNT_NI_MASK << BEDROCK_XB_SLOW_GNT_NI_SHIFT)
#define BEDROCK_XB_SLOW_GNT_II_SHIFT                 4 /* inferred */
#define BEDROCK_XB_SLOW_GNT_II_MASK                  0xfull
#define BEDROCK_XB_SLOW_GNT_II_INPLACE (BEDROCK_XB_SLOW_GNT_II_MASK << BEDROCK_XB_SLOW_GNT_II_SHIFT)
#define BEDROCK_XB_SLOW_GNT_LB_SHIFT                 0 /* inferred */
#define BEDROCK_XB_SLOW_GNT_LB_MASK                  0xfull
#define BEDROCK_XB_SLOW_GNT_LB_INPLACE (BEDROCK_XB_SLOW_GNT_LB_MASK << BEDROCK_XB_SLOW_GNT_LB_SHIFT)

/*
 * Snoop selector for internal crossbar traffic, sent to the PI1 port. The
 * header says only one selector should be set, and any set selector takes PI1
 * away from every use except this debug connection. Separate from the debug
 * data select register.
 */
/* xb_spew_control: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_SPEW_CONTROL                      0x700010 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_POQ0_SHIFT     10 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_POQ0_MASK      0x1ull
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_POQ0_INPLACE (BEDROCK_XB_SPEW_CONTROL_SNOOP_POQ0_MASK << BEDROCK_XB_SPEW_CONTROL_SNOOP_POQ0_SHIFT)
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_MP0_SHIFT      9 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_MP0_MASK       0x1ull
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_MP0_INPLACE (BEDROCK_XB_SPEW_CONTROL_SNOOP_MP0_MASK << BEDROCK_XB_SPEW_CONTROL_SNOOP_MP0_SHIFT)
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_MMQ_SHIFT      8 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_MMQ_MASK       0x1ull
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_MMQ_INPLACE (BEDROCK_XB_SPEW_CONTROL_SNOOP_MMQ_MASK << BEDROCK_XB_SPEW_CONTROL_SNOOP_MMQ_SHIFT)
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_NOQ_SHIFT      7 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_NOQ_MASK       0x1ull
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_NOQ_INPLACE (BEDROCK_XB_SPEW_CONTROL_SNOOP_NOQ_MASK << BEDROCK_XB_SPEW_CONTROL_SNOOP_NOQ_SHIFT)
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_IOQ_SHIFT      6 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_IOQ_MASK       0x1ull
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_IOQ_INPLACE (BEDROCK_XB_SPEW_CONTROL_SNOOP_IOQ_MASK << BEDROCK_XB_SPEW_CONTROL_SNOOP_IOQ_SHIFT)
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_LOQ_SHIFT      5 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_LOQ_MASK       0x1ull
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_LOQ_INPLACE (BEDROCK_XB_SPEW_CONTROL_SNOOP_LOQ_MASK << BEDROCK_XB_SPEW_CONTROL_SNOOP_LOQ_SHIFT)
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_PIQ0_SHIFT     4 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_PIQ0_MASK      0x1ull
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_PIQ0_INPLACE (BEDROCK_XB_SPEW_CONTROL_SNOOP_PIQ0_MASK << BEDROCK_XB_SPEW_CONTROL_SNOOP_PIQ0_SHIFT)
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_MIQ_SHIFT      3 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_MIQ_MASK       0x1ull
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_MIQ_INPLACE (BEDROCK_XB_SPEW_CONTROL_SNOOP_MIQ_MASK << BEDROCK_XB_SPEW_CONTROL_SNOOP_MIQ_SHIFT)
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_NIQ_SHIFT      2 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_NIQ_MASK       0x1ull
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_NIQ_INPLACE (BEDROCK_XB_SPEW_CONTROL_SNOOP_NIQ_MASK << BEDROCK_XB_SPEW_CONTROL_SNOOP_NIQ_SHIFT)
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_IIQ_SHIFT      1 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_IIQ_MASK       0x1ull
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_IIQ_INPLACE (BEDROCK_XB_SPEW_CONTROL_SNOOP_IIQ_MASK << BEDROCK_XB_SPEW_CONTROL_SNOOP_IIQ_SHIFT)
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_LIQ_SHIFT      0 /* inferred */
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_LIQ_MASK       0x1ull
#define BEDROCK_XB_SPEW_CONTROL_SNOOP_LIQ_INPLACE (BEDROCK_XB_SPEW_CONTROL_SNOOP_LIQ_MASK << BEDROCK_XB_SPEW_CONTROL_SNOOP_LIQ_SHIFT)

/*
 * Clocks the I/O output queue waits before crossbar arbitration starts, so the
 * slower I/O data rate can catch up in the queue buffer.
 */
/* xb_ioq_arb_trigger: rw64, reset 0x5; Linux 2.5.40 public SN1 crossbar
 * register headers: register names, offsets and field layouts, first-error
 * source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_IOQ_ARB_TRIGGER                   0x700018 /* inferred */
#define BEDROCK_XB_IOQ_ARB_TRIGGER_CLOCKS_SHIFT      0 /* inferred */
#define BEDROCK_XB_IOQ_ARB_TRIGGER_CLOCKS_MASK       0xfull
#define BEDROCK_XB_IOQ_ARB_TRIGGER_CLOCKS_INPLACE (BEDROCK_XB_IOQ_ARB_TRIGGER_CLOCKS_MASK << BEDROCK_XB_IOQ_ARB_TRIGGER_CLOCKS_SHIFT)

/*
 * Error record for the PI0 output queue. The header says software may write it
 * to test error handling, and the write raises an interrupt.
 */
/* xb_poq0_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_POQ0_ERROR                        0x700020 /* inferred */
#define BEDROCK_XB_POQ0_ERROR_TAIL_TIMEOUT_SHIFT     12 /* inferred */
#define BEDROCK_XB_POQ0_ERROR_TAIL_TIMEOUT_MASK      0x3ull
#define BEDROCK_XB_POQ0_ERROR_TAIL_TIMEOUT_INPLACE (BEDROCK_XB_POQ0_ERROR_TAIL_TIMEOUT_MASK << BEDROCK_XB_POQ0_ERROR_TAIL_TIMEOUT_SHIFT)
#define BEDROCK_XB_POQ0_ERROR_UNDERFLOW_SHIFT        8 /* inferred */
#define BEDROCK_XB_POQ0_ERROR_UNDERFLOW_MASK         0x3ull
#define BEDROCK_XB_POQ0_ERROR_UNDERFLOW_INPLACE (BEDROCK_XB_POQ0_ERROR_UNDERFLOW_MASK << BEDROCK_XB_POQ0_ERROR_UNDERFLOW_SHIFT)
#define BEDROCK_XB_POQ0_ERROR_OVERFLOW_SHIFT         4 /* inferred */
#define BEDROCK_XB_POQ0_ERROR_OVERFLOW_MASK          0x3ull
#define BEDROCK_XB_POQ0_ERROR_OVERFLOW_INPLACE (BEDROCK_XB_POQ0_ERROR_OVERFLOW_MASK << BEDROCK_XB_POQ0_ERROR_OVERFLOW_SHIFT)
#define BEDROCK_XB_POQ0_ERROR_INVALID_XSEL_SHIFT     0 /* inferred */
#define BEDROCK_XB_POQ0_ERROR_INVALID_XSEL_MASK      0x3ull
#define BEDROCK_XB_POQ0_ERROR_INVALID_XSEL_INPLACE (BEDROCK_XB_POQ0_ERROR_INVALID_XSEL_MASK << BEDROCK_XB_POQ0_ERROR_INVALID_XSEL_SHIFT)

/*
 * Error record for the PI0 input queue. The header says the processor-interface
 * input cannot underflow, so no underflow field is defined.
 */
/* xb_piq0_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_PIQ0_ERROR                        0x700028 /* inferred */
#define BEDROCK_XB_PIQ0_ERROR_DEADLOCK_TIMEOUT_SHIFT 4 /* inferred */
#define BEDROCK_XB_PIQ0_ERROR_DEADLOCK_TIMEOUT_MASK  0x3ull
#define BEDROCK_XB_PIQ0_ERROR_DEADLOCK_TIMEOUT_INPLACE (BEDROCK_XB_PIQ0_ERROR_DEADLOCK_TIMEOUT_MASK << BEDROCK_XB_PIQ0_ERROR_DEADLOCK_TIMEOUT_SHIFT)
#define BEDROCK_XB_PIQ0_ERROR_OVERFLOW_SHIFT         0 /* inferred */
#define BEDROCK_XB_PIQ0_ERROR_OVERFLOW_MASK          0x3ull
#define BEDROCK_XB_PIQ0_ERROR_OVERFLOW_INPLACE (BEDROCK_XB_PIQ0_ERROR_OVERFLOW_MASK << BEDROCK_XB_PIQ0_ERROR_OVERFLOW_SHIFT)

/*
 * Error record for the PI1 output queue. The header gives no field layout for
 * it. The header gives a layout only for the first-instance register of this
 * pair; this one is assumed to share it (inferred from the matching names and
 * the matching clear registers; no header text says so).
 */
/* xb_poq1_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_POQ1_ERROR                        0x700030 /* inferred */
#define BEDROCK_XB_POQ1_ERROR_TAIL_TIMEOUT_SHIFT     12 /* inferred */
#define BEDROCK_XB_POQ1_ERROR_TAIL_TIMEOUT_MASK      0x3ull
#define BEDROCK_XB_POQ1_ERROR_TAIL_TIMEOUT_INPLACE (BEDROCK_XB_POQ1_ERROR_TAIL_TIMEOUT_MASK << BEDROCK_XB_POQ1_ERROR_TAIL_TIMEOUT_SHIFT)
#define BEDROCK_XB_POQ1_ERROR_UNDERFLOW_SHIFT        8 /* inferred */
#define BEDROCK_XB_POQ1_ERROR_UNDERFLOW_MASK         0x3ull
#define BEDROCK_XB_POQ1_ERROR_UNDERFLOW_INPLACE (BEDROCK_XB_POQ1_ERROR_UNDERFLOW_MASK << BEDROCK_XB_POQ1_ERROR_UNDERFLOW_SHIFT)
#define BEDROCK_XB_POQ1_ERROR_OVERFLOW_SHIFT         4 /* inferred */
#define BEDROCK_XB_POQ1_ERROR_OVERFLOW_MASK          0x3ull
#define BEDROCK_XB_POQ1_ERROR_OVERFLOW_INPLACE (BEDROCK_XB_POQ1_ERROR_OVERFLOW_MASK << BEDROCK_XB_POQ1_ERROR_OVERFLOW_SHIFT)
#define BEDROCK_XB_POQ1_ERROR_INVALID_XSEL_SHIFT     0 /* inferred */
#define BEDROCK_XB_POQ1_ERROR_INVALID_XSEL_MASK      0x3ull
#define BEDROCK_XB_POQ1_ERROR_INVALID_XSEL_INPLACE (BEDROCK_XB_POQ1_ERROR_INVALID_XSEL_MASK << BEDROCK_XB_POQ1_ERROR_INVALID_XSEL_SHIFT)

/*
 * Error record for the PI1 input queue. The header gives no field layout for
 * it. The header gives a layout only for the first-instance register of this
 * pair; this one is assumed to share it (inferred from the matching names and
 * the matching clear registers; no header text says so).
 */
/* xb_piq1_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_PIQ1_ERROR                        0x700038 /* inferred */
#define BEDROCK_XB_PIQ1_ERROR_DEADLOCK_TIMEOUT_SHIFT 4 /* inferred */
#define BEDROCK_XB_PIQ1_ERROR_DEADLOCK_TIMEOUT_MASK  0x3ull
#define BEDROCK_XB_PIQ1_ERROR_DEADLOCK_TIMEOUT_INPLACE (BEDROCK_XB_PIQ1_ERROR_DEADLOCK_TIMEOUT_MASK << BEDROCK_XB_PIQ1_ERROR_DEADLOCK_TIMEOUT_SHIFT)
#define BEDROCK_XB_PIQ1_ERROR_OVERFLOW_SHIFT         0 /* inferred */
#define BEDROCK_XB_PIQ1_ERROR_OVERFLOW_MASK          0x3ull
#define BEDROCK_XB_PIQ1_ERROR_OVERFLOW_INPLACE (BEDROCK_XB_PIQ1_ERROR_OVERFLOW_MASK << BEDROCK_XB_PIQ1_ERROR_OVERFLOW_SHIFT)

/*
 * Error record for the memory-to-PI0 output queue. The header notes the
 * crossbar select is decoded on the memory side of this queue, so no
 * invalid-select field is defined.
 */
/* xb_mp0_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_MP0_ERROR                         0x700040 /* inferred */
#define BEDROCK_XB_MP0_ERROR_TAIL_TIMEOUT_SHIFT      12 /* inferred */
#define BEDROCK_XB_MP0_ERROR_TAIL_TIMEOUT_MASK       0x3ull
#define BEDROCK_XB_MP0_ERROR_TAIL_TIMEOUT_INPLACE (BEDROCK_XB_MP0_ERROR_TAIL_TIMEOUT_MASK << BEDROCK_XB_MP0_ERROR_TAIL_TIMEOUT_SHIFT)
#define BEDROCK_XB_MP0_ERROR_UNDERFLOW_SHIFT         8 /* inferred */
#define BEDROCK_XB_MP0_ERROR_UNDERFLOW_MASK          0x3ull
#define BEDROCK_XB_MP0_ERROR_UNDERFLOW_INPLACE (BEDROCK_XB_MP0_ERROR_UNDERFLOW_MASK << BEDROCK_XB_MP0_ERROR_UNDERFLOW_SHIFT)
#define BEDROCK_XB_MP0_ERROR_OVERFLOW_SHIFT          4 /* inferred */
#define BEDROCK_XB_MP0_ERROR_OVERFLOW_MASK           0x3ull
#define BEDROCK_XB_MP0_ERROR_OVERFLOW_INPLACE (BEDROCK_XB_MP0_ERROR_OVERFLOW_MASK << BEDROCK_XB_MP0_ERROR_OVERFLOW_SHIFT)

/*
 * Error record for the memory-to-PI1 output queue. The header gives no field
 * layout for it. The header gives a layout only for the first-instance register
 * of this pair; this one is assumed to share it (inferred from the matching
 * names and the matching clear registers; no header text says so).
 */
/* xb_mp1_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_MP1_ERROR                         0x700048 /* inferred */
#define BEDROCK_XB_MP1_ERROR_TAIL_TIMEOUT_SHIFT      12 /* inferred */
#define BEDROCK_XB_MP1_ERROR_TAIL_TIMEOUT_MASK       0x3ull
#define BEDROCK_XB_MP1_ERROR_TAIL_TIMEOUT_INPLACE (BEDROCK_XB_MP1_ERROR_TAIL_TIMEOUT_MASK << BEDROCK_XB_MP1_ERROR_TAIL_TIMEOUT_SHIFT)
#define BEDROCK_XB_MP1_ERROR_UNDERFLOW_SHIFT         8 /* inferred */
#define BEDROCK_XB_MP1_ERROR_UNDERFLOW_MASK          0x3ull
#define BEDROCK_XB_MP1_ERROR_UNDERFLOW_INPLACE (BEDROCK_XB_MP1_ERROR_UNDERFLOW_MASK << BEDROCK_XB_MP1_ERROR_UNDERFLOW_SHIFT)
#define BEDROCK_XB_MP1_ERROR_OVERFLOW_SHIFT          4 /* inferred */
#define BEDROCK_XB_MP1_ERROR_OVERFLOW_MASK           0x3ull
#define BEDROCK_XB_MP1_ERROR_OVERFLOW_INPLACE (BEDROCK_XB_MP1_ERROR_OVERFLOW_MASK << BEDROCK_XB_MP1_ERROR_OVERFLOW_SHIFT)

/*
 * Error record for the memory output queue that carries miscellaneous traffic
 * to LB, NI and II. The header gives no field layout for it.
 */
/* xb_mmq_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_MMQ_ERROR                         0x700050 /* inferred */

/*
 * Error record for the memory input queue. The header says further errors of
 * this queue are logged in the memory unit's input error registers.
 */
/* xb_miq_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_MIQ_ERROR                         0x700058 /* inferred */
#define BEDROCK_XB_MIQ_ERROR_DEADLOCK_TIMEOUT_SHIFT  4 /* inferred */
#define BEDROCK_XB_MIQ_ERROR_DEADLOCK_TIMEOUT_MASK   0xfull
#define BEDROCK_XB_MIQ_ERROR_DEADLOCK_TIMEOUT_INPLACE (BEDROCK_XB_MIQ_ERROR_DEADLOCK_TIMEOUT_MASK << BEDROCK_XB_MIQ_ERROR_DEADLOCK_TIMEOUT_SHIFT)

/*
 * Error record for the NI output queue. The header defines three separate 4-bit
 * counters for it.
 */
/* xb_noq_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_NOQ_ERROR                         0x700060 /* inferred */
#define BEDROCK_XB_NOQ_ERROR_TAIL_TIMEOUT_SHIFT      12 /* inferred */
#define BEDROCK_XB_NOQ_ERROR_TAIL_TIMEOUT_MASK       0xfull
#define BEDROCK_XB_NOQ_ERROR_TAIL_TIMEOUT_INPLACE (BEDROCK_XB_NOQ_ERROR_TAIL_TIMEOUT_MASK << BEDROCK_XB_NOQ_ERROR_TAIL_TIMEOUT_SHIFT)
#define BEDROCK_XB_NOQ_ERROR_UNDERFLOW_SHIFT         8 /* inferred */
#define BEDROCK_XB_NOQ_ERROR_UNDERFLOW_MASK          0xfull
#define BEDROCK_XB_NOQ_ERROR_UNDERFLOW_INPLACE (BEDROCK_XB_NOQ_ERROR_UNDERFLOW_MASK << BEDROCK_XB_NOQ_ERROR_UNDERFLOW_SHIFT)
#define BEDROCK_XB_NOQ_ERROR_OVERFLOW_SHIFT          4 /* inferred */
#define BEDROCK_XB_NOQ_ERROR_OVERFLOW_MASK           0xfull
#define BEDROCK_XB_NOQ_ERROR_OVERFLOW_INPLACE (BEDROCK_XB_NOQ_ERROR_OVERFLOW_MASK << BEDROCK_XB_NOQ_ERROR_OVERFLOW_SHIFT)

/*
 * Error record for the NI input queue. The header gives no field layout for it.
 */
/* xb_niq_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_NIQ_ERROR                         0x700068 /* inferred */

/*
 * Error record for the I/O output queue. The header gives no field layout for
 * it.
 */
/* xb_ioq_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_IOQ_ERROR                         0x700070 /* inferred */

/*
 * Error record for the I/O input queue. The header gives no field layout for
 * it.
 */
/* xb_iiq_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_IIQ_ERROR                         0x700078 /* inferred */

/*
 * Error record for the LB output queue.
 */
/* xb_loq_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_LOQ_ERROR                         0x700080 /* inferred */
#define BEDROCK_XB_LOQ_ERROR_TAIL_TIMEOUT_SHIFT      12 /* inferred */
#define BEDROCK_XB_LOQ_ERROR_TAIL_TIMEOUT_MASK       0x3ull
#define BEDROCK_XB_LOQ_ERROR_TAIL_TIMEOUT_INPLACE (BEDROCK_XB_LOQ_ERROR_TAIL_TIMEOUT_MASK << BEDROCK_XB_LOQ_ERROR_TAIL_TIMEOUT_SHIFT)
#define BEDROCK_XB_LOQ_ERROR_UNDERFLOW_SHIFT         8 /* inferred */
#define BEDROCK_XB_LOQ_ERROR_UNDERFLOW_MASK          0x3ull
#define BEDROCK_XB_LOQ_ERROR_UNDERFLOW_INPLACE (BEDROCK_XB_LOQ_ERROR_UNDERFLOW_MASK << BEDROCK_XB_LOQ_ERROR_UNDERFLOW_SHIFT)
#define BEDROCK_XB_LOQ_ERROR_INVALID_XSEL_SHIFT      0 /* inferred */
#define BEDROCK_XB_LOQ_ERROR_INVALID_XSEL_MASK       0x3ull
#define BEDROCK_XB_LOQ_ERROR_INVALID_XSEL_INPLACE (BEDROCK_XB_LOQ_ERROR_INVALID_XSEL_MASK << BEDROCK_XB_LOQ_ERROR_INVALID_XSEL_SHIFT)

/*
 * Error record for the LB input queue. The header says it records only
 * request-channel errors: the reply channel has no flow control and cannot
 * overflow or deadlock.
 */
/* xb_liq_error: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_LIQ_ERROR                         0x700088 /* inferred */
#define BEDROCK_XB_LIQ_ERROR_DEADLOCK_TIMEOUT_SHIFT  4 /* inferred */
#define BEDROCK_XB_LIQ_ERROR_DEADLOCK_TIMEOUT_MASK   0x1ull
#define BEDROCK_XB_LIQ_ERROR_DEADLOCK_TIMEOUT_INPLACE (BEDROCK_XB_LIQ_ERROR_DEADLOCK_TIMEOUT_MASK << BEDROCK_XB_LIQ_ERROR_DEADLOCK_TIMEOUT_SHIFT)
#define BEDROCK_XB_LIQ_ERROR_OVERFLOW_SHIFT          0 /* inferred */
#define BEDROCK_XB_LIQ_ERROR_OVERFLOW_MASK           0x1ull
#define BEDROCK_XB_LIQ_ERROR_OVERFLOW_INPLACE (BEDROCK_XB_LIQ_ERROR_OVERFLOW_MASK << BEDROCK_XB_LIQ_ERROR_OVERFLOW_SHIFT)

/*
 * The first crossbar error latched. It latches when the valid bit is clear and
 * an error occurs. Any set valid bit interrupts both processor interfaces. The
 * interrupt stays until the error register that captured the error is cleared,
 * then this register is cleared, in that order. The header says the register is
 * not writable but is set whenever software writes any error register.
 */
/* xb_first_error: r64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_FIRST_ERROR                       0x700090 /* inferred */
#define BEDROCK_XB_FIRST_ERROR_VALID_SHIFT           12 /* inferred */
#define BEDROCK_XB_FIRST_ERROR_VALID_MASK            0x1ull
#define BEDROCK_XB_FIRST_ERROR_VALID_INPLACE (BEDROCK_XB_FIRST_ERROR_VALID_MASK << BEDROCK_XB_FIRST_ERROR_VALID_SHIFT)
#define BEDROCK_XB_FIRST_ERROR_SOURCE_SHIFT          8 /* inferred */
#define BEDROCK_XB_FIRST_ERROR_SOURCE_MASK           0xfull
#define BEDROCK_XB_FIRST_ERROR_SOURCE_INPLACE (BEDROCK_XB_FIRST_ERROR_SOURCE_MASK << BEDROCK_XB_FIRST_ERROR_SOURCE_SHIFT)
#define BEDROCK_XB_FIRST_ERROR_CHANNEL_SHIFT         4 /* inferred */
#define BEDROCK_XB_FIRST_ERROR_CHANNEL_MASK          0xfull
#define BEDROCK_XB_FIRST_ERROR_CHANNEL_INPLACE (BEDROCK_XB_FIRST_ERROR_CHANNEL_MASK << BEDROCK_XB_FIRST_ERROR_CHANNEL_SHIFT)
#define BEDROCK_XB_FIRST_ERROR_ERR_TYPE_SHIFT        0 /* inferred */
#define BEDROCK_XB_FIRST_ERROR_ERR_TYPE_MASK         0xfull
#define BEDROCK_XB_FIRST_ERROR_ERR_TYPE_INPLACE (BEDROCK_XB_FIRST_ERROR_ERR_TYPE_MASK << BEDROCK_XB_FIRST_ERROR_ERR_TYPE_SHIFT)

/*
 * Selects which queue observation points drive debug output. The header says
 * more than one selected point makes the debug output undefined. The output
 * formats are not in the header.
 */
/* xb_debug_data_ctl: rw64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_DEBUG_DATA_CTL                    0x700098 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LODATA_SHIFT 15 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LODATA_MASK 0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LODATA_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LODATA_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LODATA_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_SOURCE_FIELD_SHIFT 14 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_SOURCE_FIELD_MASK 0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_SOURCE_FIELD_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_SOURCE_FIELD_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_SOURCE_FIELD_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_POQ0_SHIFT 13 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_POQ0_MASK  0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_POQ0_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_POQ0_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_POQ0_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_POQ1_SHIFT 12 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_POQ1_MASK  0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_POQ1_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_POQ1_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_POQ1_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MMQ_SHIFT  11 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MMQ_MASK   0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MMQ_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MMQ_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MMQ_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MP0_SHIFT  10 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MP0_MASK   0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MP0_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MP0_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MP0_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MP1_SHIFT  9 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MP1_MASK   0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MP1_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MP1_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MP1_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_NOQ_SHIFT  8 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_NOQ_MASK   0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_NOQ_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_NOQ_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_NOQ_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_IOQ_SHIFT  7 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_IOQ_MASK   0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_IOQ_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_IOQ_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_IOQ_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LOQ_SHIFT  6 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LOQ_MASK   0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LOQ_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LOQ_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LOQ_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_PIQ0_SHIFT 5 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_PIQ0_MASK  0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_PIQ0_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_PIQ0_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_PIQ0_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_PIQ1_SHIFT 4 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_PIQ1_MASK  0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_PIQ1_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_PIQ1_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_PIQ1_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MIQ_SHIFT  3 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MIQ_MASK   0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MIQ_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MIQ_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_MIQ_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_NIQ_SHIFT  2 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_NIQ_MASK   0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_NIQ_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_NIQ_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_NIQ_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_IIQ_SHIFT  1 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_IIQ_MASK   0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_IIQ_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_IIQ_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_IIQ_SHIFT)
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LIQ_SHIFT  0 /* inferred */
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LIQ_MASK   0x1ull
#define BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LIQ_INPLACE (BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LIQ_MASK << BEDROCK_XB_DEBUG_DATA_CTL_OBSERVE_LIQ_SHIFT)

/*
 * Three-bit select for the debug mux of the crossbar's queues and arbiter. The
 * header does not give the output each value selects.
 */
/* xb_debug_arb_ctl: rw64, reset unknown; Linux 2.5.40 public SN1 crossbar
 * register headers: register names, offsets and field layouts, first-error
 * source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_DEBUG_ARB_CTL                     0x7000a0 /* inferred */
#define BEDROCK_XB_DEBUG_ARB_CTL_SELECT_SHIFT        0 /* inferred */
#define BEDROCK_XB_DEBUG_ARB_CTL_SELECT_MASK         0x7ull
#define BEDROCK_XB_DEBUG_ARB_CTL_SELECT_INPLACE (BEDROCK_XB_DEBUG_ARB_CTL_SELECT_MASK << BEDROCK_XB_DEBUG_ARB_CTL_SELECT_SHIFT)

/*
 * Clears the PI0 output queue error record. The header does not say whether a
 * write clears by any value or only by set bits, so the mechanism is unknown.
 * Field layout as the base register.
 */
/* xb_poq0_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar
 * register headers: register names, offsets and field layouts, first-error
 * source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_POQ0_ERROR_CLEAR                  0x700120 /* inferred */

/*
 * Clears the PI0 input queue error record. The write mechanism is unknown;
 * field layout as the base register.
 */
/* xb_piq0_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar
 * register headers: register names, offsets and field layouts, first-error
 * source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_PIQ0_ERROR_CLEAR                  0x700128 /* inferred */

/*
 * Clears the PI1 output queue error record. The write mechanism is unknown.
 */
/* xb_poq1_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar
 * register headers: register names, offsets and field layouts, first-error
 * source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_POQ1_ERROR_CLEAR                  0x700130 /* inferred */

/*
 * Clears the PI1 input queue error record. The write mechanism is unknown.
 */
/* xb_piq1_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar
 * register headers: register names, offsets and field layouts, first-error
 * source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_PIQ1_ERROR_CLEAR                  0x700138 /* inferred */

/*
 * Clears the memory-to-PI0 output queue error record. The write mechanism is
 * unknown.
 */
/* xb_mp0_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_MP0_ERROR_CLEAR                   0x700140 /* inferred */

/*
 * Clears the memory-to-PI1 output queue error record. The write mechanism is
 * unknown.
 */
/* xb_mp1_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_MP1_ERROR_CLEAR                   0x700148 /* inferred */

/*
 * Clears the memory output queue error record. The write mechanism is unknown.
 */
/* xb_mmq_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_MMQ_ERROR_CLEAR                   0x700150 /* inferred */

/*
 * Clears the memory input queue error record. The header names this register
 * with an extra XM_ in the macro, and its comment says it clears the MIQ error
 * register. The write mechanism is unknown.
 */
/* xb_miq_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_MIQ_ERROR_CLEAR                   0x700158 /* inferred */

/*
 * Clears the NI output queue error record. The write mechanism is unknown.
 */
/* xb_noq_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_NOQ_ERROR_CLEAR                   0x700160 /* inferred */

/*
 * Clears the NI input queue error record. The write mechanism is unknown.
 */
/* xb_niq_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_NIQ_ERROR_CLEAR                   0x700168 /* inferred */

/*
 * Clears the I/O output queue error record. The write mechanism is unknown.
 */
/* xb_ioq_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_IOQ_ERROR_CLEAR                   0x700170 /* inferred */

/*
 * Clears the I/O input queue error record. The write mechanism is unknown.
 */
/* xb_iiq_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_IIQ_ERROR_CLEAR                   0x700178 /* inferred */

/*
 * Clears the LB output queue error record. The write mechanism is unknown.
 */
/* xb_loq_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_LOQ_ERROR_CLEAR                   0x700180 /* inferred */

/*
 * Clears the LB input queue error record. The write mechanism is unknown.
 */
/* xb_liq_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar register
 * headers: register names, offsets and field layouts, first-error source codes,
 * XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_LIQ_ERROR_CLEAR                   0x700188 /* inferred */

/*
 * Clears the first-error register. The header says it is cleared after the
 * error register that captured the error. The write mechanism is unknown.
 */
/* xb_first_error_clear: w64, reset 0x0; Linux 2.5.40 public SN1 crossbar
 * register headers: register names, offsets and field layouts, first-error
 * source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS */
#define BEDROCK_XB_FIRST_ERROR_CLEAR                 0x700190 /* inferred */

/* inferred */
#define BEDROCK_XB_PARMS_ACTIVE_DEFAULTS             0x80000fffff021ull
/* inferred */
#define BEDROCK_XB_PARMS_RESET_DEFAULTS              0x8000080000021ull

#endif /* BEDROCK_GEN_H */
