# IP35 boot: five register accesses that read like noise

Question. During a Tezro or Fuel boot the PROM and the IRIX kernel make a handful of accesses to Bedrock and PIC
registers that no public header explains. What is each register, what does the code writing it need back, and
what does a failed configuration read at the PIC look like to the processor? Observed in boot traces of a
four-processor Tezro (PROM 6.210, IRIX 6.5.30) and a one-processor Fuel; the traces show addresses and counts only.

Labels: established (read in full in the shipped binary or a public source), inferred (reasoning given), unknown
(settling read named). PROM addresses are payload offset plus `0x1fc00000`.

## 1. Processor-interface offset `0x20` is written three times per exception

- Established: the register at hub-local `0x9200000001000020` is the processor-interface CPU-number register (bit 0
  slot A or B, bit 1 which interface). The routine at `0x1fc6b530` returns it unchanged and the exception stubs read it
  first to index per-slice slots.
- Established: each of seven exception stubs (stores at `0x1fc020fc`, `0x1fc021f0`, `0x1fc022e4`, `0x1fc023d8`,
  `0x1fc024cc`, `0x1fc025c0`, `0x1fc026c0`) stores Cause, EPC and BadVAddr, in that order, to that same address
  with no increment. Three stores per exception. One separate store of `0xdeadbeefcafecafe` to it is at `0x1fc02a90`
  in early reset code.
- Inferred: a write has no effect and the register keeps returning the slice number. The public SN1 header lists it
  read-only, and the PROM keeps indexing per-slice state by it after every such triple.
- Unknown: whether silicon flags the write. Settled by a read-back after a write, or the Bedrock processor-interface
  specification.

## 2. PIC head registers touched at start-up

Bridge-family names are from the public OpenBSD xbridge header and are hints for the PIC, not established for it.

- Inferred: `0x08` widget status (8 bytes) read by the kernel at attach; `0x0c` its low word, read by the PROM.
- Inferred: `0x20` widget control; the kernel writes `0xef20420b`. Unknown: the meaning of the bits beyond the
  public masks.
- Inferred: `0x44` and `0x4c` are low words of the 8-byte registers at `0x40` (Bridge family: error command word) and
  `0x48` (link-layer control and status); the PROM writes `0` and `0x3e0` (after a read of each). Unknown: the PIC
  meaning of `0x48`.
- Inferred: `0xc4` is the low word of bus timeout at `0xc0`; `0x3ff` is the retry-count mask in the OpenBSD header.
- Inferred: `0x120` device-to-pin map; the kernel writes `0x6db6db`, three bits per device.
- Inferred: `0x284` and `0x28c` are low words of the even and odd response-buffer registers (`0x280`, `0x288`); the
  PROM writes `0x88889999` to each (nibble: valid 8, virtual channel 4, device number 0 to 3).
- Inferred: `0x10000` upward is the internal address-translation RAM; the kernel writes zero to every entry.
- Established: the instructions read do not test the result of any of these writes.

## 3. Node memory initialisation through the remote register window

- Established: the routine at `0x1fc66164` to `0x1fc66228` forms `0x9000000030000000 + (node << 33)` and, for
  i = 0 to 7, writes `0x2000` then `0x100` to `+8i` and `+0x40+8i`; it then enables refresh at hub offset `0x7a0000`
  (bit 63 and a threshold computed from the memory clock), waits, and writes `0x2b` to `+0x00..+0x38` and `0x29` to
  `+0x40..+0x78`. Forty-eight writes per node; the same on Fuel. The routine reads nothing from the window.
- Inferred: DDR SDRAM initialisation commands to DIMM positions. The order and values match the JEDEC sequence:
  extended mode register, mode register with DLL reset (bit 8, `0x100`), refresh on, operating mode register with CAS
  latency 2 (bits 6:4) and interleaved burst (bit 3), burst length field 3 for `0x2b` and 1 for `0x29`. The public SN1
  memory-directory header says refresh is off after reset and the first DIMM operation is a mode-register write.
- Unknown: the Bedrock meaning of each bit (the extended-mode select would sit in address bit 13) and why the two
  halves differ in burst length.

## 4. Memory-directory request queue size

- Established: hub offset `0x7c0050` is the outgoing request queue size: three 3-bit fields at 10:8, 18:16 and
  26:24, each defaulting to its maximum of 4, so the reset value is `0x0000000004040400`.
- Inferred: a write of exactly that value during hub initialisation is a write-back of the default.
- Unknown: the writer. No address formation `lui 0x7c` or `lui 0x1fc` with immediate `0x50` exists in the PROM
  payload or the IRIX kernel. The program counter at the store settles it.

## 5. Failed configuration reads at a PIC

- Established: widgets `0xb` and `0xf` of a four-processor Tezro are the two PICs (see
  [tezro-io-topology.md](tezro-io-topology.md)). The failing reads are PCI configuration windows inside them: head 0
  at `0x20000 + (device + 1) * 0x1000` (`0x20000` is the reserved device 0), head 1 at `+0x800000`. They are
  empty-slot probes, not probes of empty widgets.
- Established: the PROM probe routine is at `0x1fc47d44` and the read is the load at `0x1fc47e58`. It writes `0x41` to
  the head's reset-interrupt-status low word, saves a fault-recovery context, reads, and on a fault clears the
  Bedrock processor-interface error records and reports the slot absent; if the read returns it tests status bit 11.
- Established: the kernel's guarded read `_badaddr_val` (IRIX 6.5.30 IP35 `0xc000000000077680`; its 4-byte load is at
  `0xc0000000000776fc`) sets a per-CPU no-fault marker, loads, stores the result and clears the marker; a fault
  leaves through the trap path. `pcibr_piomap_probe` (`0xc0000000000ac0a4`) disables the master-timeout enable,
  calls it, writes 64 to the interrupt-reset register and returns 1 when the probe failed.
- Inferred (no capture exists): an unclaimed
  configuration cycle ends in a PCI master timeout and the processor sees a bus error. The PROM probes with every
  error enable clear, so its "absent" answer comes from the fault. Both firmware paths accept a bus error; the PROM
  also accepts returned data with status bit 11 set.
- Unknown: the processor-side error record for a read to a widget that does not exist at all, and whether a
  read of an empty slot returns all ones instead of faulting. A configuration read of an empty slot followed by
  reads of the same head's `+0x104` and `+0x174` settles both.
