<!-- generated from devices/mc/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 dae392f2b3e15a33aee9340388e677b1c60d361b28987e437dd2dd4709e5ba5a -->

# SGI MC memory controller of the R4000 Indigo, Indy and Indigo2: CPU control, GIO arbitration, memory configuration, error reporting and the graphics DMA engine

The MC gate array sits between the R4000, main memory and the GIO bus. This unit is every register software touches. Offsets are from the start of the MC window (physical 1fa00000) and are the big-endian view: the chip answers each register at two addresses four bytes apart, the higher one for a big-endian CPU and the lower one for a little-endian CPU (the lower is these offsets minus 4; the semaphore pages and the DMA block follow the same rule). All registers are 32-bit words on the CPU bus; the IRIX header marks some as byte or halfword registers, which says how many bits are meaningful, not a different access width. Grades: established means the public IRIX source tree, a shipped IRIX header or the MC chip specification states it; inferred means a reasoned reading, with the reasoning in devices/mc/README.md. The specification covers MC revisions A and B (Fast Forward machines, Indigo notes included); the Indigo board carries revisions A to C, so a reset value taken from the specification is graded for the specification's revision and is not a read of an Indigo.

Unit `mc`, macro prefix `MC`.
Default source: MC Chip Specification (R4000 project), revision 1.15.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| mc | byte | Byte offsets from the start of the MC window, big-endian view. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `cpuctrl0` | 0x4 | rw | 32 |  | mc | 0x100012 (inferred; MC Chip Specification, section 5.1 (reset column: refresh enabled, four-line bursts, MUX high-water mark 1, all else 0). Bit 18 and the HPC bit of the arbitration register are loaded from the serial EEPROM at reset, so the value is inferred, not a constant.) | established | MC Chip Specification, section 5.1; IRIX sys/mc.h |
| `cpuctrl1` | 0xc | rw | 32 |  | mc | 0xc (established; MC Chip Specification, section 5.2 (reset column)) | established | MC Chip Specification, section 5.2; IRIX sys/mc.h |
| `dogc` | 0x14 | rw | 32 |  | mc | 0x0 (established; MC Chip Specification, section 5.3 (reset column)) | established | MC Chip Specification, section 5.3; IRIX sys/mc.h |
| `sysid` | 0x1c | r | 32 |  | mc | unknown | established | MC Chip Specification, section 5.4; IRIX sys/mc.h |
| `rpss_divider` | 0x2c | rw | 32 |  | mc | 0x104 (inferred; MC Chip Specification, section 5.5 (reset column) and the Indigo PROM 4.0.5D, which times a refresh wait with the RPSS counter and never writes this register) | established | MC Chip Specification, section 5.5; IRIX sys/mc.h |
| `eerom` | 0x34 | rw | 32 |  | mc | 0x0 (established; MC Chip Specification, section 5.6 (reset column)) | established | MC Chip Specification, section 5.6; IRIX sys/mc.h |
| `ctrld` | 0x44 | rw | 32 |  | mc | 0xc30 (established; MC Chip Specification, section 5.7 (reset column)) | established | MC Chip Specification, section 5.7; IRIX sys/mc.h |
| `ref_ctr` | 0x4c | r | 32 |  | mc | unknown | established | MC Chip Specification, section 5.8; IRIX sys/mc.h |
| `gio64_arb` | 0x84 | rw | 32 |  | mc | 0x400 (inferred; MC Chip Specification, section 5.9 (reset column: only the one-GIO bit is 1). Bit 0 is loaded from the serial EEPROM at reset and the column leaves it blank.) | established | MC Chip Specification, section 5.9; IRIX sys/mc.h |
| `cpu_time` | 0x8c | rw | 32 |  | mc | 0x100 (established; MC Chip Specification, section 5.10 (reset column)) | established | MC Chip Specification, section 5.10; IRIX sys/mc.h |
| `lb_time` | 0x9c | rw | 32 |  | mc | 0x200 (established; MC Chip Specification, section 5.11 (reset column)) | established | MC Chip Specification, section 5.11; IRIX sys/mc.h |
| `memcfg0` | 0xc4 | rw | 32 |  | mc | unknown | established | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code |
| `memcfg1` | 0xcc | rw | 32 |  | mc | unknown | established | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code |
| `cpu_memacc` | 0xd4 | rw | 32 |  | mc | 0x1454333 (established; MC Chip Specification, section 5.13 (reset column)) | established | MC Chip Specification, section 5.13; IRIX sys/mc.h |
| `gio_memacc` | 0xdc | rw | 32 |  | mc | 0x4333 (established; MC Chip Specification, section 5.13 (reset column)) | established | MC Chip Specification, section 5.13; IRIX sys/mc.h |
| `cpu_err_addr` | 0xe4 | r | 32 |  | mc | 0x0 (established; MC Chip Specification, section 5.14 (reset column)) | established | MC Chip Specification, section 5.14; IRIX sys/mc.h |
| `cpu_err_stat` | 0xec | rw | 32 |  | mc | 0x0 (established; MC Chip Specification, section 5.15 (reset column)) | established | MC Chip Specification, section 5.15; IRIX sys/mc.h |
| `gio_err_addr` | 0xf4 | r | 32 |  | mc | 0x0 (established; MC Chip Specification, section 5.16 (reset column)) | established | MC Chip Specification, section 5.16; IRIX sys/mc.h |
| `gio_err_stat` | 0xfc | rw | 32 |  | mc | 0x0 (established; MC Chip Specification, section 5.17 (reset column)) | established | MC Chip Specification, section 5.17; IRIX sys/mc.h |
| `sys_semaphore` | 0x104 | rw | 32 |  | mc | 0x0 (established; MC Chip Specification, section 5.18 (reset column)) | established | MC Chip Specification, sections 2.6.1 and 5.18; IRIX sys/mc.h |
| `lock_memory` | 0x10c | rw | 32 |  | mc | 0x1 (established; MC Chip Specification, section 5.19 (reset column)) | established | MC Chip Specification, section 5.19; IRIX sys/mc.h |
| `eisa_lock` | 0x114 | rw | 32 |  | mc | 0x1 (established; MC Chip Specification, section 5.20 (reset column)) | established | MC Chip Specification, section 5.20; IRIX sys/mc.h |
| `dma_gio_mask` | 0x154 | rw | 32 |  | mc | unknown | inferred | IRIX sys/mc.h (name and role); IRIX VDMA initialisation (writes zero) |
| `dma_gio_sub` | 0x15c | rw | 32 |  | mc | unknown | inferred | IRIX sys/mc.h (name and role); IRIX VDMA initialisation (writes zero) |
| `dma_cause` | 0x164 | rw | 32 |  | mc | unknown | established | IRIX VDMA header and kernel VDMA code; IRIX sys/mc.h |
| `dma_ctl` | 0x16c | rw | 32 |  | mc | unknown | established | IRIX VDMA header and kernel VDMA code |
| `dma_tlb_hi` | 0x184 | rw | 32 | 4 | mc | unknown | established | IRIX kernel VDMA code (uTLB handling) |
| `dma_tlb_lo` | 0x18c | rw | 32 | 4 | mc | unknown | established | IRIX kernel VDMA code (uTLB handling) |
| `rpss_ctr` | 0x1004 | r | 32 |  | mc | 0x0 (established; MC Chip Specification, section 5.21 (reset column)) | established | MC Chip Specification, sections 2.6.2 and 5.21; IRIX sys/mc.h |
| `dma_memadr` | 0x2004 | rw | 32 |  | mc | unknown | established | IRIX sys/mc.h; IRIX kernel VDMA code |
| `dma_memadrd` | 0x200c | w | 32 |  | mc | unknown | inferred | IRIX sys/mc.h (name and note: memory address and set defaults) |
| `dma_size` | 0x2014 | rw | 32 |  | mc | unknown | established | IRIX kernel VDMA code; Indigo PROM memory clear |
| `dma_stride` | 0x201c | rw | 32 |  | mc | unknown | established | IRIX kernel VDMA code; IRIX vdma_args structure |
| `dma_gio_adr` | 0x2024 | rw | 32 |  | mc | unknown | established | IRIX sys/mc.h; IRIX vdma_args structure |
| `dma_gio_adrs` | 0x202c | w | 32 |  | mc | unknown | established | IRIX sys/mc.h; IRIX kernel VDMA code; Indigo PROM memory clear |
| `dma_mode` | 0x2034 | rw | 32 |  | mc | unknown | established | IRIX VDMA header |
| `dma_count` | 0x203c | rw | 32 |  | mc | unknown | inferred | IRIX sys/mc.h (name: zoom count and byte count); Indigo PROM memory clear |
| `dma_stdma` | 0x2044 | rw | 32 |  | mc | unknown | established | IRIX kernel VDMA code |
| `dma_run` | 0x204c | r | 32 |  | mc | unknown | established | IRIX VDMA header and kernel VDMA code; Indigo PROM memory clear |
| `dma_memadrds` | 0x2074 | w | 32 |  | mc | unknown | inferred | IRIX sys/mc.h (name and note: memory address, set defaults and start DMA) |
| `semaphore` | 0x10004 | rw | 32 | 16 | mc | 0x0 (established; MC Chip Specification, section 5.18 (reset column)) | established | MC Chip Specification, sections 2.6.1 and 5.18; IRIX sys/mc.h |

