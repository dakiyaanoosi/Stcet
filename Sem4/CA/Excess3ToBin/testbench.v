module excess3ToBin_tb;
	reg [3:0]X;
	wire [3:0]B;
	integer i;

	excess3ToBin uut(.X(X), .B(B));
	
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0, excess3ToBin_tb);
		
		for(i=3; i<13; i=i+1) begin
			X=i; #10;
		end
	end
endmodule