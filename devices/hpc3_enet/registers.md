<!-- generated from devices/hpc3_enet/registers.toml by defs-gen - do not edit, change the source -->

# SGI HPC3 Ethernet DMA channels (Indy)

The receive and transmit DMA channels of the HPC3 peripheral controller, which move frames between main memory and the SEEQ Ethernet controller, with the layouts of the descriptor words they read and write. Offsets are from the start of the HPC3 register window; the HPC3 of the Indy sits at physical 1fb80000. Grades say how each item was derived: established means read in the HPC3 specification, a public driver or the shipped IRIX driver as the source records; inferred means a reasoned reading, with the reasoning in devices/hpc3_enet/README.md. Registers the specification does not list are marked as such.

Unit `hpc3_enet`, macro prefix `HPC3_ENET`.
Default source: HPC3 Chip Specification, revision 1.4, 22 January 1993.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| hpc3 | byte | Byte offsets from the start of the HPC3 register window. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `rx_cbp` | 0x14000 | r | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, p. 33 (address map) and p. 39 (field definitions) |
| `rx_nbdp` | 0x14004 | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, pp. 33 and 39 |
| `rx_bc` | 0x15000 | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, pp. 33 and 39-40 |
| `rx_cntl` | 0x15004 | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, pp. 39-40 |
| `rx_gio` | 0x15008 | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, pp. 33 and 39 |
| `rx_dev` | 0x1500c | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, pp. 33 and 39 |
| `enet_reset` | 0x15014 | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, p. 41 |
| `dmacfg` | 0x15018 | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, pp. 41-42 |
| `piocfg` | 0x1501c | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, pp. 41-42 |
| `tx_cbp` | 0x16000 | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, p. 34 (address map, read) and p. 43 (field text, read and write) |
| `tx_nbdp` | 0x16004 | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, pp. 33 and 43 |
| `tx_bc` | 0x17000 | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, pp. 33, 43 |
| `tx_cntl` | 0x17004 | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, p. 44 |
| `tx_gio` | 0x17008 | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, pp. 33 and 43 |
| `tx_dev` | 0x1700c | rw | 32 |  | hpc3 | unknown | established | HPC3 Chip Specification, revision 1.4, pp. 33 and 43 |
| `rx_cur_desc` | 0x18000 | rw | 32 |  | hpc3 | unknown | established | IRIX 6.5 base-release Ethernet driver object (initialisation and interrupt handler). Not in the HPC3 specification. |
| `tx_first_cur` | 0x1a000 | r | 32 |  | hpc3 | unknown | established | IRIX 6.5 base-release Ethernet driver object (transmit path and interrupt handler). Not in the HPC3 specification. |
| `tx_first_prev` | 0x1a004 | r | 32 |  | hpc3 | unknown | established | IRIX 6.5 base-release Ethernet driver object (transmit path and interrupt handler). Not in the HPC3 specification. |

### Register `rx_cbp`

Receive current buffer pointer. HPC3 loads it when it fetches a descriptor, so it names the buffer being filled.

### Register `rx_nbdp`

Receive next descriptor pointer. Software writes the physical address of the first descriptor here before it sets the channel active.

### Register `rx_bc`

Receive byte count and flags of the current descriptor. The count is read only to the programmed interface; the flags are read and written.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `eox` | established |  | HPC3 Chip Specification, revision 1.4, p. 39 | End of chain. After the descriptor carrying it, the channel stops. |
| 29 | `xie` | established |  | HPC3 Chip Specification, revision 1.4, p. 39 | Interrupt after this descriptor. The Ethernet channels act on it only when end-of-packet is also set. |
| 13:0 | `count` | established |  | HPC3 Chip Specification, revision 1.4, pp. 33 and 39-40 | Byte count of the current buffer. HPC3 writes back the bytes left after a frame; the programmed interface reads it. |

### Register `rx_cntl`

Receive control and status. The status bits are read only copies of the SEEQ receive status.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11 | `rbo` | established |  | HPC3 Chip Specification, revision 1.4, pp. 39-40 | Receive buffer overflow: a frame was longer than its buffer. How it is cleared is not settled; see devices/hpc3_enet/README.md. |
| 10 | `ch_active_mask` | established |  | HPC3 Chip Specification, revision 1.4, pp. 39-40 | Write only. Written one, it leaves the active bit unchanged in that store. |
| 9 | `ch_active` | established |  | HPC3 Chip Specification, revision 1.4, pp. 39-40 | One while the channel is active. Software writes one to start it, and HPC3 clears it when the channel stops. A store changes it only when the mask bit is written zero in the same store. Cleared by power-on reset. |
| 8 | `endian` | established |  | HPC3 Chip Specification, revision 1.4, pp. 39-40 | One for little-endian DMA, zero for big-endian. |
| 7 | `status_7` | established |  | HPC3 Chip Specification, revision 1.4, pp. 39-40 | Read only copy of the SEEQ old or new bit. |
| 6 | `status_6` | established |  | HPC3 Chip Specification, revision 1.4, pp. 39-40 | Read only. On its own, a late receive discard. With the bit 4 status set, an end-of-packet or interrupt timeout. |
| 5:0 | `status` | established |  | HPC3 Chip Specification, revision 1.4, pp. 39-40 | Read only copy of the SEEQ receive status bits 5 to 0. |

