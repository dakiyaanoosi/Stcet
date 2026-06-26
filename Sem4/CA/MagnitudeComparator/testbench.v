module magnitudeComparator_tb;

        reg [3:0]A, B;
        wire G, L, E;
        integer i, j;

        magnitudeComparator uut(.A(A), .B(B), .G(G), .L(L), .E(E));

        initial begin
                $dumpfile("dump.vcd");
                $dumpvars(0, magnitudeComparator_tb);

                for(i=0; i<16; i=i+1) begin
                        for(j=0; j<16; j=j+1) begin
                                A = i;
                                B = j;
                                #10;
                        end
                end
        end

endmodule