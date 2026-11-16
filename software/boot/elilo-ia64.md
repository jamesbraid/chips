# ELILO on IA-64: what the boot loader hands the Linux kernel

How ELILO, the EFI boot loader of the SLES 9 and ProPack era Altix, loads a Linux/ia64 kernel, what it builds for it and the exact state it jumps in with. Stage 5 of the [Altix 350 boot path](../../platforms/sn2/boot-path.md#5-boot-loader-elilo); the kernel side that consumes this is [SN2 early boot](../linux/sn2-early-boot.md).

## Sources and grades

- **Binaries** (Ghidra export with the IA-64 processor and the PE32+ import, cross-checked with `ia64-linux-gnu-objdump` where noted). Both are PE32+ images for machine `0x200` (IA-64), subsystem 10 (EFI application), with symbol names kept:
  - `ia64-boot/elilo/elilo-3.16-ia64.efi` (SHA-256 starts `089bb8a0`), called **build 3.16** below;
  - `ia64-boot/elilo/elilo-3.4-7.sarge.1-ia64.efi` (SHA-256 starts `7e70c2a4`, from the Debian package `elilo_3.4-7.sarge.1_ia64.deb`), called **build 3.4** below.
- **Source:** the GPL source of ELILO 3.16 (`ia64-boot/elilo/elilo-3.16-all.tar.gz`, inner `elilo-3.16-source.tar.gz`): `elilo.c`, `bootparams.c`, `alloc.c`, `util.c`, `ia64/{system,plain_loader,gzip,fpswa,config,sysdeps.h}`. It names things. ELILO 3.4 source is not held, so every fact about build 3.4 comes from its binary alone.
- **Linux:** v2.6.5 `include/asm-ia64/system.h` (the kernel's copy of the structure) and `arch/ia64/kernel/head.S`, the Library `linux-history` root.
- **Grades** follow [AGENTS.md](../../AGENTS.md). **Established**: read in the named binary (function names are the binary's own) and agreeing with the source where the source exists. **Inferred**: reasoned. **Unknown**: not settled. Which ELILO release SGI shipped on the Altix media is **unknown**: neither build is from an SGI package, and no SGI `elilo.efi` or `elilo.conf` is held ([inventory](../../evidence/ia64-binaries.md)).

## The sequence

Build 3.16 `efi_main` in order (established from the binary; the same calls appear in build 3.4 apart from the points under "Differences between the builds"):

1. `BS->SetWatchdogTimer(0, 0, 0, NULL)`, then `ConOut->Reset(ConOut, FALSE)`.
2. `BS->HandleProtocol(image, LoadedImage)`; a read of the `EDD30` variable through `RT->GetVariable` (`RT->SetVariable` only when the variable needs forcing; it does not change what the kernel is given). `alternate_kernel` also reads an EFI variable when `-a` is used.
3. Configuration parse, then `sysdeps_preloop_actions`: the FPSWA search (below).
4. Configuration file: tried in this order, the first that reads wins: the file-system default names (the boot device's own list), then `elilo-ia64.conf`, then `elilo.conf`. Kernel default name `vmlinux`. A config that is not found is not an error when the user asked for the prompt.
5. Kernel load (`kernel_load`), optional initrd load, optional `-m` module load.
6. Command line is built from the config `append=`/image arguments plus variable substitution.
7. `close_devices()`, `create_boot_params()`, `BS->ExitBootServices(image, map_key)`, jump.

EFI boot services the loader calls before `ExitBootServices` (the names are established from the source and spot-checked against call-site offsets in the binary: `GetMemoryMap`, `AllocatePages`, `AllocatePool`, `FreePages`, `FreePool`, `HandleProtocol`, `LocateHandle`, `StartImage`, `SetWatchdogTimer`, `ExitBootServices`, `CreateEvent`, `CloseEvent`, `SetTimer`, `WaitForEvent`, `RaiseTPL`, `RestoreTPL`, `InstallProtocolInterface`, `UninstallProtocolInterface`; `LoadImage` is in `do_check_fpswa` by source): memory (`AllocatePool`, `AllocatePages`, `GetMemoryMap`), file access through `LoadedImage`, `SimpleFileSystem`, `FileInfo` and `DevicePath` protocols (and PXE/TFTP when net-booted), `LocateHandle(ByProtocol)` and `LoadImage`/`StartImage` for the FPSWA driver, console `ConOut->Reset`, `OutputString`, `QueryMode` and `ConIn` key reads with `WaitForEvent`/`SetTimer` for the boot-menu timeout. Runtime services before the jump: `GetVariable` (and `SetVariable` for `EDD30`). Nothing SAL, PAL or ACPI is called by ELILO itself.

## Loading the kernel: entry point and physical load address

Both the plain loader (`plain_loader.c`, binary `load_elf`) and the gzip loader (`gzip.c`, binary `gunzip_kernel`, selected when the first four bytes are a gzip header, as in the held `vmlinuz`) do the same ELF segment placement (**established** for the plain loader in source and build 3.16; the gzip loader's matching `alloc_kmem`/relocation code was read in the source only):

- The file must be an ELF64 `ET_EXEC` with `e_machine` = `EM_IA_64`. Either byte order is accepted.
- First pass over the program headers: of the `PT_LOAD` segments take the lowest `p_paddr` and the highest `p_paddr + p_memsz`. **The load address is `p_paddr`, taken as a physical address.** The lowest address must be page aligned (4 KiB EFI pages).
- `kdesc.kentry = e_entry`. A value with any of the top three address bits set (a virtual address) prints an error; the code does not stop there, but the kernel image would then jump to a region-bits address. A physical `e_entry` is what the kernel is built to have.
- `AllocatePages(AllocateAddress, EfiLoaderData, pages, low_addr)` for the whole span. If that fails and `-r`/`relocatable` is not set, loading stops ("relocation is disabled"). With relocation allowed it searches the memory map for `EfiConventionalMemory` aligned to 256 MiB and shifts every address by the difference; the kernel is not built to be moved, so for the held kernel this path is not a boot path.
- Second pass: each `PT_LOAD` is read to `p_paddr`, the tail up to `p_memsz` is zeroed, and executable segments are flushed with `fc` per 32 bytes then `sync.i; srlz.i`.
- The initrd is allocated by the allocator (`sysdeps_initrd_get_addr` returns 0, "anywhere", in the 3.16 source), as `EfiLoaderData`.

The held SN2 kernel's own numbers, from its ELF header (read directly, not through ELILO): `e_entry` `0x4008320`, first `PT_LOAD` `p_paddr` `0x4000000` (64 MiB; virtual `0xa000000100000000`), the last data segment ends at `0x4d34d60`. So the loader must be able to allocate from physical `0x4000000` upward; any `EfiLoaderData`, boot services or runtime descriptor over that range makes `AllocateAddress` fail ([SN2 early boot](../linux/sn2-early-boot.md#the-kernel-entry-state) says why the kernel cannot move). **Established** for both numbers and for ELILO's behaviour.

## The structure ELILO builds

`create_boot_params()` allocates **16 KiB** (`BOOT_PARAM_MEMSIZE`, `AllocatePool(EfiLoaderData)`), zeroes all of it, and places the NUL-terminated ASCII command line **at the end of the block** (`bp + 0x4000 - strlen - 1`). The structure is at the start. Offsets below are bytes from the pointer in `r28`.

| Offset | Field | Value ELILO stores | Grade |
|---|---|---|---|
| `0x00` | `command_line` | physical address of the ASCII command line inside the same 16 KiB block | established |
| `0x08` | `efi_systab` | the EFI system table pointer ELILO was given (physical) | established |
| `0x10` | `efi_memmap` | physical address of a fresh `GetMemoryMap` copy (an `EfiLoaderData` pool buffer, not inside the 16 KiB block) | established |
| `0x18` | `efi_memmap_size` | `MemoryMapSize` returned by `GetMemoryMap`, in bytes | established |
| `0x20` | `efi_memdesc_size` | `DescriptorSize` as returned (the firmware's stride; **not** `sizeof(EFI_MEMORY_DESCRIPTOR)` unless equal) | established |
| `0x28` | `efi_memdesc_version` | `DescriptorVersion` (u32), as returned | established |
| `0x2c` | `console_info.num_cols` | `columns` from `ConOut->QueryMode(ConOut, Mode->Mode, &cols, &rows)` (u16) | established |
| `0x2e` | `num_rows` | `rows` (u16) | established |
| `0x30` | `orig_x` | `ConOut->Mode->CursorColumn` (u16) | established |
| `0x32` | `orig_y` | `ConOut->Mode->CursorRow` (u16) | established |
| `0x38` | `fpswa` | the FPSWA protocol interface pointer, or 0 | established |
| `0x40` | `initrd_start` | physical address of the initrd, or 0 | established |
| `0x48` | `initrd_size` | initrd size in bytes, or 0 | established |
| `0x50` | `vmcode_start` | `-m` module address or 0 (build 3.16 only) | established |
| `0x58` | `vmcode_size` | module size or 0 (build 3.16 only) | established |
| `0x60`, `0x68` | `loader_addr`, `loader_size` | declared in the 3.16 source, never written (the block is zeroed): 0 | established |

The Linux v2.6.5 `struct ia64_boot_param` ends at `initrd_size` (`0x50` bytes), so the kernel ignores everything from `0x50`. Both builds have the same layout up to there. A `QueryMode` failure aborts the boot-parameter build ("boot_params QueryMode failed"), so the console object must answer `QueryMode`.

Details a model must honour:

- `efi_systab` is the **loader's** copy of the pointer in its own `SystemTable` argument; the kernel does not take it from the PROM ([EFI hand-off](../firmware/snprom/efi.md#2-the-hand-off-from-sal_b)).
- The memory map ELILO passes is the one **fetched immediately before** `ExitBootServices`, so it describes the ELILO allocations (boot-parameter block, map buffer, kernel pages, initrd) as `EfiLoaderData`. Its `MapKey` must still be current when `ExitBootServices` runs; `GetMemoryMap` is called with a 8 KiB first guess and regrown by `2 * sizeof(descriptor)` per `EFI_BUFFER_TOO_SMALL`. Any allocation made after that call, including by the firmware, invalidates the key.
- `GetMemoryMap` itself allocates (the buffer is a pool allocation), so the returned map includes that buffer; ELILO relies on the firmware growing the map consistently.
- FPSWA: `LocateHandle(ByProtocol, {c41b6531-97b9-11d3-9a29-0090273fc14d}, NULL, &size = 8, &handle)` then `HandleProtocol(handle, same GUID, &bp->fpswa)`; the stored value is the interface pointer, not the handle. A firmware with two FPSWA handles returns `EFI_BUFFER_TOO_SMALL` for the 8-byte buffer and ELILO leaves `fpswa` at 0. **Established** from the binary's GUID immediates and the call shape.
- FPSWA search order: the file `\efi\intel firmware\fpswa.efi` on every FAT file system, started with `LoadImage`/`StartImage` (an image already installed with a newer revision declines itself); a different file with `-F` or `fpswa=`. The PROM carries its own `drv_fpswa.efi` ([efi.md](../firmware/snprom/efi.md#1-the-container)); whether it is installed before ELILO runs, or ELILO loads another copy, is **unknown**.
- The structure comment says the pointed-to memory must be `EfiRuntimeServicesData`. ELILO allocates `EfiLoaderData` (type 2) in both builds, so the kernel's own reservation of the boot-parameter block, the memory map and the command line is what keeps it ([SN2 early boot](../linux/sn2-early-boot.md#memory-map-and-reservations)).

## Register and machine state at the jump

The last instructions of the loader (build 3.16, image offset `0x3910` with the branch at `0x391c`; build 3.4, `0x17a0` with the branch at `0x17ac`; read with `ia64-linux-gnu-objdump` and agreeing with the Ghidra listing) are:

```
ld8  r27 = [sp-relative slot holding kdesc.kentry]
mov  b6  = r27
mov  r28 = <boot-parameter pointer>
br.few b6          # not br.call: b0 is not updated
```

- **`r28`** holds the physical address of the boot-parameter block. **Established.**
- **`b6`** is the entry point (physical); `r27` holds the same value as a scratch (it loads the entry through `r27` into `b6`). No other register is set for the kernel. In particular `r1` (gp), `sp` (`r12`), `b0`, the register stack and `psr` are whatever EFI had at the point the application called `ExitBootServices`: EFI boot-services state, physical mode, interrupts off in practice. The kernel's first act is `rsm psr.i | psr.ic` and it rebuilds region registers, pins its own translation and uses its own stack, so it requires nothing beyond `r28` and physical-mode execution ([SN2 early boot](../linux/sn2-early-boot.md#the-kernel-entry-state)). The EFI specification, not ELILO, defines the rest, and the PROM's EFI state at that point is **unknown** (no capture).
- After `ExitBootServices` the boot-services table is gone: nothing in ELILO touches console, files or events again ("No console output permitted after create_boot_params" in the source).
- If `ExitBootServices` fails: build 3.16 frees the parameter block, rebuilds it with a fresh map and tries again, **three attempts in all** (two retries; the counter is tested before the third failure gives up); build 3.4 has **no retry** and returns with an error. Source for 3.16 (`elilo.c` `main_loop`) agrees with the binary; build 3.4 is binary only.

## Differences between the builds

| Point | Build 3.4 | Build 3.16 |
|---|---|---|
| Block size and struct size | 16 KiB; struct is `0x60` bytes (length check `0x61` + command line), nothing written past `0x50` | 16 KiB; struct is `0x70` bytes with `vmcode` and `loader_*` fields |
| `initrd_size` | `pages << 12` from a page count | byte size |
| `vmcode_*` | absent | present |
| `ExitBootServices` failure | one attempt | three attempts, rebuilding the parameter block |
| Console reset at start | not seen | `ConOut->Reset` at start (3.16 release note: added) |
| Boot-parameter offsets `0x00`-`0x48` | identical | identical |

The 3.4 column is from the binary: `create_boot_params` adds `0x61` to the command-line length against the `0x4000` limit (struct `0x60` plus the terminator) where 3.16 adds `0x71`, and `sysdeps_create_boot_params` takes three arguments instead of four.

## Where SN2 enters

Nowhere in the loader. A search of the 3.16 source for SN2, Altix, SHub, SAL and ACPI finds only the copyright names of SGI contributors and the ACPI memory-type strings in a memory-map printer; the loader reads no ACPI table and calls no SAL procedure. The SN2-specific parts of a boot reach the kernel only through (**established** for the mechanism, **unknown** for contents):

1. the SN2 PROM's EFI: system table, configuration tables (SAL system table, ACPI 2.0 RSDP, HCDP), memory map, the `QueryMode` console;
2. the kernel image's own physical load address (64 MiB on node 0);
3. the shipped `elilo.conf`: `append=` options such as the console are not held.

Therefore a model that implements the EFI side per [efi.md](../firmware/snprom/efi.md) and the kernel's requirements ([SN2 early boot](../linux/sn2-early-boot.md)) does not need any SN2 code in a loader, and a synthetic loader that builds this structure and jumps with `r28` set is equivalent for the kernel.

## Unknowns

- Which ELILO release and which `elilo.conf` SGI shipped; the console option on the Altix kernel line. Route: the ELILO package on the SLES 9 media (listed in the inventory, not extracted).
- The register and `psr` state the PROM's EFI leaves at `ExitBootServices` (the Intel EFI sample code is the likely source; not read).
- Whether the PROM's EFI hands out one FPSWA handle or two.

## Review

Independent review of chips commit `a4bfcf2`, examined at that revision. The reviewer wrote none of it. Method: both ELILO builds imported in Ghidra (PE32+ import) with every function decompiled, the 3.16 source read beside them, and the jump bundles read with `ia64-linux-gnu-objdump`.

**Confirmed.**

- Boot-parameter offsets `0x00` to `0x48` are identical in both builds and match the 3.16 structure (command line `0x00`, system table `0x08`, map `0x10`, map size `0x18`, descriptor size `0x20`, descriptor version `0x28`, console `0x2c` to `0x32`, FPSWA `0x38`, initrd `0x40` and `0x48`); build 3.16 also stores `vmcode_start`/`vmcode_size` at `0x50`/`0x58`; `0x60`/`0x68` are never written. The descriptor size is the value `GetMemoryMap` returns.
- Both builds allocate `0x4000` bytes as `EfiLoaderData`, zero it, and place the command line at `block + 0x4000 - (length + 1)`.
- The kernel is placed with `AllocatePages(AllocateAddress, EfiLoaderData, pages, p_paddr-based address)` in both builds (`alloc_kmem`).
- Build 3.16: three `ExitBootServices` attempts. Build 3.4: one attempt, then cleanup and return. Build 3.4 stores the initrd size as page count shifted left by 12.
- The jump is `mov b6 = r27; mov r28 = bp; br.few b6` in both builds (3.16 at `0x3910`/`0x391c`, 3.4 at `0x17a0`/`0x17ac`); no other register is written for the kernel.
- `SetWatchdogTimer` (`BS+0x100`) opens both builds; the `ConOut->Reset` call is in 3.16 only; `GetVariable` is `RT+0x48`.

**Fixed in this review.**

1. The 3.4 struct size was given as ending at `0x58`; the build's length check (`length + 0x61`) makes it `0x60`.
2. "Retries up to three times" read as three retries; the binary and the source make three attempts in all.
3. `r27` also holds the entry address at the jump (scratch); noted beside `b6`.

**Not checked.** The gzip loader path in the binary (source only, as the page says); the FPSWA two-handle behaviour and the config-file search order (source only); `psr` and register-stack state at `ExitBootServices` (needs the PROM's EFI).
