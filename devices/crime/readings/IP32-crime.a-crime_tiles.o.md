# Readings: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`

One entry per routine, filed here from the reading batches by binary.

- `crime_tileaddr_for_vice` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x0-0x104 (260 bytes).
  It occupies 260 bytes.
  The `lbu` at 0x34 loads 1 byte from table(sym(RRMrn)) +0x3a.
  The `lw` at 0x50 loads 4 bytes from table(sym(RRMrn)) +0x0.
  The `lw` at 0x60 loads 4 bytes from table(sym(RRMrn)) +0x4c.
  The `lw` at 0x6c loads 4 bytes from [table(sym(RRMrn))+76] +0xc.
  The `lw` at 0x74 loads 4 bytes from [[table(sym(RRMrn))+76]+12] +0x18.
  The `lh` at 0x7c loads 2 bytes from ?.
  The `lbu` at 0x80 loads 1 byte from [[[table(sym(RRMrn))+76]+12]+24] +0x18.
  The `lbu` at 0x9c loads 1 byte from [[[table(sym(RRMrn))+76]+12]+24] +0x19.
  The `lw` at 0xb0 loads 4 bytes from [[[table(sym(RRMrn))+76]+12]+24] +0x4.
  The `lw` at 0xc8 loads 4 bytes from [[[table(sym(RRMrn))+76]+12]+24] +0x8.
  The `lhu` at 0xd0 loads 2 bytes from ?.
  The `sh` at 0xe0 stores 2 bytes to ?.
  The `blez` branch at 0x14 targets 0x48, is taken when a5(?) <= 0 (signed), and falls through when a5(?) > 0 (signed).
  The `beq` branch at 0x20 targets 0x48, is taken when a5(?) >= v0(=[sym(rrm_maxrn)]) (signed), and falls through when a5(?) < v0(=[sym(rrm_maxrn)]) (signed).
  The `beq` branch at 0x38 targets 0x50, is taken when v0(=[table(sym(RRMrn))+58]:1) == 0, and falls through when v0(=[table(sym(RRMrn))+58]:1) != 0.
  The `bne` branch at 0x58 targets 0x40, is taken when t3(=entry(sym(RRMrn))) != a0, and falls through when t3(=entry(sym(RRMrn))) == a0.
  The `beq` branch at 0x64 targets 0x40, is taken when a0(=[table(sym(RRMrn))+76]) == 0, and falls through when a0(=[table(sym(RRMrn))+76]) != 0.
  The `blez` branch at 0x70 targets 0xe4, is taken when a2 <= 0 (signed), and falls through when a2 > 0 (signed).
  The `beq` branch at 0x94 targets 0xec, is taken when a7(?) >= a6(=[[[[table(sym(RRMrn))+76]+12]+24]+24]:1) (signed), and falls through when a7(?) < a6(=[[[[table(sym(RRMrn))+76]+12]+24]+24]:1) (signed).
  The `beq` branch at 0xa4 targets 0xec, is taken when t0(?) >= a3(=[[[[table(sym(RRMrn))+76]+12]+24]+25]:1) (signed), and falls through when t0(?) < a3(=[[[[table(sym(RRMrn))+76]+12]+24]+25]:1) (signed).
  The `beq` branch at 0xc0 targets 0xf4, is taken when a0(?) >= a4(=[[[[table(sym(RRMrn))+76]+12]+24]+4]) (signed), and falls through when a0(?) < a4(=[[[[table(sym(RRMrn))+76]+12]+24]+4]) (signed).
  The `beq` branch at 0xd4 targets 0xfc, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0xdc targets 0x7c, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The return at 0x40 has v0 = 0x13.
  The return at 0x48 has v0 = 0x13.
  The return at 0xe4 has v0 = 0x0.
  The return at 0xec has v0 = 0x16.
  The return at 0xf4 has v0 = 0x16.
  The return at 0xfc has v0 = 0xe.

- `crm_get_dms_tiles` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x104 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x104-0x30c (520 bytes).
  It occupies 520 bytes.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x104, `lw` at 0x138, `lw` at 0x1ac.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x10c, `lw` at 0x1a0, `lw` at 0x248.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x148, `lw` at 0x17c, `lw` at 0x188.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x164, `lw` at 0x2a4.
  The `sw` at 0x170 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `sw` at 0x18c stores 4 bytes to a0 (arg0 at entry) +0x8.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20, including `sw` at 0x1cc, `sw` at 0x1fc, `sw` at 0x270.
  The `lw` at 0x2a0 loads 4 bytes from ?.
  The `sh` at 0x2b4 stores 2 bytes to ?.
  The `sw` at 0x2e0 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `jal` at 0x134 calls dms_block_info with a0=[a0+32], a1=sp-240, a2=?, a3=?.
  The `jal` at 0x174 calls kern_free with a0=[a0+8], a1=?, a2=?, a3=?.
  The `jal` at 0x180 calls kern_malloc with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1a8 calls dms_block_get_tile_list with a0=[a0+32], a1=[a0], a2=[a0+4], a3=?, a4=sp-48.
  The `jal` at 0x1bc calls dms_close with a0=[a0+32], a1=?, a2=?, a3=[a0+32].
  The `jal` at 0x1f4 calls dms_close with a0=[a0+32], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[a0+32].
  The `jal` at 0x208 calls dms_open with a0=a0+32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[a0+32].
  The `jal` at 0x220 calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x230 calls kern_malloc with a0=([a0+4] << 0x2), a1=?, a2=[a0+4], a3=?.
  The `jal` at 0x24c calls dms_block_start_dma with a0=[a0+32], a1=[a0], a2=0x3, a3=[a0+32].
  The `jal` at 0x260 calls dms_close with a0=[a0+32], a1=?, a2=0x0, a3=?.
  The `jal` at 0x2d8 calls crmNextIncarnation with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2ec calls kern_free with a0=?, a1=?, a2=sp-176, a3=?.
  The `jal` at 0x2fc calls kern_free with a0=?, a1=?, a2=?, a3=sp-176.
  The `beq` branch at 0x11c targets 0x1ec, is taken when v0(=[a0]) == 0, and falls through when v0(=[a0]) != 0.
  The `beq` branch at 0x124 targets 0x208, is taken when a3(=[a0+32]) == 0, and falls through when a3(=[a0+32]) != 0.
  The `blez` branch at 0x140 targets 0x284, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `beq` branch at 0x14c targets 0x190, is taken when a2(=[a0+4]) == v0(?), and falls through when a2(=[a0+4]) != v0(?).
  The `bne` branch at 0x154 targets 0x164, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0x15c targets 0x1d8 and is always taken.
  The `beq` branch at 0x16c targets 0x180, is taken when a0(=[a0+8]) == 0, and falls through when a0(=[a0+8]) != 0.
  The `beq` branch at 0x194 targets 0x230, is taken when a2(=[a0+4]) >= 0x21 (signed), and falls through when a2(=[a0+4]) < 0x21 (signed).
  The `beq` branch at 0x1b4 targets 0x244, is taken when v0(=ret(dms_block_get_tile_list)) == 0, and falls through when v0(=ret(dms_block_get_tile_list)) != 0.
  The `bne` branch at 0x1c8 targets 0x220, is taken when s1(?) != a0(=sp-176), and falls through when s1(?) == a0(=sp-176).
  The `beq` branch at 0x1ec targets 0x1fc, is taken when a3(=[a0+32]) == 0, and falls through when a3(=[a0+32]) != 0.
  The `beq` branch at 0x200 targets 0x1d4 and is always taken.
  The `beq` branch at 0x210 targets 0x27c, is taken when v0(=ret(dms_open)) == 0, and falls through when v0(=ret(dms_open)) != 0.
  The `beq` branch at 0x218 targets 0x1d8 and is always taken.
  The `beq` branch at 0x228 targets 0x1d4 and is always taken.
  The `beq` branch at 0x23c targets 0x19c and is always taken.
  The `beq` branch at 0x258 targets 0x28c, is taken when v0(=ret(dms_block_start_dma)) == 0, and falls through when v0(=ret(dms_block_start_dma)) != 0.
  The `bne` branch at 0x26c targets 0x2ec, is taken when s1(?) != a2(=sp-176), and falls through when s1(?) == a2(=sp-176).
  The `beq` branch at 0x274 targets 0x1d4 and is always taken.
  The `beq` branch at 0x27c targets 0x12c and is always taken.
  The `beq` branch at 0x284 targets 0x1d8 and is always taken.
  The `blez` branch at 0x294 targets 0x2d0, is taken when a3(=[a0+4]) <= 0 (signed), and falls through when a3(=[a0+4]) > 0 (signed).
  The `bne` branch at 0x2c8 targets 0x2a0, is taken when v0(?) < a4(=[a0+4]) (signed), and falls through when v0(?) >= a4(=[a0+4]) (signed).
  The `bne` branch at 0x2d0 targets 0x2fc, is taken when s1(?) != a3(=sp-176), and falls through when s1(?) == a3(=sp-176).
  The `beq` branch at 0x2e4 targets 0x1d4 and is always taken.
  The `beq` branch at 0x2f4 targets 0x274 and is always taken.
  The `beq` branch at 0x304 targets 0x2d8 and is always taken.
  The return at 0x1e4 has v0 = one of 0x16, ?, ret(dms_open).

- `crm_tileclassinit` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x30c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x30c-0x3c0 (180 bytes).
  It occupies 180 bytes.
  The `sw` at 0x388 stores 4 bytes to sym(crm_tileusage) +0x18.
  The `sw` at 0x38c stores 4 bytes to sym(crm_tileusage) +0x34.
  The `sw` at 0x390 stores 4 bytes to sym(crm_tileusage) +0x30.
  The `sw` at 0x394 stores 4 bytes to sym(crm_tileusage) +0x28.
  The `sw` at 0x398 stores 4 bytes to sym(crm_tileusage) +0x38.
  The `sw` at 0x39c stores 4 bytes to sym(crm_tileusage) +0x2c.
  The `sw` at 0x3a0 stores 4 bytes to sym(crm_tileusage) +0x24.
  The `sw` at 0x3ac stores 4 bytes to sym(crm_tileusage) +0x20.
  The `jal` at 0x314 calls tile_nclasses with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x330 targets 0x3b0, is taken when v0(=ret(tile_nclasses)) == a5(=0x2), and falls through when v0(=ret(tile_nclasses)) != a5(=0x2).
  The `beq` branch at 0x3b8 targets 0x380 and is always taken.
  The return at 0x3a8 has v0 = ret(tile_nclasses).

