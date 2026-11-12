/* generated from defs/bedrock.toml by defs-gen - do not edit, change the source */
/* Bedrock (node controller), Origin 3000 family */
#ifndef BEDROCK_GEN_H
#define BEDROCK_GEN_H

#include <stdint.h>


/* handle_cac_buserr: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HANDLE_CAC_BUSERR                    0x000018 /* established */

/* sub_1bcf0: rw64, reset unknown; census: 115 sites, 24 routines */
#define BEDROCK_SUB_1BCF0                            0x000020 /* established */

/* memory_iscalias: rw64, reset unknown; census: 3 sites, 3 routines */
#define BEDROCK_MEMORY_ISCALIAS                      0x000028 /* established */

/* reg_000040: r64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_REG_000040                           0x000040 /* established */

/* sub_20ee0: w64, reset unknown; census: 9 sites, 7 routines */
#define BEDROCK_SUB_20EE0                            0x000090 /* established */

/* sub_200f0: r64, reset unknown; census: 12 sites, 7 routines */
#define BEDROCK_SUB_200F0                            0x000098 /* established */

/* sub_20250: r64, reset unknown; census: 5 sites, 3 routines */
#define BEDROCK_SUB_20250                            0x0000a0 /* established */

/* reg_000108: w64, reset unknown; census: 24 sites, 2 routines */
#define BEDROCK_REG_000108                           0x000108 /* established */

/* startkgclock: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_STARTKGCLOCK                         0x000118 /* established */

/* acktmoclock: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_ACKTMOCLOCK                          0x000120 /* established */

/* acktmoclock_128: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_ACKTMOCLOCK_128                      0x000128 /* established */

/* ackkgclock: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_ACKKGCLOCK                           0x000130 /* established */

/* ackkgclock_138: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_ACKKGCLOCK_138                       0x000138 /* established */

/* startkgclock_150: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_STARTKGCLOCK_150                     0x000150 /* established */

/* startkgclock_158: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_STARTKGCLOCK_158                     0x000158 /* established */

/* hubpi_eint_handler: rw64, reset unknown; census: 14 sites, 4 routines */
#define BEDROCK_HUBPI_EINT_HANDLER                   0x000400 /* established */

/* err_int_block_mask: rw64, reset unknown; census: 10 sites, 6 routines */
#define BEDROCK_ERR_INT_BLOCK_MASK                   0x000408 /* established */

/* err_int_block_mask_410: rw64, reset unknown; census: 10 sites, 6 routines */
#define BEDROCK_ERR_INT_BLOCK_MASK_410               0x000410 /* established */

/* hubpi_spool_get_next: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUBPI_SPOOL_GET_NEXT                 0x000418 /* established */

/* hubpi_spool_get_next_420: r64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_HUBPI_SPOOL_GET_NEXT_420             0x000420 /* established */

/* hubpi_spool_get_next_430: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUBPI_SPOOL_GET_NEXT_430             0x000430 /* established */

/* hubpi_spool_get_next_440: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUBPI_SPOOL_GET_NEXT_440             0x000440 /* established */

/* hubpi_spool_get_next_448: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUBPI_SPOOL_GET_NEXT_448             0x000448 /* established */

/* hubpi_spool_get_next_450: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUBPI_SPOOL_GET_NEXT_450             0x000450 /* established */

/* hubpi_spool_get_next_460: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUBPI_SPOOL_GET_NEXT_460             0x000460 /* established */

/* hubpi_spool_get_next_468: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUBPI_SPOOL_GET_NEXT_468             0x000468 /* established */

/* hubpi_eint_handler_4c8: rw64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_HUBPI_EINT_HANDLER_4C8               0x0004c8 /* established */

/* hubpi_eint_handler_4d0: rw64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_HUBPI_EINT_HANDLER_4D0               0x0004d0 /* established */

/* restore_hub_err: rw64, reset unknown; census: 103 sites, 56 routines */
#define BEDROCK_RESTORE_HUB_ERR                      0x030100 /* established */

/* reg_400110: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_REG_400110                           0x400110 /* established */

/* reg_400128: rw64, reset unknown; census: 3 sites, 1 routines */
#define BEDROCK_REG_400128                           0x400128 /* established */

/* ii_llp_error_monitor: rw64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_II_LLP_ERROR_MONITOR                 0x400130 /* established */

/* sub_3d1d8: w64, reset unknown; census: 4 sites, 2 routines */
#define BEDROCK_SUB_3D1D8                            0x4001f8 /* established */

