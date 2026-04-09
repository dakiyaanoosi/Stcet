module not_gate_tb;
  reg a;
  wire y;
  
  not_gate uut(.a(a), .y(y));
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars(0, not_gate_tb);
    a=0;
    #10;
    
    a=1;
    #10;
  end
endmodule