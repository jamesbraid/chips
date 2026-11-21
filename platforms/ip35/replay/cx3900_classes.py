# /// script
# requires-python = ">=3.11"
# dependencies = ["unicorn>=2.1", "numpy", "networkx"]
# ///
"""Enumerate Origin 3900 router graphs allowed by the guides' text and run PROM 6.210 over them.

    uv run cx3900_classes.py four N                    classes at 10 to 16 Cx-bricks (four R-bricks): counts and bisection, to four-N.json
    IP35_PAYLOAD=... uv run cx3900_classes.py prom4 N norr|rr|low [LIMIT]   PROM verdict per class from four-N.json
    IP35_PAYLOAD=... uv run cx3900_classes.py columns N                     PROM number walk per column class above 16 Cx-bricks
    IP35_PAYLOAD=... uv run cx3900_classes.py ports N SAMPLES [full] [free] random R-brick port permutations and G/H swaps
    IP35_PAYLOAD=... uv run cx3900_classes.py variants N                    extra level-2 to level-3 cables, level-3 roles

JOBS sets the worker count (default 8).  Prints one JSON line per graph.  A PROM verdict is a software expectation about
the graph, not evidence of shipped cabling (platforms/bricks/origin3900-cabling.md).
"""
import collections, itertools, json, multiprocessing as mp, os, random, sys

E = list(itertools.combinations(range(4), 2))          # the six R-brick pairs a Cx-brick's G and H can reach
PT = list(itertools.combinations_with_replacement(range(6), 2))


def rows_for(ncx, rlinks, rr=(), cross=()):
    """Replay rows. Cx-brick i is router (i+1) unit 19 with hubs on ports 2 to 5 and its partner on 1 and 6 (crossed for
    pairs in @cross); R-brick j is router (100+j) unit 38. rlinks (cx, cx port, R-brick, R port); rr (R, port, R, port)."""
    rows = []
    for i in range(ncx):
        c = "%03d" % (i + 1)
        rows += [(c, "C", str(u), "Link", "1", c, "R", "19", str(p)) for u, p in zip((10, 13, 16, 21), (2, 3, 4, 5))]
    for i in range(0, ncx, 2):
        a, b = "%03d" % (i + 1), "%03d" % (i + 2)
        rows += [(a, "R", "19", str(p), "1", b, "R", "19", str(7 - p if i in cross else p)) for p in (1, 6)]
    rows += [("%03d" % (c + 1), "R", "19", str(cp), "3", "%03d" % (100 + r), "R", "38", str(rp)) for c, cp, r, rp in rlinks]
    rows += [("%03d" % (100 + a), "R", "38", str(pa), "3", "%03d" % (100 + b), "R", "38", str(pb)) for a, pa, b, pb in rr]
    return rows


def replay(rows, roles, full=True):
    """Number walk, then (if it passes and @full) route calculation, forwarding and the dependency-cycle check."""
    import metarouter_replay as M, route_diagnostics as D
    D.PAIR.clear()
    rp, t, ridx, h0, hubs, links = M.build(rows, roles)
    rc = M.run(rp, t, h0) & 0xffffffff
    errs = [l for l in rp.out if any(k in l for k in ("rror", "xpress", "expected", "EMU", "ERR"))]
    res = {"walk": rc - (1 << 32 if rc >> 31 else 0), "err": errs[:1],
           "hubs": {f"{rn}p{p}": t.number(h) for h, rn, p in hubs}}
    if res["walk"] or not full:
        return res
    rp.out.clear()
    r2 = rp.call(0x1fc5d450, [M.K0 | t.base]) & 0xffffffff
    hist, longest, _, _ = M.sim(rp, t, ridx, hubs, links)
    res.update(route=r2 - (1 << 32 if r2 >> 31 else 0), forward=dict(hist), longest=longest,
               no_traffic=sum("no traffic" in l for l in rp.out), cycle=bool(D.cycle(D.deps(rp, t, ridx, hubs, links))))
    return res


def accepted(r):
    return r["walk"] == 0 and r.get("route", 0) == 0 and set(r.get("forward", {"ok": 1})) == {"ok"} and not r.get("cycle")


