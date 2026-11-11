/*
 * bedrock_extra.h - Hub and Bedrock network-controller registers outside the census
 *
 * Written by hand, not generated: the census names a register only where a routine in the scanned objects reaches
 * it, and the offsets below are either reached under a different role than the Linux-derived name in hub.h, or are
 * timeout registers no held code writes. Same label convention as the generated headers: [E] established,
 * [I] inferred, [U] unknown. Offsets are the I/O-interface block offsets as in hub.h and bedrock.h.
 * Sources: the Origin 350 generation kernel's I/O error handlers (chips/bedrock/README.md, the error-register table), and the
 * published SN1 register header for the two timeout registers (a sibling chip's header: its layout is [E] for the
 * Bedrock only as that header's statement, and [I] for the earlier Hub).
 */
#ifndef BEDROCK_EXTRA_H
#define BEDROCK_EXTRA_H

/* hub.h names this offset HUB_IIO_IMEM by Linux's SN0 header (name [I]). On the Bedrock the error handlers read it
 * as the widget shutdown status; the Hub's role for the same offset is not shown by any held code. */
#define BEDROCK_II_SHUTDOWN_STATUS           0x4001e8   /* [E] width 8 byte(s), access r (Bedrock-generation kernel: hubii_eint_handler, bte_error_handler, hub_xp_error_handler); bit 0 widget 0 shut down, bit 4 BTE 0, bit 8 BTE 1 [E] */

/* Two timeout registers at the I/O interface. No held code writes either. The layouts are the published SN1
 * register header's statement: [E] for the Bedrock (docs/crosstalk-host-ends.md), only [I] for the earlier Hub, where
 * Linux names the offset without a layout and a sibling chip's header does not fill a field. */
#define BEDROCK_II_CREDIT_TIMEOUT            0x4001e0   /* [E] Bedrock layout, [I] Hub: bits 25:0 count 128-clock ticks while outbound credits are below 1 (direct) or 2 (crossbar), saturate, raise one interrupt; no consumer in anything held */
#define BEDROCK_II_TAIL_TIMEOUT              0x4001f0   /* [E] Bedrock layout, [I] Hub: bits 25:0 tail timeout; the same offset holds the read-response fields below */
#define BEDROCK_II_READ_RESP_PRESCALE_B_54_32 0x007fffff00000000ull /* [E] Bedrock layout: read-response prescaler, bits 54:32; unit [U] */
#define BEDROCK_II_READ_RESP_TIMEOUT_B_59_55 0x0f80000000000000ull /* [E] Bedrock layout: read-response timeout, bits 59:55; unit [U] */

/* Widget error header words, saved raw by the kernel's I/O error-header save and print routines. */
#define BEDROCK_II_ERROR_HEADER_1            0x400220   /* [E] width 8 byte(s), access r; fields printed by the show routine, see chips/bedrock/README.md */
#define BEDROCK_II_ERROR_HEADER_2            0x400228   /* [E] width 8 byte(s), access r; as above */
/* Fields of the two words, from the kernel's print routine for them (one machine build, read in full): each field is a mask
 * and shift the routine applies before printing, and each printed line names its bit range. Bit 44 of header 1 is only
 * the condition on which the routine prints header 1 at all (its test is a sign test after a left shift); that it
 * means "valid" is [I]. */
#define BEDROCK_II_ERROR_HEADER_1_COMMAND    0x000000000000007full /* [E] bits 6:0 */
#define BEDROCK_II_ERROR_HEADER_1_SUPPLEMENTAL 0x000000000007ff00ull /* [E] bits 18:8 */
#define BEDROCK_II_ERROR_HEADER_1_SOURCE     0x000000007ff00000ull /* [E] bits 30:20 */
#define BEDROCK_II_ERROR_HEADER_1_ERR_TYPE   0x0000000f00000000ull /* [E] bits 35:32; 2 short request packet, 3 short reply packet, 4 long request packet, 5 long reply packet, any other value prints as unknown (each value selects its own text in the print routine) */
#define BEDROCK_II_ERROR_HEADER_1_OVERRUN    0x0000010000000000ull /* [E] bit 40 */
#define BEDROCK_II_ERROR_HEADER_1_PRINT_GATE 0x0000100000000000ull /* [E] bit 44 gates the print; [I] header valid */
#define BEDROCK_II_ERROR_HEADER_2_ADDRESS    0x0000003fffffffffull /* [E] bits 37:0 */
#define BEDROCK_II_ERROR_HEADER_2_TAIL       0x0000010000000000ull /* [E] bit 40 */