/* sub_1bcf0_600000: r64, reset unknown; census: 16 sites, 13 routines */
#define BEDROCK_SUB_1BCF0_600000                     0x600000 /* established */

/* sub_1bcf0_604020: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_SUB_1BCF0_604020                     0x604020 /* established */

/* sub_1bcf0_604028: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_SUB_1BCF0_604028                     0x604028 /* established */

/* sub_28e3c: rw64, reset unknown; census: 67 sites, 36 routines */
#define BEDROCK_SUB_28E3C                            0x604200 /* established */

/* reg_608000: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_REG_608000                           0x608000 /* established */

/* reg_608008: rw64, reset unknown; census: 17 sites, 5 routines */
#define BEDROCK_REG_608008                           0x608008 /* established */

/* reg_608010: rw64, reset unknown; census: 3 sites, 1 routines */
#define BEDROCK_REG_608010                           0x608010 /* established */

/* sub_11984: r64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_SUB_11984                            0x680000 /* established */

/* sub_10c0: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_SUB_10C0                             0x680008 /* established */

/* sub_10c0_680010: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_SUB_10C0_680010                      0x680010 /* established */

/* sub_18a24: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_SUB_18A24                            0x680108 /* established */

/* sub_18a24_680110: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_SUB_18A24_680110                     0x680110 /* established */

/* sub_18a24_680118: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_SUB_18A24_680118                     0x680118 /* established */

/* ni_llp_error_monitor: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_NI_LLP_ERROR_MONITOR                 0x680120 /* established */

/* part_discovery: r64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_PART_DISCOVERY                       0x681000 /* established */

/* part_discovery_681008: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_DISCOVERY_681008                0x681008 /* established */

/* part_discovery_681010: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_DISCOVERY_681010                0x681010 /* established */

/* part_discovery_681018: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_DISCOVERY_681018                0x681018 /* established */

/* part_discovery_682000: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_DISCOVERY_682000                0x682000 /* established */

/* part_discovery_682008: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_DISCOVERY_682008                0x682008 /* established */

/* sub_1bcf0_780000: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_SUB_1BCF0_780000                     0x780000 /* established */

/* mdir_xlate_addr_mem: r64, reset unknown; census: 3 sites, 3 routines */
#define BEDROCK_MDIR_XLATE_ADDR_MEM                  0x780008 /* established */

/* reg_790010: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_REG_790010                           0x790010 /* established */

/* reg_7a0000: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_REG_7A0000                           0x7a0000 /* established */

/* reg_7a0008: rw64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_REG_7A0008                           0x7a0008 /* established */

/* doacvec: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_DOACVEC                              0x7a0038 /* established */

/* reg_7c0018: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_REG_7C0018                           0x7c0018 /* established */

/* reg_7e0018: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_REG_7E0018                           0x7e0018 /* established */

/* intr_dumpvec: rw64, reset unknown; census: 19 sites, 16 routines */
#define BEDROCK_INTR_DUMPVEC                         0x800000 /* established */

/* part_init_node: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_INIT_NODE                       0x800010 /* established */

/* part_terminate: rw64, reset unknown; census: 8 sites, 5 routines */
#define BEDROCK_PART_TERMINATE                       0x800018 /* established */

/* save_hub_err: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_SAVE_HUB_ERR                         0x800020 /* established */

/* mlreset: rw64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_MLRESET                              0x800028 /* established */

/* per_hub_init: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PER_HUB_INIT                         0x800038 /* established */

/* reg_800040: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_REG_800040                           0x800040 /* established */

/* reg_800048: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_REG_800048                           0x800048 /* established */

/* hub_error_init_800050: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_800050                0x800050 /* established */

/* hub_error_init_800058: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_800058                0x800058 /* established */

/* sub_1bcf0_800090: w64, reset unknown; census: 9 sites, 8 routines */
#define BEDROCK_SUB_1BCF0_800090                     0x800090 /* established */

/* brl1_intr_poll: r64, reset unknown; census: 3 sites, 2 routines */
#define BEDROCK_BRL1_INTR_POLL                       0x800098 /* established */

/* sub_18a24_8000a0: r64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_SUB_18A24_8000A0                     0x8000a0 /* established */

/* intr_clear_all: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_INTR_CLEAR_ALL                       0x8000a8 /* established */

/* intr_clear_all_8000b0: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_INTR_CLEAR_ALL_8000B0                0x8000b0 /* established */

/* intr_clear_all_8000b8: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_INTR_CLEAR_ALL_8000B8                0x8000b8 /* established */

