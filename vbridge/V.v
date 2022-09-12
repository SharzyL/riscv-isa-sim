module V(
  input         clock,
  input         reset,
  output        req_ready,
  input         req_valid,
  input  [31:0] req_bits_inst,
  input  [31:0] req_bits_src1Data,
  output        resp_valid,
  output [31:0] resp_bits_data,
  input  [9:0]  csrInterface_vl,
  input  [9:0]  csrInterface_vStart,
  input  [2:0]  csrInterface_vlmul,
  input  [1:0]  csrInterface_vSew,
  input  [1:0]  csrInterface_vxrm,
  input         csrInterface_vta,
  input         csrInterface_vma,
  input         storeBufferClear
);
  assign req_ready = 1'h0; // @[V.scala 24:13]
  assign resp_valid = 1'h0; // @[V.scala 25:14]
  assign resp_bits_data = 32'h0; // @[V.scala 26:18]
endmodule
