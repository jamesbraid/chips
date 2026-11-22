#!/usr/bin/env python3
"""Write the Origin 3900 router cabling for N Cx-bricks as JSON: the bricks, and the cables between them.

    tools/origin3900-cabling/plan.py N          N = 4, 6, 8, ..., 32; JSON
    tools/origin3900-cabling/plan.py N --table  one line per cable instead of JSON

JSON keys: "cx_bricks" (index, partner = the Cx-brick its A and F ports join, rack, unit), "r_bricks" (id, plane
0/1 and level 2/3 above 16 Cx-bricks and null below, role 14 = 0xe MetaRouter, rack, unit) and "links" (brick, port,
connector, peer, peer_port, peer_connector; bricks are "cxI" and "rbrickJ", connector letters A to H are ports 1 to 8).
"model_choice" names what the manuals do not give.

The brick-level graph is the one drawn in Partitioning for Systems that Contain Cx-bricks (007-4426-001):
4 Cx-bricks join each other on ports 7 and 8; 6 and 8 Cx-bricks cable each Cx-brick to both R-bricks; 10 to 16
put the even-numbered Cx-bricks on one R-brick pair and the odd-numbered on the other; above 16 every group of
four Cx-bricks takes one level-2 R-brick in each of two planes, and each plane's level-2 R-brick joins all four
of its level-3 R-bricks.  Port numbers on the R-bricks are not printed anywhere; the ones written here are a
model choice the IP35 PROM 6.210 accepts (platforms/bricks/origin3900-cabling.md).  Rack and unit numbers
follow 007-4426-001 Figure 1-2 for the Cx-bricks and for the 12 + 12 router racks above 16 Cx-bricks;
which unit holds which R-brick is a model choice.
"""
import json
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
    """(rack, unit) for each Cx-brick and R-brick; rack is None for the one-rack systems."""
    cx, rb = {}, {}
    if n <= 8:
        units = [1, 2, 3, 4, 9, 10, 11, 12]
        for i in range(n):
            cx[i] = (None, units[i])
        for j in range(nr):
            rb[j] = (None, 30 + j)
        return cx, rb
    for i in range(n):                       # Figure 1-2: partitions of eight striped over racks 001 to 004
        part, k = divmod(i, 8)
        rack = "%03d" % (1 + k // 2)
        cx[i] = (rack, 7 + 8 * part + 4 * (k % 2))
    for idx, j in enumerate(rbrick_ids(n, nr)):
        if n <= 16:                          # in a compute rack, above the Cx-bricks (model choice)
            rack, unit = "002", 30 + 2 * idx
        else:
            plane = 1 if (8 <= j < 16 or j >= 20) else 0
            level3 = j >= 16
            pos = (j - 16 - 4 * plane) + 8 if level3 else (j - 8 * plane)
            rack, unit = ("101", "102")[plane], ROUTER_UNITS[pos]
        rb[j] = (rack, unit)
    return cx, rb


def plan(n):
    nr, cables = topology(n)
    cxp, rbp = place(n, nr)
    cx = [{"index": i, "partner": i ^ 1, "rack": cxp[i][0], "unit": cxp[i][1]} for i in range(n)]
    rb = []
    for j in rbrick_ids(n, nr):
        plane = 1 if (8 <= j < 16 or j >= 20) else 0
        rb.append({"id": j, "plane": plane if n > 16 else None, "level": (3 if j >= 16 else 2) if n > 16 else None,
                   "role": 14, "rack": rbp[j][0], "unit": rbp[j][1]})
    letter = lambda p: chr(64 + p)
    links = [{"brick": a, "port": pa, "connector": letter(pa), "peer": b, "peer_port": pb, "peer_connector": letter(pb)}
             for a, pa, b, pb in cables]
    model = ("R-brick port numbers, the units of R-bricks and the A-to-A, F-to-F pairing of Cx-bricks are not "
             "given by the manuals; the PROM accepts them")
    rows = lambda items: "[\n" + ",\n".join("  " + json.dumps(x) for x in items) + "\n ]"
    return ('{\n "cx_bricks": %s,\n "r_bricks": %s,\n "links": %s,\n "model_choice": %s\n}\n'
            % (rows(cx), rows(rb), rows(links), json.dumps(model)))


def table(n):
    _, cables = topology(n)
    return "".join(f"{a} port {pa} -- {b} port {pb}\n" for a, pa, b, pb in cables)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    n = int(sys.argv[1])
    sys.stdout.write(table(n) if "--table" in sys.argv[2:] else plan(n))
