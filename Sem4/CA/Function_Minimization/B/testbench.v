module special_comb_tb;
  reg [2:0]A;
  wire [2:0]B;

  special_comb uut(.A(A), .B(B));

  initial begin
      $dumpfile("dump.vcd");
      $dumpvars(0, special_comb_tb);

      A=3'b000; #10;
      A=3'b001; #10;
      A=3'b010; #10;
      A=3'b011; #10;
      A=3'b100; #10;
      A=3'b101; #10;
      A=3'b110; #10;
      A=3'b111; #10;
  end
endmodule