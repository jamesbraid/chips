/*
 * l1_requests.h - request codes the Origin 3000 kernel sends to the brick controller
 *
 * Written by hand, not generated: the census reads call arguments, not register offsets, so gen_headers.py does not
 * emit these. Label convention as the generated headers. Each value is [E]: the named routine passes it as the
 * request code of a message (the sixth argument of the message-send path). Names are the sending routine's name;
 * what each request does is [I] from that name, except where the chip page records agreement with the public
 * later-generation header. Target address and task: see the chip page.
 */
#ifndef L1_REQUESTS_H
#define L1_REQUESTS_H

#define L1_REQ_SC_COMMAND_INTERP     0x0000   /* [E] sent by sc_command_interp: interpret an ASCII command; role [I] */
#define L1_REQ_ELSC_DEBUG_GET        0x0001   /* [E] sent by elsc_debug_get; role [I] */
#define L1_REQ_RACK_BAY_TYPE_GET     0x0003   /* [E] sent by the rack, bay and brick type getters (elsc_cbrick_type_get and three more); role [I] */
#define L1_REQ_SC_VERSION            0x0005   /* [E] sent by sc_version, iobrick_sc_version; role [I] */
#define L1_REQ_IOBRICK_GET_SYS_SNUM  0x0008   /* [E] sent by iobrick_get_sys_snum; role [I] */
#define L1_REQ_ELSC_PARTITION_GET    0x0009   /* [E] sent by elsc_partition_get, peer_iobrick_partition_get; role [I] */
#define L1_REQ_SC_PORTSPEED_GET      0x000a   /* [E] sent by sc_portspeed_get, peer_iobrick_portspeed_get; role [I] */
#define L1_REQ_IOBRICK_ATTACHED_BRICKS 0x000c   /* [E] sent by iobrick_attached_bricks; role [I] */
#define L1_REQ_ELSC_SLAB_GET         0x000e   /* [E] sent by elsc_slab_get; role [I] */
#define L1_REQ_ELSC_CONS_SUBCH       0x1002   /* [E] sent by elsc_cons_subch; role [I] */
#define L1_REQ_ELSC_CONS_NODE        0x1003   /* [E] sent by elsc_cons_node; role [I] */
#define L1_REQ_ELSC_DISPLAY_LINE_1   0x1004   /* [E] sent by elsc_display_line, line 0 (request is 4100 plus the line number); role [I] */
#define L1_REQ_ELSC_DISPLAY_LINE_2   0x1005   /* [E] sent by elsc_display_line, line 1; role [I] */
#define L1_REQ_ELSC_PARTITION_SET    0x1006   /* [E] sent by elsc_partition_set, peer_iobrick_partition_set; role [I] */
#define L1_REQ_ELSC_LED_SET          0x1009   /* [E] sent by elsc_led_set; role [I] */
#define L1_REQ_ELSC_EVT_UNREG        0x100a   /* [E] sent by elsc_evt_unreg; role [I] */
#define L1_REQ_SC_SET_SYSTEM_STATE   0x100c   /* [E] sent by sc_set_system_state; role [I] */
#define L1_REQ_ELSC_SYSTEM_RESET     0x2001   /* [E] sent by elsc_system_reset; the public later-generation header gives this number to a different request, see the chip page; role [I] */
#define L1_REQ_ELSC_PWR_OFF          0x2005   /* [E] sent by elsc_pwr_off; role [I] */
#define L1_REQ_ELSC_PWR_CYCLE        0x2006   /* [E] sent by elsc_pwr_cycle; role [I] */
#define L1_REQ_ELSC_ODY_EXPANDER_GET 0x2007   /* [E] sent by elsc_ody_expander_get; role [I] */
#define L1_REQ_ELSC_ODY_EXPANDER_SET 0x2008   /* [E] sent by elsc_ody_expander_set; role [I] */

#endif /* L1_REQUESTS_H */
