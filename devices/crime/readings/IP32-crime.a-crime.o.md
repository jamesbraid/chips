# Readings: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`

One entry per routine, filed here from the reading batches by binary.

- `crimeFifoEmptyHandler` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x0-0x120 (288 bytes).
  It occupies 288 bytes.
  The `lw` at 0x0 loads 4 bytes from a1 (arg1 at entry) +0x78.
  The `lw` at 0x8 loads 4 bytes from a1 (arg1 at entry) +0x220.
  The `lw` at 0x38 loads 4 bytes from a1 (arg1 at entry) +0x13c.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x220, including `sw` at 0x44, `sw` at 0xf4.
  The `sw` at 0x50 stores 4 bytes to a1 (arg1 at entry) +0x13c.
  The `lw` at 0x5c loads 4 bytes from a1 (arg1 at entry) +0x28.
  The `lw` at 0x60 loads 4 bytes from [a1+40] +0x18.
  The `lw` at 0x64 loads 4 bytes from [[a1+40]+24] +0x2c.
  The `sw` at 0x70 stores 4 bytes to [[a1+40]+24] +0x2c.
  The `sw` at 0xa0 stores 4 bytes to [a1+120] +0x400.
  The `sw` at 0xb0 stores 4 bytes to a1 (arg1 at entry) +0x3c.
  The `lw` at 0xdc loads 4 bytes from a1 (arg1 at entry) +0x228.
  The `jal` at 0x30 calls splhi with a0=[a1+120], a1=a1 at entry (arg1), a2=[a1+544], a3=a3 at entry (arg3).
  The `jal` at 0x48 calls untimeout with a0=[a1+316], a1=?, a2=?, a3=?.
  The `jal` at 0x54 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x6c calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x9c calls flushbus with a0=?, a1=[a1+120], a2=0xfffffffff01fffff, a3=?.
  The `jal` at 0xa4 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0xac calls force_resched with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xc8 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0xd8 calls untimeout with a0=[a1+552], a1=a1 at entry (arg1), a2=[a1+544], a3=a3 at entry (arg3).
  The `jal` at 0xe0 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xec calls sv_signal with a0=a1+556, a1=?, a2=?, a3=?.
  The `jal` at 0xf8 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x110 calls cmn_err with a0=0x5, a1=sym(.rodata), a2=[a1+544], a3=a3 at entry (arg3).
  The `beq` branch at 0x20 targets 0xd8, is taken when a2(=[a1+544]) == at(=0x2), and falls through when a2(=[a1+544]) != at(=0x2).
  The `bne` branch at 0x28 targets 0x108, is taken when a2(=[a1+544]) != v0(=0x1), and falls through when a2(=[a1+544]) == v0(=0x1).
  The `beq` branch at 0x40 targets 0xc8, is taken when a0(=[a1+316]) == 0, and falls through when a0(=[a1+316]) != 0.
  The `beq` branch at 0xd0 targets 0xb8 and is always taken.
  The `beq` branch at 0x100 targets 0xb8 and is always taken.
  The `beq` branch at 0x118 targets 0xb8 and is always taken.
  The return at 0xc0 has v0 = one of ret(force_resched), ret(splx), ret(cmn_err).

- `crimeFifoFullHandler` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x1a8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x1a8-0x384 (476 bytes).
  It occupies 476 bytes.
  The `lw` at 0x1b0 loads 4 bytes from a1 (arg1 at entry) +0x78.
  3 such `lw` accesses load 4 bytes from [a1+120] +0x4000, including `lw` at 0x1b4, `lw` at 0x220, `lw` at 0x28c.
  The `ld` at 0x1dc loads 8 bytes from abs 0xffffffffb4000010.
  2 such `lw` accesses load 4 bytes from [sym(gfxinfo)] +0x1c, including `lw` at 0x24c, `lw` at 0x270.
  2 such `sw` accesses store 4 bytes to [sym(gfxinfo)] +0x1c, including `sw` at 0x254, `sw` at 0x27c.
  The `lw` at 0x280 loads 4 bytes from [sym(gfxinfo)] +0x18.
  The `sw` at 0x288 stores 4 bytes to [sym(gfxinfo)] +0x18.
  The `sw` at 0x2cc stores 4 bytes to [a1+120] +0x400.
  The `lw` at 0x2d8 loads 4 bytes from a1 (arg1 at entry) +0x3c.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x28, including `lw` at 0x2e4, `lw` at 0x36c.
  The `sw` at 0x2ec stores 4 bytes to a1 (arg1 at entry) +0x3c.
  The `lw` at 0x2f0 loads 4 bytes from [a1+40] +0x18.
  The `lw` at 0x2f4 loads 4 bytes from [[a1+40]+24] +0x2c.
  The `sw` at 0x2fc stores 4 bytes to [[a1+40]+24] +0x2c.
  The `sw` at 0x304 stores 4 bytes to a1 (arg1 at entry) +0x48.
  The `sw` at 0x314 stores 4 bytes to a1 (arg1 at entry) +0x220.
  The `sw` at 0x328 stores 4 bytes to a1 (arg1 at entry) +0x13c.
  The `lw` at 0x344 loads 4 bytes from [a1+120] +0x400.
  The `jal` at 0x1f0 calls gfx_waitf_on with a0=?, a1=?, a2=?, a3=[sym(gfxinfo)].
  The `jal` at 0x200 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x238 calls gfx_waitf_off with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x290 calls splhi with a0=?, a1=?, a2=?, a3=[[a1+120]+16384], a4=[[sym(gfxinfo)]+24]+1.
  The `jal` at 0x2c8 calls flushbus with a0=?, a1=?, a2=?, a3=?, a7=0xfffffffff01fffff.
  The `jal` at 0x2d0 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x300 calls force_resched with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x318 calls timeout with a0=sym(crimeEmptyWaitTimeout), a1=a1 at entry (arg1), a2=0xc8, a3=?.
  The `jal` at 0x324 calls crime_intr_enable with a0=0x19, a1=?, a2=?, a3=?.
  The `jal` at 0x348 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=?, a3=[[a1+120]+1024].
  The `jal` at 0x360 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=?, a3=?, a7=[a1+60].
  The `beq` branch at 0x1d0 targets 0x334, is taken when v0(?) >= 0x41 (signed), and falls through when v0(?) < 0x41 (signed).
  The `bgez` branch at 0x1e8 targets 0x270, is taken when v1(=(([0xffffffffb4000010]:8 << 0x0) << 0x25)) >= 0 (signed), and falls through when v1(=(([0xffffffffb4000010]:8 << 0x0) << 0x25)) < 0 (signed).
  The `beq` branch at 0x1f8 targets 0x370 and is always taken.
  The `beq` branch at 0x218 targets 0x238, is taken when s1(?) >= 0x64 (signed), and falls through when s1(?) < 0x64 (signed).
  The `beq` branch at 0x230 targets 0x200, is taken when a0(?) >= a1(?) (unsigned), and falls through when a0(?) < a1(?) (unsigned).
  The `beq` branch at 0x244 targets 0x280, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x278 targets 0x258 and is always taken.
  The `bne` branch at 0x2dc targets 0x358, is taken when a7(=[a1+60]) != 0, and falls through when a7(=[a1+60]) == 0.
  The `beq` branch at 0x32c targets 0x25c and is always taken.
  The `beq` branch at 0x350 targets 0x1dc and is always taken.
  The `beq` branch at 0x368 targets 0x2e8 and is always taken.
  The `beq` branch at 0x37c targets 0x220 and is always taken.
  The return at 0x268 has v0 = one of ?, ret(crime_intr_enable).

- `crimeFifoFullHandler` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x1a8 (n32).
  Inferred: it is a CRIME interrupt-path routine, because it reads the CRIME interrupt status at
  offset 0x10 (the `ld` at 0x1dc, linked row CRIME 0x10 Interrupt Status) and then acts on one bit
  of that status and on the register block behind its argument. At entry it loads the pointer at
  +0x78 of the argument in a1 (the `lw` at 0x1b0), reads the word 0x4000 past it (the `lw` at 0x1b4)
  and takes the field of that word selected by a right shift of 0x12 and a mask of 0x7f (the `srl`
  at 0x1b8 and the `andi` at 0x1bc). When the field is 0x41 or more signed (the `beq` at 0x1d0), it
  calls `cmn_err` (the `jal` at 0x348) with the word at +0x400 of the same block as its fourth
  argument, and then reads the status. The 8-byte status is tested by the sign of its value shifted
  left by 0x25 (the `bgez` at 0x1e8); when the sign is clear, the routine adds 1 to the word at
  +0x1c of the record that the word at `gfxinfo` points to (the `sw` at 0x27c) and returns. When the
  sign is set, it calls `gfx_waitf_on` (the `jal` at 0x1f0) and loops from 0x200 to 0x230: each pass
  calls `us_delay` with 1 (the `jal` at 0x200), loads the `ibctl` word (the `lw` at 0x208 on later
  passes and at 0x370 on the first), takes its field selected by a right shift of 0x15 and a mask of
  0x7f (the `srl` at 0x214 and `andi` at 0x21c, or the `srl` at 0x374 and `andi` at 0x378 on the
  first pass), takes the same field of the +0x4000 word as before (the `lw` at 0x220, the `srl` at
  0x224 and the `andi` at 0x228), and continues while the +0x4000 field is at or above the `ibctl`
  field (the unsigned compare of the `beq` at 0x230). The loop ends when the +0x4000 field falls
  below the `ibctl` field or the counter s1 reaches 0x64 (the `slti` at 0x210, tested by the `beq`
  at 0x218), and either way it calls `gfx_waitf_off` (the `jal` at 0x238). If s1 is still below 0x64
  (the `beq` at 0x244 is not taken), it adds 1 to the word at +0x1c of the gfxinfo record again (the
  `sw` at 0x254) and returns. Otherwise the path at 0x280 adds 1 to the word at +0x18 of that record
  (the `sw` at 0x288), reloads the +0x4000 word (the `lw` at 0x28c), calls `splhi` (the `jal` at
  0x290) and takes the same field of the reloaded word from the frame copy (the `sd` at 0x294, the
  `ld` at 0x298). It adds 1 to that field (the `addiu` at 0x2b0), shifts it left by 0x15 (the `sll`
  at 0x2b8) and merges it into `ibctl` over the field selected by the mask 0xfe00000 (the `lui` at
  0x2a4 builds the mask). It stores the merged word to `ibctl` (the `sw` at 0x2c0) and to +0x400 of
  the block (the `sw` at 0x2cc, in the delay slot of the `flushbus` call at 0x2c8), then calls
  `splx` with the value `splhi` returned (the `jal` at 0x2d0). Before the common exit, a nonzero
  word at +0x3c of the argument (the `lw` at 0x2d8) sends the path through `cmn_err` (the `jal` at
  0x360); the common exit sets +0x3c to 1 (the `sw` at 0x2ec), adds 1 to the word at +0x2c of the
  record reached through +0x28 and +0x18 (the `sw` at 0x2fc), calls `force_resched` (the `jal` at
  0x300), sets +0x48 and +0x220 to 1 (the `sw` at 0x304 and 0x314), calls `timeout` with
  `crimeEmptyWaitTimeout`, its argument and 0xc8 (the `jal` at 0x318), stores the return at +0x13c
  (the `sw` at 0x328), and returns the value of `crime_intr_enable` called with 0x19 (the `jal` at
  0x324).
  Unknown: what the two fields count, since no datasheet row covers the block behind the pointer at
  +0x78 of the argument or the `ibctl` word.
  Unknown: the text of the messages passed to `cmn_err` at 0x348 and 0x360, since the bundle has no
  strings for them.
  Evidence grade: inferred.

- `crimeAttach` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x414 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x414-0x514 (256 bytes).
  It occupies 256 bytes.
  The `lw` at 0x450 loads 4 bytes from a0 (arg0 at entry) +0x18.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x4c0, `lw` at 0x4ec.
  The `sw` at 0x4f8 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `lw` at 0x500 loads 4 bytes from ?.
  The `sw` at 0x510 stores 4 bytes to ?.
  The `jal` at 0x47c calls gfxdd_recycle with a0=sym(crime_regmatch), a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=0x86000.
  The `jal` at 0x4d4 calls gfxdd_mmap with a0=?, a1=0x86000, a2=?, a3=sym(gfx_fault), a4=a0 at entry (arg0), a5=sp-64, a6=0x1, a7=a0+28.
  The `beq` branch at 0x458 targets 0x470, is taken when (a1 & 0xfff) == 0, and falls through when (a1 & 0xfff) != 0.
  The `beq` branch at 0x484 targets 0x494, is taken when v0(=ret(gfxdd_recycle)) == 0, and falls through when v0(=ret(gfxdd_recycle)) != 0.
  The `beq` branch at 0x48c targets 0x460 and is always taken.
  The `beq` branch at 0x4dc targets 0x4ec, is taken when v0(=ret(gfxdd_mmap)) == 0, and falls through when v0(=ret(gfxdd_mmap)) != 0.
  The `beq` branch at 0x4e4 targets 0x460 and is always taken.
  The `beq` branch at 0x50c targets 0x460 and is always taken.
  The return at 0x468 has v0 = one of 0x0, 0xc, 0x16.

- `crimeStart` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x5a0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x5a0-0x6e4 (324 bytes).
  It occupies 324 bytes.
  The `lw` at 0x5b8 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x5c4 loads 4 bytes from [a0+24] +0x7c.
  3 such `lw` accesses load 4 bytes from [a0+24] +0x80, including `lw` at 0x5d4, `lw` at 0x63c, `lw` at 0x660.
  2 such `lh` accesses load 2 bytes from sym(crimeBoards) +0x22, including `lh` at 0x600, `lh` at 0x618.
  2 such `lw` accesses load 4 bytes from sym(crmFpPrbState) +0x0, including `lw` at 0x624, `lw` at 0x67c.
  2 such `lh` accesses load 2 bytes from sym(crimeBoards) +0x32, including `lh` at 0x630, `lh` at 0x6d0.
  The `lbu` at 0x6ac loads 1 byte from [a0+24] +0x98.
  The `sb` at 0x6c0 stores 1 byte to [a0+24] +0x98.
  The `jal` at 0x5d8 calls gbeBlankScreen with a0=[a0+24], a1=[[a0+24]+124], a2=[[a0+24]+128], a3=0x0, a4=0x0.
  The `jal` at 0x640 calls i2cfp_DMI2_KernelEDID with a0=[[a0+24]+128], a1=[[a0+24]+124], a2=?, a3=?.
  The `jal` at 0x650 calls i2cfp_DMI2_FailedEDID with a0=[[a0+24]+124], a1=?, a2=?, a3=?.
  The `jal` at 0x664 calls crime_i2cProbe with a0=[[a0+24]+128], a1=[[a0+24]+124], a2=?, a3=?.
  The `jal` at 0x674 calls crime_validate_ddc_data with a0=[[a0+24]+124], a1=?, a2=?, a3=?.
  The `blez` branch at 0x5f4 targets 0x69c, is taken when a2(=[sym(crm_num_monitors)]) <= 0 (signed), and falls through when a2(=[sym(crm_num_monitors)]) > 0 (signed).
  The `beq` branch at 0x5fc targets 0x61c and is always taken.
  The `beq` branch at 0x610 targets 0x69c, is taken when s2(?) >= a2(=[sym(crm_num_monitors)]) (signed), and falls through when s2(?) < a2(=[sym(crm_num_monitors)]) (signed).
  The `beq` branch at 0x61c targets 0x660, is taken when t9(=[sym(crimeBoards+34)]:2) == 0, and falls through when t9(=[sym(crimeBoards+34)]:2) != 0.
  The `bne` branch at 0x628 targets 0x604, is taken when ra(=[sym(crmFpPrbState)]) != s3(=0x3), and falls through when ra(=[sym(crmFpPrbState)]) == s3(=0x3).
  The `bne` branch at 0x634 targets 0x604, is taken when at(=[sym(crimeBoards+50)]:2) != 0, and falls through when at(=[sym(crimeBoards+50)]:2) == 0.
  The `bne` branch at 0x648 targets 0x684, is taken when v0(=ret(i2cfp_DMI2_KernelEDID)) != 0, and falls through when v0(=ret(i2cfp_DMI2_KernelEDID)) == 0.
  The `beq` branch at 0x658 targets 0x688 and is always taken.
  The `beq` branch at 0x66c targets 0x67c, is taken when v0(=ret(crime_i2cProbe)) == 0, and falls through when v0(=ret(crime_i2cProbe)) != 0.
  The `beq` branch at 0x680 targets 0x6d0, is taken when v0(=[sym(crmFpPrbState)]) == s3(=0x3), and falls through when v0(=[sym(crmFpPrbState)]) != s3(=0x3).
  The `bne` branch at 0x694 targets 0x618, is taken when s2(?) < a2(=[sym(crm_num_monitors)]) (signed), and falls through when s2(?) >= a2(=[sym(crm_num_monitors)]) (signed).
  The `bne` branch at 0x6d4 targets 0x688, is taken when a1(=[sym(crimeBoards+50)]:2) != 0, and falls through when a1(=[sym(crimeBoards+50)]:2) == 0.
  The `beq` branch at 0x6dc targets 0x63c and is always taken.
  The return at 0x6c8 has v0 = 0x0.

- `crmInitialize` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x6e4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x6e4-0xa6c (904 bytes).
  It occupies 904 bytes.
  The `lw` at 0x6ec loads 4 bytes from a0 (arg0 at entry) +0x7c.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x80, including `lw` at 0x714, `lw` at 0x93c, `lw` at 0xa2c.
  The `lbu` at 0x720 loads 1 byte from a1 (arg1 at entry) +0x30.
  The `lbu` at 0x738 loads 1 byte from a1 (arg1 at entry) +0x31.
  2 such `sb` accesses store 1 byte to [a0+124] +0x2b, including `sb` at 0x73c, `sb` at 0x77c.
  The `lh` at 0x740 loads 2 bytes from a1 (arg1 at entry) +0x32.
  The `sh` at 0x744 stores 2 bytes to [a0+124] +0x20.
  The `lhu` at 0x748 loads 2 bytes from a1 (arg1 at entry) +0x34.
  2 such `sh` accesses store 2 bytes to [a0+124] +0x22, including `sh` at 0x74c, `sh` at 0x9b8.
  The `lbu` at 0x75c loads 1 byte from a1 (arg1 at entry) +0x36.
  2 such `sb` accesses store 1 byte to [a0+124] +0x2d, including `sb` at 0x760, `sb` at 0x778.
  2 such `sb` accesses store 1 byte to [a0+124] +0x2f, including `sb` at 0x780, `sb` at 0x9dc.
  The `lw` at 0x788 loads 4 bytes from a1 (arg1 at entry) +0x0.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x794, `lw` at 0x858.
  The `sw` at 0x7a4 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `sw` at 0x7b4 stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `lw` at 0x7d4 loads 4 bytes from sym(crimeVTimings) +0x0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x828, `lw` at 0x83c.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x834, `sw` at 0x848.
  2 such `sw` accesses store 4 bytes to [a0+124] +0xe4, including `sw` at 0x850, `sw` at 0x9d8.
  4 such `sw` accesses store 4 bytes to [a0+124] +0x30, including `sw` at 0x854, `sw` at 0x9d0, `sw` at 0xa1c.
  2 such `lbu` accesses load 1 byte from [a0+124] +0x2e, including `lbu` at 0x878, `lbu` at 0x9e8.
  The `lw` at 0x894 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x98, including `lbu` at 0x8a0, `lbu` at 0x984.
  The `lw` at 0x8f0 loads 4 bytes from a0 (arg0 at entry) +0x28.
  4 such `lw` accesses load 4 bytes from ret(gthread_find_gfxp) +0x18, including `lw` at 0x8fc, `lw` at 0x90c, `lw` at 0x914.
  The `sw` at 0x910 stores 4 bytes to [ret(gthread_find_gfxp)+24] +0x28.
  2 such `lw` accesses load 4 bytes from [ret(gthread_find_gfxp)+24] +0x3c, including `lw` at 0x918, `lw` at 0x930.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x944, `lw` at 0x980.
  The `sb` at 0x990 stores 1 byte to a0 (arg0 at entry) +0x98.
  The `lbu` at 0x9ac loads 1 byte from [a0+124] +0x2d.
  The `lh` at 0x9c4 loads 2 bytes from sym(crimeVTimings) +0x14.
  The `lbu` at 0x9f4 loads 1 byte from [a0+124] +0x2c.
  The `sw` at 0xa14 stores 4 bytes to a0 (arg0 at entry) +0x1d0.
  The `sb` at 0xa38 stores 1 byte to [a0+124] +0x2e.
  The `jal` at 0x710 calls gbeStop with a0=[a0+128], a1=sp-48, a2=sp-48, a3=sp-48.
  The `jal` at 0x7f0 calls crmInvalidVideoTiming with a0=a1 at entry (arg1), a1=0x10, a2=0x1, a3=?, a5=0xd.
  The `jal` at 0x8c0 calls us_delay with a0=?, a1=[sym(crmInitDelay)], a2=?, a3=?.
  The `jal` at 0x8c8 calls crmAllocGfxBuffers with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8d8 calls crmInitGbeData with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8e0 calls curthreadhandle with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x8e8 calls gthread_find_gfxp with a0=ret(curthreadhandle), a1=?, a2=?, a3=?.
  The `jal` at 0x904 calls psema with a0=[ret(gthread_find_gfxp)+24]+32, a1=0x219, a2=?, a3=?.
  The `jal` at 0x924 calls us_delay with a0=0x2, a1=?, a2=?, a3=?.
  The `jal` at 0x948 calls crimeInitHW with a0=[a0+120], a1=[a0+128], a2=[a0+124], a3=a0 at entry (arg0).
  The `jal` at 0x960 calls crmLoadTlbABC with a0=a0 at entry (arg0), a1=sym(crmFrameBuffer), a2=0x0, a3=?.
  The `jal` at 0x970 calls crmLoadTlbABC with a0=a0 at entry (arg0), a1=sym(crmFrameBuffer), a2=0x2, a3=?.
  The `jal` at 0x97c calls crmLoadCidTlb with a0=[a0+120], a1=sym(crmFrameBuffer), a2=?, a3=?.
  The `jal` at 0xa08 calls timeout with a0=sym(crime_i2cFpHotProbe), a1=a0 at entry (arg0), a2=0xbb8, a3=?.
  The `jal` at 0xa28 calls crime_i2cFpProbe with a0=[a0+128], a1=?, a2=?, a3=?.
  The `jal` at 0xa48 calls cmn_err with a0=0x4, a1=sym(.rodata)+200, a2=?, a3=?.
  The `jal` at 0xa5c calls cmn_err with a0=0x4, a1=sym(.rodata)+144, a2=?, a3=?.
  The `beq` branch at 0x718 targets 0x86c, is taken when s2(=a1) == 0, and falls through when s2(=a1) != 0.
  The `beq` branch at 0x728 targets 0x9dc, is taken when a1(=0x10) == v0(=[a1+48]:1), and falls through when a1(=0x10) != v0(=[a1+48]:1).
  The `beq` branch at 0x730 targets 0x9dc, is taken when v0(=[a1+48]:1) == at(=0x20), and falls through when v0(=[a1+48]:1) != at(=0x20).
  The `beq` branch at 0x754 targets 0x768, is taken when v1(=[sym(crm_dc_board_installed)]) == 0, and falls through when v1(=[sym(crm_dc_board_installed)]) != 0.
  The `beq` branch at 0x770 targets 0x9ac, is taken when a4(=[sym(physmem)]) >= 0x2001 (unsigned), and falls through when a4(=[sym(physmem)]) < 0x2001 (unsigned).
  The `beq` branch at 0x790 targets 0x7a0, is taken when v0(=[a1]) == a5(=0xd), and falls through when v0(=[a1]) != a5(=0xd).
  The `beq` branch at 0x79c targets 0x7b8, is taken when (a0(=[a1+4]) & 0x2) == 0, and falls through when (a0(=[a1+4]) & 0x2) != 0.
  The `blez` branch at 0x7b8 targets 0x7f0, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `beq` branch at 0x7c0 targets 0x7f0, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x7d8 targets 0x9c4, is taken when t0(=[sym(crimeVTimings)]) == v0(?), and falls through when t0(=[sym(crimeVTimings)]) != v0(?).
  The `bne` branch at 0x7e8 targets 0x7d4, is taken when a7(?) < 0x10 (signed), and falls through when a7(?) >= 0x10 (signed).
  The `beq` branch at 0x7f8 targets 0x808, is taken when v0(=ret(crmInvalidVideoTiming)) == 0, and falls through when v0(=ret(crmInvalidVideoTiming)) != 0.
  The `beq` branch at 0x800 targets 0x994 and is always taken.
  The `bgtz` branch at 0x844 targets 0x820, is taken when v0(?) > 0 (signed), and falls through when v0(?) <= 0 (signed).
  The `bne` branch at 0x860 targets 0xa58, is taken when (t9(=[a1+4]) & 0x2) != 0, and falls through when (t9(=[a1+4]) & 0x2) == 0.
  The `beq` branch at 0x870 targets 0xa28, is taken when t8(=[sym(crmFpPrbState)]) == 0, and falls through when t8(=[sym(crmFpPrbState)]) != 0.
  The `beq` branch at 0x880 targets 0xa18, is taken when a0(?) == t9(=0x82), and falls through when a0(?) != t9(=0x82).
  The `beq` branch at 0x88c targets 0xa20, is taken when a0(?) == ra(=0x83), and falls through when a0(?) != ra(=0x83).
  The `beq` branch at 0x898 targets 0x9e8, is taken when at(=[a0+464]) == 0, and falls through when at(=[a0+464]) != 0.
  The `beq` branch at 0x8a8 targets 0x8c8, is taken when (v0(=[a0+152]:1) & 0x2) == 0, and falls through when (v0(=[a0+152]:1) & 0x2) != 0.
  The `bne` branch at 0x8d0 targets 0xa44, is taken when v0(=ret(crmAllocGfxBuffers)) != 0, and falls through when v0(=ret(crmAllocGfxBuffers)) == 0.
  The `beq` branch at 0x8f4 targets 0x93c, is taken when a1(=[a0+40]) == v0(=ret(gthread_find_gfxp)), and falls through when a1(=[a0+40]) != v0(=ret(gthread_find_gfxp)).
  The `beq` branch at 0x91c targets 0x93c, is taken when a1(=[[ret(gthread_find_gfxp)+24]+60]) == 0, and falls through when a1(=[[ret(gthread_find_gfxp)+24]+60]) != 0.
  The `bne` branch at 0x934 targets 0x924, is taken when a3(=[[ret(gthread_find_gfxp)+24]+60]) != 0, and falls through when a3(=[[ret(gthread_find_gfxp)+24]+60]) == 0.
  The `beq` branch at 0x9b0 targets 0x784, is taken when t9(=[[a0+124]+45]:1) == 0, and falls through when t9(=[[a0+124]+45]:1) != 0.
  The `beq` branch at 0x9bc targets 0x788 and is always taken.
  The `beq` branch at 0x9c8 targets 0xa3c, is taken when ra(=[sym(crimeVTimings)+20]:2) == 0, and falls through when ra(=[sym(crimeVTimings)+20]:2) != 0.
  The `beq` branch at 0x9d4 targets 0x858 and is always taken.
  The `beq` branch at 0x9e0 targets 0x738 and is always taken.
  The `beq` branch at 0x9ec targets 0x8a0, is taken when at(=[[a0+124]+46]:1) == v0(=0x84), and falls through when at(=[[a0+124]+46]:1) != v0(=0x84).
  The `bne` branch at 0x9f8 targets 0x8a0, is taken when v1(=[[a0+124]+44]:1) != 0, and falls through when v1(=[[a0+124]+44]:1) == 0.
  The `beq` branch at 0xa10 targets 0x8a0 and is always taken.
  The `beq` branch at 0xa18 targets 0x894 and is always taken.
  The `beq` branch at 0xa20 targets 0x894 and is always taken.
  The `beq` branch at 0xa34 targets 0x87c and is always taken.
  The `beq` branch at 0xa3c targets 0x998 and is always taken.
  The `beq` branch at 0xa50 targets 0x994 and is always taken.
  The `beq` branch at 0xa64 targets 0x994 and is always taken.
  The return at 0x9a4 has v0 = one of 0x0, 0xc, 0x16.

- `crm_finddrawable` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0xbfc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0xbfc-0xcc4 (200 bytes).
  It occupies 200 bytes.
  The `lw` at 0xc24 loads 4 bytes from sym(crmFrameBuffer) +0xce0.
  The `lw` at 0xc30 loads 4 bytes from [sym(crm_drawables)] +0x8.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xc44, `lw` at 0xc50, `lw` at 0xc68.
  The `sw` at 0xca4 stores 4 bytes to ret(crm_createdrawable) +0x4.
  The `sw` at 0xca8 stores 4 bytes to ret(crm_createdrawable) +0x0.
  The `sw` at 0xcac stores 4 bytes to ?.
  The `lw` at 0xcb0 loads 4 bytes from ret(crm_createdrawable) +0x0.
  The `sw` at 0xcc0 stores 4 bytes to [ret(crm_createdrawable)] +0x4.
  The `jal` at 0xc14 calls mutex_lock with a0=sym(crm_drawlock), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc7c calls mutex_unlock with a0=sym(crm_drawlock), a1=?, a2=?, a3=?.
  The `jal` at 0xc98 calls crm_createdrawable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xc28 targets 0xc60, is taken when v0(=[sym(crm_drawables)]) == 0, and falls through when v0(=[sym(crm_drawables)]) != 0.
  The `beq` branch at 0xc38 targets 0xc60, is taken when a1(=[[sym(crm_drawables)]+8]) >= s0(=a0) (signed), and falls through when a1(=[[sym(crm_drawables)]+8]) < s0(=a0) (signed).
  The `beq` branch at 0xc48 targets 0xc98, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0xc58 targets 0xc40, is taken when a2(?) < s0(=a0) (signed), and falls through when a2(?) >= s0(=a0) (signed).
  The `beq` branch at 0xc60 targets 0xc98, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0xc6c targets 0xc98, is taken when a3(?) != s0(=a0), and falls through when a3(?) == s0(=a0).
  The `beq` branch at 0xcb4 targets 0xc78, is taken when a0(=[ret(crm_createdrawable)]) == 0, and falls through when a0(=[ret(crm_createdrawable)]) != 0.
  The `beq` branch at 0xcbc targets 0xc78 and is always taken.
  The return at 0xc90 has v0 = ?.

