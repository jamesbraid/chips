#!/usr/bin/env python3
"""Write the Origin 3900 router cabling for N Cx-bricks as a topology plan
(routers, cbricks, links and blocks, the layout an emulator machine description is generated from).

    tools/origin3900-cabling/plan.py N          N = 4, 6, 8, ..., 32
    tools/origin3900-cabling/plan.py N --table  one line per cable instead of the plan

The brick-level graph is the one drawn in Partitioning for Systems that Contain Cx-bricks (007-4426-001):
4 Cx-bricks join each other on ports 7 and 8; 6 and 8 Cx-bricks cable each Cx-brick to both R-bricks; 10 to 16
put the even-numbered Cx-bricks on one R-brick pair and the odd-numbered on the other; above 16 every group of
four Cx-bricks takes one level-2 R-brick in each of two planes, and each plane's level-2 R-bricks join all four
of its level-3 R-bricks.  Port numbers on the R-bricks are not printed anywhere; the ones written here are a
model choice the IP35 PROM 6.210 accepts (platforms/bricks/origin3900-cabling.md).  Rack and unit numbers
follow 007-4426-001 Figure 1-2 for the Cx-bricks and for the 12 + 12 router racks above 16 Cx-bricks;
which unit holds which R-brick is a model choice.
"""
import sys

DOWN = [1, 2, 3, 4]          # level-2 R-brick ports that take Cx-bricks, in Cx order (model choice)
UP = [5, 6, 7, 8]            # level-2 ports to the plane's level-3 R-bricks 0 to 3 (model choice)
ROUTER_UNITS = [8, 10, 16, 18, 24, 26, 28, 30, 32, 34, 36, 38]   # 007-4426-001 Figure 1-2, racks 101 and 102


