# /// script
# requires-python = ">=3.11"
# dependencies = ["unicorn>=2.1"]
# ///
"""Run PROM 6.210's number walk, route calculation and deadlock check over the Origin 3900 cabling that
tools/origin3900-cabling/plan.py writes, then forward every hub pair through the tables the PROM wrote.

    IP35_PAYLOAD=ip35prom.payload.bin uv run cx3900_plan_check.py N [N ...] [--walk]

Each Cx-brick is a router with its four hubs on ports 2 to 5; R-bricks carry the MetaRouter flag.  --walk stops after
the number walk (the route calculation takes about 20 minutes at 32 Cx-bricks).  A software expectation about the
graph, not evidence of shipped cabling.
"""
import importlib.util, os, sys
import route_diagnostics as D
import metarouter_replay as M

HERE = os.path.dirname(os.path.abspath(__file__))
spec = importlib.util.spec_from_file_location("plan", os.path.join(HERE, "../../../tools/origin3900-cabling/plan.py"))
plan = importlib.util.module_from_spec(spec); spec.loader.exec_module(plan)


def rows(n):
    """The plan's cables as metarouter_replay rows: Cx-brick i is router (i+1) unit 19, R-brick j is (100+j) unit 38."""
    _, cables = plan.topology(n)
    name = lambda r: ("%03d" % (int(r[2:]) + 1), "19") if r.startswith("cx") else ("%03d" % (100 + int(r[6:])), "38")
    out = []
    for i in range(n):
        for u, p in zip((10, 13, 16, 21), (2, 3, 4, 5)):
            out.append(("%03d" % (i + 1), "C", str(u), "Link", "1", "%03d" % (i + 1), "R", "19", str(p)))
    for a, pa, b, pb in cables:
        (ra, ua), (rb, ub) = name(a), name(b)
        out.append((ra, "R", ua, str(pa), "1", rb, "R", ub, str(pb)))
    return out


def check(n, walk_only):
    r = rows(n)
    roles = {f"{x[5]}r38": 1 for x in r if x[7] == "38"} | {f"{x[0]}r38": 1 for x in r if x[2] == "38"}
    M.T[n] = {"procs": 16 * n, "rows": r}
    D.PAIR.clear()
    if walk_only:
        rp, t, ridx, h0, hubs, links = M.build(r, roles)
        rc = M.run(rp, t, h0) & 0xffffffff
        print("WALK", n, "rc", rc, "hub numbers", sorted(t.number(h) for h, _, _ in hubs) == list(range(4 * n)), flush=True)
        return
    rp, t, ridx, h0, hubs, links, nums = M.trial(n, roles=roles, quiet=False)
    print("RESULT", n, "squares", len(D.PAIR), "cycle", D.cycle(D.deps(rp, t, ridx, hubs, links)), flush=True)


if __name__ == "__main__":
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    if not args:
        sys.exit(__doc__)
    for a in args:
        check(int(a), "--walk" in sys.argv)
