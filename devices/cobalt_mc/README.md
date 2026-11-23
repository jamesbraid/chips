# Cobalt memory controller

Mode: **no-spec**. The memory controller of the Visual Workstation 320 and 540 system ASIC ([cobalt](../cobalt/README.md)).
No Linux code touches it; the shipped NT HAL touches the ECC control and the error registers, and the PROM self-test and
main module touch the rest. Registers: [registers.md](registers.md). Everything here is read from those binaries, so
meanings are **inferred** from use unless a register is only a value the code compares; no specification is held.

What the shipped code does, and where the full readings live:

- ECC control, error status, error address and syndrome: [nt-hal.md](../../software/visws/nt-hal.md#cobalt-registers-the-hal-programs).
- Bank registers, the delay counter pair, the "DIMM Speed Check" read at `+0x48` and the bank probe:
  [boot-path.md](../../software/visws/boot-path.md#memory-controller-and-graphics-memory),
  [prom-console-path.md](../../software/visws/prom-console-path.md#ram-probe).
- The bank registers start at `+0x48` on Cobalt revisions `0xa0` and `0xa8` and at `+0x50` on every other; the `+0x48` word
  on the other revisions is a separate register whose bit 16 must read 1.

Unknown: every reset value (the PROM writes before it reads), the meaning of the bank register bits beyond the stored codes
3, 2 and 0, the error status bits that select the message, the delay period and counter rates, and the block's extent past
one page. Routes: the Cobalt specification, or a read of a real machine's registers before any software has written them.
