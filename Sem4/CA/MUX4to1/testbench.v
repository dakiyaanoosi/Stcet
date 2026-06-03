module mux4to1_tb;

    reg [3:0] I;
    reg [1:0] S;
    wire Y;

    integer i;

    mux4to1 uut(.I(I), .S(S), .Y(Y));

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, mux4to1_tb);

        I = 4'b1010;

        for (i = 0; i < 4; i = i + 1) begin
            S = i;
            #10;
        end
        #10;
    end

endmodule