- `crm_unbinddrawable` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0xcc4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0xcc4-0xe6c (424 bytes).
  It occupies 424 bytes.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0xcf8, `sw` at 0xd78, `sw` at 0xd94.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0xc, including `lw` at 0xcfc, `lw` at 0xd1c, `lw` at 0xd80.
  2 such `lw` accesses load 4 bytes from [a0+12] +0x28, including `lw` at 0xd00, `lw` at 0xd20.
  The `sw` at 0xd08 stores 4 bytes to [a0+12] +0x28.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0xd0c, `lw` at 0xd2c, `lw` at 0xd6c.
  2 such `lw` accesses load 4 bytes from [a0+16] +0x28, including `lw` at 0xd10, `lw` at 0xd38.
  The `sw` at 0xd18 stores 4 bytes to [a0+16] +0x28.
  The `lw` at 0xd44 loads 4 bytes from [a0+16] +0x24.
  11 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd70, `lw` at 0xda0, `lw` at 0xda4.
  The `lw` at 0xe3c loads 4 bytes from [a0+12] +0x24.
  The `jal` at 0xd54 calls crm_destroydrawable with a0=[a0+16], a1=[a0+12], a2=[[a0+16]+40], a3=?.
  The `jal` at 0xe4c calls crm_destroydrawable with a0=[a0+12], a1=[a0+12], a2=[a0+12], a3=0x1.
  The `jal` at 0xe5c calls crm_destroydrawable with a0=?, a1=?, a2=a2 at entry (arg2), a3=?.
  The `bne` branch at 0xcd8 targets 0xd64, is taken when a1 != at(=0x3), and falls through when a1 == at(=0x3).
  The `bne` branch at 0xcf4 targets 0xce8, is taken when a0(?) < 0x3 (signed), and falls through when a0(?) >= 0x3 (signed).
  The `beq` branch at 0xd24 targets 0xe3c, is taken when v1(=[[a0+12]+40]) == 0, and falls through when v1(=[[a0+12]+40]) != 0.
  The `beq` branch at 0xd30 targets 0xe28, is taken when a1(=[a0+12]) == a0(=[a0+16]), and falls through when a1(=[a0+12]) != a0(=[a0+16]).
  The `bne` branch at 0xd3c targets 0xe28, is taken when a2(=[[a0+16]+40]) != 0, and falls through when a2(=[[a0+16]+40]) == 0.
  The `beq` branch at 0xd4c targets 0xe28, is taken when (a3(=[[a0+16]+36]) & 0x20) == 0, and falls through when (a3(=[[a0+16]+36]) & 0x20) != 0.
  The `beq` branch at 0xd5c targets 0xe28 and is always taken.
  The `beq` branch at 0xd64 targets 0xe34, is taken when a1 == a3(=0x1), and falls through when a1 != a3(=0x1).
  The `beq` branch at 0xd84 targets 0xe0c, is taken when a4(=[a0+12]) == a5(=[a0+16]), and falls through when a4(=[a0+12]) != a5(=[a0+16]).
  The `beq` branch at 0xd8c targets 0xda0 and is always taken.
  The `beq` branch at 0xd98 targets 0xe0c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xdac targets 0xdcc, is taken when a7(?) == a3(?), and falls through when a7(?) != a3(?).
  The `beq` branch at 0xdb8 targets 0xdcc, is taken when t0(?) == a3(?), and falls through when t0(?) != a3(?).
  The `bne` branch at 0xdc4 targets 0xdd0, is taken when t1(?) != a3(?), and falls through when t1(?) == a3(?).
  The `beq` branch at 0xdd0 targets 0xe0c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xde4 targets 0xd94, is taken when t2(?) == a3(?), and falls through when t2(?) != a3(?).
  The `beq` branch at 0xdf0 targets 0xd94, is taken when t3(?) == a3(?), and falls through when t3(?) != a3(?).
  The `bne` branch at 0xdfc targets 0xd98, is taken when t8(?) != a3(?), and falls through when t8(?) == a3(?).
  The `beq` branch at 0xe04 targets 0xd98 and is always taken.
  The `beq` branch at 0xe14 targets 0xe28, is taken when (t9(?) & 0x20) == 0, and falls through when (t9(?) & 0x20) != 0.
  The `beq` branch at 0xe20 targets 0xe5c, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `beq` branch at 0xe34 targets 0xd70 and is always taken.
  The `beq` branch at 0xe44 targets 0xd2c, is taken when (at(=[[a0+12]+36]) & 0x20) == 0, and falls through when (at(=[[a0+12]+36]) & 0x20) != 0.
  The `beq` branch at 0xe54 targets 0xd2c and is always taken.
  The `beq` branch at 0xe64 targets 0xe28 and is always taken.
  The return at 0xe2c has v0 = one of ?, ret(crm_destroydrawable).

- `crimeInitSpecialDDRN` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0xe6c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0xe6c-0xedc (112 bytes).
  It occupies 112 bytes.
  The `sw` at 0xe84 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `sw` at 0xe88 stores 4 bytes to a0 (arg0 at entry) +0xc.
  The `sw` at 0xe90 stores 4 bytes to ret(crm_finddrawable) +0x28.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0xc, including `lw` at 0xe94, `lw` at 0xea8, `lw` at 0xebc.
  The `sw` at 0xea4 stores 4 bytes to [a0+12] +0x18.
  The `sw` at 0xeb0 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `sw` at 0xeb8 stores 4 bytes to [a0+12] +0x1c.
  The `sw` at 0xec0 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `sw` at 0xec4 stores 4 bytes to [a0+12] +0x20.
  The `sw` at 0xecc stores 4 bytes to a0 (arg0 at entry) +0x8.
  The `jal` at 0xe7c calls crm_finddrawable with a0=0x0, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xed4 has v0 = [a0+12].

- `crimeCreateDDRN` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0xedc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0xedc-0x1010 (308 bytes).
  It occupies 308 bytes.
  The `lw` at 0xee8 loads 4 bytes from sym(crmFrameBuffer) +0x10.
  The `lw` at 0xf00 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `sw` at 0xf50 stores 4 bytes to ret(kern_malloc) +0x4c.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x7c, including `lw` at 0xf54, `lw` at 0xf64, `lw` at 0xf78.
  4 such `lw` accesses load 4 bytes from [a0+124] +0x30, including `lw` at 0xf58, `lw` at 0xf68, `lw` at 0xf7c.
  The `lh` at 0xf5c loads 2 bytes from [[a0+124]+48] +0x8.
  The `sh` at 0xf60 stores 2 bytes to ret(kvpalloc) +0x27c.
  3 such `lw` accesses load 4 bytes from ret(kern_malloc) +0x4c, including `lw` at 0xf6c, `lw` at 0xf80, `lw` at 0xfa8.
  The `lh` at 0xf70 loads 2 bytes from [[a0+124]+48] +0xa.
  The `sh` at 0xf74 stores 2 bytes to [ret(kern_malloc)+76] +0x27e.
  The `lw` at 0xf84 loads 4 bytes from [[a0+124]+48] +0xc.
  The `sw` at 0xf88 stores 4 bytes to [ret(kern_malloc)+76] +0x280.
  The `lw` at 0xf94 loads 4 bytes from [[a0+124]+48] +0x4.
  2 such `sh` accesses store 2 bytes to [ret(kern_malloc)+76] +0x284, including `sh` at 0xfac, `sh` at 0xffc.
  The `sw` at 0xfb0 stores 4 bytes to a1 (arg1 at entry) +0x4c.
  The `lw` at 0xfb4 loads 4 bytes from a1 (arg1 at entry) +0x30.
  The `sw` at 0xfb8 stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `lw` at 0xfbc loads 4 bytes from [a1+48] +0x8.
  The `lw` at 0xfc0 loads 4 bytes from [[a1+48]+8] +0x4.
  The `lw` at 0xfcc loads 4 bytes from a0 (arg0 at entry) +0x1c4.
  The `sw` at 0xfd0 stores 4 bytes to ret(kern_malloc) +0x14.
  The `sw` at 0xfd8 stores 4 bytes to a0 (arg0 at entry) +0x1c4.
  The `sw` at 0xff4 stores 4 bytes to a0 (arg0 at entry) +0x8.
  The `jal` at 0xf14 calls kern_malloc with a0=0x558, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf2c calls kvpalloc with a0=0x1, a1=0x20000000, a2=0x0, a3=?.
  The `jal` at 0xf3c calls bzero with a0=ret(kern_malloc), a1=0x558, a2=?, a3=?.
  The `jal` at 0xf48 calls bzero with a0=ret(kvpalloc), a1=0x288, a2=?, a3=?.
  The `jal` at 0x1000 calls crimeInitSpecialDDRN with a0=ret(kern_malloc), a1=[ret(kern_malloc)+76], a2=[ret(kern_malloc)+76], a3=[[[a1+48]+8]+4], a4=[a1+48], a5=a1 at entry (arg1).
  The `bne` branch at 0xef8 targets 0xf14, is taken when at(=[sym(crmFrameBuffer+16)]) != 0, and falls through when at(=[sym(crmFrameBuffer+16)]) == 0.
  The `bltz` branch at 0xf04 targets 0xff0, is taken when v0(=[a0+8]) < 0 (signed), and falls through when v0(=[a0+8]) >= 0 (signed).
  The `beq` branch at 0xf0c targets 0xfe0 and is always taken.
  The `beq` branch at 0xfa4 targets 0xff8, is taken when (v1(=[[[a0+124]+48]+4]) & 0x2) == 0, and falls through when (v1(=[[[a0+124]+48]+4]) & 0x2) != 0.
  The `beq` branch at 0xfc4 targets 0x1000, is taken when a3(=[[[a1+48]+8]+4]) == a4(=[a1+48]), and falls through when a3(=[[[a1+48]+8]+4]) != a4(=[a1+48]).
  The `beq` branch at 0xff0 targets 0xf0c and is always taken.
  The `beq` branch at 0xff8 targets 0xfb0 and is always taken.
  The `beq` branch at 0x1008 targets 0xfcc and is always taken.
  The return at 0xfe8 has v0 = one of -0x1, 0x0.

- `crimeDestroyDDRN` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x103c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x103c-0x124c (528 bytes).
  It occupies 528 bytes.
  The `lw` at 0x104c loads 4 bytes from a2 (arg2 at entry) +0x4c.
  The `lw` at 0x1078 loads 4 bytes from [a2+76] +0x30.
  The `lw` at 0x108c loads 4 bytes from [a2+76] +0x40.
  2 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x8, including `lw` at 0x10a0, `lw` at 0x1158.
  The `lw` at 0x10b8 loads 4 bytes from sym(crimeBoards) +0x10.
  The `sw` at 0x10d0 stores 4 bytes to sym(crimeBoards) +0x10.
  2 such `lw` accesses load 4 bytes from [a2+76] +0x18, including `lw` at 0x10d4, `lw` at 0x10ec.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1118, `lw` at 0x11e0.
  The `sw` at 0x111c stores 4 bytes to ?.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x4c, including `sw` at 0x1120, `sw` at 0x11f4.
  The `sw` at 0x1160 stores 4 bytes to a2 (arg2 at entry) +0x8.
  The `lw` at 0x116c loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lw` at 0x1170 loads 4 bytes from [a1+8] +0x4.
  3 such `lw` accesses load 4 bytes from sym(crmFrameBuffer) +0xce0, including `lw` at 0x1178, `lw` at 0x118c, `lw` at 0x122c.
  The `lw` at 0x117c loads 4 bytes from a0 (arg0 at entry) +0x1cc.
  2 such `lw` accesses load 4 bytes from sym(crmFrameBuffer) +0x35c, including `lw` at 0x1184, `lw` at 0x121c.
  The `lw` at 0x1198 loads 4 bytes from [a2+76] +0xc.
  The `lw` at 0x11a0 loads 4 bytes from [a2+76] +0x10.
  3 such `lw` accesses load 4 bytes from [a2+76] +0x20, including `lw` at 0x11b4, `lw` at 0x120c, `lw` at 0x1248.
  The `sw` at 0x11c8 stores 4 bytes to [a2+76] +0x20.
  The `lw` at 0x11cc loads 4 bytes from a0 (arg0 at entry) +0x1c4.
  The `sw` at 0x1234 stores 4 bytes to a0 (arg0 at entry) +0x1c4.
  The `jal` at 0x1070 calls crimeRetraceCloseRN with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1084 calls crmunpinscratch with a0=[a2+76]+36, a1=?, a2=?, a3=?.
  The `jal` at 0x1098 calls crmunpinscratch with a0=[a2+76]+52, a1=?, a2=?, a3=?.
  The `jal` at 0x10e4 calls gfxdd_lookup with a0=[[a2+76]+24], a1=[a2+76]+72, a2=?, a3=?.
  The `jal` at 0x1104 calls crmUnmapPages with a0=[a2+76]+24, a1=0x1, a2=?, a3=?.
  The `jal` at 0x1124 calls kern_free with a0=[a2+76], a1=?, a2=?, a3=?.
  The `jal` at 0x1154 calls kvpfree with a0=[a2+8], a1=0x1, a2=?, a3=?.
  The `jal` at 0x11ac calls crm_unbinddrawable with a0=[a2+76], a1=0x3, a2=?, a3=?.
  The `jal` at 0x11c0 calls crmFreeTex with a0=a0 at entry (arg0), a1=[[a2+76]+32], a2=?, a3=?.
  The `jal` at 0x1200 calls crm_unbinddrawable with a0=[a2+76], a1=0x2, a2=?, a3=?.
  The `jal` at 0x1210 calls crmUnmapPages with a0=a0+460, a1=?, a2=?, a3=?.
  The `jal` at 0x1220 calls crmUnmapChunk with a0=sym(crmFrameBuffer), a1=?, a2=?, a3=?.
  The `jal` at 0x123c calls crm_unbinddrawable with a0=[a2+76], a1=0x1, a2=?, a3=?.
  The `bne` branch at 0x1060 targets 0x1070, is taken when s0(=[a2+76]) != 0, and falls through when s0(=[a2+76]) == 0.
  The `beq` branch at 0x1068 targets 0x1134 and is always taken.
  The `beq` branch at 0x107c targets 0x108c, is taken when at(=[[a2+76]+48]) == 0, and falls through when at(=[[a2+76]+48]) != 0.
  The `beq` branch at 0x1090 targets 0x10a0, is taken when v0(=[[a2+76]+64]) == 0, and falls through when v0(=[[a2+76]+64]) != 0.
  The `beq` branch at 0x10a8 targets 0x1164, is taken when t8(=[a2+8]) == 0, and falls through when t8(=[a2+8]) != 0.
  The `bne` branch at 0x10c8 targets 0x10d4, is taken when v1(=sym(.bss)+1512) != a1(=[a2+76]+72), and falls through when v1(=sym(.bss)+1512) == a1(=[a2+76]+72).
  The `beq` branch at 0x10dc targets 0x114c, is taken when a0(=[[a2+76]+24]) == 0, and falls through when a0(=[[a2+76]+24]) != 0.
  The `beq` branch at 0x10f4 targets 0x1150, is taken when t8(=[[a2+76]+24]) == 0, and falls through when t8(=[[a2+76]+24]) != 0.
  The `beq` branch at 0x10fc targets 0x1154, is taken when v0(=ret(gfxdd_lookup)) == 0, and falls through when v0(=ret(gfxdd_lookup)) != 0.
  The `beq` branch at 0x110c targets 0x1154 and is always taken.
  The `beq` branch at 0x1114 targets 0x1230, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x115c targets 0x1168 and is always taken.
  The `bne` branch at 0x1174 targets 0x1190, is taken when ra(=[[a1+8]+4]) != at(=a1), and falls through when ra(=[[a1+8]+4]) == at(=a1).
  The `bne` branch at 0x1180 targets 0x1210, is taken when at(=[a0+460]) != 0, and falls through when at(=[a0+460]) == 0.
  The `bne` branch at 0x1188 targets 0x1220, is taken when v0(=[sym(crmGbeTables+36)]) != 0, and falls through when v0(=[sym(crmGbeTables+36)]) == 0.
  The `beq` branch at 0x1190 targets 0x11b4, is taken when v1(=[sym(crm_drawables)]) == 0, and falls through when v1(=[sym(crm_drawables)]) != 0.
  The `beq` branch at 0x119c targets 0x11f8, is taken when a0(=[[a2+76]+12]) == 0, and falls through when a0(=[[a2+76]+12]) != 0.
  The `beq` branch at 0x11a4 targets 0x1238, is taken when v0(=[[a2+76]+16]) == 0, and falls through when v0(=[[a2+76]+16]) != 0.
  The `beq` branch at 0x11b8 targets 0x11cc, is taken when a1(=[[a2+76]+32]) == 0, and falls through when a1(=[[a2+76]+32]) != 0.
  The `beq` branch at 0x11d0 targets 0x1120, is taken when v0(=[a0+452]) == 0, and falls through when v0(=[a0+452]) != 0.
  The `beq` branch at 0x11d8 targets 0x1114, is taken when s0(=[a2+76]) == v0(?), and falls through when s0(=[a2+76]) != v0(?).
  The `bne` branch at 0x11e8 targets 0x11d8, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x11f0 targets 0x1124 and is always taken.
  The `beq` branch at 0x11f8 targets 0x11b4, is taken when v0(=[[a2+76]+16]) == 0, and falls through when v0(=[[a2+76]+16]) != 0.
  The `beq` branch at 0x1208 targets 0x11b8 and is always taken.
  The `beq` branch at 0x1218 targets 0x1188 and is always taken.
  The `beq` branch at 0x1228 targets 0x1190 and is always taken.
  The `beq` branch at 0x1230 targets 0x1120 and is always taken.
  The `beq` branch at 0x1244 targets 0x11b8 and is always taken.
  The return at 0x1144 has v0 = 0x0.

- `crm_destroydrawable` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x124c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x124c-0x13b4 (360 bytes).
  It occupies 360 bytes.
  The `lw` at 0x1274 loads 4 bytes from sym(crmFrameBuffer) +0xce0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1288, `lw` at 0x12a8.
  The `lw` at 0x12d0 loads 4 bytes from a0 (arg0 at entry) +0x24.
  The `lw` at 0x12dc loads 4 bytes from sym(crmzbuffer) +0x0.
  The `lw` at 0x1320 loads 4 bytes from [sym(crmzbuffer)] +0x4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x14, including `lw` at 0x1334, `lw` at 0x1354.
  The `lw` at 0x1340 loads 4 bytes from [a0+20] +0x114.
  The `jal` at 0x1260 calls mutex_mine with a0=sym(crm_drawlock), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12e8 calls crmDestroyPbuffer with a0=a0 at entry (arg0), a1=?, a2=?, a3=sym(crmzbuffer).
  The `jal` at 0x12f0 calls crm_freedrawable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x132c calls crmSubtractZ with a0=a0 at entry (arg0), a1=a0+44, a2=[[sym(crmzbuffer)]+4], a3=sym(crmzbuffer).
  The `jal` at 0x134c calls kern_free with a0=[[a0+20]+276], a1=?, a2=?, a3=?.
  The `jal` at 0x1358 calls kern_free with a0=[a0+20], a1=?, a2=?, a3=?.
  The `jal` at 0x1360 calls crm_freedrawable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1370 calls mutex_unlock with a0=sym(crm_drawlock), a1=?, a2=?, a3=?.
  The `jal` at 0x1384 calls mutex_lock with a0=sym(crm_drawlock), a1=0x19, a2=?, a3=?.
  The `jal` at 0x1394 calls mutex_unlock with a0=sym(crm_drawlock), a1=?, a2=?, a3=?.
  The `jal` at 0x13a4 calls mutex_unlock with a0=sym(crm_drawlock), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1268 targets 0x1380, is taken when v0(=ret(mutex_mine)) == 0, and falls through when v0(=ret(mutex_mine)) != 0.
  The `beq` branch at 0x1278 targets 0x13a4, is taken when at(=[sym(crm_drawables)]) == 0, and falls through when at(=[sym(crm_drawables)]) != 0.
  The `beq` branch at 0x1280 targets 0x1294 and is always taken.
  The `beq` branch at 0x128c targets 0x12c8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x1294 targets 0x12a8, is taken when s0(=a0) != a3(?), and falls through when s0(=a0) == a3(?).
  The `beq` branch at 0x12a0 targets 0x12ac and is always taken.
  The `beq` branch at 0x12ac targets 0x12c8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x12b4 targets 0x1288, is taken when s0(=a0) != a3(?), and falls through when s0(=a0) == a3(?).
  The `beq` branch at 0x12c0 targets 0x128c and is always taken.
  The `beq` branch at 0x12c8 targets 0x13a4, is taken when a0(=one of 0x0, 0x1) == 0, and falls through when a0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x12e0 targets 0x1310, is taken when (a0(=[a0+36]) & 0x2) == 0, and falls through when (a0(=[a0+36]) & 0x2) != 0.
  The `beq` branch at 0x12f8 targets 0x1394, is taken when s1(=ret(mutex_mine)) == 0, and falls through when s1(=ret(mutex_mine)) != 0.
  The `beq` branch at 0x1310 targets 0x1334, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1318 targets 0x1334, is taken when v0(=[sym(crmzbuffer)]) == 0, and falls through when v0(=[sym(crmzbuffer)]) != 0.
  The `beq` branch at 0x1324 targets 0x1334, is taken when a2(=[[sym(crmzbuffer)]+4]) == 0, and falls through when a2(=[[sym(crmzbuffer)]+4]) != 0.
  The `beq` branch at 0x1338 targets 0x1360, is taken when a0(=[a0+20]) == 0, and falls through when a0(=[a0+20]) != 0.
  The `beq` branch at 0x1344 targets 0x1358, is taken when v0(=[[a0+20]+276]) == 0, and falls through when v0(=[[a0+20]+276]) != 0.
  The `bne` branch at 0x1368 targets 0x1300, is taken when s1(=ret(mutex_mine)) != 0, and falls through when s1(=ret(mutex_mine)) == 0.
  The `beq` branch at 0x1378 targets 0x1300 and is always taken.
  The `beq` branch at 0x138c targets 0x1274 and is always taken.
  The `beq` branch at 0x139c targets 0x1300 and is always taken.
  The `beq` branch at 0x13ac targets 0x1300 and is always taken.
  The return at 0x1308 has v0 = one of ret(crm_freedrawable), ret(mutex_unlock).

- `crm_enableovl` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x13b4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x13b4-0x1494 (224 bytes).
  It occupies 224 bytes.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x18, including `lw` at 0x13c0, `lw` at 0x143c.
  The `sw` at 0x13e8 stores 4 bytes to a3 (arg3 at entry) +0x18.
  The `lw` at 0x13ec loads 4 bytes from a2 (arg2 at entry) +0xc.
  The `sw` at 0x13f8 stores 4 bytes to a2 (arg2 at entry) +0x0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0x13fc, `lw` at 0x1420, `lw` at 0x1438.
  The `lw` at 0x1400 loads 4 bytes from [a0+24] +0x4.
  2 such `lw` accesses load 4 bytes from [a0+24] +0x78, including `lw` at 0x1430, `lw` at 0x1464.
  The `jal` at 0x140c calls RRM_CheckValidFault with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=sym(crmFrameBuffer), a7=[a2+12].
  The `jal` at 0x142c calls crmSavePP with a0=[[a0+24]+120], a1=a2+848, a2=a2+336, a3=?.
  The `jal` at 0x1440 calls crmLoadTlbABC with a0=[a0+24], a1=[a3+24], a2=0x0, a3=?.
  The `jal` at 0x1460 calls crmRestorePP with a0=[[a0+24]+120], a1=a2+848, a2=a2+336, a3=ret(crmSavePP).
  The `beq` branch at 0x13e0 targets 0x1484, is taken when at(=[a3+24]) == v0(=sym(crmFrameBuffer)), and falls through when at(=[a3+24]) != v0(=sym(crmFrameBuffer)).
  The `bne` branch at 0x13f0 targets 0x13fc, is taken when a7(=[a2+12]) != a3, and falls through when a7(=[a2+12]) == a3.
  The `bne` branch at 0x1404 targets 0x146c, is taken when t0(=[[a0+24]+4]) != a1, and falls through when t0(=[[a0+24]+4]) == a1.
  The `bltz` branch at 0x1414 targets 0x148c, is taken when v0(=ret(RRM_CheckValidFault)) < 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) >= 0 (signed).
  The `blez` branch at 0x1448 targets 0x146c, is taken when s1(=ret(crmSavePP)) <= 0 (signed), and falls through when s1(=ret(crmSavePP)) > 0 (signed).
  The `beq` branch at 0x1484 targets 0x146c and is always taken.
  The `beq` branch at 0x148c targets 0x146c and is always taken.
  The return at 0x147c has v0 = one of 0x0, 0xe.

- `crm_enablesz` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x1494 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x1494-0x1884 (1008 bytes).
  It occupies 1008 bytes.
  The `lw` at 0x14a0 loads 4 bytes from a3 (arg3 at entry) +0x20.
  2 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0xc, including `lw` at 0x14c0, `lw` at 0x1590.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x8, including `sw` at 0x14cc, `sw` at 0x159c.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x24, including `lw` at 0x14f0, `lw` at 0x1580.
  The `sw` at 0x1530 stores 4 bytes to ret(kern_malloc) +0x4.
  9 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0x1538, `lw` at 0x155c, `lw` at 0x16e0.
  5 such `lw` accesses load 4 bytes from [a0+24] +0x2c, including `lw` at 0x153c, `lw` at 0x1560, `lw` at 0x16e4.
  5 such `sw` accesses store 4 bytes to [a0+24] +0x2c, including `sw` at 0x1544, `sw` at 0x1570, `sw` at 0x16f4.
  9 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1550, `lw` at 0x1574, `lw` at 0x16dc.
  The `sw` at 0x1584 stores 4 bytes to a3 (arg3 at entry) +0x20.
  The `sw` at 0x158c stores 4 bytes to a3 (arg3 at entry) +0x24.
  6 such `sh` accesses store 2 bytes to ?, including `sh` at 0x15b0, `sh` at 0x15c0, `sh` at 0x15d8.
  The `lh` at 0x15dc loads 2 bytes from a3 (arg3 at entry) +0xc.
  2 such `lh` accesses load 2 bytes from a3 (arg3 at entry) +0x10, including `lh` at 0x15e8, `lh` at 0x1788.
  The `lh` at 0x162c loads 2 bytes from a3 (arg3 at entry) +0xe.
  2 such `lh` accesses load 2 bytes from a3 (arg3 at entry) +0x12, including `lh` at 0x1634, `lh` at 0x1784.
  2 such `lw` accesses load 4 bytes from [a0+24] +0x78, including `lw` at 0x1710, `lw` at 0x1740.
  The `lw` at 0x1770 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x1774 loads 4 bytes from [a0+8] +0x0.
  The `lhu` at 0x1778 loads 2 bytes from [[a0+8]] +0x22.
  The `lhu` at 0x1780 loads 2 bytes from [[a0+8]] +0x20.
  The `jal` at 0x1500 calls kern_malloc with a0=0x408, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1510 calls bzero with a0=ret(kern_malloc), a1=0x408, a2=?, a3=?.
  The `jal` at 0x1524 calls sema_alloc with a0=0x0, a1=0x1, a2=sym(.rodata)+248, a3=?.
  The `jal` at 0x154c calls psema with a0=?, a1=0x11a, a2=?, a3=?.
  The `jal` at 0x16bc calls crmAddZ with a0=a3 at entry (arg3), a1=a3+44, a2=?, a3=?, a6=0x1.
  The `jal` at 0x16d0 calls bzero with a0=a3+44, a1=0x40, a2=?, a3=?.
  The `jal` at 0x16d8 calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x170c calls crmSavePP with a0=[[a0+24]+120], a1=a2+848, a2=a2+336, a3=?.
  The `jal` at 0x1720 calls crmLoadTlbABC with a0=[a0+24], a1=?, a2=0x2, a3=?.
  The `jal` at 0x173c calls crmRestorePP with a0=[[a0+24]+120], a1=a2+848, a2=a2+336, a3=ret(crmSavePP).
  The `jal` at 0x1744 calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x178c calls crmAllocZbuffer with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x17ac calls vsema with a0=?, a1=?, a2=sym(crmzbuffer), a3=?.
  The `jal` at 0x17b4 calls valusema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x17c4 calls sema_dealloc with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x17cc calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x185c calls vsema with a0=?, a1=?, a2=sym(crmzbuffer), a3=?.
  The `beq` branch at 0x14b8 targets 0x14f0, is taken when v0(=[a3+32]) == 0, and falls through when v0(=[a3+32]) != 0.
  The `bne` branch at 0x14c4 targets 0x14d0, is taken when at(=[a2+12]) != a3, and falls through when at(=[a2+12]) == a3.
  The `beq` branch at 0x14f8 targets 0x1534, is taken when (v0(=[a3+36]) & 0x2) == 0, and falls through when (v0(=[a3+36]) & 0x2) != 0.
  The `beq` branch at 0x152c targets 0x1538 and is always taken.
  The `beq` branch at 0x1554 targets 0x1574, is taken when v0(=ret(psema)) == 0, and falls through when v0(=ret(psema)) != 0.
  The `beq` branch at 0x156c targets 0x14d4 and is always taken.
  The `beq` branch at 0x1578 targets 0x1764, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1594 targets 0x15a4, is taken when ra(=[a2+12]) != s1(=a3), and falls through when ra(=[a2+12]) == s1(=a3).
  The `beq` branch at 0x15b4 targets 0x15dc, is taken when v0(?) >= 0x20 (signed), and falls through when v0(?) < 0x20 (signed).
  The `beq` branch at 0x15c4 targets 0x15dc, is taken when v0(?) >= 0x20 (signed), and falls through when v0(?) < 0x20 (signed).
  The `bne` branch at 0x15d4 targets 0x15a8, is taken when v0(?) < 0x20 (signed), and falls through when v0(?) >= 0x20 (signed).
  The `bltz` branch at 0x15e4 targets 0x17ec, is taken when a0(=[a3+12]:2) < 0 (signed), and falls through when a0(=[a3+12]:2) >= 0 (signed).
  The `beq` branch at 0x15f8 targets 0x184c, is taken when v0(=[a3+16]:2) == 0, and falls through when v0(=[a3+16]:2) != 0.
  The `bltz` branch at 0x1630 targets 0x1818, is taken when a1(=[a3+14]:2) < 0 (signed), and falls through when a1(=[a3+14]:2) >= 0 (signed).
  The `beq` branch at 0x1644 targets 0x1854, is taken when a0(=[a3+18]:2) == 0, and falls through when a0(=[a3+18]:2) != 0.
  The `beq` branch at 0x1674 targets 0x16b4, is taken when v0(?) >= a1(?) (signed), and falls through when v0(?) < a1(?) (signed).
  The `beq` branch at 0x168c targets 0x16b4, is taken when v0(?) >= a1(?) (signed), and falls through when v0(?) < a1(?) (signed).
  The `beq` branch at 0x169c targets 0x16b4, is taken when v0(?) >= a1(?) (signed), and falls through when v0(?) < a1(?) (signed).
  The `bne` branch at 0x16ac targets 0x1680, is taken when v0(?) < a1(?) (signed), and falls through when v0(?) >= a1(?) (signed).
  The `beq` branch at 0x16c4 targets 0x16f8, is taken when v0(=ret(crmAddZ)) == 0, and falls through when v0(=ret(crmAddZ)) != 0.
  The `beq` branch at 0x16f0 targets 0x14d4 and is always taken.
  The `blez` branch at 0x1728 targets 0x1744, is taken when s1(=ret(crmSavePP)) <= 0 (signed), and falls through when s1(=ret(crmSavePP)) > 0 (signed).
  The `beq` branch at 0x175c targets 0x14d4 and is always taken.
  The `bne` branch at 0x1768 targets 0x1784, is taken when s0(?) != a2(=sym(crmzbuffer)), and falls through when s0(?) == a2(=sym(crmzbuffer)).
  The `beq` branch at 0x177c targets 0x178c and is always taken.
  The `beq` branch at 0x1794 targets 0x186c, is taken when v0(=ret(crmAllocZbuffer)) == 0, and falls through when v0(=ret(crmAllocZbuffer)) != 0.
  The `beq` branch at 0x17a4 targets 0x185c, is taken when s0(?) == a2(=sym(crmzbuffer)), and falls through when s0(?) != a2(=sym(crmzbuffer)).
  The `blez` branch at 0x17bc targets 0x17d4, is taken when v0(=ret(valusema)) <= 0 (signed), and falls through when v0(=ret(valusema)) > 0 (signed).
  The `beq` branch at 0x17e4 targets 0x14d4 and is always taken.
  The `beq` branch at 0x17f0 targets 0x1874, is taken when a1(=([a3+12]:2 + [a3+16]:2)) == 0, and falls through when a1(=([a3+12]:2 + [a3+16]:2)) != 0.
  The `beq` branch at 0x1810 targets 0x162c and is always taken.
  The `beq` branch at 0x181c targets 0x187c, is taken when a3(=([a3+14]:2 + [a3+18]:2)) == 0, and falls through when a3(=([a3+14]:2 + [a3+18]:2)) != 0.
  The `bgtz` branch at 0x183c targets 0x167c, is taken when a1(?) > 0 (signed), and falls through when a1(?) <= 0 (signed).
  The `beq` branch at 0x1844 targets 0x16b8 and is always taken.
  The `beq` branch at 0x184c targets 0x1620 and is always taken.
  The `beq` branch at 0x1854 targets 0x166c and is always taken.
  The `beq` branch at 0x1864 targets 0x17d8 and is always taken.
  The `beq` branch at 0x186c targets 0x1580 and is always taken.
  The `beq` branch at 0x1874 targets 0x180c and is always taken.
  The `beq` branch at 0x187c targets 0x183c and is always taken.
  The return at 0x14e8 has v0 = one of 0x0, 0x4, ret(crmAddZ), ret(crmAllocZbuffer).

- `crmRecomputeSZ` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x1884 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x1884-0x1f94 (1808 bytes).
  It occupies 1808 bytes.
  The `lw` at 0x1884 loads 4 bytes from a2 (arg2 at entry) +0x14.
  2 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0xc, including `lw` at 0x1888, `lw` at 0x1b5c.
  The `lw` at 0x188c loads 4 bytes from a2 (arg2 at entry) +0x10.
  2 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x8, including `lw` at 0x1890, `lw` at 0x1b60.
  2 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0xe, including `lh` at 0x1894, `lh` at 0x1b58.
  The `lh` at 0x18a0 loads 2 bytes from a1 (arg1 at entry) +0x12.
  The `lh` at 0x18a8 loads 2 bytes from a1 (arg1 at entry) +0x10.
  2 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0xc, including `lh` at 0x18ac, `lh` at 0x1b54.
  5 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x20, including `lw` at 0x19e0, `lw` at 0x1be0, `lw` at 0x1cf4.
  The `lbu` at 0x19e4 loads 1 byte from [a1+32] +0x19.
  12 such `sh` accesses store 2 bytes to ?, including `sh` at 0x1a00, `sh` at 0x1a10, `sh` at 0x1a28.
  The `lbu` at 0x1a9c loads 1 byte from [a1+32] +0x18.
  11 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x1b18, `lhu` at 0x1b24, `lhu` at 0x1bbc.
  The `lw` at 0x1b3c loads 4 bytes from a0 (arg0 at entry) +0x7c.
  The `lw` at 0x1b40 loads 4 bytes from [a0+124] +0x30.
  The `lw` at 0x1b44 loads 4 bytes from [[a0+124]+48] +0x4.
  3 such `lw` accesses load 4 bytes from [a1+32] +0x1c, including `lw` at 0x1be4, `lw` at 0x1cf8, `lw` at 0x1dc0.
  3 such `lw` accesses load 4 bytes from [[a1+32]+28] +0x4, including `lw` at 0x1bf0, `lw` at 0x1d00, `lw` at 0x1dc8.
  The `jal` at 0x1b94 calls crmSubtractZ with a0=a1 at entry (arg1), a1=sp-112, a2=?, a3=?.
  The `jal` at 0x1bec calls psema with a0=[[[a1+32]+28]+4], a1=0x11a, a2=?, a3=?.
  The `jal` at 0x1ce4 calls crmAddZ with a0=a1 at entry (arg1), a1=sp-112, a2=?, a3=?.
  The `jal` at 0x1cfc calls vsema with a0=[[[a1+32]+28]+4], a1=?, a2=?, a3=?.
  The `jal` at 0x1d50 calls crmSubtractZ with a0=a1 at entry (arg1), a1=sp-112, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x1dc4 calls vsema with a0=[[[a1+32]+28]+4], a1=?, a2=?, a3=?.
  The `bltz` branch at 0x18bc targets 0x19a0, is taken when t9(=[a1+12]:2) < 0 (signed), and falls through when t9(=[a1+12]:2) >= 0 (signed).
  The `bltz` branch at 0x18d0 targets 0x1c30, is taken when a6(=[a1+14]:2) < 0 (signed), and falls through when a6(=[a1+14]:2) >= 0 (signed).
  The `bltz` branch at 0x18d8 targets 0x1c1c, is taken when a5(=[a2+8]) < 0 (signed), and falls through when a5(=[a2+8]) >= 0 (signed).
  The `bltz` branch at 0x18e4 targets 0x1c24, is taken when v0(=[a2+12]) < 0 (signed), and falls through when v0(=[a2+12]) >= 0 (signed).
  The `bne` branch at 0x1904 targets 0x19e0, is taken when s2(?) != t8(?), and falls through when s2(?) == t8(?).
  The `bne` branch at 0x1938 targets 0x19e0, is taken when at(?) != v0(?), and falls through when at(?) == v0(?).
  The `bne` branch at 0x195c targets 0x19e0, is taken when a4(?) != a5(?), and falls through when a4(?) == a5(?).
  The `bne` branch at 0x1990 targets 0x19e0, is taken when a5(?) != t9(?), and falls through when a5(?) == t9(?).
  The `beq` branch at 0x1998 targets 0x1c00 and is always taken.
  The `bltz` branch at 0x19a8 targets 0x1e04, is taken when a6(=[a1+14]:2) < 0 (signed), and falls through when a6(=[a1+14]:2) >= 0 (signed).
  The `bltz` branch at 0x19b0 targets 0x1dd4, is taken when a5(=[a2+8]) < 0 (signed), and falls through when a5(=[a2+8]) >= 0 (signed).
  The `bltz` branch at 0x19b8 targets 0x1de0, is taken when v0(=[a2+12]) < 0 (signed), and falls through when v0(=[a2+12]) >= 0 (signed).
  The `beq` branch at 0x19d8 targets 0x1eb8, is taken when t8(?) == s2(=0x0), and falls through when t8(?) != s2(=0x0).
  The `bltz` branch at 0x19ec targets 0x1a2c, is taken when a6(=[[a1+32]+25]:1-1) < 0 (signed), and falls through when a6(=[[a1+32]+25]:1-1) >= 0 (signed).
  The `bne` branch at 0x1a04 targets 0x1a2c, is taken when a6(=[[a1+32]+25]:1-1) < v0(?) (signed), and falls through when a6(=[[a1+32]+25]:1-1) >= v0(?) (signed).
  The `bne` branch at 0x1a14 targets 0x1a2c, is taken when a6(=[[a1+32]+25]:1-1) < v0(?) (signed), and falls through when a6(=[[a1+32]+25]:1-1) >= v0(?) (signed).
  The `beq` branch at 0x1a24 targets 0x19f8, is taken when a6(=[[a1+32]+25]:1-1) >= v0(?) (signed), and falls through when a6(=[[a1+32]+25]:1-1) < v0(?) (signed).
  The `blez` branch at 0x1a2c targets 0x1af8, is taken when t2(=[a2+16]) <= 0 (signed), and falls through when t2(=[a2+16]) > 0 (signed).
  The `blez` branch at 0x1a34 targets 0x1af8, is taken when t3(=[a2+20]) <= 0 (signed), and falls through when t3(=[a2+20]) > 0 (signed).
  The `beq` branch at 0x1a3c targets 0x1d48, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x1a6c targets 0x1af4, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bltz` branch at 0x1a90 targets 0x1af4, is taken when v1(?) < 0 (signed), and falls through when v1(?) >= 0 (signed).
  The `beq` branch at 0x1acc targets 0x1af4, is taken when v0(?) >= a6(?) (signed), and falls through when v0(?) < a6(?) (signed).
  The `beq` branch at 0x1adc targets 0x1af4, is taken when v0(?) >= a6(?) (signed), and falls through when v0(?) < a6(?) (signed).
  The `bne` branch at 0x1aec targets 0x1ac0, is taken when v0(?) < a6(?) (signed), and falls through when v0(?) >= a6(?) (signed).
  The `bne` branch at 0x1af8 targets 0x1b3c, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `bne` branch at 0x1b34 targets 0x1b10, is taken when a6(?) < s0(=[[a1+32]+25]:1) (signed), and falls through when a6(?) >= s0(=[[a1+32]+25]:1) (signed).
  The `beq` branch at 0x1b4c targets 0x1d50, is taken when (at(=[[[a0+124]+48]+4]) & 0x2) == 0, and falls through when (at(=[[[a0+124]+48]+4]) & 0x2) != 0.
  The `bne` branch at 0x1b6c targets 0x1b90, is taken when v1(=[a1+12]:2) != a0(=[a2+8]), and falls through when v1(=[a1+12]:2) == a0(=[a2+8]).
  The `beq` branch at 0x1b78 targets 0x1b88, is taken when v0(?) == a2(=0x200), and falls through when v0(?) != a2(=0x200).
  The `bne` branch at 0x1b80 targets 0x1b94, is taken when v0(?) != a3(=-0x200), and falls through when v0(?) == a3(=-0x200).
  The `beq` branch at 0x1b88 targets 0x1ba0 and is always taken.
  The `beq` branch at 0x1ba0 targets 0x1be0, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x1bd8 targets 0x1bb4, is taken when a6(?) < s0(=[[a1+32]+25]:1) (signed), and falls through when a6(?) >= s0(=[[a1+32]+25]:1) (signed).
  The `beq` branch at 0x1bf4 targets 0x1ce4, is taken when v0(=ret(psema)) == 0, and falls through when v0(=ret(psema)) != 0.
  The `bgez` branch at 0x1c1c targets 0x18ec, is taken when v0(=[a2+12]) >= 0 (signed), and falls through when v0(=[a2+12]) < 0 (signed).
  The `beq` branch at 0x1c28 targets 0x18f4 and is always taken.
  The `bltz` branch at 0x1c30 targets 0x1dec, is taken when a5(=[a2+8]) < 0 (signed), and falls through when a5(=[a2+8]) >= 0 (signed).
  The `bltz` branch at 0x1c3c targets 0x1df8, is taken when v0(=[a2+12]) < 0 (signed), and falls through when v0(=[a2+12]) >= 0 (signed).
  The `bne` branch at 0x1c5c targets 0x19e0, is taken when s2(?) != t8(?), and falls through when s2(?) == t8(?).
  The `bne` branch at 0x1c9c targets 0x19e0, is taken when v1(?) != a3(?), and falls through when v1(?) == a3(?).
  The `bne` branch at 0x1ca4 targets 0x19e0, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x1cd4 targets 0x19e0, is taken when a6(?) != t9(?), and falls through when a6(?) == t9(?).
  The `beq` branch at 0x1cdc targets 0x1998 and is always taken.
  The `beq` branch at 0x1cec targets 0x1d60, is taken when v0(=ret(crmAddZ)) == 0, and falls through when v0(=ret(crmAddZ)) != 0.
  The `beq` branch at 0x1d04 targets 0x1d40, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x1d38 targets 0x1d14, is taken when a1(?) < s0(=[[a1+32]+25]:1) (signed), and falls through when a1(?) >= s0(=[[a1+32]+25]:1) (signed).
  The `beq` branch at 0x1d40 targets 0x1c00 and is always taken.
  The `beq` branch at 0x1d48 targets 0x1a60 and is always taken.
  The `beq` branch at 0x1d58 targets 0x1ba0 and is always taken.
  The `beq` branch at 0x1d60 targets 0x1f48, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1d68 targets 0x1dbc, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x1d90 targets 0x1dbc, is taken when v0(?) >= s0(=[[a1+32]+25]:1) (signed), and falls through when v0(?) < s0(=[[a1+32]+25]:1) (signed).
  The `bne` branch at 0x1db4 targets 0x1d78, is taken when v0(?) < s0(=[[a1+32]+25]:1) (signed), and falls through when v0(?) >= s0(=[[a1+32]+25]:1) (signed).
  The `beq` branch at 0x1dcc targets 0x1c00 and is always taken.
  The `bgez` branch at 0x1dd8 targets 0x19c0, is taken when v0(=[a2+12]) >= 0 (signed), and falls through when v0(=[a2+12]) < 0 (signed).
  The `beq` branch at 0x1de4 targets 0x19c8 and is always taken.
  The `bgez` branch at 0x1df0 targets 0x1c44, is taken when v0(=[a2+12]) >= 0 (signed), and falls through when v0(=[a2+12]) < 0 (signed).
  The `beq` branch at 0x1dfc targets 0x1c4c and is always taken.
  The `bltz` branch at 0x1e08 targets 0x1f7c, is taken when a5(=[a2+8]) < 0 (signed), and falls through when a5(=[a2+8]) >= 0 (signed).
  The `bltz` branch at 0x1e10 targets 0x1f88, is taken when v0(=[a2+12]) < 0 (signed), and falls through when v0(=[a2+12]) >= 0 (signed).
  The `bne` branch at 0x1e30 targets 0x19e0, is taken when t8(?) != s2(=0x0), and falls through when t8(?) == s2(=0x0).
  The `bne` branch at 0x1e64 targets 0x19e0, is taken when t9(?) != ra(?), and falls through when t9(?) == ra(?).
  The `bne` branch at 0x1e78 targets 0x19e0, is taken when s2(=0x0) != v1(?), and falls through when s2(=0x0) == v1(?).
  The `bne` branch at 0x1ea8 targets 0x19e0, is taken when a3(?) != a4(?), and falls through when a3(?) == a4(?).
  The `beq` branch at 0x1eb0 targets 0x1998 and is always taken.
  The `bne` branch at 0x1ee0 targets 0x19e0, is taken when a4(?) != a5(?), and falls through when a4(?) == a5(?).
  The `bne` branch at 0x1f04 targets 0x19e0, is taken when a5(?) != t9(?), and falls through when a5(?) == t9(?).
  The `bne` branch at 0x1f38 targets 0x19e0, is taken when t9(?) != at(?), and falls through when t9(?) == at(?).
  The `beq` branch at 0x1f40 targets 0x1998 and is always taken.
  The `beq` branch at 0x1f48 targets 0x1dbc, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x1f6c targets 0x1f58, is taken when a1(?) < s0(=[[a1+32]+25]:1) (signed), and falls through when a1(?) >= s0(=[[a1+32]+25]:1) (signed).
  The `beq` branch at 0x1f74 targets 0x1dc0 and is always taken.
  The `bgez` branch at 0x1f80 targets 0x1e18, is taken when v0(=[a2+12]) >= 0 (signed), and falls through when v0(=[a2+12]) < 0 (signed).
  The `beq` branch at 0x1f8c targets 0x1e20 and is always taken.
  The return at 0x1c14 has v0 = one of 0x0, 0x4, 0xc.

