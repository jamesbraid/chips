# /// script
# requires-python = ">=3.11"
# dependencies = ["unicorn>=2.1"]
# ///
"""Replay the IP35 PROM 6.210's router number walk, route calculation and router table distribution over
the cable tables of the preliminary Origin 3000 System Cabling guide (108-xxxx-PR2), then forward every
hub pair through the tables the PROM wrote.

    IP35_PAYLOAD=ip35prom.payload.bin CABLING_TEXT=cabling.txt uv run metarouter_replay.py TABLE [TABLE ...]
    IP35_PAYLOAD=ip35prom.payload.bin uv run metarouter_replay.py 3600:64p 3600:112p-alt ...

CABLING_TEXT is `pdftotext -layout` of the guide (tables 2-19 to 2-31 are parsed from it; the 32 to 128
processor "3600 series" graphs are built in the script from the guide's link lists).  META_ROLE and REP_ROLE
(default 1 and 3: the router flag bits, bit 0 meta, bit 1 repeat) set the role of U38 routers that take a rack-router
cable and of those that do not.  The 512-processor
table takes about two minutes.  This runs the PROM's code over a table built here; it is not the PROM's own
discovery and not a hardware measurement.  Replaced in the replay: console output, the environment lookup,
the read of the local node number, the vector write (recorded) and read (returns zero), two timeout
setters, the master's stores to its own hub registers, and the route cache base (moved to a mappable window).
"""
import sys, collections, re, time
import os, struct, itertools
from unicorn import *
from unicorn.mips_const import *
# Replay harness: runs the PROM number calculation (0x1fc5d63c) over a synthetic discovery table.

P=os.environ.get("IP35_PAYLOAD","assets/firmware/6.5.30/ip35prom.payload.bin")
K0=0xffffffff80000000
IMG=0x1fc00000
GP=0x1fd6f740
RAM_BASE=0x01000000
TAB=RAM_BASE+0x100000
STACK=RAM_BASE+0x3000000

def build_image():
    d=bytearray(open(P,"rb").read())
    # rewrite GOT-style 0xc00000001fXXXXXX pointers to kseg0 form, on the whole image's 8-aligned words
    for o in range(0,len(d)-8,8):
        hi=struct.unpack(">I",d[o:o+4])[0]; lo=struct.unpack(">I",d[o+4:o+8])[0]
        if hi==0xc0000000 and 0x1fc00000<=lo<0x1fe00000:
            d[o:o+8]=struct.pack(">Q",K0|lo)
    # code-built 0xc000_0000_xxxxxxxx constants: lui rX,0xc000 ... dsll32 rX,rX,0  ->  lui rX,0x8000 ... nop
    cnt=0
    for o in range(0,len(d)-4,4):
        w=struct.unpack(">I",d[o:o+4])[0]
        if w>>16 & 0xffe0 ==0x3c00 and (w&0xffff)==0xc000:
            rt=(w>>16)&31
            for k in range(1,8):
                w2=struct.unpack(">I",d[o+4*k:o+4*k+4])[0]
                # dsll32 rd,rt,sa: op 0 rs 0 rt rd sa func 0x3c
                if (w2&0x3f)==0x3c and ((w2>>16)&31)==rt and ((w2>>11)&31)==rt and ((w2>>6)&31)==0:
                    d[o:o+4]=struct.pack(">I",(w&0xffff0000)|0x8000)
                    d[o+4*k:o+4*k+4]=b"\0\0\0\0"; cnt+=1; break
    build_image.patched=cnt
    for a in (0x1fc67d4c,0x1fc680cc,0x1fc675f4):
        o=a-IMG; d[o:o+8]=struct.pack(">II",0x03e00008,0)   # jr ra ; nop
    return bytes(d)

