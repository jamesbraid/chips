# SHub 1 I/O interface: reset values and unused registers

Question. What are the reset values of the SHub 1 I/O interface registers, and what do the registers the kernel never touches (about 150 of the 166 in the header) do beyond the header's comments?

Status: **unknown**; the header states no reset value.

- Reset values: a read after the PROM ran is not a reset value, and no PROM or hardware read is held. Route: SHub PROM image or Altix diagnostics.
- The widths of the BTE data registers and what the interrupt-address register does (the kernel never programs it).
- Whether BTE busy is visible after the control write, and how a BTE reports an error to the notification address.
- Whether SHub 2 keeps any of this block. The kernel does not use it on SHub 2, and SHub 2's BTEs are elsewhere.

Related hypothesis, not evidence: 109 of the 119 offsets the Bedrock I/O interface records are in this block (devices/shub_ii/README.md).
