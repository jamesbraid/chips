/* generated from devices/uv1/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 159c697560a3b949dc49448667f72fec268c6242349e1b64f09c426b965975bf */
/* UV1 (UV 1000 generation) hub MMR map */
#ifndef UV1_GEN_H
#define UV1_GEN_H

#include <stdint.h>


/*
 * Header name UVH_NODE_ID. Hub identity: part number, revision, manufacturer and the node id the hub was given. Software reads it at offset 0 to tell the hub generation.
 */
/* node_id: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_NODE_ID                                  0x000000 /* established */
#define UV1_NODE_ID_NI_PORT_SHIFT                    56 /* established */
#define UV1_NODE_ID_NI_PORT_MASK                     0xfull
#define UV1_NODE_ID_NI_PORT_INPLACE                  (UV1_NODE_ID_NI_PORT_MASK << UV1_NODE_ID_NI_PORT_SHIFT)
#define UV1_NODE_ID_NODES_PER_BIT_SHIFT              48 /* established */
#define UV1_NODE_ID_NODES_PER_BIT_MASK               0x7full
#define UV1_NODE_ID_NODES_PER_BIT_INPLACE            (UV1_NODE_ID_NODES_PER_BIT_MASK << UV1_NODE_ID_NODES_PER_BIT_SHIFT)
#define UV1_NODE_ID_NODE_ID_SHIFT                    32 /* established */
#define UV1_NODE_ID_NODE_ID_MASK                     0x7fffull
#define UV1_NODE_ID_NODE_ID_INPLACE                  (UV1_NODE_ID_NODE_ID_MASK << UV1_NODE_ID_NODE_ID_SHIFT)
#define UV1_NODE_ID_REVISION_SHIFT                   28 /* established */
#define UV1_NODE_ID_REVISION_MASK                    0xfull
#define UV1_NODE_ID_REVISION_INPLACE                 (UV1_NODE_ID_REVISION_MASK << UV1_NODE_ID_REVISION_SHIFT)
#define UV1_NODE_ID_PART_NUMBER_SHIFT                12 /* established */
#define UV1_NODE_ID_PART_NUMBER_MASK                 0xffffull
#define UV1_NODE_ID_PART_NUMBER_INPLACE              (UV1_NODE_ID_PART_NUMBER_MASK << UV1_NODE_ID_PART_NUMBER_SHIFT)
#define UV1_NODE_ID_MANUFACTURER_SHIFT               1 /* established */
#define UV1_NODE_ID_MANUFACTURER_MASK                0x7ffull
#define UV1_NODE_ID_MANUFACTURER_INPLACE             (UV1_NODE_ID_MANUFACTURER_MASK << UV1_NODE_ID_MANUFACTURER_SHIFT)
#define UV1_NODE_ID_FORCE1_SHIFT                     0 /* established */
#define UV1_NODE_ID_FORCE1_MASK                      0x1ull
#define UV1_NODE_ID_FORCE1_INPLACE                   (UV1_NODE_ID_FORCE1_MASK << UV1_NODE_ID_FORCE1_SHIFT)

/*
 * Header name UVH_NODE_PRESENT_TABLE.
 */
/* node_present_table: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_NODE_PRESENT_TABLE                       0x001400 /* established */
#define UV1_NODE_PRESENT_TABLE_COUNT                 16
#define UV1_NODE_PRESENT_TABLE_STRIDE                8
#define UV1_NODE_PRESENT_TABLE_NODES_SHIFT           0 /* established */
#define UV1_NODE_PRESENT_TABLE_NODES_MASK            0xffffffffffffffffull
#define UV1_NODE_PRESENT_TABLE_NODES_INPLACE         (UV1_NODE_PRESENT_TABLE_NODES_MASK << UV1_NODE_PRESENT_TABLE_NODES_SHIFT)

/*
 * Header name UVH_INT_CMPB. RTC comparator B: the timer interrupt fires when the clock reaches this value.
 */
/* int_cmpb: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_INT_CMPB                                 0x022080 /* established */
#define UV1_INT_CMPB_REAL_TIME_CMPB_SHIFT            0 /* established */
#define UV1_INT_CMPB_REAL_TIME_CMPB_MASK             0xffffffffffffffull
#define UV1_INT_CMPB_REAL_TIME_CMPB_INPLACE          (UV1_INT_CMPB_REAL_TIME_CMPB_MASK << UV1_INT_CMPB_REAL_TIME_CMPB_SHIFT)

/*
 * Header name UVH_INT_CMPC.
 */
/* int_cmpc: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_INT_CMPC                                 0x022100 /* established */
#define UV1_INT_CMPC_REAL_TIME_CMPC_SHIFT            0 /* established */
#define UV1_INT_CMPC_REAL_TIME_CMPC_MASK             0xffffffffffffffull
#define UV1_INT_CMPC_REAL_TIME_CMPC_INPLACE          (UV1_INT_CMPC_REAL_TIME_CMPC_MASK << UV1_INT_CMPC_REAL_TIME_CMPC_SHIFT)

/*
 * Header name UVH_INT_CMPD.
 */
/* int_cmpd: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_INT_CMPD                                 0x022180 /* established */
#define UV1_INT_CMPD_REAL_TIME_CMPD_SHIFT            0 /* established */
#define UV1_INT_CMPD_REAL_TIME_CMPD_MASK             0xffffffffffffffull
#define UV1_INT_CMPD_REAL_TIME_CMPD_INPLACE          (UV1_INT_CMPD_REAL_TIME_CMPD_MASK << UV1_INT_CMPD_REAL_TIME_CMPD_SHIFT)

/*
 * Header name UVH_IPI_INT. Send an inter-processor interrupt: the sender writes the target apic id, vector and a send bit in the target hub global MMR window.
 */
/* ipi_int: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_IPI_INT                                  0x060500 /* established */
#define UV1_IPI_INT_SEND_SHIFT                       63 /* established */
#define UV1_IPI_INT_SEND_MASK                        0x1ull
#define UV1_IPI_INT_SEND_INPLACE                     (UV1_IPI_INT_SEND_MASK << UV1_IPI_INT_SEND_SHIFT)
#define UV1_IPI_INT_APIC_ID_SHIFT                    16 /* established */
#define UV1_IPI_INT_APIC_ID_MASK                     0xffffffffull
#define UV1_IPI_INT_APIC_ID_INPLACE                  (UV1_IPI_INT_APIC_ID_MASK << UV1_IPI_INT_APIC_ID_SHIFT)
#define UV1_IPI_INT_DESTMODE_SHIFT                   11 /* established */
#define UV1_IPI_INT_DESTMODE_MASK                    0x1ull
#define UV1_IPI_INT_DESTMODE_INPLACE                 (UV1_IPI_INT_DESTMODE_MASK << UV1_IPI_INT_DESTMODE_SHIFT)
#define UV1_IPI_INT_DELIVERY_MODE_SHIFT              8 /* established */
#define UV1_IPI_INT_DELIVERY_MODE_MASK               0x7ull
#define UV1_IPI_INT_DELIVERY_MODE_INPLACE            (UV1_IPI_INT_DELIVERY_MODE_MASK << UV1_IPI_INT_DELIVERY_MODE_SHIFT)
#define UV1_IPI_INT_VECTOR_SHIFT                     0 /* established */
#define UV1_IPI_INT_VECTOR_MASK                      0xffull
#define UV1_IPI_INT_VECTOR_INPLACE                   (UV1_IPI_INT_VECTOR_MASK << UV1_IPI_INT_VECTOR_SHIFT)

/*
 * Header name UVH_EXTIO_INT0_BROADCAST.
 */
/* extio_int0_broadcast: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_EXTIO_INT0_BROADCAST                     0x061448 /* established */
#define UV1_EXTIO_INT0_BROADCAST_ENABLE_SHIFT        0 /* established */
#define UV1_EXTIO_INT0_BROADCAST_ENABLE_MASK         0x1ull
#define UV1_EXTIO_INT0_BROADCAST_ENABLE_INPLACE      (UV1_EXTIO_INT0_BROADCAST_ENABLE_MASK << UV1_EXTIO_INT0_BROADCAST_ENABLE_SHIFT)

/*
 * Header name UVH_RTC1_INT_CONFIG. Delivery configuration (vector, apic id) for the RTC comparator interrupt.
 */
/* rtc1_int_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RTC1_INT_CONFIG                          0x0615c0 /* established */
#define UV1_RTC1_INT_CONFIG_APIC_ID_SHIFT            32 /* established */
#define UV1_RTC1_INT_CONFIG_APIC_ID_MASK             0xffffffffull
#define UV1_RTC1_INT_CONFIG_APIC_ID_INPLACE          (UV1_RTC1_INT_CONFIG_APIC_ID_MASK << UV1_RTC1_INT_CONFIG_APIC_ID_SHIFT)
#define UV1_RTC1_INT_CONFIG_M_SHIFT                  16 /* established */
#define UV1_RTC1_INT_CONFIG_M_MASK                   0x1ull
#define UV1_RTC1_INT_CONFIG_M_INPLACE                (UV1_RTC1_INT_CONFIG_M_MASK << UV1_RTC1_INT_CONFIG_M_SHIFT)
#define UV1_RTC1_INT_CONFIG_T_SHIFT                  15 /* established */
#define UV1_RTC1_INT_CONFIG_T_MASK                   0x1ull
#define UV1_RTC1_INT_CONFIG_T_INPLACE                (UV1_RTC1_INT_CONFIG_T_MASK << UV1_RTC1_INT_CONFIG_T_SHIFT)
#define UV1_RTC1_INT_CONFIG_P_SHIFT                  13 /* established */
#define UV1_RTC1_INT_CONFIG_P_MASK                   0x1ull
#define UV1_RTC1_INT_CONFIG_P_INPLACE                (UV1_RTC1_INT_CONFIG_P_MASK << UV1_RTC1_INT_CONFIG_P_SHIFT)
#define UV1_RTC1_INT_CONFIG_STATUS_SHIFT             12 /* established */
#define UV1_RTC1_INT_CONFIG_STATUS_MASK              0x1ull
#define UV1_RTC1_INT_CONFIG_STATUS_INPLACE           (UV1_RTC1_INT_CONFIG_STATUS_MASK << UV1_RTC1_INT_CONFIG_STATUS_SHIFT)
#define UV1_RTC1_INT_CONFIG_DESTMODE_SHIFT           11 /* established */
#define UV1_RTC1_INT_CONFIG_DESTMODE_MASK            0x1ull
#define UV1_RTC1_INT_CONFIG_DESTMODE_INPLACE         (UV1_RTC1_INT_CONFIG_DESTMODE_MASK << UV1_RTC1_INT_CONFIG_DESTMODE_SHIFT)
#define UV1_RTC1_INT_CONFIG_DM_SHIFT                 8 /* established */
#define UV1_RTC1_INT_CONFIG_DM_MASK                  0x7ull
#define UV1_RTC1_INT_CONFIG_DM_INPLACE               (UV1_RTC1_INT_CONFIG_DM_MASK << UV1_RTC1_INT_CONFIG_DM_SHIFT)
#define UV1_RTC1_INT_CONFIG_VECTOR_SHIFT             0 /* established */
#define UV1_RTC1_INT_CONFIG_VECTOR_MASK              0xffull
#define UV1_RTC1_INT_CONFIG_VECTOR_INPLACE           (UV1_RTC1_INT_CONFIG_VECTOR_MASK << UV1_RTC1_INT_CONFIG_VECTOR_SHIFT)

/*
 * Header name UVH_BAU_DATA_CONFIG. Where the hub sends a broadcast assist unit message interrupt: vector, delivery mode and apic id.
 */
