# IP35 PROM: how module ids are formed, and what the duplicate rack/bay check compares

Question. On an Origin 3900 Cx-brick (four node boards and one router board behind one system controller), how many
module numbers does one brick take in the PROM's board records: one per node board, or one for the brick with four slots?
Where does the PROM print "Modules with duplicate rack/bay positions detected", what does that check compare, and what
must a controller answer on each node board's link to stay clear of it?

Method. Disassembly of the shipped IP35 PROM 6.210 (built Aug 26 2004) and 6.211 (built Jan 25 2008), both read. Nothing
was run. The routines were located from their console text and checked against the controller side in the sysco
repository (`platforms/bricks/router-board-records.md`). The PROM is two images: the outer segment (addresses are
`0x1fc00000` plus the offset) and the base I/O image the outer segment carries compressed (addresses are
`0xc000000013000000` plus the file offset). The 6.211 copies of the check, the id packing routine, the two controller requests and the link reader were compared
with the 6.210 ones instruction by instruction (jump targets and table offsets masked): the logic is the same in both, and
only addresses and string offsets move.

| Image | Build | sha256 |
|---|---|---|
| outer segment | 6.210 | `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b` |
| base I/O image inside it | 6.210 | `f903b3ce33b86c286f168ba43395f36a0073c24b1d4e703adce240f683b8c2d7` |
| outer segment | 6.211 | `25f60c7f0bae9cf32611e04205b7d0c8cf08adfddbfc1bfe433facd95b5ce271` |
| base I/O image inside it | 6.211 | `70c2494e95ec3cd7b4e481254c4567f806e0c40eb7664597f39f8513a7501f33` |

Grades follow the repository rules. A reading of a shipped image is a software expectation of the hardware, not a
measurement of it. No capture of a real Cx-brick's controller answers exists here.

## Answer

**One module id per node board.** A Cx-brick takes four module ids, with consecutive bay numbers, one for each of its
node boards. It is not one module with four slots: the id has no slot field. The check counts each node board's id once.

1. **Established: the id is rack, bay and type letter, packed in 16 bits.** The routine at `0x1fc4e2c8` (6.211:
   `0x1fc4e2c0`) builds it from the rack number (as decimal digits), the bay and the brick type letter. Bits 5:0 are the
   bay (a bay of 64 or more is refused). Bits 11:6 are a rack code. Bits 15:12 are the index of the lowercase type letter
   in the 16-character table `crikxdpn%#012345` (`c` 0, `r` 1, `i` 2, `k` 3, `x` 4, `d` 5, `p` 6, `n` 7; table at
   `0x1fd51ed8`, 6.211 `0x1fd51e78`). Before the lookup the letters `4`, `A`, `6`, `7`, `8`, `9`, `Q` and `0` become `C`,
   `%`, `#` and `E` become `P`, and `=` and `V` become `I`; `R` is left alone. The rack code is bit 5 for a rack of 100 or
   more, then the tens digit and the ones digit minus one, packed into the low five bits (below 100: tens 0 to 3 and ones
   1 to 8; from 100: tens 0 to 7 and ones 1 to 4). Any other rack number, including 0, makes the routine return -1.
2. **Established: the check.** The text `*  PANIC: Modules with duplicate rack/bay positions detected  *` is at base I/O image
   `0x130ef7b8` (6.211 `0x130ef7a8`), in a box that goes on "Please assign globally unique rack and bay positions at the
   system controllers." The routine that prints it, `check_modules`, starts at `0x130e058c` (6.211 `0x130e0574`) and is
   called at `0x130e1878` (6.211 `0x130e1860`), after the PROM has walked the hardware graph and recorded every hub.
