# The `xconn.o` pairing driver of the IP27 build

`xconn.o` (`IP27/usr/cpu/sysgen/IP27boot/xconn.o`, IRIX 6.5.30, a relocatable object) is a character driver that pairs two
open device instances so that each sees the other's readiness through `poll`. It reaches no hardware register. Each routine
below was read in full; addresses are offsets in `.text`.

State, as the routines use it. `xconn_devs` is a pointer to an array of 32-byte slots, `xconn_numdevs` (defined outside the
object) is the slot count and `xconn_free_devs` is the index of the first free slot, or -1. A slot holds a pollhead pointer at +0,
a mutex at +8, the index of the paired slot at +24 (-1 for none; a free slot uses it as the free-list link) and a halfword of flags
at +28. Flag values: 1 open, 2 opened through minor number 0, 4 has been paired, 8 set by an ioctl as described below. A global
mutex, the first `.srdata` slot, guards the free list. The `.rodata` string is "%s:  Cannot allocate %d devices.\n". Slots 0 and
1 are initialised by `xconn_start` but never handed out by `xconn_getdev`, because the free list starts at slot 2.

- `xconn_getdev` (`IP27/usr/cpu/sysgen/IP27boot/xconn.o` at 0x0, 92 bytes)
  takes the global mutex with `ddi_mutex_lock`, pops the first slot off the free list (`xconn_free_devs` becomes that slot's +24
  and the slot's +24 becomes -1), releases the mutex with `mutex_unlock` and returns the slot index, or -1 when the list is
  empty. Established.
- `xconn_freedev` (`IP27/usr/cpu/sysgen/IP27boot/xconn.o` at 0x5c, 76 bytes)
  takes a slot index in `a0`. Under the global mutex it stores the old `xconn_free_devs` at the slot's +24 and makes the
  slot the new head, so freed slots go on the front. Established.
- `xconn_lockpair` (`IP27/usr/cpu/sysgen/IP27boot/xconn.o` at 0xa8, 164 bytes)
  takes slot indices `a0` and `a1`; the caller already holds the mutex of `a0` and wants that of `a1`. When `a0` is below `a1` (a
  signed compare) it takes the second mutex with `ddi_mutex_lock` and returns 0. Otherwise it calls `mutex_trylock` on it and
  returns 0 when that returns nonzero. When that returns 0 it releases the first mutex, takes the second and then the first
  with `ddi_mutex_lock`, and returns 1: the first mutex was dropped for a while. Established. Inferred: a nonzero
  `mutex_trylock` result means the lock was taken, from the routine's use of it.
- `xconn_lockconn` (`IP27/usr/cpu/sysgen/IP27boot/xconn.o` at 0x14c, 184 bytes)
  takes a slot index `a0` whose mutex is held. It reads the paired index from +24 and returns 134 when it is -1. Otherwise it calls
  `xconn_lockpair` with the slot and the partner; a result of 0 returns 0. A nonzero result means the slot's own mutex was
  dropped, so it rechecks: when flag 1 of the slot has gone it releases the partner's mutex and returns 5, when the paired
  index is unchanged it returns 0, and otherwise it releases the partner's mutex and repeats with the new paired index (which
  returns 134 if that is now -1). Established.
- `xconn_start` (`IP27/usr/cpu/sysgen/IP27boot/xconn.o` at 0x204, 328 bytes)
  allocates `xconn_numdevs * 32` bytes with `kmem_alloc` (flags 1) into `xconn_devs`. When that gives 0 it calls `cmn_err`
  (level 4, the allocation string, the driver name `xconn`, the count) and carries on into the initialisation with the
  null pointer. It calls `init_mutex` on the global mutex and on the mutex of each slot (second argument 0, the name `xconn`,
  fourth argument -1). Slots 0 and 1 get flags 0 and a paired index of -1 and no pollhead store. Slots 2 upward get flags 0
  and a zero pollhead and are chained into the free list in ascending order, the last link -1; with fewer than three slots the
  list is just -1. Established.
