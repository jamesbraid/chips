# MACE I/O ASIC Specification, chip revision 2.0: register map

Transcribed from the register tables of the specification for the register comparison in `tools/configs/mace.json`:
PCI host bridge (chapter 9, table 82), audio (table 26), ISA control (table 52), PS/2 (table 70), I2C (table 76),
timers (table 75), external ISA address map (table 68), Ethernet (table 37), the video channel registers (table 5)
and the address maps of chapter 12
(tables 91 to 93). Offsets are physical offsets from the start of the MACE window at `0x1f000000` (the
specification prints physical addresses and block-local offsets; the block bases below come from table 91 and
table 92). The video channel register sets (chapter 2, table 5) are transcribed by name and offset only; their bit fields
are not.

The specification says every internal register is defined on a 64-bit aligned boundary, readable and writable by
64-bit programmed I/O, and that the registers of a block are repeated to fill the block's address range (the
peripheral controller blocks, the Ethernet block), except the PCI block, whose six registers are not repeated: a
read of any other address in it returns `0xff` in every byte lane and a write is discarded. The PCI registers are
32-bit and accept word accesses only (the configuration data register also takes byte, halfword and three-byte
accesses). Each 8-bit register of the external ISA block spans 256 bytes in the internal view.

## PCI host bridge

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x80000` | PCI_ERR_ADDR | read-only | PCI Error Address Register |
| `0x80004` | PCI_ERR_FLAGS | read/write | PCI Error Flags Register |
| `0x80008` | PCI_CONTROL | read/write | PCI Host Bridge Control Register |
| `0x8000c` | PCI_FLUSH_REV | read/write | Read Buffer Flush (write) and Revision Info (read) |
| `0x80cf8` | PCI_CONFIG_ADDR | write only | CONFIG_ADDRESS |
| `0x80cfc` | PCI_CONFIG_DATA | read/write | CONFIG_DATA |

## Audio

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x300000` | AUD_CONTROL | read/write | Control & Status (reset control & status) |
| `0x300008` | AUD_CODEC_CNTL | read/write | Codec status control |
| `0x300010` | AUD_CODEC_MASK | read/write | Codec status input mask |
| `0x300018` | AUD_CODEC_READ | read only | Codec status input |
| `0x300020` | AUD_CH1_CNTL | read/write | Ch1 in Ring Control |
| `0x300028` | AUD_CH1_READ | read/write | Ch1 in Read Pointer |
| `0x300030` | AUD_CH1_WRITE | read/write | Ch1 in Write Pointer |
| `0x300038` | AUD_CH1_DEPTH | read only | Ch1 in Ring Depth |
| `0x300040` | AUD_CH2_CNTL | read/write | Ch2 out Ring Control |
| `0x300048` | AUD_CH2_READ | read/write | Ch2 out Read Pointer |
| `0x300050` | AUD_CH2_WRITE | read/write | Ch2 out Write Pointer |
| `0x300058` | AUD_CH2_DEPTH | read only | Ch2 out Ring Depth |
| `0x300060` | AUD_CH3_CNTL | read/write | Ch3 out Ring Control |
| `0x300068` | AUD_CH3_READ | read/write | Ch3 out Read Pointer |
| `0x300070` | AUD_CH3_WRITE | read/write | Ch3 out Write Pointer |
| `0x300078` | AUD_CH3_DEPTH | read only | Ch3 out Ring Depth |

## ISA control

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x310000` | ISA_RING_BASE | read/write | Peripheral Controller Ring Base & Reset |
| `0x310008` | ISA_MISC | read/write | Misc. Control (Flash-ROM, DP-RAM, LED, NIC) |
| `0x310010` | ISA_INT_STAT | read/write | PC Interrupt Status |
| `0x310018` | ISA_INT_MASK | read/write | PC Interrupt Mask |
| `0x312000` to `0x313ff8` | ISA_DPRAM | read/write | DP-RAM programmed I/O access |
| `0x314000` | PAR_CONTEXT_A | read/write | Parallel Context A |
| `0x314008` | PAR_CONTEXT_B | read/write | Parallel Context B |
| `0x314010` | PAR_CNTL_STAT | read/write | Parallel Cntl/Status |
| `0x314018` | PAR_DIAG | read only | Parallel Diagnostic |
| `0x318000` | S1_TX_CNTL | read/write | S1 TX Control |
| `0x318008` | S1_TX_READ | read/write | S1 TX Read Pointer |
| `0x318010` | S1_TX_WRITE | read/write | S1 TX Write Pointer |
| `0x318018` | S1_TX_DEPTH | read only | S1 TX Ring Depth |
| `0x318020` | S1_RX_CNTL | read/write | S1 RX Control |
| `0x318028` | S1_RX_READ | read/write | S1 RX Read Pointer |
| `0x318030` | S1_RX_WRITE | read/write | S1 RX Write Pointer |
| `0x318038` | S1_RX_DEPTH | read only | S1 RX Ring Depth |
| `0x31c000` | S2_TX_CNTL | read/write | S2 TX Control |
| `0x31c008` | S2_TX_READ | read/write | S2 TX Read Pointer |
| `0x31c010` | S2_TX_WRITE | read/write | S2 TX Write Pointer |
| `0x31c018` | S2_TX_DEPTH | read only | S2 TX Ring Depth |
| `0x31c020` | S2_RX_CNTL | read/write | S2 RX Control |
| `0x31c028` | S2_RX_READ | read/write | S2 RX Read Pointer |
| `0x31c030` | S2_RX_WRITE | read/write | S2 RX Write Pointer |
| `0x31c038` | S2_RX_DEPTH | read only | S2 RX Ring Depth |

## PS/2

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x320000` | KBD_TX | write only | Keyboard Transmit Buffer |
| `0x320008` | KBD_RX | read only | Keyboard Receive Buffer |
| `0x320010` | KBD_CONTROL | read/write | Keyboard Control |
| `0x320018` | KBD_STATUS | read only | Keyboard Status |
| `0x320020` | MOUSE_TX | write only | Mouse Transmit Buffer |
| `0x320028` | MOUSE_RX | read only | Mouse Receive Buffer |
| `0x320030` | MOUSE_CONTROL | read/write | Mouse Control |
| `0x320038` | MOUSE_STATUS | read only | Mouse Status |

