# SN1 IA-64: did any Bedrock Itanium node leave SGI?

Question. Did SGI sell, sample or lend a Bedrock-based Itanium system (the SN1 IA-64 node of
[platforms/sn1-ia64](../platforms/sn1-ia64/README.md)), and which Itanium stepping did the prototypes use?

Settled, and moved to the platform page ([Product or prototype](../platforms/sn1-ia64/README.md#product-or-prototype)):
prototype hardware with first-generation Itanium processors existed and ran Linux (SGI engineer's account, Linux Journal,
2003-02-01; 32 processors by early 2001), and the press of January 2003 says the SN1 Itanium 1 version never reached the market and
served software development (secondhand).

Still unknown:

- Whether any unit was sold, sampled or loaned outside SGI. The press sentence that says it "never made it to market" is
  secondhand (HPCwire, 2003-01-10, read as a search-result summary because the page refused a direct fetch), and another 2003
  piece says SGI "introduced" an Itanium 1 system "developed for the most part as a prototype" (Enterprise Systems, 2003-01-09).
- Which Itanium stepping and board revision the prototypes used. The simulator ran with `cpu_stepping A`; the ia64 tree dropped
  A1-step support in December 2000.

Routes tried: mailing list archives (linux-ia64, lkml and usenet comp.) for SN1, Synergy, Medusa, fakeprom and "Itanium
Origin" over 2000 to 2005; TechPubs (the text index has no hit for "Merced"; the filename-only search for "Itanium" returns manual numbers without text, so it
proves nothing; the Origin 3000 technical configuration guide `007-4311-002`, which a web search summary says has a Merced glossary entry, is not at the
probed TechPubs path); the public web (Computerworld, Slashdot, ESJ, Tech Monitor,
Linux Journal, HPCwire 2000, 2003, 2009).

Next route: an SGI product announcement or price list for an Itanium Origin or Onyx dated 2001 or 2002, a field-service document,
the 2001 SGI trade-show material, or a mailing-list report of a boot on SN1 hardware by someone outside SGI. The Origin 3000 guides of 2000 to 2001
(`007-4311-002` if it can be added to our holdings) should be opened for any Itanium mention before this is called closed.