class Replay:
    def __init__(self,verbose=True):
        self.out=[]
        self.uc=uc=Uc(UC_ARCH_MIPS,UC_MODE_MIPS64|UC_MODE_BIG_ENDIAN)
        uc.ctl_set_cpu_model(UC_CPU_MIPS64_MIPS64R2_GENERIC)
        img=build_image()
        uc.mem_map(IMG,0x200000)
        uc.mem_write(IMG,img)
        uc.mem_map(0,0x4000000+RAM_BASE-0)  # phys 0..~0x5000000? keep simple
        self.stubs={0x1fc67d4c:self.pr,0x1fc680cc:self.pr_err,0x1fc675f4:self.pr2}
        uc.hook_add(UC_HOOK_CODE,self.code_hook)
        uc.reg_write(UC_MIPS_REG_CP0_STATUS,0x240000e0)
        self.last=0; self.ring=[]; self.calltrace=None
        uc.reg_write(UC_MIPS_REG_GP,K0|GP) if False else None
        uc.reg_write(UC_MIPS_REG_GP,0xffffffff80000000|GP)
        # verbose flag: *(gp-0x70b0) points at a struct; +0x1c48 word
        self.verbose=verbose
        if verbose:
            for off in (-0x70b0,-0x7b28,-0x7b18):
                p=self.ld64(GP+off)&0x1fffffff
                self.w32(p+0x1c48,1)
    def ld64(self,phys):  # from image
        return struct.unpack(">Q",bytes(self.uc.mem_read(phys+0, 8)))[0] if False else struct.unpack(">Q",bytes(self.uc.mem_read(phys,8)))[0]
    def w32(self,a,v): self.uc.mem_write(a, struct.pack(">I",v&0xffffffff))
    def w16(self,a,v): self.uc.mem_write(a, struct.pack(">H",v&0xffff))
    def w8(self,a,v): self.uc.mem_write(a, bytes([v&0xff]))
    def w64(self,a,v): self.uc.mem_write(a, struct.pack(">Q",v&0xffffffffffffffff))
    def r16(self,a): return struct.unpack(">h",bytes(self.uc.mem_read(a,2)))[0]
    def r32(self,a): return struct.unpack(">i",bytes(self.uc.mem_read(a,4)))[0]
    def r8(self,a): return self.uc.mem_read(a,1)[0]
    def cstr(self,va):
        a=va&0x1fffffff if va>=K0 else va
        s=bytearray()
        while True:
            c=self.uc.mem_read(a,1)[0]
            if c==0: break
            s.append(c); a+=1
        return s.decode("latin1")
    def fmt(self,args):
        f=self.cstr(args[0]); vals=args[1:]
        i=[0]
        def rep(m):
            spec=m.group(0)
            if spec=="%%": return "%"
            v=vals[i[0]] if i[0]<len(vals) else 0; i[0]+=1
            conv=spec[-1]; flags=re.sub(r"[lhzq]","",spec[:-1])
            if conv=="s": return (flags+"s")%self.cstr(v)
            if conv in "di":
                v&=0xffffffff if "l" not in spec else 0xffffffffffffffff
                if "l" in spec:
                    v=v-(1<<64) if v>>63 else v
                else: v=v-(1<<32) if v>>31 else v
                return (flags+"d")%v
            if conv in "xXuo":
                v&=0xffffffffffffffff if "l" in spec else 0xffffffff
                return (flags+("d" if conv=="u" else conv))%v
            if conv=="c": return chr(v&0xff)
            return spec
        return re.sub(r"%[-+ #0-9.*]*[lhzq]*[a-zA-Z%]",rep,f)
    def regs(self):
        return [self.uc.reg_read(r) for r in (UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_A2,UC_MIPS_REG_A3,UC_MIPS_REG_T0,UC_MIPS_REG_T1,UC_MIPS_REG_T2,UC_MIPS_REG_T3)]
    def pr(self,pc):
        t=self.fmt(self.regs()); self.out.append(t.rstrip("\n")+("   [ra=%x]"%(self.uc.reg_read(UC_MIPS_REG_RA)&0x1fffffff) if "consistent" in t else ""))
        pass
    def pr2(self,pc):
        r=self.regs(); t=self.fmt(r[1:]); self.out.append(t.rstrip('\n'))
    def pr_err(self,pc):
        t=self.fmt(self.regs()); self.out.append("ERR: "+t.rstrip("\n"))
    def ret(self):
        self.uc.reg_write(UC_MIPS_REG_V0,0)
        self.uc.reg_write(UC_MIPS_REG_PC,self.uc.reg_read(UC_MIPS_REG_RA))
    def code_hook(self,uc,addr,size,ud):
        p=addr&0x1fffffff
        self.last=addr
        if self.calltrace is not None and (self.uc.mem_read(addr&0x1fffffff,4)[0]>>2)==3: self.calltrace.append(addr&0x1fffffff)
        self.ring.append(addr); 
        if len(self.ring)>400: self.ring.pop(0)
        if p in self.stubs: self.stubs[p](p)  # observe only; image holds jr ra
    def call(self,func,args,maxinsn=50_000_000):
        uc=self.uc
        sp=K0|STACK
        uc.reg_write(UC_MIPS_REG_SP,sp)
        for r,a in zip((UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_A2,UC_MIPS_REG_A3),args): uc.reg_write(r,a)
        sentinel=K0|(IMG+0x1ffff0)
        uc.reg_write(UC_MIPS_REG_RA,sentinel)
        try:
            uc.emu_start(K0|func,sentinel,count=maxinsn)
        except UcError as e:
            self.out.append("ring "+" ".join("%x"%(a&0xffffffff) for a in self.ring[-30:])); self.out.append("a0-a3 "+" ".join("%x"%x for x in self.regs()[:4])+" ra=%x"%uc.reg_read(UC_MIPS_REG_RA)); self.out.append("EMU ERROR %s pc=%x last=%x"%(e,uc.reg_read(UC_MIPS_REG_PC),self.last))
        return uc.reg_read(UC_MIPS_REG_V0)