- `crm_changedrawables` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x1f94 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x1f94-0x21b0 (540 bytes).
  It occupies 540 bytes.
  The `lw` at 0x1fa4 loads 4 bytes from a0 (arg0 at entry) +0x4c.
  5 such `lw` accesses load 4 bytes from [a0+76] +0xc, including `lw` at 0x1fac, `lw` at 0x203c, `lw` at 0x205c.
  5 such `lw` accesses load 4 bytes from [a0+76] +0x10, including `lw` at 0x1fc8, `lw` at 0x2030, `lw` at 0x20b0.
  The `lw` at 0x1fcc loads 4 bytes from [[a0+76]+12] +0x8.
  3 such `lw` accesses load 4 bytes from [[a0+76]+16] +0x8, including `lw` at 0x1fe0, `lw` at 0x2130, `lw` at 0x215c.
  2 such `sw` accesses store 4 bytes to [a0+76] +0xc, including `sw` at 0x2010, `sw` at 0x2180.
  3 such `sw` accesses store 4 bytes to [a0+76] +0x10, including `sw` at 0x2020, `sw` at 0x2040, `sw` at 0x219c.
  The `lw` at 0x2044 loads 4 bytes from [[a0+76]+12] +0x28.
  The `sw` at 0x2050 stores 4 bytes to [[a0+76]+12] +0x28.
  2 such `lw` accesses load 4 bytes from [[a0+76]+12] +0x24, including `lw` at 0x2060, `lw` at 0x207c.
  The `sw` at 0x2074 stores 4 bytes to [[a0+76]+12] +0x24.
  The `sw` at 0x20ac stores 4 bytes to [[a0+76]+12] +0x18.
  2 such `lw` accesses load 4 bytes from [[a0+76]+16] +0x24, including `lw` at 0x20b4, `lw` at 0x20d8.
  The `sw` at 0x20d0 stores 4 bytes to [[a0+76]+16] +0x24.
  The `sw` at 0x2100 stores 4 bytes to [[a0+76]+16] +0x18.
  2 such `lw` accesses load 4 bytes from ret(crm_finddrawable) +0x28, including `lw` at 0x2184, `lw` at 0x21a0.
  2 such `sw` accesses store 4 bytes to ret(crm_finddrawable) +0x28, including `sw` at 0x2190, `sw` at 0x21ac.
  The `jal` at 0x1ffc calls crm_unbinddrawable with a0=[a0+76], a1=one of 0x1, 0x2, 0x3, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[[a0+76]+12].
  The `jal` at 0x2094 calls crm_makecurrentpbuf with a0=a0 at entry (arg0), a1=[[a0+76]+12], a2=?, a3=?, a5=[[a0+76]+12].
  The `jal` at 0x20e8 calls crm_makecurrentpbuf with a0=a0 at entry (arg0), a1=[[a0+76]+16], a2=?, a3=?.
  The `jal` at 0x2178 calls crm_finddrawable with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x2194 calls crm_finddrawable with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1fc4 targets 0x2154, is taken when a5(=[[a0+76]+12]) == 0, and falls through when a5(=[[a0+76]+12]) != 0.
  The `beq` branch at 0x1fd0 targets 0x2128, is taken when at(=[[[a0+76]+12]+8]) == a1, and falls through when at(=[[[a0+76]+12]+8]) != a1.
  The `beq` branch at 0x1fd8 targets 0x2144, is taken when v0(=[[a0+76]+16]) == 0, and falls through when v0(=[[a0+76]+16]) != 0.
  The `beq` branch at 0x1fe4 targets 0x2144, is taken when v1(=[[[a0+76]+16]+8]) == a2, and falls through when v1(=[[[a0+76]+16]+8]) != a2.
  The `beq` branch at 0x1ff4 targets 0x2024, is taken when s1(=one of 0x2, 0x3) == 0, and falls through when s1(=one of 0x2, 0x3) != 0.
  The `beq` branch at 0x2008 targets 0x2170, is taken when (s1(=one of 0x1, 0x2, 0x3) & 0x1) == 0, and falls through when (s1(=one of 0x1, 0x2, 0x3) & 0x1) != 0.
  The `beq` branch at 0x2018 targets 0x2024, is taken when (s1(=one of 0x1, 0x2, 0x3) & 0x2) == 0, and falls through when (s1(=one of 0x1, 0x2, 0x3) & 0x2) != 0.
  The `beq` branch at 0x2024 targets 0x2178, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x202c targets 0x2054, is taken when s3(=a1) != s2(=a2), and falls through when s3(=a1) == s2(=a2).
  The `bne` branch at 0x2034 targets 0x205c, is taken when v0(=[[a0+76]+16]) != 0, and falls through when v0(=[[a0+76]+16]) == 0.
  The `beq` branch at 0x204c targets 0x205c and is always taken.
  The `beq` branch at 0x2054 targets 0x2194, is taken when v0(=[[a0+76]+16]) == 0, and falls through when v0(=[[a0+76]+16]) != 0.
  The `beq` branch at 0x2068 targets 0x20b0, is taken when (v0(=[[[a0+76]+12]+36]) & 0x10) == 0, and falls through when (v0(=[[[a0+76]+12]+36]) & 0x10) != 0.
  The `beq` branch at 0x2088 targets 0x20ac, is taken when (a1(=[[[a0+76]+12]+36]) & 0x2) == 0, and falls through when (a1(=[[[a0+76]+12]+36]) & 0x2) != 0.
  The `beq` branch at 0x209c targets 0x214c, is taken when v0(=ret(crm_makecurrentpbuf)) == 0, and falls through when v0(=ret(crm_makecurrentpbuf)) != 0.
  The `beq` branch at 0x20a4 targets 0x210c and is always taken.
  The `beq` branch at 0x20c0 targets 0x2104, is taken when (a0(=[[[a0+76]+16]+36]) & 0x10) == 0, and falls through when (a0(=[[[a0+76]+16]+36]) & 0x10) != 0.
  The `beq` branch at 0x20e0 targets 0x2100, is taken when (a3(=[[[a0+76]+16]+36]) & 0x2) == 0, and falls through when (a3(=[[[a0+76]+16]+36]) & 0x2) != 0.
  The `beq` branch at 0x20f0 targets 0x2104, is taken when v0(=ret(crm_makecurrentpbuf)) == 0, and falls through when v0(=ret(crm_makecurrentpbuf)) != 0.
  The `beq` branch at 0x20f8 targets 0x210c and is always taken.
  The `beq` branch at 0x2128 targets 0x2024, is taken when v0(=[[a0+76]+16]) == 0, and falls through when v0(=[[a0+76]+16]) != 0.
  The `beq` branch at 0x2134 targets 0x2024, is taken when a6(=[[[a0+76]+16]+8]) == a2, and falls through when a6(=[[[a0+76]+16]+8]) != a2.
  The `beq` branch at 0x213c targets 0x1ff4 and is always taken.
  The `beq` branch at 0x2144 targets 0x1ffc and is always taken.
  The `beq` branch at 0x214c targets 0x20b4 and is always taken.
  The `beq` branch at 0x2154 targets 0x2024, is taken when v0(=[[a0+76]+16]) == 0, and falls through when v0(=[[a0+76]+16]) != 0.
  The `beq` branch at 0x2160 targets 0x2024, is taken when a7(=[[[a0+76]+16]+8]) == a2, and falls through when a7(=[[[a0+76]+16]+8]) != a2.
  The `beq` branch at 0x2168 targets 0x1ff4 and is always taken.
  The `beq` branch at 0x2170 targets 0x2014 and is always taken.
  The `beq` branch at 0x218c targets 0x202c and is always taken.
  The `beq` branch at 0x21a8 targets 0x205c and is always taken.
  The return at 0x2120 has v0 = one of ret(crm_makecurrentpbuf), 0x0.

