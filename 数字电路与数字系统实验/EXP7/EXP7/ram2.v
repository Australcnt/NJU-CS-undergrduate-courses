module ram2(clk, we, inaddr, outaddr, din, dout, ram2);
    input clk;
	 input we;
	 input [3:0] inaddr;
	 input [3:0] outaddr;
	 input [7:0] din;
	 
	 output reg [7:0] dout;
	 
	 reg [7:0] ram2 [3:0];

initial
begin
    (* ram_init_file = "v_rams_8.mif" *) reg [7:0] ram2[3:0];
end

always @(posedge clk)
begin
    if (we)
        ram2[inaddr] <= din;
    else
        dout <= ram2[outaddr];
end

endmodule
