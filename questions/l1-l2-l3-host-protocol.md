# System controllers: open questions on the host protocol

Questions left by [devices/l1/host-link.md](../devices/l1/host-link.md), [devices/l2/README.md](../devices/l2/README.md)
and [devices/l3/README.md](../devices/l3/README.md).

1. **Where the UART sits on SHub 2.** *[route: missing source]* The SHub 1 PROM reaches it at junk-bus offset
   `0x7_fed4_0000`. The Linux headers name only the SHub 2 LED registers (`0xf000_0000`). Next: a SHub 2 PROM
   (`shub2snprom`, held by no archive here) or the SHub 2 junk-bus map in an SGI manual.
2. **Hardware FIFO depth of the junk-bus UART.** *[route: hardware residue]* Linux assumes 240 characters of budget, the
   IRIX object seems to assume 16, neither measured. Next: the part's datasheet (the 16550 variant is not named in
   any source read) or a read of the UART's identification registers.
3. **No-argument requests.** *[route: software now]* Linux v2.5.0's builder omits the argument-count byte when a request
   has no arguments, and so does the SN2 PROM builder (`0xffa81f40`, read in Ghidra); the open part is the receivers. The sysco ColdFire parser reads the count only for frames of 8 bytes or more.
   Next: the SN1 PROM request builder for a no-argument code (for example `0x0003`) and the ARM L1's length check.
4. **Event frame versus request body.** *[route: software now]* The SN2 kernel's event record has a four-byte code and
   argument count at offset 8, the same layout the Bedrock-side Linux v2.5.0 `sc_event` reads; a request has a two-byte code and count at offset 6. Next: where the PROM turns an L1
   event frame into the record it hands the kernel (the `0x1007` event-subchannel request and the receive path of the
   SAL `IROUTER_OP`), once a SAL runtime beyond the boot path is read.
5. **Routing of L2-addressed traffic from a node.** *[route: software now]* Partly answered: the PROM's L2-addressed traffic is
   the task-3 texts `version`, `p <partition> rst` and `p <partition> pwr d` to `0x1ffff003`, and a ColdFire `O` L1 with no L2
   answers a routing error (status 8). What remains is user space's use of the kernel's controller pipe and the C-brick (`5`)
   L1's handling of the same word. See sysco `software/firmware/l2/altix-l2-model.md`.
6. **L2 console baud.** *[route: software now]* 115 kbaud in the guide, `0x9600` in the L2 boot stage's board block.
   Next: the L2 kernel's serial driver divisor setup and the `l2term` console program.
7. **Altix 4700 controller traffic on NUMAlink 4.** *[route: missing source]* The guide says enclosures talk over
   NUMAlink with low-voltage differential signalling. Next: an Altix 4700 hardware guide that names the controller pair
   in the cable and an L1 image for that product, neither held.
8. **Whether address type 2 (L3) was ever a distinct controller.** *[route: missing source]* Only the Linux v2.5.0
   header names it. Next: an SGIconsole or L3 software source that builds such a target.
9. **Subchannel mapping of the SN2 SAL.** *[route: software now]* Whether the number `SAL_IROUTER_OPEN` returns is the
   link subchannel of the header byte. Next: the SN2 PROM's IROUTER handler in the SAL runtime.