- `crimeValidateClip` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x21b0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x21b0-0x2574 (964 bytes).
  It occupies 964 bytes.
  The `lw` at 0x21bc loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lw` at 0x21c4 loads 4 bytes from a1 (arg1 at entry) +0x4c.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x54, including `lw` at 0x21f8, `lw` at 0x2454.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x50, including `lw` at 0x21fc, `lw` at 0x2450.
  The `lw` at 0x2200 loads 4 bytes from [a1+84] +0x4.
  The `lw` at 0x2208 loads 4 bytes from [a1+80] +0x4.
  The `lw` at 0x220c loads 4 bytes from a1 (arg1 at entry) +0x14.
  The `lw` at 0x2210 loads 4 bytes from a1 (arg1 at entry) +0x10.
  2 such `lw` accesses load 4 bytes from [a1+76] +0xc, including `lw` at 0x2214, `lw` at 0x233c.
  The `lw` at 0x2220 loads 4 bytes from [[a1+76]+12] +0x8.
  The `lw` at 0x222c loads 4 bytes from [a1+76] +0x10.
  The `lw` at 0x2238 loads 4 bytes from [[a1+76]+16] +0x8.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x8, including `lw` at 0x2244, `lw` at 0x2430.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0xc, including `lw` at 0x2248, `lw` at 0x2438.
  3 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x18, including `lw` at 0x2250, `lw` at 0x22dc, `lw` at 0x2548.
  The `lw` at 0x2264 loads 4 bytes from a3 (arg3 at entry) +0x1c.
  The `sd` at 0x22d8 stores 8 bytes to ?.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x22f4, `lw` at 0x22f8, `lw` at 0x22fc.
  The `sw` at 0x2334 stores 4 bytes to [a1+8] +0x58.
  The `sw` at 0x2338 stores 4 bytes to [a1+8] +0x10.
  The `lw` at 0x2340 loads 4 bytes from [[a1+76]+12] +0x24.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0x2350, `lw` at 0x24a0.
  The `lw` at 0x23a0 loads 4 bytes from [a1+8] +0x10.
  The `sw` at 0x23a4 stores 4 bytes to [[a0+24]+120] +0x2010.
  The `ld` at 0x23a8 loads 8 bytes from [a1+8] +0x20.
  The `sd` at 0x23ac stores 8 bytes to [[a0+24]+120] +0x2020.
  The `ld` at 0x23b0 loads 8 bytes from [a1+8] +0x28.
  The `sd` at 0x23b4 stores 8 bytes to [[a0+24]+120] +0x2028.
  The `ld` at 0x23b8 loads 8 bytes from [a1+8] +0x30.
  The `sd` at 0x23bc stores 8 bytes to [[a0+24]+120] +0x2030.
  The `ld` at 0x23c0 loads 8 bytes from [a1+8] +0x38.
  The `sd` at 0x23c4 stores 8 bytes to [[a0+24]+120] +0x2038.
  The `ld` at 0x23c8 loads 8 bytes from [a1+8] +0x40.
  The `sd` at 0x23cc stores 8 bytes to [[a0+24]+120] +0x2040.
  The `lw` at 0x23d0 loads 4 bytes from [a1+8] +0x50.
  The `sw` at 0x23d4 stores 4 bytes to [[a0+24]+120] +0x2050.
  The `lw` at 0x23d8 loads 4 bytes from [a1+8] +0x58.
  The `sw` at 0x23dc stores 4 bytes to [[a0+24]+120] +0x2058.
  The `sw` at 0x23e4 stores 4 bytes to [[a0+24]+120] +0x4008.
  The `sh` at 0x2434 stores 2 bytes to [[a1+76]+12] +0xc.
  The `sh` at 0x243c stores 2 bytes to [[a1+76]+12] +0xe.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x10, including `lw` at 0x2440, `lw` at 0x2508.
  The `sh` at 0x2444 stores 2 bytes to [[a1+76]+12] +0x10.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x14, including `lw` at 0x2448, `lw` at 0x2518.
  The `sh` at 0x244c stores 2 bytes to [[a1+76]+12] +0x12.
  The `lw` at 0x2458 loads 4 bytes from [a1+80] +0x8.
  The `sw` at 0x245c stores 4 bytes to a1 (arg1 at entry) +0x58.
  The `lw` at 0x2460 loads 4 bytes from [a1+84] +0x8.
  The `sw` at 0x2468 stores 4 bytes to a1 (arg1 at entry) +0x5c.
  2 such `sw` accesses store 4 bytes to [a1+8] +0x50, including `sw` at 0x2470, `sw` at 0x2490.
  The `lw` at 0x2474 loads 4 bytes from [a1+84] +0x48.
  The `lw` at 0x2478 loads 4 bytes from [a1+84] +0x4c.
  The `lw` at 0x24a8 loads 4 bytes from [a0+24] +0x78.
  The `lw` at 0x24e0 loads 4 bytes from a3 (arg3 at entry) +0x24.
  The `lw` at 0x24f0 loads 4 bytes from a3 (arg3 at entry) +0x20.
  The `sd` at 0x2540 stores 8 bytes to [a1+8] +0x20.
  The `lw` at 0x2570 loads 4 bytes from [a3+28] +0x0.
  The `jal` at 0x2290 calls crm_changedrawables with a0=a1 at entry (arg1), a1=?, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x2354 calls crmRecomputeSZ with a0=[a0+24], a1=[[a1+76]+12], a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x236c calls crmLoadTlbABC with a0=[a0+24], a1=?, a2=?, a3=?.
  The `jal` at 0x23f4 calls crmRestorePP with a0=[[a0+24]+120], a1=[a1+76]+848, a2=[a1+76]+336, a3=ret(crmSavePP), a4=[[a1+8]+88], a5=[[a1+8]+80], a6=[[a1+8]+64]:8, a7=[[a1+8]+56]:8.
  The `jal` at 0x24b8 calls crmSavePP with a0=[[a0+24]+120], a1=[a1+76]+848, a2=[a1+76]+336, a3=?.
  The `beq` branch at 0x21f0 targets 0x220c, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x2204 targets 0x2214 and is always taken.
  The `beq` branch at 0x2218 targets 0x228c, is taken when v0(=[[a1+76]+12]) == 0, and falls through when v0(=[[a1+76]+12]) != 0.
  The `bne` branch at 0x2224 targets 0x228c, is taken when t8(=[[[a1+76]+12]+8]) != s4(?), and falls through when t8(=[[[a1+76]+12]+8]) == s4(?).
  The `beq` branch at 0x2230 targets 0x228c, is taken when v0(=[[a1+76]+16]) == 0, and falls through when v0(=[[a1+76]+16]) != 0.
  The `bne` branch at 0x223c targets 0x228c, is taken when t9(=[[[a1+76]+16]+8]) != s5(?), and falls through when t9(=[[[a1+76]+16]+8]) == s5(?).
  The `blez` branch at 0x2268 targets 0x24d0, is taken when a3(=[a3+24]) <= 0 (signed), and falls through when a3(=[a3+24]) > 0 (signed).
  The `beq` branch at 0x2274 targets 0x24d8, is taken when a3(=[a3+24]) >= 0x6 (signed), and falls through when a3(=[a3+24]) < 0x6 (signed).
  The `beq` branch at 0x2280 targets 0x2564 and is always taken.
  The `beq` branch at 0x2298 targets 0x2244, is taken when v0(=ret(crm_changedrawables)) == 0, and falls through when v0(=ret(crm_changedrawables)) != 0.
  The `beq` branch at 0x22a0 targets 0x2400 and is always taken.
  The `bltz` branch at 0x22b8 targets 0x2320, is taken when a3(?) < 0 (signed), and falls through when a3(?) >= 0 (signed).
  The `beq` branch at 0x22ec targets 0x232c, is taken when a7(?) >= a3(=[a3+24]) (signed), and falls through when a7(?) < a3(=[a3+24]) (signed).
  The `bgez` branch at 0x230c targets 0x22a8, is taken when a1(?) >= 0 (signed), and falls through when a1(?) < 0 (signed).
  The `beq` branch at 0x2318 targets 0x22ac and is always taken.
  The `beq` branch at 0x2324 targets 0x22c4 and is always taken.
  The `beq` branch at 0x232c targets 0x24e0, is taken when a3(=[a3+24]) == 0, and falls through when a3(=[a3+24]) != 0.
  The `beq` branch at 0x2348 targets 0x2430, is taken when (a1(=[[[a1+76]+12]+36]) & 0x1) == 0, and falls through when (a1(=[[[a1+76]+12]+36]) & 0x1) != 0.
  The `beq` branch at 0x235c targets 0x2430, is taken when v0(=ret(crmRecomputeSZ)) == 0, and falls through when v0(=ret(crmRecomputeSZ)) != 0.
  The `beq` branch at 0x2364 targets 0x2400 and is always taken.
  The `beq` branch at 0x237c targets 0x23a0, is taken when s1(?) >= 0x3 (signed), and falls through when s1(?) < 0x3 (signed).
  The `bne` branch at 0x2388 targets 0x236c, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x2398 targets 0x2384, is taken when s1(?) < 0x3 (signed), and falls through when s1(?) >= 0x3 (signed).
  The `blez` branch at 0x23e0 targets 0x23fc, is taken when s5(=ret(crmSavePP)) <= 0 (signed), and falls through when s5(=ret(crmSavePP)) > 0 (signed).
  The `bne` branch at 0x2464 targets 0x2474, is taken when s4(?) != s5(?), and falls through when s4(?) == s5(?).
  The `beq` branch at 0x246c targets 0x2494 and is always taken.
  The `beq` branch at 0x2498 targets 0x2400, is taken when a1(=a2) == 0, and falls through when a1(=a2) != 0.
  The `beq` branch at 0x24c8 targets 0x2384 and is always taken.
  The `beq` branch at 0x24d0 targets 0x2504, is taken when a3(=[a3+24]) == 0, and falls through when a3(=[a3+24]) != 0.
  The `bne` branch at 0x24d8 targets 0x2330, is taken when a3(=[a3+24]) != 0, and falls through when a3(=[a3+24]) == 0.
  The `beq` branch at 0x24e8 targets 0x2330, is taken when a2(=[a3+36]) == 0, and falls through when a2(=[a3+36]) != 0.
  The `bne` branch at 0x24f4 targets 0x2334, is taken when a3(=[a3+32]) != a4(=0x1), and falls through when a3(=[a3+32]) == a4(=0x1).
  The `beq` branch at 0x24fc targets 0x2334 and is always taken.
  The `bltz` branch at 0x2504 targets 0x254c, is taken when a0(=[a3+8]) < 0 (signed), and falls through when a0(=[a3+8]) >= 0 (signed).
  The `bltz` branch at 0x2514 targets 0x2558, is taken when v0(=[a3+12]) < 0 (signed), and falls through when v0(=[a3+12]) >= 0 (signed).
  The `beq` branch at 0x2544 targets 0x24d8 and is always taken.
  The `beq` branch at 0x2550 targets 0x2510 and is always taken.
  The `beq` branch at 0x255c targets 0x2520 and is always taken.
  The `beq` branch at 0x256c targets 0x22f8 and is always taken.
  The return at 0x2428 has v0 = one of -0x1, 0x0.
  The instructions from 0x2288 to 0x2288 are not reached by any path from the entry, and their branches are not listed.

- `crimeValidateDDClip` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x2574 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x2574-0x2814 (672 bytes).
  It occupies 672 bytes.
  The `lw` at 0x2578 loads 4 bytes from a1 (arg1 at entry) +0x4.
  The `lw` at 0x25a8 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x25b4 loads 4 bytes from ([a0+24] + ([a1+4] << 0x2)) +0xb8.
  2 such `sw` accesses store 4 bytes to ([a0+24] + ([a1+4] << 0x2)) +0xb8, including `sw` at 0x25c0, `sw` at 0x2690.
  4 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x8, including `lbu` at 0x25c4, `lbu` at 0x25d4, `lbu` at 0x270c.
  The `sb` at 0x25cc stores 1 byte to ?.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x25e0, `lw` at 0x25f4, `lw` at 0x2638.
  14 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0xc, including `lw` at 0x25e4, `lw` at 0x2608, `lw` at 0x2618.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2614, `sw` at 0x261c, `sw` at 0x2624.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x114, including `lw` at 0x2640, `lw` at 0x2798.
  The `sw` at 0x26c4 stores 4 bytes to ret(kern_malloc) +0x10.
  The `sw` at 0x26d8 stores 4 bytes to ret(kern_malloc) +0x114.
  The `lw` at 0x26e0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x26e4 loads 4 bytes from ret(crm_finddrawable) +0x24.
  11 such `lw` accesses load 4 bytes from ret(crm_finddrawable) +0x14, including `lw` at 0x2700, `lw` at 0x2718, `lw` at 0x272c.
  The `sb` at 0x2714 stores 1 byte to [ret(crm_finddrawable)+20] +0x8.
  The `lw` at 0x2730 loads 4 bytes from [ret(crm_finddrawable)+20] +0x10.
  2 such `lw` accesses load 4 bytes from [ret(crm_finddrawable)+20] +0x114, including `lw` at 0x2744, `lw` at 0x27a0.
  2 such `sw` accesses store 4 bytes to [ret(crm_finddrawable)+20] +0x114, including `sw` at 0x2768, `sw` at 0x2808.
  2 such `sw` accesses store 4 bytes to [ret(crm_finddrawable)+20] +0x10, including `sw` at 0x2774, `sw` at 0x27f4.
  2 such `sw` accesses store 4 bytes to [ret(crm_finddrawable)+20] +0xc, including `sw` at 0x2780, `sw` at 0x27b8.
  The `sw` at 0x27cc stores 4 bytes to ret(crm_finddrawable) +0x1c.
  The `sw` at 0x27e4 stores 4 bytes to ret(crm_finddrawable) +0x14.
  The `jal` at 0x25d8 calls bcopy with a0=a1+20, a1=?, a2=[a1+8]:1, a3=?.
  The `jal` at 0x2600 calls kern_free with a0=?, a1=[a1+12], a2=?, a3=?.
  The `jal` at 0x260c calls kern_malloc with a0=([a1+12] << 0x3), a1=[a1+12], a2=?, a3=?.
  The `jal` at 0x263c calls copyin with a0=[a1+276], a1=?, a2=([a1+12] << 0x3), a3=?, a4=([a0+24] + ([a1+4] << 0x2)).
  The `jal` at 0x264c calls kern_free with a0=?, a1=?, a2=?, a3=?, a4=([a0+24] + ([a1+4] << 0x2)).
  The `jal` at 0x2660 calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2694 calls kern_free with a0=?, a1=?, a2=?, a3=-0x14.
  The `jal` at 0x26a4 calls kern_malloc with a0=0x118, a1=([a1+4] << 0x2), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x26b4 calls bzero with a0=ret(kern_malloc), a1=0x118, a2=?, a3=?.
  The `jal` at 0x26cc calls kern_malloc with a0=([a1+12] << 0x3), a1=?, a2=?, a3=?, a5=[a1+12].
  The `jal` at 0x26dc calls crm_finddrawable with a0=[a1], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2724 calls bcopy with a0=a1+20, a1=[ret(crm_finddrawable)+20]+20, a2=[a1+8]:1, a3=?, a5=[ret(crm_finddrawable)+20].
  The `jal` at 0x2750 calls kern_free with a0=[[ret(crm_finddrawable)+20]+276], a1=[a1+12], a2=?, a3=?, a5=[ret(crm_finddrawable)+20].
  The `jal` at 0x275c calls kern_malloc with a0=([a1+12] << 0x3), a1=[a1+12], a2=?, a3=?.
  The `jal` at 0x279c calls copyin with a0=[a1+276], a1=[[ret(crm_finddrawable)+20]+276], a2=([a1+12] << 0x3), a3=?, a5=[ret(crm_finddrawable)+20].
  The `jal` at 0x27d0 calls kern_malloc with a0=0x118, a1=?, a2=?, a3=?, a5=[ret(crm_finddrawable)+20].
  The `jal` at 0x27e0 calls bzero with a0=ret(kern_malloc), a1=0x118, a2=?, a3=?.
  The `jal` at 0x27fc calls kern_malloc with a0=([a1+12] << 0x3), a1=?, a2=?, a3=?, a4=[a1+12], a5=[ret(crm_finddrawable)+20].
  The `beq` branch at 0x2588 targets 0x26dc, is taken when v0(=[a1+4]) == 0, and falls through when v0(=[a1+4]) != 0.
  The `bltz` branch at 0x2590 targets 0x25a0, is taken when v0(=[a1+4]) < 0 (signed), and falls through when v0(=[a1+4]) >= 0 (signed).
  The `bne` branch at 0x2598 targets 0x25a8, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0x25a0 targets 0x266c and is always taken.
  The `beq` branch at 0x25bc targets 0x26a4, is taken when s1(=[([a0+24] + ([a1+4] << 0x2))+184]) == 0, and falls through when s1(=[([a0+24] + ([a1+4] << 0x2))+184]) != 0.
  The `beq` branch at 0x25c8 targets 0x25e0, is taken when a2(=[a1+8]:1) == 0, and falls through when a2(=[a1+8]:1) != 0.
  The `beq` branch at 0x25ec targets 0x2624, is taken when a3(?) >= a1(=[a1+12]) (unsigned), and falls through when a3(?) < a1(=[a1+12]) (unsigned).
  The `beq` branch at 0x25f8 targets 0x260c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `blez` branch at 0x2630 targets 0x2688, is taken when a2(=([a1+12] << 0x3)) <= 0 (signed), and falls through when a2(=([a1+12] << 0x3)) > 0 (signed).
  The `beq` branch at 0x2644 targets 0x2688, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `bne` branch at 0x2658 targets 0x2694, is taken when s1(?) != a3(=-0x14), and falls through when s1(?) == a3(=-0x14).
  The `beq` branch at 0x268c targets 0x266c and is always taken.
  The `beq` branch at 0x269c targets 0x2660 and is always taken.
  The `beq` branch at 0x26c0 targets 0x25c4, is taken when a5(=[a1+12]) == 0, and falls through when a5(=[a1+12]) != 0.
  The `beq` branch at 0x26d4 targets 0x25c4 and is always taken.
  The `beq` branch at 0x26f0 targets 0x2700, is taken when (a1(=[ret(crm_finddrawable)+36]) & 0x2) == 0, and falls through when (a1(=[ret(crm_finddrawable)+36]) & 0x2) != 0.
  The `beq` branch at 0x26f8 targets 0x2670 and is always taken.
  The `beq` branch at 0x2704 targets 0x27d0, is taken when a5(=[ret(crm_finddrawable)+20]) == 0, and falls through when a5(=[ret(crm_finddrawable)+20]) != 0.
  The `beq` branch at 0x2710 targets 0x272c, is taken when a2(=[a1+8]:1) == 0, and falls through when a2(=[a1+8]:1) != 0.
  The `beq` branch at 0x273c targets 0x2780, is taken when a2(=[[ret(crm_finddrawable)+20]+16]) >= a1(=[a1+12]) (unsigned), and falls through when a2(=[[ret(crm_finddrawable)+20]+16]) < a1(=[a1+12]) (unsigned).
  The `beq` branch at 0x2748 targets 0x275c, is taken when a0(=[[ret(crm_finddrawable)+20]+276]) == 0, and falls through when a0(=[[ret(crm_finddrawable)+20]+276]) != 0.
  The `blez` branch at 0x278c targets 0x27c0, is taken when a2(=([a1+12] << 0x3)) <= 0 (signed), and falls through when a2(=([a1+12] << 0x3)) > 0 (signed).
  The `beq` branch at 0x27a4 targets 0x27c0, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x27b4 targets 0x266c and is always taken.
  The `beq` branch at 0x27c8 targets 0x266c and is always taken.
  The `beq` branch at 0x27f0 targets 0x280c, is taken when a4(=[a1+12]) == 0, and falls through when a4(=[a1+12]) != 0.
  The `beq` branch at 0x280c targets 0x270c and is always taken.
  The return at 0x267c has v0 = one of 0x0, 0xe, 0x16.
  The instructions from 0x2684 to 0x2684 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x27bc to 0x27bc are not reached by any path from the entry, and their branches are not listed.

- `crimeUpdateBackTiles` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x2814 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x2814-0x29a0 (396 bytes).
  It occupies 396 bytes.
  2 such `lbu` accesses load 1 byte from a2 (arg2 at entry) +0x1, including `lbu` at 0x2824, `lbu` at 0x2894.
  2 such `lbu` accesses load 1 byte from a2 (arg2 at entry) +0x0, including `lbu` at 0x2840, `lbu` at 0x28b0.
  The `lw` at 0x284c loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x2864 loads 4 bytes from [a0+24] +0x0.
  3 such `lw` accesses load 4 bytes from [a0+24] +0x28, including `lw` at 0x2880, `lw` at 0x28dc, `lw` at 0x28f8.
  3 such `lw` accesses load 4 bytes from [[a0+24]+40] +0x18, including `lw` at 0x2884, `lw` at 0x28e0, `lw` at 0x28fc.
  3 such `lw` accesses load 4 bytes from [[[a0+24]+40]+24] +0x2c, including `lw` at 0x2888, `lw` at 0x28e4, `lw` at 0x2900.
  3 such `sw` accesses store 4 bytes to [[[a0+24]+40]+24] +0x2c, including `sw` at 0x2890, `sw` at 0x28f4, `sw` at 0x2908.
  The `lw` at 0x2918 loads 4 bytes from a1 (arg1 at entry) +0x4c.
  2 such `lw` accesses load 4 bytes from [a0+24] +0x78, including `lw` at 0x291c, `lw` at 0x2954.
  The `sw` at 0x2940 stores 4 bytes to [a1+76] +0x48.
  2 such `lw` accesses load 4 bytes from sym(crmbackbuffer) +0x4, including `lw` at 0x2950, `lw` at 0x2968.
  2 such `sw` accesses store 4 bytes to [a1+76] +0x4, including `sw` at 0x2974, `sw` at 0x299c.
  The `jal` at 0x2858 calls mrupdatef with a0=[a0+24]+484, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2860 calls RRM_CheckValidFault with a0=[[a0+24]], a1=?, a2=?, a3=?.
  The `jal` at 0x2870 calls mrunlock with a0=[a0+24]+484, a1=?, a2=?, a3=?.
  The `jal` at 0x28a8 calls crmSubtractBackTiles with a0=sym(crmbackbuffer), a1=[a2+1]:1, a2=?, a3=?.
  The `jal` at 0x28c4 calls crmAddBackTiles with a0=sym(crmbackbuffer), a1=[a2]:1, a2=a2+2, a3=?.
  The `jal` at 0x28d4 calls mrunlock with a0=[a0+24]+484, a1=?, a2=?, a3=?.
  The `jal` at 0x290c calls mrunlock with a0=[a0+24]+484, a1=?, a2=?, a3=?.
  The `jal` at 0x292c calls crmSavePP with a0=[[a0+24]+120], a1=[a1+76]+848, a2=[a1+76]+336, a3=?.
  The `jal` at 0x2944 calls crmLoadTlbABC with a0=[a0+24], a1=sym(crmbackbuffer), a2=0x1, a3=?.
  The `jal` at 0x2960 calls crmRestorePP with a0=[[a0+24]+120], a1=[a1+76]+848, a2=[a1+76]+336, a3=ret(crmSavePP).
  The `bne` branch at 0x2838 targets 0x284c, is taken when at(=[a2+1]:1) != 0, and falls through when at(=[a2+1]:1) == 0.
  The `beq` branch at 0x2844 targets 0x2978, is taken when v1(=[a2]:1) == 0, and falls through when v1(=[a2]:1) != 0.
  The `beq` branch at 0x2868 targets 0x2880, is taken when v0(=ret(RRM_CheckValidFault)) == 0, and falls through when v0(=ret(RRM_CheckValidFault)) != 0.
  The `beq` branch at 0x2878 targets 0x297c and is always taken.
  The `beq` branch at 0x2898 targets 0x28b0, is taken when a1(=[a2+1]:1) == 0, and falls through when a1(=[a2+1]:1) != 0.
  The `beq` branch at 0x28b8 targets 0x28f8, is taken when a1(=[a2]:1) == 0, and falls through when a1(=[a2]:1) != 0.
  The `beq` branch at 0x28cc targets 0x28f8, is taken when v0(=ret(crmAddBackTiles)) == 0, and falls through when v0(=ret(crmAddBackTiles)) != 0.
  The `beq` branch at 0x28f0 targets 0x297c and is always taken.
  The `blez` branch at 0x294c targets 0x296c, is taken when s3(=ret(crmSavePP)) <= 0 (signed), and falls through when s3(=ret(crmSavePP)) > 0 (signed).
  The `beq` branch at 0x296c targets 0x2998, is taken when t8(=[sym(crmbackbuffer)+4]) == 0, and falls through when t8(=[sym(crmbackbuffer)+4]) != 0.
  The `beq` branch at 0x2998 targets 0x2978 and is always taken.
  The return at 0x2990 has v0 = one of 0x0, 0x4, 0xc.

- `crimeMapGfx` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x29c8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x29c8-0x2a84 (188 bytes).
  It occupies 188 bytes.
  The `lw` at 0x29dc loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The `lw` at 0x29e4 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x2a08 loads 4 bytes from [a0+24] +0x78.
  The `lw` at 0x2a14 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x2a18 loads 4 bytes from [a0+8] +0x4.
  The `lw` at 0x2a50 loads 4 bytes from [a0+24] +0x80.
  The `lw` at 0x2a5c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `sw` at 0x2a68 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `jal` at 0x29ec calls ddv_getaddr with a0=[a0+28], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2a0c calls v_mapkvsegment with a0=[a0+28], a1=ret(ddv_getaddr), a2=[[a0+24]+120], a3=0x5, a4=0x10, a5=0x0.
  The `jal` at 0x2a54 calls v_mapkvsegment with a0=[a0+28], a1=ret(ddv_getaddr)+20480, a2=[[a0+24]+128], a3=0x81, a4=0x10, a5=0x0.
  The `beq` branch at 0x2a28 targets 0x2a44, is taken when a2(=[[a0+8]+4]) == s0(=a0), and falls through when a2(=[[a0+8]+4]) != s0(=a0).
  The `bne` branch at 0x2a34 targets 0x2a5c, is taken when a3(=a1) < a1(=ret(ddv_getaddr)+20480) (unsigned), and falls through when a3(=a1) >= a1(=ret(ddv_getaddr)+20480) (unsigned).
  The `beq` branch at 0x2a3c targets 0x2a70 and is always taken.
  The return at 0x2a7c has v0 = one of -0x1, 0x0.

- `crimeUnMapGfx` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x2a84 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x2a84-0x2b34 (176 bytes).
  It occupies 176 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1c, including `lw` at 0x2a8c, `lw` at 0x2b04.
  The `lw` at 0x2a90 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `sw` at 0x2aa8 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `lw` at 0x2ad0 loads 4 bytes from ret(gthread_find) +0x4.
  The `lw` at 0x2ae4 loads 4 bytes from ret(gthread_find) +0x0.
  The `sw` at 0x2b28 stores 4 bytes to a0 (arg0 at entry) +0x38.
  The `jal` at 0x2ac0 calls curthreadhandle with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2ac8 calls gthread_find with a0=ret(curthreadhandle), a1=?, a2=?, a3=?.
  The `jal` at 0x2ae0 calls thread_issproc with a0=[ret(gthread_find)], a1=?, a2=-0x1, a3=?.
  The `jal` at 0x2b00 calls ddv_invalphys_fal with a0=[a0+28], a1=0x0, a2=-0x1, a3=?.
  The `jal` at 0x2b1c calls crimeInvalTLB with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `bne` branch at 0x2aa4 targets 0x2ac0, is taken when at(=[a0+28]) != 0, and falls through when at(=[a0+28]) == 0.
  The `beq` branch at 0x2ad8 targets 0x2afc, is taken when (a0(=[ret(gthread_find)+4]) & 0x4) == 0, and falls through when (a0(=[ret(gthread_find)+4]) & 0x4) != 0.
  The `beq` branch at 0x2ae8 targets 0x2afc, is taken when v0(=ret(thread_issproc)) == 0, and falls through when v0(=ret(thread_issproc)) != 0.
  The `beq` branch at 0x2af0 targets 0x2ab0 and is always taken.
  The `bne` branch at 0x2b0c targets 0x2b1c, is taken when v0(=ret(ddv_invalphys_fal)) != a1(=0x2), and falls through when v0(=ret(ddv_invalphys_fal)) == a1(=0x2).
  The `beq` branch at 0x2b14 targets 0x2ab0 and is always taken.
  The `beq` branch at 0x2b2c targets 0x2ab0 and is always taken.
  The return at 0x2ab8 has v0 = 0x0.
  The instructions from 0x2af8 to 0x2af8 are not reached by any path from the entry, and their branches are not listed.

- `crmFifoWait` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x2b94 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x2b94-0x2dbc (552 bytes).
  It occupies 552 bytes.
  The `lh` at 0x2bbc loads 2 bytes from sym(crimeBoards) +0x3c.
  The `lw` at 0x2bd4 loads 4 bytes from sym(crimeBoards) +0xc.
  The `lw` at 0x2c0c loads 4 bytes from a0 (arg0 at entry) +0x4000.
  2 such `sw` accesses store 4 bytes to [sym(crimeBoards+12)] +0x224, including `sw` at 0x2c7c, `sw` at 0x2cb0.
  2 such `lw` accesses load 4 bytes from [sym(crimeBoards+12)] +0x28, including `lw` at 0x2c90, `lw` at 0x2d84.
  2 such `lw` accesses load 4 bytes from [[sym(crimeBoards+12)]+40] +0x18, including `lw` at 0x2c94, `lw` at 0x2d88.
  2 such `lw` accesses load 4 bytes from [[[sym(crimeBoards+12)]+40]+24] +0x2c, including `lw` at 0x2c98, `lw` at 0x2d8c.
  2 such `sw` accesses store 4 bytes to [[[sym(crimeBoards+12)]+40]+24] +0x2c, including `sw` at 0x2ca0, `sw` at 0x2d94.
  The `sw` at 0x2ca8 stores 4 bytes to [sym(crimeBoards+12)] +0x220.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x400, including `sw` at 0x2cd8, `sw` at 0x2d78.
  2 such `sw` accesses store 4 bytes to [sym(crimeBoards+12)] +0x228, including `sw` at 0x2d28, `sw` at 0x2da0.
  2 such `lw` accesses load 4 bytes from [sym(crimeBoards+12)] +0x224, including `lw` at 0x2d98, `lw` at 0x2db8.
  The `jal` at 0x2bf8 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x2cac calls splhi with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x2cd4 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2cdc calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x2d1c calls timeout with a0=sym(crimeFifoWaitTimeout), a1=[sym(crimeBoards+12)], a2=?, a3=?, a4=0xf4240.
  The `jal` at 0x2d24 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2d30 calls crime_intr_enable with a0=0x19, a1=?, a2=?, a3=?.
  The `jal` at 0x2d44 calls sv_wait with a0=[sym(crimeBoards+12)]+556, a1=0x19, a2=[sym(crimeBoards+12)]+540, a3=ret(splhi).
  The `jal` at 0x2d50 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2d74 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2d7c calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x2dac calls cmn_err with a0=0x4, a1=sym(.rodata)+280, a2=a2 at entry (arg2), a3=?.
  The `beq` branch at 0x2bdc targets 0x2c5c, is taken when at(=[sym(crimeBoards+60)]:2) == 0, and falls through when at(=[sym(crimeBoards+60)]:2) != 0.
  The `bgtz` branch at 0x2be8 targets 0x2c0c, is taken when s5(?) > 0 (signed), and falls through when s5(?) <= 0 (signed).
  The `beq` branch at 0x2bf0 targets 0x2c48 and is always taken.
  The `blez` branch at 0x2c04 targets 0x2c4c, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `bne` branch at 0x2c1c targets 0x2bf8, is taken when s2(?) < t8(?) (unsigned), and falls through when s2(?) >= t8(?) (unsigned).
  The `beq` branch at 0x2c4c targets 0x2c70, is taken when t9(=[sym(crimeBoards+60)]:2) == 0, and falls through when t9(=[sym(crimeBoards+60)]:2) != 0.
  The `beq` branch at 0x2c54 targets 0x2c24 and is always taken.
  The `bne` branch at 0x2c5c targets 0x2be8, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x2c68 targets 0x2be8 and is always taken.
  The `bne` branch at 0x2c74 targets 0x2c90, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `bne` branch at 0x2c80 targets 0x2da4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x2c88 targets 0x2c28 and is always taken.
  The `beq` branch at 0x2d9c targets 0x2c80 and is always taken.
  The `beq` branch at 0x2db4 targets 0x2c88 and is always taken.
  The return at 0x2c40 has v0 = one of 0x0, 0x1, ?.

- `crimePcxSwap` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x2e54 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x2e54-0x2ff8 (420 bytes).
  It occupies 420 bytes.
  The `lw` at 0x2e7c loads 4 bytes from a0 (arg0 at entry) +0x78.
  2 such `sw` accesses store 4 bytes to [a0+120] +0x4008, including `sw` at 0x2e90, `sw` at 0x2f44.
  The `lw` at 0x2e98 loads 4 bytes from a2 (arg2 at entry) +0x4c.
  The `lw` at 0x2ea0 loads 4 bytes from a2 (arg2 at entry) +0x8.
  The `lw` at 0x2ec8 loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `sw` at 0x2ed0 stores 4 bytes to [a0+144] +0x0.
  The `lhu` at 0x2ed4 loads 2 bytes from a2 (arg2 at entry) +0x4.
  The `lw` at 0x2ee4 loads 4 bytes from a2 (arg2 at entry) +0x50.
  The `lw` at 0x2ee8 loads 4 bytes from a2 (arg2 at entry) +0x58.
  The `lw` at 0x2eec loads 4 bytes from [a2+80] +0x8.
  The `lw` at 0x2ef8 loads 4 bytes from a2 (arg2 at entry) +0x54.
  The `lw` at 0x2efc loads 4 bytes from a2 (arg2 at entry) +0x5c.
  The `lw` at 0x2f00 loads 4 bytes from [a2+84] +0x8.
  The `lw` at 0x2f18 loads 4 bytes from a2 (arg2 at entry) +0x30.
  The `lw` at 0x2f48 loads 4 bytes from [a2+76] +0x48.
  The `lw` at 0x2f90 loads 4 bytes from a1 (arg1 at entry) +0x4c.
  The `lw` at 0x2f9c loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `sw` at 0x2fa8 stores 4 bytes to [a1+76] +0x48.
  The `lw` at 0x2fac loads 4 bytes from [a1+8] +0x1f0.
  The `lw` at 0x2fe4 loads 4 bytes from [a0+120] +0x20c4.
  The `sw` at 0x2fec stores 4 bytes to [a1+8] +0xc4.
  The `jal` at 0x2e78 calls gfx_waitc_on with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2ea4 calls crmIdleWait with a0=[a0+120], a1=0xf4240, a2=?, a3=?.
  The `jal` at 0x2eb8 calls crimeError with a0=[a0+120], a1=sym(.rodata)+376, a2=?, a3=?.
  The `jal` at 0x2f14 calls crimeValidateClip with a0=[a2+48], a1=a2 at entry (arg2), a2=0x0, a3=[a2+80]+64, a4=[a0+144], a5=[[a2+80]+8], a6=[a2+88].
  The `jal` at 0x2f24 calls crmValidateDrawable with a0=a0 at entry (arg0), a1=[a2+76], a2=?, a3=?.
  The `jal` at 0x2f30 calls crmLoadGlobalsFromShadow with a0=[a0+120], a1=[a2+8], a2=?, a3=?.
  The `jal` at 0x2f3c calls crmLoadNonglobalsFromShadow with a0=[a0+120], a1=[a2+8], a2=?, a3=?.
  The `jal` at 0x2f58 calls crmRestorePP with a0=[a0+120], a1=[a2+76]+848, a2=[a2+76]+336, a3=[[a2+76]+72].
  The `jal` at 0x2f60 calls gfx_waitc_off with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2fa0 calls crmSavePP with a0=[a0+120], a1=[a1+76]+848, a2=[a1+76]+336, a3=?.
  The `jal` at 0x2fc0 calls crmIdleWait with a0=[a0+120], a1=0xf4240, a2=?, a3=?.
  The `jal` at 0x2fd4 calls crimeError with a0=[a0+120], a1=sym(.rodata)+360, a2=?, a3=?.
  The `bne` branch at 0x2e84 targets 0x2f90, is taken when s4(=a1) != 0, and falls through when s4(=a1) == 0.
  The `beq` branch at 0x2e8c targets 0x2f60, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x2eac targets 0x2ec8, is taken when v0(=ret(crmIdleWait)) == 0, and falls through when v0(=ret(crmIdleWait)) != 0.
  The `beq` branch at 0x2ec0 targets 0x2f6c and is always taken.
  The `beq` branch at 0x2edc targets 0x2f24, is taken when (a2(=[a2+4]:2) & 0x2) == 0, and falls through when (a2(=[a2+4]:2) & 0x2) != 0.
  The `bne` branch at 0x2ef0 targets 0x2f0c, is taken when a5(=[[a2+80]+8]) != a6(=[a2+88]), and falls through when a5(=[[a2+80]+8]) == a6(=[a2+88]).
  The `beq` branch at 0x2f04 targets 0x2f20, is taken when a7(=[[a2+84]+8]) == t0(=[a2+92]), and falls through when a7(=[[a2+84]+8]) != t0(=[a2+92]).
  The `bltz` branch at 0x2f1c targets 0x2ff0, is taken when v0(=ret(crimeValidateClip)) < 0 (signed), and falls through when v0(=ret(crimeValidateClip)) >= 0 (signed).
  The `beq` branch at 0x2f4c targets 0x2f60, is taken when a3(=[[a2+76]+72]) == 0, and falls through when a3(=[[a2+76]+72]) != 0.
  The `beq` branch at 0x2fb4 targets 0x2e8c, is taken when (t0(=[[a1+8]+496]) & 0x1) == 0, and falls through when (t0(=[[a1+8]+496]) & 0x1) != 0.
  The `beq` branch at 0x2fc8 targets 0x2fe4, is taken when v0(=ret(crmIdleWait)) == 0, and falls through when v0(=ret(crmIdleWait)) != 0.
  The `beq` branch at 0x2fdc targets 0x2f6c and is always taken.
  The `beq` branch at 0x2fe8 targets 0x2e8c and is always taken.
  The `beq` branch at 0x2ff0 targets 0x2f6c and is always taken.
  The return at 0x2f88 has v0 = one of -0x1, 0x0.

- `crmSavePP` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x2ff8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x2ff8-0x3118 (288 bytes).
  It occupies 288 bytes.
  The `lw` at 0x3000 loads 4 bytes from a0 (arg0 at entry) +0x4000.
  The `ld` at 0x3088 loads 8 bytes from ?.
  The `sd` at 0x308c stores 8 bytes to ?.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3090, `lw` at 0x30a4.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x3098, `sw` at 0x30b0.
  The `sw` at 0x30cc stores 4 bytes to a0 (arg0 at entry) +0x4008.
  The `jal` at 0x3048 calls crmFifoWait with a0=a0 at entry (arg0), a1=[sym(ib_full)], a2=0xf4240, a3=?.
  The `jal` at 0x305c calls crimeError with a0=a0 at entry (arg0), a1=sym(.rodata)+392, a2=?, a3=?.
  The `jal` at 0x30f4 calls crmFindPP with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x3030 targets 0x30f4, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bltz` branch at 0x3038 targets 0x30ec, is taken when s1(?) < 0 (signed), and falls through when s1(?) >= 0 (signed).
  The `beq` branch at 0x3050 targets 0x306c, is taken when v0(=ret(crmFifoWait)) == 0, and falls through when v0(=ret(crmFifoWait)) != 0.
  The `beq` branch at 0x3064 targets 0x30d0 and is always taken.
  The `blez` branch at 0x306c targets 0x30cc, is taken when s1(?) <= 0 (signed), and falls through when s1(?) > 0 (signed).
  The `bne` branch at 0x30ac targets 0x30b8, is taken when s0(?) < 0x40 (signed), and falls through when s0(?) >= 0x40 (signed).
  The `bne` branch at 0x30c4 targets 0x3088, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x30ec targets 0x303c and is always taken.
  The `bne` branch at 0x3108 targets 0x3038, is taken when v0(=ret(crmFindPP)) != t8(=-0x1), and falls through when v0(=ret(crmFindPP)) == t8(=-0x1).
  The `beq` branch at 0x3110 targets 0x30d0 and is always taken.
  The return at 0x30e4 has v0 = one of 0x0, ?.

