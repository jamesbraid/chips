# Reset fetch, the compatibility segment and the Bedrock node number: what the PROMs and IRIX show about address decode

Questions answered, for the Origin 2000/Onyx2 node controller (Hub, IP27) and the Origin 300/3000 node controller
(Bedrock, IP35):

1. The R10000 starts at uncached 0xffffffffbfc00000, physical 0x1fc00000. What makes the node controller answer that
   with the boot flash and not with memory: a fixed decode, a register, or a region of the uncached space? Does a
   node-number write, or a memory-configuration write that puts a large bank over that offset, ever change which device
   answers? What do the PROMs do around those writes with respect to where they execute?
3. Can a reference through the 32-bit compatibility segment ckseg1 (uncached attribute 3, if the manual's rule is
   applied) reach a device widget or the Hub-special space, or is it always plain uncached memory or registers? Does the
   PROM or IRIX use ckseg1 for anything besides the reset fetch and early PROM code?
5. What node number does a Bedrock hold out of reset, and what is the first PROM access to the node-number field?

Grades are the repository's three: **E** established (the code path or table was read in the named bytes, or a published
page states it; address or page given), **I** inferred (a reasoned reading, reasoning given), **U** unknown (route to
settle it given). Companion pages: [IP27 node numbering](ip27/prom-node-numbering.md),
[IP35 reset window](../questions/ip35-reset-window.md), [IP35 boot flash](ip35/boot-flash.md),
[write timing](../questions/hub-bedrock-config-write-timing.md) and
[run-time decode changes](../questions/runtime-address-decode-changes.md). Register pages:
[Hub](../devices/hub/README.md), [Bedrock](../devices/bedrock/README.md),
[Bedrock local block](../devices/bedrock_lb/README.md).

## What was read

| Item | Identity |
|---|---|
| IP27 CPU PROM, "SGI Version 6.156 built 11:27:56 AM Nov 18, 2003" | `firmware/ip27prom.img`; unpacked segment (promgen64) sha256 `c2c69bf33c375b43ec7ac511fab41ddf595be1b6838ae717e58a9a1273437fdd`; addresses are load addresses, low 32 bits |
| IP35 CPU PROM, "SGI Version 6.210 built 02:33:51 PM Aug 26, 2004" | `firmware/ip35prom.img`; unpacked segment sha256 `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b` |
| IRIX 6.5.22 and 6.5.30 `unix.IP27` | sha256 `40e3f6246b58aa9b0856cf36cd868355c0c3cbc5e00bb7fc886b52ca4622dc0f` and `567474674eaa83d36431e70f079a35819d0bc3ce1d4b4a2758b8e891b5acc463` (rehashed) |
| IRIX 6.5.22 and 6.5.30 `unix.IP35` | sha256 `87563dbc0cbc35c590348f9ec12863884fc857f6ae3a991b803aa2a71dca791c` and `412a1aae553a348376bc30cacbaf65044de1745d30222f02ec5f88297dcb1dfa` (rehashed) |
| MIPS R10000 Microprocessor User's Manual, version 2.0 (October 10, 1996) | section 6.23 "Support for Uncached Attribute"; chapter 16 on xkphys, the compatibility spaces and the Cold Reset exception |
| US 6,751,698 B1 (Bedrock) | boot flash reached through the LBOOT and RBOOT spaces; read in [IP35 boot flash](ip35/boot-flash.md) |

Not read: PROM 6.211 (patch 7208) and the base-media IP27 PROM 6.11; neither is in the held roots, so nothing below is
a statement about them (**U**). No Hub or Bedrock specification is held, so every statement about what the chip does is
from software behaviour (**I**) or a published page, never a chip document. The IP35 PROM's BaseIO image and the IP27
monitor ELF inside the PROM were not read. One Library text search for the PROM's own boot notes returned a hit in
vendor source; it was not opened.

Method for the scans below: `objdump` listings of the two unpacked PROM segments and the four kernels (text sections),
a scan of every `lui` whose immediate is 0xa000 to 0xbfff followed by the first uses of that register, and an aligned
scan of every kernel data segment and both PROMs for 64-bit words 0xffffffffa0000000 to 0xffffffffbfffffff and, in the
kernels, 32-bit words 0xbfc00000 to 0xbfcfffff.

## 1. Reset fetch

### What the processor does (E, R10000 manual)

