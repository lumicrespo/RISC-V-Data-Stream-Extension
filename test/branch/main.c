int main(void) {
  asm volatile(
      ".Loop: \n\t"
      "ss.b.i.c x5, .Loop\n\t"
      "ss.b.i.dc.2 x6, 20\n\t"
      "ss.b.i.nc x7, 24\n\t"

      "ss.b.f.c f3, 16\n\t"
      "ss.b.f.dc.2 f4, 20\n\t"

      "ss.b.v.c v8, 16\n\t"
      "ss.b.v.dc.2 v9, 20\n\t"
  );

  return 0;
}