/* generated from devices/uv_gru/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 3 */
/* input sha256 9fd998eb93a63f0428f5eca34e50f2c7058b2d23a787c4039f35569109e1a020 */
/* UV global reference unit (GRU): chiplet memory map, handles and instruction
 * word */
#ifndef UV_GRU_GEN_H
#define UV_GRU_GEN_H

#include <stdint.h>


/*
 * Control block extended handle, dword 7: the hardware's view of the active
 * control block.
 */
/* word CBE_DW7: 64 bits */
#define UV_GRU_CBE_DW7_WIDTH                         64 /* inferred */
#define UV_GRU_CBE_DW7_CBREXECSTATUS_SHIFT           56 /* inferred */
#define UV_GRU_CBE_DW7_CBREXECSTATUS_MASK            0xffull
#define UV_GRU_CBE_DW7_CBREXECSTATUS_INPLACE (UV_GRU_CBE_DW7_CBREXECSTATUS_MASK << UV_GRU_CBE_DW7_CBREXECSTATUS_SHIFT)
#define UV_GRU_CBE_DW7_CBRSTATE_SHIFT                52 /* inferred */
#define UV_GRU_CBE_DW7_CBRSTATE_MASK                 0xfull
#define UV_GRU_CBE_DW7_CBRSTATE_INPLACE (UV_GRU_CBE_DW7_CBRSTATE_MASK << UV_GRU_CBE_DW7_CBRSTATE_SHIFT)
#define UV_GRU_CBE_DW7_ECAUSE_SHIFT                  32 /* inferred */
#define UV_GRU_CBE_DW7_ECAUSE_MASK                   0xfffffull
#define UV_GRU_CBE_DW7_ECAUSE_INPLACE (UV_GRU_CBE_DW7_ECAUSE_MASK << UV_GRU_CBE_DW7_ECAUSE_SHIFT)

/*
 * First dword of a control block (the instruction word). Software fills dwords
 * 1 to 7 first, then stores this one with the start bit set and flushes the
 * line; the hardware overwrites status and substatus on completion. Positions
 * agree with the driver's own shift macros for the low fields; the high fields
 * follow the bitfield order.
 */
/* word CB_DW0: 64 bits */
#define UV_GRU_CB_DW0_WIDTH                          64 /* established */
#define UV_GRU_CB_DW0_TLB_FAULT_COLOR_SHIFT          63 /* inferred */
#define UV_GRU_CB_DW0_TLB_FAULT_COLOR_MASK           0x1ull
#define UV_GRU_CB_DW0_TLB_FAULT_COLOR_INPLACE (UV_GRU_CB_DW0_TLB_FAULT_COLOR_MASK << UV_GRU_CB_DW0_TLB_FAULT_COLOR_SHIFT)
#define UV_GRU_CB_DW0_ISUBSTATUS_SHIFT               58 /* inferred */
#define UV_GRU_CB_DW0_ISUBSTATUS_MASK                0xfull
#define UV_GRU_CB_DW0_ISUBSTATUS_INPLACE (UV_GRU_CB_DW0_ISUBSTATUS_MASK << UV_GRU_CB_DW0_ISUBSTATUS_SHIFT)
#define UV_GRU_CB_DW0_ISTATUS_SHIFT                  56 /* established */
#define UV_GRU_CB_DW0_ISTATUS_MASK                   0x3ull
#define UV_GRU_CB_DW0_ISTATUS_INPLACE (UV_GRU_CB_DW0_ISTATUS_MASK << UV_GRU_CB_DW0_ISTATUS_SHIFT)
#define UV_GRU_CB_DW0_TRI0_SHIFT                     32 /* inferred */
#define UV_GRU_CB_DW0_TRI0_MASK                      0x3fffffull
#define UV_GRU_CB_DW0_TRI0_INPLACE (UV_GRU_CB_DW0_TRI0_MASK << UV_GRU_CB_DW0_TRI0_SHIFT)
#define UV_GRU_CB_DW0_EXOPC_SHIFT                    24 /* established */
#define UV_GRU_CB_DW0_EXOPC_MASK                     0xffull
#define UV_GRU_CB_DW0_EXOPC_INPLACE (UV_GRU_CB_DW0_EXOPC_MASK << UV_GRU_CB_DW0_EXOPC_SHIFT)
#define UV_GRU_CB_DW0_OPC_SHIFT                      16 /* established */
#define UV_GRU_CB_DW0_OPC_MASK                       0xffull
#define UV_GRU_CB_DW0_OPC_INPLACE (UV_GRU_CB_DW0_OPC_MASK << UV_GRU_CB_DW0_OPC_SHIFT)
#define UV_GRU_CB_DW0_IAA1_SHIFT                     13 /* established */
#define UV_GRU_CB_DW0_IAA1_MASK                      0x3ull
#define UV_GRU_CB_DW0_IAA1_INPLACE (UV_GRU_CB_DW0_IAA1_MASK << UV_GRU_CB_DW0_IAA1_SHIFT)
#define UV_GRU_CB_DW0_IAA0_SHIFT                     11 /* established */
#define UV_GRU_CB_DW0_IAA0_MASK                      0x3ull
#define UV_GRU_CB_DW0_IAA0_INPLACE (UV_GRU_CB_DW0_IAA0_MASK << UV_GRU_CB_DW0_IAA0_SHIFT)
#define UV_GRU_CB_DW0_XTYPE_SHIFT                    8 /* established */
#define UV_GRU_CB_DW0_XTYPE_MASK                     0x7ull
#define UV_GRU_CB_DW0_XTYPE_INPLACE (UV_GRU_CB_DW0_XTYPE_MASK << UV_GRU_CB_DW0_XTYPE_SHIFT)
#define UV_GRU_CB_DW0_IMA_SHIFT                      1 /* established */
#define UV_GRU_CB_DW0_IMA_MASK                       0x7ull
#define UV_GRU_CB_DW0_IMA_INPLACE (UV_GRU_CB_DW0_IMA_MASK << UV_GRU_CB_DW0_IMA_SHIFT)
#define UV_GRU_CB_DW0_ICMD_SHIFT                     0 /* established */
#define UV_GRU_CB_DW0_ICMD_MASK                      0x1ull
#define UV_GRU_CB_DW0_ICMD_INPLACE (UV_GRU_CB_DW0_ICMD_MASK << UV_GRU_CB_DW0_ICMD_SHIFT)