ENT=0x400
class Table:
    """Synthetic discovery result. Entry i at TAB+i*0x400; object at +0x20."""
    def __init__(self,rp):
        self.rp=rp; self.n=0; self.base=TAB
        rp.w32(TAB+4,4096); rp.w32(TAB+8,0)
        self.hubs=0; self.routers=0
    def ent(self,i): return self.base+i*ENT
    def add_router(self,rid,role=0,number=None):
        rp=self.rp; i=self.n; e=self.ent(i); o=e+0x20
        rp.uc.mem_write(o,bytes(0x2f8))
        rp.w8(o,2); rp.w16(o+2,-1); rp.w64(o+8,rid)
        for k in range(8):
            rp.w16(o+0x20+16*k,-1); rp.w8(o+0x22+16*k,0xff)
        for a in range(o+0xa4,o+0x2a4,4): rp.w32(a,0xffffffff)
        for a in range(o+0x2a4,o+0x2e4,4): rp.w32(a,0xffffffff)
        # flags: state 2 (done) as discovery leaves it; role bits
        rp.w16(e+0x26, role|0x20)
        if number is not None: rp.w16(e+0x22,number)
        self.n+=1; rp.w32(TAB+8,self.n); self.routers+=1; rp.w32(TAB+0x14,self.routers)
        return i
    def add_hub(self,hid):
        rp=self.rp; i=self.n; e=self.ent(i); o=e+0x20
        rp.uc.mem_write(o,bytes(0x230))
        rp.w8(o,1); rp.w16(o+2,-1); rp.w8(o+0x12,0xff); rp.w16(o+0x10,-1); rp.w64(o+0x20,hid)
        for a in range(o+0x28,o+0x224,4): rp.w32(a,0xf)
        rp.w32(o+0x228,0xf)
        self.n+=1; rp.w32(TAB+8,self.n); self.hubs+=1; rp.w32(TAB+0x10,self.hubs)
        return i
    def link_rr(self,a,pa,b,pb):   # router entry a port pa(1..8) <-> router b port pb
        rp=self.rp
        for (x,px,y,py) in ((a,pa,b,pb),(b,pb,a,pa)):
            r=self.ent(x)+0x40+16*(px-1)
            rp.w16(r,y); rp.w8(r+2,py)
    def link_hr(self,h,r,pr):  # hub h <-> router r port pr
        rp=self.rp
        rr=self.ent(r)+0x40+16*(pr-1)
        rp.w16(rr,h); rp.w8(rr+2,1)
        rp.w16(self.ent(h)+0x30,r); rp.w8(self.ent(h)+0x32,pr)
    def number(self,i): return self.rp.r16(self.ent(i)+0x22)
    def flags(self,i): return self.rp.r16(self.ent(i)+0x26)

def run(rp,tab,master):
    return rp.call(0x1fc5d63c,[K0|tab.base,master])


