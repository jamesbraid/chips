# SN1 IA-64: did the Bedrock Itanium node ship?

Question. Did SGI sell a Bedrock-based Itanium system (the SN1 IA-64 node of [platforms/sn1-ia64](../platforms/sn1-ia64/README.md)),
and which Itanium stepping did it use?

Evidence held: the Linux port is real vendor code; its only firmware is a fake PROM for the Medusa simulator; the Kconfig help
for the choice called it "the SGI SN1 simulator" until the 2003 removal; mail of December 2000 mentions SN1 updates in the
ia64 patch; the later SN2 port replaced it by 2003 and its Kconfig help says "SGI Altix systems". Nothing held says SN1
hardware was sold or names a stepping.

Next route: an SGI product announcement or price list for an Itanium Origin or Onyx, a field-service document, or a
mailing-list message that reports a boot on SN1 hardware. None is held. A search of the Usenet and linux-ia64 mail for a
person reporting a real SN1 boot is the first step.
