module EXP6_2(clk, Q, LIN, digit0, digit1, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5);
    input clk;
	 
	 output reg [7:0] Q = 0;
	 output reg LIN;
	 output reg [3:0] digit0;
	 output reg [3:0] digit1;
	 output reg [6:0] HEX0 = 64;
	 output reg [6:0] HEX1 = 64;
	 output reg [6:0] HEX2 = 127;
	 output reg [6:0] HEX3 = 127;
	 output reg [6:0] HEX4 = 127;
	 output reg [6:0] HEX5 = 127;
	 
	 always @(posedge clk)
	 begin
	   LIN = (Q[3] ^ Q[0]) | ~(Q[0] || Q[1] || Q[2] || Q[3] || Q[4] || Q[5] || Q[6] || Q[7]);
	   Q = {LIN, Q[7:1]};
		digit0 = Q[3:0];
		digit1 = Q[7:4];
		case (digit0)
		  0: HEX0 = 64;
		  1: HEX0 = 121;
		  2: HEX0 = 36;
		  3: HEX0 = 48;
		  4: HEX0 = 25;
		  5: HEX0 = 18;
		  6: HEX0 = 2;
		  7: HEX0 = 120;
		  8: HEX0 = 0;
		  9: HEX0 = 16;
		  10: HEX0 = 8;
		  11: HEX0 = 3;
		  12: HEX0 = 70;
		  13: HEX0 = 33;
		  14: HEX0 = 6;
		  15: HEX0 = 14;
		  default: HEX0 = 127;
		endcase
		case (digit1)
		  0: HEX1 = 64;
		  1: HEX1 = 121;
		  2: HEX1 = 36;
		  3: HEX1 = 48;
		  4: HEX1 = 25;
		  5: HEX1 = 18;
		  6: HEX1 = 2;
		  7: HEX1 = 120;
		  8: HEX1 = 0;
		  9: HEX1 = 16;
		  10: HEX1 = 8;
		  11: HEX1 = 3;
		  12: HEX1 = 70;
		  13: HEX1 = 33;
		  14: HEX1 = 6;
		  15: HEX1 = 14;
		  default: HEX1 = 127;
		endcase
	 end
	 
endmodule
