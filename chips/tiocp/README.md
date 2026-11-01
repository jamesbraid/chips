# TIOCP

Mode: **no-spec** (see [docs/specs.md](../../docs/specs.md)).

PCI-X bridge of a later system family (the Altix-class SN2 generation, whose crossbar chip is the TIO). Whether any product
in scope carries it is open. Nothing in the IRIX 6.5.30 builds read here drives it.

Status: no entries. The census of the shared Bridge-family accessors already lists the offsets those accessors reach
when the chip type is 3 or the part number is `0xe000` or `0xe010`: the `tiocp` rows of
[../pic/census/census.tsv](../pic/census/census.tsv) (43 offsets, 163 access sites). The tool config
[`tools/configs/tiocp.json`](../../tools/configs/tiocp.json) is the older stub and runs no census of its own; the header
[`include/tiocp.h`](../../include/tiocp.h) is generated from those same rows.

## What the binaries say about the TIO and TIOCP (established)

- **No TIO code.** The names `tio_init_xswitch_widgets` and `Tio_brick_map_widget` occur in `kernel.o` of the IP35 boot
  set, but only in its debug name tables. The object has no text symbol with either name, no call to either and no
  relocation against either: the routines were compiled out of this build or belong to a kernel for another platform. A
  search of every IP27 and IP35 object, member and firmware image for the strings `tio_`, `Tio_`, `TIO_` and `tiocp`
  finds `tiocp.h` as a header name in the debug line tables of `kernel.o`, `pcibr.o`, `pciio_ppb.o` and `xbridge.o` in
  both builds, and of `pic.o` and the USB driver in the IP35 build (the IP27 set has `usrpci.o` in the same position). A header the compiled code includes; its contents are not in the binaries.
- **The software enumeration names it.** The debug type information of `space.o` (a member of `os.a` in both the IP27 and
  IP35 boot sets) defines an enumeration `pciio_asic_type_e` with the values UNKNOWN 0, MACE 1, BRIDGE 2, XBRIDGE 3, PIC 4
  and TIOCP 5. This is the PCI I/O layer's own numbering, not the halfword at record +114 that the accessors test (0 to 3),
  so the two must not be conflated. The IP27 build carries the same enumeration, so the name is evidence that a driver could
  be written for the chip, not that the machine has one.
- **TIOCP in the shared accessors.** The `pcireg_*` routines of `pcibr.o` branch on the halfword at record +114 (3 selects the
  fourth chip) and, for a raw pointer, on part `0xe000` or `0xe010` with manufacturer id 36. Every such branch uses the
  same 64-bit layout as PIC. The census differs from the PIC rows in one register: `+0x48`
  (`pcireg_llp_cfg_get` and `pcireg_llp_cfg_set`) is reached only on the PIC path. In `pcireg_llp_cfg_get`
  (`pcibr.o` `0x10bb4`, read in full) a record with chip type 3 branches to a `panic` call (at `0x10d18`), and so does a
  raw pointer whose part number is `0xe000` or `0xe010` with manufacturer 36; the message text was not read, so whether it
  says the register is undefined for the chip is unknown.

## Open

- Which product carries a TIOCP, and whether the register layout beyond the shared accessors matches PIC. Routes tried:
  the census of the shared accessors, a symbol and string search of the IP27 and IP35 boot objects and PROM images. Next:
  the public Altix-era headers in the pinned older Linux tree (`linux-ia64`, `tiocp.h`), read after the binary reading, for
  names to compare.