/* bau_data_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_BAU_DATA_CONFIG                          0x061680 /* established */
#define UV1_BAU_DATA_CONFIG_APIC_ID_SHIFT            32 /* established */
#define UV1_BAU_DATA_CONFIG_APIC_ID_MASK             0xffffffffull
#define UV1_BAU_DATA_CONFIG_APIC_ID_INPLACE          (UV1_BAU_DATA_CONFIG_APIC_ID_MASK << UV1_BAU_DATA_CONFIG_APIC_ID_SHIFT)
#define UV1_BAU_DATA_CONFIG_M_SHIFT                  16 /* established */
#define UV1_BAU_DATA_CONFIG_M_MASK                   0x1ull
#define UV1_BAU_DATA_CONFIG_M_INPLACE                (UV1_BAU_DATA_CONFIG_M_MASK << UV1_BAU_DATA_CONFIG_M_SHIFT)
#define UV1_BAU_DATA_CONFIG_T_SHIFT                  15 /* established */
#define UV1_BAU_DATA_CONFIG_T_MASK                   0x1ull
#define UV1_BAU_DATA_CONFIG_T_INPLACE                (UV1_BAU_DATA_CONFIG_T_MASK << UV1_BAU_DATA_CONFIG_T_SHIFT)
#define UV1_BAU_DATA_CONFIG_P_SHIFT                  13 /* established */
#define UV1_BAU_DATA_CONFIG_P_MASK                   0x1ull
#define UV1_BAU_DATA_CONFIG_P_INPLACE                (UV1_BAU_DATA_CONFIG_P_MASK << UV1_BAU_DATA_CONFIG_P_SHIFT)
#define UV1_BAU_DATA_CONFIG_STATUS_SHIFT             12 /* established */
#define UV1_BAU_DATA_CONFIG_STATUS_MASK              0x1ull
#define UV1_BAU_DATA_CONFIG_STATUS_INPLACE           (UV1_BAU_DATA_CONFIG_STATUS_MASK << UV1_BAU_DATA_CONFIG_STATUS_SHIFT)
#define UV1_BAU_DATA_CONFIG_DESTMODE_SHIFT           11 /* established */
#define UV1_BAU_DATA_CONFIG_DESTMODE_MASK            0x1ull
#define UV1_BAU_DATA_CONFIG_DESTMODE_INPLACE         (UV1_BAU_DATA_CONFIG_DESTMODE_MASK << UV1_BAU_DATA_CONFIG_DESTMODE_SHIFT)
#define UV1_BAU_DATA_CONFIG_DM_SHIFT                 8 /* established */
#define UV1_BAU_DATA_CONFIG_DM_MASK                  0x7ull
#define UV1_BAU_DATA_CONFIG_DM_INPLACE               (UV1_BAU_DATA_CONFIG_DM_MASK << UV1_BAU_DATA_CONFIG_DM_SHIFT)
#define UV1_BAU_DATA_CONFIG_VECTOR_SHIFT             0 /* established */
#define UV1_BAU_DATA_CONFIG_VECTOR_MASK              0xffull
#define UV1_BAU_DATA_CONFIG_VECTOR_INPLACE           (UV1_BAU_DATA_CONFIG_VECTOR_MASK << UV1_BAU_DATA_CONFIG_VECTOR_SHIFT)

/*
 * Header name UVH_BAU_DATA_BROADCAST. Enable broadcast of BAU message interrupts to both sockets of the hub (UV2 and later).
 */
/* bau_data_broadcast: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_BAU_DATA_BROADCAST                       0x061688 /* established */
#define UV1_BAU_DATA_BROADCAST_ENABLE_SHIFT          0 /* established */
#define UV1_BAU_DATA_BROADCAST_ENABLE_MASK           0x1ull
#define UV1_BAU_DATA_BROADCAST_ENABLE_INPLACE        (UV1_BAU_DATA_BROADCAST_ENABLE_MASK << UV1_BAU_DATA_BROADCAST_ENABLE_SHIFT)

/*
 * Header name UVH_GR0_TLB_INT0_CONFIG.
 */
/* gr0_tlb_int0_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_GR0_TLB_INT0_CONFIG                      0x061b00 /* established */
#define UV1_GR0_TLB_INT0_CONFIG_APIC_ID_SHIFT        32 /* established */
#define UV1_GR0_TLB_INT0_CONFIG_APIC_ID_MASK         0xffffffffull
#define UV1_GR0_TLB_INT0_CONFIG_APIC_ID_INPLACE      (UV1_GR0_TLB_INT0_CONFIG_APIC_ID_MASK << UV1_GR0_TLB_INT0_CONFIG_APIC_ID_SHIFT)
#define UV1_GR0_TLB_INT0_CONFIG_M_SHIFT              16 /* established */
#define UV1_GR0_TLB_INT0_CONFIG_M_MASK               0x1ull
#define UV1_GR0_TLB_INT0_CONFIG_M_INPLACE            (UV1_GR0_TLB_INT0_CONFIG_M_MASK << UV1_GR0_TLB_INT0_CONFIG_M_SHIFT)
#define UV1_GR0_TLB_INT0_CONFIG_T_SHIFT              15 /* established */
#define UV1_GR0_TLB_INT0_CONFIG_T_MASK               0x1ull
#define UV1_GR0_TLB_INT0_CONFIG_T_INPLACE            (UV1_GR0_TLB_INT0_CONFIG_T_MASK << UV1_GR0_TLB_INT0_CONFIG_T_SHIFT)
#define UV1_GR0_TLB_INT0_CONFIG_P_SHIFT              13 /* established */
#define UV1_GR0_TLB_INT0_CONFIG_P_MASK               0x1ull
#define UV1_GR0_TLB_INT0_CONFIG_P_INPLACE            (UV1_GR0_TLB_INT0_CONFIG_P_MASK << UV1_GR0_TLB_INT0_CONFIG_P_SHIFT)
#define UV1_GR0_TLB_INT0_CONFIG_STATUS_SHIFT         12 /* established */
#define UV1_GR0_TLB_INT0_CONFIG_STATUS_MASK          0x1ull
#define UV1_GR0_TLB_INT0_CONFIG_STATUS_INPLACE       (UV1_GR0_TLB_INT0_CONFIG_STATUS_MASK << UV1_GR0_TLB_INT0_CONFIG_STATUS_SHIFT)
#define UV1_GR0_TLB_INT0_CONFIG_DESTMODE_SHIFT       11 /* established */
#define UV1_GR0_TLB_INT0_CONFIG_DESTMODE_MASK        0x1ull
#define UV1_GR0_TLB_INT0_CONFIG_DESTMODE_INPLACE     (UV1_GR0_TLB_INT0_CONFIG_DESTMODE_MASK << UV1_GR0_TLB_INT0_CONFIG_DESTMODE_SHIFT)
#define UV1_GR0_TLB_INT0_CONFIG_DM_SHIFT             8 /* established */
#define UV1_GR0_TLB_INT0_CONFIG_DM_MASK              0x7ull
#define UV1_GR0_TLB_INT0_CONFIG_DM_INPLACE           (UV1_GR0_TLB_INT0_CONFIG_DM_MASK << UV1_GR0_TLB_INT0_CONFIG_DM_SHIFT)
#define UV1_GR0_TLB_INT0_CONFIG_VECTOR_SHIFT         0 /* established */
#define UV1_GR0_TLB_INT0_CONFIG_VECTOR_MASK          0xffull
#define UV1_GR0_TLB_INT0_CONFIG_VECTOR_INPLACE       (UV1_GR0_TLB_INT0_CONFIG_VECTOR_MASK << UV1_GR0_TLB_INT0_CONFIG_VECTOR_SHIFT)

/*
 * Header name UVH_GR0_TLB_INT1_CONFIG.
 */
/* gr0_tlb_int1_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_GR0_TLB_INT1_CONFIG                      0x061b40 /* established */
#define UV1_GR0_TLB_INT1_CONFIG_APIC_ID_SHIFT        32 /* established */
#define UV1_GR0_TLB_INT1_CONFIG_APIC_ID_MASK         0xffffffffull
#define UV1_GR0_TLB_INT1_CONFIG_APIC_ID_INPLACE      (UV1_GR0_TLB_INT1_CONFIG_APIC_ID_MASK << UV1_GR0_TLB_INT1_CONFIG_APIC_ID_SHIFT)
#define UV1_GR0_TLB_INT1_CONFIG_M_SHIFT              16 /* established */
#define UV1_GR0_TLB_INT1_CONFIG_M_MASK               0x1ull
#define UV1_GR0_TLB_INT1_CONFIG_M_INPLACE            (UV1_GR0_TLB_INT1_CONFIG_M_MASK << UV1_GR0_TLB_INT1_CONFIG_M_SHIFT)
#define UV1_GR0_TLB_INT1_CONFIG_T_SHIFT              15 /* established */
#define UV1_GR0_TLB_INT1_CONFIG_T_MASK               0x1ull
#define UV1_GR0_TLB_INT1_CONFIG_T_INPLACE            (UV1_GR0_TLB_INT1_CONFIG_T_MASK << UV1_GR0_TLB_INT1_CONFIG_T_SHIFT)
#define UV1_GR0_TLB_INT1_CONFIG_P_SHIFT              13 /* established */
#define UV1_GR0_TLB_INT1_CONFIG_P_MASK               0x1ull
#define UV1_GR0_TLB_INT1_CONFIG_P_INPLACE            (UV1_GR0_TLB_INT1_CONFIG_P_MASK << UV1_GR0_TLB_INT1_CONFIG_P_SHIFT)
#define UV1_GR0_TLB_INT1_CONFIG_STATUS_SHIFT         12 /* established */
#define UV1_GR0_TLB_INT1_CONFIG_STATUS_MASK          0x1ull
#define UV1_GR0_TLB_INT1_CONFIG_STATUS_INPLACE       (UV1_GR0_TLB_INT1_CONFIG_STATUS_MASK << UV1_GR0_TLB_INT1_CONFIG_STATUS_SHIFT)
#define UV1_GR0_TLB_INT1_CONFIG_DESTMODE_SHIFT       11 /* established */
#define UV1_GR0_TLB_INT1_CONFIG_DESTMODE_MASK        0x1ull
#define UV1_GR0_TLB_INT1_CONFIG_DESTMODE_INPLACE     (UV1_GR0_TLB_INT1_CONFIG_DESTMODE_MASK << UV1_GR0_TLB_INT1_CONFIG_DESTMODE_SHIFT)
#define UV1_GR0_TLB_INT1_CONFIG_DM_SHIFT             8 /* established */
#define UV1_GR0_TLB_INT1_CONFIG_DM_MASK              0x7ull
#define UV1_GR0_TLB_INT1_CONFIG_DM_INPLACE           (UV1_GR0_TLB_INT1_CONFIG_DM_MASK << UV1_GR0_TLB_INT1_CONFIG_DM_SHIFT)
#define UV1_GR0_TLB_INT1_CONFIG_VECTOR_SHIFT         0 /* established */
#define UV1_GR0_TLB_INT1_CONFIG_VECTOR_MASK          0xffull
#define UV1_GR0_TLB_INT1_CONFIG_VECTOR_INPLACE       (UV1_GR0_TLB_INT1_CONFIG_VECTOR_MASK << UV1_GR0_TLB_INT1_CONFIG_VECTOR_SHIFT)

/*
 * Header name UVH_GR1_TLB_INT0_CONFIG.
 */
