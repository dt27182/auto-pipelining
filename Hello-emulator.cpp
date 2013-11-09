#include "Hello.h"
int main (int argc, char* argv[]) {
  Hello_t* c = new Hello_t();
  int lim = (argc > 1) ? atoi(argv[1]) : -1;
  int period;
  c->init();
  FILE *f = fopen("Hello.vcd", "w");
  int delta = 0;
  for(int i = 0; i < 5; i++) {
    dat_t<1> reset = LIT<1>(1);
    c->clock_lo(reset);
    c->clock_hi(reset);
  }
  for (int t = 0; lim < 0 || t < lim; t++) {
    dat_t<1> reset = LIT<1>(0);
    if (!c->scan(stdin)) break;
    c->clock_lo(reset);
    c->print(stdout);
    c->dump(f, t);
    c->clock_hi(reset);
    c->clock_hi(reset);
  }
}
