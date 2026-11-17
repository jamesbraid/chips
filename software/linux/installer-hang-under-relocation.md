# Installer hang under relocation (Debian 7.11 ia64, Linux 3.2.78)

Sibling of [sn2-io-discovery-3.2.md](sn2-io-discovery-3.2.md). Grades: established (read in the
binary or source), inferred (follows from those), unknown.

## What hangs

The Debian 7.11 netinst kernel, started by `elilo.efi -r` so the image is relocated into node
memory, stops before any console output with IP constant at `0xa000000100a0a4a0`.

Binary: the installer's decompressed `vmlinux`, sha256 `f2c573c29dbbc030e9f93a18...`. It has no
`.symtab`. Names below come from the code's shape and the 3.2.78 source. Debian's
`linux-image-3.2.0-4-mckinley` 3.2.78-1 (snapshot.debian.org, 2016-03-09) is not the same build:
its `System.map` puts `unw_init` at `0xa000000100a09a10` and `__end_unwind` at
`0xa0000001008e0d20`, the installer kernel has `unw_init` at `0xa000000100a09950` and
`__end_unwind` at `0xa0000001008e1620`. Do not use that map for this binary. (established)

## Q1: the function and the loop

- `0xa000000100a0a4a0` is the recovery stub for an advanced load. It sits in `.init.text` after
  `unw_init` (`0xa000000100a09950`, leaf, no `alloc`; established from the listing). Source:
  `unw_init` (`arch/ia64/kernel/unwind.c:2240-2281`) with `init_unwind_table`
  (`unwind.c:2082-2094`) inlined at line 2279. (established: the function reads the
  `unw` fields at `+0x130..0x160` and stores `kernel_table` start, end, array and length; inferred
  as the 3.2.78 source of this build.) Not SN2 specific: generic ia64 init code.
- What it computes: `table->end = KERNEL_START + end[-1].end_offset`. `__end_unwind` is a `char[]`
  (`include/asm/sections.h:26`), so gcc reads the 8-byte `end_offset` as eight `ld1.a`. The main
  path, `0xa000000100a0a0a0`: `ld1.a r26=[r29]` with `r29 = r28 + 0x1ffffffffffffff1`
  (`add` at `a0a076`, `movl` at `a0a066`), `r28 = &__end_unwind = 0xa0000001008e1620`
  (`ld8` at `a0a056`, end of `.IA_64.unwind`, `0x888040 + 0x595e0`). `chk.a.clr r26` is at
  `a0a106` and branches to the stub at `a4a0` when the ALAT entry is missing. The stub reloads
  `ld1 r26=[r29]`, shifts, `or`s and does `br.few 0xa000000100a0a110` (back to the main path, not
  to `a4a0`). So the IP stays at `a4a0` only if that `ld1` never completes. (established)
- It is a byte read, not a flag poll. Nobody sets the byte: it is the top of the linked unwind
  table.
- The address: the eight `movl` constants are `0x1ffffffffffffff0..f7`, i.e. `-16+k` masked to
  61 bits, and the add carries region 5 into region 6. Effective address
  `0xc0000001008e1611` = region 6 (uncached identity), physical `0x1008e1611`. Hand decode of the
  bundle at `a0a060` (raw `05 00 00 00 01 c0 ff ff ff ff 1f c0 13 f7 ff 67`): `i=0`, `ic=1`,
  `imm5c=0x1f`, `imm9d=0x1ff`, `imm7b=0x71`, `imm41=0x7fffffffff` gives `0x1ffffffffffffff1`.
  The same formula decodes `0xa000000100000000` correctly in the same function. (established)
  Debian's own mckinley kernel has the identical eight constants at
  `0xa000000100a0a0c0..a0a270`. Why gcc masks the offset: unknown.
- The base is the plain region 5 address, so the carry is real. `__gp` is `.got + 0x200000`
  (`System.map` of the mckinley build: `__gp = 0xa000000100ea42f0`, `.got` at `...ca42f0`). Installer
  `.got` is at `0xa000000100ca2530`, so `r1 = 0xa000000100ea2530` and the slot `r1-0x1ffc30` is
  `0xa000000100ca2900`, holding `0xa0000001008e1620` on disk (bytes `20 16 8e 00 01 00 00 a0`).
  The neighbouring start slot `r1-0x1ffda8` holds `0xa000000100888040`, the start of
  `.IA_64.unwind`, which confirms the gp. Debian's mckinley image has the same plain
  region 5 values (`__end_unwind` slot `0xa0000001008e0d20`, start slot `0xa000000100887788`). Neither file has
  any relocation section (static EXEC), so nothing rewrites the slots at load. (established)
- The working hypothesis (`__pa` on an image address instead of `ia64_tpa`) is wrong for this
  access: there is no `__pa` or `tpa` here. The physical address is the link virtual address
  with the region bits dropped, so it does not depend on where elilo put the image. (established)
- ALAT: between `a0a0a0` and `a0a106` there is no call, `invala`, `rfi` or `srlz`; the only store
  is `st8 [r10]=r31` at `a0a0e0` with `r10 = &unw.kernel_table.start` (not an alias of the
  region 6 line). The architecture lets an implementation drop ALAT entries, so reaching the stub is
  legal; the stub is the normal fallback. Whether the model drops entries it should keep: unknown
  (two-line test: `ld1.a` from ordinary RAM then `chk.a.clr` with no aliasing store must not
  branch).

## Q2: head.S and relocation

- `arch/ia64/kernel/head.S:238-247` pins the kernel TR from the current IP:
  `mov r3=ip; ... dep r2=0,r3,0,KERNEL_TR_PAGE_SHIFT; ... itr.i/itr.d`, with
  `KERNEL_TR_PAGE_SHIFT = _PAGE_SIZE_64M` (`include/asm/pgtable.h:585`). So the image runs at any
  64 MB aligned physical base. (established)
- Code that uses the image's physical address goes through `ia64_tpa`: `kernel/setup.c:228-233`,
  `mca.c:2007-2047`, `smpboot.c:854`, `machine_kexec.c`, `efi.c:208`, and
  `ia64_patch_vtop` (`patch.c:111`). I found no 3.2 code that hard-codes `0x4000000`.
  (established for the greps over `arch/ia64`)
- One real `__pa` on a possibly image-resident address: `sn/pci/pci_dma.c:428`,
  `__pa(&val)` in the SN_SAL_IOIF_PCI_SAFE call, `val` on the stack. Wrong only for a stack
  inside the image (the init task); low risk. (inferred)

## Q3: what the model needs

The hang is model-side or memory-map-side, not a kernel bug. The same read happens on real
hardware: unmapped or unpopulated memory just returns data (the result only feeds
`table->end`, used by kernel backtraces). Cause is not a 64 MB alignment, boot parameter or
relocation problem. (inferred)
- Physical `0x1008e1611` is node field 0, AS 0: compatibility space, not RAM (node RAM is AS 3) and not
  MMR space. It must complete as an uncached byte read with some answer instead of a stall; see
  [accesses to undefined MMR offsets](../../platforms/sn2/address-map.md#accesses-to-undefined-mmr-offsets).
- Also check that an `ld1.a` that completes allocates an ALAT entry and `chk.a.clr` falls
  through, and that a recovery `ld1` to the same UC address completes.
- A model that stalls on an unpopulated uncached read where hardware returns data or an error
  response needs that fixed independent of this kernel.
