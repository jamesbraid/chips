# MACE coverage

What the shipped software, the published specification and the public drivers settle about the MACE (the O2's I/O
ASIC), and what stays open. Register tables and routine readings are on [the chip page](../chips/mace/README.md); this
page grades the coverage questions that were open. Labels follow [AGENTS.md](../AGENTS.md): **established**,
**inferred**, **unknown**.

Sources: IRIX 6.5.30 IP32 `kernel.o` (`read_dallas_nvram`, `write_dallas_nvram`), `mhpckm.o` (`pckm_attach`, the
`mace_rev` variable), `if_me.o` (already on the chip page); the MACE I/O ASIC specification, chip revision 2.0, July
1996 ([docs/sources/specs](sources/specs/mace-specification.pdf)), page numbers as printed; public NetBSD
`sys/arch/sgimips/mace/macekbc.c`, `mcclock_mace.c`, `macereg.h`, `sys/dev/ic/ds1687reg.h`; Linux
`arch/mips/include/asm/ip32/mace.h`, `arch/mips/sgi-ip32/ip32-platform.c`, `drivers/rtc/rtc-ds1685.c`,
`drivers/input/serio/maceps2.c` and the VINO capture driver of a 2.6.33-era history tree (`drivers/media/video/vino.c`,
`vino.h`, merge commit `981a2edd1922`).

## `0x304018`: an alias of `0x300018` (established as far as the specification goes)

The peripheral controller is a 512 KB window split into eight 64 KB sub-blocks (specification Table 92, p. 181); the
audio registers are the first sub-block. The specification says, for the whole MACE, that "those registers that exist
are aliased, i.e. repeated, to fill the entire block" (chapter 12, p. 181), and for the ISA interface that gaps within a
block's range "are aliased to existing registers" (p. 122). `0x304018` is inside the audio sub-block, 16 KB above its
start, offset `0x18` from a 16 KB boundary. Whether the repeat period is the 128-byte register set or the 16 KB page,
`0x304018` lands on the register at `0x300018`: the codec status input, which the specification marks read-only. The
flush routine in `if_me.o` (`pioflush`) writes 0 twice and reads once; a write to a read-only register is discarded, so
the effect on the chip is a read of the codec status input after two ignored writes.

- Aliasing in the audio sub-block: **established** (specification, two places).
- That the alias target is `0x300018` specifically: **inferred** (arithmetic on either repeat period; the specification
  does not give the period).
- That IRIX uses it purely as a bus flush: **established** (the routine read in full).
- **Unknown:** whether the aliased read has any side effect on the codec status input. Test: read `0x300018` twice with a
  codec change pending and compare with a read at `0x304018`.

## Linux I2C offsets: no conflict, the structure is unused (established)

The chip page recorded that Linux's `struct mace_i2c` puts control and data at 8 and `0x10` while the specification and
IRIX put them at `0x10` and `0x18`. Two things settle it.

- The specification's I2C block has **four** words: configuration and reset at `0x330000`, a reserved alias of it at
  `0x330008`, control and status at `0x330010` and data at `0x330018` (register map transcription,
  [mace-specification.registers.md](sources/specs/mace-specification.registers.md)). Linux's structure has three words and
  omits the alias, so its offsets for control and data are wrong by one slot **if** it was meant as the register layout.
- It is not used. A search of the current Linux tree for the structure name and its bit constants finds them only in the
  header, where `struct mace_perif` embeds it; no driver dereferences it. The one SGI I2C driver Linux had was the helper
  for the VINO capture chip, and it drove VINO's own I2C controller, not the MACE's: the VINO driver's two registers
  (control at slot `0x18`, data at slot `0x20` of VINO's register file, each a 32-bit value in the low half of a 64-bit
  slot) carry the bits the IRIX MACE code tests: bit 0 bus not idle, bit 1 read, bit 2 hold bus, bit 4 transfer busy,
  bit 5 acknowledge not received, bit 7 bus error. IRIX's MACE I2C routines test bits 0, 4, 5 and 7 (`_mvpi2c_*`, chip
  page). The two controllers look like one design: **inferred** (a resemblance, not evidence for any MACE field).

So the offsets IRIX and the specification use stand unchanged; the Linux disagreement is closed with the finding that
Linux never reaches the MACE I2C block. What the configuration and reset word does is still **unknown**: IRIX never
writes `0x330000` and the specification says only "Config & Reset". Settling test: a published MACE specification page for the I2C block's configuration word; no binary route, since no held code writes it.

## `0x310000` bit 4 and `mace_rev`: tried, still unknown

