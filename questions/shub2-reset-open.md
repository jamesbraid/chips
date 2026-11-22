# SHub 2: reset path past the memory test, and hardware reset values

Question. What does the SHub 2 PROM (snprom 10.54, SAL 1.54) need from the chip between "Testing memory" and the `Shell>` prompt, and what does the chip itself return at reset?

Status: **unknown** beyond the memory-test start. The reset entry (B1 to B8), the SAL_B entry vectors, the node-election and console start, and the memory and directory programming are read in [devices/shub/shub2.md](../devices/shub/shub2.md) and summarised in [shub2-model-rows.md](../devices/shub/shub2-model-rows.md). Route tag: software now (the images are in `root/sn2/`).

- Every register access after the "Testing memory" print (`0xff47a970`) up to the EFI start: NUMAlink interface set-up for one node, TIO and PIC discovery, interrupt registers the second-stage code uses. Route: the same Ghidra reading, routine by routine, with each register constant checked in the listing.
- SAL_A's selection of the SAL_B INIT and machine-check vectors for reasons 1 and 2 (the walk at `0xff6742e0`); taken from the SHub 1 reading. Route: read that walk.
- Reset values of every row, the real value of `V` (`SH2_ADDRESS_MODE`) and the revision and manufacturer encodings. Route: an Altix 4700 or 450 register capture, or a SHub 2 specification.
- Whether the lock registers (`...0208`, `...0188`) are read-to-take on hardware; a plain register that reads 0 satisfies the code.
- What the PAL call of index `0x208` does for the model beyond serving RAM at `0x100_0000` (inferred cache-as-RAM). Route: the PAL B images' handler, read as for SHub 1 in [pal-msrs.md](../software/firmware/snprom/pal-msrs.md#pal-520-0x208).
