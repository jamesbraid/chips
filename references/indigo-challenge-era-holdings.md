# Indigo, Challenge and Onyx era holdings

What we hold for the Indigo, Crimson, Challenge and Onyx machines of the early and mid 1990s: PROM images, SGI manuals
and field documents, board photographs, public driver and header sources, and what is still missing. Machines are
grouped by processor board: IP12 (Indigo R3000, 4D/30, 4D/35), IP20 (Indigo R4000), IP17 (Crimson), IP19 (Challenge and
Onyx R4400), IP21 (POWER Challenge and Onyx R8000) and IP25 (Challenge and Onyx R10000). Shared boards and graphics
follow.

## Conventions

- Library ids name a path in the Library: `techpubs:` is the SGI technical publications mirror, `origami-docs:` is the
  document cache, and `linux:`, `netbsd-src:` and `openbsd-src:` are public source trees.
- "Resolved" means the Library returned the exact path. "Cache manifest" means the document is marked held in the
  cache manifest, with a hash, and was not resolved again for this page.
- Images are not in the Library. The PROM rows point to local copies and give only the sha256 and size.
- Titles are the published titles. Nothing in a row says what the document contains beyond its title, unless noted.
- Restricted IRIX source hits came back from several searches. They were not opened and are not listed.

## IP12: Indigo R3000, 4D/30 and 4D/35

| Item | Kind | Library id or path | sha256 | Notes |
|---|---|---|---|---|
| Indigo PROM, 070-8088-xxx | PROM image | local copy only | `00b9565112db09e5d5d8a9592152bdf5bd9207dcc1986dc807e0d3b802754c01` | 262144 bytes; version not recorded ([prom-images](prom-images.md)) |
| 4D/35 PROM, 070-8086-002 | PROM image | local copy only | `5fdc6b65cf60b2003b7df20cd85a6c90175fe10da68afa9fcaaf7b0a89ef6659` | 4.0.1 Rev C, 14 Feb 1992; 524288 bytes; no boot capture |
| IRIS Indigo Workstation Owner's Guide, 007-9065-050 | owner's guide | `techpubs:library/manuals/9000/007-9065-050/pdf/007-9065-050.pdf` | not recorded | Resolved. Covers the Indigo workstation; which CPU variants it covers was not checked |
| Indigo R3000 photographs | photos (21) | `origami-docs:library/cache/photos/majix-indigo-r3000/` | per file, in cache manifest | Exterior, interior, card cage and power supply |
| Indigo R3000 photographs | photos (15) | `origami-docs:library/cache/photos/bukosek-indigo/r3k/` | per file, in cache manifest | Front, rear, backplane and motherboard. Example: `indigo_r3k_motherboard.jpg`, sha `6949e5fe613ec807faa7cc9d17f50e429c3cd8248715168c11675f524ae16fec` |

## IP20: Indigo R4000

| Item | Kind | Library id or path | sha256 | Notes |
|---|---|---|---|---|
| Indigo PROM, 070-8116-004.BE | PROM image | local copy only | `e6e1f1ed90d5979ef5829f823c2a4ff65ea24c3273a2b065a8b71abeba97f82f` | 4.0.5D Rev A, 19 Aug 1992; 524288 bytes; no boot capture |
| IRIS Indigo Workstation Owner's Guide, 007-9065-050 | owner's guide | `techpubs:library/manuals/9000/007-9065-050/pdf/007-9065-050.pdf` | not recorded | Same row as IP12. Whether it covers the R4000 Indigo was not checked |
| MIPS R4000/R4400 User's Manual, 2nd edition | CPU manual | cache manifest: `origami-docs:library/cache/misc/nekofiles.irixnet.org_Documents_doc_R4400_User_Manual_R4400_Uman_book_Ed2.pdf` | `6e8fd55e9cb4f36dff8f6c9e2f6021972e28f040518e3da00888cd84349569c4` | Also held as the cache copy of the R4000 PDF with the same hash |
| MIPS R4000/R4400 User's Manual, 2nd edition (second copy) | CPU manual | cache manifest: `origami-docs:library/cache/misc/www.sgistuff.net_hardware_other_documents_R4000_um2.pdf` | `075775a6599c0a9f4fc7f4b085575e000f42680cb2dc0bd7d70f425f7ddf197e` | Same bytes as the university mirror of the R4400 book |
| MIPS R4000 Microprocessor User's Manual, 007-2489-001 | CPU manual | `techpubs:library/manuals/2000/007-2489-001/pdf/007-2489-001.pdf` | not recorded | Resolved |
| MIPS R4000 Preliminary User's Manual, 1992 | CPU manual | cache manifest, `origami-docs:library/cache/misc/www.bitsavers.org_pdf_mips_R4000_Preliminary_Users_Manual_1992.pdf` | `f054533e922a485f0cfb5d8aff63d1f170dffc0175de6bbe1b21d6fc75f1d35c` | Preliminary; read against the final manual with care |
| Indigo R4000 photographs | photos (12) | `origami-docs:library/cache/photos/bukosek-indigo/r4k/` | per file, in cache manifest | Front, rear, rear panel and motherboard |

