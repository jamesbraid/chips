/* generated from devices/lucent_ohci/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 4 */
/* input sha256 cf7e5ea835b8e61828bc429fe75da6b0727abc470a22bf2239f922f8dba5d646 */
/* AT&T/Lucent 11C1:5802 two-port OHCI USB host controller (Origin 300 IO-8),
 * the register and identity facts the held sources establish */
#ifndef LUCENT_OHCI_GEN_H
#define LUCENT_OHCI_GEN_H

#include <stdint.h>


/*
 * Interrupt enable word. The IO-8 board test requires it to read zero after a
 * host-controller reset issued through the command register, and it prints a
 * reset-error message when it does not. That is the test's software
 * expectation, not a value measured on the part. The test's mask table narrows
 * the read-back masks of four fields: the unrecoverable-error enable in this
 * word, the frame interval toggle, the frame remaining word and the top of the
 * power-on-to-power-good time. Which bits of those the part keeps is unknown.
 */
/* hc_interrupt_enable: rw32, reset 0x0 */
#define LUCENT_OHCI_HC_INTERRUPT_ENABLE_OFFSET       0x10u /* established */

/*
 * Frame interval word. The frame interval and its toggle take the OpenHCI reset
 * values (see FRAME_INTERVAL_RESET). The largest data packet field's reset
 * value is TBD in the OpenHCI specification, and the USS-312 data sheet gives
 * it as 0h, which the IO-8 board test also expects.
 */
/* hc_fm_interval: rw32, reset 0x2edf */
#define LUCENT_OHCI_HC_FM_INTERVAL_OFFSET            0x34u /* established */
/* established */
#define LUCENT_OHCI_HC_FM_INTERVAL_FRAME_INTERVAL_TOGGLE_SHIFT 31
#define LUCENT_OHCI_HC_FM_INTERVAL_FRAME_INTERVAL_TOGGLE_MASK 0x1u
#define LUCENT_OHCI_HC_FM_INTERVAL_FRAME_INTERVAL_TOGGLE_INPLACE (LUCENT_OHCI_HC_FM_INTERVAL_FRAME_INTERVAL_TOGGLE_MASK << LUCENT_OHCI_HC_FM_INTERVAL_FRAME_INTERVAL_TOGGLE_SHIFT)
/* established */
#define LUCENT_OHCI_HC_FM_INTERVAL_FS_LARGEST_DATA_PACKET_SHIFT 16
#define LUCENT_OHCI_HC_FM_INTERVAL_FS_LARGEST_DATA_PACKET_MASK 0x7fffu
#define LUCENT_OHCI_HC_FM_INTERVAL_FS_LARGEST_DATA_PACKET_INPLACE (LUCENT_OHCI_HC_FM_INTERVAL_FS_LARGEST_DATA_PACKET_MASK << LUCENT_OHCI_HC_FM_INTERVAL_FS_LARGEST_DATA_PACKET_SHIFT)
#define LUCENT_OHCI_HC_FM_INTERVAL_FRAME_INTERVAL_SHIFT 0 /* established */
#define LUCENT_OHCI_HC_FM_INTERVAL_FRAME_INTERVAL_MASK 0x3fffu
#define LUCENT_OHCI_HC_FM_INTERVAL_FRAME_INTERVAL_INPLACE (LUCENT_OHCI_HC_FM_INTERVAL_FRAME_INTERVAL_MASK << LUCENT_OHCI_HC_FM_INTERVAL_FRAME_INTERVAL_SHIFT)

/*
 * Frame number word. The specification makes it read-only to the driver,
 * written only by the controller, with reset zero. The IO-8 board test writes
 * 0xffff to it after a controller reset, while the controller is not
 * operational and again during reset, and requires the read-back to match under
 * the mask in FM_NUMBER_WRITE_MASK. Neither the specification nor the test says
 * what a driver write does to the part. That is the open point of this
 * register.
 */
/* hc_fm_number: r32, reset 0x0; OpenHCI 1.0a section 7.3.3 (printed page 122),
 * as the source datasheet cites it; IO-8 board test register table for the
 * write check (index 0xf, offset 0x3c) */
#define LUCENT_OHCI_HC_FM_NUMBER_OFFSET              0x3cu /* established */
#define LUCENT_OHCI_HC_FM_NUMBER_FRAME_NUMBER_SHIFT  0 /* established */
#define LUCENT_OHCI_HC_FM_NUMBER_FRAME_NUMBER_MASK   0xffffu
#define LUCENT_OHCI_HC_FM_NUMBER_FRAME_NUMBER_INPLACE (LUCENT_OHCI_HC_FM_NUMBER_FRAME_NUMBER_MASK << LUCENT_OHCI_HC_FM_NUMBER_FRAME_NUMBER_SHIFT)

/*
 * Root hub descriptor A. The specification makes the power-switching and
 * over-current fields and the power-on-to-power-good time driver-written, so
 * the board test's write-and-read-back of them is a fair check of those
 * writable bits. The test writes zero and requires those fields to read back as
 * zero under the mask 0x03001b00 (the bits of PowerSwitchingMode,
 * NoPowerSwitching, OverCurrentProtectionMode and NoOverCurrentProtection, plus
 * bits 25 and 24 of the power-on-to-power-good time). The power-on value is
 * given by the USS-312 datasheet but is not stated in this unit.
 */
