#include "VV.h"
#include "verilated.h"

#include "vbridge.h"

VBridge vbridge;

struct VBridgeImpl {
  std::unique_ptr<VerilatedContext> ctx;
  std::unique_ptr<VV> top;

  void setup(int argc, char **argv);
  bool is_ready();
  v_resp step(const v_req &req);
};

void VBridgeImpl::setup(int argc, char **argv) {
  ctx = std::make_unique<VerilatedContext>();
  ctx->commandArgs(argc, argv);
  top = std::make_unique<VV>(ctx.get());
}

v_resp VBridgeImpl::step(const v_req &req) {
  if (top->req_ready) {
    top->req_bits_inst = req.insn_bits;
    top->req_bits_src1Data = req.rs1_data;
    top->req_valid = true;
  }
  top->eval();
  return v_resp{.rd_data = top->resp_bits_data, .valid = (bool) top->resp_valid};
}

bool VBridgeImpl::is_ready() {
  return top->req_ready;
}

void VBridge::setup(int argc, char **argv) {
  impl->setup(argc, argv);
}

v_resp VBridge::step(const v_req &req) {
  v_resp resp;
  while (true) {
    bool ready = impl->is_ready();
    resp = impl->step(req);
    if (ready) break;
  }
  return resp;
}

VBridge::VBridge(): impl(new VBridgeImpl) {}

VBridge::~VBridge() {
  delete impl;
}
