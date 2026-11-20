# /// script
# requires-python = ">=3.11"
# dependencies = ["unicorn>=2.1"]
# ///
"""PROM 6.210 acceptance of candidate Origin 3900 router graphs (a software expectation about the graph, not evidence of shipped cabling).

    IP35_PAYLOAD=ip35prom.payload.bin CABLING_TEXT=cabling.txt uv run cx3900_wiring.py small N [ROLE [swap]]
    IP35_PAYLOAD=ip35prom.payload.bin CABLING_TEXT=cabling.txt uv run cx3900_wiring.py sub K
    IP35_PAYLOAD=ip35prom.payload.bin CABLING_TEXT=cabling.txt uv run cx3900_wiring.py four [cross]

small: N Cx routers (each a rack-router stand-in: hubs on ports 2 to 5, partner pair on ports 1 and 6), two R-bricks, every Cx's port 7 to the
first and port 8 to the second, on R-brick port k = Cx index (swap: port 8 on k+1).  ROLE is the role flag of the R-bricks (default 1).
sub: the 16 Cx graph made from Table 2-23's four unit-38 routers (each Cx also uplinks on port 7 to the router its neighbour rack's same-unit
router uses, on a free port among 1, 2, 5 and 6), with the highest Cx removed down to K.
"""
import os, sys, collections
import route_diagnostics as D
import metarouter_replay as M
from metarouter_replay import *

def run(name, rows, roles):
    M.T[name] = {"procs": 0, "rows": rows}
    D.PAIR.clear()
    rp, t, ridx, h0, hubs, links, nums = M.trial(name, roles=roles, quiet=True)
    c = D.cycle(D.deps(rp, t, ridx, hubs, links))
    print("RESULT", name, "pair squares", len(D.PAIR), "mismatches", sum(1 for r in D.PAIR if r[4] != r[5]), "cycle", bool(c), flush=True)

def hubs_and_pairs(n):
    rows = []
    for i in range(1, n + 1):
        c = "%03d" % i
        for u, p in zip((10, 13, 16, 21), (2, 3, 4, 5)): rows.append((c, "C", str(u), "Link", "1", c, "R", "19", str(p)))
    for i in range(1, n + 1, 2):
        a, b = "%03d" % i, "%03d" % (i + 1)
        for p in (1, 6): rows.append((a, "R", "19", str(p), "1", b, "R", "19", str(p)))
    return rows

def small(n, role, swap):
    rows = hubs_and_pairs(n)
    for i in range(1, n + 1):
        k = (i - 1) % 8 + 1
        rows.append(("%03d" % i, "R", "19", "7", "3", "101", "R", "38", str(k)))
        rows.append(("%03d" % i, "R", "19", "8", "3", "102", "R", "38", str((k % 8 + 1) if swap else k)))
    run("cx%d_role%d%s" % (n, role, "_swap" if swap else ""), rows, {"101r38": role, "102r38": role})

def four(cross):
    """Four Cx and no R-brick (all four external ports go to Cx-bricks): pairs (1,2) and (3,4); ports 7 and 8 join 1-3 and 2-4
    (cross: 1-4 and 2-3 on port 8)."""
    rows = hubs_and_pairs(4)
    for p in (7, 8):
        a, b = ("001", "003") if p == 7 or not cross else ("001", "004")
        c, d = ("002", "004") if p == 7 or not cross else ("002", "003")
        rows.append((a, "R", "19", str(p), "1", b, "R", "19", str(p)))
        rows.append((c, "R", "19", str(p), "1", d, "R", "19", str(p)))
    run("four%s" % ("_cross" if cross else ""), rows, {})

def sub(keep):
    rows = M.T[23]["rows"]
    rr = [r for r in rows if r[1] == "R" and r[6] == "R"]
    hub = [r for r in rows if r[1] == "C"]
    up8, nb7, inrack = {}, {}, []
    for r in rr:
        if r[2] == "38" or r[7] == "38":
            if r[2] == "38": r = (r[5], "R", r[7], r[8], r[4], r[0], "R", r[2], r[3])
            up8[(r[0], r[2])] = (r[5], r[7], r[8]); continue
        if r[0] == r[5]: inrack.append(r); continue
        nb7[(r[0], r[2])] = (r[5], r[7]); nb7[(r[5], r[7])] = (r[0], r[2])
    used = collections.defaultdict(set)
    for v in up8.values(): used[(v[0], v[1])].add(int(v[2]))
    out = list(hub) + list(inrack)
    for k, v in up8.items(): out.append((k[0], "R", k[1], "8", "3", v[0], "R", v[1], v[2]))
    for k in up8:
        tv = up8[nb7[k]]; tgt = (tv[0], tv[1])
        fp = [p for p in (1, 2, 5, 6) if p not in used[tgt]][0]; used[tgt].add(fp)
        out.append((k[0], "R", k[1], "7", "3", tgt[0], "R", tgt[1], str(fp)))
    order = [(rk, u) for rk in sorted({r[0] for r in hub}) for u in ("19", "27")]
    kept = set(order[:keep])
    out = [r for r in out if all(not (t == "R" and u != "38" and (a, u) not in kept) for a, t, u in ((r[0], r[1], r[2]), (r[5], r[6], r[7])))]
    roles = {"%sr38" % r[5]: 1 for r in out if r[7] == "38"}
    roles.update({"%sr38" % r[0]: 1 for r in out if r[2] == "38"})
    run("sub%d" % keep, out, roles)

if __name__ == "__main__":
    M.T.update(parse(os.environ["CABLING_TEXT"]))
    a = sys.argv[1:]
    if a[0] == "small": small(int(a[1]), int(a[2]) if len(a) > 2 else 1, "swap" in a[3:])
    elif a[0] == "sub": sub(int(a[1]))
    elif a[0] == "four": four("cross" in a[1:])
    else: sys.exit(__doc__)