## IP17: Crimson

| Item | Kind | Library id or path | sha256 | Notes |
|---|---|---|---|---|
| Crimson PROM, 070-081x-005 | PROM image | local copy only | `46217a1c9a73f3e5eaec7eb955945ba4f5634c329e50063a7a08ddfa77d4ba33` | 4.0.3 Rev, 30 Apr 1992; 524288 bytes; boot capture held ([prom-images](prom-images.md)) |
| IRIS Crimson Graphics Upgrade Installation Instructions, 108-7035-020 | field document | `origami-docs:library/cache/prom/108-7035-020.pdf` | cache manifest | Crimson graphics upgrade |
| IRIS POWER Series R4400-150 Upgrade Installation Instructions, 108-0105-001 | field document | `origami-docs:library/cache/prom/108-0105-001.pdf` | cache manifest | Inferred to be for a POWER Series board, which may be Crimson. The title does not name the board; not verified |
| Crimson photographs | photos (19) | `origami-docs:library/cache/photos/sgistuff-crimson/` | per file, in cache manifest | Exterior, interior and card cage, including the Elan card cage. Example: `crimson-1300-front.jpg`, sha `e12a707097d81cf3bf5b84c0210fe5d1ffc2f40c98a01ed23f8866507b559318` |
| Crimson parts reference page | web page | `origami-docs:library/cache/hardware/parts-reference/bbsolutions-sgi-crimson.html` | not applicable | Third-party parts list. Not read for this page |

## IP19: Challenge and Onyx R4400

