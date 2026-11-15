# UV hub MMR address map

Offsets of every register the Linux UV platform headers define, by hub generation, relative to the local MMR window
(see [the platform page](README.md) for the window bases) or, in the global window, the same offset above the pnode
slot. A dash means the generation has no such register or the header gives it no address. All entries are
**established** as definitions in `v5.4:arch/x86/include/asm/uv/uv_mmrs.h` (UV1 to UV4) and
`v6.6:arch/x86/include/asm/uv/uv_mmrs.h` (UV5). Field layouts are in the per-generation maps
([uv1](../../devices/uv1/registers.md), [uv2](../../devices/uv2/registers.md), [uv3](../../devices/uv3/registers.md),
[uv4](../../devices/uv4/registers.md), [uv5](../../devices/uv5/registers.md)). The two kernel trees agree on every
UV4 register they both define (compared mechanically).

Registers exist only where the kernel needed them: this is about 70 registers of the many hundreds a hub has, and the
header never reveals the rest. The unlisted space is **unknown**; an emulator must decide a policy for reads of it.

Notable shifts between generations (established): the timer, scratch, BAU and GRU register groups move between UV3
and UV4; the address-map group moves from 0x1600000 (UV1 to UV3) to 0x480000 (UV4) and 0x470000 (UV5); the GRU TLB
control registers move from 0x401080 (UV1) to 0xc01080 (UV2 and UV3) to 0x601080 (UV4).

