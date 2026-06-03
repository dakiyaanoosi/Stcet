module mux4to1(input [3:0] I, input [1:0] S, output Y);

    assign Y = (~S[1] & ~S[0] & I[0]) |
           (~S[1] &  S[0] & I[1]) |
           ( S[1] & ~S[0] & I[2]) |
           ( S[1] &  S[0] & I[3]);

endmodule

module mux8to1(input [7:0] I, input [2:0] S, output Y);

    wire Y0, Y1;

    mux4to1 M1(.I(I[3:0]), .S(S[1:0]), .Y(Y0));

    mux4to1 M2(.I(I[7:4]), .S(S[1:0]), .Y(Y1));

    assign Y = (~S[2] & Y0) | (S[2] & Y1);

endmodule