### Register `rx_gio`

Receive FIFO tail pointer, diagnostic. Normal software does not write it.

### Register `rx_dev`

Receive FIFO head pointer, diagnostic.

### Register `enet_reset`

Reset and interrupt control, shared by both Ethernet channels. The specification calls it misc.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `loopback` | established |  | HPC3 Chip Specification, revision 1.4, p. 41 | Drives the loopback pin of the Manchester encoder. Diagnostic. |
| 1 | `clrint` | established |  | HPC3 Chip Specification, revision 1.4, p. 41 | Read: the current state of the Ethernet interrupt. Written one: clears every Ethernet interrupt source except receive buffer overflow. |
| 0 | `ch_reset` | established |  | HPC3 Chip Specification, revision 1.4, p. 41 | Resets both Ethernet DMA channels and the SEEQ, by driving the SEEQ reset pin. Set at power-on. It must be zero before either channel is set active. |

### Register `dmacfg`

DMA timing and the SEEQ work-around enables. The timing fields reset to 1111 according to the specification; the other fields have no stated reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 17:16 | `fix_timeout` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | Timeout used by the fixes above. |
| 15 | `fix_intr` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | Work-around enable for the interrupt fix. |
| 14 | `fix_eop` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | Work-around enable for the end-of-packet fix. |
| 13 | `fix_rxdc` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | Work-around enable for the receive descriptor fix. |
| 12 | `wr_ctrl` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | Write each transmit descriptor's inter-packet gap byte into the SEEQ. |
| 11:8 | `d3` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | Cycle count D3. |
| 7:4 | `d2` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | Cycle count D2. |
| 3:0 | `d1` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | Cycle count D1. The specification says D1 is not implemented and always behaves as 1. |

### Register `piocfg`

PIO timing to the SEEQ. The timing fields reset to 1111 according to the specification; the other bits have no stated reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12 | `fifo_ram_test` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | FIFO RAM test mode. Diagnostic. |
| 11:8 | `p3` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | Timing field P3. |
| 7:4 | `p2` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | Timing field P2. |
| 3:0 | `p1` | established |  | HPC3 Chip Specification, revision 1.4, pp. 41-42 | Timing field P1. |

### Register `tx_cbp`

Transmit current buffer pointer. The specification gives the access as read in one place and read and write in another.

### Register `tx_nbdp`

Transmit next descriptor pointer. Software writes the physical address of the first descriptor here before it sets the channel active.

### Register `tx_bc`

Transmit byte count and flags of the current descriptor. The count and the end-of-chain sample bit are read only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `eox` | established |  | HPC3 Chip Specification, revision 1.4, pp. 33, 43 | End of chain. After the descriptor carrying it, the channel stops. |
| 30 | `eoxp` | established |  | HPC3 Chip Specification, revision 1.4, pp. 33, 43 | End of packet: the last buffer of a frame. |
| 29 | `xie` | established |  | HPC3 Chip Specification, revision 1.4, pp. 33, 43 | Interrupt after the frame is sent. |
| 28 | `eox_sampled` | established |  | HPC3 Chip Specification, revision 1.4, p. 43 | Read only. One once HPC3 has sampled the end-of-chain flag for the frame in progress, so software can tell whether clearing that flag on the old last descriptor came too late. |
| 13:0 | `count` | established |  | HPC3 Chip Specification, revision 1.4, pp. 33, 43 | Bytes to send from the current buffer. |

### Register `tx_cntl`