| Item | Kind | Library id or path | sha256 | Notes |
|---|---|---|---|---|
| IP19 200/250 MHz Board Upgrade Installation Instructions, 108-0126-003 | field document | `origami-docs:library/cache/prom/108-0126-003.pdf` | cache manifest | IP19 board upgrade |
| CHALLENGE/Onyx L Deskside Installation Instructions, 108-7039-020 | field document | `origami-docs:library/cache/prom/108-7039-020.pdf` | cache manifest | Challenge L deskside |
| CHALLENGE/Onyx XL Rackmount Installation Instructions, 108-7042-020 | field document | `origami-docs:library/cache/prom/108-7042-020.pdf` | cache manifest | Challenge XL and Onyx rackmount |
| CHALLENGE/Onyx Site Preparation Guide, 108-7040-040 | field document | `origami-docs:library/cache/prom/108-7040-040.pdf` | cache manifest | Site requirements |
| CHALLENGE/Onyx Diagnostics Roadmap, 108-7045-030 | field document | `origami-docs:library/cache/prom/108-7045-030.pdf` | cache manifest | Which diagnostic applies to which machine |
| CHALLENGE and Onyx Rack and Deskside Illustrated Parts List, 108-0129-002 | parts list | `origami-docs:library/cache/prom/108-0129-002.pdf` | cache manifest | Shared with IP21 and IP25 |
| IRIS POWER Series R4400-150 Upgrade Installation Instructions, 108-0105-001 | field document | `origami-docs:library/cache/prom/108-0105-001.pdf` | cache manifest | Possibly a Challenge or Onyx 150 MHz R4400 upgrade. The title does not say; not verified. Also listed under IP17 |
| Deskside POWER CHALLENGE and CHALLENGE L Owner's Guide, 007-1732-050 | owner's guide | `techpubs:library/manuals/1000/007-1732-050/pdf/007-1732-050.pdf` | not recorded | Resolved. Covers the deskside Challenge L as well as POWER Challenge |
| Deskside POWER CHALLENGE and CHALLENGE L Owner's Guide, 007-1732-060 | owner's guide | `techpubs:library/manuals/1000/007-1732-060/pdf/007-1732-060.pdf` | not recorded | Resolved |
| POWER CHALLENGE and CHALLENGE XL Rackmount Owner's Guide, 007-1735-030 | owner's guide | `techpubs:library/manuals/1000/007-1735-030/pdf/007-1735-030.pdf` | not recorded | Resolved |
| POWER CHALLENGE and CHALLENGE XL Rackmount Owner's Guide, 007-1735-040 | owner's guide | `techpubs:library/manuals/1000/007-1735-040/pdf/007-1735-040.pdf` | not recorded | Resolved |
| POWER CHALLENGE and CHALLENGE XL Rackmount Owner's Guide, 007-1735-050 | owner's guide | `techpubs:library/manuals/1000/007-1735-050/pdf/007-1735-050.pdf` | not recorded | Resolved |
| POWER Onyx and Onyx Deskside Owner's Guide, 007-1733-070 | owner's guide | `origami-docs:library/cache/sgi-tech/007-1733-070-power-onyx-and-onyx-deskside-owner-s-guide.pdf` | `9b704f28c516c8867a2f48ea4f7ca1bb662343b34276000693d1fe8ac5032882` | Cache manifest; 1996 edition |
| POWER Onyx and Onyx Rackmount Owner's Guide, 007-1736-040 | owner's guide | `origami-docs:library/cache/sgi-tech/007-1736-040-power-onyx-and-onyx-rackmount-owner-s-guide.pdf` | `3a4f584e4d6147d3ef13a04216747886ed4d5eb04a35e60c939b0fa84c6d134f` | Cache manifest; 1994 edition |
| POWER Onyx and Onyx Rackmount Owner's Guide, 007-1736-060 | owner's guide | `techpubs:library/manuals/1000/007-1736-060/pdf/007-1736-060.pdf` | `258ac628824af1908bb3c30c78cdfbf4904c8a820917ca0782203c853b2d6f9f` (cache copy) | Resolved in the mirror. 1996 edition; includes the RealityEngine2 connector figure |
| MIPS R4000/R4400 User's Manual, 2nd edition, errata | errata | cache manifest: `origami-docs:library/cache/misc/nekofiles.irixnet.org_Documents_doc_R4400_R4400_buglist_r4400_2.0_3.0_MC_errata.ps` | `d8bceb12d962cfe1d83795c59f45fc942fe148dea2e26f60935746ed2893c99a` | Silicon errata for R4400 revisions 2.0 and 3.0 |
| R4400 user's manual JTAG addendum | CPU manual addendum | cache manifest: `origami-docs:library/cache/misc/nekofiles.irixnet.org_Documents_doc_R4400_User_Manual_JTAG_adden.ps.Z` | `411c7187f26dab645deefb639bdb8bcab8ad76defcc252a5ea2f6c65eb4e5fd7` | Boundary-scan addendum |
| Onyx wiki page, Challenge and Onyx | wiki page | cache manifest: `origami-docs:library/cache/misc/tech-pubs.net_wiki_index.php_Onyx` | not applicable | Original Onyx, not Onyx2. Not read for this page |

## IP21: POWER Challenge and Onyx R8000