/* gr1_tlb_int0_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_GR1_TLB_INT0_CONFIG                      0x061f00 /* established */
#define UV1_GR1_TLB_INT0_CONFIG_APIC_ID_SHIFT        32 /* established */
#define UV1_GR1_TLB_INT0_CONFIG_APIC_ID_MASK         0xffffffffull
#define UV1_GR1_TLB_INT0_CONFIG_APIC_ID_INPLACE      (UV1_GR1_TLB_INT0_CONFIG_APIC_ID_MASK << UV1_GR1_TLB_INT0_CONFIG_APIC_ID_SHIFT)
#define UV1_GR1_TLB_INT0_CONFIG_M_SHIFT              16 /* established */
#define UV1_GR1_TLB_INT0_CONFIG_M_MASK               0x1ull
#define UV1_GR1_TLB_INT0_CONFIG_M_INPLACE            (UV1_GR1_TLB_INT0_CONFIG_M_MASK << UV1_GR1_TLB_INT0_CONFIG_M_SHIFT)
#define UV1_GR1_TLB_INT0_CONFIG_T_SHIFT              15 /* established */
#define UV1_GR1_TLB_INT0_CONFIG_T_MASK               0x1ull
#define UV1_GR1_TLB_INT0_CONFIG_T_INPLACE            (UV1_GR1_TLB_INT0_CONFIG_T_MASK << UV1_GR1_TLB_INT0_CONFIG_T_SHIFT)
#define UV1_GR1_TLB_INT0_CONFIG_P_SHIFT              13 /* established */
#define UV1_GR1_TLB_INT0_CONFIG_P_MASK               0x1ull
#define UV1_GR1_TLB_INT0_CONFIG_P_INPLACE            (UV1_GR1_TLB_INT0_CONFIG_P_MASK << UV1_GR1_TLB_INT0_CONFIG_P_SHIFT)
#define UV1_GR1_TLB_INT0_CONFIG_STATUS_SHIFT         12 /* established */
#define UV1_GR1_TLB_INT0_CONFIG_STATUS_MASK          0x1ull
#define UV1_GR1_TLB_INT0_CONFIG_STATUS_INPLACE       (UV1_GR1_TLB_INT0_CONFIG_STATUS_MASK << UV1_GR1_TLB_INT0_CONFIG_STATUS_SHIFT)
#define UV1_GR1_TLB_INT0_CONFIG_DESTMODE_SHIFT       11 /* established */
#define UV1_GR1_TLB_INT0_CONFIG_DESTMODE_MASK        0x1ull
#define UV1_GR1_TLB_INT0_CONFIG_DESTMODE_INPLACE     (UV1_GR1_TLB_INT0_CONFIG_DESTMODE_MASK << UV1_GR1_TLB_INT0_CONFIG_DESTMODE_SHIFT)
#define UV1_GR1_TLB_INT0_CONFIG_DM_SHIFT             8 /* established */
#define UV1_GR1_TLB_INT0_CONFIG_DM_MASK              0x7ull
#define UV1_GR1_TLB_INT0_CONFIG_DM_INPLACE           (UV1_GR1_TLB_INT0_CONFIG_DM_MASK << UV1_GR1_TLB_INT0_CONFIG_DM_SHIFT)
#define UV1_GR1_TLB_INT0_CONFIG_VECTOR_SHIFT         0 /* established */
#define UV1_GR1_TLB_INT0_CONFIG_VECTOR_MASK          0xffull
#define UV1_GR1_TLB_INT0_CONFIG_VECTOR_INPLACE       (UV1_GR1_TLB_INT0_CONFIG_VECTOR_MASK << UV1_GR1_TLB_INT0_CONFIG_VECTOR_SHIFT)

/*
 * Header name UVH_GR1_TLB_INT1_CONFIG.
 */
/* gr1_tlb_int1_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_GR1_TLB_INT1_CONFIG                      0x061f40 /* established */
#define UV1_GR1_TLB_INT1_CONFIG_APIC_ID_SHIFT        32 /* established */
#define UV1_GR1_TLB_INT1_CONFIG_APIC_ID_MASK         0xffffffffull
#define UV1_GR1_TLB_INT1_CONFIG_APIC_ID_INPLACE      (UV1_GR1_TLB_INT1_CONFIG_APIC_ID_MASK << UV1_GR1_TLB_INT1_CONFIG_APIC_ID_SHIFT)
#define UV1_GR1_TLB_INT1_CONFIG_M_SHIFT              16 /* established */
#define UV1_GR1_TLB_INT1_CONFIG_M_MASK               0x1ull
#define UV1_GR1_TLB_INT1_CONFIG_M_INPLACE            (UV1_GR1_TLB_INT1_CONFIG_M_MASK << UV1_GR1_TLB_INT1_CONFIG_M_SHIFT)
#define UV1_GR1_TLB_INT1_CONFIG_T_SHIFT              15 /* established */
#define UV1_GR1_TLB_INT1_CONFIG_T_MASK               0x1ull
#define UV1_GR1_TLB_INT1_CONFIG_T_INPLACE            (UV1_GR1_TLB_INT1_CONFIG_T_MASK << UV1_GR1_TLB_INT1_CONFIG_T_SHIFT)
#define UV1_GR1_TLB_INT1_CONFIG_P_SHIFT              13 /* established */
#define UV1_GR1_TLB_INT1_CONFIG_P_MASK               0x1ull
#define UV1_GR1_TLB_INT1_CONFIG_P_INPLACE            (UV1_GR1_TLB_INT1_CONFIG_P_MASK << UV1_GR1_TLB_INT1_CONFIG_P_SHIFT)
#define UV1_GR1_TLB_INT1_CONFIG_STATUS_SHIFT         12 /* established */
#define UV1_GR1_TLB_INT1_CONFIG_STATUS_MASK          0x1ull
#define UV1_GR1_TLB_INT1_CONFIG_STATUS_INPLACE       (UV1_GR1_TLB_INT1_CONFIG_STATUS_MASK << UV1_GR1_TLB_INT1_CONFIG_STATUS_SHIFT)
#define UV1_GR1_TLB_INT1_CONFIG_DESTMODE_SHIFT       11 /* established */
#define UV1_GR1_TLB_INT1_CONFIG_DESTMODE_MASK        0x1ull
#define UV1_GR1_TLB_INT1_CONFIG_DESTMODE_INPLACE     (UV1_GR1_TLB_INT1_CONFIG_DESTMODE_MASK << UV1_GR1_TLB_INT1_CONFIG_DESTMODE_SHIFT)
#define UV1_GR1_TLB_INT1_CONFIG_DM_SHIFT             8 /* established */
#define UV1_GR1_TLB_INT1_CONFIG_DM_MASK              0x7ull
#define UV1_GR1_TLB_INT1_CONFIG_DM_INPLACE           (UV1_GR1_TLB_INT1_CONFIG_DM_MASK << UV1_GR1_TLB_INT1_CONFIG_DM_SHIFT)
#define UV1_GR1_TLB_INT1_CONFIG_VECTOR_SHIFT         0 /* established */
#define UV1_GR1_TLB_INT1_CONFIG_VECTOR_MASK          0xffull
#define UV1_GR1_TLB_INT1_CONFIG_VECTOR_INPLACE       (UV1_GR1_TLB_INT1_CONFIG_VECTOR_MASK << UV1_GR1_TLB_INT1_CONFIG_VECTOR_SHIFT)

/*
 * Header name UVH_EVENT_OCCURRED0. Pending hub events (error and interrupt summary bits). The ALIAS register at +8 clears bits when written.
 */
