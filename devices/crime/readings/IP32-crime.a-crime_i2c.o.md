# Readings: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`

One entry per routine, filed here from the reading batches by binary.

- `crime_i2cSetMonitor` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x0-0x24 (36 bytes).
  It occupies 36 bytes.
  The `lw` at 0x0 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sw` at 0x20 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `beq` branch at 0xc targets 0x18, is taken when a1 == 0, and falls through when a1 != 0.
  The return at 0x1c has v0 = ?.

- `crime_i2cReset` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x24 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x24-0x214 (496 bytes).
  It occupies 496 bytes.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8, including `sw` at 0x60, `sw` at 0x94, `sw` at 0xc8.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x64, `lw` at 0x98, `lw` at 0xcc.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x10, including `sw` at 0x144, `sw` at 0x16c, `sw` at 0x194.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x148, `lw` at 0x170, `lw` at 0x198.
  The `jal` at 0x78 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x80 calls us_delay with a0=0xc350, a1=?, a2=?, a3=?.
  The `jal` at 0xac calls us_delay with a0=[sym(.sdata)], a1=?, a2=[a0+8], a3=?.
  The `jal` at 0xb4 calls us_delay with a0=0x1f4, a1=?, a2=?, a3=?.
  The `jal` at 0xe0 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=[sym(.sdata)+4], a5=[a0+8].
  The `jal` at 0xe8 calls us_delay with a0=0x1f4, a1=?, a2=?, a3=?.
  The `jal` at 0x114 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?, a6=[sym(.sdata)+4].
  The `jal` at 0x11c calls us_delay with a0=0x1f4, a1=?, a2=?, a3=?.
  The `jal` at 0x15c calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x184 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x1ac calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=[sym(.sdata)+4].
  The `jal` at 0x1d4 calls us_delay with a0=[sym(.sdata)], a1=[a0+16], a2=?, a3=?, a6=[sym(.sdata)+4].
  The `blez` branch at 0x50 targets 0x1e4, is taken when at(=[sym(.sdata)+60]) <= 0 (signed), and falls through when at(=[sym(.sdata)+60]) > 0 (signed).
  The `beq` branch at 0x58 targets 0x204 and is always taken.
  The `beq` branch at 0x8c targets 0x16c, is taken when a0(=[sym(.sdata)+4]) == s1(=0x1), and falls through when a0(=[sym(.sdata)+4]) != s1(=0x1).
  The `beq` branch at 0xc0 targets 0x194, is taken when a3(=[sym(.sdata)+4]) == s1(=0x1), and falls through when a3(=[sym(.sdata)+4]) != s1(=0x1).
  The `beq` branch at 0xf4 targets 0x1bc, is taken when a6(=[sym(.sdata)+4]) == s1(=0x1), and falls through when a6(=[sym(.sdata)+4]) != s1(=0x1).
  The `beq` branch at 0x134 targets 0x1e4, is taken when s2(?) >= t1(=[sym(.sdata)+60]) (signed), and falls through when s2(?) < t1(=[sym(.sdata)+60]) (signed).
  The `bne` branch at 0x13c targets 0x60, is taken when t2(=[sym(.sdata)+4]) != s1(=0x1), and falls through when t2(=[sym(.sdata)+4]) == s1(=0x1).
  The `beq` branch at 0x164 targets 0x80 and is always taken.
  The `beq` branch at 0x18c targets 0xb4 and is always taken.
  The `beq` branch at 0x1b4 targets 0xe8 and is always taken.
  The `beq` branch at 0x1dc targets 0x11c and is always taken.
  The `beq` branch at 0x20c targets 0x13c and is always taken.
  The return at 0x1fc has v0 = one of ?, ret(us_delay).

- `crime_i2cFixupAfterErr` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x214 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x214-0x270 (92 bytes).
  It occupies 92 bytes.
  The `jal` at 0x244 calls us_delay with a0=?, a1=[sym(.sdata)+36], a2=a2 at entry (arg2), a3=[sym(.sdata)+32].
  The `jal` at 0x250 calls i2_stop with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x25c calls us_delay with a0=[sym(.sdata)+40], a1=?, a2=?, a3=?.
  The `beq` branch at 0x230 targets 0x240, is taken when a1(=[sym(.sdata)+36]) >= a3(=[sym(.sdata)+32]) (signed), and falls through when a1(=[sym(.sdata)+36]) < a3(=[sym(.sdata)+32]) (signed).
  The `beq` branch at 0x238 targets 0x244 and is always taken.
  The return at 0x268 has v0 = ret(us_delay).

- `crime_i2cfpFixupAfterErr` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x270 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x270-0x2cc (92 bytes).
  It occupies 92 bytes.
  The `jal` at 0x2a0 calls us_delay with a0=?, a1=[sym(.sdata)+36], a2=a2 at entry (arg2), a3=[sym(.sdata)+32].
  The `jal` at 0x2ac calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x2b8 calls us_delay with a0=[sym(.sdata)+40], a1=?, a2=?, a3=?.
  The `beq` branch at 0x28c targets 0x29c, is taken when a1(=[sym(.sdata)+36]) >= a3(=[sym(.sdata)+32]) (signed), and falls through when a1(=[sym(.sdata)+36]) < a3(=[sym(.sdata)+32]) (signed).
  The `beq` branch at 0x294 targets 0x2a0 and is always taken.
  The return at 0x2c4 has v0 = ret(us_delay).

- `crime_i2cProbe` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x2cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x2cc-0x52c (608 bytes).
  It occupies 608 bytes.
  The `lw` at 0x2e0 loads 4 bytes from sym(crimeBoards) +0xc.
  The `lbu` at 0x478 loads 1 byte from ?.
  The `lbu` at 0x4a8 loads 1 byte from (a1 + one of 0x64, 0xea) +0x0.
  The `sh` at 0x4e4 stores 2 bytes to (sym(crimeBoards) + (a2 << 0x3)) +0x20.
  The `sh` at 0x4f0 stores 2 bytes to (sym(crimeBoards) + (a2 << 0x3)) +0x26.
  The `jal` at 0x304 calls mutex_lock with a0=[sym(crimeBoards)+12]+468, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x318 calls crime_i2cSetMonitor with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x344 calls bzero with a0=(a1 + one of 0x64, 0xea), a1=0x80, a2=?, a3=?.
  The `jal` at 0x34c calls crime_i2cReset with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x37c calls i2_start with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x38c calls i2_sendbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=0xa0, a3=?.
  The `jal` at 0x3a0 calls i2_sendbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x3b0 calls i2_start with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3c0 calls i2_sendbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=0xa1, a3=?.
  The `jal` at 0x3e0 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3f0 calls mutex_unlock with a0=[sym(crimeBoards)+12]+468, a1=?, a2=?, a3=?.
  The `jal` at 0x458 calls i2_master_recvbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=one of 0x0, 0x1.
  The `jal` at 0x494 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=0xf, a4=one of 0x0, 0x1.
  The `jal` at 0x4b0 calls i2_stop with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x4c0 calls mutex_unlock with a0=[sym(crimeBoards)+12]+468, a1=?, a2=?, a3=?.
  The `jal` at 0x4c8 calls crime_EdidCksum with a0=(a1 + one of 0x64, 0xea), a1=?, a2=?, a3=?.
  The `jal` at 0x4fc calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x50c calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x51c calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x2f8 targets 0x30c, is taken when s3(=[sym(crimeBoards)+12]) == 0, and falls through when s3(=[sym(crimeBoards)+12]) != 0.
  The `beq` branch at 0x310 targets 0x320, is taken when t8(=[sym(crm_dc_board_installed)]) == 0, and falls through when t8(=[sym(crm_dc_board_installed)]) != 0.
  The `beq` branch at 0x334 targets 0x4f4, is taken when s6(=a2) == t9(=0x1), and falls through when s6(=a2) != t9(=0x1).
  The `beq` branch at 0x364 targets 0x3e8, is taken when s5(?) >= 0x3 (signed), and falls through when s5(?) < 0x3 (signed).
  The `beq` branch at 0x374 targets 0x3e8, is taken when s0(?) >= 0x3 (signed), and falls through when s0(?) < 0x3 (signed).
  The `beq` branch at 0x394 targets 0x4fc, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3a8 targets 0x50c, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3c8 targets 0x51c, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3d8 targets 0x440 and is always taken.
  The `beq` branch at 0x3e8 targets 0x3fc, is taken when s3(=[sym(crimeBoards)+12]) == 0, and falls through when s3(=[sym(crimeBoards)+12]) != 0.
  The `beq` branch at 0x438 targets 0x4ac, is taken when s0(?) >= 0x80 (unsigned), and falls through when s0(?) < 0x80 (unsigned).
  The `beq` branch at 0x444 targets 0x450, is taken when a0(=0x7f) == s0(?), and falls through when a0(=0x7f) != s0(?).
  The `beq` branch at 0x460 targets 0x3e0, is taken when v0(=ret(i2_master_recvbyte)) == 0, and falls through when v0(=ret(i2_master_recvbyte)) != 0.
  The `beq` branch at 0x468 targets 0x4a4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x470 targets 0x430, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x47c targets 0x42c, is taken when a2(?) != s7(?), and falls through when a2(?) == s7(?).
  The `bne` branch at 0x484 targets 0x430, is taken when a3(=0xf) != s0(?), and falls through when a3(=0xf) == s0(?).
  The `beq` branch at 0x48c targets 0x434, is taken when a4(=one of 0x0, 0x1) == 0, and falls through when a4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x49c targets 0x360 and is always taken.
  The `beq` branch at 0x4a4 targets 0x430 and is always taken.
  The `beq` branch at 0x4b8 targets 0x4c8, is taken when s3(=[sym(crimeBoards)+12]) == 0, and falls through when s3(=[sym(crimeBoards)+12]) != 0.
  The `beq` branch at 0x4ec targets 0x3fc and is always taken.
  The `beq` branch at 0x4f4 targets 0x344 and is always taken.
  The `beq` branch at 0x504 targets 0x370 and is always taken.
  The `beq` branch at 0x514 targets 0x370 and is always taken.
  The `beq` branch at 0x524 targets 0x370 and is always taken.
  The return at 0x424 has v0 = one of 0x0, 0x1.

- `crime_validate_ddc_data` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x52c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x52c-0x6ec (448 bytes).
  It occupies 448 bytes.
  3 such `sh` accesses store 2 bytes to (sym(crimeBoards) + (a1 << 0x3)) +0x22, including `sh` at 0x55c, `sh` at 0x5ac, `sh` at 0x668.
  3 such `sh` accesses store 2 bytes to (a0 + one of 0xe8, 0x16a) +0x0, including `sh` at 0x560, `sh` at 0x5b0, `sh` at 0x670.
  The `lh` at 0x564 loads 2 bytes from (sym(crimeBoards) + (a1 << 0x3)) +0x20.
  The `lbu` at 0x5ec loads 1 byte from (a0 + one of 0x6e, 0xf4) +0x0.
  The `lbu` at 0x5f0 loads 1 byte from (a0 + one of 0x6f, 0xf5) +0x0.
  The `lbu` at 0x5f4 loads 1 byte from (a0 + one of 0x7a, 0x100) +0x0.
  The `lbu` at 0x600 loads 1 byte from (a0 + one of 0x79, 0xff) +0x0.
  2 such `lbu` accesses load 1 byte from (a0 + one of 0x88, 0x10e) +0x0, including `lbu` at 0x64c, `lbu` at 0x6c8.
  The `lh` at 0x65c loads 2 bytes from (sym(crimeBoards) + (a1 << 0x3)) +0x24.
  The `sb` at 0x6d0 stores 1 byte to (a0 + one of 0x88, 0x10e) +0x0.
  The `jal` at 0x59c calls crime_i2cValidEdid with a0=(a0 + one of 0x64, 0xea), a1=(sym(crimeBoards) + (a1 << 0x3))+32, a2=a2 at entry (arg2), a3=0x1.
  The `jal` at 0x5b4 calls sgiEdid with a0=(a0 + one of 0x64, 0xea), a1=?, a2=?, a3=?.
  The `jal` at 0x5c4 calls crmFixupSony24 with a0=(a0 + one of 0x64, 0xea), a1=?, a2=?, a3=?.
  The `jal` at 0x5d4 calls sgiEdid with a0=(a0 + one of 0x64, 0xea), a1=?, a2=?, a3=?.
  The `jal` at 0x5e4 calls crmFixupSony24 with a0=(a0 + one of 0x64, 0xea), a1=?, a2=?, a3=?.
  The `jal` at 0x6dc calls bcopy with a0=sym(.sdata)+104, a1=(a0 + one of 0x64, 0xea), a2=0x8, a3=?, a4=0x1, a5=0x11, a7=[(sym(crimeBoards) + (a1 << 0x3))+36]:2.
  The `beq` branch at 0x544 targets 0x58c, is taken when a1 == a3(=0x1), and falls through when a1 != a3(=0x1).
  The `beq` branch at 0x56c targets 0x598, is taken when at(=[(sym(crimeBoards) + (a1 << 0x3))+32]:2) == v0(=0x2), and falls through when at(=[(sym(crimeBoards) + (a1 << 0x3))+32]:2) != v0(=0x2).
  The `beq` branch at 0x590 targets 0x54c and is always taken.
  The `beq` branch at 0x5a4 targets 0x5d4, is taken when v0(=ret(crime_i2cValidEdid)) == 0, and falls through when v0(=ret(crime_i2cValidEdid)) != 0.
  The `beq` branch at 0x5bc targets 0x578, is taken when v0(=ret(sgiEdid)) == 0, and falls through when v0(=ret(sgiEdid)) != 0.
  The `beq` branch at 0x5cc targets 0x578 and is always taken.
  The `beq` branch at 0x5dc targets 0x578, is taken when v0(=ret(sgiEdid)) == 0, and falls through when v0(=ret(sgiEdid)) != 0.
  The `bne` branch at 0x5fc targets 0x574, is taken when t9(?) != 0, and falls through when t9(?) == 0.
  The `beq` branch at 0x608 targets 0x674, is taken when a0(?) == ra(=0x10), and falls through when a0(?) != ra(=0x10).
  The `beq` branch at 0x610 targets 0x678, is taken when a0(?) == at(=0x12), and falls through when a0(?) != at(=0x12).
  The `beq` branch at 0x618 targets 0x694, is taken when a0(?) == a4(=0x1), and falls through when a0(?) != a4(=0x1).
  The `beq` branch at 0x624 targets 0x634, is taken when a0(?) == v0(=0x2), and falls through when a0(?) != v0(=0x2).
  The `bne` branch at 0x62c targets 0x578, is taken when a0(?) != v1(=0x11), and falls through when a0(?) == v1(=0x11).
  The `beq` branch at 0x634 targets 0x690, is taken when a0(?) == a4(=0x1), and falls through when a0(?) != a4(=0x1).
  The `beq` branch at 0x63c targets 0x690, is taken when a0(?) == a2(=0x2), and falls through when a0(?) != a2(=0x2).
  The `beq` branch at 0x644 targets 0x6b0, is taken when a0(?) == a5(=0x11), and falls through when a0(?) != a5(=0x11).
  The `beq` branch at 0x654 targets 0x6cc, is taken when (a0(?) & 0x1) == 0, and falls through when (a0(?) & 0x1) != 0.
  The `beq` branch at 0x660 targets 0x6d4, is taken when a7(=[(sym(crimeBoards) + (a1 << 0x3))+36]:2) == 0, and falls through when a7(=[(sym(crimeBoards) + (a1 << 0x3))+36]:2) != 0.
  The `beq` branch at 0x66c targets 0x574 and is always taken.
  The `bne` branch at 0x678 targets 0x574, is taken when a1(?) != t1(=0x21), and falls through when a1(?) == t1(=0x21).
  The `bne` branch at 0x680 targets 0x578, is taken when a3(?) != t2(=0x18), and falls through when a3(?) == t2(=0x18).
  The `bne` branch at 0x688 targets 0x63c, is taken when a0(?) != a4(=0x1), and falls through when a0(?) == a4(=0x1).
  The `bne` branch at 0x694 targets 0x578, is taken when a1(?) != t3(=0x26), and falls through when a1(?) == t3(=0x26).
  The `bne` branch at 0x6a0 targets 0x578, is taken when a3(?) != t8(=0x1d), and falls through when a3(?) == t8(=0x1d).
  The `beq` branch at 0x6a8 targets 0x644 and is always taken.
  The `bne` branch at 0x6b0 targets 0x578, is taken when a1(?) != t9(=0x30), and falls through when a1(?) == t9(=0x30).
  The `bne` branch at 0x6bc targets 0x578, is taken when a3(?) != ra(=0x1f), and falls through when a3(?) == ra(=0x1f).
  The `beq` branch at 0x6c4 targets 0x650 and is always taken.
  The `beq` branch at 0x6cc targets 0x65c and is always taken.
  The `beq` branch at 0x6e4 targets 0x664 and is always taken.
  The return at 0x584 has v0 = one of ?, ret(sgiEdid), ret(crmFixupSony24), 0x2.

- `i2cfp_DMI2_FailedEDID` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x6ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x6ec-0x70c (32 bytes).
  It occupies 32 bytes.
  The `sh` at 0x700 stores 2 bytes to (sym(crimeBoards) + (a1 << 0x3)) +0x32.
  The `sh` at 0x708 stores 2 bytes to a0 (arg0 at entry) +0x1ec.
  The return at 0x704 has v0 = (sym(crimeBoards) + (a1 << 0x3)).

- `crime_i2cValidEdid` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x758 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x758-0x7e8 (144 bytes).
  It occupies 144 bytes.
  The `lbu` at 0x758 loads 1 byte from a0 (arg0 at entry) +0x0.
  The `sh` at 0x76c stores 2 bytes to a1 (arg1 at entry) +0x4.
  The `lhu` at 0x770 loads 2 bytes from a1 (arg1 at entry) +0x6.
  The `lbu` at 0x784 loads 1 byte from a0 (arg0 at entry) +0x1.
  The `lbu` at 0x790 loads 1 byte from a0 (arg0 at entry) +0x2.
  The `lbu` at 0x79c loads 1 byte from a0 (arg0 at entry) +0x3.
  The `lbu` at 0x7a8 loads 1 byte from a0 (arg0 at entry) +0x4.
  The `lbu` at 0x7b4 loads 1 byte from a0 (arg0 at entry) +0x5.
  The `lbu` at 0x7c0 loads 1 byte from a0 (arg0 at entry) +0x6.
  The `lbu` at 0x7cc loads 1 byte from a0 (arg0 at entry) +0x7.
  The `beq` branch at 0x75c targets 0x784, is taken when at(=[a0]:1) == 0, and falls through when at(=[a0]:1) != 0.
  The `beq` branch at 0x768 targets 0x778, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x774 targets 0x7e0, is taken when v0(=[a1+6]:2) == 0, and falls through when v0(=[a1+6]:2) != 0.
  The `bne` branch at 0x788 targets 0x764, is taken when v0(=0xff) != v1(=[a0+1]:1), and falls through when v0(=0xff) == v1(=[a0+1]:1).
  The `bne` branch at 0x794 targets 0x764, is taken when v0(=0xff) != a2(=[a0+2]:1), and falls through when v0(=0xff) == a2(=[a0+2]:1).
  The `bne` branch at 0x7a0 targets 0x764, is taken when v0(=0xff) != a3(=[a0+3]:1), and falls through when v0(=0xff) == a3(=[a0+3]:1).
  The `bne` branch at 0x7ac targets 0x764, is taken when v0(=0xff) != a4(=[a0+4]:1), and falls through when v0(=0xff) == a4(=[a0+4]:1).
  The `bne` branch at 0x7b8 targets 0x764, is taken when v0(=0xff) != a5(=[a0+5]:1), and falls through when v0(=0xff) == a5(=[a0+5]:1).
  The `bne` branch at 0x7c4 targets 0x768, is taken when v0(=0xff) != a6(=[a0+6]:1), and falls through when v0(=0xff) == a6(=[a0+6]:1).
  The `bne` branch at 0x7d0 targets 0x768, is taken when a7(=[a0+7]:1) != 0, and falls through when a7(=[a0+7]:1) == 0.
  The `beq` branch at 0x7d8 targets 0x768 and is always taken.
  The return at 0x77c has v0 = 0x0.
  The return at 0x7e0 has v0 = 0x1.

- `crmFixupSony24` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x820 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x820-0x868 (72 bytes).
  It occupies 72 bytes.
  The `lbu` at 0x820 loads 1 byte from a0 (arg0 at entry) +0xa.
  The `lbu` at 0x82c loads 1 byte from a0 (arg0 at entry) +0xb.
  The `lbu` at 0x83c loads 1 byte from a0 (arg0 at entry) +0x15.
  The `lbu` at 0x850 loads 1 byte from a0 (arg0 at entry) +0x7f.
  The `sb` at 0x858 stores 1 byte to a0 (arg0 at entry) +0xb.
  The `sb` at 0x864 stores 1 byte to a0 (arg0 at entry) +0x7f.
  The `bne` branch at 0x824 targets 0x848, is taken when at(=[a0+10]:1) != 0, and falls through when at(=[a0+10]:1) == 0.
  The `bne` branch at 0x834 targets 0x848, is taken when v0(=[a0+11]:1) != v1(=0x1), and falls through when v0(=[a0+11]:1) == v1(=0x1).
  The `beq` branch at 0x840 targets 0x850, is taken when a1(=[a0+21]:1) == a2(=0x30), and falls through when a1(=[a0+21]:1) != a2(=0x30).
  The return at 0x848 has v0 = one of ?, [a0+11]:1.
  The return at 0x860 has v0 = [a0+11]:1.

- `crime_copyin_cmd` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x868 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x868-0x8fc (148 bytes).
  It occupies 148 bytes.
  The `lh` at 0x868 loads 2 bytes from a0 (arg0 at entry) +0x2.
  The `lw` at 0x88c loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `lbu` at 0x8cc loads 1 byte from a0 (arg0 at entry) +0x6.
  The `sb` at 0x8d4 stores 1 byte to sym(.bss) +0x80.
  The `sw` at 0x8f0 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x8a4 calls copyin with a0=[a0+8], a1=sym(.bss), a2=[a0+2]:2, a3=a3 at entry (arg3), a5=[a0+8].
  The `blez` branch at 0x874 targets 0x8c0, is taken when a2(=[a0+2]:2) <= 0 (signed), and falls through when a2(=[a0+2]:2) > 0 (signed).
  The `beq` branch at 0x87c targets 0x8c0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x884 targets 0x8c8, is taken when a2(=[a0+2]:2) == a5(=0x1), and falls through when a2(=[a0+2]:2) != a5(=0x1).
  The `beq` branch at 0x890 targets 0x8f4, is taken when a5(=[a0+8]) == 0, and falls through when a5(=[a0+8]) != 0.
  The `beq` branch at 0x8ac targets 0x8d8, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x8c0 targets 0x8b8 and is always taken.
  The `beq` branch at 0x8ec targets 0x8b8 and is always taken.
  The `beq` branch at 0x8f4 targets 0x8b8 and is always taken.
  The return at 0x8b8 has v0 = one of -0x16, -0xe, 0x0.

- `crime_i2c_cmd` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x8fc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x8fc-0xbf8 (764 bytes).
  It occupies 764 bytes.
  The `lbu` at 0x8fc loads 1 byte from a1 (arg1 at entry) +0x1.
  The `lw` at 0x910 loads 4 bytes from a0 (arg0 at entry) +0x80.
  2 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x0, including `lbu` at 0x918, `lbu` at 0x964.
  The `lw` at 0x988 loads 4 bytes from (sym(.rodata) + ([a1+1]:1 << 0x2)) +0x0.
  The `jal` at 0x948 calls mutex_lock with a0=a0+468, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x960 calls crime_i2cSetMonitor with a0=[a0+128], a1=[a1]:1, a2=?, a3=?.
  Calls (unknown callee) via register with a0=[sym(.sdata)+4], a1=?, a2=?, a3=? (`jr` at 0x98c).
  The `jal` at 0x998 calls mutex_unlock with a0=a0+468, a1=?, a2=?, a3=?.
  The `blez` branch at 0x930 targets 0x940, is taken when at(=[a1]:1) <= 0 (signed), and falls through when at(=[a1]:1) > 0 (signed).
  The `beq` branch at 0x93c targets 0x9c0, is taken when a0(=[sym(crm_dc_board_installed)]) == 0, and falls through when a0(=[sym(crm_dc_board_installed)]) != 0.
  The `beq` branch at 0x954 targets 0x96c, is taken when a1(=[sym(crm_dc_board_installed)]) == 0, and falls through when a1(=[sym(crm_dc_board_installed)]) != 0.
  The `beq` branch at 0x980 targets 0x994, is taken when v1(=[a1+1]:1) >= 0x8 (unsigned), and falls through when v1(=[a1+1]:1) < 0x8 (unsigned).
  The `beq` branch at 0x9c0 targets 0x9a0 and is always taken.
  The return at 0x9b8 has v0 = one of -0x16, 0x0.
  The instructions from 0x9c8 to 0xbf4 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x98c uses a jump table whose successors are unresolved.

- `crime_Probe2AB` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0xbf8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0xbf8-0xecc (724 bytes).
  It occupies 724 bytes.
  3 such `sb` accesses store 1 byte to sym(.bss) +0x80, including `sb` at 0xcbc, `sb` at 0xdac, `sb` at 0xe10.
  2 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x0, including `lbu` at 0xce8, `lbu` at 0xdf8.
  The `sb` at 0xe44 stores 1 byte to (ret(crime_2abGetReply) + sym(.bss)) +0x80.
  The `lw` at 0xe78 loads 4 bytes from sym(.data) +0x0.
  The `jal` at 0xc20 calls crime_i2cReset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc7c calls crime_2abSendCmd with a0=a0 at entry (arg0), a1=0x1, a2=sym(.bss), a3=0x0.
  The `jal` at 0xc98 calls crime_2abGetReply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-240, a3=?.
  The `jal` at 0xccc calls i2_stop with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xcd4 calls us_delay with a0=[sym(.sdata)+80], a1=?, a2=?, a3=?.
  The `jal` at 0xd48 calls i2_stop with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xd50 calls us_delay with a0=[sym(.sdata)+80], a1=?, a2=?, a3=?.
  The `jal` at 0xd70 calls us_delay with a0=[sym(.sdata)+80], a1=?, a2=?, a3=?.
  The `jal` at 0xd90 calls us_delay with a0=[sym(.sdata)+80], a1=?, a2=?, a3=?.
  The `jal` at 0xdb0 calls crime_2abSendCmd with a0=a0 at entry (arg0), a1=0x1, a2=sym(.bss), a3=0x0.
  The `jal` at 0xdc4 calls crime_2abGetReply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-240, a3=?.
  The `jal` at 0xde8 calls bcopy with a0=?, a1=sp-232, a2=ret(crime_2abGetReply)-1, a3=?.
  The `jal` at 0xe04 calls us_delay with a0=[sym(.sdata)+80], a1=?, a2=0xe1, a3=[a1]:1.
  The `jal` at 0xe20 calls bcopy with a0=sp-232, a1=?, a2=?, a3=?, a4=0xf2.
  The `jal` at 0xe40 calls crime_2abSendCmd with a0=a0 at entry (arg0), a1=ret(crime_2abGetReply)+1, a2=sym(.bss), a3=0x1, a5=0x4, a6=(ret(crime_2abGetReply) + sym(.bss)).
  The `jal` at 0xe74 calls strncmp with a0=sym(.rodata)+248, a1=sp-232, a2=0x13, a3=?.
  The `jal` at 0xea4 calls us_delay with a0=[sym(.sdata)+80], a1=?, a2=?, a3=?.
  The `beq` branch at 0xc54 targets 0xcbc and is always taken.
  The `beq` branch at 0xc64 targets 0xc8c, is taken when s2(?) >= 0x3 (signed), and falls through when s2(?) < 0x3 (signed).
  The `beq` branch at 0xc84 targets 0xc5c, is taken when v0(=ret(crime_2abSendCmd)) == 0, and falls through when v0(=ret(crime_2abSendCmd)) != 0.
  The `beq` branch at 0xc8c targets 0xcc8, is taken when s2(?) == s6(=0x3), and falls through when s2(?) != s6(=0x3).
  The `blez` branch at 0xca4 targets 0xd44, is taken when v0(=ret(crime_2abGetReply)) <= 0 (signed), and falls through when v0(=ret(crime_2abGetReply)) > 0 (signed).
  The `beq` branch at 0xcac targets 0xce8, is taken when a2(?) == s7(=0x1), and falls through when a2(?) != s7(=0x1).
  The `beq` branch at 0xcb4 targets 0xd0c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xcc0 targets 0xc6c and is always taken.
  The `beq` branch at 0xce0 targets 0xcb4 and is always taken.
  The `bne` branch at 0xcfc targets 0xcb4, is taken when ra(=0xe0) != at(=[a1]:1), and falls through when ra(=0xe0) == at(=[a1]:1).
  The `beq` branch at 0xd04 targets 0xd68 and is always taken.
  The `bltz` branch at 0xd58 targets 0xeb4, is taken when s2(=ret(crime_2abGetReply)) < 0 (signed), and falls through when s2(=ret(crime_2abGetReply)) >= 0 (signed).
  The `beq` branch at 0xd60 targets 0xcb4 and is always taken.
  The `beq` branch at 0xd68 targets 0xebc, is taken when v1(=0x4) == v0(=[sym(.sdata)+77]:1), and falls through when v1(=0x4) != v0(=[sym(.sdata)+77]:1).
  The `beq` branch at 0xd78 targets 0xd90 and is always taken.
  The `beq` branch at 0xd88 targets 0xe98, is taken when s2(?) >= 0x2 (signed), and falls through when s2(?) < 0x2 (signed).
  The `beq` branch at 0xdb8 targets 0xd80, is taken when v0(=ret(crime_2abSendCmd)) == 0, and falls through when v0(=ret(crime_2abSendCmd)) != 0.
  The `blez` branch at 0xdcc targets 0xd80, is taken when v0(=ret(crime_2abGetReply)) <= 0 (signed), and falls through when v0(=ret(crime_2abGetReply)) > 0 (signed).
  The `beq` branch at 0xdd8 targets 0xd80, is taken when v0(=ret(crime_2abGetReply)) >= 0x80 (signed), and falls through when v0(=ret(crime_2abGetReply)) < 0x80 (signed).
  The `beq` branch at 0xdf0 targets 0xd80, is taken when s8(=ret(crime_2abGetReply)) == s7(=0x1), and falls through when s8(=ret(crime_2abGetReply)) != s7(=0x1).
  The `bnel` branch at 0xdfc targets 0xd84, is taken when a2(=0xe1) != a3(=[a1]:1), and falls through when a2(=0xe1) == a3(=[a1]:1); its branch-likely delay slot `addiu s2,s2,1` at 0xe00 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xe48 targets 0xd80, is taken when v0(=ret(crime_2abSendCmd)) == 0, and falls through when v0(=ret(crime_2abSendCmd)) != 0.
  The `beq` branch at 0xe54 targets 0xe90, is taken when t0(=[sym(.sdata)+12]) == 0, and falls through when t0(=[sym(.sdata)+12]) != 0.
  The `beq` branch at 0xe7c targets 0xec4, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `bne` branch at 0xe88 targets 0xe6c, is taken when s1(?) < 0x3 (signed), and falls through when s1(?) >= 0x3 (signed).
  The `beq` branch at 0xe90 targets 0xd14 and is always taken.
  The `beq` branch at 0xe9c targets 0xcb4, is taken when s0(?) >= 0x1e (signed), and falls through when s0(?) < 0x1e (signed).
  The `beq` branch at 0xeac targets 0xcb4 and is always taken.
  The `beq` branch at 0xeb4 targets 0xd60 and is always taken.
  The `beq` branch at 0xebc targets 0xd70 and is always taken.
  The `beq` branch at 0xec4 targets 0xe90 and is always taken.
  The return at 0xd3c has v0 = one of 0x0, 0x1.

- `crime_2abCmdWrapper` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0xecc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0xecc-0x1004 (312 bytes).
  It occupies 312 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0xc, including `lw` at 0xf0c, `lw` at 0xf30.
  The `lh` at 0xf14 loads 2 bytes from a1 (arg1 at entry) +0x2.
  2 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0x4, including `sh` at 0xf1c, `sh` at 0xf5c.
  The `jal` at 0xf20 calls crime_2abSendCmd with a0=a0 at entry (arg0), a1=[a1+2]:2, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xf44 calls crime_2abGetReply with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=sp-64, a3=?, a4=[a1+12].
  The `jal` at 0xfa4 calls us_delay with a0=[sym(.sdata)+52], a1=?, a2=?, a3=?, a7=0x1.
  The `jal` at 0xfe4 calls us_delay with a0=[sym(.sdata)+48], a1=?, a2=?, a3=?, a7=0x1.
  The `jal` at 0xff4 calls us_delay with a0=[sym(.sdata)+44], a1=?, a2=?, a3=?, a7=0x1.
  The `beq` branch at 0xefc targets 0xf0c and is always taken.
  The `bgez` branch at 0xf04 targets 0xfb4, is taken when s2(?) >= 0 (signed), and falls through when s2(?) < 0 (signed).
  The `beq` branch at 0xf28 targets 0xf68, is taken when v0(=ret(crime_2abSendCmd)) == 0, and falls through when v0(=ret(crime_2abSendCmd)) != 0.
  The `beq` branch at 0xf34 targets 0xf04, is taken when a4(=[a1+12]) == 0, and falls through when a4(=[a1+12]) != 0.
  The `bgtz` branch at 0xf58 targets 0xf04, is taken when v0(=ret(crime_2abGetReply)) > 0 (signed), and falls through when v0(=ret(crime_2abGetReply)) <= 0 (signed).
  The `beq` branch at 0xf60 targets 0xf7c and is always taken.
  The `bgtz` branch at 0xf68 targets 0xfb4, is taken when s0(?) > 0 (signed), and falls through when s0(?) <= 0 (signed).
  The `beq` branch at 0xf74 targets 0xf04 and is always taken.
  The `beq` branch at 0xf7c targets 0xfdc, is taken when s2(=ret(crime_2abGetReply)) == 0, and falls through when s2(=ret(crime_2abGetReply)) != 0.
  The `bne` branch at 0xf8c targets 0xfb4, is taken when v0(=[sym(.sdata)+84]) < s0(?) (signed), and falls through when v0(=[sym(.sdata)+84]) >= s0(?) (signed).
  The `beq` branch at 0xf94 targets 0xff4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xf9c targets 0xfe4, is taken when s0(?) == a7(=0x1), and falls through when s0(?) != a7(=0x1).
  The `beq` branch at 0xfac targets 0xf04 and is always taken.
  The `beq` branch at 0xfdc targets 0xf88 and is always taken.
  The `beq` branch at 0xfec targets 0xf04 and is always taken.
  The `beq` branch at 0xffc targets 0xf04 and is always taken.
  The return at 0xfd4 has v0 = one of ?, -0x5, -0x91.

- `crime_2abSendCmd` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x1004 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x1004-0x1260 (604 bytes).
  It occupies 604 bytes.
  The `lbu` at 0x1098 loads 1 byte from a2 (arg2 at entry) +0x0.
  The `lbu` at 0x1168 loads 1 byte from ?.
  The `jal` at 0x102c calls i2_wait_for_bus with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x10fc calls i2_start with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x110c calls i2_sendbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=[sym(.sdata)+77]:1, a3=?.
  The `jal` at 0x1124 calls i2_sendbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=[sym(.sdata)+76]:1, a3=?.
  The `jal` at 0x1138 calls i2_sendbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x1174 calls i2_sendbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x11a0 calls i2_sendbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x11b8 calls i2_stop with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x11d4 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=[sym(.sdata)+76]:1, a3=?.
  The `jal` at 0x1210 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1224 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1234 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x124c calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x104c targets 0x1244, is taken when v0(=ret(i2_wait_for_bus)) == 0, and falls through when v0(=ret(i2_wait_for_bus)) != 0.
  The `bne` branch at 0x1078 targets 0x10f0, is taken when s2(?) < 0x4 (signed), and falls through when s2(?) >= 0x4 (signed).
  The `bne` branch at 0x1090 targets 0x10bc, is taken when s7(?) != a0(=0x3), and falls through when s7(?) == a0(=0x3).
  The `bne` branch at 0x109c targets 0x10c0, is taken when a1(=0xf0) != a2(=[a2]:1), and falls through when a1(=0xf0) == a2(=[a2]:1).
  The `beq` branch at 0x10a8 targets 0x11c8, is taken when a3(=0x4) == a4(=[sym(.sdata)+77]:1), and falls through when a3(=0x4) != a4(=[sym(.sdata)+77]:1).
  The `beq` branch at 0x10b4 targets 0x1068 and is always taken.
  The `beq` branch at 0x1114 targets 0x11d0, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x112c targets 0x1210, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x1140 targets 0x124c, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `blez` branch at 0x1158 targets 0x1198, is taken when s4(=a1) <= 0 (signed), and falls through when s4(=a1) > 0 (signed).
  The `beq` branch at 0x117c targets 0x1234, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `bne` branch at 0x1190 targets 0x1168, is taken when s5(?) < s4(=a1) (signed), and falls through when s5(?) >= s4(=a1) (signed).
  The `beq` branch at 0x11a8 targets 0x1224, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x11b0 targets 0x11c0, is taken when t9(=a3) == 0, and falls through when t9(=a3) != 0.
  The `beq` branch at 0x11c0 targets 0x10c0 and is always taken.
  The `beq` branch at 0x11c8 targets 0x10b4 and is always taken.
  The `bne` branch at 0x11e8 targets 0x1064, is taken when v1(=one of 0x0, 0x1) != 0, and falls through when v1(=one of 0x0, 0x1) == 0.
  The `bne` branch at 0x11f0 targets 0x1064, is taken when a0(=one of 0x0, 0x1) != 0, and falls through when a0(=one of 0x0, 0x1) == 0.
  The `bne` branch at 0x11f8 targets 0x1064, is taken when a1(=one of 0x0, 0x1) != 0, and falls through when a1(=one of 0x0, 0x1) == 0.
  The `bne` branch at 0x1200 targets 0x1068, is taken when s3(=one of 0x0, 0x1) != 0, and falls through when s3(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x1208 targets 0x11b0 and is always taken.
  The `beq` branch at 0x121c targets 0x11e4 and is always taken.
  The `beq` branch at 0x122c targets 0x11e4 and is always taken.
  The `beq` branch at 0x123c targets 0x1068 and is always taken.
  The `beq` branch at 0x1244 targets 0x10c0 and is always taken.
  The `beq` branch at 0x1258 targets 0x11e4 and is always taken.
  The return at 0x10e8 has v0 = one of 0x0, 0x1.

- `crime_2abGetReply` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x1260 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x1260-0x1490 (560 bytes).
  It occupies 560 bytes.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x12a4, `sw` at 0x13dc.
  The `sb` at 0x13b0 stores 1 byte to ?.
  2 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x0, including `lw` at 0x13b4, `lw` at 0x1444.
  The `jal` at 0x1278 calls splprof with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1288 calls i2_stop with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x12a8 calls i2_slave_recvbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=sp-80, a3=sp-76, a4=0x1, a5=0x0.
  The `jal` at 0x12d4 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x12f8 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1328 calls i2_slave_recvbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=sp-80, a3=sp-76, a4=0x0, a5=0x0.
  The `jal` at 0x1350 calls i2_slave_recvbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=sp-80, a3=sp-76, a4=0x0, a5=0x0.
  The `jal` at 0x1394 calls i2_slave_recvbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=sp-80, a3=sp-76, a4=0x0, a5=0x0.
  The `jal` at 0x13f4 calls i2_slave_recvbyte with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=sp-80, a3=sp-76, a4=0x0, a5=0x1.
  The `jal` at 0x1404 calls i2_wait_for_stop with a0=[sym(.sdata)+4], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x140c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1414 calls us_delay with a0=[sym(.sdata)+56], a1=?, a2=?, a3=?.
  The `jal` at 0x1430 calls splx with a0=[sym(.sbss)], a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x1450 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x1460 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1470 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1480 calls crime_i2cFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x12b0 targets 0x12f8, is taken when v0(=ret(i2_slave_recvbyte)) == 0, and falls through when v0(=ret(i2_slave_recvbyte)) != 0.
  The `beq` branch at 0x12c0 targets 0x1318, is taken when (s1(?) & 0x1) == 0, and falls through when (s1(?) & 0x1) != 0.
  The `beq` branch at 0x12cc targets 0x1430, is taken when v0(=[sym(.sdata)+8]) == 0, and falls through when v0(=[sym(.sdata)+8]) != 0.
  The `beq` branch at 0x1308 targets 0x1448, is taken when v1(?) == a0(=0x2), and falls through when v1(?) != a0(=0x2).
  The `beq` branch at 0x1310 targets 0x12e4 and is always taken.
  The `beq` branch at 0x1330 targets 0x1450, is taken when v0(=ret(i2_slave_recvbyte)) == 0, and falls through when v0(=ret(i2_slave_recvbyte)) != 0.
  The `beq` branch at 0x1358 targets 0x1480, is taken when v0(=ret(i2_slave_recvbyte)) == 0, and falls through when v0(=ret(i2_slave_recvbyte)) != 0.
  The `blez` branch at 0x136c targets 0x13e0, is taken when t8(?) <= 0 (signed), and falls through when t8(?) > 0 (signed).
  The `beq` branch at 0x139c targets 0x1470, is taken when v0(=ret(i2_slave_recvbyte)) == 0, and falls through when v0(=ret(i2_slave_recvbyte)) != 0.
  The `bne` branch at 0x13d8 targets 0x1380, is taken when v0(?) < v1(?) (signed), and falls through when v0(?) >= v1(?) (signed).
  The `beq` branch at 0x13fc targets 0x1460, is taken when v0(=ret(i2_slave_recvbyte)) == 0, and falls through when v0(=ret(i2_slave_recvbyte)) != 0.
  The `beq` branch at 0x1420 targets 0x1440, is taken when a0(?) == s1(?), and falls through when a0(?) != s1(?).
  The `beq` branch at 0x1428 targets 0x12e0 and is always taken.
  The `beq` branch at 0x1438 targets 0x12d4 and is always taken.
  The `beq` branch at 0x1440 targets 0x12e0 and is always taken.
  The `beq` branch at 0x1448 targets 0x12e0 and is always taken.
  The `beq` branch at 0x1458 targets 0x12e0 and is always taken.
  The `beq` branch at 0x1468 targets 0x12e0 and is always taken.
  The `beq` branch at 0x1478 targets 0x12e0 and is always taken.
  The `beq` branch at 0x1488 targets 0x12e0 and is always taken.
  The return at 0x12f0 has v0 = one of ?, -0x1.

- `crime_i2cFpProbe` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x1490 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x1490-0x16d8 (584 bytes).
  It occupies 584 bytes.
  7 such `sw` accesses store 4 bytes to sym(crmFpPrbState) +0x0, including `sw` at 0x14bc, `sw` at 0x1568, `sw` at 0x15d4.
  The `sh` at 0x14e8 stores 2 bytes to sym(crimeBoards) +0x3a.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x14f4, `lw` at 0x1534.
  The `jal` at 0x14ec calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1528 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x1570 calls i2cfp_PanelID with a0=a0 at entry (arg0), a1=sp-48, a2=?, a3=?.
  The `jal` at 0x15f4 calls find_inventory with a0=0x0, a1=0x11, a2=0x0, a3=0x0, a4=0x0, a5=0x0.
  The `jal` at 0x1618 calls replace_in_inventory with a0=ret(find_inventory), a1=0x11, a2=0x1, a3=0x0, a4=0x0, a5=0x0.
  The `jal` at 0x165c calls add_to_inventory with a0=0x11, a1=0x1, a2=0x0, a3=0x0, a4=0x0.
  The `jal` at 0x1688 calls find_inventory with a0=0x0, a1=0x11, a2=0x4, a3=0x0, a4=0x0, a5=0x0.
  The `jal` at 0x16a8 calls replace_in_inventory with a0=ret(find_inventory), a1=0x11, a2=0x5, a3=0x0, a4=0x0, a5=0x0.
  The `jal` at 0x16c8 calls add_to_inventory with a0=0x11, a1=0x5, a2=0x0, a3=0x0, a4=0x0.
  The `beq` branch at 0x14b0 targets 0x14dc, is taken when at(=[sym(crm_dc_board_installed)]) == 0, and falls through when at(=[sym(crm_dc_board_installed)]) != 0.
  The `beq` branch at 0x150c targets 0x1570, is taken when s2(=0x3) == a2(?), and falls through when s2(=0x3) != a2(?).
  The `beq` branch at 0x1514 targets 0x1524 and is always taken.
  The `beq` branch at 0x151c targets 0x156c, is taken when s2(=0x3) == a0(?), and falls through when s2(=0x3) != a0(?).
  The `bne` branch at 0x154c targets 0x151c, is taken when v0(?) < 0x1a (unsigned), and falls through when v0(?) >= 0x1a (unsigned).
  The `beq` branch at 0x1554 targets 0x1570, is taken when s2(=0x3) == a0(?), and falls through when s2(=0x3) != a0(?).
  The `beq` branch at 0x1564 targets 0x14c4 and is always taken.
  The `beq` branch at 0x1578 targets 0x1640, is taken when v0(=ret(i2cfp_PanelID)) == 0, and falls through when v0(=ret(i2cfp_PanelID)) != 0.
  The `beq` branch at 0x1584 targets 0x15e0, is taken when s2(=0x3) == v0(?), and falls through when s2(=0x3) != v0(?).
  The `beq` branch at 0x158c targets 0x15e0, is taken when s1(=0x2) == v0(?), and falls through when s1(=0x2) != v0(?).
  The `beq` branch at 0x1594 targets 0x15e4, is taken when v0(?) == a0(=0x4), and falls through when v0(?) != a0(=0x4).
  The `beq` branch at 0x15a0 targets 0x1678, is taken when v0(?) == a2(=0x5), and falls through when v0(?) != a2(=0x5).
  The `beq` branch at 0x15b4 targets 0x1630, is taken when s1(=0x2) == v0(?), and falls through when s1(=0x2) != v0(?).
  The `beq` branch at 0x15bc targets 0x1630, is taken when s2(=0x3) == v0(?), and falls through when s2(=0x3) != v0(?).
  The `beq` branch at 0x15c4 targets 0x166c, is taken when v0(?) == a0(=0x4), and falls through when v0(?) != a0(=0x4).
  The `beq` branch at 0x15cc targets 0x1628, is taken when v0(?) == a1(=0x5), and falls through when v0(?) != a1(=0x5).
  The `beq` branch at 0x15d8 targets 0x14c4 and is always taken.
  The `beq` branch at 0x15fc targets 0x1650, is taken when v0(=ret(find_inventory)) == 0, and falls through when v0(=ret(find_inventory)) != 0.
  The `beq` branch at 0x1620 targets 0x15ac and is always taken.
  The `beq` branch at 0x1628 targets 0x14c4 and is always taken.
  The `beq` branch at 0x1638 targets 0x14c4 and is always taken.
  The `beq` branch at 0x1648 targets 0x14c4 and is always taken.
  The `beq` branch at 0x1664 targets 0x15ac and is always taken.
  The `beq` branch at 0x1670 targets 0x14c4 and is always taken.
  The `beq` branch at 0x1690 targets 0x16b8, is taken when v0(=ret(find_inventory)) == 0, and falls through when v0(=ret(find_inventory)) != 0.
  The `beq` branch at 0x16b0 targets 0x15ac and is always taken.
  The `beq` branch at 0x16d0 targets 0x15ac and is always taken.
  The return at 0x14d4 has v0 = one of 0x0, 0x82, 0x83, 0x84.

- `crime_i2cFpHotProbe` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x16d8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x16d8-0x1870 (408 bytes).
  It occupies 408 bytes.
  The `lw` at 0x16e0 loads 4 bytes from a0 (arg0 at entry) +0x80.
  The `lw` at 0x16e8 loads 4 bytes from a0 (arg0 at entry) +0x7c.
  4 such `lbu` accesses load 1 byte from [a0+124] +0x2e, including `lbu` at 0x16f0, `lbu` at 0x17f4, `lbu` at 0x180c.
  3 such `lw` accesses load 4 bytes from sym(crmFpPrbState) +0x0, including `lw` at 0x170c, `lw` at 0x1748, `lw` at 0x1750.
  2 such `lbu` accesses load 1 byte from [a0+124] +0x2c, including `lbu` at 0x1710, `lbu` at 0x1760.
  The `sb` at 0x1738 stores 1 byte to [a0+124] +0x2e.
  The `lw` at 0x178c loads 4 bytes from [a0+124] +0x30.
  The `lw` at 0x1798 loads 4 bytes from [[a0+124]+48] +0xc.
  The `lh` at 0x17b8 loads 2 bytes from [[a0+124]+48] +0x8.
  2 such `lh` accesses load 2 bytes from [[a0+124]+48] +0xa, including `lh` at 0x17c8, `lh` at 0x1840.
  The `sw` at 0x1828 stores 4 bytes to a0 (arg0 at entry) +0x1d0.
  The `jal` at 0x1724 calls crime_i2cFpProbe with a0=[a0+128], a1=a1 at entry (arg1), a2=0x84, a3=0x84, a5=[[a0+124]+46]:1.
  The `jal` at 0x17dc calls i2cfp_PanelOn with a0=a0 at entry (arg0), a1=[a0+124], a2=[a0+128], a3=0x84, a4=one of 0x300, 0x500.
  The `jal` at 0x17e8 calls crime_FpSchedForRetrace with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x1800 calls crime_FpSchedForRetrace with a0=a0 at entry (arg0), a1=0x0, a2=sym(crmFpPrbState), a3=?, a6=0x2.
  The `jal` at 0x181c calls timeout with a0=sym(crime_i2cFpHotProbe), a1=a0 at entry (arg0), a2=0xbb8, a3=0x84, a4=[[a0+124]+44]:1.
  The `jal` at 0x1860 calls cmn_err with a0=0x4, a1=sym(.rodata)+32, a2=0x84, a3=a3 at entry (arg3), a5=[[a0+124]+46]:1.
  The `beq` branch at 0x1708 targets 0x1858, is taken when a2(=0x84) == a5(=[[a0+124]+46]:1), and falls through when a2(=0x84) != a5(=[[a0+124]+46]:1).
  The `bne` branch at 0x1714 targets 0x1858, is taken when t8(=[[a0+124]+44]:1) != 0, and falls through when t8(=[[a0+124]+44]:1) == 0.
  The `beq` branch at 0x171c targets 0x1758, is taken when s1(=[sym(crmFpPrbState)]) == t9(=0x1), and falls through when s1(=[sym(crmFpPrbState)]) != t9(=0x1).
  The `beq` branch at 0x1744 targets 0x1784, is taken when s1(=[sym(crmFpPrbState)]) == a6(=0x2), and falls through when s1(=[sym(crmFpPrbState)]) != a6(=0x2).
  The `beq` branch at 0x174c targets 0x17f8, is taken when s1(=[sym(crmFpPrbState)]) == a1(=0x3), and falls through when s1(=[sym(crmFpPrbState)]) != a1(=0x3).
  The `beq` branch at 0x1758 targets 0x176c, is taken when a3(=0x84) == a5(?), and falls through when a3(=0x84) != a5(?).
  The `beq` branch at 0x1764 targets 0x1810, is taken when a4(=[[a0+124]+44]:1) == 0, and falls through when a4(=[[a0+124]+44]:1) != 0.
  The `bne` branch at 0x1784 targets 0x174c, is taken when a0(=[sym(crmFpPrbState)]) != a1(=0x3), and falls through when a0(=[sym(crmFpPrbState)]) == a1(=0x3).
  The `beq` branch at 0x1790 targets 0x1758, is taken when a0(=[[a0+124]+48]) == 0, and falls through when a0(=[[a0+124]+48]) != 0.
  The `bltz` branch at 0x17a4 targets 0x182c, is taken when a1(?) < 0 (signed), and falls through when a1(?) >= 0 (signed).
  The `bne` branch at 0x17ac targets 0x1754, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x17b4 targets 0x1834, is taken when a5(?) == a3(=0x82), and falls through when a5(?) != a3(=0x82).
  The `bne` branch at 0x17c0 targets 0x1758, is taken when a1(=[[[a0+124]+48]+8]:2) != a4(=0x500), and falls through when a1(=[[[a0+124]+48]+8]:2) == a4(=0x500).
  The `bne` branch at 0x17d0 targets 0x1754, is taken when a6(=[[[a0+124]+48]+10]:2) != a7(=0x400), and falls through when a6(=[[[a0+124]+48]+10]:2) == a7(=0x400).
  The `beq` branch at 0x17f0 targets 0x1754 and is always taken.
  The `bne` branch at 0x17f8 targets 0x1754, is taken when t0(=[sym(crmFpPrbState)]) != a6(=0x2), and falls through when t0(=[sym(crmFpPrbState)]) == a6(=0x2).
  The `beq` branch at 0x1808 targets 0x1754 and is always taken.
  The `beq` branch at 0x1824 targets 0x1768 and is always taken.
  The `beq` branch at 0x182c targets 0x17ac and is always taken.
  The `bne` branch at 0x1838 targets 0x1758, is taken when a1(=[[[a0+124]+48]+8]:2) != a2(=0x400), and falls through when a1(=[[[a0+124]+48]+8]:2) == a2(=0x400).
  The `bne` branch at 0x1848 targets 0x1758, is taken when a3(=[[[a0+124]+48]+10]:2) != a4(=0x300), and falls through when a3(=[[[a0+124]+48]+10]:2) == a4(=0x300).
  The `beq` branch at 0x1850 targets 0x17d8 and is always taken.
  The `beq` branch at 0x1868 targets 0x1754 and is always taken.
  The return at 0x177c has v0 = ?.

- `i2cfp_PortRead` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x1870 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x1870-0x18f8 (136 bytes).
  It occupies 136 bytes.
  The `jal` at 0x1898 calls i2_start_addr with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=a1 at entry (arg1).
  The `jal` at 0x18b0 calls i2_master_recvbyte with a0=0x1, a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=0x0.
  The `jal` at 0x18c4 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `beq` branch at 0x18a0 targets 0x18e4, is taken when v0(=ret(i2_start_addr)) == 0, and falls through when v0(=ret(i2_start_addr)) != 0.
  The `beq` branch at 0x18b8 targets 0x18ec, is taken when v0(=ret(i2_master_recvbyte)) == 0, and falls through when v0(=ret(i2_master_recvbyte)) != 0.
  The `beq` branch at 0x18e4 targets 0x18c0 and is always taken.
  The `beq` branch at 0x18f0 targets 0x18c4 and is always taken.
  The return at 0x18dc has v0 = one of 0x0, 0x1.

- `i2cfp_PortWrite` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x18f8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x18f8-0x1978 (128 bytes).
  It occupies 128 bytes.
  The `jal` at 0x191c calls i2_start_addr with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x1930 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x1944 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `beq` branch at 0x1924 targets 0x1964, is taken when v0(=ret(i2_start_addr)) == 0, and falls through when v0(=ret(i2_start_addr)) != 0.
  The `beq` branch at 0x1938 targets 0x196c, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x1964 targets 0x1940 and is always taken.
  The `beq` branch at 0x1970 targets 0x1944 and is always taken.
  The return at 0x195c has v0 = one of 0x0, 0x1.

- `i2cfp_PanelID` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x1978 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x1978-0x19c0 (72 bytes).
  It occupies 72 bytes.
  The `lbu` at 0x199c loads 1 byte from a1 (arg1 at entry) +0x0.
  The `sb` at 0x19ac stores 1 byte to a1 (arg1 at entry) +0x0.
  The `jal` at 0x1988 calls i2cfp_PortRead with a0=a0 at entry (arg0), a1=0x70, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `beq` branch at 0x1990 targets 0x19b8, is taken when v0(=ret(i2cfp_PortRead)) == 0, and falls through when v0(=ret(i2cfp_PortRead)) != 0.
  The `beq` branch at 0x19b8 targets 0x19b0 and is always taken.
  The return at 0x19b0 has v0 = one of 0x0, 0x1.

- `i2cfp_DualChannelProbe` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x19c0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x19c0-0x1a84 (196 bytes).
  It occupies 196 bytes.
  The `jal` at 0x19d4 calls i2cfp_PortRead with a0=a0 at entry (arg0), a1=0x7e, a2=sp-32, a3=a3 at entry (arg3).
  The `jal` at 0x19f4 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x7e, a2=0xff, a3=?.
  The `jal` at 0x1a04 calls i2cfp_PortRead with a0=a0 at entry (arg0), a1=0x7e, a2=sp-31, a3=?.
  The `jal` at 0x1a20 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x7e, a2=0x7f, a3=?.
  The `jal` at 0x1a30 calls i2cfp_PortRead with a0=a0 at entry (arg0), a1=0x7e, a2=sp-31, a3=?.
  The `jal` at 0x1a5c calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x7e, a2=?, a3=?.
  The `bne` branch at 0x19dc targets 0x19ec, is taken when v0(=ret(i2cfp_PortRead)) != 0, and falls through when v0(=ret(i2cfp_PortRead)) == 0.
  The `beq` branch at 0x19e4 targets 0x1a70 and is always taken.
  The return at 0x1a7c has v0 = one of 0x0, ?.

- `i2cfp_DualChannelCommand` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x1a84 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x1a84-0x1aa4 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x1a90 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x7e, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The return at 0x1a9c has v0 = ret(i2cfp_PortWrite).

- `i2_start` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x1aa4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x1aa4-0x1bec (328 bytes).
  It occupies 328 bytes.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x1ac8, `sw` at 0x1b08, `sw` at 0x1b30.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x1acc, `lw` at 0x1b0c, `lw` at 0x1b34.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x10, including `sw` at 0x1b68, `sw` at 0x1b98, `sw` at 0x1bc0.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10, including `lw` at 0x1b6c, `lw` at 0x1b9c, `lw` at 0x1bc4.
  The `jal` at 0x1ae4 calls us_delay with a0=[sym(.sdata)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(.sdata)].
  The `jal` at 0x1af0 calls i2_sync_clk with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1b28 calls us_delay with a0=[sym(.sdata)], a1=?, a2=[a1+8], a3=[sym(.sdata)], a4=0x1.
  The `jal` at 0x1b4c calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?, a6=[a1+8].
  The `jal` at 0x1b84 calls us_delay with a0=[sym(.sdata)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(.sdata)].
  The `jal` at 0x1bb4 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=[sym(.sdata)].
  The `jal` at 0x1bdc calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `beq` branch at 0x1ac0 targets 0x1b68, is taken when a0 == at(=0x1), and falls through when a0 != at(=0x1).
  The `beq` branch at 0x1afc targets 0x1b94, is taken when s1(=a0) == a0(=0x1), and falls through when s1(=a0) != a0(=0x1).
  The `beq` branch at 0x1b8c targets 0x1af0 and is always taken.
  The `beq` branch at 0x1be4 targets 0x1b58 and is always taken.
  The return at 0x1b60 has v0 = ret(us_delay).

- `i2_stop` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x1c38 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x1c38-0x1da0 (360 bytes).
  It occupies 360 bytes.
  4 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x1c58, `sw` at 0x1c80, `sw` at 0x1ca8.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x1c5c, `lw` at 0x1c84, `lw` at 0x1cac.
  4 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x10, including `sw` at 0x1d00, `sw` at 0x1d28, `sw` at 0x1d50.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10, including `lw` at 0x1d04, `lw` at 0x1d2c, `lw` at 0x1d54.
  The `jal` at 0x1c74 calls us_delay with a0=[sym(.sdata)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(.sdata)], a4=0x2.
  The `jal` at 0x1c9c calls us_delay with a0=[sym(.sdata)], a1=?, a2=[a1+8], a3=0x3.
  The `jal` at 0x1cc4 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?, a5=[a1+8], a6=0x1.
  The `jal` at 0x1ce8 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x1d1c calls us_delay with a0=[sym(.sdata)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(.sdata)], a4=0x2.
  The `jal` at 0x1d44 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x1d6c calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x1d90 calls us_delay with a0=[sym(.sdata)], a1=?, a2=[a1+16], a3=?.
  The `beq` branch at 0x1c50 targets 0x1d00, is taken when a0 == at(=0x1), and falls through when a0 != at(=0x1).
  The `beq` branch at 0x1d98 targets 0x1cf4 and is always taken.
  The return at 0x1cf8 has v0 = ret(us_delay).

- `i2_sync_clk` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x1da0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x1da0-0x1e50 (176 bytes).
  It occupies 176 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x1dc0, `lw` at 0x1dec.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10, including `lw` at 0x1e28, `lw` at 0x1e38.
  The `jal` at 0x1dd8 calls us_delay with a0=0x1, a1=?, a2=?, a3=?, a4=0x1.
  The `beq` branch at 0x1db8 targets 0x1e34, is taken when a0 == a4(=0x1), and falls through when a0 != a4(=0x1).
  The `beq` branch at 0x1dc8 targets 0x1e2c, is taken when (v0(?) & 0x2) == 0, and falls through when (v0(?) & 0x2) != 0.
  The `beq` branch at 0x1dd0 targets 0x1e3c and is always taken.
  The `beq` branch at 0x1de4 targets 0x1e24, is taken when s2(=a0) == a4(=0x1), and falls through when s2(=a0) != a4(=0x1).
  The `beq` branch at 0x1dfc targets 0x1e2c, is taken when (v0(?) & 0x2) == 0, and falls through when (v0(?) & 0x2) != 0.
  The `bne` branch at 0x1e04 targets 0x1dd8, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x1e24 targets 0x1df0 and is always taken.
  The `beq` branch at 0x1e2c targets 0x1e0c and is always taken.
  The `beq` branch at 0x1e34 targets 0x1dc4 and is always taken.
  The `beq` branch at 0x1e48 targets 0x1e04 and is always taken.
  The return at 0x1e1c has v0 = one of 0x0, 0x1.

- `i2_sendbyte` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x1e50 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x1e50-0x2290 (1088 bytes).
  It occupies 1088 bytes.
  9 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x1e94, `sw` at 0x1ed8, `sw` at 0x1ef8.
  11 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x1e98, `lw` at 0x1edc, `lw` at 0x1efc.
  9 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x10, including `sw` at 0x1f3c, `sw` at 0x1ff4, `sw` at 0x2014.
  11 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10, including `lw` at 0x1f40, `lw` at 0x1ff8, `lw` at 0x2018.
  The `jal` at 0x1eac calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x1ef0 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x1f14 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x1f20 calls i2_sync_clk with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1f54 calls us_delay with a0=[sym(.sdata)], a1=[a1+16], a2=?, a3=?.
  The `jal` at 0x1f84 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=[a1+8].
  The `jal` at 0x1fa8 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?, a5=[a1+8].
  The `jal` at 0x1fb4 calls i2_sync_clk with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1fe4 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?, a7=[a1+8].
  The `jal` at 0x200c calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x2030 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x2058 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x207c calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x20a4 calls us_delay with a0=[sym(.sdata)], a1=[a1+16], a2=?, a3=?.
  The `jal` at 0x20d4 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=[a1+8].
  The `jal` at 0x20f8 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?, a5=[a1+8].
  The `jal` at 0x2104 calls i2_sync_clk with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x2138 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x21bc calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x21dc calls us_delay with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x220c calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x2230 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x2268 calls us_delay with a0=[sym(.sdata)], a1=[a1+16], a2=?, a3=?.
  The `beq` branch at 0x1e8c targets 0x2278 and is always taken.
  The `beq` branch at 0x1ebc targets 0x20b4, is taken when (s3(?) & 0xff) == 0, and falls through when (s3(?) & 0xff) != 0.
  The `beq` branch at 0x1ec8 targets 0x1f64, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x1ed0 targets 0x1ff4, is taken when s1(=a0) == s2(=0x1), and falls through when s1(=a0) != s2(=0x1).
  The `beq` branch at 0x1f28 targets 0x216c, is taken when v0(=ret(i2_sync_clk)) == 0, and falls through when v0(=ret(i2_sync_clk)) != 0.
  The `bne` branch at 0x1f34 targets 0x1e94, is taken when s1(=a0) != s2(=0x1), and falls through when s1(=a0) == s2(=0x1).
  The `beq` branch at 0x1f5c targets 0x1eb8 and is always taken.
  The `beq` branch at 0x1f64 targets 0x2040, is taken when s1(=a0) == s2(=0x1), and falls through when s1(=a0) != s2(=0x1).
  The `beq` branch at 0x1fbc targets 0x21ec, is taken when v0(=ret(i2_sync_clk)) == 0, and falls through when v0(=ret(i2_sync_clk)) != 0.
  The `beq` branch at 0x1fc4 targets 0x208c, is taken when s1(=a0) == s2(=0x1), and falls through when s1(=a0) != s2(=0x1).
  The `beq` branch at 0x1fec targets 0x1eb8 and is always taken.
  The `beq` branch at 0x2038 targets 0x1f20 and is always taken.
  The `beq` branch at 0x2084 targets 0x1fb0 and is always taken.
  The `beq` branch at 0x20ac targets 0x1eb8 and is always taken.
  The `beq` branch at 0x20b4 targets 0x21f4, is taken when s1(=a0) == s2(=0x1), and falls through when s1(=a0) != s2(=0x1).
  The `beq` branch at 0x210c targets 0x2248, is taken when v0(=ret(i2_sync_clk)) == 0, and falls through when v0(=ret(i2_sync_clk)) != 0.
  The `beq` branch at 0x2114 targets 0x2240, is taken when s1(=a0) == s2(=0x1), and falls through when s1(=a0) != s2(=0x1).
  The `beq` branch at 0x2128 targets 0x219c, is taken when (a6(?) & 0x1) == 0, and falls through when (a6(?) & 0x1) != 0.
  The `beq` branch at 0x2130 targets 0x2284 and is always taken.
  The `beq` branch at 0x2140 targets 0x2194, is taken when s1(=a0) == s2(=0x1), and falls through when s1(=a0) != s2(=0x1).
  The `beq` branch at 0x2158 targets 0x219c, is taken when (a7(?) & 0x1) == 0, and falls through when (a7(?) & 0x1) != 0.
  The `bne` branch at 0x2160 targets 0x2138, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x2194 targets 0x214c and is always taken.
  The `beq` branch at 0x219c targets 0x2250, is taken when s1(=a0) == s2(=0x1), and falls through when s1(=a0) != s2(=0x1).
  The `beq` branch at 0x21d0 targets 0x21dc, is taken when a0(=[sym(.sdata)+36]) >= v0(=[sym(.sdata)+32]) (signed), and falls through when a0(=[sym(.sdata)+36]) < v0(=[sym(.sdata)+32]) (signed).
  The `beq` branch at 0x21e4 targets 0x216c and is always taken.
  The `beq` branch at 0x21ec targets 0x216c and is always taken.
  The `beq` branch at 0x2238 targets 0x2100 and is always taken.
  The `beq` branch at 0x2240 targets 0x2120 and is always taken.
  The `beq` branch at 0x2248 targets 0x216c and is always taken.
  The `beq` branch at 0x2270 targets 0x21c8 and is always taken.
  The `beq` branch at 0x227c targets 0x1ec8 and is always taken.
  The `beq` branch at 0x2288 targets 0x2160 and is always taken.
  The return at 0x218c has v0 = one of 0x0, 0x1.

- `i2_wait_for_bus` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x2290 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x2290-0x23c4 (308 bytes).
  It occupies 308 bytes.
  The `sw` at 0x22c4 stores 4 bytes to a1 (arg1 at entry) +0x8.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x22c8, `lw` at 0x22e8, `lw` at 0x231c.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10, including `lw` at 0x235c, `lw` at 0x239c, `lw` at 0x23c0.
  The `sw` at 0x2398 stores 4 bytes to a1 (arg1 at entry) +0x10.
  The `jal` at 0x22e0 calls us_delay with a0=[sym(.sdata)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(.sdata)].
  The `jal` at 0x2320 calls us_delay with a0=0x64, a1=[sym(.sdata)+88], a2=?, a3=?.
  The `jal` at 0x2368 calls us_delay with a0=0x64, a1=[sym(.sdata)+88], a2=?, a3=?.
  The `jal` at 0x23b4 calls us_delay with a0=[sym(.sdata)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(.sdata)], a5=[a1+16].
  The `beq` branch at 0x22bc targets 0x2398, is taken when a0 == s4(=0x1), and falls through when a0 != s4(=0x1).
  The `beq` branch at 0x2304 targets 0x2370, is taken when s5(=0x2) == v1(?), and falls through when s5(=0x2) != v1(?).
  The `bgtz` branch at 0x230c targets 0x2350, is taken when a1(=[sym(.sdata)+88]) > 0 (signed), and falls through when a1(=[sym(.sdata)+88]) <= 0 (signed).
  The `beq` branch at 0x2314 targets 0x2370 and is always taken.
  The `beq` branch at 0x233c targets 0x2360, is taken when s5(=0x2) == a0(?), and falls through when s5(=0x2) != a0(?).
  The `beq` branch at 0x2348 targets 0x2360, is taken when s0(?) >= a1(=[sym(.sdata)+88]) (signed), and falls through when s0(?) < a1(=[sym(.sdata)+88]) (signed).
  The `bne` branch at 0x2350 targets 0x231c, is taken when s3(=a0) != s4(=0x1), and falls through when s3(=a0) == s4(=0x1).
  The `beq` branch at 0x2358 targets 0x2320 and is always taken.
  The `beq` branch at 0x2360 targets 0x2374, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x23bc targets 0x22ec and is always taken.
  The return at 0x2390 has v0 = 0x1.

- `i2_spin_for` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x23c4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x23c4-0x24d0 (268 bytes).
  It occupies 268 bytes.
  The `lbu` at 0x23d0 loads 1 byte from a5 (arg5 at entry) +0x0.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x23dc, `lw` at 0x2438, `lw` at 0x2468.
  3 such `sb` accesses store 1 byte to a6 (arg6 at entry) +0x0, including `sb` at 0x2414, `sb` at 0x2490, `sb` at 0x24cc.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10, including `lw` at 0x24ac, `lw` at 0x24b4, `lw` at 0x24bc.
  The `beq` branch at 0x23c4 targets 0x23d4, is taken when a5 == 0, and falls through when a5 != 0.
  The `beq` branch at 0x23cc targets 0x23ec and is always taken.
  The `beq` branch at 0x23d4 targets 0x24b8, is taken when a0 == v0(=0x1), and falls through when a0 != v0(=0x1).
  The `beq` branch at 0x23f4 targets 0x240c, is taken when a3 == v1(?), and falls through when a3 != v1(?).
  The `bgtz` branch at 0x23fc targets 0x2430, is taken when a4 > 0 (signed), and falls through when a4 <= 0 (signed).
  The `beq` branch at 0x2404 targets 0x24c0 and is always taken.
  The `beq` branch at 0x240c targets 0x2418, is taken when a6 == 0, and falls through when a6 != 0.
  The `blez` branch at 0x2418 targets 0x24a0, is taken when a4 <= 0 (signed), and falls through when a4 > 0 (signed).
  The `beq` branch at 0x2428 targets 0x2488, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x2430 targets 0x24a8, is taken when a0 == t3(=0x1), and falls through when a0 != t3(=0x1).
  The `beq` branch at 0x2450 targets 0x2488, is taken when a3 == a7(?), and falls through when a3 != a7(?).
  The `beq` branch at 0x2458 targets 0x2488, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x2460 targets 0x24b0, is taken when a0 == t3(=0x1), and falls through when a0 != t3(=0x1).
  The `bne` branch at 0x2480 targets 0x2428, is taken when a3 != v1(?), and falls through when a3 == v1(?).
  The `beq` branch at 0x2488 targets 0x2498, is taken when a6 == 0, and falls through when a6 != 0.
  The `bne` branch at 0x2498 targets 0x2420, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0x24a8 targets 0x243c and is always taken.
  The `beq` branch at 0x24b0 targets 0x246c and is always taken.
  The `beq` branch at 0x24b8 targets 0x23e0 and is always taken.
  The `beq` branch at 0x24c0 targets 0x24a0, is taken when a6 == 0, and falls through when a6 != 0.
  The `beq` branch at 0x24c8 targets 0x24a0 and is always taken.
  The return at 0x2420 has v0 = 0x1.
  The return at 0x24a0 has v0 = 0x0.

- `i2_wait_for_stop` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x24d0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x24d0-0x255c (140 bytes).
  It occupies 140 bytes.
  The `jal` at 0x24f4 calls i2_spin_for with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2, a3=0x2, a4=[sym(.sdata)+92], a5=0x0, a6=sp-48.
  The `jal` at 0x2528 calls i2_spin_for with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x3, a3=0x3, a5=0x0, a6=0x0.
  The `beq` branch at 0x24fc targets 0x2554, is taken when v0(=ret(i2_spin_for)) == 0, and falls through when v0(=ret(i2_spin_for)) != 0.
  The `beq` branch at 0x2508 targets 0x2544, is taken when at(?) == v0(=0x3), and falls through when at(?) != v0(=0x3).
  The `beq` branch at 0x2530 targets 0x254c, is taken when v0(=ret(i2_spin_for)) == 0, and falls through when v0(=ret(i2_spin_for)) != 0.
  The `beq` branch at 0x2544 targets 0x253c and is always taken.
  The `beq` branch at 0x254c targets 0x2538 and is always taken.
  The `beq` branch at 0x2554 targets 0x2538 and is always taken.
  The return at 0x253c has v0 = one of 0x0, 0x1.

- `i2_slave_recvbyte` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x255c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x255c-0x2884 (808 bytes).
  It occupies 808 bytes.
  The `lbu` at 0x2604 loads 1 byte from a2 (arg2 at entry) +0x0.
  The `sb` at 0x2618 stores 1 byte to a2 (arg2 at entry) +0x0.
  6 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x268c, `sw` at 0x26fc, `sw` at 0x275c.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x2690, `lw` at 0x2700, `lw` at 0x279c.
  6 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x10, including `sw` at 0x2734, `sw` at 0x27bc, `sw` at 0x2828.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10, including `lw` at 0x2738, `lw` at 0x27c0, `lw` at 0x2840.
  5 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0x2760, `sw` at 0x277c, `sw` at 0x27e4.
  The `jal` at 0x25c8 calls i2_spin_for with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2, a3=0x0, a5=0x0, a6=0x0.
  The `jal` at 0x25f4 calls i2_spin_for with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2, a3=0x2, a5=0x0, a6=sp-80.
  The `jal` at 0x2674 calls i2_spin_for with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2, a3=0x0, a4=[sym(.sdata)+96], a5=0x0, a6=0x0.
  The `jal` at 0x26b8 calls i2_spin_for with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2, a3=0x2, a4=[sym(.sdata)+96], a5=sp-80, a6=0x0.
  The `jal` at 0x26dc calls i2_spin_for with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2, a3=0x0, a4=[sym(.sdata)+96], a5=0x0, a6=0x0.
  The `jal` at 0x274c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x276c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x27ac calls splx with a0=[sym(.sbss)], a1=?, a2=a5 at entry (arg5), a3=?, a5=[sym(.sdata)+8].
  The `jal` at 0x27cc calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x27e8 calls splprof with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2804 calls splx with a0=[sym(.sbss)], a1=?, a2=a5 at entry (arg5), a3=?.
  The `jal` at 0x2854 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `beq` branch at 0x2598 targets 0x25a4, is taken when at(=[sym(.sdata)+8]) == 0, and falls through when at(=[sym(.sdata)+8]) != 0.
  The `beq` branch at 0x25a0 targets 0x27e8, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0x25a8 targets 0x2878 and is always taken.
  The `beq` branch at 0x25d0 targets 0x27cc, is taken when v0(=ret(i2_spin_for)) == 0, and falls through when v0(=ret(i2_spin_for)) != 0.
  The `beq` branch at 0x25d8 targets 0x2654, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x25fc targets 0x276c, is taken when v0(=ret(i2_spin_for)) == 0, and falls through when v0(=ret(i2_spin_for)) != 0.
  The `beq` branch at 0x2614 targets 0x264c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x2624 targets 0x265c, is taken when s0(?) >= 0x8 (signed), and falls through when s0(?) < 0x8 (signed).
  The `beq` branch at 0x262c targets 0x25b4, is taken when a0(=[sym(.sdata)+8]) == 0, and falls through when a0(=[sym(.sdata)+8]) != 0.
  The `bne` branch at 0x2634 targets 0x25b4, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `bne` branch at 0x263c targets 0x25b4, is taken when s5(=a4) != 0, and falls through when s5(=a4) == 0.
  The `beq` branch at 0x2644 targets 0x25e0 and is always taken.
  The `beq` branch at 0x264c targets 0x261c and is always taken.
  The `beq` branch at 0x2654 targets 0x25dc and is always taken.
  The `beq` branch at 0x267c targets 0x2854, is taken when v0(=ret(i2_spin_for)) == 0, and falls through when v0(=ret(i2_spin_for)) != 0.
  The `beq` branch at 0x2684 targets 0x2734, is taken when s2(=a0) == s0(=0x1), and falls through when s2(=a0) != s0(=0x1).
  The `beq` branch at 0x26c0 targets 0x274c, is taken when v0(=ret(i2_spin_for)) == 0, and falls through when v0(=ret(i2_spin_for)) != 0.
  The `beq` branch at 0x26e4 targets 0x2804, is taken when v0(=ret(i2_spin_for)) == 0, and falls through when v0(=ret(i2_spin_for)) != 0.
  The `beq` branch at 0x26ec targets 0x2788, is taken when a2(=a5) == 0, and falls through when a2(=a5) != 0.
  The `beq` branch at 0x26f4 targets 0x27bc, is taken when s2(=a0) == s0(=0x1), and falls through when s2(=a0) != s0(=0x1).
  The `beq` branch at 0x2744 targets 0x26a0 and is always taken.
  The `beq` branch at 0x2754 targets 0x2824, is taken when s2(=a0) == s0(=0x1), and falls through when s2(=a0) != s0(=0x1).
  The `beq` branch at 0x2764 targets 0x270c and is always taken.
  The `beq` branch at 0x2774 targets 0x282c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x2780 targets 0x270c and is always taken.
  The `beq` branch at 0x2788 targets 0x26f4, is taken when a5(=[sym(.sdata)+8]) == 0, and falls through when a5(=[sym(.sdata)+8]) != 0.
  The `beq` branch at 0x2790 targets 0x283c, is taken when s2(=a0) == s0(=0x1), and falls through when s2(=a0) != s0(=0x1).
  The `beq` branch at 0x27b4 targets 0x270c and is always taken.
  The `beq` branch at 0x27c4 targets 0x2708 and is always taken.
  The `beq` branch at 0x27d4 targets 0x2834, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x27e0 targets 0x270c and is always taken.
  The `beq` branch at 0x27f4 targets 0x2868, is taken when s2(=a0) == t0(=0x1), and falls through when s2(=a0) != t0(=0x1).
  The `beq` branch at 0x27fc targets 0x25a4 and is always taken.
  The `beq` branch at 0x280c targets 0x2870, is taken when s2(=a0) == s0(=0x1), and falls through when s2(=a0) != s0(=0x1).
  The `beq` branch at 0x281c targets 0x270c and is always taken.
  The `beq` branch at 0x2824 targets 0x2760 and is always taken.
  The `beq` branch at 0x282c targets 0x277c and is always taken.
  The `beq` branch at 0x2834 targets 0x27e0 and is always taken.
  The `beq` branch at 0x284c targets 0x27ac and is always taken.
  The `beq` branch at 0x2860 targets 0x270c and is always taken.
  The `beq` branch at 0x2868 targets 0x25a4 and is always taken.
  The `beq` branch at 0x2870 targets 0x2818 and is always taken.
  The `beq` branch at 0x287c targets 0x262c and is always taken.
  The return at 0x272c has v0 = one of 0x0, 0x1.
  The instructions from 0x25b0 to 0x25b0 are not reached by any path from the entry, and their branches are not listed.

- `i2_master_recvbyte` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x2884 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x2884-0x2c10 (908 bytes).
  It occupies 908 bytes.
  7 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x28c4, `sw` at 0x2904, `sw` at 0x2940.
  8 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x28c8, `lw` at 0x28f0, `lw` at 0x2908.
  2 such `sb` accesses store 1 byte to a2 (arg2 at entry) +0x0, including `sb` at 0x2900, `sb` at 0x2998.
  The `lbu` at 0x2978 loads 1 byte from a2 (arg2 at entry) +0x0.
  8 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10, including `lw` at 0x2988, `lw` at 0x29a0, `lw` at 0x29cc.
  7 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x10, including `sw` at 0x299c, `sw` at 0x29c8, `sw` at 0x2a9c.
  The `jal` at 0x28e0 calls us_delay with a0=[sym(.sdata)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2920 calls us_delay with a0=[sym(.sdata)], a1=[a1+8], a2=?, a3=?.
  The `jal` at 0x295c calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?, a5=[a1+8].
  The `jal` at 0x2968 calls i2_sync_clk with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x29b8 calls us_delay with a0=[sym(.sdata)], a1=([a2]:1 << 0x1), a2=?, a3=[a1+16].
  The `jal` at 0x29e4 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?, a6=[a1+16].
  The `jal` at 0x2a24 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?, a7=a3 at entry (arg3).
  The `jal` at 0x2a30 calls i2_sync_clk with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x2a64 calls us_delay with a0=[sym(.sdata)], a1=0x3, a2=?, a3=?.
  The `jal` at 0x2a6c calls us_delay with a0=[sym(.sdata)+32], a1=?, a2=?, a3=?.
  The `jal` at 0x2ab8 calls us_delay with a0=[sym(.sdata)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2aec calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?, a7=a3 at entry (arg3).
  The `jal` at 0x2af8 calls i2_sync_clk with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x2b2c calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `jal` at 0x2b60 calls us_delay with a0=[sym(.sdata)], a1=?, a2=[a1+16], a3=?, a7=a3 at entry (arg3).
  The `jal` at 0x2b8c calls us_delay with a0=[sym(.sdata)], a1=0x3, a2=?, a3=?, a4=[a1+16].
  The `jal` at 0x2bb8 calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?, a6=[a1+8].
  The `jal` at 0x2bec calls us_delay with a0=[sym(.sdata)], a1=?, a2=?, a3=?.
  The `beq` branch at 0x28bc targets 0x2a9c, is taken when a0 == s3(=0x1), and falls through when a0 != s3(=0x1).
  The `beq` branch at 0x28e8 targets 0x2c04 and is always taken.
  The `beq` branch at 0x2930 targets 0x29f4, is taken when s5(?) >= 0x8 (unsigned), and falls through when s5(?) < 0x8 (unsigned).
  The `beq` branch at 0x2938 targets 0x29c8, is taken when s1(=a0) == s3(=0x1), and falls through when s1(=a0) != s3(=0x1).
  The `beq` branch at 0x2970 targets 0x2b3c, is taken when v0(=ret(i2_sync_clk)) == 0, and falls through when v0(=ret(i2_sync_clk)) != 0.
  The `bne` branch at 0x2980 targets 0x28f0, is taken when s1(=a0) != s3(=0x1), and falls through when s1(=a0) == s3(=0x1).
  The `beq` branch at 0x29c0 targets 0x2928 and is always taken.
  The `beq` branch at 0x29ec targets 0x2964 and is always taken.
  The `beq` branch at 0x29f8 targets 0x2ac8, is taken when a7(=a3) == 0, and falls through when a7(=a3) != 0.
  The `beq` branch at 0x2a00 targets 0x2b44, is taken when s1(=a0) == s3(=0x1), and falls through when s1(=a0) != s3(=0x1).
  The `beq` branch at 0x2a38 targets 0x2bc8, is taken when v0(=ret(i2_sync_clk)) == 0, and falls through when v0(=ret(i2_sync_clk)) != 0.
  The `beq` branch at 0x2a40 targets 0x2b70, is taken when s1(=a0) == s3(=0x1), and falls through when s1(=a0) != s3(=0x1).
  The `beq` branch at 0x2ac0 targets 0x28e8 and is always taken.
  The `beq` branch at 0x2ac8 targets 0x2bd0, is taken when s1(=a0) == s3(=0x1), and falls through when s1(=a0) != s3(=0x1).
  The `beq` branch at 0x2b00 targets 0x2bfc, is taken when v0(=ret(i2_sync_clk)) == 0, and falls through when v0(=ret(i2_sync_clk)) != 0.
  The `bne` branch at 0x2b08 targets 0x2b9c, is taken when s1(=a0) != s3(=0x1), and falls through when s1(=a0) == s3(=0x1).
  The `beq` branch at 0x2b34 targets 0x2a6c and is always taken.
  The `beq` branch at 0x2b3c targets 0x2a78 and is always taken.
  The `beq` branch at 0x2b68 targets 0x2a30 and is always taken.
  The `beq` branch at 0x2b94 targets 0x2a6c and is always taken.
  The `beq` branch at 0x2bc0 targets 0x2a6c and is always taken.
  The `beq` branch at 0x2bc8 targets 0x2a78 and is always taken.
  The `beq` branch at 0x2bf4 targets 0x2af8 and is always taken.
  The `beq` branch at 0x2bfc targets 0x2a78 and is always taken.
  The `beq` branch at 0x2c08 targets 0x2938 and is always taken.
  The return at 0x2a94 has v0 = one of 0x0, 0x1.

- `i2cfp_DMI2_BkltWrapper` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x2c10 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x2c10-0x2ca0 (144 bytes).
  It occupies 144 bytes.
  The `jal` at 0x2c24 calls copyin with a0=a1 at entry (arg1), a1=sp-48, a2=0x8, a3=a3 at entry (arg3).
  The `jal` at 0x2c48 calls copyin with a0=?, a1=sp-40, a2=0x1, a3=?.
  The `jal` at 0x2c6c calls i2cfp_DMI2_BkltFuncs with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=sp-40.
  The `jal` at 0x2c80 calls copyout with a0=sp-40, a1=?, a2=0x1, a3=?.
  The `beq` branch at 0x2c2c targets 0x2c44, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x2c50 targets 0x2c60, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x2c58 targets 0x2c38 and is always taken.
  The `beq` branch at 0x2c88 targets 0x2c98, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x2c90 targets 0x2c38 and is always taken.
  The `beq` branch at 0x2c98 targets 0x2c38 and is always taken.
  The return at 0x2c3c has v0 = one of -0xe, ?.

- `i2cfp_DMI2_BkltFuncs` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x2ca0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x2ca0-0x2e1c (380 bytes).
  It occupies 380 bytes.
  The `lbu` at 0x2d60 loads 1 byte from a4 (arg4 at entry) +0x0.
  The `sb` at 0x2db0 stores 1 byte to a4 (arg4 at entry) +0x0.
  The `jal` at 0x2d18 calls i2_start_addr with a0=0x1, a1=a0 at entry (arg0), a2=0x50, a3=a3 at entry (arg3).
  The `jal` at 0x2d3c calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=(a1 | a2).
  The `jal` at 0x2d78 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=[a4]:1, a4=0x1.
  The `jal` at 0x2d98 calls i2_master_recvbyte with a0=0x1, a1=a0 at entry (arg0), a2=sp-80, a3=0x1, a4=0x1.
  The `jal` at 0x2db8 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x2e04 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `bne` branch at 0x2cd4 targets 0x2ce0, is taken when a1 < 0x81 (signed), and falls through when a1 >= 0x81 (signed).
  The `beq` branch at 0x2cf0 targets 0x2de4, is taken when s0(=a1) == v1(=0x90), and falls through when s0(=a1) != v1(=0x90).
  The `beq` branch at 0x2cf8 targets 0x2de4, is taken when s0(=a1) == v0(=0xb0), and falls through when s0(=a1) != v0(=0xb0).
  The `beq` branch at 0x2d00 targets 0x2df4, is taken when s0(=a1) == a0(=0xa0), and falls through when s0(=a1) != a0(=0xa0).
  The `beq` branch at 0x2d08 targets 0x2df4, is taken when s0(=a1) == a1(=0xc0), and falls through when s0(=a1) != a1(=0xc0).
  The `beq` branch at 0x2d20 targets 0x2dec, is taken when v0(=ret(i2_start_addr)) == 0, and falls through when v0(=ret(i2_start_addr)) != 0.
  The `beq` branch at 0x2d44 targets 0x2dfc, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x2d4c targets 0x2e04, is taken when s3(=one of 0x2, 0x3) == a0(=0x2), and falls through when s3(=one of 0x2, 0x3) != a0(=0x2).
  The `beq` branch at 0x2d58 targets 0x2d90, is taken when s2(=one of 0x0, 0x1, 0x2) == a4(=0x1), and falls through when s2(=one of 0x0, 0x1, 0x2) != a4(=0x1).
  The `bne` branch at 0x2d80 targets 0x2db8, is taken when v0(=ret(i2_sendbyte)) != 0, and falls through when v0(=ret(i2_sendbyte)) == 0.
  The `beq` branch at 0x2d88 targets 0x2dc4 and is always taken.
  The `beq` branch at 0x2da0 targets 0x2e14, is taken when v0(=ret(i2_master_recvbyte)) == 0, and falls through when v0(=ret(i2_master_recvbyte)) != 0.
  The `beq` branch at 0x2de4 targets 0x2d10 and is always taken.
  The `beq` branch at 0x2dec targets 0x2dc4 and is always taken.
  The `beq` branch at 0x2df4 targets 0x2d10 and is always taken.
  The `beq` branch at 0x2dfc targets 0x2dc4 and is always taken.
  The `beq` branch at 0x2e0c targets 0x2dc4 and is always taken.
  The `beq` branch at 0x2e14 targets 0x2dc4 and is always taken.
  The return at 0x2ddc has v0 = one of 0x0, 0x1.

- `i2cfp_DMI2_SensorFuncs` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x2e1c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x2e1c-0x30ec (720 bytes).
  It occupies 720 bytes.
  The `lbu` at 0x2fc8 loads 1 byte from ?.
  The `jal` at 0x2e38 calls copyin with a0=a1 at entry (arg1), a1=sp-320, a2=0xc, a3=a3 at entry (arg3).
  The `jal` at 0x2ea0 calls i2_start_addr with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x2eb4 calls copyin with a0=?, a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0x2eec calls i2_master_recvbyte with a0=0x1, a1=a0 at entry (arg0), a2=sp-304, a3=0x1.
  The `jal` at 0x2f20 calls i2_master_recvbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=0x1.
  The `jal` at 0x2f54 calls i2_master_recvbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=0x0.
  The `jal` at 0x2f64 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x2f74 calls copyout with a0=sp-304, a1=?, a2=0x100, a3=?.
  The `jal` at 0x2fa0 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x2fcc calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x2ff4 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3034 calls i2_master_recvbyte with a0=0x1, a1=a0 at entry (arg0), a2=sp-319, a3=0x1.
  The `jal` at 0x3060 calls copyout with a0=sp-320, a1=a1 at entry (arg1), a2=0xc, a3=?.
  The `jal` at 0x3088 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x30c4 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x30dc calls cmn_err with a0=0x4, a1=sym(.rodata)+88, a2=?, a3=?.
  The `beq` branch at 0x2e44 targets 0x2e68, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x2e6c targets 0x2ecc, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x2e78 targets 0x2ecc, is taken when v0(?) == at(=0x2), and falls through when v0(?) != at(=0x2).
  The `beq` branch at 0x2e80 targets 0x2e94, is taken when v0(?) == v1(=0x1), and falls through when v0(?) != v1(=0x1).
  The `bne` branch at 0x2e8c targets 0x30d4, is taken when v0(?) != a0(=0x3), and falls through when v0(?) == a0(=0x3).
  The `beq` branch at 0x2ea8 targets 0x2f8c, is taken when v0(=ret(i2_start_addr)) == 0, and falls through when v0(=ret(i2_start_addr)) != 0.
  The `beq` branch at 0x2ebc targets 0x2ed4, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x2ec4 targets 0x2e50 and is always taken.
  The `beq` branch at 0x2ecc targets 0x2e94 and is always taken.
  The `beq` branch at 0x2ed4 targets 0x2f94, is taken when s2(=one of 0x0, 0x1) == 0, and falls through when s2(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2edc targets 0x3028, is taken when s2(=0x3) == s1(?), and falls through when s2(=0x3) != s1(?).
  The `beq` branch at 0x2ef4 targets 0x3078, is taken when v0(=ret(i2_master_recvbyte)) == 0, and falls through when v0(=ret(i2_master_recvbyte)) != 0.
  The `beq` branch at 0x2efc targets 0x3004, is taken when s2(=0x3) == s1(?), and falls through when s2(=0x3) != s1(?).
  The `beq` branch at 0x2f28 targets 0x304c, is taken when v0(=ret(i2_master_recvbyte)) == 0, and falls through when v0(=ret(i2_master_recvbyte)) != 0.
  The `bne` branch at 0x2f40 targets 0x2f14, is taken when s1(?) < t8(?) (signed), and falls through when s1(?) >= t8(?) (signed).
  The `beq` branch at 0x2f5c targets 0x3020, is taken when v0(=ret(i2_master_recvbyte)) == 0, and falls through when v0(=ret(i2_master_recvbyte)) != 0.
  The `beq` branch at 0x2f7c targets 0x305c, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x2f84 targets 0x2e50 and is always taken.
  The `beq` branch at 0x2f8c targets 0x2e50 and is always taken.
  The `beq` branch at 0x2f94 targets 0x3080, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x2fa8 targets 0x30b8, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x2fb0 targets 0x30a0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `blez` branch at 0x2fb8 targets 0x2ff0, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `beq` branch at 0x2fd4 targets 0x30a8, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `bne` branch at 0x2fe8 targets 0x2fc8, is taken when s1(?) < a4(?) (signed), and falls through when s1(?) >= a4(?) (signed).
  The `beq` branch at 0x2ffc targets 0x2e50 and is always taken.
  The `beq` branch at 0x3008 targets 0x30c0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x3010 targets 0x3054, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x3018 targets 0x2f0c and is always taken.
  The `beq` branch at 0x3020 targets 0x2e50 and is always taken.
  The `bne` branch at 0x303c targets 0x2efc, is taken when v0(=ret(i2_master_recvbyte)) != 0, and falls through when v0(=ret(i2_master_recvbyte)) == 0.
  The `beq` branch at 0x3044 targets 0x2e50 and is always taken.
  The `beq` branch at 0x304c targets 0x2e50 and is always taken.
  The `beq` branch at 0x3054 targets 0x2f44 and is always taken.
  The `beq` branch at 0x3068 targets 0x30b0, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x3070 targets 0x2e50 and is always taken.
  The `beq` branch at 0x3078 targets 0x2e50 and is always taken.
  The `bne` branch at 0x3090 targets 0x2fb0, is taken when v0(=ret(i2_sendbyte)) != 0, and falls through when v0(=ret(i2_sendbyte)) == 0.
  The `beq` branch at 0x3098 targets 0x2e50 and is always taken.
  The `beq` branch at 0x30a0 targets 0x2ff0 and is always taken.
  The `beq` branch at 0x30a8 targets 0x2e50 and is always taken.
  The `beq` branch at 0x30b0 targets 0x2e50 and is always taken.
  The `beq` branch at 0x30b8 targets 0x2e50 and is always taken.
  The `beq` branch at 0x30cc targets 0x2e50 and is always taken.
  The `beq` branch at 0x30e4 targets 0x2e50 and is always taken.
  The return at 0x2e60 has v0 = one of -0xe, 0x0, 0x1.

- `i2cfp_DMI2_EnableSequel` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x30ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x30ec-0x314c (96 bytes).
  It occupies 96 bytes.
  The `lbu` at 0x30ec loads 1 byte from a1 (arg1 at entry) +0x2e.
  The `jal` at 0x311c calls i2cfp_PortRead with a0=a0 at entry (arg0), a1=0x70, a2=sp-32, a3=a3 at entry (arg3).
  The `jal` at 0x3138 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `beq` branch at 0x3100 targets 0x3114, is taken when at(=[a1+46]:1) == v0(=0x84), and falls through when at(=[a1+46]:1) != v0(=0x84).
  The `beq` branch at 0x3144 targets 0x3108 and is always taken.
  The return at 0x310c has v0 = one of 0x0, ret(i2cfp_PortWrite).

- `i2cfp_DMI2_DisableSequel` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x314c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x314c-0x31b0 (100 bytes).
  It occupies 100 bytes.
  The `lbu` at 0x314c loads 1 byte from a1 (arg1 at entry) +0x2e.
  The `jal` at 0x317c calls i2cfp_PortRead with a0=a0 at entry (arg0), a1=0x70, a2=sp-32, a3=a3 at entry (arg3).
  The `jal` at 0x319c calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `beq` branch at 0x3160 targets 0x3174, is taken when at(=[a1+46]:1) == v0(=0x84), and falls through when at(=[a1+46]:1) != v0(=0x84).
  The `beq` branch at 0x31a8 targets 0x3168 and is always taken.
  The return at 0x316c has v0 = one of 0x0, ret(i2cfp_PortWrite).

- `i2cfp_PanelOn` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x31b0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x31b0-0x34c0 (784 bytes).
  It occupies 784 bytes.
  The `lbu` at 0x31c0 loads 1 byte from a1 (arg1 at entry) +0x2e.
  The `lh` at 0x31e0 loads 2 bytes from sym(crimeBoards) +0x3a.
  The `sh` at 0x31f4 stores 2 bytes to sym(crimeBoards) +0x3a.
  The `sw` at 0x3258 stores 4 bytes to a2 (arg2 at entry) +0x10030.
  The `sw` at 0x3264 stores 4 bytes to a2 (arg2 at entry) +0x10028.
  The `sw` at 0x3270 stores 4 bytes to a2 (arg2 at entry) +0x1002c.
  The `jal` at 0x3224 calls crime_setvideotiming with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-104, a3=0x84, a4=0x83, a5=[a1+46]:1.
  The `jal` at 0x326c calls i2cfp_PortWrite with a0=a2 at entry (arg2), a1=0x70, a2=0xe7, a3=?.
  The `jal` at 0x3280 calls i2cfp_AudioVolLeft with a0=a2 at entry (arg2), a1=[sym(.sdata)+16], a2=?, a3=?.
  The `jal` at 0x3294 calls i2cfp_AudioVolRight with a0=a2 at entry (arg2), a1=[sym(.sdata)+20], a2=?, a3=?.
  The `jal` at 0x32a8 calls i2cfp_AudioBass with a0=a2 at entry (arg2), a1=[sym(.sdata)+24], a2=?, a3=?.
  The `jal` at 0x32bc calls i2cfp_AudioTreble with a0=a2 at entry (arg2), a1=[sym(.sdata)+28], a2=?, a3=?.
  The `jal` at 0x32d0 calls i2cfp_AudioSwitch with a0=a2 at entry (arg2), a1=0xce, a2=?, a3=?.
  The `jal` at 0x32e4 calls i2cfp_BlUp with a0=a2 at entry (arg2), a1=0x64, a2=?, a3=?.
  The `jal` at 0x32f8 calls i2cfp_SetBit with a0=a2 at entry (arg2), a1=0x0, a2=?, a3=?.
  The `jal` at 0x337c calls i2cfp_PortRead with a0=a2 at entry (arg2), a1=0x70, a2=sp-112, a3=0x84, a5=[a1+46]:1.
  The `jal` at 0x339c calls i2cfp_PortWrite with a0=a2 at entry (arg2), a1=0x70, a2=?, a3=?.
  The `jal` at 0x33b0 calls i2cfp_PortRead with a0=a2 at entry (arg2), a1=0x70, a2=sp-112, a3=?.
  The `jal` at 0x33dc calls i2cfp_PortRead with a0=a2 at entry (arg2), a1=0x70, a2=sp-112, a3=?.
  The `jal` at 0x33fc calls i2cfp_PortWrite with a0=a2 at entry (arg2), a1=0x70, a2=?, a3=?.
  The `jal` at 0x3410 calls i2cfp_PortRead with a0=a2 at entry (arg2), a1=0x70, a2=sp-112, a3=?.
  The `jal` at 0x343c calls i2cfp_DMI2_BkltFuncs with a0=a2 at entry (arg2), a1=0x80, a2=0x0, a3=0x1, a4=0x0.
  The `jal` at 0x3458 calls i2cfp_DMI2_BkltFuncs with a0=a2 at entry (arg2), a1=0x10, a2=0x0, a3=0x0, a4=0x0.
  The `jal` at 0x3468 calls us_delay with a0=0x30d40, a1=?, a2=?, a3=?.
  The `jal` at 0x3480 calls i2cfp_DMI2_BkltFuncs with a0=a2 at entry (arg2), a1=0x10, a2=0x0, a3=0x1, a4=0x0.
  The `beq` branch at 0x31d0 targets 0x336c, is taken when a5(=[a1+46]:1) == 0, and falls through when a5(=[a1+46]:1) != 0.
  The `beq` branch at 0x31e8 targets 0x3364, is taken when at(=[sym(crimeBoards)+58]:2) == v0(=0x1), and falls through when at(=[sym(crimeBoards)+58]:2) != v0(=0x1).
  The `beq` branch at 0x31f0 targets 0x3374, is taken when a5(=[a1+46]:1) == a3(=0x84), and falls through when a5(=[a1+46]:1) != a3(=0x84).
  The `beq` branch at 0x3204 targets 0x332c, is taken when a5(=[a1+46]:1) == a4(=0x83), and falls through when a5(=[a1+46]:1) != a4(=0x83).
  The `beq` branch at 0x3210 targets 0x3348, is taken when a5(=[a1+46]:1) == a6(=0x82), and falls through when a5(=[a1+46]:1) != a6(=0x82).
  The `beq` branch at 0x3274 targets 0x330c, is taken when v0(=ret(i2cfp_PortWrite)) == 0, and falls through when v0(=ret(i2cfp_PortWrite)) != 0.
  The `beq` branch at 0x3288 targets 0x330c, is taken when v0(=ret(i2cfp_AudioVolLeft)) == 0, and falls through when v0(=ret(i2cfp_AudioVolLeft)) != 0.
  The `beq` branch at 0x329c targets 0x330c, is taken when v0(=ret(i2cfp_AudioVolRight)) == 0, and falls through when v0(=ret(i2cfp_AudioVolRight)) != 0.
  The `beq` branch at 0x32b0 targets 0x330c, is taken when v0(=ret(i2cfp_AudioBass)) == 0, and falls through when v0(=ret(i2cfp_AudioBass)) != 0.
  The `beq` branch at 0x32c4 targets 0x330c, is taken when v0(=ret(i2cfp_AudioTreble)) == 0, and falls through when v0(=ret(i2cfp_AudioTreble)) != 0.
  The `beq` branch at 0x32d8 targets 0x330c, is taken when v0(=ret(i2cfp_AudioSwitch)) == 0, and falls through when v0(=ret(i2cfp_AudioSwitch)) != 0.
  The `beq` branch at 0x32ec targets 0x330c, is taken when v0(=ret(i2cfp_BlUp)) == 0, and falls through when v0(=ret(i2cfp_BlUp)) != 0.
  The `beq` branch at 0x3300 targets 0x330c, is taken when v0(=ret(i2cfp_SetBit)) == 0, and falls through when v0(=ret(i2cfp_SetBit)) != 0.
  The `beq` branch at 0x3340 targets 0x3224 and is always taken.
  The `beq` branch at 0x335c targets 0x3224 and is always taken.
  The `beq` branch at 0x3364 targets 0x3310 and is always taken.
  The `beq` branch at 0x336c targets 0x330c and is always taken.
  The `beq` branch at 0x33a4 targets 0x34a0, is taken when v0(=ret(i2cfp_PortWrite)) == 0, and falls through when v0(=ret(i2cfp_PortWrite)) != 0.
  The `beq` branch at 0x33cc targets 0x342c, is taken when s1(=0x4) == a3(?), and falls through when s1(=0x4) != a3(?).
  The `beq` branch at 0x3404 targets 0x3498, is taken when v0(=ret(i2cfp_PortWrite)) == 0, and falls through when v0(=ret(i2cfp_PortWrite)) != 0.
  The `bne` branch at 0x3424 targets 0x33d4, is taken when s1(=0x4) != a3(?), and falls through when s1(=0x4) == a3(?).
  The `beq` branch at 0x3444 targets 0x34a8, is taken when v0(=ret(i2cfp_DMI2_BkltFuncs)) == 0, and falls through when v0(=ret(i2cfp_DMI2_BkltFuncs)) != 0.
  The `beq` branch at 0x3460 targets 0x34b0, is taken when v0(=ret(i2cfp_DMI2_BkltFuncs)) == 0, and falls through when v0(=ret(i2cfp_DMI2_BkltFuncs)) != 0.
  The `beq` branch at 0x3488 targets 0x34b8, is taken when v0(=ret(i2cfp_DMI2_BkltFuncs)) == 0, and falls through when v0(=ret(i2cfp_DMI2_BkltFuncs)) != 0.
  The `beq` branch at 0x3490 targets 0x330c and is always taken.
  The `beq` branch at 0x3498 targets 0x330c and is always taken.
  The `beq` branch at 0x34a0 targets 0x330c and is always taken.
  The `beq` branch at 0x34a8 targets 0x330c and is always taken.
  The `beq` branch at 0x34b0 targets 0x330c and is always taken.
  The `beq` branch at 0x34b8 targets 0x330c and is always taken.
  The return at 0x3324 has v0 = one of 0x0, 0x1.

- `i2cfp_PanelOff` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x34c0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x34c0-0x355c (156 bytes).
  It occupies 156 bytes.
  The `lw` at 0x34c8 loads 4 bytes from sym(crimeBoards) +0x8.
  The `lbu` at 0x34d0 loads 1 byte from [sym(crimeBoards)+8] +0x2e.
  The `lh` at 0x34ec loads 2 bytes from sym(crimeBoards) +0x3a.
  The `sh` at 0x34fc stores 2 bytes to sym(crimeBoards) +0x3a.
  The `jal` at 0x3504 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=0xff, a3=0x1, a4=0x84, a5=[[sym(crimeBoards)+8]+46]:1, a6=sym(crimeBoards).
  The `jal` at 0x3528 calls i2cfp_PortRead with a0=a0 at entry (arg0), a1=0x70, a2=sp-32, a3=0x1, a4=0x84, a5=[[sym(crimeBoards)+8]+46]:1, a6=sym(crimeBoards).
  The `jal` at 0x3544 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `beq` branch at 0x34e8 targets 0x3510, is taken when a5(=[[sym(crimeBoards)+8]+46]:1) == 0, and falls through when a5(=[[sym(crimeBoards)+8]+46]:1) != 0.
  The `beq` branch at 0x34f0 targets 0x3554, is taken when v0(=[sym(crimeBoards)+58]:2) == 0, and falls through when v0(=[sym(crimeBoards)+58]:2) != 0.
  The `beq` branch at 0x34f8 targets 0x3524, is taken when a5(=[[sym(crimeBoards)+8]+46]:1) == a4(=0x84), and falls through when a5(=[[sym(crimeBoards)+8]+46]:1) != a4(=0x84).
  The `beq` branch at 0x354c targets 0x3510 and is always taken.
  The `beq` branch at 0x3554 targets 0x3514 and is always taken.
  The return at 0x351c has v0 = one of ?, 0x1.

- `i2cfp_BlUp` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x355c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x355c-0x36a8 (332 bytes).
  It occupies 332 bytes.
  The `jal` at 0x35cc calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `jal` at 0x35e0 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `jal` at 0x35f4 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `jal` at 0x3608 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `beq` branch at 0x3588 targets 0x3594, is taken when at(=[sym(.sbss)+12]) == 0, and falls through when at(=[sym(.sbss)+12]) != 0.
  The `beq` branch at 0x35a4 targets 0x366c, is taken when s6(=a1-1) == v1(=-0x1), and falls through when s6(=a1-1) != v1(=-0x1).
  The `beq` branch at 0x3610 targets 0x3630, is taken when s3(=ret(i2cfp_PortWrite)) == 0, and falls through when s3(=ret(i2cfp_PortWrite)) != 0.
  The `beq` branch at 0x3618 targets 0x3630, is taken when s4(=ret(i2cfp_PortWrite)) == 0, and falls through when s4(=ret(i2cfp_PortWrite)) != 0.
  The `beq` branch at 0x3620 targets 0x3630, is taken when s5(=ret(i2cfp_PortWrite)) == 0, and falls through when s5(=ret(i2cfp_PortWrite)) != 0.
  The `bne` branch at 0x3628 targets 0x3640, is taken when v0(=ret(i2cfp_PortWrite)) != 0, and falls through when v0(=ret(i2cfp_PortWrite)) == 0.
  The `bne` branch at 0x3638 targets 0x35c4, is taken when s1(?) < 0xa (unsigned), and falls through when s1(?) >= 0xa (unsigned).
  The `beq` branch at 0x3648 targets 0x36a0, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x3658 targets 0x3664, is taken when v0(=[sym(.sbss)+4]) >= 0x64 (signed), and falls through when v0(=[sym(.sbss)+4]) < 0x64 (signed).
  The `bne` branch at 0x3664 targets 0x35c4, is taken when s6(?) != a1(=-0x1), and falls through when s6(?) == a1(=-0x1).
  The `beq` branch at 0x36a0 targets 0x3670 and is always taken.
  The return at 0x3698 has v0 = one of 0x0, 0x1.

- `i2cfp_BlDown` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x36a8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x36a8-0x3810 (360 bytes).
  It occupies 360 bytes.
  The `jal` at 0x3724 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `jal` at 0x3738 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `jal` at 0x374c calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `jal` at 0x3760 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `jal` at 0x3770 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `beq` branch at 0x36d4 targets 0x36e0, is taken when at(=[sym(.sbss)+12]) == 0, and falls through when at(=[sym(.sbss)+12]) != 0.
  The `beq` branch at 0x36f8 targets 0x37d4, is taken when s6(=a1-1) == v1(=-0x1), and falls through when s6(=a1-1) != v1(=-0x1).
  The `beq` branch at 0x3778 targets 0x3798, is taken when s3(=ret(i2cfp_PortWrite)) == 0, and falls through when s3(=ret(i2cfp_PortWrite)) != 0.
  The `beq` branch at 0x3780 targets 0x3798, is taken when s4(=ret(i2cfp_PortWrite)) == 0, and falls through when s4(=ret(i2cfp_PortWrite)) != 0.
  The `beq` branch at 0x3788 targets 0x3798, is taken when s5(=ret(i2cfp_PortWrite)) == 0, and falls through when s5(=ret(i2cfp_PortWrite)) != 0.
  The `bne` branch at 0x3790 targets 0x37ac, is taken when v0(=ret(i2cfp_PortWrite)) != 0, and falls through when v0(=ret(i2cfp_PortWrite)) == 0.
  The `bne` branch at 0x37a0 targets 0x3720, is taken when s1(?) < 0xa (unsigned), and falls through when s1(?) >= 0xa (unsigned).
  The `beq` branch at 0x37b4 targets 0x3808, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `blez` branch at 0x37c0 targets 0x37cc, is taken when v0(=[sym(.sbss)+4]) <= 0 (signed), and falls through when v0(=[sym(.sbss)+4]) > 0 (signed).
  The `bne` branch at 0x37cc targets 0x371c, is taken when s6(?) != at(=-0x1), and falls through when s6(?) == at(=-0x1).
  The `beq` branch at 0x3808 targets 0x37d8 and is always taken.
  The return at 0x3800 has v0 = one of 0x0, 0x1.

- `i2cfp_DMI2_KernelEDID` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x3810 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x3810-0x3a0c (508 bytes).
  It occupies 508 bytes.
  The `lw` at 0x3824 loads 4 bytes from sym(crimeBoards) +0xc.
  The `sh` at 0x39bc stores 2 bytes to (sym(crimeBoards) + (a2 << 0x3)) +0x30.
  The `sh` at 0x39c4 stores 2 bytes to (sym(crimeBoards) + (a2 << 0x3)) +0x36.
  The `sh` at 0x39c8 stores 2 bytes to (sym(crimeBoards) + (a2 << 0x3)) +0x32.
  The `sh` at 0x39cc stores 2 bytes to a1 (arg1 at entry) +0x1ec.
  The `jal` at 0x3848 calls mutex_lock with a0=[sym(crimeBoards)+12]+468, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3864 calls bzero with a0=a1+364, a1=0x80, a2=?, a3=?.
  The `jal` at 0x3888 calls i2_start with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3898 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=0xa0, a3=?.
  The `jal` at 0x38b0 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x38c0 calls i2_start with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x38d0 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=0xa1, a3=?.
  The `jal` at 0x38f0 calls crime_i2cfpFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3900 calls mutex_unlock with a0=[sym(crimeBoards)+12]+468, a1=?, a2=?, a3=?.
  The `jal` at 0x3910 calls crime_i2cfpFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3934 calls crime_i2cfpFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3944 calls crime_i2cfpFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x395c calls i2_master_recvbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=one of 0x0, 0x1.
  The `jal` at 0x3994 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x399c calls crime_EdidCksum with a0=a1+364, a1=?, a2=?, a3=?.
  The `jal` at 0x39d8 calls mutex_unlock with a0=[sym(crimeBoards)+12]+468, a1=0x2, a2=?, a3=?.
  The `beq` branch at 0x383c targets 0x3850, is taken when s3(=[sym(crimeBoards)+12]) == 0, and falls through when s3(=[sym(crimeBoards)+12]) != 0.
  The `beq` branch at 0x387c targets 0x38f8, is taken when s1(?) >= 0x3 (signed), and falls through when s1(?) < 0x3 (signed).
  The `beq` branch at 0x38a0 targets 0x3934, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x38b8 targets 0x3910, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x38d8 targets 0x3944, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x38e8 targets 0x397c and is always taken.
  The `beq` branch at 0x38f8 targets 0x3908, is taken when s3(=[sym(crimeBoards)+12]) == 0, and falls through when s3(=[sym(crimeBoards)+12]) != 0.
  The `beq` branch at 0x3908 targets 0x39e4 and is always taken.
  The `bne` branch at 0x391c targets 0x3870, is taken when s2(=one of 0x0, 0x1) != 0, and falls through when s2(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x3924 targets 0x38ac, is taken when s5(=one of 0x0, 0x1) == 0, and falls through when s5(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x392c targets 0x3874 and is always taken.
  The `beq` branch at 0x393c targets 0x3874 and is always taken.
  The `beq` branch at 0x394c targets 0x391c and is always taken.
  The `beq` branch at 0x3964 targets 0x38f0, is taken when v0(=ret(i2_master_recvbyte)) == 0, and falls through when v0(=ret(i2_master_recvbyte)) != 0.
  The `beq` branch at 0x3974 targets 0x3990, is taken when s1(?) >= 0x80 (unsigned), and falls through when s1(?) < 0x80 (unsigned).
  The `bne` branch at 0x397c targets 0x3954, is taken when s5(=0x7f) != s1(?), and falls through when s5(=0x7f) == s1(?).
  The `beq` branch at 0x3988 targets 0x3954 and is always taken.
  The `bne` branch at 0x39c0 targets 0x39d0, is taken when (v0(=ret(crime_EdidCksum)) & 0xffff) != 0, and falls through when (v0(=ret(crime_EdidCksum)) & 0xffff) == 0.
  The `beq` branch at 0x39d0 targets 0x39e4, is taken when s3(=[sym(crimeBoards)+12]) == 0, and falls through when s3(=[sym(crimeBoards)+12]) != 0.
  The return at 0x3a04 has v0 = one of 0x0, 0x1.

- `i2cfp_DMI2_EDIDFuncs` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x3a0c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x3a0c-0x3dd8 (972 bytes).
  It occupies 972 bytes.
  The `lw` at 0x3a40 loads 4 bytes from sym(crimeBoards) +0xc.
  4 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x3c5c, `lbu` at 0x3c70, `lbu` at 0x3c84.
  The `sh` at 0x3d80 stores 2 bytes to table(sym(crimeBoards)) +0x30.
  The `sh` at 0x3d88 stores 2 bytes to table(sym(crimeBoards)) +0x36.
  The `sh` at 0x3d90 stores 2 bytes to table(sym(crimeBoards)) +0x32.
  The `sh` at 0x3d94 stores 2 bytes to ?.
  The `jal` at 0x3a3c calls copyin with a0=a2 at entry (arg2), a1=sp-208, a2=0xc, a3=a3 at entry (arg3).
  The `jal` at 0x3a9c calls bzero with a0=sp-192, a1=0x80, a2=?, a3=?.
  The `jal` at 0x3ac0 calls i2_start with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3ad0 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=0xa0, a3=?.
  The `jal` at 0x3ae8 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3af8 calls i2_start with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3b08 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=0xa1, a3=?.
  The `jal` at 0x3b24 calls crime_i2cfpFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3b34 calls mutex_unlock with a0=[sym(crimeBoards)+12]+468, a1=?, a2=?, a3=?.
  The `jal` at 0x3b48 calls mutex_lock with a0=[sym(crimeBoards)+12]+468, a1=0x19, a2=0x80, a3=?.
  The `jal` at 0x3b58 calls crime_i2cfpFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3b84 calls crime_i2cfpFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3b94 calls crime_i2cfpFixupAfterErr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3ba8 calls copyin with a0=?, a1=sp-192, a2=0x80, a3=?.
  The `jal` at 0x3bc4 calls i2cfp_PortRead with a0=a0 at entry (arg0), a1=0x70, a2=sp-64, a3=?.
  The `jal` at 0x3be4 calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `jal` at 0x3c0c calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3c14 calls us_delay with a0=0x2710, a1=?, a2=?, a3=?.
  The `jal` at 0x3c38 calls i2_start_addr with a0=0x1, a1=a0 at entry (arg0), a2=0xa0, a3=?.
  The `jal` at 0x3c4c calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3c60 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3c74 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3c88 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3c9c calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3cbc calls i2cfp_PortRead with a0=a0 at entry (arg0), a1=0x70, a2=sp-64, a3=?.
  The `jal` at 0x3cdc calls i2cfp_PortWrite with a0=a0 at entry (arg0), a1=0x70, a2=?, a3=?.
  The `jal` at 0x3d04 calls i2_master_recvbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=one of 0x0, 0x1.
  The `jal` at 0x3d38 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3d58 calls bcopy with a0=sp-192, a1=a1+364, a2=0x4, a3=?.
  The `jal` at 0x3d70 calls crime_EdidCksum with a0=sp-192, a1=?, a2=?, a3=?.
  The `jal` at 0x3da0 calls copyout with a0=sp-192, a1=?, a2=0x80, a3=?.
  The `jal` at 0x3dc8 calls mutex_unlock with a0=[sym(crimeBoards)+12]+468, a1=?, a2=?, a3=?.
  The `beq` branch at 0x3a4c targets 0x3a7c, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x3a80 targets 0x3ba4, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x3a88 targets 0x3b44, is taken when s3(=[sym(crimeBoards)+12]) != 0, and falls through when s3(=[sym(crimeBoards)+12]) == 0.
  The `beq` branch at 0x3a90 targets 0x3b7c, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x3ab4 targets 0x3b2c, is taken when s1(?) >= 0x3 (signed), and falls through when s1(?) < 0x3 (signed).
  The `beq` branch at 0x3ad8 targets 0x3b84, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3af0 targets 0x3b58, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3b10 targets 0x3b94, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3b1c targets 0x3d24 and is always taken.
  The `beq` branch at 0x3b2c targets 0x3b3c, is taken when s3(=[sym(crimeBoards)+12]) == 0, and falls through when s3(=[sym(crimeBoards)+12]) != 0.
  The `beq` branch at 0x3b3c targets 0x3a58 and is always taken.
  The `beq` branch at 0x3b50 targets 0x3a90 and is always taken.
  The `bne` branch at 0x3b64 targets 0x3aa8, is taken when s2(=one of 0x0, 0x1) != 0, and falls through when s2(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x3b6c targets 0x3ae4, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x3b74 targets 0x3aac and is always taken.
  The `beq` branch at 0x3b7c targets 0x3a98 and is always taken.
  The `beq` branch at 0x3b8c targets 0x3aac and is always taken.
  The `beq` branch at 0x3b9c targets 0x3b64 and is always taken.
  The `beq` branch at 0x3bb0 targets 0x3bc0, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x3bb8 targets 0x3a58 and is always taken.
  The `beq` branch at 0x3bcc targets 0x3cec, is taken when v0(=ret(i2cfp_PortRead)) == 0, and falls through when v0(=ret(i2cfp_PortRead)) != 0.
  The `beq` branch at 0x3bec targets 0x3cf4, is taken when v0(=ret(i2cfp_PortWrite)) == 0, and falls through when v0(=ret(i2cfp_PortWrite)) != 0.
  The `beq` branch at 0x3bfc targets 0x3c30 and is always taken.
  The `beq` branch at 0x3c28 targets 0x3cb4, is taken when s3(?) >= 0x80 (unsigned), and falls through when s3(?) < 0x80 (unsigned).
  The `beq` branch at 0x3c40 targets 0x3c04, is taken when v0(=ret(i2_start_addr)) == 0, and falls through when v0(=ret(i2_start_addr)) != 0.
  The `beq` branch at 0x3c54 targets 0x3c04, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3c68 targets 0x3c04, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3c7c targets 0x3c04, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3c90 targets 0x3c04, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `bne` branch at 0x3ca4 targets 0x3c0c, is taken when v0(=ret(i2_sendbyte)) != 0, and falls through when v0(=ret(i2_sendbyte)) == 0.
  The `beq` branch at 0x3cac targets 0x3c08 and is always taken.
  The `beq` branch at 0x3ce4 targets 0x3a58 and is always taken.
  The `beq` branch at 0x3cec targets 0x3a58 and is always taken.
  The `beq` branch at 0x3cf4 targets 0x3a58 and is always taken.
  The `beq` branch at 0x3d0c targets 0x3b24, is taken when v0(=ret(i2_master_recvbyte)) == 0, and falls through when v0(=ret(i2_master_recvbyte)) != 0.
  The `beq` branch at 0x3d1c targets 0x3d38, is taken when s1(?) >= 0x80 (unsigned), and falls through when s1(?) < 0x80 (unsigned).
  The `bne` branch at 0x3d24 targets 0x3cfc, is taken when s4(=0x7f) != s1(?), and falls through when s4(=0x7f) == s1(?).
  The `beq` branch at 0x3d30 targets 0x3cfc and is always taken.
  The `bne` branch at 0x3d44 targets 0x3d98, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x3d84 targets 0x3d98, is taken when (v0(=ret(crime_EdidCksum)) & 0xffff) != 0, and falls through when (v0(=ret(crime_EdidCksum)) & 0xffff) == 0.
  The `beq` branch at 0x3da8 targets 0x3db8, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x3db0 targets 0x3a58 and is always taken.
  The `bne` branch at 0x3db8 targets 0x3dc8, is taken when s3(=[sym(crimeBoards)+12]) != 0, and falls through when s3(=[sym(crimeBoards)+12]) == 0.
  The `beq` branch at 0x3dc0 targets 0x3a58 and is always taken.
  The `beq` branch at 0x3dd0 targets 0x3dc0 and is always taken.
  The return at 0x3a74 has v0 = one of -0xe, 0x0, ?, 0x1.

- `i2cfp_AudioVolLeft` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x3dd8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x3dd8-0x3e78 (160 bytes).
  It occupies 160 bytes.
  The `jal` at 0x3dfc calls i2_start_addr with a0=0x1, a1=a0 at entry (arg0), a2=0x82, a3=a3 at entry (arg3).
  The `jal` at 0x3e10 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x3e24 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3e44 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `beq` branch at 0x3e04 targets 0x3e3c, is taken when v0(=ret(i2_start_addr)) == 0, and falls through when v0(=ret(i2_start_addr)) != 0.
  The `beq` branch at 0x3e18 targets 0x3e64, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3e2c targets 0x3e6c, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3e34 targets 0x3e44 and is always taken.
  The `beq` branch at 0x3e64 targets 0x3e40 and is always taken.
  The `beq` branch at 0x3e70 targets 0x3e44 and is always taken.
  The return at 0x3e5c has v0 = one of 0x0, 0x1.

- `i2cfp_AudioVolRight` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x3e78 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x3e78-0x3f18 (160 bytes).
  It occupies 160 bytes.
  The `jal` at 0x3e9c calls i2_start_addr with a0=0x1, a1=a0 at entry (arg0), a2=0x82, a3=a3 at entry (arg3).
  The `jal` at 0x3eb0 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=0x1, a3=?.
  The `jal` at 0x3ec4 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3ee4 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `beq` branch at 0x3ea4 targets 0x3edc, is taken when v0(=ret(i2_start_addr)) == 0, and falls through when v0(=ret(i2_start_addr)) != 0.
  The `beq` branch at 0x3eb8 targets 0x3f04, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3ecc targets 0x3f0c, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3ed4 targets 0x3ee4 and is always taken.
  The `beq` branch at 0x3f04 targets 0x3ee0 and is always taken.
  The `beq` branch at 0x3f10 targets 0x3ee4 and is always taken.
  The return at 0x3efc has v0 = one of 0x0, 0x1.

- `i2cfp_AudioBass` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x3f18 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x3f18-0x3fb8 (160 bytes).
  It occupies 160 bytes.
  The `jal` at 0x3f3c calls i2_start_addr with a0=0x1, a1=a0 at entry (arg0), a2=0x82, a3=a3 at entry (arg3).
  The `jal` at 0x3f50 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=0x2, a3=?.
  The `jal` at 0x3f64 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3f84 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `beq` branch at 0x3f44 targets 0x3f7c, is taken when v0(=ret(i2_start_addr)) == 0, and falls through when v0(=ret(i2_start_addr)) != 0.
  The `beq` branch at 0x3f58 targets 0x3fa4, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3f6c targets 0x3fac, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x3f74 targets 0x3f84 and is always taken.
  The `beq` branch at 0x3fa4 targets 0x3f80 and is always taken.
  The `beq` branch at 0x3fb0 targets 0x3f84 and is always taken.
  The return at 0x3f9c has v0 = one of 0x0, 0x1.

- `i2cfp_AudioTreble` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x3fb8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x3fb8-0x4058 (160 bytes).
  It occupies 160 bytes.
  The `jal` at 0x3fdc calls i2_start_addr with a0=0x1, a1=a0 at entry (arg0), a2=0x82, a3=a3 at entry (arg3).
  The `jal` at 0x3ff0 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=0x3, a3=?.
  The `jal` at 0x4004 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x4024 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `beq` branch at 0x3fe4 targets 0x401c, is taken when v0(=ret(i2_start_addr)) == 0, and falls through when v0(=ret(i2_start_addr)) != 0.
  The `beq` branch at 0x3ff8 targets 0x4044, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x400c targets 0x404c, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x4014 targets 0x4024 and is always taken.
  The `beq` branch at 0x4044 targets 0x4020 and is always taken.
  The `beq` branch at 0x4050 targets 0x4024 and is always taken.
  The return at 0x403c has v0 = one of 0x0, 0x1.

- `i2cfp_AudioSwitch` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x4058 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x4058-0x410c (180 bytes).
  It occupies 180 bytes.
  The `jal` at 0x4088 calls i2_start_addr with a0=0x1, a1=a0 at entry (arg0), a2=0x82, a3=a3 at entry (arg3).
  The `jal` at 0x409c calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=0x8, a3=?.
  The `jal` at 0x40b0 calls i2_sendbyte with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x40d0 calls i2_stop with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=?.
  The `beq` branch at 0x4074 targets 0x40f8, is taken when (a1 & 0x20) == 0, and falls through when (a1 & 0x20) != 0.
  The `beq` branch at 0x4090 targets 0x40c8, is taken when v0(=ret(i2_start_addr)) == 0, and falls through when v0(=ret(i2_start_addr)) != 0.
  The `beq` branch at 0x40a4 targets 0x40f0, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x40b8 targets 0x4100, is taken when v0(=ret(i2_sendbyte)) == 0, and falls through when v0(=ret(i2_sendbyte)) != 0.
  The `beq` branch at 0x40c0 targets 0x40d0 and is always taken.
  The `beq` branch at 0x40f0 targets 0x40cc and is always taken.
  The `beq` branch at 0x40f8 targets 0x4080 and is always taken.
  The `beq` branch at 0x4104 targets 0x40d0 and is always taken.
  The return at 0x40e8 has v0 = one of 0x0, 0x1.

- `crime_i2cfp_command` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)` at 0x4158 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_i2c.o)`.
  Range: 0x4158-0x439c (580 bytes).
  It occupies 580 bytes.
  The `lw` at 0x4158 loads 4 bytes from a0 (arg0 at entry) +0x7c.
  The `lbu` at 0x415c loads 1 byte from [a0+124] +0x2e.
  The `lw` at 0x4160 loads 4 bytes from a0 (arg0 at entry) +0x80.
  The `lw` at 0x4178 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x4194 loads 4 bytes from (sym(.rodata)+160 + ([a1] << 0x2)) +0x0.
  Calls (unknown callee) via register with a0=a0 at entry (arg0), a1=(sym(.rodata)+160 + ([a1] << 0x2)), a2=[sym(.sbss)+4], a3=[(sym(.rodata)+160 + ([a1] << 0x2))], a5=[a0+124], a6=[sym(.sdata)+16], a7=[sym(.sdata)+20] (`jr` at 0x41a0).
  The `jal` at 0x438c calls cmn_err with a0=0x6, a1=sym(.rodata)+128, a2=[a1], a3=([a1] << 0x2), a5=[a0+124].
  The `beq` branch at 0x4170 targets 0x41a8, is taken when at(=[[a0+124]+46]:1) == 0, and falls through when at(=[[a0+124]+46]:1) != 0.
  The `beq` branch at 0x418c targets 0x4384, is taken when a2(=[a1]) >= 0x16 (unsigned), and falls through when a2(=[a1]) < 0x16 (unsigned).
  The `beq` branch at 0x41a8 targets 0x41c0 and is always taken.
  The `beq` branch at 0x4394 targets 0x41c0 and is always taken.
  The return at 0x41c8 has v0 = one of 0x13, 0x16.
  The instructions from 0x41b0 to 0x41bc are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x41d0 to 0x4380 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x41a0 uses a jump table whose successors are unresolved.
