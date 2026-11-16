# IP35 node board: which DIMM pair is populated, and what the PROM and the kernel do when pair 0 is empty

Question. On an Origin 300 or Origin 350 node board with one DIMM pair fitted, do the published manuals and the shipped
software put that pair in the low banks (0 and 1) or the high banks (2 and 3)? What does the boot PROM do when bank 0 is
empty, how does it tell the operating system, and which software copes?

Grades are those of the repository: **established** (whole routine or page read), **inferred** (reasoned), **unknown**.
Image addresses are for the CPU PROM segment `ip35prom` of SGI Version 6.210 (load address 0xc00000001fc00000, unpacked
segment sha256 `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`) and for the BaseIO monitor ELF the
same container carries (gzip stream at container offset 0x8cbb0, linked at 0xc000000013000000, unpacked sha256
`f903b3ce33b86c286f168ba43395f36a0073c24b1d4e703adce240f683b8c2d7`). The write sequence of the bank configuration word
is in [prom-md-config.md](prom-md-config.md); the word's fields and the probe are in
[ip35-prom-memory-bank-config.md](../../questions/ip35-prom-memory-bank-config.md).

## Answer

1. **Manuals: one pair means banks 0 and 1. Established (text read).** SGI Origin 300 User's Guide, 007-4365-001, printed
   p. 60 ("Installing DIMMS"), note: if only one pair of DIMMs is installed, banks 0 and 1 must be populated. The same
   guide, p. 10 and p. 57 (Figures 1-5 and 4-9), and 007-4365-002 p. 11 (Figure 1-5) define pair 0 as banks 0 and 1 and
   pair 1 as banks 2 and 3. 007-4365-002 p. 56 ("Memory") tells the owner to fill slots 1 and 3 first, then slots 2 and 4.
   The text of Figure 4-9 of -001 lists the four sockets in the order bank 0, bank 2, bank 1, bank 3; if that is
   the physical order, slots 1 and 3 are banks 0 and 1 (inferred: -002's slot figure carries no bank labels, and the two
   guides are assumed to number slots alike). Neither guide says what the factory ships; they state a rule for the owner.
2. **The one printed counter-example is not decisive. Established that the text exists, inferred that it does not
   contradict item 1.** The `eeprom` example in 007-4365-001 (printed pp. 75 to 76, appendix B) prints "DIMM 0 - no hardware
   detected", "DIMM 1 - no hardware detected" and SPD dumps for DIMM 2 and DIMM 3. If the controller's DIMM number were the
   bank number, that system would have pair 1 only. Which bank a controller DIMM number names was not found (see
   unknown 1), and the example comes from a four-processor system, not a census.
3. **Empty bank 0 is legal and the PROM repairs it with the bank-select field. Established.** After the scan and probes
   the PROM decodes the eight software banks from the configuration word. If bank 0 is not enabled, or its number is in the
   disabled-bank string, it takes the first of banks 1, 2, 3 that is enabled and not disabled and stores that bank number S
   in bits 33:32 of the word (selectors 1, 2 and 3: calls at 0x1fc65b38, 0x1fc65b4c and 0x1fc65aa4 of the routine at
   0x1fc6587c; the objdump cross-check of 0x1fc659c0 to 0x1fc65b90 agrees). The writer 0x1fc56d94 first prints
   `*** Swapping bank 0 with bank %d on module %M (nasid %d)` and
   `*** All other banks on the node are remapped as well.` (strings at segment offsets 0x7b3c8 and 0x7b401). With no usable
   bank it prints `ERROR: no usable memory present for low address` and `Freezing node` (0x7b700, 0x7b738; print calls at
   0x1fc65acc and 0x1fc65aec; the routine returns -1). When bank 0 is good no store is made and S stays 0. A pair-1-only board therefore gets
   S = 2 (bank 2 is the first enabled one); a board with banks 0 and 1 fitted gets S = 0 and no message.