### Register `cpuctrl0`

CPU control 0: refresh, parity reporting, watchdog enable, system and graphics reset, interrupt enable, PROM-write bus error, warm resets, the little-endian toggle, the MUX FIFO high-water mark and the bus-error data stall. The Indigo PROM reads this register back after every store to any MC register, as a write-buffer flush, and the kernel's first-revision workaround is a dummy PROM read before each MC store. A qtest can check the reset value, that the stall field and the high-water field read back what was written, and that writing the warm-restart bit restarts the CPU without clearing memory.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `bus_rate` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Stall cycles between bus-error data returned to the CPU; should equal the CPU memory read column field. |
| 27 | `back2` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Allow back-to-back GIO writes with no dead tristate cycle between the MC and the MUX chip. |
| 26 | `r4k_chk_par_n` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Set: tell the R4000 not to check parity on memory read data. Clear: it checks. |
| 25 | `bad_par` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Write bad parity on CPU stores to memory, for a parity diagnostic. |
| 24:20 | `mux_hwm` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | High-water mark of the MUX chip CPU write FIFO; the lowest bit is ignored. Software stores 32 minus the mark: the value is the cache line size in bytes divided by 8, plus 4 (6, 8, 12 or 20 for 4-, 8-, 16- or 32-word lines). |
| 19 | `wrst` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Warm reset of the R4000 that does not re-read the serial EEPROM. |
| 18 | `little` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Configure the MC for a little-endian CPU. The boot-time EEPROM sets it; if it disagrees with the CPU the machine does not work. The Linux header calls bit 17 the little-endian bit and bit 18 a memory-destroying warm reset; the specification (section 5.1), NetBSD and the IRIX header (which the shipped IRIX code uses) say bit 17 is reserved and bit 18 is little-endian. |
| 16 | `wr_st` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Warm restart: starts an R4000 reset sequence without resetting other chips or most of the MC. Refresh continues. The Indigo PROM stores this bit alone to apply a new endian setting after rewriting the serial EEPROM. |
| 15 | `prom_wr_en` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Clear: a CPU write to the boot PROM raises a bus-error interrupt. Set: writes are silently ignored. It does not block the write. |
| 14 | `snoop_en` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Enable snoop logic for graphics DMA. |
| 13 | `int_en` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Enable the interrupt writes the MC makes to the CPU. Without it the CPU never sees an interrupt. |
| 12 | `cmd_par` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Report parity errors on the SysCmd bus. The specification notes early R4000 revisions do not drive correct SysCmd parity. |
| 11 | `en_lock` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Let EISA lock memory away from the CPU; the specification says to leave it 0. Meaningless on the Indigo, which has no EISA. |
| 10 | `grr` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Graphics reset, active low: clear asserts the graphics reset, set releases it. It resets to clear. |
| 9 | `sin` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | System initialization: setting it resets the whole machine as if power were cycled. |
| 8 | `dog` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Watchdog enable. The watchdog resets the machine when its counter wraps. |
| 7 | `cpr` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Report parity errors on CPU bus transactions. |
| 6 | `mpr` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Report parity errors on main memory. |
| 5 | `gpr` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Report parity errors on GIO transactions. |
| 4 | `rfe` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Refresh enable. |
| 3:0 | `refs` | established |  | MC Chip Specification, section 5.1; IRIX sys/mc.h | Refresh burst length divided by two lines: 1 is two lines, 2 is four, 4 is eight, 15 is thirty. Four lines for 1M-and-larger SIMMs; eight for 256Kx36 and 512Kx36. |

