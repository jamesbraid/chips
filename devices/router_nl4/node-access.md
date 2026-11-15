# Reaching a router from a node: the vector registers and the node's link registers

A router has no address of its own. A node sends it a "vector" request: a read or write of one 64-bit register, carried
along a route of output-port nibbles, with the reply captured in registers of the node's SHub (or TIO). The names and
numbers below are the SN2 PROM's own register tables; they are not in any Linux header
([README.md](README.md) explains the table format and why). Grades as in [AGENTS.md](../../AGENTS.md). I did not edit
[../shub/](../shub/README.md); the register list here is what that page should absorb (see the last section).

## Vector registers (established: names, numbers, field positions from the PROM tables; both generations)

Offsets are node offsets. In the SHub 1 image they carry the bias `0x1_0000_0000` that the rest of that chip's registers
carry in the PROM's listings; in the SHub 2 image they do not. TIO has the same vector block in its own space (the
PROM's vector routine builds a TIO address for an odd NASID).

| Register | SHub 1 | SHub 2 | Fields |
|---|---|---|---|
| `VEC_DATA` | `0x1_1006_6000` | `0x1006_7000` | `DATA` 63:0: value to write |
| `VEC_PARMS` | `0x1_1006_6080` | `0x1006_7080` | `BUSY` 63 (read-only), `START` 62 (write 1 to send), `PIO_ID` 45:35, `ADDRESS` 34:3, `NI_PORT` 1, `TYPE` 0 |
| `VEC_ROUTE` | `0x1_1006_6100` | `0x1006_7100` | `ROUTE` 63:0 |
| `VEC_RDDATA` | `0x1_1007_4000` | `0x1007_4000` | `DATA` 63:0: value read from the router |
| `VEC_RETURN` | `0x1_1007_4080` | `0x1007_4080` | `ROUTE` 63:0: the return path of the reply |
| `VEC_STATUS` | `0x1_1007_4100` | `0x1007_4100` | `STATUS_VALID` 63, `OVERRUN` 62, `SOURCE` 59:46 (SHub 1) or 61:46 (SHub 2), `PIO_ID` 45:35, `ADDRESS` 34:3, `TYPE` 2:0 |
| `VEC_STATUS_ALIAS` | `0x1_1007_4108` | `0x1007_4108` | the same fields, flags mark it read-only; reading it probably does not clear `STATUS_VALID` (inferred from the name and flags) |

`ADDRESS` is the router register number (it is a doubleword number in bits 34:3, so the field takes the byte offset
directly). `PIO_ID` is a tag the request carries and the reply repeats. `TYPE` in `VEC_PARMS` selects read (0) or
write (1, inferred: the PROM's read path writes 0 and its write routine was not read). The reply's `TYPE` is a status
code (below).

### The read sequence the PROM uses (established, SHub 2 SAL 10.54, read in full; constants confirmed in objdump)

1. Take a global lock, with a 5,000,000-tick timeout; if the lock cannot be taken the PROM prints "breaking vector
   lock on node %d". Whether it then carries on was not determined (the call is to the PROM's message routine, which is
   a panic in other uses), and the lock's own implementation was not read.
2. Store 0 to `VEC_STATUS` (clears `STATUS_VALID`), read it back; if bit 63 is still set, release the lock and fail.
3. Poll `VEC_STATUS` until bit 63 reads clear, at most 1,024 reads. If it never clears the routine waits
   (100 units, then growing by a factor of 4) and tries again, at most 8 times, then fails.
4. Store `0xdeadbeefdeadbeef` to `VEC_RDDATA` (poison, so a stale reply is recognisable).
5. Store the route (all nibbles but the first, see below) to `VEC_ROUTE`.
6. Store the command to `VEC_PARMS`: bit 62 (`START`) set, `PIO_ID` = `0x1c8`, `ADDRESS` = the register number,
   `NI_PORT` = first route nibble minus one, `TYPE` = 0.
7. Poll `VEC_STATUS` (with a delay of 100 units before each read) until `STATUS_VALID` is set, at most 1,024 times;
   read the reply data from `VEC_RDDATA`.
