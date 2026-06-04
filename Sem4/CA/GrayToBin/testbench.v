module grayToBin_tb;
	reg [3:0]G;
	wire [3:0]B;
	integer i;
	
	grayToBin uut(.G(G), .B(B));
	
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0, grayToBin_tb);
	
		for(i=0; i<16; i=i+1) begin
			G=i; #10;
		end
	end
endmodule