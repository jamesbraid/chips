# Inbound DMA on SHub 1: from a PIC bus master to node memory

What happens when a PCI or PCI-X device behind a PIC reads or writes main memory on an Altix 350 (SHub 1): how the PIC turns the bus address into a Crosstalk address, what the packet looks like, what the SHub's I/O interface (II) does with it, and how software knows the data has landed. The outbound direction (processor loads and stores to the PIC) is on the [II page](README.md) and the [PIC page](../pic/README.md); the interrupt direction is on the [SHub interrupt page](../shub/interrupts.md#where-a-pic-interrupt-lands-on-shub-1).

**Labels.** As in [AGENTS.md](../../AGENTS.md): *established* is read in full from a binary, a published specification page or public driver code; *inferred* is a reasoned reading, with the reasoning given; *unknown* is not settled, with the route that would settle it. No SHub 1 specification is held, so everything about the II's own behaviour is software-derived at best. The Bridge, XBridge and Crossbow specifications describe sibling chips: where they are used below they state a hypothesis for the PIC, not a fact about it.

**Sources.**

| Short name | What |
|---|---|
| Linux SN2 | SGI's Altix platform code in Linux (`arch/ia64/sn/pci/pcibr/pcibr_dma.c`, `pcibr_ate.c`, `pcibr_provider.c`, `arch/ia64/include/asm/sn/pcibr_provider.h`, `pic.h`, `shubio.h`, `io.h`, `drivers/ide/sgiioc4.c`), read at the Linux history repository commit `981a2edd1922`. The PIC page pins the same files at v5.3 (`4d856f72c10e`); these were not diffed against each other. Public, GPL |
| PROM 10.54 | the SHub 1 firmware image `shub1snprom.bin` of SNPROM 10.54 (SAL 5.04), read in Ghidra with this repository's IA-64 processor, addresses as the PROM loads |
| Bridge 4.0 | SGI, *Bridge ASIC Specification*, revision 4.0, 27 March 1997 (printed page numbers below) |
| XBridge 0.5 | SGI, *XBridge ASIC Specification*, revision 0.5, 1 October 1998 |
| Crossbow 12.0 | SGI, *Crossbow ASIC Specification*, revision 12.0, 14 November 1996 |

## The path in one table

| Step | Where | What | Grade |
|---|---|---|---|
| 1 | PCI device | issues a memory read or write at a PCI address | |
| 2 | PIC | classifies the address: `0` to `0x3fffffff` local, `0x40000000` to `0x7fffffff` translated through the 1024-entry table, `0x80000000` to `0xffffffff` direct window, above 4 GiB 64-bit direct | established (Linux SN2 constants; Bridge 4.0 section 4.3.1, same split) |
| 3 | PIC | forms a Crosstalk request: destination widget, 48-bit address, attribute bits (barrier, coherent, prefetch or precise read, byte enables, size) | established for the inputs; the packet itself inferred (below) |
| 4 | Crosstalk link and Crossbow (widget 0) | carries it to the SHub's widget | established that a crossbar is in the path ([crossbow](../crosstalk/README.md)) |
| 5 | SHub II | checks the inbound widget and device masks, allocates a request buffer (CRB), turns the Crosstalk address into a node memory access | the masks and CRB layout established as definitions; the address decode inferred |
| 6 | SHub memory side | performs the read or write, with coherence against processor caches | unknown in detail (no SHub specification) |
| 7 | back | a read returns a response packet with the same transaction number; a write has no response | inferred from Bridge 4.0 Table 53 |

## 1. Address translation on the PIC side

### What the Crosstalk address is

The kernel's DMA view of a physical address (`PHYS_TO_DMA`, [address map](../../platforms/sn2/address-map.md#dma-addresses-seen-by-bridges)) drops the region and address-space bits and moves the node number down two bits. For the shift of 38 the firmware reports, the result is

