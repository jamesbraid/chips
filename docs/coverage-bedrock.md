# Bedrock coverage: processor-interface error clear semantics

The Bedrock page records that the IRIX 6.5.30 IP35 kernel writes all ones to processor-interface `0x438` and `0x458`, zero
to `0x448` and `0x468`, and writes the handled bit (or all ones from `hub_error_clear`) back to `0x400`, and left open whether
those four are clear-on-read and whether the pending register is write-one-to-clear. Labels follow
[AGENTS.md](../AGENTS.md): **established**, **inferred**, **unknown**.

Source for this page: the Bedrock-family processor-interface development header shipped on the IRIX 6.5.30 media
(`usr/include/sys/SN/SN1`). Its statements are cited here in our own words; it is a vendor header, not a binary, a published
specification or a public driver, so every statement taken from it is graded **inferred** even where the IRIX accesses
agree with it. The public Hub header in the Linux IP27 port was also read for the older chip.

## What the header says, and what the kernel does

- **The error status words clear by writing, not by reading.** Each status register is not cleared at reset, and a write of
  any data to its paired "clear" address clears **both** status words of that processor (status 0 and status 1 together).
  The clear addresses are `0x438` (status 0, processor A) and `0x448` (status 1, processor A), `0x458` and `0x468` for B.
  Grade: **inferred**. The IRIX writes to those four addresses are consistent: writing all ones to one and zero to the
  other would be redundant under that rule, and a read of either is never needed. The Bedrock page's open question
  ("clear-on-read, as in the public Hub headers") has the wrong chip's rule: the **older Hub's** public header calls the same
  four offsets "clear on read", the Bedrock header says write-clear. They are different chips with the same offsets; the Hub
  statement must not be applied to the Bedrock (the Bedrock page already treats siblings as hypothesis).
- **The pending register at `0x400` is write-one-to-clear; a separate writable alias sits at `0x3f8`.** A read of `0x400`
  returns all error sources; storing to `0x400` clears every bit for which the data has a one; storing to `0x3f8` writes the
  unreserved bits directly (all but the uncorrectable-memory-error bit). Grade: **inferred**. This matches the kernel: the
  handler stores the single handled bit to `0x400`, `hub_error_clear` stores all ones, and neither store would make sense
  on a plain read/write register. The `0x3f8` alias is reached by no IRIX routine read (the census has no row there);
  its purpose is a test or reset path: **unknown**.
- **Status registers are not cleared at reset.** The header says so for the pending register and for each status word:
  software cannot assume zero after reset. **Inferred.**

## What stays unknown

| item | route | discriminating test |
|---|---|---|
| What a second error does to a status word whose valid bit is still set, beyond setting the overrun bit | the header describes the fields only | cause two errors back to back and read both words |
| Whether a read of `0x438` has any effect | silicon only | read it with an error latched, then read `0x430` |
| What the `0x3f8` writable alias is used for | no held software uses it | write a bit through `0x3f8` and watch the interrupt |
