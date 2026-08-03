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
        :
        : "r"(p), "r"(sd_i), "f"(sd_f),
          "r"(d0), "r"(d1), "r"(d2), "r"(d3)
        : "memory", "v0");

    return 0;
}