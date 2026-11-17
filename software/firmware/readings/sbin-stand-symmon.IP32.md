# Readings: `sbin/stand/symmon.IP32`

One entry per routine, filed here from the reading batches by binary.

- `exception` in `sbin/stand/symmon.IP32` at 0xa001041c (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa001041c-0xa0010998 (1404 bytes).
  It occupies 1404 bytes.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa001041c, `lw` at 0xa0010438, `lw` at 0xa0010568.
  61 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa001043c, `sd` at 0xa0010580, `sd` at 0xa0010588.
  The `ld` at 0xa0010448 loads 8 bytes from ?.
  The `ld` at 0xa00104c8 loads 8 bytes from abs 0xffffffffb4000040.
  The `ld` at 0xa00104d8 loads 8 bytes from abs 0xffffffffb4000048.
  The `ld` at 0xa00104e8 loads 8 bytes from abs 0xffffffffb4000058.
  The `ld` at 0xa00104f8 loads 8 bytes from abs 0xffffffffb4000250.
  The `ld` at 0xa0010508 loads 8 bytes from abs 0xffffffffb4000258.
  The `ld` at 0xa0010518 loads 8 bytes from abs 0xffffffffb4000260.
  The `ld` at 0xa0010528 loads 8 bytes from abs 0xffffffffb4000268.
  The `ld` at 0xa0010538 loads 8 bytes from abs 0xffffffffb4000270.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa0010570, `sw` at 0xa0010578, `sw` at 0xa001098c.
  2 such `sw` accesses store 4 bytes to abs 0xffffffffa005a5e0, including `sw` at 0xa001092c, `sw` at 0xa001096c.
  The `sw` at 0xa0010938 stores 4 bytes to abs 0xffffffffa005a5f0.
  The `lw` at 0xa0010954 loads 4 bytes from abs 0xffffffffa005a5f0.
  The `jal` at 0xa00108cc calls _ip32_disable_serial_dma [0xa001140c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa0010984 calls _save_vectors [0xa001be54] with a0=?, a1=?, a2=?, a3=?.
  Calls symmon_exchandler [0xa0019f3c] via direct with a0=?, a1=?, a2=?, a3=? (`j` at 0xa0010990).
  The `beq` branch at 0xa0010424 targets 0xa0010438, is taken when k0(?) == at(=0x1), and falls through when k0(?) != at(=0x1).
  The `beq` branch at 0xa0010430 targets 0xa0010448 and is always taken.
  The `beq` branch at 0xa001056c targets 0xa001098c, is taken when k0(?) == 0, and falls through when k0(?) != 0.
  The `bne` branch at 0xa001079c targets 0xa00107d4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0xa00107a8 targets 0xa00107d4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa00107b4 targets 0xa00107d4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa00107c0 targets 0xa00107d4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0xa00107cc targets 0xa00107e4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0xa00107dc targets 0xa0010814 and is always taken.
  The `beq` branch at 0xa00108c4 targets 0xa001098c, is taken when v0(?) == at(=0x2), and falls through when v0(?) != at(=0x2).
  The `beq` branch at 0xa00108f0 targets 0xa0010984, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xa00108fc targets 0xa0010984, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xa0010908 targets 0xa0010984, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `blez` branch at 0xa0010944 targets 0xa0010984, is taken when t0(?) <= 0 (signed), and falls through when t0(?) > 0 (signed).

- `_ip32_disable_serial_dma` in `sbin/stand/symmon.IP32` at 0xa001140c (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa001140c-0xa0011470 (100 bytes).
  It occupies 100 bytes.
  The `ld` at 0xa0011414 loads 8 bytes from abs 0xffffffffbf318000.
  The `sd` at 0xa001141c stores 8 bytes to abs 0xffffffffa003c920.
  The `ld` at 0xa0011430 loads 8 bytes from abs 0xffffffffbf318020.
  The `ld` at 0xa0011434 loads 8 bytes from abs 0xffffffffbf31c000.
  The `ld` at 0xa0011438 loads 8 bytes from abs 0xffffffffbf31c020.
  The `sd` at 0xa001143c stores 8 bytes to abs 0xffffffffa003c928.
  The `sd` at 0xa0011440 stores 8 bytes to abs 0xffffffffa003c930.
  The `sd` at 0xa0011444 stores 8 bytes to abs 0xffffffffa003c938.
  The `sd` at 0xa001145c stores 8 bytes to abs 0xffffffffbf318000.
  The `sd` at 0xa0011460 stores 8 bytes to abs 0xffffffffbf318020.
  The `sd` at 0xa0011464 stores 8 bytes to abs 0xffffffffbf31c000.
  The `sd` at 0xa001146c stores 8 bytes to abs 0xffffffffbf31c020.
  The return at 0xa0011468 has v0 = 0xffffffffbf31c020.

- `_ip32_restore_serial_dma` in `sbin/stand/symmon.IP32` at 0xa0011470 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0011470-0xa00114b0 (64 bytes).
  It occupies 64 bytes.
  The `ld` at 0xa0011488 loads 8 bytes from abs 0xffffffffa003c920.
  The `ld` at 0xa001148c loads 8 bytes from abs 0xffffffffa003c938.
  The `ld` at 0xa0011490 loads 8 bytes from abs 0xffffffffa003c930.
  The `ld` at 0xa0011494 loads 8 bytes from abs 0xffffffffa003c928.
  The `sd` at 0xa001149c stores 8 bytes to abs 0xffffffffbf318000.
  The `sd` at 0xa00114a0 stores 8 bytes to abs 0xffffffffbf318020.
  The `sd` at 0xa00114a4 stores 8 bytes to abs 0xffffffffbf31c000.
  The `sd` at 0xa00114ac stores 8 bytes to abs 0xffffffffbf31c020.
  The return at 0xa00114a8 has v0 = 0xffffffffbf31c020.

- `configurePort` in `sbin/stand/symmon.IP32` at 0xa0020734 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0020734-0xa0020854 (288 bytes).
  It occupies 288 bytes.
  The `sd` at 0xa0020768 stores 8 bytes to abs 0xffffffffbf310000.
  2 such `lw` accesses load 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc554c, including `lw` at 0xa0020780, `lw` at 0xa00207dc.
  2 such `sb` accesses store 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372428] +0x0, including `sb` at 0xa002078c, `sb` at 0xa00207e8.
  The `lw` at 0xa0020794 loads 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc553c.
  The `sb` at 0xa00207a0 stores 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372412] +0x0.
  2 such `lw` accesses load 4 bytes from (a0 << 0x2) -0x5ffa73a8, including `lw` at 0xa00207a8, `lw` at 0xa00207b8.
  The `lw` at 0xa00207ac loads 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc5558.
  The `sb` at 0xa00207b0 stores 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372440] +0x0.
  2 such `lw` accesses load 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc5554, including `lw` at 0xa00207c8, `lw` at 0xa00207f0.
  2 such `sb` accesses store 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372436] +0x0, including `sb` at 0xa00207d4, `sb` at 0xa00207fc.
  The `lw` at 0xa0020804 loads 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc5548.
  The `sb` at 0xa0020810 stores 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372424] +0x0.
  The `lw` at 0xa0020818 loads 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc5550.
  The `sb` at 0xa0020824 stores 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372432] +0x0.
  The `sw` at 0xa0020828 stores 4 bytes to table(0xffffffffa0058444) +0x0.
  The `sw` at 0xa0020830 stores 4 bytes to table(0xffffffffa0058448) +0x0.
  The `jal` at 0xa00207a4 calls mapBaud [0xa00208e0] with a0=[(a0 << 0x2)-1610249128], a1=0x18, a2=[(((a0 << 0x3) + a0) << 0x2)-1610372412], a3=[(((a0 << 0x3) + a0) << 0x2)-1610372428].
  The `jal` at 0xa00207b4 calls mapBaud [0xa00208e0] with a0=[(a0 << 0x2)-1610249128], a1=[(((a0 << 0x3) + a0) << 0x2)-1610372440], a2=?, a3=?.
  The `jal` at 0xa0020844 calls __assert [0xa0027fc8] with a0=0xffffffffa0036360, a1=0xffffffffa0036300, a2=0x19c, a3=a3 at entry (arg3).
  The `bltz` branch at 0xa0020748 targets 0xa0020834, is taken when a0 < 0 (signed), and falls through when a0 >= 0 (signed).
  The `beq` branch at 0xa0020754 targets 0xa0020834, is taken when a0 >= 0x2 (signed), and falls through when a0 < 0x2 (signed).
  The `beq` branch at 0xa002084c targets 0xa002075c and is always taken.
  The return at 0xa002082c has v0 = ret(mapBaud).