def topology(n):
    """Cx-bricks, R-bricks and cables.  A cable is (a, a_port, b, b_port) with router ids cxI and rbrickJ."""
    if n % 2 or not 4 <= n <= 32:
        sys.exit("plan.py: the Origin 3900 takes 4, 6, 8, ... 32 Cx-bricks here")
    cables = []
    for i in range(0, n, 2):
        for p in (1, 6):                     # A to A and F to F: the PROM rejects A to F above 128 processors
            cables.append((f"cx{i}", p, f"cx{i + 1}", p))
    if n == 4:
        cables += [("cx0", 7, "cx2", 7), ("cx1", 7, "cx3", 7), ("cx0", 8, "cx3", 8), ("cx1", 8, "cx2", 8)]
        return 0, cables
    if n <= 8:
        for i in range(n):
            cables += [(f"cx{i}", 7, "rbrick0", i + 1), (f"cx{i}", 8, "rbrick1", i + 1)]
        return 2, cables
    if n <= 16:
        # Figure 2-23: Cx 2, 4, ... (zero-based odd) on R-bricks 0 and 1, Cx 1, 3, ... on 2 and 3
        for i in range(n):
            a, b = (0, 1) if i % 2 else (2, 3)
            cables += [(f"cx{i}", 7, f"rbrick{a}", i // 2 + 1), (f"cx{i}", 8, f"rbrick{b}", i // 2 + 1)]
        return 4, cables
    # Figure 2-37: level-2 R-brick j of plane A is rbrick j, of plane B rbrick 8 + j (j < columns);
    # level-3 R-bricks 0 to 3 of plane A are rbrick 16 to 19, of plane B rbrick 20 to 23.
    cols = (n + 3) // 4
    for i in range(n):
        j, s = divmod(i, 4)
        cables += [(f"cx{i}", 7, f"rbrick{j}", DOWN[s]), (f"cx{i}", 8, f"rbrick{8 + j}", DOWN[s])]
    for plane in (0, 1):
        for j in range(cols):
            for t in range(4):
                cables.append((f"rbrick{8 * plane + j}", UP[t], f"rbrick{16 + 4 * plane + t}", j + 1))
    return 24, cables


def rbrick_ids(n, nr):
    if n <= 16:
        return list(range(nr))
    cols = (n + 3) // 4
    return list(range(cols)) + list(range(8, 8 + cols)) + list(range(16, 24))


def place(n, nr):
    """(parent, rack, unit) for each Cx-brick and R-brick; rack is None for the one-rack systems."""
    cx, rb = {}, {}
    if n <= 8:
        units = [1, 2, 3, 4, 9, 10, 11, 12]
        for i in range(n):
            cx[i] = ("rack", None, units[i])
        for j in range(nr):
            rb[j] = ("rack", None, 30 + j)
        return cx, rb
    for i in range(n):                       # Figure 1-2: partitions of eight striped over racks 001 to 004
        part, k = divmod(i, 8)
        rack = "%03d" % (1 + k // 2)
        cx[i] = ("rack-" + rack, rack, 7 + 8 * part + 4 * (k % 2))
    for idx, j in enumerate(rbrick_ids(n, nr)):
        if n <= 16:                          # in a compute rack, above the Cx-bricks (model choice)
            rack, unit = "002", 30 + 2 * idx
        else:
            plane = 1 if (8 <= j < 16 or j >= 20) else 0
            level3 = j >= 16
            pos = (j - 16 - 4 * plane) + 8 if level3 else (j - 8 * plane)
            rack, unit = ("101", "102")[plane], ROUTER_UNITS[pos]
        rb[j] = ("rack-" + rack, rack, unit)
    return cx, rb


def flow(d):
    parts = []
    for k, v in d.items():
        if isinstance(v, list):
            v = "[" + ", ".join(str(x) for x in v) + "]"
        elif k == "rack":
            v = f'"{v}"'
        parts.append(f"{k}: {v}")
    return "{" + ", ".join(parts) + "}"


def link_id(a, pa, b, pb):
    if a.startswith("cx") and b.startswith("cx"):
        return f"cx-link-{a[2:]}-{b[2:]}-{pa}", {"port": pa}
    if a.startswith("cx"):
        return f"cx-link-{a[2:]}-r{b[6:]}-{pa}", {"a_port": pa, "b_port": pb}
    return f"router-link-{a[6:]}-{b[6:]}-{pa}-{pb}", {"a_port": pa, "b_port": pb}


def plan(n):
    nr, cables = topology(n)
    cxp, rbp = place(n, nr)
    used = {}
    for a, pa, b, pb in cables:
        used.setdefault(a, []).append(pa)
        used.setdefault(b, []).append(pb)
    out = ["# SPDX-License-Identifier: BSD-3-Clause",
           f"# Plan for the repeated per-brick text of origin3900-{n}cx.yaml and its layer.",
           "routers:"]
    for i in range(n):
        parent, rack, unit = cxp[i]
        d = {"id": f"cx{i}", "kind": "cx", "label": f"Cx-brick {i}", "parent": parent}
        if rack:
            d["rack"] = rack
        d["unit"] = unit
        out.append("  - " + flow(d))
    for j in rbrick_ids(n, nr):
        parent, rack, unit = rbp[j]
        d = {"id": f"rbrick{j}", "label": f"R-brick {j}", "parent": parent}
        if rack:
            d["rack"] = rack
        d.update(unit=unit, role=14, omit_buses=[f"port-{p}-cable" for p in sorted(used[f"rbrick{j}"])])
        out.append("  - " + flow(d))
    out += ["cbricks: []", "links:"]
    for a, pa, b, pb in cables:
        lid, ports = link_id(a, pa, b, pb)
        out.append("  - " + flow({"id": lid, "a": a, "b": b, **ports}))
    out += blocks(n, nr, used)
    return "\n".join(out) + "\n"


def blocks(n, nr, used):
    q = lambda s: '"' + s + '"'
    srcs = ["007-4572-001 printed pages 4, 11 and 14: ports A and F both join one other Cx-brick",
            "007-4653-001 printed page 100: the R-brick's rear ports are lettered A to H against 1 to 8",
            "007-4653-001 printed pages 46 and 60: R-brick counts, and with four Cx-bricks all four ports go to Cx-bricks"]
    if n >= 6:
        srcs.append("007-4426-001 Figures 2-11 to 2-37: which R-brick each Cx-brick cable reaches")
    srcs.append("firmware:ip35-prom-6.210 router discovery: the stock PROM accepts this graph (software expectation)")
    b = ["blocks:", "  model-link-ports:", "    kind: link-ports",
         '    reason: "{own} port {port} cabled to {other} port {other_port}; the brick pairs are drawn in the '
         'partitioning guide, the R-brick port numbers are a model choice."',
         "    sources: [" + ", ".join(q(s) for s in srcs) + "]"]
    ids = [f"rbrick{j}" for j in rbrick_ids(n, nr)]
    empty = {}
    for r in ids:
        free = tuple(p for p in range(1, 9) if p not in used[r])
        if free:
            empty.setdefault(free, []).append(r)
    if empty:
        b += ["  model-empty-ports:", "    kind: empty-ports", "    order: port",
              "    routers: [" + ", ".join(ids) + "]", "    groups:"]
        for free, routers in empty.items():
            g = ["      - ports: [" + ", ".join(map(str, free)) + "]"]
            if routers != ids:
                g.append("        routers: [" + ", ".join(routers) + "]")
            g += ["        reason: No Cx-brick or R-brick cable is drawn on these ports.",
                  '        sources: ["007-4426-001 Figures 2-21 and 2-37: no further R-brick cable is drawn", '
                  '"007-4653-001 printed page 46, Table 2-1: R-brick counts"]']
            b += g
    b += ["  model-cx-xio-empty:", "    kind: cx-xio-empty", "    keep: [cx0-xio-0-connector]",
          "    reason: This composition fits one I/O brick, on node board 0 of the first Cx-brick.",
          '    sources: ["007-4572-001 printed pages 2 and 14: a Cx-brick attaches up to four I/O bricks"]',
          "  model-cx-instances:", "    kind: instances", "    model: layers/modules/cx-brick.yaml",
          "    prefixes: [" + ", ".join(f"cx{i}" for i in range(1, n)) + "]", "    parent: rack",
          "    comment: The Cx-brick router-to-router cables are product buses.",
          "    omit_buses: [numalink-a-link, numalink-f-link, numalink-g-link, numalink-h-link]",
          "    alias: cx-basis"]
    if nr:
        b += ["  model-router-instances:", "    kind: instances", "    model: layers/modules/r-brick.yaml",
              "    prefixes: [" + ", ".join(ids) + "]", "    parent: rack",
              "    comment: The router-to-router cables are product buses."]
    b += ["  layer-bedrock-aliases:", "    kind: aliases", "    of: cx-nodes", "    suffix: -bedrock",
          "    anchor: cx-bedrock", "    cx_from: 1",
          "  layer-l1-aliases:", "    kind: aliases", "    of: cx", "    suffix: -l1", "    anchor: cx-l1", "    cx_from: 1",
          "  layer-cx-numbers:", "    kind: chassis-numbers", "    of: routers", "    only: cx", "    suffix: -chassis",
          '    reason: "Model choice: module number {unit}. Only distinctness is needed, and a Cx-brick router also '
          'takes the number four above its own."']
    if nr:
        b += ["  layer-router-numbers:", "    kind: chassis-numbers", "    of: routers", "    only: r", "    suffix: -brick",
              '    reason: "Model choice: module number {unit}; only distinctness is needed."',
              "  layer-router-roles:", "    kind: router-roles", "    reasons:",
              '      14: "{r} is a metarouter (the Origin 3900 guide\'s name for every R-brick), and the stock PROM '
              'accepts a Cx-brick graph only with the MetaRouter flag on every R-brick, level 3 included. Inferred."']
    b += ["  layer-node-identities:", "    kind: identities", "    of: cx-nodes", "    suffix: -bedrock",
          "    serial_base: 0x51454d554e00",
          "    reason: Synthetic node identity N{i}; not hardware evidence.",
          "  layer-cx-router-identities:", "    kind: identities", "    of: routers", "    only: cx", "    suffix: -router",
          "    serial_base: 0x51454d555200",
          "    reason: Synthetic router descriptor identity; no physical barcode is claimed."]
    if nr:
        b += ["  layer-r-router-identities:", "    kind: identities", "    of: routers", "    only: r", "    suffix: -router",
              "    serial_base: 0x51454d555240",
              "    reason: Synthetic router descriptor identity; no physical barcode is claimed."]
    b += ["  layer-link-buses:", "    kind: link-buses",
          "    sources: [007-4572-001-ports, 007-4653-001-rbrick-ports, 007-4653-001-sizes]",
          "    notes: The brick pairs are drawn in the partitioning guide; the R-brick port numbers are a model choice the stock PROM accepts.",
          "  layer-link-connections:", "    kind: link-connections",
          "    sources: [007-4572-001-ports, 007-4653-001-rbrick-ports, 007-4653-001-sizes]"]
    return b


def table(n):
    _, cables = topology(n)
    return "".join(f"{a} port {pa} -- {b} port {pb}\n" for a, pa, b, pb in cables)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    n = int(sys.argv[1])
    sys.stdout.write(table(n) if "--table" in sys.argv[2:] else plan(n))