/*
 * Context configuration handle, dword 0: allocates control blocks and data
 * segment to a context and routes its interrupts. Dword 1 is the control block
 * allocation map, dwords 2 to 5 the eight address space ids, dwords 6 and 7 the
 * eight page size availability masks.
 */
/* word CCH_DW0: 64 bits */
#define UV_GRU_CCH_DW0_WIDTH                         64 /* inferred */
#define UV_GRU_CCH_DW0_DSR_ALLOCATION_MAP_SHIFT      32 /* inferred */
#define UV_GRU_CCH_DW0_DSR_ALLOCATION_MAP_MASK       0xffffffffull
#define UV_GRU_CCH_DW0_DSR_ALLOCATION_MAP_INPLACE (UV_GRU_CCH_DW0_DSR_ALLOCATION_MAP_MASK << UV_GRU_CCH_DW0_DSR_ALLOCATION_MAP_SHIFT)
#define UV_GRU_CCH_DW0_TFM_DONE_BIT_ENABLE_SHIFT     28 /* inferred */
#define UV_GRU_CCH_DW0_TFM_DONE_BIT_ENABLE_MASK      0x1ull
#define UV_GRU_CCH_DW0_TFM_DONE_BIT_ENABLE_INPLACE (UV_GRU_CCH_DW0_TFM_DONE_BIT_ENABLE_MASK << UV_GRU_CCH_DW0_TFM_DONE_BIT_ENABLE_SHIFT)
#define UV_GRU_CCH_DW0_CAUSE_SHIFT                   24 /* inferred */
#define UV_GRU_CCH_DW0_CAUSE_MASK                    0xfull
#define UV_GRU_CCH_DW0_CAUSE_INPLACE (UV_GRU_CCH_DW0_CAUSE_MASK << UV_GRU_CCH_DW0_CAUSE_SHIFT)
#define UV_GRU_CCH_DW0_STATE_SHIFT                   18 /* inferred */
#define UV_GRU_CCH_DW0_STATE_MASK                    0x3ull
#define UV_GRU_CCH_DW0_STATE_INPLACE (UV_GRU_CCH_DW0_STATE_MASK << UV_GRU_CCH_DW0_STATE_SHIFT)
#define UV_GRU_CCH_DW0_STATUS_SHIFT                  16 /* inferred */
#define UV_GRU_CCH_DW0_STATUS_MASK                   0x3ull
#define UV_GRU_CCH_DW0_STATUS_INPLACE (UV_GRU_CCH_DW0_STATUS_MASK << UV_GRU_CCH_DW0_STATUS_SHIFT)
#define UV_GRU_CCH_DW0_TLB_INT_SELECT_SHIFT          12 /* inferred */
#define UV_GRU_CCH_DW0_TLB_INT_SELECT_MASK           0xfull
#define UV_GRU_CCH_DW0_TLB_INT_SELECT_INPLACE (UV_GRU_CCH_DW0_TLB_INT_SELECT_MASK << UV_GRU_CCH_DW0_TLB_INT_SELECT_SHIFT)
#define UV_GRU_CCH_DW0_TFM_FAULT_BIT_ENABLE_SHIFT    11 /* inferred */
#define UV_GRU_CCH_DW0_TFM_FAULT_BIT_ENABLE_MASK     0x1ull
#define UV_GRU_CCH_DW0_TFM_FAULT_BIT_ENABLE_INPLACE (UV_GRU_CCH_DW0_TFM_FAULT_BIT_ENABLE_MASK << UV_GRU_CCH_DW0_TFM_FAULT_BIT_ENABLE_SHIFT)
#define UV_GRU_CCH_DW0_TLB_INT_ENABLE_SHIFT          10 /* inferred */
#define UV_GRU_CCH_DW0_TLB_INT_ENABLE_MASK           0x1ull
#define UV_GRU_CCH_DW0_TLB_INT_ENABLE_INPLACE (UV_GRU_CCH_DW0_TLB_INT_ENABLE_MASK << UV_GRU_CCH_DW0_TLB_INT_ENABLE_SHIFT)
#define UV_GRU_CCH_DW0_CB_INT_ENABLE_SHIFT           9 /* inferred */
#define UV_GRU_CCH_DW0_CB_INT_ENABLE_MASK            0x1ull
#define UV_GRU_CCH_DW0_CB_INT_ENABLE_INPLACE (UV_GRU_CCH_DW0_CB_INT_ENABLE_MASK << UV_GRU_CCH_DW0_CB_INT_ENABLE_SHIFT)
#define UV_GRU_CCH_DW0_REQ_SLICE_SHIFT               7 /* inferred */
#define UV_GRU_CCH_DW0_REQ_SLICE_MASK                0x3ull
#define UV_GRU_CCH_DW0_REQ_SLICE_INPLACE (UV_GRU_CCH_DW0_REQ_SLICE_MASK << UV_GRU_CCH_DW0_REQ_SLICE_SHIFT)
#define UV_GRU_CCH_DW0_REQ_SLICE_SET_ENABLE_SHIFT    6 /* inferred */
#define UV_GRU_CCH_DW0_REQ_SLICE_SET_ENABLE_MASK     0x1ull
#define UV_GRU_CCH_DW0_REQ_SLICE_SET_ENABLE_INPLACE (UV_GRU_CCH_DW0_REQ_SLICE_SET_ENABLE_MASK << UV_GRU_CCH_DW0_REQ_SLICE_SET_ENABLE_SHIFT)
#define UV_GRU_CCH_DW0_UNMAP_ENABLE_SHIFT            5 /* inferred */
#define UV_GRU_CCH_DW0_UNMAP_ENABLE_MASK             0x1ull
#define UV_GRU_CCH_DW0_UNMAP_ENABLE_INPLACE (UV_GRU_CCH_DW0_UNMAP_ENABLE_MASK << UV_GRU_CCH_DW0_UNMAP_ENABLE_SHIFT)
#define UV_GRU_CCH_DW0_OPC_SHIFT                     2 /* inferred */
#define UV_GRU_CCH_DW0_OPC_MASK                      0x7ull
#define UV_GRU_CCH_DW0_OPC_INPLACE (UV_GRU_CCH_DW0_OPC_MASK << UV_GRU_CCH_DW0_OPC_SHIFT)
#define UV_GRU_CCH_DW0_DELRESP_SHIFT                 1 /* inferred */
#define UV_GRU_CCH_DW0_DELRESP_MASK                  0x1ull
#define UV_GRU_CCH_DW0_DELRESP_INPLACE (UV_GRU_CCH_DW0_DELRESP_MASK << UV_GRU_CCH_DW0_DELRESP_SHIFT)
#define UV_GRU_CCH_DW0_CMD_SHIFT                     0 /* inferred */
#define UV_GRU_CCH_DW0_CMD_MASK                      0x1ull
#define UV_GRU_CCH_DW0_CMD_INPLACE (UV_GRU_CCH_DW0_CMD_MASK << UV_GRU_CCH_DW0_CMD_SHIFT)