# fix hub table init (local 128 words at o+0x28, meta 16 words at o+0x228)
def add_hub(self,hid):
    rp=self.rp; i=self.n; e=self.ent(i); o=e+0x20
    rp.uc.mem_write(o,bytes(0x270))
    rp.w8(o,1); rp.w16(o+2,-1); rp.w8(o+0x12,0xff); rp.w16(o+0x10,-1); rp.w64(o+0x20,hid)
    for a in range(o+0x28,o+0x268,4): rp.w32(a,0xf)
    self.n+=1; rp.w32(TAB+8,self.n); self.hubs+=1; rp.w32(TAB+0x10,self.hubs)
    return i
Table.add_hub=add_hub

ROW=re.compile(r'^\s*(\d{3})\s+([A-Z])\s+(\d+)\s+(\w+)\s+~?\s*(\d+)\s*M\s+(\d{3})\s+([A-Z])\s+(\d+)\s+(\w+)\s*$')
def parse(path):
    tabs=collections.OrderedDict(); cur=None
    for ln,l in enumerate(open(path,encoding="latin1")):
        h=re.search(r'Table 2-(\d+)\s+(?:\(Alternate\)\s+)?(\d+)[ -][Pp]rocessor',l)
        if h and ln>400 and '....' not in l: cur=int(h.group(1)); tabs.setdefault(cur,{"procs":int(h.group(2)),"rows":[]}); continue
        r=ROW.match(l)
        if r and cur: 
            tabs[cur]["rows"].append(r.groups())
    return tabs

def build(rows, roles, master=None, hub_per_c=True):
    """rows: parsed table rows. roles: dict router-name->role bits (0 ordinary,1 meta,3 repeat)."""
    rp=Replay(); t=Table(rp)
    rname=lambda r,u:f"{r}r{u}"
    routers=[]; seen=set()
    for (ra,ta,ua,pa,ln,rb,tb,ub,pb) in rows:
        for (r,ty,u) in ((ra,ta,ua),(rb,tb,ub)):
            if ty=="R" and rname(r,u) not in seen: seen.add(rname(r,u)); routers.append(rname(r,u))
    cs=[(ra,ua,rb,ub,pb) for (ra,ta,ua,pa,ln,rb,tb,ub,pb) in rows if ta=="C" and tb=="R"]
    first_c=cs[0]; mname=master or rname(first_c[2],first_c[3])
    routers=[mname]+[x for x in routers if x!=mname]
    h0=t.add_hub(0x1000); ridx={}
    ridx[mname]=t.add_router(0x5000,role=roles.get(mname,0))
    for i,r in enumerate(routers[1:]): ridx[r]=t.add_router(0x5001+i,role=roles.get(r,0))
    hubs=[(h0,rname(first_c[2],first_c[3]),int(first_c[4]))]
    t.link_hr(h0,ridx[rname(first_c[2],first_c[3])],int(first_c[4]))
    for k,(ra,ua,rb,ub,pb) in enumerate(cs[1:]):
        h=t.add_hub(0x1001+k); rn=rname(rb,ub); t.link_hr(h,ridx[rn],int(pb)); hubs.append((h,rn,int(pb)))
    links=[]
    for (ra,ta,ua,pa,ln,rb,tb,ub,pb) in rows:
        if ta=="R" and tb=="R":
            t.link_rr(ridx[rname(ra,ua)],int(pa),ridx[rname(rb,ub)],int(pb)); links.append((rname(ra,ua),int(pa),rname(rb,ub),int(pb)))
    return rp,t,ridx,h0,hubs,links
_orig_bi=build_image
def build_image2():
    import struct
    d=bytearray(_orig_bi())
    o=0x1fc6b5d0-0x1fc00000
    d[o:o+8]=struct.pack(">II",0x03e00008,0x24020000)   # jr ra ; li v0,0   (local NASID read)
    o=0x1fc697ec-0x1fc00000
    d[o:o+12]=struct.pack('>III',0xA0C00000,0x03e00008,0x2402ffff)   # getenv(): empty value, return -1
    return bytes(d)
build_image=build_image2

