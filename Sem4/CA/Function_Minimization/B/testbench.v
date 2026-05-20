module special_comb_tb;
  reg [2:0]A;
  wire [2:0]B;
  integer i;

  special_comb uut(.A(A), .B(B));

  initial begin
      $dumpfile("dump.vcd");
      $dumpvars(0, special_comb_tb);

      for(i=0; i<8; i=i+1) begin
        A=i;
      end
  end
endmodule