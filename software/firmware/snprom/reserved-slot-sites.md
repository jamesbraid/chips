# SN2 PROM reserved-slot sites: one row per site

Companion to [pal-instructions.md](pal-instructions.md) section 5. One row for each of the 747 reserved slots in the PAL code of
`shub1snprom.bin` (SAL 5.04, package `snprom-10.54-70399`, sha256 starting `51ccf9ad`): 702 M-unit words `0x108000000` and 45
B-unit words `0x48000000`. Addresses are slot addresses. The rows hold addresses, register numbers and field patterns only; no image
bytes or listings.

**Columns.**
- *Unit*: M or B. *Class*: the context class defined in section 5 of the page (V, K, P1, P2, R, S, O, N1, N2, W1, W2, U for M-unit; B0, B1,
  BP for B-unit).
- *Serialize*: the nearest preceding non-nop instruction.
- *Before*: the last msr writes before the slot, oldest first, as `index=pattern`. The pattern is the 64-bit value in hex with `x` for a
  nibble the trace could not resolve and `*` for a nibble that is partly known; `?` as the index means the index register was not
  resolved (caller-supplied). `bank x N` is N consecutive writes to msr[1600..1627].
- *After*: the msr reads (`R`) and writes (`W`) that follow before the next slot, branch or return, in order, up to six. `(tbit vs n)` or
  `(cmp vs n)` is the test that the value read first reaches, with its constant operand; no `vs` means the other operand was a register
  not resolved. `BR`, `RET`, `CALL` end the trace. `?` as the index means unresolved (a read through `msr[r0]` is msr[0] and is shown `R0`).
- *Entry*: `A` reached by static flow from the PAL_A entry at +0x300; `R` from the PAL_B reset continuation (stub at +0x10060); `D` from the
  PAL_PROC dispatch (+0x10010); `E` from the event stubs (+0x10070, +0x10080); `5` from the PAL procedure 520 handler (PAL_B 5.73
  only). Static flow follows both arms of every conditional branch and resolves only ip-relative jumps, so a letter means "can be reached",
  not "is reached", and the set is a lower bound: a return through a register set from `ip` is followed only part of the way (the site
  `0xfffca626` is on the PAL_A 5.37 path by hand reading and is marked `A` by hand; the review added 14 more PAL_A sites, the ones after the
  second V site on the same path, found by following those returns, see the review in pal-instructions.md). `-` means not reached from any of these entries by this method.

Grades: addresses, registers and field patterns are *established* (read from the listing). Every class label and every entry letter is a
reading of code shape (*inferred*), with the limits in section 5 of the page.


## generic PAL_A (1 sites)

| Site | Unit | Class | Serialize | Before | After | Entry |
|---|---|---|---|---|---|---|
| `0xffff82f6` | M | W2 | srlz.i | 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 BR | - |

## PAL_A 5.37 (23 sites)