| Item | Kind | Library id or path | sha256 | Notes |
|---|---|---|---|---|
| IP21 Board Upgrade Installation Instructions, 108-0122-003 | field document | `origami-docs:library/cache/prom/108-0122-003.pdf` | cache manifest | IP21 board upgrade |
| 64 MB SIMM Upgrade for R8000 Indigo2 and POWER CHALLENGE M, 108-0139-001 | field document | `origami-docs:library/cache/prom/108-0139-001.pdf` | cache manifest | Memory for POWER Challenge M; also covers an Indigo2 |
| POWER Indigo2 and POWER CHALLENGE M Upgrade Instructions, 108-0130-001 | field document | `origami-docs:library/cache/prom/108-0130-001.pdf` | cache manifest | POWER Challenge M upgrade; also covers an Indigo2 |
| Deskside POWER CHALLENGE and CHALLENGE L Owner's Guide, 007-1732-050 and -060 | owner's guide | `techpubs:library/manuals/1000/007-1732-050/pdf/007-1732-050.pdf` | not recorded | Also in the IP19 table. Resolved |
| POWER CHALLENGE and CHALLENGE XL Rackmount Owner's Guide, 007-1735-030, -040, -050 | owner's guide | `techpubs:library/manuals/1000/007-1735-030/pdf/007-1735-030.pdf` (and -040, -050) | not recorded | Also in the IP19 table. All three resolved |
| POWER Onyx Owner's Guides, 007-1733-070 and 007-1736-040 and -060 | owner's guide | see IP19 table | see IP19 table | Shared with IP19 and IP25 |
| MIPS R8000 user's manual | CPU manual | cache manifest: `origami-docs:library/cache/misc/www.sgistuff.net_hardware_other_documents_r8000-um.pdf` | `c2396abc5865bc7d6b9984f268b1859f4098a3006bfa7aa429a7ee9230198e46` | Chip manual |
| R8000 announcement text | announcement | cache manifest: `origami-docs:library/cache/misc/www.sgistuff.net_hardware_other_documents_r8000-announce.txt` | `a552c1ec1e2cdcf172000760001aefd616dc226d2cf019f716c4337075faae69` | POWER Challenge announcement |
| R8000 (TFP) microprocessor paper | paper | cache manifest: `origami-docs:library/cache/misc/nekofiles.irixnet.org_Documents_doc_R8000_R8000_Micro_Paper.ps` | not recorded | Chip paper |
| TFP R8000 Product Overview | overview | cache manifest: `origami-docs:library/cache/misc/nekofiles.irixnet.org_Documents_doc_TFP_R8000_Prod_Overview.ps` | not recorded | Chip overview |
| IP21 board specimen photographs, six images | photos | `origami-docs:library/cache/hardware/parts-reference/collected/75349736ab01d2214218537f.html` | `d1c65ee1b6cf54a292c61919b9ba4d05d7a2fe512f7c8fc4b6cbe37447af124a` | Page with photographs of an IP21 board; three downloaded and viewed |

## IP25: Challenge and Onyx R10000

| Item | Kind | Library id or path | sha256 | Notes |
|---|---|---|---|---|
| IP25 Upgrade Installation Instructions, 108-0142-001 | field document | `origami-docs:library/cache/prom/108-0142-001.pdf` | `d6b852b6ecce12ea34a2c153f1c54814594d5f126198911fd739a84d1c989347` | IP25 board upgrade |
| MIPS R10000 Microprocessor User's Manual, 007-2490-001 | CPU manual | `techpubs:library/manuals/2000/007-2490-001/pdf/007-2490-001.pdf` | not recorded | Resolved |
| MIPS R10000 user's manual, version 2.0 | CPU manual | cache manifest: `origami-docs:library/cache/mips/r10000-users-manual-v2.0.pdf` | `6023b060b52e136cc3bda8a4ed348b3eb9a99d7947f2390eedf775d431213006` | Primary reference for the R10000 CPU model |
| R10000 technical brief | overview | cache manifest: `origami-docs:library/cache/mips/r10000-technical-brief.pdf` | `41c0f6e4243f123419f8ae7b0ee28a6ca79cf1c347df969367a38776e1db72f5` | Product overview |
| R10000 I/O timing application note | application note | cache manifest: `origami-docs:library/cache/mips/r10000-io-timing-appnote.ps` | `10a987a0f53c224dd32bf06aef6032aae971bdbe9ae9ec7a2670994c0c818734` | Timing of the system interface |
| SGI HSTL signalling specification | specification | cache manifest: `origami-docs:library/cache/misc/nekofiles.irixnet.org_Documents_doc_R10000_HSTL_SGI_HSTL_spec.ps` | `b0dc99baf79fd840d65ccf67d75c568593b4ec374411772305d81aba4ba1134a` | Signalling used by the R10000 system interface |
| R10000 silicon errata, revisions 2.3 to 2.5 | errata | cache manifest: `origami-docs:library/cache/mips/r10000-si-errata-2.3-2.5.ps` | `05d7fad7d440ebb5e6c99d312191456fcc5138030199760cf78d6ff06af66d1d` | Silicon errata |
| R10000 user's manual errata, versions 1.0 and 1.1 | errata | cache manifest: `origami-docs:library/cache/mips/r10000-um-v1.1-errata.ps` | `543eb61a3db131d27db94bd0b88f300add0bd3557a37cdcb3e4f72311ddb8e99` | Manual errata (1.0 errata also held) |

