module majority_circuit_tb;
    reg [2:0]A;
    wire Z;
    integer i;

    majority_circuit uut(.A(A), .Z(Z));

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, majority_circuit_tb);

        for (i=0; i<7; i=i+1) begin
            A=i; #10;
        end
        A=3'b111; #10;
    end
endmodule
