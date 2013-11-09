package Counters

import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap
import scala.collection.mutable.LinkedHashMap
import scala.collection.mutable.Queue
import scala.collection.mutable.Stack
import Chisel._
import Node._
import Reg._
import Counters._

object Counters {
  val cntrPipePins = new ArrayBuffer[UInt]()
  var counterRegs = LinkedHashMap[Reg, Bits]() //reg -> counter reg
  val nodes = new LinkedHashMap[Bits, Node]() //counters -> node being counted

  def collectRegsAndBits(m : Module) : LinkedHashMap[Reg, Bits] = {
    val regsToProbe = new LinkedHashMap[Reg, Bits]() //reg -> its own data node
    m.bfs {node =>
      //println("IAN: node " + node.name)
      if(node.isTypeNode && node.getNode.isInstanceOf[Reg]){
        regsToProbe += (node.getNode.asInstanceOf[Reg] -> node.asInstanceOf[Bits])
          //println("IAN: regToProbe " + node.inputs(0).getNode)
          //println("IAN: regToProbe bits " + node.inputs(0).getNode)
      }
    }
    return regsToProbe
  }

  // let's just track enables first...
  def addCounters (m : Module) = {
    println("IAN: place counters")
    val regsToProbe = collectRegsAndBits(m)
    for(((reg, bits), i) <- regsToProbe.zipWithIndex){
      if (reg.isEnable) {
        val cntr = Reg(init=UInt(0, 32))
        when(reg.enable){
          cntr := cntr + UInt(1)
        }
        cntr.getNode.setName("cntr" + i)
        counterRegs += (reg -> cntr)
        nodes += (cntr -> reg)
      }
    }

    m.genAllMuxes
    Module.backend.collectNodesIntoComp(Module.backend.initializeDFS)
  }

  def addEnableCounters() = {
    println("called")
    Module.backend.preElaborateTransforms += ((c: Module) => addCounters(c))
  }

  def addCounterPin(c: Module) = {
    for ((reg, cntr) <- counterRegs) {
      //cntr.setName(reg.name + "_cntr")
      //cntr.width_ = (reg.width_ << 5)
      //cntr.component = reg.componentOf
      //cntr.clock = reg.clock
      //cntr.genMuxes(cntr)
      //println("IAN: addCounterPin counter " + cntr)
      //println("IAN: addCounterPin counter input " + cntr.inputs(0).getNode)
      //println("IAN: addCounterPin cntr.component " + cntr.componentOf)
      //println("IAN: addCounterPin cntr " + cntr.name)
      //println("IAN: -----------------------------------")
      connectCounterPin(c, reg.component, cntr.getNode.asInstanceOf[Reg], cntr)  
    }
  }

  def connectCounterPin(topC: Module, c: Module, cntr: Reg, p: Node): Unit = {
    assert(topC != null, "topC")
    assert(c != null, "c")
    assert(p != null, "p")

    val pin = UInt(OUTPUT); pin.init("", (n: Node) => cntr.width)
    pin.isIo = true
    pin.inputs += p
    //println(c.name + "_" + p.name)
    //println("pin input: " + compInitPin.inputs(0).getNode)  
    pin.setName("io_" + cntr.name)
    c.io.asInstanceOf[Bundle] += pin
    pin.component = c
    cntrPipePins += pin
    if(c != topC){
      //println("recursive calling")
      connectCounterPin(topC, c.parent, cntr, pin)
    }
  }

  def addPin(module: Module, dir: IODirection, width: Int, name: String): UInt = {
    val pin = UInt(dir, width)
    pin.isIo = true
    pin.setName(name)
    pin.component = module
    module.io.asInstanceOf[Bundle] += pin
    pin
  }

  def getPin(module: Module, string: String): UInt =
    module.io.asInstanceOf[Bundle](string).asInstanceOf[UInt]

  def addPins(modules: ArrayBuffer[Module], dir: IODirection, width: Int, name: String) {
    val walked = new ArrayBuffer[Module]()
    for (module <- modules) {
      if (!walked.contains(module)) {
        walked += module
        var child = module
        var pin = addPin(module, dir, width, name)
        var parent = child.parent
        while (parent != null) {
          if (walked.contains(parent)) {
            if (dir == INPUT)
              pin.inputs += getPin(parent, name)
            else if (dir == OUTPUT)
              getPin(parent, name).inputs += pin
            else {

            }
            parent = null
          } else {
            walked += parent
            val nextPin = addPin(parent, dir, width, name)
            if (dir == INPUT)
              pin.inputs += nextPin
            else if (dir == OUTPUT)
              nextPin.inputs += pin
            else {

            }
            child = parent
            parent = child.parent
            pin = nextPin
          }
        }
      }
    }
  }

