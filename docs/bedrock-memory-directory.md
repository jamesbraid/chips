# Bedrock memory and directory (MD)

The memory and directory unit is the Bedrock's memory controller and coherence directory. Its registers start 7.5 MiB
into the node's register space, from the current-cell vector through the memory debug selector. Its register
layouts, with a grade on each field, are in [defs/bedrock_md.toml](../defs/bedrock_md.toml); the generated
reference is [gen/docs/bedrock_md.md](../gen/docs/bedrock_md.md). The register names and offsets are in the
[chip page](../chips/bedrock/README.md), which this page extends and does not repeat.

No Bedrock specification is held. Field positions, access widths and the reset statements come from the public
Linux 2.5.40 SN1 memory-directory header and its companion. The public Linux v2.5.0 SN1 address header gives the
backdoor formulas. Coherence behaviour comes from the Origin 2000 paper and the MIPS and NEC processor manuals,
and the self-test and ECC code tables come from the shipped boot firmware and its memory diagnostic. Every fact
below carries a grade. A grade of established here means a published source states the fact. Inferred means a
reasoned reading, a software expectation or a sibling-chip reading. Nothing here is a hardware read.

## Reset

- The refresh enable bit is cleared on reset, so the first DIMM operation must be a mode-register write. The
  header states this. The refresh enable and threshold survive a soft reset.
- Memory configuration, refresh control and directory configuration keep their contents through the soft reset
  that the header names. The header does not say which reset that is.
- The outgoing reply queue reads 12 entries in each header field and 24 in each data field at reset. The outgoing
  request queue defaults to four entries in each of its three fields.
- The header gives no reset value for the other registers. Those reset values are unknown.

## Banks and sizes

- A node has eight software banks of 1 GB. Software bank n starts at node offset n gigabytes.
- The four DIMM positions in memory configuration each hold two physical banks. Each position has a byte with two
  bank enables, a DRAM width bit and a size code.
- Size codes in the companion header: 0 empty, 1 is 64 MB, 2 is 128 MB, 3 is 256 MB, 4 is 512 MB and 5 is 1 GB.
  The register header's rule is 64 MB times a power of two, which agrees. The companion is partly carried over
  from an earlier machine, so the code table is inferred.
- The bank-select field maps locational banks to software banks by exclusive-or.
- The header says software must ask the system controller whether a DIMM is x4 or x8/x16 before it sets the
  width. The header gives no encoding of the width bit.

## Backdoors into the directory and the ECC

The public SN1 address header defines carriers that software uses to reach the unit's storage through ordinary
loads and stores. The formulas are established as header facts. What the carriers hold is graded below.

- **Directory word.** The directory word for an ordinary physical address `pa` is at the Hub special space base
  plus seven eighths of 8 GiB, plus the node number bits, plus `(pa >> 3) & 0x3ffffff0`. Each 128-byte memory line
  has one 64-bit directory word, so words are on a 16-byte stride. For node zero the words begin at uncached
  address `0x90000001c0000000`, derived from the formula.
- **Page counter.** The header names an entry 8 bytes past the directory word, in each 16-byte slot. The header
  gives its address and says that counter and protection entries use four interleaves at a 16-byte stride. It
  gives no counter fields, increment or saturation rules, and no alias rule. Its contents are unknown.
- **Protection entry.** The protection accessor adds 0x408 to the seven-eighths base. It selects one entry per
  16 KiB page, using bits 8:7 of the physical address for one of four interleaves. The header gives no meaning for
  the entry's bits, so access enforcement is unknown.
- **Memory ECC entry.** Five eighths of the node space holds one check byte per doubleword:
  `(pa & NASID_MASK) | 5/8 * 8 GiB | (((pa >> 3) & 0x3fffffff) ^ 7)`. The halfword form uses `^ 6` and covers two
  bytes. The header states the formula only.
- **Scrub carrier.** Four eighths of the node space uses the same index transform as the ECC entry. The header
  names it and says nothing more. The boot firmware's memory test reads check bytes through it, so a byte read
  must return the check byte. What a store there does is unknown.

Directory word formats (both flavors use bits 1:0 for the format):

- Format 0 is unowned, 1 is pointer, 2 is shared fine, and 3 is shared coarse in the standard flavor or shared sparse
  in the premium flavor. The directory configuration register's bit 0 selects the premium flavor, which uses 64-bit
  words. The standard flavor uses the low 32 bits.
- Pointer format: state in bits 4:2 (0 exclusive, 4 busy shared, 5 busy exclusive, 6 wait, 7 poisoned), first
  pointer in bits 15:8, and in a premium word bits 24:22 extend the pointer to bits 10:8. A pointer carries its node
  above three device bits. Device bit 1 marks an I/O owner. A processor's slice is device bit 0 plus device bit 2
  shifted down one, so slices 0 to 3 are device values 0, 1, 4 and 5.
- Shared-fine format: first tag in bits 4:2 (premium adds 23:22) and first vector in bits 15:8 (premium adds 31:24).
  A vector bit stands for one processor interface, not one processor. That reading is inferred from the
  diagnostics that exercise the format.

