<!-- generated from formats/l1_requests/format.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 9b3aa784db21ee484f4206cd4dc8b9729cd11cf3f9d9d9a81598e181b6c4e09d -->

# request codes the Origin 3000 kernel sends to the brick controller

Unit `l1_requests`, macro prefix `L1`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `REQ_ELSC_CONS_NODE` | 0x1003 | established |  | sent by elsc_cons_node; role [I] |
| `REQ_ELSC_CONS_SUBCH` | 0x1002 | established |  | sent by elsc_cons_subch; role [I] |
| `REQ_ELSC_DEBUG_GET` | 0x1 | established |  | sent by elsc_debug_get; role [I] |
| `REQ_ELSC_DISPLAY_LINE_1` | 0x1004 | established |  | sent by elsc_display_line, line 0 (request is 4100 plus the line number); role [I] |
| `REQ_ELSC_DISPLAY_LINE_2` | 0x1005 | established |  | sent by elsc_display_line, line 1; role [I] |
| `REQ_ELSC_EVT_UNREG` | 0x100a | established |  | sent by elsc_evt_unreg; role [I] |
| `REQ_ELSC_LED_SET` | 0x1009 | established |  | sent by elsc_led_set; role [I] |
| `REQ_ELSC_ODY_EXPANDER_GET` | 0x2007 | established |  | sent by elsc_ody_expander_get; role [I] |
| `REQ_ELSC_ODY_EXPANDER_SET` | 0x2008 | established |  | sent by elsc_ody_expander_set; role [I] |
| `REQ_ELSC_PARTITION_GET` | 0x9 | established |  | sent by elsc_partition_get, peer_iobrick_partition_get; role [I] |
| `REQ_ELSC_PARTITION_SET` | 0x1006 | established |  | sent by elsc_partition_set, peer_iobrick_partition_set; role [I] |
| `REQ_ELSC_PWR_CYCLE` | 0x2006 | established |  | sent by elsc_pwr_cycle; role [I] |
| `REQ_ELSC_PWR_OFF` | 0x2005 | established |  | sent by elsc_pwr_off; role [I] |
| `REQ_ELSC_SLAB_GET` | 0xe | established |  | sent by elsc_slab_get; role [I] |
| `REQ_ELSC_SYSTEM_RESET` | 0x2001 | established |  | sent by elsc_system_reset; the public later-generation header gives this number to a different request, see the chip page; role [I] |
| `REQ_IOBRICK_ATTACHED_BRICKS` | 0xc | established |  | sent by iobrick_attached_bricks; role [I] |
| `REQ_IOBRICK_GET_SYS_SNUM` | 0x8 | established |  | sent by iobrick_get_sys_snum; role [I] |
| `REQ_RACK_BAY_TYPE_GET` | 0x3 | established |  | sent by the rack, bay and brick type getters (elsc_cbrick_type_get and three more); role [I] |
| `REQ_SC_COMMAND_INTERP` | 0x0 | established |  | sent by sc_command_interp: interpret an ASCII command; role [I] |
| `REQ_SC_PORTSPEED_GET` | 0xa | established |  | sent by sc_portspeed_get, peer_iobrick_portspeed_get; role [I] |
| `REQ_SC_SET_SYSTEM_STATE` | 0x100c | established |  | sent by sc_set_system_state; role [I] |
| `REQ_SC_VERSION` | 0x5 | established |  | sent by sc_version, iobrick_sc_version; role [I] |
