# Crossbow ASIC Specification, revision 12.0: register map

Transcribed from the address map on printed pages 73 to 76 (11/18/96) for the register comparison in
`tools/configs/xbow.json`. Offsets are widget-local byte offsets (the specification prints them as
`0x00_0000_0000` and so on). The specification says every register is 32 bits or less, aligned to a 64-bit
boundary with the data in bits 31:0, reachable only by a double-word packet; an access to a reserved address
or any other packet type is an error, and so is a write to a read-only or read-and-clear register.
The link registers start at 0x100 for link 8, and each next link is 0x40 above the previous one.
Access words are the specification's own ("read&clear" is a read that also clears the error bits).

## Common registers

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x0` | XB_ID | read-only | Crossbow Identification |
| `0x8` | XB_STAT | read-only | Crossbow Widget 0 Status |
| `0x10` | XB_ERR_UPPER | read-only | Crossbow Error Upper Address |
| `0x18` | XB_ERR_LOWER | read-only | Crossbow Error Lower Address |
| `0x20` | XB_CTRL | read/write | Crossbow Widget 0 Control |
| `0x28` | XB_PKT_TO | read/write | Crossbow Packet Time-out |
| `0x30` | XB_INT_UPPER | read/write | Crossbow Interrupt Destination Upper Address |
| `0x38` | XB_INT_LOWER | read/write | Crossbow Interrupt Destination Lower Address |
| `0x40` | XB_ERR_CMDWORD | read/write | Crossbow Error Command Word |
| `0x48` | XB_LLP_CTRL | read/write | Crossbow LLP Control |
| `0x50` | XB_STAT_CLR | read&clear | Crossbow Widget 0 Status (read and clear) |
| `0x58` | XB_ARB_RELOAD | read/write | Crossbow Arbitration Reload |
| `0x60` | XB_PERF_CTR_A | read/write | Crossbow Performance Counter A |
| `0x68` | XB_PERF_CTR_B | read/write | Crossbow Performance Counter B |
| `0x70` | XB_NIC | read/write | Crossbow NIC register |
| `0x78 to 0xf8` | Reserved | reserved | Reserved |

## Link registers

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x100 + 64xn` | XB_LINK_IBUF_FLUSH | read-only | Link (8 + n) Input Buffer Flush (n = 0 to 7) |
| `0x108 + 64xn` | XB_LINK_CTRL | read/write | Link (8 + n) Control (n = 0 to 7) |
| `0x110 + 64xn` | XB_LINK_STAT | read-only | Link (8 + n) Status (n = 0 to 7) |
| `0x118 + 64xn` | XB_LINK_ARB_UPPER | read/write | Link (8 + n) Arbitration Upper (n = 0 to 7) |
| `0x120 + 64xn` | XB_LINK_ARB_LOWER | read/write | Link (8 + n) Arbitration Lower (n = 0 to 7) |
| `0x128 + 64xn` | XB_LINK_STAT_CLR | read&clear | Link (8 + n) Status (read and clear) (n = 0 to 7) |
| `0x130 + 64xn` | XB_LINK_RESET | write-only | Link (8 + n) Reset (n = 0 to 7) |
| `0x138 + 64xn` | XB_LINK_AUX_STAT | read-only | Link (8 + n) Auxiliary Status (n = 0 to 7) |
| `0x300 to 0xffff8` | Reserved | reserved | Reserved |
