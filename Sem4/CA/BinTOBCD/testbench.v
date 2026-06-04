module binaryToBCD_tb;
	reg [3:0]B;
	wire [4:0]Y;
	integer i;
	
	binaryToBCD uut(.B(B), .Y(Y));

	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0, binaryToBCD_tb);
	
		for(i=0; i<15; i=i+1) begin
			B=i; #10;
		end
	end
endmodule