`pckm_attach` (`mhpckm.o` `0x10`) reads the 64-bit word at `0x1f310000` once, sets the exported variable `mace_rev` to 1
when bit 4 is set and to 0 otherwise, and nothing else in the IP32 `*.o` objects references the variable (a symbol search
of every member; only `mhpckm.o` defines it). The specification (Table 53, p. 123) defines bit 0 as the external reset,
bits 14:1 as reserved read-as-zero, and bits 31:15 as the ring buffer base. Bit 4 is not described.

Routes tried and what they gave:

- The specification's PS/2 chapter (pp. 140 to 142): the status register's bit 6 is a parity error. No revision note.
- The host bridge revision register (`0x8000c`, p. 165): MACE 1.0 has host bridge revision 0 and MACE 2.0 revision 1.
  The bug list (p. 167) is for the host bridge revision 0 and says nothing about PS/2.
- NetBSD `macekbc.c` and Linux `maceps2.c`: neither reads `0x310000` bit 4 or tests a MACE revision. NetBSD's driver
  reads only the receive, control and status words.

**Hypothesis (inferred at best, fills no field):** bit 4 distinguishes the MACE revision whose PS/2 parity flag is
reliable, because IRIX's only use is to decide whether to act on status bit 6. **Unknown** otherwise. Discriminating
test: read `0x310000` and the host bridge revision at `0x8000c` on a MACE 1.0 part and a 2.0 part; the bit should track
the revision. Valid end state if neither part is measured: unknown, no further software route.

## Calendar-clock user RAM: base register and size established, the stride conflicts with the specification

`read_dallas_nvram` and `write_dallas_nvram` (`kernel.o` `0x12c28`, `0x12d00`, read in full) take (buffer, offset, length)
and return 1 unless `offset + length` is below `0x72` (114) and the offset is above 0. They first clear bit 4 of the
register at slot `0x0a` (`0x3a0a07`), which NetBSD's header names the DS1687 bank select (0 selects bank 0; **inferred**
that IRIX means the same), then move bytes one at a time at the
**consecutive** physical addresses `0x1f3a0e08 + offset + index`, last byte first.

- The base slot is register `0x0e`: `0xe08 >> 8 = 14` (**established** arithmetic). The public NetBSD header puts the
  first user RAM byte of the Dallas DS1687 at register 14 and its size at 114 bytes. The bound `0x72` is the same 114
  (**established** for both numbers; the chip being a DS1687-compatible part is **inferred**, from NetBSD's clock driver
  and Linux's `rtc-ds1685` platform data, both of which drive the MACE calendar clock as that part, with a 256-byte
  register step).
- The conflict: the specification says each 8-bit register spans 256 bytes and Linux and NetBSD both step 256 bytes per
  register and read the data in byte lane 7 (`(reg << 8) + 7`). IRIX steps one byte. If the register file really is at
  256-byte spacing, the IRIX loop reads register `0x0e` repeatedly (every address in its 256-byte slot decodes to it) and
  returns the same value for every index. Callers: no object or archive member of the IP32 boot set has an undefined
  reference to either routine (`nm` over every `.o` and every archive member), and `kernel.o` itself has no call
  relocation to either one (every relocation in both the 6.5-base and 6.5.30 IP32 `kernel.o` checked: the only references to the two
  symbols are in the debug sections). The stripped diagnostic (`ide`, IP32, 6.5-base) and monitor (`symmon`, IP32, 6.5-base) were
  searched for any address built from the upper half `0xbf3a` and a lower half in `0x0e00` to `0xffff` within 24 instructions
  (a scan of the code for `lui` followed by an add, or, load or store using the same register). The diagnostic forms only
  `0xbf3a0007` to `0xbf3a0c00`, `0xbf3a4a00` and `0xbf3a4b00`, the monitor only `0xbf3a4807`, `0xbf3a4a07` and `0xbf3a4b07`. Neither forms an address
  in `0xbf3a0e08` to `0xbf3a0e79`, the span the one-byte-stride loop covers. So no held IRIX code calls the two routines
  (**inferred**: the scan does not follow an address passed in a register from a caller or built across more than 24
  instructions, and the IP32 PROM, whose firmware segment is plain code at `0x81000000` but is not yet in the census, is not covered). The routines are unused
  in the shipped software and the stride conflict has no consequence for it.
- Test that settles the hardware side: write distinct bytes to user RAM registers 14 and 15 through the lane-7 addresses
  `0x3a0e07` and `0x3a0f07`, then read `0x3a0e08` through `0x3a0e0f` and `0x3a0f00`; a slot that aliases every byte
  address returns the same value everywhere.

## What else on the MACE open list this pass touched

| item | result |
|---|---|
| `0x304018` | settled above |
| Linux I2C offsets | closed, above |
| revision strap | unchanged, test given |
| calendar-clock user RAM spacing | base register and size established, stride conflict recorded with its test |
| the IP32 PROM, run-time pointer blocks, failure behaviour | not touched: the PROM census entry and the Ethernet, serial and video attach routines are separate software work |