def nib(word,i): return (word>>(4*i))&0xf
def sim(rp,t,ridx,hubs,links):
    """Forward every hub pair by the look-ahead rule (turn for the next element comes from the previous element's table)
    using the tables the PROM wrote.  Returns a Counter of outcomes and the longest router path."""
    adj={}
    for (a,pa,b,pb) in links: adj[(a,pa)]=('R',b,pb); adj[(b,pb)]=('R',a,pa)
    for (h,rn,p) in hubs: adj[(rn,p)]=('H',h,1)
    def hubtab(h,D):
        o=t.ent(h)+0x20
        return rp.r32(o+0x28+4*(D&0x7f)) if (D>>7)==(t.number(h)>>7) else rp.r32(o+0x228+4*(D>>7))
    def rtab(rn,D):
        i=ridx[rn]; o=t.ent(i)+0x20; fl=rp.r8(o+0x24); num=t.number(i)
        if (D>>7)==(num>>7) or fl: return rp.r32(o+0xa4+4*(D&0x7f))&0xffffffff
        return rp.r32(o+0x2a4+4*(D>>7))&0xffffffff
    hub_by_nasid={t.number(h):h for h,rn,p in hubs}
    hist=collections.Counter(); maxh=0; bad=[]; paths=collections.Counter()
    for (hs,rs,ps) in hubs:
        for nd,hd in hub_by_nasid.items():
            if hd==hs: continue
            turn=hubtab(hs,nd)&0xffffffff
            cur=rs; entry=ps; hops=0; res="ok"
            while True:
                if turn>7: res="unset turn at %s"%("first router" if hops==0 else "router"); break
                hops+=1
                if hops>40: res="loop"; break
                ex=((entry-1+turn)%8)+1
                nb=adj.get((cur,ex))
                if nb is None: res="unwired exit"; break
                if nb[0]=='H':
                    res="ok" if nb[1]==hd else "wrong hub"; break
                turn=nib(rtab(cur,nd),entry-1); cur=nb[1]; entry=nb[2]
            hist[res]+=1
            if res=="ok": maxh=max(maxh,hops); paths[hops]+=1
            elif len(bad)<3: bad.append((hs,nd,res))
    return hist,maxh,dict(sorted(paths.items())),bad

def call2(self,func,args,maxinsn=3_000_000_000):
    uc=self.uc; sp=K0|STACK; uc.reg_write(UC_MIPS_REG_SP,sp)
    for r,a in zip((UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_A2,UC_MIPS_REG_A3),args): uc.reg_write(r,a)
    sentinel=K0|(IMG+0x1ffff0); uc.reg_write(UC_MIPS_REG_RA,sentinel)
    try: uc.emu_start(K0|func,sentinel,count=maxinsn)
    except UcError as e: self.out.append("EMU ERROR %s pc=%x last=%x"%(e,uc.reg_read(UC_MIPS_REG_PC),self.last))
    self.finished = (uc.reg_read(UC_MIPS_REG_PC)==sentinel)
    return uc.reg_read(UC_MIPS_REG_V0)
Replay.call=call2

# distribution stubs: vector write (0x1fc5ce88) records, vector read (0x1fc5cf3c) returns 0, timeout setters no-op
_bi2=build_image
def build_image3():
    import struct
    d=bytearray(_bi2())
    def put(a,*w): d[a-0x1fc00000:a-0x1fc00000+4*len(w)]=struct.pack(">%dI"%len(w),*w)
    put(0x1fc5ce88,0x03e00008,0x24020000)
    put(0x1fc5cf3c,0xfce00000,0x03e00008,0x24020000)   # sd $0,0($7); jr ra; li v0,0
    put(0x1fc52800,0x03e00008,0x24020000)
    put(0x1fc5d03c,0x0000c025)   # lwu $24,68($5) -> or $24,$0,$0 (save of local hub table; hub registers unmapped)
    put(0x1fc5d06c,0x0000f825)   # lwu $31,584($19) likewise
    put(0x1fc5d044,0)            # sd $24,4088($6): local hub table store, hub register space unmapped
    put(0x1fc530a8,0x3c15a800)   # route cache base: 0x96.. window is not a valid xkphys address for Unicorn; use 0xa8..
    put(0x1fc530b0,0x0015a83c)
    put(0x1fc5d074,0)            # sd $31,8192($4): meta entry 0 store likewise
    put(0x1fc527dc,0x03e00008,0x24020000)
    return bytes(d)
