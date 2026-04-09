module or_gate_tb;
  reg a, b;
  wire y;
  
  or_gate uut(.a(a), .b(b), .y(y));
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars(0, or_gate_tb);
    a=0;
    b=0;
    #10;
    
    a=0;
    b=1;
    #10;
    
    a=1;
    b=0;
    #10;
    
    a=1;
    b=1;
    #10;
  end
endmodule
