package Hello 
 
import Chisel._ 
import scala.collection.mutable.HashMap

/*
class Hello extends Module {
  val io = new Bundle { 
    val read_data = UInt(OUTPUT, 4)
    val read_addr = Bits(INPUT, 4)
  }
  val a = Reg(init=Bits(3))
  
  val b = Bits()
  b := a + io.read_addr
  
  val c = Bits()
  c := b + Bits(3)
  
  val d = Bits()
  d := b - Bits(3)
  
  val e = Bits()
  e := c
  
  val f = Bits()
  f := e + Bits(4)
  
  val g = Bits()
  g := f + Bits(5)
  
  val h = Bits()
  h := g + Bits(5)
  
  val i = Bits()
  i := h + Bits(5)
  
  val z = Bits()
  z := a + Bits(4)
  
  val y = Bits()
  y := z + Bits(5)
  
  val x = Bits()
  x := y + Bits(3)
  
  val w = Bits()
  w := x + Bits(2)
  
  val v = Bits()
  v := w + Bits(1)
  
  val u = Bits()
  u := v + Bits(2)
  
  val j = Bits()
  j := i + u
  
  a := j
  io.read_data := b
  
  Module.pipelineComponent = this
  Module.annotateNodeStage(a.comp, 0)
  Module.annotateNodeStage(i, 1)
  Module.annotateNodeStage(j, 4)
  Module.annotateNodeStage(io.read_addr, 0)
  Module.annotateNodeStage(io.read_data, 0)
  
}*/


class Hello extends Module {
  val io = new Bundle { 
    val read_data = UInt(OUTPUT, 32)
    val read_addr = Bits(INPUT, 4)
  }

  val pc_reg = Reg(init = UInt(0,4))
  val pc_plus4 = UInt()
  pc_plus4 := pc_reg + UInt(1)
  val pc_plus4_exe = UInt()
  pc_plus4_exe := pc_plus4
  val pc_plus4_mem = UInt()
  pc_plus4_mem := pc_plus4_exe
  
  val imem = Module(new TICache())
  imem.io.req.valid := Bool(true)
  imem.io.req.bits := pc_reg
  
  val inst = Bits()
  inst := imem.io.resp

  val rs1 = Bits()
  val rs2 = Bits()
  val rd = Bits()
  val op = Bits()
  val imm = Bits()
  rs1 := inst(11,8)
  rs2 := inst(7,4)
  rd := inst(3,0)
  op := inst(14,12)
  imm := Cat(Bits(0,15), inst(31,15))
  
  val isJmp = Bool()
  isJmp := op === UInt(6)
  val isNotJmp = Bool()
  isNotJmp := ~(op === UInt(6))
  when(isNotJmp){
    pc_reg := pc_plus4_mem
  }
  val jmpTarget = Bits()
  jmpTarget := imm(3,0)
  when(isJmp){
    pc_reg := jmpTarget
  }
  val rd_exe = Bits()
  rd_exe := rd
  val rd_mem = Bits()
  rd_mem := rd_exe
  
  val regfile = Module(new TransactionMem(16, 3, 2, 1)(Bits(width = 32)))
  val rs1_data = UInt()
  val rs2_data = UInt()
  rs1_data := regfile.read(rs1, 0)
  rs2_data := regfile.read(rs2, 1)
  io.read_data := regfile.read(io.read_addr, 2)
  
  val operand1 = UInt()
  operand1 := rs1_data
  when(op === UInt(4)){
    operand1 := UInt(0)
  }
  val operand2 = UInt()
  operand2 := rs2_data
  when(op > UInt(1)){
    operand2 := imm
  }
  
  val operand1_exe = UInt()
  val operand2_exe = UInt()
  operand1_exe := operand1
  operand2_exe := operand2
  
  val adder_out = UInt()
  val subtract_out = UInt()
  adder_out := operand1_exe + operand2_exe
  subtract_out := operand1_exe - operand2_exe
  val adder_out_exe = UInt()
  val subtract_out_exe = UInt()
  adder_out_exe := adder_out
  subtract_out_exe := subtract_out
  val adder_out_mem = UInt()
  val subtract_out_mem = UInt()
  adder_out_mem := adder_out_exe
  subtract_out_mem := subtract_out_exe
  
  val adder_sel = Bool()
  val subtract_sel = Bool()
  adder_sel := (op === UInt(0)) || (op === UInt(2) || (op === UInt(4)))
  subtract_sel := (op === UInt(1)) || (op === UInt(3))

  val adder_sel_exe = Bool()
  val subtract_sel_exe = Bool()
  adder_sel_exe := adder_sel
  subtract_sel_exe := subtract_sel
  val adder_sel_mem = Bool()
  val subtract_sel_mem = Bool()
  adder_sel_mem := adder_sel_exe
  subtract_sel_mem := subtract_sel_exe
  
  when(adder_sel_mem){
    regfile.write(rd_mem, adder_out_mem, 0)
  }
  when(subtract_sel_mem){
    regfile.write(rd_mem, subtract_out_mem, 1)
  }
  
  //automatic pipelining specification
  //limit automatic pipelining to this Component(the dpath)
  Module.pipelineComponent = this
  