build_image=build_image3
VW=[]
_oldinit=Replay.__init__
def _init(self,*a,**k):
    _oldinit(self,*a,**k)
    self.stubs[0x1fc5ce88]=lambda pc: VW.append((self.uc.reg_read(UC_MIPS_REG_A1),self.uc.reg_read(UC_MIPS_REG_A2),self.uc.reg_read(UC_MIPS_REG_A3)&0xffffffffffffffff))
Replay.__init__=_init

def roles_for(rows, rep_role=3, meta_role=1):
    adj=collections.defaultdict(set)
    for (ra,ta,ua,pa,ln,rb,tb,ub,pb) in rows:
        if ta=="R" and tb=="R":
            a=f"{ra}r{ua}";b=f"{rb}r{ub}"; adj[a].add(b);adj[b].add(a)
    roles={}
    for r,nb in adj.items():
        if r.endswith("r38"):
            roles[r]= meta_role if any(not x.endswith("r38") for x in nb) else rep_role
    return roles
def trial(k,rep_role=3,meta_role=1,quiet=False,roles=None):
    rows=T[k]["rows"]
    roles=roles if roles is not None else roles_for(rows,rep_role,meta_role)
    rp,t,ridx,h0,hubs,links=build(rows,roles)
    r=run(rp,t,h0)
    walk=[l for l in rp.out if not l.startswith(("ring","a0-a3"))]
    nums={n:t.number(i) for n,i in ridx.items()}
    unn=[n for n,v in nums.items() if v==-1]
    hubn=[t.number(h) for h,_,_ in hubs]
    print(k,T[k]["procs"],"walk: routers",len(nums),"unnumbered",len(unn),"hubs",len(hubs),"hubnums",min(hubn),max(hubn),"distinct hubs",len(set(hubn)))
    errs=[l for l in walk if 'rror' in l or 'xpress' in l or 'expected' in l or 'EMU' in l]
    print("  walk errs:",errs[:4], "n=",len(errs))
    print("  nlocal/depth lines:",[l for l in walk if 'nlocal' in l or 'ftdepth' in l or 'depth' in l][:6])
    rc=r&0xffffffff; rc-= (1<<32) if rc>>31 else 0
    print("  number calc returned",rc)
    if rc!=0:
        print("  number calc failed: route calculation not run"); return rp,t,ridx,h0,hubs,links,nums
    rp.out.clear()
    r2=rp.call(0x1fc5d450,[K0|t.base]); rc2=r2&0xffffffff; rc2-=(1<<32) if rc2>>31 else 0
    rl=[l for l in rp.out if not l.startswith(("ring","a0-a3"))]
    print("  route calc returned",rc2,"messages",len(rl),collections.Counter(l[:50] for l in rl).most_common(4))
    if not quiet: print("  forwarding:",sim(rp,t,ridx,hubs,links))
    return rp,t,ridx,h0,hubs,links,nums

def mk(full,partial,inter):
    rows=[]
    def R(a,ua,pa,b,ub,pb): rows.append((a,"R",str(ua),str(pa),"1",b,"R",str(ub),str(pb)))
    def Cc(r,u,rr_,ur,p): rows.append((r,"C",str(u),"Link","1",rr_,"R",str(ur),str(p)))
    for r in full+partial:
        for u,p in zip((10,13,16,21),(2,3,4,5)): Cc(r,u,r,19,p)
    for r in full:
        for u,p in zip((24,29,32,35),(2,3,4,5)): Cc(r,u,r,27,p)
        R(r,19,1,r,27,1); R(r,19,6,r,27,6)
    for (a,pa,b,pb) in inter:
        ra,ua=a.split("R"); rb,ub=b.split("R"); R(ra,ua,pa,rb,ub,pb)
    return rows
