/* generated from devices/hub_windows/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 433dec6921b0152c218127b867a36172e0ae5ba71149fa793336f17dac3023f3 */
/* Hub register arrays whose extent is a fact of its own */
#ifndef HUB_WIN_GEN_H
#define HUB_WIN_GEN_H

#include <stdint.h>


/* enum iio_prb_mode */
#define HUB_WIN_IIO_PRB_MODE_NORMAL                  0 /* established */
#define HUB_WIN_IIO_PRB_MODE_COLLECT_A               1 /* established */
#define HUB_WIN_IIO_PRB_MODE_SERVICE_A               2 /* established */
#define HUB_WIN_IIO_PRB_MODE_SERVICE_B               3 /* established */

/*
 * The graphics registers of both processor slots as one window: page, credit counter, bias, interrupt counter and interrupt comparator for slot A, then the same five for slot B. The source gives the distance between the two sets as the offset of the slot B page from the slot A page. The entries are also listed one by one under their own names; this is the same storage seen as an array, so that its extent is data.
 */
/* pi_gfx_window: rw64, reset 0x0 */
#define HUB_WIN_PI_GFX_WINDOW                        0x000300 /* established */
#define HUB_WIN_PI_GFX_WINDOW_COUNT                  10
#define HUB_WIN_PI_GFX_WINDOW_STRIDE                 8

/*
 * The six memory/directory performance counters as one array. The header gives no access type, so rw is an assumption.
 */
/* md_perf_cnt: rw64, reset unknown; Linux SN0 Hub memory/directory header: MD_PERF_CNT0 to MD_PERF_CNT5 */
#define HUB_WIN_MD_PERF_CNT                          0x210010 /* inferred */
#define HUB_WIN_MD_PERF_CNT_COUNT                    6
#define HUB_WIN_MD_PERF_CNT_STRIDE                   8

/*
 * The eight microcontroller and UART 0 registers as one array. The same storage is listed one by one where the census reaches it. The header gives no access type, so rw is an assumption.
 */
/* md_ureg0: rw64, reset unknown; Linux SN0 Hub memory/directory header: MD_UREG0_0 to MD_UREG0_7 */
#define HUB_WIN_MD_UREG0                             0x220000 /* inferred */
#define HUB_WIN_MD_UREG0_COUNT                       8
#define HUB_WIN_MD_UREG0_STRIDE                      8

/*
 * The sixteen microcontroller and UART 1 registers as one array. They are also listed one by one under their own names; this is the same storage seen as an array, so that its extent is data. On the Origin 200 (the SN00 variant) the kernel's per-processor LED macro writes the LED of slice 0 at element 0 and the LED of slice 1 at element 4, a spacing of four elements per slice; other Hub variants use the separate LED registers. The IRIX register table gives read and write access for the entries it lists (0, 1 and 15) and the header gives all sixteen the same description.
 */
/* md_ureg1: rw64, reset unknown */
#define HUB_WIN_MD_UREG1                             0x220080 /* established */
#define HUB_WIN_MD_UREG1_COUNT                       16
#define HUB_WIN_MD_UREG1_STRIDE                      8

/*
 * The nine I/O partial-request buffer entries (0, then 8 to f) as one array; entry 0 sits at the first offset and entries 8 to f follow, eight bytes apart. The header gives no access type, so rw is an assumption. The header says the nak and overflow counters are status fields to be used only when cleaning up after errors.
 */