def pool(fn, args):
    with mp.Pool(int(os.environ.get("JOBS", "8"))) as p:
        for res in p.imap(fn, args):
            print(json.dumps(res), flush=True)


# ---- 10 to 16 Cx-bricks on four R-bricks

def four_classes(n):
    """Every class: a multiset of pair types (the R-brick pairs of a pair's two Cx-bricks) and an R-R multigraph."""
    perms = list(itertools.permutations(range(4)))
    emaps = [[E.index(tuple(sorted((p[a], p[b])))) for a, b in E] for p in perms]
    seen = set()
    for combo in itertools.combinations_with_replacement(range(len(PT)), n // 2):
        deg = [0] * 4
        for t in combo:
            for e in PT[t]:
                for r in E[e]:
                    deg[r] += 1
        if max(deg) > 8:
            continue

        def rrs(i, spare, cur):
            if i == len(E):
                yield cur
                return
            a, b = E[i]
            for k in range(min(spare[a], spare[b]) + 1):
                s = list(spare); s[a] -= k; s[b] -= k
                yield from rrs(i + 1, s, cur + [E[i]] * k)

        for rr in rrs(0, [8 - d for d in deg], []):
            seen.add(min((tuple(sorted(tuple(sorted((em[PT[t][0]], em[PT[t][1]]))) for t in combo)),
                          tuple(sorted(tuple(sorted((p[a], p[b]))) for a, b in rr))) for p, em in zip(perms, emaps)))
    return sorted(seen)


def four_edges(n, cls):
    ed = []
    for k, (ea, eb) in enumerate(cls[0]):
        ed += [(2 * k, 2 * k + 1)] * 2 + [(c, n + r) for c, e in ((2 * k, ea), (2 * k + 1, eb)) for r in E[e]]
    return ed + [(n + a, n + b) for a, b in cls[1]]


def bisection(n, ed):
    """Fewest cables across a cut with n/2 Cx-bricks on each side (R-bricks on either)."""
    import numpy as np
    cx = []
    for sub in itertools.combinations(range(1, n), n // 2):
        s = np.zeros(n, bool); s[list(sub)] = True; cx.append(s)
    cx = np.array(cx); rm = np.array(list(itertools.product((False, True), repeat=4)))
    S = np.concatenate([np.repeat(cx, len(rm), axis=0), np.tile(rm, (len(cx), 1))], axis=1)
    u = np.array([e[0] for e in ed]); v = np.array([e[1] for e in ed])
    return int((S[:, u] != S[:, v]).sum(axis=1).min())


def connected(n, ed):
    adj = collections.defaultdict(set)
    for u, v in ed:
        adj[u].add(v); adj[v].add(u)
    seen, st = {0}, [0]
    while st:
        for v in adj[st.pop()] - seen:
            seen.add(v); st.append(v)
    return len(seen) == n + 4


def four_rows(n, cls):
    """Cx-brick G (7) to the lower R-brick of its pair, H (8) to the higher; R ports in order; R-R cables after."""
    nxt = [1] * 4; links = []; rr = []
    for k, (ea, eb) in enumerate(cls[0]):
        for c, e in ((2 * k, ea), (2 * k + 1, eb)):
            for port, r in zip((7, 8), E[e]):
                links.append((c, port, r, nxt[r])); nxt[r] += 1
    for a, b in cls[1]:
        rr.append((a, nxt[a], b, nxt[b])); nxt[a] += 1; nxt[b] += 1
    return rows_for(n, links, rr), {"%03dr38" % (100 + j): 1 for j in range(4)}


def prom4_job(a):
    n, cls = a
    r = replay(*four_rows(n, cls))
    return {"class": cls, "accepted": accepted(r), "err": r["err"], "no_traffic": r.get("no_traffic")}


# ---- above 16 Cx-bricks: two planes, ceil(N/4) columns, four level-3 R-bricks per plane

def column_classes(n, samples=300, seed=1):
    """Column multigraphs (a loop is a pair inside one column, an edge a pair split over two), each column 1 to 4
    Cx-bricks: exhaustive up to relabelling for 5 columns or fewer, else a sample of distinct Weisfeiler-Lehman classes.
    The canonical form and the split-pair form come first."""
    import networkx as nx
    c = (n + 3) // 4; P = n // 2
    first = [[(k // 2, k // 2) for k in range(P)]]
    if n % 4:
        first.append([(k // 2, k // 2) for k in range(P - 3)] + [(c - 2, c - 2), (c - 2, c - 1), (c - 1, c - 1)])
    out = {}
    if c <= 5:
        perms = list(itertools.permutations(range(c)))
        cand = [(i, j) for i in range(c) for j in range(i, c)]
        for combo in itertools.combinations_with_replacement(cand, P):
            deg = collections.Counter(x for e in combo for x in e)
            if len(deg) == c and max(deg.values()) <= 4:
                out.setdefault(min(tuple(sorted(tuple(sorted((p[i], p[j]))) for i, j in combo)) for p in perms), list(combo))
    else:
        rnd = random.Random(seed)
        for _ in range(samples * 50):
            if len(out) >= samples:
                break
            order = list(range(c)) + [x for x in rnd.sample([x for x in range(c) for _ in range(3)], n - c)]
            rnd.shuffle(order)
            edges = sorted(tuple(sorted(order[2 * k:2 * k + 2])) for k in range(P))
            G = nx.Graph(); G.add_nodes_from(range(c), lab="0")
            for (i, j), m in collections.Counter(edges).items():
                if i == j:
                    G.nodes[i]["lab"] = str(m)
                else:
                    G.add_edge(i, j, lab=str(m))
            out.setdefault(nx.weisfeiler_lehman_graph_hash(G, node_attr="lab", edge_attr="lab"), edges)
    canon = lambda e: sorted(map(tuple, e))
    return first + [e for e in out.values() if canon(e) not in [canon(f) for f in first]]


def big_rows(n, colpairs, perm=None, swap=(), extra=(), l3role=1):
    """Level-2 R-brick j of plane A is R-brick j, of plane B 8 + j; level-3 t of plane A 16 + t, of plane B 20 + t.
    Cx-bricks on level-2 ports 1 to 4, level-2 ports 5 to 8 to level-3 0 to 3, level-3 port j + 1 to column j, unless
    @perm (R-brick -> eight ports) relabels them."""
    c = (n + 3) // 4; slot = collections.Counter(); links = []; rr = []
    P = perm or {r: list(range(1, 9)) for r in range(24)}
    for k, (ca, cb) in enumerate(colpairs):
        for x, col in ((2 * k, ca), (2 * k + 1, cb)):
            s = slot[col]; slot[col] += 1
            pa, pb = (8, 7) if x in swap else (7, 8)
            links += [(x, pa, col, P[col][s]), (x, pb, 8 + col, P[8 + col][s])]
    for plane in (0, 1):
        for j in range(c):
            for t in range(4):
                a, b = 8 * plane + j, 16 + 4 * plane + t
                rr.append((a, P[a][4 + t], b, P[b][j]))
    rr += [(8 * plane + j, lp, 16 + 4 * plane + t, tp) for plane, j, t, lp, tp in extra]
    roles = {"%03dr38" % (100 + r): 1 for j in range(c) for r in (j, 8 + j)}
    roles.update({"%03dr38" % (116 + t): l3role for t in range(8)})
    return rows_for(n, links, rr), roles


def hub0(n, r):
    return [min(r["hubs"]["%03dr19p%d" % (x + 1, p)] for p in (2, 3, 4, 5)) for x in range(n)]


def columns_job(a):
    n, cp = a
    r = replay(*big_rows(n, cp), full=False)
    return {"n": n, "columns": cp, "walk": r["walk"], "err": r["err"], "hub0": hub0(n, r)}


def ruled_perm(n, rnd):
    """Ports the PROM accepts above 16 Cx-bricks (section 5 of the cabling page): one set S of four Cx ports shared by every
    level-2 R-brick, partners on ranks of S that differ in one bit, level-2 uplinks in any order, and one column-to-port
    map shared by the four level-3 R-bricks of a plane."""
    perm = {}
    for plane in (0, 1):
        m = rnd.sample(range(1, 9), 8)
        perm.update({16 + 4 * plane + t: m for t in range(4)})
    S = sorted(rnd.sample(range(1, 9), 4)); up = [x for x in range(1, 9) if x not in S]
    for r in list(range((n + 3) // 4)) + list(range(8, 8 + (n + 3) // 4)):
        ranks = rnd.choice([o for o in itertools.permutations(range(4)) if bin(o[0] ^ o[1]).count("1") == 1
                            and bin(o[2] ^ o[3]).count("1") == 1])
        perm[r] = [S[k] for k in ranks] + rnd.sample(up, 4)
    return perm


def ports_job(a):
    n, seed, full, free = a
    rnd = random.Random(seed)
    perm = {r: rnd.sample(range(1, 9), 8) for r in range(24)} if free or n <= 16 else ruled_perm(n, rnd)
    swap = {x for x in range(n) if rnd.random() < 0.5}
    if n <= 16:
        links = []
        for x in range(n):
            ra, rb = (0, 1) if x % 2 else (2, 3)
            pa, pb = (8, 7) if x in swap else (7, 8)
            links += [(x, pa, ra, perm[ra][x // 2]), (x, pb, rb, perm[rb][x // 2])]
        rows, roles = rows_for(n, links), {"%03dr38" % (100 + j): 1 for j in range(4)}
    else:
        rows, roles = big_rows(n, [(k // 2, k // 2) for k in range(n // 2)], perm, swap)
    r = replay(rows, roles, full)
    return {"n": n, "seed": seed, "accepted": accepted(r), "err": r["err"], "hub0": hub0(n, r)}


if __name__ == "__main__":
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    a = sys.argv[1:]
    if not a:
        sys.exit(__doc__)
    n = int(a[1])
    if a[0] == "four":
        rows = []
        for cls in four_classes(n):
            ed = four_edges(n, cls)
            ok = connected(n, ed)
            rows.append([cls, ok, bisection(n, ed) if ok else None])
        json.dump(rows, open(f"four-{n}.json", "w"))
        print(n, "classes", len(rows), "connected", sum(r[1] for r in rows),
              "bisection >= N", sum(1 for r in rows if r[1] and r[2] >= n),
              "and no R-R cable", sum(1 for r in rows if r[1] and r[2] >= n and not r[0][1]))
    elif a[0] == "prom4":
        rows = json.load(open(f"four-{n}.json"))
        pick = [r[0] for r in rows if r[1] and ((r[2] < n) if a[2] == "low" else (r[2] >= n and (not r[0][1]) == (a[2] == "norr")))]
        if len(a) > 3 and len(pick) > int(a[3]):
            pick = random.Random(7).sample(pick, int(a[3]))
        pool(prom4_job, [(n, [[tuple(p) for p in c[0]], [tuple(p) for p in c[1]]]) for c in pick])
    elif a[0] == "columns":
        pool(columns_job, [(n, cp) for cp in column_classes(n)])
    elif a[0] == "ports":
        pool(ports_job, [(n, s, "full" in a[3:], "free" in a[3:]) for s in range(1, int(a[2]) + 1)])
    elif a[0] == "variants":
        c = (n + 3) // 4; j = c - 1; cp = [(k // 2, k // 2) for k in range(n // 2)]
        for name, ex, role in (("canonical", [], 1), ("one extra cable per plane", [(p, j, 0, 3, 6) for p in (0, 1)], 1),
                               ("two extra cables per plane", [(p, j, t, 3 + t, 6) for p in (0, 1) for t in (0, 1)], 1),
                               ("level-3 ordinary", [], 0), ("level-3 meta and repeat", [], 3)):
            r = replay(*big_rows(n, cp, extra=ex, l3role=role), full=False)
            print(json.dumps({"n": n, "variant": name, "walk": r["walk"], "err": r["err"]}), flush=True)
    else:
        sys.exit(__doc__)
