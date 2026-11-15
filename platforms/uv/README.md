# Altix UV and the UV hub family (UV1 to UV5)

SGI's x86 successor to the Itanium Altix is a cache-coherent NUMA machine built from blades, each carrying a hub chip
that sits between the Intel sockets and the NUMAlink fabric. The Linux platform code calls the hub generations UV1,
UV2, UV3, UV4 (with a UV4A revision) and UV5. This page is the topology and address-map reference; register maps are
in [devices/uv1](../../devices/uv1/README.md) to [devices/uv5](../../devices/uv5/README.md), the global reference unit
is [devices/uv_gru](../../devices/uv_gru/README.md) and the broadcast assist unit is
[devices/uv_bau](../../devices/uv_bau/README.md).

Grades follow [AGENTS.md](../../AGENTS.md). Almost everything here is **established** as a definition in SGI-written
Linux platform code: v5.4 for UV1 to UV4 (the last tree that still carries the UV1 to UV3 broadcast assist registers)
and v6.6 for UV4 and UV5. Source is cited as `v5.4:path` or `v6.6:path`. **Nothing was read from a UV binary, and no UV
firmware, hub specification or hub datasheet is held**, so reset values, behaviour not exercised by the kernel and
every physical NUMAlink fact are unknown unless a sentence says otherwise.

## Hub generations

| Generation | Part number (node id register) | Kernel product string | Notes |
|---|---|---|---|
| UV1 | 0x88a5 | none (v5.4 calls the generation by its revision only) | MMR windows are twice the size of later ones; no longer in the current kernel (established: `v3.10:arch/x86/include/asm/uv/uv_mmrs.h`, `v5.4:.../uv_hub.h`) |
| UV2 | 0x8eb8, also 0x1111 | "UV2000/3000" | the second part number is accepted as the same generation (established: `v6.6:arch/x86/kernel/apic/x2apic_uv_x.c`) |
| UV3 | 0x9578, also 0x4321 | "UV300" | |
| UV4 | 0x99a1 | "UV400" | UV4A is the same part number at a later revision |
| UV5 | 0xa171 | "UV500" | new region (RH10) address-map blocks; no GRU TLB or broadcast assist registers in the kernel header |

The software revision numbering is a kernel convention, not the chip's: UV2 base 3, UV3 base 5, UV4 base 7, UV4A 8 and
UV5 9, each added to the chip's revision field (UV2 and UV4 subtract one first). A UV1 hub is revision below 3
(established: `v6.6:arch/x86/include/asm/uv/uv_hub.h`, `v3.10:.../uv_hub.h`). UV4A is detected as UV4 with software
revision 8 (established).

Reading the node id register at offset 0 of the local MMR window is how Linux identifies the generation: part number
in bits 27:12, chip revision in 31:28, manufacturer in 11:1 and bit 0 reads as one on every generation (established,
register maps). The hub is identified before anything else is known, so an emulator must serve this one register.

The SGI UV Systems Linux Configuration and Operations Guide (007-5629-005) names the first generation UV1000 and shows
the system controller listing a rack as `UV1000` with blades named `IP93` and base I/O and disk blades as `IP93-BASEIO`
and `IP93-DISK` (established as manual text, rev 005 printed page 8). The manual also says partitioning needs no cable
changes and is done with commands to the system controller, that hardware memory firewalls protect each partition, and
that a GRU no-fault mode lets one partition reach another safely (established as manual text, printed pages 3 to 4).
It does not state a hub register fact.

## Address spaces the CPU sees

All values are established from `v5.4`/`v6.6` `uv_hub.h` unless marked.