/* iio_ioprb: rw64, reset unknown; Linux SN0 Hub I/O header: IIO_IOPRB_0 to IIO_IOPRB_F, IIO_NUM_IPRBS; the iprb_t structure */
#define HUB_WIN_IIO_IOPRB                            0x400198 /* inferred */
#define HUB_WIN_IIO_IOPRB_COUNT                      9
#define HUB_WIN_IIO_IOPRB_STRIDE                     8
#define HUB_WIN_IIO_IOPRB_ERROR_SHIFT                48 /* established */
#define HUB_WIN_IIO_IOPRB_ERROR_MASK                 0x1ull
#define HUB_WIN_IIO_IOPRB_ERROR_INPLACE              (HUB_WIN_IIO_IOPRB_ERROR_MASK << HUB_WIN_IIO_IOPRB_ERROR_SHIFT)
#define HUB_WIN_IIO_IOPRB_OVFLOW_SHIFT               43 /* established */
#define HUB_WIN_IIO_IOPRB_OVFLOW_MASK                0x1full
#define HUB_WIN_IIO_IOPRB_OVFLOW_INPLACE             (HUB_WIN_IIO_IOPRB_OVFLOW_MASK << HUB_WIN_IIO_IOPRB_OVFLOW_SHIFT)
#define HUB_WIN_IIO_IOPRB_FIRE_AND_FORGET_SHIFT      42 /* established */
#define HUB_WIN_IIO_IOPRB_FIRE_AND_FORGET_MASK       0x1ull
#define HUB_WIN_IIO_IOPRB_FIRE_AND_FORGET_INPLACE    (HUB_WIN_IIO_IOPRB_FIRE_AND_FORGET_MASK << HUB_WIN_IIO_IOPRB_FIRE_AND_FORGET_SHIFT)
#define HUB_WIN_IIO_IOPRB_MODE_SHIFT                 40 /* established */
#define HUB_WIN_IIO_IOPRB_MODE_MASK                  0x3ull
#define HUB_WIN_IIO_IOPRB_MODE_INPLACE               (HUB_WIN_IIO_IOPRB_MODE_MASK << HUB_WIN_IIO_IOPRB_MODE_SHIFT)
#define HUB_WIN_IIO_IOPRB_BNAKCTR_SHIFT              24 /* established */
#define HUB_WIN_IIO_IOPRB_BNAKCTR_MASK               0x3fffull
#define HUB_WIN_IIO_IOPRB_BNAKCTR_INPLACE            (HUB_WIN_IIO_IOPRB_BNAKCTR_MASK << HUB_WIN_IIO_IOPRB_BNAKCTR_SHIFT)
#define HUB_WIN_IIO_IOPRB_ANAKCTR_SHIFT              8 /* established */
#define HUB_WIN_IIO_IOPRB_ANAKCTR_MASK               0x3fffull
#define HUB_WIN_IIO_IOPRB_ANAKCTR_INPLACE            (HUB_WIN_IIO_IOPRB_ANAKCTR_MASK << HUB_WIN_IIO_IOPRB_ANAKCTR_SHIFT)
#define HUB_WIN_IIO_IOPRB_XTALKCTR_SHIFT             0 /* established */
#define HUB_WIN_IIO_IOPRB_XTALKCTR_MASK              0xffull
#define HUB_WIN_IIO_IOPRB_XTALKCTR_INPLACE           (HUB_WIN_IIO_IOPRB_XTALKCTR_MASK << HUB_WIN_IIO_IOPRB_XTALKCTR_SHIFT)

/*
 * The eight PIO read address table entries as one array. The header gives no access type, so rw is an assumption.
 */
/* iio_prte: rw64, reset unknown; Linux SN0 Hub I/O header: IIO_PRTE_0, IIO_PRTE(x), IIO_NUM_PRTES; the iprte_a structure */
#define HUB_WIN_IIO_PRTE                             0x400308 /* inferred */
#define HUB_WIN_IIO_PRTE_COUNT                       8
#define HUB_WIN_IIO_PRTE_STRIDE                      8
#define HUB_WIN_IIO_PRTE_VALID_SHIFT                 56 /* established */
#define HUB_WIN_IIO_PRTE_VALID_MASK                  0x1ull
#define HUB_WIN_IIO_PRTE_VALID_INPLACE               (HUB_WIN_IIO_PRTE_VALID_MASK << HUB_WIN_IIO_PRTE_VALID_SHIFT)
#define HUB_WIN_IIO_PRTE_SRCNODE_SHIFT               46 /* established */
#define HUB_WIN_IIO_PRTE_SRCNODE_MASK                0x1ffull
#define HUB_WIN_IIO_PRTE_SRCNODE_INPLACE             (HUB_WIN_IIO_PRTE_SRCNODE_MASK << HUB_WIN_IIO_PRTE_SRCNODE_SHIFT)
#define HUB_WIN_IIO_PRTE_INITIATOR_SHIFT             44 /* established */
#define HUB_WIN_IIO_PRTE_INITIATOR_MASK              0x3ull
#define HUB_WIN_IIO_PRTE_INITIATOR_INPLACE           (HUB_WIN_IIO_PRTE_INITIATOR_MASK << HUB_WIN_IIO_PRTE_INITIATOR_SHIFT)
#define HUB_WIN_IIO_PRTE_ADDR_SHIFT                  3 /* established */
#define HUB_WIN_IIO_PRTE_ADDR_MASK                   0x3fffffffffull
#define HUB_WIN_IIO_PRTE_ADDR_INPLACE                (HUB_WIN_IIO_PRTE_ADDR_MASK << HUB_WIN_IIO_PRTE_ADDR_SHIFT)

