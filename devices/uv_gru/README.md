# UV global reference unit (GRU)

The GRU is a per-hub engine that lets a user program issue loads, stores, block copies, message-queue operations and
atomic memory operations on global addresses, with its own TLB that the kernel fills on a miss. Each hub carries two
GRU chiplets. Constants, handle words and the instruction word are in [registers.toml](registers.toml); the
reference is [registers.md](registers.md). Grades: **established** where SGI's Linux driver states a number or
a macro, **inferred** where a field position follows from the declared bitfield order (those words say so).
Source: the Linux v6.6 tree's `drivers/misc/sgi-gru` driver (GPL, SGI-written). No hardware specification is held.

## What the driver supports

The driver runs only when the hub's software revision is below 5, which is UV1 and UV2 (established). UV3 and later
have GRU registers in the kernel header but no driver. Where the unit lives: the base of the GRU window is the base
field of `rh_gam_gru_overlay_config` (UV1 to UV4) in the local MMR window, masked to 47 bits; the driver spans 128 MiB
per chiplet times the maximum blade count (established). The GRU sees MMR space through a different address form: the
fixed GRU MMR base 0x4000000, the offset, and the pnode shifted by M (established, `uv_hub.h`).

## Layout of one chiplet (128 MiB)

| Range | Contents | Grade |
|---|---|---|
| 0 to 0x4000000 | user segments, one per context, every 4 MiB; each maps control blocks then the data segment | established |
| 0x4000000 | TLB fault maps, 16, one per context | established |
| 0x4008000 | TLB global handles, 24 | established |
| 0x4010000 | control block extended handles, 128 | established |
| 0x4018000 | TLB fault handles, 128 | established |
| 0x4020000 | context configuration handles, 16 | established |

Every handle starts on a 256-byte boundary and uses the first 64 bytes. Within a user segment control block *n* is at
256 times *n* (128 blocks, 32 KiB) and the 32 KiB data segment starts at 0x20000. Chiplet address is the base plus
128 MiB times (2 times pnode plus chiplet number).

## How software uses it

1. **Configure a context** through its context configuration handle: write the control block allocation map, the data
   segment allocation map and eight address space ids, then issue the allocate opcode and poll the handle's status
   (idle, exception, active) until it is idle; on exception the cause says why. Start and deallocate the same way.
   Control blocks allocate two at a time and data segment space in 1 KiB units (established).
2. **Issue an instruction** by filling control block dwords 1 to 7 (addresses, element count, stride, operands), then a
   single ordered 64-bit store of dword 0 containing the start bit, status field set to active, opcode, extended
   opcode, element type, access attributes and the data-segment index, and a cache line flush of the block. The block's
   status field then moves from active to idle, exception or "call OS" (established).
3. **Handle a TLB miss.** The block ends in "call OS". The kernel reads the matching TLB fault handle (missing address
   and address space id, cause), builds a TLB entry (page frame shifted right 12, size code, global address attribute,
   dirty bit, fill address space) and issues write-and-restart; or issues exception to fail the block. Faults reach
   the kernel either by an interrupt from the context's TLB interrupt register or by polling the fault map; the
   interrupt registers are `gr0_tlb_int0_config`, `gr0_tlb_int1_config`, `gr1_tlb_int0_config`, `gr1_tlb_int1_config`
   in the UV1 to UV4 register maps, one pair apart per core (established, `grufile.c`).
4. **Flush the GRU TLB** when a mapping changes by writing the TLB global handle (address, mask, address space id,
   page size, count, context bitmap) with the invalidate opcode and polling its status (established).

## Instruction set

Opcodes 0 to 15: no-op, block copy, vector load, indirect vector load, vector store, indirect vector store, vector set,
indirect vector set, message queue, masked compare exchange, atomics with implicit operands (plain and registered),
atomics with explicit operands (plain and registered), block store, vector flush. Extended opcodes select the atomic
operation (fetch, clear, increment, decrement, queue check; swap, or, and, xor, add, compare-swap, compare-add,
equality and inequality poll; masked compare exchange). Element types are byte, 2, 4, 8 bytes and a 64-byte line
(types 4, 5 and 7 are not defined in the driver). All values are in the constants of the register map.

Exception causes in the extended control block are bit masks (listed in the CBE word). The driver retries an exception
only when every set cause is in the retry group: execution hardware error, TLB hardware error, request timeout,
non-fatal response, response data error (established, `gru_instructions.h`).

## Unknown

Everything about how the engine behaves beyond what the driver does: TLB size and replacement, ordering rules between
blocks, the message queue wire format beyond the head word (head and limit, 32 bits each), and reset state of every
handle. See [questions/uv-open.md](../../questions/uv-open.md).
