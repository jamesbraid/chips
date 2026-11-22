# SHub 2: reset path past the memory test, and hardware reset values

Question. What does the SHub 2 PROM (snprom 10.54, SAL 1.54) need from the chip between "Testing memory" and the `Shell>` prompt, and what does the chip itself return at reset?

Status: **partly settled**. The reset entry (B1 to B8), the SAL_B entry vectors, the node election and console start, and the memory and directory programming are read in [devices/shub/shub2.md](../devices/shub/shub2.md). The stretch from the memory test to the jump into EFI (progress `0x17` to `0x48`) is read for one node, no neighbours and no L2 in [devices/shub/shub2-to-shell.md](../devices/shub/shub2-to-shell.md), which carries the ready-to-model rows; the summary is in [shub2-model-rows.md](../devices/shub/shub2-model-rows.md). Route tag: software now (the images are in `root/sn2/`). Open from that reading:

- The L1 replies the post-test requests parse (`0x0003`, `0x0013`, `0x000e`, `0x0009`, `0x0006`, `0x0010`, `0x0012`, `0x0008`, and the SHub 2 requests `0x0005`, `0x0016`, `0x0017`): only `0x0001`, `0x0005`, `0x0016` and `0x0017` are decoded. Route: decode each caller's parse call (`0xff494680`) and check the L1 model.
- The weight value the export-compliance check takes for the processors (stored from the `0x0010` reply). Route: read `0xff4fc2a0` and the store it makes.
- NUMAlink with a neighbour (vector engine command and reply bits, router objects, routing tables). Route: a second reading of the vector read and write routines (`0xff419e80`, `0xff41ad30`) with a router present, and the router method table (`0xff5fd188`).
- TIO register bodies: method slots `0x120`, `0x2f8`, `0x2a8`, `0x308`, `0x288`, `0x318`, `0x2e0` of the TIO table (`0xff5fd508`) and the two corelet set-ups (`0xff4cae30`, `0xff513d10`, `0xff4caf50`, `0xff514a30`). Route: read them as the SHub routines were read; the Linux `tiocp` and `tioca` code is the check.
- The names of `0x2_2000_0000`, `0x2_2001_0018`, `0x2_2011_0008`, `0x1006_0000`, `0x1006_0280`, `0x1006_0480` and the NI fields at `0x5000_0000`, `0x5000_0010`, `0x5000_0048`: the PROM's register-name table holds them and was not decoded (no pointer to the name strings was found). Route: read the register decoder (`0xff4e6410`).
- What EFI and the SAL runtime need from the node after the jump (console through the SAL, the shell prompt). Route: the SHub 2 runtime component, read as for SHub 1.
- SAL_A's selection of the SAL_B INIT and machine-check vectors for reasons 1 and 2 (the walk at `0xff6742e0`); taken from the SHub 1 reading. Route: read that walk.
- Reset values of every row, the real value of `V` (`SH2_ADDRESS_MODE`) and the revision and manufacturer encodings. Route: an Altix 4700 or 450 register capture, or a SHub 2 specification.
- Whether the lock registers (`...0208`, `...0188`) are read-to-take on hardware; a plain register that reads 0 satisfies the code.
- What the PAL call of index `0x208` does for the model beyond serving RAM at `0x100_0000` (inferred cache-as-RAM). Route: the PAL B images' handler, read as for SHub 1 in [pal-msrs.md](../software/firmware/snprom/pal-msrs.md#pal-520-0x208).
