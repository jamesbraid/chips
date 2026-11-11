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

#endif /* BEDROCK_EXTRA_H */
