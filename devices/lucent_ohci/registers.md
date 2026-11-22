<!-- generated from devices/lucent_ohci/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 cf7e5ea835b8e61828bc429fe75da6b0727abc470a22bf2239f922f8dba5d646 -->

# AT&T/Lucent 11C1:5802 two-port OHCI USB host controller (Origin 300 IO-8), the register and identity facts the held sources establish

The two-port USB host controller on the Origin 300 IO-8 board (PCI 11c1:5802, OpenHCI register interface). The register offsets follow the OpenHCI word layout; the IO-8 board test names its operational registers by word index. Grades say how each item was derived: established means the published OpenHCI specification, the Lucent USS-312 datasheet, a published SGI manual or a public hardware capture states it; inferred means a software expectation taken from the IO-8 board test's own checks, or a reading of its masks. No reset word for the PCI configuration Command and Status registers is held, and the reset values of the operational registers are unknown unless a row says otherwise. Software expectations are what the diagnostic requires, not measured chip behaviour.

Unit `lucent_ohci`, macro prefix `LUCENT_OHCI`.
Default source: OpenHCI 1.0a (sections cited per item); Lucent USS-312 datasheet; Online Diagnostics manual 108-0286-007; IO-8 board test (io8bt) in the stock PROM diagnostics; public IRIX hinv capture of an Origin 300 IO-8.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `hc_interrupt_enable` | 0x10 | rw | 32 |  |  | 0x0 | established |  |
| `hc_fm_interval` | 0x34 | rw | 32 |  |  | 0x2edf | established |  |
| `hc_fm_number` | 0x3c | r | 32 |  |  | 0x0 (OpenHCI 1.0a section 7.3.3 (printed page 122), as the source datasheet cites it; IO-8 board test register table for the write check (index 0xf, offset 0x3c)) | established | OpenHCI 1.0a section 7.3.3 (printed page 122), as the source datasheet cites it; IO-8 board test register table for the write check (index 0xf, offset 0x3c) |
| `hc_rh_descriptor_a` | 0x48 | rw | 32 |  |  | 0x10000902 | established |  |
| `hc_rh_descriptor_b` | 0x4c | rw | 32 |  |  | 0x60000 | established |  |

### Register `hc_interrupt_enable`

Interrupt enable word. The IO-8 board test requires it to read zero after a host-controller reset issued through the command register, and it prints a reset-error message when it does not. That is the test's software expectation, not a value measured on the part. The test's mask table narrows the read-back masks of four fields: the unrecoverable-error enable in this word, the frame interval toggle, the frame remaining word and the top of the power-on-to-power-good time. Which bits of those the part keeps is unknown.

### Register `hc_fm_interval`

Frame interval word. The frame interval and its toggle take the OpenHCI reset values (see FRAME_INTERVAL_RESET). The largest data packet field's reset value is TBD in the OpenHCI specification, and the USS-312 data sheet gives it as 0h, which the IO-8 board test also expects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `frame_interval_toggle` | established |  |  | Toggle, reset zero per the specification |
| 30:16 | `fs_largest_data_packet` | established |  |  | Largest data packet size. Its reset value is TBD in the OpenHCI specification; the USS-312 data sheet (Table 40) gives 0h and the IO-8 board test expects zero |
| 13:0 | `frame_interval` | established |  |  | Frame interval in bit times, reset 0x2edf per the specification |

### Register `hc_fm_number`

Frame number word. The specification makes it read-only to the driver, written only by the controller, with reset zero. The IO-8 board test writes 0xffff to it after a controller reset, while the controller is not operational and again during reset, and requires the read-back to match under the mask in FM_NUMBER_WRITE_MASK. Neither the specification nor the test says what a driver write does to the part. That is the open point of this register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `frame_number` | established |  | OpenHCI 1.0a section 7.3.3 (printed page 122), as the source datasheet cites it; IO-8 board test register table for the write check (index 0xf, offset 0x3c) | Frame number, written by the controller |

### Register `hc_rh_descriptor_a`