- `crmRestorePP` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x3118 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x3118-0x3240 (296 bytes).
  It occupies 296 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3178, `ld` at 0x3194.
  The `sd` at 0x317c stores 8 bytes to ?.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x31d4, `lw` at 0x31e8, `lw` at 0x3224.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x31e0, `sw` at 0x31f0.
  The `jal` at 0x3230 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=?, a3=?.
  The `blez` branch at 0x3150 targets 0x31f4, is taken when a3 <= 0 (signed), and falls through when a3 > 0 (signed).
  The `beq` branch at 0x3164 targets 0x3194 and is always taken.
  The `bne` branch at 0x316c targets 0x3220, is taken when a5(=0x3) != a1(?), and falls through when a5(=0x3) == a1(?).
  The `beq` branch at 0x318c targets 0x31f4, is taken when s2(?) >= s5(=a3) (signed), and falls through when s2(?) < s5(=a3) (signed).
  The `beq` branch at 0x31c4 targets 0x31e4, is taken when s6(=0x2) == a1(?), and falls through when s6(=0x2) != a1(?).
  The `bne` branch at 0x31cc targets 0x316c, is taken when s7(=0x1) != a1(?), and falls through when s7(=0x1) == a1(?).
  The `beq` branch at 0x31dc targets 0x3180 and is always taken.
  The `beq` branch at 0x31ec targets 0x3180 and is always taken.
  The `beq` branch at 0x3238 targets 0x3180 and is always taken.
  The return at 0x3218 has v0 = ?.

- `crmLoadNonglobalsFromShadow` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x3240 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x3240-0x3434 (500 bytes).
  It occupies 500 bytes.
  The `lw` at 0x3240 loads 4 bytes from a1 (arg1 at entry) +0x1f0.
  The `lw` at 0x3244 loads 4 bytes from a1 (arg1 at entry) +0x60.
  The `sw` at 0x3248 stores 4 bytes to a0 (arg0 at entry) +0x2060.
  The `lw` at 0x324c loads 4 bytes from a1 (arg1 at entry) +0xa0.
  The `sw` at 0x3250 stores 4 bytes to a0 (arg0 at entry) +0x20a0.
  The `lw` at 0x3254 loads 4 bytes from a1 (arg1 at entry) +0xa8.
  The `sw` at 0x3258 stores 4 bytes to a0 (arg0 at entry) +0x20a8.
  The `lw` at 0x325c loads 4 bytes from a1 (arg1 at entry) +0xac.
  The `sw` at 0x3260 stores 4 bytes to a0 (arg0 at entry) +0x20ac.
  The `lw` at 0x3264 loads 4 bytes from a1 (arg1 at entry) +0xb0.
  The `sw` at 0x3268 stores 4 bytes to a0 (arg0 at entry) +0x20b0.
  The `lw` at 0x326c loads 4 bytes from a1 (arg1 at entry) +0xb4.
  The `sw` at 0x3274 stores 4 bytes to a0 (arg0 at entry) +0x20b4.
  The `lw` at 0x327c loads 4 bytes from a1 (arg1 at entry) +0xd0.
  The `sw` at 0x3288 stores 4 bytes to a0 (arg0 at entry) +0x20d0.
  The `lw` at 0x328c loads 4 bytes from a1 (arg1 at entry) +0xc0.
  The `sw` at 0x3290 stores 4 bytes to a0 (arg0 at entry) +0x20c0.
  The `lw` at 0x3294 loads 4 bytes from a1 (arg1 at entry) +0xc4.
  The `sw` at 0x3298 stores 4 bytes to a0 (arg0 at entry) +0x20c4.
  The `lw` at 0x32a4 loads 4 bytes from a1 (arg1 at entry) +0x210.
  The `sw` at 0x32a8 stores 4 bytes to a0 (arg0 at entry) +0x3010.
  The `lw` at 0x32ac loads 4 bytes from a1 (arg1 at entry) +0x230.
  The `sw` at 0x32b0 stores 4 bytes to a0 (arg0 at entry) +0x3030.
  The `lw` at 0x32b4 loads 4 bytes from a1 (arg1 at entry) +0x238.
  The `sw` at 0x32b8 stores 4 bytes to a0 (arg0 at entry) +0x3038.
  The `lw` at 0x32c4 loads 4 bytes from a1 (arg1 at entry) +0x70.
  The `sw` at 0x32c8 stores 4 bytes to a0 (arg0 at entry) +0x2070.
  The `lw` at 0x32cc loads 4 bytes from a1 (arg1 at entry) +0x74.
  The `sw` at 0x32d0 stores 4 bytes to a0 (arg0 at entry) +0x2074.
  The `lw` at 0x32d4 loads 4 bytes from a1 (arg1 at entry) +0x78.
  The `sw` at 0x32d8 stores 4 bytes to a0 (arg0 at entry) +0x2078.
  The `lw` at 0x32e4 loads 4 bytes from a1 (arg1 at entry) +0x80.
  The `sw` at 0x32e8 stores 4 bytes to a0 (arg0 at entry) +0x2080.
  The `lw` at 0x32ec loads 4 bytes from a1 (arg1 at entry) +0x84.
  The `sw` at 0x32f0 stores 4 bytes to a0 (arg0 at entry) +0x2084.
  The `lw` at 0x32f4 loads 4 bytes from a1 (arg1 at entry) +0x88.
  The `sw` at 0x32f8 stores 4 bytes to a0 (arg0 at entry) +0x2088.
  The `lw` at 0x32fc loads 4 bytes from a1 (arg1 at entry) +0x8c.
  The `sw` at 0x3300 stores 4 bytes to a0 (arg0 at entry) +0x208c.
  The `lw` at 0x3304 loads 4 bytes from a1 (arg1 at entry) +0x90.
  The `sw` at 0x330c stores 4 bytes to a0 (arg0 at entry) +0x2090.
  The `lw` at 0x3318 loads 4 bytes from a1 (arg1 at entry) +0x94.
  The `sw` at 0x3324 stores 4 bytes to a0 (arg0 at entry) +0x2094.
  The `lw` at 0x3328 loads 4 bytes from a1 (arg1 at entry) +0x178.
  The `sw` at 0x332c stores 4 bytes to a0 (arg0 at entry) +0x2178.
  The `lw` at 0x3330 loads 4 bytes from a1 (arg1 at entry) +0x180.
  The `sw` at 0x3334 stores 4 bytes to a0 (arg0 at entry) +0x2180.
  The `lw` at 0x3338 loads 4 bytes from a1 (arg1 at entry) +0x188.
  The `sw` at 0x333c stores 4 bytes to a0 (arg0 at entry) +0x2188.
  The `lw` at 0x3340 loads 4 bytes from a1 (arg1 at entry) +0x190.
  The `sw` at 0x3344 stores 4 bytes to a0 (arg0 at entry) +0x2190.
  The `lw` at 0x3348 loads 4 bytes from a1 (arg1 at entry) +0x194.
  The `sw` at 0x334c stores 4 bytes to a0 (arg0 at entry) +0x2194.
  The `ld` at 0x3358 loads 8 bytes from a1 (arg1 at entry) +0x1c8.
  The `sd` at 0x335c stores 8 bytes to a0 (arg0 at entry) +0x21c8.
  The `ld` at 0x3360 loads 8 bytes from a1 (arg1 at entry) +0x1d0.
  The `sd` at 0x3364 stores 8 bytes to a0 (arg0 at entry) +0x21d0.
  The `ld` at 0x3368 loads 8 bytes from a1 (arg1 at entry) +0x1d8.
  The `sd` at 0x336c stores 8 bytes to a0 (arg0 at entry) +0x21d8.
  The `lw` at 0x3378 loads 4 bytes from a1 (arg1 at entry) +0xe0.
  The `sw` at 0x337c stores 4 bytes to a0 (arg0 at entry) +0x20e0.
  The `lw` at 0x3380 loads 4 bytes from a1 (arg1 at entry) +0xe4.
  The `sw` at 0x3384 stores 4 bytes to a0 (arg0 at entry) +0x20e4.
  The `lw` at 0x3388 loads 4 bytes from a1 (arg1 at entry) +0xe8.
  The `sw` at 0x338c stores 4 bytes to a0 (arg0 at entry) +0x20e8.
  The `lw` at 0x3390 loads 4 bytes from a1 (arg1 at entry) +0xec.
  The `sw` at 0x3394 stores 4 bytes to a0 (arg0 at entry) +0x20ec.
  The `lw` at 0x3398 loads 4 bytes from a1 (arg1 at entry) +0xf0.
  The `sw` at 0x339c stores 4 bytes to a0 (arg0 at entry) +0x20f0.
  The `lw` at 0x33a0 loads 4 bytes from a1 (arg1 at entry) +0xf4.
  The `sw` at 0x33a4 stores 4 bytes to a0 (arg0 at entry) +0x20f4.
  The `lw` at 0x33a8 loads 4 bytes from a1 (arg1 at entry) +0xf8.
  The `sw` at 0x33ac stores 4 bytes to a0 (arg0 at entry) +0x20f8.
  The `lw` at 0x33b0 loads 4 bytes from a1 (arg1 at entry) +0xfc.
  The `sw` at 0x33b4 stores 4 bytes to a0 (arg0 at entry) +0x20fc.
  The `lw` at 0x33b8 loads 4 bytes from a1 (arg1 at entry) +0x100.
  The `sw` at 0x33bc stores 4 bytes to a0 (arg0 at entry) +0x2100.
  The `lw` at 0x33c0 loads 4 bytes from a1 (arg1 at entry) +0x104.
  The `sw` at 0x33c4 stores 4 bytes to a0 (arg0 at entry) +0x2104.
  The `lw` at 0x33c8 loads 4 bytes from a1 (arg1 at entry) +0x108.
  The `sw` at 0x33cc stores 4 bytes to a0 (arg0 at entry) +0x2108.
  The `lw` at 0x33d0 loads 4 bytes from a1 (arg1 at entry) +0x10c.
  The `sw` at 0x33d4 stores 4 bytes to a0 (arg0 at entry) +0x210c.
  The `ld` at 0x33e0 loads 8 bytes from a1 (arg1 at entry) +0x120.
  The `sd` at 0x33e4 stores 8 bytes to a0 (arg0 at entry) +0x2120.
  The `ld` at 0x33e8 loads 8 bytes from a1 (arg1 at entry) +0x128.
  The `sd` at 0x33ec stores 8 bytes to a0 (arg0 at entry) +0x2128.
  The `lw` at 0x33f0 loads 4 bytes from a1 (arg1 at entry) +0x130.
  The `sw` at 0x33f4 stores 4 bytes to a0 (arg0 at entry) +0x2130.
  The `lw` at 0x33f8 loads 4 bytes from a1 (arg1 at entry) +0x134.
  The `sw` at 0x33fc stores 4 bytes to a0 (arg0 at entry) +0x2134.
  The `ld` at 0x3400 loads 8 bytes from a1 (arg1 at entry) +0x138.
  The `sd` at 0x3404 stores 8 bytes to a0 (arg0 at entry) +0x2138.
  The `ld` at 0x3408 loads 8 bytes from a1 (arg1 at entry) +0x140.
  The `sd` at 0x340c stores 8 bytes to a0 (arg0 at entry) +0x2140.
  The `ld` at 0x3410 loads 8 bytes from a1 (arg1 at entry) +0x148.
  The `sd` at 0x3414 stores 8 bytes to a0 (arg0 at entry) +0x2148.
  The `ld` at 0x3418 loads 8 bytes from a1 (arg1 at entry) +0x150.
  The `sd` at 0x341c stores 8 bytes to a0 (arg0 at entry) +0x2150.
  The `lw` at 0x3420 loads 4 bytes from a1 (arg1 at entry) +0x158.
  The `sw` at 0x3424 stores 4 bytes to a0 (arg0 at entry) +0x2158.
  The `lw` at 0x3428 loads 4 bytes from a1 (arg1 at entry) +0x15c.
  The `sw` at 0x3430 stores 4 bytes to a0 (arg0 at entry) +0x215c.
  The `beq` branch at 0x3284 targets 0x329c, is taken when (a5(=[a1+496]) & 0x1) == 0, and falls through when (a5(=[a1+496]) & 0x1) != 0.
  The `beq` branch at 0x329c targets 0x32bc, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x32bc targets 0x32e4, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x3320 targets 0x3350, is taken when (a5(=[a1+496]) & 0x40) == 0, and falls through when (a5(=[a1+496]) & 0x40) != 0.
  The `beq` branch at 0x3350 targets 0x3370, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x3370 targets 0x33d8, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x33d8 targets 0x32dc, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The return at 0x32dc has v0 = one of [a1+112], ?.
  The return at 0x342c has v0 = ?.

- `crmLoadGlobalsFromShadow` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x3434 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x3434-0x357c (328 bytes).
  It occupies 328 bytes.
  The `lw` at 0x3434 loads 4 bytes from a1 (arg1 at entry) +0x1f0.
  The `lw` at 0x3438 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `sw` at 0x343c stores 4 bytes to a0 (arg0 at entry) +0x2000.
  The `lw` at 0x3440 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `sw` at 0x3444 stores 4 bytes to a0 (arg0 at entry) +0x2008.
  The `lw` at 0x3448 loads 4 bytes from a1 (arg1 at entry) +0x10.
  The `sw` at 0x344c stores 4 bytes to a0 (arg0 at entry) +0x2010.
  The `lw` at 0x3450 loads 4 bytes from a1 (arg1 at entry) +0x18.
  The `sw` at 0x3454 stores 4 bytes to a0 (arg0 at entry) +0x2018.
  The `ld` at 0x3458 loads 8 bytes from a1 (arg1 at entry) +0x20.
  The `sd` at 0x345c stores 8 bytes to a0 (arg0 at entry) +0x2020.
  The `ld` at 0x3460 loads 8 bytes from a1 (arg1 at entry) +0x28.
  The `sd` at 0x3464 stores 8 bytes to a0 (arg0 at entry) +0x2028.
  The `ld` at 0x3468 loads 8 bytes from a1 (arg1 at entry) +0x30.
  The `sd` at 0x346c stores 8 bytes to a0 (arg0 at entry) +0x2030.
  The `ld` at 0x3470 loads 8 bytes from a1 (arg1 at entry) +0x38.
  The `sd` at 0x3474 stores 8 bytes to a0 (arg0 at entry) +0x2038.
  The `ld` at 0x3478 loads 8 bytes from a1 (arg1 at entry) +0x40.
  The `sd` at 0x347c stores 8 bytes to a0 (arg0 at entry) +0x2040.
  The `lw` at 0x3480 loads 4 bytes from a1 (arg1 at entry) +0x50.
  The `sw` at 0x3484 stores 4 bytes to a0 (arg0 at entry) +0x2050.
  The `lw` at 0x3488 loads 4 bytes from a1 (arg1 at entry) +0x58.
  The `sw` at 0x348c stores 4 bytes to a0 (arg0 at entry) +0x2058.
  The `lw` at 0x3490 loads 4 bytes from a1 (arg1 at entry) +0x1b0.
  The `sw` at 0x3494 stores 4 bytes to a0 (arg0 at entry) +0x21b0.
  The `lw` at 0x3498 loads 4 bytes from a1 (arg1 at entry) +0x1b8.
  The `sw` at 0x34a0 stores 4 bytes to a0 (arg0 at entry) +0x21b8.
  The `lw` at 0x34a4 loads 4 bytes from a1 (arg1 at entry) +0xd8.
  The `sw` at 0x34b0 stores 4 bytes to a0 (arg0 at entry) +0x20d8.
  The `lw` at 0x34b4 loads 4 bytes from a1 (arg1 at entry) +0x200.
  The `sw` at 0x34b8 stores 4 bytes to a0 (arg0 at entry) +0x3000.
  The `lw` at 0x34bc loads 4 bytes from a1 (arg1 at entry) +0x208.
  The `sw` at 0x34c0 stores 4 bytes to a0 (arg0 at entry) +0x3008.
  The `lw` at 0x34c4 loads 4 bytes from a1 (arg1 at entry) +0x218.
  The `sw` at 0x34c8 stores 4 bytes to a0 (arg0 at entry) +0x3018.
  The `lw` at 0x34cc loads 4 bytes from a1 (arg1 at entry) +0x220.
  The `sw` at 0x34d0 stores 4 bytes to a0 (arg0 at entry) +0x3020.
  The `lw` at 0x34d4 loads 4 bytes from a1 (arg1 at entry) +0x228.
  The `sw` at 0x34d8 stores 4 bytes to a0 (arg0 at entry) +0x3028.
  The `lw` at 0x34dc loads 4 bytes from a1 (arg1 at entry) +0x240.
  The `sw` at 0x34e0 stores 4 bytes to a0 (arg0 at entry) +0x3040.
  The `lw` at 0x34e4 loads 4 bytes from a1 (arg1 at entry) +0x248.
  The `sw` at 0x34e8 stores 4 bytes to a0 (arg0 at entry) +0x3048.
  The `ld` at 0x3500 loads 8 bytes from a1 (arg1 at entry) +0x48.
  The `sd` at 0x350c stores 8 bytes to a0 (arg0 at entry) +0x2048.
  The `lw` at 0x3510 loads 4 bytes from a1 (arg1 at entry) +0x170.
  The `sw` at 0x3514 stores 4 bytes to a0 (arg0 at entry) +0x2170.
  The `lw` at 0x3518 loads 4 bytes from a1 (arg1 at entry) +0x1a0.
  The `sw` at 0x351c stores 4 bytes to a0 (arg0 at entry) +0x21a0.
  The `lw` at 0x3520 loads 4 bytes from a1 (arg1 at entry) +0x1a8.
  The `sw` at 0x3524 stores 4 bytes to a0 (arg0 at entry) +0x21a8.
  The `lw` at 0x3528 loads 4 bytes from a1 (arg1 at entry) +0x198.
  The `sw` at 0x352c stores 4 bytes to a0 (arg0 at entry) +0x2198.
  The `lw` at 0x3538 loads 4 bytes from a1 (arg1 at entry) +0x1c0.
  The `sw` at 0x353c stores 4 bytes to a0 (arg0 at entry) +0x21c0.
  The `lw` at 0x3540 loads 4 bytes from a1 (arg1 at entry) +0x1e0.
  The `sw` at 0x3544 stores 4 bytes to a0 (arg0 at entry) +0x21e0.
  The `lw` at 0x3548 loads 4 bytes from a1 (arg1 at entry) +0x1e8.
  The `sw` at 0x354c stores 4 bytes to a0 (arg0 at entry) +0x21e8.
  The `lw` at 0x3558 loads 4 bytes from a1 (arg1 at entry) +0x110.
  The `sw` at 0x355c stores 4 bytes to a0 (arg0 at entry) +0x2110.
  The `ld` at 0x3560 loads 8 bytes from a1 (arg1 at entry) +0x118.
  The `sd` at 0x3564 stores 8 bytes to a0 (arg0 at entry) +0x2118.
  The `lw` at 0x3568 loads 4 bytes from a1 (arg1 at entry) +0x160.
  The `sw` at 0x356c stores 4 bytes to a0 (arg0 at entry) +0x2160.
  The `lw` at 0x3570 loads 4 bytes from a1 (arg1 at entry) +0x168.
  The `sw` at 0x3578 stores 4 bytes to a0 (arg0 at entry) +0x2168.
  The `beq` branch at 0x34ac targets 0x34ec, is taken when (a4(=[a1+496]) & 0x4) == 0, and falls through when (a4(=[a1+496]) & 0x4) != 0.
  The `beq` branch at 0x34ec targets 0x34fc, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x3508 targets 0x3530, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x3530 targets 0x3550, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x3550 targets 0x34f4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0x34f4 has v0 = ?.
  The return at 0x3574 has v0 = ?.

- `restore_linear` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x357c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x357c-0x35e4 (104 bytes).
  It occupies 104 bytes.
  The `ld` at 0x35b8 loads 8 bytes from ?.
  The `sd` at 0x35c0 stores 8 bytes to ?.
  The `beq` branch at 0x357c targets 0x35dc, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x359c targets 0x35c4, is taken when (a5(?) & a2(?)) == 0, and falls through when (a5(?) & a2(?)) != 0.
  The `beq` branch at 0x35cc targets 0x35dc, is taken when a4(?) >= 0x20 (signed), and falls through when a4(?) < 0x20 (signed).
  The `bne` branch at 0x35d4 targets 0x3590, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The return at 0x35dc has v0 = ?.

- `crimeRestore` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x35e4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x35e4-0x36c8 (228 bytes).
  It occupies 228 bytes.
  The `lw` at 0x35f8 loads 4 bytes from sym(crimeBoards) +0x10.
  The `lw` at 0x3608 loads 4 bytes from sym(crmFrameBuffer) +0x5ec.
  The `lw` at 0x3618 loads 4 bytes from sym(crimeBoards) +0x0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3628, `lw` at 0x364c.
  The `sw` at 0x3658 stores 4 bytes to ?.
  The `sw` at 0x369c stores 4 bytes to [sym(crimeBoards)] +0x4008.
  The `jal` at 0x3674 calls restore_linear with a0=[sym(crimeBoards)]+5888, a1=sym(.bss)+1512, a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x3688 calls restore_linear with a0=[sym(crimeBoards)]+6016, a1=sym(.bss)+1512, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x36ac calls crmRestorePP with a0=[sym(crimeBoards)], a1=a4 at entry (arg4), a2=a5 at entry (arg5), a3=a6 at entry (arg6).
  The `blez` branch at 0x361c targets 0x365c, is taken when a3 <= 0 (signed), and falls through when a3 > 0 (signed).
  The `bne` branch at 0x3654 targets 0x3628, is taken when t0(?) < a3 (signed), and falls through when t0(?) >= a3 (signed).
  The `beq` branch at 0x3664 targets 0x367c, is taken when t3(=a0) == 0, and falls through when t3(=a0) != 0.
  The `beq` branch at 0x367c targets 0x3690, is taken when s3(=a1) == 0, and falls through when s3(=a1) != 0.
  The `blez` branch at 0x3698 targets 0x36b4, is taken when s2(=a6) <= 0 (signed), and falls through when s2(=a6) > 0 (signed).
  The return at 0x36c0 has v0 = one of ?, ret(crmRestorePP).

- `crimeOpenPbuf` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x3750 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x3750-0x385c (268 bytes).
  It occupies 268 bytes.
  The `lw` at 0x3750 loads 4 bytes from a1 (arg1 at entry) +0x0.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0xc, including `lw` at 0x376c, `lw` at 0x3814.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x3780, `lw` at 0x3820.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x3794, `lw` at 0x3818.
  The `lw` at 0x37c4 loads 4 bytes from ret(crm_finddrawable) +0x24.
  2 such `sw` accesses store 4 bytes to ret(crm_finddrawable) +0x24, including `sw` at 0x37e4, `sw` at 0x37f8.
  The `lw` at 0x37e8 loads 4 bytes from a1 (arg1 at entry) +0x10.
  The `sw` at 0x3808 stores 4 bytes to ret(crm_finddrawable) +0x18.
  The `lw` at 0x3828 loads 4 bytes from ret(crm_finddrawable) +0x18.
  The `jal` at 0x37bc calls crm_finddrawable with a0=[a1], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x16.
  The `jal` at 0x37fc calls kern_malloc with a0=0x28, a1=?, a2=?, a3=?, a4=0xb.
  The `jal` at 0x380c calls bzero with a0=ret(kern_malloc), a1=0x28, a2=?, a3=?.
  The `jal` at 0x382c calls crmAllocPbuffer with a0=[ret(crm_finddrawable)+24], a1=[a1+4], a2=[a1+8], a3=?, a4=[a1+12].
  The `jal` at 0x383c calls crm_destroydrawable with a0=ret(crm_finddrawable), a1=?, a2=?, a3=?.
  The `beq` branch at 0x3764 targets 0x37a8, is taken when a0(=[a1]) == 0, and falls through when a0(=[a1]) != 0.
  The `bltz` branch at 0x3770 targets 0x37a8, is taken when v0(=[a1+12]) < 0 (signed), and falls through when v0(=[a1+12]) >= 0 (signed).
  The `beq` branch at 0x3778 targets 0x37a8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `blez` branch at 0x3784 targets 0x37a8, is taken when v0(=[a1+4]) <= 0 (signed), and falls through when v0(=[a1+4]) > 0 (signed).
  The `beq` branch at 0x378c targets 0x37a8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `blez` branch at 0x3798 targets 0x37a8, is taken when v0(=[a1+8]) <= 0 (signed), and falls through when v0(=[a1+8]) > 0 (signed).
  The `bne` branch at 0x37a0 targets 0x37bc, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x37d0 targets 0x37e0, is taken when a0(=[ret(crm_finddrawable)+36]) == v1(=0x10), and falls through when a0(=[ret(crm_finddrawable)+36]) != v1(=0x10).
  The `beq` branch at 0x37d8 targets 0x37a8 and is always taken.
  The `beq` branch at 0x37f0 targets 0x37fc, is taken when (a1(=[a1+16]) & 0x1) == 0, and falls through when (a1(=[a1+16]) & 0x1) != 0.
  The `beq` branch at 0x3834 targets 0x3850, is taken when v0(=ret(crmAllocPbuffer)) == 0, and falls through when v0(=ret(crmAllocPbuffer)) != 0.
  The `beq` branch at 0x3848 targets 0x37a8 and is always taken.
  The `beq` branch at 0x3854 targets 0x37a8 and is always taken.
  The return at 0x37b4 has v0 = one of 0x16, 0xb, ret(crmAllocPbuffer), 0x0.

- `crime_load_fbtlb` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x3948 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x3948-0x3bd0 (648 bytes).
  It occupies 648 bytes.
  The `lw` at 0x3974 loads 4 bytes from a1 (arg1 at entry) +0x4c.
  3 such `lw` accesses load 4 bytes from [a1+76] +0x10, including `lw` at 0x3980, `lw` at 0x39d4, `lw` at 0x3b1c.
  The `lw` at 0x3984 loads 4 bytes from [[a1+76]+16] +0x8.
  The `lw` at 0x3988 loads 4 bytes from a1 (arg1 at entry) +0x14.
  The `lbu` at 0x3994 loads 1 byte from a3 (arg3 at entry) +0x1.
  The `lbu` at 0x39e0 loads 1 byte from a3 (arg3 at entry) +0x0.
  The `lw` at 0x3a0c loads 4 bytes from a1 (arg1 at entry) +0x10.
  The `lw` at 0x3a20 loads 4 bytes from [a1+76] +0xc.
  9 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3a34, `lw` at 0x3a50, `lw` at 0x3a64.
  3 such `lbu` accesses load 1 byte from a3 (arg3 at entry) +0x2, including `lbu` at 0x3a40, `lbu` at 0x3a88, `lbu` at 0x3af0.
  The `lw` at 0x3a60 loads 4 bytes from a3 (arg3 at entry) +0x4.
  The `sw` at 0x3a94 stores 4 bytes to ([a1+76] + ([a3+2]:1 << 0x2)) +0x0.
  The `lw` at 0x3a98 loads 4 bytes from a2 (arg2 at entry) +0x4.
  The `lw` at 0x3aa4 loads 4 bytes from a2 (arg2 at entry) +0x78.
  The `sw` at 0x3ae0 stores 4 bytes to [a2+120] +0x2050.
  The `lh` at 0x3b20 loads 2 bytes from [[a1+76]+16] +0xe.
  The `lh` at 0x3b24 loads 2 bytes from [[a1+76]+16] +0xc.
  The `lw` at 0x3b30 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `sw` at 0x3b44 stores 4 bytes to [a1+8] +0x50.
  The `sw` at 0x3b84 stores 4 bytes to ?.
  The `jal` at 0x3970 calls RRM_CheckValidFault with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3a08 calls crm_changedrawables with a0=a1 at entry (arg1), a1=[a1+16], a2=[a1+20], a3=?.
  The `jal` at 0x3aa8 calls RRM_CheckValidFault with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3ac4 calls crmSavePP with a0=[a2+120], a1=[a1+76]+848, a2=[a1+76]+336, a3=?.
  The `jal` at 0x3aec calls crmLoadTlbABC with a0=a2 at entry (arg2), a1=?, a2=[a3+2]:1, a3=?.
  The `jal` at 0x3b04 calls crmRestorePP with a0=[a2+120], a1=[a1+76]+848, a2=[a1+76]+336, a3=ret(crmSavePP).
  The `jal` at 0x3b88 calls crm_get_dms_tiles with a0=?, a1=[a3]:1, a2=0x1, a3=?.
  The `bltz` branch at 0x3978 targets 0x3b14, is taken when v0(=ret(RRM_CheckValidFault)) < 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) >= 0 (signed).
  The `bne` branch at 0x398c targets 0x3a04, is taken when at(=[[[a1+76]+16]+8]) != a2(=[a1+20]), and falls through when at(=[[[a1+76]+16]+8]) == a2(=[a1+20]).
  The `beq` branch at 0x3998 targets 0x3a20, is taken when v0(=[a3+1]:1) == 0, and falls through when v0(=[a3+1]:1) != 0.
  The `beq` branch at 0x39a0 targets 0x39cc, is taken when v0(=[a3+1]:1) == v1(=0x1), and falls through when v0(=[a3+1]:1) != v1(=0x1).
  The `beq` branch at 0x39cc targets 0x3a20, is taken when v0(=[a3+1]:1) == 0, and falls through when v0(=[a3+1]:1) != 0.
  The `beq` branch at 0x39d8 targets 0x3a2c, is taken when v0(=[[a1+76]+16]) == 0, and falls through when v0(=[[a1+76]+16]) != 0.
  The `beq` branch at 0x39e4 targets 0x3b48, is taken when a1(=[a3]:1) == 0, and falls through when a1(=[a3]:1) != 0.
  The `beq` branch at 0x39ec targets 0x3b64, is taken when a1(=[a3]:1) == a2(=0x1), and falls through when a1(=[a3]:1) != a2(=0x1).
  The `beq` branch at 0x39f4 targets 0x3a34, is taken when a1(=[a3]:1) == a3(=0x2), and falls through when a1(=[a3]:1) != a3(=0x2).
  The `beq` branch at 0x39fc targets 0x39ac and is always taken.
  The `beq` branch at 0x3a10 targets 0x3b1c, is taken when v0(=ret(crm_changedrawables)) == 0, and falls through when v0(=ret(crm_changedrawables)) != 0.
  The `beq` branch at 0x3a18 targets 0x39ac and is always taken.
  The `bne` branch at 0x3a24 targets 0x39e0, is taken when v0(=[[a1+76]+12]) != 0, and falls through when v0(=[[a1+76]+12]) == 0.
  The `beq` branch at 0x3a2c targets 0x39ac and is always taken.
  The `beq` branch at 0x3a38 targets 0x3b54, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x3a48 targets 0x3b5c, is taken when a4(=[a3+2]:1) >= 0x3 (signed), and falls through when a4(=[a3+2]:1) < 0x3 (signed).
  The `beq` branch at 0x3a58 targets 0x3a70, is taken when (a5(?) & 0x20) == 0, and falls through when (a5(?) & 0x20) != 0.
  The `bne` branch at 0x3a68 targets 0x3b84, is taken when a6(?) != v0(=[a3+4]), and falls through when a6(?) == v0(=[a3+4]).
  The `beq` branch at 0x3a74 targets 0x3b7c, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `blez` branch at 0x3a80 targets 0x3ba0, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `bne` branch at 0x3a9c targets 0x3b0c, is taken when t0(=[a2+4]) != s3(=a1), and falls through when t0(=[a2+4]) == s3(=a1).
  The `bltz` branch at 0x3ab0 targets 0x3bc0, is taken when v0(=ret(RRM_CheckValidFault)) < 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) >= 0 (signed).
  The `beq` branch at 0x3ad0 targets 0x3ae4, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `blez` branch at 0x3af4 targets 0x3b0c, is taken when s2(=ret(crmSavePP)) <= 0 (signed), and falls through when s2(=ret(crmSavePP)) > 0 (signed).
  The `beq` branch at 0x3b0c targets 0x39ac and is always taken.
  The `beq` branch at 0x3b14 targets 0x39ac and is always taken.
  The `beq` branch at 0x3b40 targets 0x3994 and is always taken.
  The `bne` branch at 0x3b4c targets 0x3a40, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x3b54 targets 0x39ac and is always taken.
  The `beq` branch at 0x3b5c targets 0x39b0 and is always taken.
  The `bne` branch at 0x3b68 targets 0x3a40, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x3b74 targets 0x3b4c and is always taken.
  The `beq` branch at 0x3b7c targets 0x39b0 and is always taken.
  The `beq` branch at 0x3b90 targets 0x3a70, is taken when v0(=ret(crm_get_dms_tiles)) == 0, and falls through when v0(=ret(crm_get_dms_tiles)) != 0.
  The `beq` branch at 0x3b98 targets 0x39b0 and is always taken.
  The `bltz` branch at 0x3ba0 targets 0x3bc8, is taken when v0(?) < 0 (signed), and falls through when v0(?) >= 0 (signed).
  The `bne` branch at 0x3bb0 targets 0x3a88, is taken when (t8(?) & 0x1) != 0, and falls through when (t8(?) & 0x1) == 0.
  The `beq` branch at 0x3bb8 targets 0x39ac and is always taken.
  The `beq` branch at 0x3bc0 targets 0x39ac and is always taken.
  The `beq` branch at 0x3bc8 targets 0x39ac and is always taken.
  The return at 0x39c4 has v0 = one of 0x0, 0x4, 0xe, 0x16, ret(crm_get_dms_tiles).

