module twos_complementer_tb;
  reg [3:0]A;
  wire [3:0]B;
  integer i;

  twos_complementer uut(.A(A), .B(B));

    initial begin
        $dumpfile("twoscomp.vcd");
        $dumpvars(0, twos_complementer_tb);

        for(i=0; i<15; i=i+1) begin
          A=i; #10;
        end
        A=4'b1111; #10;
    end
endmodule