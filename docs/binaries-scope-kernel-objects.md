# Excluded kernel objects of the IP27 build

Each entry classifies one shipped object of the IP27 kernel build that the scope list removes from the function table
by a role rule (network, process core, device driver). It says what the object is, which chip it drives if any, and
which rule removes its routines. Object sizes and routine counts come from the file's symbol table; the routine
names, data symbols and undefined imports are read from the file under `root/`.

Labels: every entry here is inferred. It classifies from the symbol table and the imports. No routine body was read in
full. "Excluded" means the rule named in the entry takes the object's routines out of the function table; the rule texts
are in the [function scope section](inventory/README.md#function-scope). Objects with no routine rows say so.

## Network, STREAMS and cluster objects (scope rule 2)

- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(if.o)` (inferred): the generic network interface layer, a 49380-byte member with 47
  routines. `ifioctl` (2672 bytes) is the largest, and `if_detach`, `ifunit` and `if_create_linkaddr` keep the interface
  list and the link-level addresses. It imports the hardware-graph calls `hwgraph_path_add` and `hwgraph_edge_add`. No
  chip is driven here; the drivers below it are the chips. Rule 2 excludes the 47 routines.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(if_loop.o)` (inferred): the software loopback interface, three routines in an
  8740-byte member: `looutput` (756 bytes) sends a packet back into the receive path, `loioctl` configures the interface
  and `loattach` registers it. It moves mbufs with `m_get` and `m_datacopy`, and drives no hardware.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(multi.o)` (inferred): the link-layer multicast address list, nine routines in an
  8676-byte member. `mfadd` and `mfdel` add and remove an address, `mflookup` and `mfmatch` search the list, and the member
  allocates its entries from the kernel heap. It touches no chip.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(netisr.o)` (inferred): the network software interrupt threads, 15 routines in an
  18292-byte member. `netisr_init` starts the threads, `network_input` queues an inbound packet, and `netproc` and `sockd`
  are the thread bodies. It creates its threads with `sthread_create` and reads the processor count from `maxcpus`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(raw.o)` (inferred): the raw link-level socket, 21 routines in a 24916-byte member.
  `rawioctl` (2164 bytes), `rawopen` and `rawclose` serve the socket, and `snoop_input2` and `drain_input` feed the
  snoop path. It drives no chip.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(raw_cb.o)` (inferred): the control-block list for raw sockets, eight routines in an
  11028-byte member. `raw_attach`, `raw_detach` and `raw_bind` create and bind a block, `rawcb_hold` and `rawcb_rele`
  count its references, and `raw_pcbpurgeif` drops blocks that belong to a removed interface.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(raw_proto.o)` (inferred): the protocol switch entry for the raw domain. The member
  holds no routine rows. Its data symbols `rawprotosw` (192 bytes) and `rawdomain` (80 bytes) are the table the socket
  layer indexes, and its imports are the raw protocol routines `raw_init`, `raw_output` and `raw_usrreq`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(raw_usrreq.o)` (inferred): the request dispatch for raw sockets, five routines in a
  13172-byte member. `raw_usrreq` (916 bytes) switches on the request type, `raw_protocol_input` (792 bytes) receives
  packets, and `raw_input` and `raw_ctlinput` handle delivery and control messages.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(radix.o)` (inferred): the radix tree that holds routes and netmasks, 19 routines in
  a 23828-byte member. `rn_addroute` and `rn_delete` (1068 and 1316 bytes) insert and remove leaves, `rn_match` (808
  bytes) does the longest-prefix lookup, and `rn_addmask` (916 bytes) keeps the netmask tree.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(route.o)` (inferred): the routing table code, 22 routines in a 26308-byte member.
  `rtrequest1` (1052 bytes) adds, changes and deletes routes, `rtalloc1` (776 bytes) finds one, `rtinit` and `rtredirect`
  handle interface and redirect updates, and `rtioctl` is the control entry. No chip is driven.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(rtsock.o)` (inferred): the routing socket, which sends route changes to user
  programs. Sixteen routines in a 27988-byte member: `route_output` (2368 bytes) takes route requests, `sysctl_iflist`
  (1160 bytes) reports the interface list, and `rt_msg1`, `rt_msg2` and `rt_newaddrmsg` build the replies.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(slcompress.o)` (inferred): Van Jacobson TCP and IP header compression for serial
  links, four routines in a 10916-byte member. `vj_compress` (2500 bytes) and `vj_uncompress` (1364 bytes) do the work,
  and `vj_comp_init` and `vj_uncomp_init` set up their state. It drives no chip.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(compat.o)` (inferred): a one-routine compatibility member, `schednetisr` in a
  4740-byte object. It schedules the network software interrupt, and its only import of note is `network_input`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(rsvp.o)` (inferred): RSVP resource reservation, 39 routines in a 33988-byte member.
  `ps_init` (848 bytes) and `ps_output` (720 bytes) run the packet scheduler, `ps_tick_maint` maintains its timers, and
  `rsvp_addflow` (488 bytes) adds a reserved flow. It calls the packet queues in `bsd.a(rsvp_qo.o)`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(rsvp_qo.o)` (inferred): the packet queues under RSVP, five routines in a 7268-byte
  member. `psqo_init`, `psqo_alloc_queue` and `psqo_free_queue` manage the queues, and `psqo_enq_pkt` and
  `psqo_get_next_pkt` add and take packets.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(if_is.o)` (inferred): an interface-striping driver, 41 routines in a 47284-byte
  member. Its `is_*` routines, such as `is_output` (1576 bytes), `is_reorder_drain` (1352 bytes) and
  `is_input_reorder_entry`, spread output over several links and put input back in order with the stripe vector. It
  attaches to the interface list with `if_attach` and `if_detach`. No chip is driven directly.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(igmp.o)` (inferred): IGMP group membership, 14 routines in an 18516-byte member.
  `igmp_input` (1256 bytes) handles membership reports, `igmp_sendpkt` sends them, and the `igmp_update_host_*` routines
  keep the host's group state in a hash table.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(if_ether.o)` (inferred): ARP, 27 routines in a 35844-byte member. `in_arpinput`
  (1596 bytes) and `arpresolve` (1560 bytes) answer and resolve address requests, `arptimer` (836 bytes) ages entries,
  and `arpioctl` is the control entry. It calls the routing tree through `rtalloc1` and the interface lookup
  `ifa_ifwithnet`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(in.o)` (inferred): IPv4 interface addressing, 73 routines in a 52404-byte member.
  `in_control` (3452 bytes) is the address ioctl, `in_ifinit` (964 bytes) sets an interface address, and `inet_addr` and
  `inet_ntop` convert text. It also carries the generic tunnel attach `gifattach` and the IPv6 start-up `in6_init`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(in_pcb.o)` (inferred): the protocol control blocks for IPv4 sockets, 38 routines in a
  46724-byte member. `in_pcblookupx` (3580 bytes) finds the block for an arriving packet, `in_pcballoc` and `in_pcbbind`
  create and bind one, and `udp_full_assign` and `tcp_full_assign` set the full endpoint.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(in_proto.o)` (inferred): the IPv4 protocol switch, a member with no routine rows.
  Its data symbols `inetsw` (1152 bytes), `inetdomain` (80 bytes) and `in_gif_protosw` (96 bytes) are the table that
  maps protocol numbers to the TCP, UDP, ICMP and IGMP entry points.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(ip_icmp.o)` (inferred): ICMP, nine routines in a 17156-byte member. `icmp_input`
  (1472 bytes) handles inbound messages, `icmp_reflect` (944 bytes) builds replies, and `icmp_send` sends errors. It
  uses the redirect routine `rtredirect` from the routing code.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(ip_input.o)` (inferred): the IPv4 input path, 21 routines in a 34516-byte member.
  `ip_input` (2740 bytes) validates each packet, `ip_reass` and `ip_reass_strict` reassemble fragments, and `ip_forward`
  and `ip_dooptions` route and process options.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(ip_output.o)` (inferred): the IPv4 output path, nine routines in a 32292-byte
  member. `ip_output` is the transmit entry, `ip_setmoptions` and `ip_getmoptions` (1524 and 460 bytes) manage multicast
  options, and `ip_ctloutput` (1244 bytes) is the socket option entry.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(raw_ip.o)` (inferred): raw IP sockets, three routines in an 11204-byte member:
  `rip_input`, `rip_output` (516 bytes) and `rip_ctloutput` (736 bytes). It imports `ip_mrouter_set` and `ip_mrouter_get`
  for multicast control.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(tcp_debug.o)` (inferred): the TCP trace hook, one routine `tcp_trace` in an
  11092-byte member. It records state transitions for the debug printout and imports `printf`, `iptime` and `bzero`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(tcp_input.o)` (inferred): TCP input processing, 13 routines in a 43972-byte member.
  `tcp_input_private` (10032 bytes) is the segment handler, `tcp_input` (1164 bytes) is its entry, `tcp_dooptions`
  parses options, and `tcp_mss` (1556 bytes) sets the segment size. It calls `in_pcblookupx` for the connection.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(tcp_output.o)` (inferred): TCP output, two routines in a 16100-byte member. `tcp_output`
  builds and sends segments, and `tcp_setpersist` arms the persist timer. It imports the checksum routine `in_cksum` and
  the IPv6 output routine `tcp6_output`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(tcp_subr.o)` (inferred): TCP support routines, 29 routines in a 30388-byte member.
  `tcp_close` (1168 bytes), `tcp_respond` (876 bytes) and `tcp_template` (608 bytes) close a connection and build reply
  packets, and the `sack_sndupdate` routine (676 bytes) keeps the selective-acknowledgement list. `iss_hash` derives the
  initial sequence number from an MD5 digest.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(tcp_timer.o)` (inferred): the TCP timers, five routines in a 16244-byte member.
  `tcp_timers` (1392 bytes) runs the per-connection timers, `tcp_slowtimo` and `tcp_fasttimo` are the periodic entries,
  and `tcp_zaptw` (684 bytes) clears TIME_WAIT blocks.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(tcp_usrreq.o)` (inferred): the TCP socket requests, five routines in a 15732-byte
  member. `tcp_usrreq`, `tcp_attach` and `tcp_disconnect` are the socket entry points, and `tcp_ctloutput` (624 bytes)
  handles socket options.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(udp_usrreq.o)` (inferred): UDP, eight routines in a 23620-byte member. `udp_input`
  (2724 bytes) demultiplexes datagrams, `udp_usrreq` (2088 bytes) is the socket entry, and `udp_output` (1296 bytes)
  sends them. Its import `nfs_input` shows that NFS traffic is passed up from here.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(rsvp_input.o)` (inferred): the RSVP input path, two routines in an 8852-byte member:
  `rsvp_input` (620 bytes) receives reservation messages and `socket_send` hands them to the socket layer.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(offload.o)` (inferred): fragment vectors for checksum and segmentation offload, ten
  routines in a 14836-byte member. `build_frag_vec` (1664 bytes) builds the vector and `frag_vec_coalesce_long_chain`
  merges long chains. `tcp_max_tso_len` (276 bytes) is the segment-size routine of the same path. The member imports no
  chip routine.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(bsdinit.o)` (inferred): network start-up, five routines in an 8724-byte member.
  `bsd_init` calls the protocol and interface initialisers, `sethostid` and `gethostid` (116 and 72 bytes) read and set the
  host identifier, and `phost_gethostid` (12 bytes) is a second routine of the same kind.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(uipc_domain.o)` (inferred): the protocol domain table, 12 routines in a 13332-byte
  member. `domaininit` installs the domains, `pffindproto` and `pffindtype` search the protocol switch, and
  `ifdown_pfctlinput` tells the protocols that an interface went down.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(uipc_socket.o)` (inferred): the socket core, 21 routines in a 31764-byte member.
  `soreceive` (3040 bytes) and `sosend` (1808 bytes) move the data, `soclose` (976 bytes) closes a socket, and
  `sogetopt` and `sosetopt` handle options. It takes locks with `mutex_spinlock`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(uipc_socket2.o)` (inferred): socket buffers and wakeups, 27 routines in a 28676-byte
  member. `sbappendaddr` (2100 bytes), `sbappendrights` and `sbappend` add to the receive buffer, `sonewconn` (908 bytes)
  makes a socket for a new connection, and `soisconnected` and related routines change its state.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(uipc_syscalls.o)` (inferred): the socket system calls, 33 routines in a 26820-byte
  member. `socket`, `bind`, `listen` and `accept` are the call entries, `recvit` (1132 bytes) and `sendit` (636 bytes)
  carry the data, and the `xpg4_recvmsg` and `xpg5_recvmsg` variants serve the newer interfaces.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(uipc_socket1.o)` (inferred): socket control, nine routines in a 17252-byte member.
  `soioctl` (952 bytes) is the socket ioctl, `uipc_connect` (432 bytes) and `uipc_getpeername` and `uipc_getsockname`
  answer the address calls, and `sopoll` (428 bytes) supports poll.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(bitswap.o)` (inferred): one routine, `bitswapcopy`, in a 3940-byte member. The loop
  reads each source byte, uses it as an index into a 256-entry table whose pointer is loaded from `gp-30720`, and stores the
  table entry at the destination. The table's contents were not read, so the bit order it applies is the one the routine's
  name gives. The member has no imports.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(ether.o)` (inferred): the common Ethernet layer, 16 routines in a 21348-byte member.
  `ether_output` (1140 bytes) and `ether_input` (1136 bytes) carry frames, `ether_ioctl` (1028 bytes) configures the
  interface, and `ether_selfsnoop` copies frames to packet capture. It attaches interfaces with `if_attach`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(in_cksum.o)` (inferred): the Internet checksum, one routine `in_cksum` in a 4692-byte
  member, with `in_cksum_sub` for the partial sum. It is a software checksum and touches no chip.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(lance.o)` (inferred): a driver for the LANCE Ethernet controller, three routines in
  a 5828-byte member. `lance_init` starts the chip, `lance_ioctl` (452 bytes) handles configuration, and `laf_hash` (128
  bytes) computes the address filter bit. It is a network-interface driver outside the IOC3 and IOC4 set, so rule 2
  removes it.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(mclance.o)` (inferred): the multicast filter for the LANCE, three routines in a
  4724-byte member: `AddMulti`, `DeleteMulti` and `CalcIndex` maintain the filter table. It imports the multicast list
  calls `mfadd`, `mfdel` and `mfmatch` from `bsd.a(multi.o)`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(remque.o)` (inferred): two queue primitives, `_insque` and `_remque`, in a 3716-byte
  member. They splice an element into or out of a doubly linked list and do not touch a chip.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(hashing.o)` (inferred): the generic hash tables, 14 routines in a 14772-byte member.
  `hash_enum_bestmatch` and `hash_enum_getnext` walk a table, `hash_lookup_refcnt` and `hash_remove_refcnt` find and drop
  entries with a reference count, and `compute_crc32` builds the CRC table.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(bsd_icrash.o)` (inferred): a crash-analysis hook, one routine `bsd_icrash` in a
  77364-byte member. It reads the network state of a dump, including the `tcb`, `udb`, `rawcb` and `rt_tables` data
  symbols, and calls no chip routine.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(md5.o)` (inferred): the MD5 digest, six routines in a 10644-byte member.
  `MD5Transform` (3340 bytes) is the core, `_BSD_MD5Init`, `_BSD_MD5Update` and `_BSD_MD5Final` wrap it, and `Encode` and
  `Decode` convert words. The TCP initial sequence code in `bsd.a(tcp_subr.o)` calls it.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(ppsratecheck.o)` (inferred): one routine, `ppsratecheck`, in a 3908-byte member. It
  limits how often an event may happen in a given interval and imports only `time`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(vsocket.o)` (inferred): the virtual socket object, six routines in a 9300-byte
  member. `vsocreate_internal` (208 bytes) creates one, `vsocket_hold` and `vsocket_release` count references, and
  `vsocket_free` releases it. `vsocket.o` joins the object to a behaviour chain with `bhv_insert_initial`.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(lsock.o)` (inferred): the local socket glue for kernel users, two routines
  `lcreate` and `lclose` in an 8564-byte member. It wraps `socreate`, `sobind`, `soconnect2` and `solisten` and does not
  drive a chip.
- `IP27/usr/cpu/sysgen/IP27boot/bsd.a(vsock_lp.o)` (inferred): one routine, `vsock_hinit`, in a 2916-byte member. It
  sets up the virtual socket head and has no imports. No chip is driven.
- `IP27/usr/cpu/sysgen/IP27boot/bsdidbg.o` (inferred): the debugger commands for the network stack, 83 routines in a
  132464-byte object. `idbg_mbcache`, `idbg_rawif`, `idbg_soc`, `idbg_hashtable` and `idbg_ifnet` print the mbuf cache,
  raw interfaces, sockets, hash tables and interfaces. It imports the `tcb` and `rt_tables` data symbols it prints.
- `IP27/usr/cpu/sysgen/IP27boot/cl.o` (inferred): the cluster device driver that carries data between partitions. Its
  14 routines include `cl_write` (732 bytes), `cl_read` (684 bytes), `cl_part_activate` and `cl_create_alenlist`, and it
  imports the cross-partition calls `xpc_send`, `xpc_receive` and `xpc_connect`. It drives no chip directly.
- `IP27/usr/cpu/sysgen/IP27boot/clone.o` (inferred): the clone device, two routines in a 7800-byte object. `clnopen`
  (484 bytes) opens the real driver named by the major number, and `clone_get_cdevsw` finds its switch entry through
  `hwgraph_cdevsw_get`.
- `IP27/usr/cpu/sysgen/IP27boot/clshm.o` (inferred): cross-partition shared memory, 36 routines in a 46864-byte object.
  `ctl_ioctl` (1488 bytes) is the control entry, `allocate_remote_shmid` (1192 bytes) and `allocate_local_shmid` set up a
  segment, and the page routines `part_page_allocate` and `part_permit_page` come from the partition layer. It converts
  node IDs with `nasid_to_compact_node`.
- `IP27/usr/cpu/sysgen/IP27boot/cn.o` (inferred): the console STREAMS multiplexer, 29 routines in a 25200-byte object.
  `cnopen`, `cnclose`, `cnread` and `cnwrite` serve the console device, `cn_link` (400 bytes) joins the console stream,
  and `cn_write_stream` writes to it. It imports `gfx_earlyinit`, the graphics console's early start-up.
- `IP27/usr/cpu/sysgen/IP27boot/connld.o` (inferred): the STREAMS connection module that lets a pipe be opened by name,
  four routines in a 12880-byte object: `connopen`, `connclose`, `connput` and `connvnode`. It imports `makepipe` and
  `fifo_stropen`. No chip is driven.
- `IP27/usr/cpu/sysgen/IP27boot/if_cl.o` (inferred): the network interface over the cluster link, 35 routines in a 49024-byte
  object. `ifcl_output` (2768 bytes) sends packets, `ifcl_ioctl` (1488 bytes) configures the interface, `ifcl_xpc_async`
  (1400 bytes) handles the cross-partition completion, and `ifcl_xmit_arp` sends ARP requests over it. It uses the
  cluster calls and no network chip.

## Process, memory, scheduler, lock and debugger objects (scope rule 3)

- `IP27/usr/cpu/sysgen/IP27boot/capability.a(capability.o)` (inferred): the capability set for processes, 11 routines in a
  14372-byte member. `cap_set` (812 bytes) and `cap_setpcap` (552 bytes) change the set, `cap_get` (456 bytes) reads it,
  and `cap_exec_newcap` (248 bytes) gives a new program its set at exec. It imports the auditing calls `sat_*`.
- `IP27/usr/cpu/sysgen/IP27boot/capability.a(cap_able.o)` (inferred): the capability checks, three routines in a
  6164-byte member: `cap_able` (48 bytes) and `cap_able_cred` (204 bytes) answer whether a credential holds a capability,
  and `cap_able_any` tests a set of them.
- `IP27/usr/cpu/sysgen/IP27boot/cdl.o` (inferred): the connection-point layer that attaches device drivers, 23 routines in
  a 24576-byte object. `cdl_add_driver` (836 bytes) registers a driver, `cdl_call_attach` (492 bytes) attaches it to a
  connection point, and `cdl_add_connpt_reg_locked` (1316 bytes) records the point. It imports the hardware-graph
  calls and drives no chip itself.
- `IP27/usr/cpu/sysgen/IP27boot/compression.a(compression.o)` (inferred): the compression front end, five routines in a
  7060-byte member: `compress` and `uncompress` (132 bytes each) select a method, `compression_init` and
  `compression_end` start and stop it. It calls the three coders in the same archive.
- `IP27/usr/cpu/sysgen/IP27boot/compression.a(rle1.o)` (inferred): a run-length coder, two routines `rle1_comp` and
  `rle1_uncomp` (208 bytes) in a 5140-byte member. It works on memory buffers only.
- `IP27/usr/cpu/sysgen/IP27boot/compression.a(zp.o)` (inferred): a second coder with `zp_comp` and `zp_uncomp` (56 bytes)
  in a 3588-byte member. It works on memory buffers and imports nothing from the chip layer.
- `IP27/usr/cpu/sysgen/IP27boot/compression.a(lzf.o)` (inferred): an LZF coder, `lzf_comp` and `lzf_uncomp` (332 bytes) in
  a 5140-byte member. It works on memory buffers only.
- `IP27/usr/cpu/sysgen/IP27boot/crypto.a(sha2.o)` (inferred): SHA-256 and SHA-512, 18 routines in a 16644-byte member.
  `SHA256_Transform` and `SHA512_Transform` (824 bytes each) are the compression functions, and the `_Init`, `_Update`
  and `_Final` entries wrap them. It imports only `bcopy` and `bzero`.
- `IP27/usr/cpu/sysgen/IP27boot/crypto.a(rijndael-alg-fst.o)` (inferred): the AES block cipher core, four routines in a
  25540-byte member: `rijndaelEncrypt` (1428 bytes), `rijndaelDecrypt` (1344 bytes), `rijndaelKeySched` and
  `rijndaelKeyEncToDec` (364 bytes).
- `IP27/usr/cpu/sysgen/IP27boot/crypto.a(rijndael-api-fst.o)` (inferred): the AES interface over the core above, six
  routines in a 12324-byte member. `rijndael_makeKey` and `rijndael_cipherInit` set up a key and mode,
  `rijndael_blockEncrypt` and `rijndael_padEncrypt` (1096 and 844 bytes) run it, and the member imports `panic`.
- `IP27/usr/cpu/sysgen/IP27boot/devpoll.o` (inferred): the `/dev/poll` interface, 27 routines in a 31936-byte object.
  `devpoll_scan` (1916 bytes) checks the descriptors, `devpoll_register` (868 bytes) adds one, and the `pollblock_*`
  routines keep the wait records. It registers its device with `hwgraph_char_device_add`.
- `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` (inferred): the lock metering and debug layer, 63 routines in a
  41892-byte member. `bitlockdebug`, `_64bitlockdebug` and `spinlockdebug` (612, 612 and 600 bytes) check lock use,
  `lockmeter_insert` (308 bytes) records contention, and `initsplocks` starts the tables. It uses AVL trees through
  `avl_insert` and `avl_find`.
- `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocksasm.o)` (inferred): the assembler try-lock routines, three in a
  4580-byte member: `try_spinlock`, `try_bitlock` and `try_64bitlock` (44 bytes each for the bit forms). Each takes a lock
  if it is free and returns without waiting.
- `IP27/usr/cpu/sysgen/IP27boot/dial.o` (inferred): the dial box input driver, 14 routines in a 29928-byte object.
  `dial_wioctl` (2016 bytes) is the control entry, `dial_intr` (716 bytes) takes the device interrupt, and
  `dial_set_resolution` and `dial_set_LEDs` drive the box. Its imports are the input event calls `idevGenValEvents`
  and `idevSetValDesc`. It also imports `idevChangeLineSettings`, which points to a serial line. The object is listed
  under rule 3, although rule 4 names input devices.
- `IP27/usr/cpu/sysgen/IP27boot/dialbox.o` (inferred): a second copy of the dial box driver, 14 routines in a 27448-byte
  object with the same entry names as `dial.o`. Its largest routines match `dial.o`'s, except that `dial_init_device`
  (408 bytes) appears where `dial.o` has `dial_set_str_dpy` (260 bytes here, 504 bytes in `dial.o`).
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(gang.o)` (inferred): gang scheduling, 34 routines in a 34308-byte member.
  `gang_startrun` (1348 bytes) starts a gang, `gang_find_bindings` (812 bytes) places its threads, and `gang_schedule`
  (440 bytes) picks the next one. It locks with `nested_spinlock` and reads the processor set with `cpu_to_cpuset`.
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(runq.o)` (inferred): the run queues, 29 routines in a 29316-byte member.
  `putrunq` (492 bytes) puts a thread on a queue, `pick_q` (460 bytes) takes one off, `idler` (412 bytes) runs when no
  thread is ready, and `setinfoRunq` (784 bytes) sets the queue data. It moves threads between CPUs with `cpu_insert_localq`.
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(utility.o)` (inferred): scheduler start-up, three routines in a 7892-byte member:
  `schedinit`, `force_resched` and `_disp_sanity`. The member imports `makeRunq`, `init_batchsys` and `init_rt`, the
  set-up routines for the run queues and the batch and realtime classes.
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(psched.o)` (inferred): the POSIX scheduling calls, six routines in a 10036-byte
  member: `sched_setscheduler`, `sched_getscheduler`, `sched_setparam` and `sched_getparam` read and set a thread's policy,
  and `sched_rr_get_interval` and `sched_yield` complete the set. It checks rights with `pcred_access`.
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(wtree.o)` (inferred): the weighted-tree scheduler, nine routines in an 11604-byte
  member. `wtree_sched_tick` (780 bytes) is its largest routine, `wt_run_time` and `wt_set_weight` handle each job's
  share, and `wtree_init` sets the tree up.
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(job.o)` (inferred): job objects that group threads for scheduling, ten routines in
  a 10564-byte member. `job_attach_thread` (96 bytes) and `job_unlink_thread` (148 bytes) add and remove a thread,
  `job_create` makes a job and `job_uncache` drops a cached one.
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(q.o)` (inferred): the doubly linked queue primitives, six routines in a 4324-byte
  member: `pushq`, `popq`, `rmq`, `q_insert_before`, `q_move_after` and `init_q_element`. The member has no imports.
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(batch.o)` (inferred): the batch scheduling class, 34 routines in a 31796-byte
  member. `batchd` (704 bytes) is the batch daemon, `batch_set_binding` (520 bytes) binds a batch job to processors, and
  `batch_pass_binding` and `batch_critical_meter` (332 and 488 bytes) pass and measure the binding.
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(cpu.o)` (inferred): the per-CPU dispatch helpers, 18 routines in a 22468-byte
  member. `cpu_select_q` (1192 bytes) and `cpu_select_rq` (672 bytes) choose the queue for a thread, `global_find_work`
  looks across CPUs, and `cpu_insert_localq` (424 bytes) fills a local queue. It reads node placement with
  `cpuid_to_compact_node`.
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(miser.o)` (inferred): the resource-guarantee scheduler, 35 routines in a 34340-byte
  member. `miser_send_request_scall` (1224 bytes) takes a system call request, `miser_set_quantum` and `miser_set_resources`
  set a job's share, and `miser_respond` (408 bytes) answers the requester. It uses the batch queue calls.
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(rt.o)` (inferred): the realtime scheduling class, 22 routines in a 27044-byte member.
  `rt_add_gq` (1640 bytes) adds a thread to the realtime queue, `rt_thread_select` (908 bytes) picks the next one,
  `start_rt` and `rt_nonpreemptable` manage the class, and `rt_queued_pri` reports the priority of the head.
- `IP27/usr/cpu/sysgen/IP27boot/disp.a(cpuset.o)` (inferred): processor sets, 69 routines in an 83988-byte member.
  `cpuset_create` (3016 bytes) makes a set, `cpuset_attach_pid` (1796 bytes) and `cpuset_move_pid` (1096 bytes) move
  processes into it, and `failsoft_purge_cpu` (1312 bytes) empties a set whose CPU failed. It flushes the TLB through
  `da_flush_tlb`.
- `IP27/usr/cpu/sysgen/IP27boot/failover.o` (inferred): multipath failover for SCSI paths, 49 routines in a 57080-byte
  object. `fo_start` starts the path manager, `fo_scsi_device_switch_new` (1312 bytes) moves a device to a new path, and
  `lsi_switch_func` (1772 bytes) is the switch routine. It walks the hardware graph with `hwgraph_traverse`. The rule
  text names no device class, so the object is listed under rule 3.
- `IP27/usr/cpu/sysgen/IP27boot/fru.a(sn0_fru_analysis.o)` (inferred): the field-replaceable-unit analysis for IP27 errors,
  34 routines in a 37476-byte member. `kf_analysis_print` (852 bytes), `kf_memory_bank_disable` (660 bytes) and
  `kf_node_tables_build` (648 bytes) print results and build the node tables, and `kf_cpu_err_info_get` and
  `kf_hub_err_info_get` read the error records of the CPU and the Hub. Its rule tables are in `sn0_fru_tables.o`.
  Scope question: see [the scope questions](#scope-questions).
- `IP27/usr/cpu/sysgen/IP27boot/fru.a(sn0_fru_node.o)` (inferred): the per-node FRU analysis, 14 routines in a 21444-byte
  member. `kf_hub_analyze` (876 bytes) and `kf_ii_crb_analyze` (540 bytes) analyse the Hub and its interface registers,
  `kf_pi_analyze` (1484 bytes) and `kf_md_analyze` (968 bytes) analyse the processor and memory interfaces, and
  `kf_board_analyze` is also a routine here. It imports `kf_hub_err_info_get` from `sn0_fru_analysis.o`.
- `IP27/usr/cpu/sysgen/IP27boot/fru.a(sn0_fru_io.o)` (inferred): the FRU analysis of the I/O side, four routines in a
  12404-byte member. `kf_xbow_analyze` (1676 bytes) analyses the Xbow crossbar, `kf_bridge_analyze` (1416 bytes) the
  Bridge, `kf_io_analyze` the I/O board, and `kf_pci_slave_dev_present` checks a PCI slave. It imports `pciio_error_extract`.
  Scope question: see [the scope questions](#scope-questions).
- `IP27/usr/cpu/sysgen/IP27boot/fru.a(sn0_fru_tables.o)` (inferred): the rule tables for the FRU analysis. The member
  holds no routine rows; its data symbols are `kf_cond_tab` (1632 bytes), `kf_action_set_tab` (360 bytes) and
  `kf_rule_tab` (136 bytes), and its five rule indexes are 4-byte constants `KF_BRIDGE_RULE_INDEX`, `KF_XBOW_RULE_INDEX`,
  `KF_MD_RULE_INDEX`, `KF_NI_RULE_INDEX` and `KF_PI_RULE_INDEX`.
- `IP27/usr/cpu/sysgen/IP27boot/graph.a(graph.o)` (inferred): the graph vertex and edge primitives, 26 routines in a
  32916-byte member. `graph_vertex_allocate` (1668 bytes) makes a vertex, `graph_edge_add` (876 bytes) and
  `graph_edge_remove` (852 bytes) link vertices, and the `graph_info_*_LBL` routines (about 900 bytes each) attach labelled
  information.
- `IP27/usr/cpu/sysgen/IP27boot/graph.a(hwgraph.o)` (inferred): the hardware graph, the device tree the kernel keeps. Its
  76 routines in a 51956-byte member include `hwgraph_inventory_add` (580 bytes), `hwgraph_vertex_name_get` (528 bytes) and
  `hwgraph_vpath_create` (484 bytes). It imports no chip routine; the chip drivers import its calls to publish their vertices.
- `IP27/usr/cpu/sysgen/IP27boot/graph.a(strtbl.o)` (inferred): the string table used by the graph, three routines in a
  6180-byte member: `string_table_init`, `string_table_insert` (536 bytes) and `string_table_destroy`.
- `IP27/usr/cpu/sysgen/IP27boot/graphidbg.o` (inferred): debugger commands for the graph, six routines in a 15288-byte
  object. `idbg_graph_vertex` (896 bytes) and `idbg_graph_handles` (900 bytes) print vertices and handles, `idbg_graph_summ`
  prints a summary, and `idbg_graph_help` lists the commands.
- `IP27/usr/cpu/sysgen/IP27boot/grio.a(grio.o)` (inferred): the guaranteed-rate I/O scheduler for block devices, 11 routines
  in a 19252-byte member. `griostrategy` (868 bytes) is the block entry, `grio_config` (668 bytes) sets the reservations,
  and `grio_start_next_rtdisk_io` and `grio_start_next_nonrtdisk_io` pick the next request. It finds block devices through
  `hwgraph_bdevsw_get`.
- `IP27/usr/cpu/sysgen/IP27boot/grio.a(grio_comm.o)` (inferred): the message path of the first guaranteed-rate scheduler,
  11 routines in a 15284-byte member. `grio_read_grio_req` (468 bytes) and `grio_resp_grio_req` (388 bytes) carry requests
  to the daemon and back, and `grio_add_msg_to_q_and_wait` waits for the reply.
- `IP27/usr/cpu/sysgen/IP27boot/grio.a(grio_sub.o)` (inferred): the stream and disk bookkeeping of the first scheduler, 52
  routines in a 41108-byte member. `grio_get_priority_bp` (812 bytes), `grio_determine_stream_priority` (472 bytes) and
  `grio_add_disk_info` (436 bytes) set priorities and record each disk's streams.
- `IP27/usr/cpu/sysgen/IP27boot/grio.a(grio_vod.o)` (inferred): the video-on-demand slot allocator of the first scheduler,
  seven routines in an 8212-byte member. `grio_determine_vod_priority` (576 bytes), `grio_find_closest_slot` (272 bytes) and
  `grio_vod_get_least_used_slot` pick a time slot for a stream.
- `IP27/usr/cpu/sysgen/IP27boot/grio.a(grio_monitor.o)` (inferred): the monitor of the first scheduler, five routines in an
  8180-byte member: `grio_monitor_start`, `grio_monitor_stop`, `grio_monitor_read`, and the I/O start and end hooks
  `grio_monitor_io_start` (240 bytes) and `grio_monitor_io_end` (228 bytes).
- `IP27/usr/cpu/sysgen/IP27boot/grio2.a(grio2.o)` (inferred): the second guaranteed-rate scheduler's start and stop, four
  routines in a 10436-byte member. `grio2init` and `grio2shutdown` start and stop it, `grio2_forced_shutdown` (528 bytes)
  stops it on error, and `grio2_version` reports the version.
- `IP27/usr/cpu/sysgen/IP27boot/grio2.a(grio2_comm.o)` (inferred): the command queue of the second scheduler, 16 routines in
  a 24276-byte member. `grio2_comm_send_cmds_local` (744 bytes) sends commands, `grio2_comm_insert_cmds` and
  `grio2_comm_remove_cmds` manage the queue, and `I_grio2_client_kern_notify` (800 bytes) tells a client of an event.
- `IP27/usr/cpu/sysgen/IP27boot/grio2.a(grio2_config.o)` (inferred): the reservation and configuration code of the second
  scheduler, 28 routines in a 52628-byte member. `grio2_config` (1436 bytes), `grio2_reserve` (912 bytes) and
  `grio2_reserve_fd` (1084 bytes) set reservations, and `grio2_modify` (948 bytes) changes one.
- `IP27/usr/cpu/sysgen/IP27boot/grio2.a(grio2_dbg.o)` (inferred): the debug printout of the second scheduler, 28 routines in
  a 31172-byte member. `grio2_dbg_stream` (500 bytes), `grio2_dbg_io_hist` (500 bytes) and `grio2_dbg_cmd` print its state.
- `IP27/usr/cpu/sysgen/IP27boot/grio2.a(grio2_fs.o)` (inferred): the file-system side of the second scheduler, ten routines
  in a 23588-byte member. `grio2_fs_dba` (1220 bytes) and `grio2_fs_dba_alloc` (792 bytes) allocate disk blocks for a
  managed file, and `grio2_fs_manage` and `grio2_fs_unmanage` (724 and 688 bytes) enrol and remove it.
- `IP27/usr/cpu/sysgen/IP27boot/grio2.a(grio2_misc.o)` (inferred): device name and identifier conversions for the second
  scheduler, four routines in an 11044-byte member: `grio2_devname_to_id` (612 bytes), `grio2_dev_to_id` (300 bytes),
  `grio2_xfs_vn_to_id` (532 bytes) and `grio2_id_hash`. It finds devices with `hwgraph_path_to_dev`.
- `IP27/usr/cpu/sysgen/IP27boot/grio2.a(grio2_icrash.o)` (inferred): one routine, `grio2_icrash`, in a 28004-byte member,
  a crash-analysis hook for the second scheduler. It has no imports.
- `IP27/usr/cpu/sysgen/IP27boot/grio2.a(grio2_irix.o)` (inferred): the kernel glue of the second scheduler, eight routines in
  a 10916-byte member. `grio2_fd_to_id` (572 bytes) maps a file descriptor to its stream, `grio2_filep_make_grio` and
  `grio2_filep_make_nongrio` change a file's class, and `grio2_nanotime` reads the clock.
- `IP27/usr/cpu/sysgen/IP27boot/grio2.a(grio2_sched.o)` (inferred): the dispatch loop of the second scheduler, nine routines
  in a 19076-byte member. `grio2_start_io` (1144 bytes) starts a request, `grio2strategy` (656 bytes) is the block entry,
  `grio2_iodone` (544 bytes) completes one, and `grio2_sched_thread` runs the loop. It finds block devices with
  `hwgraph_bdevsw_get`.
- `IP27/usr/cpu/sysgen/IP27boot/grio2.a(grio2_stream.o)` (inferred): stream reservations of the second scheduler, 36
  routines in a 45236-byte member. `grio2_stream_bw_reserve` and `grio2_stream_bw_release` account bandwidth,
  `grio2_stream_new` (520 bytes) creates a stream, and `grio2_stream_send_local_reservations` (908 bytes) sends them out.
- `IP27/usr/cpu/sysgen/IP27boot/grio2.a(grio2_qos.o)` (inferred): the quality-of-service samples of the second scheduler,
  12 routines in an 18548-byte member. `grio2_qos_add_sample` (1544 bytes) records a sample, `grio2_qos_get_hist` (452
  bytes) returns the history, and `grio2_qos_reset` (284 bytes) clears the state.
- `IP27/usr/cpu/sysgen/IP27boot/grio2idbg.o` (inferred): the debugger commands of the second scheduler, 26 routines in a
  23632-byte object: `idbg_grio2_grstreams`, `idbg_grio2_grcache`, `idbg_grio2_grq` and `idbg_grio2_grhelp` print its
  tables and queues.
- `IP27/usr/cpu/sysgen/IP27boot/grioidbg.o` (inferred): the debugger commands of the first scheduler, 11 routines in a
  17448-byte object. `idbg_griodiskstreamsum` (504 bytes) and `idbg_griodsum` (300 bytes) print disk and stream summaries,
  and `idbg_griohelp` lists the commands.
- `IP27/usr/cpu/sysgen/IP27boot/hardlocks.a(chardlocks.o)` (inferred): the spin and bit lock routines, 19 routines in a
  10084-byte member: `spinlock_alloc`, `spinlock_dealloc`, `init_spinlock`, `bitlock64bit_islocked` and
  `bitlock_islocked`. The member also defines `meter_spinlock`.
- `IP27/usr/cpu/sysgen/IP27boot/hardlocks.a(llsclocks.o)` (inferred): the spin and bit locks of the load-linked and
  store-conditional kind (the archive holds 28 `ll` or `sc` instructions in its disassembly), 22 routines in a 10868-byte member. `nested_spintrylock` and `nested_bittrylock` (156 bytes
  each) and `mutex_spinlock_spl` (84 bytes) are the try and blocking forms.
- `IP27/usr/cpu/sysgen/IP27boot/hardlocks_statistics.a(chardlocks.o)` (inferred): the statistics build of `chardlocks.o`,
  19 routines in a 10100-byte member with the same names. `bitlock64bit_islocked` (72 bytes) and `bitlock_islocked` (64
  bytes) are the sizes of the plain build.
- `IP27/usr/cpu/sysgen/IP27boot/hardlocks_statistics.a(llsclocks.o)` (inferred): the statistics build of `llsclocks.o`, 22
  routines in a 12308-byte member. Its `nested_spintrylock` and `nested_bittrylock` are 172 bytes each, against 156 bytes in
  the plain build.
- `IP27/usr/cpu/sysgen/IP27boot/i2c.o` (inferred): the I2C bus master, seven routines in a 12224-byte object.
  `i2c_master_xmit_recv` (964 bytes), `i2c_master_recv` (680 bytes) and `i2c_master_xmit` (600 bytes) move bytes on the bus,
  `i2c_arb` (528 bytes) handles arbitration, and `i2c_probe` checks for a device. It imports `node_can_talk_to_elsc`, which
  tells it whether the controller on that node is reachable. Scope question: see [the scope questions](#scope-questions).
- `IP27/usr/cpu/sysgen/IP27boot/idbg.o` (inferred): the kernel debugger, 304 routines in a 991696-byte object, the largest
  in the batch. `btrace` (9364 bytes), `dumppda` (4764 bytes), `idbg_mrlockfull` and `_idbg_utrace` are its large
  commands. It imports `compact_to_nasid_node` and `get_routername` among its 281 imports, and reads the process and
  memory structures for display.
- `IP27/usr/cpu/sysgen/IP27boot/idev.o` (inferred): the input-device event layer that the tablet and dial drivers
  use, 22 routines in a 25896-byte object. `idevGenPtrEvent` (736 bytes), `idevGenBtnEvents` (624 bytes) and
  `idevGenValEvents` (748 bytes) build events, `idevSetValDesc` (560 bytes) sets a valuator, and `idev_ioctl_name` names
  the requests. It drives no chip itself.

## Device drivers and input objects (scope rule 4)

- `IP27/usr/cpu/sysgen/IP27boot/calcomp.o` (inferred): a driver for a Calcomp digitizer, judging by its `cal_` routines and input-event imports, eight routines in a 26256-byte
  object. `cal_other_control` (2216 bytes) and `cal_wioctl` (1452 bytes) are the control entries, `cal_intr` (836 bytes)
  takes the device interrupt, and `cal_init` starts the device. It delivers input events through `idevGenValEvents` and
  `idevSetPtr`. No system chip is driven.
- `IP27/usr/cpu/sysgen/IP27boot/cserialio.o` (inferred): the serial line driver, 22 routines in a 21768-byte object.
  `csio_ioctl` (992 bytes), `csio_open` (864 bytes), `csio_read` and `csio_write` serve the port, `csio_config` (276 bytes)
  sets the line, and `sio_lock_port` and `sio_unlock_port` guard it. It takes its port from the device info of the
  caller and does not program a system chip.
- `IP27/usr/cpu/sysgen/IP27boot/ecpplp.o` (inferred): the parallel-port driver, 33 routines in a 57304-byte object.
  `plpintr` (1708 bytes) takes the port interrupt, `plpio` (1452 bytes) moves data, `plpattach` (1300 bytes) attaches the
  port, and `plp_dma` (780 bytes) runs a transfer. It imports `ioc3_intr_connect`, `ioc3_subdev_enabled` and
  `ioc3_write_ireg`, so the port is an IOC3 subdevice. Scope question: see [the scope questions](#scope-questions).
- `IP27/usr/cpu/sysgen/IP27boot/fcadp.a(fcadp.o)` (inferred): the Fibre Channel host adapter driver, 93 routines in a
  98820-byte member. `fcadpioctl` (1404 bytes) is the control entry, `ulm_event` (1100 bytes) and `fc_scsi_complete`
  (1068 bytes) handle completions, and `fcadp_ctlrinit` (920 bytes) starts the controller. It reaches the adapter over PCI
  and reserves Bridge buffers through `pcibr_alloc_all_rrbs`, like the PCI driver `pciba.o` in the chip-driver page.
- `IP27/usr/cpu/sysgen/IP27boot/fcadp.a(hwlip.o)` (inferred): the loop initialisation sequence of the adapter, six routines
  in an 8708-byte member. `sh_check_loopfailure` (344 bytes) and `sh_timer_checking` (64 bytes) watch for failures,
  `sh_start_lip_sequencer` and `sh_send_lip_primitive_in_lip` send the primitives, and `sh_get_vaddr_lip_code` gives the
  firmware location.
- `IP27/usr/cpu/sysgen/IP27boot/fcadp.a(hwutil.o)` (inferred): the adapter's utility routines, 45 routines in a 46916-byte
  member. `sh_loadnrun_lip` (1012 bytes) loads and starts the loop firmware, `sh_reload_mainline_firmware` (692 bytes)
  reloads the main firmware, and `sh_access_scratch` reads the scratch memory of the adapter.
- `IP27/usr/cpu/sysgen/IP27boot/fcadp.a(hwconfig.o)` (inferred): the adapter configuration, 10 routines in a 16148-byte
  member. `sh_init_1160_ram` (1776 bytes) sets up the adapter's memory, `sh_initialize` (916 bytes) brings it up,
  `sh_read_link_speed` reads the link rate, and `sh_invalidate_tcbs` clears its command blocks.
- `IP27/usr/cpu/sysgen/IP27boot/fcadp.a(hwintr.o)` (inferred): the adapter's interrupt routines, five routines in a 15476-byte
  member. `sh_frontend_isr` takes the front-end interrupt, `sh_backend_isr` (1040 bytes) the back-end one, `sh_int_error`
  (1940 bytes) decodes errors, and `sh_pci_errout` reports PCI errors.
- `IP27/usr/cpu/sysgen/IP27boot/fcadp.a(hwtrans.o)` (inferred): the transfer routines, two routines in a 9108-byte member:
  `sh_deliver_tcb` hands a command block to the adapter and `sh_special_tcb` (1668 bytes) handles the special ones.
- `IP27/usr/cpu/sysgen/IP27boot/fcadp.a(ulmutil.o)` (inferred): the byte and word accessors for the adapter's memory,
  seven routines in a 5156-byte member: `inMemByte`, `inMemWord`, `outMemWord`, `outMemByte` and the swap helpers
  `ulm_swap8` and `ULM_SWAP_SHORT`.
- `IP27/usr/cpu/sysgen/IP27boot/fcal.o` (inferred): the Fibre Channel arbitrated-loop address tables, a member with no
  routine rows. Its data symbols are `alpa_to_tid` (256 bytes, the map from loop address to target number) and
  `tid_to_alpa` (127 bytes, the reverse map), both in a 2192-byte object.
- `IP27/usr/cpu/sysgen/IP27boot/fcidbg.o` (inferred): the debugger commands of the Fibre Channel driver, two routines
  `fcidbg_init` and `idbg_fc` (1008 bytes) in a 9040-byte object. `idbg_fc` prints the adapter state; it reads the
  `fcadp_init_time` symbol.
- `IP27/usr/cpu/sysgen/IP27boot/gentty.o` (inferred): the generic terminal driver for the controlling terminal, eight
  routines in an 11944-byte object. `syopen` (380 bytes), `syread` and `sywrite` (288 bytes each) serve `/dev/tty`,
  and `sypoll` (332 bytes) handles poll. It finds the real terminal through `hwgraph_cdevsw_get`.
- `IP27/usr/cpu/sysgen/IP27boot/hitachi.o` (inferred): an input device driver, nine routines in a 26296-byte object.
  `htchi_wioctl` (1520 bytes) is the control entry, `htchi_pressure_intr` (856 bytes) and `htchi_intr` (724 bytes) take
  the device interrupts, and `htchi_init_device` sets it up. Its events go through the input-event layer `idev`.
- `IP27/usr/cpu/sysgen/IP27boot/htport.o` (inferred): a display port driver for a text and graphics terminal, 38 routines
  in a 59440-byte object. `txPaint` (1152 bytes), `txShdOutline` (1188 bytes) and `txCsistuff` (1244 bytes) draw text and
  shapes, `txInitfonts` loads the fonts, and `txDialog` (864 bytes) shows a dialog. It drives a display, not a system chip.

## IP35 build: network, STREAMS and cluster objects (scope rule 2)

The IP35 kernel carries most of the network members of the IP27 build above, built into its own `bsd.a` and `socket.a`
archives. Where an IP35 member is byte-identical to the `socket.a` member of the same name, the row is written once under
`bsd.a`, the path the table uses. Routine names and sizes come from the IP35 symbol table, so they can differ from the
IP27 entries: `bsd.a(if.o)` is 49300 bytes here and 49380 bytes in the IP27 build. Labels are inferred, from the symbol
table and undefined imports. No routine body was read in full.

- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(if.o)` (inferred): the generic network interface layer, 47 routines in a 49300-byte
  member. `ifioctl` (2672 bytes) is the largest; `if_create_linkaddr`, `if_detach` and `ifunit` keep the interface list and
  the link-level addresses. It imports the hardware-graph calls `hwgraph_path_add`, `hwgraph_edge_add` and
  `hwgraph_traverse`. No chip is driven directly.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(if_loop.o)` (inferred): the software loopback interface, three routines in an 8644-byte
  member. `looutput` (756 bytes) hands a packet back to `network_input`, `loioctl` configures the interface and `loattach`
  registers it with `if_attach`. It drives no hardware.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(netisr.o)` (inferred): the network software interrupt threads, 15 routines in an
  18212-byte member. `netisr_init` starts them through `xthread_setup` and `xthread_set_func`, `network_input` queues an
  inbound packet, and `netproc` and `sockd` are the thread bodies. It reads `maxcpus` and calls no chip routine.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(raw.o)` (inferred): the raw link-level socket, 21 routines in a 24836-byte member.
  `rawioctl` (2164 bytes) is the control entry, `snoop_input2` (1208 bytes) feeds the packet-capture path, and `rawopen`,
  `rawclose`, `drain_input` and `rawif_attach` serve the socket and the interface. It imports `bitswapcopy` from the
  bit-order copy routine and drives no chip.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(raw_cb.o)` (inferred): the control-block list for raw sockets, eight routines in a
  10948-byte member. `raw_attach` (188 bytes) and `raw_bind` (260 bytes) create and bind a block, `raw_disconnect` and
  `raw_pcbpurgeif` (292 bytes) drops the blocks tied to a removed interface, and `rawcb_free` and `rawcb_rele` drop
  references. It links blocks with
  `_insque` and `_remque`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(raw_usrreq.o)` (inferred): the request dispatch for raw sockets, five routines in a
  13092-byte member. `raw_usrreq` (916 bytes) is the entry, `raw_protocol_input` (792 bytes) receives packets, and
  `raw_input`, `raw_init` and `raw_ctlinput` (8 bytes) deliver and initialise. Its imports are the raw routines it
  dispatches to and the socket buffer calls `sbappendaddr` and `sowakeup`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(radix.o)` (inferred): the radix tree that holds routes and netmasks, 19 routines in a
  23732-byte member. `rn_delete` (1316 bytes), `rn_addroute` (1068 bytes) and `rn_addmask` (916 bytes) change the tree,
  `rn_match` (808 bytes) does the longest-prefix lookup, and `rn_insert` (496 bytes) places a leaf. It takes the route lock
  through `mrupdatef` and `mrunlock`. No chip is driven.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(route.o)` (inferred): the routing table code, 22 routines in a 26212-byte member.
  `rtrequest1` (1052 bytes) adds, changes and deletes routes, `rtioctl` (1028 bytes) is the control entry, and `rtalloc1`
  (776 bytes) finds a route. `rtinit` and `rtredirect` handle interface and redirect updates, and `rt_missmsg` and
  `rt_newaddrmsg` report changes to the routing socket.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(rtsock.o)` (inferred): the routing socket, which sends route changes to user programs.
  16 routines in a 27892-byte member. `route_output` (2368 bytes) takes route requests, `sysctl_iflist` (1160 bytes) reports
  the interface list, and `rt_msg1`, `rt_msg2` and `rt_newaddrmsg` build the replies. It imports the `rt_tables` data symbol that holds the routing tables.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(rsvp.o)` (inferred): RSVP resource reservation and the packet scheduler, 39 routines in
  a 33908-byte member. `ps_init` (848 bytes) sets up the packet scheduler, `ps_send_down` (844 bytes) and `ps_output`
  (720 bytes) send packets down to the interface, `ps_tick_maint` maintains its timers and `rsvp_addflow` (488 bytes) adds a reserved flow.
  It calls the packet queues in `bsd.a(rsvp_qo.o)` through `psqo_enq_pkt` and `psqo_get_next_pkt`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(rsvp_qo.o)` (inferred): the packet queues under RSVP, five routines in a 7188-byte
  member. `psqo_init` (60 bytes), `psqo_alloc_queue` (128 bytes) and `psqo_free_queue` (116 bytes) manage the queues, and
  `psqo_enq_pkt` (352 bytes) and `psqo_get_next_pkt` (368 bytes) add and take packets. It imports `kmem_zalloc`,
  `kmem_free`, `bzero` and the spin-lock calls, and no chip routine.

- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(if_is.o)` (inferred): the interface-striping driver, 41 routines in a 47204-byte member.
  `is_output` (1576 bytes) spreads output over several links, `is_reorder_drain` (1352 bytes) and `is_input_reorder_entry`
  (792 bytes) put input back in order, and `is_add_link` (672 bytes) adds a member link. It attaches and detaches with
  `if_attach` and `if_detach`, starts its threads with `xthread_set_func`, and reaches the raw interface through
  `rawif_attach` and `rawif_detach`. No chip is driven directly.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(igmp.o)` (inferred): IGMP group membership, 14 routines in an 18420-byte member.
  `igmp_input` (1256 bytes) handles membership reports, `igmp_sendpkt` (392 bytes) sends them, and
  `igmp_update_host_membership` and `igmp_update_host_new_membership` keep the host's group state, found through the hash
  calls `hash_lookup` and `hash_enum`. It calls `ip_mroute_init` and `ip_mroute_slowtimo` for the multicast router.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(if_ether.o)` (inferred): ARP, 27 routines in a 35764-byte member. `in_arpinput`
  (1596 bytes) answers requests, `arpresolve` (1560 bytes) resolves an address, `arp_rtrequest` (1016 bytes) keeps the
  route entries, and `arptimer` (836 bytes) ages them. It looks up interfaces with `ifa_ifwithnet`. No chip is driven.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(in.o)` (inferred): IPv4 interface addressing, 73 routines in a 52324-byte member.
  `in_control` (3452 bytes) is the address ioctl, `in_ifinit` (964 bytes) sets an interface address, and `inet_addr`
  (712 bytes) and `inet_ntop` (888 bytes) convert text. It starts IPv6 with `in6_init`, joins and leaves groups with
  `igmp_joingroup` and `igmp_leavegroup`, and imports the tunnel switches `auto_tunnel_enable` and `config_tunnel_enable`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(in_pcb.o)` (inferred): the protocol control blocks for IPv4 sockets, 38 routines in a
  46628-byte member. `in_pcblookupx` (3580 bytes) finds the block for an arriving packet, `in_pcbnotify` (1388 bytes)
  reports errors to it, and `udp_full_assign` and `tcp_full_assign` set the full endpoint. It draws ports with
  `inpcb_randomize_ports` and reads the port limit `ipport_maxport`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(ip_icmp.o)` (inferred): ICMP, nine routines in a 17076-byte member. `icmp_input`
  (1472 bytes) handles inbound messages, `icmp_reflect` (944 bytes) builds replies, `icmp_error` (956 bytes) reports a
  failed datagram, and `icmp_send` (232 bytes) sends one. It imports the settings `icmp_respond_to_timestamp` and
  `icmp_respond_to_address_mask`, which decide whether those requests get replies.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(ip_input.o)` (inferred): the IPv4 input path, 21 routines in a 34436-byte member.
  `ip_input` (2740 bytes) validates each packet, `ip_reass` (1176 bytes) and `ip_reass_strict` (1452 bytes) reassemble
  fragments, and `ip_dooptions` (1320 bytes) and `ip_forward` (1316 bytes) process options and forward. It looks up the
  next protocol through `inetsw`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(ip_output.o)` (inferred): the IPv4 output path, nine routines in a 32196-byte member.
  `ip_output` (3664 bytes) is the transmit entry, `ip_setmoptions` (1524 bytes) and `ip_getmoptions` (460 bytes) set and
  read multicast options, `ip_ctloutput` (1244 bytes) is the socket option entry, and `ip_pcbopts` (448 bytes) keeps the
  option block. It calls `in_addmulti2` and `in_delmulti` for group changes.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(raw_ip.o)` (inferred): raw IP sockets, three routines in an 11124-byte member:
  `rip_input` (172 bytes), `rip_output` (516 bytes) and `rip_ctloutput` (736 bytes). It imports the multicast router
  switches `ip_mrouter_set` and `ip_mrouter_get` and the RSVP virtual-interface calls `ip_rsvp_vif_init` and
  `ip_rsvp_vif_done`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(tcp_debug.o)` (inferred): the TCP trace hook, one routine `tcp_trace` (1128 bytes) in an
  11012-byte member. It prints state changes with `printf`, reads the time with `iptime`, and carries the state, timer and
  request name tables `tcpstates`, `tcptimers` and `prurequests`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(tcp_input.o)` (inferred): TCP input processing, 13 routines in a 43876-byte member.
  `tcp_input_private` (10032 bytes) is the segment handler, `tcp_input` (1160 bytes) is its entry, `tcp_dooptions` (820
  bytes) parses options, `tcp_mss` (1556 bytes) sets the segment size and `tcp_reass` (1292 bytes) reassembles out-of-order
  data. It finds the connection with `in_pcblookupx` and picks initial sequence numbers with `iss_hash`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(tcp_output.o)` (inferred): TCP output, two routines in a 16004-byte member. `tcp_output`
  (5216 bytes) builds and sends segments, and `tcp_setpersist` (180 bytes) arms the persist timer. It imports the checksum
  `in_cksum`, the IP output routines `ip_output` and `tcp6_output`, and `tcp_max_tso_len`, the segment-size routine of the
  offload path.

- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(tcp_subr.o)` (inferred): TCP support routines, 29 routines in a 30308-byte member.
  `tcp_close` (1168 bytes) closes a connection, `tcp_respond` (876 bytes) and `tcp_template` (608 bytes) build reply
  packets, `tcp_msgsize` (772 bytes) sizes a message, and `sack_sndupdate` (676 bytes) keeps the selective-acknowledgement
  list. It imports the MD5 routines `_BSD_MD5Init`, `_BSD_MD5Update` and `_BSD_MD5Final` and sets up its zones with
  `kmem_zone_init`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(tcp_timer.o)` (inferred): the TCP timers, five routines in a 16148-byte member.
  `tcp_timers` (1392 bytes) runs the per-connection timers, `tcp_fasttimo` (988 bytes) and `tcp_slowtimo` (884 bytes) are
  the periodic entries, `tcp_zaptw` (684 bytes) clears TIME_WAIT blocks, and `tcp_canceltimers` (36 bytes) stops them. It
  imports `tcp_close`, `tcp_drop`, `tcp_output` and `tcp_respond` to act on expired timers.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(tcp_usrreq.o)` (inferred): the TCP socket requests, five routines in a 15652-byte
  member. `tcp_usrreq` (1860 bytes) is the socket entry, `tcp_attach` and `tcp_disconnect` (180 bytes each) create and drop
  a connection, `tcp_usrclosed` (380 bytes) handles a closed socket, and `tcp_ctloutput` (624 bytes) handles options. It
  calls the IPv4 block routines `in_pcballoc`, `in_pcbbind`, `in_pcbconnect` and `in_pcbdetach`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(udp_usrreq.o)` (inferred): UDP, eight routines in a 23540-byte member. `udp_input`
  (2724 bytes) demultiplexes datagrams, `udp_usrreq` (2088 bytes) is the socket entry, `udp_output` (1296 bytes) sends them,
  and `udp_ctlinput` (236 bytes) handles control messages. It finds the block with `in_pcblookupx`, reports errors through
  `icmp_error`, and reads the NFS port `nfs_port` from its data.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(rsvp_input.o)` (inferred): the RSVP input path, two routines in an 8772-byte member:
  `rsvp_input` (620 bytes) receives reservation messages and `socket_send` (176 bytes) hands them to the socket layer
  through `sbappendaddr` and `sowakeup`. It passes raw packets to `rip_input` and checks `rsvp_on`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(offload.o)` (inferred): fragment vectors for checksum and segmentation offload, ten
  routines in a 14740-byte member. `build_frag_vec` (1664 bytes) builds the vector, `frgvec_header_copy` (744 bytes) copies
  the header into it, `frag_vec_coalesce_long_chain` (344 bytes) merges long chains, and `udp_to_frag_vec_cksum` (300 bytes)
  builds one for UDP. `tcp_max_tso_len` (276 bytes) gives the segment size. It imports no chip routine.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(bsdinit.o)` (inferred): network start-up, five routines in an 8628-byte member.
  `bsd_init` (192 bytes) calls the protocol, interface and socket initialisers, `sethostid` (116 bytes) and `gethostid`
  (72 bytes) set and read the host identifier, and `phost_sethostid` and `phost_gethostid` (8 and 12 bytes) are the
  smaller counterparts. It imports `netisr_init`, `loattach` and `sockd_init` among the start-up calls.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(uipc_domain.o)` (inferred): the protocol domain table, 12 routines in a 13236-byte
  member. `domaininit` (276 bytes) installs the domains, `pffindproto` (304 bytes) searches the protocol switch,
  `domain_add` and `domain_drain` (264 and 232 bytes) add a domain and drain its queues, and `pfctlinput2` (216 bytes)
  passes a control input to the protocols. It imports the domain records `inetdomain`, `inet6domain`, `routedomain`,
  `rawdomain` and `atmarpdomain`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(uipc_socket.o)` (inferred): the socket core, 21 routines in a 31684-byte member.
  `soreceive` (3040 bytes) and `sosend` (1808 bytes) move the data, `soclose` (976 bytes) closes a socket, and `sogetopt`
  and `sosetopt` (852 and 840 bytes) handle options. It takes locks with `mutex_spinlock` and sends and receives mbuf
  chains with `m_copy`, `m_flip` and `m_shget`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(uipc_socket2.o)` (inferred): socket buffers and wakeups, 27 routines in a 28596-byte
  member. `sbappendaddr` (2100 bytes), `sbappendrights` (1460 bytes) and `sbappend` (1008 bytes) add to the receive buffer,
  `sonewconn` (908 bytes) makes a socket for a new connection, and `sbcompress` (504 bytes) packs the buffer. It imports
  `mp_streams_interrupt` and the atomic add-with-wrap calls.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(uipc_syscalls.o)` (inferred): the socket system calls, 33 routines in a 26740-byte
  member. `recvit` (1132 bytes) and `sendit` (636 bytes) carry the data for the receive and send calls, `xpg4_recvmsg` and
  `xpg5_recvmsg` (464 bytes each) serve the newer message interfaces, and `irix5_to_cmsghdr` (352 bytes) converts the
  control header from the IRIX 5 layout. It moves user data with `copyin` and `copyout`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(uipc_socket1.o)` (inferred): socket control, nine routines in a 17156-byte member.
  `uipc_accept` (1528 bytes) takes a connection, `soioctl` (952 bytes) is the socket ioctl, `uipc_connect` (432 bytes) and
  `uipc_getpeername` (368 bytes) answer the address calls, and `sopoll` (428 bytes) supports poll. It forwards interface
  and route ioctls to `ifioctl` and `rtioctl`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(hashing.o)` (inferred): the generic hash tables, 14 routines in a 14676-byte member.
  `hash_enum_bestmatch` (340 bytes) and `hash_enum_getnext` (332 bytes) walk a table, and `hash_lookup_refcnt`,
  `hash_remove_refcnt` and `hash_lookup_remove` (308 bytes each) find and drop entries. It guards its tables with the
  `mrlock` calls and `splimp` and `splx`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(bsd_icrash.o)` (inferred): a crash-analysis hook, one routine `bsd_icrash` (8 bytes) in a
  77060-byte member. Most of the member is not code in its symbol table. It imports the network tables `tcb`, `udb`,
  `rawcb`, `rt_tables`, the hash tables and `ifnet`, plus the stream and page counters, so the crash tools can read the
  network state of a dump. It calls no chip routine.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(vsocket.o)` (inferred): the virtual socket object, six routines in a 9220-byte member.
  `vsocreate_internal` (208 bytes) creates one, `vsocket_alloc` (128 bytes) takes it from the zone, `vsocket_hold` and
  `vsocket_release` (68 and 148 bytes) count references, and `vso_initialize` (88 bytes) sets it up. It joins the object
  to a behaviour chain with `bhv_insert_initial`.
- `IP35/usr/cpu/sysgen/IP35boot/bsd.a(lsock.o)` (inferred): the local socket glue for kernel users, two routines `lcreate`
  (112 bytes) and `lclose` (272 bytes) in an 8484-byte member. It wraps the socket calls `socreate`, `sobind`, `soconnect2`
  and `solisten`, and it drives no chip.

- `IP35/usr/cpu/sysgen/IP35boot/bsdidbg.o` (inferred): the debugger commands for the network stack, 83 routines in a
  132376-byte object. `idbg_mbcache` (1000 bytes), `idbg_rawif` (860 bytes), `idbg_soc` (788 bytes), `idbg_hashtable`
  (720 bytes) and `idbg_inpcb` (712 bytes) print the mbuf cache, raw interfaces, sockets, hash tables and protocol blocks.
  It registers them with `idbg_addfunc` and reads the ARP, IGMP and mbuf state through `llinfo_arp`,
  `igmp_router_info_head` and `mb_source_cache`. It drives no chip.
- `IP35/usr/cpu/sysgen/IP35boot/cl.o` (inferred): the cluster device driver that carries data between partitions, 14 routines
  in a 17296-byte object. `cl_write` (732 bytes) and `cl_read` (684 bytes) move data, `cl_create_device` (428 bytes) and
  `cl_create_alenlist` (384 bytes) set up a device and its scatter list, and `cl_part_activate` and `cl_async_thread`
  follow the partition. It imports the cross-partition calls `xpc_send`, `xpc_receive` and `xpc_connect`, and
  `part_register_handlers` and `part_id`. It drives no chip directly. The same bytes are also at `cl_part.o`.
- `IP35/usr/cpu/sysgen/IP35boot/clone.o` (inferred): the clone device, two routines in a 7712-byte object. `clnopen` (484
  bytes) opens the real driver named by the major number, and `clone_get_cdevsw` (152 bytes) finds its switch entry
  through `hwgraph_cdevsw_get`.
- `IP35/usr/cpu/sysgen/IP35boot/clshm.o` (inferred): cross-partition shared memory, 36 routines in a 46784-byte object.
  `ctl_ioctl` (1496 bytes) is the control entry, `allocate_remote_shmid` (1192 bytes) and `allocate_local_shmid` (1188 bytes)
  set up a segment, and `allocate_cross_pages` (912 bytes) maps pages for it. It registers its device with
  `hwgraph_char_device_add`, and it finds the partition's memory object through `getpmo_ns`. No chip is driven directly.
- `IP35/usr/cpu/sysgen/IP35boot/cn.o` (inferred): the console STREAMS multiplexer, 29 routines in a 25752-byte object.
  `cnwrite` (604 bytes), `cnioctl` (420 bytes) and `cn_write_stream` (404 bytes) serve the console device, and `cn_link`
  (400 bytes) joins the console stream. It selects among the console back ends through the data symbols
  `sio_cons_funcs`, `pckm_cons_funcs` and `console_is_tport`, and it imports `ducons_write` and `gfx_earlyinit`.
- `IP35/usr/cpu/sysgen/IP35boot/connld.o` (inferred): the STREAMS connection module that lets a pipe be opened by name, four
  routines in a 12800-byte object: `connopen` (1964 bytes), `connvnode`, `connput` and `connclose`. It imports `makepipe`,
  `fifo_stropen` and `fifo_vnodeops`. No chip is driven.

## Scope questions

Each object below is listed under the rule shown, but its imports or routine names match a class the scope text keeps.
These are questions for the scope list; nothing here changes `scripts/inventory-config.json`.

- `fru.a` (sn0_fru_analysis.o, sn0_fru_node.o, sn0_fru_io.o) is listed under rule 3, the core rule. The function-scope
  text keeps objects that report errors for the Hub, Xbow, Bridge and router. These routines cover the Hub
  (`kf_hub_err_info_get`, `kf_hub_analyze`), the Xbow (`kf_xbow_analyze`), the Bridge (`kf_bridge_analyze`) and the
  router (`kf_router_analyze`), and `sn0_fru_io.o` imports `pciio_error_extract`. Candidates for the keep list.
- The I2C bus master (`i2c.o`) is listed under rule 3. It is the I2C master on the node's bus, and the scope text
  keeps controller objects on the same buses. The ELSC controller object `elsc.o` calls these routines and is also
  listed under rule 3; the [chip-driver page](binaries-scope-chip-drivers.md) flags it for the same review. Candidates
  for the keep list.
- The parallel-port driver (`ecpplp.o`) is listed under rule 4, which removes drivers that do not drive a system ASIC.
  It imports `ioc3_intr_connect`, `ioc3_subdev_enabled` and `ioc3_write_ireg`, so it drives the IOC3 parallel port. The
  IOC3 Ethernet and keyboard objects are kept for the same reason. Candidate for the keep list.
- `IP27/usr/cpu/sysgen/IP27boot/fcadp.a` members reserve Bridge read-response buffers through `pcibr_alloc_all_rrbs`. Rule 4
  removes them, as it removes the PCI driver `pciba.o`, so this is consistent with the existing decision.
- Rule labels that do not match the class of the object (the in/out result does not change): `fddi.a` is listed under
  rule 1 but is a network interface; `dksc.o` and `ds.a` are device drivers under rule 1; `dial.o` and `dialbox.o` are
  input devices under rule 3; `compression.a` and `crypto.a` are under rule 3, which names no coder or cipher class.
