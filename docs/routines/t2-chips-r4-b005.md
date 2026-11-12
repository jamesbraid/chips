# Tier-2 reading, round 4, batch 5 of chips: routine role statements

Each entry names a routine in the IP27 boot-set object `pcibr.o` and its address. The statements come only from the rendered instruction facts: loads and stores at fixed offsets from `a0`, compare chains, calls and return shapes. Every role here is inferred. The routine names suggest bridge register accessors, but the facts do not show which registers they touch, so the register meanings stay open.

- `pcireg_arbitration_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11698
  **Inferred.** It sends a zero `a0` to a panic block at 0x117f4 (branch at 0x116a0) and loads a halfword at `a0+0x72` at 0x116bc. It dispatches on that halfword through compares at 0x116c4 to 0x116e8, with -1 going to the panic block, and reads and writes a 32-bit word at 0x11758 and 0x11764. The name suggests setting bits in an arbitration register; the mask and the register address are not in these facts.

- `pcireg_arbitration_bit_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11808
  **Inferred.** It sends a zero `a0` to a panic block at 0x11970 (branch at 0x11810) and loads the same halfword at `a0+0x72` at 0x1182c, then dispatches on it. It reads a 32-bit word at 0x118c8 and stores the changed word at 0x118d8, the read-modify-write shape of a bit clear. The name suggests clearing bits in the same arbitration register as its set partner at 0x11698; the facts do not confirm the mask.

- `pcireg_nic_addr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11984
  **Inferred.** It sends a zero `a0` to a panic block at 0x11ac8 (branch at 0x1198c) and reads the halfword at `a0+0x72` at 0x119a8, the doubleword at `a0+8` and a word at `a0+4`. It makes no stores, and its return at 0x119e0 yields 0 or a value the facts do not resolve. The name suggests a NIC address getter, but the source of the returned value is unknown here.

- `pcireg_parity_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11adc
  **Inferred.** It sends a zero `a0` to a panic block at 0x11c24 (branch at 0x11ae4), reads the halfword at `a0+0x72` at 0x11b00, and loads two doubleword values from addresses the facts do not resolve at 0x11b94 and 0x11bb0. Two panic calls at 0x11c1c and 0x11c28 pass a fourth argument of -1 or 0xd002 on one path. The return at 0x11b38 yields 0 or an unknown value, so the parity error meaning is not settled.

- `pcireg_timeout_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11c38
  **Inferred.** It sends a zero `a0` to a panic block at 0x11d88 (branch at 0x11c40), reads the halfword at `a0+0x72` at 0x11c5c, and reads two words at 0x11ca0 and 0x11cfc. It does not store, and it returns 0 or an unknown value at 0x11c94. The name suggests a timeout getter; the facts leave the field and the return value open.

- `pcireg_timeout_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11d9c
  **Inferred.** It sends a zero `a0` to a panic block at 0x11ee0 (branch at 0x11da4), reads the halfword at `a0+0x72` at 0x11dc0 and a word at `a0+4` at 0x11e00, and then stores a 32-bit word at 0x11e60. It returns 3 or an unknown value, or reaches the panic at 0x11ee4 with the .rodata string at +12520. The name suggests a timeout setter; the value written and the register are not shown by the facts.

- `pcireg_timeout_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11ef4
  **Inferred.** It sends a zero `a0` to a panic block at 0x12054 (branch at 0x11efc) and reads the halfword at `a0+0x72` at 0x11f18 and a word at `a0+4` at 0x11f5c. It reads a word at 0x11fb8 and stores a modified word at 0x11fc4, a read-modify-write set. The return at 0x11f50 yields an unknown value or the panic result, and the bit mask is not in these facts.

- `pcireg_timeout_bit_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12068
  **Inferred.** It sends a zero `a0` to a panic block at 0x121d0 (branch at 0x12070) and reads the halfword at `a0+0x72` at 0x1208c and a word at `a0+4` at 0x120cc. It reads a word at 0x12128 and stores the changed word at 0x12138, the read-modify-write shape of a bit clear. The return at 0x120c0 yields 3, an unknown value, or the panic result.