/* event_occurred0: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_EVENT_OCCURRED0                          0x070000 /* established */
#define UV1_EVENT_OCCURRED0_POWER_MANAGEMENT_REQ_SHIFT 56 /* established */
#define UV1_EVENT_OCCURRED0_POWER_MANAGEMENT_REQ_MASK 0x1ull
#define UV1_EVENT_OCCURRED0_POWER_MANAGEMENT_REQ_INPLACE (UV1_EVENT_OCCURRED0_POWER_MANAGEMENT_REQ_MASK << UV1_EVENT_OCCURRED0_POWER_MANAGEMENT_REQ_SHIFT)
#define UV1_EVENT_OCCURRED0_BAU_DATA_SHIFT           55 /* established */
#define UV1_EVENT_OCCURRED0_BAU_DATA_MASK            0x1ull
#define UV1_EVENT_OCCURRED0_BAU_DATA_INPLACE         (UV1_EVENT_OCCURRED0_BAU_DATA_MASK << UV1_EVENT_OCCURRED0_BAU_DATA_SHIFT)
#define UV1_EVENT_OCCURRED0_RTC3_SHIFT               54 /* established */
#define UV1_EVENT_OCCURRED0_RTC3_MASK                0x1ull
#define UV1_EVENT_OCCURRED0_RTC3_INPLACE             (UV1_EVENT_OCCURRED0_RTC3_MASK << UV1_EVENT_OCCURRED0_RTC3_SHIFT)
#define UV1_EVENT_OCCURRED0_RTC2_SHIFT               53 /* established */
#define UV1_EVENT_OCCURRED0_RTC2_MASK                0x1ull
#define UV1_EVENT_OCCURRED0_RTC2_INPLACE             (UV1_EVENT_OCCURRED0_RTC2_MASK << UV1_EVENT_OCCURRED0_RTC2_SHIFT)
#define UV1_EVENT_OCCURRED0_RTC1_SHIFT               52 /* established */
#define UV1_EVENT_OCCURRED0_RTC1_MASK                0x1ull
#define UV1_EVENT_OCCURRED0_RTC1_INPLACE             (UV1_EVENT_OCCURRED0_RTC1_MASK << UV1_EVENT_OCCURRED0_RTC1_SHIFT)
#define UV1_EVENT_OCCURRED0_RTC0_SHIFT               51 /* established */
#define UV1_EVENT_OCCURRED0_RTC0_MASK                0x1ull
#define UV1_EVENT_OCCURRED0_RTC0_INPLACE             (UV1_EVENT_OCCURRED0_RTC0_MASK << UV1_EVENT_OCCURRED0_RTC0_SHIFT)
#define UV1_EVENT_OCCURRED0_PROFILE_INT_SHIFT        50 /* established */
#define UV1_EVENT_OCCURRED0_PROFILE_INT_MASK         0x1ull
#define UV1_EVENT_OCCURRED0_PROFILE_INT_INPLACE      (UV1_EVENT_OCCURRED0_PROFILE_INT_MASK << UV1_EVENT_OCCURRED0_PROFILE_INT_SHIFT)
#define UV1_EVENT_OCCURRED0_EXTIO_INT3_SHIFT         49 /* established */
#define UV1_EVENT_OCCURRED0_EXTIO_INT3_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_EXTIO_INT3_INPLACE       (UV1_EVENT_OCCURRED0_EXTIO_INT3_MASK << UV1_EVENT_OCCURRED0_EXTIO_INT3_SHIFT)
#define UV1_EVENT_OCCURRED0_EXTIO_INT2_SHIFT         48 /* established */
#define UV1_EVENT_OCCURRED0_EXTIO_INT2_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_EXTIO_INT2_INPLACE       (UV1_EVENT_OCCURRED0_EXTIO_INT2_MASK << UV1_EVENT_OCCURRED0_EXTIO_INT2_SHIFT)
#define UV1_EVENT_OCCURRED0_EXTIO_INT1_SHIFT         47 /* established */
#define UV1_EVENT_OCCURRED0_EXTIO_INT1_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_EXTIO_INT1_INPLACE       (UV1_EVENT_OCCURRED0_EXTIO_INT1_MASK << UV1_EVENT_OCCURRED0_EXTIO_INT1_SHIFT)
#define UV1_EVENT_OCCURRED0_EXTIO_INT0_SHIFT         46 /* established */
#define UV1_EVENT_OCCURRED0_EXTIO_INT0_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_EXTIO_INT0_INPLACE       (UV1_EVENT_OCCURRED0_EXTIO_INT0_MASK << UV1_EVENT_OCCURRED0_EXTIO_INT0_SHIFT)
#define UV1_EVENT_OCCURRED0_IPI_INT_SHIFT            45 /* established */
#define UV1_EVENT_OCCURRED0_IPI_INT_MASK             0x1ull
#define UV1_EVENT_OCCURRED0_IPI_INT_INPLACE          (UV1_EVENT_OCCURRED0_IPI_INT_MASK << UV1_EVENT_OCCURRED0_IPI_INT_SHIFT)
#define UV1_EVENT_OCCURRED0_LA_SEQ_TRIGGER_SHIFT     44 /* established */
#define UV1_EVENT_OCCURRED0_LA_SEQ_TRIGGER_MASK      0x1ull
#define UV1_EVENT_OCCURRED0_LA_SEQ_TRIGGER_INPLACE   (UV1_EVENT_OCCURRED0_LA_SEQ_TRIGGER_MASK << UV1_EVENT_OCCURRED0_LA_SEQ_TRIGGER_SHIFT)
#define UV1_EVENT_OCCURRED0_LTC_INT_SHIFT            43 /* established */
#define UV1_EVENT_OCCURRED0_LTC_INT_MASK             0x1ull
#define UV1_EVENT_OCCURRED0_LTC_INT_INPLACE          (UV1_EVENT_OCCURRED0_LTC_INT_MASK << UV1_EVENT_OCCURRED0_LTC_INT_SHIFT)
#define UV1_EVENT_OCCURRED0_L1_TO_ASIC_SHIFT         42 /* established */
#define UV1_EVENT_OCCURRED0_L1_TO_ASIC_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_L1_TO_ASIC_INPLACE       (UV1_EVENT_OCCURRED0_L1_TO_ASIC_MASK << UV1_EVENT_OCCURRED0_L1_TO_ASIC_SHIFT)
#define UV1_EVENT_OCCURRED0_ASIC_TO_L1_SHIFT         41 /* established */
#define UV1_EVENT_OCCURRED0_ASIC_TO_L1_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_ASIC_TO_L1_INPLACE       (UV1_EVENT_OCCURRED0_ASIC_TO_L1_MASK << UV1_EVENT_OCCURRED0_ASIC_TO_L1_SHIFT)
#define UV1_EVENT_OCCURRED0_STOP_CLOCK_SHIFT         40 /* established */
#define UV1_EVENT_OCCURRED0_STOP_CLOCK_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_STOP_CLOCK_INPLACE       (UV1_EVENT_OCCURRED0_STOP_CLOCK_MASK << UV1_EVENT_OCCURRED0_STOP_CLOCK_SHIFT)
#define UV1_EVENT_OCCURRED0_L1_NMI_INT_SHIFT         39 /* established */
#define UV1_EVENT_OCCURRED0_L1_NMI_INT_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_L1_NMI_INT_INPLACE       (UV1_EVENT_OCCURRED0_L1_NMI_INT_MASK << UV1_EVENT_OCCURRED0_L1_NMI_INT_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_15_SHIFT      38 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_15_MASK       0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_15_INPLACE    (UV1_EVENT_OCCURRED0_LB_IRQ_INT_15_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_15_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_14_SHIFT      37 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_14_MASK       0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_14_INPLACE    (UV1_EVENT_OCCURRED0_LB_IRQ_INT_14_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_14_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_13_SHIFT      36 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_13_MASK       0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_13_INPLACE    (UV1_EVENT_OCCURRED0_LB_IRQ_INT_13_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_13_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_12_SHIFT      35 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_12_MASK       0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_12_INPLACE    (UV1_EVENT_OCCURRED0_LB_IRQ_INT_12_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_12_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_11_SHIFT      34 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_11_MASK       0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_11_INPLACE    (UV1_EVENT_OCCURRED0_LB_IRQ_INT_11_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_11_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_10_SHIFT      33 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_10_MASK       0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_10_INPLACE    (UV1_EVENT_OCCURRED0_LB_IRQ_INT_10_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_10_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_9_SHIFT       32 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_9_MASK        0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_9_INPLACE     (UV1_EVENT_OCCURRED0_LB_IRQ_INT_9_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_9_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_8_SHIFT       31 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_8_MASK        0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_8_INPLACE     (UV1_EVENT_OCCURRED0_LB_IRQ_INT_8_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_8_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_7_SHIFT       30 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_7_MASK        0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_7_INPLACE     (UV1_EVENT_OCCURRED0_LB_IRQ_INT_7_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_7_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_6_SHIFT       29 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_6_MASK        0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_6_INPLACE     (UV1_EVENT_OCCURRED0_LB_IRQ_INT_6_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_6_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_5_SHIFT       28 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_5_MASK        0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_5_INPLACE     (UV1_EVENT_OCCURRED0_LB_IRQ_INT_5_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_5_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_4_SHIFT       27 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_4_MASK        0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_4_INPLACE     (UV1_EVENT_OCCURRED0_LB_IRQ_INT_4_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_4_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_3_SHIFT       26 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_3_MASK        0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_3_INPLACE     (UV1_EVENT_OCCURRED0_LB_IRQ_INT_3_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_3_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_2_SHIFT       25 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_2_MASK        0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_2_INPLACE     (UV1_EVENT_OCCURRED0_LB_IRQ_INT_2_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_2_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_1_SHIFT       24 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_1_MASK        0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_1_INPLACE     (UV1_EVENT_OCCURRED0_LB_IRQ_INT_1_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_1_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_0_SHIFT       23 /* established */
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_0_MASK        0x1ull
#define UV1_EVENT_OCCURRED0_LB_IRQ_INT_0_INPLACE     (UV1_EVENT_OCCURRED0_LB_IRQ_INT_0_MASK << UV1_EVENT_OCCURRED0_LB_IRQ_INT_0_SHIFT)
#define UV1_EVENT_OCCURRED0_SYSTEM_SHUTDOWN_INT_SHIFT 22 /* established */
#define UV1_EVENT_OCCURRED0_SYSTEM_SHUTDOWN_INT_MASK 0x1ull
#define UV1_EVENT_OCCURRED0_SYSTEM_SHUTDOWN_INT_INPLACE (UV1_EVENT_OCCURRED0_SYSTEM_SHUTDOWN_INT_MASK << UV1_EVENT_OCCURRED0_SYSTEM_SHUTDOWN_INT_SHIFT)
#define UV1_EVENT_OCCURRED0_RH_VPI_INT_SHIFT         21 /* established */
#define UV1_EVENT_OCCURRED0_RH_VPI_INT_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_RH_VPI_INT_INPLACE       (UV1_EVENT_OCCURRED0_RH_VPI_INT_MASK << UV1_EVENT_OCCURRED0_RH_VPI_INT_SHIFT)
#define UV1_EVENT_OCCURRED0_SI_AOERR1_SHIFT          20 /* established */
#define UV1_EVENT_OCCURRED0_SI_AOERR1_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_SI_AOERR1_INPLACE        (UV1_EVENT_OCCURRED0_SI_AOERR1_MASK << UV1_EVENT_OCCURRED0_SI_AOERR1_SHIFT)
#define UV1_EVENT_OCCURRED0_XN_AOERR1_SHIFT          19 /* established */
#define UV1_EVENT_OCCURRED0_XN_AOERR1_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_XN_AOERR1_INPLACE        (UV1_EVENT_OCCURRED0_XN_AOERR1_MASK << UV1_EVENT_OCCURRED0_XN_AOERR1_SHIFT)
#define UV1_EVENT_OCCURRED0_RH_AOERR1_SHIFT          18 /* established */
#define UV1_EVENT_OCCURRED0_RH_AOERR1_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_RH_AOERR1_INPLACE        (UV1_EVENT_OCCURRED0_RH_AOERR1_MASK << UV1_EVENT_OCCURRED0_RH_AOERR1_SHIFT)
#define UV1_EVENT_OCCURRED0_LH_AOERR1_SHIFT          17 /* established */
#define UV1_EVENT_OCCURRED0_LH_AOERR1_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_LH_AOERR1_INPLACE        (UV1_EVENT_OCCURRED0_LH_AOERR1_MASK << UV1_EVENT_OCCURRED0_LH_AOERR1_SHIFT)
#define UV1_EVENT_OCCURRED0_GR1_AOERR1_SHIFT         16 /* established */
#define UV1_EVENT_OCCURRED0_GR1_AOERR1_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_GR1_AOERR1_INPLACE       (UV1_EVENT_OCCURRED0_GR1_AOERR1_MASK << UV1_EVENT_OCCURRED0_GR1_AOERR1_SHIFT)
#define UV1_EVENT_OCCURRED0_GR0_AOERR1_SHIFT         15 /* established */
#define UV1_EVENT_OCCURRED0_GR0_AOERR1_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_GR0_AOERR1_INPLACE       (UV1_EVENT_OCCURRED0_GR0_AOERR1_MASK << UV1_EVENT_OCCURRED0_GR0_AOERR1_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_AOERR1_SHIFT          14 /* established */
#define UV1_EVENT_OCCURRED0_LB_AOERR1_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_LB_AOERR1_INPLACE        (UV1_EVENT_OCCURRED0_LB_AOERR1_MASK << UV1_EVENT_OCCURRED0_LB_AOERR1_SHIFT)
#define UV1_EVENT_OCCURRED0_SI_AOERR0_SHIFT          13 /* established */
#define UV1_EVENT_OCCURRED0_SI_AOERR0_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_SI_AOERR0_INPLACE        (UV1_EVENT_OCCURRED0_SI_AOERR0_MASK << UV1_EVENT_OCCURRED0_SI_AOERR0_SHIFT)
#define UV1_EVENT_OCCURRED0_XN_AOERR0_SHIFT          12 /* established */
#define UV1_EVENT_OCCURRED0_XN_AOERR0_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_XN_AOERR0_INPLACE        (UV1_EVENT_OCCURRED0_XN_AOERR0_MASK << UV1_EVENT_OCCURRED0_XN_AOERR0_SHIFT)
#define UV1_EVENT_OCCURRED0_RH_AOERR0_SHIFT          11 /* established */
#define UV1_EVENT_OCCURRED0_RH_AOERR0_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_RH_AOERR0_INPLACE        (UV1_EVENT_OCCURRED0_RH_AOERR0_MASK << UV1_EVENT_OCCURRED0_RH_AOERR0_SHIFT)
#define UV1_EVENT_OCCURRED0_LH_AOERR0_SHIFT          10 /* established */
#define UV1_EVENT_OCCURRED0_LH_AOERR0_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_LH_AOERR0_INPLACE        (UV1_EVENT_OCCURRED0_LH_AOERR0_MASK << UV1_EVENT_OCCURRED0_LH_AOERR0_SHIFT)
#define UV1_EVENT_OCCURRED0_GR1_AOERR0_SHIFT         9 /* established */
#define UV1_EVENT_OCCURRED0_GR1_AOERR0_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_GR1_AOERR0_INPLACE       (UV1_EVENT_OCCURRED0_GR1_AOERR0_MASK << UV1_EVENT_OCCURRED0_GR1_AOERR0_SHIFT)
#define UV1_EVENT_OCCURRED0_GR0_AOERR0_SHIFT         8 /* established */
#define UV1_EVENT_OCCURRED0_GR0_AOERR0_MASK          0x1ull
#define UV1_EVENT_OCCURRED0_GR0_AOERR0_INPLACE       (UV1_EVENT_OCCURRED0_GR0_AOERR0_MASK << UV1_EVENT_OCCURRED0_GR0_AOERR0_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_AOERR0_SHIFT          7 /* established */
#define UV1_EVENT_OCCURRED0_LB_AOERR0_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_LB_AOERR0_INPLACE        (UV1_EVENT_OCCURRED0_LB_AOERR0_MASK << UV1_EVENT_OCCURRED0_LB_AOERR0_SHIFT)
#define UV1_EVENT_OCCURRED0_SI_HCERR_SHIFT           6 /* established */
#define UV1_EVENT_OCCURRED0_SI_HCERR_MASK            0x1ull
#define UV1_EVENT_OCCURRED0_SI_HCERR_INPLACE         (UV1_EVENT_OCCURRED0_SI_HCERR_MASK << UV1_EVENT_OCCURRED0_SI_HCERR_SHIFT)
#define UV1_EVENT_OCCURRED0_XN_HCERR_SHIFT           5 /* established */
#define UV1_EVENT_OCCURRED0_XN_HCERR_MASK            0x1ull
#define UV1_EVENT_OCCURRED0_XN_HCERR_INPLACE         (UV1_EVENT_OCCURRED0_XN_HCERR_MASK << UV1_EVENT_OCCURRED0_XN_HCERR_SHIFT)
#define UV1_EVENT_OCCURRED0_RH_HCERR_SHIFT           4 /* established */
#define UV1_EVENT_OCCURRED0_RH_HCERR_MASK            0x1ull
#define UV1_EVENT_OCCURRED0_RH_HCERR_INPLACE         (UV1_EVENT_OCCURRED0_RH_HCERR_MASK << UV1_EVENT_OCCURRED0_RH_HCERR_SHIFT)
#define UV1_EVENT_OCCURRED0_LH_HCERR_SHIFT           3 /* established */
#define UV1_EVENT_OCCURRED0_LH_HCERR_MASK            0x1ull
#define UV1_EVENT_OCCURRED0_LH_HCERR_INPLACE         (UV1_EVENT_OCCURRED0_LH_HCERR_MASK << UV1_EVENT_OCCURRED0_LH_HCERR_SHIFT)
#define UV1_EVENT_OCCURRED0_GR1_HCERR_SHIFT          2 /* established */
#define UV1_EVENT_OCCURRED0_GR1_HCERR_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_GR1_HCERR_INPLACE        (UV1_EVENT_OCCURRED0_GR1_HCERR_MASK << UV1_EVENT_OCCURRED0_GR1_HCERR_SHIFT)
#define UV1_EVENT_OCCURRED0_GR0_HCERR_SHIFT          1 /* established */
#define UV1_EVENT_OCCURRED0_GR0_HCERR_MASK           0x1ull
#define UV1_EVENT_OCCURRED0_GR0_HCERR_INPLACE        (UV1_EVENT_OCCURRED0_GR0_HCERR_MASK << UV1_EVENT_OCCURRED0_GR0_HCERR_SHIFT)
#define UV1_EVENT_OCCURRED0_LB_HCERR_SHIFT           0 /* established */
#define UV1_EVENT_OCCURRED0_LB_HCERR_MASK            0x1ull
#define UV1_EVENT_OCCURRED0_LB_HCERR_INPLACE         (UV1_EVENT_OCCURRED0_LB_HCERR_MASK << UV1_EVENT_OCCURRED0_LB_HCERR_SHIFT)

