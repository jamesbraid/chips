# IOC4 serial ring DMA

The IOC4 serial ports move their data through rings in memory. The chip page
([devices/ioc4/README.md](README.md)) covers the register map and the
driver's port set-up. This page adds what the public Linux driver and the IOC3
notes say about the ring engine the two chips share. The field names and masks
are in `devices/ioc4/registers-extra.toml`.

Grades are established, inferred and unknown. The public driver is a driver
author's naming of the registers, not a measurement, so its field layouts are
inferred. The source is the Linux serial driver `drivers/tty/serial/ioc4_serial.c`
at the `references/code/linux-5.3` pin (`4d856f72c10e`), which holds all the masks
below (the driver was removed from later Linux trees, so the newest pin has no
copy). The commit named in earlier versions, `c9bace5bce3e`, is not a submodule
here and was not checked. The IOC3 comparison below reads `include/asm/sn/ioc3.h` in
the same pin.

## Ring pointers

- A ring entry is 8 bytes: four data bytes and four status bytes. Producer and
  consumer indices step in 8-byte units. (inferred, from the driver's entry layout)
- The active index bits are 11:3 on a 4 KB ring, mask `0xff8`. The chip page
  shows the reset path using that mask (established). A 1 KB ring uses bits 9:3,
  mask `0x3f8` (inferred, from the driver's pointer mask).

## Receive timer

- The RX timer register holds a reload count in bits 11:0 and a current count in
  bits 27:16. (inferred) The driver defines the current-count field and does not
  read it.
- The IOC3 receive-timeout routine stores at most 4095 in its timer register
  ([devices/ioc3/README.md](../ioc3/README.md)). That is the same twelve-bit
  reload field, so the two chips' timers agree on width.
- Setting bit 31 of the RX consumer write is the timer-arm write. (inferred, from
  the driver's name for the bit) Whether the chip reads the bit back is not
  established.
- Bytes that do not yet fill an entry's four data slots wait for the fourth byte
  or for the receive timer to expire. (inferred, from a driver comment about bytes
  held for four or the timer; the comment is the only source)

## Port shadow

The shadow register is the port's modem and line status word. The public driver
gives these fields. All are inferred.

| Bits | Meaning |
|---|---|
| 0 | data ready |
| 1 | overrun error |
| 2 | parity error |
| 3 | framing error |
| 4 | break |
| 5 | transmit holding register empty |
| 6 | transmit shift register empty |
| 7 | error character in the receive FIFO |
| 16 | clear-to-send changed (DCTS) |
| 19 | carrier-detect changed (DDCD) |
| 20 | clear-to-send level (CTS) |
| 23 | carrier-detect level (DCD) |
| 24 | DTR |
| 25 | RTS |
| 26 | OUT1 |
| 27 | OUT2 |
| 28 | loopback |

The driver gives each position (`ioc4_serial.c` lines 219-235).

## Modem-valid receive slots

Whether the chip sets the modem-valid flag on every externally received byte is
unknown. No source settles it. The public driver checks carrier-detect changes on
each modem-valid slot, so it expects the DCD bit in such a slot to reflect the
current line. (The driver's expectation is inferred; the flag's behaviour is
unknown.)

## Not on this page

- Reset values of the ring and timer registers: unknown. The chip page explains
  why no software source settles them.
- The receive status values a loopback test reads back: not imported. No
  hardware read or published firmware citation holds them.
- Driver set-up values such as the receive threshold, the timer period and the
  ring sizes a build chooses: these are driver policy, not chip behaviour.