  def getModulesWithCntr(): ArrayBuffer[Module] = {
    val res = new ArrayBuffer[Module]
    for ((reg, cntr) <- counterRegs)
      if (!res.contains(reg.component))
        res += reg.component
    res
  }

/* ----------------------------------------
          .-~~-.--.                         
         :         )
 .~ ~ -.\       /.- ~~ .
 >       `.   .'       <
(         .- -.         )
 `- -.-~  `- -'  ~-.- -'
   (        :        )           _ _ .-:
    ~--.    :    .--~        .-~  .-~  }
        ~-.-^-.-~ \_      .~  .-~   .~
                 \ \'     \ '_ _ -~
                  `.`.    //
         . - ~ ~-.__`.`-.//
     .-~   . - ~  }~ ~ ~-.~-.
   .' .-~      .-~       :/~-.~-./:
  /_~_ _ . - ~                 ~-.~-._
                                   ~-.<
                                            
---------------------------------------- */
  
  def getDaisyControlPin(module: Module): UInt =
    getPin(module, "io_daisy_control")

  def addDaisyControlPins() =
    addPins(getModulesWithCntr(), INPUT, 2, "io_daisy_control")

  def addDaisyOutPin(module: Module) =
    addPin(module, OUTPUT, 1, "io_daisy_out")

  def addDaisyInPin(module: Module) =
    addPin(module, INPUT, 1, "io_daisy_in")

  def addDaisyOut() {
    val walked = new ArrayBuffer[Module]
    for (module <- getModulesWithCntr())
      if (!walked.contains(module)) {
        walked += module   
        addDaisyOutPin(module)
        var parent = module.parent
        while (parent != null && !walked.contains(parent)) {
          walked += parent
          addDaisyOutPin(parent)
          parent = parent.parent
        }
      }
  }

  def hasDaisyOutPin(module: Module): Boolean =
    module.io.asInstanceOf[Bundle].contains("io_daisy_out")
  
  def getDaisyOutPin(module: Module): UInt =
    getPin(module, "io_daisy_out")

  def hasDaisyInPin(module: Module): Boolean =
    module.io.asInstanceOf[Bundle].contains("io_daisy_in")

  def getDaisyInPin(module: Module): UInt =
    getPin(module, "io_daisy_in")

  def addDaisyIn() {
    val modulesWithCntr = getModulesWithCntr()
    val queue = new Queue[Module]
    queue.enqueue(Module.topComponent)
    while (!queue.isEmpty) {
      val module = queue.dequeue
      val children = module.children.filter(hasDaisyOutPin(_))
      if (children.length > 1) { // create daisy chain connecting all modules
        children.tail.map(m => addDaisyInPin(m))
      }
      if (children.length > 0 && modulesWithCntr.contains(module)) { // add module's cntr to beginning of daisy chain
        addDaisyInPin(children(0))
      }
      queue ++= children
    }
  }

  def hasDaisyIn(module: Module): Boolean =
    module.io.asInstanceOf[Bundle].contains("io_daisy_in")

  def isShift(daisyControl: UInt): Bool = daisyControl(0)
  def isCopy(daisyControl: UInt): Bool = daisyControl(1)

  // create and return mapping cntr -> cntr's shadow
  def addDaisies(): LinkedHashMap[Bits, Bits] = {
    val res = new LinkedHashMap[Bits, Bits]
    for ((reg, cntr) <- counterRegs) {
      println("HUY: This is a hack, fix it soon!!")
      cntr.getNode.infer
      val shadow = Reg(UInt(width = cntr.getNode.width))
      shadow.getNode.infer
      shadow.getNode.setName(cntr.getNode.name + "_daisy")
      when(isCopy(getDaisyControlPin(reg.component))) {
        shadow := cntr
      }
      res += (cntr -> shadow)
    }
    res
  }

  // creates neighborhood of cntrs in the same component
  def getCntrNeighborhoods(): LinkedHashMap[Module, ArrayBuffer[Bits]] = {
    val res = new LinkedHashMap[Module, ArrayBuffer[Bits]]
    for ((reg, cntr) <- counterRegs) {
      if (!res.contains(reg.component))
        res += (reg.component -> new ArrayBuffer[Bits])
      res(reg.component) += cntr
    }
    res
  }

