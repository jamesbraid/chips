# File-system objects in the kernel builds

Each entry classifies one shipped file of the four kernel builds (IP27, IP30, IP32, IP35) whose routines are
file-system code. The routine names and sizes come from the file's symbol table. The window scan found no
register access in any of them, so the scope rule that lists the file removes its routines from the function
table. Labels: a classification from names, sizes and the scan's result is inferred.

- `IP27/usr/cpu/sysgen/IP27boot/acl_hwg.o` (inferred): a 5520-byte object with three routines, `acl_hwg_iaccess`,
  `acl_hwg_get` and `acl_hwg_match`. Its names describe access checks and ACL reads for hardware-graph device
  nodes. The window scan found no register access, so scope rule 1 excludes its routines.
- `IP27/usr/cpu/sysgen/IP27boot/acl_nfs3.o` (inferred): a 6288-byte object with two routines, `acl_nfs_iaccess`
  and `acl_nfs_get`, which check and fetch access-control lists for NFS version 3 files. Scope rule 1 lists it,
  and the scan records zero window sites for it.
- `IP27/usr/cpu/sysgen/IP27boot/acl_xfs.o` (inferred): one routine, `acl_xfs_iaccess`, in a 5328-byte object. It
  is the XFS counterpart of the NFS check above. The scan records zero window sites, and rule 1 removes it.
- `IP27/usr/cpu/sysgen/IP27boot/autofs.a(auto_subr.o)` (inferred): 20 routines in a 26548-byte member, among them
  `do_mount`, `makeautonode`, `do_unmount` and `unmount_hierarchy`. They build and tear down the automount
  hierarchy under the autofs trigger directories. The scan found no window site, so scope rule 1 excludes them.
- `IP27/usr/cpu/sysgen/IP27boot/autofs.a(auto_vfsops.o)` (inferred): nine routines in a 15540-byte member, led by
  `autofs_init`, `auto_mount` and `auto_unmount`, plus `auto_statvfs`. They form the autofs mount table entry
  points. No window site was recorded, and rule 1 removes the nine routines.
- `IP27/usr/cpu/sysgen/IP27boot/autofs.a(auto_vnops.o)` (inferred): 24 vnode operations in a 32036-byte member,
  among them `auto_lookup`, `auto_readdir` and `auto_rmdir`. The routines answer file-system requests on autofs
  directories. The scan records zero window sites for the member, and scope rule 1 lists it.
- `IP27/usr/cpu/sysgen/IP27boot/autofs.a(autofs_icrash.o)` (inferred): a 13780-byte member holding the single
  routine `autofs_icrash`. The routine is a crash-analysis hook for the autofs state, and the scan records no
  device register access for it. Rule 1 removes it.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_cnode.o)` (inferred): 15 routines in a 25012-byte member, for
  example `cfind`, `cachefs_addfidhash` and `makecachefsnode`. They keep the hash of cache file nodes that map
  back to the back file system. No device window is reached, and rule 1 excludes the member's routines.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_resource.o)` (inferred): ten routines in a 15780-byte member,
  among them `cachefs_replacement`, `cachefs_garbage_collect` and `cachefs_allocblocks`. They decide which cache
  objects to evict and reserve blocks on the cache disk. Zero window sites were recorded for this member.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_singlewrc.o)` (inferred): five routines in a 14708-byte member,
  all named `c_single_` followed by an operation (`init`, `check`, `modify`, `invalidate`, `expire`). They are
  the single-writer consistency policy for cached objects. The scan records no window site.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_strict.o)` (inferred): five routines in a 13172-byte member,
  named `c_strict_` plus the same five operations. They form the strict consistency policy, the sibling of the
  single-writer member above. No window site was recorded, so scope rule 1 excludes them.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_subr.o)` (inferred): 54 routines in a 75412-byte member. The
  largest is the cache-directory set: `activate_cache`, `cachefs_cache_create`, `coalesce_allocmap` and
  `cachefs_update_allocmap`. Its allocation-map routines keep block lists on the cache volume. Zero window sites.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_fscache.o)` (inferred): nine routines in a 13108-byte member,
  `fscache_create`, `fscache_destroy`, `fscache_hold` and `fscache_rele` among them. Each one manages a cache
  object's reference count and its list membership. Rule 1 removes these routines.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_vfsops.o)` (inferred): 19 routines in a 32052-byte member,
  including `cachefs_mount`, `cachefs_unmount`, `cachefs_statvfs` and `get_minor_number`. These are the cache
  file system's mount, unmount and statistics entry points. No device window is reached by these routines.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_module.o)` (inferred): a 10932-byte member with three routines,
  `cachefs_init`, `cachefs_getstat` and `cachefs_clearstat`. They register the module and read or clear its
  counters. The scan found no window access, and the member sits under rule 1.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_vnops.o)` (inferred): 45 routines in a 79764-byte member, from
  `cachefs_open` and `cachefs_read` through `cachefs_fsync`. These are the cache file system's vnode operations
  for regular files. Zero window sites were recorded for this member.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_noopc.o)` (inferred): five routines in a 10932-byte member,
  named `c_nop_` plus the five operations. They are the consistency policy that does nothing, the third sibling
  beside the single-writer and strict members. The scan records no window site, so rule 1 covers it.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_backops.o)` (inferred): 24 routines in a 118948-byte member,
  each prefixed `cachefs_backop_` or `cachefs_lookup_back`. They forward requests to the back file system. Zero
  window sites were recorded, and scope rule 1 removes the member's routines.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_frontops.o)` (inferred): 13 routines in a 13732-byte member,
  each prefixed `cachefs_frontop_`, for example `cachefs_frontop_lookup` and `cachefs_frontop_rename`. They act
  on the cache's front file system. The scan found no register access, so rule 1 lists the member.
- `IP27/usr/cpu/sysgen/IP27boot/cachefs.a(cachefs_icrash.o)` (inferred): one routine, `cachefs_icrash`, in a
  25028-byte member. It is the crash-analysis counterpart of the autofs hook above, with the same zero-site
  result. Scope rule 1 excludes the routine.
