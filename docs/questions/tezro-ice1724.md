# Tezro: the ICE1724 behind the TI bridge, and how IRIX attaches it

Extends [tezro-ti-bridge.md](tezro-ti-bridge.md) and [chips/ice1724](../../chips/ice1724/README.md).
Sources: IRIX 6.5.30 IP35 objects `mad_dd.o` (SHA-256 `905a72a7...1518`), `pciio_ppb.o` (`aadca7cf...1632`),
`pcibr.o` and `pciio.o`, read as instruction listings (nothing run); published `hinv` captures; the TI PCI2050
data manual SCPS053B.

## Placement (inferred)

Two Tezro captures list the bridge and `1412:1724` (both at "PCI slot 2"): one `hinv -mv` with a PCI serial board at
`xtalk/15/pci-x/1/2` (so bus 1 device 2 is taken and bus 0 device 2 is the bridge), one `hinv -vm`. A third bus
must hold the controller; the only bridge is the PCI2050. `ppb_device_init` (`0x530`) passes the secondary-bus device
number as the slot of each function it registers, which is why the listing prints 2. Confirming captures:
`ls /hw/module/*/IXbrick/xtalk/15/pci-x/0/2/`, `hinv -mvv`, a config dump of the bridge (`0x00`..`0x4f`).

## Bridge driver, exactly

- `pciio_ppb_attach` `0x1b40`: class `0xb` == 6 and subclass `0xa` in {0, 4}; then `ppb_scan`, `ppb_addr_space_assign`,
  `ppb_attach_function` (which calls `pciio_device_attach` per child, `0x1c78`).
- `ppb_bus_alloc` `0x1968`: 8-word bitmap in `.bss`+0x10, MSB first; `pciio_ppb_init` `0x1acc` reserves 0..15 and 255
  with `ppb_bus_reserve` `0x1a28`. First allocation is 16.
- `do_ppb_scan` `0x2d8`: writes config bytes `0x18`, `0x19` (`0x330`..`0x350`), then `0x1a` = secondary in a loop
  over ancestors (`0x41c`..`0x43c`); vertex `ppb_%d` (`0x36c`); probes devices 0..31 by `pciio_config_get_safe` of
  vendor ID at `(bus << 16) | (dev << 11)` (`0x458`..`0x490`); `ppb_device_init` registers each function with
  `pciio_device_info_new` (slot = device number, function `0xff` for single-function).
- `ppb_function_init` `0x6c0`: header types 0 and 1 only; BAR sizing by all-ones write; latency timer from `0x3e`
  (`max_lat*8`, else `0x20`, not for vendor `10a9`); sets command bit 2 if clear (`0xc90`..`0xca0`); counts a
  function with bit 2 set in the record halfword at `+0x6a` (`0xab0`..`0xabc`); nested bridges recurse and add
  their count (`0xb7c`..`0xbd4`).
- `function_addr_space_assign` `0xf40`: BARs, ROM (`0x30`), command |= 7 (`0x11cc`..`0x11e8`).
  `ppb_addr_space_assign` `0xcf8`: bridge config `0x1c`, `0x1d`, `0x30`, `0x32`, `0x20`, `0x22`, `0x24`, `0x26`,
  `0x28`, `0x2c`.
- **Multi-master check** (`ppb_scan` `0x84`..`0x2b4`): if `[record+0x6a] < 2` proceed. Otherwise
  `pciio_businfo_multi_master_get` on the bus above the bridge; zero and `pciio_multimaster_override` zero prints the
  three-line warning (strings at `.rodata` `0x0`, `0x20`, `0x60`, `0xa8`) and returns -1. This corrects
  [tezro-ti-bridge.md](tezro-ti-bridge.md) item 3, which stated the check unconditionally. `pcibr_businfo_get`
  (`pcibr.o` `0x44ec`): multi-master is 1 only when the record halfword at `+0x72` is 2 and the halfword at `+0x74`
  has bit 0 set; 0 for `+0x72` == 1.
