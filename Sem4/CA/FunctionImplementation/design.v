module decoder3to8(input A, B, C, output [7:0]D);
        assign D[0] = ~A & ~B & ~C;
        assign D[1] = ~A & ~B &  C;
        assign D[2] = ~A &  B & ~C;
        assign D[3] = ~A &  B &  C;
        assign D[4] =  A & ~B & ~C;
        assign D[5] =  A & ~B &  C;
        assign D[6] =  A &  B & ~C;
        assign D[7] =  A &  B &  C;
endmodule

module functionDecoder(input A, B, C,
                       output F1, F2, F3);

        wire [7:0]D;

        decoder3to8 dec(.A(A), .B(B), .C(C), .D(D));

        assign F1 = D[2] | D[4] | D[7];
        assign F2 = D[0] | D[3];
        assign F3 = D[0] | D[2] | D[3] | D[4] | D[7];

endmodule