/*
 * The eight network age-control registers as one array: CPU 0 memory, CPU 0 PIO, CPU 1 memory, CPU 1 PIO, GBR memory, GBR PIO, I/O memory, I/O PIO, in that order. The same storage is listed one by one in the network interface unit, where the field layout sits. The header gives no access type, so rw is an assumption.
 */
/* ni_age: rw64, reset unknown; Linux SN0 Hub network interface header: NI_AGE_CPU0_MEMORY to NI_AGE_IO_PIO (NI_AGE_REG_MIN, NI_AGE_REG_MAX) */
#define HUB_WIN_NI_AGE                               0x600500 /* inferred */
#define HUB_WIN_NI_AGE_COUNT                         8
#define HUB_WIN_NI_AGE_STRIDE                        8

/*
 * The 32-entry meta routing table as one array, replacing the split of the first entry and the other 31. Each entry holds the exit port. The header gives no access type, so rw is an assumption.
 */
/* ni_meta_table: rw64, reset unknown; Linux SN0 Hub network interface header: NI_META_TABLE(x), NI_META_ENTRIES, NMT_EXIT_PORT_MASK */
#define HUB_WIN_NI_META_TABLE                        0x638000 /* inferred */
#define HUB_WIN_NI_META_TABLE_COUNT                  32
#define HUB_WIN_NI_META_TABLE_STRIDE                 8
#define HUB_WIN_NI_META_TABLE_EXIT_PORT_SHIFT        0 /* established */
#define HUB_WIN_NI_META_TABLE_EXIT_PORT_MASK         0xfull
#define HUB_WIN_NI_META_TABLE_EXIT_PORT_INPLACE      (HUB_WIN_NI_META_TABLE_EXIT_PORT_MASK << HUB_WIN_NI_META_TABLE_EXIT_PORT_SHIFT)

/*
 * The 16-entry local routing table as one array, replacing the split of the first entry and the other 15. Each entry holds the exit port. The header gives no access type, so rw is an assumption.
 */
/* ni_local_table: rw64, reset unknown; Linux SN0 Hub network interface header: NI_LOCAL_TABLE(x), NI_LOCAL_ENTRIES, NLT_EXIT_PORT_MASK */
#define HUB_WIN_NI_LOCAL_TABLE                       0x638100 /* inferred */
#define HUB_WIN_NI_LOCAL_TABLE_COUNT                 16
#define HUB_WIN_NI_LOCAL_TABLE_STRIDE                8
#define HUB_WIN_NI_LOCAL_TABLE_EXIT_PORT_SHIFT       0 /* established */
#define HUB_WIN_NI_LOCAL_TABLE_EXIT_PORT_MASK        0xfull
#define HUB_WIN_NI_LOCAL_TABLE_EXIT_PORT_INPLACE     (HUB_WIN_NI_LOCAL_TABLE_EXIT_PORT_MASK << HUB_WIN_NI_LOCAL_TABLE_EXIT_PORT_SHIFT)

#define HUB_WIN_BWIN_INDEX_BITS                      0x3u /* established */
#define HUB_WIN_BWIN_SIZE_BITS_M_MODE                0x1du /* established */
#define HUB_WIN_BWIN_SIZE_BITS_N_MODE                0x1cu /* established */
#define HUB_WIN_HUB_REGISTER_WIDGET                  0x1u /* established */
#define HUB_WIN_HUB_REGISTER_WINDOW_SIZE             0x800000u /* established */
#define HUB_WIN_NASID_BITS_M_MODE                    0x8u /* established */
#define HUB_WIN_NASID_BITS_N_MODE                    0x9u /* established */
#define HUB_WIN_NASID_LOCAL_BITS                     0x4u /* established */
#define HUB_WIN_NASID_SHIFT_M_MODE                   0x20u /* established */
#define HUB_WIN_NASID_SHIFT_N_MODE                   0x1fu /* established */
#define HUB_WIN_NODE_SIZE_BITS_M_MODE                0x20u /* established */
#define HUB_WIN_NODE_SIZE_BITS_N_MODE                0x1fu /* established */
#define HUB_WIN_SWIN_SIZE_BITS                       0x18u /* established */

#endif /* HUB_WIN_GEN_H */