- `pciio_ppb_intr_map` `0x1888`: table in `.data` `{1,2,4,8, 2,4,8,1, 4,8,1,2, 8,1,2,4}` indexed
  `(slot & 3) * 4 + pin`, applied up the chain of bridge infos (`+0x1f0`). INTA at device 2 behind the bridge at
  device 2 gives INTC, then INTA at the host slot.

## Audio driver (`mad_dd.o`)

- `mad_attach` `0x14c`: no device-number or subsystem-vendor test.
- `mad_create_subsys` `0x1e4`: sub-device ID at config `0x2e` vs `0x3630` selects `mad_init_revolution` (`0x368`) or
  four `mad_ac97_write` calls (`0x3a4`..`0x3d8`: reg `0x18`=`0x808`, `0x1a`=0, `0xe`=`0x8040`, `0x1c`=0).
  `mad_ac97_read` (`0x3158`) is called only from `mad_ac97_mute` (regs 2 and 4). No codec ID register is read, no
  GPIO or I2C access identifies a codec.
- No interrupt allocation: the import list has none; the mask registers are never written.
- `mad_start_dma` `0xe48`: `bzero(buf, [rec+0x220] << 2)` then `size = [rec+0x220] - 1` to `MT+0x14` (word),
  `MT+0x24` and `MT+0x44` (halfword, address xor 2).

## Answers to the emulation questions (2026-11-11)

Five questions came from a team running a model of this path. Their observations are model behaviour (a running guest on
an emulated chip), not hardware evidence. Sources: `mad_dd.o` as above, re-disassembled with relocations for this section;
IC Ensemble *ICE1724 (Envy24HT)* preliminary Rev. 0.91, 11/05/01 ("ICE DS"); TI *PCI2050 PCI-to-PCI Bridge Data Manual*
SCPS053B ("TI DS", the PCI2050B manual agrees on these registers); the public Linux `sound/pci/ice1712` driver (Linux 7.2-rc7).

1. **Writes to CCS `0x1b` and MT `0x17`.** What the driver sends is **established**; what the chip does with it is
   **inferred**. The driver has no byte store to either offset. `mad_set_eeprom` (`0x2f54`) assembles EEPROM bytes 10 to 12
   into bits 23:0 of one register and stores it with a single `sw` at CCS `0x18` (`0x2fe4`), so bits 31:24, which land on
   CCS `0x1b`, are zero. `mad_start_dma` (`0xe48`) stores `count - 1` with a single `sw` at MT `0x14` (`0xf98`), so MT `0x17`
   carries bits 31:24 of `count - 1`, zero for any buffer under 64 MiB. Both are the fourth byte of a 32-bit store, as
   suspected. Word stores keep the register's byte order; only byte and halfword accesses use the offset-xor-3 and xor-2
   lane rule, so these two bytes are not xor-3 images of some other byte register. ICE DS p. 4-9 makes CCS18 a 24-bit
   register (bits 22:0 defined) and p. 4-3 allows byte, word or dword CCS access; the MT14 count uses bits 18:0 (p. 4-19).
   The datasheet map has nothing at CCS `0x1b` or MT `0x17`, and states neither the write effect nor the read value.
   The reasoning for "ignored" is that an unassigned lane has no storage to update, and a write of zero is the
   reset value of any register that might sit there, so no outcome differs for this driver. A model should accept the write
   and drop it, and keep it observable in a log. Read value of those bytes: **unknown**. The driver was not searched
   exhaustively for reads of CCS18 or MT14 as words; the position code reads MT10, MT24 and MT40. Would settle it: a
   measurement on a real part, or a datasheet revision that defines the lanes.
2. **BARs 2 and 3 (config `0x18`, `0x1c`) size-probed.** **Inferred**: both read back 0 after an all-ones write, as
   unimplemented BARs do in the PCI base specification (hardwired to zero). ICE DS Table 3-1 (p. 3-1) lists both offsets as
   "-" with no register description, and the datasheet gives no read value. For the two implemented BARs the datasheet is
   explicit (**established**, ICE DS pp. 3-4 and 3-5): BAR0 bits 31:5 read/write, bits 4:1 read 0, bit 0 reads 1, so an
   all-ones probe reads `FFFFFFE1` (32 bytes); BAR1 bits 31:7 read/write, bits 6:1 read 0, bit 0 reads 1, so `FFFFFF81`
   (128 bytes). What the IRIX bridge driver does with a zero read-back was not read for this section. Would settle it: a
   config dump of a real controller, or the part's PCI configuration documentation.
