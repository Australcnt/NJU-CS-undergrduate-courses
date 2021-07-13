module EXP7(clk, we, inaddr, outaddr, din, dout1, dout2, HEX0, HEX1);
    input clk;
	 input we;
	 input [3:0] inaddr;
	 input [3:0] outaddr;
	 input [7:0] din;
	 
	 output [7:0] dout1;
	 output [7:0] dout2;
	 output reg [6:0] HEX0;
	 output reg [6:0] HEX1;
	 
    ram1 myram1(clk, we, inaddr, outaddr, din, dout1);
	 ram2port myram2(.clock(clk), .data(din), .wraddress(inaddr), .rdaddress(outaddr), .wren(we), .q(dout2));
	 
always @(*)
begin	
	 case (dout1[1:0])
	     2'b00: HEX0 = 64;
		  2'b01: HEX0 = 121;
		  2'b10: HEX0 = 36;
		  2'b11: HEX0 = 48;
		  default: HEX0 = 127;
	 endcase
	 
	 case (dout2[1:0])
	     2'b00: HEX1 = 64;
		  2'b01: HEX1 = 121;
		  2'b10: HEX1 = 36;
		  2'b11: HEX1 = 48;
		  default: HEX1 = 127;
	 endcase
end

endmodule