/* hc_rh_descriptor_a: rw32, reset 0x10000902 */
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_OFFSET        0x48u /* established */
/* established */
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_POWER_ON_TO_POWER_GOOD_TIME_SHIFT 24
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_POWER_ON_TO_POWER_GOOD_TIME_MASK 0xffu
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_POWER_ON_TO_POWER_GOOD_TIME_INPLACE (LUCENT_OHCI_HC_RH_DESCRIPTOR_A_POWER_ON_TO_POWER_GOOD_TIME_MASK << LUCENT_OHCI_HC_RH_DESCRIPTOR_A_POWER_ON_TO_POWER_GOOD_TIME_SHIFT)
/* established */
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_NO_OVER_CURRENT_PROTECTION_SHIFT 12
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_NO_OVER_CURRENT_PROTECTION_MASK 0x1u
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_NO_OVER_CURRENT_PROTECTION_INPLACE (LUCENT_OHCI_HC_RH_DESCRIPTOR_A_NO_OVER_CURRENT_PROTECTION_MASK << LUCENT_OHCI_HC_RH_DESCRIPTOR_A_NO_OVER_CURRENT_PROTECTION_SHIFT)
/* established */
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_OVER_CURRENT_PROTECTION_MODE_SHIFT 11
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_OVER_CURRENT_PROTECTION_MODE_MASK 0x1u
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_OVER_CURRENT_PROTECTION_MODE_INPLACE (LUCENT_OHCI_HC_RH_DESCRIPTOR_A_OVER_CURRENT_PROTECTION_MODE_MASK << LUCENT_OHCI_HC_RH_DESCRIPTOR_A_OVER_CURRENT_PROTECTION_MODE_SHIFT)
/* established */
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_NO_POWER_SWITCHING_SHIFT 9
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_NO_POWER_SWITCHING_MASK 0x1u
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_NO_POWER_SWITCHING_INPLACE (LUCENT_OHCI_HC_RH_DESCRIPTOR_A_NO_POWER_SWITCHING_MASK << LUCENT_OHCI_HC_RH_DESCRIPTOR_A_NO_POWER_SWITCHING_SHIFT)
/* established */
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_POWER_SWITCHING_MODE_SHIFT 8
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_POWER_SWITCHING_MODE_MASK 0x1u
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_A_POWER_SWITCHING_MODE_INPLACE (LUCENT_OHCI_HC_RH_DESCRIPTOR_A_POWER_SWITCHING_MODE_MASK << LUCENT_OHCI_HC_RH_DESCRIPTOR_A_POWER_SWITCHING_MODE_SHIFT)

/*
 * Root hub descriptor B. The specification gives the device-removable and
 * port-power-control fields as driver written, one bit per port starting at bit
 * 1 of each half, and says a hardware reset does not reset the root hub. The
 * board test's USBRESET check requires the port bits to survive a USBRESET
 * followed by a controller reset. The specification's prose points the other
 * way about USBRESET, and its reset column permits keeping the fields, so the
 * survival is inferred from the test alone.
 */
/* hc_rh_descriptor_b: rw32, reset 0x60000 */
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_B_OFFSET        0x4cu /* established */
/* established */
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_B_PORT_POWER_CONTROL_MASK_SHIFT 16
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_B_PORT_POWER_CONTROL_MASK_MASK 0xffffu
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_B_PORT_POWER_CONTROL_MASK_INPLACE (LUCENT_OHCI_HC_RH_DESCRIPTOR_B_PORT_POWER_CONTROL_MASK_MASK << LUCENT_OHCI_HC_RH_DESCRIPTOR_B_PORT_POWER_CONTROL_MASK_SHIFT)
/* established */
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_B_DEVICE_REMOVABLE_SHIFT 0
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_B_DEVICE_REMOVABLE_MASK 0xffffu
#define LUCENT_OHCI_HC_RH_DESCRIPTOR_B_DEVICE_REMOVABLE_INPLACE (LUCENT_OHCI_HC_RH_DESCRIPTOR_B_DEVICE_REMOVABLE_MASK << LUCENT_OHCI_HC_RH_DESCRIPTOR_B_DEVICE_REMOVABLE_SHIFT)

#define LUCENT_OHCI_FM_NUMBER_WRITE_MASK             0xffffu /* inferred */
#define LUCENT_OHCI_FRAME_INTERVAL_RESET             0x2edfu /* established */
#define LUCENT_OHCI_HCLSTHRESHOLD_RESET              0x628u /* established */
#define LUCENT_OHCI_MAX_LAT                          0x56u /* established */
#define LUCENT_OHCI_MIN_GNT                          0x3u /* established */
#define LUCENT_OHCI_PCI_DEVICE_ID                    0x5802u /* established */
#define LUCENT_OHCI_PCI_VENDOR_ID                    0x11c1u /* established */
#define LUCENT_OHCI_SUBSYSTEM_ID                     0x5802u /* established */
#define LUCENT_OHCI_SUBSYSTEM_VENDOR_ID              0x11c1u /* established */

#endif /* LUCENT_OHCI_GEN_H */