- `pcireg_type1_cntr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x121e4
  **Inferred.** It sends a zero `a0` to a panic block at 0x12338 (branch at 0x121ec) and reads the halfword at `a0+0x72` at 0x12208 and a word at `a0+4` at 0x12250. It reads one more word at 0x122ac and two doublewords at 0x122d4 and 0x122f0, and returns 0 or an unknown value at 0x12244. The name suggests a read of a type 1 configuration counter; the facts do not show what the counter counts.

- `pcireg_type1_cntr_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1234c
  **Inferred.** It sends a zero `a0` to a panic block at 0x12490 (branch at 0x12354) and reads the halfword at `a0+0x72` at 0x12370 and a word at `a0+4` at 0x123b0. It stores a 32-bit word at 0x12410 and returns 3, an unknown value, or the panic result at 0x123a4. The name suggests a write to the same type 1 counter that its getter at 0x121e4 reads; the stored value is not shown.

- `pcireg_pci_bus_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x124a4
  **Inferred.** It sends a zero `a0` to a panic block at 0x12600 (branch at 0x124ac) and reads the halfword at `a0+0x72` at 0x124c8, the doubleword at `a0+8` at 0x124d4 and the word at `a0+4` at 0x1250c. It makes no stores and returns 0 or an unknown value at 0x12500. The name suggests a PCI bus address getter; the facts do not show the address it returns.

- `pcireg_pci_bus_addr_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12614
  **Inferred.** It sends a zero `a0` to a panic block at 0x12780 (branch at 0x1261c) and reads the halfword at `a0+0x72` at 0x12638 and the word at `a0+4` at 0x12680. It loads a doubleword from an address the facts do not resolve at 0x12710 and returns 0 or an unknown value at 0x12674. The name suggests a getter for an address of the bus address register, but the facts do not settle which address.

- `pcireg_intr_status_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12794
  **Inferred.** It sends a zero `a0` to a panic block at 0x128e8 (branch at 0x1279c) and reads the halfword at `a0+0x72` at 0x127b8 and the word at `a0+4` at 0x12800. It reads one more word at 0x1285c and two doublewords at 0x12884 and 0x128a0, and returns 0 or an unknown value at 0x127f4. The name suggests a status getter for interrupts; the facts do not show which status bits it reads.

- `pcireg_intr_enable_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x128fc
  **Inferred.** It sends a zero `a0` to a panic block at 0x12a4c (branch at 0x12904) and reads the halfword at `a0+0x72` at 0x12920 and the word at `a0+4` at 0x12964. It reads a word at 0x129c0 and returns 0 or an unknown value at 0x12958. The name suggests a getter for the interrupt enable register; the facts do not show the register address.

- `pcireg_intr_enable_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12a60
  **Inferred.** It sends a zero `a0` to a panic block at 0x12ba4 (branch at 0x12a68) and reads the halfword at `a0+0x72` at 0x12a84 and the word at `a0+4` at 0x12ac4. It stores a 32-bit word at 0x12b24 and returns 3, an unknown value, or the panic result at 0x12ab8. The name suggests a setter for the interrupt enable register that its getter at 0x128fc reads; the value written is not in the facts.

- `pcireg_intr_enable_bit_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12bb8
  **Inferred.** It sends a zero `a0` to a panic block at 0x12d24 (branch at 0x12bc0) and reads the halfword at `a0+0x72` at 0x12bdc and the word at `a0+4` at 0x12c20. It reads a word at 0x12c7c and stores the changed word at 0x12c8c, the read-modify-write shape of a bit clear on the interrupt enable register. The mask is not shown by the facts, and the return at 0x12c14 is an unknown value or the panic result.