### Register `cpuctrl1`

CPU control 1: the CPU address/command FIFO high-water mark, GIO bus timeout enable and the fixed-endianness selects for the HPC and the two GIO slots. The HPC fixed bit must be set for an HPC1.5, which every Indigo uses, and clear for an HPC3. A qtest can check the reset value and that bits outside the defined ones read back as written or as zero (the source does not say which).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 17 | `exp1_little` | established |  | MC Chip Specification, section 5.2; IRIX sys/mc.h | Slot 1 DMA is little-endian when fixed. |
| 16 | `exp1_fx` | established |  | MC Chip Specification, section 5.2; IRIX sys/mc.h | Slot 1 DMA endianness is fixed to the slot 1 little-endian bit. |
| 15 | `exp0_little` | established |  | MC Chip Specification, section 5.2; IRIX sys/mc.h | Slot 0 DMA is little-endian when fixed. |
| 14 | `exp0_fx` | established |  | MC Chip Specification, section 5.2; IRIX sys/mc.h | Slot 0 DMA endianness is fixed to the slot 0 little-endian bit. |
| 13 | `hpc_little` | established |  | MC Chip Specification, section 5.2; IRIX sys/mc.h | HPC DMA is little-endian when the fixed bit is set. Set to the CPU's byte order for an HPC1.5. |
| 12 | `hpc_fx` | established |  | MC Chip Specification, section 5.2; IRIX sys/mc.h | HPC DMA endianness is fixed to the HPC little-endian bit. Set for HPC1.5, clear for HPC3. |
| 4 | `abort_en` | established |  | MC Chip Specification, section 5.2; IRIX sys/mc.h | Enable GIO bus timeouts. Without it a bad GIO address hangs the system. |
| 3:0 | `mc_hwm` | established |  | MC Chip Specification, section 5.2; IRIX sys/mc.h | High-water mark of the MC CPU address/command FIFO: 17 minus the entries wanted; never below 6. |

