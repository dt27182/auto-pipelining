module TICache(input clk, input reset,
    input  io_req_valid,
    input [3:0] mem_addr,
    output[31:0] io_resp
);

  wire[31:0] T0;
  wire[31:0] T1;
  wire[31:0] T2;
  wire[31:0] T3;
  wire[31:0] T4;
  wire[31:0] T5;
  wire[31:0] T6;
  wire[31:0] T7;
  wire[31:0] T8;
  wire[31:0] T9;
  wire[31:0] T10;
  wire[31:0] T11;
  wire[31:0] T12;
  wire[31:0] T13;
  wire[31:0] T14;
  wire[31:0] T15;
  wire[31:0] T16;
  wire[31:0] T17;
  wire[31:0] T18;
  wire[31:0] T19;
  reg[31:0] imem_0;
  wire[31:0] T20;
  reg[31:0] imem_1;
  wire[31:0] T21;
  wire T22;
  wire T23;
  wire[3:0] T24;
  wire[3:0] T25;
  wire[3:0] T26;
  wire[31:0] T27;
  wire[31:0] T28;
  reg[31:0] imem_2;
  wire[31:0] T29;
  reg[31:0] imem_3;
  wire[31:0] T30;
  wire T31;
  wire T32;
  wire[3:0] T33;
  wire T34;
  wire T35;
  wire[3:0] T36;
  wire[31:0] T37;
  wire[31:0] T38;
  wire[31:0] T39;
  wire[31:0] T40;
  wire[31:0] T41;
  wire[31:0] T42;
  wire[31:0] T43;
  wire[31:0] T44;
  reg[31:0] imem_4;
  wire[31:0] T45;
  reg[31:0] imem_5;
  wire[31:0] T46;
  wire T47;
  wire T48;
  wire[3:0] T49;
  wire[31:0] T50;
  wire[31:0] T51;
  reg[31:0] imem_6;
  wire[31:0] T52;
  reg[31:0] imem_7;
  wire[31:0] T53;
  wire T54;
  wire T55;
  wire[3:0] T56;
  wire T57;
  wire T58;
  wire[3:0] T59;
  wire T60;
  wire T61;
  wire[3:0] T62;
  wire[31:0] T63;
  wire[31:0] T64;
  wire[31:0] T65;
  wire[31:0] T66;
  wire[31:0] T67;
  wire[31:0] T68;
  wire[31:0] T69;
  wire[31:0] T70;
  wire[31:0] T71;
  wire[31:0] T72;
  wire[31:0] T73;
  wire[31:0] T74;
  wire[31:0] T75;
  wire[31:0] T76;
  reg[31:0] imem_8;
  wire[31:0] T77;
  reg[31:0] imem_9;
  wire[31:0] T78;
  wire T79;
  wire T80;
  wire[3:0] T81;
  wire[31:0] T82;
  wire[31:0] T83;
  reg[31:0] imem_10;
  wire[31:0] T84;
  reg[31:0] imem_11;
  wire[31:0] T85;
  wire T86;
  wire T87;
  wire[3:0] T88;
  wire T89;
  wire T90;
  wire[3:0] T91;
  wire[31:0] T92;
  wire[31:0] T93;
  wire[31:0] T94;
  wire[31:0] T95;
  wire[31:0] T96;
  wire[31:0] T97;
  wire[31:0] T98;
  wire[31:0] T99;
  reg[31:0] imem_12;
  wire[31:0] T100;
  reg[31:0] imem_13;
  wire[31:0] T101;
  wire T102;
  wire T103;
  wire[3:0] T104;
  wire[31:0] T105;
  wire[31:0] T106;
  reg[31:0] imem_14;
  wire[31:0] T107;
  reg[31:0] imem_15;
  wire[31:0] T108;
  wire T109;
  wire T110;
  wire[3:0] T111;
  wire T112;
  wire T113;
  wire[3:0] T114;
  wire T115;
  wire T116;
  wire[3:0] T117;
  wire T118;
  wire T119;
  wire[3:0] T120;

  assign io_resp = T0;
  assign T0 = T1;
  assign T1 = T2;
  assign T2 = T3;
  assign T3 = T4;
  assign T4 = T5;
  assign T5 = T118 ? T63 : T6;
  assign T6 = T7;
  assign T7 = T8;
  assign T8 = T9;
  assign T9 = T10;
  assign T10 = T11;
  assign T11 = T60 ? T37 : T12;
  assign T12 = T13;
  assign T13 = T14;
  assign T14 = T15;
  assign T15 = T16;
  assign T16 = T17;
  assign T17 = T34 ? T27 : T18;
  assign T18 = T19;
  assign T19 = T22 ? imem_1 : imem_0;
  assign T20 = reset ? 32'h4000/* 16384*/ : imem_0;
  assign T21 = reset ? 32'h4101/* 16641*/ : imem_1;
  assign T22 = T23;
  assign T23 = T24[1'h0/* 0*/:1'h0/* 0*/];
  assign T24 = T25;
  assign T25 = T26;
  assign T26 = mem_addr;
  assign T27 = T28;
  assign T28 = T31 ? imem_3 : imem_2;
  assign T29 = reset ? 32'ha0f0/* 41200*/ : imem_2;
  assign T30 = reset ? 32'h121f1/* 74225*/ : imem_3;
  assign T31 = T32;
  assign T32 = T33[1'h0/* 0*/:1'h0/* 0*/];
  assign T33 = T25;
  assign T34 = T35;
  assign T35 = T36[1'h1/* 1*/:1'h1/* 1*/];
  assign T36 = T25;
  assign T37 = T38;
  assign T38 = T39;
  assign T39 = T40;
  assign T40 = T41;
  assign T41 = T42;
  assign T42 = T57 ? T50 : T43;
  assign T43 = T44;
  assign T44 = T47 ? imem_5 : imem_4;
  assign T45 = reset ? 32'h12/* 18*/ : imem_4;
  assign T46 = reset ? 32'h1203/* 4611*/ : imem_5;
  assign T47 = T48;
  assign T48 = T49[1'h0/* 0*/:1'h0/* 0*/];
  assign T49 = T25;
  assign T50 = T51;
  assign T51 = T54 ? imem_7 : imem_6;
  assign T52 = reset ? 32'h44f4/* 17652*/ : imem_6;
  assign T53 = reset ? 32'h4e0f0/* 319728*/ : imem_7;
  assign T54 = T55;
  assign T55 = T56[1'h0/* 0*/:1'h0/* 0*/];
  assign T56 = T25;
  assign T57 = T58;
  assign T58 = T59[1'h1/* 1*/:1'h1/* 1*/];
  assign T59 = T25;
  assign T60 = T61;
  assign T61 = T62[2'h2/* 2*/:2'h2/* 2*/];
  assign T62 = T25;
  assign T63 = T64;
  assign T64 = T65;
  assign T65 = T66;
  assign T66 = T67;
  assign T67 = T68;
  assign T68 = T115 ? T92 : T69;
  assign T69 = T70;
  assign T70 = T71;
  assign T71 = T72;
  assign T72 = T73;
  assign T73 = T74;
  assign T74 = T89 ? T82 : T75;
  assign T75 = T76;
  assign T76 = T79 ? imem_9 : imem_8;
  assign T77 = reset ? 32'ha4f4/* 42228*/ : imem_8;
  assign T78 = reset ? 32'h124f4/* 74996*/ : imem_9;
  assign T79 = T80;
  assign T80 = T81[1'h0/* 0*/:1'h0/* 0*/];
  assign T81 = T25;
  assign T82 = T83;
  assign T83 = T86 ? imem_11 : imem_10;
  assign T84 = reset ? 32'h50f0/* 20720*/ : imem_10;
  assign T85 = reset ? 32'h50f0/* 20720*/ : imem_11;
  assign T86 = T87;
  assign T87 = T88[1'h0/* 0*/:1'h0/* 0*/];
  assign T88 = T25;
  assign T89 = T90;
  assign T90 = T91[1'h1/* 1*/:1'h1/* 1*/];
  assign T91 = T25;
  assign T92 = T93;
  assign T93 = T94;
  assign T94 = T95;
  assign T95 = T96;
  assign T96 = T97;
  assign T97 = T112 ? T105 : T98;
  assign T98 = T99;
  assign T99 = T102 ? imem_13 : imem_12;
  assign T100 = reset ? 32'h50f0/* 20720*/ : imem_12;
  assign T101 = reset ? 32'h50f0/* 20720*/ : imem_13;
  assign T102 = T103;
  assign T103 = T104[1'h0/* 0*/:1'h0/* 0*/];
  assign T104 = T25;
  assign T105 = T106;
  assign T106 = T109 ? imem_15 : imem_14;
  assign T107 = reset ? 32'h50f0/* 20720*/ : imem_14;
  assign T108 = reset ? 32'h50f0/* 20720*/ : imem_15;
  assign T109 = T110;
  assign T110 = T111[1'h0/* 0*/:1'h0/* 0*/];
  assign T111 = T25;
  assign T112 = T113;
  assign T113 = T114[1'h1/* 1*/:1'h1/* 1*/];
  assign T114 = T25;
  assign T115 = T116;
  assign T116 = T117[2'h2/* 2*/:2'h2/* 2*/];
  assign T117 = T25;
  assign T118 = T119;
  assign T119 = T120[2'h3/* 3*/:2'h3/* 3*/];
  assign T120 = T25;

  always @(posedge clk) begin
    imem_0 <= T20;
    imem_1 <= T21;
    imem_2 <= T29;
    imem_3 <= T30;
    imem_4 <= T45;
    imem_5 <= T46;
    imem_6 <= T52;
    imem_7 <= T53;
    imem_8 <= T77;
    imem_9 <= T78;
    imem_10 <= T84;
    imem_11 <= T85;
    imem_12 <= T100;
    imem_13 <= T101;
    imem_14 <= T107;
    imem_15 <= T108;
  end
