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
  `nm_setattr` (656 bytes), `nm_access` (332 bytes) and `nm_poll` (168 bytes). `nm_link` is 8 bytes long, the size
  of a bare return.
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
