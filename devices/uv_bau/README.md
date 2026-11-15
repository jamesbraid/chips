# UV broadcast assist unit (BAU)

The BAU sends one message to many hubs at once and tracks acknowledgements. Linux uses it to broadcast TLB shootdowns
to the processors of other blades. Registers sit in the hub maps ([uv1](../uv1/README.md) to [uv4](../uv4/README.md);
names starting `lb_bau_` and `bau_`); [registers.toml](registers.toml) here holds the descriptor and queue layouts and
constants. Source: Linux v5.4 `arch/x86/include/asm/uv/uv_bau.h` and `arch/x86/platform/uv/tlb_uv.c` (GPL, SGI-written;
removed from later kernels). Grades are **established** for what the driver programs and **inferred** where a position
follows from bitfield order. UV5 has no BAU registers in the header.

## Registers the driver touches

| Register | Role (established from the driver) |
|---|---|
| `lb_bau_sb_descriptor_base` | physical page address of the descriptor array and the home node id; one array of 64 sets of 8 descriptors of 64 bytes |
| `lb_bau_sb_activation_control` | write the set index plus the push bit to start the broadcast; init bit 63 written once at start |
| `lb_bau_sb_activation_status_0` and `_1` (and `_2` from UV2) | two status bits per set, read to learn completion |
| `lb_bau_intd_payload_queue_first`, `_last`, `_tail` (UV1 to UV3) | destination queue bounds; the kernel maintains the tail |
| `lb_proc_intd_queue_first`, `_last`, soft-ack pending and clear (UV4) | the same on UV4, with hardware managing the tail |
| `lb_bau_intd_software_acknowledge` (+ alias) | eight pending and eight timeout bits, one per destination ack resource; software writes the alias to acknowledge |
| `lb_bau_misc_control` | mode bits: software acknowledge mode, 4-bit timeout period, extended status, prefetch hint (UV3), UV2 and UV3 workarounds |
| `bau_data_config` | vector, delivery mode, destination mode and apic id of the message interrupt the destination raises |
| `bau_data_broadcast` | UV2 and later: enable broadcast of the interrupt to both sockets |

## Sequence (established, `tlb_uv.c`)

1. Per hub: allocate the descriptor array, fill every descriptor with the software-ack flag, base destination nasid,
   subnode id 0x10 and the endpoint-interrupt command (0x38 on UV1, 0x28 on later hubs), write the descriptor base,
   allocate the destination queue (20 entries of 32 bytes, 32-byte aligned), write first and last (and the tail before
   UV4), then program `bau_data_config` with the apic id and vector.
2. Enable timeouts on UV1 to UV3: with software-ack mode off write the 4-bit period (9 on UV1, 15 later), then turn
   software-ack mode on; UV3 also clears prefetch hint and sets extended status; UV2 clears extended status.
3. Initialise: write 1 shl 63 to activation control on every hub, and 1 to `bau_data_broadcast` on UV2 and later.
4. Send: set bits of the destination vector (bit *n* is node base plus 2n), message type regular, sequence number;
   write push plus the per-cpu set index to activation control (local window); poll the two status bits for the set
   (idle, busy, destination timeout, strong nack, source timeout, put error); retry as message type retry, falling
   back to IPIs on repeated timeouts.
5. Receive: the destination hub writes the message into its queue with the software-ack vector in byte 15 and raises the
   configured interrupt; the handler flushes the TLB per message, clears the matching ack bits through the alias and
   advances through the queue.

## Message formats

Distribution vector, 32 bytes: one bit per destination, even node ids from the base. Header, 16 bytes (UV1 and the UV2
and UV3 forms differ; both in [registers.toml](registers.toml)). Payload, 16 bytes with 12 usable: the address (or all
TLBs), sending cpu, ack count; UV4 adds a 24-bit qualifier the source sets to the value for the ASCII string SGI. The
queue entry carries the address, sender, ack count filled in by hardware, replied-to bit, message type, cancel bit, the
software-ack vector and the sequence number.

## Unknown

Status encodings of the UV4 hardware queue, the meaning of header fields the driver always writes zero, and the
bit-level contract of the three status registers (the driver reads them through helpers whose bits agree with the
register maps). See [questions/uv-open.md](../../questions/uv-open.md).