/*
 * Header name UVH_EVENT_OCCURRED0_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.
 */
/* event_occurred0_alias: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_EVENT_OCCURRED0_ALIAS                    0x070008 /* established */

/*
 * Header name UVH_SCRATCH5. Scratch register firmware and kernel share: carries the TSC sync state and the NMI request bit.
 */
/* scratch5: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_SCRATCH5                                 0x2d0200 /* established */
#define UV1_SCRATCH5_SCRATCH5_SHIFT                  0 /* established */
#define UV1_SCRATCH5_SCRATCH5_MASK                   0xffffffffffffffffull
#define UV1_SCRATCH5_SCRATCH5_INPLACE                (UV1_SCRATCH5_SCRATCH5_MASK << UV1_SCRATCH5_SCRATCH5_SHIFT)

/*
 * Header name UVH_SCRATCH5_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.
 */
/* scratch5_alias: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_SCRATCH5_ALIAS                           0x2d0208 /* established */

/*
 * Header name UVH_SCRATCH5_ALIAS_2. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.
 */
/* scratch5_alias_2: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_SCRATCH5_ALIAS_2                         0x2d0210 /* established */

/*
 * Header name UVH_LB_BAU_SB_DESCRIPTOR_BASE. Base of the 64 sets of selective-broadcast descriptors in memory: page address and the home node id.
 */
/* lb_bau_sb_descriptor_base: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_LB_BAU_SB_DESCRIPTOR_BASE                0x320010 /* established */
#define UV1_LB_BAU_SB_DESCRIPTOR_BASE_NODE_ID_SHIFT  49 /* established */
#define UV1_LB_BAU_SB_DESCRIPTOR_BASE_NODE_ID_MASK   0x3fffull
#define UV1_LB_BAU_SB_DESCRIPTOR_BASE_NODE_ID_INPLACE (UV1_LB_BAU_SB_DESCRIPTOR_BASE_NODE_ID_MASK << UV1_LB_BAU_SB_DESCRIPTOR_BASE_NODE_ID_SHIFT)
#define UV1_LB_BAU_SB_DESCRIPTOR_BASE_PAGE_ADDRESS_SHIFT 12 /* established */
#define UV1_LB_BAU_SB_DESCRIPTOR_BASE_PAGE_ADDRESS_MASK 0x7fffffffull
#define UV1_LB_BAU_SB_DESCRIPTOR_BASE_PAGE_ADDRESS_INPLACE (UV1_LB_BAU_SB_DESCRIPTOR_BASE_PAGE_ADDRESS_MASK << UV1_LB_BAU_SB_DESCRIPTOR_BASE_PAGE_ADDRESS_SHIFT)

/*
 * Header name UVH_LB_BAU_SB_ACTIVATION_CONTROL. Start a broadcast: a push bit plus the index of the descriptor set.
 */
/* lb_bau_sb_activation_control: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_LB_BAU_SB_ACTIVATION_CONTROL             0x320020 /* established */
#define UV1_LB_BAU_SB_ACTIVATION_CONTROL_INIT_SHIFT  63 /* established */
#define UV1_LB_BAU_SB_ACTIVATION_CONTROL_INIT_MASK   0x1ull
#define UV1_LB_BAU_SB_ACTIVATION_CONTROL_INIT_INPLACE (UV1_LB_BAU_SB_ACTIVATION_CONTROL_INIT_MASK << UV1_LB_BAU_SB_ACTIVATION_CONTROL_INIT_SHIFT)
#define UV1_LB_BAU_SB_ACTIVATION_CONTROL_PUSH_SHIFT  62 /* established */
#define UV1_LB_BAU_SB_ACTIVATION_CONTROL_PUSH_MASK   0x1ull
#define UV1_LB_BAU_SB_ACTIVATION_CONTROL_PUSH_INPLACE (UV1_LB_BAU_SB_ACTIVATION_CONTROL_PUSH_MASK << UV1_LB_BAU_SB_ACTIVATION_CONTROL_PUSH_SHIFT)
#define UV1_LB_BAU_SB_ACTIVATION_CONTROL_INDEX_SHIFT 0 /* established */
#define UV1_LB_BAU_SB_ACTIVATION_CONTROL_INDEX_MASK  0x3full
#define UV1_LB_BAU_SB_ACTIVATION_CONTROL_INDEX_INPLACE (UV1_LB_BAU_SB_ACTIVATION_CONTROL_INDEX_MASK << UV1_LB_BAU_SB_ACTIVATION_CONTROL_INDEX_SHIFT)

/*
 * Header name UVH_LB_BAU_SB_ACTIVATION_STATUS_0.
 */
/* lb_bau_sb_activation_status_0: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_LB_BAU_SB_ACTIVATION_STATUS_0            0x320030 /* established */
#define UV1_LB_BAU_SB_ACTIVATION_STATUS_0_STATUS_SHIFT 0 /* established */
#define UV1_LB_BAU_SB_ACTIVATION_STATUS_0_STATUS_MASK 0xffffffffffffffffull
#define UV1_LB_BAU_SB_ACTIVATION_STATUS_0_STATUS_INPLACE (UV1_LB_BAU_SB_ACTIVATION_STATUS_0_STATUS_MASK << UV1_LB_BAU_SB_ACTIVATION_STATUS_0_STATUS_SHIFT)

/*
 * Header name UVH_LB_BAU_SB_ACTIVATION_STATUS_1.
 */
/* lb_bau_sb_activation_status_1: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_LB_BAU_SB_ACTIVATION_STATUS_1            0x320040 /* established */
#define UV1_LB_BAU_SB_ACTIVATION_STATUS_1_STATUS_SHIFT 0 /* established */
#define UV1_LB_BAU_SB_ACTIVATION_STATUS_1_STATUS_MASK 0xffffffffffffffffull
#define UV1_LB_BAU_SB_ACTIVATION_STATUS_1_STATUS_INPLACE (UV1_LB_BAU_SB_ACTIVATION_STATUS_1_STATUS_MASK << UV1_LB_BAU_SB_ACTIVATION_STATUS_1_STATUS_SHIFT)

/*
 * Header name UVH_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST.
 */
/* lb_bau_intd_payload_queue_first: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST          0x320050 /* established */
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST_NODE_ID_SHIFT 49 /* established */
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST_NODE_ID_MASK 0x3fffull
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST_NODE_ID_INPLACE (UV1_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST_NODE_ID_MASK << UV1_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST_NODE_ID_SHIFT)
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST_ADDRESS_SHIFT 4 /* established */
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST_ADDRESS_MASK 0x7fffffffffull
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST_ADDRESS_INPLACE (UV1_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST_ADDRESS_MASK << UV1_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST_ADDRESS_SHIFT)

/*
 * Header name UVH_LB_BAU_INTD_PAYLOAD_QUEUE_LAST.
 */
/* lb_bau_intd_payload_queue_last: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_LAST           0x320060 /* established */
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_LAST_ADDRESS_SHIFT 4 /* established */
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_LAST_ADDRESS_MASK 0x7fffffffffull
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_LAST_ADDRESS_INPLACE (UV1_LB_BAU_INTD_PAYLOAD_QUEUE_LAST_ADDRESS_MASK << UV1_LB_BAU_INTD_PAYLOAD_QUEUE_LAST_ADDRESS_SHIFT)

/*
 * Header name UVH_LB_BAU_INTD_PAYLOAD_QUEUE_TAIL.
 */
/* lb_bau_intd_payload_queue_tail: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_TAIL           0x320070 /* established */
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_TAIL_ADDRESS_SHIFT 4 /* established */
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_TAIL_ADDRESS_MASK 0x7fffffffffull
#define UV1_LB_BAU_INTD_PAYLOAD_QUEUE_TAIL_ADDRESS_INPLACE (UV1_LB_BAU_INTD_PAYLOAD_QUEUE_TAIL_ADDRESS_MASK << UV1_LB_BAU_INTD_PAYLOAD_QUEUE_TAIL_ADDRESS_SHIFT)

/*
 * Header name UVH_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE.
 */
/* lb_bau_intd_software_acknowledge: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE         0x320080 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_7_SHIFT 15 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_7_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_7_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_7_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_7_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_6_SHIFT 14 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_6_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_6_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_6_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_6_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_5_SHIFT 13 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_5_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_5_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_5_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_5_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_4_SHIFT 12 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_4_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_4_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_4_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_4_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_3_SHIFT 11 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_3_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_3_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_3_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_3_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_2_SHIFT 10 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_2_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_2_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_2_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_2_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_1_SHIFT 9 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_1_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_1_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_1_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_1_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_0_SHIFT 8 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_0_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_0_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_0_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_TIMEOUT_0_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_7_SHIFT 7 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_7_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_7_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_7_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_7_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_6_SHIFT 6 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_6_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_6_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_6_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_6_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_5_SHIFT 5 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_5_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_5_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_5_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_5_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_4_SHIFT 4 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_4_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_4_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_4_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_4_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_3_SHIFT 3 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_3_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_3_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_3_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_3_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_2_SHIFT 2 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_2_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_2_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_2_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_2_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_1_SHIFT 1 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_1_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_1_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_1_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_1_SHIFT)
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_0_SHIFT 0 /* established */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_0_MASK 0x1ull
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_0_INPLACE (UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_0_MASK << UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_PENDING_0_SHIFT)

/*
 * Header name UVH_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.
 */
/* lb_bau_intd_software_acknowledge_alias: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_ALIAS   0x320088 /* established */

/*
 * Header name UV1H_LB_TARGET_PHYSICAL_APIC_ID_MASK.
 */
/* lb_target_physical_apic_id_mask: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_LB_TARGET_PHYSICAL_APIC_ID_MASK          0x320130 /* established */
#define UV1_LB_TARGET_PHYSICAL_APIC_ID_MASK_BIT_ENABLES_SHIFT 0 /* established */
#define UV1_LB_TARGET_PHYSICAL_APIC_ID_MASK_BIT_ENABLES_MASK 0xffffffffull
#define UV1_LB_TARGET_PHYSICAL_APIC_ID_MASK_BIT_ENABLES_INPLACE (UV1_LB_TARGET_PHYSICAL_APIC_ID_MASK_BIT_ENABLES_MASK << UV1_LB_TARGET_PHYSICAL_APIC_ID_MASK_BIT_ENABLES_SHIFT)

/*
 * Header name UVH_LB_BAU_MISC_CONTROL. BAU mode control: software acknowledge mode, acknowledge timeout period and per-generation workarounds.
 */