/*
 * TLB fault handle, dword 0. The OS reads the cause here after a TLB miss and
 * issues an opcode to fill the TLB.
 */
/* word TFH_DW0: 64 bits */
#define UV_GRU_TFH_DW0_WIDTH                         64 /* inferred */
#define UV_GRU_TFH_DW0_CTXNUM_SHIFT                  48 /* inferred */
#define UV_GRU_TFH_DW0_CTXNUM_MASK                   0xfull
#define UV_GRU_TFH_DW0_CTXNUM_INPLACE (UV_GRU_TFH_DW0_CTXNUM_MASK << UV_GRU_TFH_DW0_CTXNUM_SHIFT)
#define UV_GRU_TFH_DW0_INDEXWAY_SHIFT                32 /* inferred */
#define UV_GRU_TFH_DW0_INDEXWAY_MASK                 0xfffull
#define UV_GRU_TFH_DW0_INDEXWAY_INPLACE (UV_GRU_TFH_DW0_INDEXWAY_MASK << UV_GRU_TFH_DW0_INDEXWAY_SHIFT)
#define UV_GRU_TFH_DW0_CB_INT_SHIFT                  30 /* inferred */
#define UV_GRU_TFH_DW0_CB_INT_MASK                   0x1ull
#define UV_GRU_TFH_DW0_CB_INT_INPLACE (UV_GRU_TFH_DW0_CB_INT_MASK << UV_GRU_TFH_DW0_CB_INT_SHIFT)
#define UV_GRU_TFH_DW0_CAUSE_SHIFT                   24 /* inferred */
#define UV_GRU_TFH_DW0_CAUSE_MASK                    0x3full
#define UV_GRU_TFH_DW0_CAUSE_INPLACE (UV_GRU_TFH_DW0_CAUSE_MASK << UV_GRU_TFH_DW0_CAUSE_SHIFT)
#define UV_GRU_TFH_DW0_STATE_SHIFT                   20 /* inferred */
#define UV_GRU_TFH_DW0_STATE_MASK                    0x7ull
#define UV_GRU_TFH_DW0_STATE_INPLACE (UV_GRU_TFH_DW0_STATE_MASK << UV_GRU_TFH_DW0_STATE_SHIFT)
#define UV_GRU_TFH_DW0_STATUS_SHIFT                  16 /* inferred */
#define UV_GRU_TFH_DW0_STATUS_MASK                   0x3ull
#define UV_GRU_TFH_DW0_STATUS_INPLACE (UV_GRU_TFH_DW0_STATUS_MASK << UV_GRU_TFH_DW0_STATUS_SHIFT)
#define UV_GRU_TFH_DW0_OPC_SHIFT                     4 /* inferred */
#define UV_GRU_TFH_DW0_OPC_MASK                      0x7ull
#define UV_GRU_TFH_DW0_OPC_INPLACE (UV_GRU_TFH_DW0_OPC_MASK << UV_GRU_TFH_DW0_OPC_SHIFT)
#define UV_GRU_TFH_DW0_DELRESP_SHIFT                 1 /* inferred */
#define UV_GRU_TFH_DW0_DELRESP_MASK                  0x1ull
#define UV_GRU_TFH_DW0_DELRESP_INPLACE (UV_GRU_TFH_DW0_DELRESP_MASK << UV_GRU_TFH_DW0_DELRESP_SHIFT)
#define UV_GRU_TFH_DW0_CMD_SHIFT                     0 /* inferred */
#define UV_GRU_TFH_DW0_CMD_MASK                      0x1ull
#define UV_GRU_TFH_DW0_CMD_INPLACE (UV_GRU_TFH_DW0_CMD_MASK << UV_GRU_TFH_DW0_CMD_SHIFT)

