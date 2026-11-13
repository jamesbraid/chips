# TI TL16PIR552 parallel port (Fuel and Origin 200)

The TL16PIR552 is a dual UART and IEEE 1284 parallel-port controller with ECP and EPP support, with a
16-byte parallel FIFO. Public board photographs show its package marking on a Fuel system board,
`030-1707-005` revision B, and on an Origin 200 IP29 system board. The register facts the TI datasheet
states are in `devices/tl16pir552/registers.toml`, and the generated reference is `devices/tl16pir552/registers.md`. This
page holds what that unit does not carry.

Each fact carries one label. **Established** means the TI datasheet states it. **Inferred** means a
reasoned reading of the datasheet, such as the bit order of a list it gives. **Unknown** means the
sources do not settle it. No fact here was measured on a board.

## Sources

- **Texas Instruments, *TL16PIR552 Dual UART and IEEE 1284 Parallel Port*, SLLS222A**, December 1995,
  revised August 1996. Page numbers are the datasheet's printed pages, which equal the PDF pages: register tables
  on pp. 43 to 45, mode descriptions and the 16-byte FIFO on pp. 40 to 41, the reset pin on p. 5.
  Register offsets, bit positions and mode values were checked against these pages.
- **SGI, *Fuel Visual Workstation Hardware User's Guide*, 007-4480-001.** Describes a 25-pin ECP and EPP
  capable parallel connector on the IP34 board. It does not name the controller. The parallel port is described on printed p. 125 (IEEE 1284-A, EPP and ECP modes) and the 25-pin ECP port on p. 28; the L1 diagnostic port label is on p. 6 and the USB-B maintenance note on p. 130. Re-read for this verification.
- **Public board photographs.** A revision B Fuel system board (`030-1707-005`) and an Origin 200 IP29
  system board. Both show the TL16PIR552PH marking. The Origin 200 board revision is not established.

## Use on SGI boards (inferred)

- **Fuel revision B.** The marking on the board photograph establishes the part on that revision only.
- **Fuel revisions G and H (`030-1707-003`).** Assigning the part here is an inference from board
  similarity. It is not established.
- **Origin 200 IP29.** The marking corroborates use of this part on another SGI board family. The
  revision is not stated.

## Register contract (established, with gaps)

The register table, the mode values of the ECR, the CNFGA and CNFGB fields, and the FIFO behaviour are in
the unit. These facts describe the TI part alone.

- The offsets assume a parallel-port base of 378h, with chip selects PPCS and ECPCS. Whether Fuel exposes
  this map unchanged is **unknown**. The chip-select groups are the TI document's, not established Fuel
  address ranges.
- Reset: the active-high RESET input clears the UART and parallel-port internal registers. The reset
  value of each register is not stated per register and is **unknown** here.
- The FIFO holds 16 bytes (p. 40). In FIFO test mode the FIFO does not stop accepting or sending data
  when full or empty, and its read and write address counters wrap (p. 41); test-mode reads return bytes
  in the order written (p. 45). The datasheet states no such overrun behaviour for the other modes, and
  does not define which byte remains after a write to a full FIFO.
- CNFGA reads `0x1f`: implementation ID `0001` in the top nibble, low nibble reserved and read as ones.
- CNFGB reports compression unsupported, samples the IRQ line, reports IRQ7 and DMA channel 3. The IRQ
  sample depends on the board, so its reset value is **unknown**.
- The DCR and DSR bit positions are established from Tables 17 and 16 (pp. 44 and 43). DCR INIT is
  active low.

## Interrupts and DMA

- The datasheet describes DCR bit 4 (interrupt on a rising ACK), the ECR bit 4 falling-FAULT interrupt in
  ECP mode, and ECR service-interrupt and DMA behaviour. These are TI facts.
- CNFGB reports IRQ7 and DMA channel 3. That is the part's own report of its selection. It does not
  establish which IOC3 input or DMA channel Fuel connects.
- The Fuel IOC3 input, the board IRQ routing and the assertion path through any bridge are **unknown**.
- Whether the part's DMA request and acknowledge lines reach the board, and how IOC3 would carry a
  transfer, are **unknown**. No Fuel DMA address, descriptor, translation or byte-swap rule is established.

## Fuel wiring (unknown)

- The TI datasheet does not establish the Fuel address decode, the IOC3 connection, the interrupt wiring or
  the DMA wiring. These are **unknown**.
- The Fuel guide's rear-panel description calls one port an "L1 diagnostic port" (printed p. 6) and
  another a USB-B maintenance port (printed p. 130). It does not say whether these are one connector or
  two. Which of them carries this part is **unknown**.
- Route: a Fuel board schematic, or a revision-specific measurement with its provenance recorded.

## Out of scope

- The two UART channels and their register contract.
- EPP timing and the full IEEE 1284 electrical behaviour beyond the cited register effects.
- Use of the part on revisions G and H of the Fuel board, except as the inference above.