4. **S reaches the operating system as KLCONFIG memory-component field +58. Established (whole routine read).** The
   KLCONFIG builder at 0x1fc546d0 to 0x1fc547f8 loads the word at node alias +0x780008 (local form), stores bits 33:32 at
   +58 (`sh t3,58(s0)` at 0x1fc54788), then for each of eight banks tests enable bit 8l+(i&1) of lane l = (i>>1)&3, takes
   the 4-bit size code at 8l+4 and stores `0x2000000 << code >> 20` megabytes at +60+2i, summing the sizes at +56. So the
   bank-size array is in the order of the word's lanes, with S recorded beside it and not applied to it. The IP35
   kernel (kudzu `formats/klconfig/README.md`, "Memory sizing") XORs the slot number with +58 when it reads
   the array, so slot s gets the size of entry s XOR S: with S = 2 and sizes {0,0,256,256,...} slot 0 and 1 get 256 MB.
5. **The monitor prints the same mapping. Established.** The BaseIO monitor routine at 0xc0000000130a1d8c (file offset
   0xa1d8c) prints each bank as `Bank %d, %d MBytes` and, when S is nonzero (or for bank 0), ` <-- (Software Bank %d)` with the
   value bank XOR the halfword at +58 (strings at monitor offsets 0xf5550 and 0xf5578). The size is `0x20 << digit`
   megabytes from a digit string, so the display matches the builder's 32 MB << code.
6. **Who ignores S. Established for OpenBSD.** OpenBSD's `kl_add_memory_ip35` (sys/arch/sgi/sgi/sginode.c, in the
   `sgi-is-alive-at-7.9` branch of the public tree) takes only the size array and the entry count. Entry i is registered at
   node offset i GB; the `membnk_dimm_select` field is read only for a debug print. With S = 2 and sizes {0,0,256,256} it
   therefore claims software banks 2 and 3 (2 GB to 2.25 GB), which the swapped decode leaves empty, and the kernel faults
   in its first allocation. With pair 0 populated S is 0 and the two views agree. (Also, the loop's `continue` for a bank
   of 64 MB or less skips the 1 GB advance of the base; irrelevant for 256 MB and larger banks.)
7. **IRIX copes. Established** for the 6.5.30 IP35 kernel (kudzu `software/kernel/ip35-memory-error-address-decode.md`):
   the slot-size routine always XORs by +58, and the memory-error decoders XOR address bits 31:30 by bits 33:32 of the
   word. The public 6.5.7 source defines the field as the bank-to-physical-address mapping and halves it in an IP27 memory-size
   routine (the NVRAM condition on that use is from the 6.5.30 IP27 kernel, see the kudzu page); the 6.5.7 tree was not
   searched for IP35 code, so nothing is claimed about it.

## Conclusion

The only rule stated in print is pair 0 (banks 0 and 1) for a single pair (-001 p. 60), with slots 1 and 3 filled first
(-002 p. 56). The PROM, the monitor and IRIX all handle the other case (pair 1 only, S = 2) transparently, so shipped
software does not decide the factory fill; it only shows that both fills boot on IRIX. A default of pair 0 is consistent
with every published rule and is the only fill a guest that ignores the bank-select field can use. A default of pair 1
rests on the `eeprom` example (item 2), which depends on an unfound DIMM-number-to-bank mapping.

## Unknown

1. Which bank a controller DIMM number (the L1's `DIMM 0` to `DIMM 3` records, selected through a multiplexer) names. The L1
   package 1 name table lists the four routes in the order DIMM 0, DIMM 2, DIMM 1, DIMM 3; the PROM scan names a bank by
   lane (bank >> 1) and position in the lane (bank & 1) and passes both to its DIMM read at 0x1fc309cc. Route: follow
   that read to the multiplexer select and match it to the L1 table.
2. What the factory fitted. No source read states it. The Origin 350 owner's guide is not held, so its fill rule is not read.
3. Whether the `SwapBank` promlog variable (monitor strings at 0xf0dc0; the monitor writes a single digit through the
   routines at 0xc0000000130af918 and 0xc0000000130ae68c when memory is disabled) is read by the CPU PROM: no
   reference to its string was found in the CPU PROM segment.
