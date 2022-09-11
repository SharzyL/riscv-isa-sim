#ifndef _RISCV_VBRIDGE_H
#define _RISCV_VBRIDGE_H

#include "../riscv/disasm.h"

uint32_t clip(uint32_t binary, int a, int b) { return (binary >> a) & ((1 << (b - a + 1)) - 1); }

bool is_vector_instr(insn_fetch_t *f) {
  uint32_t opcode = clip(f->insn.bits(), 0, 6);

  if ((opcode & 0b1011111) == 0b0000111 || opcode == 0b1010111) {
    return true;
  } else {
    return false;
  }
}

struct v_req {
  uint32_t rd_data;
};

struct v_resp {
  uint32_t insn_bits;
  uint32_t rs1_data;
  uint32_t rs2_data;
  bool sb_clear;
};

#endif