/*
 * TLB fault handle, dword 2: the missing address space id on read, the fill
 * address space id and attributes on write.
 */
/* word TFH_DW2: 64 bits */
#define UV_GRU_TFH_DW2_WIDTH                         64 /* inferred */
#define UV_GRU_TFH_DW2_GAA_SHIFT                     57 /* inferred */
#define UV_GRU_TFH_DW2_GAA_MASK                      0x3ull
#define UV_GRU_TFH_DW2_GAA_INPLACE (UV_GRU_TFH_DW2_GAA_MASK << UV_GRU_TFH_DW2_GAA_SHIFT)
#define UV_GRU_TFH_DW2_DIRTY_SHIFT                   56 /* inferred */
#define UV_GRU_TFH_DW2_DIRTY_MASK                    0x1ull
#define UV_GRU_TFH_DW2_DIRTY_INPLACE (UV_GRU_TFH_DW2_DIRTY_MASK << UV_GRU_TFH_DW2_DIRTY_SHIFT)
#define UV_GRU_TFH_DW2_FILLASID_SHIFT                32 /* inferred */
#define UV_GRU_TFH_DW2_FILLASID_MASK                 0xffffffull
#define UV_GRU_TFH_DW2_FILLASID_INPLACE (UV_GRU_TFH_DW2_FILLASID_MASK << UV_GRU_TFH_DW2_FILLASID_SHIFT)
#define UV_GRU_TFH_DW2_MISSASID_SHIFT                0 /* inferred */
#define UV_GRU_TFH_DW2_MISSASID_MASK                 0xffffffull
#define UV_GRU_TFH_DW2_MISSASID_INPLACE (UV_GRU_TFH_DW2_MISSASID_MASK << UV_GRU_TFH_DW2_MISSASID_SHIFT)