- `xconn_open` (`IP27/usr/cpu/sysgen/IP27boot/xconn.o` at 0x34c, 256 bytes)
  takes a pointer to the device number in `a0`. Its result is 2 when `xconn_devs` is 0. It then takes the minor number with
  `geteminor`: minor 0 selects flags 3, minor 1 selects flags 1, any other minor gives 22. It calls `xconn_getdev` and gives 11
  when no slot is free. For a slot with no pollhead it calls `phalloc` (argument 0) and, when that gives 0, calls `xconn_freedev`
  and gives 12. Otherwise it stores the flags in the slot, rewrites the device number as `makedevice` of the old major and the
  slot index and gives 0. Each open of either minor so yields a fresh slot under a new minor number. Established.
- `xconn_close` (`IP27/usr/cpu/sysgen/IP27boot/xconn.o` at 0x44c, 308 bytes)
  takes the device number in `a0` and locks the slot's mutex. When flag 1 is clear it unlocks and returns 22. When the slot has
  a partner it calls `xconn_lockconn`; a result of 5 unlocks the slot and returns 5. A result of 0 means the partner is locked:
  it sets the partner's +24 to -1, calls `pollwakeup` on the partner's pollhead with events 16, unlocks the partner and sets its
  own +24 to -1. Any other result (134), like having no partner, skips that. Last it clears its own flags, unlocks, calls
  `xconn_freedev` and returns 0. The partner's flag 4 is left alone. Established.
- `xconn_ioctl` (`IP27/usr/cpu/sysgen/IP27boot/xconn.o` at 0x580, 764 bytes)
  takes the device number in `a0`, a request in `a1` and an argument in `a2`, locks the slot and returns 22 when flag 1 is
  clear. Request `0x786300` pairs the slot with the slot whose index is the argument: it needs flag 2 on the caller (else 22),
  returns 133 when the caller already has a partner, and 22 when the index is negative, not below `xconn_numdevs` or the
  caller's own. It takes the target's mutex with `xconn_lockpair`; when that dropped the caller's mutex and flag 1 or flag 2 of the caller
  is gone afterwards, it unlocks the target and returns 5. The target must have flag 1 and not flag 2 (else 22) and no
  partner (else 146). Then it stores the target's index in the caller's +24 and the caller's in the target's, sets flag 4 on
  both, and returns 0. Request `0x786301` returns 134 when the caller has no partner. Otherwise argument bit 0 clears flag 8 on
  the caller; with bit 0 clear, bit 1 sets flag 8 on the caller; bit 1 is ignored when bit 0 is set. When argument bit 2 is set
  it then calls `xconn_lockconn` and returns its result if that is nonzero; otherwise, when the partner's flag 8 was clear, it
  sets it and calls `pollwakeup` on the partner's pollhead with events `0x41` when the partner has flag 2 and events 4 when not,
  and it unlocks the partner. With bit 2 clear it returns 0. Any other request returns 22. Every exit unlocks the caller's
  mutex. Established.
- `xconn_poll` (`IP27/usr/cpu/sysgen/IP27boot/xconn.o` at 0x87c, 360 bytes)
  takes the device number in `a0`, the requested events in `a1`, an any-events-yet flag in `a2` and pointers for the returned
  events (a halfword), the pollhead and its generation word (`a3` to `a5`). It locks the slot and returns 22 when flag 1 is clear.
  For a slot with flag 2 the events start at 16 when flag 4 is set and the partner has gone and at 0 otherwise, and flag 8
  adds `a1 & 0x41`. For a slot without flag 2 they are 0 for a live partner with flag 8 clear and `a1 & 4` with flag 8 set; a
  gone partner gives 16 with flag 4 set and 0 without. It stores the events as a halfword through `a3` and, when they are zero
  and `a2` is zero, also stores the slot's pollhead through `a4` and the word at +12 of the pollhead through `a5`. It unlocks and
  returns 0. Established.