### Register `dogc`

Watchdog timer. A read returns the 20-bit counter, which counts refresh bursts and so wraps in about 67 seconds at the 62 microsecond refresh interval; any write clears it. When CPUCTRL0 enables the watchdog, a wrap resets the machine. IRIX names the read and the write DOGC and DOGR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:0 | `count` | established |  | MC Chip Specification, section 5.3; IRIX sys/mc.h | Watchdog counter. |

### Register `sysid`

MC revision and EISA-present bit. The specification gives revision A as 0 and revision B as 1; IRIX code treats revisions 0 and 1 specially and refers to a 'revision C' part for large DRAM, which is inferred to read 3.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `eisa` | established |  | MC Chip Specification, section 5.4; IRIX sys/mc.h | EISA bus present, from the board's eisa_present pin. Always 0 on the Indigo. |
| 3:0 | `chip_rev` | established |  | MC Chip Specification, section 5.4; IRIX sys/mc.h | Revision of the MC chip: 0 is A, 1 is B. |

### Register `rpss_divider`

Divider and increment for the RPSS counter. The counter adds the increment each time the CPU clock has been divided by the divider plus one. At a 50 MHz CPU clock the reset value (divide by five, add one) counts every 100 nanoseconds; for a 33 MHz clock the specification says divide by ten and add three. IRIX kernels write a different value (divide by two, add one).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `inc` | established |  | MC Chip Specification, section 5.5; IRIX sys/mc.h | Amount added to the RPSS counter on each divided tick. |
| 7:0 | `div` | established |  | MC Chip Specification, section 5.5; IRIX sys/mc.h | Clock divider minus one. |

### Register `eerom`

Bit-banged serial interface to the 93C56-class EEPROM that holds the R4000 mode stream. The first three EEPROM bits are read by the MC itself at reset: byte order, HPC bus width and a reserved bit. Software rewrites the EEPROM through this register and then restarts the CPU to change byte order. The data-in bit cannot be written. A qtest can check that data-in follows the modelled EEPROM and that chip-select and clock read back.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `sdata_in` | established |  | MC Chip Specification, section 5.6; IRIX sys/mc.h | Data from the EEPROM; read only. |
| 3 | `sdata_out` | established |  | MC Chip Specification, section 5.6; IRIX sys/mc.h | Data to the EEPROM. |
| 2 | `sck` | established |  | MC Chip Specification, section 5.6; IRIX sys/mc.h | EEPROM serial clock. |
| 1 | `cs` | established |  | MC Chip Specification, section 5.6; IRIX sys/mc.h | EEPROM chip select, active high. |
| 0 | `pre` | inferred |  | Linux asm/sgi/mc.h names it as the EEPROM PRE pin; the specification and the IRIX header call it reserved | PRE pin of the EEPROM. |

### Register `ctrld`

Refresh counter preload. The counter counts down at the CPU clock and, on reaching zero, reloads from this register and requests a refresh burst. It should hold the number of CPU clocks in 62.5 microseconds.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `ref` | established |  | MC Chip Specification, section 5.7; IRIX sys/mc.h | Preload value. |

### Register `ref_ctr`

Current value of the refresh counter.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `refc` | established |  | MC Chip Specification, section 5.8; IRIX sys/mc.h | Refresh counter. |

### Register `gio64_arb`