endmodule

module TransactionMem(input clk,
    input [3:0] io_reads_0_adr,
    output[31:0] io_reads_0_dat,
    input [3:0] io_reads_1_adr,
    output[31:0] io_reads_1_dat,
    input [3:0] io_reads_2_adr,
    output[31:0] io_reads_2_dat,
    input  io_writes_0_is,
    input [3:0] io_writes_0_adr,
    input [31:0] io_writes_0_dat,
    input  io_writes_1_is,
    input [3:0] io_writes_1_adr,
    input [31:0] io_writes_1_dat
);

  wire[31:0] T0;
  reg [31:0] mem [15:0];
  wire[31:0] T1;
  wire[31:0] T2;
  wire[31:0] datas_0;
  wire[31:0] T3;
  wire[31:0] T4;
  wire[31:0] T5;
  wire[31:0] T6;
  wire ens_0;
  wire T7;
  wire[3:0] addrs_0;
  wire[3:0] T8;
  wire[3:0] T9;
  wire[3:0] T10;
  wire[3:0] T11;
  wire[31:0] T12;
  wire[31:0] T13;

  assign io_reads_2_dat = T0;
  assign T0 = mem[io_reads_2_adr];
  assign T2 = datas_0;
  assign datas_0 = T3;
  assign T3 = T4;
  assign T4 = io_writes_1_is ? io_writes_1_dat : T5;
  assign T5 = io_writes_0_is ? io_writes_0_dat : T6;
  assign T6 = {31'h0/* 0*/, 1'h0/* 0*/};
  assign ens_0 = T7;
  assign T7 = io_writes_0_is || io_writes_1_is;
  assign addrs_0 = T8;
  assign T8 = T9;
  assign T9 = io_writes_1_is ? io_writes_1_adr : T10;
  assign T10 = io_writes_0_is ? io_writes_0_adr : T11;
  assign T11 = {3'h0/* 0*/, 1'h0/* 0*/};
  assign io_reads_1_dat = T12;
  assign T12 = mem[io_reads_1_adr];
  assign io_reads_0_dat = T13;
  assign T13 = mem[io_reads_0_adr];

  always @(posedge clk) begin
    if (ens_0)
      mem[addrs_0] <= T2;
  end