| Site | Unit | Class | Serialize | Before | After | Entry |
|---|---|---|---|---|---|---|
| `0xfffc9cb6` | M | W2 | srlz.i | 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 BR | - |
| `0xfffca406` | M | V | srlz.d | 1536=xxxxxxxxxxxx*xxx; 1572=xxxxxxxxxxxx*xxx; 1640=0; 1546=9**00*xx*0**x*ff | R1558 W1558 R1608 (cmp vs 0x0) R1609 (cmp vs 0x0) R1610 (cmp vs 0x0) R1611 (cmp vs 0x0) ... | A |
| `0xfffca626` | M | V | srlz.d | 1558=xxxxxxxxxxxx*xxx; 1546=9**00*xx*00007ff; 1544=xxxxxxxxxxxxxxxx | R1608 (cmp vs 0x0) R1609 (cmp vs 0x0) R1610 (cmp vs 0x0) R1611 (cmp vs 0x0) BR | A |
| `0xfffca826` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxxxfx; 1544=600; 1546=9720**000000067f | W1084 R0 (tbit vs 0xa) R0 (tbit vs 0x7) R1559 R1559 R1559 | A |
| `0xfffcac26` | M | N1 | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1544=x*fc; 1546=8**00*xx*0000000 | W? W? W1546 | A |
| `0xfffcad26` | M | N1 | srlz.d | ?=0; ?=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1559 W1544 W1545 W1547 W1546 | A |
| `0xfffcae86` | M | O | srlz.d | 1544=x*fc; 1545=fffc0019b; 1547=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R0 (tbit vs 0x7) R1536 R1553 W1536 W1553 R0 (tbit vs 0x5) ... | A |
| `0xfffcbc1c` | B | B1 | srlz.i | 1777=xxxxxxxxxxxxxxxx; bank x1; 1572=xxxxxxxxxxxx*000; 1664=xxxxxxxxxxxxxxx* | limit | - |
| `0xfffcd386` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxx**x; 1544=301; 1546=9740**00000003** | W1084 BR | - |
| `0xfffcd4d6` | M | N1 | srlz.d | bank x4; 1084=xxxxxxxx*xxxx**x; 1544=201; 1546=9700**00000002** | W1084 BR | A |
| `0xfffcd5c6` | M | N2 | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | - |
| `0xfffcd696` | M | N2 | srlz.d | 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | - |
| `0xfffcd9a6` | M | N1 | srlz.d | bank x7; 1546=8d20**0000000000 | R1559 W1546 Wbank x10 | A |
| `0xfffcdb06` | M | N2 | srlz.d | bank x7; 1544=0 | R1559 BR | A |
| `0xfffcdd66` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | R1559 W? W? W? | A |
| `0xfffcde56` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*00; ?=8**00*xx*0000000 | W? W? W? | A |
| `0xfffcdea6` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*ff; ?=8**00*xx*0000000 | R1559 BR | A |
| `0xfffce576` | M | U | srlz.d | 1545=0; 1547=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | A |
| `0xfffcebf6` | M | U | srlz.d | 1545=0; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | - |
| `0xfffced06` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx; 1545=0; 1547=xxxxxxxxxxxxxxxx | BR | - |
| `0xfffceee6` | M | N1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xfffcfcc6` | M | N1 | srlz.d | 1040=4; 1545=xxxxxxxxxxxxxxx*; 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1559 Wbank x11 | - |
| `0xfffcfe46` | M | N2 | srlz.d | bank x6; 1544=xxxxxxxxxxxxxxxx; 1546=9490**034000xxxx | RET | - |

## PAL_B 5.73 (223 sites)

| Site | Unit | Class | Serialize | Before | After | Entry |
|---|---|---|---|---|---|---|
| `0xffe7f1f6` | M | W2 | srlz.i | 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 BR | E |
| `0xffe88216` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxx**x; 1544=301; 1546=9740**00000003** | W1084 BR | - |
| `0xffe88346` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxx**x; 1544=301; 1546=9740**00000003** | W1084 BR | 5 |
| `0xffe88496` | M | N1 | srlz.d | bank x4; 1084=xxxxxxxx*xxxx**x; 1544=201; 1546=9700**00000002** | W1084 BR | - |
| `0xffe88586` | M | N2 | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | - |
| `0xffe88656` | M | N2 | srlz.d | 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | 5 |
| `0xffe88ac6` | M | N1 | srlz.d | bank x7; 1546=8d20**0000000000 | R1559 W1546 Wbank x10 | 5ER |
| `0xffe88c26` | M | N2 | srlz.d | bank x7; 1544=0 | R1559 BR | 5ER |
| `0xffe88e86` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | R1559 W? W? W? | 5ER |
| `0xffe88f76` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*00; ?=8**00*xx*0000000 | W? W? W? | 5ER |
| `0xffe88fc6` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*ff; ?=8**00*xx*0000000 | R1559 BR | 5ER |
| `0xffe89696` | M | U | srlz.d | 1545=0; 1547=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | - |
| `0xffe89d16` | M | U | srlz.d | 1545=0; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | E |
| `0xffe89e06` | M | N1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1084 BR | - |
| `0xffe8a1c6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx; 1545=0; 1547=xxxxxxxxxxxxxxxx | BR | - |
| `0xffe8a336` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx*xxxxxxx | W1084 R1079 (tbit vs 0x20) CALL | - |
| `0xffe8a856` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xffe8a8a6` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xffe8a8f6` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 BR | - |
| `0xffe8ab26` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xffe8ab76` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xffe8abc6` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 BR | - |
| `0xffe8ad76` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx*xxxxxxx; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 | - |
| `0xffe8aea6` | M | W1 | srlz.i | 1084=xxxxxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000380; 1084=xxxxxxxx*xxxxxfx | W1084 RET | - |
| `0xffe8b046` | M | N1 | srlz.i | 1084=xxxxxxxxxxxxxxxx; 1084=xxxxxxxx*xxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300 | W1084 R1072 R1073 R1074 (tbit vs 0x3e) R1075 (tbit vs 0x5) R1076 | - |
| `0xffe8caf6` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx*xxxxxxx; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 | - |
| `0xffe8cc26` | M | W1 | srlz.i | 1084=xxxxxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000380; 1084=xxxxxxxx*xxxxxfx | W1084 RET | - |
| `0xffe8cd76` | M | S | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1544=xx; 1546=8*xx**xx*0000000 | R1600 R1601 R1601 R1600 RET | - |
| `0xffe8cf36` | M | N2 | srlz.d | bank x6; 1544=xxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffe8d5e6` | M | R | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | R1545 (cmp vs r21?) W1544 Wbank x1 W1546 | - |
| `0xffe8d7c6` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxx*xx; bank x1; 1546=8**00*xx*0000000 | W1544 W1546 Wbank x10 | - |
| `0xffe8d8f6` | M | N2 | srlz.d | bank x8 | BR | - |
| `0xffe8dad6` | M | N1 | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | W1544 R1545 Wbank x1 W1546 | - |
| `0xffe8dbd6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxx**xx; bank x1; 1546=8**00*xx*0000000 | BR | - |
| `0xffe8dfa6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=*x*0*xxxxxxxxxxx | R1545 (cmp vs 0x0) BR | - |
| `0xffe8e3d6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=*x*0*xxxxxxxxxxx | BR | - |
| `0xffe8e796` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=*x*0*xxxxxxxxxxx | R1545 (cmp vs 0x7) BR | - |
| `0xffe8ecd6` | M | N2 | srlz.d | 1546=8922000000000000 | BR | - |
| `0xffe8ed46` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1545 (cmp vs 0x0) R1504 (tbit vs 0x27) BR | - |
| `0xffe8f036` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R? W1546 | - |
| `0xffe8f0b6` | M | O | srlz.d | 1546=8**00*xx*0000000 | R? RET | - |
| `0xffe8f4a6` | M | U | srlz.d | bank x6; 1546=8**00*xx*0000000; ?=x*000000x*000 | W1544 W1546 | - |
| `0xffe8f4e6` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | W? W1546 | - |
| `0xffe8f556` | M | N1 | srlz.d | ?=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | Wbank x11 | - |
| `0xffe8f666` | M | N2 | srlz.d | bank x7; 1546=8**00*xx*0000000 | RET | - |
| `0xffe8f866` | M | N2 | srlz.d | bank x8 | RET | - |
| `0xffe8f996` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 RET | - |
| `0xffe8fb96` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xffe8fcd6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xffe8fe06` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 RET | - |
| `0xffe8fff6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) Wbank x1 W1546 | - |
| `0xffe90116` | M | N2 | srlz.d | bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xffe902f6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 Wbank x1 W1546 | - |
| `0xffe903e6` | M | N2 | srlz.d | bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xffe905c6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) W1546 W1544 Wbank x1 | - |
| `0xffe906f6` | M | N2 | srlz.d | 1546=8**00*xx*0000000; 1544=xxxxxxxxxxxxxxxx; bank x1 | RET | - |
| `0xffe916f6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=*xxxxxxxxxxxxxxx | R1545 (cmp vs 0x0) R1547 BR | - |
| `0xffe91b66` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1545=0; 1547=xxxxxxxxxxxxxxxx; 1546=*x*0*xxxxxxxxxxx | BR | - |
| `0xffe92076` | M | N2 | srlz.d | 1544=xxxxxxxxxxxx0*xx; 1545=0; 1547=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | BR | E |
| `0xffe92ad6` | M | N2 | srlz.d | 1237=xxxxxxxxxxxxxxx*; 1237=xxxxxxxxxxxxxxxx; 1546=8922000000000000 | BR | - |
| `0xffe92b86` | M | N2 | srlz.d | 1546=8922000000000000 | BR | - |
| `0xffe92c26` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1545 (cmp vs 0x0) R1547 BR | - |
| `0xffe93196` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R? W1546 | - |
| `0xffe93216` | M | O | srlz.d | 1546=8**80*xx*0000000 | R? RET | - |
| `0xffe934f6` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | W? W? W1546 | - |
| `0xffe935f6` | M | N2 | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | RET | - |
| `0xffe937c6` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R? R? R? R? R? RET | - |
| `0xffe93b06` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | W? W? W? W? W? W1546 | - |
| `0xffe93c26` | M | N2 | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | RET | - |
| `0xffe93e26` | M | N2 | srlz.d | bank x7; 1546=8**80*xx*0000000 | RET | - |
| `0xffe93f56` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 R1547 RET | - |
| `0xffe94106` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1545=*xxxxxxxxxxxxx; 1547=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffe94246` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1545=0; 1546=8**00*xx*0000000 | RET | - |
| `0xffe94366` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 RET | - |
| `0xffe94556` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 W1545 W1546 | - |
| `0xffe945c6` | M | N2 | srlz.d | 1545=*xxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffe94796` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 W1546 W1545 | - |
| `0xffe94826` | M | N2 | srlz.d | 1546=8**00*xx*0000000; 1545=*xxxxxxxxxxxxx | RET | - |
| `0xffe94a06` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 W1545 W1547 W1546 | - |
| `0xffe94a96` | M | N2 | srlz.d | 1545=*xxxxxxxxxxxxx; 1547=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffe95646` | M | S | srlz.d | ?=x*xxxxxxx**xxxxx; ?=x*xxxxxxx***xxxx; 1546=8**00*xx*0000000; 1544=xxxxxxxxxxxx**xx | R1608 (cmp) RET | - |
| `0xffe958f6` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1028 R1029 R1030 R1031 RET | - |
| `0xffe95aa6` | M | N2 | srlz.d | bank x4; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffe96886` | M | N1 | srlz.d | 1084=xxxxxxxxxxxxx*xx; 1416=xx**xxxxxxxxxxxx; 1544=1; 1546=8**00*xx*0000000 | W1544 Wbank x4 W1546 | - |
| `0xffe968e6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x4; 1546=8**00*xx*0000000 | RET | - |
| `0xffe96a36` | M | N1 | srlz.d | 1544=1; 1546=8**00*xx*0000000 | W1544 W1546 | - |
| `0xffe96a76` | M | S | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1608 W1546 | - |
| `0xffe96ac6` | M | S | srlz.d | 1546=8**00*xx*0000000 | R1608 W1546 | - |
| `0xffe96b26` | M | S | srlz.d | 1546=8**00*xx*0000000 | R1608 W1546 | - |
| `0xffe96b66` | M | S | srlz.d | 1546=8**00*xx*0000000 | R1608 RET | - |
| `0xffe9ad86` | M | R | srlz.d | 1504=xxx*xxxxxxxxxxxx; 1504=xxx*xxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | E |
| `0xffe9aec6` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | R1510 (tbit vs 0x3) W1544 W1546 | E |
| `0xffe9afc6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | E |
| `0xffe9b106` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | R1511 (tbit vs 0x3) W1544 W1546 | E |
| `0xffe9b206` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | E |
| `0xffe9b346` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | R1512 (tbit vs 0x3) W1544 W1546 | E |
| `0xffe9b446` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | E |
| `0xffe9b586` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=xxxxxxxxxxxxxxxx | BR | E |
| `0xffea0fe6` | M | P1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) BR | - |
| `0xffea27c6` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 R1152 (tbit vs 0x12) R1237 (tbit vs 0x2) ... | - |
| `0xffea32b6` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 R1152 (tbit vs 0x12) R1237 (tbit vs 0x2) ... | D |
| `0xffea3c86` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 R1152 (tbit vs 0x12) R1237 (tbit vs 0x2) ... | - |
| `0xffea41d6` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 BR | - |
| `0xffea4366` | M | N1 | srlz.i | 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | 5 |
| `0xffea5146` | M | N1 | srlz.d | 1040=4; 1545=xxxxxxxxxxxxxxx*; 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1559 Wbank x11 | - |
| `0xffea52c6` | M | N2 | srlz.d | bank x6; 1544=xxxxxxxxxxxxxxxx; 1546=9490**034000xxxx | RET | - |
| `0xffea5626` | M | N1 | srlz.i | 1558=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xffea5786` | M | N1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xffea89fc` | B | B1 | srlz.i | 1641=xxxxxxxxxxxxxxxx; 1776=xxxxxxxxxxxxxxxx; 1464=xxxxxxxxxxxxxxxx; 1283=xxxxxxxxxxxxxxxx | R0 R1641 | D |
| `0xffea8a3c` | B | B0 | srlz.i | - | R0 R1642 | D |
| `0xffea8a8c` | B | B0 | srlz.i | - | R0 R1641 R1642 | D |
| `0xffea8acc` | B | B0 | srlz.i | - | BR | D |
| `0xffeab8ec` | B | B1 | srlz.i | 1776=xxxxxxxxxxxxxxxx; 1464=xxxxxxxxxxxxxxxx; 1283=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | BR | - |
| `0xffeb827c` | B | B1 | srlz.i | 1643=xxxxxxxxxxxxxxxx; 1642=xxxxxxxxxxxxxxxx; 1282=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | W1282 R1640 R1237 (tbit vs 0x5) W1237 R1572 (tbit vs 0xe) | - |
| `0xffeba05c` | B | B1 | srlz.i | 1237=xxxxxxxxxxxxxx*x; 1640=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | R1642 R0 | E |
| `0xffeba12c` | B | B0 | srlz.i | - | R1642 R1641 R0 | E |
| `0xffeba17c` | B | B0 | srlz.i | - | R? R1641 | E |
| `0xffeba1bc` | B | B0 | srlz.i | - | R? | E |
| `0xffeba1ec` | B | B0 | srlz.i | - | BR | E |
| `0xffebfcc6` | M | P2 | srlz.d | 1040=xxxxxxxxxxxxxxxx; 1416=xxxxxxxxxxx*xxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1028 R1029 R1030 (tbit vs 0x0) R1031 (cmp vs r3?) R1416 W1416 ... | E |
| `0xffecafb6` | M | P2 | srlz.d | 1040=xxxxxxxxxxxxxxxx; 1416=xxxxxxxxxxx*xxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1028 R1029 R1030 (tbit vs 0x0) R1031 (cmp vs r3?) R1416 W1416 ... | E |
| `0xffed4116` | M | O | srlz.i | 1728=xxx*xxxxxxxxxxxx; 1730=xxxxxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1779 W1779 W1779 R1558 R1168 W1168 ... | E |
| `0xffed4a8c` | B | B1 | srlz.i | 1643=xxxxxxxxxxxxxxxx; 1416=xxxxxxxxxxx*xxxx; 1664=xxxxxxxxxxxxxxx* | BR | E |
| `0xffed51c6` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxxxfx; 1544=380; 1546=9780**00000003ff | R1559 W1544 W1546 | R |
| `0xffed5246` | M | N1 | srlz.d | 1544=10380; 1546=9780**00000103ff | R1559 W1544 W1546 | R |
| `0xffed52c6` | M | N1 | srlz.d | 1544=20380; 1546=9780**00000203ff | R1559 W1544 W1546 | R |
| `0xffed5346` | M | N1 | srlz.d | 1544=30380; 1546=9780**00000303ff | W1084 W1057 W1056 R1559 W1544 Wbank x1 ... | R |
| `0xffed5436` | M | O | srlz.d | 1056=200007; 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=97c0**01d0003000 | R0 (tbit vs 0x1) W1056 W1040 CALL | R |
| `0xffed77c6` | M | K | srlz.d | 1640=xxxxxxxxxxxxxxxx; 1664=2; 1544=xxxxxxxxxxxxxxxx; 1546=9021004d60000001 | R1212 (tbit vs 0xe) R1226 (cmp vs r20?) BR | R |
| `0xffed7886` | M | U | srlz.d | 1640=x*xxxxxxxxxxxxxx; ?=9020000000000001 | W1664 R0 (tbit vs 0x18) W1573 R1779 (tbit vs 0xf) BR | R |
| `0xffed87d6` | M | N1 | srlz.i | 1416=xxxxxxxxxxx*xxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1552 BR | - |
| `0xffeefe76` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xffeefec6` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xffeeff16` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 CALL | - |
| `0xffef01a6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xffef01f6` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xffef0246` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 W? | - |
| `0xffef0d46` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef0ec6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef1046` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef11c6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef1346` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef14c6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef1646` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef17c6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 Wbank x1 ... | - |
| `0xffef1906` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxxxxx | W1084 W? BR | - |
| `0xffef1cd6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef1e56` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef1fd6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef2156` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef22d6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef2456` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef25d6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffef2756` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 W? BR | - |
| `0xffef2956` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxxxxx | W1084 RET | - |
| `0xffef3610` | M | S | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1544=xx; 1546=8*xx**xx*0000000 | R1600 R1601 R1601 R1600 RET | - |
| `0xffef37d0` | M | N2 | srlz.d | bank x6; 1544=xxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffef4030` | M | N1 | srlz.d | 1056=xxxxxxxxxxxxxxx*; 1544=0; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xffef4150` | M | O | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xffef4290` | M | N1 | srlz.d | 1544=0; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xffef43b0` | M | O | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xffef44e0` | M | N1 | srlz.d | 1544=0; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xffef4610` | M | O | srlz.d | 1544=*xx; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xffef4740` | M | N1 | srlz.d | 1544=*xx; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xffef4870` | M | O | srlz.d | 1544=*xxx; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xffef49a0` | M | N1 | srlz.d | 1544=*xxx; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xffef4ac0` | M | O | srlz.d | 1544=**00; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) BR | - |
| `0xffef4e00` | M | R | srlz.d | ?=xxxxxxxxxxxxxxxx; 480=xxxxxx*xxxxxxxxx; 1544=0; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xffef5150` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=0 | R1559 W1544 W1546 | - |
| `0xffef52a0` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 | - |
| `0xffef5400` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xffef5750` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=*00 | R1559 W1544 W1546 | - |
| `0xffef58a0` | M | R | srlz.d | 1544=*000; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 | - |
| `0xffef5a00` | M | R | srlz.d | 1544=*00; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xffef5d50` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=*00 | R1559 W1544 W1546 | - |
| `0xffef5eb0` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 | - |
| `0xffef6010` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xffef6360` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xffef64c0` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 | - |
| `0xffef6620` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xffef6970` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xffef6ac0` | M | R | srlz.d | 1544=*000; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) W? BR | - |
| `0xffef6f20` | M | N1 | srlz.d | 529=xxxxxxxxxxxxxxx*; 1544=0; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xffef7070` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 W1545 | - |
| `0xffef7230` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xffef7380` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 W1545 | - |
| `0xffef7540` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xffef76a0` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 W1545 | - |
| `0xffef7860` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xffef79c0` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 W1545 | - |
| `0xffef7b80` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xffef7cd0` | M | R | srlz.d | 1544=x*00; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) BR | - |
| `0xffef8100` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xx*00; 1547=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xffef8260` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 R1547 (cmp vs r39?) R1559 W1544 W1546 W1545 ... | - |
| `0xffef8460` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xx*00; 1547=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xffef85c0` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 R1547 (cmp vs r40?) R1559 W1544 W1546 W1545 ... | - |
| `0xffef87c0` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xx*00; 1547=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xffef8930` | M | R | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | R1545 R1547 (cmp vs r39?) R1559 W1544 W1546 W1545 ... | - |
| `0xffef8b30` | M | N1 | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000; 1545=*xx*00; 1547=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xffef8ca0` | M | R | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | R1545 R1547 (cmp vs r40?) R1559 W1544 W1546 W1545 ... | - |
| `0xffef8ea0` | M | N1 | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000; 1545=*xx*00; 1547=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xffef9000` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 R1547 (cmp vs r39?) BR | - |
| `0xffef9226` | M | P1 | srlz.i | ?=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) | - |
| `0xfff00586` | M | P1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfff00936` | M | N1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 R1552 W1552 R? W? CALL | - |
| `0xfff00d66` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfff01766` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) | - |
| `0xfff01e76` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfff026e6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfff02d46` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfff037d6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfff03c56` | M | N1 | srlz.i | 1512=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xfff040c6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) | - |
| `0xfff04866` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1560 R1640 W1560 ... | - |
| `0xfff05156` | M | P1 | srlz.i | 1640=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfff05926` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xfff06826` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xfff07626` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xfff08436` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xfff08dc6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xfff09656` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xfff09f76` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) CALL | - |
| `0xfff0a806` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |

## PAL_A 7.31 (19 sites)

| Site | Unit | Class | Serialize | Before | After | Entry |
|---|---|---|---|---|---|---|
| `0xfffc31b6` | M | W2 | srlz.i | 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 BR | - |
| `0xfffc38a6` | M | V | srlz.d | 1572=xxxxxxxxxxxx*xxx; 1640=0; 1546=9**00*xx*000xxxx; 1544=xxxxxxxxxxxxxxxx | R1558 W1558 R1608 (cmp vs 0x0) R1609 (cmp vs 0x0) R1610 (cmp vs 0x0) R1611 (cmp vs 0x0) ... | A |
| `0xfffc3ab6` | M | V | srlz.d | 1558=xxxxxxxxxxxx*xxx; 1546=9**00*xx*00007ff; 1544=xxxxxxxxxxxxxxxx | R1608 (cmp vs 0x0) R1609 (cmp vs 0x0) R1610 (cmp vs 0x0) R1611 (cmp vs 0x0) BR | A |
| `0xfffc3cb6` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxxxfx; 1544=600; 1546=9720**000000067f | W1084 R0 (tbit vs 0xa) R1536 W1536 R0 (tbit vs 0x7) R1559 ... | A |
| `0xfffc4046` | M | N1 | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1536=xxxxxxxxxxxxxxx*; 1544=7fc; 1546=8**00*xx*0000000 | W? W? W1546 | A |
| `0xfffc4146` | M | N1 | srlz.d | ?=0; ?=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1559 W1544 W1545 W1546 | A |
| `0xfffc4286` | M | O | srlz.d | 1544=7fc; 1545=fffc0019b; 1546=8**00*xx*0000000 | R0 (tbit vs 0x7) R1536 R1553 W1536 W1553 R0 (tbit vs 0x5) ... | A |
| `0xfffc501c` | B | B1 | srlz.i | 1777=xxxxxxxxxxxxxxxx; bank x1; 1572=xxxxxxxxxxxx*000; 1664=xxxxxxxxxxxxxxx* | limit | - |
| `0xfffc8236` | M | N1 | srlz.d | bank x4; 1084=xxxxxxxx*xxxx**x; 1544=201; 1546=9700**00000002** | W1084 BR | A |
| `0xfffc8326` | M | N2 | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | - |
| `0xfffc83f6` | M | N2 | srlz.d | 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | - |
| `0xfffc8706` | M | N1 | srlz.d | bank x7; 1546=8d20**0000000000 | R1559 W1546 Wbank x10 | A |
| `0xfffc8866` | M | N2 | srlz.d | bank x7; 1544=0 | R1559 BR | A |
| `0xfffc8ac6` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | R1559 W? W? W? | A |
| `0xfffc8bb6` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*00; ?=8**00*xx*0000000 | W? W? W? | A |
| `0xfffc8c06` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*ff; ?=8**00*xx*0000000 | R1559 BR | A |
| `0xfffc90c6` | M | U | srlz.d | 1545=0; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | A |
| `0xfffc9846` | M | U | srlz.d | 1545=0; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | - |
| `0xfffc9956` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx; 1545=0 | BR | A |

## PAL_B 7.79 (223 sites)

| Site | Unit | Class | Serialize | Before | After | Entry |
|---|---|---|---|---|---|---|
| `0xffdcf1f6` | M | W2 | srlz.i | 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 BR | E |
| `0xffdd8216` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxx**x; 1544=301; 1546=9740**00000003** | W1084 BR | - |
| `0xffdd8346` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxx**x; 1544=301; 1546=9740**00000003** | W1084 BR | - |
| `0xffdd8496` | M | N1 | srlz.d | bank x4; 1084=xxxxxxxx*xxxx**x; 1544=201; 1546=9700**00000002** | W1084 BR | - |
| `0xffdd8586` | M | N2 | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | - |
| `0xffdd8656` | M | N2 | srlz.d | 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | - |
| `0xffdd8ac6` | M | N1 | srlz.d | bank x7; 1546=8d20**0000000000 | R1559 W1546 Wbank x10 | ER |
| `0xffdd8c26` | M | N2 | srlz.d | bank x7; 1544=0 | R1559 BR | ER |
| `0xffdd8e86` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | R1559 W? W? W? | ER |
| `0xffdd8f76` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*00; ?=8**00*xx*0000000 | W? W? W? | ER |
| `0xffdd8fc6` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*ff; ?=8**00*xx*0000000 | R1559 BR | ER |
| `0xffdd9486` | M | U | srlz.d | 1545=0; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | - |
| `0xffdd9c06` | M | U | srlz.d | 1545=0; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | E |
| `0xffdd9d06` | M | N1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1084 BR | - |
| `0xffdda0b6` | M | N2 | srlz.d | ?=xxxxxxxxxxxxxx*x; 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx; 1545=0 | BR | E |
| `0xffdda226` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx*xxxxxxx | W1084 R1079 (tbit vs 0x20) CALL | - |
| `0xffdda746` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xffdda796` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xffdda7e6` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 BR | - |
| `0xffddaa16` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xffddaa66` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xffddaab6` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 BR | - |
| `0xffddac66` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx*xxxxxxx; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 | - |
| `0xffddad96` | M | W1 | srlz.i | 1084=xxxxxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000380; 1084=xxxxxxxx*xxxxxfx | W1084 RET | - |
| `0xffddaf36` | M | N1 | srlz.i | 1084=xxxxxxxxxxxxxxxx; 1084=xxxxxxxx*xxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300 | W1084 R1072 R1073 R1074 (tbit vs 0x3e) R1075 (tbit vs 0x5) R1076 | - |
| `0xffddc9e6` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx*xxxxxxx; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 | - |
| `0xffddcb16` | M | W1 | srlz.i | 1084=xxxxxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000380; 1084=xxxxxxxx*xxxxxfx | W1084 RET | - |
| `0xffddcc66` | M | S | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1544=xx; 1546=8*xx**xx*0000000 | R1600 R1601 R1601 R1600 RET | - |
| `0xffddce26` | M | N2 | srlz.d | bank x6; 1544=xxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffddd4d6` | M | R | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | R1545 (cmp vs r21?) W1544 Wbank x1 W1546 | - |
| `0xffddd6b6` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxx*xx; bank x1; 1546=8**00*xx*0000000 | W1544 W1546 Wbank x10 | - |
| `0xffddd7e6` | M | N2 | srlz.d | bank x8 | BR | - |
| `0xffddd9c6` | M | N1 | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | W1544 R1545 Wbank x1 W1546 | - |
| `0xffdddac6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxx**xx; bank x1; 1546=8**00*xx*0000000 | BR | - |
| `0xffddde96` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=*x*0*xxxxxxxxxxx | R1545 (cmp vs 0x0) BR | - |
| `0xffdde2c6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=*x*0*xxxxxxxxxxx | BR | - |
| `0xffdde686` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=*x*0*xxxxxxxxxxx | R1545 (cmp vs 0x7) BR | - |
| `0xffddebc6` | M | N2 | srlz.d | 1546=8922000000000000 | BR | - |
| `0xffddec36` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1545 (cmp vs 0x0) R1504 (tbit vs 0x27) BR | - |
| `0xffddef26` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R? W1546 | - |
| `0xffddefa6` | M | O | srlz.d | 1546=8**00*xx*0000000 | R? RET | - |
| `0xffddf396` | M | U | srlz.d | bank x6; 1546=8**00*xx*0000000; ?=x*000000x*000 | W1544 W1546 | - |
| `0xffddf3d6` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | W? W1546 | - |
| `0xffddf446` | M | N1 | srlz.d | ?=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | Wbank x11 | - |
| `0xffddf556` | M | N2 | srlz.d | bank x7; 1546=8**00*xx*0000000 | RET | - |
| `0xffddf756` | M | N2 | srlz.d | bank x8 | RET | - |
| `0xffddf886` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 RET | - |
| `0xffddfa86` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xffddfbc6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xffddfcf6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 RET | - |
| `0xffddfee6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) Wbank x1 W1546 | - |
| `0xffde0006` | M | N2 | srlz.d | bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xffde01e6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 Wbank x1 W1546 | - |
| `0xffde02d6` | M | N2 | srlz.d | bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xffde04b6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) W1546 W1544 Wbank x1 | - |
| `0xffde05e6` | M | N2 | srlz.d | 1546=8**00*xx*0000000; 1544=xxxxxxxxxxxxxxxx; bank x1 | RET | - |
| `0xffde1796` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=*xxxxxxxxxxxxxxx | R1545 (cmp vs 0x0) BR | - |
| `0xffde1bc6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1545=0; 1546=*x*0*xxxxxxxxxxx | BR | - |
| `0xffde1fc6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxx**xx; 1545=0; 1546=xxxxxxxxxxxxxxxx | BR | E |
| `0xffde2876` | M | N2 | srlz.d | 1237=xxxxxxxxxxxxxxx*; 1237=xxxxxxxxxxxxxxxx; 1546=8922000000000000 | BR | - |
| `0xffde2906` | M | N2 | srlz.d | 1546=8922000000000000 | BR | - |
| `0xffde29a6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1545 (cmp vs 0x0) BR | - |
| `0xffde2e36` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R? W1546 | - |
| `0xffde2eb6` | M | O | srlz.d | 1546=8**80*xx*0000000 | R? RET | - |
| `0xffde3196` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | W? W? W1546 | - |
| `0xffde3296` | M | N2 | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | RET | - |
| `0xffde3466` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R? R? R? R? R? RET | - |
| `0xffde37a6` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | W? W? W? W? W? W1546 | - |
| `0xffde38c6` | M | N2 | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | RET | - |
| `0xffde3ac6` | M | N2 | srlz.d | bank x7; 1546=8**80*xx*0000000 | RET | - |
| `0xffde3bf6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 RET | - |
| `0xffde3d66` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1545=*xxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffde3ea6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1545=0; 1546=8**00*xx*0000000 | RET | - |
| `0xffde3fc6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 RET | - |
| `0xffde41b6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 W1545 W1546 | - |
| `0xffde4226` | M | N2 | srlz.d | 1545=*xxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffde43f6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 W1546 W1545 | - |
| `0xffde4486` | M | N2 | srlz.d | 1546=8**00*xx*0000000; 1545=*xxxxxxxxxxxxx | RET | - |
| `0xffde4666` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 W1545 W1546 | - |
| `0xffde46e6` | M | N2 | srlz.d | 1545=*xxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffde5296` | M | S | srlz.d | ?=x*xxxxxxx**xxxxx; ?=x*xxxxxxx***xxxx; 1546=8**00*xx*0000000; 1544=xxxxxxxxxxxx**xx | R1608 (cmp) RET | - |
| `0xffde54a6` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1028 R1029 R1030 R1031 RET | - |
| `0xffde5656` | M | N2 | srlz.d | bank x4; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffde6436` | M | N1 | srlz.d | 1084=xxxxxxxxxxxxx*xx; 1416=xx**xxxxxxxxxxxx; 1544=1; 1546=8**00*xx*0000000 | W1544 Wbank x4 W1546 | - |
| `0xffde6496` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x4; 1546=8**00*xx*0000000 | RET | - |
| `0xffde65e6` | M | N1 | srlz.d | 1544=1; 1546=8**00*xx*0000000 | W1544 W1546 | - |
| `0xffde6626` | M | S | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1608 W1546 | - |
| `0xffde6676` | M | S | srlz.d | 1546=8**00*xx*0000000 | R1608 W1546 | - |
| `0xffde66d6` | M | S | srlz.d | 1546=8**00*xx*0000000 | R1608 W1546 | - |
| `0xffde6716` | M | S | srlz.d | 1546=8**00*xx*0000000 | R1608 RET | - |
| `0xffdea8d6` | M | R | srlz.d | 1504=xxx*xxxxxxxxxxxx; 1504=xxx*xxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | E |
| `0xffdeaa16` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | R1510 (tbit vs 0x3) W1544 W1546 | E |
| `0xffdeab26` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | E |
| `0xffdeac66` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | R1511 (tbit vs 0x3) W1544 W1546 | E |
| `0xffdead76` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | E |
| `0xffdeaeb6` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | R1512 (tbit vs 0x3) W1544 W1546 | E |
| `0xffdeafc6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | E |
| `0xffdeb106` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=xxxxxxxxxxxxxxxx | BR | E |
| `0xffdf0766` | M | P1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) BR | - |
| `0xffdf1f46` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 R1152 (tbit vs 0x12) R1237 (tbit vs 0x2) ... | - |
| `0xffdf2a36` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 R1152 (tbit vs 0x12) R1237 (tbit vs 0x2) ... | D |
| `0xffdf3406` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 R1152 (tbit vs 0x12) R1237 (tbit vs 0x2) ... | - |
| `0xffdf3956` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 BR | - |
| `0xffdf3ae6` | M | N1 | srlz.i | 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xffdf44c6` | M | N1 | srlz.d | 1040=4; 1545=xxxxxxxxxxxxxxx*; 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1559 Wbank x11 | - |
| `0xffdf4646` | M | N2 | srlz.d | bank x6; 1544=xxxxxxxxxxxxxxxx; 1546=9490**034000*xxx | RET | - |
| `0xffdf4986` | M | N1 | srlz.i | 1558=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xffdf4ae6` | M | N1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xffdf7c5c` | B | B1 | srlz.i | 1641=xxxxxxxxxxxxxxxx; 1776=xxxxxxxxxxxxxxxx; 1464=xxxxxxxxxxxxxxxx; 1283=xxxxxxxxxxxxxxxx | R0 R1641 | D |
| `0xffdf7c9c` | B | B0 | srlz.i | - | R0 R1642 | D |
| `0xffdf7cec` | B | B0 | srlz.i | - | R0 R1641 R1642 | D |
| `0xffdf7d2c` | B | B0 | srlz.i | - | BR | D |
| `0xffdfa8ec` | B | B1 | srlz.i | 1776=xxxxxxxxxxxxxxxx; 1464=xxxxxxxxxxxxxxxx; 1283=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | BR | - |
| `0xffe0727c` | B | B1 | srlz.i | 1643=xxxxxxxxxxxxxxxx; 1642=xxxxxxxxxxxxxxxx; 1282=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | W1282 R1640 R1237 (tbit vs 0x5) W1237 R1572 (tbit vs 0xe) | - |
| `0xffe0905c` | B | B1 | srlz.i | 1237=xxxxxxxxxxxxxx*x; 1640=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | R1642 R0 | E |
| `0xffe0912c` | B | B0 | srlz.i | - | R1642 R1641 R0 | E |
| `0xffe0917c` | B | B0 | srlz.i | - | R? R1641 | E |
| `0xffe091bc` | B | B0 | srlz.i | - | R? | E |
| `0xffe091ec` | B | B0 | srlz.i | - | BR | E |
| `0xffe0ecc6` | M | P2 | srlz.d | 1040=xxxxxxxxxxxxxxxx; 1416=xxxxxxxxxxx*xxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1028 R1029 R1030 (tbit vs 0x0) R1031 (cmp vs r3?) R1416 W1416 ... | E |
| `0xffe19fb6` | M | P2 | srlz.d | 1040=xxxxxxxxxxxxxxxx; 1416=xxxxxxxxxxx*xxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1028 R1029 R1030 (tbit vs 0x0) R1031 (cmp vs r3?) R1416 W1416 ... | E |
| `0xffe230e6` | M | O | srlz.i | 1728=xxx*xxxxxxxxxxxx; 1730=xxxxxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1779 W1779 W1779 R1558 R1168 W1168 ... | E |
| `0xffe23a5c` | B | B1 | srlz.i | 1643=xxxxxxxxxxxxxxxx; 1416=xxxxxxxxxxx*xxxx; 1664=xxxxxxxxxxxxxxx* | BR | E |
| `0xffe24266` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxxxfx; 1544=380; 1546=9780**00000003ff | R1559 W1544 W1546 | R |
| `0xffe242e6` | M | N1 | srlz.d | 1544=10380; 1546=9780**00000103ff | R1559 W1544 W1546 | R |
| `0xffe24366` | M | N1 | srlz.d | 1544=20380; 1546=9780**00000203ff | R1559 W1544 W1546 | R |
| `0xffe243e6` | M | N1 | srlz.d | 1544=30380; 1546=9780**00000303ff | W1084 W1057 W1056 R1559 W1544 Wbank x1 ... | R |
| `0xffe244d6` | M | N1 | srlz.d | 1056=200007; 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=97c0**01d0003000 | W1056 W1040 CALL | R |
| `0xffe26856` | M | K | srlz.d | 1640=xxxxxxxxxxxxxxxx; 1664=2; 1544=xxxxxxxxxxxxxxxx; 1546=9021004d60000001 | R1212 (tbit vs 0xe) R1226 (cmp vs r20?) BR | R |
| `0xffe26916` | M | U | srlz.d | 1640=x*xxxxxxxxxxxxxx; ?=9020000000000001 | W1664 R0 (tbit vs 0x18) W1573 R1779 (tbit vs 0xf) BR | R |
| `0xffe27866` | M | N1 | srlz.i | 1416=xxxxxxxxxxx*xxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1552 BR | - |
| `0xffe3ee76` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xffe3eec6` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xffe3ef16` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 CALL | - |
| `0xffe3f1a6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xffe3f1f6` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xffe3f246` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 W? | - |
| `0xffe3fd46` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe3fec6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe40046` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe401c6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe40346` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe404c6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe40646` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe407c6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 Wbank x1 ... | - |
| `0xffe40906` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxxxxx | W1084 W? BR | - |
| `0xffe40cd6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe40e56` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe40fd6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe41156` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe412d6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe41456` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe415d6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xffe41756` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 W? BR | - |
| `0xffe41956` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxxxxx | W1084 RET | - |
| `0xffe42610` | M | S | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1544=xx; 1546=8*xx**xx*0000000 | R1600 R1601 R1601 R1600 RET | - |
| `0xffe427d0` | M | N2 | srlz.d | bank x6; 1544=xxx; 1546=8**00*xx*0000000 | RET | - |
| `0xffe43030` | M | N1 | srlz.d | 1056=xxxxxxxxxxxxxxx*; 1544=0; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xffe43150` | M | O | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xffe43290` | M | N1 | srlz.d | 1544=0; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xffe433b0` | M | O | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xffe434e0` | M | N1 | srlz.d | 1544=0; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xffe43610` | M | O | srlz.d | 1544=*xx; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xffe43740` | M | N1 | srlz.d | 1544=*xx; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xffe43870` | M | O | srlz.d | 1544=*xxx; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xffe439a0` | M | N1 | srlz.d | 1544=*xxx; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xffe43ac0` | M | O | srlz.d | 1544=**00; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) BR | - |
| `0xffe43e00` | M | R | srlz.d | ?=xxxxxxxxxxxxxxxx; 480=xxxxxx*xxxxxxxxx; 1544=0; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xffe44150` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=0 | R1559 W1544 W1546 | - |
| `0xffe442a0` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 | - |
| `0xffe44400` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xffe44750` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=*00 | R1559 W1544 W1546 | - |
| `0xffe448a0` | M | R | srlz.d | 1544=*000; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 | - |
| `0xffe44a00` | M | R | srlz.d | 1544=*00; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xffe44d50` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=*00 | R1559 W1544 W1546 | - |
| `0xffe44eb0` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 | - |
| `0xffe45010` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xffe45360` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xffe454c0` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 | - |
| `0xffe45620` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xffe45970` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xffe45ac0` | M | R | srlz.d | 1544=*000; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) W? BR | - |
| `0xffe45eb0` | M | N1 | srlz.d | 529=xxxxxxxxxxxxxxx*; 1544=0; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xffe46000` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 W1545 | - |
| `0xffe461c0` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xffe46310` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 W1545 | - |
| `0xffe464d0` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xffe46630` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 W1545 | - |
| `0xffe467f0` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xffe46950` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 W1545 | - |
| `0xffe46b10` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xffe46c60` | M | R | srlz.d | 1544=**00; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) BR | - |
| `0xffe46fd0` | M | N1 | srlz.d | 529=xxxxxxxxxxxxxxx*; 1544=0; 1546=8**00*xx*0000000; 1545=*xx*00 | R1559 W1544 W1546 | - |
| `0xffe47120` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r39?) R1559 W1544 W1546 W1545 | - |
| `0xffe472d0` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xx*00 | R1559 W1544 W1546 | - |
| `0xffe47420` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 W1545 | - |
| `0xffe475d0` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xx*00 | R1559 W1544 W1546 | - |
| `0xffe47730` | M | R | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | R1545 (cmp vs r39?) R1559 W1544 W1546 W1545 | - |
| `0xffe478e0` | M | N1 | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000; 1545=*xx*00 | R1559 W1544 W1546 | - |
| `0xffe47a40` | M | R | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 W1545 | - |
| `0xffe47bf0` | M | N1 | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000; 1545=*xx*00 | R1559 W1544 W1546 | - |
| `0xffe47d40` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r39?) BR | - |
| `0xffe47f26` | M | P1 | srlz.i | ?=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) | - |
| `0xffe4f246` | M | P1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xffe4f5f6` | M | N1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 R1552 W1552 R? W? CALL | - |
| `0xffe4fa26` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xffe50426` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) | - |
| `0xffe50b36` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xffe513a6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xffe51a06` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xffe52496` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xffe52916` | M | N1 | srlz.i | 1512=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xffe52d86` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) | - |
| `0xffe53526` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1560 R1640 W1560 ... | - |
| `0xffe53e16` | M | P1 | srlz.i | 1640=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xffe545e6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xffe554c6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xffe562c6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xffe57116` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xffe57aa6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xffe58336` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |
| `0xffe58c46` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) CALL | - |
| `0xffe594d6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1536 (tbit vs 0x0) | - |

