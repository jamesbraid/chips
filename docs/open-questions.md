# Open questions

Each entry: the question, the routes already tried, the next route. When answered, the fact moves into its
chip page and the entry is deleted.

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
- **IP35 reset window.** The routing rule that returns boot-PROM bytes for uncached memory-space fetches of physical
  0x1fc0xxxx after bank 0 is enabled, and whether any write ends it, are not visible in the PROM. Tried: full read of
  the reset, memory and jump-to-RAM path. Next: see [docs/questions/ip35-reset-window.md](questions/ip35-reset-window.md).