Transmit control and status. The status bits are read only copies of the SEEQ transmit status.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 10 | `ch_active_mask` | established |  | HPC3 Chip Specification, revision 1.4, p. 44 | As for the receive control register. |
| 9 | `ch_active` | established |  | HPC3 Chip Specification, revision 1.4, p. 44 | As for the receive control register. |
| 8 | `endian` | established |  | HPC3 Chip Specification, revision 1.4, p. 44 | As for the receive control register. |
| 7:5 | `status_7_5` | established |  | HPC3 Chip Specification, revision 1.4, p. 44 | Read only. The specification gives this field as a copy of the SEEQ transmit status bit 7; it does not split the three bits. |
| 4 | `status_4` | established |  | HPC3 Chip Specification, revision 1.4, p. 44 | Read only. Late collision: a collision after the first 80 bytes left the FIFO. |
| 3:0 | `status` | established |  | HPC3 Chip Specification, revision 1.4, p. 44 | Read only copy of the SEEQ transmit status bits 3 to 0. |

### Register `tx_gio`

Transmit FIFO tail pointer, diagnostic.

### Register `tx_dev`

Transmit FIFO head pointer, diagnostic.

### Register `rx_cur_desc`

Receive current descriptor pointer. The specification does not list it. The IRIX driver writes it at initialisation with the descriptor it marks end-of-chain, and reads it after the receive channel stops. How the hardware updates it is not settled; see devices/hpc3_enet/README.md.

### Register `tx_first_cur`

First descriptor of the packet in progress. The specification does not list it. The IRIX driver reads it. Its update rule is unknown.

### Register `tx_first_prev`

First descriptor of the previous packet. The specification does not list it. The IRIX driver reads it while the transmit channel is active, to reclaim transmit descriptors. Its update rule is unknown.

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `RX_DESC_CTL` | 32 | established | HPC3 Chip Specification, revision 1.4, pp. 6-7 and 14 |
| `TX_DESC_CTL` | 32 | established | HPC3 Chip Specification, revision 1.4, pp. 6-7, 13-14 |

### Word `RX_DESC_CTL`

Word 1 of a receive descriptor, the count and flags that HPC3 writes back when a frame has been stored.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `eox` | established |  | HPC3 Chip Specification, revision 1.4, pp. 6-7 and 14 | End of chain. The channel stops after this descriptor. |
| 30 | `eoxp` | established |  | HPC3 Chip Specification, revision 1.4, pp. 6-7 and 14 | Must be set on every receive descriptor, which carries one frame. |
| 29 | `xie` | established |  | HPC3 Chip Specification, revision 1.4, pp. 6-7 and 14 | Interrupt after this descriptor. Ignored unless end-of-packet is also set. |
| 14 | `own` | inferred |  | HPC3 Chip Specification, revision 1.4, pp. 6-7 and 14 | Reserved in the specification and used by every driver as a receive ownership flag. HPC3 does not read it: the specification gives no ownership check. The write-back of the count clears it. |
| 13:0 | `count` | established |  | HPC3 Chip Specification, revision 1.4, pp. 6-7 and 14 | Buffer size when armed. After a frame, HPC3 writes back the bytes left: the frame length is the armed size, minus the bytes left, minus 3. |

### Word `TX_DESC_CTL`

Word 1 of a transmit descriptor: the count, flags and inter-packet gap byte.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `eox` | established |  | HPC3 Chip Specification, revision 1.4, pp. 6-7, 13-14 | End of chain. The channel stops after the frame whose descriptor carries it has gone. |
| 30 | `eoxp` | established |  | HPC3 Chip Specification, revision 1.4, pp. 6-7, 13-14 | Last buffer of a frame. |
| 29 | `xie` | established |  | HPC3 Chip Specification, revision 1.4, pp. 6-7, 13-14 | Interrupt after this frame is sent. |
| 23:16 | `ipg` | established |  | HPC3 Chip Specification, revision 1.4, pp. 6-7, 13-14 | Inter-packet gap byte, written to SEEQ extended register 2 when the write-control bit is set in the DMA configuration. |
| 15 | `txd` | established |  | HPC3 Chip Specification, revision 1.4, pp. 6-7, 13-14 | Set by HPC3 in the first descriptor of a frame once the frame has gone. HPC3 clears bits 14 to 0 in the same write. |
| 13:0 | `count` | established |  | HPC3 Chip Specification, revision 1.4, pp. 6-7, 13-14 | Bytes to send from this buffer. |

## Test vectors

A vector is a value recorded from a source. An example only shows the layout.

| Target | Value | Kind | Decoded |
|---|---|---|---|
| `dmacfg` | 0x30026 | vector | d1=6, d2=2, d3=0, wr_ctrl=0, fix_rxdc=0, fix_eop=0, fix_intr=0, fix_timeout=3 |
| `dmacfg` | 0x3e026 | vector | d1=6, d2=2, d3=0, wr_ctrl=0, fix_rxdc=1, fix_eop=1, fix_intr=1, fix_timeout=3 |
| `piocfg` | 0x161 | vector | p1=1, p2=6, p3=1, fifo_ram_test=0 |