- `mace_errputc` in `sbin/stand/symmon.IP32` at 0xa0020ad4 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0020ad4-0xa0020b40 (108 bytes).
  It occupies 108 bytes.
  The `lw` at 0xa0020ad8 loads 4 bytes from abs 0xffffffffa0058438.
  2 such `lw` accesses load 4 bytes from abs 0xffffffffa003aabc, including `lw` at 0xa0020af4, `lw` at 0xa0020b08.
  2 such `lbu` accesses load 1 byte from [0xffffffffa003aabc] +0x0, including `lbu` at 0xa0020af8, `lbu` at 0xa0020b0c.
  The `lw` at 0xa0020b1c loads 4 bytes from abs 0xffffffffa003aaa8.
  The `sb` at 0xa0020b28 stores 1 byte to [0xffffffffa003aaa8] +0x0.
  The `jal` at 0xa0020b2c calls (unnamed) [0xa00203dc] with a0=0x0, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa0020ae4 targets 0xa0020b2c, is taken when at(=[0xffffffffa0058438]) == 0, and falls through when at(=[0xffffffffa0058438]) != 0.
  The `bne` branch at 0xa0020b00 targets 0xa0020b1c, is taken when (v0(=[[0xffffffffa003aabc]]:1) & 0x20) != 0, and falls through when (v0(=[[0xffffffffa003aabc]]:1) & 0x20) == 0.
  The `beq` branch at 0xa0020b14 targets 0xa0020b08, is taken when (a3(=[[0xffffffffa003aabc]]:1) & 0x20) == 0, and falls through when (a3(=[[0xffffffffa003aabc]]:1) & 0x20) != 0.
  The `beq` branch at 0xa0020b38 targets 0xa0020aec and is always taken.
  The return at 0xa0020b24 has v0 = ?.

- `mace_n16c550_install` in `sbin/stand/symmon.IP32` at 0xa0020b40 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0020b40-0xa0020c30 (240 bytes).
  It occupies 240 bytes.
  The `sw` at 0xa0020b9c stores 4 bytes to ret(AddChild) +0x10.
  The `jal` at 0xa0020b60 calls (unnamed) [0xa00203dc] with a0=0x0, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa0020b84 calls AddChild [0xa0024228] with a0=a0 at entry (arg0), a1=0xffffffffa003ab18, a2=0x0, a3=?.
  The `jal` at 0xa0020ba0 calls AddChild [0xa0024228] with a0=ret(AddChild), a1=0xffffffffa003ab40, a2=0x0, a3=?.
  The `jal` at 0xa0020bb4 calls RegisterDriverStrategy [0xa0024128] with a0=ret(AddChild), a1=0xffffffffa00204dc, a2=?, a3=?.
  The `jal` at 0xa0020c00 calls __assert [0xa0027fc8] with a0=0xffffffffa0036408, a1=0xffffffffa0036300, a2=0x26e, a3=?.
  The `jal` at 0xa0020c20 calls __assert [0xa0027fc8] with a0=0xffffffffa0036418, a1=0xffffffffa0036300, a2=0x272, a3=?.
  The `beq` branch at 0xa0020b8c targets 0xa0020bf0, is taken when v0(=ret(AddChild)) == 0, and falls through when v0(=ret(AddChild)) != 0.
  The `beq` branch at 0xa0020ba8 targets 0xa0020c10, is taken when v0(=ret(AddChild)) == 0, and falls through when v0(=ret(AddChild)) != 0.
  The `bne` branch at 0xa0020bc4 targets 0xa0020b80, is taken when s1(?) != t8(=0x2), and falls through when s1(?) == t8(=0x2).
  The `beq` branch at 0xa0020c08 targets 0xa0020b98 and is always taken.
  The `beq` branch at 0xa0020c28 targets 0xa0020bb4 and is always taken.
  The return at 0xa0020be8 has v0 = 0x0.

