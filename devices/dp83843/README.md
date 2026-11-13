# DP83840A and DP83843 Ethernet transceivers

The Ethernet controller on the Origin 200 and Origin 300 base I/O boards reaches its
10/100 Mb/s transceiver only through the MII management registers. The Origin 200 carries
a DP83840A. The Origin 300 IO-8 board carries a DP83843. This page records the published
facts about the two parts that this repository does not already hold, and what is still
unknown. The DP83843 register contract is in `devices/dp83843/registers.toml`; its generated reference
is `devices/dp83843/registers.md`. The DP83840A register map is not held here, so this page makes
no register claims for it.

Each fact carries one of the labels used across this repository. **Established** means
the datasheet or a public driver states it, with the citation. **Inferred** means a reasoned
reading of established facts or of a public driver. **Observed** means a printed line from
a published boot log of real hardware, cited by its source; this repository has no
other grade for that kind of evidence. **Unknown** means not settled, with the route that
would settle it.

## Sources

- **DP83843 datasheet, revision B** (TI publication SNLS021B), cited as `DP83843 revision B datasheet, PDF p. N
  (printed p. M)`. The chip page for the IOC3 already cites this document for the reserved
  register ranges. The page numbers were re-read against the PDF: the PDF page is the printed page plus one
  (register map Table 5 on PDF p. 46, BMCR Table 6 on pp. 47 to 48, BMSR Table 7 on pp. 48 to 49, ANER Table 12 on
  p. 53, LBR Table 21 on pp. 59 to 61, 10BTSCR Table 22 on p. 61, loopback prose in section 3.10 on p. 34).
- **OpenBSD sgi mailing list, "Origin 300 with NUMA link"**, Maurice Janssen, 2014-02-12.
  The post quotes a boot log from a real Origin 300. The same post is already a source for
  the [IOC3 page](../ioc3/README.md), which carries the Origin 300 supplement.
- **OpenBSD MII device table** (`sys/dev/mii/miidevs`), for the model numbers of the National
  Semiconductor PHYs. Re-read at the OpenBSD pin `7011342f6a72`: `DP83840` is model 0, `DP83843` model 1 and `DP83815` model 2 under the National Semiconductor OUI
  (`miidevs`, lines 274 to 276). The facts that depend on them stay inferred.

## Identity and placement

- **The Origin 300 IO-8 transceiver is a DP83843 at MII address 1.** Observed: the boot log
  quoted in the mailing-list post shows `iec0` attached under the IOC3 and the transceiver
  answering at `phy 1`, with the line `nsphyter0 at iec0 phy 1: DP83843 10/100 PHY, rev. 0`.
  The OpenBSD driver name `nsphyter` belongs to the DP83843 part, not to the DP83840A.
- **The identity registers read as PHYIDR1 `0x2000`, PHYIDR2 `0x5C10` on the DP83843 at
  revision 0.** Inferred. PHYIDR1 is the OUI's upper bits and is the same for both parts. In
  PHYIDR2 the model field is bits 9 to 4, and the DP83843 model is 1 where the DP83840 is 0,
  so the same OUI decodes to `0x5C10` for the DP83843 and to `0x5C0x` for the DP83840 family.
  This relies on the OpenBSD model constants, which are not re-read here.
- **The IRIX probe accepts this identity.** `ef_phyprobe`, described in the
  [IOC3 page](../ioc3/README.md), accepts the two values `0x20005c0` and `0x20005c1`, which are PHYIDR1 followed by PHYIDR2
  with its revision nibble dropped. Those are the model-0 and model-1 identities, so the probe takes the
  DP83843 as well as the DP83840 family. Inferred from the bit mapping of the probe's
  established accept list.
- **The Origin 200 DP83840A is not described on this page.** The repository holds no
  published Origin 200 capture that names its MII address or revision. Unknown: its MII
  address, and whether the probe's accept list is the only identity check it passes.

## Autonegotiation restart

The DP83843 datasheet describes the restart in these terms. Each is established unless noted.

- BMCR bit 9 (restart autonegotiation) is read and written, and self-clears (PDF p. 48,
  printed p. 47). It reads one until the PHY initiates autonegotiation, then clears.
- A restart suppresses link pulses until a break-link timer of about 1.5 seconds expires
  (PDF p. 31, printed p. 30). A renegotiation request halts transmit data and link pulses for
  that interval.
- Completing negotiation takes roughly 2 to 3 seconds as a general estimate (PDF p. 31). The
  datasheet does not say whether that estimate includes the break-link interval.
- Software clearing bit 9 after the request does not cancel negotiation (Table 6).

