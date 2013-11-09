#include "Hello.h"

void Hello_t::init ( bool rand_init ) {
  if (rand_init) Hello_regfile__mem.randomize();
  if (rand_init) Hello_imem__imem_7.randomize();
  if (rand_init) Hello_imem__imem_6.randomize();
  if (rand_init) Hello_imem__imem_5.randomize();
  if (rand_init) Hello_imem__imem_4.randomize();
  if (rand_init) Hello_imem__imem_3.randomize();
  if (rand_init) Hello_imem__imem_2.randomize();
  if (rand_init) Hello_imem__imem_1.randomize();
  if (rand_init) Hello_imem__imem_0.randomize();
  if (rand_init) R52.randomize();
  if (rand_init) R54.randomize();
  if (rand_init) R61.randomize();
  if (rand_init) Hello__pc_reg.randomize();
  if (rand_init) R71.randomize();
}
void Hello_t::clock_lo ( dat_t<1> reset ) {
  { Hello__Huy_1_.values[0] = R71.values[0]; }
  { Hello__Huy_0_.values[0] = R61.values[0]; }
  { T0.values[0] = Hello__Huy_0_.values[0]+Hello__Huy_1_.values[0]; }
  T0.values[0] = T0.values[0] & 4294967295;
  { Hello__adder_out.values[0] = T0.values[0]; }
  { Hello__Huy_2_.values[0] = R54.values[0]; }
  { val_t __mask = -Hello__Huy_2_.values[0]; T1.values[0] = 0x0L ^ ((0x0L ^ Hello__adder_out.values[0]) & __mask); }
  { Hello_regfile__io_writes_0_dat.values[0] = T1.values[0]; }
  { Hello_imem__mem_addr.values[0] = Hello__pc_reg.values[0]; }
  { T2.values[0] = Hello_imem__mem_addr.values[0]; }
  T2.values[0] = T2.values[0] & 7;
  { T3.values[0] = T2.values[0]; }
  T4.values[0] = (T3.values[0] >> 0) & 1;
  { val_t __mask = -T4.values[0]; T5.values[0] = Hello_imem__imem_0.values[0] ^ ((Hello_imem__imem_0.values[0] ^ Hello_imem__imem_1.values[0]) & __mask); }
  T6.values[0] = (T3.values[0] >> 0) & 1;
  { val_t __mask = -T6.values[0]; T7.values[0] = Hello_imem__imem_2.values[0] ^ ((Hello_imem__imem_2.values[0] ^ Hello_imem__imem_3.values[0]) & __mask); }
  T8.values[0] = (T3.values[0] >> 1) & 1;
  { val_t __mask = -T8.values[0]; T9.values[0] = T5.values[0] ^ ((T5.values[0] ^ T7.values[0]) & __mask); }
  T10.values[0] = (T3.values[0] >> 0) & 1;
  { val_t __mask = -T10.values[0]; T11.values[0] = Hello_imem__imem_4.values[0] ^ ((Hello_imem__imem_4.values[0] ^ Hello_imem__imem_5.values[0]) & __mask); }
  T12.values[0] = (T3.values[0] >> 0) & 1;
  { val_t __mask = -T12.values[0]; T13.values[0] = Hello_imem__imem_6.values[0] ^ ((Hello_imem__imem_6.values[0] ^ Hello_imem__imem_7.values[0]) & __mask); }
  T14.values[0] = (T3.values[0] >> 1) & 1;
  { val_t __mask = -T14.values[0]; T15.values[0] = T11.values[0] ^ ((T11.values[0] ^ T13.values[0]) & __mask); }
  T16.values[0] = (T3.values[0] >> 2) & 1;
  { val_t __mask = -T16.values[0]; T17.values[0] = T9.values[0] ^ ((T9.values[0] ^ T15.values[0]) & __mask); }
  { Hello_imem__io_resp.values[0] = T17.values[0]; }
  { Hello__inst.values[0] = Hello_imem__io_resp.values[0]; }
  { T18.values[0] = Hello__inst.values[0] >> 12; }
  T18.values[0] = T18.values[0] & 7;
  { Hello__op.values[0] = T18.values[0]; }
  T19.values[0] = Hello__op.values[0] == 0x2L;
  T20.values[0] = Hello__op.values[0] == 0x0L;
  { T21.values[0] = T20.values[0]||T19.values[0]; }
  { Hello__adder_sel.values[0] = T21.values[0]; }
  { val_t __mask = -Hello__Huy_2_.values[0]; T22.values[0] = 0x0L ^ ((0x0L ^ Hello__adder_sel.values[0]) & __mask); }
  { Hello_regfile__io_writes_0_is.values[0] = T22.values[0]; }
  { val_t __mask = -Hello_regfile__io_writes_0_is.values[0]; T23.values[0] = 0x0L ^ ((0x0L ^ Hello_regfile__io_writes_0_dat.values[0]) & __mask); }
  { T24.values[0] = Hello__Huy_0_.values[0]-Hello__Huy_1_.values[0]; }
  T24.values[0] = T24.values[0] & 4294967295;
  { Hello__subtract_out.values[0] = T24.values[0]; }
  { Hello__Huy_3_.values[0] = R52.values[0]; }
  { val_t __mask = -Hello__Huy_3_.values[0]; T25.values[0] = 0x0L ^ ((0x0L ^ Hello__subtract_out.values[0]) & __mask); }
  { Hello_regfile__io_writes_1_dat.values[0] = T25.values[0]; }
  T26.values[0] = Hello__op.values[0] == 0x3L;
  T27.values[0] = Hello__op.values[0] == 0x1L;
  { T28.values[0] = T27.values[0]||T26.values[0]; }
  { Hello__subtract_sel.values[0] = T28.values[0]; }
  { val_t __mask = -Hello__Huy_3_.values[0]; T29.values[0] = 0x0L ^ ((0x0L ^ Hello__subtract_sel.values[0]) & __mask); }
  { Hello_regfile__io_writes_1_is.values[0] = T29.values[0]; }
  { val_t __mask = -Hello_regfile__io_writes_1_is.values[0]; T30.values[0] = T23.values[0] ^ ((T23.values[0] ^ Hello_regfile__io_writes_1_dat.values[0]) & __mask); }
  { T31.values[0] = T30.values[0]; }
  { Hello_regfile__datas_0.values[0] = T31.values[0]; }
  { T32.values[0] = Hello_regfile__datas_0.values[0]; }
  { T33.values[0] = Hello_regfile__io_writes_0_is.values[0]||Hello_regfile__io_writes_1_is.values[0]; }
  { Hello_regfile__ens_0.values[0] = T33.values[0]; }
  { T34.values[0] = Hello__inst.values[0]; }
  T34.values[0] = T34.values[0] & 15;
  { Hello__rd.values[0] = T34.values[0]; }
  { val_t __mask = -Hello__Huy_2_.values[0]; T35.values[0] = 0x0L ^ ((0x0L ^ Hello__rd.values[0]) & __mask); }
  { T36.values[0] = T35.values[0]; }
  T36.values[0] = T36.values[0] & 7;
  { Hello_regfile__io_writes_0_adr.values[0] = T36.values[0]; }
  { val_t __mask = -Hello_regfile__io_writes_0_is.values[0]; T37.values[0] = 0x0L ^ ((0x0L ^ Hello_regfile__io_writes_0_adr.values[0]) & __mask); }
  { val_t __mask = -Hello__Huy_3_.values[0]; T38.values[0] = 0x0L ^ ((0x0L ^ Hello__rd.values[0]) & __mask); }
  { T39.values[0] = T38.values[0]; }
  T39.values[0] = T39.values[0] & 7;
  { Hello_regfile__io_writes_1_adr.values[0] = T39.values[0]; }
  { val_t __mask = -Hello_regfile__io_writes_1_is.values[0]; T40.values[0] = T37.values[0] ^ ((T37.values[0] ^ Hello_regfile__io_writes_1_adr.values[0]) & __mask); }
  { T41.values[0] = T40.values[0]; }
  { Hello_regfile__addrs_0.values[0] = T41.values[0]; }
  { Hello_imem__reset.values[0] = reset.values[0]; }
  { val_t __mask = -Hello_imem__reset.values[0]; T43.values[0] = Hello_imem__imem_7.values[0] ^ ((Hello_imem__imem_7.values[0] ^ 0x5000L) & __mask); }
  { Hello_imem__imem_7_shadow.values[0] = T43.values[0]; }
  { val_t __mask = -Hello_imem__reset.values[0]; T44.values[0] = Hello_imem__imem_6.values[0] ^ ((Hello_imem__imem_6.values[0] ^ 0x5000L) & __mask); }
  { Hello_imem__imem_6_shadow.values[0] = T44.values[0]; }
  { val_t __mask = -Hello_imem__reset.values[0]; T45.values[0] = Hello_imem__imem_5.values[0] ^ ((Hello_imem__imem_5.values[0] ^ 0x1203L) & __mask); }
  { Hello_imem__imem_5_shadow.values[0] = T45.values[0]; }
  { val_t __mask = -Hello_imem__reset.values[0]; T46.values[0] = Hello_imem__imem_4.values[0] ^ ((Hello_imem__imem_4.values[0] ^ 0x12L) & __mask); }
  { Hello_imem__imem_4_shadow.values[0] = T46.values[0]; }
  { val_t __mask = -Hello_imem__reset.values[0]; T47.values[0] = Hello_imem__imem_3.values[0] ^ ((Hello_imem__imem_3.values[0] ^ 0x12101L) & __mask); }
  { Hello_imem__imem_3_shadow.values[0] = T47.values[0]; }
  { val_t __mask = -Hello_imem__reset.values[0]; T48.values[0] = Hello_imem__imem_2.values[0] ^ ((Hello_imem__imem_2.values[0] ^ 0xa000L) & __mask); }
  { Hello_imem__imem_2_shadow.values[0] = T48.values[0]; }
  { val_t __mask = -Hello_imem__reset.values[0]; T49.values[0] = Hello_imem__imem_1.values[0] ^ ((Hello_imem__imem_1.values[0] ^ 0x4101L) & __mask); }
  { Hello_imem__imem_1_shadow.values[0] = T49.values[0]; }
  { val_t __mask = -Hello_imem__reset.values[0]; T50.values[0] = Hello_imem__imem_0.values[0] ^ ((Hello_imem__imem_0.values[0] ^ 0x4000L) & __mask); }
  { Hello_imem__imem_0_shadow.values[0] = T50.values[0]; }
  { Hello__subtract_sel_init.values[0] = 0x0L; }
  { val_t __mask = -reset.values[0]; T51.values[0] = Hello__subtract_sel.values[0] ^ ((Hello__subtract_sel.values[0] ^ Hello__subtract_sel_init.values[0]) & __mask); }
  { R52_shadow.values[0] = T51.values[0]; }
  { Hello__adder_sel_init.values[0] = 0x0L; }
  { val_t __mask = -reset.values[0]; T53.values[0] = Hello__adder_sel.values[0] ^ ((Hello__adder_sel.values[0] ^ Hello__adder_sel_init.values[0]) & __mask); }
  { R54_shadow.values[0] = T53.values[0]; }
  { T55.values[0] = Hello__inst.values[0] >> 8; }
  T55.values[0] = T55.values[0] & 15;
  { Hello__rs1.values[0] = T55.values[0]; }
  { T56.values[0] = Hello__rs1.values[0]; }
  T56.values[0] = T56.values[0] & 7;
  { Hello_regfile__io_reads_0_adr.values[0] = T56.values[0]; }
  { T57.values[0] = Hello_regfile__mem.get(Hello_regfile__io_reads_0_adr.values[0], 0); }
  { Hello_regfile__io_reads_0_dat.values[0] = T57.values[0]; }
  { Hello__rs1_data.values[0] = Hello_regfile__io_reads_0_dat.values[0]; }
  T58.values[0] = Hello__op.values[0] == 0x4L;
  { val_t __mask = -T58.values[0]; T59.values[0] = Hello__rs1_data.values[0] ^ ((Hello__rs1_data.values[0] ^ 0x0L) & __mask); }
  { Hello__operand1.values[0] = T59.values[0]; }
  { val_t __mask = -reset.values[0]; T60.values[0] = Hello__operand1.values[0] ^ ((Hello__operand1.values[0] ^ 0x0L) & __mask); }
  { R61_shadow.values[0] = T60.values[0]; }
  { T62.values[0] = Hello__pc_reg.values[0]+0x1L; }
  T62.values[0] = T62.values[0] & 15;
  { Hello__pc_plus4.values[0] = T62.values[0]; }
  { Hello__pc_reg_shadow.values[0] = TERNARY(reset.values[0], 0x0L, Hello__pc_plus4.values[0]); }
  { T63.values[0] = Hello__inst.values[0] >> 4; }
  T63.values[0] = T63.values[0] & 15;
  { Hello__rs2.values[0] = T63.values[0]; }
  { T64.values[0] = Hello__rs2.values[0]; }
  T64.values[0] = T64.values[0] & 7;
  { Hello_regfile__io_reads_1_adr.values[0] = T64.values[0]; }
  { T65.values[0] = Hello_regfile__mem.get(Hello_regfile__io_reads_1_adr.values[0], 0); }
  { Hello_regfile__io_reads_1_dat.values[0] = T65.values[0]; }
  { Hello__rs2_data.values[0] = Hello_regfile__io_reads_1_dat.values[0]; }
  { T66.values[0] = Hello__inst.values[0] >> 15; }
  T66.values[0] = T66.values[0] & 131071;
  { T67.values[0] = T66.values[0] | 0x0L << 17; }
  { Hello__imm.values[0] = T67.values[0]; }
  T68.values[0] = 0x1L<Hello__op.values[0];
  { val_t __mask = -T68.values[0]; T69.values[0] = Hello__rs2_data.values[0] ^ ((Hello__rs2_data.values[0] ^ Hello__imm.values[0]) & __mask); }
  { Hello__operand2.values[0] = T69.values[0]; }
  { val_t __mask = -reset.values[0]; T70.values[0] = Hello__operand2.values[0] ^ ((Hello__operand2.values[0] ^ 0x0L) & __mask); }
  { R71_shadow.values[0] = T70.values[0]; }
  { T72.values[0] = Hello__io_read_addr.values[0]; }
  T72.values[0] = T72.values[0] & 7;
  { Hello_regfile__io_reads_2_adr.values[0] = T72.values[0]; }
  { T73.values[0] = Hello_regfile__mem.get(Hello_regfile__io_reads_2_adr.values[0], 0); }
  { Hello_regfile__io_reads_2_dat.values[0] = T73.values[0]; }
  { Hello__io_read_data.values[0] = Hello_regfile__io_reads_2_dat.values[0]; }
}
void Hello_t::clock_hi ( dat_t<1> reset ) {
  { Hello_regfile__mem.put(Hello_regfile__addrs_0.values[0], 0, (T32.values[0] & (-Hello_regfile__ens_0.values[0])) | (Hello_regfile__mem.get(Hello_regfile__addrs_0.values[0], 0) & ~(-Hello_regfile__ens_0.values[0]))); }
  Hello_imem__imem_7 = Hello_imem__imem_7_shadow;
  Hello_imem__imem_6 = Hello_imem__imem_6_shadow;
  Hello_imem__imem_5 = Hello_imem__imem_5_shadow;
  Hello_imem__imem_4 = Hello_imem__imem_4_shadow;
  Hello_imem__imem_3 = Hello_imem__imem_3_shadow;
  Hello_imem__imem_2 = Hello_imem__imem_2_shadow;
  Hello_imem__imem_1 = Hello_imem__imem_1_shadow;
  Hello_imem__imem_0 = Hello_imem__imem_0_shadow;
  R52 = R52_shadow;
  R54 = R54_shadow;
  R61 = R61_shadow;
  Hello__pc_reg = Hello__pc_reg_shadow;
  R71 = R71_shadow;
}
int Hello_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk_cnt < min) min = clk_cnt;
  clk_cnt-=min;
  if (clk_cnt == 0) clock_lo( reset );
  if (clk_cnt == 0) clock_hi( reset );
  if (clk_cnt == 0) clk_cnt = clk;
  return min;
}
void Hello_t::print ( FILE* f ) {
  fprintf(f, "%s", TO_CSTR(Hello__io_read_data));
  fprintf(f, "\n");
  fflush(f);
}
bool Hello_t::scan ( FILE* f ) {
  str_to_dat(read_tok(f), Hello__io_read_addr);
  return(!feof(f));
}
void Hello_t::dump(FILE *f, int t) {
  if (t == 0) {
    fprintf(f, "$timescale 1ps $end\n");
    fprintf(f, "$scope module Hello $end\n");
    fprintf(f, "$var wire 32 N0 Huy_1_ $end\n");
    fprintf(f, "$var wire 32 N1 Huy_0_ $end\n");
    fprintf(f, "$var wire 32 N2 T0 $end\n");
    fprintf(f, "$var wire 32 N3 adder_out $end\n");
    fprintf(f, "$var wire 1 N4 Huy_2_ $end\n");
    fprintf(f, "$var wire 32 N5 T1 $end\n");
    fprintf(f, "$var wire 32 N25 inst $end\n");
    fprintf(f, "$var wire 3 N26 T18 $end\n");
    fprintf(f, "$var wire 3 N27 op $end\n");
    fprintf(f, "$var wire 1 N28 T19 $end\n");
    fprintf(f, "$var wire 1 N29 T20 $end\n");
    fprintf(f, "$var wire 1 N30 T21 $end\n");
    fprintf(f, "$var wire 1 N31 adder_sel $end\n");
    fprintf(f, "$var wire 1 N32 T22 $end\n");
    fprintf(f, "$var wire 32 N35 T24 $end\n");
    fprintf(f, "$var wire 32 N36 subtract_out $end\n");
    fprintf(f, "$var wire 1 N37 Huy_3_ $end\n");
    fprintf(f, "$var wire 32 N38 T25 $end\n");
    fprintf(f, "$var wire 1 N40 T26 $end\n");
    fprintf(f, "$var wire 1 N41 T27 $end\n");
    fprintf(f, "$var wire 1 N42 T28 $end\n");
    fprintf(f, "$var wire 1 N43 subtract_sel $end\n");
    fprintf(f, "$var wire 1 N44 T29 $end\n");
    fprintf(f, "$var wire 4 N52 T34 $end\n");
    fprintf(f, "$var wire 4 N53 rd $end\n");
    fprintf(f, "$var wire 4 N54 T35 $end\n");
    fprintf(f, "$var wire 3 N55 T36 $end\n");
    fprintf(f, "$var wire 4 N58 T38 $end\n");
    fprintf(f, "$var wire 3 N59 T39 $end\n");
    fprintf(f, "$var wire 1 N65 reset $end\n");
    fprintf(f, "$var wire 1 N83 subtract_sel_init $end\n");
    fprintf(f, "$var wire 1 N84 T51 $end\n");
    fprintf(f, "$var wire 1 N85 R52 $end\n");
    fprintf(f, "$var wire 1 N86 adder_sel_init $end\n");
    fprintf(f, "$var wire 1 N87 T53 $end\n");
    fprintf(f, "$var wire 1 N88 R54 $end\n");
    fprintf(f, "$var wire 4 N89 T55 $end\n");
    fprintf(f, "$var wire 4 N90 rs1 $end\n");
    fprintf(f, "$var wire 3 N91 T56 $end\n");
    fprintf(f, "$var wire 32 N95 rs1_data $end\n");
    fprintf(f, "$var wire 1 N96 T58 $end\n");
    fprintf(f, "$var wire 32 N97 T59 $end\n");
    fprintf(f, "$var wire 32 N98 operand1 $end\n");
    fprintf(f, "$var wire 32 N99 T60 $end\n");
    fprintf(f, "$var wire 32 N100 R61 $end\n");
    fprintf(f, "$var wire 4 N101 T62 $end\n");
    fprintf(f, "$var wire 4 N102 pc_plus4 $end\n");
    fprintf(f, "$var wire 4 N103 pc_reg $end\n");
    fprintf(f, "$var wire 4 N104 T63 $end\n");
    fprintf(f, "$var wire 4 N105 rs2 $end\n");
    fprintf(f, "$var wire 3 N106 T64 $end\n");
    fprintf(f, "$var wire 32 N110 rs2_data $end\n");
    fprintf(f, "$var wire 17 N111 T66 $end\n");
    fprintf(f, "$var wire 32 N112 T67 $end\n");
    fprintf(f, "$var wire 32 N113 imm $end\n");
    fprintf(f, "$var wire 1 N114 T68 $end\n");
    fprintf(f, "$var wire 32 N115 T69 $end\n");
    fprintf(f, "$var wire 32 N116 operand2 $end\n");
    fprintf(f, "$var wire 32 N117 T70 $end\n");
    fprintf(f, "$var wire 32 N118 R71 $end\n");
    fprintf(f, "$var wire 4 N119 io_read_addr $end\n");
    fprintf(f, "$var wire 3 N120 T72 $end\n");
    fprintf(f, "$var wire 32 N124 io_read_data $end\n");
    fprintf(f, "$scope module imem $end\n");
    fprintf(f, "$var wire 4 N7 mem_addr $end\n");
    fprintf(f, "$var wire 3 N8 T2 $end\n");
    fprintf(f, "$var wire 3 N9 T3 $end\n");
    fprintf(f, "$var wire 1 N10 T4 $end\n");
    fprintf(f, "$var wire 32 N11 T5 $end\n");
    fprintf(f, "$var wire 1 N12 T6 $end\n");
    fprintf(f, "$var wire 32 N13 T7 $end\n");
    fprintf(f, "$var wire 1 N14 T8 $end\n");
    fprintf(f, "$var wire 32 N15 T9 $end\n");
    fprintf(f, "$var wire 1 N16 T10 $end\n");
    fprintf(f, "$var wire 32 N17 T11 $end\n");
    fprintf(f, "$var wire 1 N18 T12 $end\n");
    fprintf(f, "$var wire 32 N19 T13 $end\n");
    fprintf(f, "$var wire 1 N20 T14 $end\n");
    fprintf(f, "$var wire 32 N21 T15 $end\n");
    fprintf(f, "$var wire 1 N22 T16 $end\n");
    fprintf(f, "$var wire 32 N23 T17 $end\n");
    fprintf(f, "$var wire 32 N24 io_resp $end\n");
    fprintf(f, "$var wire 1 N66 reset $end\n");
    fprintf(f, "$var wire 32 N67 T43 $end\n");
    fprintf(f, "$var wire 32 N68 imem_7 $end\n");
    fprintf(f, "$var wire 32 N69 T44 $end\n");
    fprintf(f, "$var wire 32 N70 imem_6 $end\n");
    fprintf(f, "$var wire 32 N71 T45 $end\n");
    fprintf(f, "$var wire 32 N72 imem_5 $end\n");
    fprintf(f, "$var wire 32 N73 T46 $end\n");
    fprintf(f, "$var wire 32 N74 imem_4 $end\n");
    fprintf(f, "$var wire 32 N75 T47 $end\n");
    fprintf(f, "$var wire 32 N76 imem_3 $end\n");
    fprintf(f, "$var wire 32 N77 T48 $end\n");
    fprintf(f, "$var wire 32 N78 imem_2 $end\n");
    fprintf(f, "$var wire 32 N79 T49 $end\n");
    fprintf(f, "$var wire 32 N80 imem_1 $end\n");
    fprintf(f, "$var wire 32 N81 T50 $end\n");
    fprintf(f, "$var wire 32 N82 imem_0 $end\n");
    fprintf(f, "$upscope $end\n");
    fprintf(f, "$scope module regfile $end\n");
    fprintf(f, "$var wire 32 N6 io_writes_0_dat $end\n");
    fprintf(f, "$var wire 1 N33 io_writes_0_is $end\n");
    fprintf(f, "$var wire 32 N34 T23 $end\n");
    fprintf(f, "$var wire 32 N39 io_writes_1_dat $end\n");
    fprintf(f, "$var wire 1 N45 io_writes_1_is $end\n");
    fprintf(f, "$var wire 32 N46 T30 $end\n");
    fprintf(f, "$var wire 32 N47 T31 $end\n");
    fprintf(f, "$var wire 32 N48 datas_0 $end\n");
    fprintf(f, "$var wire 32 N49 T32 $end\n");
    fprintf(f, "$var wire 1 N50 T33 $end\n");
    fprintf(f, "$var wire 1 N51 ens_0 $end\n");
    fprintf(f, "$var wire 3 N56 io_writes_0_adr $end\n");
    fprintf(f, "$var wire 3 N57 T37 $end\n");
    fprintf(f, "$var wire 3 N60 io_writes_1_adr $end\n");
    fprintf(f, "$var wire 3 N61 T40 $end\n");
    fprintf(f, "$var wire 3 N62 T41 $end\n");
    fprintf(f, "$var wire 3 N63 addrs_0 $end\n");
    fprintf(f, "$var wire 32 N64 T42 $end\n");
    fprintf(f, "$var wire 3 N92 io_reads_0_adr $end\n");
    fprintf(f, "$var wire 32 N93 T57 $end\n");
    fprintf(f, "$var wire 32 N94 io_reads_0_dat $end\n");
    fprintf(f, "$var wire 3 N107 io_reads_1_adr $end\n");
    fprintf(f, "$var wire 32 N108 T65 $end\n");
    fprintf(f, "$var wire 32 N109 io_reads_1_dat $end\n");
    fprintf(f, "$var wire 3 N121 io_reads_2_adr $end\n");
    fprintf(f, "$var wire 32 N122 T73 $end\n");
    fprintf(f, "$var wire 32 N123 io_reads_2_dat $end\n");
    fprintf(f, "$upscope $end\n");
    fprintf(f, "$upscope $end\n");
    fprintf(f, "$enddefinitions $end\n");
    fprintf(f, "$dumpvars\n");
    fprintf(f, "$end\n");
  }
  fprintf(f, "#%d\n", t);
  if (t == 0 || (Hello__Huy_1_ != Hello__Huy_1___prev).to_bool())
    dat_dump(f, Hello__Huy_1_, "N0");
  Hello__Huy_1___prev = Hello__Huy_1_;
  if (t == 0 || (Hello__Huy_0_ != Hello__Huy_0___prev).to_bool())
    dat_dump(f, Hello__Huy_0_, "N1");
  Hello__Huy_0___prev = Hello__Huy_0_;
  if (t == 0 || (T0 != T0__prev).to_bool())
    dat_dump(f, T0, "N2");
  T0__prev = T0;
  if (t == 0 || (Hello__adder_out != Hello__adder_out__prev).to_bool())
    dat_dump(f, Hello__adder_out, "N3");
  Hello__adder_out__prev = Hello__adder_out;
  if (t == 0 || (Hello__Huy_2_ != Hello__Huy_2___prev).to_bool())
    dat_dump(f, Hello__Huy_2_, "N4");
  Hello__Huy_2___prev = Hello__Huy_2_;
  if (t == 0 || (T1 != T1__prev).to_bool())
    dat_dump(f, T1, "N5");
  T1__prev = T1;
  if (t == 0 || (Hello_regfile__io_writes_0_dat != Hello_regfile__io_writes_0_dat__prev).to_bool())
    dat_dump(f, Hello_regfile__io_writes_0_dat, "N6");
  Hello_regfile__io_writes_0_dat__prev = Hello_regfile__io_writes_0_dat;
  if (t == 0 || (Hello_imem__mem_addr != Hello_imem__mem_addr__prev).to_bool())
    dat_dump(f, Hello_imem__mem_addr, "N7");
  Hello_imem__mem_addr__prev = Hello_imem__mem_addr;
  if (t == 0 || (T2 != T2__prev).to_bool())
    dat_dump(f, T2, "N8");
  T2__prev = T2;
  if (t == 0 || (T3 != T3__prev).to_bool())
    dat_dump(f, T3, "N9");
  T3__prev = T3;
  if (t == 0 || (T4 != T4__prev).to_bool())
    dat_dump(f, T4, "N10");
  T4__prev = T4;
  if (t == 0 || (T5 != T5__prev).to_bool())
    dat_dump(f, T5, "N11");
  T5__prev = T5;
  if (t == 0 || (T6 != T6__prev).to_bool())
    dat_dump(f, T6, "N12");
  T6__prev = T6;
  if (t == 0 || (T7 != T7__prev).to_bool())
    dat_dump(f, T7, "N13");
  T7__prev = T7;
  if (t == 0 || (T8 != T8__prev).to_bool())
    dat_dump(f, T8, "N14");
  T8__prev = T8;
  if (t == 0 || (T9 != T9__prev).to_bool())
    dat_dump(f, T9, "N15");
  T9__prev = T9;
  if (t == 0 || (T10 != T10__prev).to_bool())
    dat_dump(f, T10, "N16");
  T10__prev = T10;
  if (t == 0 || (T11 != T11__prev).to_bool())
    dat_dump(f, T11, "N17");
  T11__prev = T11;
  if (t == 0 || (T12 != T12__prev).to_bool())
    dat_dump(f, T12, "N18");
  T12__prev = T12;
  if (t == 0 || (T13 != T13__prev).to_bool())
    dat_dump(f, T13, "N19");
  T13__prev = T13;
  if (t == 0 || (T14 != T14__prev).to_bool())
    dat_dump(f, T14, "N20");
  T14__prev = T14;
  if (t == 0 || (T15 != T15__prev).to_bool())
    dat_dump(f, T15, "N21");
  T15__prev = T15;
  if (t == 0 || (T16 != T16__prev).to_bool())
    dat_dump(f, T16, "N22");
  T16__prev = T16;
  if (t == 0 || (T17 != T17__prev).to_bool())
    dat_dump(f, T17, "N23");
  T17__prev = T17;
  if (t == 0 || (Hello_imem__io_resp != Hello_imem__io_resp__prev).to_bool())
    dat_dump(f, Hello_imem__io_resp, "N24");
  Hello_imem__io_resp__prev = Hello_imem__io_resp;
  if (t == 0 || (Hello__inst != Hello__inst__prev).to_bool())
    dat_dump(f, Hello__inst, "N25");
  Hello__inst__prev = Hello__inst;
  if (t == 0 || (T18 != T18__prev).to_bool())
    dat_dump(f, T18, "N26");
  T18__prev = T18;
  if (t == 0 || (Hello__op != Hello__op__prev).to_bool())
    dat_dump(f, Hello__op, "N27");
  Hello__op__prev = Hello__op;
  if (t == 0 || (T19 != T19__prev).to_bool())
    dat_dump(f, T19, "N28");
  T19__prev = T19;
  if (t == 0 || (T20 != T20__prev).to_bool())
    dat_dump(f, T20, "N29");
  T20__prev = T20;
  if (t == 0 || (T21 != T21__prev).to_bool())
    dat_dump(f, T21, "N30");
  T21__prev = T21;
  if (t == 0 || (Hello__adder_sel != Hello__adder_sel__prev).to_bool())
    dat_dump(f, Hello__adder_sel, "N31");
  Hello__adder_sel__prev = Hello__adder_sel;
  if (t == 0 || (T22 != T22__prev).to_bool())
    dat_dump(f, T22, "N32");
  T22__prev = T22;
  if (t == 0 || (Hello_regfile__io_writes_0_is != Hello_regfile__io_writes_0_is__prev).to_bool())
    dat_dump(f, Hello_regfile__io_writes_0_is, "N33");
  Hello_regfile__io_writes_0_is__prev = Hello_regfile__io_writes_0_is;
  if (t == 0 || (T23 != T23__prev).to_bool())
    dat_dump(f, T23, "N34");
  T23__prev = T23;
  if (t == 0 || (T24 != T24__prev).to_bool())
    dat_dump(f, T24, "N35");
  T24__prev = T24;
  if (t == 0 || (Hello__subtract_out != Hello__subtract_out__prev).to_bool())
    dat_dump(f, Hello__subtract_out, "N36");
  Hello__subtract_out__prev = Hello__subtract_out;
  if (t == 0 || (Hello__Huy_3_ != Hello__Huy_3___prev).to_bool())
    dat_dump(f, Hello__Huy_3_, "N37");
  Hello__Huy_3___prev = Hello__Huy_3_;
  if (t == 0 || (T25 != T25__prev).to_bool())
    dat_dump(f, T25, "N38");
  T25__prev = T25;
  if (t == 0 || (Hello_regfile__io_writes_1_dat != Hello_regfile__io_writes_1_dat__prev).to_bool())
    dat_dump(f, Hello_regfile__io_writes_1_dat, "N39");
  Hello_regfile__io_writes_1_dat__prev = Hello_regfile__io_writes_1_dat;
  if (t == 0 || (T26 != T26__prev).to_bool())
    dat_dump(f, T26, "N40");
  T26__prev = T26;
  if (t == 0 || (T27 != T27__prev).to_bool())
    dat_dump(f, T27, "N41");
  T27__prev = T27;
  if (t == 0 || (T28 != T28__prev).to_bool())
    dat_dump(f, T28, "N42");
  T28__prev = T28;
  if (t == 0 || (Hello__subtract_sel != Hello__subtract_sel__prev).to_bool())
    dat_dump(f, Hello__subtract_sel, "N43");
  Hello__subtract_sel__prev = Hello__subtract_sel;
  if (t == 0 || (T29 != T29__prev).to_bool())
    dat_dump(f, T29, "N44");
  T29__prev = T29;
  if (t == 0 || (Hello_regfile__io_writes_1_is != Hello_regfile__io_writes_1_is__prev).to_bool())
    dat_dump(f, Hello_regfile__io_writes_1_is, "N45");
  Hello_regfile__io_writes_1_is__prev = Hello_regfile__io_writes_1_is;
  if (t == 0 || (T30 != T30__prev).to_bool())
    dat_dump(f, T30, "N46");
  T30__prev = T30;
  if (t == 0 || (T31 != T31__prev).to_bool())
    dat_dump(f, T31, "N47");
  T31__prev = T31;
  if (t == 0 || (Hello_regfile__datas_0 != Hello_regfile__datas_0__prev).to_bool())
    dat_dump(f, Hello_regfile__datas_0, "N48");
  Hello_regfile__datas_0__prev = Hello_regfile__datas_0;
  if (t == 0 || (T32 != T32__prev).to_bool())
    dat_dump(f, T32, "N49");
  T32__prev = T32;
  if (t == 0 || (T33 != T33__prev).to_bool())
    dat_dump(f, T33, "N50");
  T33__prev = T33;
  if (t == 0 || (Hello_regfile__ens_0 != Hello_regfile__ens_0__prev).to_bool())
    dat_dump(f, Hello_regfile__ens_0, "N51");
  Hello_regfile__ens_0__prev = Hello_regfile__ens_0;
  if (t == 0 || (T34 != T34__prev).to_bool())
    dat_dump(f, T34, "N52");
  T34__prev = T34;
  if (t == 0 || (Hello__rd != Hello__rd__prev).to_bool())
    dat_dump(f, Hello__rd, "N53");
  Hello__rd__prev = Hello__rd;
  if (t == 0 || (T35 != T35__prev).to_bool())
    dat_dump(f, T35, "N54");
  T35__prev = T35;
  if (t == 0 || (T36 != T36__prev).to_bool())
    dat_dump(f, T36, "N55");
  T36__prev = T36;
  if (t == 0 || (Hello_regfile__io_writes_0_adr != Hello_regfile__io_writes_0_adr__prev).to_bool())
    dat_dump(f, Hello_regfile__io_writes_0_adr, "N56");
  Hello_regfile__io_writes_0_adr__prev = Hello_regfile__io_writes_0_adr;
  if (t == 0 || (T37 != T37__prev).to_bool())
    dat_dump(f, T37, "N57");
  T37__prev = T37;
  if (t == 0 || (T38 != T38__prev).to_bool())
    dat_dump(f, T38, "N58");
  T38__prev = T38;
  if (t == 0 || (T39 != T39__prev).to_bool())
    dat_dump(f, T39, "N59");
  T39__prev = T39;
  if (t == 0 || (Hello_regfile__io_writes_1_adr != Hello_regfile__io_writes_1_adr__prev).to_bool())
    dat_dump(f, Hello_regfile__io_writes_1_adr, "N60");
  Hello_regfile__io_writes_1_adr__prev = Hello_regfile__io_writes_1_adr;
  if (t == 0 || (T40 != T40__prev).to_bool())
    dat_dump(f, T40, "N61");
  T40__prev = T40;
  if (t == 0 || (T41 != T41__prev).to_bool())
    dat_dump(f, T41, "N62");
  T41__prev = T41;
  if (t == 0 || (Hello_regfile__addrs_0 != Hello_regfile__addrs_0__prev).to_bool())
    dat_dump(f, Hello_regfile__addrs_0, "N63");
  Hello_regfile__addrs_0__prev = Hello_regfile__addrs_0;
  if (t == 0 || (T42 != T42__prev).to_bool())
    dat_dump(f, T42, "N64");
  T42__prev = T42;
  if (t == 0 || (Hello_imem__reset != Hello_imem__reset__prev).to_bool())
    dat_dump(f, Hello_imem__reset, "N66");
  Hello_imem__reset__prev = Hello_imem__reset;
  if (t == 0 || (T43 != T43__prev).to_bool())
    dat_dump(f, T43, "N67");
  T43__prev = T43;
  if (t == 0 || (Hello_imem__imem_7 != Hello_imem__imem_7__prev).to_bool())
    dat_dump(f, Hello_imem__imem_7, "N68");
  Hello_imem__imem_7__prev = Hello_imem__imem_7;
  if (t == 0 || (T44 != T44__prev).to_bool())
    dat_dump(f, T44, "N69");
  T44__prev = T44;
  if (t == 0 || (Hello_imem__imem_6 != Hello_imem__imem_6__prev).to_bool())
    dat_dump(f, Hello_imem__imem_6, "N70");
  Hello_imem__imem_6__prev = Hello_imem__imem_6;
  if (t == 0 || (T45 != T45__prev).to_bool())
    dat_dump(f, T45, "N71");
  T45__prev = T45;
  if (t == 0 || (Hello_imem__imem_5 != Hello_imem__imem_5__prev).to_bool())
    dat_dump(f, Hello_imem__imem_5, "N72");
  Hello_imem__imem_5__prev = Hello_imem__imem_5;
  if (t == 0 || (T46 != T46__prev).to_bool())
    dat_dump(f, T46, "N73");
  T46__prev = T46;
  if (t == 0 || (Hello_imem__imem_4 != Hello_imem__imem_4__prev).to_bool())
    dat_dump(f, Hello_imem__imem_4, "N74");
  Hello_imem__imem_4__prev = Hello_imem__imem_4;
  if (t == 0 || (T47 != T47__prev).to_bool())
    dat_dump(f, T47, "N75");
  T47__prev = T47;
  if (t == 0 || (Hello_imem__imem_3 != Hello_imem__imem_3__prev).to_bool())
    dat_dump(f, Hello_imem__imem_3, "N76");
  Hello_imem__imem_3__prev = Hello_imem__imem_3;
  if (t == 0 || (T48 != T48__prev).to_bool())
    dat_dump(f, T48, "N77");
  T48__prev = T48;
  if (t == 0 || (Hello_imem__imem_2 != Hello_imem__imem_2__prev).to_bool())
    dat_dump(f, Hello_imem__imem_2, "N78");
  Hello_imem__imem_2__prev = Hello_imem__imem_2;
  if (t == 0 || (T49 != T49__prev).to_bool())
    dat_dump(f, T49, "N79");
  T49__prev = T49;
  if (t == 0 || (Hello_imem__imem_1 != Hello_imem__imem_1__prev).to_bool())
    dat_dump(f, Hello_imem__imem_1, "N80");
  Hello_imem__imem_1__prev = Hello_imem__imem_1;
  if (t == 0 || (T50 != T50__prev).to_bool())
    dat_dump(f, T50, "N81");
  T50__prev = T50;
  if (t == 0 || (Hello_imem__imem_0 != Hello_imem__imem_0__prev).to_bool())
    dat_dump(f, Hello_imem__imem_0, "N82");
  Hello_imem__imem_0__prev = Hello_imem__imem_0;
  if (t == 0 || (Hello__subtract_sel_init != Hello__subtract_sel_init__prev).to_bool())
    dat_dump(f, Hello__subtract_sel_init, "N83");
  Hello__subtract_sel_init__prev = Hello__subtract_sel_init;
  if (t == 0 || (T51 != T51__prev).to_bool())
    dat_dump(f, T51, "N84");
  T51__prev = T51;
  if (t == 0 || (R52 != R52__prev).to_bool())
    dat_dump(f, R52, "N85");
  R52__prev = R52;
  if (t == 0 || (Hello__adder_sel_init != Hello__adder_sel_init__prev).to_bool())
    dat_dump(f, Hello__adder_sel_init, "N86");
  Hello__adder_sel_init__prev = Hello__adder_sel_init;
  if (t == 0 || (T53 != T53__prev).to_bool())
    dat_dump(f, T53, "N87");
  T53__prev = T53;
  if (t == 0 || (R54 != R54__prev).to_bool())
    dat_dump(f, R54, "N88");
  R54__prev = R54;
  if (t == 0 || (T55 != T55__prev).to_bool())
    dat_dump(f, T55, "N89");
  T55__prev = T55;
  if (t == 0 || (Hello__rs1 != Hello__rs1__prev).to_bool())
    dat_dump(f, Hello__rs1, "N90");
  Hello__rs1__prev = Hello__rs1;
  if (t == 0 || (T56 != T56__prev).to_bool())
    dat_dump(f, T56, "N91");
  T56__prev = T56;
  if (t == 0 || (Hello_regfile__io_reads_0_adr != Hello_regfile__io_reads_0_adr__prev).to_bool())
    dat_dump(f, Hello_regfile__io_reads_0_adr, "N92");
  Hello_regfile__io_reads_0_adr__prev = Hello_regfile__io_reads_0_adr;
  if (t == 0 || (T57 != T57__prev).to_bool())
    dat_dump(f, T57, "N93");
  T57__prev = T57;
  if (t == 0 || (Hello_regfile__io_reads_0_dat != Hello_regfile__io_reads_0_dat__prev).to_bool())
    dat_dump(f, Hello_regfile__io_reads_0_dat, "N94");
  Hello_regfile__io_reads_0_dat__prev = Hello_regfile__io_reads_0_dat;
  if (t == 0 || (Hello__rs1_data != Hello__rs1_data__prev).to_bool())
    dat_dump(f, Hello__rs1_data, "N95");
  Hello__rs1_data__prev = Hello__rs1_data;
  if (t == 0 || (T58 != T58__prev).to_bool())
    dat_dump(f, T58, "N96");
  T58__prev = T58;
  if (t == 0 || (T59 != T59__prev).to_bool())
    dat_dump(f, T59, "N97");
  T59__prev = T59;
  if (t == 0 || (Hello__operand1 != Hello__operand1__prev).to_bool())
    dat_dump(f, Hello__operand1, "N98");
  Hello__operand1__prev = Hello__operand1;
  if (t == 0 || (T60 != T60__prev).to_bool())
    dat_dump(f, T60, "N99");
  T60__prev = T60;
  if (t == 0 || (R61 != R61__prev).to_bool())
    dat_dump(f, R61, "N100");
  R61__prev = R61;
  if (t == 0 || (T62 != T62__prev).to_bool())
    dat_dump(f, T62, "N101");
  T62__prev = T62;
  if (t == 0 || (Hello__pc_plus4 != Hello__pc_plus4__prev).to_bool())
    dat_dump(f, Hello__pc_plus4, "N102");
  Hello__pc_plus4__prev = Hello__pc_plus4;
  if (t == 0 || (Hello__pc_reg != Hello__pc_reg__prev).to_bool())
    dat_dump(f, Hello__pc_reg, "N103");
  Hello__pc_reg__prev = Hello__pc_reg;
  if (t == 0 || (T63 != T63__prev).to_bool())
    dat_dump(f, T63, "N104");
  T63__prev = T63;
  if (t == 0 || (Hello__rs2 != Hello__rs2__prev).to_bool())
    dat_dump(f, Hello__rs2, "N105");
  Hello__rs2__prev = Hello__rs2;
  if (t == 0 || (T64 != T64__prev).to_bool())
    dat_dump(f, T64, "N106");
  T64__prev = T64;
  if (t == 0 || (Hello_regfile__io_reads_1_adr != Hello_regfile__io_reads_1_adr__prev).to_bool())
    dat_dump(f, Hello_regfile__io_reads_1_adr, "N107");
  Hello_regfile__io_reads_1_adr__prev = Hello_regfile__io_reads_1_adr;
  if (t == 0 || (T65 != T65__prev).to_bool())
    dat_dump(f, T65, "N108");
  T65__prev = T65;
  if (t == 0 || (Hello_regfile__io_reads_1_dat != Hello_regfile__io_reads_1_dat__prev).to_bool())
    dat_dump(f, Hello_regfile__io_reads_1_dat, "N109");
  Hello_regfile__io_reads_1_dat__prev = Hello_regfile__io_reads_1_dat;
  if (t == 0 || (Hello__rs2_data != Hello__rs2_data__prev).to_bool())
    dat_dump(f, Hello__rs2_data, "N110");
  Hello__rs2_data__prev = Hello__rs2_data;
  if (t == 0 || (T66 != T66__prev).to_bool())
    dat_dump(f, T66, "N111");
  T66__prev = T66;
  if (t == 0 || (T67 != T67__prev).to_bool())
    dat_dump(f, T67, "N112");
  T67__prev = T67;
  if (t == 0 || (Hello__imm != Hello__imm__prev).to_bool())
    dat_dump(f, Hello__imm, "N113");
  Hello__imm__prev = Hello__imm;
  if (t == 0 || (T68 != T68__prev).to_bool())
    dat_dump(f, T68, "N114");
  T68__prev = T68;
  if (t == 0 || (T69 != T69__prev).to_bool())
    dat_dump(f, T69, "N115");
  T69__prev = T69;
  if (t == 0 || (Hello__operand2 != Hello__operand2__prev).to_bool())
    dat_dump(f, Hello__operand2, "N116");
  Hello__operand2__prev = Hello__operand2;
  if (t == 0 || (T70 != T70__prev).to_bool())
    dat_dump(f, T70, "N117");
  T70__prev = T70;
  if (t == 0 || (R71 != R71__prev).to_bool())
    dat_dump(f, R71, "N118");
  R71__prev = R71;
  if (t == 0 || (Hello__io_read_addr != Hello__io_read_addr__prev).to_bool())
    dat_dump(f, Hello__io_read_addr, "N119");
  Hello__io_read_addr__prev = Hello__io_read_addr;
  if (t == 0 || (T72 != T72__prev).to_bool())
    dat_dump(f, T72, "N120");
  T72__prev = T72;
  if (t == 0 || (Hello_regfile__io_reads_2_adr != Hello_regfile__io_reads_2_adr__prev).to_bool())
    dat_dump(f, Hello_regfile__io_reads_2_adr, "N121");
  Hello_regfile__io_reads_2_adr__prev = Hello_regfile__io_reads_2_adr;
  if (t == 0 || (T73 != T73__prev).to_bool())
    dat_dump(f, T73, "N122");
  T73__prev = T73;
  if (t == 0 || (Hello_regfile__io_reads_2_dat != Hello_regfile__io_reads_2_dat__prev).to_bool())
    dat_dump(f, Hello_regfile__io_reads_2_dat, "N123");
  Hello_regfile__io_reads_2_dat__prev = Hello_regfile__io_reads_2_dat;
  if (t == 0 || (Hello__io_read_data != Hello__io_read_data__prev).to_bool())
    dat_dump(f, Hello__io_read_data, "N124");
  Hello__io_read_data__prev = Hello__io_read_data;
}
