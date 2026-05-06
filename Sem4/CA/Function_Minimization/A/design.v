// F(A, B, C, D) = Σ (0, 1, 3, 4, 8, 9, 15)

module function_min(input [3:0]A, output F);

  assign F = (~A[2] & ~A[1]) |
    (~A[3] & ~A[2] & A[0]) |
    (~A[3] & A[2] & ~A[1] & ~A[0]) |
    (A[3] & A[2] & A[1] & A[0]);
    
endmodule