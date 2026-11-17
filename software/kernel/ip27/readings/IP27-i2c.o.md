# Readings: `IP27/usr/cpu/sysgen/IP27boot/i2c.o`

One entry per routine, filed here from the reading batches by binary.

- `i2c_probe` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x88
  **Inferred.** Role (from name): probes whether an I2C port answers. It reads through a window computed from `a0` with a fixed offset (loads at 0xb8 and 0xf8) and runs a loop bounded by a comparison at 0xf0 and 0x12c, returning 0 at 0x138 or 1 at 0x140. The device-level meaning comes only from the name, the offsets and the loop shape, so it is a guess from the register window.
  Reviewed: 2026-11-12

- `i2c_probe` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x88
  **Inferred.** A polling loop: a backward branch at 0x12c repeats while an unsigned count is below a bound, and the branch at 0xf0 leaves it when the count reaches the bound. It loads doublewords at 0x8c, 0xb8, 0xbc, 0xf8 and 0x108, two of them at the constant offset -0x6dfffffffe5e0000; the base registers are not shown. It returns 0 at 0x138 and 1 at 0x140, so it is a yes/no probe. The loop bound, the compared values and the register meanings are not shown by the facts.
  Reviewed: 2026-11-12

- `i2c_probe` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x88
  **Inferred.** Reads a doubleword from the fixed address 0x9200000001030100 and a second doubleword from an address built from a0 in the high window, several times over (`ld` at 0x8c, 0xb8, 0xbc, 0xf8, 0x108). Unsigned compares at 0xf0 and 0x12c against a6 and an equality test at 0x100 of a5 against t0 steer a loop that leaves by returning 0 at 0x138 or 1 at 0x140. The loop may be a bounded poll, but the facts do not show what it waits for. The meaning of the compared values is unknown.
  Reviewed: 2026-11-12

- `i2c_arb` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x148
  **Inferred.** Role (from name): arbitrates bus ownership before a transfer. It calls `node_can_talk_to_elsc` at 0x194 and branches to 0x334 on a zero result at 0x19c. It tests bit 0 of a register read at 0x1bc, 0x214 and 0x2d4, and compares a value loaded at 0x1c4 and 0x21c (not the incoming `a0`) against the constants 0xe0 and 0xe8 at 0x1cc, 0x1d4, 0x224 and 0x22c. A doubleword is stored at 0x208 when `a2` is nonzero. The return at 0x350 is either -11 or not derived.
  Reviewed: 2026-11-12

- `i2c_arb` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x148
  **Inferred.** Role (from name): an arbitration routine for a shared bus. It first calls `node_can_talk_to_elsc` at 0x194 and branches to 0x334 when that call yields zero. It then loops on loaded doubleword values, testing bit 0 of values loaded at constant offset -0x6dfffffffe5dfff8 and comparing a value loaded at 0x1c4, 0x21c and 0x2dc with the constants 0xe0 and 0xe8 at 0x1cc, 0x1d4, 0x224 and 0x22c. The return at 0x350 yields one of -0xb or an unknown value, so the meaning of the return value is open.
  Reviewed: 2026-11-12

- `i2c_arb` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x148
  **Inferred.** Calls node_can_talk_to_elsc at 0x194 with its four arguments, and a zero result there branches to the tail at 0x334. Later it tests bit 0 of doublewords loaded through a0-derived addresses (0x1bc, 0x214, 0x2d4) and compares the constants 0xe0 (a4) and 0xe8 (a5) against a doubleword loaded through an a0-derived address (0x1cc, 0x1d4, 0x224, 0x22c). It stores a doubleword through a2 at 0x208 and its return value at 0x350 is either unresolved or -0xb. Which arbitration step each branch implements is unknown.
  Reviewed: 2026-11-12

- `i2c_master_xmit` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x358
  **Inferred.** Role (from name): the master transmit half of an I2C transfer. It calls `i2c_arb` at 0x3b0, branches on a negative result at 0x3c0 and a zero result at 0x3d4, then runs a loop bounded by the length in `a3` (test at 0x4a4 and 0x538). Stores go through the computed window at `a0` (0x410, 0x4b8 and 0x548), and the code tests status bits 0x16, 0x80 and 0x8. A word is stored at 0x3ac and 0x528 through a pointer register, probably the fifth argument `a4`; what it holds is not derived from the facts.
  Reviewed: 2026-11-12

- `i2c_master_recv` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x5b0
  **Inferred.** Role (from name): the master receive half of an I2C transfer, the read counterpart of `i2c_master_xmit`. It calls `i2c_arb` at 0x610, branches on its result at 0x620 and 0x634, then loops with the length in `a3` tested at 0x70c and 0x714. Stores go through the computed window at `a0` (0x678 and 0x794), a byte store is at 0x768, and the code tests status bits 0x16 and 0x80. What those bits mean is not derived.
  Reviewed: 2026-11-12

- `i2c_master_xmit_recv` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x858
  **Inferred.** Role (from name): a combined write-then-read on the I2C bus, built from the same pieces as `i2c_master_xmit` and `i2c_master_recv`. It calls `i2c_arb` at 0x8c4 and then runs two loops in one body, one with a load-byte then store through the window at 0x9d0 and 0x9d4 and one with a byte store at 0xb38. The lengths are tested at 0x9bc, 0xad8 and 0xae0. Zero stores at 0x8b8 and 0x8c0 go through `a4` and `a7`, and word stores at 0xa44 and 0xb54 use other registers; the facts do not show what is counted. Status bits 0x16, 0x80 and 0x8 are tested as in the single-direction routines.
  Reviewed: 2026-11-12
