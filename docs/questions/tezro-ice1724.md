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

## Unknown

Codec parts, subsystem IDs, EEPROM image, whether anything else sits behind the bridge, the primary bus number
written to `0x18` (`pciio_info_bus_get` of the bridge), the bridge variant. Audio libraries are not held in any
local root (searched `chips` and `kudzu` roots, depth 6).
