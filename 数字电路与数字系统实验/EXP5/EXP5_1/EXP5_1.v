module EXP5_1(clk, start, pause, clr, count_clk, clk_1s, count_scd, ending, units_digit, tens_digit, units_HEX, tens_HEX, HEX2, HEX3, HEX4, HEX5);
	input clk;
	input start;
	input pause;
	input clr;
	
	output reg [24:0]count_clk = 0;
	output reg clk_1s = 0;
	output reg [6:0] count_scd = 0;
	output reg ending = 0;
	output reg [3:0] units_digit = 0;
	output reg [3:0] tens_digit = 0;
	output reg [6:0] units_HEX = 64;
	output reg [6:0] tens_HEX = 64;
	output reg [6:0] HEX2 = 127;
	output reg [6:0] HEX3 = 127;
	output reg [6:0] HEX4 = 127;
	output reg [6:0] HEX5 = 127;

	always @(posedge clk)
	  if (clr == 1 || start == 0)
	  begin
	    count_clk = 0;
		 count_scd = 0;
		 units_HEX = 64;
		 tens_HEX = 64;
	  end
	  else if (pause == 1)
	  begin
	    count_clk = count_clk;
		 count_scd = count_scd;
		 units_HEX = units_HEX;
		 tens_HEX = tens_HEX;
	  end
	  else if (count_clk == 25000000)
	  begin
	    count_clk <= 0;
	    clk_1s <= ~clk_1s;
		 if (clk_1s == 0)
		   count_scd = (count_scd + 1) % 100;
		 if (count_scd == 00 && clk_1s == 0)
		   ending <= 1;
		 else
		   ending <= 0;
		 units_digit = count_scd % 10;
		 tens_digit = count_scd / 10;
		 units_HEX = 0;
		 tens_HEX = 0;
		 case (units_digit)
		   0: units_HEX = 64;
			1: units_HEX = 121;
			2: units_HEX = 36;
			3: units_HEX = 48;
			4: units_HEX = 25;
			5: units_HEX = 18;
			6: units_HEX = 2;
			7: units_HEX = 120;
			8: units_HEX = 0;
			9: units_HEX = 16;
			default: units_HEX = 64;
		 endcase
		 case (tens_digit)
		   0: tens_HEX = 64;
			1: tens_HEX = 121;
			2: tens_HEX = 36;
			3: tens_HEX = 48;
			4: tens_HEX = 25;
			5: tens_HEX = 18;
			6: tens_HEX = 2;
			7: tens_HEX = 120;
			8: tens_HEX = 0;
			9: tens_HEX = 16;
			default: tens_HEX = 64;
		 endcase
	  end
	  else
	    count_clk <= count_clk + 1;

endmodule