## Directory state and the protocol

The header names the states but not the transitions. The expected protocol is inferred for Bedrock from the
Origin 2000 Hub paper and from the processor side.

- Established for the Origin 2000 Hub, from Laudon and Lenoski (ISCA 1997, section 3.2): a read of an unowned line
  makes the reader the exclusive owner. A read of a shared line adds the reader to the sharers. A read of a line
  another processor owns ends shared between the two after an intervention. A read-exclusive or upgrade makes the
  requester the owner and invalidates other copies. An owner's write-back returns the line to unowned. Clean
  exclusive and shared copies are dropped without telling the directory.
- Inferred for Bedrock: the same protocol carries over. The directory transitions that the boot diagnostic checks
  are the protocol's, not a Bedrock specification.
- Established for the processor, from the NEC VR10000 and VR12000 manual (U10278EJ4V0UM00, revision 4) and the MIPS
  R10000 manual version 2.0: under cache algorithm 5 a load miss issues a coherent block read shared, which may
  return an exclusive line. Under algorithm 4 a load miss issues a coherent block read exclusive. A store miss
  issues a read exclusive, and a store to a shared copy issues an upgrade. Algorithm 3 and uncached references make
  no coherent request. Index and hit WriteBack Invalidate write a dirty block back and drop a clean one. Hit Invalidate drops the block without a write-back.
- Unknown: the busy and wait states on Bedrock, what the unit does to a word for an I/O requester, the
  premium-directory behaviour of each transition, and how an instruction fetch's read is classed.

## Error records and check codes

The memory error register holds an address, an eight-bit syndrome and a valid and overrun flag pair for each of
three kinds. The kinds are read correctable, write uncorrectable and read uncorrectable. The address and syndrome
belong to the earliest error of the highest priority. A kind's overrun is set when its address could not be
recorded. Bit 63 is set when uncorrectable errors reached different cache lines. The header's summary gives the
order of each pair's bits in one place only, so the pair order in the defs file is inferred. The directory error
record follows the same rule. Its valid bits are explicit in the header: 63 uncorrectable, 62 double-bit
protection, 61 correctable and 60 correctable protection, with the overrun bits 59 to 56 in the same order.

**Memory check code.** The unit stores one check byte per doubleword and checks it on reads. The code is the
boot firmware's memory diagnostic's own table, read from that shipped image. It is inferred to be the hardware
code, because the diagnostic checks the hardware against it. Its 72 columns, in order from data bit 0 through
data bit 63 and then the eight check bits, are:

```text
13 23 43 83 2f f1 0d 07 d0 70 4f f8 61 62 64 68
1c 2c 4c 8c 15 25 45 85 19 29 49 89 1a 2a 4a 8a
51 52 54 58 91 92 94 98 a1 a2 a4 a8 31 32 34 38
16 26 46 86 1f f2 0b 0e b0 e0 8f f4 c1 c2 c4 c8
01 02 04 08 10 20 40 80
```

Every column is distinct and of odd weight, so this is a single-error-correcting, double-error-detecting code. A
single-bit error is named by its syndrome. A double-bit error has a nonzero syndrome that names no bit.

**Directory check code.** The premium flavor's directory word carries seven check bits at 37:32 and 48. The
standard flavor carries six check bits at 21:16. The diagnostic's columns are inferred to be the hardware's. For the
premium flavor there is one column per word bit, in four rows of sixteen:

```text
1f 2f 37 3b 3d 3e 07 0b 0d 0e 13 15 16 19 1a 1c
7f 4f 57 5b 5d 5e 67 6b 6d 6e 73 75 76 79 7a 7c
01 02 04 08 10 20 23 25 26 29 2a 2c 31 32 34 38
40 43 45 46 49 4a 4c 51 52 54 58 61 62 64 68 70
```

The standard flavor's 32 columns are two rows: the premium table's first row, then its third row. The columns
exclusive-or to zero, so the all-ones word is a codeword.

**Checking on a read.** The header gives the error records. The behaviour that makes them fire is inferred from the
diagnostics:

- A write with ECC in force regenerates the check field. A write with the ignore bit set stores the word as written.
- A read of a line whose check byte or word disagrees is checked, unless the ignore bit is set. A correctable
  syndrome latches a correctable error and corrects the stored value. Any other nonzero syndrome latches an
  uncorrectable error.
- An uncached read of an uncorrectable doubleword takes a bus error, which the diagnostic requires. What a cached
  read of the same doubleword does is unknown. The processor manual says a double, single or partial-word read
  with the error indication posts a Bus Error, and a block read posts a Cache Error. Which one the Hub's reply
  produces for a cached read is not established.
- A data write to a marked line rewrites the entry and unmarks the line. The header does not state that. It is
  inferred from the diagnostics that write data and then read it back cleanly.
- The scrub carrier reads and writes the check byte of the block it covers. Its store semantics are unknown.

## Memory special space (fetch-and-op)

