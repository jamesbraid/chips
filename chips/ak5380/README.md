# AKM AK5380 stereo ADC (DMediaPro DM8, unverified)

Mode: **no-spec**. No shipped software touches this part.

- **Unknown, and no software dependency.** The DM8's line and microphone input converter. The IRIX driver has no register path
  for an input converter: the only converter writes go to the two DAC chips (see [../ice1724/README.md](../ice1724/README.md)),
  and the driver reports a fixed input gain range of zero. The AK5380 is named for the board only by secondary reviews of the
  Revolution 7.1 (guru3d, iXBT Labs, xbitlabs), not by an SGI document or a shipped file, and nothing ties the DM8 to that
  exact board except the DAC and controller match. Treat the part number as a lead.
- Route that would settle it: a DM8 board photograph or the DM8 service parts list; a public AKM datasheet for the register-less
  part would then complete the page.
