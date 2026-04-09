module xor_gate_tb;
  reg a, b;
  wire y;
  
  xor_gate uut(.a(a), .b(b), .y(y));
  
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars(0, xor_gate_tb);
    
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