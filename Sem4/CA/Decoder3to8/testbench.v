module decoder3to8_tb;

    reg [2:0] A;
    wire [7:0] Y;

    integer i;

    decoder3to8 uut(.A(A), .Y(Y));

    initial begin

        $dumpfile("dump.vcd");
        $dumpvars(0, decoder3to8_tb);

        for(i = 0; i < 8; i = i + 1)
        begin
            A = i;
            #10;
        end
        #10;
    end

endmodule