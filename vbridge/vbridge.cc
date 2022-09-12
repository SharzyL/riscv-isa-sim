#include "VV.h"
#include "verilated.h"

#include "vbridge.h"

void setup() {
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  Vour* top = new Vour{contextp};
  while (!contextp->gotFinish()) { top->eval(); }
  delete top;
  delete contextp;
  return 0;
}