GIO arbitration parameters: per-device bus width, real-time or long-burst class, bus-master ability and pipelining. Real-time devices are served in fixed priority; long-burst devices round-robin with the CPU between each. The IRIX kernel comments that reads of this register and of the two time registers can return corrupted values, so it writes from a software copy and never reads back. A qtest can check the reset value and that every defined bit stores.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `exp1_piped` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | Slot 1 is a pipelined device. |
| 14 | `exp0_piped` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | Slot 0 is a pipelined device: 0 for Indigo, 1 for Fullhouse. |
| 13 | `exp1_mst` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | Slot 1 can be a bus master. |
| 12 | `exp0_mst` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | Slot 0 can be a bus master; set only when a master is installed. |
| 11 | `grx_mst` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | Graphics can be a bus master; the specification says 0 for every device that exists. |
| 10 | `one_gio` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | One pipelined GIO bus exists. Should be set. |
| 9 | `eisa_mst` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | EISA can be a GIO master: 0 for Indigo, 1 for Fullhouse. |
| 8 | `exp1_rt` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | Slot 1 is real-time. |
| 7 | `exp0_rt` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | Slot 0 is real-time. |
| 6 | `grx_rt` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | Graphics is a real-time device (1) or long-burst (0). |
| 5 | `hpc_exp_size_64` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | Second HPC (the window below the primary HPC) transfers are 64 bits wide. |
| 4 | `eisa_size_64` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | EISA transfers are 64 bits wide; the specification says set 0. |
| 3 | `exp1_size_64` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | GIO slot 1 transfers are 64 bits wide. 0 for Indigo. |
| 2 | `exp0_size_64` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | GIO slot 0 transfers are 64 bits wide. 0 for Indigo. |
| 1 | `grx_size_64` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | Graphics transfers are 64 bits wide. The specification says starter and Express graphics are 32-bit and Newport is 32-bit in an Indigo and 64-bit elsewhere. |
| 0 | `hpc_size_64` | established |  | MC Chip Specification, section 5.9; IRIX sys/mc.h | HPC transfers are 64 bits wide. 0 for HPC1 and HPC1.5, 1 for HPC3. Loaded from the serial EEPROM at reset because the MC needs it for the boot PROM fetches. |

### Register `cpu_time`

Length of the CPU's arbitration slot in GIO clocks. The CPU holds the bus for the whole period even if idle. IRIX writes 43 (about 1.3 microseconds at 33 MHz).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `time` | established |  | MC Chip Specification, section 5.10; IRIX sys/mc.h | GIO clocks in the CPU time period. |

### Register `lb_time`

Length of the long-burst devices' arbitration slot in GIO clocks. Unlike the CPU's, a long-burst slot ends when the device stops using the bus. IRIX writes 847 (about 25 microseconds at 33 MHz).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `time` | established |  | MC Chip Specification, section 5.11; IRIX sys/mc.h | GIO clocks in the long-burst time period. |

### Register `memcfg0`

Memory configuration for banks 0 (high half) and 1 (low half). Each bank is four 36-bit SIMMs of one size. The base is compared with physical address bits 29 to 22, so it is in 4 MiB units and must be a multiple of the bank size; larger banks go at lower bases. A zero half means no usable bank. The specification gives only the valid bits a reset value of 0. If two valid banks overlap, accesses raise a bus error and do not complete.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `bnk0` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 0 SIMMs have two sub-banks. |
| 29 | `vld0` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 0 is valid. |
| 28:24 | `msize0` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 0 SIMM size code. |
| 23:16 | `base0` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Base address of bank 0, in 4 MiB units. |
| 14 | `bnk1` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 1 SIMMs have two sub-banks; set for the 512Kx36, 2Mx36 and 8Mx36 sizes. |
| 13 | `vld1` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 1 is valid. |
| 12:8 | `msize1` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 1 SIMM size code: 0 is 256Kx36 (4 MiB bank), 1 is 512Kx36, 3 is 1Mx36, 7 is 2Mx36, 15 is 4Mx36, 31 is 8Mx36 (128 MiB bank). |
| 7:0 | `base1` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Base address of bank 1, in 4 MiB units. |

### Register `memcfg1`

Memory configuration for banks 2 (high half) and 3 (low half); the layout is that of the first configuration register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `bnk2` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 2 SIMMs have two sub-banks. |
| 29 | `vld2` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 2 is valid. |
| 28:24 | `msize2` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 2 SIMM size code. |
| 23:16 | `base2` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Base address of bank 2, in 4 MiB units. |
| 14 | `bnk3` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 3 SIMMs have two sub-banks. |
| 13 | `vld3` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 3 is valid. |
| 12:8 | `msize3` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Bank 3 SIMM size code. |
| 7:0 | `base3` | established |  | MC Chip Specification, section 5.12; IRIX sys/mc.h and the IRIX kernel's bank code | Base address of bank 3, in 4 MiB units. |

