/*
 * ioc4_extra.h - IOC4 registers outside the census
 *
 * Written by hand, not generated: the census cannot reach these, so gen_headers.py never emits them and does not
 * overwrite this file. Same label convention as the generated headers: [E] established, [I] inferred, [U] unknown.
 * Source: the Origin 3000 kernel's keyboard poll routine, which indexes the words by port.
 */
#ifndef IOC4_EXTRA_H
#define IOC4_EXTRA_H

#define IOC4_KM_RX_KBD                       0x000204   /* [E] width 4 byte(s), access r; keyboard receive */
#define IOC4_KM_RX_MOUSE                     0x000208   /* [E] width 4 byte(s), access r; mouse receive */
#define IOC4_KM_TX_KBD                       0x00020c   /* [E] width 4 byte(s), access w; keyboard transmit */
#define IOC4_KM_TX_MOUSE                     0x000210   /* [E] width 4 byte(s), access w; mouse transmit */

/* ATA DMA block (0x140 + 4n) and the control word. Roles are the public Linux IDE driver's names; the IRIX access pattern in the
 * control word's two low bits is re-read ([E] for the access and the written values); the meaning of each bit is the driver's
 * statement ([I] here). Words 0, 3 and 4 are named by the driver but not touched by any routine on this part ([U]). */
#define IOC4_ATA_DMA_TIMING                  0x000140   /* [I] width 4 byte(s); index 0; name from the public driver only */
#define IOC4_ATA_DMA_LIST_LOW                0x000144   /* [I] index 1; written by the packet-DMA start routine */
#define IOC4_ATA_DMA_LIST_HIGH               0x000148   /* [I] index 2; written by the packet-DMA start routine */
#define IOC4_ATA_DMA_CURRENT_LOW             0x00014c   /* [U] index 3; name from the public driver only */
#define IOC4_ATA_DMA_CURRENT_HIGH            0x000150   /* [U] index 4; name from the public driver only */
#define IOC4_ATA_DMA_COUNT_DEVICE            0x000154   /* [I] index 5; read by the completion routine */
#define IOC4_ATA_DMA_COUNT_MEMORY            0x000158   /* [I] index 6; read by the completion routine */
#define IOC4_ATA_DMA_CONTROL                 0x00015c   /* [E] index 7, byte accesses; bits below */
#define IOC4_ATA_DMA_CONTROL_START           0x01       /* [E] bit 0: ORed with the direction bit and stored once to start a transfer (earlier full reading; the combined value was not re-derived); name [I] */
#define IOC4_ATA_DMA_CONTROL_STOP            0x02       /* [E] bit 1: the value 2 is stored, then the word is read until the bit clears; name [I] */
#define IOC4_ATA_DMA_CONTROL_DIR_TO_MEMORY   0x04       /* [I] bit 2: 1 copies ATA data to memory; the direction convention rests on the public driver's comments */
#define IOC4_ATA_DMA_CONTROL_ACTIVE          0x08       /* [E] bit 3: read first by the start routine, which stops the engine before arming when set; name [I] */
#define IOC4_ATA_DMA_CONTROL_ERROR           0x10       /* [E] bit 4: tested; when set the start routine stores 2 and the completion routine reads it back; name [I] */
#define IOC4_ATA_DMA_END_AREA                0x000160   /* [I] index 8; bus address of the 128-byte end-of-transfer area */

/* Fields of IOC4_SIO_CR (0x20): the attach routine stores 0xf and the reset wait polls bit 7. */
#define IOC4_SIO_CR_CMD_PULSE                0x0000000f /* [E] value stored at attach; that bits 3:0 are a strobe field is [I] */
#define IOC4_SIO_CR_SIO_DIAG_IDLE            0x00000080 /* [E] bit 7, polled until set; name [I] */

#endif /* IOC4_EXTRA_H */
