module mux4to1(input [3:0] I, input [1:0] S, output Y);

    assign Y = (~S[1] & ~S[0] & I[0]) |
            (~S[1] &  S[0] & I[1]) |
            ( S[1] & ~S[0] & I[2]) |
            ( S[1] &  S[0] & I[3]);
endmodule