module twos_complementer_tb;
  reg [3:0]A;
  wire [3:0]B;

  twos_complementer uut(.A(A), .B(B));

    initial begin
        $dumpfile("twoscomp.vcd");
      	$dumpvars(0, twos_complementer_tb);

        A=4'b0000; #10;
        A=4'b0001; #10;
        A=4'b0010; #10;
        A=4'b0011; #10;
        A=4'b0100; #10;
        A=4'b0101; #10;
        A=4'b0110; #10;
        A=4'b0111; #10;
        A=4'b1000; #10;
    end
endmodule