S={
 "32p":(["001"],[],[]),
 "48p":(["001"],["002"],[("001R19",7,"002R19",7),("001R19",8,"002R19",8),("001R27",7,"002R19",1),("001R27",8,"002R19",6)]),
 "64p":(["001","002"],[],[("001R19",7,"002R19",7),("001R19",8,"002R27",8),("001R27",7,"002R27",7),("001R27",8,"002R19",8)]),
 "80p":(["001","002"],["003"],[("001R19",7,"002R19",7),("001R19",8,"003R19",8),("001R27",7,"002R27",7),("001R27",8,"003R19",6),("002R19",8,"003R19",7),("002R27",8,"003R19",1)]),
 "96p":(["001","002","003"],[],[("001R19",7,"002R19",7),("001R27",7,"002R27",7),("002R19",8,"003R19",7),("002R27",8,"003R27",7),("003R19",8,"001R19",8),("003R27",8,"001R27",8)]),
 "112p std":(["001","002","003"],["004"],[("001R19",7,"002R19",7),("001R19",8,"003R19",8),("001R27",7,"002R27",7),("001R27",8,"003R27",8),("002R19",8,"004R19",8),("002R27",8,"004R19",6),("003R19",7,"004R19",7),("003R27",7,"004R19",1)]),
 "112p alt":(["001","002","004"],["003"],[("001R19",7,"002R19",7),("001R19",8,"003R19",8),("001R27",7,"002R27",7),("001R27",8,"003R19",6),("002R19",8,"004R19",8),("002R27",8,"004R27",8),("003R19",1,"004R27",7),("003R19",7,"004R19",7)]),
 "128p":(["001","002","003","004"],[],[("001R19",7,"002R19",7),("001R19",8,"003R19",8),("001R27",7,"002R27",7),("001R27",8,"003R27",8),("002R19",8,"004R19",8),("002R27",8,"004R27",8),("003R19",7,"004R19",7),("003R27",7,"004R27",7)]),
}

S={
 "32p":(["001"],[],[]),
 "48p":(["001"],["002"],[("001R19",7,"002R19",7),("001R19",8,"002R19",8),("001R27",7,"002R19",1),("001R27",8,"002R19",6)]),
 "64p":(["001","002"],[],[("001R19",7,"002R19",7),("001R19",8,"002R27",8),("001R27",7,"002R27",7),("001R27",8,"002R19",8)]),
 "80p":(["001","002"],["003"],[("001R19",7,"002R19",7),("001R19",8,"003R19",8),("001R27",7,"002R27",7),("001R27",8,"003R19",6),("002R19",8,"003R19",7),("002R27",8,"003R19",1)]),
 "96p":(["001","002","003"],[],[("001R19",7,"002R19",7),("001R27",7,"002R27",7),("002R19",8,"003R19",7),("002R27",8,"003R27",7),("003R19",8,"001R19",8),("003R27",8,"001R27",8)]),
 "112p-std":(["001","002","003"],["004"],[("001R19",7,"002R19",7),("001R19",8,"003R19",8),("001R27",7,"002R27",7),("001R27",8,"003R27",8),("002R19",8,"004R19",8),("002R27",8,"004R19",6),("003R19",7,"004R19",7),("003R27",7,"004R19",1)]),
 "112p-alt":(["001","002","004"],["003"],[("001R19",7,"002R19",7),("001R19",8,"003R19",8),("001R27",7,"002R27",7),("001R27",8,"003R19",6),("002R19",8,"004R19",8),("002R27",8,"004R27",8),("003R19",1,"004R27",7),("003R19",7,"004R19",7)]),
 "128p":(["001","002","003","004"],[],[("001R19",7,"002R19",7),("001R19",8,"003R19",8),("001R27",7,"002R27",7),("001R27",8,"003R27",8),("002R19",8,"004R19",8),("002R27",8,"004R27",8),("003R19",7,"004R19",7),("003R27",7,"004R27",7)]),
}
T={}

if __name__=="__main__":
    args=sys.argv[1:]
    if not args: sys.exit(__doc__)
    cab=os.environ.get("CABLING_TEXT")
    for a in args:
        if a.startswith("3600:"):
            f,p,i=S[a[5:]]; T[a]={"procs":0,"rows":mk(f,p,i)}; key=a; roles={}
        else:
            if cab and not any(isinstance(k,int) for k in T): T.update(parse(cab))
            key=int(a); roles=roles_for(T[key]["rows"],rep_role=int(os.environ.get("REP_ROLE",3)),meta_role=int(os.environ.get("META_ROLE",1)))
        t0=time.time(); print("==",a,flush=True)
        res=trial(key,roles=roles if roles is not None else None)
        print("  finished",res[0].finished,"secs",round(time.time()-t0),flush=True)