- The cold-reset vector is 0xffffffffbfc00000 in 64-bit mode, in unmapped uncached space, so no TLB or cache set-up is
  needed first (manual, "Cold Reset Exception").
- For an unmapped reference the uncached attribute driven on SysAD[59:58] comes from virtual address bits 58:57; for a
  mapped one it comes from the TLB entry's bits 63:62 (section 6.23). ckseg1 is the 64-bit-kernel form of kseg1: bits
  63:62 are 11 and bits 61:31 are all ones (chapter 16). Bits 58:57 are inside that run of ones, so the attribute is 3.
  **I**: the manual states each rule, and the value 3 is the combination. The manual never prints "ckseg1 carries attribute 3".

### What decides the answer (I, no register found; U for the rule)

- The first instruction is fetched before any PROM instruction can write anything: the word at 0x1fc00000 is
  `j 0x1fc00400` (IP35 6.210) or `j 0x1fc00800` (IP27 6.156). So whatever answers is a power-on decode. **E**.
- Neither PROM's reset path stores to anything that behaves like a boot-window enable. The stores before the TLB is
  set up go to the progress words (PI offset 0x108 plus 8 per processor), local-block scratch words, the network port
  reset and the cached-alias size ([IP35 reset window](../questions/ip35-reset-window.md), "Registers written in the
  reset path"; IP27 table in [node numbering](ip27/prom-node-numbering.md)). **E** for the stores, **I** that none is a
  window control (no register is named by anything held).
- Which part of the address space answers is therefore a fixed address-range decode, **I**. The range is the boot
  window of the node controller's special space: on IP35 physical 0x1fc00000 is offset 0x07c00000 into the 128 MB local
  boot space at 0x18000000 to 0x1fffffff (the public header values in [IP35 boot flash](ip35/boot-flash.md), **E** as the
  header's statement; the PROM reads its own image from 0x9000000018000000, **E** in the reset-window page); on IP27 the
  PROM's copy source is 0x9000000010000000 (local) and 0x9000000030000000 plus the node number shifted left 32 (remote),
  from [IP35 reset window](../questions/ip35-reset-window.md) (contrast section; not re-read here), so 0x1fc00000 is
  offset 0x0fc00000 into a boot space that ends at 0x1fffffff. **E** for the values, **I** that the reset address is the
  top of that window.
- The attribute does not appear to select between flash and memory at this physical range. The PROMs reach the same
  flash with attribute 0 and with attribute 3 (below). **E** for the accesses, **I** for the conclusion. So the rule
  is "address range", not "attribute 3 means memory".

| Access | Attribute | Physical | Answered by | Where in the PROM | Grade |
|---|---|---|---|---|---|
| reset fetch | 3 (ckseg1) | 0x1fc00000 | flash | 6.210 0x1fc00000; 6.156 0x1fc00000 | E that it is fetched; I that flash answers (the machines boot) |
| mapped code, TLB entry 62, ASID 1: EntryLo 0x7f0012 and 0x7f4012 | 0 (bits 63:62 clear) | 0x1fc00000, 0x1fd00000 | flash | written at 6.210 0x1fc05cb8, 6.156 0x1fc05978; everything from the first TLB set-up to the copy runs here | E for the entry; I that flash answers |
| RAM copy source | 0 (xkphys 0x90...) | LBOOT base | flash | 6.210 copy source 0x9000000018000000 | E (reset-window page) |
| PROM copy destination, and the uncached RAM mapping (entry 61, ASID 2, EntryLo 0x68016 and 0x6c016) | 3 (0x9600000001a00000) and 0 (the mapping) | 0x01a00000 | node memory | 6.210 entry 61 at 0x1fc05d34; 6.156 at 0x1fc059f4 | E for the entries; I that memory answers |
| KSEG1 fetches of TLB-helper text (below) | 3 (ckseg1) | 0x1fc05xxx | flash, with memory configured | 6.210 0x1fc05d0c and later hops, after the memory step at 0x1fc6a8a0 | E for the order; I for the result |

So at physical 0x1fc00000 flash answers for attribute 0 and attribute 3, and at 0x01a00000 memory answers for
attribute 0 and attribute 3 (a PROM that runs from entry 61 and copies to 0x9600000001a00000 depends on both). This is
a PROM-behaviour reading; the same two PROM addresses answered the same way on real machines is **I**, not a capture
read for this page.

Not settled (**U**): whether 0x1fc00000 and the boot-window base show the same flash because the flash decode wraps
(0x7c00000 on IP35, 0xfc00000 on IP27, so the period would have to divide 4 MB) or because a dedicated remap
sends the top of the window to the base. The IP35 patent describes 16 MB of flash as two 8 MB parts and does not say
whether reads wrap, which does not fit a 4 MB period but does not exclude a remap. The test that settles it is a read
of flash through the boot window at offsets 0, 0x400000 and 0x800000 beyond the image, compared with the reset-window
bytes.

### Does a node-number or memory-configuration write change what answers? (I, no counter-example)

- Node number. Both PROMs keep fetching and addressing through node-number-zero forms across the node-number write and
  fetch from flash after it:
  - IP27 6.156: "CPU switching to UALIAS" (0x1fc51fd4), TLB write for ASID 2 at 0x1fc51fe8 (setter 0x1fc059a0, RAM at
    0x01a00000, attribute-0 uncached, node bits zero), caches flushed (0x1fc52028 to 0x1fc52040), global barrier
    (0x1fc520b4), local barrier (0x1fc520bc), busy loop, the three stores to `NI_STATUS_REV_ID` at 0x1fc4d37c (call at
    0x1fc520dc), busy loop, local barrier, global barrier (0x1fc521c4), then the ASID 4 mapping that carries the new
    number (call at 0x1fc5220c, setter 0x1fc05a98). The processors that finish main then `jalr` to the reset-vector
    slot 0xbfc00010 (0x1fc52998) and run the slave loop from flash. **E** for the sequence (re-read here for the
    call sites; the full account is in [node numbering](ip27/prom-node-numbering.md)).
  - IP35 6.210: the node-number routine 0x1fc5c328 is called at 0x1fc61254; the helper that installs the node-qualified
    cached mapping, whose first act is a hop to KSEG1, is called at 0x1fc613ec, after the write; "Local %s entering slave
    loop" is followed by `jalr` to 0xbfc00010 at 0x1fc61af4. **E** for the call sites, **I** for their order relative
    to the write (addresses, not a traced flow).
  - IRIX never writes a node number ([run-time decode changes](../questions/runtime-address-decode-changes.md), **E**) and
    calls PROM slot 0xbfc00038 from `allowboot` after the numbers are final (section 3).
  - So KSEG1 and flash-window references keep working after the number changes. I: the PROMs would not run
    otherwise. Why they keep working (compatibility and node-bits-zero references always mean the local node, or flash
    is outside node numbering) is **U**. The cached-alias size the IP27 PROM sets (4 KB, store at 0x1fc01140) is far
    smaller than the 2 MB PROM-RAM window, so it does not explain the uncached node-zero reference ([node
    numbering](ip27/prom-node-numbering.md)).
- Memory configuration (IP35). The memory initialisation call is 0x1fc6a8a0, the copy is 0x1fc6a990 and the jump to the
  uncached RAM copy is 0x1fc6a9e4; each helper that writes a TLB entry runs its privileged instructions from the KSEG1
  alias of its own flash address (hops at 0x1fc05d0c, 0x1fc05d88, 0x1fc05e04), so flash is fetched through ckseg1 after
  bank 0 is enabled. **E** for the code. The PROM rejects a 256 MB bank ("256 MB dimm bank not supported on IP27 node
  boards.", test at 0x1fc51924, [IP35 reset window](../questions/ip35-reset-window.md)), so any bank 0 it accepts is 512
  MB or more and, starting at physical 0, covers 0x1fc00000 (**I**: the bank-size codes were read, but a bank that
  does not start at 0 was not excluded). Taken together, memory over the flash range does not stop flash answering a
  ckseg1 fetch (**I**). The [IP35 memory-config page](ip35/prom-md-config.md) has the write sequence; the word is
  written with the node's other processors parked in a rendezvous (**E** there).
- IP27 has the same shape: the slave loop re-creates the ASID 1 flash mapping after memory is configured and runs from it
  uncached (**E**, 0x1fc01c0c to 0x1fc04884 per [node numbering](ip27/prom-node-numbering.md)).
- No kernel store to a node number, region-present, cached-alias or memory-configuration register after `mlreset`
  ([run-time decode changes](../questions/runtime-address-decode-changes.md), **E** for resolved store sites), so nothing under IRIX changes
  the answer at run time.

## 3. The compatibility segment (ckseg1) in the PROMs and the kernels

### Uses found

A `lui` with immediate 0xa000 to 0xbfff followed by a 32-bit use is a kseg1 value; followed by `dsll` or `dsll32` it is a
piece of a 64-bit constant (0xa8 is the cached xkphys alias, not kseg1; 22 such sites in 6.156, 27 in 6.210 and 3 in each
kernel). **E** for each classification below (the listing was read at every site named).

| Use | Where | What it does | Grade |
|---|---|---|---|
| Reset vector | hardware | cold reset and NMI fetch | E |
| TLB-helper hop: `lui 0xa000; or $13,$13,$1; jr $13` | 6.156: 0x1fc05808, 0x1fc05858, 0x1fc0589c, 0x1fc05930, 0x1fc059bc, 0x1fc05a38, 0x1fc05ab4; 6.210: 0x1fc05b48, 0x1fc05b98, 0x1fc05bdc, 0x1fc05c70, 0x1fc05cfc, 0x1fc05d78, 0x1fc05df4 | each routine that writes or reads the TLB jumps to the ckseg1 alias of its own flash address first, so the mapping it is changing cannot be the one it fetches from; the return value is the address masked and re-or'd into the mapped window | E |
| Return-address alias | 6.156 0x1fc05b44 (`or $2,$2,$1`); 6.210 0x1fc05e84 | helper returns its argument with 0xa0000000 or'd in when the current ASID is 1, the "running from the flash window" state | E |
| Exception-entry alias | 6.156 0x1fc02544; 6.210 0x1fc01d24 | the exception path ors 0xa0000000 into an address inside the flash window and keeps it in a floating-point register; the same path then reads the node number from `NI_STATUS_REV_ID` (9 bits at 6.156 0x1fc02560; 8 bits at 6.210 0x1fc01d40) to address its save area | E for the code, I for the purpose |
| Calls through the jump table at the top of the image: `jalr` to 0xbfc00010 and 0xbfc00038 | 6.156: 0x1fc2af3c, 0x1fc52998 (slot 0x10), 0x1fc188b0 (slot 0x38); 6.210: 0x1fc30398, 0x1fc61af4 (slot 0x10), 0x1fc1a9c8 (slot 0x38) | re-entry into the slave loop and the launch call; slot roles from [node numbering](ip27/prom-node-numbering.md) | E |
| Comparisons against 0xbfc00000 and 0xbfd00000 | 6.156: 0x1fc00bdc, 0x1fc0279c, 0x1fc06128, 0x1fc0612c, 0x1fc312bc; 6.210: 0x1fc00600, 0x1fc01f78, 0x1fc063e0, 0x1fc063e4, 0x1fc3b36c | tests whether ErrorEPC, EPC or a pointer lies in the flash window | E for the sites, I for the purpose |

No load or store through a kseg1 base exists in either PROM, and neither PROM image holds a 64-bit word in
0xffffffffa0000000 to 0xffffffffbfffffff. **E** for the `lui` forms and the literal-pool scan. A kseg1 address built
some other way (a constant assembled by shifts from a small immediate) would not be found: shift-built constants were
checked for the small-immediate-then-`dsll` forms and the hits were xkphys masks, not kseg1 (**I**).

IRIX (6.5.22 and 6.5.30, both platforms; 6.5.30 addresses):

| Use | Where | What it does | Grade |
|---|---|---|---|
| `allowboot` calls PROM slot 0xbfc00038 | IP27 `lui 0xbfc0` at 0xc0000000000444a0, `jalr $30` at 0xc000000000044588 (6.5.22: 0x43c4c, 0x43d2c); IP35 `lui` at 0xc0000000000660a4, `jalr $22` at 0xc0000000000661d0 (6.5.22 `lui` at 0xc0000000000663b4) | start a processor through the PROM launch call; a ckseg1 instruction fetch of flash with all memory and the final node numbers in place | E |
| `_hook_exceptions` stores | IP27: `lui 0xa000` at 0xc00000000004cd4c, 0x4ce4c, 0x4cf1c, 0x4cf74 and `lui 0xa001` at 0x4cf7c (6.5.22: 0x4c3ac, 0x4c4ac, 0x4c57c, 0x4c5d4, 0x4c5dc); IP35: 0xc00000000006dd4c, 0x6df0c (6.5.22: 0x6df5c, 0x6e11c) | words of handler code are copied with `sw` to 0xa0000000, to 0xa0000100 and (IP27 only found) to 0xa0000180, plus a second base 0xa0010000 (IP27) or 0xa0008000 (IP35) chosen by a byte of a per-processor record; a store through ckseg1 to low physical memory of the node | E for the stores; I that the target is node memory and that the CPU later executes these words as exception vectors |
| Range tests | `kl_panic` (IP27 0xc000000000037804, 0x37978; IP35 0xc00000000005e6f8, 0x5e86c), `ibe_isbogus` (IP27 only, 0xc0000000001a8720), `kvtophys`, `kvtophyspnum`, `kvtophyspg` (IP27 0xc0000000001f1b20, 0x1f1a68, 0x1f1d7c; IP35 0xc0000000002a1e94, 0x2a1de0, 0x2a2100) | compare an address against 0xa0000000 to classify kseg0 against kseg1 and, in `kvtophys`, mask with 0x1fffffff to get the physical address | E for the compares; I for "treats ckseg1 as physical = low 29 bits" |
| Constants that are not CPU addresses | `mio_init` (0xb0000000, 0xbbb00000 or'd into a register field), `if_egopen` (0xa000008c and 0xa0000010 passed to a helper that works on the adapter's own memory), `rad_start_subsys` (0xa0000008 stored into descriptors), `if_xframeopen`, `_hal_fix_xaui_tx_lanes_sync` (0xb20000e4 passed to a PHY helper), MD5, pattern and test constants | not dereferenced by the CPU in the routine | I (callees of the helper calls not read in full) |

No kernel data segment holds a 64-bit word in 0xffffffffa0000000 to 0xffffffffbfffffff other than test patterns
(0xaaaaaaaa, 0xaaaa0300, 0xbcffffff, 0xbfe3ffff, and on IP35 0xa55aeaa5, 0xbc05ff00, 0xbc15f700), and none holds a 32-bit
word 0xbfc00000 to 0xbfcfffff. **E** for the scan. The kernels therefore never build a ckseg1 pointer to a widget, to the
Hub special space or to the Bedrock local block: they use the xkphys forms (0x92.., the Hub accessors in the PROM are
built `lui 0x9200`, `dsll`, `ori 0x100`, `dsll`; **E** in the PROM, not re-scanned in the kernels).

### Answer

- In the PROMs and in IRIX, a ckseg1 reference is only (a) the reset or NMI fetch, (b) an instruction fetch of the flash
  jump table or TLB-helper text, and (c) in IRIX, a store of exception handler code to low node memory. Nothing found
  reads or writes a widget, the Hub special space or a node-controller register through ckseg1. **E** for the absence in
  these five images.
- Whether the hardware would send a ckseg1 data reference to a widget or a node-controller register if software made
  one is **U**: no code here makes it. The only software that might is a driver that maps a low-512 MB resource through
  kseg1, as the public Linux kernel's generic ioremap does; that was not read for this page. The discriminating test is a ckseg1
  load of a low physical address inside widget 8's window (0x08200000 is widget 8 plus 0x200000) on a node whose
  memory covers that address, comparing the data with a read of the same physical address through attribute 3 and
  attribute 1 xkphys forms.
- The IRIX vector stores show that ckseg1 data stores to physical 0x0, 0x100 and 0x180 are expected to land in node
  memory (**I**), and the PROM's flash fetches show that ckseg1 at 0x1fc00000 reaches flash (**I**). Both fit "a
  decode on the low 512 MB by address range, with the boot window carved out". They do not show that attribute
  3 alone selects memory.

## 5. Bedrock node number out of reset (IP35 6.210)

- Register. The node number is bits 39:32 of the local block `rev_id` register, local alias 0x9200000001600000
  (offset 0x600000); region size is bits 47:46 ([Bedrock local block](../devices/bedrock_lb/README.md)). The PROM reads
  it with a 0x24-byte getter at 0x1fc6b5d0 (loads the word, masks 255 shifted left 32, `dsrl32`; 311 call sites). **E**.
- Out-of-reset value: **U**. The header gives no reset value, and no PROM code before its first read could have set
  one, so the hardware value is visible only in a hardware read before the PROM runs. Route: that read.
- First access, cold reset: the first read of the node field is in the main routine at 0x1fc698dc, at 0x1fc6991c.
  Entry order: main loads PI offset 0x20 (processor slice), stores progress value 13 (0x1fc69918), calls the getter
  (0x1fc6991c) and passes the node number as the first argument to 0x1fc697ec with the string "DisableIO"
  (0x1fc6fd18) as the name. **E** for the code. The reset body (0x1fc00400 to 0x1fc011d8) has no read of the field: the
  only reset-body accesses to the local block are to offsets 0x8000, 0x8008, 0x8010 (scratch words, 0x1fc007c4 to
  0x1fc00828, 0x1fc00c2c) and 0x4200 (the real-time counter set-up through 0x1fc6b600, LED 0x35). The three calls
  from the reset body into the routine 0x1fc50c34, which does read the field (via the getter at 0x1fc50c70), are at 0x1fc00778,
  0x1fc00d5c and 0x1fc00f0c, each behind a progress write of 0xb4, 0x83 or 0x84 and the "permanently disabling cpu %C here"
  text: they are the processor-disable failure paths, not the normal cold path. **E** for the call sites; **I** that
  these are only failure paths (the branch conditions into them were read only as far as 0x1fc00c2c to 0x1fc00c4c).
- The soft-reset and NMI entry reads the field earlier: 0x1fc01d40 reads it after building a KSEG1 alias of 0x1fc01e5c,
  shifts it down and masks 8 bits, to address the processor's save area. **E** (this entry is taken when
  ErrorEPC is in the flash window, 0x1fc005f4 to 0x1fc00604).
- What 0x1fc697ec does with the value: it opens the PROM's environment region for that node (0x1fc3336c): if the argument
  is negative or equals a second read of the field (0x1fc33514) it uses the local boot window at 0x900000001a000000
  (LBOOT plus 0x2000000), otherwise 0x900000003a000000 plus the node number shifted left 33. The argument is the field
  just read, so the local window is always taken at this call. **E** for the code; **I** that the region is the
  second flash position (32 MB stride in [IP35 boot flash](ip35/boot-flash.md)), since the "DisableIO" lookup that uses it was not
  read to its end. The node number in this path is not tested for zero, and no store to the register precedes it.
- The first store to the field: the hub initialisation routine 0x1fc676c8 stores zero to the whole word at 0x1fc67718
  (`sd $0,0($11)` with the address 0x9200000001600000), called from main at 0x1fc69e78 after the getter has been called at
  0x1fc6991c, 0x1fc69ac4, 0x1fc69b18 and 0x1fc69e2c. So the PROM reads the field four times and then clears node number and
  region size to zero before it assigns the real value (0x1fc61254 on the boot node; a remote assignment by
  0x1fc27c20 for other nodes). **E** for the sites, **I** for "before any assignment" (the routine's callers were not all
  traced).
- Consequence: nothing in the PROM requires a particular reset value. A zero would leave the first reads in the
  local-window case and the explicit clear later; a nonzero value would also take the local window (the compare is of the
  register with itself). **I**.

## Open

| Unknown | Route |
|---|---|
| Hardware value of node and region size out of reset on Bedrock; and on the Hub (no PROM read before main settles it either) | read before the PROM runs |
| Whether the flash window wraps or the top of the window is remapped to its base | read the window at offsets beyond the image (section 1) |
| Whether a ckseg1 data reference can reach a widget or a node-controller register | a ckseg1 load against attribute-1 and attribute-3 xkphys loads of one physical address (section 3) |
| Why node-bits-zero references mean the local node after the node number changes | read of a node-zero-numbered address from a node with a nonzero number |
| The same facts for PROM 6.211 and the base-media IP27 PROM | unpack the images and repeat the scans |

## How to repeat

```
retools/tools/re-run python3 retools/tools/chips/promgen64.py root/firmware/ip27prom.img out p156
retools/tools/re-run python3 retools/tools/chips/promgen64.py root/firmware/ip35prom.img out p210
retools/tools/re-run sh -c 'mips64-linux-gnuabi64-objdump -D -b binary -m mips:isa64 -EB \
    --adjust-vma=0xc00000001fc00000 -w -M no-aliases,gpr-names=numeric --no-show-raw-insn \
    out/p210.ip35prom.bin'
```

For the kernels use `objdump -d` on the linked images. The kseg1 scan is the `lui` immediate filter described above; the
getter at 0x1fc6b5d0 and the string pool base are located as in [IP35 PROM memory configuration](ip35/prom-md-config.md).