/* do_intr_block_bit: rw64, reset unknown; census: 5 sites, 2 routines */
#define BEDROCK_DO_INTR_BLOCK_BIT                    0x8000c0 /* established */

/* part_activate: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_PART_ACTIVATE                        0x8000c8 /* established */

/* part_activate_8000d0: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_PART_ACTIVATE_8000D0                 0x8000d0 /* established */

/* part_init_node_8000e8: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_INIT_NODE_8000E8                0x8000e8 /* established */

/* hub_error_init_8000f0: rw64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_8000F0                0x8000f0 /* established */

/* set_timer_intr: w64, reset unknown; census: 3 sites, 3 routines */
#define BEDROCK_SET_TIMER_INTR                       0x800108 /* established */

/* set_timer_intr_800110: w64, reset unknown; census: 3 sites, 3 routines */
#define BEDROCK_SET_TIMER_INTR_800110                0x800110 /* established */

/* hub_rtc_init: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_RTC_INIT                         0x800140 /* established */

/* hub_rtc_init_800148: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_RTC_INIT_800148                  0x800148 /* established */

/* hub_rtc_init_800150: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_RTC_INIT_800150                  0x800150 /* established */

/* hub_rtc_init_800158: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_RTC_INIT_800158                  0x800158 /* established */

/* sub_3ec6c: rw64, reset unknown; census: 3 sites, 2 routines */
#define BEDROCK_SUB_3EC6C                            0x800400 /* established */

/* hub_error_init_800408: rw64, reset unknown; census: 5 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_800408                0x800408 /* established */

/* hub_error_init_800410: rw64, reset unknown; census: 5 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_800410                0x800410 /* established */

/* hub_error_init_800418: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_800418                0x800418 /* established */

/* hub_error_init_800420: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_800420                0x800420 /* established */

/* show_hub_pi_err: r64, reset unknown; census: 6 sites, 3 routines */
#define BEDROCK_SHOW_HUB_PI_ERR                      0x800428 /* established */

/* hub_error_clear: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_CLEAR                      0x800438 /* established */

/* hub_error_init_800448: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_800448                0x800448 /* established */

/* hub_error_clear_800458: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_CLEAR_800458               0x800458 /* established */

/* hub_error_init_800468: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_800468                0x800468 /* established */

/* hub_error_clear_8004c8: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_CLEAR_8004C8               0x8004c8 /* established */

/* hub_error_clear_8004d0: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_CLEAR_8004D0               0x8004d0 /* established */

/* part_init_node_a00000: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_INIT_NODE_A00000                0xa00000 /* established */

/* part_init_node_a00010: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_INIT_NODE_A00010                0xa00010 /* established */

/* mlreset_a00018: w64, reset unknown; census: 5 sites, 5 routines */
#define BEDROCK_MLRESET_A00018                       0xa00018 /* established */

/* mlreset_a00028: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_MLRESET_A00028                       0xa00028 /* established */

/* per_hub_init_a00038: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PER_HUB_INIT_A00038                  0xa00038 /* established */

/* hub_error_init_a00040: r64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_A00040                0xa00040 /* established */

/* hub_error_init_a00048: r64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_A00048                0xa00048 /* established */

/* hub_error_init_a00050: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_A00050                0xa00050 /* established */

/* hub_error_init_a00058: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_A00058                0xa00058 /* established */

/* sub_1bcf0_a00090: w64, reset unknown; census: 7 sites, 6 routines */
#define BEDROCK_SUB_1BCF0_A00090                     0xa00090 /* established */

/* intr_connect_level: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_INTR_CONNECT_LEVEL                   0xa00098 /* established */

/* intr_clear_all_a000a8: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_INTR_CLEAR_ALL_A000A8                0xa000a8 /* established */

/* intr_clear_all_a000b0: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_INTR_CLEAR_ALL_A000B0                0xa000b0 /* established */

/* intr_clear_all_a000b8: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_INTR_CLEAR_ALL_A000B8                0xa000b8 /* established */

/* do_intr_block_bit_a000c0: rw64, reset unknown; census: 5 sites, 2 routines */
#define BEDROCK_DO_INTR_BLOCK_BIT_A000C0             0xa000c0 /* established */

/* part_init_node_a000e8: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_INIT_NODE_A000E8                0xa000e8 /* established */

/* hub_error_init_a000f0: rw64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_A000F0                0xa000f0 /* established */

/* set_timer_intr_a00108: w64, reset unknown; census: 3 sites, 3 routines */
#define BEDROCK_SET_TIMER_INTR_A00108                0xa00108 /* established */