- `crimePrivate` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x3bd0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x3bd0-0x4af8 (3880 bytes).
  It occupies 3880 bytes.
  The `lw` at 0x3bd8 loads 4 bytes from a0 (arg0 at entry) +0x18.
  4 such `lbu` accesses load 1 byte from [a0+24] +0x98, including `lbu` at 0x3d40, `lbu` at 0x3e28, `lbu` at 0x4024.
  8 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4c, including `lw` at 0x3dbc, `lw` at 0x3f68, `lw` at 0x3fa0.
  3 such `lw` accesses load 4 bytes from [a1+76] +0x18, including `lw` at 0x3dc8, `lw` at 0x3fac, `lw` at 0x40ac.
  4 such `lw` accesses load 4 bytes from [a0+24] +0x7c, including `lw` at 0x3e34, `lw` at 0x3eb4, `lw` at 0x4378.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x3e54, `lw` at 0x42b0, `lw` at 0x42c8.
  3 such `lw` accesses load 4 bytes from [a0+8] +0x4, including `lw` at 0x3e58, `lw` at 0x42b4, `lw` at 0x42cc.
  3 such `lw` accesses load 4 bytes from [a0+24] +0x80, including `lw` at 0x3ec0, `lw` at 0x4480, `lw` at 0x451c.
  The `sw` at 0x3f24 stores 4 bytes to [a1+76] +0x18.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x409c, `lw` at 0x4680.
  The `lw` at 0x40f4 loads 4 bytes from [a0+24] +0x138.
  The `sw` at 0x40fc stores 4 bytes to [a0+24] +0x138.
  The `sw` at 0x4108 stores 4 bytes to ret(kern_malloc) +0x8.
  2 such `lw` accesses load 4 bytes from [a1+76] +0x20, including `lw` at 0x4320, `lw` at 0x49d4.
  The `lbu` at 0x4384 loads 1 byte from [[a0+24]+124] +0x2e.
  2 such `lw` accesses load 4 bytes from [a0+24] +0x88, including `lw` at 0x43d0, `lw` at 0x43e4.
  3 such `lw` accesses load 4 bytes from [a0+24] +0x84, including `lw` at 0x43f8, `lw` at 0x4740, `lw` at 0x4a60.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x440c, `sw` at 0x4a7c, `sw` at 0x4a94.
  The `sb` at 0x4490 stores 1 byte to [[a0+24]+124] +0x2e.
  The `lw` at 0x449c loads 4 bytes from ret(kern_malloc) +0x8.
  2 such `lw` accesses load 4 bytes from [a0+24] +0x1c8, including `lw` at 0x44b8, `lw` at 0x4830.
  The `sw` at 0x44c0 stores 4 bytes to ret(kern_malloc) +0x0.
  The `sw` at 0x44c4 stores 4 bytes to [[a0+24]+456] +0x4.
  The `sw` at 0x44c8 stores 4 bytes to [a0+24] +0x1c8.
  The `lh` at 0x4554 loads 2 bytes from table(sym(crimeBoards)) +0x22.
  The `lhu` at 0x4568 loads 2 bytes from ([[a0+24]+124] + one of 0xe8, 0x16a) +0x0.
  The `lw` at 0x4600 loads 4 bytes from [a0+24] +0xa0.
  The `lw` at 0x4604 loads 4 bytes from [a0+24] +0x9c.
  The `sb` at 0x460c stores 1 byte to [a0+24] +0x9a.
  The `sb` at 0x461c stores 1 byte to [a0+24] +0x9b.
  2 such `lw` accesses load 4 bytes from [a1+76] +0xc, including `lw` at 0x4664, `lw` at 0x4818.
  The `sw` at 0x4690 stores 4 bytes to [a1+8] +0x1f0.
  The `lw` at 0x469c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `sw` at 0x46a4 stores 4 bytes to a0 (arg0 at entry) +0x4.
  2 such `sw` accesses store 4 bytes to [a0+24] +0x1cc, including `sw` at 0x4750, `sw` at 0x4970.
  2 such `sw` accesses store 4 bytes to [a0+24] +0x88, including `sw` at 0x475c, `sw` at 0x4978.
  The `sw` at 0x47b8 stores 4 bytes to a4 (arg4 at entry) +0x0.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x47f0, `lw` at 0x49b4, `lw` at 0x49c0.
  2 such `lw` accesses load 4 bytes from [a0+24] +0x78, including `lw` at 0x48a4, `lw` at 0x4a10.
  The `sw` at 0x497c stores 4 bytes to [a1+76] +0x1c.
  The `lw` at 0x4980 loads 4 bytes from [a0+24] +0x4.
  The `sw` at 0x4a38 stores 4 bytes to [[a0+24]+120] +0x4008.
  The `sw` at 0x4a88 stores 4 bytes to [a1+76] +0x20.
  The `jal` at 0x3cfc calls copyin with a0=a3 at entry (arg3), a1=sp-144, a2=0x8, a3=a3 at entry (arg3), a6=0x55f5, a7=0x0.
  The `jal` at 0x3dd4 calls gfxdd_lookup with a0=[[a1+76]+24], a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=0x0.
  The `jal` at 0x3df0 calls copyin with a0=a3 at entry (arg3), a1=sp-1040, a2=0x24, a3=a3 at entry (arg3), a7=0x0.
  The `jal` at 0x3e84 calls copyin with a0=a3 at entry (arg3), a1=sp-92, a2=0x4, a3=a3 at entry (arg3), a7=0x0.
  The `jal` at 0x3edc calls kern_malloc with a0=0x304, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x55f5, a7=0x0.
  The `jal` at 0x3ef0 calls copyin with a0=a3 at entry (arg3), a1=ret(kern_malloc), a2=0x304, a3=?.
  The `jal` at 0x3f00 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x3f10 calls crmUnmapPages with a0=[a1+76]+24, a1=?, a2=?, a3=?.
  The `jal` at 0x3f40 calls copyin with a0=a3 at entry (arg3), a1=sp-576, a2=0xc, a3=?.
  The `jal` at 0x3f88 calls copyin with a0=a3 at entry (arg3), a1=sp-88, a2=0xc, a3=a3 at entry (arg3), a7=0x0.
  The `jal` at 0x3fb8 calls gfxdd_lookup with a0=[[a1+76]+24], a1=a1 at entry (arg1), a2=[a1+76]+24, a3=a3 at entry (arg3), a7=0x0.
  The `jal` at 0x3fd0 calls crimeFrameInfo with a0=[a0+24], a1=a1 at entry (arg1), a2=sp-1000, a3=?, a7=0x0.
  The `jal` at 0x3fe0 calls copyout with a0=sp-1000, a1=a3 at entry (arg3), a2=0x20, a3=?.
  The `jal` at 0x4000 calls copyin with a0=a3 at entry (arg3), a1=sp-200, a2=0x8, a3=a3 at entry (arg3), a7=0x0.
  The `jal` at 0x4050 calls copyin with a0=a3 at entry (arg3), a1=sp-616, a2=0x10, a3=?, a7=0x0.
  The `jal` at 0x4078 calls copyin with a0=a3 at entry (arg3), a1=sp-256, a2=0x8, a3=a3 at entry (arg3).
  The `jal` at 0x4098 calls crmMapPages with a0=[a1+8], a1=0x288, a2=[a1+76]+24, a3=?.
  The `jal` at 0x40a8 calls ddv_getaddr with a0=[[a1+76]+24], a1=?, a2=?, a3=?.
  The `jal` at 0x40bc calls copyout with a0=sp-96, a1=a3 at entry (arg3), a2=0x4, a3=?.
  The `jal` at 0x40dc calls kern_malloc with a0=0x220, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x40ec calls bzero with a0=ret(kern_malloc), a1=0x220, a2=?, a3=?.
  The `jal` at 0x4110 calls copyout with a0=sp-560, a1=a3 at entry (arg3), a2=0x4, a3=?.
  The `jal` at 0x4120 calls kern_free with a0=ret(kern_malloc), a1=0x1, a2=?, a3=?.
  The `jal` at 0x4140 calls copyin with a0=a3 at entry (arg3), a1=sp-240, a2=0x14, a3=a3 at entry (arg3), a7=0x0.
  The `jal` at 0x4178 calls copyin with a0=a3 at entry (arg3), a1=sp-960, a2=0x38, a3=?, a7=0x0.
  The `jal` at 0x4198 calls copyin with a0=a3 at entry (arg3), a1=sp-584, a2=0x8, a3=?.
  The `jal` at 0x41b8 calls copyin with a0=a3 at entry (arg3), a1=sp-904, a2=0x102, a3=?, a7=0x0.
  The `jal` at 0x41d8 calls copyin with a0=a3 at entry (arg3), a1=sp-552, a2=0x118, a3=a3 at entry (arg3).
  The `jal` at 0x41f8 calls copyin with a0=a3 at entry (arg3), a1=sp-136, a2=0x28, a3=a3 at entry (arg3), a7=0x0.
  The `jal` at 0x423c calls copyin with a0=a3 at entry (arg3), a1=sp-632, a2=0x10, a3=0x560b, a7=0x0.
  The `jal` at 0x425c calls copyin with a0=a3 at entry (arg3), a1=sp-968, a2=0x4, a3=?, a7=0x0.
  The `jal` at 0x427c calls copyin with a0=a3 at entry (arg3), a1=sp-192, a2=0x30, a3=a3 at entry (arg3), a6=0x55f5, a7=0x0.
  The `jal` at 0x42e0 calls crimeSetGammaRamp with a0=a0 at entry (arg0), a1=ret(kern_malloc), a2=?, a3=?.
  The `jal` at 0x42ec calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x4304 calls copyin with a0=a3 at entry (arg3), a1=sp-600, a2=0xc, a3=?.
  The `jal` at 0x4344 calls copyout with a0=sym(crm_tileusage), a1=a3 at entry (arg3), a2=0x14, a3=0x560f, a7=0x0.
  The `jal` at 0x4360 calls copyin with a0=a3 at entry (arg3), a1=sp-640, a2=0x4, a3=?, a7=0x0.
  The `jal` at 0x43c0 calls crmDefineTex with a0=[a0+24], a1=a1 at entry (arg1), a2=sp-1040, a3=?.
  The `jal` at 0x4414 calls crmUnmapChunk with a0=sym(crmGbeTables), a1=[a1+76], a2=a2 at entry (arg2), a3=[[a0+24]+136], a7=[[a0+8]+4].
  The `jal` at 0x4430 calls copyin with a0=a3 at entry (arg3), a1=sp-272, a2=0x10, a3=a3 at entry (arg3).
  The `jal` at 0x4448 calls crmDeallocTex with a0=a1 at entry (arg1), a1=a3 at entry (arg3), a2=a2 at entry (arg2), a3=0x5602.
  The `jal` at 0x4460 calls copyin with a0=a3 at entry (arg3), a1=sp-964, a2=0x4, a3=?, a4=0x5651, a7=0x0.
  The `jal` at 0x447c calls crime_i2cFpProbe with a0=[[a0+24]+128], a1=0x1, a2=a2 at entry (arg2), a3=0x560f, a4=[[a0+24]+124], a5=[[a0+24]+128], a7=0x0.
  The `jal` at 0x44a0 calls init_sema with a0=ret(kern_malloc)+16, a1=0x1, a2=sym(.rodata)+512, a3=[ret(kern_malloc)+8].
  The `jal` at 0x44b0 calls mutex_lock with a0=[a0+24]+476, a1=0x19, a2=?, a3=?.
  The `jal` at 0x44cc calls mutex_unlock with a0=[a0+24]+476, a1=?, a2=?, a3=?.
  The `jal` at 0x44e0 calls copyin with a0=a3 at entry (arg3), a1=sp-248, a2=0x8, a3=a3 at entry (arg3), a7=0x0.
  The `jal` at 0x4520 calls crime_i2cProbe with a0=[[a0+24]+128], a1=[[a0+24]+124], a2=?, a3=?, a4=0x1.
  The `jal` at 0x452c calls crime_validate_ddc_data with a0=[[a0+24]+124], a1=?, a2=?, a3=?.
  The `jal` at 0x4570 calls copyout with a0=sp-584, a1=a3 at entry (arg3), a2=0x8, a3=?.
  The `jal` at 0x4594 calls crime_i2cfp_command with a0=[a0+24], a1=sp-88, a2=?, a3=?.
  The `jal` at 0x45b4 calls copyout with a0=sp-88, a1=a3 at entry (arg3), a2=0xc, a3=?, a7=[sym(crmFpPrbState)].
  The `jal` at 0x45d4 calls crime_load_fbtlb with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[a0+24], a3=sp-144.
  The `jal` at 0x45e8 calls crimeSetDisplayMode with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4618 calls crimePositionCursor with a0=[a0+24], a1=[[a0+24]+156], a2=[[a0+24]+160], a3=?.
  The `jal` at 0x4628 calls crimeClosePbuf with a0=[a0+24], a1=sp-256, a2=?, a3=?.
  The `jal` at 0x4638 calls RRM_CheckValidFault with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4660 calls crm_enablesz with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[a1+76], a3=[[a1+76]+12].
  The `jal` at 0x4694 calls crimeInitSpecialDDRN with a0=[a1+76], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?, a4=0x5651, a5=[sym(.sdata)+16], a7=0x0.
  The `jal` at 0x46a8 calls crmSwapBufd with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x46d4 calls crime_load_linear_tlb with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[a0+24], a3=sp-576.
  The `jal` at 0x46e4 calls crimeOpenPbuf with a0=a1 at entry (arg1), a1=sp-240, a2=?, a3=?.
  The `jal` at 0x46f4 calls crmInitialize with a0=[a0+24], a1=sp-960, a2=?, a3=?.
  The `jal` at 0x4708 calls crimeUpdateBackTiles with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-904, a3=?.
  The `jal` at 0x4718 calls crimeValidateDDClip with a0=a0 at entry (arg0), a1=sp-552, a2=?, a3=?.
  The `jal` at 0x4728 calls crimePixelDma with a0=a0 at entry (arg0), a1=sp-136, a2=?, a3=?.
  The `jal` at 0x473c calls crmMapPages with a0=[[a0+24]+132], a1=0x600, a2=sp-216, a3=a3 at entry (arg3), a6=[[a0+8]+4], a7=0x0.
  The `jal` at 0x4754 calls ddv_getaddr with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4760 calls ddv_getaddr with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4774 calls copyout with a0=sp-212, a1=a3 at entry (arg3), a2=0x4, a3=?.
  The `jal` at 0x4784 calls crmMapChunk with a0=sym(crmGbeTables), a1=sp-208, a2=?, a3=?.
  The `jal` at 0x47a0 calls crime_i2c_cmd with a0=[a0+24], a1=sp-632, a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x47bc calls crimeBlankscreen with a0=[a0+24], a1=?, a2=?, a3=?.
  The `jal` at 0x47cc calls crimeLoadTimingTable with a0=[a0+24], a1=sp-192, a2=?, a3=?.
  The `jal` at 0x4814 calls crm_enableovl with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[a1+76], a3=[[a1+76]+12].
  The `jal` at 0x4828 calls mutex_lock with a0=[a0+24]+476, a1=0x19, a2=?, a3=?.
  The `jal` at 0x4854 calls copyout with a0=sp-248, a1=a3 at entry (arg3), a2=0x8, a3=?.
  The `jal` at 0x4870 calls copyout with a0=([[a0+24]+124] + one of 0x64, 0xea), a1=?, a2=0x80, a3=?, a4=0x1, a5=[table(sym(crimeBoards))+34]:2, a6=0x2.
  The `jal` at 0x48a0 calls crime_clear_buffer with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[[a0+24]+120], a3=sp-600.
  The `jal` at 0x48c8 calls copyout with a0=sp-600, a1=a3 at entry (arg3), a2=0xc, a3=?.
  The `jal` at 0x4900 calls crimeUnSchedSwapBuf with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x4930 calls crmAllocTex with a0=[a0+24], a1=[a1+76], a2=sp-272, a3=0x0.
  The `jal` at 0x4948 calls copyout with a0=sp-272, a1=a3 at entry (arg3), a2=0x10, a3=?.
  The `jal` at 0x4960 calls crmUnmapPages with a0=[a0+24]+460, a1=?, a2=?, a3=?.
  The `jal` at 0x49e8 calls mutex_unlock with a0=[a0+24]+476, a1=?, a2=?, a3=?.
  The `jal` at 0x4a00 calls mutex_unlock with a0=[a0+24]+476, a1=?, a2=?, a3=?.
  The `jal` at 0x4a14 calls RRM_CheckValidFault with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4a30 calls crmLoadTexTlb with a0=[a1+76], a1=?, a2=?, a3=?.
  The `jal` at 0x4a98 calls mutex_unlock with a0=[a0+24]+476, a1=?, a2=?, a3=?.
  The `jal` at 0x4aa8 calls crmFindFreeDidTbl with a0=[a0+24], a1=?, a2=0x8, a3=?, a7=0x1.
  The `jal` at 0x4ad0 calls cmn_err with a0=0x1, a1=sym(.rodata)+440, a2=a2 at entry (arg2), a3=?, a7=0x0.
  The `jal` at 0x4ae8 calls cmn_err with a0=0x1, a1=sym(.rodata)+480, a2=a2 at entry (arg2), a3=?.
  The `bne` branch at 0x3c04 targets 0x3c48, is taken when a2 < 0x5603 (unsigned), and falls through when a2 >= 0x5603 (unsigned).
  The `beq` branch at 0x3c10 targets 0x3c70, is taken when a2 >= 0x5604 (unsigned), and falls through when a2 < 0x5604 (unsigned).
  The `bne` branch at 0x3c18 targets 0x3dec, is taken when a1 != 0, and falls through when a1 == 0.
  The `bne` branch at 0x3c4c targets 0x3cc4, is taken when a2 < 0x55f8 (unsigned), and falls through when a2 >= 0x55f8 (unsigned).
  The `beq` branch at 0x3c58 targets 0x3d58, is taken when a2 >= 0x55f9 (unsigned), and falls through when a2 < 0x55f9 (unsigned).
  The `bne` branch at 0x3c60 targets 0x3dbc, is taken when s0(=a1) != 0, and falls through when s0(=a1) == 0.
  The `beq` branch at 0x3c68 targets 0x3c24 and is always taken.
  The `bne` branch at 0x3c74 targets 0x3d14, is taken when a2 < 0x560c (unsigned), and falls through when a2 >= 0x560c (unsigned).
  The `bne` branch at 0x3c80 targets 0x3fd0, is taken when a2 < 0x560d (unsigned), and falls through when a2 >= 0x560d (unsigned).
  The `bne` branch at 0x3c8c targets 0x3e9c, is taken when a2 < 0x5610 (unsigned), and falls through when a2 >= 0x5610 (unsigned).
  The `bne` branch at 0x3c98 targets 0x4254, is taken when a2 < 0x5611 (unsigned), and falls through when a2 >= 0x5611 (unsigned).
  The `bne` branch at 0x3ca0 targets 0x4ac0, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x3cac targets 0x4294, is taken when a2 >= 0x5651 (unsigned), and falls through when a2 < 0x5651 (unsigned).
  The `bne` branch at 0x3cb4 targets 0x431c, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x3cbc targets 0x3c24 and is always taken.
  The `bne` branch at 0x3cc4 targets 0x3d90, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `bne` branch at 0x3cd0 targets 0x3ff8, is taken when a2 < 0x55f5 (unsigned), and falls through when a2 >= 0x55f5 (unsigned).
  The `bne` branch at 0x3cd8 targets 0x3ed4, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `bne` branch at 0x3ce4 targets 0x4274, is taken when a2 < 0x55f7 (unsigned), and falls through when a2 >= 0x55f7 (unsigned).
  The `bne` branch at 0x3cec targets 0x4ae4, is taken when a2 != ra(=0x55f7), and falls through when a2 == ra(=0x55f7).
  The `beq` branch at 0x3d04 targets 0x45cc, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x3d0c targets 0x3c24 and is always taken.
  The `bne` branch at 0x3d14 targets 0x3e08, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0x3d1c targets 0x41b0, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `bne` branch at 0x3d24 targets 0x403c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `bne` branch at 0x3d2c targets 0x435c, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x3d38 targets 0x4ae4, is taken when a2 != a3(=0x560b), and falls through when a2 == a3(=0x560b).
  The `bne` branch at 0x3d48 targets 0x4234, is taken when (a4(=[[a0+24]+152]:1) & 0x1) != 0, and falls through when (a4(=[[a0+24]+152]:1) & 0x1) == 0.
  The `beq` branch at 0x3d50 targets 0x3c24 and is always taken.
  The `bne` branch at 0x3d58 targets 0x3e40, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bne` branch at 0x3d64 targets 0x41d0, is taken when a2 < 0x5600 (unsigned), and falls through when a2 >= 0x5600 (unsigned).
  The `bne` branch at 0x3d6c targets 0x4068, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x3d78 targets 0x4210, is taken when a2 >= 0x5602 (unsigned), and falls through when a2 < 0x5602 (unsigned).
  The `bne` branch at 0x3d80 targets 0x442c, is taken when s0(=a1) != 0, and falls through when s0(=a1) == 0.
  The `beq` branch at 0x3d88 targets 0x3c24 and is always taken.
  The `bne` branch at 0x3d90 targets 0x3e6c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x3d9c targets 0x41f0, is taken when a2 < 0x55f3 (unsigned), and falls through when a2 >= 0x55f3 (unsigned).
  The `bne` branch at 0x3da4 targets 0x4ae4, is taken when a2 != t2(=0x55f3), and falls through when a2 == t2(=0x55f3).
  The `bne` branch at 0x3dac targets 0x3fa0, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x3db4 targets 0x3c24 and is always taken.
  The `beq` branch at 0x3dc0 targets 0x422c, is taken when s1(=[a1+76]) == 0, and falls through when s1(=[a1+76]) != 0.
  The `beq` branch at 0x3dcc targets 0x3f10, is taken when a0(=[[a1+76]+24]) == 0, and falls through when a0(=[[a1+76]+24]) != 0.
  The `bne` branch at 0x3ddc targets 0x3f10, is taken when v0(=ret(gfxdd_lookup)) != 0, and falls through when v0(=ret(gfxdd_lookup)) == 0.
  The `beq` branch at 0x3de4 targets 0x3c24 and is always taken.
  The `beq` branch at 0x3df8 targets 0x43bc, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x3e00 targets 0x3c24 and is always taken.
  The `bne` branch at 0x3e0c targets 0x3f28, is taken when a2 < 0x5606 (unsigned), and falls through when a2 >= 0x5606 (unsigned).
  The `bne` branch at 0x3e18 targets 0x42fc, is taken when a2 < 0x5607 (unsigned), and falls through when a2 >= 0x5607 (unsigned).
  The `bne` branch at 0x3e20 targets 0x4ae4, is taken when a2 != t8(=0x5607), and falls through when a2 == t8(=0x5607).
  The `bne` branch at 0x3e30 targets 0x4190, is taken when (t9(=[[a0+24]+152]:1) & 0x1) != 0, and falls through when (t9(=[[a0+24]+152]:1) & 0x1) == 0.
  The `beq` branch at 0x3e38 targets 0x3c24 and is always taken.
  The `bne` branch at 0x3e40 targets 0x3f58, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x3e4c targets 0x4130, is taken when a2 >= 0x55fe (unsigned), and falls through when a2 < 0x55fe (unsigned).
  The `beq` branch at 0x3e5c targets 0x44dc, is taken when at(=[[a0+8]+4]) == s3(=a0), and falls through when at(=[[a0+8]+4]) != s3(=a0).
  The `beq` branch at 0x3e64 targets 0x3c24 and is always taken.
  The `bne` branch at 0x3e6c targets 0x3f7c, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0x3e74 targets 0x4ae4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x3e8c targets 0x4600, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x3e94 targets 0x3c24 and is always taken.
  The `bne` branch at 0x3e9c targets 0x4018, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `bne` branch at 0x3ea4 targets 0x4338, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x3eac targets 0x4ae4, is taken when a2 != a3(=0x560f), and falls through when a2 == a3(=0x560f).
  The `beq` branch at 0x3eb8 targets 0x3ecc, is taken when a4(=[[a0+24]+124]) == 0, and falls through when a4(=[[a0+24]+124]) != 0.
  The `bne` branch at 0x3ec4 targets 0x4478, is taken when a5(=[[a0+24]+128]) != 0, and falls through when a5(=[[a0+24]+128]) == 0.
  The `beq` branch at 0x3ecc targets 0x3c24 and is always taken.
  The `bne` branch at 0x3ed4 targets 0x4ae4, is taken when a2 != a6(=0x55f5), and falls through when a2 == a6(=0x55f5).
  The `beq` branch at 0x3ef8 targets 0x42e0, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x3f08 targets 0x3c24 and is always taken.
  The `bne` branch at 0x3f18 targets 0x3c24, is taken when v0(=ret(crmUnmapPages)) != 0, and falls through when v0(=ret(crmUnmapPages)) == 0.
  The `beq` branch at 0x3f20 targets 0x3c24 and is always taken.
  The `bne` branch at 0x3f28 targets 0x40d4, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x3f30 targets 0x4ae4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x3f48 targets 0x46cc, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x3f50 targets 0x3c24 and is always taken.
  The `bne` branch at 0x3f58 targets 0x4158, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x3f60 targets 0x4ae4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x3f6c targets 0x42b0, is taken when t1(=[a1+76]) != 0, and falls through when t1(=[a1+76]) == 0.
  The `beq` branch at 0x3f74 targets 0x3c24 and is always taken.
  The `bne` branch at 0x3f7c targets 0x4ae0, is taken when a2 != t2(=0x5213), and falls through when a2 == t2(=0x5213).
  The `beq` branch at 0x3f90 targets 0x4378, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x3f98 targets 0x3c24 and is always taken.
  The `beq` branch at 0x3fa4 targets 0x4398, is taken when s4(=[a1+76]) == 0, and falls through when s4(=[a1+76]) != 0.
  The `beq` branch at 0x3fb0 targets 0x4094, is taken when a0(=[[a1+76]+24]) == 0, and falls through when a0(=[[a1+76]+24]) != 0.
  The `bne` branch at 0x3fc0 targets 0x4094, is taken when v0(=ret(gfxdd_lookup)) != 0, and falls through when v0(=ret(gfxdd_lookup)) == 0.
  The `beq` branch at 0x3fc8 targets 0x3c24 and is always taken.
  The `beq` branch at 0x3fe8 targets 0x43a0, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x3ff0 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4008 targets 0x45e4, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x4010 targets 0x3c24 and is always taken.
  The `bne` branch at 0x401c targets 0x4ae4, is taken when a2 != t3(=0x560d), and falls through when a2 == t3(=0x560d).
  The `bne` branch at 0x402c targets 0x4174, is taken when (t8(=[[a0+24]+152]:1) & 0x1) != 0, and falls through when (t8(=[[a0+24]+152]:1) & 0x1) == 0.
  The `beq` branch at 0x4034 targets 0x3c24 and is always taken.
  The `bne` branch at 0x4040 targets 0x4ae4, is taken when a2 != t9(=0x5609), and falls through when a2 == t9(=0x5609).
  The `beq` branch at 0x4058 targets 0x43a8, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x4060 targets 0x3c24 and is always taken.
  The `bne` branch at 0x4068 targets 0x4ae4, is taken when a2 != ra(=0x5600), and falls through when a2 == ra(=0x5600).
  The `beq` branch at 0x4080 targets 0x4628, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x4088 targets 0x3c24 and is always taken.
  The `bne` branch at 0x40a0 targets 0x3c24, is taken when v0(=ret(crmMapPages)) != 0, and falls through when v0(=ret(crmMapPages)) == 0.
  The `beq` branch at 0x40c4 targets 0x3c28, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x40cc targets 0x3c24 and is always taken.
  The `bne` branch at 0x40d4 targets 0x4ae4, is taken when a2 != at(=0x5604), and falls through when a2 == at(=0x5604).
  The `beq` branch at 0x4118 targets 0x4494, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x4128 targets 0x3c24 and is always taken.
  The `bne` branch at 0x4130 targets 0x4ae4, is taken when a2 != v1(=0x55fe), and falls through when a2 == v1(=0x55fe).
  The `beq` branch at 0x4148 targets 0x46e4, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x4150 targets 0x3c24 and is always taken.
  The `bne` branch at 0x4158 targets 0x4ae4, is taken when a2 != a0(=0x55f9), and falls through when a2 == a0(=0x55f9).
  The `bne` branch at 0x4164 targets 0x42c8, is taken when a1(=[a1+76]) != 0, and falls through when a1(=[a1+76]) == 0.
  The `beq` branch at 0x416c targets 0x3c24 and is always taken.
  The `beq` branch at 0x4180 targets 0x46f4, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x4188 targets 0x3c24 and is always taken.
  The `beq` branch at 0x41a0 targets 0x44f8, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x41a8 targets 0x3c24 and is always taken.
  The `beq` branch at 0x41c0 targets 0x4704, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x41c8 targets 0x3c24 and is always taken.
  The `beq` branch at 0x41e0 targets 0x4718, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x41e8 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4200 targets 0x4728, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x4208 targets 0x3c24 and is always taken.
  The `bne` branch at 0x4214 targets 0x4ae4, is taken when a2 != a3(=0x5602), and falls through when a2 == a3(=0x5602).
  The `bne` branch at 0x421c targets 0x4448, is taken when s0(=a1) != 0, and falls through when s0(=a1) == 0.
  The `beq` branch at 0x4224 targets 0x3c24 and is always taken.
  The `beq` branch at 0x422c targets 0x3c24 and is always taken.
  The `beq` branch at 0x4244 targets 0x479c, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x424c targets 0x3c24 and is always taken.
  The `beq` branch at 0x4264 targets 0x47bc, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x426c targets 0x3c24 and is always taken.
  The `beq` branch at 0x4284 targets 0x47cc, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x428c targets 0x3c24 and is always taken.
  The `bne` branch at 0x4294 targets 0x4ae4, is taken when a2 != a4(=0x5651), and falls through when a2 == a4(=0x5651).
  The `beq` branch at 0x42a0 targets 0x4680, is taken when a5(=[sym(.sdata)+16]) == 0, and falls through when a5(=[sym(.sdata)+16]) != 0.
  The `beq` branch at 0x42a8 targets 0x3c28 and is always taken.
  The `beq` branch at 0x42b8 targets 0x43d0, is taken when a6(=[[a0+8]+4]) == s3(=a0), and falls through when a6(=[[a0+8]+4]) != s3(=a0).
  The `beq` branch at 0x42c0 targets 0x3c24 and is always taken.
  The `beq` branch at 0x42d0 targets 0x43e4, is taken when a7(=[[a0+8]+4]) == s3(=a0), and falls through when a7(=[[a0+8]+4]) != s3(=a0).
  The `beq` branch at 0x42d8 targets 0x3c24 and is always taken.
  The `beq` branch at 0x42f4 targets 0x3c28 and is always taken.
  The `beq` branch at 0x430c targets 0x4898, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x4314 targets 0x3c24 and is always taken.
  The `bne` branch at 0x4328 targets 0x4458, is taken when t0(=[[a1+76]+32]) != 0, and falls through when t0(=[[a1+76]+32]) == 0.
  The `beq` branch at 0x4330 targets 0x3c24 and is always taken.
  The `beq` branch at 0x434c targets 0x46bc, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x4354 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4368 targets 0x48fc, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x4370 targets 0x3c24 and is always taken.
  The `beq` branch at 0x437c targets 0x4390, is taken when v0(=[[a0+24]+124]) == 0, and falls through when v0(=[[a0+24]+124]) != 0.
  The `bne` branch at 0x4388 targets 0x4588, is taken when a1(=[[[a0+24]+124]+46]:1) != 0, and falls through when a1(=[[[a0+24]+124]+46]:1) == 0.
  The `beq` branch at 0x4390 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4398 targets 0x3c24 and is always taken.
  The `beq` branch at 0x43a0 targets 0x3c24 and is always taken.
  The `bne` branch at 0x43ac targets 0x4638, is taken when s2(=[a1+76]) != 0, and falls through when s2(=[a1+76]) == 0.
  The `beq` branch at 0x43b4 targets 0x3c24 and is always taken.
  The `beq` branch at 0x43c8 targets 0x3c24 and is always taken.
  The `beq` branch at 0x43d4 targets 0x4738, is taken when a2(=[[a0+24]+136]) == 0, and falls through when a2(=[[a0+24]+136]) != 0.
  The `beq` branch at 0x43dc targets 0x3c24 and is always taken.
  The `beq` branch at 0x43e8 targets 0x46c4, is taken when a3(=[[a0+24]+136]) == 0, and falls through when a3(=[[a0+24]+136]) != 0.
  The `bne` branch at 0x4408 targets 0x43f4, is taken when a0(?) < 0x4 (signed), and falls through when a0(?) >= 0x4 (signed).
  The `beq` branch at 0x441c targets 0x4960, is taken when v0(=ret(crmUnmapChunk)) == 0, and falls through when v0(=ret(crmUnmapChunk)) != 0.
  The `beq` branch at 0x4424 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4438 targets 0x4928, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x4440 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4450 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4468 targets 0x47dc, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x4470 targets 0x3c24 and is always taken.
  The `beq` branch at 0x448c targets 0x3c24 and is always taken.
  The `beq` branch at 0x44bc targets 0x44c8, is taken when v0(=[[a0+24]+456]) == 0, and falls through when v0(=[[a0+24]+456]) != 0.
  The `beq` branch at 0x44d4 targets 0x3c24 and is always taken.
  The `beq` branch at 0x44e8 targets 0x4844, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x44f0 targets 0x3c24 and is always taken.
  The `blez` branch at 0x44f8 targets 0x4888, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0x4500 targets 0x48ec, is taken when v0(=[sym(crm_dc_board_installed)]) == 0, and falls through when v0(=[sym(crm_dc_board_installed)]) != 0.
  The `beq` branch at 0x4510 targets 0x4538, is taken when (a3(=[[a0+24]+152]:1) & 0x4) == 0, and falls through when (a3(=[[a0+24]+152]:1) & 0x4) != 0.
  The `beq` branch at 0x453c targets 0x48e0, is taken when s0(?) == a4(=0x1), and falls through when s0(?) != a4(=0x1).
  The `beq` branch at 0x455c targets 0x486c, is taken when a5(=[table(sym(crimeBoards))+34]:2) == a6(=0x2), and falls through when a5(=[table(sym(crimeBoards))+34]:2) != a6(=0x2).
  The `beq` branch at 0x4578 targets 0x4910, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x4580 targets 0x3c24 and is always taken.
  The `beq` branch at 0x45a0 targets 0x48f4, is taken when a7(=[sym(crmFpPrbState)]) == s4(=0x1), and falls through when a7(=[sym(crmFpPrbState)]) != s4(=0x1).
  The `bne` branch at 0x45a8 targets 0x3c24, is taken when v0(=ret(crime_i2cfp_command)) != 0, and falls through when v0(=ret(crime_i2cfp_command)) == 0.
  The `beq` branch at 0x45bc targets 0x3c28, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x45c4 targets 0x3c24 and is always taken.
  The `beq` branch at 0x45dc targets 0x3c24 and is always taken.
  The `bltz` branch at 0x45f0 targets 0x4918, is taken when v0(=ret(crimeSetDisplayMode)) < 0 (signed), and falls through when v0(=ret(crimeSetDisplayMode)) >= 0 (signed).
  The `beq` branch at 0x45f8 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4620 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4630 targets 0x3c24 and is always taken.
  The `bltz` branch at 0x4640 targets 0x4920, is taken when v0(=ret(RRM_CheckValidFault)) < 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) >= 0 (signed).
  The `beq` branch at 0x464c targets 0x4804, is taken when (v0(?) & 0x1) == 0, and falls through when (v0(?) & 0x1) != 0.
  The `beq` branch at 0x4668 targets 0x499c, is taken when v0(=ret(crm_enablesz)) == 0, and falls through when v0(=ret(crm_enablesz)) != 0.
  The `beq` branch at 0x4670 targets 0x4824, is taken when a0(=ret(crm_enablesz)) == 0, and falls through when a0(=ret(crm_enablesz)) != 0.
  The `beq` branch at 0x4678 targets 0x3c24 and is always taken.
  The `beq` branch at 0x46b4 targets 0x3c24 and is always taken.
  The `beq` branch at 0x46bc targets 0x3c24 and is always taken.
  The `beq` branch at 0x46c4 targets 0x3c24 and is always taken.
  The `beq` branch at 0x46dc targets 0x3c24 and is always taken.
  The `beq` branch at 0x46ec targets 0x3c24 and is always taken.
  The `beq` branch at 0x46fc targets 0x3c24 and is always taken.
  The `beq` branch at 0x4710 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4720 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4730 targets 0x3c24 and is always taken.
  The `bne` branch at 0x4744 targets 0x3c24, is taken when v0(=ret(crmMapPages)) != 0, and falls through when v0(=ret(crmMapPages)) == 0.
  The `beq` branch at 0x478c targets 0x4a48, is taken when v0(=ret(crmMapChunk)) == 0, and falls through when v0(=ret(crmMapChunk)) != 0.
  The `beq` branch at 0x4794 targets 0x3c24 and is always taken.
  The `bltz` branch at 0x47a8 targets 0x4994, is taken when v0(=ret(crime_i2c_cmd)) < 0 (signed), and falls through when v0(=ret(crime_i2c_cmd)) >= 0 (signed).
  The `beq` branch at 0x47b4 targets 0x3c24 and is always taken.
  The `beq` branch at 0x47c4 targets 0x3c24 and is always taken.
  The `beq` branch at 0x47d4 targets 0x3c24 and is always taken.
  The `beq` branch at 0x47e0 targets 0x47fc, is taken when v0(?) >= 0x80 (signed), and falls through when v0(?) < 0x80 (signed).
  The `bne` branch at 0x47f4 targets 0x497c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x47fc targets 0x3c24 and is always taken.
  The `beq` branch at 0x4804 targets 0x4820, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x481c targets 0x4678, is taken when v0(=ret(crm_enableovl)) != 0, and falls through when v0(=ret(crm_enableovl)) == 0.
  The `beq` branch at 0x4834 targets 0x4a00, is taken when v0(=[[a0+24]+456]) == 0, and falls through when v0(=[[a0+24]+456]) != 0.
  The `beq` branch at 0x483c targets 0x49c0 and is always taken.
  The `beq` branch at 0x4848 targets 0x4aa8, is taken when a6(?) == a7(=0x1), and falls through when a6(?) != a7(=0x1).
  The `beq` branch at 0x485c targets 0x49f8, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x4864 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4878 targets 0x4564, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x4880 targets 0x3c24 and is always taken.
  The `bne` branch at 0x4888 targets 0x4508, is taken when v0(=[sym(crm_dc_board_installed)]) != 0, and falls through when v0(=[sym(crm_dc_board_installed)]) == 0.
  The `beq` branch at 0x4890 targets 0x4508 and is always taken.
  The `bne` branch at 0x48ac targets 0x3c24, is taken when v0(=ret(crime_clear_buffer)) != t0(=-0x1), and falls through when v0(=ret(crime_clear_buffer)) == t0(=-0x1).
  The `beq` branch at 0x48d0 targets 0x4ab8, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x48d8 targets 0x3c24 and is always taken.
  The `beq` branch at 0x48e4 targets 0x4544 and is always taken.
  The `beq` branch at 0x48ec targets 0x3c24 and is always taken.
  The `beq` branch at 0x48f4 targets 0x45a8 and is always taken.
  The `beq` branch at 0x4908 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4910 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4918 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4920 targets 0x3c24 and is always taken.
  The `bne` branch at 0x4938 targets 0x3c24, is taken when v0(=ret(crmAllocTex)) != 0, and falls through when v0(=ret(crmAllocTex)) == 0.
  The `beq` branch at 0x4950 targets 0x3c28, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x4958 targets 0x3c24 and is always taken.
  The `bne` branch at 0x4968 targets 0x3c24, is taken when v0(=ret(crmUnmapPages)) != 0, and falls through when v0(=ret(crmUnmapPages)) == 0.
  The `beq` branch at 0x4974 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4984 targets 0x4a10, is taken when t2(=[[a0+24]+4]) == s0(=a1), and falls through when t2(=[[a0+24]+4]) != s0(=a1).
  The `beq` branch at 0x498c targets 0x3c24 and is always taken.
  The `beq` branch at 0x4994 targets 0x3c24 and is always taken.
  The `bne` branch at 0x49a4 targets 0x4808, is taken when (t3(?) & 0x4) != 0, and falls through when (t3(?) & 0x4) == 0.
  The `beq` branch at 0x49ac targets 0x4670 and is always taken.
  The `beq` branch at 0x49b8 targets 0x4a00, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x49c4 targets 0x49b4, is taken when t8(?) != a0(?), and falls through when t8(?) == a0(?).
  The `beq` branch at 0x49cc targets 0x4a00, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x49d8 targets 0x4a88, is taken when a0(=[[a1+76]+32]) == 0, and falls through when a0(=[[a1+76]+32]) != 0.
  The `beq` branch at 0x49e0 targets 0x4a98, is taken when a0(=[[a1+76]+32]) == v0(?), and falls through when a0(=[[a1+76]+32]) != v0(?).
  The `beq` branch at 0x49f0 targets 0x3c24 and is always taken.
  The `beq` branch at 0x49f8 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4a08 targets 0x3c24 and is always taken.
  The `bgez` branch at 0x4a1c targets 0x4a30, is taken when v0(=ret(RRM_CheckValidFault)) >= 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) < 0 (signed).
  The `beq` branch at 0x4a28 targets 0x4a40 and is always taken.
  The `beq` branch at 0x4a40 targets 0x3c28 and is always taken.
  The `bne` branch at 0x4a78 targets 0x4a58, is taken when v0(?) < 0x4 (signed), and falls through when v0(?) >= 0x4 (signed).
  The `beq` branch at 0x4a80 targets 0x3c28 and is always taken.
  The `beq` branch at 0x4aa0 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4ab0 targets 0x484c and is always taken.
  The `beq` branch at 0x4ab8 targets 0x3c24 and is always taken.
  The `bne` branch at 0x4ac0 targets 0x4ae4, is taken when a2 != v0(=0x564f), and falls through when a2 == v0(=0x564f).
  The `beq` branch at 0x4ad8 targets 0x3c24 and is always taken.
  The `beq` branch at 0x4af0 targets 0x3c24 and is always taken.
  The return at 0x3c40 has v0 = one of ?, ret(crmMapPages), 0x10, ret(crimeSetGammaRamp), ret(crime_i2cfp_command), ret(crmAllocTex), 0x0, 0x4, ret(crmMapChunk).
  The instructions from 0x4090 to 0x4090 are not reached by any path from the entry, and their branches are not listed.

- `crmAllocGfxBuffers` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x4b3c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x4b3c-0x4df8 (700 bytes).
  It occupies 700 bytes.
  The `lw` at 0x4b44 loads 4 bytes from a0 (arg0 at entry) +0x7c.
  3 such `lw` accesses load 4 bytes from sym(crmFrameBuffer) +0x22c, including `lw` at 0x4b6c, `lw` at 0x4cf0, `lw` at 0x4d98.
  The `lhu` at 0x4b70 loads 2 bytes from [a0+124] +0x22.
  The `lhu` at 0x4b74 loads 2 bytes from [a0+124] +0x20.
  The `lbu` at 0x4bb8 loads 1 byte from sym(crmFrameBuffer) +0x240.
  The `lbu` at 0x4bbc loads 1 byte from sym(crmFrameBuffer) +0x241.
  4 such `lw` accesses load 4 bytes from sym(crmFrameBuffer) +0x4, including `lw` at 0x4bf0, `lw` at 0x4cbc, `lw` at 0x4d44.
  3 such `lbu` accesses load 1 byte from [a0+124] +0x2f, including `lbu` at 0x4bfc, `lbu` at 0x4d58, `lbu` at 0x4d90.
  The `lbu` at 0x4c58 loads 1 byte from sym(crmFrameBuffer) +0x18.
  The `lbu` at 0x4c5c loads 1 byte from sym(crmFrameBuffer) +0x19.
  The `sw` at 0x4cd4 stores 4 bytes to sym(crmFrameBuffer) +0x10.
  2 such `lw` accesses load 4 bytes from sym(crmbackbuffer) +0x4, including `lw` at 0x4cd8, `lw` at 0x4d60.
  The `sw` at 0x4cec stores 4 bytes to sym(crmbackbuffer) +0x10.
  The `sw` at 0x4d04 stores 4 bytes to sym(crmFrameBuffer) +0x238.
  2 such `lw` accesses load 4 bytes from sym(crmFrameBuffer) +0x2d4, including `lw` at 0x4d08, `lw` at 0x4dd0.
  The `lw` at 0x4d1c loads 4 bytes from sym(crmzbuffer) +0x4.
  The `sw` at 0x4d80 stores 4 bytes to sym(crmzbuffer) +0x4.
  The `jal` at 0x4b5c calls bzero with a0=a0+164, a1=0x14, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4ccc calls crmNextIncarnation with a0=?, a1=[sym(crmFrameBuffer+4)], a2=?, a3=?.
  The `jal` at 0x4ce4 calls crmNextIncarnation with a0=sym(crmbackbuffer), a1=?, a2=?, a3=?.
  The `jal` at 0x4cfc calls crmNextIncarnation with a0=sym(crmFrameBuffer), a1=?, a2=?, a3=?.
  The `jal` at 0x4d38 calls crmFreeChunk with a0=sym(crmFrameBuffer), a1=[sym(crmFrameBuffer+4)], a2=[sym(crmOverlayBuffer+4)], a3=?, a5=[sym(crmOverlayBuffer+25)]:1, a6=[sym(crmOverlayBuffer+24)]:1.
  The `jal` at 0x4d54 calls crmAllocFrameBuffer with a0=sym(crmFrameBuffer), a1=[[a0+124]+32]:2, a2=[[a0+124]+34]:2, a3=[[a0+124]+47]:1.
  The `jal` at 0x4d74 calls sema_alloc with a0=0x0, a1=0x1, a2=sym(.rodata)+248, a3=?.
  The `jal` at 0x4d8c calls crmAllocBackbuffer with a0=sym(crmbackbuffer), a1=[[a0+124]+32]:2, a2=[[a0+124]+34]:2, a3=[[a0+124]+47]:1.
  The `jal` at 0x4da4 calls crmFreeChunk with a0=sym(crmFrameBuffer), a1=[sym(crmFrameBuffer+4)], a2=?, a3=?, a5=[sym(crmFrameBuffer+25)]:1, a6=[sym(crmFrameBuffer+24)]:1.
  The `jal` at 0x4db0 calls crmFreeChunk with a0=sym(crmbackbuffer), a1=?, a2=?, a3=?.
  The `jal` at 0x4dc4 calls crmAllocOverlayBuffer with a0=sym(crmFrameBuffer), a1=[[a0+124]+32]:2, a2=[[a0+124]+34]:2, a3=?.
  The `jal` at 0x4de0 calls crmAllocCid with a0=sym(crmFrameBuffer), a1=[[a0+124]+32]:2, a2=[[a0+124]+34]:2, a3=?.
  The `beq` branch at 0x4b78 targets 0x4bf0, is taken when a2(=[sym(crmOverlayBuffer+4)]) == 0, and falls through when a2(=[sym(crmOverlayBuffer+4)]) != 0.
  The `beq` branch at 0x4ba8 targets 0x4c88, is taken when a0(?) >= 0x11 (signed), and falls through when a0(?) < 0x11 (signed).
  The `beq` branch at 0x4bb4 targets 0x4c88, is taken when v0(?) >= 0x11 (signed), and falls through when v0(?) < 0x11 (signed).
  The `bne` branch at 0x4bc4 targets 0x4bd8, is taken when a6(=[sym(crmOverlayBuffer+24)]:1) < a0(?) (signed), and falls through when a6(=[sym(crmOverlayBuffer+24)]:1) >= a0(?) (signed).
  The `beq` branch at 0x4bcc targets 0x4be4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x4bd8 targets 0x4be4, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x4bec targets 0x4d38, is taken when a2(=[sym(crmOverlayBuffer+4)]) != a4(?), and falls through when a2(=[sym(crmOverlayBuffer+4)]) == a4(?).
  The `beq` branch at 0x4bf4 targets 0x4cc4, is taken when a1(=[sym(crmFrameBuffer+4)]) == 0, and falls through when a1(=[sym(crmFrameBuffer+4)]) != 0.
  The `beq` branch at 0x4c48 targets 0x4d30, is taken when a0(?) >= 0x11 (signed), and falls through when a0(?) < 0x11 (signed).
  The `beq` branch at 0x4c54 targets 0x4d30, is taken when v0(?) >= 0x11 (signed), and falls through when v0(?) < 0x11 (signed).
  The `bne` branch at 0x4c64 targets 0x4c78, is taken when a6(=[sym(crmFrameBuffer+24)]:1) < a0(?) (signed), and falls through when a6(=[sym(crmFrameBuffer+24)]:1) >= a0(?) (signed).
  The `beq` branch at 0x4c6c targets 0x4cb0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x4c78 targets 0x4cac, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x4c80 targets 0x4cb0 and is always taken.
  The `bne` branch at 0x4cb8 targets 0x4da4, is taken when a1(=[sym(crmFrameBuffer+4)]) != t2(?), and falls through when a1(=[sym(crmFrameBuffer+4)]) == t2(?).
  The `beq` branch at 0x4cc4 targets 0x4d48, is taken when a1(=[sym(crmFrameBuffer+4)]) == 0, and falls through when a1(=[sym(crmFrameBuffer+4)]) != 0.
  The `beq` branch at 0x4cdc targets 0x4d84, is taken when t8(=[sym(crmbackbuffer)+4]) == 0, and falls through when t8(=[sym(crmbackbuffer)+4]) != 0.
  The `beq` branch at 0x4cf4 targets 0x4dc0, is taken when t9(=[sym(crmOverlayBuffer+4)]) == 0, and falls through when t9(=[sym(crmOverlayBuffer+4)]) != 0.
  The `beq` branch at 0x4d0c targets 0x4ddc, is taken when ra(=[sym(crmCidBuffer+4)]) == 0, and falls through when ra(=[sym(crmCidBuffer+4)]) != 0.
  The `beq` branch at 0x4d20 targets 0x4d6c, is taken when at(=[sym(crmzbuffer)+4]) == 0, and falls through when at(=[sym(crmzbuffer)+4]) != 0.
  The `beq` branch at 0x4d28 targets 0x4c8c and is always taken.
  The `beq` branch at 0x4d30 targets 0x4c8c and is always taken.
  The `beq` branch at 0x4d40 targets 0x4bf4 and is always taken.
  The `beq` branch at 0x4d5c targets 0x4cdc, is taken when v0(=ret(crmAllocFrameBuffer)) == 0, and falls through when v0(=ret(crmAllocFrameBuffer)) != 0.
  The `beq` branch at 0x4d64 targets 0x4c8c and is always taken.
  The `beq` branch at 0x4d7c targets 0x4d28 and is always taken.
  The `beq` branch at 0x4d94 targets 0x4cf4, is taken when v0(=ret(crmAllocBackbuffer)) == 0, and falls through when v0(=ret(crmAllocBackbuffer)) != 0.
  The `beq` branch at 0x4d9c targets 0x4c8c and is always taken.
  The `beq` branch at 0x4db8 targets 0x4cc0 and is always taken.
  The `beq` branch at 0x4dcc targets 0x4d0c, is taken when v0(=ret(crmAllocOverlayBuffer)) == 0, and falls through when v0(=ret(crmAllocOverlayBuffer)) != 0.
  The `beq` branch at 0x4dd4 targets 0x4c8c and is always taken.
  The `beq` branch at 0x4de8 targets 0x4d18, is taken when v0(=ret(crmAllocCid)) == 0, and falls through when v0(=ret(crmAllocCid)) != 0.
  The `beq` branch at 0x4df0 targets 0x4c8c and is always taken.
  The return at 0x4ca4 has v0 = one of -0x1, 0x0, 0x16.

- `crmFirstInit` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x4df8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x4df8-0x4e64 (108 bytes).
  It occupies 108 bytes.
  The `lw` at 0x4e00 loads 4 bytes from sym(crmFrameBuffer) +0x5ec.
  The `sw` at 0x4e28 stores 4 bytes to sym(crmFrameBuffer) +0x5ec.
  The `sw` at 0x4e38 stores 4 bytes to sym(crmFrameBuffer) +0x340.
  The `sw` at 0x4e40 stores 4 bytes to sym(crmFrameBuffer) +0x2d8.
  The `sw` at 0x4e4c stores 4 bytes to sym(crmFrameBuffer) +0x230.
  The `sw` at 0x4e58 stores 4 bytes to sym(crmFrameBuffer) +0x8.
  The `jal` at 0x4e24 calls crm_tileclassinit with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4e54 calls crmAllocGbeTables with a0=sym(crmFrameBuffer), a1=sym(crmFrameBuffer), a2=sym(crmFrameBuffer), a3=sym(crmFrameBuffer), a4=sym(crmFrameBuffer), a5=sym(.sbss).
  The `beq` branch at 0x4e08 targets 0x4e18, is taken when at(=[sym(.bss)+1516]) == 0, and falls through when at(=[sym(.bss)+1516]) != 0.
  The `beq` branch at 0x4e5c targets 0x4e10 and is always taken.
  The return at 0x4e10 has v0 = one of ?, ret(crmAllocGbeTables).

- `crime_earlyinit` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x4e64 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x4e64-0x5364 (1280 bytes).
  It occupies 1280 bytes.
  The `lw` at 0x4e80 loads 4 bytes from sym(crimeBoards) +0x0.
  The `lw` at 0x4e88 loads 4 bytes from sym(crimeBoards) +0x8.
  The `lw` at 0x4e8c loads 4 bytes from sym(crimeBoards) +0x4.
  9 such `lw` accesses load 4 bytes from sym(crimeBoards) +0xc, including `lw` at 0x4ea4, `lw` at 0x4f68, `lw` at 0x4f70.
  2 such `sh` accesses store 2 bytes to sym(crimeBoards) +0x38, including `sh` at 0x4ecc, `sh` at 0x51e4.
  2 such `lw` accesses load 4 bytes from sym(crmzbuffer) +0x0, including `lw` at 0x4efc, `lw` at 0x4f14.
  The `sw` at 0x4f18 stores 4 bytes to sym(crmzbuffer) +0x0.
  The `lw` at 0x4f1c loads 4 bytes from sym(crmFrameBuffer) +0x2dc.
  The `lw` at 0x4f28 loads 4 bytes from sym(crmFrameBuffer) +0x2d8.
  The `sw` at 0x4f2c stores 4 bytes to sym(crmFrameBuffer) +0x2e0.
  The `sw` at 0x4f34 stores 4 bytes to sym(crmFrameBuffer) +0x2d4.
  The `sw` at 0x4f44 stores 4 bytes to sym(crmFrameBuffer) +0x2dc.
  3 such `lw` accesses load 4 bytes from sym(crmFrameBuffer) +0xce0, including `lw` at 0x4f48, `lw` at 0x4f5c, `lw` at 0x52c8.
  The `sw` at 0x4f6c stores 4 bytes to [sym(crimeBoards+12)] +0x88.
  The `sw` at 0x4f74 stores 4 bytes to [sym(crimeBoards+12)] +0x1cc.
  The `sw` at 0x4f7c stores 4 bytes to [sym(crimeBoards+12)] +0x138.
  The `sb` at 0x4f8c stores 1 byte to [sym(crimeBoards+12)] +0x98.
  The `sw` at 0x4f94 stores 4 bytes to sym(crmFrameBuffer) +0x348.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x4fa0, `lw` at 0x4fbc, `lw` at 0x4fec.
  The `sw` at 0x4fe0 stores 4 bytes to ?.
  The `lw` at 0x500c loads 4 bytes from sym(crmFrameBuffer) +0xb20.
  The `lw` at 0x5010 loads 4 bytes from [sym(.bss)+2848] +0x4.
  The `sw` at 0x5020 stores 4 bytes to sym(crmFrameBuffer) +0xbd4.
  The `sh` at 0x5040 stores 2 bytes to sym(crimeBoards) +0x22.
  The `sh` at 0x5044 stores 2 bytes to sym(crimeBoards) +0x20.
  2 such `sh` accesses store 2 bytes to sym(crimeBoards) +0x1a, including `sh` at 0x5058, `sh` at 0x525c.
  2 such `sh` accesses store 2 bytes to sym(crimeBoards) +0x18, including `sh` at 0x5060, `sh` at 0x5264.
  2 such `sh` accesses store 2 bytes to sym(crmFrameBuffer) +0xc5a, including `sh` at 0x506c, `sh` at 0x5218.
  2 such `sh` accesses store 2 bytes to sym(crmFrameBuffer) +0xbd8, including `sh` at 0x5078, `sh` at 0x5210.
  3 such `lbu` accesses load 1 byte from sym(crmFrameBuffer) +0xb1e, including `lbu` at 0x5084, `lbu` at 0x527c, `lbu` at 0x52a0.
  3 such `lhu` accesses load 2 bytes from sym(crmFrameBuffer) +0xb10, including `lhu` at 0x5094, `lhu` at 0x52ec, `lhu` at 0x534c.
  The `lbu` at 0x50a4 loads 1 byte from sym(crmFrameBuffer) +0x240.
  The `lhu` at 0x50b4 loads 2 bytes from sym(crmFrameBuffer) +0xb12.
  The `lbu` at 0x50c4 loads 1 byte from sym(crmFrameBuffer) +0x241.
  The `sw` at 0x50e0 stores 4 bytes to sym(crmFrameBuffer) +0x238.
  The `lbu` at 0x5120 loads 1 byte from sym(crimeBoards) +0x3e.
  The `lbu` at 0x5140 loads 1 byte from sym(crmFrameBuffer) +0xb1d.
  The `lbu` at 0x51d0 loads 1 byte from sym(arg_console) +0x0.
  The `sb` at 0x51e0 stores 1 byte to sym(crimeBoards) +0x3e.
  The `sw` at 0x5204 stores 4 bytes to [sym(crimeBoards)] +0x408.
  The `sh` at 0x5214 stores 2 bytes to sym(crmFrameBuffer) +0xcdc.
  The `sb` at 0x5234 stores 1 byte to sym(crmFrameBuffer) +0xb1c.
  The `sh` at 0x524c stores 2 bytes to sym(crimeBoards) +0x2a.
  The `sh` at 0x5254 stores 2 bytes to sym(crimeBoards) +0x28.
  The `jal` at 0x4e90 calls crimeProbe with a0=[sym(crimeBoards)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4ec8 calls gbeStop with a0=[sym(crimeBoards+4)], a1=sp-80, a2=sp-80, a3=sp-80.
  The `jal` at 0x4ed0 calls in_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4ee4 calls crmFreeChunk with a0=sym(crmFrameBuffer), a1=?, a2=?, a3=?.
  The `jal` at 0x4ef0 calls crmFreeChunk with a0=sym(crmbackbuffer), a1=?, a2=?, a3=?.
  The `jal` at 0x4f08 calls crmFreeChunk with a0=[sym(crmzbuffer)], a1=?, a2=?, a3=?.
  The `jal` at 0x4f10 calls kern_free with a0=[sym(crmzbuffer)], a1=?, a2=?, a3=?.
  The `jal` at 0x4f40 calls bzero with a0=[sym(crmCidBuffer+8)], a1=0x40, a2=?, a3=?.
  The `jal` at 0x4f54 calls crm_destroydrawable with a0=[sym(crm_drawables)], a1=?, a2=?, a3=?.
  The `jal` at 0x4f88 calls crmNextIncarnation with a0=[sym(crimeBoards+12)], a1=?, a2=?, a3=?.
  The `jal` at 0x4fac calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4fc0 calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x507c calls crimeInitInfo with a0=[sym(crimeBoards)], a1=[sym(crimeBoards+4)], a2=sym(.bss)+2800, a3=0x0, a4=0xff.
  The `jal` at 0x50d8 calls crmNextIncarnation with a0=?, a1=?, a2=?, a3=?, a7=[sym(crmOverlayBuffer+24)]:1.
  The `jal` at 0x50f0 calls crimeInitHW with a0=[sym(crimeBoards)], a1=[sym(crimeBoards+4)], a2=sym(.bss)+2800, a3=0x0.
  The `jal` at 0x5100 calls gbeRun with a0=[sym(crimeBoards+4)], a1=sym(.bss)+2800, a2=0x0, a3=?.
  The `jal` at 0x5118 calls gbeBlankScreen with a0=[sym(crimeBoards+12)], a1=sym(.bss)+2800, a2=[sym(crimeBoards+4)], a3=0x0, a4=0x1.
  The `jal` at 0x5138 calls crmInitTp with a0=[sym(crimeBoards)], a1=[sym(crimeBoards+4)], a2=sym(.bss)+2800, a3=sym(crmFrameBuffer).
  The `jal` at 0x5154 calls crime_clearfb with a0=[sym(crimeBoards)], a1=[sym(crimeBoards+4)], a2=?, a3=?.
  The `jal` at 0x516c calls htp_register_board with a0=[sym(crimeBoards)], a1=sym(crime_htp_fncs), a2=[sym(.bss)+2832]:2, a3=?.
  The `jal` at 0x519c calls crmFreeChunk with a0=sym(crmFrameBuffer), a1=?, a2=?, a3=?, a7=[sym(crmOverlayBuffer+24)]:1.
  The `jal` at 0x51ac calls crmAllocOverlayBuffer with a0=sym(crmFrameBuffer), a1=[sym(.bss)+2832]:2, a2=[sym(.bss)+2834]:2, a3=?.
  The `jal` at 0x51c4 calls is_specified with a0=sym(arg_console), a1=?, a2=?, a3=?.
  The `jal` at 0x51e8 calls gbeProbe with a0=[sym(crimeBoards+4)], a1=?, a2=?, a3=?.
  The `jal` at 0x51fc calls gbeStop with a0=[sym(crimeBoards+4)], a1=sp-80, a2=sp-80, a3=sp-80.
  The `jal` at 0x521c calls i2cfp_DualChannelProbe with a0=[sym(crimeBoards+4)], a1=?, a2=?, a3=?.
  The `jal` at 0x5274 calls crimeInitInfo with a0=[sym(crimeBoards)], a1=[sym(crimeBoards+4)], a2=sym(.bss)+2800, a3=0x0.
  The `jal` at 0x528c calls crmFirstInit with a0=sym(crimeBoards), a1=?, a2=?, a3=?.
  The `jal` at 0x52ac calls i2cfp_PanelOff with a0=[sym(crimeBoards+4)], a1=?, a2=?, a3=?.
  The `jal` at 0x52bc calls crmFreeChunk with a0=sym(crmFrameBuffer), a1=?, a2=?, a3=?.
  The `jal` at 0x52e0 calls i2cfp_DMI2_BkltFuncs with a0=[sym(crimeBoards+4)], a1=0x10, a2=0x0, a3=0x0, a4=0x0, a5=0x84, a6=[sym(.bss)+2846]:1.
  The `jal` at 0x52f8 calls crmRetraceCloseAllRn with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x5324 calls i2cfp_DMI2_BkltFuncs with a0=[sym(crimeBoards+4)], a1=0x10, a2=0x0, a3=0x0, a4=0x0.
  The `jal` at 0x5340 calls cmn_err with a0=0x4, a1=sym(.rodata)+520, a2=?, a3=?.
  The `jal` at 0x5354 calls cmn_err with a0=0x4, a1=sym(.rodata)+520, a2=?, a3=?.
  The `beq` branch at 0x4e98 targets 0x52cc, is taken when v0(=ret(crimeProbe)) == 0, and falls through when v0(=ret(crimeProbe)) != 0.
  The `beq` branch at 0x4eb0 targets 0x51bc, is taken when t8(=[sym(crimeBoards+12)]) == 0, and falls through when t8(=[sym(crimeBoards+12)]) != 0.
  The `beq` branch at 0x4ed8 targets 0x52f8, is taken when v0(=ret(in_panic_mode)) == 0, and falls through when v0(=ret(in_panic_mode)) != 0.
  The `beq` branch at 0x4f00 targets 0x4f1c, is taken when a0(=[sym(crmzbuffer)]) == 0, and falls through when a0(=[sym(crmzbuffer)]) != 0.
  The `beq` branch at 0x4f24 targets 0x52bc, is taken when (v0(=[sym(crmCidBuffer+12)]) & 0x10) == 0, and falls through when (v0(=[sym(crmCidBuffer+12)]) & 0x10) != 0.
  The `beq` branch at 0x4f4c targets 0x4f68, is taken when a0(=[sym(crm_drawables)]) == 0, and falls through when a0(=[sym(crm_drawables)]) != 0.
  The `bne` branch at 0x4f60 targets 0x4f54, is taken when a0(=[sym(crm_drawables)]) != 0, and falls through when a0(=[sym(crm_drawables)]) == 0.
  The `beq` branch at 0x4f98 targets 0x4fe4 and is always taken.
  The `beq` branch at 0x4fa4 targets 0x4fc0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x4fdc targets 0x500c, is taken when s3(?) >= 0x20 (signed), and falls through when s3(?) < 0x20 (signed).
  The `bne` branch at 0x4ff8 targets 0x4fa0, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `bne` branch at 0x5004 targets 0x4fec, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0x5018 targets 0x5028, is taken when (a0(=[[sym(.bss)+2848]+4]) & 0x2) == 0, and falls through when (a0(=[[sym(.bss)+2848]+4]) & 0x2) != 0.
  The `blez` branch at 0x5028 targets 0x5064, is taken when a0(=[sym(crm_num_monitors)]) <= 0 (signed), and falls through when a0(=[sym(crm_num_monitors)]) > 0 (signed).
  The `beq` branch at 0x5048 targets 0x5064, is taken when v0(?) >= a0(=[sym(crm_num_monitors)]) (signed), and falls through when v0(?) < a0(=[sym(crm_num_monitors)]) (signed).
  The `bne` branch at 0x505c targets 0x5038, is taken when v0(?) < a0(=[sym(crm_num_monitors)]) (signed), and falls through when v0(?) >= a0(=[sym(crm_num_monitors)]) (signed).
  The `beq` branch at 0x508c targets 0x52d4, is taken when a5(=0x84) == a6(=[sym(.bss)+2846]:1), and falls through when a5(=0x84) != a6(=[sym(.bss)+2846]:1).
  The `bne` branch at 0x50b0 targets 0x519c, is taken when a7(=[sym(crmOverlayBuffer+24)]:1) != t0(?), and falls through when a7(=[sym(crmOverlayBuffer+24)]:1) == t0(?).
  The `bne` branch at 0x50d0 targets 0x519c, is taken when t1(=[sym(crmOverlayBuffer+25)]:1) != t2(?), and falls through when t1(=[sym(crmOverlayBuffer+25)]:1) == t2(?).
  The `beq` branch at 0x5128 targets 0x52a0, is taken when t3(=[sym(crimeBoards+62)]:1) == t8(=0x64), and falls through when t3(=[sym(crimeBoards+62)]:1) != t8(=0x64).
  The `beq` branch at 0x5144 targets 0x5150, is taken when t9(=[sym(.bss)+2845]:1) == 0, and falls through when t9(=[sym(.bss)+2845]:1) != 0.
  The `beq` branch at 0x51b4 targets 0x50e8 and is always taken.
  The `beq` branch at 0x51cc targets 0x5308, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x51d8 targets 0x5310, is taken when v0(=[sym(arg_console)]:1) == t8(=0x47), and falls through when v0(=[sym(arg_console)]:1) != t8(=0x47).
  The `beq` branch at 0x5228 targets 0x5234, is taken when v0(=ret(i2cfp_DualChannelProbe)) == 0, and falls through when v0(=ret(i2cfp_DualChannelProbe)) != 0.
  The `blez` branch at 0x523c targets 0x5268, is taken when a0(=[sym(crm_num_monitors)]) <= 0 (signed), and falls through when a0(=[sym(crm_num_monitors)]) > 0 (signed).
  The `bne` branch at 0x5260 targets 0x5248, is taken when v0(?) < a0(=[sym(crm_num_monitors)]) (signed), and falls through when v0(?) >= a0(=[sym(crm_num_monitors)]) (signed).
  The `beq` branch at 0x5284 targets 0x5318, is taken when at(=0x84) == v0(=[sym(.bss)+2846]:1), and falls through when at(=0x84) != v0(=[sym(.bss)+2846]:1).
  The `beq` branch at 0x5298 targets 0x5094 and is always taken.
  The `beq` branch at 0x52a4 targets 0x5130, is taken when t8(=[sym(.bss)+2846]:1) == 0, and falls through when t8(=[sym(.bss)+2846]:1) != 0.
  The `beq` branch at 0x52b4 targets 0x5130 and is always taken.
  The `beq` branch at 0x52c4 targets 0x4f4c and is always taken.
  The `beq` branch at 0x52cc targets 0x5180 and is always taken.
  The `bnel` branch at 0x52e8 targets 0x5098, is taken when v0(=ret(i2cfp_DMI2_BkltFuncs)) != 0, and falls through when v0(=ret(i2cfp_DMI2_BkltFuncs)) == 0; its branch-likely delay slot `lhu s3,32(s4)` at 0x52ec runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x52f0 targets 0x533c and is always taken.
  The `beq` branch at 0x5300 targets 0x4ee0 and is always taken.
  The `beq` branch at 0x5308 targets 0x51e0 and is always taken.
  The `beq` branch at 0x5310 targets 0x51e0 and is always taken.
  The `bne` branch at 0x532c targets 0x528c, is taken when v0(=ret(i2cfp_DMI2_BkltFuncs)) != 0, and falls through when v0(=ret(i2cfp_DMI2_BkltFuncs)) == 0.
  The `beq` branch at 0x5334 targets 0x5350 and is always taken.
  The `beq` branch at 0x5348 targets 0x5098 and is always taken.
  The `beq` branch at 0x535c targets 0x528c and is always taken.
  The return at 0x5194 has v0 = one of 0x0, 0x1.

- `crime_init` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x5364 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x5364-0x57d4 (1136 bytes).
  It occupies 1136 bytes.
  The `lw` at 0x5378 loads 4 bytes from sym(crimeBoards) +0x8.
  2 such `lbu` accesses load 1 byte from sym(crmFrameBuffer) +0xb1e, including `lbu` at 0x5388, `lbu` at 0x5428.
  The `lw` at 0x53d4 loads 4 bytes from sym(crimeBoards) +0x0.
  The `sw` at 0x53d8 stores 4 bytes to ret(kern_malloc) +0x78.
  4 such `lw` accesses load 4 bytes from sym(crimeBoards) +0x4, including `lw` at 0x53e0, `lw` at 0x5568, `lw` at 0x5580.
  The `sw` at 0x53ec stores 4 bytes to ret(kern_malloc) +0x90.
  The `sw` at 0x53f8 stores 4 bytes to ret(kern_malloc) +0x7c.
  The `sw` at 0x5404 stores 4 bytes to ret(kern_malloc) +0x80.
  The `sw` at 0x5438 stores 4 bytes to ret(kern_malloc) +0x34.
  The `sw` at 0x5444 stores 4 bytes to ret(kern_malloc) +0x38.
  The `sw` at 0x5450 stores 4 bytes to ret(kern_malloc) +0xc.
  The `sw` at 0x5468 stores 4 bytes to ret(kern_malloc) +0x84.
  2 such `lh` accesses load 2 bytes from sym(crimeBoards) +0x22, including `lh` at 0x5498, `lh` at 0x56bc.
  2 such `lh` accesses load 2 bytes from sym(crimeBoards) +0x3c, including `lh` at 0x54b4, `lh` at 0x56a4.
  The `lw` at 0x5534 loads 4 bytes from sym(crimeBoards) +0x14.
  The `sw` at 0x5538 stores 4 bytes to sym(crimeBoards) +0xc.
  The `sw` at 0x5548 stores 4 bytes to sym(crimeBoards) +0x14.
  The `ld` at 0x554c loads 8 bytes from abs 0xffffffffb4000028.
  The `sd` at 0x5564 stores 8 bytes to abs 0xffffffffb4000028.
  The `sw` at 0x557c stores 4 bytes to [sym(crimeBoards+4)] +0x10020.
  The `sw` at 0x5598 stores 4 bytes to [sym(crimeBoards+4)] +0x10024.
  The `lw` at 0x56e0 loads 4 bytes from ret(kern_malloc) +0x80.
  The `jal` at 0x53bc calls kern_malloc with a0=0x230, a1=?, a2=?, a3=?.
  The `jal` at 0x53cc calls bzero with a0=ret(kern_malloc), a1=0x230, a2=?, a3=?.
  The `jal` at 0x5400 calls add_to_inventory with a0=0x7, a1=0x11, a2=0x0, a3=0x0, a4=0x1.
  The `jal` at 0x5420 calls add_to_inventory with a0=0x11, a1=0x3, a2=0x0, a3=0x0, a4=0x0.
  The `jal` at 0x5454 calls kvpalloc with a0=0x1, a1=0x10080010, a2=0x0, a3=ret(kern_malloc)+324.
  The `jal` at 0x5464 calls bzero with a0=ret(kvpalloc), a1=0x600, a2=?, a3=?.
  The `jal` at 0x5478 calls init_mutex with a0=ret(kern_malloc)+468, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jal` at 0x54cc calls init_mutex with a0=ret(kern_malloc)+476, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jal` at 0x54e0 calls mrlock_init with a0=ret(kern_malloc)+484, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jal` at 0x54ec calls spinlock_init with a0=ret(kern_malloc)+540, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x5500 calls init_sv with a0=ret(kern_malloc)+556, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jal` at 0x5514 calls init_mutex with a0=sym(crm_drawlock), a1=0x0, a2=0x0, a3=-0x1.
  The `jal` at 0x551c calls crimeRetraceInit with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x552c calls GfxRegisterBoard with a0=sym(crimeBoards), a1=ret(kern_malloc), a2=sym(.bss)+2800, a3=?.
  The `jal` at 0x55ac calls setcrimevector with a0=?, a1=0x1, a2=sym(crimeInterrupt), a3=?, a4=0x0.
  The `jal` at 0x55e0 calls setcrimevector with a0=0x10, a1=0x1, a2=sym(crimeRetraceHandler), a3=ret(kern_malloc), a4=0x0.
  The `jal` at 0x5608 calls setcrimevector with a0=0x11, a1=0x1, a2=sym(crimePreblankHandler), a3=ret(kern_malloc), a4=0x0.
  The `jal` at 0x5628 calls setcrimevector with a0=0x1a, a1=0x1, a2=sym(crimeFifoFullHandler), a3=ret(kern_malloc), a4=0x0.
  The `jal` at 0x5648 calls setcrimevector with a0=0x19, a1=0x1, a2=sym(crimeFifoEmptyHandler), a3=ret(kern_malloc), a4=0x4.
  The `jal` at 0x5674 calls crime_i2cProbe with a0=[sym(crimeBoards+4)], a1=sym(.bss)+2800, a2=?, a3=?, a4=[sym(crimeBoards+34)]:2.
  The `jal` at 0x5684 calls crime_validate_ddc_data with a0=sym(.bss)+2800, a1=?, a2=?, a3=?.
  The `jal` at 0x56e4 calls gbeBlankScreen with a0=ret(kern_malloc), a1=sym(.bss)+2800, a2=[ret(kern_malloc)+128], a3=0x1, a4=0x1, a6=[sym(crimeBoards+60)]:2.
  The `jal` at 0x5708 calls find_inventory with a0=0x0, a1=0x11, a2=0x4, a3=0x0, a4=0x0, a5=0x0.
  The `jal` at 0x5728 calls replace_in_inventory with a0=ret(find_inventory), a1=0x11, a2=0x5, a3=0x0, a4=0x0, a5=0x0.
  The `jal` at 0x5748 calls add_to_inventory with a0=0x11, a1=0x5, a2=0x0, a3=0x0, a4=0x0.
  The `jal` at 0x575c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x5770 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x5784 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x5798 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?, a4=0x4.
  The `jal` at 0x57ac calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x57c4 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[sym(.bss)+2846]:1, a3=a3 at entry (arg3).
  The `beq` branch at 0x5380 targets 0x5658, is taken when s5(=sym(.bss)+2800) == 0, and falls through when s5(=sym(.bss)+2800) != 0.
  The `beq` branch at 0x5390 targets 0x56a8, is taken when a2(=[sym(.bss)+2846]:1) == t8(=0x82), and falls through when a2(=[sym(.bss)+2846]:1) != t8(=0x82).
  The `beq` branch at 0x5398 targets 0x56a8, is taken when a2(=[sym(.bss)+2846]:1) == t9(=0x83), and falls through when a2(=[sym(.bss)+2846]:1) != t9(=0x83).
  The `beq` branch at 0x53a0 targets 0x56a8, is taken when a2(=[sym(.bss)+2846]:1) == v0(=0x84), and falls through when a2(=[sym(.bss)+2846]:1) != v0(=0x84).
  The `bne` branch at 0x53a8 targets 0x57bc, is taken when a2(=[sym(.bss)+2846]:1) != 0, and falls through when a2(=[sym(.bss)+2846]:1) == 0.
  The `beq` branch at 0x540c targets 0x5428, is taken when at(=[sym(crm_dc_board_installed)]) == 0, and falls through when at(=[sym(crm_dc_board_installed)]) != 0.
  The `beq` branch at 0x5430 targets 0x56f4, is taken when v0(=0x84) == v1(=[sym(.bss)+2846]:1), and falls through when v0(=0x84) != v1(=[sym(.bss)+2846]:1).
  The `blez` branch at 0x5488 targets 0x54b4, is taken when v0(=[sym(crm_num_monitors)]) <= 0 (signed), and falls through when v0(=[sym(crm_num_monitors)]) > 0 (signed).
  The `beq` branch at 0x549c targets 0x5670, is taken when a4(=[sym(crimeBoards+34)]:2) == 0, and falls through when a4(=[sym(crimeBoards+34)]:2) != 0.
  The `bne` branch at 0x54ac targets 0x5498, is taken when s2(?) < v0(=[sym(crm_num_monitors)]) (signed), and falls through when s2(?) >= v0(=[sym(crm_num_monitors)]) (signed).
  The `beq` branch at 0x54b8 targets 0x56b0, is taken when a6(=[sym(crimeBoards+60)]:2) == 0, and falls through when a6(=[sym(crimeBoards+60)]:2) != 0.
  The `bne` branch at 0x55b4 targets 0x5758, is taken when v0(=ret(setcrimevector)) != 0, and falls through when v0(=ret(setcrimevector)) == 0.
  The `bne` branch at 0x55c4 targets 0x559c, is taken when s2(?) < 0x4 (signed), and falls through when s2(?) >= 0x4 (signed).
  The `bne` branch at 0x55ec targets 0x576c, is taken when v0(=ret(setcrimevector)) != 0, and falls through when v0(=ret(setcrimevector)) == 0.
  The `bne` branch at 0x5610 targets 0x5780, is taken when v0(=ret(setcrimevector)) != 0, and falls through when v0(=ret(setcrimevector)) == 0.
  The `bne` branch at 0x5630 targets 0x5794, is taken when v0(=ret(setcrimevector)) != 0, and falls through when v0(=ret(setcrimevector)) == 0.
  The `bne` branch at 0x5650 targets 0x57a8, is taken when v0(=ret(setcrimevector)) != 0, and falls through when v0(=ret(setcrimevector)) == 0.
  The `beq` branch at 0x567c targets 0x568c, is taken when v0(=ret(crime_i2cProbe)) == 0, and falls through when v0(=ret(crime_i2cProbe)) != 0.
  The `bne` branch at 0x5698 targets 0x5498, is taken when s2(?) < v0(=[sym(crm_num_monitors)]) (signed), and falls through when s2(?) >= v0(=[sym(crm_num_monitors)]) (signed).
  The `beq` branch at 0x56a0 targets 0x54b8 and is always taken.
  The `beq` branch at 0x56a8 targets 0x53b0 and is always taken.
  The `blez` branch at 0x56b0 targets 0x56d4, is taken when v0(=[sym(crm_num_monitors)]) <= 0 (signed), and falls through when v0(=[sym(crm_num_monitors)]) > 0 (signed).
  The `beq` branch at 0x56c4 targets 0x54c0, is taken when a4(=[sym(crimeBoards+34)]:2) == 0, and falls through when a4(=[sym(crimeBoards+34)]:2) != 0.
  The `bne` branch at 0x56cc targets 0x56bc, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x56ec targets 0x54c4 and is always taken.
  The `beq` branch at 0x5710 targets 0x5738, is taken when v0(=ret(find_inventory)) == 0, and falls through when v0(=ret(find_inventory)) != 0.
  The `beq` branch at 0x5730 targets 0x5438 and is always taken.
  The `beq` branch at 0x5750 targets 0x5438 and is always taken.
  The `beq` branch at 0x5764 targets 0x55c0 and is always taken.
  The `beq` branch at 0x5778 targets 0x55f8 and is always taken.
  The `beq` branch at 0x578c targets 0x5618 and is always taken.
  The `beq` branch at 0x57a0 targets 0x5638 and is always taken.
  The `beq` branch at 0x57b4 targets 0x565c and is always taken.
  The `beq` branch at 0x57cc targets 0x53b4 and is always taken.
  The return at 0x5668 has v0 = one of ?, ret(cmn_err).

- `crime_init` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x5364 (n32).
  Inferred: it sets up one CRIME board record, because it allocates a 0x230-byte block with
  `kern_malloc` (the `jal` at 0x53bc), fills the block from the board table at `crimeBoards`, and
  passes the block to `GfxRegisterBoard` (the `jal` at 0x552c) and to the vector installs after it.
  It does nothing when the pointer at `crimeBoards`+0x8 is zero (the `beq` at 0x5380); otherwise it
  reads the byte at +0x2e of that record (the `lbu` at 0x5388). When that byte is 0x82, 0x83 or 0x84
  (the `beq` branches at 0x5390 to 0x53a0), the `sw` at 0x56ac clears `gbe_gammawar`; a byte that is
  nonzero and none of those goes to `cmn_err` first (the `jal` at 0x57c4). It calls
  `add_to_inventory` (the `jal` at 0x5400), calls it again when `crm_dc_board_installed` is nonzero
  (the `jal` at 0x5420), and tests the byte against 0x84 (the `beq` at 0x5430); when it matches, the
  routine calls `find_inventory` (the `jal` at 0x5708), then `replace_in_inventory` (the `jal` at
  0x5728) or `add_to_inventory` (the `jal` at 0x5748) on its result. It stores the word at
  `crimeBoards`+0x0 at +0x78 of the block (the `sw` at 0x53d8), the address 0x10 past `crimeBoards`
  at +0x90 (the `sw` at 0x53ec), the record at +0x7c (the `sw` at 0x53f8), the word at
  `crimeBoards`+0x4 at +0x80 (the `sw` at 0x5404), then 0x20 at +0x34, 1 at +0xc, and the `kvpalloc`
  result at +0x84 (the `sw` at 0x5468), which `bzero` clears for 0x600 bytes (the `jal` at 0x5464).
  It calls `init_mutex` on +468 and +476, `mrlock_init` on +484, `spinlock_init` on +540, `init_sv`
  on +556 and `init_mutex` on the global `crm_drawlock` (the `jal` calls at 0x5478 to 0x5514), then
  `crimeRetraceInit` on the block (the `jal` at 0x551c). It writes 0xffffff to the words at 0x10020
  and 0x10024 past the pointer at `crimeBoards`+0x4 (the `sw` at 0x557c and 0x5598), reads the
  8-byte CRIME register at offset 0x28 (the `ld` at 0x554c, linked row CRIME 0x28 Hardware
  Interrupt), clears the bits selected by the mask 0xfffffffffff0ffff (the `ori` at 0x5558) and
  writes the result back (the `sd` at 0x5564). It calls `setcrimevector` for vectors 0x10, 0x11,
  0x1a and 0x19 with `crimeRetraceHandler`, `crimePreblankHandler`, `crimeFifoFullHandler` and
  `crimeFifoEmptyHandler` (the `jal` calls at 0x55e0 to 0x5648), and for `crimeInterrupt` in a loop
  bounded by 0x4 (the `jal` at 0x55ac and the `bne` at 0x55c4); a nonzero return from any of these
  calls goes to `cmn_err` at level 0x4 (the `jal` calls at 0x575c to 0x57ac); after that it calls
  `crime_i2cProbe` (the `jal` at 0x5674), calls `crime_validate_ddc_data` only when the probe
  returns nonzero (the `beq` at 0x567c and the `jal` at 0x5684), and calls `gbeBlankScreen` after
  its monitor loops (the `jal` at 0x56e4).
  Unknown: the text of the messages passed to `cmn_err` at 0x575c to 0x57c4, and the work done
  inside `kern_malloc`, `setcrimevector` and the other callees, since the bundle has no strings and
  no notes for them.
  Evidence grade: inferred.

- `crimeError` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x57d4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x57d4-0x5848 (116 bytes).
  It occupies 116 bytes.
  The `sw` at 0x5800 stores 4 bytes to a0 (arg0 at entry) +0x408.
  The `sw` at 0x5834 stores 4 bytes to a0 (arg0 at entry) +0x400.
  The `jal` at 0x57f0 calls cmn_err with a0=0x4, a1=sym(.rodata)+872, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x57fc calls us_delay with a0=0xa, a1=?, a2=?, a3=?.
  The `jal` at 0x5830 calls flushbus with a0=?, a1=?, a2=(([sym(ib_count)] | ([sym(ib_empty)] << 0xe)) | (([sym(ib_full)] << 0x15) | ([sym(ib_stall)] << 0x7))), a3=(([sym(ib_full)] << 0x15) | ([sym(ib_stall)] << 0x7)), a4=([sym(ib_stall)] << 0x7), a5=([sym(ib_empty)] << 0xe).
  The return at 0x5840 has v0 = ret(flushbus).

- `crime_channel_info` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x589c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x589c-0x58f4 (88 bytes).
  It occupies 88 bytes.
  The `lw` at 0x58a0 loads 4 bytes from sym(crimeBoards) +0x8.
  2 such `lw` accesses load 4 bytes from sym(crmFrameBuffer) +0xb20, including `lw` at 0x58ac, `lw` at 0x58c0.
  The `lh` at 0x58b8 loads 2 bytes from [sym(.bss)+2848] +0x8.
  The `sh` at 0x58bc stores 2 bytes to a0 (arg0 at entry) +0x0.
  The `lh` at 0x58c4 loads 2 bytes from [sym(.bss)+2848] +0xa.
  2 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0x0, including `sh` at 0x58c8, `sh` at 0x58d8.
  2 such `lbu` accesses load 1 byte from sym(crmFrameBuffer) +0xb1d, including `lbu` at 0x58cc, `lbu` at 0x58e0.
  The `beq` branch at 0x58a4 targets 0x58ec, is taken when a4(=sym(.bss)+2800) == 0, and falls through when a4(=sym(.bss)+2800) != 0.
  The `beq` branch at 0x58b0 targets 0x58ec, is taken when a5(=[sym(.bss)+2848]) == 0, and falls through when a5(=[sym(.bss)+2848]) != 0.
  The `beq` branch at 0x58d0 targets 0x58e4, is taken when v0(=[sym(.bss)+2845]:1) == 0, and falls through when v0(=[sym(.bss)+2845]:1) != 0.
  The return at 0x58dc has v0 = [sym(.bss)+2845]:1.
  The return at 0x58e4 has v0 = [sym(.bss)+2845]:1.
  The return at 0x58ec has v0 = 0x0.

- `crime_video_info` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x591c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x591c-0x59c0 (164 bytes).
  It occupies 164 bytes.
  The `lw` at 0x592c loads 4 bytes from (sym(crimeBoards) + (a0 << 0x6)) +0x8.
  The `lbu` at 0x593c loads 1 byte from [(sym(crimeBoards) + (a0 << 0x6))+8] +0x28.
  The `sb` at 0x5940 stores 1 byte to a1 (arg1 at entry) +0x0.
  The `lbu` at 0x5944 loads 1 byte from [(sym(crimeBoards) + (a0 << 0x6))+8] +0x29.
  The `sb` at 0x5948 stores 1 byte to a1 (arg1 at entry) +0x1.
  The `lbu` at 0x594c loads 1 byte from [(sym(crimeBoards) + (a0 << 0x6))+8] +0x2a.
  The `sb` at 0x5950 stores 1 byte to a1 (arg1 at entry) +0x2.
  The `lw` at 0x5954 loads 4 bytes from [(sym(crimeBoards) + (a0 << 0x6))+8] +0x40.
  The `sb` at 0x5968 stores 1 byte to a1 (arg1 at entry) +0x3.
  The `lh` at 0x596c loads 2 bytes from [(sym(crimeBoards) + (a0 << 0x6))+8] +0x3c.
  The `sh` at 0x5970 stores 2 bytes to a1 (arg1 at entry) +0x4.
  The `lh` at 0x5974 loads 2 bytes from [(sym(crimeBoards) + (a0 << 0x6))+8] +0x3e.
  3 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0x8, including `sh` at 0x5978, `sh` at 0x5990, `sh` at 0x59b0.
  The `sh` at 0x597c stores 2 bytes to a1 (arg1 at entry) +0x6.
  The `lw` at 0x5980 loads 4 bytes from [(sym(crimeBoards) + (a0 << 0x6))+8] +0x38.
  The `lw` at 0x5998 loads 4 bytes from (sym(crimeBoards) + (a0 << 0x6)) +0xc.
  The `lw` at 0x59a4 loads 4 bytes from [(sym(crimeBoards) + (a0 << 0x6))+12] +0x88.
  The `beq` branch at 0x5934 targets 0x59b8, is taken when a5(=[(sym(crimeBoards) + (a0 << 0x6))+8]) == 0, and falls through when a5(=[(sym(crimeBoards) + (a0 << 0x6))+8]) != 0.
  The `beq` branch at 0x5988 targets 0x5998, is taken when (a7(=[[(sym(crimeBoards) + (a0 << 0x6))+8]+56]) & 0x2) == 0, and falls through when (a7(=[[(sym(crimeBoards) + (a0 << 0x6))+8]+56]) & 0x2) != 0.
  The `beq` branch at 0x599c targets 0x59b4, is taken when a3(=[(sym(crimeBoards) + (a0 << 0x6))+12]) == 0, and falls through when a3(=[(sym(crimeBoards) + (a0 << 0x6))+12]) != 0.
  The `beq` branch at 0x59a8 targets 0x59b8, is taken when v1(=[[(sym(crimeBoards) + (a0 << 0x6))+12]+136]) == 0, and falls through when v1(=[[(sym(crimeBoards) + (a0 << 0x6))+12]+136]) != 0.
  The return at 0x59b8 has v0 = one of -0x1, 0x0.

- `crm_callvideo` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x59e0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)`.
  Range: 0x59e0-0x5a28 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0x59f0 loads 4 bytes from sym(crimeBoards) +0x4.
  The `lw` at 0x5a0c loads 4 bytes from sym(crimeBoards) +0x18.
  The `lw` at 0x5a1c loads 4 bytes from sym(crimeBoards) +0x1c.
  The `jalr` at 0x5a18 calls (unknown callee) with a0=[sym(crimeBoards+28)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sym(crimeBoards), a4=[sym(crimeBoards+24)], a5=[sym(crimeBoards+4)].
  The `beq` branch at 0x59f4 targets 0x5a0c, is taken when a5(=[sym(crimeBoards+4)]) == a0, and falls through when a5(=[sym(crimeBoards+4)]) != a0.
  The `blez` branch at 0x59fc targets 0x59f0, is taken when a4(?) <= 0 (signed), and falls through when a4(?) > 0 (signed).
  The `beq` branch at 0x5a10 targets 0x5a04, is taken when a4(=[sym(crimeBoards+24)]) == 0, and falls through when a4(=[sym(crimeBoards+24)]) != 0.
  The `beq` branch at 0x5a20 targets 0x5a04 and is always taken.
  The return at 0x5a04 has v0 = one of ?, ret(?).
