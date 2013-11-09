package MyBackend

import Chisel._
import Counters._

trait AddCounters extends Backend {
  preElaborateTransforms += ((c: Module) => Counters.addCounters(c))
  preElaborateTransforms += ((c: Module) => Counters.createDaisyChain(c))
  analyses += ((c: Module) => Counters.printOrdering())
  // Counters.addEnableCounters()
  // Counters.addDaisyChain()
}

class MyVBackend extends VerilogBackend with AddCounters
class MyCBackend extends CppBackend with AddCounters
