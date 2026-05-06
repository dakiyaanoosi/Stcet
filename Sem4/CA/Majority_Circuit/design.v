module majority_circuit(input [2:0]A, output Z);
	assign Z = (A[2] & A[1]) | (A[1] & A[0]) | (A[2] & A[0]);
endmodule