## Shared boards: MC, HPC1, Everest backplane, EBus, IO4 and options

| Item | Kind | Library id or path | sha256 | Notes |
|---|---|---|---|---|
| IO4 base-I/O PROM, io4prom.bin | PROM image | local copy only | `7019deaeacfe5476ffb5e80c50181bb4590c39793de2fc722994ccca83d5a4f1` | 1035936 bytes; base-I/O PROM for IP19, IP21 and IP25 (Library id `origami-docs:library/prom-inventory.md`). Version not recorded |
| GE10 geometry-engine firmware, GE10prom.u | firmware image | local copy only | `3d63f7050f468964b9f8bb12ac203036864802d059a8110d710475cc7d6257d7` | 207680 bytes. Graphics firmware; the board family it belongs to is unconfirmed |
| Six IO4 Boards Installation Instructions, 108-0147-001 | field document | `origami-docs:library/cache/sgi-docs/108-0147-001-six-io4-boards-install.pdf` | `f7a02e88e5fdd5fcc495679df63f1c4ff2f72fd03d5801a128cc893a1e94abf2` | IO4 board installation |
| Everest Core-Board Revision History, 108-0141-001 | revision history | `origami-docs:library/cache/sgi-docs/108-0141-001-everest-core-board-revision-history.pdf` | `67eca22f7fd0c3abe0e35b3f056f28a12539ac5ba92070a436ccc4aa54ea8ab2` | Only Everest document held. Board revision list, not a technical reference |
| Sirius Video Installation Instructions, 108-0109-004 | field document | `origami-docs:library/cache/prom/108-0109-004.pdf` | `94344ba45c463430d10f07563ae8ac935479f4b294ec8544da85b5b5e479482b` | VME video option; era not in title |
| VideoCreator Installation Instructions, VME version, 108-0108-001 | field document | `origami-docs:library/cache/prom/108-0108-001.pdf` | `a45ee2aed58bc8540bb6a20de928cff12e0e0f6cb1e41823501962e7d6160d2f` | VME video option; era not in title |
| VME/ISA Synchronous Communications Administrator's Guide, 007-2278-001 | administrator's guide | `techpubs:library/manuals/2000/007-2278-001/pdf/007-2278-001.pdf` | not recorded | In the techpubs catalogue; not resolved as a file in this pass |
| VME Sync Communications Board Installation Instructions, 108-0112-002 | field document | `origami-docs:library/cache/prom/108-0112-002.pdf` | `5a906bcf59a54f47082789f3112362c6689b1f0d023d3ac626d06bc9a3ccf87b` | VME board |
| 100Base-T VME Board Installation Instructions, 108-0148-001 | field document | `origami-docs:library/cache/prom/108-0148-001.pdf` | `bf09f7ce20b65abb34b270315105a5e9fe2bbee4ba4afaeda6d327264b16abf0` | VME board |
| HIPPI Installation Instructions, 108-0106-003 | field document | `origami-docs:library/cache/prom/108-0106-003.pdf` | `619d4c736f0d74ca4e7b0cab035079a121053b55f33eebaf16ca0b53bef93c1a` | Era not in title |
| VMEbus FDDIXPress Board Installation Instructions, 108-7030-040 | field document | `origami-docs:library/cache/prom/108-7030-040.pdf` | `bc4a75c0d1f7a8fdeba1d63c615370d99ff3b0a7bc5342354e0380d0ff73bd76` | VME network board |
| FDDIXPress Mezzanine Board for CHALLENGE and Onyx, 108-0116-002 | field document | `origami-docs:library/cache/prom/108-0116-002.pdf` | `0fcec7c448ffc01a0e17521ec28b0b4da6522772d26ff0b6201ca2dbd4db5952` | Challenge and Onyx mezzanine |
| IRIS ATM-OC3 Board for CHALLENGE and Onyx, 108-0113-003 | field document | `origami-docs:library/cache/prom/108-0113-003.pdf` | `5f320532c8f340eeddfc3440b0323639ed5002db6455d0f67e1e13349f68101f` | Challenge and Onyx network board |
| POWER Channel E-Plex Installation Instructions, 108-0114-001 | field document | `origami-docs:library/cache/prom/108-0114-001.pdf` | `c4882d82fd96fb35a278f79a091ad1f3de8e5c9f12df0a377a96e76e30156f17` | Board named in title only; not read |
| EFAST Network Controller Board Installation Instructions, 108-0101-001 | field document | `origami-docs:library/cache/prom/108-0101-001.pdf` | `751514b1e130bad468344a542ce93ac34ae83c018ea6fb685a8580eb7824a21b` | Era not in title |
| RAID Hardware Installation and Upgrade Instructions, 108-0104-002 | field document | `origami-docs:library/cache/prom/108-0104-002.pdf` | `b39201ed92ce8fb79ba79b3906e4202db0da0167398d557400ab8463d3ed66a9` | Era not in title |
| CHALLENGE RAID Installation and Maintenance Instructions, 108-0128-006 | field document | `origami-docs:library/cache/prom/108-0128-006.pdf` | `7885ab5ca058df2a43ab24546d3e0d3aeb41a538b6dd60aa1322dd12463fd240` | Challenge storage |
| CHALLENGE RAID Owner's Guide, 007-2532-004 | owner's guide | `origami-docs:library/cache/sgi-tech/007-2532-004-challenge-raid-owner-s-guide.pdf` | `be2104fda813a88a67f48302dda4c3716dbaff50de741b5798725372d2220a76` | Challenge storage. The -006 (`64ee8061dff1355672ffd87abbcacab3a4c0a4124ca1dfbb94f4eca95c97ea1d`) and -007 (`8bbcff9e5580eb4255bf1ed7e162210db816dbda5cc0c96dce4413a2644d22d8`) editions are also in the cache manifest |
| CHALLENGE Vault L Installation Instructions, 108-0124-001 | field document | `origami-docs:library/cache/prom/108-0124-001.pdf` | `76fd858793e742ea8e8f8f2461e7312d9488c5fd00223fbb937a81c5630b620b` | Challenge storage |
| Vault Rack and SCSIBox 2 Installation Instructions, 108-7044-040 | field document | `origami-docs:library/cache/prom/108-7044-040.pdf` | `7966f7270ea196b6b6db3dfcef43438ab1f9d35ab08253b1594f780e1bca40b6` | Challenge storage |
| CHALLENGE Vault L Owner's Guide, 007-2443-001 and -002 | owner's guide | `techpubs:library/manuals/2000/007-2443-001/pdf/007-2443-001.pdf` | not recorded | In the techpubs catalogue (-001 and -002); not resolved as files in this pass |
| CHALLENGE Vault Rack and SCSIBox 2 Owner's Guide, 007-1762-030 | owner's guide | `origami-docs:library/cache/sgi-tech/007-1762-030-challenge-vault-rack-and-scsibox-2-owner-s-guide.pdf` | `59e2065bc43982e5bfa4af06b655c5cc808852af0f5edcd8b6798456927b2e80` | Storage. The -040 edition is also in the cache manifest |
| CHALLENGEvault M Owner's Guide, 007-2155-001 | owner's guide | `origami-docs:library/cache/sgi-tech/007-2155-001-challengevault-m-owner-s-guide.pdf` | `5bbb267756803878d34cbb7e38c018f6ce7c64190999714742a6a2e68d906dc9` | Storage |
| Multi-Channel Option Installation Instructions, 108-7047-040 | field document | `origami-docs:library/cache/prom/108-7047-040.pdf` | `256cacf25c1e528353bb8795d98f91d462852d16ee73dd35d73b81c71ab12d57` | Option; era not in title |
| Array Installation Instructions, 108-0138-004 | field document | `origami-docs:library/cache/prom/108-0138-004.pdf` | `1c4ae7bb5fa9fb95e24f7593fdb25eee766c0f429955aba33d0eaa3b5af9a835` | Era not in title |
| Triple Keyboard Option Installation Instructions, 108-0125-001 | field document | `origami-docs:library/cache/prom/108-0125-001.pdf` | `ded1552e2fccac06160e68c0f7e4100d0711c1d0cf91a246356ee5b6cc1e4e7c` | Era not in title |
| Audio/Serial Option Board Installation Instructions, 108-0134-001 | field document | `origami-docs:library/cache/prom/108-0134-001.pdf` | `da242c311ebf310a051a1bcea004f00faf79b9f733bbc95de81dd7fc0d65d192` | Era not in title |
| Challenge and Onyx support forum thread, repair | forum thread | cache manifest: `origami-docs:library/cache/misc/forums.irixnet.org_thread-3220-post-23022.html` | not applicable | Field report on a Challenge and Onyx that would not finish booting. Not read for this page |