endmodule

module Hello(input clk, input reset,
    output[31:0] io_read_data,
    input [3:0] io_read_addr
);

  wire[31:0] T0;
  wire[31:0] T1;
  wire[31:0] T2;
  wire[31:0] T3;
  wire[31:0] T4;
  wire[31:0] T5;
  wire[31:0] subtract_out_mem;
  wire[31:0] T6;
  wire[31:0] subtract_out_exe;
  wire[31:0] T7;
  wire[31:0] subtract_out;
  wire[31:0] T8;
  wire[31:0] T9;
  wire[31:0] T10;
  wire[31:0] T11;
  wire[31:0] T12;
  wire[31:0] operand2_exe;
  wire[31:0] T13;
  wire[31:0] operand2;
  reg[31:0] Stage_2_PipeReg_8;
  wire[31:0] T14;
  wire[31:0] T15;
  wire[31:0] T16;
  wire[31:0] T17;
  wire[31:0] rs2_data;
  wire[31:0] T18;
  wire[31:0] bypassMux_regfile_io_reads_1_dat;
  wire[31:0] T19;
  wire[31:0] regfile_io_reads_1_dat;
  wire[31:0] T20;
  wire hazard_num8_regfile_readport_num1_3_subtract_sel_mem;
  wire T21;
  wire[3:0] T22;
  wire[3:0] rd;
  reg[3:0] Stage_2_PipeReg_13;
  wire[3:0] T23;
  reg[3:0] Stage_1_PipeReg_12;
  wire[3:0] T24;
  wire[3:0] T25;
  wire[3:0] T26;
  wire[31:0] T27;
  wire[31:0] inst;
  wire[31:0] T28;
  wire[31:0] imem_io_resp;
  wire[3:0] T29;
  wire[3:0] T30;
  wire T31;
  wire T32;
  wire T33;
  wire T34;
  reg[0:0] Stage_2_PipeReg_19;
  wire T35;
  reg[0:0] Stage_1_PipeReg_18;
  wire T36;
  wire T37;
  wire T38;
  wire[2:0] T39;
  wire[2:0] T40;
  wire[2:0] op;
  wire[2:0] T41;
  wire[2:0] T42;
  wire[31:0] T43;
  reg[0:0] Stage_2_PipeReg_10;
  wire T44;
  reg[0:0] Stage_1_PipeReg_9;
  wire T45;
  wire T46;
  wire T47;
  wire[2:0] T48;
  wire[2:0] T49;
  wire T50;
  wire PipeStage_Valid_3;
  reg[0:0] Stage_2_valid_reg;
  wire T51;
  wire T52;
  wire PipeStage_Stall_2;
  wire T53;
  wire T54;
  wire PipeStage_Valid_0;
  wire T55;
  wire spec_kill_pc_reg;
  wire T56;
  wire PipeStage_Valid_2;
  wire T57;
  wire T58;
  wire hazard_num9_regfile_readport_num2_3_subtract_sel_mem;
  wire T59;
  wire[3:0] T60;
  wire T61;
  wire T62;
  wire T63;
  wire T64;
  wire T65;
  wire hazard_num6_regfile_readport_num2_3_adder_sel_mem;
  wire T66;
  wire[3:0] T67;
  wire T68;
  wire T69;
  wire T70;
  wire T71;
  wire T72;
  wire T73;
  reg[0:0] Stage_2_PipeReg_17;
  wire T74;
  reg[0:0] Stage_1_PipeReg_16;
  wire T75;
  wire T76;
  wire T77;
  wire T78;
  wire T79;
  wire[2:0] T80;
  wire T81;
  wire T82;
  wire[2:0] T83;
  wire[2:0] T84;
  reg[0:0] Stage_2_PipeReg_7;
  wire T85;
  reg[0:0] Stage_1_PipeReg_6;
  wire T86;
  wire T87;
  wire T88;
  wire[2:0] T89;
  wire[2:0] T90;
  wire T91;
  reg[0:0] Stage_1_valid_reg;
  wire T92;
  wire T93;
  wire PipeStage_Stall_1;
  wire T94;
  wire T95;
  wire PipeStage_Valid_1;
  wire T96;
  wire T97;
  reg[0:0] Stage_0_valid_reg;
  wire T98;
  wire T99;
  wire PipeStage_Stall_0;
  wire T100;
  wire T101;
  wire T102;
  wire[3:0] T103;
  wire[3:0] T104;
  wire[3:0] pc_plus4_mem;
  reg[3:0] Stage_1_PipeReg_3;
  wire[3:0] T105;
  reg[3:0] Stage_0_PipeReg_2;
  wire[3:0] T106;
  wire[3:0] T107;
  wire[3:0] pc_plus4_exe;
  wire[3:0] T108;
  wire[3:0] pc_plus4;
  wire[3:0] T109;
  wire[3:0] T110;
  wire[3:0] T111;
  wire[3:0] T112;
  reg[3:0] pc_reg;
  wire T113;
  wire isJmp;
  wire T114;
  wire T115;
  reg[2:0] Stage_1_PipeReg_20;
  wire[2:0] T116;
  wire[2:0] T117;
  wire[2:0] T118;
  wire isNotJmp;
  wire T119;
  wire T120;
  wire T121;
  wire T122;
  reg[2:0] Stage_1_PipeReg_1;
  wire[2:0] T123;
  wire[2:0] T124;
  wire[2:0] T125;
  wire[3:0] T126;
  wire[3:0] T127;
  wire do_speculate_pc_reg;
  wire T128;
  wire T129;
  wire[3:0] T130;
  wire[3:0] T131;
  wire[3:0] jmpTarget;
  wire[3:0] T132;
  wire[3:0] T133;
  reg[31:0] Stage_1_PipeReg_5;
  wire[31:0] T134;
  wire[31:0] T135;
  wire[31:0] imm;
  wire[31:0] T136;
  wire[31:0] T137;
  wire[16:0] T138;
  wire[16:0] T139;
  wire[31:0] T140;
  wire[31:0] T141;
  reg[3:0] spec_write_data_reg_pc_reg_1;
  reg[3:0] spec_write_data_reg_pc_reg_0;
  wire T142;
  wire[31:0] T143;
  wire[31:0] T144;
  wire[31:0] T145;
  wire[31:0] T146;
  wire[31:0] T147;
  wire[31:0] operand1_exe;
  wire[31:0] T148;
  wire[31:0] operand1;
  reg[31:0] Stage_2_PipeReg_15;
  wire[31:0] T149;
  wire[31:0] T150;
  wire[31:0] T151;
  wire[31:0] T152;
  wire[31:0] rs1_data;
  wire[31:0] T153;
  wire[31:0] bypassMux_regfile_io_reads_0_dat;
  wire[31:0] T154;
  wire[31:0] regfile_io_reads_0_dat;
  wire[31:0] T155;
  wire hazard_num7_regfile_readport_num0_3_subtract_sel_mem;
  wire T156;
  wire[3:0] T157;
  wire T158;
  wire T159;
  wire T160;
  wire[31:0] T161;
  wire hazard_num4_regfile_readport_num0_3_adder_sel_mem;
  wire T162;
  wire[3:0] T163;
  wire T164;
  wire T165;
  wire T166;
  wire[31:0] T167;
  reg[0:0] Stage_1_PipeReg_0;
  wire T168;
  wire T169;
  wire T170;
  wire[2:0] T171;
  wire[31:0] T172;
  wire hazard_num5_regfile_readport_num1_3_adder_sel_mem;
  wire T173;
  wire[3:0] T174;
  wire T175;
  wire T176;
  wire T177;
  reg[31:0] Stage_1_PipeReg_4;
  wire[31:0] T178;
  wire[31:0] T179;
  wire[31:0] T180;
  reg[0:0] Stage_1_PipeReg_21;
  wire T181;
  wire T182;
  wire T183;
  wire[2:0] T184;
  wire[2:0] T185;
  wire[31:0] T186;
  wire[31:0] T187;
  wire T188;
  wire subtract_sel_mem;
  wire T189;
  wire subtract_sel_exe;
  wire T190;
  wire subtract_sel;
  wire T191;
  wire T192;
  wire[3:0] T193;
  wire[3:0] T194;
  wire[3:0] T195;
  wire[3:0] T196;
  wire[3:0] rd_mem;
  wire[3:0] T197;
  wire[3:0] rd_exe;
  wire[3:0] T198;
  wire T199;
  wire T200;
  wire T201;
  wire T202;
  wire T203;
  wire T204;
  wire T205;
  wire PipeStage_Stall_3;
  wire T206;
  wire T207;
  wire T208;
  wire[31:0] T209;
  wire[31:0] T210;
  wire[31:0] T211;
  wire[31:0] T212;
  wire[31:0] T213;
  wire[31:0] T214;
  wire[31:0] adder_out_mem;
  wire[31:0] T215;
  wire[31:0] adder_out_exe;
  wire[31:0] T216;
  wire[31:0] adder_out;
  wire[31:0] T217;
  wire[31:0] T218;
  wire T219;
  wire adder_sel_mem;
  wire T220;
  wire adder_sel_exe;
  wire T221;
  wire adder_sel;
  wire T222;
  wire T223;
  wire[3:0] T224;
  wire[3:0] T225;
  wire[3:0] T226;
  wire[3:0] T227;
  wire T228;
  wire T229;
  wire T230;
  wire T231;
  wire T232;
  wire T233;
  wire T234;
  wire T235;
  wire[3:0] T236;
  wire[3:0] T237;
  wire[3:0] rs2;
  wire[3:0] T238;
  wire[3:0] T239;
  reg[31:0] Stage_1_PipeReg_11;
  wire[31:0] T240;
  wire[31:0] T241;
  wire[31:0] T242;
  wire[3:0] T243;
  wire[3:0] rs1;
  wire[3:0] T244;
  wire[3:0] T245;
  reg[31:0] Stage_1_PipeReg_22;
  wire[31:0] T246;
  wire[31:0] T247;
  wire[31:0] T248;
  reg[3:0] Stage_0_PipeReg_14;
  wire[3:0] T249;
  wire[3:0] T250;
  wire[3:0] T251;
  wire[31:0] T252;
  wire[31:0] regfile_io_reads_2_dat;

  assign T0 = T1;
  assign T1 = T2;
  assign T2 = T3;
  assign T3 = T188 ? T5 : T4;
  assign T4 = {31'h0/* 0*/, 1'h0/* 0*/};
  assign T5 = subtract_out_mem;
  assign subtract_out_mem = T6;
  assign T6 = subtract_out_exe;
  assign subtract_out_exe = T7;
  assign T7 = subtract_out;
  assign subtract_out = T8;
  assign T8 = T9;
  assign T9 = T10;
  assign T10 = T11;
  assign T11 = T187 - T12;
  assign T12 = operand2_exe;
  assign operand2_exe = T13;
  assign T13 = operand2;
  assign operand2 = Stage_2_PipeReg_8;
  assign T14 = reset ? T186 : T15;
  assign T15 = T16;
  assign T16 = Stage_1_PipeReg_21 ? Stage_1_PipeReg_4 : T17;
  assign T17 = rs2_data;
  assign rs2_data = T18;
  assign T18 = bypassMux_regfile_io_reads_1_dat;
  assign bypassMux_regfile_io_reads_1_dat = hazard_num5_regfile_readport_num1_3_adder_sel_mem ? T143 : T19;
  assign T19 = hazard_num8_regfile_readport_num1_3_subtract_sel_mem ? T20 : regfile_io_reads_1_dat;
  assign T20 = T10;
  assign hazard_num8_regfile_readport_num1_3_subtract_sel_mem = T31 && T21;
  assign T21 = T237 == T22;
  assign T22 = rd;
  assign rd = Stage_2_PipeReg_13;
  assign T23 = reset ? T30 : Stage_1_PipeReg_12;
  assign T24 = reset ? T29 : T25;
  assign T25 = T26;
  assign T26 = T27[2'h3/* 3*/:1'h0/* 0*/];
  assign T27 = inst;
  assign inst = T28;
  assign T28 = imem_io_resp;
  assign T29 = {3'h0/* 0*/, 1'h0/* 0*/};
  assign T30 = {3'h0/* 0*/, 1'h0/* 0*/};
  assign T31 = T50 && T32;
  assign T32 = T33;
  assign T33 = T34;
  assign T34 = Stage_2_PipeReg_10 || Stage_2_PipeReg_19;
  assign T35 = reset ? 1'h0/* 0*/ : Stage_1_PipeReg_18;
  assign T36 = reset ? 1'h0/* 0*/ : T37;
  assign T37 = T38;
  assign T38 = T40 == T39;
  assign T39 = {1'h0/* 0*/, 2'h3/* 3*/};
  assign T40 = op;
  assign op = T41;
  assign T41 = T42;
  assign T42 = T43[4'he/* 14*/:4'hc/* 12*/];
  assign T43 = inst;
  assign T44 = reset ? 1'h0/* 0*/ : Stage_1_PipeReg_9;
  assign T45 = reset ? 1'h0/* 0*/ : T46;
  assign T46 = T47;
  assign T47 = T49 == T48;
  assign T48 = {2'h0/* 0*/, 1'h1/* 1*/};
  assign T49 = op;
  assign T50 = PipeStage_Valid_3;
  assign PipeStage_Valid_3 = Stage_2_valid_reg;
  assign T51 = T52 || reset;
  assign T52 = ~ PipeStage_Stall_2;
  assign PipeStage_Stall_2 = T53;
  assign T53 = ~ T54;
  assign T54 = PipeStage_Valid_0 == PipeStage_Valid_0;
  assign PipeStage_Valid_0 = T55;
  assign T55 = ~ spec_kill_pc_reg;
  assign spec_kill_pc_reg = T101 && T56;
  assign T56 = PipeStage_Valid_2;
  assign PipeStage_Valid_2 = T57;
  assign T57 = T64 && T58;
  assign T58 = ~ hazard_num9_regfile_readport_num2_3_subtract_sel_mem;
  assign hazard_num9_regfile_readport_num2_3_subtract_sel_mem = T61 && T59;
  assign T59 = T236 == T60;
  assign T60 = rd;
  assign T61 = T63 && T62;
  assign T62 = T33;
  assign T63 = PipeStage_Valid_3;
  assign T64 = Stage_1_valid_reg && T65;
  assign T65 = ~ hazard_num6_regfile_readport_num2_3_adder_sel_mem;
  assign hazard_num6_regfile_readport_num2_3_adder_sel_mem = T68 && T66;
  assign T66 = T236 == T67;
  assign T67 = rd;
  assign T68 = T91 && T69;
  assign T69 = T70;
  assign T70 = T71;
  assign T71 = Stage_2_PipeReg_7 || T72;
  assign T72 = T73;
  assign T73 = Stage_2_PipeReg_17;
  assign T74 = reset ? 1'h0/* 0*/ : Stage_1_PipeReg_16;
  assign T75 = reset ? 1'h0/* 0*/ : T76;
  assign T76 = T77;
  assign T77 = T81 || T78;
  assign T78 = T79;
  assign T79 = T80 == 3'h4/* 4*/;
  assign T80 = op;
  assign T81 = T82;
  assign T82 = T84 == T83;
  assign T83 = {1'h0/* 0*/, 2'h2/* 2*/};
  assign T84 = op;
  assign T85 = reset ? 1'h0/* 0*/ : Stage_1_PipeReg_6;
  assign T86 = reset ? 1'h0/* 0*/ : T87;
  assign T87 = T88;
  assign T88 = T90 == T89;
  assign T89 = {2'h0/* 0*/, 1'h0/* 0*/};
  assign T90 = op;
  assign T91 = PipeStage_Valid_3;
  assign T92 = T93 || reset;
  assign T93 = ~ PipeStage_Stall_1;
  assign PipeStage_Stall_1 = T94;
  assign T94 = hazard_num6_regfile_readport_num2_3_adder_sel_mem || hazard_num9_regfile_readport_num2_3_subtract_sel_mem;
  assign T95 = reset ? 1'h0/* 0*/ : PipeStage_Valid_1;
  assign PipeStage_Valid_1 = T96;
  assign T96 = Stage_0_valid_reg && T97;
  assign T97 = ~ spec_kill_pc_reg;
  assign T98 = T99 || reset;
  assign T99 = ~ PipeStage_Stall_0;
  assign PipeStage_Stall_0 = T94;
  assign T100 = reset ? 1'h0/* 0*/ : PipeStage_Valid_0;
  assign T101 = ~ T102;
  assign T102 = spec_write_data_reg_pc_reg_1 == T103;
  assign T103 = T104;
  assign T104 = isJmp ? jmpTarget : pc_plus4_mem;
  assign pc_plus4_mem = Stage_1_PipeReg_3;
  assign T105 = reset ? T131 : Stage_0_PipeReg_2;
  assign T106 = reset ? T130 : T107;
  assign T107 = pc_plus4_exe;
  assign pc_plus4_exe = T108;
  assign T108 = pc_plus4;
  assign pc_plus4 = T109;
  assign T109 = T110;
  assign T110 = T112 + T111;
  assign T111 = {3'h0/* 0*/, 1'h1/* 1*/};
  assign T112 = pc_reg;
  assign T113 = isNotJmp || isJmp;
  assign isJmp = T114;
  assign T114 = T115;
  assign T115 = Stage_1_PipeReg_20 == 3'h6/* 6*/;
  assign T116 = reset ? T118 : T117;
  assign T117 = op;
  assign T118 = {2'h0/* 0*/, 1'h0/* 0*/};
  assign isNotJmp = T119;
  assign T119 = T120;
  assign T120 = ~ T121;
  assign T121 = T122;
  assign T122 = Stage_1_PipeReg_1 == 3'h6/* 6*/;
  assign T123 = reset ? T125 : T124;
  assign T124 = op;
  assign T125 = {2'h0/* 0*/, 1'h0/* 0*/};
  assign T126 = do_speculate_pc_reg ? pc_plus4 : T127;
  assign T127 = spec_kill_pc_reg ? T104 : pc_reg;
  assign do_speculate_pc_reg = T129 && T128;
  assign T128 = ~ spec_kill_pc_reg;
  assign T129 = ~ PipeStage_Stall_0;
  assign T130 = {3'h0/* 0*/, 1'h0/* 0*/};
  assign T131 = {3'h0/* 0*/, 1'h0/* 0*/};
  assign jmpTarget = T132;
  assign T132 = T133;
  assign T133 = Stage_1_PipeReg_5[2'h3/* 3*/:1'h0/* 0*/];
  assign T134 = reset ? T141 : T135;
  assign T135 = imm;
  assign imm = T136;
  assign T136 = T137;
  assign T137 = {15'h0/* 0*/, T138};
  assign T138 = T139;
  assign T139 = T140[5'h1f/* 31*/:4'hf/* 15*/];
  assign T140 = inst;
  assign T141 = {31'h0/* 0*/, 1'h0/* 0*/};
  assign T142 = reset ? 1'h0/* 0*/ : PipeStage_Valid_2;
  assign T143 = T144;
  assign T144 = T145;
  assign T145 = T147 + T146;
  assign T146 = operand2_exe;
  assign T147 = operand1_exe;
  assign operand1_exe = T148;
  assign T148 = operand1;
  assign operand1 = Stage_2_PipeReg_15;
  assign T149 = reset ? T172 : T150;
  assign T150 = T151;
  assign T151 = Stage_1_PipeReg_0 ? T167 : T152;
  assign T152 = rs1_data;
  assign rs1_data = T153;
  assign T153 = bypassMux_regfile_io_reads_0_dat;
  assign bypassMux_regfile_io_reads_0_dat = hazard_num4_regfile_readport_num0_3_adder_sel_mem ? T161 : T154;
  assign T154 = hazard_num7_regfile_readport_num0_3_subtract_sel_mem ? T155 : regfile_io_reads_0_dat;
  assign T155 = T10;
  assign hazard_num7_regfile_readport_num0_3_subtract_sel_mem = T158 && T156;
  assign T156 = T243 == T157;
  assign T157 = rd;
  assign T158 = T160 && T159;
  assign T159 = T33;
  assign T160 = PipeStage_Valid_3;
  assign T161 = T144;
  assign hazard_num4_regfile_readport_num0_3_adder_sel_mem = T164 && T162;
  assign T162 = T243 == T163;
  assign T163 = rd;
  assign T164 = T166 && T165;
  assign T165 = T70;
  assign T166 = PipeStage_Valid_3;
  assign T167 = {31'h0/* 0*/, 1'h0/* 0*/};
  assign T168 = reset ? 1'h0/* 0*/ : T169;
  assign T169 = T170;
  assign T170 = T171 == 3'h4/* 4*/;
  assign T171 = op;
  assign T172 = {31'h0/* 0*/, 1'h0/* 0*/};
  assign hazard_num5_regfile_readport_num1_3_adder_sel_mem = T175 && T173;
  assign T173 = T237 == T174;
  assign T174 = rd;
  assign T175 = T177 && T176;
  assign T176 = T70;
  assign T177 = PipeStage_Valid_3;
  assign T178 = reset ? T180 : T179;
  assign T179 = imm;
  assign T180 = {31'h0/* 0*/, 1'h0/* 0*/};
  assign T181 = reset ? 1'h0/* 0*/ : T182;
  assign T182 = T183;
  assign T183 = T185 < T184;
  assign T184 = op;
  assign T185 = {2'h0/* 0*/, 1'h1/* 1*/};
  assign T186 = {31'h0/* 0*/, 1'h0/* 0*/};
  assign T187 = operand1_exe;
  assign T188 = subtract_sel_mem;
  assign subtract_sel_mem = T189;
  assign T189 = subtract_sel_exe;
  assign subtract_sel_exe = T190;
  assign T190 = subtract_sel;
  assign subtract_sel = T191;
  assign T191 = T192;
  assign T192 = T33;
  assign T193 = T194;
  assign T194 = T199 ? T196 : T195;
  assign T195 = {3'h0/* 0*/, 1'h0/* 0*/};
  assign T196 = rd_mem;
  assign rd_mem = T197;
  assign T197 = rd_exe;
  assign rd_exe = T198;
  assign T198 = rd;
  assign T199 = subtract_sel_mem;
  assign T200 = T201;
  assign T201 = T203 ? T202 : 1'h0/* 0*/;
  assign T202 = subtract_sel_mem;
  assign T203 = T204;
  assign T204 = T208 && T205;
  assign T205 = ~ PipeStage_Stall_3;
  assign PipeStage_Stall_3 = T206;
  assign T206 = ~ T207;
  assign T207 = PipeStage_Valid_0 == PipeStage_Valid_0;
  assign T208 = subtract_sel_mem && PipeStage_Valid_3;
  assign T209 = T210;
  assign T210 = T211;
  assign T211 = T212;
  assign T212 = T219 ? T214 : T213;
  assign T213 = {31'h0/* 0*/, 1'h0/* 0*/};
  assign T214 = adder_out_mem;
  assign adder_out_mem = T215;
  assign T215 = adder_out_exe;
  assign adder_out_exe = T216;
  assign T216 = adder_out;
  assign adder_out = T217;
  assign T217 = T218;
  assign T218 = T144;
  assign T219 = adder_sel_mem;
  assign adder_sel_mem = T220;
  assign T220 = adder_sel_exe;
  assign adder_sel_exe = T221;
  assign T221 = adder_sel;
  assign adder_sel = T222;
  assign T222 = T223;
  assign T223 = T70;
  assign T224 = T225;
  assign T225 = T228 ? T227 : T226;
  assign T226 = {3'h0/* 0*/, 1'h0/* 0*/};
  assign T227 = rd_mem;
  assign T228 = adder_sel_mem;
  assign T229 = T230;
  assign T230 = T232 ? T231 : 1'h0/* 0*/;
  assign T231 = adder_sel_mem;
  assign T232 = T233;
  assign T233 = T235 && T234;
  assign T234 = ~ PipeStage_Stall_3;
  assign T235 = adder_sel_mem && PipeStage_Valid_3;
  assign T236 = io_read_addr;
  assign T237 = rs2;
  assign rs2 = T238;
  assign T238 = T239;
  assign T239 = Stage_1_PipeReg_11[3'h7/* 7*/:3'h4/* 4*/];
  assign T240 = reset ? T242 : T241;
  assign T241 = inst;
  assign T242 = {31'h0/* 0*/, 1'h0/* 0*/};
  assign T243 = rs1;
  assign rs1 = T244;
  assign T244 = T245;
  assign T245 = Stage_1_PipeReg_22[4'hb/* 11*/:4'h8/* 8*/];
  assign T246 = reset ? T248 : T247;
  assign T247 = inst;
  assign T248 = {31'h0/* 0*/, 1'h0/* 0*/};
  assign T249 = reset ? T251 : T250;
  assign T250 = pc_reg;
  assign T251 = {3'h0/* 0*/, 1'h0/* 0*/};
  assign io_read_data = T252;
  assign T252 = regfile_io_reads_2_dat;
  TICache imem(.clk(clk), .reset(reset),
       .io_req_valid( 1'h1/* 1*/ ),
       .mem_addr( Stage_0_PipeReg_14 ),
       .io_resp( imem_io_resp )
  );
  TransactionMem regfile(.clk(clk),
       .io_reads_0_adr( T243 ),
       .io_reads_0_dat( regfile_io_reads_0_dat ),
       .io_reads_1_adr( T237 ),
       .io_reads_1_dat( regfile_io_reads_1_dat ),
       .io_reads_2_adr( T236 ),
       .io_reads_2_dat( regfile_io_reads_2_dat ),
       .io_writes_0_is( T229 ),
       .io_writes_0_adr( T224 ),
       .io_writes_0_dat( T209 ),
       .io_writes_1_is( T200 ),
       .io_writes_1_adr( T193 ),
       .io_writes_1_dat( T0 )
  );

  always @(posedge clk) begin
    Stage_2_PipeReg_8 <= T14;
    Stage_2_PipeReg_13 <= T23;
    Stage_1_PipeReg_12 <= T24;
    Stage_2_PipeReg_19 <= T35;
    Stage_1_PipeReg_18 <= T36;
    Stage_2_PipeReg_10 <= T44;
    Stage_1_PipeReg_9 <= T45;
    if(T51) begin
      Stage_2_valid_reg <= T142;
    end
    Stage_2_PipeReg_17 <= T74;
    Stage_1_PipeReg_16 <= T75;
    Stage_2_PipeReg_7 <= T85;
    Stage_1_PipeReg_6 <= T86;
    if(T92) begin
      Stage_1_valid_reg <= T95;
    end
    if(T98) begin
      Stage_0_valid_reg <= T100;
    end
    Stage_1_PipeReg_3 <= T105;
    Stage_0_PipeReg_2 <= T106;
    if(reset) begin
      pc_reg <= 4'h0/* 0*/;
    end else if(T113) begin
      pc_reg <= T126;
    end
    Stage_1_PipeReg_20 <= T116;
    Stage_1_PipeReg_1 <= T123;
    Stage_1_PipeReg_5 <= T134;
    spec_write_data_reg_pc_reg_1 <= spec_write_data_reg_pc_reg_0;
    spec_write_data_reg_pc_reg_0 <= pc_plus4;
    Stage_2_PipeReg_15 <= T149;
    Stage_1_PipeReg_0 <= T168;
    Stage_1_PipeReg_4 <= T178;
    Stage_1_PipeReg_21 <= T181;
    Stage_1_PipeReg_11 <= T240;
    Stage_1_PipeReg_22 <= T246;
    Stage_0_PipeReg_14 <= T249;
  end
endmodule