  /*Module.annotateNodeStage(pc_reg, 0)
  Module.annotateNodeStage(pc_plus4, 0)
  Module.annotateNodeStage(pc_plus4_exe, 1)
  Module.annotateNodeStage(isNotJmp,2)
  Module.annotateNodeStage(pc_plus4_mem, 2)
  Module.annotateNodeStage(isJmp, 2)
  Module.annotateNodeStage(jmpTarget, 2)
  
  Module.annotateNodeStage(rs1_data, 0)
  Module.annotateNodeStage(rs2_data, 0)
  Module.annotateNodeStage(io.read_data, 0)
  Module.annotateNodeStage(rs1, 0)
  Module.annotateNodeStage(rs2, 0)
  Module.annotateNodeStage(io.read_addr, 0)
  
  Module.annotateNodeStage(rd, 0)
  Module.annotateNodeStage(adder_sel, 0)
  Module.annotateNodeStage(subtract_sel, 0)
  Module.annotateNodeStage(adder_out, 0)
  Module.annotateNodeStage(subtract_out, 0)
  
  Module.annotateNodeStage(rd_exe, 1)
  Module.annotateNodeStage(adder_sel_exe, 1)
  Module.annotateNodeStage(subtract_sel_exe, 1)
  Module.annotateNodeStage(adder_out_exe, 1)
  Module.annotateNodeStage(subtract_out_exe, 1)
  
  Module.annotateNodeStage(rd_mem, 2)
  Module.annotateNodeStage(adder_sel_mem, 2)
  Module.annotateNodeStage(subtract_sel_mem, 2)
  Module.annotateNodeStage(adder_out_mem, 2)
  Module.annotateNodeStage(subtract_out_mem, 2)
  
  Module.speculate(pc_reg.comp.asInstanceOf[Reg], pc_plus4)
  //Module.addForwardedReg(pc_reg.comp.asInstanceOf[Reg])
  Module.addForwardedMemReadPort(regfile, regfile.io.reads(0))
  Module.addForwardedMemReadPort(regfile, regfile.io.reads(1))*/
  
  Module.annotateNodeStage(pc_reg, 0)
  Module.annotateNodeStage(pc_plus4, 0)
  Module.annotateNodeStage(isNotJmp,2)
  Module.annotateNodeStage(pc_plus4_mem, 2)
  Module.annotateNodeStage(isJmp, 2)
  Module.annotateNodeStage(jmpTarget, 2)
  
  Module.annotateNodeStage(imem.io.req.valid, 1)
  Module.annotateNodeStage(imem.io.req.bits, 1)
  Module.annotateNodeStage(imem.io.resp, 1)
  Module.annotateNodeStage(imem.req_ready, 1)
  Module.annotateNodeStage(imem.resp_ready, 1)
  Module.annotateNodeStage(imem.resp_valid, 1)
  
  Module.annotateNodeStage(rs1_data, 2)
  Module.annotateNodeStage(rs2_data, 2)
  Module.annotateNodeStage(io.read_data, 2)
  Module.annotateNodeStage(rs1, 2)
  Module.annotateNodeStage(rs2, 2)
  Module.annotateNodeStage(io.read_addr, 2)
  
  Module.annotateNodeStage(rd_mem, 3)
  Module.annotateNodeStage(adder_sel_mem, 3)
  Module.annotateNodeStage(subtract_sel_mem, 3)
  Module.annotateNodeStage(adder_out_mem, 3)
  Module.annotateNodeStage(subtract_out_mem, 3)
  
  Module.speculate(pc_reg.comp.asInstanceOf[Reg], pc_plus4)
  //Module.addForwardedReg(pc_reg.comp.asInstanceOf[Reg])
  Module.addForwardedMemReadPort(regfile, regfile.io.reads(0))
  Module.addForwardedMemReadPort(regfile, regfile.io.reads(1))
  
  //specify number of stages
  //Module.setNumStages(2)
  
  //specify partitions for 1st pipeline register
  //Module.addPipeReg(0, operand1, UInt(0))
  //Module.addPipeReg(0, operand2, UInt(0))
  //Module.addPipeReg(0, adder_sel, Bool(false))
  //Module.addPipeReg(0, subtract_sel, Bool(false))
  //Module.addPipeReg(0, rd, UInt(0))
}

class HelloTests(c: Hello) extends Tester(c, Array(c.io)) {
  defTests {
    val vars = new HashMap[Node, Node]()
    var all_correct = true
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(15)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(0)
    vars(c.io.read_data) = UInt(1)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(1)
    vars(c.io.read_data) = UInt(2)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(3)
    vars(c.io.read_data) = UInt(2)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(4)
    vars(c.io.read_data) = UInt(2)
    all_correct = step(vars) && all_correct
    
    all_correct
  }
}

object Hello {
  def main(args: Array[String]): Unit = {
    if(args(0) == "-ctest"){
      chiselMainTest(args.slice(1, args.length) ++ Array("--backend", "c", "--genHarness", "--compile", "--test", "--vcd", "--debug"), () => Module(new Hello())) {
        c => new HelloTests(c) }
    } else if(args(0) == "-vbuild"){
      chiselMain(args.slice(1,args.length) ++ Array("--backend", "v"), () => Module(new Hello()))
    } else if(args(0) == "-backannotation"){
      chiselMain(args.slice(1,args.length) ++ Array("--backend", "MyBackend.MyBackend"), () => Module(new Hello()))
    }
  }
}