Root hub descriptor A. The specification makes the power-switching and over-current fields and the power-on-to-power-good time driver-written, so the board test's write-and-read-back of them is a fair check of those writable bits. The test writes zero and requires those fields to read back as zero under the mask 0x03001b00 (the bits of PowerSwitchingMode, NoPowerSwitching, OverCurrentProtectionMode and NoOverCurrentProtection, plus bits 25 and 24 of the power-on-to-power-good time). The power-on value is given by the USS-312 datasheet but is not stated in this unit.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `power_on_to_power_good_time` | established |  |  | Power-on to power-good time in 2 ms units, driver written per the specification. The board test checks only bits 25 and 24 |
| 12 | `no_over_current_protection` | established |  |  | Over-current protection disabled when set, driver written per the specification |
| 11 | `over_current_protection_mode` | established |  |  | Per-port (1) or global (0) over-current reporting, driver written per the specification |
| 9 | `no_power_switching` | established |  |  | Power switching disabled when set, driver written per the specification |
| 8 | `power_switching_mode` | established |  |  | Per-port (1) or global (0) power switching, driver written per the specification |

### Register `hc_rh_descriptor_b`

Root hub descriptor B. The specification gives the device-removable and port-power-control fields as driver written, one bit per port starting at bit 1 of each half, and says a hardware reset does not reset the root hub. The board test's USBRESET check requires the port bits to survive a USBRESET followed by a controller reset. The specification's prose points the other way about USBRESET, and its reset column permits keeping the fields, so the survival is inferred from the test alone.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:16 | `port_power_control_mask` | established |  |  | One bit per port from bit 17, driver written |
| 15:0 | `device_removable` | established |  |  | One bit per port from bit 1, driver written |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `FM_NUMBER_WRITE_MASK` | 0xffff | inferred |  | Read-back mask the IO-8 board test applies after writing the frame number register. It shows the full 16-bit field is expected to hold a driver write while the controller is not operational. What the part does with a write while operational is unknown. |
| `FRAME_INTERVAL_RESET` | 0x2edf | established | OpenHCI 1.0a, section 7.3.1 (figure on printed page 120, table on printed page 121), as the source datasheet cites it | Reset value of the frame interval field of the frame interval register. The specification gives it. The field that holds the largest data packet size in the same register is marked TBD there, so it is not listed here (see the register's doc). |
| `HCLSTHRESHOLD_RESET` | 0x628 | established | Lucent USS-312 datasheet, Table 44 | Reset value of the low-speed threshold register the datasheet gives. |
| `MAX_LAT` | 0x56 | established | Lucent USS-312 datasheet | Max_Lat configuration value the datasheet gives for this part. |
| `MIN_GNT` | 0x3 | established | Lucent USS-312 datasheet | Min_Gnt configuration value the datasheet gives for this part. |
| `PCI_DEVICE_ID` | 0x5802 | established | public IRIX hinv capture of an Origin 300 IO-8 (decimal 22530, PCI device 5, interface OHCI); Lucent USS-312 datasheet | PCI device ID of the two-port OHCI function. The capture reports the decimal form, 22530. The board places it at PCI device 5. |
| `PCI_VENDOR_ID` | 0x11c1 | established | public IRIX hinv capture of an Origin 300 IO-8 (decimal 4545, PCI device 5, interface OHCI); Lucent USS-312 datasheet | PCI vendor ID of AT&T/Lucent. The capture reports the decimal form, 4545, for this function. |
| `SUBSYSTEM_ID` | 0x5802 | established | Lucent USS-312 datasheet, Tables 3 and 18 | Subsystem ID the datasheet gives. Same write rule as the subsystem vendor ID. The value on a fitted IO-8 part is not read from a capture here. |
| `SUBSYSTEM_VENDOR_ID` | 0x11c1 | established | Lucent USS-312 datasheet, Tables 3 and 17 | Subsystem vendor ID the datasheet gives. It is read-only unless system firmware opens the subsystem fields through configuration register 4Ch. Whether the IO-8 firmware does so, and so what the fitted part reports, is unknown. |