/* lb_bau_misc_control: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_LB_BAU_MISC_CONTROL                      0x320170 /* established */
#define UV1_LB_BAU_MISC_CONTROL_FUN_SHIFT            48 /* established */
#define UV1_LB_BAU_MISC_CONTROL_FUN_MASK             0xffffull
#define UV1_LB_BAU_MISC_CONTROL_FUN_INPLACE          (UV1_LB_BAU_MISC_CONTROL_FUN_MASK << UV1_LB_BAU_MISC_CONTROL_FUN_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_ENABLE_PROGRAMMED_INITIAL_PRIORITY_SHIFT 28 /* established */
#define UV1_LB_BAU_MISC_CONTROL_ENABLE_PROGRAMMED_INITIAL_PRIORITY_MASK 0x1ull
#define UV1_LB_BAU_MISC_CONTROL_ENABLE_PROGRAMMED_INITIAL_PRIORITY_INPLACE (UV1_LB_BAU_MISC_CONTROL_ENABLE_PROGRAMMED_INITIAL_PRIORITY_MASK << UV1_LB_BAU_MISC_CONTROL_ENABLE_PROGRAMMED_INITIAL_PRIORITY_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_USE_INCOMING_PRIORITY_SHIFT 27 /* established */
#define UV1_LB_BAU_MISC_CONTROL_USE_INCOMING_PRIORITY_MASK 0x1ull
#define UV1_LB_BAU_MISC_CONTROL_USE_INCOMING_PRIORITY_INPLACE (UV1_LB_BAU_MISC_CONTROL_USE_INCOMING_PRIORITY_MASK << UV1_LB_BAU_MISC_CONTROL_USE_INCOMING_PRIORITY_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_PROGRAMMED_INITIAL_PRIORITY_SHIFT 24 /* established */
#define UV1_LB_BAU_MISC_CONTROL_PROGRAMMED_INITIAL_PRIORITY_MASK 0x7ull
#define UV1_LB_BAU_MISC_CONTROL_PROGRAMMED_INITIAL_PRIORITY_INPLACE (UV1_LB_BAU_MISC_CONTROL_PROGRAMMED_INITIAL_PRIORITY_MASK << UV1_LB_BAU_MISC_CONTROL_PROGRAMMED_INITIAL_PRIORITY_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_SUPPRESS_DEST_REGISTRATION_SHIFT 23 /* established */
#define UV1_LB_BAU_MISC_CONTROL_SUPPRESS_DEST_REGISTRATION_MASK 0x1ull
#define UV1_LB_BAU_MISC_CONTROL_SUPPRESS_DEST_REGISTRATION_INPLACE (UV1_LB_BAU_MISC_CONTROL_SUPPRESS_DEST_REGISTRATION_MASK << UV1_LB_BAU_MISC_CONTROL_SUPPRESS_DEST_REGISTRATION_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_VGA_IO_PORT_16_BIT_DECODE_SHIFT 22 /* established */
#define UV1_LB_BAU_MISC_CONTROL_VGA_IO_PORT_16_BIT_DECODE_MASK 0x1ull
#define UV1_LB_BAU_MISC_CONTROL_VGA_IO_PORT_16_BIT_DECODE_INPLACE (UV1_LB_BAU_MISC_CONTROL_VGA_IO_PORT_16_BIT_DECODE_MASK << UV1_LB_BAU_MISC_CONTROL_VGA_IO_PORT_16_BIT_DECODE_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_VGA_IO_PORT_DECODE_ENABLE_SHIFT 21 /* established */
#define UV1_LB_BAU_MISC_CONTROL_VGA_IO_PORT_DECODE_ENABLE_MASK 0x1ull
#define UV1_LB_BAU_MISC_CONTROL_VGA_IO_PORT_DECODE_ENABLE_INPLACE (UV1_LB_BAU_MISC_CONTROL_VGA_IO_PORT_DECODE_ENABLE_MASK << UV1_LB_BAU_MISC_CONTROL_VGA_IO_PORT_DECODE_ENABLE_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_ENABLE_DUAL_MAPPING_MODE_SHIFT 20 /* established */
#define UV1_LB_BAU_MISC_CONTROL_ENABLE_DUAL_MAPPING_MODE_MASK 0x1ull
#define UV1_LB_BAU_MISC_CONTROL_ENABLE_DUAL_MAPPING_MODE_INPLACE (UV1_LB_BAU_MISC_CONTROL_ENABLE_DUAL_MAPPING_MODE_MASK << UV1_LB_BAU_MISC_CONTROL_ENABLE_DUAL_MAPPING_MODE_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_INTD_SOFT_ACK_TIMEOUT_PERIOD_SHIFT 16 /* established */
#define UV1_LB_BAU_MISC_CONTROL_INTD_SOFT_ACK_TIMEOUT_PERIOD_MASK 0xfull
#define UV1_LB_BAU_MISC_CONTROL_INTD_SOFT_ACK_TIMEOUT_PERIOD_INPLACE (UV1_LB_BAU_MISC_CONTROL_INTD_SOFT_ACK_TIMEOUT_PERIOD_MASK << UV1_LB_BAU_MISC_CONTROL_INTD_SOFT_ACK_TIMEOUT_PERIOD_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_ENABLE_INTD_SOFT_ACK_MODE_SHIFT 15 /* established */
#define UV1_LB_BAU_MISC_CONTROL_ENABLE_INTD_SOFT_ACK_MODE_MASK 0x1ull
#define UV1_LB_BAU_MISC_CONTROL_ENABLE_INTD_SOFT_ACK_MODE_INPLACE (UV1_LB_BAU_MISC_CONTROL_ENABLE_INTD_SOFT_ACK_MODE_MASK << UV1_LB_BAU_MISC_CONTROL_ENABLE_INTD_SOFT_ACK_MODE_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_DESCRIPTOR_FETCH_MODE_SHIFT 14 /* established */
#define UV1_LB_BAU_MISC_CONTROL_DESCRIPTOR_FETCH_MODE_MASK 0x1ull
#define UV1_LB_BAU_MISC_CONTROL_DESCRIPTOR_FETCH_MODE_INPLACE (UV1_LB_BAU_MISC_CONTROL_DESCRIPTOR_FETCH_MODE_MASK << UV1_LB_BAU_MISC_CONTROL_DESCRIPTOR_FETCH_MODE_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_QPI_AGENT_PRESENCE_VECTOR_SHIFT 11 /* established */
#define UV1_LB_BAU_MISC_CONTROL_QPI_AGENT_PRESENCE_VECTOR_MASK 0x7ull
#define UV1_LB_BAU_MISC_CONTROL_QPI_AGENT_PRESENCE_VECTOR_INPLACE (UV1_LB_BAU_MISC_CONTROL_QPI_AGENT_PRESENCE_VECTOR_MASK << UV1_LB_BAU_MISC_CONTROL_QPI_AGENT_PRESENCE_VECTOR_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_FORCE_LOCK_NOP_SHIFT 10 /* established */
#define UV1_LB_BAU_MISC_CONTROL_FORCE_LOCK_NOP_MASK  0x1ull
#define UV1_LB_BAU_MISC_CONTROL_FORCE_LOCK_NOP_INPLACE (UV1_LB_BAU_MISC_CONTROL_FORCE_LOCK_NOP_MASK << UV1_LB_BAU_MISC_CONTROL_FORCE_LOCK_NOP_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_FORCE_BROADCAST_SHIFT 9 /* established */
#define UV1_LB_BAU_MISC_CONTROL_FORCE_BROADCAST_MASK 0x1ull
#define UV1_LB_BAU_MISC_CONTROL_FORCE_BROADCAST_INPLACE (UV1_LB_BAU_MISC_CONTROL_FORCE_BROADCAST_MASK << UV1_LB_BAU_MISC_CONTROL_FORCE_BROADCAST_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_APIC_MODE_SHIFT      8 /* established */
#define UV1_LB_BAU_MISC_CONTROL_APIC_MODE_MASK       0x1ull
#define UV1_LB_BAU_MISC_CONTROL_APIC_MODE_INPLACE    (UV1_LB_BAU_MISC_CONTROL_APIC_MODE_MASK << UV1_LB_BAU_MISC_CONTROL_APIC_MODE_SHIFT)
#define UV1_LB_BAU_MISC_CONTROL_REJECTION_DELAY_SHIFT 0 /* established */
#define UV1_LB_BAU_MISC_CONTROL_REJECTION_DELAY_MASK 0xffull
#define UV1_LB_BAU_MISC_CONTROL_REJECTION_DELAY_INPLACE (UV1_LB_BAU_MISC_CONTROL_REJECTION_DELAY_MASK << UV1_LB_BAU_MISC_CONTROL_REJECTION_DELAY_SHIFT)

/*
 * Header name UVH_RTC. Real-time clock counter, replicated across the cache lines of its page from UV2 on so sockets can read it in parallel.
 */
/* rtc: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RTC                                      0x340000 /* established */
#define UV1_RTC_REAL_TIME_CLOCK_SHIFT                0 /* established */
#define UV1_RTC_REAL_TIME_CLOCK_MASK                 0xffffffffffffffull
#define UV1_RTC_REAL_TIME_CLOCK_INPLACE              (UV1_RTC_REAL_TIME_CLOCK_MASK << UV1_RTC_REAL_TIME_CLOCK_SHIFT)

/*
 * Header name UVH_GR0_TLB_MMR_CONTROL.
 */
/* gr0_tlb_mmr_control: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_GR0_TLB_MMR_CONTROL                      0x401080 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBLRUV_SHIFT 60 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBLRUV_MASK 0x1ull
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBLRUV_INPLACE (UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBLRUV_MASK << UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBLRUV_SHIFT)
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBRREG_SHIFT 56 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBRREG_MASK 0x1ull
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBRREG_INPLACE (UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBRREG_MASK << UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBRREG_SHIFT)
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBPGSIZE_SHIFT 54 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBPGSIZE_MASK 0x1ull
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBPGSIZE_INPLACE (UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBPGSIZE_MASK << UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBPGSIZE_SHIFT)
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBRAM_SHIFT 52 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBRAM_MASK  0x1ull
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBRAM_INPLACE (UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBRAM_MASK << UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_TLBRAM_SHIFT)
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_CON_SHIFT    48 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_CON_MASK     0x1ull
#define UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_CON_INPLACE  (UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_CON_MASK << UV1_GR0_TLB_MMR_CONTROL_MMR_INJ_CON_SHIFT)
#define UV1_GR0_TLB_MMR_CONTROL_MMR_READ_SHIFT       31 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_MMR_READ_MASK        0x1ull
#define UV1_GR0_TLB_MMR_CONTROL_MMR_READ_INPLACE     (UV1_GR0_TLB_MMR_CONTROL_MMR_READ_MASK << UV1_GR0_TLB_MMR_CONTROL_MMR_READ_SHIFT)
#define UV1_GR0_TLB_MMR_CONTROL_MMR_WRITE_SHIFT      30 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_MMR_WRITE_MASK       0x1ull
#define UV1_GR0_TLB_MMR_CONTROL_MMR_WRITE_INPLACE    (UV1_GR0_TLB_MMR_CONTROL_MMR_WRITE_MASK << UV1_GR0_TLB_MMR_CONTROL_MMR_WRITE_SHIFT)
#define UV1_GR0_TLB_MMR_CONTROL_MMR_HASH_INDEX_EN_SHIFT 20 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_MMR_HASH_INDEX_EN_MASK 0x1ull
#define UV1_GR0_TLB_MMR_CONTROL_MMR_HASH_INDEX_EN_INPLACE (UV1_GR0_TLB_MMR_CONTROL_MMR_HASH_INDEX_EN_MASK << UV1_GR0_TLB_MMR_CONTROL_MMR_HASH_INDEX_EN_SHIFT)
#define UV1_GR0_TLB_MMR_CONTROL_AUTO_VALID_EN_SHIFT  16 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_AUTO_VALID_EN_MASK   0x1ull
#define UV1_GR0_TLB_MMR_CONTROL_AUTO_VALID_EN_INPLACE (UV1_GR0_TLB_MMR_CONTROL_AUTO_VALID_EN_MASK << UV1_GR0_TLB_MMR_CONTROL_AUTO_VALID_EN_SHIFT)
#define UV1_GR0_TLB_MMR_CONTROL_MEM_SEL_SHIFT        12 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_MEM_SEL_MASK         0x3ull
#define UV1_GR0_TLB_MMR_CONTROL_MEM_SEL_INPLACE      (UV1_GR0_TLB_MMR_CONTROL_MEM_SEL_MASK << UV1_GR0_TLB_MMR_CONTROL_MEM_SEL_SHIFT)
#define UV1_GR0_TLB_MMR_CONTROL_INDEX_SHIFT          0 /* established */
#define UV1_GR0_TLB_MMR_CONTROL_INDEX_MASK           0xfffull
#define UV1_GR0_TLB_MMR_CONTROL_INDEX_INPLACE        (UV1_GR0_TLB_MMR_CONTROL_INDEX_MASK << UV1_GR0_TLB_MMR_CONTROL_INDEX_SHIFT)