/* Memory controller bank configuration word: four byte lanes, one per pair of DIMM banks. Read and written by the
 * PROM at the node-alias offset below; the kernel's local-form address is 0x780008 (BEDROCK_MDIR_XLATE_ADDR_MEM in
 * bedrock.h, named there by routine prefix, [I]). Both PROM routines were read in full (docs/questions). */
#define BEDROCK_MEM_BANK_CONFIG              0x1f80008  /* [E] width 8 byte(s), access rw (node alias); lane i of 0..3 is bits 8i+7:8i */
#define BEDROCK_MEM_BANK_CONFIG_LANE_ENABLE  0x03       /* [E] per lane, bits 1:0 enable the lane's two banks, one bit each; bits 3:2 are not read by the decode routine [U] */
#define BEDROCK_MEM_BANK_CONFIG_LANE_SIZE    0xf0       /* [E] per lane, bits 7:4: one size code shared by both banks of the lane */
#define BEDROCK_MEM_BANK_CONFIG_BANK_SELECT  0x300000000ull /* [E] bits 33:32; the PROM clears these and ORs in a selector shifted left 32 (not masked to two bits by that routine) */
#define BEDROCK_MEM_BANK_CONFIG_B_58_56      0x0700000000000000ull /* [E] the same write ORs in 7 here; meaning [U]: settle by a published Bedrock register list (none held) or the same routine's callers' use of the result */

/* Processor-interface error spool size (address 0x800428; bedrock.h carries the address without the encoding). Read in the error-print routine of the Origin 350 generation kernel (one machine build, re-read): a zero value
 * means no spool; otherwise the routine loads the value, subtracts one and shifts 4096 left by the result. */
#define BEDROCK_PI_ERROR_SPOOL_SIZE_BASE     4096       /* [E] bytes for a value of 1 */
/* [E] encoding: bytes = 4096 << (value - 1) for a nonzero value; the field width is not shown by the routine ([U]). */

/* I/O interface widget status (address 0x400008). The handler tests bit 32 as the error flag; with it set,
 * the routine that names the reason tests the three bits below. Register offset and bit 32 re-read in the widget-disabled
 * check of the Origin 350 generation kernel; the three reason bits are the README table's established reading. */
#define BEDROCK_II_WIDGET_STATUS             0x400008   /* [E] width 8 byte(s), access r */
#define BEDROCK_II_WIDGET_STATUS_ERROR       0x0000000100000000ull /* [E] bit 32, the "crazy" error flag; name [I] */
#define BEDROCK_II_WIDGET_STATUS_RETRY_TIMEOUT 0x0000000000000200ull /* [E] bit 9, reason when bit 32 is set */
#define BEDROCK_II_WIDGET_STATUS_TAIL_TIMEOUT  0x0000000000000020ull /* [E] bit 5, reason when bit 32 is set */
#define BEDROCK_II_WIDGET_STATUS_CREDIT_TIMEOUT 0x0000000000000010ull /* [E] bit 4, reason when bit 32 is set */

/* Node region bitmask at address 0x1000018 (node alias). The bus-error handler shifts 1 left by the faulting address's
 * region number and ANDs it with this register; a nonzero result sends the error to the partition error path. Access
 * pattern [E] (re-read in the Origin 350 generation kernel's cached bus-error handler); that it is a per-region bitmask is [I]. */
#define BEDROCK_NODE_REGION_MASK             0x1000018  /* [E] width 8 byte(s), access r; name [I] */

#endif /* BEDROCK_EXTRA_H */
