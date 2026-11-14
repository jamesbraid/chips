# TIOCE

Mode: **no-spec**. The TIOCE is a dual-port **PCI Express bridge** of the TIO generation: widget part number `0xce00`, source id 1, revision A = 1.
No specification is held. What the register header calls the CE ("CE Programmer's Reference Overview" is its source document) and the provider code
show the following. All facts are SGI's Linux Altix platform code (linux-5.3 pin 4d856f72c10e), so they are **established** as software definitions, never as
measurements. Registers: [registers.md](registers.md) (262 register entries and 190 named constants).

## What the code says it is

- **A PCIe root: two ports, each with a virtual PCI-to-PCI bridge (established).** The header defines a "CE Host Bridge" (vendor `0x10a9`, device `0x4001`) and a "CE Virtual
  PPB" (`0x10a9`, `0x4002`) and an array of two for every per-port resource (`TIOCE_NUM_PORTS`). The provider finds which port a device is on by reading
  the secondary bus number of the port-2 logical bridge at device 2 and comparing bus numbers. Each port has its own "LSI" link block (link
  layer, PHY receive and transmit, LTSSM, gearbox), its own downstream and upstream credit logic ("DTL" and "UTL"), and four INTx pins (A to D).
- **Blocks (established, register names).** `adm` administration (credits, interrupt status, mask, destination and force, error summary, timeouts, debug
  select), `lsi` link blocks at two bases, `crm` and `cxm` coretalk request and transmit modules, `dtl` and `utl`, `ure` the upstream request engine (credit,
  page map, direct maps, address translation entries, response and buffer flush registers), `dre` the downstream request engine, and several large
  diagnostic buffer windows (maintenance views of the upstream and downstream data and header buffers, 0x24000 and up).
- **It sits on a TIO widget (established).** The FPGA-port driver reads widget 3's identification word and treats part `0xce00` as a TIOCE to be left alone
  ([TIOCX](../tiocx/README.md)). The provider shares the PCI bridge error interrupt, vector `0x33`, with the PIC and TIOCP.

## DMA modes (established, provider)

Five flavours; the first two need no translation entry. Bus addresses are PCI Express addresses.

| mode | bus address window | mechanism |
|---|---|---|
| D64 | bit 63 set | bits 53:0 the coretalk address, bit 62 barrier, bit 61 message-signalled interrupt |
| D32 | `0x80000000` to `0xffffffff` | per-port direct map register holds the upper bits of the coretalk address with the low 30 bits cleared; low 30 bits from the bus address; a second user needs the same upper part |
| M32 | `0x0` to `0x7fffffff` | 32/40-bit translation entries 64 up (the first 64 are reserved for super pages), 256 KiB pages; interrupt-capable |
| M40 | `0x4000000000` to `0x7fffffffff` | 4096 entries of 64 MiB; not interrupt-capable |
| M40S | `0x8000000000` to `0xffffffffff` | 32 entries per port of 16 GiB (super pages); not interrupt-capable |

Entry format (both entry tables): bit 63 valid, bit 62 message-signalled interrupt, address in the high bits, page-aligned. The page size of the 32/40-bit pool is a field of the
upstream page map register; the provider sets 256 KiB, the largest it uses. A bug-compatible detail to question: the M40S window as written cannot hold the entries of
port 2 ([question](../../questions/altix-io-sn2-cross-check.md#tioce-m40s-window)).

## Register access workaround (established, provider; revision A only)

Erratum PV944642: on revision A, the kernel brackets every access to a register below `0x45000` with dummy reads. Before the access it reads one register chosen by the offset
(offset `0x0` or `0x80`: register `0xc0`; `0x148` or `0x200`: `0x28`; anything else: `0x158`). After it, when the offset is `0x100` it reads `0x38`, and for every offset
below the limit it reads `0xb050`. The header says "reads instead of writes" is acceptable per the hardware group. An emulator can ignore the workaround; software that follows it must find those registers readable.

## Interrupts (established)

Fifteen destination registers `adm_int_dest` indexed by source bit. Sources: bit 0 CE error, 1 and 2 link IP errors, 3 PCIe error, 4 and 5 hot-plug per port, 6 to 9 port 1
INTA to INTD, 10 to 13 port 2 INTA to INTD, 14 to 17 message slots, 22 and 23 power-management events. To retarget a line interrupt the provider sets the mask bit, writes
the destination (vector in bits 63:56, destination coretalk address below), clears the mask bit, then forces the interrupt through `adm_force_int` (bits 0 to 7 are INTA to INTD of each port, 8 forces
always). Revision A hardware cannot do that (erratum PV945826): the provider reads the interrupt status and, if the source is set, writes the interrupt data (`1 << 8` plus the kernel vector)
straight to the destination address with an ordinary store.

## Not covered

PCIe configuration space (the header lists a PCI compatible window from `0x04000000` and an enhanced window from `0x10000000`, constants `PIO_*`), the link-training states and every debug register: the
header names them; nothing is read. Reset values and access directions are **unknown**. Which Altix model carries a TIOCE: [question](../../questions/altix-io-sn2-cross-check.md#pic-versus-tio-by-product).