## I2C

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x330000` | I2C_CONFIG | read/write | Config & Reset |
| `0x330008` | I2C_CONFIG_ALIAS | read/write | Reserved (alias of Config & Reset) |
| `0x330010` | I2C_CONTROL | read/write | Control & Status |
| `0x330018` | I2C_DATA | read/write | Data |

## Timers

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x340000` | TMR_UST | read/write | Universal System Time |
| `0x340008` | TMR_COMPARE1 | read/write | Compare Timer #1 |
| `0x340010` | TMR_COMPARE2 | read/write | Compare Timer #2 |
| `0x340018` | TMR_COMPARE3 | read/write | Compare Timer #3 |
| `0x340020` | TMR_AIN | read/write | Audio Input UST (high word at +0x20) and MSC (low word at +0x24) |
| `0x340028` | TMR_AOUT1 | read/write | Audio Output #1 UST and MSC |
| `0x340030` | TMR_AOUT2 | read/write | Audio Output #2 UST and MSC |
| `0x340038` | TMR_VIN1 | read/write | Video Input #1 UST and MSC |
| `0x340040` | TMR_VIN2 | read/write | Video Input #2 UST and MSC |
| `0x340048` | TMR_VOUT | read/write | Video Output UST and MSC |

## External ISA block

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x380000` to `0x387ff8` | ISA_PARALLEL | read/write | Centronics/EPP Parallel Port Interface |
| `0x388000` to `0x38fff8` | ISA_ECP1284 | read/write | ECP1284 Parallel Port Registers |
| `0x390000` to `0x397ff8` | ISA_SERIAL1 | read/write | Serial Port COM #1 |
| `0x398000` to `0x39fff8` | ISA_SERIAL2 | read/write | Serial Port COM #2 |
| `0x3a0000` to `0x3affff` | ISA_RTC | read/write | Dallas Calendar Clock chip (256 bytes, one register per 256-byte step) |

## Ethernet

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x280000` | ETH_MAC_CONTROL | read/write | MAC Control |
| `0x280008` | ETH_INT_STATUS | read/write | Interrupt Status |
| `0x280010` | ETH_DMA_CONTROL | read/write | DMA Control |
| `0x280018` | ETH_TIMER | read/write | Timer |
| `0x280020` | ETH_TX_INT_ALIAS | write only | Transmit Interrupt Alias |
| `0x280028` | ETH_RX_INT_ALIAS | write only | Receive Interrupt Alias |
| `0x280030` | ETH_TX_RING_PTR | read/write | TX Ring buffer r/w ptr |
| `0x280038` | ETH_TX_RING_PTR_ALIAS | read/write | Alias of the transmit ring pointer register |
| `0x280040` | ETH_RX_FIFO | read only | RX mcl FIFO w/r/d |
| `0x280048` | ETH_RX_FIFO_ALIAS1 | read only | Alias of the receive FIFO register |
| `0x280050` | ETH_RX_FIFO_ALIAS2 | read only | Alias of the receive FIFO register |
| `0x280058` | ETH_INT_REQUEST | write only | Interrupt Request (write) and Last Transmit Vector (read, diagnostic) |
| `0x280060` | ETH_PHY_DATA | write only | PHY data out (write) and PHY data in (read) |
| `0x280068` | ETH_PHY_ADDR | read/write | PHY address |
| `0x280070` | ETH_PHY_READ_START | write only | PHY read start |
| `0x280078` | ETH_BACKOFF | write only | Backoff |
| `0x280080` to `0x280098` | ETH_INCOMING_MSG | read only | Incoming message queue (reserved) |
| `0x2800a0` | ETH_PHYS_ADDR | read/write | Physical Address |
| `0x2800a8` | ETH_PHYS_ADDR2 | read/write | Secondary Physical Address |
| `0x2800b0` | ETH_MCAST_FILTER | read/write | Multicast Filter |
| `0x2800b8` | ETH_TX_RING_BASE | read/write | Transmit Ring Base |
| `0x2800c0` to `0x2800f8` | ETH_TX_DIAG | read only | Transmit packet 1 and 2 command header and concatenation pointers (diagnostic) |
| `0x280100` to `0x2801f8` | ETH_INTERNAL_RAM | read/write | Internal RAM |