/*
 * Header name UVH_GR0_TLB_MMR_READ_DATA_HI.
 */
/* gr0_tlb_mmr_read_data_hi: r64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_GR0_TLB_MMR_READ_DATA_HI                 0x4010a0 /* established */
#define UV1_GR0_TLB_MMR_READ_DATA_HI_LARGER_SHIFT    44 /* established */
#define UV1_GR0_TLB_MMR_READ_DATA_HI_LARGER_MASK     0x1ull
#define UV1_GR0_TLB_MMR_READ_DATA_HI_LARGER_INPLACE  (UV1_GR0_TLB_MMR_READ_DATA_HI_LARGER_MASK << UV1_GR0_TLB_MMR_READ_DATA_HI_LARGER_SHIFT)
#define UV1_GR0_TLB_MMR_READ_DATA_HI_DIRTY_SHIFT     43 /* established */
#define UV1_GR0_TLB_MMR_READ_DATA_HI_DIRTY_MASK      0x1ull
#define UV1_GR0_TLB_MMR_READ_DATA_HI_DIRTY_INPLACE   (UV1_GR0_TLB_MMR_READ_DATA_HI_DIRTY_MASK << UV1_GR0_TLB_MMR_READ_DATA_HI_DIRTY_SHIFT)
#define UV1_GR0_TLB_MMR_READ_DATA_HI_GAA_SHIFT       41 /* established */
#define UV1_GR0_TLB_MMR_READ_DATA_HI_GAA_MASK        0x3ull
#define UV1_GR0_TLB_MMR_READ_DATA_HI_GAA_INPLACE     (UV1_GR0_TLB_MMR_READ_DATA_HI_GAA_MASK << UV1_GR0_TLB_MMR_READ_DATA_HI_GAA_SHIFT)
#define UV1_GR0_TLB_MMR_READ_DATA_HI_PFN_SHIFT       0 /* established */
#define UV1_GR0_TLB_MMR_READ_DATA_HI_PFN_MASK        0x1ffffffffffull
#define UV1_GR0_TLB_MMR_READ_DATA_HI_PFN_INPLACE     (UV1_GR0_TLB_MMR_READ_DATA_HI_PFN_MASK << UV1_GR0_TLB_MMR_READ_DATA_HI_PFN_SHIFT)

/*
 * Header name UVH_GR0_TLB_MMR_READ_DATA_LO.
 */
/* gr0_tlb_mmr_read_data_lo: r64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_GR0_TLB_MMR_READ_DATA_LO                 0x4010a8 /* established */
#define UV1_GR0_TLB_MMR_READ_DATA_LO_VALID_SHIFT     63 /* established */
#define UV1_GR0_TLB_MMR_READ_DATA_LO_VALID_MASK      0x1ull
#define UV1_GR0_TLB_MMR_READ_DATA_LO_VALID_INPLACE   (UV1_GR0_TLB_MMR_READ_DATA_LO_VALID_MASK << UV1_GR0_TLB_MMR_READ_DATA_LO_VALID_SHIFT)
#define UV1_GR0_TLB_MMR_READ_DATA_LO_ASID_SHIFT      39 /* established */
#define UV1_GR0_TLB_MMR_READ_DATA_LO_ASID_MASK       0xffffffull
#define UV1_GR0_TLB_MMR_READ_DATA_LO_ASID_INPLACE    (UV1_GR0_TLB_MMR_READ_DATA_LO_ASID_MASK << UV1_GR0_TLB_MMR_READ_DATA_LO_ASID_SHIFT)
#define UV1_GR0_TLB_MMR_READ_DATA_LO_VPN_SHIFT       0 /* established */
#define UV1_GR0_TLB_MMR_READ_DATA_LO_VPN_MASK        0x7fffffffffull
#define UV1_GR0_TLB_MMR_READ_DATA_LO_VPN_INPLACE     (UV1_GR0_TLB_MMR_READ_DATA_LO_VPN_MASK << UV1_GR0_TLB_MMR_READ_DATA_LO_VPN_SHIFT)

/*
 * Header name UVH_GR1_TLB_MMR_CONTROL.
 */
/* gr1_tlb_mmr_control: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_GR1_TLB_MMR_CONTROL                      0x801080 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBLRUV_SHIFT 60 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBLRUV_MASK 0x1ull
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBLRUV_INPLACE (UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBLRUV_MASK << UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBLRUV_SHIFT)
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBRREG_SHIFT 56 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBRREG_MASK 0x1ull
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBRREG_INPLACE (UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBRREG_MASK << UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBRREG_SHIFT)
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBPGSIZE_SHIFT 54 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBPGSIZE_MASK 0x1ull
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBPGSIZE_INPLACE (UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBPGSIZE_MASK << UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBPGSIZE_SHIFT)
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBRAM_SHIFT 52 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBRAM_MASK  0x1ull
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBRAM_INPLACE (UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBRAM_MASK << UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_TLBRAM_SHIFT)
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_CON_SHIFT    48 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_CON_MASK     0x1ull
#define UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_CON_INPLACE  (UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_CON_MASK << UV1_GR1_TLB_MMR_CONTROL_MMR_INJ_CON_SHIFT)
#define UV1_GR1_TLB_MMR_CONTROL_MMR_READ_SHIFT       31 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_MMR_READ_MASK        0x1ull
#define UV1_GR1_TLB_MMR_CONTROL_MMR_READ_INPLACE     (UV1_GR1_TLB_MMR_CONTROL_MMR_READ_MASK << UV1_GR1_TLB_MMR_CONTROL_MMR_READ_SHIFT)
#define UV1_GR1_TLB_MMR_CONTROL_MMR_WRITE_SHIFT      30 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_MMR_WRITE_MASK       0x1ull
#define UV1_GR1_TLB_MMR_CONTROL_MMR_WRITE_INPLACE    (UV1_GR1_TLB_MMR_CONTROL_MMR_WRITE_MASK << UV1_GR1_TLB_MMR_CONTROL_MMR_WRITE_SHIFT)
#define UV1_GR1_TLB_MMR_CONTROL_MMR_HASH_INDEX_EN_SHIFT 20 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_MMR_HASH_INDEX_EN_MASK 0x1ull
#define UV1_GR1_TLB_MMR_CONTROL_MMR_HASH_INDEX_EN_INPLACE (UV1_GR1_TLB_MMR_CONTROL_MMR_HASH_INDEX_EN_MASK << UV1_GR1_TLB_MMR_CONTROL_MMR_HASH_INDEX_EN_SHIFT)
#define UV1_GR1_TLB_MMR_CONTROL_AUTO_VALID_EN_SHIFT  16 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_AUTO_VALID_EN_MASK   0x1ull
#define UV1_GR1_TLB_MMR_CONTROL_AUTO_VALID_EN_INPLACE (UV1_GR1_TLB_MMR_CONTROL_AUTO_VALID_EN_MASK << UV1_GR1_TLB_MMR_CONTROL_AUTO_VALID_EN_SHIFT)
#define UV1_GR1_TLB_MMR_CONTROL_MEM_SEL_SHIFT        12 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_MEM_SEL_MASK         0x3ull
#define UV1_GR1_TLB_MMR_CONTROL_MEM_SEL_INPLACE      (UV1_GR1_TLB_MMR_CONTROL_MEM_SEL_MASK << UV1_GR1_TLB_MMR_CONTROL_MEM_SEL_SHIFT)
#define UV1_GR1_TLB_MMR_CONTROL_INDEX_SHIFT          0 /* established */
#define UV1_GR1_TLB_MMR_CONTROL_INDEX_MASK           0xfffull
#define UV1_GR1_TLB_MMR_CONTROL_INDEX_INPLACE        (UV1_GR1_TLB_MMR_CONTROL_INDEX_MASK << UV1_GR1_TLB_MMR_CONTROL_INDEX_SHIFT)

/*
 * Header name UVH_GR1_TLB_MMR_READ_DATA_HI.
 */
/* gr1_tlb_mmr_read_data_hi: r64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_GR1_TLB_MMR_READ_DATA_HI                 0x8010a0 /* established */
#define UV1_GR1_TLB_MMR_READ_DATA_HI_LARGER_SHIFT    44 /* established */
#define UV1_GR1_TLB_MMR_READ_DATA_HI_LARGER_MASK     0x1ull
#define UV1_GR1_TLB_MMR_READ_DATA_HI_LARGER_INPLACE  (UV1_GR1_TLB_MMR_READ_DATA_HI_LARGER_MASK << UV1_GR1_TLB_MMR_READ_DATA_HI_LARGER_SHIFT)
#define UV1_GR1_TLB_MMR_READ_DATA_HI_DIRTY_SHIFT     43 /* established */
#define UV1_GR1_TLB_MMR_READ_DATA_HI_DIRTY_MASK      0x1ull
#define UV1_GR1_TLB_MMR_READ_DATA_HI_DIRTY_INPLACE   (UV1_GR1_TLB_MMR_READ_DATA_HI_DIRTY_MASK << UV1_GR1_TLB_MMR_READ_DATA_HI_DIRTY_SHIFT)
#define UV1_GR1_TLB_MMR_READ_DATA_HI_GAA_SHIFT       41 /* established */
#define UV1_GR1_TLB_MMR_READ_DATA_HI_GAA_MASK        0x3ull
#define UV1_GR1_TLB_MMR_READ_DATA_HI_GAA_INPLACE     (UV1_GR1_TLB_MMR_READ_DATA_HI_GAA_MASK << UV1_GR1_TLB_MMR_READ_DATA_HI_GAA_SHIFT)
#define UV1_GR1_TLB_MMR_READ_DATA_HI_PFN_SHIFT       0 /* established */
#define UV1_GR1_TLB_MMR_READ_DATA_HI_PFN_MASK        0x1ffffffffffull
#define UV1_GR1_TLB_MMR_READ_DATA_HI_PFN_INPLACE     (UV1_GR1_TLB_MMR_READ_DATA_HI_PFN_MASK << UV1_GR1_TLB_MMR_READ_DATA_HI_PFN_SHIFT)

/*
 * Header name UVH_GR1_TLB_MMR_READ_DATA_LO.
 */
/* gr1_tlb_mmr_read_data_lo: r64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_GR1_TLB_MMR_READ_DATA_LO                 0x8010a8 /* established */
#define UV1_GR1_TLB_MMR_READ_DATA_LO_VALID_SHIFT     63 /* established */
#define UV1_GR1_TLB_MMR_READ_DATA_LO_VALID_MASK      0x1ull
#define UV1_GR1_TLB_MMR_READ_DATA_LO_VALID_INPLACE   (UV1_GR1_TLB_MMR_READ_DATA_LO_VALID_MASK << UV1_GR1_TLB_MMR_READ_DATA_LO_VALID_SHIFT)
#define UV1_GR1_TLB_MMR_READ_DATA_LO_ASID_SHIFT      39 /* established */
#define UV1_GR1_TLB_MMR_READ_DATA_LO_ASID_MASK       0xffffffull
#define UV1_GR1_TLB_MMR_READ_DATA_LO_ASID_INPLACE    (UV1_GR1_TLB_MMR_READ_DATA_LO_ASID_MASK << UV1_GR1_TLB_MMR_READ_DATA_LO_ASID_SHIFT)
#define UV1_GR1_TLB_MMR_READ_DATA_LO_VPN_SHIFT       0 /* established */
#define UV1_GR1_TLB_MMR_READ_DATA_LO_VPN_MASK        0x7fffffffffull
#define UV1_GR1_TLB_MMR_READ_DATA_LO_VPN_INPLACE     (UV1_GR1_TLB_MMR_READ_DATA_LO_VPN_MASK << UV1_GR1_TLB_MMR_READ_DATA_LO_VPN_SHIFT)

