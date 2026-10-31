# IRIX files this repository reads

Proprietary SGI files, copied by the reader from their own IRIX 6.5.30 install or media into `root/`. They are
never committed: `root/` is ignored. Paths only; the manifest `scripts/inventory-root.sha256` pins the exact
bytes the tables were made from, and `scripts/inventory.py` fails on any difference.

`root/` holds one tree per build, named by board: `IP27`, `IP30`, `IP32`, `IP35`, each mirroring the IRIX
file system, plus `spec/` (text extractions of the published specifications, see docs/specs.md).

```files
IP27/unix
IP27/usr/cpu/sysgen/IP27boot/kernel.o
IP30/unix
IP30/usr/cpu/sysgen/IP30boot/kernel.o
IP30/usr/cpu/firmware/IP30prom.bin
IP30/sbin/stand/ide.IP30
IP35/usr/cpu/sysgen/IP35boot/kernel.o
IP35/usr/cpu/firmware/ip35prom.img
IP32/usr/cpu/sysgen/IP32boot/kernel.o
IP32/usr/cpu/sysgen/IP32boot/mace.o
IP32/usr/cpu/sysgen/IP32boot/os.a
IP32/usr/cpu/firmware/ip32prom.image
IP32/sbin/stand/ide.IP32
IP32/sbin/stand/symmon.IP32
```

What is held and what is not (each gap is a question in docs/open-questions.md):

- `IP27/unix` and `IP30/unix` are linked kernels with symbols and line tables. They carry every driver,
  including the Bridge, XBridge, PIC and TIOCP register accessors, Hub, Xbow and IOC3 code (IP27) and the HEART
  code (IP30). Each is one build, so a branch for another chip in it is code the build carries, not proof that
  machine uses it.
- `IP35` has only the kernel object `kernel.o`. The Bridge-family driver object, the Hub driver objects and
  the linked IP35 kernel are not held. The kernel object has Hub, node-interrupt and error code and unresolved
  references to the Bridge-family routines.
- `IP32` has the kernel object, `mace.o` and `os.a`; the CRIME driver archive is in the graphics workspace, not here.
- PROMs held: IP30, IP35 (a promgen64 container whose single segment `tools/promgen64.py` unpacks, checksum
  verified) and IP32. No IP27 PROM or I/O-board PROM is held.
- Diagnostics held: `ide` for IP30 and IP32, `symmon` for IP32. No `ide` for IP27 or IP35.
