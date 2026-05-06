module majority_circuit_tb;
    reg [2:0]A;
    wire Z;

    majority_circuit uut(.A(A), .Z(Z));

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, majority_circuit_tb);

        A = 3'b000; #10;
        A = 3'b001; #10;
        A = 3'b010; #10;
        A = 3'b011; #10;
        A = 3'b100; #10;
        A = 3'b101; #10;
        A = 3'b110; #10;
        A = 3'b111; #10;
    end
endmodule