/* set_timer_intr_a00110: w64, reset unknown; census: 3 sites, 3 routines */
#define BEDROCK_SET_TIMER_INTR_A00110                0xa00110 /* established */

/* hub_rtc_init_a00140: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_RTC_INIT_A00140                  0xa00140 /* established */

/* hub_rtc_init_a00148: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_RTC_INIT_A00148                  0xa00148 /* established */

/* hub_rtc_init_a00150: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_RTC_INIT_A00150                  0xa00150 /* established */

/* hub_rtc_init_a00158: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_RTC_INIT_A00158                  0xa00158 /* established */

/* sub_3ec6c_a00400: rw64, reset unknown; census: 3 sites, 2 routines */
#define BEDROCK_SUB_3EC6C_A00400                     0xa00400 /* established */

/* hub_error_init_a00408: rw64, reset unknown; census: 5 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_A00408                0xa00408 /* established */

/* hub_error_init_a00410: rw64, reset unknown; census: 5 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_A00410                0xa00410 /* established */

/* hub_error_init_a00418: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_A00418                0xa00418 /* established */

/* hub_error_init_a00420: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_A00420                0xa00420 /* established */

/* show_hub_pi_err_a00428: r64, reset unknown; census: 4 sites, 2 routines */
#define BEDROCK_SHOW_HUB_PI_ERR_A00428               0xa00428 /* established */

/* hub_error_clear_a00438: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_CLEAR_A00438               0xa00438 /* established */

/* hub_error_init_a00448: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_A00448                0xa00448 /* established */

/* hub_error_clear_a00458: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_CLEAR_A00458               0xa00458 /* established */

/* hub_error_init_a00468: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_INIT_A00468                0xa00468 /* established */

/* hub_error_clear_a004c8: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_CLEAR_A004C8               0xa004c8 /* established */

/* hub_error_clear_a004d0: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_CLEAR_A004D0               0xa004d0 /* established */

/* md_perf_start_count: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_MD_PERF_START_COUNT                  0xa10000 /* established */

/* hubii_check_widget_disabled: r64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_HUBII_CHECK_WIDGET_DISABLED          0xc00008 /* established */

/* hub_widget_id: r64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_HUB_WIDGET_ID                        0xc00020 /* established */

/* hub_set_piomode: rw64, reset unknown; census: 6 sites, 3 routines */
#define BEDROCK_HUB_SET_PIOMODE                      0xc00110 /* established */

/* hub_device_inquiry: r64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_HUB_DEVICE_INQUIRY                   0xc00118 /* established */

/* hub_widgetdev_enable: rw64, reset unknown; census: 5 sites, 3 routines */
#define BEDROCK_HUB_WIDGETDEV_ENABLE                 0xc00120 /* established */

/* hubii_eint_init: rw64, reset unknown; census: 6 sites, 5 routines */
#define BEDROCK_HUBII_EINT_INIT                      0xc00128 /* established */

/* capture_hub_stats: rw64, reset unknown; census: 3 sites, 2 routines */
#define BEDROCK_CAPTURE_HUB_STATS                    0xc00130 /* established */

/* hub_error_clear_c00138: rw64, reset unknown; census: 7 sites, 4 routines */
#define BEDROCK_HUB_ERROR_CLEAR_C00138               0xc00138 /* established */

/* hub_piomap_alloc: rw64, reset unknown; census: 5 sites, 4 routines */
#define BEDROCK_HUB_PIOMAP_ALLOC                     0xc00160 /* established */

/* mlreset_c00190: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_MLRESET_C00190                       0xc00190 /* established */

/* hub_error_clear_c00198: rw64, reset unknown; census: 7 sites, 4 routines */
#define BEDROCK_HUB_ERROR_CLEAR_C00198               0xc00198 /* established */

/* bte_error_handler: rw64, reset unknown; census: 4 sites, 3 routines */
#define BEDROCK_BTE_ERROR_HANDLER                    0xc001e8 /* established */

/* bte_error_handler_c001f8: rw64, reset unknown; census: 5 sites, 4 routines */
#define BEDROCK_BTE_ERROR_HANDLER_C001F8             0xc001f8 /* established */

/* sub_3dbbc: rw64, reset unknown; census: 5 sites, 3 routines */
#define BEDROCK_SUB_3DBBC                            0xc00200 /* established */

/* bte_error_handler_c00220: rw64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_BTE_ERROR_HANDLER_C00220             0xc00220 /* established */

/* bte_error_handler_c00228: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_BTE_ERROR_HANDLER_C00228             0xc00228 /* established */

