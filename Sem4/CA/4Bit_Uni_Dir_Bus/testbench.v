module bit4_uni_dir_bus_tb;
	reg en;
	reg [3:0]a;
	wire [3:0]y;

	bit4_uni_dir_bus uut(.en(en), .a(a), .y(y));
	initial begin
		$dumpfile("dump3.vcd");
		$dumpvars(0, bit4_uni_dir_bus_tb);
		
		en=1; a=0000; #10;
		en=1; a=1111; #10;
		en=1; a=1010; #10;
		
		en=0; a=0000; #10;
		en=0; a=1111; #10;
		en=0; a=1010; #10;
	end
endmodule
		