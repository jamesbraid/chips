# /// script
# requires-python = ">=3.11"
# dependencies = ["unicorn>=2.1"]
# ///
"""Two diagnostics over metarouter_replay.py's graphs.

    IP35_PAYLOAD=ip35prom.payload.bin CABLING_TEXT=cabling.txt uv run route_diagnostics.py TABLE [TABLE ...]

TABLE is a guide table number (19 for Table 2-19) or `3600:48p` style.  For each graph it prints
  PAIR  the squares the PROM's pair check (0x1fc241ac) compares, and those that fail: router entries R and
        N (joined by the port at record index i), the other router X on record index j, X's index-i neighbour
        Z and N's index-j neighbour Y.  Record index k is router port 8 - k.  The check fails when Y != Z.
        (Entry numbers are the replay's table indices.)
  CDG   a cycle, if any, in the channel dependency graph of the routes the PROM wrote: forward every hub
        pair through the written tables (as `sim` does), make each router-to-router exit a channel and each
        consecutive pair on a path a dependency.  The PROM's own deadlock check is a separate routine; this
        is an independent walk of its output.
"""
import collections, os, sys
import metarouter_replay as M
from metarouter_replay import *

PAIR = []
_old = M.Replay.__init__
def _init(self, *a, **k):
    _old(self, *a, **k)
    g = lambda r: self.uc.reg_read(r)
    self.stubs[0x1fc24448] = lambda pc: PAIR.append(
        (g(UC_MIPS_REG_S7), g(UC_MIPS_REG_S4), g(UC_MIPS_REG_S1), g(UC_MIPS_REG_T2),
         g(UC_MIPS_REG_T7) & 0xffffffff, g(UC_MIPS_REG_V0) & 0xffffffff))
M.Replay.__init__ = _init

def deps(rp, t, ridx, hubs, links):
    adj = {}
    for (a, pa, b, pb) in links: adj[(a, pa)] = ('R', b, pb); adj[(b, pb)] = ('R', a, pa)
    for (h, rn, p) in hubs: adj[(rn, p)] = ('H', h, 1)
    def hubtab(h, D):
        o = t.ent(h) + 0x20
        return rp.r32(o + 0x28 + 4 * (D & 0x7f)) if (D >> 7) == (t.number(h) >> 7) else rp.r32(o + 0x228 + 4 * (D >> 7))
    def rtab(rn, D):
        i = ridx[rn]; o = t.ent(i) + 0x20; fl = rp.r8(o + 0x24); num = t.number(i)
        if (D >> 7) == (num >> 7) or fl: return rp.r32(o + 0xa4 + 4 * (D & 0x7f)) & 0xffffffff
        return rp.r32(o + 0x2a4 + 4 * (D >> 7)) & 0xffffffff
    hub_by = {t.number(h): h for h, rn, p in hubs}
    dep = collections.defaultdict(set)
    for (hs, rs, ps) in hubs:
        for nd, hd in hub_by.items():
            if hd == hs: continue
            turn = hubtab(hs, nd) & 0xffffffff; cur = rs; entry = ps; prev = None
            while turn <= 7:
                ex = ((entry - 1 + turn) % 8) + 1; nb = adj.get((cur, ex))
                if nb is None or nb[0] == 'H': break
                ch = (cur, ex)
                if prev: dep[prev].add(ch)
                prev = ch
                turn = nib(rtab(cur, nd), entry - 1); cur = nb[1]; entry = nb[2]
    return dep

def cycle(dep):
    color = {}; stack = []
    def dfs(u):
        color[u] = 1; stack.append(u)
        for v in dep.get(u, ()):
            if color.get(v, 0) == 0:
                r = dfs(v)
                if r: return r
            elif color[v] == 1: return stack[stack.index(v):] + [v]
        stack.pop(); color[u] = 2
    for u in list(dep):
        if color.get(u, 0) == 0:
            r = dfs(u)
            if r: return r

if __name__ == "__main__":
    cab = os.environ.get("CABLING_TEXT")
    if cab: M.T.update(parse(cab))
    for a in sys.argv[1:]:
        if a.startswith("3600:"):
            f, p, i = S[a[5:]]; M.T[a] = {"procs": 0, "rows": mk(f, p, i)}; key = a; roles = {}
        else:
            key = int(a); roles = roles_for(M.T[key]["rows"])
        PAIR.clear()
        rp, t, ridx, h0, hubs, links, nums = M.trial(key, roles=roles, quiet=True)
        print("PAIR", a, "squares examined:", len(PAIR))
        for r in PAIR:
            if r[4] != r[5]: print("PAIR mismatch R=%d N=%d i=%d j=%d Z=%d Y=%d" % r)
        c = cycle(deps(rp, t, ridx, hubs, links))
        print("CDG", a, "cycle:", c)
