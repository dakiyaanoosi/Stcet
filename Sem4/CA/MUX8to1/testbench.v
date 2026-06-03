module mux8to1_tb;

    reg [7:0] I;
    reg [2:0] S;
    wire Y;

    integer i;

    mux8to1 uut(.I(I), .S(S), .Y(Y));

    initial begin

        $dumpfile("dump.vcd");
        $dumpvars(0, mux8to1_tb);

        I = 8'b10101010;

        for(i = 0; i < 8; i = i + 1)
        begin
            S = i;
            #10;
        end
        #10;
    end

endmodule