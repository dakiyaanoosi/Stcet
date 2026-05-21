module mux4x1_tb;
	reg [1:0]s;
	reg [3:0]a;
	wire f;
	integer i;
	
	
	mux4x1 uut(.s(s), .a(a), .f(f));

	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0, mux4x1_tb);

		a=4'b1011;

		for(i=0; i<3; i=i+1) begin
			s=i; #10;
		end
		s=2'b11; #10;
	end
endmodule