  // data structure for tracking scan chain ordering
  // module -> list of counters in order they are connected in chain
  // to compute final order, walk module tree from parent to child
  // parent's chain appears first, then child, depth first
  val scanOrdering = new LinkedHashMap[Module, ArrayBuffer[Bits]]
  def printOrdering() {
    val stack = new Stack[Module]
    val out = Module.backend.createOutputFile("scanordering")
    stack.push(Module.topComponent)
    val res = new StringBuilder("")
    while (!stack.isEmpty) {
      val module = stack.pop
      for (cntr <- scanOrdering(module)) {
        val node = nodes(cntr)
        res.insert(0, cntr.getNode.width + " " + Module.backend.emitRef(node) + "\n")
      }
      for (child <- module.children.filter(hasDaisyOutPin(_)))
        stack.push(child)
    }
    out.write(res.result())
    out.close()
  }

  def doShift(enable: Bool, lhs: Bits, rhs: Bits) {
    val wl = lhs.getNode.width
    val wr = rhs.getNode.width
    when (enable) {
      if (wr > 1) {
        lhs := Cat(lhs(wl-2,0), rhs(wr-1))
      } else if (wr == 1) {
        lhs := Cat(lhs(wl-2,0), rhs)
      } else {
        assert(false)
      }
    }
  }

  def connectDaisy(port: Bits, daisy: Bits) {
    val w = daisy.getNode.width
    port.inputs += daisy(w-1)
  }

  def connectDaisies() {
    val daisiesSets = addDaisies()
    val neighborhoods = getCntrNeighborhoods()
    val queue = new Queue[Module]
    queue.enqueue(Module.topComponent)
    while (!queue.isEmpty) {
      val module = queue.dequeue
      scanOrdering += (module -> new ArrayBuffer[Bits])
      val daisies = new ArrayBuffer[Bits]()
      if (neighborhoods.contains(module)) { // connecting local daisies
        for (cntr <- neighborhoods(module)) {
          daisies += daisiesSets(cntr)
          scanOrdering(module) += cntr
        }
        val shift = isShift(getDaisyControlPin(module))
        for (i <- 1 until daisies.length) { // shifting neighbors into each other
          val daisy = doShift(shift, daisies(i), daisies(i-1))
        }
        if (hasDaisyInPin(module)) { // shift final pin in from outside
          doShift(shift, daisies(0), getDaisyInPin(module))
        } else { // current module is leaft, shift final pin in from 0
          doShift(shift, daisies(0), UInt(0,1))
        }
      }
      // daisying in and out of submodules
      val outs = module.children.filter(hasDaisyOutPin(_))
      assert(module.children.filter(x => hasDaisyInPin(x) && !hasDaisyOutPin(x)).length == 0) // can't daisy w/o daisy out
      if (outs.length > 1) // multiple children, chain them together
        for (i <- 1 until outs.length)
          getDaisyInPin(outs(i)).inputs += getDaisyOutPin(outs(i-1))
      val in: Bits = 
        if (outs.length == 0) {
          null 
        } else {
          val pin = getDaisyInPin(outs(0))
          if (pin.inputs.length == 1)
            null
          else
            pin
        }
      if (daisies.length > 0 && !(in == null)) { // local daisies, w/ children
        connectDaisy(in, daisies.last)
      } else if (daisies.length == 0 && !(in == null)) {// no local daisies, w/ children
        in.inputs += getDaisyInPin(module)
      } else if (daisies.length > 0 && in == null) { // local daisies, w/o children
        connectDaisy(getDaisyOutPin(module), daisies.last)
      } else if (daisies.length == 0 && in == null) { // no local daisies, w/o children

      }
      if (outs.length > 0) // if we have children at all, last child always goes out to top
        getDaisyOutPin(module).inputs += getDaisyOutPin(outs.last)
      queue ++= module.children.filter(m => hasDaisyInPin(m) || hasDaisyOutPin(m))
    }
  }

  def createDaisyChain(m: Module) {
    addDaisyControlPins()
    addDaisyOut()
    addDaisyIn()
    connectDaisies()
    m.genAllMuxes
    Module.backend.collectNodesIntoComp(Module.backend.initializeDFS)
  }

  def addDaisyChain() {
    println("called 2")
    Module.backend.preElaborateTransforms += ((c: Module) => createDaisyChain(c))
    Module.backend.analyses += ((c: Module) => printOrdering())
  }
}

//class CountersBackend extends VerilogBackend{
//    counter_transforms += ((c: Module) => addCounterPin(c))
//}