8. Release the lock. Judge the status: `OVERRUN` set is error -2; `TYPE` = 0 with `PIO_ID` = `0x1c8` and `ADDRESS`
   equal to the request is success; `TYPE` 4, 5 or 6 are errors -4, -5, -6; anything else -3. A poll that runs out is
   -7 after the retries.

What a reply `TYPE` of 4, 5 and 6 mean is not stated in what was read. The PROM's error decoder has the strings
"Vector Request Route Error", "Vector Reply Route Error", "VERRA, Vector address error", "VERRC, Vector command
error" and "VERAC, Vector address/command error", and the SHub error text "Hub got invalid vector err from rtr",
"Hub got protection err from rtr", "Hub got HW err accessing rtr". Mapping codes 4, 5 and 6 onto them is **unknown**.

The same routine with a route of 0 does not use the vector registers at all: it reads the register straight from the
node's global MMR window (`0x3_0000_0000` plus the NASID shifted up by 40 minus the node-configuration value read from
`0x2_2011_0000`; see [../../software/firmware/snprom/README.md](../../software/firmware/snprom/README.md)). For an odd
NASID (a TIO) it builds the TIO form instead. So one PROM read function covers "this node", "another node" and "a
router" with only the route and the NASID changing (established for the code; the local-versus-vector split on route 0
is the whole use).

### Route format (route layout established; hop semantics inferred)

The 64-bit route is sixteen nibbles, lowest nibble first. The routine's first nibble selects which of the node's two
network ports the request leaves by: the value minus one is stored in `NI_PORT` (so 1 and 2 are valid). The rest of the
route (shifted down one nibble) goes into `VEC_ROUTE`. If it is then zero, the routine sets nibble 8 of `VEC_ROUTE` to
`0xf` first; why is **unknown**. The PROM's own limit is sixteen hops: "Max vector length 16 exceeded on path 0x%lx".
Every later nibble is the output port number at the next router (inferred). The reply's route comes back in
`VEC_RETURN` (the routers build it on the way; the PROM keeps it for the return route, inferred from the name).

## Link registers of the node (established as names and numbers; roles inferred)

Each of the two network ports has a link-layer block. SHub 1 NI0 at `0x1_5000_0000`, NI1 at `0x1_5000_2000`; SHub 2 NI0
at `0x5000_0000`, NI1 at `0x5000_2000` (a 0x2000 stride in both).

| Offset | Name | Fields (SHub 1) |
|---|---|---|
| `+0x00` | `LLP_STAT` | `LINK_RESET_STATE` 3:0 (the PROM treats 9 as link up, inferred) |
| `+0x08` | `LLP_RESET` | `WARM` 1, `LINK` 0 (flags mark them self-clearing, inferred) |
| `+0x10` | `LLP_RESET_EN` | `OK` 0 |
| `+0x18` | `LLP_CHAN_MODE` | `ENABLE_CLKQUAD` 4, `ENABLE_RMT_FT_UPD` 3, `ENABLE_TUNING` 2, `AC_ENCODE` 1, `BITMODE32` 0 (SHub 2 adds `ENABLE_LINK` 5) |
| `+0x20` | `LLP_CONFIG` | `FTU_TIME` 37:26, `NULLTIMEOUT` 25:20, `MAXRETRY` 19:10 (SHub 1) or 55:40 with enables at 59:56 (SHub 2), `MAXBURST` 9:0 |
| `+0x28` | `LLP_TEST_CTL` | `CBERROR` 62, `CAPTURED` 61, `FAKESNERROR` 60, `SENDSNERROR` 59, `SENDCBERROR` 58, `CAPTURECBONLY` 57, `ARMCAPTURE` 56, `NOISE_MODE` 55:54, `LFSR_MODE` 53:52, `WIRE_SEL` 49:44, `SEND_TEST_MODE` 41:40, `PATTERN` 39:0 |
| `+0x30`, `+0x38` | `LLP_CAPT_WD1`, `LLP_CAPT_WD2` | `DATA` 63:0 |
| `+0x40` | `LLP_CAPT_SBCB` | capture status bits 36:32, `CAPTUREDRCVCRC` 31:16, `CAPTUREDRCVSBSN` 15:0 |
| `+0x48` | `LLP_ERR` | SHub 1: `WIRE_OVERFLOW` 52, `WIRE_CNT` 51:28, `POWER_NOT_OK` 27, `SQUASH` 26, `RCV_LINK_RESET` 25, `RETRY_TIMEOUT` 24, `RETRY_COUNT` 23:16, `RX_CB_ERR_COUNT` 15:8, `RX_SN_ERR_COUNT` 7:0. SHub 2: the same flags at 60 and 59:36 to 32, and the three counters moved to `LLP_ERR1` (`+0x50`: `RETRY_COUNT` 63:48, `RX_SN_ERR_COUNT` 47:0) and `LLP_ERR2` (`+0x58`: `RX_CB_ERR_COUNT` 47:0) |
| `+0x60` | `LLP_PKT` (SHub 2 only) | `COUNT` 47:0 |