- `pcireg_intr_enable_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12d38
  **Inferred.** It sends a zero `a0` to a panic block at 0x12e98 (branch at 0x12d40) and reads the halfword at `a0+0x72` at 0x12d5c and the word at `a0+4` at 0x12da0. It reads a word at 0x12dfc and stores the changed word at 0x12e08, the read-modify-write shape of a bit set on the interrupt enable register. The return at 0x12d94 is an unknown value or the panic result, and the mask is not in the facts.

- `pcireg_intr_reset_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12eac
  **Inferred.** It sends a zero `a0` to a panic block at 0x12ff0 (branch at 0x12eb4) and reads the halfword at `a0+0x72` at 0x12ed0 and the word at `a0+4` at 0x12f10. It stores a 32-bit word at 0x12f70 and returns 3, an unknown value, or the panic result at 0x12f04. The name suggests a write to an interrupt reset register; the stored value and the register are not shown.

- `pcireg_intr_reset_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x13004
  **Inferred.** It sends a zero `a0` to a panic block at 0x13164 (branch at 0x1300c) and reads the halfword at `a0+0x72` at 0x13028 and the word at `a0+4` at 0x1306c. It reads a word at 0x130c8 and stores the changed word at 0x130d4, a read-modify-write set. The return at 0x13060 is an unknown value or the panic result, and the bit mask is open.

- `pcireg_intr_mode_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x13178
  **Inferred.** It sends a zero `a0` to a panic block at 0x132cc (branch at 0x13180) and reads the halfword at `a0+0x72` at 0x1319c and the word at `a0+4` at 0x131e4. It reads a word at 0x13240 and returns 0 or an unknown value at 0x131d8. The name suggests a getter for an interrupt mode setting; the facts do not show which mode field it extracts.

- `pcireg_intr_mode_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x132e0
  **Inferred.** It sends a zero `a0` to a panic block at 0x13428 (branch at 0x132e8) and reads the halfword at `a0+0x72` at 0x13304 and the word at `a0+4` at 0x13348. It stores a 32-bit word at 0x133a8 and returns an unknown value or the panic result at 0x1333c. The name suggests a setter for the interrupt mode register that its getter at 0x13178 reads; the value written is not in the facts.

- `pcireg_intr_mode_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1343c
  **Inferred.** It sends a zero `a0` to a panic block at 0x1359c (branch at 0x13444) and reads the halfword at `a0+0x72` at 0x13460 and the word at `a0+4` at 0x134a4. It reads a word at 0x13500 and stores the changed word at 0x1350c, a read-modify-write set. The return at 0x13498 is an unknown value or the panic result, and the mask is not in these facts.

- `pcireg_intr_mode_bit_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x135b0
  **Inferred.** It sends a zero `a0` to a panic block at 0x13718 (branch at 0x135b8) and reads the halfword at `a0+0x72` at 0x135d4 and the word at `a0+4` at 0x13614. It reads a word at 0x13670 and stores the changed word at 0x13680, a read-modify-write clear. It returns 3, an unknown value, or the panic result at 0x13608.

- `pcireg_intr_device_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1372c
  **Inferred.** It sends a zero `a0` to a panic block at 0x13880 (branch at 0x13734) and reads the halfword at `a0+0x72` at 0x13750 and the word at `a0+4` at 0x13798. It reads a word at 0x137f4 and returns 0 or an unknown value at 0x1378c. The name suggests a getter for an interrupt device field; the facts do not show which field.

- `pcireg_intr_device_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x13894
  **Inferred.** It sends a zero `a0` to a panic block at 0x139dc (branch at 0x1389c) and reads the halfword at `a0+0x72` at 0x138b8 and the word at `a0+4` at 0x138fc. It stores a 32-bit word at 0x1395c and returns an unknown value or the panic result at 0x138f0. The name suggests a setter for the interrupt device register that its getter at 0x1372c reads; the value written is not shown.
