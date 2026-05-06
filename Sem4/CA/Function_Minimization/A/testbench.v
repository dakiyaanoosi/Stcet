module function_min_tb;
  reg [3:0]A;
  wire F;

  function_min uut(.A(A), .F(F));

  initial begin
    $dumpfile("dump.vcd");
    $dumpvars(0, function_min_tb);

    A = 4'b0000; #10;
    A = 4'b0001; #10;
    A = 4'b0011; #10;
    A = 4'b0100; #10;
    A = 4'b1000; #10;
    A = 4'b1001; #10;
    A = 4'b1111; #10;
  end
endmodule