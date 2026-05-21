module mux4x1(input [1:0]s, input [3:0]a, output f);
	assign f= ~s[0] ? ~s[1] ? a[0] : a[1] : ~s[1] ? a[2] : a[3];
endmodule
