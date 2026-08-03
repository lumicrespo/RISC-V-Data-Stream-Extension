int main(void)
{
    register long *p asm("a0") = 0;
    register long  sd_i asm("a1");
    register float sd_f asm("ft0");

register long d0 asm("a2") = 64;
    register long d1 asm("a3") = 8;
    register long d2 asm("a4") = 4;
    register long d3 asm("a5") = 2;

    asm volatile(
        //==========================================================
        // Integer Streams
        //==========================================================

        "ss.sta.i.ld.w      a1, a0\n\t"
        "ss.app.i           a1, a2, a3, a4\n\t"
        "ss.end.i           a1, a2, a3, a4\n\t"

        "ss.sta.i.st.d      a1, a0\n\t"
        "ss.app.i           a1, a2, a3, a4\n\t"
        "ss.app.i           a1, a3, a4, a5\n\t"
        "ss.end.i           a1, a2, a3, a4\n\t"

        //==========================================================
        // Floating-point Streams
        //==========================================================

        "ss.sta.f.ld.d      ft0, a0\n\t"
        "ss.app.f           ft0, a2, a3, a4\n\t"
        "ss.end.f           ft0, a2, a3, a4\n\t"

        "ss.sta.f.st.b      ft0, a0\n\t"
        "ss.app.f           ft0, a2, a3, a4\n\t"
        "ss.app.f           ft0, a3, a4, a5\n\t"
        "ss.end.f           ft0, a2, a3, a4\n\t"

        //==========================================================
        // Vector Streams (1 dimension)
        //==========================================================

        "ss.sta.v.ld.w.1        v0, a0\n\t"
        "ss.app.v               v0, a2, a3, a4\n\t"
        "ss.end.v               v0, a2, a3, a4\n\t"

        //==========================================================
        // Vector Streams (2 dimensions)
        //==========================================================

        "ss.sta.v.ld.w.2.unm    v0, a0\n\t"
        "ss.app.v               v0, a2, a3, a4\n\t"
        "ss.app.v               v0, a3, a4, a5\n\t"
        "ss.end.v               v0, a2, a3, a4\n\t"

        //==========================================================
        // Vector Streams (3 dimensions)
        //==========================================================

        "ss.sta.v.st.h.2.indx   v0, a0\n\t"
        "ss.app.v               v0, a2, a3, a4\n\t"
        "ss.app.v               v0, a3, a4, a5\n\t"
        "ss.end.v               v0, a2, a3, a4\n\t"
        
        //==========================================================
        // Vector Streams (4 dimensions)
        //==========================================================

        "ss.sta.v.st.d.unm      v0, a0\n\t"
        "ss.app.v               v0, a2, a3, a4\n\t"
        "ss.app.v               v0, a3, a4, a5\n\t"
        "ss.app.v               v0, a4, a5, a2\n\t"
        "ss.end.v               v0, a2, a3, a4\n\t"

        //==========================================================
        // Integer Static Modifiers
        //==========================================================

        "ss.app.i.mod.ofs.inc.1 a1, a2\n\t"
        "ss.app.i.mod.ofs.dec.2 a1, a3\n\t"
        "ss.app.i.mod.str.inc.3 a1, a4\n\t"
        "ss.app.i.mod.str.dec.l a1, a5\n\t"
        "ss.app.i.mod.siz.inc.1 a1, a2\n\t"
        "ss.app.i.mod.siz.dec.l a1, a3\n\t"

        //==========================================================
        // Floating-point Static Modifiers
        //==========================================================

        "ss.app.f.mod.ofs.inc.1 ft0, a2\n\t"
        "ss.app.f.mod.ofs.dec.2 ft0, a3\n\t"
        "ss.app.f.mod.str.inc.3 ft0, a4\n\t"
        "ss.app.f.mod.str.dec.l ft0, a5\n\t"
        "ss.app.f.mod.siz.inc.1 ft0, a2\n\t"
        "ss.app.f.mod.siz.dec.l ft0, a3\n\t"

        //==========================================================
        // Vector Static Modifiers
        //==========================================================

        "ss.app.v.mod.ofs.inc.1 v0, a2\n\t"
        "ss.app.v.mod.ofs.dec.2 v0, a3\n\t"
        "ss.app.v.mod.str.inc.3 v0, a4\n\t"
        "ss.app.v.mod.str.dec.l v0, a5\n\t"
        "ss.app.v.mod.siz.inc.1 v0, a2\n\t"
        "ss.app.v.mod.siz.dec.l v0, a3\n\t"

        //==========================================================
        // Integer Dynamic Modifiers
        //==========================================================

        "ss.app.i.ind.ofs.inc.1 a1, a2\n\t"
        "ss.app.i.ind.ofs.dec.2 a1, a3\n\t"
        "ss.app.i.ind.ofs.add.3 a1, a4\n\t"
        "ss.app.i.ind.ofs.sub.l a1, a5\n\t"
        "ss.app.i.ind.ofs.set.1 a1, a2\n\t"

        "ss.app.i.ind.str.inc.2 a1, a3\n\t"
        "ss.app.i.ind.str.dec.3 a1, a4\n\t"
        "ss.app.i.ind.str.add.l a1, a5\n\t"
        "ss.app.i.ind.str.sub.1 a1, a2\n\t"
        "ss.app.i.ind.str.set.2 a1, a3\n\t"

        "ss.app.i.ind.siz.inc.3 a1, a4\n\t"
        "ss.app.i.ind.siz.dec.l a1, a5\n\t"
        "ss.app.i.ind.siz.add.1 a1, a2\n\t"
        "ss.app.i.ind.siz.sub.2 a1, a3\n\t"
        "ss.app.i.ind.siz.set.3 a1, a4\n\t"

        //==========================================================
        // Floating-point Dynamic Modifiers
        //==========================================================

        "ss.app.f.ind.ofs.inc.1 ft0, a2\n\t"
        "ss.app.f.ind.ofs.dec.2 ft0, a3\n\t"
        "ss.app.f.ind.ofs.add.3 ft0, a4\n\t"
        "ss.app.f.ind.ofs.sub.l ft0, a5\n\t"
        "ss.app.f.ind.ofs.set.1 ft0, a2\n\t"

        "ss.app.f.ind.str.inc.2 ft0, a3\n\t"
        "ss.app.f.ind.str.dec.3 ft0, a4\n\t"
        "ss.app.f.ind.str.add.l ft0, a5\n\t"
        "ss.app.f.ind.str.sub.1 ft0, a2\n\t"
        "ss.app.f.ind.str.set.2 ft0, a3\n\t"

        "ss.app.f.ind.siz.inc.3 ft0, a4\n\t"
        "ss.app.f.ind.siz.dec.l ft0, a5\n\t"
        "ss.app.f.ind.siz.add.1 ft0, a2\n\t"
        "ss.app.f.ind.siz.sub.2 ft0, a3\n\t"
        "ss.app.f.ind.siz.set.3 ft0, a4\n\t"

        //==========================================================
        // Vector Dynamic Modifiers
        //==========================================================

        "ss.app.v.ind.ofs.inc.1 v0, a2\n\t"
        "ss.app.v.ind.ofs.dec.2 v0, a3\n\t"
        "ss.app.v.ind.ofs.add.3 v0, a4\n\t"
        "ss.app.v.ind.ofs.sub.l v0, a5\n\t"
        "ss.app.v.ind.ofs.set.1 v0, a2\n\t"

        "ss.app.v.ind.str.inc.2 v0, a3\n\t"
        "ss.app.v.ind.str.dec.3 v0, a4\n\t"
        "ss.app.v.ind.str.add.l v0, a5\n\t"
        "ss.app.v.ind.str.sub.1 v0, a2\n\t"
        "ss.app.v.ind.str.set.2 v0, a3\n\t"

        "ss.app.v.ind.siz.inc.3 v0, a4\n\t"
        "ss.app.v.ind.siz.dec.l v0, a5\n\t"
        "ss.app.v.ind.siz.add.1 v0, a2\n\t"
        "ss.app.v.ind.siz.sub.2 v0, a3\n\t"
        "ss.app.v.ind.siz.set.3 v0, a4\n\t"

        //==========================================================
        // Integer Scatter-Gather Indirect Modifiers
        //==========================================================

        "ss.end.i.sgi.inc a1, a2\n\t"
        "ss.end.i.sgi.dec a1, a2\n\t"
        "ss.end.i.sgi.add a1, a2\n\t"
        "ss.end.i.sgi.sub a1, a2\n\t"
        "ss.end.i.sgi.set a1, a2\n\t"

        //==========================================================
        // Floating-point Scatter-Gather Indirect Modifiers
        //==========================================================

        "ss.end.f.sgi.inc ft0, a2\n\t"
        "ss.end.f.sgi.dec ft0, a2\n\t"
        "ss.end.f.sgi.add ft0, a2\n\t"
        "ss.end.f.sgi.sub ft0, a2\n\t"
        "ss.end.f.sgi.set ft0, a2\n\t"

        //==========================================================
        // Vector Scatter-Gather Indirect Modifiers
        //==========================================================

        "ss.end.v.sgi.inc v0, v1\n\t"
        "ss.end.v.sgi.dec v0, v1\n\t"
        "ss.end.v.sgi.add v0, v1\n\t"
        "ss.end.v.sgi.sub v0, v1\n\t"
        "ss.end.v.sgi.set v0, v1\n\t"
        :
        : "r"(p), "r"(sd_i), "f"(sd_f),
          "r"(d0), "r"(d1), "r"(d2), "r"(d3)
        : "memory", "v0");

    return 0;
}