/*
 * TLB fault handle, dword 3: page frame and page size of the entry to write.
 * Dword 1 holds the missing virtual address, dword 4 the virtual address to
 * fill.
 */
/* word TFH_DW3: 64 bits */
#define UV_GRU_TFH_DW3_WIDTH                         64 /* inferred */
#define UV_GRU_TFH_DW3_PAGESIZE_SHIFT                48 /* inferred */
#define UV_GRU_TFH_DW3_PAGESIZE_MASK                 0x1full
#define UV_GRU_TFH_DW3_PAGESIZE_INPLACE (UV_GRU_TFH_DW3_PAGESIZE_MASK << UV_GRU_TFH_DW3_PAGESIZE_SHIFT)
#define UV_GRU_TFH_DW3_PFN_SHIFT                     0 /* inferred */
#define UV_GRU_TFH_DW3_PFN_MASK                      0x1ffffffffffull
#define UV_GRU_TFH_DW3_PFN_INPLACE (UV_GRU_TFH_DW3_PFN_MASK << UV_GRU_TFH_DW3_PFN_SHIFT)

/*
 * TLB global handle, dword 0: used to flush GRU TLB entries after the kernel
 * changes a mapping. Dword 1 is the virtual address, dword 4 the context
 * bitmap.
 */
/* word TGH_DW0: 64 bits */
#define UV_GRU_TGH_DW0_WIDTH                         64 /* inferred */
#define UV_GRU_TGH_DW0_CAUSE_SHIFT                   24 /* inferred */
#define UV_GRU_TGH_DW0_CAUSE_MASK                    0x7ull
#define UV_GRU_TGH_DW0_CAUSE_INPLACE (UV_GRU_TGH_DW0_CAUSE_MASK << UV_GRU_TGH_DW0_CAUSE_SHIFT)
#define UV_GRU_TGH_DW0_STATE_SHIFT                   20 /* inferred */
#define UV_GRU_TGH_DW0_STATE_MASK                    0x7ull
#define UV_GRU_TGH_DW0_STATE_INPLACE (UV_GRU_TGH_DW0_STATE_MASK << UV_GRU_TGH_DW0_STATE_SHIFT)
#define UV_GRU_TGH_DW0_STATUS_SHIFT                  16 /* inferred */
#define UV_GRU_TGH_DW0_STATUS_MASK                   0x3ull
#define UV_GRU_TGH_DW0_STATUS_INPLACE (UV_GRU_TGH_DW0_STATUS_MASK << UV_GRU_TGH_DW0_STATUS_SHIFT)
#define UV_GRU_TGH_DW0_OPC_SHIFT                     2 /* inferred */
#define UV_GRU_TGH_DW0_OPC_MASK                      0x1ull
#define UV_GRU_TGH_DW0_OPC_INPLACE (UV_GRU_TGH_DW0_OPC_MASK << UV_GRU_TGH_DW0_OPC_SHIFT)
#define UV_GRU_TGH_DW0_DELRESP_SHIFT                 1 /* inferred */
#define UV_GRU_TGH_DW0_DELRESP_MASK                  0x1ull
#define UV_GRU_TGH_DW0_DELRESP_INPLACE (UV_GRU_TGH_DW0_DELRESP_MASK << UV_GRU_TGH_DW0_DELRESP_SHIFT)
#define UV_GRU_TGH_DW0_CMD_SHIFT                     0 /* inferred */
#define UV_GRU_TGH_DW0_CMD_MASK                      0x1ull
#define UV_GRU_TGH_DW0_CMD_INPLACE (UV_GRU_TGH_DW0_CMD_MASK << UV_GRU_TGH_DW0_CMD_SHIFT)