| Space | UV1 | UV2 and UV3 | UV4 and UV5 |
|---|---|---|---|
| Local MMR window (this hub's registers, 8-byte registers) | 0xf4000000, 64 MiB | 0xfa000000, 32 MiB | 0xfa000000, 32 MiB |
| Global MMR32 window (any hub, reduced register set, `pnode << 15` ORed in) | 0xf8000000, 64 MiB | 0xfc000000, 32 MiB | none |
| Global MMR64 window (any hub, all MMRs) | high in the physical map, base from firmware or the MMR overlay register, `pnode << 26` by default | same | same |
| Local bus (system controller interface window) | 0x1c00000, 4 MiB; 64 one-byte slots at its top | same | same |

The 64-bit window base comes from the firmware table (below) when present, else from the base field of the MMR overlay
register shifted into place, with the enable bit masked off, and the pnode shift 26 (established, `x2apic_uv_x.c`). The
MMR overlay register is `rh_gam_mmr_overlay_config` (UV1 to UV4) or `rh10_gam_mmr_overlay_config` (UV5) in the register
maps. Each hub's MMRs therefore occupy a 64 MiB slot in the 64-bit window.

A global physical address whose top two bits are both set selects MMR space rather than memory (established,
`uv_gpa_in_mmr_space`).

## Node numbering and global physical addresses

- A NASID is 15 bits. Compute blades have a clear low bit, routers a set low bit. Hub registers carry the GNODE, the
  NASID shifted right by one. The PNODE is the low N bits of the gnode and is the number used to index MMR windows.
  The kernel allows 16384 blades in a NUMAlink fabric and 256 in one single system image (established).
- The NUMAlink global physical address on UV1 to UV3 is the gnode above an M-bit node offset, with M between 35 and
  40 and N (pnode bits) between 0 and 10, M + N at most 44 on x86-64 (established, comment in `uv_hub.h`). A socket
  address is the pnode just above the offset.
- UV1 to UV3 take M and N from `rh_gam_addr_map_config` (m_skt in bits 5:0, n_skt in 9:6; UV1 and UV2 and UV3 have
  both, UV4 only n_skt). The global address needs the gnode moved to a fixed bit: on UV2 to bit 40 when M is 40 and
  39 otherwise, on UV3 to the m_skt field of the GR0 GAM configuration register (established, `get_mn`). The kernel
  records a special case for UV2 revision 1 hubs.
- UV4 and UV5 have no fixed M. Firmware gives the kernel a table of address ranges (below), the kernel looks up the
  node that owns a physical address by comparing it against range limits expressed in 64 MiB units (physical address
  bits 56:26), and the global address is the NASID shifted to the gpa shift (46 unless firmware says otherwise). UV5
  reads n_skt from the `rh10_gam_addr_map_config` register (3 bits at 8:6) and UV4 from `rh_gam_addr_map_config`
  (4 bits at 9:6). Both assume a minimum partition of four sockets (established, `early_get_pnodeid`).

How a given hub routes a request by its NASID inside the NUMAlink fabric (route tables, router ports) is not in the
kernel header: **unknown**, and no router specification for UV is held.

## Firmware interface (UV BIOS)

The kernel finds a table with signature `UVST` through the EFI system table; its function pointer is the single
runtime entry (established, `bios.h`). Versions: 1 for UV2 and UV3, 0x400 to 0x403 for UV4 (0x401 adds the gpa shift,
0x402 the non-volatile range types, 0x403 removes a range proximity field), 0x500 for UV5. Entry types: 1 address-map
parameters, 2 the range table, 3 the architecture string ("SGI2" to "SGI5"; the kernel can learn the generation from it instead of the node id register). Parameters: MMR base and GRU base, their pnode shifts and the gpa shift. A range entry carries a type (RAM,
non-volatile RAM, NV window, NV mailbox, hole), NASID, socket id, pnode and limit.

Runtime calls (established as names and numbers, not behaviour): common, get hub info, frequency base (platform,
interval timer, real-time clock), allocate and free a message-queue watchlist, change memory protection (restrict,
allow atomic memory operations, allow read and write), get partition address, set legacy VGA target, plus extended
ones for the object heap, master NASID, object and port enumeration, geography and PCI topology. Return codes are 0,
1 (more passes), and negative errno values. The real-time clock frequency is only obtainable from the frequency call;
the value is **unknown** here.

## Interrupts, IPIs, NMI and the timer

| Function | Mechanism | Grade |
|---|---|---|
| Send an IPI to a processor on any hub | write the target's apic id, vector and the send bit to `ipi_int` in the target hub's global MMR window; the pnode of the target comes from its apic id | established (`uv_time.c`) |
| Real-time clock | one free-running counter in `rtc`, 56 significant bits; from UV2 on the register is replicated per cache line across its page and each processor reads its own line | established; counter frequency is firmware data, unknown |
| Timer interrupt | arm comparator `int_cmpb`, point `rtc1_int_config` at an apic id and vector, clear by writing the alias of event register 2; the pending bit is the RTC comparator bit of event register 2 on UV2 to UV4 (on UV1 the equivalent bit is in event register 0, bit 52, from the v5.4 macros) | established |
| Device and GRU interrupts | each source has a configuration register (vector, delivery mode, destination mode, apic id in bits 63:32) that the kernel programs per interrupt; the hub forwards the vector to the apic id | established |
| NMI from the system controller | UV2 to UV4 use event bits `extio_int0` to `extio_int3` plus an enable register; UV5 uses the same names in event register 1; old firmware uses bit 63 of the scratch register instead | established |
| Firmware and kernel handshake | `scratch5` carries the TSC sync state and the NMI request bits | established as a place; bit meanings in `uv_hub.h` are kernel's, firmware's own use unknown |

## Open items

[questions/uv-open.md](../../questions/uv-open.md).
