# /// script
# dependencies = ["unicorn>=2.1"]
# ///
"""Number walk of a guide table (argument 1) for every way of giving both role flags to NREP of its U38 routers, the
rest MetaRouters.  Arguments: TABLE PART NPARTS NREP (PART of NPARTS splits the work).  Prints one WALK line each;
`rc 0` is a pass.  Same environment as metarouter_replay.py."""
import os,sys,itertools,time
import metarouter_replay as M
from metarouter_replay import *
M.T.update(parse(os.environ["CABLING_TEXT"]))
key=int(sys.argv[1]); part=int(sys.argv[2]); nparts=int(sys.argv[3]); nrep=int(sys.argv[4])
rows=M.T[key]["rows"]
u38=sorted(roles_for(rows))
combos=list(itertools.combinations(u38,nrep))
for ci,rep in enumerate(combos):
    if ci%nparts!=part: continue
    roles={n:(3 if n in rep else 1) for n in u38}
    t0=time.time()
    rp,t,ridx,h0,hubs,links=build(rows,roles)
    rc=run(rp,t,h0)&0xffffffff
    print("WALK",key,"rep=",",".join(rep),"rc",rc,round(time.time()-t0,1),flush=True)
