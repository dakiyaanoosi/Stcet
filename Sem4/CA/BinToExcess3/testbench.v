module binToExcess3_tb;
	reg [3:0]B;
	wire [3:0]X;
	integer i;

	binToExcess3 uut(.B(B), .X(X));
	
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0, binToExcess3_tb);
		
		for(i=0; i<10; i=i+1) begin
			B=i; #10;
		end
	end
endmodule