The processor's uncached attribute 2 selects the memory special space. The unit reaches ordinary node memory
through its fetch-and-op operations. The Bedrock header describes only the operation cache: two status registers,
each with a valid bit and a 27-bit address at bits 32:6. Each cached entry is one 64-byte block.

The operation encodings are inferred for Bedrock from the public SN2 header (Linux v5.3, `arch/ia64/include/asm/sn/mspec.h`),
where the block is 64 bytes and the first 8 bytes are the variable:

- A load at offset 0 returns the value. A load at 8 fetches and increments. A load at 16 fetches and decrements.
  A load at 24 fetches and clears.
- A store at 0 stores. A store at 8 or 16 increments or decrements and ignores the data. A store at 24 ands and a
  store at 32 ors.
- A store at 56 clears a cache entry. No consumer issues it, and the offsets 40 and 48 are never issued.
- Bit 2 of the address selects a 32-bit word of the variable. An operation then acts on that word only.
- The fetch-and-op test in the boot diagnostic confirms the 32-bit form and the word-wise increment and decrement.
  That is a software expectation, not a hardware read.

Whether Bedrock performs the operation in a cache, and what an operation on a line held in a processor cache does,
are unknown.

## Interrupts

- A correctable memory or directory error raises level-1 bit 61. The public interrupt tables give the number.
  The line that raises it on Bedrock is inferred from the diagnostic's wait on that bit.
- An uncorrectable memory or directory error raises error-interrupt pending bit 24. The processor-interface header
  assigns the bit to memory and directory errors, and its comment says it must be cleared in the MD unit. The line
  that raises it is inferred. The diagnostics wait on the bit through the monitor's interrupt path.
- The per-processor uncached-uncorrectable pair, bits 20 and 21, is in the processor-interface header. Whether the
  MD unit raises them is unknown.
- The error line follows pending bits under the mask, as the processor-interface page records. Which interface
  each error reaches is unknown.

## Self-test (software expectation)

The stock boot firmware uses the self-test registers in a fixed sequence. The sequence is a software expectation,
read from the shipped firmware's disassembly. It does not establish the hardware's command precedence, self-clearing
behaviour, reset status, algorithm or duration.

1. Write 0x4 to self-test control to reset the engine.
2. Write the pattern with bit 7 set to self-test data. The memory probe supplies pattern 0x5a, so the data word is 0xda.
3. Write a start word to self-test control. The start word is `((dimm << 5) & 0x60) | ((bank << 4) & 0x10) | 1`. The
   eight start words for DIMM-bank pairs 0/0 through 3/1 are 0x01, 0x11, 0x21, 0x31, 0x41, 0x51, 0x61 and 0x71.
4. Poll the status done bit until it sets or a deadline passes. The deadline is inferred to be about 625 ms.
5. On done with passed clear, read the error address, the directory error data and the four memory error data
   registers. If done never sets, write 0x2 to stop the engine and report a hang.

The firmware accepts a result only when both done and passed are set. A status word that stays zero is a timeout,
not a bad-memory report.

The zero-pattern phase, with data 0x80 (write control set, pattern zero, no other control), is inferred to write
zero through the selected bank and to clear its check marks. The name of the control bit supports that reading.
It has not been checked on hardware.

## Page migration

The IRIX 6.5.10 to 6.5.16 IP35 kernel reads the migration candidate through its clear alias and arms the
thresholds with bit 63 set. Software stores a down-counted difference threshold, `0x7fff` minus the desired
difference, and inferred from that the hardware compares against a down-counted value. Which reading is right is
unknown. The candidate's page field, initiator and valid bit are established as header facts. The clear alias
removes the candidate only by inference. The [chip page](../chips/bedrock/README.md) covers the IRIX side of the
same sequence.

## Refresh

The header gives the threshold as 3125 Bedrock clocks, which is 4096 refreshes per 64 ms (15.6 microseconds each).
The Origin 3000 architecture book says the interface refreshes about every 8 microseconds. The two disagree, and
the clock rate that would reconcile them is inferred. The conflict is unresolved. Refresh progression is not a
property the header describes beyond the threshold and the enable bit.

## Known gaps and what would settle them

- Field positions of the miscellaneous error words and the protocol error record. Route: the header's field
  tables for those registers, read in full.
- Reset values of every register except the header's statements above. Route: a Bedrock specification or a read of
  a running machine after firmware hand-off, with the explicit agreement that physical tests need.
- The width conflict in the issue-block debug selector. Route: the header's endian layouts against its prose.
- The order of the valid and overrun bits within each memory error flag pair, and the bits 54 to 52 that the
  diagnostic waits on. Route: the header's flag summary, read against the diagnostic.
- Whether the page counter at the `+8` offset counts, and what the protection entry's bits mean. Route: a
  hardware counter specification or a matching-revision measurement.
- Refresh interval: the 3125-cycle threshold against the book's 8 microseconds. Route: the Bedrock clock rate from
  a specification, or a measurement of refresh traffic.