Public drivers and headers for these boards are in the next section. No public driver for Everest, EBus or IO4 was
found. Searches for those names returned only restricted hits, which were not opened.

## Graphics: Entry, XS/XZ/Elan, Extreme, VGX and RealityEngine

| Item | Kind | Library id or path | sha256 | Notes |
|---|---|---|---|---|
| Indigo XS24-Z graphics board assembly | photo | `origami-docs:library/cache/photos/bukosek-indigo/express/indigo_express_xs24z.jpg` | `a9928ae1be66ceba173c03517ac17fef3fec65a0ecdb7879270d870554c998ab` | XS family |
| Crimson Elan card cage | photo | `origami-docs:library/cache/photos/sgistuff-crimson/crimson-1301-cardcageelan.jpg` | `5d21f6c6bd33ff66bee6e0821c7a2edec4418086e24c030192fed861c7a3e13a` | Elan graphics in the card cage |
| Indigo Express GR2 graphics board, rear | photo | `origami-docs:library/cache/photos/bukosek-indigo/express/indigo_express_gr2_back.jpg` | `0e020a95cbfb77d4f07dfb62f5c03a13fef12cb101d5a545010c2ca853e4fc8b` | Express graphics. Not in the requested list; kept as an adjacent item |
| Indigo Express photographs | photos (11) | `origami-docs:library/cache/photos/bukosek-indigo/express/` | per file, in cache manifest | Express graphics set (GR2, GE7 jumpers, VB1, VM2, XS24-Z) |
| POWER CHALLENGE to Extreme Graphics, and Onyx Extreme to RealityEngine2 Upgrade Instructions, 108-0117-002 | field document | `origami-docs:library/cache/prom/108-0117-002.pdf` | `9edc877c49e49304f859dc9560e97ef3cd6be53f379ab598c8a5493b33d4573c` | Extreme graphics; also the Extreme to RealityEngine2 path |
| RealityEngine2 connector figure | figure | `techpubs:library/manuals/1000/007-1736-060/pdf/007-1736-060.pdf` | see IP19 table | Figure 2-6 of the Onyx rackmount owner's guide |
| Reality hub timing guide | web page | `origami-docs:library/cache/asic/reality-sgi-hub-timing-guide.html` | not applicable | Title only; not read |
| GE10 geometry-engine firmware | firmware image | local copy only | see the shared boards table | Family unconfirmed |
| InfiniteReality upgrade, Deskside and Rackmount Onyx, 108-0132-002 | field document | `origami-docs:library/cache/prom/108-0132-002.pdf` | `7f7da686e09fac443ef92c721562a69fd349faafea2f20f0c6125ab3d86b106d` | Adjacent: InfiniteReality is not in the requested list |