## PAL_A 1.27 (23 sites)

| Site | Unit | Class | Serialize | Before | After | Entry |
|---|---|---|---|---|---|---|
| `0xfffd0476` | M | W2 | srlz.i | 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 BR | - |
| `0xfffd0b16` | M | V | srlz.d | 1536=xxxxxxxxxxxx*xxx; 1572=xxxxxxxxxxxx*xxx; 1640=0; 1546=9**00*xx*0**xfff | R1558 W1558 R1608 (cmp vs 0x0) R1609 (cmp vs 0x0) R1610 (cmp vs 0x0) R1611 (cmp vs 0x0) ... | A |
| `0xfffd0d36` | M | V | srlz.d | 1558=xxxxxxxxxxxx*xxx; 1546=9**00*xx*00007ff; 1544=xxxxxxxxxxxxxxxx | R1608 (cmp vs 0x0) R1609 (cmp vs 0x0) R1610 (cmp vs 0x0) R1611 (cmp vs 0x0) BR | A |
| `0xfffd0f36` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxxxfx; 1544=600; 1546=9720**000000067f | W1084 R0 (tbit vs 0xa) R0 (tbit vs 0x7) R1559 R1559 R1559 | A |
| `0xfffd13a6` | M | N1 | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1544=*x7fc; 1546=8**00*xx*0000000 | W? W? W1546 | A |
| `0xfffd14a6` | M | N1 | srlz.d | ?=0; ?=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1559 W1544 W1545 W1547 W1546 | A |
| `0xfffd1606` | M | O | srlz.d | 1544=*x7fc; 1545=fffc0019b; 1547=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R0 (tbit vs 0x7) R1536 R1553 W1536 W1553 R0 (tbit vs 0x5) ... | A |
| `0xfffd23dc` | B | B1 | srlz.i | 1777=xxxxxxxxxxxxxxxx; bank x1; 1572=xxxxxxxxxxxx*000; 1664=xxxxxxxxxxxxxxx* | limit | - |
| `0xfffd3ba6` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxx**x; 1544=301; 1546=9740**00000003** | W1084 BR | - |
| `0xfffd3cf6` | M | N1 | srlz.d | bank x4; 1084=xxxxxxxx*xxxx**x; 1544=201; 1546=9700**00000002** | W1084 BR | A |
| `0xfffd3de6` | M | N2 | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | - |
| `0xfffd3eb6` | M | N2 | srlz.d | 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | - |
| `0xfffd41c6` | M | N1 | srlz.d | bank x7; 1546=8d20**0000000000 | R1559 W1546 Wbank x10 | A |
| `0xfffd4326` | M | N2 | srlz.d | bank x7; 1544=0 | R1559 BR | A |
| `0xfffd4586` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | R1559 W? W? W? | A |
| `0xfffd4676` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*00; ?=8**00*xx*0000000 | W? W? W? | A |
| `0xfffd46c6` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*ff; ?=8**00*xx*0000000 | R1559 BR | A |
| `0xfffd4ec6` | M | U | srlz.d | 1545=0; 1547=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | A |
| `0xfffd5676` | M | U | srlz.d | 1545=0; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | - |
| `0xfffd5786` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx; 1545=0; 1547=xxxxxxxxxxxxxxxx | BR | - |
| `0xfffd5966` | M | N1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xfffd67a6` | M | N1 | srlz.d | 1040=4; 1545=xxxxxxxxxxxxxxx*; 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1559 Wbank x11 | - |
| `0xfffd6936` | M | N2 | srlz.d | bank x6; 1544=xxxxxxxxxxxxxxxx; 1546=9490**03400*xxxx | RET | - |

## PAL_B 2.25 (235 sites)

| Site | Unit | Class | Serialize | Before | After | Entry |
|---|---|---|---|---|---|---|
| `0xfff2f1f6` | M | W2 | srlz.i | 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 BR | E |
| `0xfff38216` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxx**x; 1544=301; 1546=9740**00000003** | W1084 BR | - |
| `0xfff38346` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxx**x; 1544=301; 1546=9740**00000003** | W1084 BR | - |
| `0xfff38496` | M | N1 | srlz.d | bank x4; 1084=xxxxxxxx*xxxx**x; 1544=201; 1546=9700**00000002** | W1084 BR | - |
| `0xfff38586` | M | N2 | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | - |
| `0xfff38656` | M | N2 | srlz.d | 1546=97e0**000000007f; bank x4; 1544=xxxxxxxxxxxxxxxx | BR | - |
| `0xfff38ac6` | M | N1 | srlz.d | bank x7; 1546=8d20**0000000000 | R1559 W1546 Wbank x10 | R |
| `0xfff38c26` | M | N2 | srlz.d | bank x7; 1544=0 | R1559 BR | R |
| `0xfff38e86` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | R1559 W? W? W? | R |
| `0xfff38f76` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*00; ?=8**00*xx*0000000 | W? W? W? | R |
| `0xfff38fc6` | M | U | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=*ff; ?=8**00*xx*0000000 | R1559 BR | R |
| `0xfff397c6` | M | U | srlz.d | 1545=0; 1547=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | R |
| `0xfff39f76` | M | U | srlz.d | 1545=0; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx | BR | - |
| `0xfff3a066` | M | N1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1084 BR | - |
| `0xfff3a426` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx; 1545=0; 1547=xxxxxxxxxxxxxxxx | BR | - |
| `0xfff3a596` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx*xxxxxxx | W1084 R1079 (tbit vs 0x20) CALL | - |
| `0xfff3aab6` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xfff3ab06` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xfff3ab56` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 BR | - |
| `0xfff3ad86` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xfff3add6` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xfff3ae26` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 BR | - |
| `0xfff3afd6` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx*xxxxxxx; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 | - |
| `0xfff3b106` | M | W1 | srlz.i | 1084=xxxxxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000380; 1084=xxxxxxxx*xxxxxfx | W1084 RET | - |
| `0xfff3b2a6` | M | N1 | srlz.i | 1084=xxxxxxxxxxxxxxxx; 1084=xxxxxxxx*xxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300 | W1084 R1072 R1073 R1074 (tbit vs 0x3e) R1075 (tbit vs 0x5) R1076 | - |
| `0xfff3cd56` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx*xxxxxxx; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 | - |
| `0xfff3ce86` | M | W1 | srlz.i | 1084=xxxxxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000380; 1084=xxxxxxxx*xxxxxfx | W1084 RET | - |
| `0xfff3cfd6` | M | S | srlz.d | 1084=xxxxxxxxxxxxxxxx; 1544=xx; 1546=8*xx**xx*0000000 | R1600 R1601 R1601 R1600 RET | - |
| `0xfff3d196` | M | N2 | srlz.d | bank x6; 1544=xxx; 1546=8**00*xx*0000000 | RET | - |
| `0xfff3d846` | M | R | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | R1545 (cmp vs r21?) W1544 Wbank x1 W1546 | - |
| `0xfff3da26` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxx*xx; bank x1; 1546=8**00*xx*0000000 | W1544 W1546 Wbank x10 | - |
| `0xfff3db56` | M | N2 | srlz.d | bank x8 | BR | - |
| `0xfff3dd36` | M | N1 | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | W1544 R1545 Wbank x1 W1546 | - |
| `0xfff3de36` | M | N2 | srlz.d | 1544=xxxxxxxxxxxx**xx; bank x1; 1546=8**00*xx*0000000 | BR | - |
| `0xfff3e206` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=*x*0*xxxxxxxxxxx | R1545 (cmp vs 0x7) R1559 BR | - |
| `0xfff3e616` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=*x*0*xxxxxxxxxxx | BR | - |
| `0xfff3e9d6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=*x*0*xxxxxxxxxxx | R1545 (cmp vs 0x7) BR | - |
| `0xfff3ef16` | M | N2 | srlz.d | 1546=8922000000000000 | BR | - |
| `0xfff3ef86` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1545 (cmp vs 0x0) R1504 (tbit vs 0x27) BR | - |
| `0xfff3f276` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R? W1546 | - |
| `0xfff3f2f6` | M | O | srlz.d | 1546=8**00*xx*0000000 | R? RET | - |
| `0xfff3f6e6` | M | U | srlz.d | bank x6; 1546=8**00*xx*0000000; ?=x*000000x*000 | W1544 W1546 | - |
| `0xfff3f726` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | W? W1546 | - |
| `0xfff3f796` | M | N1 | srlz.d | ?=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | Wbank x11 | - |
| `0xfff3f8a6` | M | N2 | srlz.d | bank x7; 1546=8**00*xx*0000000 | RET | - |
| `0xfff3faa6` | M | N2 | srlz.d | bank x8 | RET | - |
| `0xfff3fbd6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 RET | - |
| `0xfff3fdd6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xfff3ff16` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xfff40046` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 RET | - |
| `0xfff40236` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) Wbank x1 W1546 | - |
| `0xfff40356` | M | N2 | srlz.d | bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xfff40536` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 Wbank x1 W1546 | - |
| `0xfff40626` | M | N2 | srlz.d | bank x1; 1546=8**00*xx*0000000 | RET | - |
| `0xfff40806` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) W1546 W1544 Wbank x1 | - |
| `0xfff40936` | M | N2 | srlz.d | 1546=8**00*xx*0000000; 1544=xxxxxxxxxxxxxxxx; bank x1 | RET | - |
| `0xfff41b06` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=*xxxxxxxxxxxxxxx | R1545 (cmp vs 0x0) R1547 R1559 BR | - |
| `0xfff41f66` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1545=0; 1547=xxxxxxxxxxxxxxxx; 1546=*x*0*xxxxxxxxxxx | BR | - |
| `0xfff42636` | M | N2 | srlz.d | 1544=xxxxxxxxxxx*0xxx; 1545=0; 1547=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | BR | - |
| `0xfff4317c` | B | B1 | srlz.i | 1282=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | R1282 W1282 R1237 W1237 R1237 W1237 ... | - |
| `0xfff4338c` | B | B1 | srlz.i | 1237=xxxxxxxxxxxxxxx*; 1237=xxxxxxxxxxxxxxxx; 1282=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | R1282 W1282 BR | - |
| `0xfff43446` | M | N2 | srlz.d | 1282=xxxxxxxxxxxxxxxx; 1546=8922000000000000 | BR | - |
| `0xfff434f6` | M | N2 | srlz.d | 1546=8922000000000000 | BR | - |
| `0xfff43596` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1545 (cmp vs 0x0) R1547 BR | - |
| `0xfff43ce6` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R? W1546 | - |
| `0xfff43d66` | M | O | srlz.d | 1546=8**80*xx*0000000 | R? RET | - |
| `0xfff44046` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | W? W? W1546 | - |
| `0xfff44146` | M | N2 | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | RET | - |
| `0xfff44316` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R? R? R? R? R? RET | - |
| `0xfff44656` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | W? W? W? W? W? W1546 | - |
| `0xfff44776` | M | N2 | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | RET | - |
| `0xfff44976` | M | N2 | srlz.d | bank x7; 1546=8**80*xx*0000000 | RET | - |
| `0xfff44aa6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 R1547 RET | - |
| `0xfff44c56` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1545=*xxxxxxxxxxxxx; 1547=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xfff44d96` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1545=0; 1546=8**00*xx*0000000 | RET | - |
| `0xfff44eb6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 RET | - |
| `0xfff450a6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 W1545 W1546 | - |
| `0xfff45116` | M | N2 | srlz.d | 1545=*xxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xfff452e6` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 W1546 W1545 | - |
| `0xfff45376` | M | N2 | srlz.d | 1546=8**00*xx*0000000; 1545=*xxxxxxxxxxxxx | RET | - |
| `0xfff45556` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 W1545 W1547 W1546 | - |
| `0xfff455e6` | M | N2 | srlz.d | 1545=*xxxxxxxxxxxxx; 1547=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xfff46196` | M | S | srlz.d | ?=x*xxxxxxx**xxxxx; ?=x*xxxxxxx***xxxx; 1546=8**00*xx*0000000; 1544=xxxxxxxxxxxx**xx | R1608 (cmp) RET | - |
| `0xfff46446` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1028 R1029 R1030 R1031 RET | - |
| `0xfff465f6` | M | N2 | srlz.d | bank x4; 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | RET | - |
| `0xfff473d6` | M | N1 | srlz.d | 1084=xxxxxxxxxxxxx*xx; 1416=xx**xxxxxxxxxxxx; 1544=1; 1546=8**00*xx*0000000 | W1544 Wbank x4 W1546 | - |
| `0xfff47436` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x4; 1546=8**00*xx*0000000 | RET | - |
| `0xfff47586` | M | N1 | srlz.d | 1544=1; 1546=8**00*xx*0000000 | W1544 W1546 | - |
| `0xfff475c6` | M | S | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1608 W1546 | - |
| `0xfff47616` | M | S | srlz.d | 1546=8**00*xx*0000000 | R1608 W1546 | - |
| `0xfff47676` | M | S | srlz.d | 1546=8**00*xx*0000000 | R1608 W1546 | - |
| `0xfff476b6` | M | S | srlz.d | 1546=8**00*xx*0000000 | R1608 RET | - |
| `0xfff4b776` | M | R | srlz.d | 1504=xx**xxxxxxxxxxxx; 1504=xx**xxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | - |
| `0xfff4b8b6` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | R1510 (cmp vs 0x25) W1544 W1546 | - |
| `0xfff4b976` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | - |
| `0xfff4bab6` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | R1511 (cmp vs 0x25) W1544 W1546 | - |
| `0xfff4bb76` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | - |
| `0xfff4bcb6` | M | O | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=8**00*xx*0000000 | R1512 (cmp vs 0x25) W1544 W1546 | - |
| `0xfff4bd76` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1545 (cmp vs 0x7) W1544 Wbank x1 W1546 | - |
| `0xfff4beb6` | M | N2 | srlz.d | 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=*x*00*xx*0000000 | BR | - |
| `0xfff4eadc` | B | B1 | srlz.i | 1416=xxxxxxxxxxx*xxxx; 1237=xxxxxxxxxxxxxxxx; 1282=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | R1282 W1282 R1237 (tbit vs 0x5) W1237 R1553 (tbit vs 0xb) R1536 ... | D |
| `0xfff4ef26` | M | R | srlz.d | 1536=xxxxxxxxxxx*xxxx; 1553=xxxxxxxxxxxxx*xx; 1544=0; 1546=*x*0*xxxxxxxxxxx | R1545 BR | - |
| `0xfff4fac6` | M | R | srlz.d | 1536=xxxxxxxxxxx*xxxx; 1553=xxxxxxxxxxxxx*xx; 1544=0; 1546=*x*0*xxxxxxxxxxx | R1545 R1237 W1237 R1237 (tbit vs 0x0) R1282 (tbit vs 0x7) W1282 ... | - |
| `0xfff4fc6c` | B | BP | srlz.i | 1237=xxxxxxxxxxxxxx*x; 1282=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | R1282 W1282 R1237 W1237 R1416 W1416 ... | D |
| `0xfff50416` | M | R | srlz.d | 1536=xxxxxxxxxxx*xxxx; 1553=xxxxxxxxxxxxx*xx; 1544=0; 1546=*x*0*xxxxxxxxxxx | R1545 R1237 W1237 R1237 (tbit vs 0x0) R1282 (tbit vs 0x7) W1282 ... | - |
| `0xfff505bc` | B | BP | srlz.i | 1237=xxxxxxxxxxxxxx*x; 1282=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | R1282 W1282 R1237 W1237 R1416 W1416 ... | D |
| `0xfff50d16` | M | R | srlz.d | 1536=xxxxxxxxxxx*xxxx; 1553=xxxxxxxxxxxxx*xx; 1544=0; 1546=*x*0*xxxxxxxxxxx | R1545 R1237 W1237 R1237 (tbit vs 0x0) R1282 (tbit vs 0x7) W1282 ... | - |
| `0xfff50ebc` | B | BP | srlz.i | 1237=xxxxxxxxxxxxxx*x; 1282=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | R1282 W1282 R1237 W1237 R1416 W1416 ... | - |
| `0xfff530e6` | M | P1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) BR | - |
| `0xfff548c6` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 R1152 (tbit vs 0x12) R1237 (tbit vs 0x2) ... | - |
| `0xfff553b6` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 R1152 (tbit vs 0x12) R1237 (tbit vs 0x2) ... | D |
| `0xfff55d86` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 R1152 (tbit vs 0x12) R1237 (tbit vs 0x2) ... | - |
| `0xfff562d6` | M | W2 | srlz.i | 1730=xxxxxxxxxxxxxxxx; 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1730=xxxxx**xxxxxxxxx | W1730 W1640 R1553 W1553 BR | - |
| `0xfff56466` | M | N1 | srlz.i | 1553=xxxxx*xxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xfff572a6` | M | N1 | srlz.d | 1040=4; 1545=xxxxxxxxxxxxxxx*; 1544=xxxxxxxxxxxxxxxx; 1546=xxxxxxxxxxxxxxxx | R1559 Wbank x11 | - |
| `0xfff57436` | M | N2 | srlz.d | bank x6; 1544=xxxxxxxxxxxxxxxx; 1546=9490**03400*xxxx | RET | - |
| `0xfff577e6` | M | N1 | srlz.i | 1558=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xfff57946` | M | N1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xfff5ab6c` | B | B1 | srlz.i | 1641=xxxxxxxxxxxxxxxx; 1776=xxxxxxxxxxxxxxxx; 1464=xxxxxxxxxxxxxxxx; 1283=xxxxxxxxxxxxxxxx | R0 R1641 | D |
| `0xfff5abac` | B | B0 | srlz.i | - | R0 R1642 | D |
| `0xfff5abfc` | B | B0 | srlz.i | - | R0 R1641 R1642 | D |
| `0xfff5ac3c` | B | B0 | srlz.i | - | BR | D |
| `0xfff5dbfc` | B | B1 | srlz.i | 1776=xxxxxxxxxxxxxxxx; 1464=xxxxxxxxxxxxxxxx; 1283=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | CALL | - |
| `0xfff6a28c` | B | B1 | srlz.i | 1643=xxxxxxxxxxxxxxxx; 1642=xxxxxxxxxxxxxxxx; 1282=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | W1282 R1640 R1237 (tbit vs 0x6) W1237 R1572 (tbit vs 0xe) | - |
| `0xfff6c06c` | B | B1 | srlz.i | 1237=xxxxxxxxxxxxxx*x; 1640=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1664=xxxxxxxxxxxxxxx* | R1642 R0 | E |
| `0xfff6c13c` | B | B0 | srlz.i | - | R1642 R1641 R0 | E |
| `0xfff6c18c` | B | B0 | srlz.i | - | R? R1641 | E |
| `0xfff6c1cc` | B | B0 | srlz.i | - | R? | E |
| `0xfff6c1fc` | B | B0 | srlz.i | - | BR | E |
| `0xfff72cd6` | M | R | srlz.d | 1536=xxxxxxxxxxx*xxxx; 1553=xxxxxxxxxxxxx*xx; 1544=0; 1546=*x*0*xxxxxxxxxxx | R1545 R1416 W1416 R1152 (tbit vs 0x12) R1237 (tbit vs 0x2) R1572 (tbit vs 0x12) ... | - |
| `0xfff736d6` | M | R | srlz.d | 1536=xxxxxxxxxxx*xxxx; 1553=xxxxxxxxxxxxx*xx; 1544=0; 1546=*x*0*xxxxxxxxxxx | R1545 BR | - |
| `0xfff73d06` | M | O | srlz.i | 1728=xxx*xxxxxxxxxxxx; 1730=xxxxxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | R1779 W1779 W1779 R1558 R1168 W1168 ... | E |
| `0xfff74476` | M | R | srlz.d | 1536=xxxxxxxxxxx*xxxx; 1553=xxxxxxxxxxxxx*xx; 1544=0; 1546=*x*0*xxxxxxxxxxx | R1545 R1640 (tbit vs 0x4) R1553 R1536 W1536 W1553 ... | - |
| `0xfff748b6` | M | P2 | srlz.d | 1536=xxxxxxxxxxx*xxxx; 1553=xxxxxxxxxxxxx*xx; 1544=0; 1546=*x*0*xxxxxxxxxxx | R1545 R1640 (cmp vs 0x0) R1416 W1416 R1416 (tbit vs 0x28) BR | - |
| `0xfff74e6c` | B | B1 | srlz.i | 1416=xxxxxxxxxxx*xxxx; 1664=xxxxxxxxxxxxxxx* | BR | - |
| `0xfff75686` | M | N1 | srlz.d | bank x1; 1084=xxxxxxxx*xxxxxfx; 1544=380; 1546=9780**00000003ff | R1559 W1544 W1546 | R |
| `0xfff75706` | M | N1 | srlz.d | 1544=10380; 1546=9780**00000103ff | R1559 W1544 W1546 | R |
| `0xfff75786` | M | N1 | srlz.d | 1544=20380; 1546=9780**00000203ff | R1559 W1544 W1546 | R |
| `0xfff75806` | M | N1 | srlz.d | 1544=30380; 1546=9780**00000303ff | W1084 W1057 W1056 R1559 W1544 Wbank x1 ... | R |
| `0xfff758f6` | M | O | srlz.d | 1056=200007; 1544=xxxxxxxxxxxxxxxx; bank x1; 1546=97c0**01d0003000 | R0 (tbit vs 0x1) W1056 W1040 CALL | R |
| `0xfff77b36` | M | K | srlz.d | 1640=xxxxxxxxxxxxxxxx; 1664=2; 1544=xxxxxxxxxxxxxxxx; 1546=9021004d60000001 | R1212 (tbit vs 0xe) R1226 (cmp vs r20?) BR | R |
| `0xfff77bf6` | M | U | srlz.d | 1640=x*xxxxxxxxxxxxxx; ?=9020000000000001 | W1664 R0 (tbit vs 0x18) W1573 R1779 (tbit vs 0xf) BR | R |
| `0xfff78da6` | M | N1 | srlz.i | 1416=xxxxxxxxxxx*xxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1552 BR | - |
| `0xfff90e76` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xfff90ec6` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xfff90f16` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 CALL | - |
| `0xfff911a6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*3x | W1546 Wbank x1 W1084 | - |
| `0xfff911f6` | M | W1 | srlz.i | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*1x | W1546 Wbank x1 W1084 | - |
| `0xfff91246` | M | W1 | srlz.d | 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxx*2x | W1084 W? | - |
| `0xfff91d46` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff91ec6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff92046` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff921c6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff92346` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff924c6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff92646` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff927c6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 Wbank x1 ... | - |
| `0xfff92906` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxxxxx | W1084 W? BR | - |
| `0xfff92cd6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff92e56` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff92fd6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff93156` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff932d6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff93456` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff935d6` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 R1559 R1084 W1544 W1546 W1084 ... | - |
| `0xfff93756` | M | W1 | srlz.i | 1544=xxxxxxxxxxx*xxxx; 1546=8**00*xx*0000300; 1084=xxxxxxxx80000**x; bank x4 | W1084 W? BR | - |
| `0xfff93956` | M | W1 | srlz.i | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000300; bank x1; 1084=xxxxxxxx*xxxxxxx | W1084 RET | - |
| `0xfff94610` | M | S | srlz.d | ?=xxxxxxxxxxxxxxxx; ?=xxxxxxxxxxxxxxxx; 1544=xx; 1546=8*xx**xx*0000000 | R1600 R1601 R1601 R1600 RET | - |
| `0xfff947d0` | M | N2 | srlz.d | bank x6; 1544=xxx; 1546=8**00*xx*0000000 | RET | - |
| `0xfff95030` | M | N1 | srlz.d | 1056=xxxxxxxxxxxxxxx*; 1544=0; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xfff95150` | M | O | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xfff95290` | M | N1 | srlz.d | 1544=0; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xfff953b0` | M | O | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xfff954e0` | M | N1 | srlz.d | 1544=0; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xfff95610` | M | O | srlz.d | 1544=*xx; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xfff95740` | M | N1 | srlz.d | 1544=*xx; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xfff95870` | M | O | srlz.d | 1544=*xxx; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) W1544 R1559 Wbank x1 W1546 | - |
| `0xfff959a0` | M | N1 | srlz.d | 1544=*xxx; bank x1; 1546=8**00*xx*0000000 | W1544 R1559 W1546 | - |
| `0xfff95ac0` | M | O | srlz.d | 1544=**00; 1546=8**00*xx*0000000 | R1058 (cmp vs r46?) BR | - |
| `0xfff95e00` | M | R | srlz.d | ?=xxxxxxxxxxxxxxxx; 480=xxxxxx*xxxxxxxxx; 1544=0; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xfff96150` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=0 | R1559 W1544 W1546 | - |
| `0xfff962a0` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 | - |
| `0xfff96400` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xfff96750` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=*00 | R1559 W1544 W1546 | - |
| `0xfff968a0` | M | R | srlz.d | 1544=*000; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 | - |
| `0xfff96a00` | M | R | srlz.d | 1544=*00; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xfff96d50` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=*00 | R1559 W1544 W1546 | - |
| `0xfff96eb0` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 | - |
| `0xfff97010` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xfff97360` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xfff974c0` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 | - |
| `0xfff97620` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (tbit vs 0x3) | - |
| `0xfff97970` | M | N1 | srlz.d | bank x1; 1546=8d40000000000000; 1544=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xfff97ac0` | M | R | srlz.d | 1544=*000; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) W? BR | - |
| `0xfff97f20` | M | N1 | srlz.d | 529=xxxxxxxxxxxxxxx*; 1544=0; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xfff98070` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 W1545 | - |
| `0xfff98230` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xfff98380` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 W1545 | - |
| `0xfff98540` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xfff986a0` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) R1559 W1544 W1546 W1545 | - |
| `0xfff98860` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xfff989c0` | M | R | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000 | R1545 (cmp vs r41?) R1559 W1544 W1546 W1545 | - |
| `0xfff98b80` | M | N1 | srlz.d | 1544=xxxxxxxxxxxxxxxx; 1546=8**00*xx*0000000; 1545=*xxxxxxx*00000 | R1559 W1544 W1546 | - |
| `0xfff98cd0` | M | R | srlz.d | 1544=x*00; 1546=8**00*xx*0000000 | R1545 (cmp vs r40?) BR | - |
| `0xfff99100` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xx*00; 1547=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xfff99260` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 R1547 (cmp vs r39?) R1559 W1544 W1546 W1545 ... | - |
| `0xfff99460` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xx*00; 1547=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xfff995c0` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 R1547 (cmp vs r40?) R1559 W1544 W1546 W1545 ... | - |
| `0xfff997c0` | M | N1 | srlz.d | 1544=0; 1546=8**00*xx*0000000; 1545=*xx*00; 1547=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xfff99930` | M | R | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | R1545 R1547 (cmp vs r39?) R1559 W1544 W1546 W1545 ... | - |
| `0xfff99b30` | M | N1 | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000; 1545=*xx*00; 1547=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xfff99ca0` | M | R | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000 | R1545 R1547 (cmp vs r40?) R1559 W1544 W1546 W1545 ... | - |
| `0xfff99ea0` | M | N1 | srlz.d | 1544=xxxxxxxxxxxx**xx; 1546=8**00*xx*0000000; 1545=*xx*00; 1547=xxxxxxxxxxxxxxxx | R1559 W1544 W1546 | - |
| `0xfff9a000` | M | R | srlz.d | 1544=0; 1546=8**00*xx*0000000 | R1545 R1547 (cmp vs r39?) BR | - |
| `0xfff9a226` | M | P1 | srlz.i | ?=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) | - |
| `0xfffa1586` | M | P1 | srlz.i | 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffa1936` | M | N1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 R1552 W1552 R? W? CALL | - |
| `0xfffa1d66` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffa2766` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) | - |
| `0xfffa2e76` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffa36e6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffa3d46` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffa47d6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffa4c56` | M | N1 | srlz.i | 1512=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 BR | - |
| `0xfffa50c6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) | - |
| `0xfffa5866` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) R1560 R1640 W1560 ... | - |
| `0xfffa6156` | M | P1 | srlz.i | 1640=xxxxxxxxxxxxxxxx; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffa6926` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffa77d6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffa8586` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffa9356` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffa9ce6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffaa576` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffaae26` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
| `0xfffab6a6` | M | P1 | srlz.i | 1552=xxxxxxxxxxxxxx*x; 1640=xx*xxxxxxxxxxxxx; 1544=xxxxxxxxxxxxxxxx; 1546=8940000000000000 | W1640 W1552 R1552 (tbit vs 0x2) CALL | - |
