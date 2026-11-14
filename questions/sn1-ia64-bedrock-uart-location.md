# SN1 IA-64: where the Bedrock UART sits

Question. The SN1 IA-64 early console programs a 16550-style UART at the node's remote register window plus `0x80`, with
registers eight bytes apart and a baud base of 124800 (`arch/ia64/sn/sn1/setup.c`, `sn1_setup`, used when the L1 protocol
console is not configured). The Bedrock pages place the junk-bus microcontroller and UART registers at hub offsets
`0x220000` and `0x220080` (the MD block, [devices/hub/README.md](../devices/hub/README.md)). Is the port's UART address a simulator model, a
Bedrock register alias, or the real device?

Routes tried: the port's source only. Its own comment calls the arrangement a hack in the serial code and
the same file defines `IS_RUNNING_ON_SIMULATOR`, so a simulator-only mapping is plausible, but no file says so. How the remote register window's offset 0 relates to hub register offsets is not stated either.

Added: the simulator run script sets `tsconsole on` and `uart_echo on`, so the simulator provided a console UART of its own,
which makes a simulator-only mapping more likely; the first-generation hardware's console is not described (SGI's account of
the power-on says the PROM, not the kernel, was the first code to run, and says nothing about the console). See
[platforms/sn1-ia64/bring-up.md](../platforms/sn1-ia64/bring-up.md).

Next route: the SN1 IA-64 PROM or a hardware note, neither held; or the Medusa simulator documentation. A route in the held
sources: open `drivers/char/serial.c` and `kernel/printk.c` at the v2.5.0 commit (the hack the comment names), which the
Library's text index does not cover but `read_library` opens by commit id.