These resolve some earlier readings of the SHub 1 PROM ([boot-sequence.md](../../software/firmware/snprom/boot-sequence.md)):
the register at `0x1_5000_0000 + 0x2000 * p` whose low nibble must be 9 is `LLP_STAT`; the one at `+0x48` whose bit 27 the
PROM clears and re-reads is `LLP_ERR`'s `POWER_NOT_OK`, and bits 7:0 and 15:8 are the two error counters. The
register-to-name step is inferred from offset and bit position matching, not from a reference in the code.

The node's own routing tables are in the same block (established as names and numbers):

| Table | SHub 1 | SHub 2 | Entry |
|---|---|---|---|
| `NI0_LOCAL_TABLE` | `0x1_5002_2000` | `0x5002_4000` | `VALID` 63, `V0` 4, `DIR0` 3:0 |
| `NI0_GLOBAL_TABLE` | `0x1_5002_2400` | `0x5002_4800` | same |
| `NI0_OVER_RIDE_TABLE` | `0x1_5002_2480` | `0x5002_5000` | `ENABLE` 63, `V0` 4, `DIR0` 3:0 |
| `NI1_*` | `+0x1000` | `+0x2000` | same |

Table lengths are inferred from the spacing: SHub 1 local table 128 doublewords (to the global table at `+0x400`),
global 16 (to the override table at `+0x480`); SHub 2 local 256 and global 256. The node's `DIR0` is four bits plus
a `V0` bit; the router's port tables use a five-bit `DIR0` (4:0). What a value selects is **unknown** (no loop that
fills them was read); a route through a router needs the router's ports 0 to 7, which fit in either.

Error and status registers for the two ports (`NI0_ERROR_SUMMARY_1`, `_2`, `_OVERFLOW`, `_MASK`, `_FIRST_ERROR`,
`_ERROR_DETAIL_1` to `3`, and the alias registers) sit at `0x1_5004_0500` to `0x1_5004_0690` (SHub 1) and `0x5004_0500`
to `0x5004_0690` (SHub 2). The PROM's error decoder prints bit names for them, for example "Hub NI saw too many link
errors" and "Hub chip's llp interface is down". Bit meanings were not extracted here.

## Changes for the SHub page (not made here)

1. Add the vector block, the NI link block, the two node routing tables and the NI error registers above to
   `devices/shub/registers.toml` and `registers.shub2.toml`, with the offsets as listed (SHub 1 with its `0x1_` bias).
2. Replace the unnamed readings of `0x1_5000_0000`, `0x1_5000_0048` and the counters in
   [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md) with the names above, noting that the match is by
   offset and bit position (inferred) except where a routine's use is read.
3. The firmware state word the PROM keeps at `0x1_101d_0080` has an analogue in the router: the chip-match routines pass
   a register number to the PROM's shared code, `0x101d0080` for the SHub 2 entry, `0x901d0080` for TIO and 4096 for the
   NUMAlink 4 router, which is `SCRATCH0` (`0x1000`). So the router keeps the firmware's state word in `SCRATCH0`
   (inferred from the three match routines; the shared code that uses the number was not read).