- `IP27/usr/cpu/sysgen/IP27boot/cachefsidbg.o` (inferred): 30 routines in a 44192-byte object, mostly debugger
  printers such as `idbg_cachefscache`, `idbg_fscache` and `print_cachefs_cnodes`. They print cache state for the
  kernel debugger and touch no device register. Rule 1 excludes them.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_attr.o)` (inferred): two routines, `dm_get_fileattr` and
  `dm_set_fileattr`, in a 4628-byte member. They read and write the data-management attributes of a file. The
  scan records zero window sites, and the Data Management API sits under scope rule 1.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_bulkattr.o)` (inferred): four routines in a 5652-byte member,
  `dm_init_attrloc`, `dm_get_bulkattr_rvp`, `dm_get_dirattrs_rvp` and `dm_get_bulkall_rvp`. They return batches
  of attributes to an application. The scan found no window access.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_config.o)` (inferred): two routines, `dm_get_config` and
  `dm_get_config_events`, in a 4868-byte member. They report which events and limits the data-management
  interface supports for a file system. Zero window sites, so rule 1 removes them.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_dmattr.o)` (inferred): seven routines in a 6932-byte member, from
  `dm_set_dmattr` and `dm_get_dmattr` to `dm_set_inherit` and `dm_clear_inherit`. They store named
  data-management attributes on files and directories. No window access was recorded.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_event.o)` (inferred): ten routines in a 14116-byte member, for example
  `dm_send_mount_event`, `dm_send_unmount_event` and `dm_create_userevent`. They build and queue data-management
  events to the sessions that asked for them. Zero window sites were recorded for the member.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_handle.o)` (inferred): three routines in a 5156-byte member,
  `dm_create_by_handle`, `dm_mkdir_by_handle` and `dm_symlink_by_handle`. They create objects named by a
  persistent handle instead of a path. The scan records no register access.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_hole.o)` (inferred): three routines in a 5124-byte member,
  `dm_probe_hole`, `dm_punch_hole` and `dm_get_allocinfo_rvp`. They query and free the unallocated ranges of a
  file. Zero window sites, and rule 1 lists the member.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_io.o)` (inferred): four routines in a 5556-byte member, among them
  `dm_read_invis_rvp`, `dm_write_invis_rvp` and `dm_sync_by_handle`. They move file data without an event
  being sent. The scan found no device window reached by these routines.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_mountinfo.o)` (inferred): four routines in a 10676-byte member,
  `dm_fsys_vector`, `dm_query_fsys_for_vector`, `dm_code_level` and `dm_enosys`. They hold the table of file-system
  entry points the interface calls and the stub for an unsupported one. No window site was recorded.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_region.o)` (inferred): two routines in a 4644-byte member,
  `dm_get_region` and `dm_set_region`, which read and write the managed-region list of a file. Scope rule 1
  removes both.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_register.o)` (inferred): 26 routines in a 29012-byte member. They cover
  the registration of a file system (`dm_add_fsys_entry`, `dm_remove_fsys_entry`) and the path-to-handle and
  handle-to-vnode conversions. No window access was recorded.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_right.o)` (inferred): 20 routines in a 19844-byte member, including
  `dm_init_tevp`, `dm_app_get_tdp` and `dm_change_right`. They track application rights and the event and
  token records behind them. The scan found zero window sites for this member.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_session.o)` (inferred): 32 routines in a 34148-byte member, starting
  with `dm_init` and including `link_session`, `dm_flush_events` and `dm_find_msg_and_lock`. They keep the list of
  open sessions and the events queued on each. Scope rule 1 removes these routines.
- `IP27/usr/cpu/sysgen/IP27boot/dmi.a(dmi_sysent.o)` (inferred): one routine, `dmi`, in a 13140-byte member. It is
  the system-call entry that dispatches the data-management calls to the routines above. Zero window sites.
- `IP27/usr/cpu/sysgen/IP27boot/dmiidbg.o` (inferred): 13 routines in a 18968-byte object, including
  `idbg_dmi_sessions`, `idbg_dmi_regs` and `idbg_dmi_equeue`. They print the session, register and event state of
  the data-management interface for the kernel debugger. No device register is touched.
- `IP27/usr/cpu/sysgen/IP27boot/efs.a(efs_bitmap.o)` (inferred): four routines in an 8740-byte member. `efs_findfree`
  (632 bytes) searches a cylinder group's free-block bitmap, and `efs_bmread` (76 bytes) and `efs_bmrelse` (32 bytes)
  get and release the buffer that holds one bitmap block. The fourth routine, `efs_bitfunc`, has no symbol size.
- `IP27/usr/cpu/sysgen/IP27boot/efs.a(efs_bmap.o)` (inferred): six routines in a 15284-byte member, among them
  `efs_bmapExtent` (992 bytes), `efs_bmapLogicalBlock` (2068 bytes), `efs_lbmap` (212 bytes), `efs_expand` (876 bytes)
  and `efs_clrbuf` (268 bytes). They map a file's logical block to a disk block through the extent records of the
  inode, extend the extent list and clear newly added buffers.
- `IP27/usr/cpu/sysgen/IP27boot/efs.a(efs_dalloc.o)` (inferred): five routines in a 13124-byte member: `efs_alloc`,
  `efs_grow` (592 bytes), `efs_move` (792 bytes), `efs_free` (280 bytes) and `efs_btoss` (148 bytes). They hand out
  and return data blocks for an EFS file, and `efs_move` relocates a file's blocks when it grows. The routine
  `efs_btoss` converts between byte and sector counts by its name.
- `IP27/usr/cpu/sysgen/IP27boot/efs.a(efs_dir.o)` (inferred): 16 routines in a 22804-byte member. The directory
  operations are `efs_dirlookup` (1344 bytes), `efs_direnter` (632 bytes), `efs_dirremove` (756 bytes),
  `efs_dirrewrite` (244 bytes) and `efs_readdir` (748 bytes), with block helpers `getdirblk`, `putdirblk` and
  `growdir`. `irix5_efs_fmtdirent` is the variant that writes directory entries in the IRIX 5 layout.
- `IP27/usr/cpu/sysgen/IP27boot/efs.a(efs_ialloc.o)` (inferred): six routines in a 10804-byte member. `efs_pickcg`
  chooses a cylinder group for a new inode, `efs_scancg` (276 bytes) and `efs_scanchunk` (996 bytes) search it for
  a free inode, and `efs_ialloc` and `efs_ifree` allocate and release the inode. `efs_goodcg` tests a group's
  suitability.
- `IP27/usr/cpu/sysgen/IP27boot/efs.a(efs_iget.o)` (inferred): nine routines in a 12340-byte member. `ihashinit`
  sets up the in-core inode hash, `iget` (1168 bytes) finds or loads an inode, and `iput` (44 bytes) drops a
  reference. `ilock`, `ilock_nowait` and `iunlock` take and release the inode lock, and `iflush` and `ireclaim`
  write back and free an inode that is no longer referenced.
- `IP27/usr/cpu/sysgen/IP27boot/efs.a(efs_inode.o)` (inferred): 20 routines in a 26484-byte member. `efs_iread`
  (464 bytes) and `efs_iupdat` (1400 bytes) move an on-disk inode to and from memory, `efs_itrunc` (1716 bytes)
  truncates a file's extents, and `efs_readindir` and `efs_writeindir` handle indirect blocks. Allocation of new
  inodes goes through `efs_icreate` (592 bytes) and `efs_iformat` (592 bytes), and the extent helpers
  `efs_alloc_extent`, `efs_realloc_extent` and `efs_free_extent` sit alongside them.
- `IP27/usr/cpu/sysgen/IP27boot/efs.a(efs_subr.o)` (inferred): four routines in a 7716-byte member: `efs_error`
  (236 bytes) reports a file-system error, `efs_setcorrupt` (20 bytes) marks the file system damaged, `efs_asynchk`
  (228 bytes) checks an asynchronous request, and `efs_builddsum` builds a superblock checksum by its name.
- `IP27/usr/cpu/sysgen/IP27boot/efs.a(efs_vfsops.o)` (inferred): 21 routines in a 29588-byte member. The mount path
  is `efs_mount` (436 bytes), `efs_mountroot` (392 bytes) and `efs_mountfs` (1968 bytes), which calls
  `efs_checksb` (316 bytes) to validate the superblock. The rest are `efs_unmount` (512 bytes), `efs_statvfs`,
  `efs_sync` (1584 bytes) and `efs_sbupdate`, plus `devvptoefs` (720 bytes), which finds the EFS mounted on a device.
- `IP27/usr/cpu/sysgen/IP27boot/efs.a(efs_vnodeops.o)` (inferred): 37 routines in a 47396-byte member, the largest
  EFS object. They are the vnode operations the kernel calls on EFS files and directories: `efs_read` and
  `efs_write` with `efs_readi` (1136 bytes) and `efs_writei` (1500 bytes), `efs_lookup`, `efs_create`, `efs_rename`
  (2228 bytes), `efs_setattr` (1720 bytes) and `efs_fcntl` (780 bytes). `diostrat` (1364 bytes) and `efs_strategy`
  pass block I/O down to the device layer.
- `IP27/usr/cpu/sysgen/IP27boot/lofs.a(lofs_icrash.o)` (inferred): one routine, `lofs_icrash`, in a 12644-byte member.
  Its `_icrash` suffix matches the crash-analysis hooks that other file-system members of this set carry. The symbol
  table gives the routine no size.
- `IP27/usr/cpu/sysgen/IP27boot/lofs.a(lofs_subr.o)` (inferred): eight routines in a 12548-byte member. `makelonode`
  (988 bytes) and `makelfsnode` (412 bytes) create the loopback nodes that stand in front of a directory tree mounted
  at a second path, `freelonode` (468 bytes) and `freelfsnode` (156 bytes) release them, and `lfsfind` (48 bytes) looks
  one up. `lnode_flush` (360 bytes) writes a node's state back, and `lofs_realvfs` (72 bytes) returns the file system
  under a node.
- `IP27/usr/cpu/sysgen/IP27boot/lofs.a(lofs_vfsops.o)` (inferred): six routines in an 11668-byte member: `lofs_init`,
  `lofs_mount` (704 bytes), `lofs_unmount` (328 bytes), `lofs_root` (40 bytes), `lofs_statvfs` (200 bytes) and
  `lofs_sync` (196 bytes). They are the mount, unmount, root, statistics and sync entry points of the loopback file
  system.
- `IP27/usr/cpu/sysgen/IP27boot/lofs.a(lofs_vnops.o)` (inferred): 42 routines in a 31012-byte member, the largest
  loopback object. They are the vnode operations of loopback nodes, led by `lofs_lookup` (1292 bytes), `lofs_map`
  (224 bytes), `lofs_rename` (200 bytes), `lofs_attrget` (204 bytes) and `lofs_attrset` (148 bytes). The `realvp`
  routines, including `lofs_non_lofs_realvp` (76 bytes), hand back the vnode a loopback node stands for.
- `IP27/usr/cpu/sysgen/IP27boot/namefs.a(namevfs.o)` (inferred): 12 routines in a 19492-byte member. `nm_mount`
  (1184 bytes), `nm_unmount` (716 bytes), `nm_unmountall` (528 bytes), `nm_root` (60 bytes) and `nm_statvfs`
  (188 bytes) make up the mount interface of the name file system, which attaches an open stream descriptor at a
  path. `nameinsert`, `namefind`, `nameremove`, `nmgetid` (212 bytes) and `nmclearid` (116 bytes) keep the table of
  attached names and hand out their identifiers.
- `IP27/usr/cpu/sysgen/IP27boot/namefs.a(namevno.o)` (inferred): 21 routines in a 21476-byte member, the vnode
  operations of an attached name node. Among them are `nm_open`, `nm_close` (212 bytes), `nm_getattr` (288 bytes),
  `nm_setattr` (656 bytes), `nm_access` (332 bytes) and `nm_poll` (168 bytes). `nm_link` is 8 bytes long: a return with
  the constant 18 set in its delay slot and no other work.
- `IP27/usr/cpu/sysgen/IP27boot/fifofs.a(fifosubr.o)` (inferred): 17 routines in a 19812-byte member. `makepipe`
  (184 bytes) and `fifovp` (552 bytes) create the node for a pipe or a named FIFO, `fifo_initlocks` and
  `fifo_cr_lock` set up the lock records that serialize readers and writers, and `fifogetid` (192 bytes) and
  `fifoclearid` (128 bytes) manage the identifiers of named FIFOs. `fifofind` and `fifoinsert` keep the table of
  live FIFOs.
- `IP27/usr/cpu/sysgen/IP27boot/fifofs.a(fifovnops.o)` (inferred): 19 routines in a 29764-byte member, the vnode
  operations of a FIFO node. `fifo_read` (680 bytes) and `fifo_write` (904 bytes) are its two data paths, and
  `fifo_close` (1124 bytes) has the largest listed size. The rest include `fifo_open`, `fifo_ioctl` (616 bytes), `fifo_poll`
  (104 bytes) and `fifo_pathconf` (204 bytes).
- `IP27/usr/cpu/sysgen/IP27boot/hwgfs.a(hwgsubr.o)` (inferred): 11 routines in a 15428-byte member. `hwgfs_allocnode`
  (392 bytes), `hwgfs_getnode` (376 bytes) and `hwgfs_freenode` (380 bytes) manage the nodes of the hardware graph,
  `hwgfs_get_permissions` and `hwgfs_set_permissions` (352 bytes) read and write their permissions, and
  `hwgfs_vertex_destroy` (140 bytes) and `hwgfs_vertex_clone` (36 bytes) react when a graph vertex goes away or is
  copied. `hwginit` and `hwgfs_earlyinit` start the subsystem.
- `IP27/usr/cpu/sysgen/IP27boot/hwgfs.a(hwgvfsops.o)` (inferred): five routines in a 10612-byte member: `hwgmount`,
  `hwgunmount` (244 bytes), `hwgroot` (64 bytes), `hwgstatvfs` (240 bytes) and `hwgsync` (180 bytes). They mount the
  hardware-graph file system and answer its root, statistics and sync requests.
- `IP27/usr/cpu/sysgen/IP27boot/hwgfs.a(hwgvnops.o)` (inferred): 21 routines in a 25876-byte member, the vnode
  operations of the graph's directories and nodes. `hwglookup` (208 bytes), `hwg_dirlookup` (360 bytes),
  `hwgreaddir` (476 bytes) and `hwgcreate` (400 bytes) cover lookup, listing and creation. `hwgattr_get` (1044 bytes),
  `hwgattr_set` (536 bytes), `hwgattr_create`, `hwgattr_replace` and `hwgattr_remove` manage named attributes, and
  `cap_hwg_get` (136 bytes) and `cap_hwg_match` (92 bytes) check capabilities on a node.
- `IP27/usr/cpu/sysgen/IP27boot/fsctl.o` (inferred): 13 routines in an 18336-byte object. `fscopen` (124 bytes),
  `fscclose` (152 bytes) and `fscioctl` (1844 bytes) open, close and serve requests on the file-system control
  node. `fsr_flush` (320 bytes), `fsr_inval_buf` (124 bytes) and `fsr_invalid` (272 bytes) flush and invalidate
  cached blocks, `invalidblocks` (152 bytes) handles a block list, and `irix5_to_fscarg` (64 bytes),
  `irix5_o32_to_fscarg` and `irix5_n32_to_fscarg` (160 bytes each) convert the argument record for each ABI.
- `IP27/usr/cpu/sysgen/IP27boot/specfs.a(specsubr_attr.o)` (inferred): five routines in an 8836-byte member:
  `spec_at_init`, `spec_at_lock` (76 bytes), `spec_at_unlock` (52 bytes), `spec_at_insert_bhv` (364 bytes) and
  `spec_at_free` (52 bytes). They set up, lock and free the attribute record of a special node, and
  `spec_at_insert_bhv` links a behaviour record into that node's chain.
- `IP27/usr/cpu/sysgen/IP27boot/specfs.a(specsubr_common.o)` (inferred): 20 routines in a 22180-byte member.
  `spec_cs_get` (580 bytes) and `spec_cs_makesnode` (556 bytes) find or create the common special node for a
  device, `spec_cs_attach` (132 bytes) and `spec_cs_delete` (240 bytes) attach and remove it, and `spec_cs_clone`
  (208 bytes) makes a clone. `spec_cs_device_hold` (72 bytes), `spec_cs_device_rele` (64 bytes) and
  `spec_cs_device_close` (340 bytes) keep the count of holds on the device, and `spec_cs_get_size` (12 bytes)
  returns its size.
- `IP27/usr/cpu/sysgen/IP27boot/specfs.a(specsubr_local.o)` (inferred): 21 routines in a 23396-byte member, the
  per-device table of special vnodes. `spec_get` (1220 bytes), `spec_makesnode` (1112 bytes), `spec_find` (200
  bytes), `spec_insert` (164 bytes) and `spec_delete` (228 bytes) look up and maintain its entries, and
  `spec_make_clone` (272 bytes) builds a clone. `spec_dev_is_inuse` (196 bytes), `spec_ismounted` (72 bytes) and
  `spec_devsize` (72 bytes) answer questions about the device behind a node.
- `IP27/usr/cpu/sysgen/IP27boot/specfs.a(specvfsops.o)` (inferred): one routine, `spec_sync`, with no symbol size, in
  a 6948-byte member. It is the sync entry point of the special-file system.
- `IP27/usr/cpu/sysgen/IP27boot/specfs.a(specvnops_attr.o)` (inferred): 36 routines in a 25220-byte member, the
  vnode operations of the attribute layer. Many are short. `spec_at_read` (36 bytes) makes one call and then sets
  the return value to 19, and the larger ones are `spec_at_setattr` (1416 bytes), `spec_at_getattr` (324 bytes),
  `spec_at_access` (388 bytes) and `spec_at_attr_get` (196 bytes).
- `IP27/usr/cpu/sysgen/IP27boot/specfs.a(specvnops_common.o)` (inferred): 53 routines in a 41028-byte member, the
  vnode operations of the common layer. The larger ones are `spec_cs_setattr_vop` (1424 bytes), `spec_cs_open_hndl`
  (1364 bytes), `spec_cs_read_vop` (832 bytes) and `spec_cs_write_vop` (792 bytes). The `_hndl` and `_vop` suffixes
  show that each operation has a handle form and a vnode form, and `spec_cs_mac_label_get` (80 bytes) reads a label.
- `IP27/usr/cpu/sysgen/IP27boot/specfs.a(specvnops_local.o)` (inferred): 58 routines in a 56644-byte member, the
  largest object of the special-file set. Its operations are `spec_open` (632 bytes), `spec_read` (800 bytes),
  `spec_write` (728 bytes), `spec_ioctl` (124 bytes), `spec_getattr` (576 bytes), `spec_setattr` (428 bytes) and
  `spec_fcntl` (400 bytes). `spec_read_rsync` (1080 bytes) is a second read path whose name suggests a sync step, and
  `spec_fsync` (1136 bytes) has the largest listed size in this member.
- `IP27/usr/cpu/sysgen/IP27boot/udf.a(udf_attr.o)` (inferred): nine routines in a 14228-byte member. `udf_attr_get`
  (188 bytes), `udf_attr_set` (980 bytes), `udf_attr_list` (936 bytes), `udf_attr_remove` (500 bytes) and
  `udf_attr_remove_all` (444 bytes) read, write, list and remove a UDF file's extended attributes. The attributes
  live in a stream directory, which `udf_get_streamdir` and `udf_iattr_get` reach, and `udf_attr_fetch` (40 bytes)
  is the shared fetch step.
- `IP27/usr/cpu/sysgen/IP27boot/udf.a(udf_bitmap.o)` (inferred): four routines in a 9396-byte member: `udf_findfree`
  (696 bytes), `udf_bmread` (68 bytes), `udf_bmrelse` (32 bytes) and `udf_bitfunc`. They search a UDF partition's
  space bitmap for free blocks and read and release the bitmap block that holds the result, the same split as the
  EFS bitmap member.
- `IP27/usr/cpu/sysgen/IP27boot/udf.a(udf_dev_read.o)` (inferred): 26 routines in a 31604-byte member, the
  mount-time reader of UDF volume structures. `udf_read_descriptor` (972 bytes) reads descriptors from the device,
  `udf_read_mnt` (1176 bytes) reads the volume set, `udf_get_fentry` (1176 bytes) reads a file entry, and
  `udf_bmap_read` (1280 bytes) and `udf_apply_sparing` (408 bytes) map logical blocks to physical ones through the
  sparing table. Each `udf_get_` routine has a `udf_destroy_` partner that frees its record.
- `IP27/usr/cpu/sysgen/IP27boot/udf.a(udf_read.o)` (inferred): eight routines in a 17732-byte member: `udf_read`
  (152 bytes), `udf_readbuf` (164 bytes), `udf_readdir` (1044 bytes), `udf_lookup` (348 bytes), `udf_dirlookup`
  (1484 bytes), `udf_stream_dirlookup` (528 bytes) and `udf_dirisempty` (192 bytes). They form the read path, the
  directory read and lookup, and the lookup inside a stream directory of extended attributes.
- `IP27/usr/cpu/sysgen/IP27boot/udf.a(udf_util.o)` (inferred): 34 routines in a 28004-byte member, the helpers the
  other UDF objects share. `udf_checktag` checks a descriptor tag, `udf_checksum` and `udf_crc` (80 bytes) compute
  the checksums, and `udf_set_crc` and `udf_check_crc` (68 bytes each) store and verify CRCs. `udf_transname` (360
  bytes) converts file names, `udf_timetotimespec` (764 bytes) converts times, and `udf_permtomode` and
  `udf_modetoperm` (248 bytes each) convert permissions. The `udf_debug_` family prints state for the kernel
  debugger.
- `IP27/usr/cpu/sysgen/IP27boot/udf.a(udf_vfsops.o)` (inferred): 12 routines in a 23204-byte member: `udf_mount`
  (412 bytes), `udf_mountfs` (1412 bytes), `udf_unmount` (608 bytes), `udf_statvfs` (396 bytes), `udf_statdevvp`
  (644 bytes), `udf_vget` (172 bytes) and `udf_sync` (2340 bytes), with the small `udf_init`, `udf_root` and
  `udf_mntupdate` entry points. `udf_sync` has the largest listed size of the member.
- `IP27/usr/cpu/sysgen/IP27boot/udf.a(udf_vnops.o)` (inferred): 30 routines in a 44900-byte member, the vnode
  operations of UDF files and directories. `udf_rename` (2784 bytes) is the largest, followed by `udf_setattr` (1736
  bytes), `udf_create` (1416 bytes) and `udf_mkdir` (752 bytes). `udf_direnter` (692 bytes) and `udf_dirrewrite`
  (168 bytes) write directory entries back to the disk.
- `IP27/usr/cpu/sysgen/IP27boot/udf.a(udf_xlate.o)` (inferred): 38 routines in a 34660-byte member. `udf_swap`
  is the shared byte-order helper, and each `udf_xlate_` routine converts one on-disk UDF structure between its disk
  layout and its in-memory form. Examples are `udf_xlate_desc_tag` (436 bytes), `udf_xlate_file_entry` (800 bytes),
  `udf_xlate_fileset_desc` (1084 bytes), `udf_xlate_pri_vol_desc` (1040 bytes) and `udf_xlate_part_map_spare` (692
  bytes).
- `IP27/usr/cpu/sysgen/IP27boot/umfs.a(umfs_entry.o)` (established): one routine, `umfscall`, in a 3876-byte member.
  Read in full, it saves `ra`, makes one `jal` whose relocation names `nopkg`, restores `ra` and returns. It sets
  no return value of its own.
- `IP27/usr/cpu/sysgen/IP27boot/umfs.a(umfs_vfsops.o)` (established): twelve routines in an 8132-byte member, each
  a two-instruction return. `umfs_init` sets `v0` to zero in its delay slot. The other eleven, from `umfs_mount`
  to `umfs_quotactl`, set `v0` to 89 and return. Read in full.
- `IP27/usr/cpu/sysgen/IP27boot/umfs.a(umfs_vnodeops.o)` (established): 47 routines in an 18596-byte member, each
  a two-instruction return read in full. 41 set `v0` to 89, `umfs_map` sets it to 19, and five (`umfs_strategy`,
  `umfs_rwlock`, `umfs_rwunlock`, `umfs_link_removed` and `umfs_vnode_change`) return with no value set.

## IP30 boot set

The IP30 kernel build carries the same file-system members as the IP27 build, each compiled separately, so
each one has its own size and its own routines. Each entry below is read from that build's symbol table and
the census, and the window scan's access count is zero for every member listed here.

- `IP30/usr/cpu/sysgen/IP30boot/autofs.a(auto_subr.o)` (inferred): 20 routines in a 26532-byte member. `do_mount`
  (948 bytes), `makeautonode` (484 bytes) and `unmount_hierarchy` (444 bytes) build and tear down the automount
  tree under the trigger directories, and `send_unmount_request` (624 bytes) sends an unmount request to the
  automount daemon. The four `xdr_` routines encode the mount and unmount request and reply records. The scan
  records no window reference in this member.
- `IP30/usr/cpu/sysgen/IP30boot/autofs.a(auto_vfsops.o)` (inferred): nine routines in a 15508-byte member, the
  mount-table entry points of the autofs file system. `auto_mount` (1148 bytes) is the largest, with
  `auto_unmount` (328 bytes), `auto_statvfs` (196 bytes) and `autofs_init` (164 bytes) beside it. The census
  lists no register access for this member.
- `IP30/usr/cpu/sysgen/IP30boot/autofs.a(auto_vnops.o)` (inferred): 24 vnode operations in a 32020-byte member.
  `auto_lookup` (2372 bytes) is the largest, followed by `auto_readdir` (1208 bytes), `auto_rmdir` (884 bytes) and
  `auto_mkdir` (744 bytes). They answer file requests on autofs directories. Its access count in the scan is zero.
- `IP30/usr/cpu/sysgen/IP30boot/autofs.a(autofs_icrash.o)` (inferred): one routine, `autofs_icrash`, in a
  13396-byte member, and the symbol table gives it no size. Its name marks it as a crash-analysis hook for the
  autofs state. The scan records nothing reaching a chip window here.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_cnode.o)` (inferred): 15 routines in a 24996-byte member, for
  example `makecachefsnode` (2888 bytes), `cachefs_initcnode` (1760 bytes) and `valid_allocmap` (776 bytes). They
  keep the hash of cache nodes keyed by file id, find nodes with `cfind` and `cfind_by_fid`, and check the
  allocation map. Nothing in it reaches a chip window.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_resource.o)` (inferred): ten routines in a 15764-byte member.
  `cachefs_replacement` (1264 bytes) chooses which cached files to evict, `replace_front_file` (468 bytes) swaps
  one out, and `cachefs_allocblocks` (324 bytes) and `cachefs_allocfile` (248 bytes) reserve cache space. No
  window site was recorded for it.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_singlewrc.o)` (inferred): five routines in a 14692-byte member,
  all named `c_single_` followed by an operation. `c_single_check_cached_object` (1780 bytes) is the largest,
  with `c_single_modify_cached_object` (688 bytes) beside it. It is the single-writer consistency policy for
  cached objects, and its access count is zero.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_strict.o)` (inferred): five routines in a 13156-byte member,
  named `c_strict_` plus the same five operations. `c_strict_check_cached_object` (1300 bytes) and
  `c_strict_modify_cached_object` (724 bytes) are the bulk. The strict policy is the sibling of the single-writer
  member above, and the census has no register access for it.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_subr.o)` (inferred): 54 routines in a 75380-byte member, the
  largest cache-file member of this build. `release_fileheader` (2544 bytes) and `cachefs_cache_create` (1756
  bytes) lead, with `cachefsio_read` and `cachefsio_write` (1376 bytes each) doing the cache-side transfers and
  `cachefs_async_daemon` (940 bytes) running the background queue. Its allocation-map and directory routines keep
  block lists on the cache volume, not on any device window.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_fscache.o)` (inferred): nine routines in a 13076-byte member.
  `fscache_sync` (912 bytes) flushes cache objects, `fscache_destroy` (340 bytes) releases one, and the
  `fscache_hold` and `fscache_rele` pair (68 bytes each) adjust its reference count. The list helpers
  `fscache_list_add` and `fscache_list_remove` manage its membership. The scan's access count is zero.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_vfsops.o)` (inferred): 19 routines in a 32036-byte member, the
  mount and statistics entry points of the cache file system. `cachefs_mount` (4952 bytes) is the largest, with
  `cachefs_unmount` (628 bytes), `cachefs_vget` (888 bytes) and `cachefs_complete_mount` (552 bytes) following.
  `make_cachefs_fsid` (288 bytes) builds the file-system identifier, and the census lists no register access for
  this member.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_module.o)` (inferred): three routines in a 10916-byte member,
  `cachefs_init`, `cachefs_getstat` (24 bytes) and `cachefs_clearstat` (244 bytes). They register the module and
  read or reset its counters, and the scan's access count for it is zero.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_vnops.o)` (inferred): 45 vnode operations in a 79748-byte member,
  the front-side file operations of the cache. `cachefs_symlink` (2920 bytes) is the largest, then
  `cachefs_readdir` (2036 bytes), `cachefs_lookup_locked` (2016 bytes), `cachehit_lookup` (1996 bytes) and
  `cachefs_create` (1892 bytes). Nothing in the member reaches a chip window.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_noopc.o)` (inferred): five routines in a 10916-byte member, all
  named `c_nop_` plus an operation. `c_nop_modify_cached_object` (612 bytes) and `c_nop_check_cached_object`
  (404 bytes) are the largest. This is the no-op variant of the consistency policy: its operations take the same
  names as the strict and single-writer members, and the scan records zero access sites for it.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_backops.o)` (inferred): 24 routines in a 118916-byte member,
  one per operation sent to the back file system. `cachefs_backop_writevp` (800 bytes) and
  `cachefs_backop_readvp` (764 bytes) move file data, `cachefs_backop_getattr` (764 bytes) and
  `cachefs_backop_rename` (756 bytes) handle attributes and names, and `cachefs_getbackvp` finds the back vnode.
  The member is large only because of its operation count, and it holds no window access.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_frontops.o)` (inferred): 13 routines in a 13700-byte member, the
  operations that run against the cache's own front files. `cachefs_frontop_writevp` (340 bytes) and
  `cachefs_frontop_readvp` (316 bytes) are the data paths, `cachefs_frontop_rename` (248 bytes) renames a front
  file, and `cachefs_getfrontvp` (260 bytes) fetches its vnode. The census lists no register access here.
- `IP30/usr/cpu/sysgen/IP30boot/cachefs.a(cachefs_icrash.o)` (inferred): one routine, `cachefs_icrash`, in a
  24628-byte member. The symbol table gives the routine no size. It is the crash-analysis hook for the cache
  state, the sibling of the autofs hook above, and the scan records no chip window for it.
- `IP30/usr/cpu/sysgen/IP30boot/cachefsidbg.o` (inferred): 30 routines in a 44176-byte object, the kernel
  debugger commands for the cache. `prcnode` (748 bytes), `cflags_to_str` (524 bytes), `prcfsreq` (448 bytes)
  and `prfscache` (436 bytes) print cache nodes, request flags and the front-cache state. The debugger prints
  these structures and touches no device window.
- `IP30/usr/cpu/sysgen/IP30boot/cpr.a(ckpt_procfs.o)` (inferred): 50 routines in a 53700-byte member. The scope
  list files it with the file-system objects, but its routines are process checkpoint and restart calls:
  `ckpt_getpsinfo` (1088 bytes), `ckpt_memfork` (732 bytes), `ckpt_prioctl_thread` (728 bytes) and `ckpt_abort`
  (864 bytes) read and set process state through `/proc`. The scan records no window access in the member.
- `IP30/usr/cpu/sysgen/IP30boot/cpr.a(ckpt_sys.o)` (inferred): 22 routines in a 21924-byte member, the system-call
  side of the same checkpoint and restart code. `ckpt_sys` (648 bytes) is the dispatcher, with `ckpt_setexec`
  (520 bytes), `ckpt_restartreturn` (560 bytes) and `ckpt_getchildpids` (272 bytes) beside it. It is process
  state, not file-system code, and the census has no register access for it.
- `IP30/usr/cpu/sysgen/IP30boot/cpr.a(ckpt_util.o)` (inferred): nine routines in a 10932-byte member, the file-handle
  helpers the checkpoint code shares. `ckpt_fid` (284 bytes) and `ckpt_vp_open` (280 bytes) turn a vnode into a file
  identifier and reopen it, `ckpt_lookup_add` (304 bytes) and `ckpt_lookup` (100 bytes) keep the table of those
  identifiers, and `ckpt_setfd` (60 bytes) installs a descriptor. The member holds no register access in the scan.
- `IP30/usr/cpu/sysgen/IP30boot/dksc.o` (inferred): 60 routines in a 75280-byte object, a SCSI disk class driver
  rather than file-system code, although the scope list files it under the file-system rule. `dkscioctl` (2364
  bytes), `dkscopen` (1828 bytes), `dk_chkcond` (1672 bytes) and `dk_intr` (800 bytes) carry the disk requests,
  sense data and interrupts up through callback routines (`dk_callback_backend`, 756 bytes). Its adapter is reached
  through those callbacks, and the scan records zero window sites in the object.
- `IP30/usr/cpu/sysgen/IP30boot/dmi.a(dmi_mountinfo.o)` (inferred): four routines in a 10660-byte member. The
  data-management interface's mount query, `dm_query_fsys_for_vector` (1104 bytes), reads the vector of entry points
  that `dm_fsys_vector` (256 bytes) returns. `dm_enosys` (8 bytes) is the stub that reports an unsupported call.
  Nothing here touches a window.
- `IP30/usr/cpu/sysgen/IP30boot/dmi.a(dmi_register.o)` (inferred): 26 routines in a 28996-byte member, the
  registration side of the data-management interface. `dm_getall_disp` (704 bytes), `dm_handle_to_vp` (676 bytes)
  and `dm_set_disp` (656 bytes) are the largest, and `dm_add_fsys_entry` and `dm_remove_fsys_entry` (380 and 420
  bytes) add and drop a file system from the registry. The census shows no register access in this member.
- `IP30/usr/cpu/sysgen/IP30boot/dmi.a(dmi_session.o)` (inferred): 32 routines in a 34132-byte member that keep the
  open sessions and their event queues. `dm_enqueue` (1208 bytes) and `dm_get_events` (1032 bytes) are the queue
  entry points, `dm_respond_event` (404 bytes) answers one, and `dm_release_threads` (472 bytes) wakes the waiting
  threads. Its access count in the scan is zero.
- `IP30/usr/cpu/sysgen/IP30boot/dmiidbg.o` (inferred): 13 routines in an 18968-byte object, the kernel debugger
  commands for the data-management state. `idbg_dmi_event` (592 bytes) and `print_one_reglist` (520 bytes) print
  events and registrations, `idbg_dmi_sessions` (260 bytes) lists sessions, and `state_to_name` (176 bytes) and
  `right_to_name` (140 bytes) decode state and right values. The object reads and prints kernel memory only.
- `IP30/usr/cpu/sysgen/IP30boot/dms.a(dms.o)` (inferred): seven routines in a 15092-byte member, the device-style
  entry points: `dmsioctl` (2460 bytes), `dmsopen` (172 bytes), `dmsmap` (84 bytes), `dmspoll` (108 bytes) and
  `dmsclose` (92 bytes). The scope list files the member under the file-system rule, which does not name this kind
  of object. The scan records no window reference, so the routines stay out of the function table.
- `IP30/usr/cpu/sysgen/IP30boot/dms.a(dmskern.o)` (inferred): 81 routines in an 85492-byte member, the kernel side of
  the same service. Its pools of blocks and FIFOs run through `dms_pool_create` (4172 bytes), `dms_block_split` (968
  bytes), `dms_block_alloc` (660 bytes) and `dms_fifo_deq` (464 bytes). Routines such as `dms_block_start_dma` and
  `dms_block_end_dma` (8 bytes each) bracket transfers, and the notify and admin FIFOs carry the events. The
  members have no register access in the scan.
- `IP30/usr/cpu/sysgen/IP30boot/dms.a(dmrbcompat.o)` (inferred): 24 routines in a 16932-byte member, a compatibility
  layer over the same service that presents a ring of frames. `dmrb_attach` (716 bytes) binds a ring, and
  `dmrb_putvalid` (264 bytes), `dmrb_getnextvalid` (220 bytes) and `dmrb_getnextfree` (192 bytes) move frames
  between the valid and free lists. `dmrb_getpagelist` (100 bytes) returns the page list of a frame. The scan's
  access count is zero.
- `IP30/usr/cpu/sysgen/IP30boot/ds.a(dsreq.o)` (inferred): 18 routines in a 22196-byte member, the request side of
  the device-side service. `dsioctl` (2580 bytes) is the largest, with `task_glue` (648 bytes), `task_find` (220
  bytes), `ds_copyiov` (204 bytes) and `dma_lock` (172 bytes) beside it. The `irix5_` routines convert request
  records between the 32-bit and current layouts. The scope list places it with the file-system objects, but the
  routines are request and task plumbing, and no register access is recorded.
- `IP30/usr/cpu/sysgen/IP30boot/ds.a(dsglue.o)` (inferred): seven routines in a 10452-byte member, the glue layer
  between the request routines of the same service and their backend. `glue_start` (444 bytes),
  `glue_reserve` (428 bytes) and `glue_return` (336 bytes) move a request into and out of that layer, and
  `glue_getopt` (200 bytes) reads its options. The census has no register access for this member.
- `IP30/usr/cpu/sysgen/IP30boot/efs.a(efs_bitmap.o)` (inferred): four routines in an 8708-byte member. `efs_findfree`
  (632 bytes) searches a cylinder group's free-block bitmap, and `efs_bmread` (76 bytes) and `efs_bmrelse` (32
  bytes) get and release the buffer that holds one bitmap block. `efs_bitfunc` has no symbol size. The scan's access
  count is zero.
- `IP30/usr/cpu/sysgen/IP30boot/efs.a(efs_bmap.o)` (inferred): six routines in a 15268-byte member, among them
  `efs_bmapLogicalBlock` (2068 bytes), `efs_bmapExtent` (992 bytes), `efs_expand` (876 bytes), `efs_lbmap` (212
  bytes) and `efs_clrbuf` (268 bytes). They map a logical block of a file to a disk block through the inode's extent
  records, extend the extent list, and clear newly added buffers. The census records no window access.
- `IP30/usr/cpu/sysgen/IP30boot/efs.a(efs_dalloc.o)` (inferred): five routines in a 13108-byte member: `efs_alloc`,
  `efs_move` (792 bytes), `efs_grow` (592 bytes), `efs_free` (280 bytes) and `efs_btoss` (148 bytes). They hand out
  and return data blocks of an EFS file, and `efs_move` relocates a file's blocks when it grows. The scan records no
  window site for the member.
- `IP30/usr/cpu/sysgen/IP30boot/efs.a(efs_dir.o)` (inferred): 16 routines in a 22772-byte member. `efs_dirlookup`
  (1344 bytes), `efs_direnter` (632 bytes), `efs_dirremove` (756 bytes), `efs_dirrewrite` (244 bytes) and
  `efs_readdir` (748 bytes) are the directory operations, with block helpers `getdirblk` (552 bytes), `putdirblk`,
  `growdir` (340 bytes) and `dircorrupted`. `irix5_efs_fmtdirent` writes entries in the IRIX 5 layout. The member has
  no register access in the scan.
- `IP30/usr/cpu/sysgen/IP30boot/efs.a(efs_ialloc.o)` (inferred): six routines in a 10788-byte member. `efs_pickcg`
  (412 bytes) chooses a cylinder group for a new inode, `efs_scancg` (276 bytes) and `efs_scanchunk` (996 bytes)
  search it for a free inode, and `efs_ialloc` (596 bytes) and `efs_ifree` (292 bytes) allocate and release the
  inode. `efs_goodcg` tests a group's suitability. Its access count is zero.
- `IP30/usr/cpu/sysgen/IP30boot/efs.a(efs_iget.o)` (inferred): nine routines in a 12324-byte member. `iget` (1168
  bytes) finds or loads an inode, `iput` (44 bytes) drops a reference, and `ihashinit` sets up the in-core inode hash.
  `ilock`, `ilock_nowait` and `iunlock` take and release the inode lock, and `iflush` and `ireclaim` write back and
  free an inode that is no longer referenced. The scan records nothing reaching a window.
- `IP30/usr/cpu/sysgen/IP30boot/efs.a(efs_inode.o)` (inferred): 20 routines in a 26468-byte member. `efs_iupdat`
  (1400 bytes) writes an inode back to disk, `efs_iread` (464 bytes) reads one, and `efs_itrunc` (1716 bytes)
  truncates a file's extents. `efs_readindir` and `efs_writeindir` handle indirect blocks, `efs_whichzone` (608
  bytes) picks a zone, and `efs_icreate` and `efs_iformat` (592 bytes each) make new inodes. No window site was
  recorded.
- `IP30/usr/cpu/sysgen/IP30boot/efs.a(efs_vfsops.o)` (inferred): 21 routines in a 29460-byte member. The mount path is
  `efs_mount` (436 bytes), `efs_mountroot` (392 bytes) and `efs_mountfs` (1968 bytes), which calls `efs_checksb`
  (316 bytes) to check the superblock. The rest are `efs_unmount` (512 bytes), `efs_sync` (1584 bytes), `efs_statvfs`
  (308 bytes) and `efs_sbupdate` (348 bytes), plus `devvptoefs` (720 bytes), which finds the EFS on a device. The
  scan's access count for this member is zero.
- `IP30/usr/cpu/sysgen/IP30boot/efs.a(efs_vnodeops.o)` (inferred): 37 routines in a 47332-byte member, the largest EFS
  object of the build. They are the vnode operations the kernel calls on EFS files: `efs_rename` (2228 bytes),
  `efs_setattr` (1720 bytes), `efs_writei` (1500 bytes), `efs_readi` (1136 bytes), `efs_create` (868 bytes) and
  `efs_fcntl` (780 bytes). `diostrat` (1364 bytes) handles direct I/O requests. The member records no window access.

## Checkpoint, disk-set, disk-driver and FDDI objects (scope rule 1)

Rule 1 also lists the members below. Their routine names place them outside the file-system class: some are checkpoint and
restart code, some are disk and SCSI drivers, and the FDDI members are network code. Each entry says what the member is;
the rule that removes it is the one named in the entry. The scan was not run on these members, so the exclusion comes
from the object's role, as the rule text says. Labels: inferred, from the symbol table and undefined imports. No routine
body was read in full.

- `IP27/usr/cpu/sysgen/IP27boot/cpr.a(ckpt_procfs.o)` (inferred): the checkpoint interface through `/proc`, 50 routines in a
  53716-byte member. `ckpt_getpsinfo` (1088 bytes), `ckpt_getsiginfo` (868 bytes) and `ckpt_prioctl_thread` (728 bytes)
  read and set process state for the checkpoint, and `ckpt_abort` (864 bytes) cancels one. It imports the `/proc` address
  space calls `as_lookup` and `as_rele`, and it imports no chip routine.
- `IP27/usr/cpu/sysgen/IP27boot/cpr.a(ckpt_sys.o)` (inferred): the checkpoint and restart system calls, 22 routines in a
  21940-byte member. `ckpt_sys` (648 bytes) is the entry point, `ckpt_restartreturn` (560 bytes) returns a restored
  process to user mode, and `ckpt_setexec` (520 bytes) restores the exec image. Its imports include `execmap`, `prctl`
  and `pidfork`, and it drives no chip.
- `IP27/usr/cpu/sysgen/IP27boot/cpr.a(ckpt_util.o)` (inferred): the checkpoint helpers, nine routines in a 10948-byte
  member. `ckpt_lookup_add` (304 bytes) and `ckpt_lookup` (100 bytes) keep a table of saved objects, `ckpt_fid` (284 bytes)
  builds a file identifier and `ckpt_vp_open` (280 bytes) reopens a saved vnode.
- `IP27/usr/cpu/sysgen/IP27boot/dksc.o` (inferred): the SCSI disk driver, 60 routines in a 75336-byte object. `dkscioctl`
  (2364 bytes) is the control entry, `dkscopen` (1828 bytes) opens a disk, `dk_chkcond` (1672 bytes) and
  `dk_print_sense` (1120 bytes) handle SCSI check conditions, and `dk_intr` (800 bytes) completes requests. It imports the
  multipath calls `fo_max_paths` and `fo_scsi_device_update_generic`, and it reaches its controller through the device
  graph, with no chip routine named.
- `IP27/usr/cpu/sysgen/IP27boot/dms.a(dms.o)` (inferred): the data-migration device, seven routines in a 15236-byte member.
  `dmsioctl` (2496 bytes) is the control entry, and `dmsopen`, `dmsclose`, `dmspoll` and `dmsmap` complete the device
  entry points.
- `IP27/usr/cpu/sysgen/IP27boot/dms.a(dmscall.o)` (inferred): the call table of the migration device, six routines in an
  8852-byte member: `dmscall_add` (328 bytes), `dmscall_expand` (316 bytes), `dmscall_remove` (216 bytes), `dmscall_scan`
  (208 bytes) and `dmscall_destroy`. It imports `dms_add_log`, the migration log call.
- `IP27/usr/cpu/sysgen/IP27boot/dms.a(dmskern.o)` (inferred): the migration block pools in the kernel, 83 routines in an
  85236-byte member. `dms_pool_create` (3344 bytes) makes a pool, `dms_block_split` (968 bytes) divides a block,
  `dms_block_switch_pages` (756 bytes) moves pages between blocks, and `_dms_pool_destroy` (820 bytes) frees a pool. It
  imports `nasid_to_compact_node`, which places memory by node.
- `IP27/usr/cpu/sysgen/IP27boot/dms.a(dmslt.o)` (inferred): a lookup table for the migration pools, seven routines in an
  8900-byte member. `dmslt_create` (276 bytes), `dmslt_expand` (452 bytes), `dmslt_lookup` (200 bytes), `dmslt_remove`
  (176 bytes) and `dmslt_scan` (144 bytes) keep it.
- `IP27/usr/cpu/sysgen/IP27boot/dms.a(dmrbcompat.o)` (inferred): the compatibility layer of the migration pools, 24
  routines in a 16932-byte member. `dmrb_attach` (716 bytes) binds a handle, `dmrb_putvalid` (264 bytes) and
  `dmrb_getnextvalid` (220 bytes) manage the valid list, and `dmrb_getnextfree` and `dmrb_putfree` (192 and 164 bytes)
  manage the free list.
- `IP27/usr/cpu/sysgen/IP27boot/ds.a(dsreq.o)` (inferred): the SCSI request interface for user programs, 18 routines in a
  22196-byte member. `dsioctl` (2580 bytes) takes a request, `task_glue` (648 bytes) and `task_find` (220 bytes) match it to
  a task, and `dsopen` (296 bytes) opens the device. It imports `scsi_hwgraph_lock`, `scsi_dev_info_get` and the glue
  calls of `ds.a(dsglue.o)`, and it drives no chip itself.
- `IP27/usr/cpu/sysgen/IP27boot/ds.a(dsglue.o)` (inferred): the glue of the SCSI request interface, seven routines in a
  10468-byte member: `glue_start` (444 bytes), `glue_reserve` (428 bytes), `glue_return` (336 bytes), `glue_getopt`
  (200 bytes) and `glue_release` (148 bytes). It imports `scsi_dev_info_get` and `iomap`.
- `IP27/usr/cpu/sysgen/IP27boot/fddi.a(smt.o)` (inferred): the FDDI station management, 11 routines in a 14948-byte
  member. `smt_ioctl` (1696 bytes) is the control entry, `smt_new_st` (412 bytes) changes the station state, `smt_ler`
  (224 bytes) reports link errors, and `smt_timo` (196 bytes) is the timer. Its imports name no chip. This is network
  code, which rule 2 would name; the member is listed under rule 1.
- `IP27/usr/cpu/sysgen/IP27boot/fddi.a(pcm.o)` (inferred): the FDDI physical connection code, three routines in a
  15700-byte member. `host_pcm` (3896 bytes) is the largest, `pcm_code` (1500 bytes) runs the connection state machine,
  and `pcm_pc_signal` signals it. Its imports name no chip.
- `IP27/usr/cpu/sysgen/IP27boot/fddi.a(mpcm.o)` (inferred): a second physical connection routine set, two routines
  `moto_pcm` (1188 bytes) and `motopcm_code` in a 10596-byte member. It shares the station calls of `smt.o` and imports
  no chip routine.

## IP35 build: file-system, volume and checkpoint objects (scope rule 1)

The members below are the file-system, disk and checkpoint objects of the IP35 build that rule 1 removes. Each entry says what
the member is and which rule removes it. The scan was not run on these members, so the exclusion comes from the object's
role, as the rule text says. Labels: inferred, from the symbol table and undefined imports. No routine body was read in full.

- `IP35/usr/cpu/sysgen/IP35boot/autofs.a(auto_subr.o)` (inferred): the automount support routines, 20 routines in a 26468-byte
  member. `do_mount` (948 bytes) and `do_unmount` (416 bytes) mount and unmount a tree, `send_unmount_request` (624 bytes) talks
  to the automount daemon through an RPC client (`kclnt_create`, `kxdr_string`), and `makeautonode` (484 bytes) creates a
  node and attaches its behaviour with `bhv_insert_initial`. It drives no chip.
- `IP35/usr/cpu/sysgen/IP35boot/autofs.a(auto_vfsops.o)` (inferred): the automount file-system operations, nine routines in a
  15444-byte member. `auto_mount` (1148 bytes) and `auto_unmount` (328 bytes) are the mount and unmount entries, `auto_statvfs`
  (196 bytes) reports space, and `irix5_to_autofs_args` (144 bytes) converts the mount arguments from the IRIX 5 layout. It
  imports `vfs_insertbhv` and `vfssw`.
- `IP35/usr/cpu/sysgen/IP35boot/autofs.a(auto_vnops.o)` (inferred): the automount vnode operations, 24 routines in a 31956-byte
  member. `auto_lookup` (2372 bytes) resolves a name and may mount beneath it, `auto_readdir` (1208 bytes) lists a directory,
  and `auto_rmdir`, `auto_mkdir` and `auto_symlink` (884, 744 and 600 bytes) change it. It calls `do_mount` in `auto_subr.o`.
- `IP35/usr/cpu/sysgen/IP35boot/autofs.a(autofs_icrash.o)` (inferred): a crash-analysis hook with one 8-byte routine,
  `autofs_icrash`, in a 13508-byte member. The member's data symbol `autofs_icrash_struct` is the record the crash tools read.
  It imports nothing.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_cnode.o)` (inferred): the cache file-system nodes, 15 routines in a 24932-byte
  member. `makecachefsnode` (2888 bytes) builds a node, `cachefs_initcnode` (1760 bytes) initialises it, and `valid_allocmap`
  and `valid_file_header` (776 and 344 bytes) check the cache's allocation map and file header. It imports the front-directory
  calls `cachefs_create_frontdir` and `cachefs_lookup_frontdir`.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_resource.o)` (inferred): the cache space manager, ten routines in a 15700-byte
  member. `cachefs_replacement` (1264 bytes) chooses files to replace, `replace_front_file` (468 bytes) removes one,
  `cachefs_allocblocks` and `cachefs_allocfile` (324 and 248 bytes) reserve space, and `cachefs_checkfid` (280 bytes) checks an
  identifier. It imports the cache lock `cachefs_cachelock`.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_singlewrc.o)` (inferred): the single-writer caching policy, five routines in a
  14628-byte member. `c_single_check_cached_object` (1780 bytes), `c_single_init_cached_object` (1500 bytes) and
  `c_single_modify_cached_object` (688 bytes) check, set up and update a cached file, and `c_single_invalidate_cached_object` and
  `c_single_expire_cached_object` (160 and 140 bytes) drop one. Its operations table is `singlecfsops`.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_strict.o)` (inferred): the strict-consistency caching policy, five routines in a
  13092-byte member. `c_strict_init_cached_object` (1428 bytes), `c_strict_check_cached_object` (1300 bytes) and
  `c_strict_modify_cached_object` (724 bytes) follow the policy's rules, and `c_strict_invalidate_cached_object` (156 bytes)
  drops an entry. It asks the back end for attributes with `cachefs_backop_getattr`.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_subr.o)` (inferred): cache support routines, 54 routines in a 75316-byte member.
  `release_fileheader` (2544 bytes) releases a file header, `cachefs_cache_create` (1756 bytes) makes a cache, `cachefsio_read`
  and `cachefsio_write` (1376 bytes each) move cached data, and `fileheader_cache_find` (1144 bytes) searches the header cache.
  It calls the back-end operations `cachefs_backop_readdir`, `cachefs_backop_readvp` and `cachefs_backop_writevp`.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_fscache.o)` (inferred): the cache-file-system instance table, nine routines in a
  13012-byte member. `fscache_sync` (912 bytes) flushes a cache, `fscache_create` and `fscache_destroy` (348 and 340 bytes) make
  and remove one, `fscache_free_cnodes` (180 bytes) frees its nodes, and `fscache_list_find` (84 bytes) searches the list.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_vfsops.o)` (inferred): the cache file-system mount and unmount code, 19 routines
  in a 31972-byte member. `cachefs_mount` (4952 bytes) mounts a cache over a back-end file system, `cachefs_unmount` (628 bytes)
  takes it down, `cachefs_vget` (888 bytes) returns a vnode, and `cachefs_complete_mount` (552 bytes) finishes the mount. It
  It keeps its cache list and minor-number map in the data symbols `cachefs_cachelist` and `cachefs_minormap`.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_module.o)` (inferred): the cache file-system module start-up, three routines in
  a 10852-byte member. `cachefs_init` (420 bytes) sets up the zones and the lock state and calls `getudev`, `cachefs_clearstat` (244 bytes)
  resets the counters, and `cachefs_getstat` (24 bytes) reads them.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_vnops.o)` (inferred): the cache file vnode operations, 45 routines in a 79684-byte
  member. `cachefs_symlink` (2920 bytes), `cachefs_readdir` (2036 bytes), `cachefs_lookup_locked` (2016 bytes), `cachehit_lookup`
  (1996 bytes) and `cachefs_create` (1892 bytes) are the largest. It imports 125 names, including the back-end calls
  `cachefs_backop_*`.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_noopc.o)` (inferred): the no-cache caching policy, five routines in a 10852-byte
  member. `c_nop_init_cached_object` (1084 bytes), `c_nop_modify_cached_object` (612 bytes) and `c_nop_check_cached_object`
  (404 bytes) handle their objects with no cache store, and `c_nop_invalidate_cached_object` (20 bytes) is the shortest of them. Its operations
  table is `nopcfsops`.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_backops.o)` (inferred): the back-end operations, 24 routines in a 118852-byte
  member. `cachefs_backop_writevp`, `cachefs_backop_readvp`, `cachefs_backop_getattr` and `cachefs_backop_rename` (800, 764, 764
  and 756 bytes) call the real file system underneath the cache. It imports the version locks, `dnlc_purge_vp`, `vn_rele`, the spin-lock
  calls and `sv_wait_sig`.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_frontops.o)` (inferred): the front-end operations, 13 routines in a 13636-byte
  member. `cachefs_frontop_writevp` and `cachefs_frontop_readvp` (340 and 316 bytes) read and write the cached copy, and
  `cachefs_getfrontvp` (260 bytes) returns its vnode. It imports seven names, none of them a device.
- `IP35/usr/cpu/sysgen/IP35boot/cachefs.a(cachefs_icrash.o)` (inferred): a crash-analysis hook with one 8-byte routine
  `cachefs_icrash`, in a 24660-byte member. Its data symbol `cachefs_icrash_struct` is the record the crash tools read.
  It imports nothing.
- `IP35/usr/cpu/sysgen/IP35boot/cachefsidbg.o` (inferred): the debugger commands for the cache file system, 30 routines in a
  44112-byte object. `prtcnode` (748 bytes), `idbg_fileheader` (460 bytes) and `prcfsreq` (448 bytes) print cache nodes, file
  headers and requests, and `cflags_to_str` (524 bytes) names the flags. It registers them with `idbg_addfunc` and reads the
  cache list `cachefs_cachelist` and the vnode-type table `tab_vtypes`.
- `IP35/usr/cpu/sysgen/IP35boot/cpr.a(ckpt_procfs.o)` (inferred): the checkpoint interface through `/proc`, 50 routines in a
  53636-byte member. `ckpt_getpsinfo` (1088 bytes), `ckpt_getsiginfo` (868 bytes) and `ckpt_memfork` (732 bytes) read and
  change process state for a checkpoint, and `ckpt_abort` (864 bytes) cancels one. It imports the address-space calls
  `as_lookup` and `as_rele` and the timer state `ckptitimer`, and it drives no chip.
- `IP35/usr/cpu/sysgen/IP35boot/cpr.a(ckpt_sys.o)` (inferred): the checkpoint and restart system calls, 22 routines in a
  21860-byte member. `ckpt_sys` (648 bytes) is the entry point, `ckpt_restartreturn` (560 bytes) returns a restored process to
  user mode, `ckpt_setexec` (520 bytes) restores the exec image and `ckpt_diropen` (300 bytes) reopens a directory. It imports
  `execmap`, `exit` and the file-descriptor calls `fdaccess` and `fdsetattr`. No chip is driven.
- `IP35/usr/cpu/sysgen/IP35boot/cpr.a(ckpt_util.o)` (inferred): the checkpoint helpers, nine routines in a 10868-byte member.
  `ckpt_lookup_add` (304 bytes) and `ckpt_lookup` (100 bytes) keep a table of saved objects, `ckpt_fid` (284 bytes) builds a
  file identifier, and `ckpt_vp_open` (280 bytes) reopens a saved vnode. It imports `vfile_alloc` and `vfile_ready`.
- `IP35/usr/cpu/sysgen/IP35boot/dksc.o` (inferred): the SCSI disk driver, 60 routines in a 75248-byte object. `dkscioctl`
  (2364 bytes) is the control entry, `dkscopen` (1828 bytes) opens a disk, `dk_chkcond` (1672 bytes) and `dk_print_sense`
  (1120 bytes) handle SCSI check conditions, and it imports `biodone` for completion. It calls the multipath routine
  `fo_max_paths` and reaches its controller through the device graph, with no chip routine named. Rule 1 lists it, though its
  routines are a device driver's; the scope questions note this label.
- `IP35/usr/cpu/sysgen/IP35boot/dmi.a(dmi_mountinfo.o)` (inferred): the data-management mount table, four routines in a
  10596-byte member. `dm_query_fsys_for_vector` (1104 bytes) finds the file-system vector for a mount, `dm_fsys_vector`
  (256 bytes) is the vector table, and `dm_enosys` and `dm_code_level` (8 bytes each) return fixed values. It walks the
  file-system switch `vfssw`.
- `IP35/usr/cpu/sysgen/IP35boot/dmi.a(dmi_register.o)` (inferred): the data-management event registration, 26 routines in a
  28932-byte member. `dm_getall_disp` (704 bytes), `dm_set_disp` (656 bytes) and `dm_handle_to_vp` (676 bytes) read and set
  the event dispositions and convert handles to vnodes, and `dm_clrmount_callback` (520 bytes) clears a mount's registrations.
  It links and unlinks events with `dm_link_event` and `dm_unlink_event`. It drives no chip.
- `IP35/usr/cpu/sysgen/IP35boot/dmi.a(dmi_session.o)` (inferred): data-management sessions and their event queues, 32 routines in
  a 34068-byte member. `dm_enqueue` (1208 bytes) queues an event, `dm_get_events` (1032 bytes) returns queued events,
  `dm_release_threads` (472 bytes) and `dm_flush_events` (448 bytes) drain the queues, and `dm_add_fsys_entry` and
  `dm_remove_fsys_entry` change the file-system table. It keeps its sessions in `dm_sessions`.
- `IP35/usr/cpu/sysgen/IP35boot/dmiidbg.o` (inferred): the data-management debugger, two routines in an 18968-byte object,
  `dmiidbginit` and `dmiidbgunload` (116 bytes each). Its symbol table defines only those two, while the function table
  names 13 routines from the debug information (`idbg_dmi_event`, 592 bytes, is the largest). It imports `dm_registers`,
  `dm_sessions` and `idbg_addfunc` and `idbg_delfunc`.
- `IP35/usr/cpu/sysgen/IP35boot/dms.a(dms.o)` (inferred): the data-migration device, seven routines in a 15092-byte member.
  `dmsioctl` (2460 bytes) is the control entry, and `dmsopen`, `dmspoll` and `dmsinit` (172, 108 and 236 bytes) complete the
  device entry points. It imports the block calls `dms_block_alloc` and `dms_block_attach` and the admin event call
  `dms_admin_event`. No chip is driven.
- `IP35/usr/cpu/sysgen/IP35boot/dms.a(dmskern.o)` (inferred): the data-migration kernel core, 81 routines in an 83396-byte member.
  `dms_pool_create` (3368 bytes) makes a pool, `dms_block_split` (968 bytes) splits a block, `dms_print_block` (824 bytes)
  prints one, and `_dms_pool_destroy` (820 bytes) removes a pool. It reads the cache geometry it allocates against
  (`cachecolormask`, `cachecolorsize`, `boot_sidcache_size`) and flushes with `dki_dcache_wbinval`.
- `IP35/usr/cpu/sysgen/IP35boot/dms.a(dmrbcompat.o)` (inferred): the compatibility layer for the migration ring buffers, 24
  routines in a 16932-byte member. `dmrb_attach` (716 bytes) attaches a buffer, `dmrb_putvalid` (264 bytes) and
  `dmrb_getnextvalid` and `dmrb_getnextfree` (220 and 192 bytes) move entries through the ring. It imports the block and
  FIFO calls, `dms_fifo_enq` and `dms_fifo_deq` among them.
- `IP35/usr/cpu/sysgen/IP35boot/ds.a(dsreq.o)` (inferred): the SCSI request interface, 18 routines in a 22196-byte member.
  `dsioctl` (2580 bytes) is the control entry, `dsopen` (296 bytes) opens a device, and `task_glue` (648 bytes) and `task_find`
  (220 bytes) build and locate a request. It reserves and starts host-adapter work through the `glue_*` routines, and it
  reports command-length errors with `ds_report_cmdlen_err`.
- `IP35/usr/cpu/sysgen/IP35boot/ds.a(dsglue.o)` (inferred): the adapter glue for SCSI requests, seven routines in a 10388-byte
  member. `glue_start` (444 bytes) starts a request, `glue_reserve` (428 bytes) and `glue_return` (336 bytes) take and give back
  an adapter, and `glue_getopt` (200 bytes) reads an option. It imports `iomap`, `iounmap` and `dma_unlock`, and it defines
  the default glue table `glue_default`.
- `IP35/usr/cpu/sysgen/IP35boot/efs.a(efs_bitmap.o)` (inferred): the EFS free-block bitmap, four routines in an 8644-byte member.
  `efs_findfree` (632 bytes) searches the bitmap, `efs_bitfunc` (572 bytes) sets and clears bits through the bit-field calls
  `bbfset` and `bbfclr`, and `efs_bmread` and `efs_bmrelse` (76 and 32 bytes) read and release a bitmap block.
- `IP35/usr/cpu/sysgen/IP35boot/efs.a(efs_bmap.o)` (inferred): the EFS block mapping, six routines in a 15204-byte member.
  `efs_bmapLogicalBlock` (2068 bytes) maps a file block to a disk block, `efs_bmapExtent` (992 bytes) maps an extent, and
  `efs_expand` (876 bytes) grows a file. It imports `efs_alloc`, `efs_free` and `efs_readindir`.
- `IP35/usr/cpu/sysgen/IP35boot/efs.a(efs_dalloc.o)` (inferred): the EFS block allocator, five routines in a 13044-byte member.
  `efs_alloc` (1704 bytes) allocates blocks, `efs_move` (792 bytes) relocates data, `efs_grow` (592 bytes) extends a file and
  `efs_free` (280 bytes) releases blocks. It searches with `efs_findfree` and `efs_bitfunc`.
- `IP35/usr/cpu/sysgen/IP35boot/efs.a(efs_dir.o)` (inferred): EFS directories, 16 routines in a 22708-byte member.
  `efs_dirlookup` (1344 bytes) finds a name, `efs_dirremove` (756 bytes) removes one, `efs_readdir` (748 bytes) lists entries and
  `efs_direnter` (632 bytes) adds one. It uses the directory name cache through `dnlc_lookup_fast` and `dnlc_enter_fast`.
- `IP35/usr/cpu/sysgen/IP35boot/efs.a(efs_ialloc.o)` (inferred): EFS inode allocation, six routines in a 10724-byte member.
  `efs_scanchunk` (996 bytes) scans a chunk for a free inode, `efs_ialloc` (596 bytes) allocates one, `efs_pickcg` (412 bytes)
  picks the cylinder group, and `efs_ifree` (292 bytes) frees one. It calls `efs_icreate` for a new inode.
- `IP35/usr/cpu/sysgen/IP35boot/efs.a(efs_iget.o)` (inferred): EFS inode lookup and release, nine routines in a 12260-byte member.
  `iget` (1168 bytes) returns an inode for a vnode, `ireclaim` and `iflush` (256 bytes each) reclaim and flush one,
  `iinactive` (148 bytes) handles the last reference, and `efs_idestroy` releases it. It imports `efs_iread` and `efs_itrunc`.
- `IP35/usr/cpu/sysgen/IP35boot/efs.a(efs_inode.o)` (inferred): EFS inode I/O, 20 routines in a 26404-byte member.
  `efs_itrunc` (1716 bytes) truncates a file, `efs_iupdat` (1400 bytes) writes the inode to disk, `efs_readindir` (628 bytes)
  reads indirect blocks and `efs_whichzone` (608 bytes) finds a block's zone.
- `IP35/usr/cpu/sysgen/IP35boot/efs.a(efs_vfsops.o)` (inferred): the EFS mount and sync operations, 21 routines in a 29812-byte
  member. `efs_mountfs` (1968 bytes) mounts a volume, `efs_sync` (1584 bytes) flushes it, `efs_unmount` (512 bytes) unmounts it,
  and `devvptoefs` (720 bytes) finds the volume for a device vnode. It defines the file-system switch entry `efs_vfsops`.
- `IP35/usr/cpu/sysgen/IP35boot/efs.a(efs_vnodeops.o)` (inferred): the EFS vnode operations, 37 routines in a 47316-byte member.
  `efs_rename` (2228 bytes), `efs_setattr` (1720 bytes), `efs_writei` (1500 bytes) and `diostrat` (1364 bytes) are the largest.
  It defines the vnode-operation table `efs_vnodeops` and imports the buffer-cache calls `bread`, `bwrite` and `biomove`.