3. **Established: what it compares.** It takes the list of hub NASIDs that the walk built (up to 128 entries, each NASID
   once). For each NASID it finds that node's board record of type 17 (the compute-node board record) and reads the 16-bit
   module id at record offset +14. It compares only that value, against every id already seen. Rack, bay and type letter
   are not compared separately: they are already folded into the id. The router board and the brick as a whole take no
   part, because the loop sees only type 17 records (the router's record type is not 17: inferred).
4. **Established: its three outcomes, per NASID.**

   | Module id read | What happens |
   |---|---|
   | 0 | ends in the banner "Some module(s) did not have their rack and bay position information assigned" (`0x130ef728`; 6.211 `0x130ef718`); with the PROM's verbose word set it first prints "module id not assigned for brd on nasid %d" |
   | -1 or -2 | skipped; with the verbose word set, "module number not found for nasid %d" |
   | any other value equal to one already seen | ends in the duplicate banner above; with the verbose word set it first prints "duplicate module id on nasid %d" |

   A missing type 17 record is skipped too ("Cannot get module board for nasid %d" with the verbose word set; the word is the
   one at offset 5320 of the PROM's data area, which gates its other debug prints; what sets it was not traced). The strings
   are at `0x130ef648` to `0x130ef6f8` (6.211 `0x130ef638` to `0x130ef6e8`). After the banner the check calls a routine at
   `0x130debec` (not read) and returns -1. An id of 0 therefore stops the boot at the other banner, while -1 and -2 do not
   stop it.
5. **Established: where each node's id comes from.** The routine that builds a node's board record (`0x1fc4f1a0`, store at
   `0x1fc4f264`) writes the id at +14 from `0x1fc57620` (6.211 `0x1fc57618`), which asks that node's own link to the
   controller. Board class `0xc000` (processor-element bricks) takes a different path there, with rack and bay from a table
   (`0x1fc57834`); every other class is asked through its own link, and nothing read gives the Cx node that class. The
   question for one link is `0x1fc68724` (6.211 `0x1fc6871c`): it calls `0x1fc24cc8` (6.211 `0x1fc24ccc`) with the position request enabled,
   returns 0 when both rack and bay are 0, and otherwise returns the packed id from item 1.
6. **Established: the two controller requests per link.** `0x1fc24cc8` sends request code 3 (rack, bay and type letter) and
   reads a packed word: bits 5:0 are the bay and bits 15:6 are the rack, then the type letter in a second field. It then
   sends request code 14 (`0x1fc0ee08`) and reads one integer, the position. If the type letter is `6` (the Cx-brick
   letter), the PROM adds the low two bits of the position, with the position's sign, to the bay; a position of 4 also turns
   the letter into `R`. Every other letter in the list of item 1 is turned into `C` here. So a node board at position *n*
   (0 to 3) gets bay *b* + *n* and type `c`, and the router position (4) gets bay *b* (4 has low bits 0) and type `r`.
   The sum and the letter change are the same in 6.210 and 6.211.
7. **Established in the sysco reading of the controller firmware (that page marks its readings unverified): the controller
   answers this way.** On a Cx-brick the controller opens five ports, four node boards in board order and the router.
   Request 3 returns rack and bay and the letter `6`, and request 14 returns the port number as the position. The
   controller holds one rack and bay for the brick, so it returns the same pair on every port (inferred from that). The PROM,
   not the controller, adds the position to the bay. A real brick therefore shows its four nodes at consecutive bays, such as
   `001c07`, `001c08`, `001c09` and `001c10` for a brick whose lowest rack unit is 7, and the router at `001r07`.
   The published rack layout (a Cx-brick is 4U; bricks at units 7, 11, 15 and so on, see
   [the size ladder](../bricks/size-ladder.md)) leaves those ranges disjoint.

## What a model must answer

Per brick, and for each of its five links:

| Link | Request 3 (rack, bay, letter) | Request 14 (position) |
|---|---|---|
| node board 0 to 3 | the brick's rack, the brick's lowest rack unit *b*, letter `6` | 0 to 3 |
| router | the same rack and bay, letter `6` | 4 |

- The bay and rack in request 3 must be the same on all five links. Adding the board number to the bay in that answer as
  well (a bay of *b* + *n* with position *n*) makes the PROM add it twice: node *n* ends at *b* + 2*n*. (Inferred as the
  likely cause of an overlap seen with five consecutive numbers per brick; the PROM side of it is established, the model
  side was not read.)
- Bricks must be at least 4 bays apart, as a real 4U brick is. Bays *b* to *b* + 3 of two bricks in one rack must not
  overlap, or the second brick's node boards repeat the first's ids and the check fires. Units at bays 1, 2, 3 and 4 do
  overlap (1 to 4, 2 to 5, and so on).
- The rack must be a number the packing accepts (item 1): 1 to 8, 11 to 18, 21 to 28 or 31 to 38, or 101 to 104, 111 to
  114 and so on. Rack 0 with a nonzero bay makes every node id -1, which the check skips silently, so it does not stop the
  boot but it leaves the nodes without a usable id (the later effect is unknown). Rack 0 with bay 0 returns 0 and stops
  the boot at the other banner.
- A link that does not answer returns an error code that the PROM may store as the id (an unanswering node reads as -100 in
  the id; inferred from the control flow: the wrapper's error value reaches the id store unchanged). Two silent nodes would
  then look like duplicates.

## Not settled

- **Unknown:** how the router's own module id is formed. The PROM prints "Warning: Unable to read router module id (vector
  0x%lx from %M); using cbrick's id" (outer segment `0x72c48`), which says the router's id is read from the router chip
  and falls back to the node's, but the read itself was not traced.
- **Unknown:** what a real Cx-brick controller sends on the wire. Everything above about it is the controller firmware's
  code, not a capture.
- **Unknown:** which discovery entries take the stored variable `LastModule` instead of the controller. A second board
  record builder (`0x1fc4f068`, called at `0x1fc59740`) fills the id at +14 from that variable, and the controller-asking
  builder (`0x1fc4f1a0`, called at `0x1fc596e4`) is chosen by a flag test on the discovery entry that was not traced. The
  PROM also falls back to `LastModule` when its own controller request fails (see
  [the timeout page](prom-l1-request-timeouts.md)).
- **Unknown:** whether the type 17 board record is the only record the PROM stores module ids on, and how the IRIX kernel
  turns the four ids into hardware graph names (the earlier claim of a `slab` alias on a node vertex was not found in the
  shipped kernel).
- **Unknown:** the negative-position case (the sign is kept in the sum; no controller was seen to send one).