/*
 * TLB global handle, dword 2.
 */
/* word TGH_DW2: 64 bits */
#define UV_GRU_TGH_DW2_WIDTH                         64 /* inferred */
#define UV_GRU_TGH_DW2_GLOBAL_SHIFT                  48 /* inferred */
#define UV_GRU_TGH_DW2_GLOBAL_MASK                   0x1ull
#define UV_GRU_TGH_DW2_GLOBAL_INPLACE (UV_GRU_TGH_DW2_GLOBAL_MASK << UV_GRU_TGH_DW2_GLOBAL_SHIFT)
#define UV_GRU_TGH_DW2_PAGESIZE_SHIFT                32 /* inferred */
#define UV_GRU_TGH_DW2_PAGESIZE_MASK                 0x1full
#define UV_GRU_TGH_DW2_PAGESIZE_INPLACE (UV_GRU_TGH_DW2_PAGESIZE_MASK << UV_GRU_TGH_DW2_PAGESIZE_SHIFT)
#define UV_GRU_TGH_DW2_ASID_SHIFT                    0 /* inferred */
#define UV_GRU_TGH_DW2_ASID_MASK                     0xffffffull
#define UV_GRU_TGH_DW2_ASID_INPLACE (UV_GRU_TGH_DW2_ASID_MASK << UV_GRU_TGH_DW2_ASID_SHIFT)

/*
 * TLB global handle, dword 3: address mask and the count of pages to purge.
 */
/* word TGH_DW3: 64 bits */
#define UV_GRU_TGH_DW3_WIDTH                         64 /* inferred */
#define UV_GRU_TGH_DW3_N_SHIFT                       48 /* inferred */
#define UV_GRU_TGH_DW3_N_MASK                        0x3ffull
#define UV_GRU_TGH_DW3_N_INPLACE (UV_GRU_TGH_DW3_N_MASK << UV_GRU_TGH_DW3_N_SHIFT)
#define UV_GRU_TGH_DW3_VADDRMASK_SHIFT               0 /* inferred */
#define UV_GRU_TGH_DW3_VADDRMASK_MASK                0x7fffffffffull
#define UV_GRU_TGH_DW3_VADDRMASK_INPLACE (UV_GRU_TGH_DW3_VADDRMASK_MASK << UV_GRU_TGH_DW3_VADDRMASK_SHIFT)