/* hub_error_devenable: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_HUB_ERROR_DEVENABLE                  0xc002c8 /* established */

/* hub_widget_reset: rw64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_HUB_WIDGET_RESET                     0xc00308 /* established */

/* hub_widget_reset_c00388: rw64, reset unknown; census: 3 sites, 2 routines */
#define BEDROCK_HUB_WIDGET_RESET_C00388              0xc00388 /* established */

/* hubiio_crb_free: rw64, reset unknown; census: 3 sites, 1 routines */
#define BEDROCK_HUBIIO_CRB_FREE                      0xc00390 /* established */

/* per_hub_init_c003a8: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PER_HUB_INIT_C003A8                  0xc003a8 /* established */

/* bte_crb_error_handler: rw64, reset unknown; census: 7 sites, 1 routines */
#define BEDROCK_BTE_CRB_ERROR_HANDLER                0xc003b0 /* established */

/* per_hub_init_c003b8: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PER_HUB_INIT_C003B8                  0xc003b8 /* established */

/* per_hub_init_c003c0: w64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_PER_HUB_INIT_C003C0                  0xc003c0 /* established */

/* hubiio_crb_free_c00400: rw64, reset unknown; census: 8 sites, 6 routines */
#define BEDROCK_HUBIIO_CRB_FREE_C00400               0xc00400 /* established */

/* hubiio_crb_error_handler: r64, reset unknown; census: 3 sites, 3 routines */
#define BEDROCK_HUBIIO_CRB_ERROR_HANDLER             0xc00408 /* established */

/* hubiio_crb_error_handler_c00410: r64, reset unknown; census: 3 sites, 3 routines */
#define BEDROCK_HUBIIO_CRB_ERROR_HANDLER_C00410      0xc00410 /* established */

/* dump_crb: r64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_DUMP_CRB                             0xc00418 /* established */

/* io_perf_start_count: rw64, reset unknown; census: 4 sites, 2 routines */
#define BEDROCK_IO_PERF_START_COUNT                  0xc30000 /* established */

/* io_perf_start_count_c30008: r64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_IO_PERF_START_COUNT_C30008           0xc30008 /* established */

/* get_hub_chiprev: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_GET_HUB_CHIPREV                      0xe00000 /* established */

/* part_init_node_e04000: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_INIT_NODE_E04000                0xe04000 /* established */

/* part_init_node_e04010: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_PART_INIT_NODE_E04010                0xe04010 /* established */

/* part_init_node_e04020: w64, reset unknown; census: 4 sites, 4 routines */
#define BEDROCK_PART_INIT_NODE_E04020                0xe04020 /* established */

/* nic_access_hub: rw64, reset unknown; census: 6 sites, 1 routines */
#define BEDROCK_NIC_ACCESS_HUB                       0xe04030 /* established */

/* bte_error_handler_e04040: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_BTE_ERROR_HANDLER_E04040             0xe04040 /* established */

/* hub_error_clear_e04048: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_HUB_ERROR_CLEAR_E04048               0xe04048 /* established */

/* hub_error_clear_e04050: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_HUB_ERROR_CLEAR_E04050               0xe04050 /* established */

/* bte_error_handler_e04058: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_BTE_ERROR_HANDLER_E04058             0xe04058 /* established */

/* bte_error_handler_e04060: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_BTE_ERROR_HANDLER_E04060             0xe04060 /* established */

/* sub_10c0_e08010: w64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_SUB_10C0_E08010                      0xe08010 /* established */

/* vector_write_node: rw64, reset unknown; census: 6 sites, 2 routines */
#define BEDROCK_VECTOR_WRITE_NODE                    0xe0c000 /* established */

/* vector_write_node_e0c008: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_VECTOR_WRITE_NODE_E0C008             0xe0c008 /* established */

/* vector_write_node_e0c010: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_VECTOR_WRITE_NODE_E0C010             0xe0c010 /* established */

/* vector_write_node_e0c020: r64, reset unknown; census: 4 sites, 2 routines */
#define BEDROCK_VECTOR_WRITE_NODE_E0C020             0xe0c020 /* established */

/* vector_read_node: rw64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_VECTOR_READ_NODE                     0xe0c030 /* established */

/* vector_write_node_e0c038: r64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_VECTOR_WRITE_NODE_E0C038             0xe0c038 /* established */

/* ni_port_down_reset: r64, reset unknown; census: 4 sites, 3 routines */
#define BEDROCK_NI_PORT_DOWN_RESET                   0xe80000 /* established */

