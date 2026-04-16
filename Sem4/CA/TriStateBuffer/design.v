module tri_state(input en, input a, output y);
	assign y = (en == 1) ? a : 1'bz;
endmodule