3. **Subsystem ID, EEPROM, converter and codec parts on the Tezro: unknown.** `mad_dd.o` carries no per-board table. Its
   only board test is the sub-device word (config `0x2e`) against `0x3630` (`mad_create_subsys`, `0x28c`..`0x294`): equal
   selects the GPIO-serial converter path (`mad_init_revolution`), unequal runs four AC'97 register writes. Strings in the
   object name no codec, board or model. The public list gives `1412:3630` as M-Audio Revolution 7.1, and the public
   driver's Revolution 7.1 entry (`revo.c`, subsystem constant `0x12143036` in the EEPROM byte order) pairs it with an AKM
   AK4381 front and an AK4355 surround converter on GPIO chip selects and an AK5380 input, which is the shape the
   IRIX path programs. That identifies what the 3630 recipe drives; it does not show that a Tezro carries a 3630 part, and no
   public list, capture or Tezro document held here gives the Tezro's subsystem ID or EEPROM. The 17 front and 33 surround
   frames seen at attach are what the driver's 3630 recipe sends, so they say the model presented `3630` (or the driver
   took that path), not what the board holds. **Unknown**; the DM8 board uses the same path, which is the only
   board where it is known to run. Would settle it: a config dump of `0x00`..`0x3f` and the 19 EEPROM bytes from a real
   Tezro (not to be requested from owners; wait for a published capture), or a board photograph. Until then a model must
   state its choice of subsystem ID as a model choice.
4. **D3hot to D0.** **Established** (vendor text): ICE DS p. 3-7 says a transition from D3hot to D0 "will generate an
   internal reset (incl. PCI config. space)", and that D0 is the state after power-up or internal reset. So the reset covers
   both the registers and the configuration header, and the header returns to its defaults, including the BAR base
   addresses and the command register, so the BARs must be reprogrammed. The datasheet does not say what happens to
   the strapped fields (CCS04 to CCS07 and the subsystem IDs) in that reset, whether the EEPROM is read again, or whether
   the power state bits read back as D0 afterwards. The IRIX driver never writes the PM control register, so none of this
   is exercised by it.
5. **TI PCI2050 prefetchable-upper registers.** **Established** for the register shape: config `0x28` (prefetchable base
   upper 32 bits, TI DS p. 4-12) and `0x2c` (limit upper 32 bits, TI DS p. 4-13) are full 32-bit read/write registers
   with reset value `00000000`, so both read 0 until written and read back what was written. The manual says to program
   them to zero when 32-bit addressing is used. The prefetchable base and limit at `0x24` and `0x26` (pp. 4-11, 4-12) have
   their low four bits read-only and defined as reading 0. In the PCI-to-PCI bridge specification the 64-bit
   capability is advertised as `1h` in those bits, so a 0 there means 32-bit-only (**inferred**; the specification is not
   held here). The manual never says the bridge accepts dual-address cycles: its command table lists code `1101b`
   (Table 3-1, p. 3-2) and then says the remaining commands address memory, I/O or configuration, without
   claiming it for the part. So a 64-bit prefetchable window is **not supported on the evidence held (inferred)**; the
   registers store a value, and whether the bridge forwards above 4 GiB is **unknown**. The IRIX bridge driver reads `0x24`
   back to test 64-bit support (see above), so a model with those bits at 0 steers it to the 32-bit path. Would settle it:
   a read of real bridge registers, or an errata sheet.

## Unknown

Codec parts, subsystem IDs, EEPROM image, whether anything else sits behind the bridge, the primary bus number
written to `0x18` (`pciio_info_bus_get` of the bridge), the bridge variant. Audio libraries are not held in any
local root (searched `chips` and `kudzu` roots, depth 6).