/* sub_18a24_e80010: r64, reset unknown; census: 3 sites, 2 routines */
#define BEDROCK_SUB_18A24_E80010                     0xe80010 /* established */

/* sub_18a24_e80100: rw64, reset unknown; census: 8 sites, 4 routines */
#define BEDROCK_SUB_18A24_E80100                     0xe80100 /* established */

/* sub_18a24_e80120: r64, reset unknown; census: 13 sites, 6 routines */
#define BEDROCK_SUB_18A24_E80120                     0xe80120 /* established */

/* hub_error_clear_f00120: w64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_HUB_ERROR_CLEAR_F00120               0xf00120 /* established */

/* memory_read_accessible: rw64, reset unknown; census: 3 sites, 3 routines */
#define BEDROCK_MEMORY_READ_ACCESSIBLE               0xf80000 /* established */

/* part_init_node_f80008: rw64, reset unknown; census: 4 sites, 3 routines */
#define BEDROCK_PART_INIT_NODE_F80008                0xf80008 /* established */

/* fetchop_flush: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_FETCHOP_FLUSH                        0xf80020 /* established */

/* fetchop_flush_f80028: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_FETCHOP_FLUSH_F80028                 0xf80028 /* established */

/* log_md_errors: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_LOG_MD_ERRORS                        0xf80040 /* established */

/* hub_error_clear_f80058: r64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_HUB_ERROR_CLEAR_F80058               0xf80058 /* established */

/* cpuprom_map: rw64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_CPUPROM_MAP                          0xfa0008 /* established */

/* per_hub_init_fa0038: w64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_PER_HUB_INIT_FA0038                  0xfa0038 /* established */

/* show_dir_state: r64, reset unknown; census: 30 sites, 18 routines */
#define BEDROCK_SHOW_DIR_STATE                       0xfc0000 /* established */

/* memerror_sbe_intr: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_MEMERROR_SBE_INTR                    0xfc0010 /* established */

/* memerror_sbe_intr_fc0018: r64, reset unknown; census: 4 sites, 3 routines */
#define BEDROCK_MEMERROR_SBE_INTR_FC0018             0xfc0018 /* established */

/* hub_error_clear_fc0028: r64, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_HUB_ERROR_CLEAR_FC0028               0xfc0028 /* established */

/* migr_effthreshold_diff: w64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_MIGR_EFFTHRESHOLD_DIFF               0xfc0040 /* established */

/* sub_1242c: rw64, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_SUB_1242C                            0xfc0050 /* established */

/* memerror_sbe_intr_fe0010: r64, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_MEMERROR_SBE_INTR_FE0010             0xfe0010 /* established */

/* memerror_sbe_intr_fe0018: r64, reset unknown; census: 5 sites, 3 routines */
#define BEDROCK_MEMERROR_SBE_INTR_FE0018             0xfe0018 /* established */

/* boot_space_off_000064: r32, space bedrock_boot_space, reset unknown; census: 2 sites, 1 routines */
#define BEDROCK_BOOT_SPACE_OFF_000064                0x000064 /* established */

/* boot_space_nic_get_phase_bits: r64, space bedrock_boot_space, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_BOOT_SPACE_NIC_GET_PHASE_BITS        0x000078 /* established */

/* boot_space_off_000080: r64, space bedrock_boot_space, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_BOOT_SPACE_OFF_000080                0x000080 /* established */

/* boot_space_off_00008c: r32, space bedrock_boot_space, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_BOOT_SPACE_OFF_00008C                0x00008c /* established */

/* boot_space_off_00009c: r32, space bedrock_boot_space, reset unknown; census: 1 sites, 1 routines */
#define BEDROCK_BOOT_SPACE_OFF_00009C                0x00009c /* established */

/* boot_space_cpuprom_detailed_inventory_info_add: r32, space bedrock_boot_space, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_BOOT_SPACE_CPUPROM_DETAILED_INVENTORY_INFO_ADD 0x0000a0 /* established */

/* boot_space_cpuprom_detailed_inventory_info_add_a4: r32, space bedrock_boot_space, reset unknown; census: 2 sites, 2 routines */
#define BEDROCK_BOOT_SPACE_CPUPROM_DETAILED_INVENTORY_INFO_ADD_A4 0x0000a4 /* established */