/*
 * Header name UVH_RH_GAM_ADDR_MAP_CONFIG. Address map shape: number of node-offset (m) and node-number (n) bits.
 */
/* rh_gam_addr_map_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RH_GAM_ADDR_MAP_CONFIG                   0x1600000 /* established */
#define UV1_RH_GAM_ADDR_MAP_CONFIG_MMIOL_CFG_SHIFT   12 /* established */
#define UV1_RH_GAM_ADDR_MAP_CONFIG_MMIOL_CFG_MASK    0x1ull
#define UV1_RH_GAM_ADDR_MAP_CONFIG_MMIOL_CFG_INPLACE (UV1_RH_GAM_ADDR_MAP_CONFIG_MMIOL_CFG_MASK << UV1_RH_GAM_ADDR_MAP_CONFIG_MMIOL_CFG_SHIFT)
#define UV1_RH_GAM_ADDR_MAP_CONFIG_N_SKT_SHIFT       6 /* established */
#define UV1_RH_GAM_ADDR_MAP_CONFIG_N_SKT_MASK        0xfull
#define UV1_RH_GAM_ADDR_MAP_CONFIG_N_SKT_INPLACE     (UV1_RH_GAM_ADDR_MAP_CONFIG_N_SKT_MASK << UV1_RH_GAM_ADDR_MAP_CONFIG_N_SKT_SHIFT)
#define UV1_RH_GAM_ADDR_MAP_CONFIG_M_SKT_SHIFT       0 /* established */
#define UV1_RH_GAM_ADDR_MAP_CONFIG_M_SKT_MASK        0x3full
#define UV1_RH_GAM_ADDR_MAP_CONFIG_M_SKT_INPLACE     (UV1_RH_GAM_ADDR_MAP_CONFIG_M_SKT_MASK << UV1_RH_GAM_ADDR_MAP_CONFIG_M_SKT_SHIFT)

/*
 * Header name UVH_RH_GAM_GRU_OVERLAY_CONFIG. Base and enable of the GRU window.
 */
/* rh_gam_gru_overlay_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG                0x1600010 /* established */
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_ENABLE_SHIFT   63 /* established */
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_ENABLE_MASK    0x1ull
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_ENABLE_INPLACE (UV1_RH_GAM_GRU_OVERLAY_CONFIG_ENABLE_MASK << UV1_RH_GAM_GRU_OVERLAY_CONFIG_ENABLE_SHIFT)
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_N_GRU_SHIFT    52 /* established */
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_N_GRU_MASK     0xfull
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_N_GRU_INPLACE  (UV1_RH_GAM_GRU_OVERLAY_CONFIG_N_GRU_MASK << UV1_RH_GAM_GRU_OVERLAY_CONFIG_N_GRU_SHIFT)
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_GR4_SHIFT      48 /* established */
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_GR4_MASK       0x1ull
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_GR4_INPLACE    (UV1_RH_GAM_GRU_OVERLAY_CONFIG_GR4_MASK << UV1_RH_GAM_GRU_OVERLAY_CONFIG_GR4_SHIFT)
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_BASE_SHIFT     28 /* established */
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_BASE_MASK      0x3ffffull
#define UV1_RH_GAM_GRU_OVERLAY_CONFIG_BASE_INPLACE   (UV1_RH_GAM_GRU_OVERLAY_CONFIG_BASE_MASK << UV1_RH_GAM_GRU_OVERLAY_CONFIG_BASE_SHIFT)

/*
 * Header name UVH_RH_GAM_MMR_OVERLAY_CONFIG. Base and enable of the global MMR window.
 */
/* rh_gam_mmr_overlay_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RH_GAM_MMR_OVERLAY_CONFIG                0x1600028 /* established */
#define UV1_RH_GAM_MMR_OVERLAY_CONFIG_ENABLE_SHIFT   63 /* established */
#define UV1_RH_GAM_MMR_OVERLAY_CONFIG_ENABLE_MASK    0x1ull
#define UV1_RH_GAM_MMR_OVERLAY_CONFIG_ENABLE_INPLACE (UV1_RH_GAM_MMR_OVERLAY_CONFIG_ENABLE_MASK << UV1_RH_GAM_MMR_OVERLAY_CONFIG_ENABLE_SHIFT)
#define UV1_RH_GAM_MMR_OVERLAY_CONFIG_DUAL_HUB_SHIFT 46 /* established */
#define UV1_RH_GAM_MMR_OVERLAY_CONFIG_DUAL_HUB_MASK  0x1ull
#define UV1_RH_GAM_MMR_OVERLAY_CONFIG_DUAL_HUB_INPLACE (UV1_RH_GAM_MMR_OVERLAY_CONFIG_DUAL_HUB_MASK << UV1_RH_GAM_MMR_OVERLAY_CONFIG_DUAL_HUB_SHIFT)
#define UV1_RH_GAM_MMR_OVERLAY_CONFIG_BASE_SHIFT     26 /* established */
#define UV1_RH_GAM_MMR_OVERLAY_CONFIG_BASE_MASK      0xfffffull
#define UV1_RH_GAM_MMR_OVERLAY_CONFIG_BASE_INPLACE   (UV1_RH_GAM_MMR_OVERLAY_CONFIG_BASE_MASK << UV1_RH_GAM_MMR_OVERLAY_CONFIG_BASE_SHIFT)

/*
 * Header name UVH_RH_GAM_MMIOH_OVERLAY_CONFIG.
 */
/* rh_gam_mmioh_overlay_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG              0x1600030 /* established */
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_ENABLE_SHIFT 63 /* established */
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_ENABLE_MASK  0x1ull
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_ENABLE_INPLACE (UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_ENABLE_MASK << UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_ENABLE_SHIFT)
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_N_IO_SHIFT   52 /* established */
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_N_IO_MASK    0xfull
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_N_IO_INPLACE (UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_N_IO_MASK << UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_N_IO_SHIFT)
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_M_IO_SHIFT   46 /* established */
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_M_IO_MASK    0x3full
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_M_IO_INPLACE (UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_M_IO_MASK << UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_M_IO_SHIFT)
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_BASE_SHIFT   30 /* established */
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_BASE_MASK    0xffffull
#define UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_BASE_INPLACE (UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_BASE_MASK << UV1_RH_GAM_MMIOH_OVERLAY_CONFIG_BASE_SHIFT)

/*
 * Header name UVH_RH_GAM_ALIAS_0_OVERLAY_CONFIG.
 */
/* rh_gam_alias_0_overlay_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG            0x16000c8 /* established */
#define UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_ENABLE_SHIFT 63 /* established */
#define UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_ENABLE_MASK 0x1ull
#define UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_ENABLE_INPLACE (UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_ENABLE_MASK << UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_ENABLE_SHIFT)
#define UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_M_ALIAS_SHIFT 48 /* established */
#define UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_M_ALIAS_MASK 0x1full
#define UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_M_ALIAS_INPLACE (UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_M_ALIAS_MASK << UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_M_ALIAS_SHIFT)
#define UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_BASE_SHIFT 24 /* established */
#define UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_BASE_MASK  0xffull
#define UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_BASE_INPLACE (UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_BASE_MASK << UV1_RH_GAM_ALIAS_0_OVERLAY_CONFIG_BASE_SHIFT)

/*
 * Header name UVH_RH_GAM_ALIAS_0_REDIRECT_CONFIG.
 */
/* rh_gam_alias_0_redirect_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RH_GAM_ALIAS_0_REDIRECT_CONFIG           0x16000d0 /* established */
#define UV1_RH_GAM_ALIAS_0_REDIRECT_CONFIG_DEST_BASE_SHIFT 24 /* established */
#define UV1_RH_GAM_ALIAS_0_REDIRECT_CONFIG_DEST_BASE_MASK 0x3fffffull
#define UV1_RH_GAM_ALIAS_0_REDIRECT_CONFIG_DEST_BASE_INPLACE (UV1_RH_GAM_ALIAS_0_REDIRECT_CONFIG_DEST_BASE_MASK << UV1_RH_GAM_ALIAS_0_REDIRECT_CONFIG_DEST_BASE_SHIFT)

/*
 * Header name UVH_RH_GAM_ALIAS_1_OVERLAY_CONFIG.
 */
/* rh_gam_alias_1_overlay_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG            0x16000d8 /* established */
#define UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_ENABLE_SHIFT 63 /* established */
#define UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_ENABLE_MASK 0x1ull
#define UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_ENABLE_INPLACE (UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_ENABLE_MASK << UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_ENABLE_SHIFT)
#define UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_M_ALIAS_SHIFT 48 /* established */
#define UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_M_ALIAS_MASK 0x1full
#define UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_M_ALIAS_INPLACE (UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_M_ALIAS_MASK << UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_M_ALIAS_SHIFT)
#define UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_BASE_SHIFT 24 /* established */
#define UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_BASE_MASK  0xffull
#define UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_BASE_INPLACE (UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_BASE_MASK << UV1_RH_GAM_ALIAS_1_OVERLAY_CONFIG_BASE_SHIFT)

/*
 * Header name UVH_RH_GAM_ALIAS_1_REDIRECT_CONFIG.
 */
/* rh_gam_alias_1_redirect_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RH_GAM_ALIAS_1_REDIRECT_CONFIG           0x16000e0 /* established */
#define UV1_RH_GAM_ALIAS_1_REDIRECT_CONFIG_DEST_BASE_SHIFT 24 /* established */
#define UV1_RH_GAM_ALIAS_1_REDIRECT_CONFIG_DEST_BASE_MASK 0x3fffffull
#define UV1_RH_GAM_ALIAS_1_REDIRECT_CONFIG_DEST_BASE_INPLACE (UV1_RH_GAM_ALIAS_1_REDIRECT_CONFIG_DEST_BASE_MASK << UV1_RH_GAM_ALIAS_1_REDIRECT_CONFIG_DEST_BASE_SHIFT)

/*
 * Header name UVH_RH_GAM_ALIAS_2_OVERLAY_CONFIG.
 */
/* rh_gam_alias_2_overlay_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG            0x16000e8 /* established */
#define UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_ENABLE_SHIFT 63 /* established */
#define UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_ENABLE_MASK 0x1ull
#define UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_ENABLE_INPLACE (UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_ENABLE_MASK << UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_ENABLE_SHIFT)
#define UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_M_ALIAS_SHIFT 48 /* established */
#define UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_M_ALIAS_MASK 0x1full
#define UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_M_ALIAS_INPLACE (UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_M_ALIAS_MASK << UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_M_ALIAS_SHIFT)
#define UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_BASE_SHIFT 24 /* established */
#define UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_BASE_MASK  0xffull
#define UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_BASE_INPLACE (UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_BASE_MASK << UV1_RH_GAM_ALIAS_2_OVERLAY_CONFIG_BASE_SHIFT)

/*
 * Header name UVH_RH_GAM_ALIAS_2_REDIRECT_CONFIG.
 */
/* rh_gam_alias_2_redirect_config: rw64, reset unknown; Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header */
#define UV1_RH_GAM_ALIAS_2_REDIRECT_CONFIG           0x16000f0 /* established */
#define UV1_RH_GAM_ALIAS_2_REDIRECT_CONFIG_DEST_BASE_SHIFT 24 /* established */
#define UV1_RH_GAM_ALIAS_2_REDIRECT_CONFIG_DEST_BASE_MASK 0x3fffffull
#define UV1_RH_GAM_ALIAS_2_REDIRECT_CONFIG_DEST_BASE_INPLACE (UV1_RH_GAM_ALIAS_2_REDIRECT_CONFIG_DEST_BASE_MASK << UV1_RH_GAM_ALIAS_2_REDIRECT_CONFIG_DEST_BASE_SHIFT)

#endif /* UV1_GEN_H */
