package Hello 
 
import Chisel._ 
import scala.collection.mutable.HashMap

class Hello extends Module {
  val io = new Bundle { 
    val read_data = UInt(OUTPUT, 32)
    val read_addr = Bits(INPUT, 4)
  }

  val pc_reg = Reg(init = UInt(0,4))
  val pc_plus4 = UInt()
  pc_plus4 := pc_reg + UInt(1)
  pc_reg := pc_plus4
  
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
  
  val regfile = Module(new TransactionMem(8, 3, 2, 1)(Bits(width = 32)))
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
  val adder_out = UInt()
  val subtract_out = UInt()
  adder_out := operand1 + operand2
  subtract_out := operand1 - operand2
  
  val adder_sel = Bool()
  val subtract_sel = Bool()
  adder_sel := (op === UInt(0)) || (op === UInt(2))
  subtract_sel := (op === UInt(1)) || (op === UInt(3))
  
  when(adder_sel){
    regfile.write(rd, adder_out, 0)
  }
  when(subtract_sel){
    regfile.write(rd, subtract_out, 1)
  }
  
  val operand1_init = UInt(0)
  val operand2_init = UInt(0)
  val adder_sel_init = Bool(false)
  val subtract_sel_init = Bool(false)
  //automatic pipelining specification
  //specify number of stages
  Module.setNumStages(2)
  
  //limit automatic pipelining to this Component(the dpath)
  Module.pipelineComponent = this
  
  //specify partitions for 1st pipeline register
  Module.addPipeReg(0, operand1, operand1_init)
  Module.addPipeReg(0, operand2, operand2_init)
  Module.addPipeReg(0, adder_sel, adder_sel_init)
  Module.addPipeReg(0, subtract_sel, subtract_sel_init)
}

class HelloTests(c: Hello) extends Tester(c, Array(c.io)) {
  defTests {
    val vars = new HashMap[Node, Node]()
    var all_correct = true
    
    vars(c.io.read_addr) = UInt(0)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(0)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(0)
    all_correct = step(vars) && all_correct
    
    vars(c.io.read_addr) = UInt(0)
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
    
    
    all_correct
  }
}

object Hello {
  def main(args: Array[String]): Unit = {
    val args = Array("--backend", "c", "--genHarness", "--compile", "--test", "--vcd", "--debug")
    chiselMainTest(args, () => Module(new Hello())) {
      c => new HelloTests(c) }
  }
}