**Unknown:**
- When bit 9 clears relative to the break-link interval. The datasheet allows it to clear when
  the request is accepted, or to hold through the break-link interval and clear when link pulses
  start. Route: read BMCR and BMSR before the restart, immediately after it, near 5 ms after it,
  across break-link expiry, and after negotiation completes, on a DP83843 of the board's revision,
  with the partner, cable and timestamps recorded.
- Whether disabling autonegotiation while a restart is pending cancels the break-link interval,
  and when a forced link becomes valid. Route: the same capture, with autonegotiation disabled at
  two points, once during break-link and once after negotiation starts.

## Forced mode and link status

- With BMCR bit 12 (autonegotiation enable) clear, bit 13 selects the forced speed and bit 8
  the forced duplex (PDF pp. 47 to 48, printed pp. 46 to 47, Table 6).
- BMSR bit 5 (autonegotiation complete) and bit 2 (link status) report different conditions.
  A forced link can be valid without a completed autonegotiation (PDF pp. 48 to 49, printed
  pp. 47 to 48, Table 7).
- BMSR bit 2 latches a link loss low until software reads the register (PDF p. 49, printed p. 48).
- The link-validity criteria are left to the implementation (PDF p. 49).
- **Unknown:** the settling time of the link after a forced-mode write, and the bit 5 readback
  after autonegotiation is disabled during a pending restart. No public page gives either.

## Loopback

- Setting BMCR bit 14 (loopback) sets LBR bits 5 (Twister loopback) and 4 (10 Mb/s ENDEC
  loopback) automatically (PDF p. 34, printed p. 33, and Table 21, PDF p. 60, printed p. 59).
- Writing either value to BMCR bit 14 returns the LBR 100 Mb/s data-path field, bits 9 to 7,
  to normal operation (PDF p. 34).
- **Unknown:** whether LBR bits 5 and 4 stay set after BMCR loopback is written back to zero.
  The datasheet does not give their readback then. Route: an LBR readback on a physical part
  after a loopback write of one and then of zero.
- **Unknown:** whether BMCR loopback cancels a pending restart request. The datasheet does not
  say.
- **Conflict:** the prose on the LBR register describes a bit 6 digital loopback selection that
  clears on a write. Table 21 marks bit 6 reserved and read only. Neither reading is settled by the
  datasheet text consulted, so bit 6 has no field in `devices/dp83843/registers.toml`.

## Isolate and power down

- BMCR bit 10 (isolate) cuts the part off from the MII data inputs and outputs, but serial
  management still answers and the TD outputs keep sending idles or link pulses (PDF p. 34,
  printed p. 33, section 3.9; Table 6, PDF p. 48, printed p. 47). Link signalling therefore
  continues while isolate is set.
- Isolate resets to one only when the PHY address latches `00000`, and otherwise to zero. After
  reset only software changes it (PDF p. 48, printed p. 47; section 2.4.2 on PHYAD). The board's
  part answers at address 1 in the boot log quoted above, so the rule gives zero there. That
  reading is inferred from the observed address, not read from a board's strap pins.
- BMCR bit 11 (power down) stops the part transmitting or receiving on an active network and
  disables Wake-on-LAN and receive reaction (PDF p. 47, printed p. 46, Table 6).
- **Unknown:** what a restart request does while power down is set. The datasheet does not
  define whether bit 9 reads back one, or whether negotiation completes, in that state. Route: a
  BMSR and BMCR readback on a physical part after a restart with power down set.

## Strap-dependent bits and the mode readback

- LBR bits 13 to 7 are bypass bits, and 10BTSCR bits 12 and 11 are serial bits. The datasheet
  marks all of them strap-dependent (established). The board's straps are not verified, so
  their reset values on the Origin 300 are unknown.
- 10BTSCR bit 7 reads one in full-duplex or repeater mode (established, Table 21).

## Reset values

- BMSR resets to `0x7849` with no link and no completed negotiation (established, PDF pp. 48
  to 49). That value has bit 6, preamble suppression, set.
- ANER resets to `0x0004` (established, PDF p. 53, printed p. 52). Bit 2, next-page capability,
  is permanently one.
- LBR and 10BTSCR reset to zero in the nominal table for copper, nibble-mode straps (established
  for the table; the strap-dependent bits above are not covered by that reading).
- A public erratum revises a reset reading for the next-page transmit register, register 7. The
  erratum's text is not held in this repository, so register 7 is unknown here.

## Not on this page

- The DP83840A register map, reset values and link behaviour. The repository holds no
  transcription of them.
- Anything read from the IO-8 boot firmware's own register accesses. Those are the IOC3 page's
  business, and the IOC3 page grades them separately.