| Bits | Content | Grade |
|---|---|---|
| 47 | clear for memory. Set for the register window: the interrupt address the kernel builds is `nasid << 36 \| 1 << 47 \| offset of the II interrupt register` | bit 47 construction established (2.4 kernel, [interrupt page](../shub/interrupts.md#where-a-pic-interrupt-lands-on-shub-1)); "register space" meaning inferred; what a DMA with bit 47 set does is unknown |
| 46:36 | NASID (11 bits). Node bit 0 of the NASID sits where bit 36 of a processor address would be, so the NASID's low two bits take the place of the address-space bits | established as the macro; the PROM computes the same: the PIC attach helper `0xffb6bd50` takes the NASID from the window pointer (bits 48:38), shifts the field down two places and uses that as the base |
| 35:0 | byte offset within the node's memory (64 GiB) | established as the macro |

Not read: what the II does with the two NASID bits that overlap the address-space selector. The processor side selects cached memory with AS = 3 ([address map](../../platforms/sn2/address-map.md#anatomy-of-a-node-address)); an inbound DMA has no AS field of its own, so the II must choose the memory space itself. It is inferred to be ordinary (cache-coherent) memory, since DMA to AS 0 would reach registers. **Unknown**; a SHub 1 specification or an II trace would settle it.

### The four ways a PCI address reaches memory

| Window | PCI address | How the Crosstalk address is formed | Attribute source | Grade |
|---|---|---|---|---|
| Local | `0` to `0x3fffffff` | no mapping (PIC's own space) | none | established (constants); Bridge 4.0 Figure 4 |
| Translated (ATE) | `0x40000000` to `0x7fffffff` | entry index = (address minus `0x40000000`) >> I/O page shift; Crosstalk address = entry page address (bits 47:12) plus the offset inside the page; target = entry bits 11:8 | entry bits 4:0; PCI address bit 29 selects swap | established (Linux SN2; Bridge 4.0 section 4.3.4) |
| Direct, 32-bit | `0x80000000` to `0xffffffff` (2 GiB) | `(dir_off << 31) + (address & 0x7fffffff)`; target = dir_w_id | Device(n) register bits; one direct-map register shared by all devices | established for the form (Bridge 4.0 Table 45 and section 4.3.3; Linux `pcibr_dmatrans_direct32`); the formula for the PIC inferred from the PROM's use of it (below) |
| Direct, 64-bit | above 4 GiB | the low 48 PCI address bits are the Crosstalk address unchanged | bits 63:54 of the address itself | established (Linux `pcibr_dmatrans_direct64`; XBridge 0.5 Tables 87 to 89, Bridge 4.0 Tables 46 to 49) |

### Direct-map register (`+0x80`)

Fields: `dir_w_id` bits 23:20, `dir_add512` bit 17, `dir_off` bits 16:0 ([PIC registers](../pic/registers-extra.md), `DIR_MAP_REG`). `dir_off` counts 2 GiB units of Crosstalk address (bit 0 is address bit 31). Bit 17 adds 512 MiB and applies only when `dir_off` is 0 (Bridge 4.0 section 4.3.3; a MIPS kseg convenience).

What the SHub 1 PROM programs, from the attach helper `0xffb6bd50` and the setters it calls (`0xffab7af0` for the offset, `0xffab7850` for the widget, `0xffab7e50` and `0xffab8110` for bit 17; the setters first identify the chip from the identification word, part `0xd102` or `0xd112`, manufacturer `0x24`): **established**.

| Quantity | Value | Where from |
|---|---|---|
| Target node | the PIC's own node when a node-record halfword equals `0x700` (the field is filled by `0xffac0420(nasid)`; what `0x700` denotes is unknown); otherwise the lowest even NASID that has an entry in the node table and whose memory size is nonzero. The size routine `0xffa788b0(n)` reads one MMR at `nasid << 38 \| 0x8000000900010010` and sums four bank fields | established for the code; role of `0x700` unknown |
| Base `x` | `(nasid << 38 & 0x1ffc000000000) >> 2`, that is `nasid << 36` | established |
| `dir_off` | `x >> 31`, that is `nasid << 5` | established |
| `dir_w_id` | the byte at node-record `+0x60`, also copied to `+0x100` | established that it is that byte; that it is the SHub's own widget number is inferred: the earlier `main_three` PIC set-up writes the II widget-control `wid` field (bits 3:0, 8 to 15 on this machine) there, `0xffab0d7c` to `0xffab0d9c` |
| `dir_add512` | set only when `x == 0x20000000`, which no `nasid << 36` equals, so it is cleared | established |
| Recorded for the kernel | `x & ~0x7fffffff` at record `+0x58`; the kernel's `pbi_dir_xbase` is inferred to be this word | the field name inferred; Linux reads the value from a PROM-built record |

So a 32-bit direct DMA reaches the first 2 GiB of the node offset space of the chosen node. Memory above that offset needs the translated window or 64-bit addressing. The PIC attach also zeroes the direct-map register first (`0xffab0d6c`, earlier stage).

### Translation entries

Table: `p_int_ate_ram`, 1024 doublewords at PIC `+0x10000`. There is no external entry RAM on the PIC (the Bridge's `+0x80000` array has no PIC counterpart; Bridge 4.0 section 4.3.4 has 128 internal entries and up to 64K external). The PROM stores the count `0x400` in the node record at the start of the attach and later writes zero to every entry, so all start invalid (`0xffb6e5ac`, established).

| Bits | Name | Meaning | Grade |
|---|---|---|---|
| 0 | `V` | valid | established (Linux `PCI32_ATE_V`) |
| 1 | `CO` | coherent (PIC only; the same bit is "PIO" on the TIOCP) | established as a declaration; effect unknown |
| 2 | `MSI` | message-signalled interrupt write | established as a declaration |
| 3 | `PREF` | prefetch (reads) | established |
| 4 | `BAR` | barrier (set in the Crosstalk command word) | established |
| 11:8 | target widget | the hub's Crosstalk widget id (`pbi_hub_xid`) | established |
| 47:12 | address | page address in the Crosstalk view above; the kernel stores the address with its flags in the low bits and increments it by one I/O page per entry | established |

The Bridge's entry has a precise bit at position 2 and a coherent bit at 1 (Bridge 4.0 Table 52). The PIC header names bit 2 as MSI and defines no precise bit, so a PIC cannot request a precise read through a translated mapping (inferred from the absence; a sibling chip is not evidence).

The I/O page size is PIC control bit 21: clear 4 KiB, set 16 KiB. The PROM clears it in `pic_attach2` (the control write that masks `0xffffffffffdfffff`), so firmware pages are 4 KiB. The kernel sets it for a 16 KiB kernel page size (`pcibr_bus_fixup`). Entries therefore span 4 MiB (4 KiB pages) or 16 MiB (16 KiB pages) of the 1 GiB translated window. In the translated window PCI address bit 29 selects byte swap, set by the kernel only when the device's Device register already has `swap_direct`; the index is the address bits below that.

### 64-bit direct attributes

The top 16 bits of a 64-bit direct address carry attributes. The Altix header's declaration, with the spec's:

| Bit | Linux SN2 name | XBridge 0.5 Table 87 | Bridge 4.0 Table 46 | Notes |
|---|---|---|---|---|
| 63:60 | target widget | target id | target id | the kernel adds `pbi_hub_xid << 60` |
| 59 | `PREF` | prefetch | prefetch | streaming mappings; masked off in PCI-X |
| 58 | `PREC` | precise | precise | defined; no kernel path sets it |
| 57 | `VIRTUAL` | virtual request | virtual request | the kernel sets it for PCI functions other than 0 in conventional PCI mode |
| 56 | `BAR` | barrier | barrier | set for consistent (descriptor) mappings |
| 55 | `SWAP` | swap | remote map field (55:48) | defined; the kernel never sets it |
| 54 | `VIRTUAL1` | unused | part of remote map | defined; never set |

Established as declarations. In 64-bit mode only a few attributes come from the Device register (swap, coherent, GBR on the sibling chips: Bridge 4.0 Table 49). What the SHub does when the coherent bit is clear is unknown.

### Which window Linux SN2 uses

`pcibr_dma_map` (`pcibr_dma.c`): a device mask below `0x7fffffff` gets no mapping (returns 0). A full 64-bit mask (`~0`) gets 64-bit direct with `PREF` (streaming) or `BAR` (consistent). Anything between gets 32-bit direct if the PIC is in conventional PCI mode and the address lies in the 2 GiB starting at the PROM's base; otherwise a run of translation entries with `PREF` (streaming) or `BAR` (consistent), never in PCI-X mode (the PIC cannot page-map 32-bit addresses there, and the direct window is refused too). Established.

For the Altix 350's two main DMA masters: the IOC4's ATA engine uses 32-bit PCI addresses (the IDE layer's default mask; the driver sets none, inferred from `sgiioc4.c`), so on a PCI-mode bus it takes the direct window when the buffer's node offset is under 2 GiB and translation entries otherwise. The QLogic ISP 12160 on the IO9 card sets a 64-bit mask when the host supports one; whether the card's bus is in PCI or PCI-X mode on a running machine is not in the sources read. **Unknown.**

### What the PROM programs (and what it does not)

All establishing reads are the attach routine `pic_attach2` (`0xffb6d9c0`), the Device routine `0xffb37e70` and the `main_three` PIC set-up `0xffab0c00`.

| What | Value | Site | Grade |
|---|---|---|---|
| Direct map | as above | `0xffb6bd50` | established |
| Translation entries | 1024 written 0 | `0xffb6e5ac` | established |
| Control | bit 21 cleared (4 KiB pages), bit 31 set, bit 29 set unless revision 1, bit 30 cleared for revisions 1 to 3, bit 9 cleared, bits 62:61 and 42:40 cleared, bits 55:48 rewritten | `0xffb6d9c0`, `0xffab0d2c` | established; the PIC page has the full table |
| Device(n) | bit 27 cleared, bit 25 set (bits 27 and 25 cleared for revision 1), **bit 18 (prefetch) set**, bit 13 (`dev_swap`) cleared, bit 12 set except for slot 3, bits 11:0 from the slot's direct-mapped window; **bits 19 (`swap_direct`), 17 (precise), 16 (coherent), 15 (barrier) and 14 (GBR) are kept as read** | `0xffb37e70` | established for the operations; the values left in 19 to 14 are whatever the chip held |
| Response buffers | `0x88889999` to `+0x280` and `+0x288` | `0xffab0dcc`, `0xffab0dec` | established |
| Link credits | PIC control bits 15:12 and the crossbar's link entry, from a table keyed by widget part | `0xffab0130`, table `0xffbe10e0`; [II page](README.md#x-widget-0-and-link-window-accesses-not-ii-registers) | established |

The PROM maps nothing in the translated window and sets no 64-bit attributes; those are the kernel's. It does not write the swap, precise, coherent or barrier Device bits, so the values the kernel finds in `pbi_devreg` are the reset values (unknown) or whatever an earlier stage left.

### Barrier, prefetch, precise and the read buffers

From the sibling specifications; **inferred for the PIC** unless noted.

| Attribute | Effect | Source |
|---|---|---|
| precise | the PIC issues a doubleword read for exactly the enabled bytes; never combined with prefetch | Bridge 4.0 section 5.3.1.1 and the programmer's note in section 4.3.1 |
| neither | a single 128-byte cache-line read; buffer freed after one bus tenure | Bridge 4.0 section 5.3.1.2 |
| prefetch | a cache-line read, then incremental line reads into the device's free buffers up to a page boundary (4 KiB or 16 KiB); the buffer stays valid across tenures | Bridge 4.0 section 5.3.1.3 |
| barrier | sets the barrier bit of the command word of the request | Bridge 4.0 Table 47 |
| coherent | sets the coherent bit of the command word | Bridge 4.0 Table 47 |
| virtual request | picks one of two buffer groups per device, so a descriptor read does not flush a data stream | Bridge 4.0 section 5.3.1.5 |
| writes | a write never asks for a response; unaligned or partial transfers are cut into quarter-line packets or gathered when `dir_wrt_gen` is set; "do not assert precise or prefetch on a write" in 64-bit mode | Bridge 4.0 sections 4.3.1 and 5.3.2 |

Read buffers: a read from a device with no response buffer assigned is retried forever, with no error (Bridge 4.0 programmer's note, printed p.73). The PROM assigns four buffers to each of the first two slots through the even and odd response-buffer registers ([PIC page](../pic/README.md#prom-set-up-of-a-pic-in-main_three-0xffab0c00), row 8). Whether the PIC behaves the same is inferred.

## 2. Crosstalk packet formats

All three Crosstalk specifications describe the same packet; [crosstalk/packets.md](../crosstalk/packets.md) is the long form. What the DMA path needs:

**Command word** (32 bits; Bridge 4.0 section 3.2.9 Table 15 and Crossbow 12.0 Table 12, which agree; the Crossbow's introductory Table 1 puts the transaction number and type at different positions and is wrong by comparison with the other two): destination widget 31:28, source widget 27:24, packet type 23:20, transaction number 19:15, coherent 14, data size 13:12, GBR 11, virtual backplane message 10, error 9, barrier 8, 7:0 reserved. Established.

| Packet | Header | Data | Notes | Grade |
|---|---|---|---|---|
| Write request, no response (DMA write; type `4` by name) | command word; remote map field 31:16 (0 on the XBridge in every mode, so inferred 0 for a PIC); address 47:0; data enables | 8 bytes (DS 0, with an 8-bit enable word), 32 bytes (DS 1, a 32-bit enable word, four doublewords) or 128 bytes (DS 2, no enables) | the Crossbow's micropacket table lists no row for type 4 above a doubleword, so the wire type of a 32 or 128 byte DMA write is unknown | layout established (Crossbow 12.0 Tables 1 and 2, Bridge 4.0 section 7.2); type for DMA writes inferred; size table gap noted in [packets.md](../crosstalk/packets.md#36-packet-sizes-in-micropackets) |
| Read request (type `0`) | the same two header doublewords (inferred) | none | a precise read is DS 0 with an enable byte mask; other reads are DS 2 (128 bytes) | type value established; the header layout of a request without data unknown |
| Read response (type `1`) | command word, then data | DS 0, 1 or 2: one, four or sixteen data doublewords (8, 32 or 128 bytes); micropackets 1, 3 or 9 (Crossbow 12.0 Table 25) | carries the request's transaction number; whether it repeats the address is unknown. The PIC checks the data size against the sideband head and tail marks and reports a mismatch as a bad response | established for counts; the rest inferred from Bridge 4.0 Tables 53 and 54 |
| Write response (type `3`) | command word only | none | a PIC never asks for one, so receiving one is an error (`UNEXPECTED_RESP`) | established for the Bridge (Table 53); the PIC inferred |

**Transaction numbers the Bridge generates** (Bridge 4.0 section 7.3, printed p.88; **inferred for the PIC**): a read uses the number of the response buffer it holds, `0x00` to `0x0f`; a PCI write uses `0x10` plus the device number, `0x10` to `0x17`; an interrupt write uses `0x18` plus the device number for a pin and `0x1f` for an error interrupt. A response buffer number above 15 is an error. The II's request record keeps a 5-bit transaction number and the source widget (`crb_a` fields `tnum` and `sidn`), which is the same width.

**Sizes at a glance.** Write: 8, 32 or 128 bytes. Read: 8 (precise) or 128 (other); the prefetcher issues consecutive 128-byte reads. The Bridge's inbound request buffer holds three line or quarter-line writes or fifteen reads and doubleword writes, and the crossbar is told to give it three buffer locations (Bridge 4.0 section 5.2). The Altix PROM gives the PIC three request credits through its table entry. Inferred equal for the PIC.

## 3. The SHub II inbound side

The II is the SHub's Crosstalk port ([overview](README.md)). The header defines the following for inbound traffic. Everything below is the header's definition (established) with roles inferred from names and comments, except where marked.

| Register | Offset | Role for inbound DMA | PROM 10.54 | Reset |
|---|---|---|---|---|
| `inbound_widget_access` (IIWA) | `0x400118` | one bit per source widget: bit 0 widget 0, bits 15:8 widgets 8 to 15. A request from a widget is accepted only if its bit is set. Software uses it to fence off a misbehaving widget. Replies coming in from Crosstalk are not checked | `0xff01` at `0xffab30e0` | unknown (the Bedrock sibling resets to 0) |
| `inbound_device_error_mask` (IIDEM) | `0x400120` | eight bits for each of widgets 8 to 15, one per DMA master (device) behind it. A request passes only if both its device bit here and its widget's IIWA bit are set. The II clears a device's bit itself when it detects an error that requires shutting the device down. The header assumes transaction numbers 0 to 7 are the device numbers ("Bridge-centric") | **no write found** in the routines traced (`0xffaad720`, `0xffab1cc0`, `0xffab34b0`) | unknown. The Hub and Bedrock siblings reset to all ones (established for those chips), so a model that powers up with every device enabled matches the sibling. The PROM works without writing it, which is consistent with all ones |
| `outbound_widget_access` (IOWA) | `0x400110` | not inbound: qualifies PIO and graphics writes the II launches | `0xff01` | unknown |
| `widget_control` (WCR) | `0x400020` | `wid` bits 3:0: the SHub's own widget number, the target of every DMA; the PROM reads it back to set the PIC's direct-map widget; destination credits 15:13 (PROM leaves 4) | `wid` set by `0xffab33e0`; credit by `0xffab3580` | unknown |
| `wrapper_control` (IWC) | `0x400250` | bit 0 `dma_byte_swap`; bits 32:28 and 40:36 the network reply and request queue depths, bits 49:44 the inbound queue depth; force-credit bits 63:62 | bit 0 cleared by read-modify-write at `0xffaad9f6` | unknown |
| CRBs (`crb_a` to `crb_e`) | `0x400400 + 0x30 n`, n = 0 to 14 | the table of 15 request buffers used for Crosstalk operations (cache-line and partial) and BTE/IO. An inbound request from Crosstalk is recorded with initiator 0 (Crosstalk) and incoming message type 0. Entry A holds valid, I/O-write, the 47-bit address, the transaction number and the source widget; C the size, coherent, GBR, response-required and barrier flags; D the partial address and byte enables, BTE flag and priority counters; E the timeout and context | all 15 entries written 0, five doublewords each, at `0xffab1cc0` | "only valid, priority count, timeout, timeout valid and context valid are initialised at reset" (header text) |
| `crb_management` (ICMR) | `0x4003a8` | valid vector (bits 34:20), error-mark vector (bits 49:35), spurious-message flag; writing it while CRBs are active is dangerous | not touched | unknown |
| `crb_control` (ICCR) | `0x4003b0` | software control of the table, with priority over incoming Crosstalk and BTE requests | not touched | unknown |
| `crb_deallocate` (ICDR) | `0x400390` | returns a marked entry to the free list after software has cleared its mark | not touched | unknown |
| `crb_timeout` (ICTO), `crb_timeout_prescaler` (ICTP) | `0x4003b8`, `0x4003c0` | the maximum timeout and the divider for the per-entry counters | prescale `0x1fffff` at `0xffab1cc0` | unknown |
| `ioq_fifo_depth` (IFDR), `iiq_arbitration` (IIAP) | `0x400398`, `0x4003a0` | debug depth of two internal queues and a slow-drain mode of the inbound queue | not touched | unknown |
| `error_packet_header_1`, `_2` (IIEPH1, IIEPH2) | `0x400220`, `0x400228` | capture the header flit of an erroneous incoming network packet | written 0 | unknown |
| IPRB 0 and 8 to F, IPRTE 0 to 7 | `0x400198` to `0x4001d8`, `0x400308` to `0x400380` | **not inbound.** Both are the outbound PIO tracking: request buffers per widget and the table of outstanding PIO reads. Credits and ordering for processor loads and stores live here, not for DMA | cleared or bit 42 set | |

**Request buffer allocation.** The header says the table serves "Crosstalk operations (both cache-line and partial operations) or BTE/IO" and that the first error from a DMA write by a given device, or from a given BTE stream, leads to a marked entry. Nothing says how an entry is chosen; whether a write holds an entry until memory acknowledges it (and so how many DMA writes may be in flight, up to 15) is **unknown**. For a cache-line write the entry's fields (`wb`, `intvn`, `ack_cnt`, `hold`, `stall_ib`) point at a directory protocol with invalidation acknowledgements, which is **inferred** from the names only.

**Memory access.** The II presents a cache-coherent memory access to the node selected by the NASID in the Crosstalk address (above). Whether that is a full-line write that invalidates sharers or a read-modify-write of a partial line, and whether the coherent attribute changes anything, is **unknown**. The processor-side special spaces (fetch-and-op, AS 2) are unrelated to DMA.

**Access errors.** From the header and the existing pages:

| Condition | Visible effect | Grade |
|---|---|---|
| Widget bit clear in IIWA or device bit clear in IIDEM | the request is refused. What the requester sees (error response, silent discard or an interrupt) is unknown for a write; for a read an error response is inferred | refusal established as the header's purpose; outcome unknown |
| First write error from a device, or an error response from memory (directory error, poison, write error, access error, partial read or write error, timeout, incoming packet with its error bit) | the entry is marked, `errcode` (3 bits) says which: 0 directory, 1 poison, 2 write, 3 access, 4 partial write, 5 partial read, 6 timeout, 7 Crosstalk error; an II interrupt goes out through `interrupt_destination` (level, PI, node) to register `0x1800090` or `0x1a00090` of that PI; the device's IIDEM bit is cleared; software reads the entry, clears the mark, and writes the entry number to ICDR | established as definitions (header comments and the codes in `registers.toml`); the sequence of events inferred |
| No kernel path reads the CRBs for a DMA error. The BTE error handler reads them for BTE entries only; PIC error interrupt vector `0x33` is serviced by firmware | | established ([README](README.md#what-the-kernel-actually-uses)) |
| A read response with the error bit set reaches the PIC as `RESP_XTALK_ERROR`; what the PCI device is then told is unknown | | Bridge 4.0 Table 53; PIC inferred |

## 4. Completion and ordering

| Mechanism | What it does | Grade |
|---|---|---|
| Posted writes | a PCI write completes on the bus when the PIC accepts it; the data may still be in the PIC's write buffers (gather or write request buffer) or in the II. Nothing tells the device the data has reached memory | inferred from the Bridge's write buffering (Bridge 4.0 section 5.3.2) |
| Flush by interrupt (Linux `sn_dma_flush`) | after a non-relaxed programmed-I/O read from a PIC device (`__sn_inb`, `readl` and friends call it after `mf.a`) the kernel stores 1 to a per-device force address, then spins until the word the interrupt was aimed at reads `0x10f`. The interrupt reaches the II as a write to `SH_II_INT0` or `INT1` (address `nasid << 36 \| 1 << 47 \| register`), data inferred `0x100 \| vector`. Because it follows the device's DMA writes through the same PIC and the same link, its arrival means those writes have been accepted ahead of it. Addresses of the flush word and the force register come from the PROM. The relaxed accessors skip the flush | established for the kernel sequence and the constant (Linux SN2 `pcibr_dma.c`, `io.h`); the ordering argument inferred (the Bridge flushes a device's gathered writes and buffered reads when one of its interrupt pins fires: Bridge 4.0 section 5.3.2; whether a forced interrupt does the same is unknown) |
| Target flush register (`+0x50`) | a read returns zero only after earlier requests to the PIC from the host have completed. It orders processor-to-PIC traffic (ATE writes), not DMA | established for the kernel use (`ate_write`); Bridge 4.0 section 3.2.11 |
| Device write-request-buffer flush (`+0x240 + 8n`) | a read forces that device's buffered writes out. The kernel reads it only for the TIOCP, with the note that on the PIC it does not prove the data has entered the coherence domain | established as a comment |
| Barrier bit | orders a packet after earlier ones from the same source; set from the ATE `BAR` bit or the 64-bit address attribute; the kernel sets it for consistent mappings | established that it exists and who sets it; the wire guarantee unknown ([packets.md](../crosstalk/packets.md#44-ordering-barriers-and-flush)) |
| Responses first | a Bridge sends responses ahead of its own requests | Bridge 4.0 section 7.4 |
| Read results | a read response arrives later than posted DMA writes only if no flush intervenes; "In rare cases, the read response may beat the DMA" (kernel comment) | established as the vendor's own description |

Interrupt delivery order against DMA: an interrupt is a write packet from the same widget, so it cannot be seen before the packets queued ahead of it on one link in order. The model must therefore keep a device's DMA writes and its interrupt writes in one FIFO to the II. The hardware guarantee across the II to memory is unknown; the kernel does not rely on the data being visible in caches after an ordinary interrupt without the flush above.

## 5. The model's minimum

For a PIC bus master (an IOC4 ATA engine, a QLogic SCSI controller) to read and write node memory faithfully:

1. **PIC registers that must hold what is written** (plain 64-bit read/write cells; reads have no side effect except where noted): control (`+0x20`, page-size bit 21), direct map (`+0x80`), translation entries (`+0x10000` and 1023 more doublewords), Device(0..3) (`+0x200 + 8n`), response buffer map (`+0x280`, `+0x288`). A PCI read must not complete if no response buffer is assigned to its device.
2. **Direct 32-bit**: `xtalk = (dir_off << 31) + (pci & 0x7fffffff)`, target `dir_w_id`; **translated**: index from the page size bit, then entry fields as above, honouring `V`; **64-bit**: the address with bits 63:54 taken as attributes. Reject a write to an invalid entry as a PIC error (what error is unknown; do not guess a success).
3. **Crosstalk to memory**: take a request addressed to widget `wid` (II widget control bits 3:0), bits 46:36 as the NASID, bits 35:0 as the offset, bit 47 clear. Forward to the node's memory; a set bit 47 must not be treated as memory.
4. **II registers whose value matters**: IIWA bit for the source widget, IIDEM bit for the device number (the model may keep the Hub's all-ones reset and let the guest firmware write `0xff01` to IIWA, which the PROM does). Everything else in the CRB and wrapper space can be plain storage that the PROM writes and nothing reads, with the sole exception of the CRB mark and valid vectors if an error path is modelled.
5. **Ordering**: one FIFO per source for DMA writes and interrupt writes; the interrupt write completes after the data. The flush word (`0x10f` at the address the PROM chose) needs this and nothing else.
6. **Explicit gaps, not guesses**: coherence of a DMA write against processor caches (treat every inbound write as coherent), byte placement for the `swap_direct` and `dev_swap` bits (see the PIC page), write granularity at memory, and every error outcome above. Report an access the model cannot decode instead of answering it.

## 6. Unknowns, and what would settle each

| Unknown | Route |
|---|---|
| How the II turns the NASID bits and the missing address-space bits into a memory request; whether a bit-47 DMA is ever legal | an SHub specification or a trace of an II inbound packet |
| Reset values of IIWA, IIDEM, the PIC Device register coherent, precise and barrier bits | a read after power-on on a machine we hold (read-only, per the hardware rules) |
| What a refused or failed inbound write returns to the PIC and what a read returns | the same, or an II specification |
| PACTYP and header layout of 32 and 128 byte DMA writes and of read requests | a link capture, or the Crosstalk specification's packet chapter |
| The PIC's transaction number scheme | a PIC specification or a capture |
| What the PROM's node-record halfword `0x700` selects in `0xffb6bd50` | read the writer of record `+0x104` (`0xffac0420`) and its two table callees `0xffa80490`, `0xffa80270` |
| Whether the I/O buses of an Altix 350 run in PCI or PCI-X mode, and which window a real IO9 or IO10 uses | a boot log from a running machine |
| Whether a forced interrupt flushes the device's buffered writes | a PIC specification |
| Number of DMA writes in flight and the credit arithmetic in the II | an SHub specification |

## Reviews

Not yet reviewed.
