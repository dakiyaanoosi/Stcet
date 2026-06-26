module functionDecoder_tb;

        reg A, B, C;
        wire F1, F2, F3;
        integer i;

        functionDecoder uut(
                .A(A),
                .B(B),
                .C(C),
                .F1(F1),
                .F2(F2),
                .F3(F3)
        );

        initial begin
                $dumpfile("dump.vcd");
                $dumpvars(0, functionDecoder_tb);

                for(i=0; i<8; i=i+1) begin
                        {A,B,C} = i;
                        #10;
                end
        end

endmodule