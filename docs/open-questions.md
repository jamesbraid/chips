# Open questions

Each entry: the question, the routes already tried, the next route. When answered, the fact moves into its
chip page and the entry is deleted.

- **IP35 driver objects.** The held IP35 `kernel.o` has no Bridge-family, PIC or Hub-interrupt-hardware accessors
  of its own beyond the node code; the objects with the PIC accessors are not held. Tried: symbol table of
  `kernel.o`, the IP35 PROM. Next: add the IP35 boot-directory driver archives and the linked IP35 kernel to
  `root/` and rerun `tools/run.sh tools/configs/pic.json`.
- **IP27 and I/O-board PROMs.** None held. The Hub, Bridge and Xbow bring-up sequences are visible only in
  kernels and the IP30 and IP35 PROMs until one is added.
- **Chip numbering inside the shared Bridge-family accessors.** The accessors choose among four chips by a
  type field and by the identification word's part number. Which chip is which is inferred from the part
  numbers and offsets matching the Bridge, XBridge and PIC layouts; not read from a named source.
  Next: the XBridge and Crossbow specifications' identification-register sections (page images).
- **TIOCP.** Whether any product in scope carries it is not established. Tried: its part numbers appear only
  in the shared accessors. Next: Linux `pci-xtalk-bridge.c` and its history for the platform that uses it.
- **Hub, Bedrock, HEART, IOC3, IOC4 inventories.** Censuses not run (stub configs). Next: write each config's
  seeds (see HAIKU-BRIEF.md) and run `tools/run.sh`.
- **Model of a PROM's window base.** A PROM builds its window pointer at run time; the census recovers a
  pointer only where an identity-register probe shows it. Next: constant-fold the PROM's address setup.
