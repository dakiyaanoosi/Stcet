module function_min_tb;
  reg [3:0]A;
  wire F;
  integer i;

  function_min uut(.A(A), .F(F));

  initial begin
    $dumpfile("dump.vcd");
    $dumpvars(0, function_min_tb);

    for(i=0; i<15; i=i+1) begin
      A=i; #10;
    end
    A=4'b1111; #10;
  end
endmodule