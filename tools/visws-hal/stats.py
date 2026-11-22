#!/usr/bin/env python3
"""Facts about one x86 PE HAL and its Ghidra export, as JSON on stdout.

    stats.py IMAGE.dll decompile.json

Reads the image with pefile: identity, version resource, export table (ordinal, name, RVA, and
code or data by the section the RVA lands in), import counts per module. Reads the export's
function list: total functions, and how many carry a name from each source (IMPORTED is a name
applied from a symbol file, ANALYSIS a name Ghidra derived, DEFAULT an unnamed FUN_ placeholder).
Run it in the toolchain image (re-run python3 -I tools/visws-hal/stats.py ...).
"""
import collections
import hashlib
import json
import sys

import pefile


def main(image, export):
    data = open(image, 'rb').read()
    pe = pefile.PE(data=data)
    sects = pe.sections
    code = 0x20000000

    def kind(rva):
        for s in sects:
            if s.VirtualAddress <= rva < s.VirtualAddress + max(s.Misc_VirtualSize, s.SizeOfRawData):
                return 'code' if s.Characteristics & code else 'data'
        return 'unknown'

    exports = []
    d = getattr(pe, 'DIRECTORY_ENTRY_EXPORT', None)
    if d:
        for e in d.symbols:
            exports.append({'ordinal': e.ordinal, 'name': e.name.decode() if e.name else None,
                            'rva': e.address, 'kind': kind(e.address),
                            'forwarder': e.forwarder.decode() if e.forwarder else None})
    imports = {}
    for m in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', []):
        imports[m.dll.decode()] = len(m.imports)
    ver = {}
    for fi in getattr(pe, 'FileInfo', []) or []:
        for e in fi:
            if getattr(e, 'Key', b'') == b'StringFileInfo':
                for t in e.StringTable:
                    ver = {k.decode(): v.decode(errors='replace') for k, v in t.entries.items()}
    j = json.load(open(export))
    fs = j['functions']
    out = {
        'sha256': hashlib.sha256(data).hexdigest(),
        'bytes': len(data),
        'timestamp': pe.FILE_HEADER.TimeDateStamp,
        'image_base': pe.OPTIONAL_HEADER.ImageBase,
        'sections': [(s.Name.rstrip(b'\0').decode(), s.VirtualAddress, s.Misc_VirtualSize) for s in sects],
        'version': {k: ver[k] for k in ('FileVersion', 'ProductVersion', 'OriginalFilename') if k in ver},
        'exports': exports,
        'import_counts': imports,
        'functions': len(fs),
        'decompiled': sum(1 for f in fs if f.get('complete')),
        'name_sources': dict(collections.Counter(f['name_source'] for f in fs)),
    }
    json.dump(out, sys.stdout, indent=1)
    print()


if __name__ == '__main__':
    main(*sys.argv[1:3])