### Register `cpu_memacc`

DRAM timing used for CPU accesses, in CPU clocks. The Indigo PROM writes 0x11453433 and tests the register by walking a one bit through the low 28 bits, then restoring the old value. A qtest can check the reset value and that bits 27 to 0 store.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 29 | `big_alias` | established |  | IRIX sys/mc.h (revision D); Linux asm/sgi/mc.h | Place the low-memory alias at 512 MiB. Revision D parts only, never the Indigo. |
| 28 | `cas_half` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Hold CAS high for only half a cycle in page-mode reads; needed for three-cycle page-mode reads. |
| 27:24 | `cbr` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Refresh: cycles CAS is low before RAS drops. |
| 23:20 | `rasl` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Refresh: cycles RAS is high before CAS drops between lines. |
| 19:16 | `rcasl` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Refresh: cycles RAS is low before CAS is raised. |
| 15:12 | `rash` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Cycles RAS must stay high for precharge. |
| 11:8 | `row` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Row address cycles minus one; the specification says set 4. |
| 7:4 | `rd_col` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Cycles the column address is held between page-mode reads. |
| 3:0 | `wr_col` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Cycles the column address is held between page-mode writes. |

### Register `gio_memacc`

DRAM timing used for GIO accesses, in GIO clocks. The specification recommends write and read column 2, row 3 and precharge 2; the Indigo PROM writes read column 3, the Indy and Indigo2 PROMs read column 2.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 29 | `big_alias` | established |  | IRIX sys/mc.h (revision D); Linux asm/sgi/mc.h | As in the CPU register. Revision D only. |
| 17 | `addr_half` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Change the column address on the falling clock edge. |
| 16 | `cas_half` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Hold CAS high for half a cycle in page-mode reads. |
| 15:12 | `rash` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Cycles RAS must stay high. |
| 11:8 | `row` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Row address cycles. |
| 7:4 | `rd_col` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Cycles the column address is held between page-mode reads. |
| 3:0 | `wr_col` | established |  | MC Chip Specification, section 5.13; IRIX sys/mc.h | Cycles the column address is held between page-mode writes. |

### Register `cpu_err_addr`

Address of the last CPU parity or bus error; valid only while an error bit is set in the CPU error status. For a parity error the low three bits are meaningless and the status byte field gives the failing byte lane. The specification's revision B fix list says revision A could latch the wrong address when a write follows a read that failed parity.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `addr` | established |  | MC Chip Specification, section 5.14; IRIX sys/mc.h | Error address. |

### Register `cpu_err_stat`

CPU error status. Any write clears it (the PROM and the kernel write zero). The bits are sticky. A qtest can check that a write of any value clears every bit and that a CPU read of an unmapped address sets the address-error bit.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13 | `bad_data` | established |  | MC Chip Specification, section 5.15; IRIX sys/mc.h | The CPU sent a bad-data identifier. |
| 12 | `syscmd_par` | established |  | MC Chip Specification, section 5.15; IRIX sys/mc.h | SysCmd parity error; the byte field is invalid. |
| 11 | `sysad_par` | established |  | MC Chip Specification, section 5.15; IRIX sys/mc.h | SysAD address or MC write data parity error; only the low four byte bits are valid. |
| 10 | `addr` | established |  | MC Chip Specification, section 5.15; IRIX sys/mc.h | Memory bus error: the address maps to no valid bank, or an MC register was accessed at the address wrong for the current byte order. |
| 9 | `par` | established |  | MC Chip Specification, section 5.15; IRIX sys/mc.h | CPU parity error. |
| 8 | `rd` | established |  | MC Chip Specification, section 5.15; IRIX sys/mc.h | With the parity bit: the error was on a memory read (clear: a memory write). |
| 7:0 | `byte` | established |  | MC Chip Specification, section 5.15; IRIX sys/mc.h | Byte lanes in error, bit 0 the lowest lane; several may be set. |

### Register `gio_err_addr`

Address of the last GIO parity or bus error, valid while a GIO error bit is set. Low two bits are meaningless for 32-bit devices, low three for 64-bit.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `addr` | established |  | MC Chip Specification, section 5.16; IRIX sys/mc.h | Error address. |

### Register `gio_err_stat`

