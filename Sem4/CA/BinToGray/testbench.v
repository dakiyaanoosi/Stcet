module binaryToGray_tb;
	reg [3:0]B;
	wire [3:0]G;
	integer i;
	
	binaryToGray uut(.B(B), .G(G));
	
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0, binaryToGray_tb);
	
		for(i=0; i<16; i=i+1) begin
			B=i; #10;
		end
	end
endmodule