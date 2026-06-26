module priorityEncoder_tb;

        reg [3:0]D;
        wire [1:0]Y;
        wire V;
        integer i;

        priorityEncoder uut(.D(D), .Y(Y), .V(V));

        initial begin
                $dumpfile("dump.vcd");
                $dumpvars(0, priorityEncoder_tb);

                for(i=0; i<16; i=i+1) begin
                        D = i;
                        #10;
                end
        end

endmodule