GIO error status. Any write clears it. The bits are sticky.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `pio_wr_par` | established |  | MC Chip Specification, section 5.17; IRIX sys/mc.h | Data parity error on a programmed-I/O write. |
| 14 | `pio_rd_par` | established |  | MC Chip Specification, section 5.17; IRIX sys/mc.h | Data parity error on a programmed-I/O read. |
| 13 | `bc` | established |  | MC Chip Specification, section 5.17; IRIX sys/mc.h | Parity error on a GIO slave byte-count cycle. |
| 12 | `addr` | established |  | MC Chip Specification, section 5.17; IRIX sys/mc.h | Parity error on a GIO slave address cycle; needs the GIO parity enable. |
| 11 | `prom` | established |  | MC Chip Specification, section 5.17; IRIX sys/mc.h | CPU wrote the boot PROM while the PROM-write enable in CPU control 0 was clear. |
| 10 | `time` | established |  | MC Chip Specification, section 5.17; IRIX sys/mc.h | GIO transaction timed out; needs the timeout enable in CPU control 1. |
| 9 | `wr_par` | established |  | MC Chip Specification, section 5.17; IRIX sys/mc.h | GIO memory write parity error. |
| 8 | `rd_par` | established |  | MC Chip Specification, section 5.17; IRIX sys/mc.h | GIO memory read parity error. |
| 7:0 | `byte` | established |  | MC Chip Specification, section 5.17; IRIX sys/mc.h | Byte lanes in error. |

### Register `sys_semaphore`

System semaphore, in the privileged register page. A read returns the bit and sets it to one; a write stores bit 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `sem` | established |  | MC Chip Specification, sections 2.6.1 and 5.18; IRIX sys/mc.h | Semaphore bit. |

### Register `lock_memory`

Writing 0 locks every device except the CPU out of main memory, for a locked CPU sequence; 1 releases.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `lock_n` | established |  | MC Chip Specification, section 5.19; IRIX sys/mc.h | 0 locked, 1 unlocked. |

### Register `eisa_lock`

Writing 0 asserts the EISA lock output. The Indigo has no EISA bus, so the register has no effect there (inferred from the absent bus).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `lock` | established |  | MC Chip Specification, section 5.20; IRIX sys/mc.h | 0 locked, 1 unlocked. |

### Register `dma_gio_mask`

Mask applied to the GIO address of a graphics DMA to translate it, with the substitution register. The kernel and the Indigo PROM store zero in both, which leaves the address unchanged. The bit layout is not stated by any source held.

### Register `dma_gio_sub`

Substitution bits for the GIO address translation; see the mask register.

### Register `dma_cause`

Sticky cause bits of the graphics DMA engine, the same bits the run register shows below the running bit. Software writes zero to clear them and to drop the DMA-done interrupt. Whether a write of any value clears them is not stated; IRIX only writes zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `bpte` | established |  | IRIX VDMA header and kernel VDMA code; IRIX sys/mc.h | Invalid page-table-entry address. |
| 4 | `bmem` | established |  | IRIX VDMA header and kernel VDMA code; IRIX sys/mc.h | Invalid memory address. |
| 3 | `complete` | established |  | IRIX VDMA header and kernel VDMA code; IRIX sys/mc.h | The last DMA finished successfully. IRIX ignores the error bits when this is set. |
| 2 | `clean` | established |  | IRIX VDMA header and kernel VDMA code; IRIX sys/mc.h | Wrote to a read-only page. |
| 1 | `utlbmiss` | established |  | IRIX VDMA header and kernel VDMA code; IRIX sys/mc.h | The four-entry DMA TLB had no entry for the segment. |
| 0 | `pagefault` | established |  | IRIX VDMA header and kernel VDMA code; IRIX sys/mc.h | Touched a page whose valid bit is clear. |

### Register `dma_ctl`

