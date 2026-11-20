# /// script
# dependencies = ["unicorn>=2.1"]
# ///
"""A guess, not shipped wiring: 32 Cx-brick routers (four hubs on ports 2 to 5, pairs joined on ports 1 and 6), each
with port 7 (plane 1, argument `p1`) and, for `both`, port 8 (plane 2) cabled to a copy of Table 2-31's U38 network
in place of the 3800's rack routers.  Prints the PROM's verdicts and the pair and cycle diagnostics."""
import os,sys,collections
import route_diagnostics as D
import metarouter_replay as M
from metarouter_replay import *
M.T.update(parse(os.environ["CABLING_TEXT"]))
base=M.T[31]["rows"]
rr=[r for r in base if r[1]=="R" and r[6]=="R"]
uu=[r for r in rr if r[2]=="38" and r[7]=="38"]
up=[r for r in rr if (r[2]=="38")!=(r[7]=="38")]
racks=sorted({(r[0],r[2]) for r in up if r[2]!="38"}|{(r[5],r[7]) for r in up if r[7]!="38"})
assert len(racks)==32
cx={rk:i+1 for i,rk in enumerate(racks)}
def build_rows(planes,uplink_ports,plane2_shift=True,meta_port_map=None):
    rows=[]
    for i in range(1,33):
        r="%03d"%i
        for u,p in zip((10,13,16,21),(2,3,4,5)): rows.append((r,"C",str(u),"Link","1",r,"R","19",str(p)))
    for k in range(1,33,2):
        a,b="%03d"%k,"%03d"%(k+1)
        for p in (1,6): rows.append((a,"R","19",str(p),"1",b,"R","19",str(p)))
    for pl in planes:
        ren=(lambda x:x) if pl==1 else (lambda x:"1"+x[1:])
        for r in uu: rows.append((ren(r[0]),"R",r[2],r[3],r[4],ren(r[5]),"R",r[7],r[8]))
        for r in up:
            if r[2]!="38": cxr,(mr,mu),mp=r[0:1][0],(r[5],r[7]),r[8]; ck=(r[0],r[2])
            else: ck=(r[5],r[7]); mr,mu,mp=r[0],r[2],r[3]
            mp=(meta_port_map or {}).get((pl,mp),mp)
            rows.append(("%03d"%cx[ck],"R","19",str(uplink_ports[pl]),"3",ren(mr),"R","38",mp))
    return rows
def run(name,rows):
    M.T[name]={"procs":512,"rows":rows}
    roles=roles_for(rows)
    D.PAIR.clear()
    rp,t,ridx,h0,hubs,links,nums=M.trial(name,roles=roles,quiet=True)
    print("PAIR",name,"squares",len(D.PAIR),"mismatch",sum(1 for r in D.PAIR if r[4]!=r[5]))
    print("CDG",name,D.cycle(D.deps(rp,t,ridx,hubs,links)),flush=True)
    return rp,t,ridx,hubs,links
which=sys.argv[1]
if which=="p1": run("3900-plane1",build_rows([1],{1:7}))
if which=="both": run("3900-both",build_rows([1,2],{1:7,2:8}))
