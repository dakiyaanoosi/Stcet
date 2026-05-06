// Condition:
// Inputs 0–3 → Output = Input + 1
// Inputs 4–7 → Output = Input − 1

module special_comb(input [2:0]A, output [2:0]B);
	assign B = (A <= 3) ? (A + 1) : (A - 1);
endmodule