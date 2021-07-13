module clk_speed(
input clkin,
input rst,
input clken,
input [9:0] clk_freq,
output reg clkout
);
wire [31:0] countlimit;
assign countlimit=(25000000/clk_freq);

reg [31:0] clkcount;
always @ (posedge clkin)
begin
	if(rst)
	begin
		clkcount=0;
		clkout=1'b0;
	end
	else
	begin
		if(clken)
		begin
			clkcount=clkcount+1;
			if(clkcount>=countlimit)
			begin
				clkcount=32'd0;
				clkout=~clkout;
			end
		else
			clkout=clkout;
		end
		else
		begin
			clkcount=clkcount;
			clkout=clkout;
		end
	end
end
	
endmodule 