## Public Linux, NetBSD and OpenBSD sources

| Item | Kind | Library id or path | Notes |
|---|---|---|---|
| Linux `arch/mips/sgi-ip22` | driver directory | `linux:arch/mips/sgi-ip22` | IP22 class (Indy and Indigo2). Not Challenge-era |
| Linux `asm/sgi/mc.h`, 9479 bytes | header | `linux:arch/mips/include/asm/sgi/mc.h` | Memory controller header for the IP22 class. Whether it describes the memory controller of the Indigo or Crimson era is not verified |
| Linux `asm/sgi/hpc3.h`, 14470 bytes | header | `linux:arch/mips/include/asm/sgi/hpc3.h` | HPC3 for IP22. Not HPC1 |
| Linux `asm/sgi/ioc.h`, 6491 bytes | header | `linux:arch/mips/include/asm/sgi/ioc.h` | IOC for the IP22 class. Not in scope |
| NetBSD `sys/arch/sgimips/hpc` | driver directory | `netbsd-src:sys/arch/sgimips/hpc` | HPC bus driver (`hpc.c`). Which HPC generation it covers was not checked |
| NetBSD `sys/arch/sgimips/sgimips/arcemu.c`, 17933 bytes | PROM interface | `netbsd-src:sys/arch/sgimips/sgimips/arcemu.c` | PROM interface layer. Includes an IP12 memory-descriptor routine |
| OpenBSD `sys/arch/sgi/hpc` | driver directory | `openbsd-src:sys/arch/sgi/hpc` | Checked, not found in the Library |