| Register | UV1 | UV2 | UV3 | UV4 | UV5 |
|---|---|---|---|---|---|
| `node_present_table` | 0x1400 | 0x1400 | 0x1400 | 0x1400 | - |
| `node_present_0` | - | - | - | - | 0x1400 |
| `node_present_1` | - | - | - | - | 0x1408 |
| `int_cmpb` | 0x22080 | 0x22080 | 0x22080 | 0x22080 | 0x22080 |
| `int_cmpc` | 0x22100 | 0x22100 | 0x22100 | 0x22100 | - |
| `int_cmpd` | 0x22180 | 0x22180 | 0x22180 | 0x22180 | - |
| `ipi_int` | 0x60500 | 0x60500 | 0x60500 | 0x60500 | 0x60500 |
| `extio_int0_broadcast` | 0x61448 | 0x61448 | 0x61448 | 0x61448 | 0x61448 |
| `rtc1_int_config` | 0x615c0 | 0x615c0 | 0x615c0 | 0x615c0 | 0x615c0 |
| `bau_data_config` | 0x61680 | 0x61680 | 0x61680 | 0x61680 | - |
| `bau_data_broadcast` | 0x61688 | 0x61688 | 0x61688 | 0x61688 | - |
| `gr0_tlb_int0_config` | 0x61b00 | 0x61b00 | 0x61b00 | 0x61b00 | - |
| `gr0_tlb_int1_config` | 0x61b40 | 0x61b40 | 0x61b40 | 0x61b40 | - |
| `gr1_tlb_int0_config` | 0x61f00 | 0x61f00 | 0x61f00 | 0x62100 | - |
| `gr1_tlb_int1_config` | 0x61f40 | 0x61f40 | 0x61f40 | 0x62140 | - |
| `event_occurred0` | 0x70000 | 0x70000 | 0x70000 | 0x70000 | 0x70000 |
| `event_occurred0_alias` | 0x70008 | 0x70008 | 0x70008 | 0x70008 | 0x70008 |
| `event_occurred1` | - | - | - | 0x70080 | 0x70080 |
| `event_occurred1_alias` | - | - | - | 0x70088 | 0x70088 |
| `event_occurred2` | - | 0x70100 | 0x70100 | 0x70100 | - |
| `event_occurred2` | - | - | - | 0x70100 | 0x70100 |
| `event_occurred2_alias` | - | 0x70108 | 0x70108 | 0x70108 | - |
| `event_occurred2_alias` | - | - | - | 0x70108 | 0x70108 |
| `lb_proc_intd_queue_first` | - | - | - | 0xa4100 | - |
| `lb_proc_intd_queue_last` | - | - | - | 0xa4108 | - |
| `lb_proc_intd_soft_ack_pending` | - | - | - | 0xa4110 | - |
| `lb_proc_intd_soft_ack_clear` | - | - | - | 0xa4118 | - |
| `scratch5` | 0x2d0200 | 0x2d0200 | 0x2d0200 | 0xb0200 | 0xb0200 |
| `scratch5_alias` | 0x2d0208 | 0x2d0208 | 0x2d0208 | 0xb0208 | 0xb0208 |
| `scratch5_alias_2` | 0x2d0210 | 0x2d0210 | 0x2d0210 | 0xb0210 | 0xb0210 |
| `lb_bau_sb_descriptor_base` | 0x320010 | 0x320010 | 0x320010 | 0xc8010 | - |
| `lb_bau_sb_activation_control` | 0x320020 | 0x320020 | 0x320020 | 0xc8020 | - |
| `lb_bau_sb_activation_status_0` | 0x320030 | 0x320030 | 0x320030 | 0xc8030 | - |
| `lb_bau_sb_activation_status_1` | 0x320040 | 0x320040 | 0x320040 | 0xc8040 | - |
| `lb_bau_sb_activation_status_2` | - | 0x320130 | 0x320130 | 0xc8130 | - |
| `lb_bau_misc_control` | 0x320170 | 0x320170 | 0x320170 | 0xc8170 | - |
| `rtc` | 0x340000 | 0x340000 | 0x340000 | 0xe0000 | 0xe0000 |
| `lb_bau_intd_payload_queue_first` | 0x320050 | 0x320050 | 0x320050 | - | - |
| `lb_bau_intd_payload_queue_last` | 0x320060 | 0x320060 | 0x320060 | - | - |
| `lb_bau_intd_payload_queue_tail` | 0x320070 | 0x320070 | 0x320070 | - | - |
| `lb_bau_intd_software_acknowledge` | 0x320080 | 0x320080 | 0x320080 | - | - |
| `lb_bau_intd_software_acknowledge_alias` | 0x320088 | 0x320088 | 0x320088 | - | - |
| `lb_target_physical_apic_id_mask` | 0x320130 | - | - | - | - |
| `gr0_tlb_mmr_control` | 0x401080 | 0xc01080 | 0xc01080 | 0x601080 | - |
| `gr0_tlb_mmr_read_data_hi` | 0x4010a0 | 0xc010a0 | 0xc010a0 | 0x6010a0 | - |
| `gr0_tlb_mmr_read_data_lo` | 0x4010a8 | 0xc010a8 | 0xc010a8 | 0x6010a8 | - |
| `rh10_gam_addr_map_config` | - | - | - | - | 0x470000 |
| `rh10_gam_mmr_overlay_config` | - | - | - | - | 0x470090 |
| `rh10_gam_gru_overlay_config` | - | - | - | - | 0x4700b0 |
| `rh10_gam_mmioh_overlay_config0` | - | - | - | - | 0x473000 |
| `rh10_gam_mmioh_redirect_config0` | - | - | - | - | 0x473800 |
| `rh10_gam_mmioh_overlay_config1` | - | - | - | - | 0x474000 |
| `rh10_gam_mmioh_redirect_config1` | - | - | - | - | 0x474800 |
| `rh_gam_addr_map_config` | 0x1600000 | 0x1600000 | 0x1600000 | 0x480000 | - |
| `rh_gam_gru_overlay_config` | 0x1600010 | 0x1600010 | 0x1600010 | 0x480010 | - |
| `rh_gam_mmr_overlay_config` | 0x1600028 | 0x1600028 | 0x1600028 | 0x480028 | - |
| `rh_gam_alias_0_overlay_config` | 0x16000c8 | 0x16000c8 | 0x16000c8 | 0x4800c8 | - |
| `rh_gam_alias_0_redirect_config` | 0x16000d0 | 0x16000d0 | 0x16000d0 | 0x4800d0 | - |
| `rh_gam_alias_1_overlay_config` | 0x16000d8 | 0x16000d8 | 0x16000d8 | 0x4800d8 | - |
| `rh_gam_alias_1_redirect_config` | 0x16000e0 | 0x16000e0 | 0x16000e0 | 0x4800e0 | - |
| `rh_gam_alias_2_overlay_config` | 0x16000e8 | 0x16000e8 | 0x16000e8 | 0x4800e8 | - |
| `rh_gam_alias_2_redirect_config` | 0x16000f0 | 0x16000f0 | 0x16000f0 | 0x4800f0 | - |
| `rh_gam_mmioh_overlay_config0` | - | - | 0x1603000 | 0x483000 | - |
| `rh_gam_mmioh_redirect_config0` | - | - | 0x1603800 | 0x483800 | - |
| `rh_gam_mmioh_overlay_config1` | - | - | 0x1604000 | 0x484000 | - |
| `rh_gam_mmioh_redirect_config1` | - | - | 0x1604800 | 0x484800 | - |
| `gr0_gam_gr_config` | - | - | - | 0x600028 | 0x600028 |
| `gr1_tlb_mmr_control` | 0x801080 | 0x1001080 | 0x1001080 | 0x701080 | - |
| `gr1_tlb_mmr_read_data_hi` | 0x8010a0 | 0x10010a0 | 0x10010a0 | 0x7010a0 | - |
| `gr1_tlb_mmr_read_data_lo` | 0x8010a8 | 0x10010a8 | 0x10010a8 | 0x7010a8 | - |
| `gr0_gam_gr_config` | - | - | 0xc00028 | - | - |
| `rh_gam_mmioh_overlay_config` | 0x1600030 | 0x1600030 | - | - | - |

Addresses also carry 32-bit aliases in the header for the MMR32 window on UV1 to UV3 (for example the BAU descriptor
base at 0x9a0 on UV1 to UV3 and 0x9c0 on UV4, and the activation control at 0x9a8); the register maps carry the 64-bit
offsets only. The UV5 node-present register pair replaces the 16-entry (UV1 to UV3) and 4-entry (UV4) node present
table at 0x1400.

## UV4A

UV4A is the later revision of the UV4 part number. The header differs from UV4 only in these items (established):
the node id position of the BAU descriptor base (bits 63:53 instead of 62:49) and its page address width (bits 51:12
instead of 45:12); the MMIOH overlay fields (base in bits 51:26 and m_io in 57:52 instead of 45:26 and 51:46); the
MMIOH redirect entry node mask (the header gives UV4A a 12-bit mask); and the GRU GAM configuration register, which UV4A does not define.
Everything else in the UV4 map applies unchanged.