- `cpu_rtcinit` in `sbin/stand/symmon.IP32` at 0xa0027468 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0027468-0xa00274e8 (128 bytes).
  It occupies 128 bytes.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a0a07, including `lbu` at 0xa0027470, `lbu` at 0xa00274bc.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a0a07, including `sb` at 0xa0027488, `sb` at 0xa00274cc.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a4b07, including `lbu` at 0xa0027490, `lbu` at 0xa00274a0.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a4b07, including `sb` at 0xa002749c, `sb` at 0xa00274a8.
  The `lbu` at 0xa00274ac loads 1 byte from abs 0xffffffffbf3a4a07.
  The `sb` at 0xa00274b8 stores 1 byte to abs 0xffffffffbf3a4a07.
  The `sw` at 0xa00274e4 stores 4 bytes to abs 0xffffffffa003c004.
  The `jal` at 0xa0027484 calls flushbus [0xa0028520] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa00274c8 calls flushbus [0xa0028520] with a0=?, a1=?, a2=-0x11, a3=0xffffffffbf3a0000, a4=-0x4, a5=([0xffffffffbf3a4b07]:1 | 0x81), a7=-0x3.
  The return at 0xa00274e0 has v0 = ret(flushbus).

- `cpu_powerdown` in `sbin/stand/symmon.IP32` at 0xa00274e8 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa00274e8-0xa00275ec (260 bytes).
  It occupies 260 bytes.
  The `lbu` at 0xa002753c loads 1 byte from abs 0xffffffffbf3a0a07.
  3 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a4b07, including `lbu` at 0xa002755c, `lbu` at 0xa00275d0, `lbu` at 0xa00275dc.
  3 such `sb` accesses store 1 byte to abs 0xffffffffbf3a4b07, including `sb` at 0xa0027564, `sb` at 0xa00275d8, `sb` at 0xa00275e8.
  3 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a4a07, including `lbu` at 0xa0027568, `lbu` at 0xa0027580, `lbu` at 0xa0027590.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a4a07, including `sb` at 0xa0027574, `sb` at 0xa0027598.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a0a07, including `sb` at 0xa00275a0, `sb` at 0xa00275c4.
  The `jal` at 0xa0027570 calls flushbus [0xa0028520] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa0027578 calls us_delay [0xa0029048] with a0=0xf4240, a1=?, a2=?, a3=?.
  The `jal` at 0xa002759c calls flushbus [0xa0028520] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa00275a4 calls us_delay [0xa0029048] with a0=0xf4240, a1=?, a2=?, a3=?.
  The `jal` at 0xa00275ac calls printf [0xa002e620] with a0=0xffffffffa0037218, a1=?, a2=?, a3=?.
  The `jal` at 0xa00275b4 calls us_delay [0xa0029048] with a0=0xf4240, a1=?, a2=?, a3=?.
  The `jal` at 0xa00275c0 calls flushbus [0xa0028520] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa0027554 targets 0xa00275bc and is always taken.
  The `bne` branch at 0xa0027588 targets 0xa0027568, is taken when (ra(=[0xffffffffbf3a4a07]:1) & 0x3) != 0, and falls through when (ra(=[0xffffffffbf3a4a07]:1) & 0x3) == 0.
  The `bne` branch at 0xa00275c8 targets 0xa002755c, is taken when s6(=a0) != 0, and falls through when s6(=a0) == 0.
  The `beq` branch at 0xa00275e4 targets 0xa0027568 and is always taken.