#define UV_GRU_CACHE_LINE                            0x40u /* established */
/* established */
#define UV_GRU_CBE_BASE                              0x4010000u
#define UV_GRU_CBR_AU_SIZE                           0x2u /* established */
#define UV_GRU_CBS_ACTIVE                            0x2u /* established */
#define UV_GRU_CBS_CALL_OS                           0x3u /* established */
#define UV_GRU_CBS_EXCEPTION                         0x1u /* established */
#define UV_GRU_CBS_IDLE                              0x0u /* established */
#define UV_GRU_CB_BASE                               0x0u /* established */
#define UV_GRU_CCHOP_ALLOCATE                        0x2u /* established */
#define UV_GRU_CCHOP_DEALLOCATE                      0x4u /* established */
#define UV_GRU_CCHOP_INTERRUPT                       0x3u /* established */
#define UV_GRU_CCHOP_INTERRUPT_SYNC                  0x5u /* established */
#define UV_GRU_CCHOP_START                           0x1u /* established */
/* established */
#define UV_GRU_CCH_BASE                              0x4020000u
#define UV_GRU_CHIPLETS_PER_HUB                      0x2u /* established */
/* established */
#define UV_GRU_CHIPLET_SIZE                          0x8000000u
#define UV_GRU_DSR_AU_BYTES                          0x400u /* established */
#define UV_GRU_DS_BASE                               0x20000u /* established */
#define UV_GRU_GAA_MMIO                              0x1u /* established */
#define UV_GRU_GAA_NCRAM                             0x2u /* established */
#define UV_GRU_GAA_RAM                               0x0u /* established */
#define UV_GRU_GAA_REGISTER                          0x3u /* established */
#define UV_GRU_GRU_PADDR_SHIFT                       0xcu /* established */
#define UV_GRU_GSEG_PAGESIZE                         0x40000u /* established */
#define UV_GRU_GSEG_STRIDE                           0x400000u /* established */
#define UV_GRU_HANDLE_BYTES                          0x40u /* established */
#define UV_GRU_HANDLE_STRIDE                         0x100u /* established */
#define UV_GRU_IAA_MMIO                              0x1u /* established */
#define UV_GRU_IAA_NCRAM                             0x2u /* established */
#define UV_GRU_IAA_RAM                               0x0u /* established */
#define UV_GRU_IAA_REGISTER                          0x3u /* established */
/* established */
#define UV_GRU_MCS_BASE                              0x4000000u
#define UV_GRU_NUM_CB                                0x80u /* established */
#define UV_GRU_NUM_CCH                               0x10u /* established */
#define UV_GRU_NUM_DSR_BYTES                         0x8000u /* established */
#define UV_GRU_NUM_TFM                               0x10u /* established */
#define UV_GRU_NUM_TGH                               0x18u /* established */
#define UV_GRU_OP_BCOPY                              0x1u /* established */
#define UV_GRU_OP_BSTORE                             0xeu /* established */
#define UV_GRU_OP_GAMER                              0xcu /* established */
#define UV_GRU_OP_GAMERR                             0xdu /* established */
#define UV_GRU_OP_GAMIR                              0xau /* established */
#define UV_GRU_OP_GAMIRR                             0xbu /* established */
#define UV_GRU_OP_GAMXR                              0x9u /* established */
#define UV_GRU_OP_IVLOAD                             0x3u /* established */
#define UV_GRU_OP_IVSET                              0x7u /* established */
#define UV_GRU_OP_IVSTORE                            0x5u /* established */
#define UV_GRU_OP_MESQ                               0x8u /* established */
#define UV_GRU_OP_NOP                                0x0u /* established */
#define UV_GRU_OP_VFLUSH                             0xfu /* established */
#define UV_GRU_OP_VLOAD                              0x2u /* established */
#define UV_GRU_OP_VSET                               0x6u /* established */
#define UV_GRU_OP_VSTORE                             0x4u /* established */
#define UV_GRU_SUPPORTED_BELOW_HUB_REVISION          0x5u /* established */
#define UV_GRU_TFHOP_EXCEPTION                       0x4u /* established */
#define UV_GRU_TFHOP_NOOP                            0x0u /* established */
#define UV_GRU_TFHOP_RESTART                         0x1u /* established */
#define UV_GRU_TFHOP_USER_POLLING_MODE               0x7u /* established */
#define UV_GRU_TFHOP_WRITE_ONLY                      0x2u /* established */
#define UV_GRU_TFHOP_WRITE_RESTART                   0x3u /* established */
/* established */
#define UV_GRU_TFH_BASE                              0x4018000u
/* established */
#define UV_GRU_TFM_BASE                              0x4000000u
#define UV_GRU_TGHOP_TLBINV                          0x1u /* established */
/* established */
#define UV_GRU_TGH_BASE                              0x4008000u
#define UV_GRU_XTYPE_B                               0x0u /* established */
#define UV_GRU_XTYPE_CL                              0x6u /* established */
#define UV_GRU_XTYPE_DW                              0x3u /* established */
#define UV_GRU_XTYPE_S                               0x1u /* established */
#define UV_GRU_XTYPE_W                               0x2u /* established */

#endif /* UV_GRU_GEN_H */
