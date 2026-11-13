# Origin 2000 network router (CrayLink)

The router is the six-port CrayLink switch that joins the Hubs of an Origin 2000 or
Onyx2 module and, through cables, other modules. Its register offsets and widths are
in [devices/router_origin2000/registers.md](registers.md), generated from
[devices/router_origin2000/registers.toml](registers.toml). Field layouts and reset
values are not in any public source, so they are not here either. The link layer is
in [crosstalk-link.md](../crosstalk/README.md), which covers the 128-bit micropacket and its
LLP rows for the router network.

This page keeps the public facts about the router that the register contract does not
carry: how it is built, what a message looks like, what the histogram selectors count,
and which boards carry it. Each fact has a grade and a source. Grades follow the
chips vocabulary: established, inferred, approximation, unknown.

## Ports, routing and messages

| Fact | Grade | Source |
|---|---|---|
| Six ports. Each port has a source-synchronous physical interface, link protocol logic, a receiver and a sender. The receiver can present a message straight to the crossbar when its queue is empty and the output is free. | established | 007-3439-002 Router sections, printed pp. 80-83 (Figure 3-3); Galles 1997 |
| A message is one header micropacket, then zero or more data micropackets. A tail bit marks the last one. | established | Galles 1997 |
| A micropacket is 128 data bits plus 8 sideband bits. The sideband carries the virtual-channel tag and link credits. | established | Galles 1997 |
| The header carries a 9-bit destination ID, a 4-bit direction, an 8-bit age and 2 bits of congestion control: 23 bits in all. | established | Galles 1997 |
| Direction 0 is reserved for the chip's own administration block. Data messages use directions 1 to 6. | established | Galles 1997 |
| The destination ID is the node number. It is placed in address bits 40:32. Its upper 5 bits select the meta domain and its lower 4 bits the local node. | established | public IP27 PROM manual, remote addressing |
| Four virtual channels per port, credit-based flow control per channel, 256-byte receive buffers per channel per port. | established | Galles 1997 |
| Each port keeps linked lists, one per output port per virtual channel, so a blocked head does not hold up traffic for other outputs. | established | Galles 1997 |
| Ordinary age runs 0 to 239. Ages 240 to 255 are sixteen high-priority levels. Age advances at a programmable rate and the arbiter favours the oldest traffic. | established | Galles 1997 |
| A tail-timeout timer fabricates a tail and flags an error when a channel stalls mid-message. A deadlock timer resets a port that stays full with no progress. | established | Galles 1997 |
| Routing is adaptive: messages for one destination may take different paths. | unknown | 007-3439-002, printed p. 80 (PDF p. 94) |
| Routing is static: software programs tables that fix one path per pair of endpoints, and may reprogram them. | unknown | Galles 1997, printed p. 36 (PDF p. 3) |
| The paper says the direction names the exit port. How a table entry encodes that direction is not settled by any public source. | unknown | Galles 1997 |

The two routing rows conflict. Settling them needs a Router register document, or a
console observation of two messages to one destination taking different paths.

The paper labels a 42-bit data field in its header figure. Its prose reserves 23 of the
128 bits and says the rest carry data. Which reading is right is open.

## Histogram selectors

Each port has a histogram of four buckets. A port selector picks what the buckets count. Prestor's thesis gives these definitions (printed p. 81, PDF p. 82, Table 5.4), in the order link utilisation, DAMQ, age, without selector numbers. The selector numbers come from the public Linux SN header `router.h` (linux-2.5.40, lines 352 to 354: `RPPARM_HISTSEL_AGE` 0, `_UTIL` 1, `_DAMQ` 2).

| Selector | Bucket 0 | Bucket 1 | Bucket 2 | Bucket 3 |
|---|---|---|---|---|
| 0, message age | age 0 to 63 | age 64 to 127 | age 128 to 191 | age 192 to 255 |
| 1, link utilisation | a received micropacket bypassed queued arbitration | a micropacket was received | a micropacket was sent | one tick of a 50 MHz timebase |
| 2, DAMQ virtual channel | no entries occupied | 1 to 7 entries | 8 to 14 entries | 15 entries |

The thesis defines a bypass as a received micropacket that finds its queue empty and
its crossbar output uncontended. These definitions are established by the thesis.

The thesis does not say which event samples message age or DAMQ occupancy. Those two
selectors have defined buckets but no known sampling event, so their progression is
unknown.

## Boards

| Fact | Grade | Source |
|---|---|---|
| Part `030-0841-002` is a Router board ("PCA Origin 2000 Router 8P" in the catalogue); IP27 is the machine it is used with by inference from the catalogue's "for use with IP31" note on the next part. | established | SGI parts catalogue HMM-408-B, p. 29 |
| Part `030-0841-003` is the later Router board specified for IP31 machines. | established | SGI parts catalogue HMM-408-B, p. 29 |
| The board's one-wire record name is `ROUTER-IR1`. `hinv -m` prints the hyphen on `030-0841-002`. One capture shows revision G. | established | one `hinv -m` capture of an IP31 Origin 2000 with two `030-0841-002` Routers, comp.sys.sgi.hardware, 4 December 2001 |
| On `030-0841-003` the record reads `ROUTER_IR1`, revisions B, C or D, group `0xff`, capability `0xffffffff`, variety `0xff`. | established | three public rack captures: Origin 2400 (posted 2007-11-08 and 2016-11-20) and Onyx2 (posted 2007-12-03) |

The board's one-wire part holds the fixed-offset board record. IRIX lists it at
`/hw/module/M/slot/rN/router`.

## What is unknown

- Whether routing is adaptive or static (see above).
- Whether the header's data field is 23 bits or 42 bits.
- Which event samples message age and DAMQ occupancy for the histogram selectors 0 and 2.
- The revision value a production part reports in its status word.
- Which external Router ports a specific four-node module uses. Internal ports and the
  Hub and BaseIO widgets are fixed. External cables and optional I/O need a published
  installation procedure, public schematics, or a firmware inventory from a known
  enclosure and board revision.