## Video

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x100000` | VIN1_CONTROL | read/write | Video Input Channel #1 DMA Control |
| `0x100008` | VIN1_STATUS | read/write | Video Input Channel #1 DMA Status |
| `0x100010` | VIN1_CONFIG | read/write | Video Input Channel #1 Channel configuration options |
| `0x100018` | VIN1_NEXT_DESC | read/write | Video Input Channel #1 Pointer to next descriptor block |
| `0x100020` | VIN1_FLD_OFFSET | read/write | Video Input Channel #1 Offset into first page for first pixel |
| `0x100028` | VIN1_LINE_WIDTH | read/write | Video Input Channel #1 Width of each video line in bytes |
| `0x100030` | VIN1_HCLIP_ODD | read/write | Video Input Channel #1 Pixel boundaries for odd video input line |
| `0x100038` | VIN1_VCLIP_ODD | read/write | Video Input Channel #1 Line boundaries for odd video input line |
| `0x100040` | VIN1_ALPHA_ODD | read/write | Video Input Channel #1 Alpha value for odd video input line |
| `0x100048` | VIN1_HCLIP_EVEN | read/write | Video Input Channel #1 Pixel boundaries for even video input line |
| `0x100050` | VIN1_VCLIP_EVEN | read/write | Video Input Channel #1 Line boundaries for even video input line |
| `0x100058` | VIN1_ALPHA_EVEN | read/write | Video Input Channel #1 Alpha value for even video input line |
| `0x100080` to `0x1000b8` | VIN1_DMA_DESC | read/write | Video Input Channel #1 DMA Descriptors |
| `0x180000` | VIN2_CONTROL | read/write | Video Input Channel #2 DMA Control |
| `0x180008` | VIN2_STATUS | read/write | Video Input Channel #2 DMA Status |
| `0x180010` | VIN2_CONFIG | read/write | Video Input Channel #2 Channel configuration options |
| `0x180018` | VIN2_NEXT_DESC | read/write | Video Input Channel #2 Pointer to next descriptor block |
| `0x180020` | VIN2_FLD_OFFSET | read/write | Video Input Channel #2 Offset into first page for first pixel |
| `0x180028` | VIN2_LINE_WIDTH | read/write | Video Input Channel #2 Width of each video line in bytes |
| `0x180030` | VIN2_HCLIP_ODD | read/write | Video Input Channel #2 Pixel boundaries for odd video input line |
| `0x180038` | VIN2_VCLIP_ODD | read/write | Video Input Channel #2 Line boundaries for odd video input line |
| `0x180040` | VIN2_ALPHA_ODD | read/write | Video Input Channel #2 Alpha value for odd video input line |
| `0x180048` | VIN2_HCLIP_EVEN | read/write | Video Input Channel #2 Pixel boundaries for even video input line |
| `0x180050` | VIN2_VCLIP_EVEN | read/write | Video Input Channel #2 Line boundaries for even video input line |
| `0x180058` | VIN2_ALPHA_EVEN | read/write | Video Input Channel #2 Alpha value for even video input line |
| `0x180080` to `0x1800b8` | VIN2_DMA_DESC | read/write | Video Input Channel #2 DMA Descriptors |
| `0x200000` | VOUT_CONTROL | read/write | Video Output Channel DMA Control |
| `0x200008` | VOUT_STATUS | read/write | Video Output Channel DMA Status |
| `0x200010` | VOUT_CONFIG | read/write | Video Output Channel Channel configuration options |
| `0x200018` | VOUT_NEXT_DESC | read/write | Video Output Channel Pointer to next descriptor block |
| `0x200020` | VOUT_FLD_OFFSET | read/write | Video Output Channel Offset into first page for first pixel |
| `0x200028` | VOUT_FIELD_SIZE | read/write | Video Output Channel Width and height of output field |
| `0x200030` | VOUT_HPAD_ODD | read/write | Video Output Channel Pixel boundaries for odd video output line |
| `0x200038` | VOUT_VPAD_ODD | read/write | Video Output Channel Line boundaries for odd video output line |
| `0x200040` | VOUT_HPAD_EVEN | read/write | Video Output Channel Pixel boundaries for even video output line |
| `0x200048` | VOUT_VPAD_EVEN | read/write | Video Output Channel Line boundaries for even video output line |
| `0x200050` | VOUT_GEN_DLY | read/write | Video Output Channel Genlock Delay Value |
| `0x200058` | VOUT_VHW_CFG | read/write | Video Output Channel Hardware Configuration |
| `0x200080` to `0x2000b8` | VOUT_DMA_DESC | read/write | Video Output Channel DMA Descriptors |
