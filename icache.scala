package Hello 
 
import Chisel._

class TICacheIo extends TransactionalBundle
{
  override val req = new ValidIO(Bits(width=4)).flip()
  override val resp = Bits(OUTPUT, 32)
}

class TICache() extends TransactionalComponent
{
  val io = new TICacheIo()
  val num_lines = 8
  val imem = Vec.fill(num_lines){Reg(Bits(width = 32))}
  for(i <- 0 until num_lines){
    imem(i) := imem(i)
  }
  when (this.reset){
    //fill in instructions
    //op = 0 => add
    //op = 1 => sub
    //op = 2 => addi
    //op = 3 => subi
    //op = 4 => seti
    //op = 5 => nop
    imem(0) := Cat(Bits(0,17), Bits(4,3), Bits(0,4), Bits(0,4), Bits(0,4)) //r0 = 0
    imem(1) := Cat(Bits(0,17), Bits(4,3), Bits(1,4), Bits(0,4), Bits(1,4)) //r1 = 0
    imem(2) := Cat(Bits(1,17), Bits(2,3), Bits(0,4), Bits(0,4), Bits(0,4)) //r0 = r0 + 1
    imem(3) := Cat(Bits(2,17), Bits(2,3), Bits(1,4), Bits(0,4), Bits(1,4)) //r1 = r1 + 2
    imem(4) := Cat(Bits(0,17), Bits(0,3), Bits(0,4), Bits(1,4), Bits(2,4)) //r2 = r0 + r1
    imem(5) := Cat(Bits(0,17), Bits(1,3), Bits(2,4), Bits(0,4), Bits(3,4)) //r3 = r2 - r0
    imem(6) := Cat(Bits(0,17), Bits(5,3), Bits(0,4), Bits(0,4), Bits(0,4)) //r0 = r0 + 0
    imem(7) := Cat(Bits(0,17), Bits(5,3), Bits(0,4), Bits(0,4), Bits(0,4)) //r0 = r0 + 0
  }
  override val req_ready = Bool(true)
  val mem_addr = io.req.bits
  acceptBackPressure = false
  io.resp := imem(mem_addr)
  override val resp_valid = Bool(true)

}