- `cpu_scandevs` in `sbin/stand/symmon.IP32` at 0xa00275ec (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa00275ec-0xa0027690 (164 bytes).
  It occupies 164 bytes.
  The `lw` at 0xa00275f0 loads 4 bytes from abs 0xffffffffa003c004.
  The `lbu` at 0xa0027604 loads 1 byte from abs 0xffffffffbf3a0c07.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a0a07, including `lbu` at 0xa0027614, `lbu` at 0xa002763c.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a0a07, including `sb` at 0xa0027620, `sb` at 0xa0027650.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a4a07, including `lbu` at 0xa0027628, `lbu` at 0xa002762c.
  The `sb` at 0xa0027638 stores 1 byte to abs 0xffffffffbf3a4a07.
  The `lw` at 0xa002767c loads 4 bytes from abs 0xffffffffa005a3e0.
  The `jal` at 0xa002761c calls flushbus [0xa0028520] with a0=a0 at entry (arg0), a1=0xffffffffbf3a0000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa002764c calls flushbus [0xa0028520] with a0=?, a1=?, a2=-0x11, a3=0xffffffffbf3a0000, a4=-0x4, a5=[0xffffffffbf3a4a07]:1.
  The `jal` at 0xa0027664 calls cpu_powerdown [0xa00274e8] with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa00275f8 targets 0xa0027678, is taken when at(=[0xffffffffa003c004]) == 0, and falls through when at(=[0xffffffffa003c004]) != 0.
  The `beq` branch at 0xa002760c targets 0xa0027670, is taken when (v0(=[0xffffffffbf3a0c07]:1) & 0x80) == 0, and falls through when (v0(=[0xffffffffbf3a0c07]:1) & 0x80) != 0.
  The `beq` branch at 0xa002765c targets 0xa0027670, is taken when (a6(=[0xffffffffbf3a4a07]:1) & 0x1) == 0, and falls through when (a6(=[0xffffffffbf3a4a07]:1) & 0x1) != 0.
  The `bne` branch at 0xa0027680 targets 0xa0027670, is taken when a7(=[0xffffffffa005a3e0]) != 0, and falls through when a7(=[0xffffffffa005a3e0]) == 0.
  The `beq` branch at 0xa0027688 targets 0xa0027604 and is always taken.
  The return at 0xa0027670 has v0 = one of ?, ret(flushbus), ret(cpu_powerdown).

- `flashEnable` in `sbin/stand/symmon.IP32` at 0xa00277cc (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa00277cc-0xa0027800 (52 bytes).
  It occupies 52 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffbf310008, including `ld` at 0xa00277d8, `ld` at 0xa00277ec.
  2 such `sd` accesses store 8 bytes to abs 0xffffffffbf310008, including `sd` at 0xa00277e0, `sd` at 0xa00277fc.
  The `beq` branch at 0xa00277d0 targets 0xa00277ec, is taken when a0 == 0, and falls through when a0 != 0.
  The return at 0xa00277e4 has v0 = ?.
  The return at 0xa00277f8 has v0 = ?.

- `cpu_get_memsize` in `sbin/stand/symmon.IP32` at 0xa0027e40 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0027e40-0xa0027eac (108 bytes).
  It occupies 108 bytes.
  The `ld` at 0xa0027e44 loads 8 bytes from abs 0xffffffffb4000208.
  The `ld` at 0xa0027e78 loads 8 bytes from ?.
  The `sw` at 0xa0027ea0 stores 4 bytes to abs 0xffffffffa0058d98.
  The `beq` branch at 0xa0027e50 targets 0xa0027ea4, is taken when (a5(=[0xffffffffb4000208]:8) & 0x100) == 0, and falls through when (a5(=[0xffffffffb4000208]:8) & 0x100) != 0.
  The `beq` branch at 0xa0027e68 targets 0xa0027e78 and is always taken.
  The `beq` branch at 0xa0027e70 targets 0xa0027e9c, is taken when a3(?) == a7(=0x8), and falls through when a3(?) != a7(=0x8).
  The `beq` branch at 0xa0027e80 targets 0xa0027e70, is taken when a5(=[0xffffffffb4000208]:8) == a4(?), and falls through when a5(=[0xffffffffb4000208]:8) != a4(?).
  The `bnel` branch at 0xa0027e8c targets 0xa0027e70, is taken when (a4(?) & 0x100) != 0, and falls through when (a4(?) & 0x100) == 0; its branch-likely delay slot `addu v0,a6,v0` at 0xa0027e90 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa0027e94 targets 0xa0027e70 and is always taken.
  The `beq` branch at 0xa0027ea4 targets 0xa0027e5c and is always taken.
  The return at 0xa0027e9c has v0 = ?.

- `ip32_set_cpuled` in `sbin/stand/symmon.IP32` at 0xa0028004 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0028004-0xa0028028 (36 bytes).
  It occupies 36 bytes.
  The `ld` at 0xa002800c loads 8 bytes from abs 0xffffffffbf310008.
  The `sd` at 0xa0028024 stores 8 bytes to abs 0xffffffffbf310008.
  The return at 0xa0028020 has v0 = 0xffffffffbf310000.

- `init_pci` in `sbin/stand/symmon.IP32` at 0xa0028184 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0028184-0xa00281a8 (36 bytes).
  It occupies 36 bytes.
  The `sw` at 0xa0028194 stores 4 bytes to abs 0xffffffffa00596ec.
  The `sw` at 0xa002819c stores 4 bytes to abs 0xffffffffbf080004.
  The `sw` at 0xa00281a4 stores 4 bytes to abs 0xffffffffbf080008.
  The return at 0xa00281a0 has v0 = 0xffffffffbf080000.

- `wbflush` in `sbin/stand/symmon.IP32` at 0xa0028520 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0028520-0xa0028540 (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0xa0028528 loads 8 bytes from abs 0xffffffffb4000008.
  The `ld` at 0xa002852c loads 8 bytes from abs 0xffffffffb4000200.
  The `ld` at 0xa002853c loads 8 bytes from abs 0xffffffffbf310008.
  The return at 0xa0028538 has v0 = ?.

- `crm_softreset` in `sbin/stand/symmon.IP32` at 0xa002859c (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa002859c-0xa00285b8 (28 bytes).
  It occupies 28 bytes.
  The `sd` at 0xa00285ac stores 8 bytes to abs 0xffffffffb4000008.
  The `bal` at 0xa00285a8 calls crm_deadloop [0xa00285d4] with a0=0xffffffffb4000008, a1=0x400, a2=?, a3=?.
  The `beq` branch at 0xa00285b0 targets 0xa002859c and is always taken.

- `crm_hardreset` in `sbin/stand/symmon.IP32` at 0xa00285b8 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa00285b8-0xa00285d4 (28 bytes).
  It occupies 28 bytes.
  The `sd` at 0xa00285c8 stores 8 bytes to abs 0xffffffffb4000008.
  The `bal` at 0xa00285c4 calls crm_deadloop [0xa00285d4] with a0=0xffffffffb4000008, a1=0x800, a2=?, a3=?.
  The `beq` branch at 0xa00285cc targets 0xa00285b8 and is always taken.

- `crm_deadloop` in `sbin/stand/symmon.IP32` at 0xa00285d4 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa00285d4-0xa0028600 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0xa00285d8 loads 8 bytes from abs 0xffffffffbf310008.
  The `sd` at 0xa00285e8 stores 8 bytes to abs 0xffffffffbf310008.
  The `bgtz` branch at 0xa00285f0 targets 0xa00285f0, is taken when a2(?) > 0 (signed), and falls through when a2(?) <= 0 (signed).
  The return at 0xa00285f8 has v0 = ?.

- `led_on` in `sbin/stand/symmon.IP32` at 0xa0028600 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0028600-0xa0028640 (64 bytes).
  It occupies 64 bytes.
  The `ld` at 0xa0028614 loads 8 bytes from abs 0xffffffffbf310008.
  The `sd` at 0xa0028628 stores 8 bytes to abs 0xffffffffbf310008.
  The return at 0xa0028634 has v0 = ?.
  The instructions from 0xa002863c to 0xa002863c are not reached by any path from the entry, and their branches are not listed.

- `led_off` in `sbin/stand/symmon.IP32` at 0xa0028640 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0028640-0xa0028678 (56 bytes).
  It occupies 56 bytes.
  The `ld` at 0xa0028654 loads 8 bytes from abs 0xffffffffbf310008.
  The `sd` at 0xa0028660 stores 8 bytes to abs 0xffffffffbf310008.
  The return at 0xa002866c has v0 = ?.
  The instructions from 0xa0028674 to 0xa0028674 are not reached by any path from the entry, and their branches are not listed.

- `ticksper1024inst` in `sbin/stand/symmon.IP32` at 0xa0028678 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0028678-0xa00286b8 (64 bytes).
  It occupies 64 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000038, including `ld` at 0xa0028698, `ld` at 0xa00286a4.
  Calls (unnamed) [0xffffffffa002868c] via register-constant with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`jr` at 0xa00286a8).
  The `beq` branch at 0xa0028684 targets 0xa0028694 and is always taken.
  The `bgtz` branch at 0xa002869c targets 0xa002869c, is taken when t1(?) > 0 (signed), and falls through when t1(?) <= 0 (signed).
  The instructions from 0xa002868c to 0xa0028690 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xa00286b0 to 0xa00286b4 are not reached by any path from the entry, and their branches are not listed.

- `cpuclkper100ticks` in `sbin/stand/symmon.IP32` at 0xa00286b8 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa00286b8-0xa0028768 (176 bytes).
  It occupies 176 bytes.
  The `sd` at 0xa00286f0 stores 8 bytes to abs 0xffffffffb4000038.
  The `ld` at 0xa00286f8 loads 8 bytes from abs 0xffffffffb4000038.
  Calls (unnamed) [0xffffffffa00286d0] via register-constant with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`jr` at 0xa0028758).
  The `beq` branch at 0xa00286c8 targets 0xa00286d8 and is always taken.
  The `bne` branch at 0xa002870c targets 0xa00286f8, is taken when t2(?) < t0(=0x5bc8) (unsigned), and falls through when t2(?) >= t0(=0x5bc8) (unsigned).
  The `bne` branch at 0xa002871c targets 0xa00286ec, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `bne` branch at 0xa0028734 targets 0xa0028740 and is always taken.
  The `bne` branch at 0xa002874c targets 0xa0028758 and is always taken.
  The instructions from 0xa00286d0 to 0xa00286d4 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xa002873c to 0xa002873c are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xa0028754 to 0xa0028754 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xa0028760 to 0xa0028764 are not reached by any path from the entry, and their branches are not listed.

- `_ticksper1024inst` in `sbin/stand/symmon.IP32` at 0xa0029174 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0029174-0xa00291ac (56 bytes).
  It occupies 56 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000038, including `ld` at 0xa0029194, `ld` at 0xa00291a0.
  The `bgtz` branch at 0xa0029198 targets 0xa0029198, is taken when t1(?) > 0 (signed), and falls through when t1(?) <= 0 (signed).
  The return at 0xa00291a4 has v0 = ?.

- `_cpuclkper100ticks` in `sbin/stand/symmon.IP32` at 0xa00291ac (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa00291ac-0xa0029260 (180 bytes).
  It occupies 180 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000038, including `ld` at 0xa00291e4, `ld` at 0xa00291f0.
  The `sw` at 0xa0029248 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `bne` branch at 0xa00291fc targets 0xa00291f0, is taken when t2(=[0xffffffffb4000038]:8) < t0(=[0xffffffffb4000038]:8+23496) (unsigned), and falls through when t2(=[0xffffffffb4000038]:8) >= t0(=[0xffffffffb4000038]:8+23496) (unsigned).
  The `bne` branch at 0xa0029218 targets 0xa00291e4, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `bne` branch at 0xa0029230 targets 0xa002923c and is always taken.
  The `bne` branch at 0xa002924c targets 0xa0029258 and is always taken.
  The return at 0xa0029258 has v0 = ?.
  The instructions from 0xa0029238 to 0xa0029238 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xa0029254 to 0xa0029254 are not reached by any path from the entry, and their branches are not listed.

- `md_init` in `sbin/stand/symmon.IP32` at 0xa00292c8 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa00292c8-0xa00293f0 (296 bytes).
  It occupies 296 bytes.
  The `lw` at 0xa00292d8 loads 4 bytes from abs 0xffffffffa005a3e0.
  2 such `sw` accesses store 4 bytes to abs 0xffffffffa00592b0, including `sw` at 0xa00292f4, `sw` at 0xa0029384.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa00293a0, `sw` at 0xa00293c0, `sw` at 0xa00293c8.
  The `lw` at 0xa00293bc loads 4 bytes from ret(arcsGetMemDesc) +0x0.
  The `lw` at 0xa00293c4 loads 4 bytes from ret(arcsGetMemDesc) +0x4.
  The `lw` at 0xa00293d0 loads 4 bytes from ret(arcsGetMemDesc) +0x8.
  The `jal` at 0xa00292f0 calls cpu_mem_init [0xa0027eac] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa0029300 calls md_alloc [0xa00293f0] with a0=0x1000, a1=0x1, a2=0x1, a3=?.
  The `jal` at 0xa0029310 calls md_alloc [0xa00293f0] with a0=0x0, a1=0x1, a2=0x0, a3=?.
  The `jal` at 0xa0029334 calls arcsGetMemDesc [0xa002a724] with a0=0x0, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa0029348 calls arcsGetMemDesc [0xa002a724] with a0=ret(arcsGetMemDesc), a1=?, a2=?, a3=?.
  The `jal` at 0xa002936c calls malloc [0xa002fb10] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa0029380 calls arcsGetMemDesc [0xa002a724] with a0=0x0, a1=0xffffffffa0060000, a2=?, a3=?.
  The `jal` at 0xa00293ac calls arcsGetMemDesc [0xa002a724] with a0=ret(arcsGetMemDesc), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa00292e4 targets 0xa0029334, is taken when at(=[0xffffffffa005a3e0]) == 0, and falls through when at(=[0xffffffffa005a3e0]) != 0.
  The `beq` branch at 0xa002933c targets 0xa0029360, is taken when v0(=ret(arcsGetMemDesc)) == 0, and falls through when v0(=ret(arcsGetMemDesc)) != 0.
  The `bne` branch at 0xa0029350 targets 0xa0029348, is taken when v0(=ret(arcsGetMemDesc)) != 0, and falls through when v0(=ret(arcsGetMemDesc)) == 0.
  The `beq` branch at 0xa0029358 targets 0xa0029368 and is always taken.
  The `beq` branch at 0xa0029388 targets 0xa002931c, is taken when v0(=ret(arcsGetMemDesc)) == 0, and falls through when v0(=ret(arcsGetMemDesc)) != 0.
  The `beq` branch at 0xa0029398 targets 0xa00293bc and is always taken.
  The `beq` branch at 0xa00293b4 targets 0xa00293e8, is taken when v0(=ret(arcsGetMemDesc)) == 0, and falls through when v0(=ret(arcsGetMemDesc)) != 0.
  The `bne` branch at 0xa00293d8 targets 0xa00293a0, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0xa00293e0 targets 0xa00293a4 and is always taken.
  The `beq` branch at 0xa00293e8 targets 0xa002931c and is always taken.
  The return at 0xa002932c has v0 = one of ret(md_alloc), ret(arcsGetMemDesc).

- `md_alloc` in `sbin/stand/symmon.IP32` at 0xa00293f0 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa00293f0-0xa002951c (300 bytes).
  It occupies 300 bytes.
  The `lw` at 0xa002940c loads 4 bytes from abs 0xffffffffa00592b0.
  The `lw` at 0xa0029424 loads 4 bytes from [0xffffffffa00592b0] +0x4.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa0029434, `lw` at 0xa0029444, `lw` at 0xa0029448.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa0029490, `sw` at 0xa00294a0, `sw` at 0xa0029518.
  The `jal` at 0xa0029488 calls md_add [0xa002963c] with a0=((a1 << 0xc) + a0), a1=?, a2=?, a3=a3 at entry (arg3), a5=a2 at entry (arg2).
  The `jal` at 0xa00294ac calls printf [0xa002e620] with a0=0xffffffffa00375e8, a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a2 at entry (arg2).
  The `jal` at 0xa00294e4 calls md_add [0xa002963c] with a0=((a1 << 0xc) + a0), a1=?, a2=?, a3=a3 at entry (arg3), a5=a2 at entry (arg2).
  The `jal` at 0xa00294f4 calls md_add [0xa002963c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `beq` branch at 0xa0029418 targets 0xa0029460, is taken when at(=[0xffffffffa00592b0]) == 0, and falls through when at(=[0xffffffffa00592b0]) != 0.
  The `beq` branch at 0xa0029420 targets 0xa0029438 and is always taken.
  The `beq` branch at 0xa002942c targets 0xa00294a8, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bnel` branch at 0xa0029440 targets 0xa002942c, is taken when s1(=a0) < v1(?) (unsigned), and falls through when s1(=a0) >= v1(?) (unsigned); its branch-likely delay slot `lw s0,16(s0)` at 0xa0029444 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0xa0029458 targets 0xa002942c, is taken when s1(=a0) >= a0(?) (unsigned), and falls through when s1(=a0) < a0(?) (unsigned); its branch-likely delay slot `lw s0,16(s0)` at 0xa002945c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa0029460 targets 0xa00294a8, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0xa0029480 targets 0xa00294d4, is taken when a6(?) != s1(=a0), and falls through when a6(?) == s1(=a0).
  The `beq` branch at 0xa002949c targets 0xa00294b8 and is always taken.
  The `beq` branch at 0xa0029514 targets 0xa00294b8 and is always taken.
  The return at 0xa00294cc has v0 = one of ?, 0x0, ret(md_add).
  The instructions from 0xa0029428 to 0xa0029428 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xa00294a4 to 0xa00294a4 are not reached by any path from the entry, and their branches are not listed.

- `md_dealloc` in `sbin/stand/symmon.IP32` at 0xa002951c (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa002951c-0xa002963c (288 bytes).
  It occupies 288 bytes.
  The `lw` at 0xa0029528 loads 4 bytes from abs 0xffffffffa00592b0.
  14 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa0029550, `lw` at 0xa0029560, `lw` at 0xa0029564.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa0029588, `sw` at 0xa0029600, `sw` at 0xa002960c.
  The `lw` at 0xa0029598 loads 4 bytes from [0xffffffffa00592b0] +0x10.
  The `jal` at 0xa00295a4 calls printf [0xa002e620] with a0=0xffffffffa00375e8, a1=(a0 << 0xc), a2=a2 at entry (arg2), a3=?, a4=a0 at entry (arg0), a5=[0xffffffffa00592b0].
  The `jal` at 0xa0029608 calls free [0xa002fd18] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa0029534 targets 0xa002957c, is taken when a5(=[0xffffffffa00592b0]) == 0, and falls through when a5(=[0xffffffffa00592b0]) != 0.
  The `beq` branch at 0xa002953c targets 0xa0029550 and is always taken.
  The `beq` branch at 0xa0029548 targets 0xa00295a0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bnel` branch at 0xa002955c targets 0xa0029548, is taken when v0(=(a0 << 0xc)) < a6(?) (unsigned), and falls through when v0(=(a0 << 0xc)) >= a6(?) (unsigned); its branch-likely delay slot `lw s0,16(s0)` at 0xa0029560 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0xa0029574 targets 0xa0029548, is taken when v0(=(a0 << 0xc)) >= a7(?) (unsigned), and falls through when v0(=(a0 << 0xc)) < a7(?) (unsigned); its branch-likely delay slot `lw s0,16(s0)` at 0xa0029578 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa002957c targets 0xa00295a0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa002958c targets 0xa00295b4, is taken when a5(=[0xffffffffa00592b0]) == 0, and falls through when a5(=[0xffffffffa00592b0]) != 0.
  The `beq` branch at 0xa0029594 targets 0xa00295d4 and is always taken.
  The `beq` branch at 0xa00295ac targets 0xa00295b8 and is always taken.
  The `beq` branch at 0xa00295c8 targets 0xa00295b4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xa00295d4 targets 0xa00295c8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xa00295e0 targets 0xa00295c8, is taken when v0(?) != a3(=0x3), and falls through when v0(?) == a3(=0x3).
  The `bne` branch at 0xa00295ec targets 0xa00295c8, is taken when a1(?) != v0(?), and falls through when a1(?) == v0(?).
  The `beq` branch at 0xa0029614 targets 0xa00295c8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xa0029620 targets 0xa00295c8, is taken when v0(?) != a3(=0x3), and falls through when v0(?) == a3(=0x3).
  The `beql` branch at 0xa002962c targets 0xa00295f8, is taken when a5(?) == v0(?), and falls through when a5(?) != v0(?); its branch-likely delay slot `lw a4,8(a0)` at 0xa0029630 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa0029634 targets 0xa00295c8 and is always taken.
  The return at 0xa00295c0 has v0 = one of 0x0, 0x1.
  The instructions from 0xa0029544 to 0xa0029544 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xa002959c to 0xa002959c are not reached by any path from the entry, and their branches are not listed.

- `md_add` in `sbin/stand/symmon.IP32` at 0xa002963c (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa002963c-0xa00297d4 (408 bytes).
  It occupies 408 bytes.
  The `lw` at 0xa0029668 loads 4 bytes from abs 0xffffffffa00592b0.
  2 such `lw` accesses load 4 bytes from [0xffffffffa00592b0] +0x4, including `lw` at 0xa002967c, `lw` at 0xa00296a0.
  The `lw` at 0xa0029690 loads 4 bytes from [0xffffffffa00592b0] +0x10.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa00296b4, `lw` at 0xa00296c0, `lw` at 0xa00296c4.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa00296e8, `sw` at 0xa0029704.
  4 such `sw` accesses store 4 bytes to ret(malloc) +0x10, including `sw` at 0xa00296f4, `sw` at 0xa002970c, `sw` at 0xa002976c.
  The `sw` at 0xa0029710 stores 4 bytes to ret(malloc) +0x4.
  The `sw` at 0xa0029724 stores 4 bytes to ret(malloc) +0xc.
  The `sw` at 0xa0029728 stores 4 bytes to ret(malloc) +0x8.
  The `sw` at 0xa002972c stores 4 bytes to ret(malloc) +0x0.
  2 such `sw` accesses store 4 bytes to abs 0xffffffffa00592b0, including `sw` at 0xa0029778, `sw` at 0xa00297b4.
  The `jal` at 0xa00296dc calls malloc [0xa002fb10] with a0=0x14, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa00296f8 calls malloc [0xa002fb10] with a0=0x14, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa0029754 calls malloc [0xa002fb10] with a0=0x14, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa00297a0 calls malloc [0xa002fb10] with a0=0x14, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa002965c targets 0xa0029784, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0xa0029670 targets 0xa00297a0, is taken when s3(=[0xffffffffa00592b0]) == 0, and falls through when s3(=[0xffffffffa00592b0]) != 0.
  The `bne` branch at 0xa002968c targets 0xa0029754, is taken when s2(?) < a1(=[[0xffffffffa00592b0]+4]) (unsigned), and falls through when s2(?) >= a1(=[[0xffffffffa00592b0]+4]) (unsigned).
  The `beq` branch at 0xa0029694 targets 0xa00296d4, is taken when s1(=[[0xffffffffa00592b0]+16]) == 0, and falls through when s1(=[[0xffffffffa00592b0]+16]) != 0.
  The `beq` branch at 0xa002969c targets 0xa00296b8 and is always taken.
  The `beq` branch at 0xa00296ac targets 0xa00296d4, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beql` branch at 0xa00296bc targets 0xa00296a8, is taken when t9(?) >= s2(?) (unsigned), and falls through when t9(?) < s2(?) (unsigned); its branch-likely delay slot `lw t8,16(s1)` at 0xa00296c0 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0xa00296cc targets 0xa00296a8, is taken when s2(?) >= ra(?) (unsigned), and falls through when s2(?) < ra(?) (unsigned); its branch-likely delay slot `lw t8,16(s1)` at 0xa00296d0 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0xa00296d4 targets 0xa00296f8, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0xa00296e4 targets 0xa0029790, is taken when v0(=ret(malloc)) == 0, and falls through when v0(=ret(malloc)) != 0.
  The `beq` branch at 0xa00296f0 targets 0xa0029710 and is always taken.
  The `beq` branch at 0xa0029700 targets 0xa002977c, is taken when v0(=ret(malloc)) == 0, and falls through when v0(=ret(malloc)) != 0.
  The `beq` branch at 0xa002975c targets 0xa0029798, is taken when v0(=ret(malloc)) == 0, and falls through when v0(=ret(malloc)) != 0.
  The `beq` branch at 0xa0029774 targets 0xa0029710 and is always taken.
  The `beq` branch at 0xa002977c targets 0xa0029730 and is always taken.
  The `beq` branch at 0xa0029788 targets 0xa0029730 and is always taken.
  The `beq` branch at 0xa0029790 targets 0xa0029730 and is always taken.
  The `beq` branch at 0xa0029798 targets 0xa0029734 and is always taken.
  The `beq` branch at 0xa00297b0 targets 0xa00297cc, is taken when v0(=ret(malloc)) == 0, and falls through when v0(=ret(malloc)) != 0.
  The `beq` branch at 0xa00297c4 targets 0xa0029710 and is always taken.
  The `beq` branch at 0xa00297cc targets 0xa0029730 and is always taken.
  The return at 0xa002974c has v0 = one of ?, 0x0.
  The instructions from 0xa00296a4 to 0xa00296a4 are not reached by any path from the entry, and their branches are not listed.

- `usecwait` in `sbin/stand/symmon.IP32` at 0xa0029f54 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0029f54-0xa0029f94 (64 bytes).
  It occupies 64 bytes.
  The `sd` at 0xa0029f64 stores 8 bytes to abs 0xffffffffb4000038.
  The `ld` at 0xa0029f74 loads 8 bytes from abs 0xffffffffb4000038.
  The `bgtz` branch at 0xa0029f84 targets 0xa0029f74, is taken when a2(?) > 0 (signed), and falls through when a2(?) <= 0 (signed).
  The return at 0xa0029f8c has v0 = ?.

- `clockAccess` in `sbin/stand/symmon.IP32` at 0xa002a4b4 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa002a4b4-0xa002a5c4 (272 bytes).
  It occupies 272 bytes.
  5 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a0a07, including `lbu` at 0xa002a4b8, `lbu` at 0xa002a4d8, `lbu` at 0xa002a4e8.
  The `lbu` at 0xa002a520 loads 1 byte from a1 (arg1 at entry) +0x7.
  The `lbu` at 0xa002a524 loads 1 byte from a1 (arg1 at entry) +0x6.
  The `lbu` at 0xa002a528 loads 1 byte from a1 (arg1 at entry) +0x5.
  The `lbu` at 0xa002a52c loads 1 byte from a1 (arg1 at entry) +0x4.
  The `lbu` at 0xa002a530 loads 1 byte from a1 (arg1 at entry) +0x3.
  The `lbu` at 0xa002a534 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `lbu` at 0xa002a538 loads 1 byte from a1 (arg1 at entry) +0x1.
  The `lbu` at 0xa002a53c loads 1 byte from a1 (arg1 at entry) +0x2.
  The `sb` at 0xa002a540 stores 1 byte to abs 0xffffffffbf3a0007.
  The `sb` at 0xa002a544 stores 1 byte to abs 0xffffffffbf3a0207.
  The `sb` at 0xa002a548 stores 1 byte to abs 0xffffffffbf3a0407.
  The `sb` at 0xa002a54c stores 1 byte to abs 0xffffffffbf3a0707.
  The `sb` at 0xa002a550 stores 1 byte to abs 0xffffffffbf3a0807.
  The `sb` at 0xa002a554 stores 1 byte to abs 0xffffffffbf3a0907.
  The `sb` at 0xa002a558 stores 1 byte to abs 0xffffffffbf3a4807.
  The `sb` at 0xa002a55c stores 1 byte to abs 0xffffffffbf3a0607.
  The `lbu` at 0xa002a568 loads 1 byte from abs 0xffffffffbf3a0007.
  The `lbu` at 0xa002a56c loads 1 byte from abs 0xffffffffbf3a0207.
  The `lbu` at 0xa002a570 loads 1 byte from abs 0xffffffffbf3a0407.
  The `sb` at 0xa002a574 stores 1 byte to a1 (arg1 at entry) +0x1.
  The `sb` at 0xa002a578 stores 1 byte to a1 (arg1 at entry) +0x2.
  The `lbu` at 0xa002a57c loads 1 byte from abs 0xffffffffbf3a0707.
  The `sb` at 0xa002a580 stores 1 byte to a1 (arg1 at entry) +0x0.
  The `lbu` at 0xa002a584 loads 1 byte from abs 0xffffffffbf3a0807.
  The `sb` at 0xa002a588 stores 1 byte to a1 (arg1 at entry) +0x3.
  The `lbu` at 0xa002a58c loads 1 byte from abs 0xffffffffbf3a0907.
  The `sb` at 0xa002a590 stores 1 byte to a1 (arg1 at entry) +0x4.
  The `lbu` at 0xa002a594 loads 1 byte from abs 0xffffffffbf3a4807.
  The `sb` at 0xa002a598 stores 1 byte to a1 (arg1 at entry) +0x5.
  The `lbu` at 0xa002a59c loads 1 byte from abs 0xffffffffbf3a0607.
  The `sb` at 0xa002a5a0 stores 1 byte to a1 (arg1 at entry) +0x6.
  The `sb` at 0xa002a5a8 stores 1 byte to a1 (arg1 at entry) +0x7.
  The `sb` at 0xa002a5b8 stores 1 byte to abs 0xffffffffbf3a0a07.
  The `beq` branch at 0xa002a4c4 targets 0xa002a4d8, is taken when at(?) == v1(=0x20), and falls through when at(?) != v1(=0x20).
  The `beq` branch at 0xa002a4e0 targets 0xa002a5ac, is taken when (v1(=[0xffffffffbf3a0a07]:1) & 0x10) == 0, and falls through when (v1(=[0xffffffffbf3a0a07]:1) & 0x10) != 0.
  The `beq` branch at 0xa002a4f4 targets 0xa002a518, is taken when (a2(=[0xffffffffbf3a0a07]:1) & 0x80) == 0, and falls through when (a2(=[0xffffffffbf3a0a07]:1) & 0x80) != 0.
  The `beq` branch at 0xa002a500 targets 0xa002a5bc, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0xa002a510 targets 0xa002a500, is taken when (v1(=[0xffffffffbf3a0a07]:1) & 0x80) != 0, and falls through when (v1(=[0xffffffffbf3a0a07]:1) & 0x80) == 0.
  The `beq` branch at 0xa002a518 targets 0xa002a568, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0xa002a5a4 targets 0xa002a560 and is always taken.
  The `beq` branch at 0xa002a5b4 targets 0xa002a4e8 and is always taken.
  The return at 0xa002a4d0 has v0 = 0x1.
  The return at 0xa002a560 has v0 = 0x0.
  The return at 0xa002a5bc has v0 = 0x1.

- `resetClock` in `sbin/stand/symmon.IP32` at 0xa002a5c4 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa002a5c4-0xa002a65c (152 bytes).
  It occupies 152 bytes.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a0b07, including `lbu` at 0xa002a5fc, `lbu` at 0xa002a62c.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a0b07, including `sb` at 0xa002a610, `sb` at 0xa002a640.
  The `lbu` at 0xa002a614 loads 1 byte from abs 0xffffffffbf3a0a07.
  The `sb` at 0xa002a628 stores 1 byte to abs 0xffffffffbf3a0a07.
  The `jal` at 0xa002a63c calls clockAccess [0xa002a4b4] with a0=0x1, a1=sp-16, a2=0x1, a3=?, a4=-0x41, a6=-0x5, a7=0x2.
  The `jal` at 0xa002a648 calls printf [0xa002e620] with a0=0xffffffffa0037678, a1=?, a2=?, a3=?.
  The return at 0xa002a654 has v0 = ret(printf).

- `kl_inv_find` in `sbin/stand/symmon.IP32` at 0xa0030eb8 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0030eb8-0xa0030efc (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0xa0030ebc loads 4 bytes from abs 0xffffffffa0001024.
  The `lw` at 0xa0030ee0 loads 4 bytes from abs 0xffffffffa0001028.
  The `lw` at 0xa0030ee4 loads 4 bytes from [0xffffffffa0001028] +0x34.
  The `jalr` at 0xa0030ee8 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa0030ec8 targets 0xa0030ee0, is taken when at(=[0xffffffffa0001024]) >= 0x35 (unsigned), and falls through when at(=[0xffffffffa0001024]) < 0x35 (unsigned).
  The `beq` branch at 0xa0030ef4 targets 0xa0030ed4 and is always taken.
  The return at 0xa0030ed8 has v0 = one of 0x0, ret(?).

- `kl_hinv` in `sbin/stand/symmon.IP32` at 0xa0030efc (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0030efc-0xa0030f40 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0xa0030f00 loads 4 bytes from abs 0xffffffffa0001024.
  The `lw` at 0xa0030f24 loads 4 bytes from abs 0xffffffffa0001028.
  The `lw` at 0xa0030f28 loads 4 bytes from [0xffffffffa0001028] +0x38.
  The `jalr` at 0xa0030f2c calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa0030f0c targets 0xa0030f24, is taken when at(=[0xffffffffa0001024]) >= 0x39 (unsigned), and falls through when at(=[0xffffffffa0001024]) < 0x39 (unsigned).
  The `beq` branch at 0xa0030f38 targets 0xa0030f18 and is always taken.
  The return at 0xa0030f1c has v0 = one of 0x0, ret(?).

- `kl_get_num_cpus` in `sbin/stand/symmon.IP32` at 0xa0030f40 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0030f40-0xa0030f84 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0xa0030f44 loads 4 bytes from abs 0xffffffffa0001024.
  The `lw` at 0xa0030f68 loads 4 bytes from abs 0xffffffffa0001028.
  The `lw` at 0xa0030f6c loads 4 bytes from [0xffffffffa0001028] +0x3c.
  The `jalr` at 0xa0030f70 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa0030f50 targets 0xa0030f68, is taken when at(=[0xffffffffa0001024]) >= 0x3d (unsigned), and falls through when at(=[0xffffffffa0001024]) < 0x3d (unsigned).
  The `beq` branch at 0xa0030f7c targets 0xa0030f5c and is always taken.
  The return at 0xa0030f60 has v0 = one of 0x0, ret(?).

- `sn0_getcpuid` in `sbin/stand/symmon.IP32` at 0xa0030f84 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0030f84-0xa0030fc8 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0xa0030f88 loads 4 bytes from abs 0xffffffffa0001024.
  The `lw` at 0xa0030fac loads 4 bytes from abs 0xffffffffa0001028.
  The `lw` at 0xa0030fb0 loads 4 bytes from [0xffffffffa0001028] +0x40.
  The `jalr` at 0xa0030fb4 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa0030f94 targets 0xa0030fac, is taken when at(=[0xffffffffa0001024]) >= 0x41 (unsigned), and falls through when at(=[0xffffffffa0001024]) < 0x41 (unsigned).
  The `beq` branch at 0xa0030fc0 targets 0xa0030fa0 and is always taken.
  The return at 0xa0030fa4 has v0 = one of -0x1, ret(?).
