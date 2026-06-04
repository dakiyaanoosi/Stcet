module binaryToBCD(input [3:0]B, output [4:0]Y);
	assign Y = B <= (4'b1001) ? B : B + 5'b00110;
endmodule