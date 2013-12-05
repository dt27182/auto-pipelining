`ifndef RISCV_CONST_VH
`define RISCV_CONST_VH

`define CPU_DATA_BITS 32
`define CPU_ADDR_BITS 30
`define MEM_ADDR_BITS 34
`define MEM_DATA_BITS 128
`define MEM_TAG_BITS 10

`define BR_N    4'd0
`define BR_EQ   4'd1
`define BR_NE   4'd2
`define BR_LT   4'd3
`define BR_LTU  4'd4
`define BR_GE   4'd5
`define BR_GEU  4'd6
`define BR_J    4'd7
`define BR_JR   4'd8

`define PC_4   3'd0
`define PC_BTB 3'd1
`define PC_EX4 3'd2
`define PC_BR  3'd3
`define PC_J   3'd4
`define PC_JR  3'd5

`define KF_Y  1'b1
`define KF_N  1'b0

`define REN_Y 1'b1
`define REN_N 1'b0

`define ALU0_X    3'd0
`define ALU0_0    3'd1
`define ALU0_SHA  3'd2
`define ALU0_SEXT_SPLIT 3'd3
`define ALU0_SEXT 3'd4
`define ALU0_RS2  3'd5

`define ALU1_X    1'b0
`define ALU1_RS1  1'b0
`define ALU1_LUI  1'b1

`define FN_X     4'd0
`define FN_ADD   4'd0
`define FN_SUB   4'd1
`define FN_SLT   4'd2
`define FN_SLTU  4'd3
`define FN_AND   4'd4
`define FN_OR    4'd5
`define FN_XOR   4'd6
`define FN_NOR   4'd7
`define FN_SL    4'd8
`define FN_SR    4'd9
`define FN_SRA   4'd10
`define FN_SLTX  4'd11
`define FN_SLTUX 4'd12

`define M_NO 2'b00
`define M_RD 2'b10
`define M_WR 2'b11

`define WEN_N 1'b0
`define WEN_Y 1'b1

`define WA_X  2'd1
`define WA_RD 2'd1
`define WA_1 2'd2

`define WB_X   2'd0
`define WB_PC4  2'd0
`define WB_ALU 2'd1
`define WB_MEM 2'd2
`define WB_FH  2'd3

`define THEN_N 1'b0
`define THEN_Y 1'b1

`endif // RISCV_CONST_VH
