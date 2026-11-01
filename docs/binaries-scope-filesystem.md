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
