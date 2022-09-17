#ifndef _RISCV_VBRIDGE_H
#define _RISCV_VBRIDGE_H

#include <cstddef>

inline uint32_t clip(uint32_t binary, int a, int b) { return (binary >> a) & ((1 << (b - a + 1)) - 1); }

inline bool is_vector_instr(uint64_t f) {
  uint32_t opcode = clip(f, 0, 6);

  if ((opcode & 0b1011111) == 0b0000111 || opcode == 0b1010111) {
    return true;
  } else {
    return false;
  }
}

struct v_resp {
  uint32_t rd_data;
  bool valid;
};

struct v_req {
  uint32_t insn_bits;
  uint32_t rs1_data;
  uint32_t rs2_data;
  bool sb_clear;
  bool valid;
};

struct VBridgeImpl;

struct VBridge {
  VBridgeImpl *impl;
  VBridge();
  ~VBridge();
  void setup(int argc, char **argv);
  v_resp step(const v_req &req);
};

extern VBridge vbridge;

#endif