#define BEDROCK_BOOT_SPACE_OFF_000064_B_15_0         0xffffu /* inferred */
#define BEDROCK_BOOT_SPACE_OFF_000064_B_8_0          0x1ffu /* inferred */
#define BEDROCK_BRL1_INTR_POLL_B_4                   0x10u /* inferred */
#define BEDROCK_BTE_CRB_ERROR_HANDLER_V_800          0x800u /* inferred */
#define BEDROCK_BTE_ERROR_HANDLER_B_0                0x1u /* inferred */
#define BEDROCK_BTE_ERROR_HANDLER_B_4                0x10u /* inferred */
#define BEDROCK_BTE_ERROR_HANDLER_B_4_0              0x11u /* inferred */
#define BEDROCK_BTE_ERROR_HANDLER_B_8                0x100u /* inferred */
#define BEDROCK_BTE_ERROR_HANDLER_C001F8_V_FF0000    0xff0000u /* inferred */
#define BEDROCK_BTE_ERROR_HANDLER_C001F8_V_FFFF      0xffffu /* inferred */
#define BEDROCK_BTE_ERROR_HANDLER_V_101              0x101u /* inferred */
#define BEDROCK_CAPTURE_HUB_STATS_B_15_0             0xffffu /* inferred */
#define BEDROCK_DOACVEC_B_0                          0x1u /* inferred */
#define BEDROCK_GET_HUB_CHIPREV_B_3_0                0xfu /* inferred */
#define BEDROCK_HUBIIO_CRB_ERROR_HANDLER_B_1_0       0x3u /* inferred */
#define BEDROCK_HUBIIO_CRB_FREE_B_4                  0x10u /* inferred */
#define BEDROCK_HUBIIO_CRB_FREE_C00400_B_0           0x1u /* inferred */
#define BEDROCK_HUBIIO_CRB_FREE_C00400_B_2_0         0x7u /* inferred */
#define BEDROCK_HUBIIO_CRB_FREE_C00400_B_3_0         0xfu /* inferred */
#define BEDROCK_HUBIIO_CRB_FREE_C00400_B_4_0         0x1fu /* inferred */
#define BEDROCK_HUBIIO_CRB_FREE_V_10                 0x10u /* inferred */
#define BEDROCK_HUBII_EINT_INIT_B_1                  0x2u /* inferred */
#define BEDROCK_HUBII_EINT_INIT_B_10_0               0x7ffu /* inferred */
#define BEDROCK_HUBII_EINT_INIT_B_13                 0x2000u /* inferred */
#define BEDROCK_HUBPI_EINT_HANDLER_4C8_B_7_0         0xffu /* inferred */
#define BEDROCK_HUB_ERROR_CLEAR_C00138_V_1000000     0x1000000u /* inferred */
#define BEDROCK_HUB_PIOMAP_ALLOC_B_3_0               0xfu /* inferred */
#define BEDROCK_HUB_PIOMAP_ALLOC_B_4_0               0x1fu /* inferred */
#define BEDROCK_HUB_PIOMAP_ALLOC_B_7_0               0xffu /* inferred */
#define BEDROCK_HUB_PIOMAP_ALLOC_V_300               0x300u /* inferred */
#define BEDROCK_HUB_WIDGET_ID_B_3_0                  0xfu /* inferred */
#define BEDROCK_HUB_WIDGET_RESET_B_7_0               0xffu /* inferred */
#define BEDROCK_HUB_WIDGET_RESET_C00388_B_4          0x10u /* inferred */
#define BEDROCK_II_LLP_ERROR_MONITOR_B_15_0          0xffffu /* inferred */
#define BEDROCK_MDIR_XLATE_ADDR_MEM_B_1_0            0x3u /* inferred */
#define BEDROCK_MEMERROR_SBE_INTR_FE0018_B_0         0x1u /* inferred */
#define BEDROCK_MEMORY_ISCALIAS_V_1                  0x1u /* inferred */
#define BEDROCK_NIC_ACCESS_HUB_B_0                   0x1u /* inferred */
#define BEDROCK_NIC_ACCESS_HUB_B_1                   0x2u /* inferred */
#define BEDROCK_NI_LLP_ERROR_MONITOR_B_3_0           0xfu /* inferred */
#define BEDROCK_NI_PORT_DOWN_RESET_B_1               0x2u /* inferred */
#define BEDROCK_NI_PORT_DOWN_RESET_B_2_1             0x6u /* inferred */
#define BEDROCK_PER_HUB_INIT_C003A8_V_F0             0xf0u /* inferred */
#define BEDROCK_PER_HUB_INIT_C003B8_V_FF             0xffu /* inferred */
#define BEDROCK_PER_HUB_INIT_V_200000                0x200000u /* inferred */
#define BEDROCK_REG_000108_V_1                       0x1u /* inferred */
#define BEDROCK_REG_000108_V_2                       0x2u /* inferred */
#define BEDROCK_REG_000108_V_2A                      0x2au /* inferred */
#define BEDROCK_REG_000108_V_2B                      0x2bu /* inferred */
#define BEDROCK_REG_000108_V_3                       0x3u /* inferred */
#define BEDROCK_REG_000108_V_35                      0x35u /* inferred */
#define BEDROCK_REG_000108_V_36                      0x36u /* inferred */
#define BEDROCK_REG_000108_V_4                       0x4u /* inferred */
#define BEDROCK_REG_000108_V_5                       0x5u /* inferred */
#define BEDROCK_REG_000108_V_5D                      0x5du /* inferred */
#define BEDROCK_REG_000108_V_5E                      0x5eu /* inferred */
#define BEDROCK_REG_000108_V_5F                      0x5fu /* inferred */
#define BEDROCK_REG_000108_V_60                      0x60u /* inferred */
#define BEDROCK_REG_000108_V_81                      0x81u /* inferred */
#define BEDROCK_REG_000108_V_83                      0x83u /* inferred */
#define BEDROCK_REG_000108_V_84                      0x84u /* inferred */
#define BEDROCK_REG_000108_V_A                       0xau /* inferred */
#define BEDROCK_REG_000108_V_B                       0xbu /* inferred */
#define BEDROCK_REG_000108_V_B4                      0xb4u /* inferred */
#define BEDROCK_REG_000108_V_C                       0xcu /* inferred */
#define BEDROCK_REG_000108_V_E                       0xeu /* inferred */
#define BEDROCK_REG_000108_V_F                       0xfu /* inferred */
#define BEDROCK_REG_400110_V_FF01                    0xff01u /* inferred */
#define BEDROCK_REG_400128_B_13                      0x2000u /* inferred */
#define BEDROCK_REG_400128_V_100                     0x100u /* inferred */
#define BEDROCK_REG_608008_V_7F80000                 0x7f80000u /* inferred */
#define BEDROCK_REG_608010_B_8                       0x100u /* inferred */
#define BEDROCK_REG_608010_V_7                       0x7u /* inferred */
#define BEDROCK_REG_7A0000_B_11_0                    0xfffu /* inferred */
#define BEDROCK_SHOW_DIR_STATE_B_0                   0x1u /* inferred */
#define BEDROCK_SUB_10C0_680010_V_1                  0x1u /* inferred */
#define BEDROCK_SUB_11984_B_0                        0x1u /* inferred */
#define BEDROCK_SUB_18A24_E80120_B_7_0               0xffu /* inferred */
#define BEDROCK_SUB_1BCF0_600000_B_1_0               0x3u /* inferred */
#define BEDROCK_SUB_1BCF0_600000_B_6_0               0x7fu /* inferred */
#define BEDROCK_SUB_1BCF0_600000_B_7_0               0xffu /* inferred */
#define BEDROCK_SUB_1BCF0_800090_V_100               0x100u /* inferred */
#define BEDROCK_SUB_1BCF0_800090_V_64                0x64u /* inferred */
#define BEDROCK_SUB_1BCF0_A00090_V_100               0x100u /* inferred */
#define BEDROCK_SUB_1BCF0_A00090_V_64                0x64u /* inferred */
#define BEDROCK_SUB_1BCF0_B_0                        0x1u /* inferred */
#define BEDROCK_SUB_1BCF0_B_1                        0x2u /* inferred */
#define BEDROCK_SUB_1BCF0_V_CAFE                     0xcafeu /* inferred */
#define BEDROCK_SUB_20250_B_0                        0x1u /* inferred */
#define BEDROCK_SUB_20EE0_B_0                        0x1u /* inferred */
#define BEDROCK_SUB_20EE0_V_40                       0x40u /* inferred */
#define BEDROCK_SUB_20EE0_V_64                       0x64u /* inferred */
#define BEDROCK_SUB_20EE0_V_6B                       0x6bu /* inferred */
#define BEDROCK_SUB_20EE0_V_7                        0x7u /* inferred */
#define BEDROCK_SUB_28E3C_B_13_4                     0x3ff0u /* inferred */
#define BEDROCK_SUB_28E3C_B_9_0                      0x3ffu /* inferred */
#define BEDROCK_SUB_3D1D8_V_1                        0x1u /* inferred */
#define BEDROCK_SUB_3D1D8_V_10000                    0x10000u /* inferred */
#define BEDROCK_SUB_3D1D8_V_20000                    0x20000u /* inferred */

#endif /* BEDROCK_GEN_H */