## Existing chips pages

No chips page covers the Indigo R3000 or R4000, Crimson, Challenge, Onyx, Everest, MC, HPC1, IO4, EBus or the graphics
named above. [prom-images.md](prom-images.md) lists PROM images for IP12, IP17 and IP20 only. The nearest pages are the
Indy and Indigo2 PROM notes in `platforms/ip22/`, which are outside this scope. `devices/ioc4/` covers the IOC4 chip of
the IP35 class. It is not the Challenge IO4 board.

## Missing

### IP12 (Indigo R3000, 4D/30, 4D/35)

- Indigo R3000 hardware and service manual, with the 4D/30 and 4D/35 variants. Number not known.
- MIPS R3000 microprocessor user's manual. Number not known.
- PROM images for the 4D/30 and for any later Indigo R3000 revision. Only one Indigo PROM is held, and its version is not recorded.

### IP20 (Indigo R4000)

- Indigo R4000 hardware and service manual. The owner's guide 007-9065-050 is held but its CPU coverage is unchecked.
- Any PROM revision of the Indigo R4000 besides 4.0.5D.

### IP17 (Crimson)

- Crimson owner's guide and hardware manual. Number not known.
- Crimson graphics board manual beyond the upgrade instructions.
- PROM revisions after 4.0.3.

### IP19 (Challenge and Onyx R4400)

- Deskside POWER CHALLENGE and CHALLENGE L Owner's Guide, 007-1732-040 (1995 edition). Not in the mirror.
- POWER Onyx and Onyx Deskside Owner's Guide, 007-1733-050 (1995 edition). Not in the mirror.
- IP19 processor-board PROM image. Not held. The base-I/O PROM is held.
- Challenge and Onyx theory of operations manual. Not found in the Library.
- Challenge and Onyx R4400 boards: service and parts manual beyond the parts list. Not found.

### IP21 (POWER Challenge and Onyx R8000)

- IP21 processor-board PROM image. Not held. The base-I/O PROM is held.
- IP21 processor board hardware reference. The upgrade instructions are held, not a reference.
- R8000 chip user's manual variants, beyond the one held. Not checked.

### IP25 (Challenge and Onyx R10000)

- IP25 processor-board PROM image. Not held.
- IP25 processor board hardware reference. The upgrade instructions are held, not a reference.
- Onyx and Challenge owner's guides for the R10000 generation beyond the 1996 editions held. Not checked.

### Shared boards: MC, HPC1, Everest, EBus, IO4

- MC (memory controller) chip specification for the Indigo and Crimson generation. Not held. Number not known.
- HPC1 chip specification. Not held. Number not known.
- Everest backplane and system-bus technical reference, and the Challenge and Onyx theory of operations manual. Not held.
- MC3 memory board manual. Not held.
- IO4 board hardware manual. Only the installation sheet is held.
- Challenge IO4 PROM appendix, 007-1732-030 (`apd.html`). Listed as a candidate in the cache manifest and not in the mirror.
- Public driver for Everest, EBus or IO4. None found.

### Graphics

- Entry graphics hardware and programming references. None held.
- XS, XZ and Elan graphics owner's guide and hardware reference. Photographs are held; no written reference is.
- Extreme graphics board technical reference. Only the upgrade instructions are held.
- VGX and VGXT manuals. None held.
- RealityEngine (RE1) field and hardware guides, including the RM and DG boards and the GE geometry engines. Only the upgrade instructions and the connector figure are held.
- Public driver or microcode documentation for any of the graphics boards in this section. None found in this pass.

### Release notes

- IRIX release notes for Indigo, Challenge and Onyx. Not found in this pass. The catalogue holds release notes for other products only.

## How this page was checked

- The paths marked "resolved" were checked with the Library resolver. Other holdings were taken from the cache manifest and the
  techpubs catalogue, and their hashes were not recomputed.
- The restricted searches were not opened. Restricted hits are not listed.
- The `docs-index`, `check-links` and `leakcheck` tools are not on this host. The repo has no index of its references pages,
  so nothing was regenerated. Links and the leak check were run by hand.
