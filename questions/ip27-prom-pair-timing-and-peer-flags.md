# IP27 PROM: pair timing, the port-reset restart and the peer exception flag

Open points left by [platforms/ip27/prom-multiprocessor-start.md](../platforms/ip27/prom-multiprocessor-start.md).

1. **How long is the pair liveness poll in real time, and how far apart do slices A and B leave reset?** *[route: hardware residue]*
   The PROM reads the other slice's compare register 200,000 times. The published manual says only that the PROM times out;
   nothing held gives a read latency or a release skew. Next: Hub documentation not held, or a timed read on a physical node
   board (needs the owner's agreement first).
2. **Does the Hub port reset the PROM triggers at reset restart both slices?** *[route: missing source]* The code stores a
   constant at PI+0x420 and writes 0x81 to NI_PORT_RESET and depends on the constant surviving. Next: a Hub manual page for
   NI_PORT_RESET.
3. **What sets bit 30 of a peer entry's flags in the discovery table, the flag that makes the master print "took an exception"?**
   *[route: software now]* Next: read the writers of that field in the discovery routines at `0x1fc47174` and `0x1fc470a0`.
4. **What do bits 22, 51 and 53 of NI_SCRATCH_REG1 mean to the peer wait?** *[route: software now]* Next: the IRIX kernel's use of
   the same register.
5. **Does the PI_RT_LOCAL_CTRL GCLK path exist on a node board?** *[route: missing source]* Only field names are held. Next: the
   Hub register manual.
6. The inflated monitor image (gzip stream at payload offset 0x75e00) was not read; whether it touches the slice-private
   or flipped low memory is unknown.