- `crmAllocTiles` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x3c0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x3c0-0x4b4 (244 bytes).
  It occupies 244 bytes.
  The `lw` at 0x3f8 loads 4 bytes from sym(crimeBoards) +0x14.
  The `lw` at 0x428 loads 4 bytes from (sym(crime_tile_classes) + (a3 << 0x2)) +0x0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x444, `lw` at 0x460.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0x454, `sh` at 0x47c.
  The `jal` at 0x3e8 calls kern_malloc with a0=(a1 << 0x2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x424 calls tile_alloc with a0=a1 at entry (arg1), a1=ret(kern_malloc), a2=[(sym(crime_tile_classes) + (a3 << 0x2))], a3=?, a4=(a3 << 0x2).
  The `jal` at 0x480 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x4a4 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?, a6=ret(kern_malloc).
  The `beq` branch at 0x400 targets 0x40c, is taken when (s2(=a2) & 0x8) == 0, and falls through when (s2(=a2) & 0x8) != 0.
  The `beq` branch at 0x430 targets 0x4a4, is taken when v0(=ret(tile_alloc)) == 0, and falls through when v0(=ret(tile_alloc)) != 0.
  The `blez` branch at 0x438 targets 0x480, is taken when s0(=a1) <= 0 (signed), and falls through when s0(=a1) > 0 (signed).
  The `beq` branch at 0x458 targets 0x480, is taken when a2(?) >= s0(=a1) (signed), and falls through when a2(?) < s0(=a1) (signed).
  The `bne` branch at 0x478 targets 0x444, is taken when a2(?) < s0(=a1) (signed), and falls through when a2(?) >= s0(=a1) (signed).
  The `beq` branch at 0x4ac targets 0x48c and is always taken.
  The return at 0x49c has v0 = one of 0x0, 0x1.

- `crmFreeTiles` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x4b4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x4b4-0x5e0 (300 bytes).
  It occupies 300 bytes.
  The `lw` at 0x4d0 loads 4 bytes from sym(crimeBoards) +0x0.
  The `lw` at 0x4e4 loads 4 bytes from sym(crimeBoards) +0xc.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x508, `lhu` at 0x524.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x518, `sw` at 0x540.
  The `lw` at 0x558 loads 4 bytes from [sym(crimeBoards)+12] +0x4.
  The `lw` at 0x564 loads 4 bytes from [[sym(crimeBoards)+12]+4] +0x30.
  The `lh` at 0x59c loads 2 bytes from (sym(crm_tileusage) + (a3 + a3)) +0x0.
  The `sh` at 0x5a8 stores 2 bytes to (sym(crm_tileusage) + (a3 + a3)) +0x0.
  The `lh` at 0x5ac loads 2 bytes from sym(crm_tileusage) +0x2.
  The `sh` at 0x5b8 stores 2 bytes to sym(crm_tileusage) +0x2.
  The `jal` at 0x4ec calls kern_malloc with a0=(a1 << 0x2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x544 calls curthreadhandle with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x54c calls gthread_find_gfxp with a0=ret(curthreadhandle), a1=?, a2=?, a3=?.
  The `jal` at 0x578 calls tile_free with a0=a1 at entry (arg1), a1=ret(kern_malloc), a2=0x0, a3=?.
  The `jal` at 0x580 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x5d0 calls crmFifoWait with a0=[sym(crimeBoards)], a1=[sym(ib_full)], a2=0xf4240, a3=?.
  The `blez` branch at 0x4f8 targets 0x544, is taken when s0(=a1) <= 0 (signed), and falls through when s0(=a1) > 0 (signed).
  The `beq` branch at 0x51c targets 0x544, is taken when a5(?) >= s0(=a1) (signed), and falls through when a5(?) < s0(=a1) (signed).
  The `bne` branch at 0x53c targets 0x508, is taken when a5(?) < s0(=a1) (signed), and falls through when a5(?) >= s0(=a1) (signed).
  The `beq` branch at 0x55c targets 0x574, is taken when a1(=[[sym(crimeBoards)+12]+4]) == 0, and falls through when a1(=[[sym(crimeBoards)+12]+4]) != 0.
  The `beq` branch at 0x568 targets 0x5c8, is taken when a2(=[[[sym(crimeBoards)+12]+4]+48]) == v0(=ret(gthread_find_gfxp)), and falls through when a2(=[[[sym(crimeBoards)+12]+4]+48]) != v0(=ret(gthread_find_gfxp)).
  The `beq` branch at 0x5d8 targets 0x574 and is always taken.
  The return at 0x5c0 has v0 = ret(kern_free).

- `crmFreeChunk` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x5e0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x5e0-0x6f0 (272 bytes).
  It occupies 272 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x5e0, `lw` at 0x620, `lw` at 0x6c4.
  The `sw` at 0x5e4 stores 4 bytes to a0 (arg0 at entry) +0x10.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0xc, including `lw` at 0x5f8, `lw` at 0x674, `lw` at 0x690.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x634, `lw` at 0x6a8, `lw` at 0x6cc.
  The `lhu` at 0x63c loads 2 bytes from ?.
  The `sh` at 0x654 stores 2 bytes to ?.
  The `lw` at 0x660 loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The `sw` at 0x684 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `sw` at 0x6b0 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `lbu` at 0x6c0 loads 1 byte from a0 (arg0 at entry) +0x15.
  The `jal` at 0x66c calls bzero with a0=[a0+28]+8, a1=0x400, a2=[a0+28], a3=?.
  The `jal` at 0x688 calls crm_get_dms_tiles with a0=a0 at entry (arg0), a1=?, a2=[a0+12], a3=?.
  The `jal` at 0x6a4 calls bzero with a0=[a0+8], a1=?, a2=?, a3=?.
  The `jal` at 0x6c8 calls crmFreeTiles with a0=[a0+8], a1=[a0+4], a2=[a0+12], a3=[a0+21]:1.
  The `beq` branch at 0x5f0 targets 0x6b4, is taken when a3(=[a0+4]) == 0, and falls through when a3(=[a0+4]) != 0.
  The `beq` branch at 0x604 targets 0x678, is taken when (a2(=[a0+12]) & 0x1) == 0, and falls through when (a2(=[a0+12]) & 0x1) != 0.
  The `blez` branch at 0x60c targets 0x660, is taken when a3(=[a0+4]) <= 0 (signed), and falls through when a3(=[a0+4]) > 0 (signed).
  The `beq` branch at 0x618 targets 0x6e0 and is always taken.
  The `beq` branch at 0x62c targets 0x660, is taken when a0(?) >= v0(=[a0+4]) (signed), and falls through when a0(?) < v0(=[a0+4]) (signed).
  The `beq` branch at 0x640 targets 0x658, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0x658 targets 0x620, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x664 targets 0x674, is taken when a2(=[a0+28]) == 0, and falls through when a2(=[a0+28]) != 0.
  The `beq` branch at 0x67c targets 0x6c0, is taken when (a2(=[a0+12]) & 0x20) == 0, and falls through when (a2(=[a0+12]) & 0x20) != 0.
  The `beq` branch at 0x698 targets 0x6d8, is taken when (t2(=[a0+12]) & 0x1) == 0, and falls through when (t2(=[a0+12]) & 0x1) != 0.
  The `beq` branch at 0x6d0 targets 0x694 and is always taken.
  The `beq` branch at 0x6d8 targets 0x6a0 and is always taken.
  The `beq` branch at 0x6e8 targets 0x638 and is always taken.
  The return at 0x6b8 has v0 = one of ?, ret(bzero).

- `crmAllocChunk` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x6f0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x6f0-0x79c (172 bytes).
  It occupies 172 bytes.
  The `lw` at 0x720 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `sb` at 0x754 stores 1 byte to a0 (arg0 at entry) +0x15.
  The `sb` at 0x758 stores 1 byte to a0 (arg0 at entry) +0x17.
  The `sb` at 0x75c stores 1 byte to a0 (arg0 at entry) +0x16.
  The `sw` at 0x760 stores 4 bytes to a0 (arg0 at entry) +0xc.
  The `sw` at 0x764 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `sw` at 0x76c stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `lh` at 0x774 loads 2 bytes from sym(crm_tileusage) +0x2.
  The `sh` at 0x784 stores 2 bytes to sym(crm_tileusage) +0x2.
  The `lh` at 0x788 loads 2 bytes from (sym(crm_tileusage) + (a3 + a3)) +0x0.
  The `sh` at 0x798 stores 2 bytes to (sym(crm_tileusage) + (a3 + a3)) +0x0.
  The `jal` at 0x71c calls crmAllocTiles with a0=[a0+8], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x74c calls crmNextIncarnation with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x714 targets 0x74c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x724 targets 0x74c, is taken when v0(=ret(crmAllocTiles)) == 0, and falls through when v0(=ret(crmAllocTiles)) != 0.
  The `beq` branch at 0x794 targets 0x72c and is always taken.
  The return at 0x744 has v0 = one of 0x0, 0x1.

- `resizechunk` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x79c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x79c-0x93c (416 bytes).
  It occupies 416 bytes.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x19, including `lbu` at 0x7e8, `lbu` at 0x87c, `lbu` at 0x8c0.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x18, including `lbu` at 0x804, `lbu` at 0x82c, `lbu` at 0x858.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x818, `lw` at 0x8f8.
  3 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x824, `lhu` at 0x850, `lhu` at 0x8b8.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0x828, `sh` at 0x854, `sh` at 0x8bc.
  The `sb` at 0x8e8 stores 1 byte to a0 (arg0 at entry) +0x18.
  The `sb` at 0x8ec stores 1 byte to a0 (arg0 at entry) +0x19.
  The `sw` at 0x8f0 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `sw` at 0x924 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `jal` at 0x7d8 calls kern_malloc with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8fc calls bcopy with a0=ret(kern_malloc), a1=[a0+8], a2=?, a3=[a0+25]:1.
  The `jal` at 0x910 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x918 calls crmNextIncarnation with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0x7fc targets 0x934, is taken when a3(=[a0+25]:1) <= 0 (signed), and falls through when a3(=[a0+25]:1) > 0 (signed).
  The `blez` branch at 0x810 targets 0x844, is taken when t2(=[a0+24]:1) <= 0 (signed), and falls through when t2(=[a0+24]:1) > 0 (signed).
  The `bne` branch at 0x83c targets 0x818, is taken when a7(?) < t2(=[a0+24]:1) (signed), and falls through when a7(?) >= t2(=[a0+24]:1) (signed).
  The `blez` branch at 0x848 targets 0x87c, is taken when v1(?) <= 0 (signed), and falls through when v1(?) > 0 (signed).
  The `bne` branch at 0x874 targets 0x850, is taken when a7(?) < a0(?) (signed), and falls through when a7(?) >= a0(?) (signed).
  The `bne` branch at 0x888 targets 0x810, is taken when t9(?) < a3(=[a0+25]:1) (signed), and falls through when t9(?) >= a3(=[a0+25]:1) (signed).
  The `blez` branch at 0x8b0 targets 0x8e4, is taken when t2(?) <= 0 (signed), and falls through when t2(?) > 0 (signed).
  The `bne` branch at 0x8dc targets 0x8b8, is taken when t9(?) < ra(?) (signed), and falls through when t9(?) >= ra(?) (signed).
  The `beq` branch at 0x934 targets 0x894 and is always taken.
  The return at 0x92c has v0 = ret(crmNextIncarnation).

- `crmResizeFb` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x93c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x93c-0xcb8 (892 bytes).
  It occupies 892 bytes.
  The `lh` at 0x93c loads 2 bytes from a0 (arg0 at entry) +0xa.
  The `lw` at 0x94c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lh` at 0x95c loads 2 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x9ac loads 4 bytes from sym(crmFrameBuffer) +0x4.
  2 such `lbu` accesses load 1 byte from sym(crmFrameBuffer) +0x14, including `lbu` at 0x9b8, `lbu` at 0xb80.
  The `lbu` at 0x9e4 loads 1 byte from sym(crmFrameBuffer) +0x18.
  The `lbu` at 0x9e8 loads 1 byte from sym(crmFrameBuffer) +0x19.
  2 such `lbu` accesses load 1 byte from sym(crmOverlayBuffer) +0x14, including `lbu` at 0xa1c, `lbu` at 0xbd4.
  2 such `lbu` accesses load 1 byte from sym(crmOverlayBuffer) +0x18, including `lbu` at 0xa5c, `lbu` at 0xbf4.
  2 such `lbu` accesses load 1 byte from sym(crmOverlayBuffer) +0x19, including `lbu` at 0xa60, `lbu` at 0xc04.
  2 such `lw` accesses load 4 bytes from sym(crmOverlayBuffer) +0x4, including `lw` at 0xac4, `lw` at 0xbfc.
  The `lw` at 0xb68 loads 4 bytes from sym(crmzbuffer) +0x0.
  The `sb` at 0xb70 stores 1 byte to sym(crmbackbuffer) +0x19.
  The `sb` at 0xb78 stores 1 byte to sym(crmbackbuffer) +0x18.
  The `lbu` at 0xb7c loads 1 byte from [sym(crmzbuffer)] +0x14.
  The `sb` at 0xbb4 stores 1 byte to [sym(crmzbuffer)] +0x19.
  The `sb` at 0xbb8 stores 1 byte to [sym(crmzbuffer)] +0x18.
  The `jal` at 0xae4 calls kern_malloc with a0=?, a1=0x200, a2=?, a3=?.
  The `jal` at 0xafc calls crmAllocTiles with a0=ret(kern_malloc), a1=?, a2=0x8, a3=0x2.
  The `jal` at 0xb0c calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0xb2c calls resizechunk with a0=sym(crmFrameBuffer), a1=ret(kern_malloc), a2=?, a3=?.
  The `jal` at 0xb4c calls resizechunk with a0=sym(crmOverlayBuffer), a1=?, a2=?, a3=?.
  The `jal` at 0xb54 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `beq` branch at 0x974 targets 0x980, is taken when (at(=[a0+4]) & 0x2) == 0, and falls through when (at(=[a0+4]) & 0x2) != 0.
  The `beq` branch at 0x99c targets 0xa80, is taken when s0(?) >= 0x11 (signed), and falls through when s0(?) < 0x11 (signed).
  The `beq` branch at 0x9b0 targets 0xbcc, is taken when a0(=[sym(crmFrameBuffer)+4]) == 0, and falls through when a0(=[sym(crmFrameBuffer)+4]) != 0.
  The `beq` branch at 0x9dc targets 0xbc4, is taken when s1(?) >= 0x11 (signed), and falls through when s1(?) < 0x11 (signed).
  The `bne` branch at 0x9f0 targets 0xa08, is taken when a2(=[sym(crmFrameBuffer)+24]:1) < s1(?) (signed), and falls through when a2(=[sym(crmFrameBuffer)+24]:1) >= s1(?) (signed).
  The `beq` branch at 0x9f8 targets 0xc60, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa00 targets 0xa10 and is always taken.
  The `beq` branch at 0xa08 targets 0xc48, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa54 targets 0xc40, is taken when a2(?) >= 0x4 (signed), and falls through when a2(?) < 0x4 (signed).
  The `bne` branch at 0xa68 targets 0xab4, is taken when a6(=[sym(crmOverlayBuffer)+24]:1) < a2(?) (signed), and falls through when a6(=[sym(crmOverlayBuffer)+24]:1) >= a2(?) (signed).
  The `beq` branch at 0xa70 targets 0xc50, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa78 targets 0xabc and is always taken.
  The `beq` branch at 0xab4 targets 0xac0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0xad0 targets 0xadc, is taken when s3(?) != 0, and falls through when s3(?) == 0.
  The `beq` branch at 0xad8 targets 0xc68, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0xb04 targets 0xb1c, is taken when v0(=ret(crmAllocTiles)) == 0, and falls through when v0(=ret(crmAllocTiles)) != 0.
  The `beq` branch at 0xb14 targets 0xa84 and is always taken.
  The `beq` branch at 0xb1c targets 0xb34, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xb34 targets 0xb54, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0xb5c targets 0xbbc, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xb74 targets 0xbbc, is taken when v0(=[sym(crmzbuffer)]) == 0, and falls through when v0(=[sym(crmzbuffer)]) != 0.
  The `beq` branch at 0xb84 targets 0xbb4, is taken when v1(=[sym(crmFrameBuffer)+20]:1) == a0(=[[sym(crmzbuffer)]+20]:1), and falls through when v1(=[sym(crmFrameBuffer)+20]:1) != a0(=[[sym(crmzbuffer)]+20]:1).
  The `beq` branch at 0xbbc targets 0xa84 and is always taken.
  The `beq` branch at 0xbc4 targets 0xa84 and is always taken.
  The `beq` branch at 0xc08 targets 0xc40, is taken when a2(?) >= 0x4 (signed), and falls through when a2(?) < 0x4 (signed).
  The `bne` branch at 0xc14 targets 0xc70, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0xc1c targets 0xc68, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xc38 targets 0xad8 and is always taken.
  The `beq` branch at 0xc40 targets 0xa84 and is always taken.
  The `beq` branch at 0xc48 targets 0xa10 and is always taken.
  The `beq` branch at 0xc50 targets 0xc68, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xc58 targets 0xae0 and is always taken.
  The `beq` branch at 0xc60 targets 0xa84 and is always taken.
  The `beq` branch at 0xc68 targets 0xa84 and is always taken.
  The `beq` branch at 0xc70 targets 0xc98, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xc90 targets 0xad8 and is always taken.
  The `beq` branch at 0xcb0 targets 0xad8 and is always taken.
  The return at 0xaac has v0 = one of 0x0, 0xc, 0x16.

- `crmAllocBackbuffer` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0xcb8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0xcb8-0xdcc (276 bytes).
  It occupies 276 bytes.
  The `lw` at 0xcb8 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `sw` at 0xd14 stores 4 bytes to a0 (arg0 at entry) +0x8.
  The `sb` at 0xda8 stores 1 byte to a0 (arg0 at entry) +0x14.
  The `sb` at 0xdbc stores 1 byte to a0 (arg0 at entry) +0x19.
  The `sb` at 0xdc8 stores 1 byte to a0 (arg0 at entry) +0x18.
  The `jal` at 0xcf4 calls kern_free with a0=[a0+8], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?, a6=0x10.
  The `jal` at 0xd00 calls bzero with a0=a0 at entry (arg0), a1=0x28, a2=?, a3=?.
  The `jal` at 0xd08 calls kern_malloc with a0=0x200, a1=?, a2=?, a3=?.
  The `jal` at 0xd18 calls bzero with a0=ret(kern_malloc), a1=0x200, a2=?, a3=?.
  The `jal` at 0xd2c calls crmAllocChunk with a0=a0 at entry (arg0), a1=0x0, a2=0xd, a3=0x3.
  The `beq` branch at 0xcd4 targets 0xd4c, is taken when a3 == at(=0x20), and falls through when a3 != at(=0x20).
  The `beq` branch at 0xcdc targets 0xd50, is taken when a3 == a6(=0x10), and falls through when a3 != a6(=0x10).
  The `beq` branch at 0xcec targets 0xcfc, is taken when v0(=[a0+8]) == 0, and falls through when v0(=[a0+8]) != 0.
  The `beq` branch at 0xd34 targets 0xd74, is taken when v0(=ret(crmAllocChunk)) == 0, and falls through when v0(=ret(crmAllocChunk)) != 0.
  The `beq` branch at 0xd6c targets 0xce4 and is always taken.
  The `beq` branch at 0xdc4 targets 0xd3c and is always taken.
  The return at 0xd44 has v0 = one of ret(crmAllocChunk), 0x0.

- `crmAllocPbuffer` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0xdcc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0xdcc-0xeb4 (232 bytes).
  It occupies 232 bytes.
  The `sb` at 0xe90 stores 1 byte to a0 (arg0 at entry) +0x14.
  The `sb` at 0xea4 stores 1 byte to a0 (arg0 at entry) +0x19.
  The `sb` at 0xeb0 stores 1 byte to a0 (arg0 at entry) +0x18.
  The `jal` at 0xe3c calls crmAllocChunk with a0=a0 at entry (arg0), a1=0x0, a2=0xc, a3=0x0.
  The `beq` branch at 0xdfc targets 0xe18, is taken when a3 == at(=0x20), and falls through when a3 != at(=0x20).
  The `beq` branch at 0xe08 targets 0xe18, is taken when a3 == v1(=0x10), and falls through when a3 != v1(=0x10).
  The `bne` branch at 0xe10 targets 0xe34, is taken when a3 != a0(=0x8), and falls through when a3 == a0(=0x8).
  The `beq` branch at 0xe44 targets 0xe5c, is taken when v0(=ret(crmAllocChunk)) == 0, and falls through when v0(=ret(crmAllocChunk)) != 0.
  The `beq` branch at 0xeac targets 0xe4c and is always taken.
  The return at 0xe54 has v0 = one of ret(crmAllocChunk), 0x0.

- `crmAllocPbufTiles` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0xeb4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0xeb4-0xf5c (168 bytes).
  It occupies 168 bytes.
  The `lbu` at 0xeb4 loads 1 byte from a0 (arg0 at entry) +0x19.
  The `lbu` at 0xeb8 loads 1 byte from a0 (arg0 at entry) +0x18.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4, including `sw` at 0xedc, `sw` at 0xf14.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8, including `sw` at 0xee8, `sw` at 0xf1c.
  The `lw` at 0xef0 loads 4 bytes from a0 (arg0 at entry) +0xc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xef8, `lw` at 0xf24.
  The `lw` at 0xf10 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `sb` at 0xf2c stores 1 byte to a0 (arg0 at entry) +0x15.
  The `sw` at 0xf34 stores 4 bytes to a0 (arg0 at entry) +0xc.
  The `jal` at 0xee0 calls kern_malloc with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xefc calls crmAllocChunk with a0=a0 at entry (arg0), a1=[a0+4], a2=[a0+12], a3=0x8.
  The `jal` at 0xf0c calls kern_free with a0=[a0+8], a1=?, a2=?, a3=?.
  The `jal` at 0xf38 calls bzero with a0=ret(kern_malloc), a1=([a0+4] + [a0+4]), a2=([a0+12] | 0x20), a3=0x9.
  The `bne` branch at 0xeec targets 0xf20, is taken when s1(=a1) != 0, and falls through when s1(=a1) == 0.
  The `beq` branch at 0xf04 targets 0xf44, is taken when v0(=ret(crmAllocChunk)) == 0, and falls through when v0(=ret(crmAllocChunk)) != 0.
  The `beq` branch at 0xf18 targets 0xf44 and is always taken.
  The return at 0xf54 has v0 = one of ret(crmAllocChunk), 0x0.

- `crmDestroyPbuffer` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0xf5c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0xf5c-0x1034 (216 bytes).
  It occupies 216 bytes.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0xf5c, `lw` at 0xf90, `lw` at 0xf94.
  3 such `lw` accesses load 4 bytes from [a0+32] +0x1c, including `lw` at 0xf74, `lw` at 0xfb0, `lw` at 0xfc4.
  2 such `lw` accesses load 4 bytes from [[a0+32]+28] +0x4, including `lw` at 0xf80, `lw` at 0xfb8.
  The `lw` at 0xf98 loads 4 bytes from [a0+32] +0x8.
  The `sw` at 0xfd0 stores 4 bytes to a0 (arg0 at entry) +0x20.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0xfd4, `lw` at 0xfe8, `lw` at 0x1000.
  The `lw` at 0xfec loads 4 bytes from [a0+24] +0x8.
  The `sw` at 0x100c stores 4 bytes to a0 (arg0 at entry) +0x18.
  The `jal` at 0xf7c calls psema with a0=[[[a0+32]+28]+4], a1=0x11a, a2=a2 at entry (arg2), a3=[a0+32].
  The `jal` at 0xf8c calls crmFreeChunk with a0=[a0+32], a1=?, a2=?, a3=?.
  The `jal` at 0xfa4 calls kern_free with a0=[[a0+32]+8], a1=?, a2=?, a3=[a0+32].
  The `jal` at 0xfb4 calls vsema with a0=[[[a0+32]+28]+4], a1=?, a2=?, a3=[a0+32].
  The `jal` at 0xfc0 calls kern_free with a0=[[a0+32]+28], a1=?, a2=?, a3=?.
  The `jal` at 0xfc8 calls kern_free with a0=[a0+32], a1=?, a2=?, a3=?.
  The `jal` at 0xfe0 calls crmFreeChunk with a0=[a0+24], a1=?, a2=?, a3=?.
  The `jal` at 0xff8 calls kern_free with a0=[[a0+24]+8], a1=?, a2=[[a0+24]+8], a3=?.
  The `jal` at 0x1004 calls kern_free with a0=[a0+24], a1=?, a2=?, a3=?.
  The `jal` at 0x1024 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0xf6c targets 0xfd4, is taken when a3(=[a0+32]) == 0, and falls through when a3(=[a0+32]) != 0.
  The `bne` branch at 0xf84 targets 0x1020, is taken when v0(=ret(psema)) != 0, and falls through when v0(=ret(psema)) == 0.
  The `beq` branch at 0xf9c targets 0xfb0, is taken when a0(=[[a0+32]+8]) == 0, and falls through when a0(=[[a0+32]+8]) != 0.
  The `beq` branch at 0xfd8 targets 0x1014, is taken when a0(=[a0+24]) == 0, and falls through when a0(=[a0+24]) != 0.
  The `beq` branch at 0xff0 targets 0x1004, is taken when a2(=[[a0+24]+8]) == 0, and falls through when a2(=[[a0+24]+8]) != 0.
  The `beq` branch at 0x102c targets 0x1014 and is always taken.
  The return at 0x1018 has v0 = one of ?, ret(kern_free), ret(cmn_err).

- `crmAllocFrameBuffer` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x1034 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x1034-0x1128 (244 bytes).
  It occupies 244 bytes.
  The `sb` at 0x1104 stores 1 byte to a0 (arg0 at entry) +0x18.
  The `sb` at 0x1114 stores 1 byte to a0 (arg0 at entry) +0x19.
  The `sb` at 0x1124 stores 1 byte to a0 (arg0 at entry) +0x14.
  The `jal` at 0x10c8 calls crmAllocChunk with a0=a0 at entry (arg0), a1=?, a2=0xc, a3=0x2, a6=a2 at entry (arg2), a7=a1 at entry (arg1).
  The `beq` branch at 0x1064 targets 0x10e8, is taken when a3 == at(=0x20), and falls through when a3 != at(=0x20).
  The `beq` branch at 0x1070 targets 0x10e8, is taken when a3 == v0(=0x10), and falls through when a3 != v0(=0x10).
  The `beq` branch at 0x1078 targets 0x10e8, is taken when a3 == v1(=0x8), and falls through when a3 != v1(=0x8).
  The `beq` branch at 0x10d0 targets 0x10fc, is taken when v0(=ret(crmAllocChunk)) == 0, and falls through when v0(=ret(crmAllocChunk)) != 0.
  The `beq` branch at 0x10f4 targets 0x1080 and is always taken.
  The `beq` branch at 0x1120 targets 0x10d8 and is always taken.
  The return at 0x10e0 has v0 = one of ret(crmAllocChunk), 0x0.

- `crmAllocOverlayBuffer` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x1128 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x1128-0x11ac (132 bytes).
  It occupies 132 bytes.
  The `sb` at 0x1194 stores 1 byte to a0 (arg0 at entry) +0x18.
  The `sb` at 0x119c stores 1 byte to a0 (arg0 at entry) +0x19.
  The `sb` at 0x11a0 stores 1 byte to a0 (arg0 at entry) +0x14.
  The `jal` at 0x1170 calls crmAllocChunk with a0=a0 at entry (arg0), a1=?, a2=0x1c, a3=0x5.
  The `beq` branch at 0x1178 targets 0x1188, is taken when v0(=ret(crmAllocChunk)) == 0, and falls through when v0(=ret(crmAllocChunk)) != 0.
  The `beq` branch at 0x11a4 targets 0x1180 and is always taken.
  The return at 0x1180 has v0 = one of ret(crmAllocChunk), 0x0.

- `crmAllocCid` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x11ac (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x11ac-0x12b8 (268 bytes).
  It occupies 268 bytes.
  The `lw` at 0x11cc loads 4 bytes from a0 (arg0 at entry) +0x4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x123c, `lw` at 0x1288.
  The `lbu` at 0x1270 loads 1 byte from sym(crmOverlayBuffer) +0x18.
  The `lw` at 0x1278 loads 4 bytes from sym(crmOverlayBuffer) +0x8.
  The `lhu` at 0x129c loads 2 bytes from ?.
  The `sh` at 0x12a8 stores 2 bytes to ?.
  The `sw` at 0x12ac stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `jal` at 0x11f8 calls crmAllocChunk with a0=a0 at entry (arg0), a1=0x0, a2=0x10, a3=0x0.
  The `jal` at 0x1224 calls crmAllocChunk with a0=a0 at entry (arg0), a1=?, a2=0x8, a3=0x0.
  The `jal` at 0x1238 calls bzero with a0=[a0+8], a1=0x20, a2=?, a3=?.
  The `beq` branch at 0x11c4 targets 0x11f0, is taken when a1 == at(=0x500), and falls through when a1 != at(=0x500).
  The `beq` branch at 0x11d0 targets 0x1210, is taken when v1(=[a0+4]) == 0, and falls through when v1(=[a0+4]) != 0.
  The `beq` branch at 0x1200 targets 0x1234, is taken when v0(=ret(crmAllocChunk)) == 0, and falls through when v0(=ret(crmAllocChunk)) != 0.
  The `beq` branch at 0x1208 targets 0x11e0 and is always taken.
  The `beq` branch at 0x122c targets 0x11dc and is always taken.
  The `blez` branch at 0x1258 targets 0x12ac, is taken when a4(?) <= 0 (signed), and falls through when a4(?) > 0 (signed).
  The `bne` branch at 0x12a4 targets 0x1270, is taken when v0(?) < a4(?) (signed), and falls through when v0(?) >= a4(?) (signed).
  The `beq` branch at 0x12b0 targets 0x11dc and is always taken.
  The return at 0x11e8 has v0 = one of ?, ret(crmAllocChunk).

- `crmAllocGbeTables` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x12b8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x12b8-0x12dc (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x12c8 calls crmAllocChunk with a0=a0 at entry (arg0), a1=0x4, a2=0x0, a3=0x0.
  The return at 0x12d4 has v0 = ret(crmAllocChunk).

- `crmAllocZbuffer` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x12dc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x12dc-0x13e4 (264 bytes).
  It occupies 264 bytes.
  The `lw` at 0x12e8 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `sw` at 0x1310 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `sw` at 0x1330 stores 4 bytes to ret(kern_malloc) +0x8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x0, including `sw` at 0x1344, `sw` at 0x1384.
  The `sw` at 0x1350 stores 4 bytes to ret(kern_malloc) +0x1c.
  The `lw` at 0x1378 loads 4 bytes from ret(kern_malloc) +0x8.
  The `sb` at 0x13ac stores 1 byte to ret(kern_malloc) +0x14.
  The `sb` at 0x13c0 stores 1 byte to ret(kern_malloc) +0x18.
  The `sb` at 0x13cc stores 1 byte to ret(kern_malloc) +0x19.
  The `jal` at 0x1300 calls bzero with a0=a0 at entry (arg0), a1=0x408, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x130c calls kern_malloc with a0=0x28, a1=?, a2=?, a3=?.
  The `jal` at 0x131c calls bzero with a0=ret(kern_malloc), a1=0x28, a2=?, a3=?.
  The `jal` at 0x1324 calls kern_malloc with a0=0x200, a1=?, a2=?, a3=?.
  The `jal` at 0x1334 calls bzero with a0=ret(kern_malloc), a1=0x200, a2=?, a3=?.
  The `jal` at 0x1360 calls crmAllocChunk with a0=ret(kern_malloc), a1=0x0, a2=0xd, a3=one of 0x4, 0x8.
  The `jal` at 0x1374 calls kern_free with a0=[ret(kern_malloc)+8], a1=?, a2=?, a3=?, a4=0x4.
  The `jal` at 0x137c calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `beq` branch at 0x134c targets 0x1358, is taken when s1(=a0) == at(=sym(crmzbuffer)), and falls through when s1(=a0) != at(=sym(crmzbuffer)).
  The `beq` branch at 0x136c targets 0x1390, is taken when v0(=ret(crmAllocChunk)) == 0, and falls through when v0(=ret(crmAllocChunk)) != 0.
  The `beq` branch at 0x1388 targets 0x13d0 and is always taken.
  The return at 0x13dc has v0 = one of ret(crmAllocChunk), 0x0.

- `crmAllocTex` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x13e4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x13e4-0x15ec (520 bytes).
  It occupies 520 bytes.
  The `lw` at 0x13ec loads 4 bytes from a2 (arg2 at entry) +0x4.
  The `lw` at 0x1414 loads 4 bytes from a1 (arg1 at entry) +0x20.
  The `lw` at 0x1428 loads 4 bytes from a2 (arg2 at entry) +0x8.
  3 such `lw` accesses load 4 bytes from ret(kern_malloc) +0x8, including `lw` at 0x1474, `lw` at 0x14ec, `lw` at 0x157c.
  The `lw` at 0x14d4 loads 4 bytes from a2 (arg2 at entry) +0x0.
  3 such `sw` accesses store 4 bytes to ret(kern_malloc) +0x0, including `sw` at 0x14d8, `sw` at 0x156c, `sw` at 0x15b0.
  2 such `sw` accesses store 4 bytes to ret(kern_malloc) +0x8, including `sw` at 0x154c, `sw` at 0x15c0.
  The `lw` at 0x1550 loads 4 bytes from a0 (arg0 at entry) +0x138.
  The `sw` at 0x1558 stores 4 bytes to a0 (arg0 at entry) +0x138.
  The `sw` at 0x1560 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `sw` at 0x15b8 stores 4 bytes to ret(kern_malloc) +0x4.
  The `lw` at 0x15bc loads 4 bytes from [a1+32] +0x18.
  The `sw` at 0x15c8 stores 4 bytes to [a1+32] +0x18.
  The `sw` at 0x15d8 stores 4 bytes to a2 (arg2 at entry) +0xc.
  The `jal` at 0x143c calls kern_malloc with a0=0x28, a1=?, a2=?, a3=?.
  The `jal` at 0x144c calls bzero with a0=ret(kern_malloc), a1=0x28, a2=?, a3=?.
  The `jal` at 0x1464 calls crmAllocChunk with a0=ret(kern_malloc), a1=[a2+4], a2=one of 0x2, 0x22, a3=?.
  The `jal` at 0x1480 calls kern_free with a0=[ret(kern_malloc)+8], a1=?, a2=?, a3=?.
  The `jal` at 0x1488 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x14dc calls crm_get_dms_tiles with a0=ret(kern_malloc), a1=?, a2=?, a3=a0 at entry (arg0).
  The `jal` at 0x14f8 calls kern_free with a0=[ret(kern_malloc)+8], a1=?, a2=?, a3=?.
  The `jal` at 0x1500 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x1514 calls psema with a0=[a1+32]+16, a1=0x11a, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x152c calls vsema with a0=[a1+32]+16, a1=?, a2=?, a3=?.
  The `jal` at 0x153c calls kern_malloc with a0=([a2+4] + [a2+4]), a1=?, a2=0x22, a3=?.
  The `jal` at 0x1568 calls crmMapChunk with a0=ret(kern_malloc), a1=sp-80, a2=[a0+312]+1, a3=a0 at entry (arg0).
  The `jal` at 0x1578 calls kern_free with a0=[ret(kern_malloc)+8], a1=?, a2=?, a3=?.
  The `jal` at 0x1580 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x1588 calls vsema with a0=[a1+32]+16, a1=?, a2=?, a3=?.
  The `jal` at 0x1598 calls kern_malloc with a0=0xc, a1=?, a2=?, a3=?.
  The `jal` at 0x15a8 calls bzero with a0=ret(kern_malloc), a1=0xc, a2=?, a3=?.
  The `jal` at 0x15dc calls vsema with a0=[a1+32]+16, a1=?, a2=?, a3=[[a1+32]+24].
  The `beq` branch at 0x140c targets 0x14b8, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x1418 targets 0x14b8, is taken when s3(=[a1+32]) == 0, and falls through when s3(=[a1+32]) != 0.
  The `beq` branch at 0x1420 targets 0x1510, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0x1430 targets 0x14c0, is taken when (at(=[a2+8]) & 0x1) == 0, and falls through when (at(=[a2+8]) & 0x1) != 0.
  The `beq` branch at 0x1454 targets 0x153c, is taken when s1(=a3) == 0, and falls through when s1(=a3) != 0.
  The `beq` branch at 0x146c targets 0x14cc, is taken when v0(=ret(crmAllocChunk)) == 0, and falls through when v0(=ret(crmAllocChunk)) != 0.
  The `beq` branch at 0x1478 targets 0x1488, is taken when a0(=[ret(kern_malloc)+8]) == 0, and falls through when a0(=[ret(kern_malloc)+8]) != 0.
  The `beq` branch at 0x1490 targets 0x152c, is taken when s1(=a3) == 0, and falls through when s1(=a3) != 0.
  The `beq` branch at 0x14b8 targets 0x1498 and is always taken.
  The `beq` branch at 0x14c4 targets 0x143c and is always taken.
  The `beq` branch at 0x14cc targets 0x1550, is taken when s1(=a3) == 0, and falls through when s1(=a3) != 0.
  The `beq` branch at 0x14e4 targets 0x1598, is taken when v0(=ret(crm_get_dms_tiles)) == 0, and falls through when v0(=ret(crm_get_dms_tiles)) != 0.
  The `beq` branch at 0x14f0 targets 0x1500, is taken when a0(=[ret(kern_malloc)+8]) == 0, and falls through when a0(=[ret(kern_malloc)+8]) != 0.
  The `beq` branch at 0x1508 targets 0x1498 and is always taken.
  The `beq` branch at 0x151c targets 0x1428, is taken when v0(=ret(psema)) == 0, and falls through when v0(=ret(psema)) != 0.
  The `beq` branch at 0x1524 targets 0x1498 and is always taken.
  The `beq` branch at 0x1534 targets 0x1498 and is always taken.
  The `beq` branch at 0x1548 targets 0x145c and is always taken.
  The `beq` branch at 0x1570 targets 0x1598, is taken when v0(=ret(crmMapChunk)) == 0, and falls through when v0(=ret(crmMapChunk)) != 0.
  The `beq` branch at 0x1590 targets 0x1498 and is always taken.
  The `beq` branch at 0x15c4 targets 0x15dc, is taken when s1(=a3) == 0, and falls through when s1(=a3) != 0.
  The `beq` branch at 0x15d4 targets 0x1498 and is always taken.
  The `beq` branch at 0x15e4 targets 0x15d0 and is always taken.
  The return at 0x14b0 has v0 = one of ret(crmAllocChunk), 0x16, ret(crm_get_dms_tiles), 0x4, ret(crmMapChunk), 0x0.

- `crmFreeTex` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x15ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x15ec-0x1798 (428 bytes).
  It occupies 428 bytes.
  The `lw` at 0x1648 loads 4 bytes from a1 (arg1 at entry) +0xc.
  The `sw` at 0x1654 stores 4 bytes to a1 (arg1 at entry) +0xc.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x1670, `lw` at 0x168c.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x0, including `lw` at 0x1678, `lw` at 0x1680.
  The `sw` at 0x167c stores 4 bytes to [a1+4] +0x0.
  The `sw` at 0x1690 stores 4 bytes to [a1] +0x4.
  The `lw` at 0x169c loads 4 bytes from a1 (arg1 at entry) +0x18.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x16bc, `lw` at 0x16e0, `lw` at 0x16ec.
  The `sw` at 0x1744 stores 4 bytes to ?.
  The `sw` at 0x1794 stores 4 bytes to a0 (arg0 at entry) +0x1c8.
  The `jal` at 0x1610 calls psema with a0=a1+16, a1=0x11a, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1640 calls mutex_lock with a0=a0+476, a1=0x19, a2=?, a3=?.
  The `jal` at 0x1658 calls vsema with a0=a1+16, a1=[a1+12]-1, a2=?, a3=?.
  The `jal` at 0x1660 calls mutex_unlock with a0=a0+476, a1=?, a2=?, a3=?.
  The `jal` at 0x1694 calls mutex_unlock with a0=a0+476, a1=[a1+12]-1, a2=?, a3=?, a4=[a1+4].
  The `jal` at 0x16b4 calls crmFreeChunk with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x16c8 calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x16d0 calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x16dc calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x170c calls crmUnmapChunk with a0=?, a1=?, a2=?, a3=?, a4=a2 at entry (arg2).
  The `jal` at 0x172c calls kmem_free with a0=?, a1=0x1d0, a2=?, a3=?.
  The `jal` at 0x1764 calls vsema with a0=a1+16, a1=?, a2=?, a3=?.
  The `jal` at 0x1774 calls freesema with a0=a1+16, a1=?, a2=?, a3=?.
  The `jal` at 0x177c calls kern_free with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1618 targets 0x1634, is taken when v0(=ret(psema)) == 0, and falls through when v0(=ret(psema)) != 0.
  The `blez` branch at 0x1650 targets 0x1670, is taken when a1(=[a1+12]-1) <= 0 (signed), and falls through when a1(=[a1+12]-1) > 0 (signed).
  The `beq` branch at 0x1668 targets 0x1620 and is always taken.
  The `beq` branch at 0x1674 targets 0x178c, is taken when a4(=[a1+4]) == 0, and falls through when a4(=[a1+4]) != 0.
  The `beq` branch at 0x1684 targets 0x1694, is taken when v0(=[a1]) == 0, and falls through when v0(=[a1]) != 0.
  The `beq` branch at 0x16a4 targets 0x1720, is taken when v0(=[a1+24]) == 0, and falls through when v0(=[a1+24]) != 0.
  The `beq` branch at 0x16ac targets 0x16ec and is always taken.
  The `beq` branch at 0x16c0 targets 0x16d0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x16e4 targets 0x171c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x16fc targets 0x16b4, is taken when (a3(?) & 0x20) != 0, and falls through when (a3(?) & 0x20) == 0.
  The `bne` branch at 0x1704 targets 0x16b4, is taken when a4(=a2) != 0, and falls through when a4(=a2) == 0.
  The `beq` branch at 0x1714 targets 0x16b4 and is always taken.
  The `beq` branch at 0x1724 targets 0x1748 and is always taken.
  The `beq` branch at 0x1740 targets 0x1764, is taken when s2(?) >= 0x80 (unsigned), and falls through when s2(?) < 0x80 (unsigned).
  The `bne` branch at 0x174c targets 0x172c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `bne` branch at 0x175c targets 0x1748, is taken when s2(?) < 0x80 (unsigned), and falls through when s2(?) >= 0x80 (unsigned).
  The `beq` branch at 0x1784 targets 0x1620 and is always taken.
  The `beq` branch at 0x1790 targets 0x1680 and is always taken.
  The return at 0x162c has v0 = one of -0x1, 0x0.

- `crmDeallocTex` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x1798 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x1798-0x18d0 (312 bytes).
  It occupies 312 bytes.
  The `lw` at 0x179c loads 4 bytes from a0 (arg0 at entry) +0x4c.
  The `lw` at 0x17b8 loads 4 bytes from [a0+76] +0x20.
  The `lw` at 0x17f4 loads 4 bytes from [[a0+76]+32] +0x18.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1810, `lw` at 0x1824, `lw` at 0x1830.
  The `sw` at 0x18a4 stores 4 bytes to ?.
  The `sw` at 0x18cc stores 4 bytes to [[a0+76]+32] +0x18.
  The `jal` at 0x17cc calls psema with a0=[[a0+76]+32]+16, a1=0x11a, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a0+76].
  The `jal` at 0x1848 calls vsema with a0=[[a0+76]+32]+16, a1=?, a2=?, a3=?.
  The `jal` at 0x186c calls crmUnmapChunk with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1874 calls crmFreeChunk with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1888 calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1890 calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x18ac calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x18b8 calls vsema with a0=[[a0+76]+32]+16, a1=?, a2=?, a3=?.
  The `beq` branch at 0x17b0 targets 0x17e0, is taken when a4(=[a0+76]) == 0, and falls through when a4(=[a0+76]) != 0.
  The `beq` branch at 0x17bc targets 0x1864, is taken when s2(=[[a0+76]+32]) == 0, and falls through when s2(=[[a0+76]+32]) != 0.
  The `beq` branch at 0x17d4 targets 0x17f4, is taken when v0(=ret(psema)) == 0, and falls through when v0(=ret(psema)) != 0.
  The `beq` branch at 0x17fc targets 0x1848, is taken when s0(=[[[a0+76]+32]+24]) == 0, and falls through when s0(=[[[a0+76]+32]+24]) != 0.
  The `beq` branch at 0x1808 targets 0x1830 and is always taken.
  The `beq` branch at 0x181c targets 0x186c, is taken when 0 >= at(?) (unsigned), and falls through when 0 < at(?) (unsigned).
  The `beq` branch at 0x1828 targets 0x1848, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1838 targets 0x1810, is taken when v0(?) == s3(=a1), and falls through when v0(?) != s3(=a1).
  The `beq` branch at 0x1840 targets 0x1824 and is always taken.
  The `beq` branch at 0x185c targets 0x17e0 and is always taken.
  The `beq` branch at 0x1864 targets 0x17e4 and is always taken.
  The `beq` branch at 0x1880 targets 0x1890, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x189c targets 0x18c8, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0x18c0 targets 0x17e0 and is always taken.
  The `beq` branch at 0x18c8 targets 0x18a8 and is always taken.
  The return at 0x17ec has v0 = one of 0x0, 0x4, 0x16.

- `crmDefineTex` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x18d0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x18d0-0x1d28 (1112 bytes).
  It occupies 1112 bytes.
  The `lw` at 0x18d8 loads 4 bytes from a2 (arg2 at entry) +0x8.
  The `lw` at 0x18e0 loads 4 bytes from a2 (arg2 at entry) +0x4.
  The `lw` at 0x18f8 loads 4 bytes from a1 (arg1 at entry) +0x4c.
  The `lw` at 0x1914 loads 4 bytes from [a1+76] +0x20.
  The `lw` at 0x1924 loads 4 bytes from a1 (arg1 at entry) +0x30.
  The `lw` at 0x1930 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `sw` at 0x1958 stores 4 bytes to a2 (arg2 at entry) +0x0.
  14 such `lw` accesses load 4 bytes from ?, including `lw` at 0x19c4, `lw` at 0x1a34, `lw` at 0x1a6c.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x19e8, `sd` at 0x19f8, `sd` at 0x1a10.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x1ad4, `lhu` at 0x1b28.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0x1ae8, `sh` at 0x1b30.
  The `sw` at 0x1ccc stores 4 bytes to ?.
  The `lw` at 0x1cd4 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `sd` at 0x1d08 stores 8 bytes to ret(kmem_alloc) +0x1c0.
  The `jal` at 0x1920 calls RRM_CheckValidFault with a0=[a1+48], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1998 calls psema with a0=[[a1+76]+32]+16, a1=0x11a, a2=?, a3=?.
  The `jal` at 0x1b88 calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1b98 calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c2c calls crmAllocTex with a0=a0 at entry (arg0), a1=?, a2=sp-160, a3=0x1.
  The `jal` at 0x1c64 calls crm_get_dms_tiles with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c7c calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c8c calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c9c calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1cb0 calls kmem_alloc with a0=0x1d0, a1=0x900, a2=?, a3=?.
  The `jal` at 0x1cc8 calls bzero with a0=ret(kmem_alloc), a1=0x1d0, a2=?, a3=?.
  The `jal` at 0x1d0c calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x190c targets 0x1ba8, is taken when s4(=[a1+76]) == 0, and falls through when s4(=[a1+76]) != 0.
  The `beq` branch at 0x1918 targets 0x19b0, is taken when s1(=[[a1+76]+32]) == 0, and falls through when s1(=[[a1+76]+32]) != 0.
  The `bltz` branch at 0x1928 targets 0x1bb0, is taken when v0(=ret(RRM_CheckValidFault)) < 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) >= 0 (signed).
  The `beq` branch at 0x193c targets 0x19b8, is taken when (v0(=[a2]) & at(=0xffffffff80000000)) == 0, and falls through when (v0(=[a2]) & at(=0xffffffff80000000)) != 0.
  The `bne` branch at 0x1954 targets 0x1990, is taken when s5(?) < 0x80 (unsigned), and falls through when s5(?) >= 0x80 (unsigned).
  The `beq` branch at 0x19a0 targets 0x19c0, is taken when v0(=ret(psema)) == 0, and falls through when v0(=ret(psema)) != 0.
  The `beq` branch at 0x19a8 targets 0x1960 and is always taken.
  The `beq` branch at 0x19b0 targets 0x1960 and is always taken.
  The `beq` branch at 0x19b8 targets 0x1944 and is always taken.
  The `beq` branch at 0x19d0 targets 0x1cac, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x19ec targets 0x1a14, is taken when a5(?) >= 0x1d (unsigned), and falls through when a5(?) < 0x1d (unsigned).
  The `beq` branch at 0x19fc targets 0x1a14, is taken when a5(?) >= 0x1d (unsigned), and falls through when a5(?) < 0x1d (unsigned).
  The `bne` branch at 0x1a0c targets 0x19e0, is taken when a5(?) < 0x1d (unsigned), and falls through when a5(?) >= 0x1d (unsigned).
  The `beq` branch at 0x1a38 targets 0x1b50, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x1a40 targets 0x1bb8, is taken when s3(=one of 0x0, 0x20) == 0, and falls through when s3(=one of 0x0, 0x20) != 0.
  The `beq` branch at 0x1a48 targets 0x1bbc, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1a50 targets 0x1a68, is taken when s3(=one of 0x0, 0x20) == 0, and falls through when s3(=one of 0x0, 0x20) != 0.
  The `beq` branch at 0x1a60 targets 0x1c64, is taken when a1(?) == t2(=0x1), and falls through when a1(?) != t2(=0x1).
  The `bne` branch at 0x1a78 targets 0x1c8c, is taken when t3(?) < t8(?) (signed), and falls through when t3(?) >= t8(?) (signed).
  The `beq` branch at 0x1a80 targets 0x1c5c, is taken when s3(=one of 0x0, 0x20) == 0, and falls through when s3(=one of 0x0, 0x20) != 0.
  The `beq` branch at 0x1a8c targets 0x1b50, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0x1a94 targets 0x1b34, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x1a9c targets 0x1d1c and is always taken.
  The `beq` branch at 0x1aac targets 0x1b98, is taken when s0(?) >= t9(?) (unsigned), and falls through when s0(?) < t9(?) (unsigned).
  The `beq` branch at 0x1af0 targets 0x1b34, is taken when a5(?) >= s2(?) (unsigned), and falls through when a5(?) < s2(?) (unsigned).
  The `beq` branch at 0x1af8 targets 0x1aa4, is taken when s3(=one of 0x0, 0x20) == 0, and falls through when s3(=one of 0x0, 0x20) != 0.
  The `bne` branch at 0x1b00 targets 0x1aa4, is taken when s6(=0x5) != s5(?), and falls through when s6(=0x5) == s5(?).
  The `beq` branch at 0x1b2c targets 0x1aec and is always taken.
  The `beq` branch at 0x1b3c targets 0x1c54, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `bne` branch at 0x1b48 targets 0x1a94, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x1b58 targets 0x1b80, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x1b68 targets 0x1b74, is taken when s2(?) < 0x2 (signed), and falls through when s2(?) >= 0x2 (signed).
  The `bne` branch at 0x1b74 targets 0x1b80, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bne` branch at 0x1b80 targets 0x1a34, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x1b90 targets 0x1960 and is always taken.
  The `beq` branch at 0x1ba0 targets 0x1960 and is always taken.
  The `beq` branch at 0x1ba8 targets 0x1960 and is always taken.
  The `beq` branch at 0x1bb0 targets 0x1960 and is always taken.
  The `beq` branch at 0x1bc0 targets 0x1c04, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1bc8 targets 0x1be0 and is always taken.
  The `beq` branch at 0x1bd4 targets 0x1c04, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1be4 targets 0x1bd0, is taken when v1(?) != a6(?), and falls through when v1(?) == a6(?).
  The `bne` branch at 0x1bf4 targets 0x1bd0, is taken when s3(=one of 0x0, 0x20) != a3(?), and falls through when s3(=one of 0x0, 0x20) == a3(?).
  The `bne` branch at 0x1bfc targets 0x1a50, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x1c0c targets 0x1d0c, is taken when s3(=one of 0x0, 0x20) == 0, and falls through when s3(=one of 0x0, 0x20) != 0.
  The `bne` branch at 0x1c3c targets 0x1c9c, is taken when v0(=ret(crmAllocTex)) != 0, and falls through when v0(=ret(crmAllocTex)) == 0.
  The `beq` branch at 0x1c4c targets 0x1a68 and is always taken.
  The `beq` branch at 0x1c54 targets 0x1b44 and is always taken.
  The `beq` branch at 0x1c5c targets 0x1a88 and is always taken.
  The `beq` branch at 0x1c74 targets 0x1a68, is taken when v0(=ret(crm_get_dms_tiles)) == 0, and falls through when v0(=ret(crm_get_dms_tiles)) != 0.
  The `beq` branch at 0x1c84 targets 0x1960 and is always taken.
  The `beq` branch at 0x1c94 targets 0x1960 and is always taken.
  The `beq` branch at 0x1ca4 targets 0x1960 and is always taken.
  The `bne` branch at 0x1cfc targets 0x1ce4, is taken when a2(?) < 0x1c (unsigned), and falls through when a2(?) >= 0x1c (unsigned).
  The `beq` branch at 0x1d04 targets 0x1a14 and is always taken.
  The `beq` branch at 0x1d14 targets 0x1960 and is always taken.
  The `beq` branch at 0x1d20 targets 0x1af8 and is always taken.
  The return at 0x1988 has v0 = one of 0x0, 0x4, 0x16.

- `crmLoadTexTlb` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x1d28 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x1d28-0x1d8c (100 bytes).
  It occupies 100 bytes.
  The `lw` at 0x1d28 loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The `lw` at 0x1d2c loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `lw` at 0x1d40 loads 4 bytes from ([a0+32] + ([a0+28] << 0x2)) +0x20.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1d44, `lw` at 0x1d64.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1d50, `ld` at 0x1d70.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1d58, `sd` at 0x1d80.
  The `beq` branch at 0x1d5c targets 0x1d84, is taken when a2(?) >= 0x1c (unsigned), and falls through when a2(?) < 0x1c (unsigned).
  The `bne` branch at 0x1d7c targets 0x1d44, is taken when a2(?) < 0x1c (unsigned), and falls through when a2(?) >= 0x1c (unsigned).
  The return at 0x1d84 has v0 = ?.

- `crmMapPages` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x1d8c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x1d8c-0x1e24 (152 bytes).
  It occupies 152 bytes.
  4 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x0, including `lw` at 0x1dd4, `lw` at 0x1de4, `lw` at 0x1dfc.
  The `jal` at 0x1db0 calls crmCreateRegion with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=0x0.
  The `jal` at 0x1dd0 calls ddv_lock with a0=[a2], a1=?, a2=?, a3=?.
  The `jal` at 0x1dec calls ddv_mappages with a0=[a2], a1=0x0, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x1df8 calls ddv_unlock with a0=[a2], a1=?, a2=?, a3=?.
  The `jal` at 0x1e0c calls gfxdd_munmap with a0=[a2], a1=?, a2=?, a3=?, a4=ret(ddv_mappages).
  The `beq` branch at 0x1db8 targets 0x1dd0, is taken when v0(=ret(crmCreateRegion)) == 0, and falls through when v0(=ret(crmCreateRegion)) != 0.
  The `beq` branch at 0x1e04 targets 0x1e1c, is taken when a4(=ret(ddv_mappages)) == 0, and falls through when a4(=ret(ddv_mappages)) != 0.
  The `beq` branch at 0x1e14 targets 0x1dc0 and is always taken.
  The `beq` branch at 0x1e1c targets 0x1dc4 and is always taken.
  The return at 0x1dc8 has v0 = one of ?, 0x0.

- `crmUnmapPages` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x1e24 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x1e24-0x1e4c (40 bytes).
  It occupies 40 bytes.
  The `lw` at 0x1e24 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sw` at 0x1e28 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `jal` at 0x1e34 calls gfxdd_munmap with a0=[a0], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1e44 has v0 = 0x0.

- `crmMapChunk` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x1e4c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x1e4c-0x1fe4 (408 bytes).
  It occupies 408 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0xc, including `lw` at 0x1e4c, `lw` at 0x1ea8, `lw` at 0x1fa4.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0x1e50, `sw` at 0x1fe0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x1e60, `lw` at 0x1eb8, `lw` at 0x1eec.
  The `lw` at 0x1edc loads 4 bytes from a0 (arg0 at entry) +0x8.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x24, including `lw` at 0x1ee8, `lw` at 0x1f54, `lw` at 0x1f94.
  The `lhu` at 0x1f08 loads 2 bytes from ?.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1f28, `sw` at 0x1f44.
  The `jal` at 0x1e80 calls crmCreateRegion with a0=a0+36, a1=([a0+4] << 0x10), a2=0x0, a3=?.
  The `jal` at 0x1ebc calls kern_malloc with a0=([a0+4] + [a0+4]), a1=?, a2=?, a3=?.
  The `jal` at 0x1ecc calls crm_update_sz_tiles with a0=a0 at entry (arg0), a1=ret(kern_malloc), a2=?, a3=?.
  The `jal` at 0x1ee4 calls ddv_lock with a0=[a0+36], a1=?, a2=?, a3=?.
  The `jal` at 0x1f58 calls ddv_mappfns with a0=[a0+36], a1=?, a2=sp-128, a3=0x10, a4=0x0.
  The `jal` at 0x1f90 calls ddv_unlock with a0=[a0+36], a1=?, a2=?, a3=?.
  The `jal` at 0x1fb4 calls kern_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1fbc calls gfxdd_munmap with a0=[a0+36], a1=?, a2=?, a3=?.
  The `jal` at 0x1fcc calls ddv_getaddr with a0=[a0+36], a1=?, a2=?, a3=?.
  The `beq` branch at 0x1e88 targets 0x1ea8, is taken when v0(=ret(crmCreateRegion)) == 0, and falls through when v0(=ret(crmCreateRegion)) != 0.
  The `beq` branch at 0x1eb0 targets 0x1edc, is taken when (a5(=[a0+12]) & 0x1) == 0, and falls through when (a5(=[a0+12]) & 0x1) != 0.
  The `beq` branch at 0x1ed4 targets 0x1ee4 and is always taken.
  The `blez` branch at 0x1ef8 targets 0x1f90, is taken when a4(=[a0+4]) <= 0 (signed), and falls through when a4(=[a0+4]) > 0 (signed).
  The `beq` branch at 0x1f2c targets 0x1f48, is taken when a4(?) >= 0x10 (signed), and falls through when a4(?) < 0x10 (signed).
  The `bne` branch at 0x1f40 targets 0x1f1c, is taken when a4(?) < 0x10 (signed), and falls through when a4(?) >= 0x10 (signed).
  The `bne` branch at 0x1f6c targets 0x1f90, is taken when v0(=ret(ddv_mappfns)) != 0, and falls through when v0(=ret(ddv_mappfns)) == 0.
  The `bne` branch at 0x1f88 targets 0x1f08, is taken when a2(?) < a3(=[a0+4]) (signed), and falls through when a2(?) >= a3(=[a0+4]) (signed).
  The `beq` branch at 0x1f9c targets 0x1fcc, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1fac targets 0x1fbc, is taken when (a4(=[a0+12]) & 0x1) == 0, and falls through when (a4(=[a0+12]) & 0x1) != 0.
  The `beq` branch at 0x1fc4 targets 0x1e94 and is always taken.
  The `beq` branch at 0x1fdc targets 0x1e90 and is always taken.
  The return at 0x1ea0 has v0 = ?.

- `crmCreateRegion` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x1fe4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x1fe4-0x2018 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x1ff4 calls gfxdd_mmap_mem with a0=a3 at entry (arg3), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a0 at entry (arg0).
  The `beq` branch at 0x1ffc targets 0x2010, is taken when v0(=ret(gfxdd_mmap_mem)) == 0, and falls through when v0(=ret(gfxdd_mmap_mem)) != 0.
  The `beq` branch at 0x2010 targets 0x2008 and is always taken.
  The return at 0x2008 has v0 = one of 0x0, 0xc.

- `crm_update_sz_tiles` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x2018 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x2018-0x209c (132 bytes).
  It occupies 132 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x202c, `lw` at 0x205c.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x2034, `lhu` at 0x2064.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0x2048, `sh` at 0x2074.
  The `beq` branch at 0x2018 targets 0x2090, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0x2040 targets 0x2054, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x2054 targets 0x2088, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x206c targets 0x2080, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0x2080 targets 0x202c, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The return at 0x2088 has v0 = ?.
  The return at 0x2094 has v0 = 0x0.

- `crm_tile_list` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x209c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x209c-0x213c (160 bytes).
  It occupies 160 bytes.
  The `lw` at 0x209c loads 4 bytes from a0 (arg0 at entry) +0xc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x20d4, `lw` at 0x20f8.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x20e4, `lhu` at 0x210c.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0x20ec, `sh` at 0x2118.
  The `jal` at 0x20b8 calls crm_update_sz_tiles with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x0.
  The `beq` branch at 0x20b0 targets 0x20cc, is taken when (at(=[a0+12]) & 0x1) == 0, and falls through when (at(=[a0+12]) & 0x1) != 0.
  The `beq` branch at 0x20c4 targets 0x2130 and is always taken.
  The `blez` branch at 0x20cc targets 0x211c, is taken when a2 <= 0 (signed), and falls through when a2 > 0 (signed).
  The `beq` branch at 0x20f0 targets 0x211c, is taken when v0(?) >= a2 (signed), and falls through when v0(?) < a2 (signed).
  The `bne` branch at 0x2114 targets 0x20d4, is taken when v0(?) < a2 (signed), and falls through when v0(?) >= a2 (signed).
  The `beq` branch at 0x2124 targets 0x2130, is taken when a2 >= 0 (signed), and falls through when a2 < 0 (signed).
  The return at 0x2134 has v0 = one of ret(crm_update_sz_tiles), a2, 0x0.

- `crmUnmapChunk` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x213c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x213c-0x2164 (40 bytes).
  It occupies 40 bytes.
  The `lw` at 0x213c loads 4 bytes from a0 (arg0 at entry) +0x24.
  The `sw` at 0x2140 stores 4 bytes to a0 (arg0 at entry) +0x24.
  The `jal` at 0x214c calls gfxdd_munmap with a0=[a0+36], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x215c has v0 = 0x0.

- `crmValidateDrawable` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x2164 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x2164-0x22b4 (336 bytes).
  It occupies 336 bytes.
  The `lw` at 0x216c loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `lw` at 0x21b0 loads 4 bytes from ?.
  The `lw` at 0x21cc loads 4 bytes from a1 (arg1 at entry) +0x24.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xb4, including `sw` at 0x21e4, `sw` at 0x227c.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x21e8, `ld` at 0x21fc.
  6 such `sd` accesses store 8 bytes to ?, including `sd` at 0x21f0, `sd` at 0x2208, `sd` at 0x2288.
  2 such `sw` accesses store 4 bytes to [a0+120] +0x4008, including `sw` at 0x220c, `sw` at 0x225c.
  The `lw` at 0x2210 loads 4 bytes from a1 (arg1 at entry) +0x20.
  The `lw` at 0x221c loads 4 bytes from a1 (arg1 at entry) +0x1c.
  The `lw` at 0x2228 loads 4 bytes from ([a1+32] + ([a1+28] << 0x2)) +0x20.
  The `lw` at 0x2260 loads 4 bytes from a1 (arg1 at entry) +0x34.
  The `lw` at 0x226c loads 4 bytes from a0 (arg0 at entry) +0xb4.
  The `jal` at 0x2198 calls crmLoadTlbABC with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2250 calls crmLoadTexTlb with a0=a1 at entry (arg1), a1=?, a2=?, a3=?, a4=[([a1+32] + ([a1+28] << 0x2))+32].
  The `beq` branch at 0x2190 targets 0x21b0 and is always taken.
  The `beq` branch at 0x21a8 targets 0x21cc, is taken when s1(?) >= 0x3 (signed), and falls through when s1(?) < 0x3 (signed).
  The `bne` branch at 0x21b4 targets 0x2198, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x21c4 targets 0x21b0, is taken when s1(?) < 0x3 (signed), and falls through when s1(?) >= 0x3 (signed).
  The `beq` branch at 0x21d8 targets 0x2260, is taken when v1(=[a1+36]) == 0, and falls through when v1(=[a1+36]) != 0.
  The `bne` branch at 0x2204 targets 0x21e8, is taken when a5(?) < 0x10 (signed), and falls through when a5(?) >= 0x10 (signed).
  The `beq` branch at 0x2214 targets 0x2234, is taken when a0(=[a1+32]) == 0, and falls through when a0(=[a1+32]) != 0.
  The `bne` branch at 0x222c targets 0x2250, is taken when a4(=[([a1+32] + ([a1+28] << 0x2))+32]) != 0, and falls through when a4(=[([a1+32] + ([a1+28] << 0x2))+32]) == 0.
  The `beq` branch at 0x2258 targets 0x2230 and is always taken.
  The `bne` branch at 0x2264 targets 0x21e4, is taken when a5(=[a1+52]) != 0, and falls through when a5(=[a1+52]) == 0.
  The `beq` branch at 0x2274 targets 0x220c, is taken when a6(=[a0+180]) == 0, and falls through when a6(=[a0+180]) != 0.
  The `beq` branch at 0x2290 targets 0x220c, is taken when a0(?) >= 0x10 (signed), and falls through when a0(?) < 0x10 (signed).
  The `bne` branch at 0x22a4 targets 0x2280, is taken when a0(?) < 0x10 (signed), and falls through when a0(?) >= 0x10 (signed).
  The `beq` branch at 0x22ac targets 0x220c and is always taken.
  The return at 0x2248 has v0 = ?.

- `crmLoadTlbABC` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x22b4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x22b4-0x2464 (432 bytes).
  It occupies 432 bytes.
  The `lw` at 0x22b4 loads 4 bytes from a1 (arg1 at entry) +0x10.
  The `lw` at 0x22c4 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `lw` at 0x22cc loads 4 bytes from ((a2 << 0x2) + a0) +0xa4.
  The `sw` at 0x22e8 stores 4 bytes to ((a2 << 0x2) + a0) +0xa4.
  The `lw` at 0x22fc loads 4 bytes from a1 (arg1 at entry) +0xc.
  The `lbu` at 0x2300 loads 1 byte from a1 (arg1 at entry) +0x19.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x231c, `lw` at 0x23d4.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2330, `ld` at 0x2354.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0x233c, `sd` at 0x2360, `sd` at 0x2410.
  2 such `sw` accesses store 4 bytes to [a0+120] +0x4008, including `sw` at 0x2364, `sw` at 0x2448.
  The `lbu` at 0x2374 loads 1 byte from a1 (arg1 at entry) +0x17.
  The `lbu` at 0x2378 loads 1 byte from a1 (arg1 at entry) +0x18.
  2 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x16, including `lbu` at 0x2380, `lbu` at 0x23ac.
  The `lhu` at 0x23e8 loads 2 bytes from ?.
  The `sh` at 0x23f4 stores 2 bytes to ?.
  The `beq` branch at 0x22dc targets 0x2368, is taken when at(=[((a2 << 0x2) + a0)+164]) == a5(=[a1+16]), and falls through when at(=[((a2 << 0x2) + a0)+164]) != a5(=[a1+16]).
  The `beq` branch at 0x22e4 targets 0x244c, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x22ec targets 0x2454, is taken when a2 == a6(=0x1), and falls through when a2 != a6(=0x1).
  The `beq` branch at 0x22f4 targets 0x245c, is taken when a2 == a7(=0x2), and falls through when a2 != a7(=0x2).
  The `beq` branch at 0x2310 targets 0x2374, is taken when (a5(=[a1+12]) & 0x1) == 0, and falls through when (a5(=[a1+12]) & 0x1) != 0.
  The `blez` branch at 0x2320 targets 0x2364, is taken when a5(=([a1+25]:1 << 0x2)) <= 0 (signed), and falls through when a5(=([a1+25]:1 << 0x2)) > 0 (signed).
  The `beq` branch at 0x2340 targets 0x2364, is taken when a1(?) >= a5(=([a1+25]:1 << 0x2)) (signed), and falls through when a1(?) < a5(=([a1+25]:1 << 0x2)) (signed).
  The `bne` branch at 0x235c targets 0x2328, is taken when a1(?) < a5(=([a1+25]:1 << 0x2)) (signed), and falls through when a1(?) >= a5(=([a1+25]:1 << 0x2)) (signed).
  The `beq` branch at 0x239c targets 0x2440, is taken when t8(=[a1+23]:1) >= t1(=([a1+23]:1 + [a1+25]:1)) (signed), and falls through when t8(=[a1+23]:1) < t1(=([a1+23]:1 + [a1+25]:1)) (signed).
  The `beq` branch at 0x23c0 targets 0x2430, is taken when a2(=[a1+22]:1) >= a7(=([a1+22]:1 + [a1+24]:1)) (signed), and falls through when a2(=[a1+22]:1) < a7(=([a1+22]:1 + [a1+24]:1)) (signed).
  The `beq` branch at 0x23f0 targets 0x23fc, is taken when v1(?) == ra(=0x3), and falls through when v1(?) != ra(=0x3).
  The `bne` branch at 0x23f8 targets 0x2414, is taken when a2(?) != t3(=([a1+22]:1 + [a1+24]:1)-1), and falls through when a2(?) == t3(=([a1+22]:1 + [a1+24]:1)-1).
  The `bne` branch at 0x2428 targets 0x23d4, is taken when a2(?) < a7(=([a1+22]:1 + [a1+24]:1)) (signed), and falls through when a2(?) >= a7(=([a1+22]:1 + [a1+24]:1)) (signed).
  The `bne` branch at 0x2438 targets 0x23ac, is taken when t8(?) < a2(=([a1+23]:1 + [a1+25]:1)) (signed), and falls through when t8(?) >= a2(=([a1+23]:1 + [a1+25]:1)) (signed).
  The `beq` branch at 0x2444 targets 0x2368 and is always taken.
  The `beq` branch at 0x244c targets 0x22fc and is always taken.
  The `beq` branch at 0x2454 targets 0x22fc and is always taken.
  The `beq` branch at 0x245c targets 0x22fc and is always taken.
  The return at 0x236c has v0 = ?.

- `crmLoadCidTlb` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` at 0x2464 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)`.
  Range: 0x2464-0x2500 (156 bytes).
  It occupies 156 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x2494, `lw` at 0x24fc.
  The `lw` at 0x24a4 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lhu` at 0x24b4 loads 2 bytes from ?.
  The `sh` at 0x24b8 stores 2 bytes to ?.
  The `sd` at 0x24e4 stores 8 bytes to ?.
  The `sw` at 0x24e8 stores 4 bytes to a0 (arg0 at entry) +0x4008.
  The `beq` branch at 0x2478 targets 0x24f4 and is always taken.
  The `beq` branch at 0x248c targets 0x24e8, is taken when a3(?) >= 0x10 (signed), and falls through when a3(?) < 0x10 (signed).
  The `beq` branch at 0x249c targets 0x24bc, is taken when a3(?) >= v0(=[a1+4]) (signed), and falls through when a3(?) < v0(=[a1+4]) (signed).
  The `bne` branch at 0x24bc targets 0x2480, is taken when a5(?) != a6(=0x3), and falls through when a5(?) == a6(=0x3).
  The `beq` branch at 0x24e0 targets 0x2480 and is always taken.
  The `beq` branch at 0x24f8 targets 0x2498 and is always taken.
  The return at 0x24ec has v0 = ?.