Graphics DMA control. The kernel initialises it to a constant that also carries fields no source names (the kernel's comment lists a TLB limit of 512, a slave limit of 4, a 32-word cache line and the page size); only the three named bits are defined here. The Indigo PROM writes zero to turn translation off for its memory-clear DMA.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 9 | `decslv` | established |  | IRIX VDMA header and kernel VDMA code | The slave does true GIO decrementing DMA. |
| 8 | `xlate` | established |  | IRIX VDMA header and kernel VDMA code | Translate DMA memory addresses as virtual through the DMA TLB; clear means physical. |
| 4 | `ie` | established |  | IRIX VDMA header and kernel VDMA code | Enable the DMA-complete interrupt. |

### Register `dma_tlb_hi`

DMA TLB entry high word, four entries. Holds the virtual address of one segment (the span one page of page-table entries maps), aligned to that span. Software clears unused entries by writing zero.

Array of 4 registers, stride 16.

### Register `dma_tlb_lo`

DMA TLB entry low word, four entries. Names the physical page of page-table entries for the segment in the matching high word. Bits 25 to 6 are the physical address divided by 64.

Array of 4 registers, stride 16.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25:6 | `pt_addr` | established |  | IRIX kernel VDMA code (uTLB handling) | Physical address of the page-table page, divided by 64. |
| 1 | `valid` | established |  | IRIX kernel VDMA code (uTLB handling) | Entry valid. |

### Register `rpss_ctr`

RPSS counter: 32 bits, read only, rolls over without an interrupt. It advances by the divider register's increment every divider-plus-one CPU clocks; at reset that is one every 100 nanoseconds at 50 MHz. The page is mappable by user processes. A qtest can check that two reads differ and that a write is ignored.

### Register `dma_memadr`

DMA memory address, virtual or physical according to the translate bit. It advances as the DMA runs, so after a stop or fault it names the next byte; software reads it to find the faulting address.

### Register `dma_memadrd`

Writes the memory address register and also sets default values for the other DMA parameters. Which defaults is not stated by any source held, and no held code writes it.

### Register `dma_size`

DMA line width in bytes and line count. The kernel splits transfers over 65535 bytes into lines of 32768.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:16 | `height` | established |  | IRIX kernel VDMA code; Indigo PROM memory clear | Number of lines. |
| 15:0 | `width` | established |  | IRIX kernel VDMA code; Indigo PROM memory clear | Line width in bytes. |

### Register `dma_stride`

Signed byte distance from the end of one line to the start of the next, and the vertical zoom factor (how many times each line repeats, at most 1023). The kernel forces the stride to zero when there is one line to avoid a TLB-miss quirk.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:16 | `zoom` | established |  | IRIX kernel VDMA code; IRIX vdma_args structure | Line repeat count. |
| 15:0 | `stride` | established |  | IRIX kernel VDMA code; IRIX vdma_args structure | Stride in bytes, two's complement. |

### Register `dma_gio_adr`

GIO slave address of the DMA, or the constant to write in fill mode. Writing it does not start the DMA.

### Register `dma_gio_adrs`

Writes the GIO address (or fill constant) and starts the DMA. The kernel writes it last, after the other parameters.

### Register `dma_mode`

DMA mode. The Indigo PROM's memory clear uses long burst, incrementing address, fill and graphics-to-host.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `lburst` | established |  | IRIX VDMA header | Long-burst transfers. |
| 5 | `snoop` | established |  | IRIX VDMA header | Enable cache snoop (short bursts). |
| 4 | `inca` | established |  | IRIX VDMA header | Memory address increments (clear: decrements). |
| 3 | `fill` | established |  | IRIX VDMA header | Write a constant (the GIO address register) to memory. |
| 2 | `sync` | established |  | IRIX VDMA header | Delay the transfer until the graphics sync. |
| 1 | `gtoh` | established |  | IRIX VDMA header | Transfer from graphics to host memory (clear: host to graphics). |

### Register `dma_count`

Working counters of the running DMA: the remaining zoom count and byte count. The Indigo PROM writes 1 in the upper half before starting a fill, commenting that the zoom factor is one; the field layout is not stated by any source held.

### Register `dma_stdma`

Start or resume the virtual DMA. The kernel writes 1 after fixing a page fault to resume and 0 to stop a timed-out transfer.

### Register `dma_run`

DMA status: the cause bits plus a running bit. The PROM polls the running bit to wait for its memory clear.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `running` | established |  | IRIX VDMA header and kernel VDMA code; Indigo PROM memory clear | A DMA is in progress. |
| 5 | `bpte` | established |  | IRIX VDMA header and kernel VDMA code; Indigo PROM memory clear | As in the cause register. |
| 4 | `bmem` | established |  | IRIX VDMA header and kernel VDMA code; Indigo PROM memory clear | As in the cause register. |
| 3 | `complete` | established |  | IRIX VDMA header and kernel VDMA code; Indigo PROM memory clear | As in the cause register. |
| 2 | `clean` | established |  | IRIX VDMA header and kernel VDMA code; Indigo PROM memory clear | As in the cause register. |
| 1 | `utlbmiss` | established |  | IRIX VDMA header and kernel VDMA code; Indigo PROM memory clear | As in the cause register. |
| 0 | `pagefault` | established |  | IRIX VDMA header and kernel VDMA code; Indigo PROM memory clear | As in the cause register. |

### Register `dma_memadrds`

Writes the memory address, sets the default DMA parameters and starts the DMA. No held code writes it.

### Register `semaphore`

Sixteen user semaphores, each in its own 4 KiB page so a page can be mapped into a user process. A read returns the bit and sets it to one; a write stores bit 0.

Array of 16 registers, stride 4096.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `sem` | established |  | MC Chip Specification, sections 2.6.1 and 5.18; IRIX sys/mc.h | Semaphore bit. |
