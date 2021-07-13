module display_presscount(press_count, HEX4, HEX5);
	input [6:0]press_count;
	
	output reg [6:0]HEX4;
	output reg [6:0]HEX5;
	
	reg [3:0]units_digit = 0;
	reg [3:0]tens_digit = 0;
	
	always @(*)
	begin
	   units_digit = press_count % 10;
		tens_digit = press_count / 10;
		case(units_digit)
			0: HEX4[6:0] = 7'b1000000;
			1: HEX4[6:0] = 7'b1111001;
			2: HEX4[6:0] = 7'b0100100;
			3: HEX4[6:0] = 7'b0110000;
			4: HEX4[6:0] = 7'b0011001;
			5: HEX4[6:0] = 7'b0010010;
			6: HEX4[6:0] = 7'b0000010;
			7: HEX4[6:0] = 7'b1111000;
			8: HEX4[6:0] = 7'b0000000;
			9: HEX4[6:0] = 7'b0010000;
			default: HEX4[6:0] = 7'b1111111;
		endcase
		
		case(tens_digit)
			0: HEX5[6:0] = 7'b1000000;
			1: HEX5[6:0] = 7'b1111001;
			2: HEX5[6:0] = 7'b0100100;
			3: HEX5[6:0] = 7'b0110000;
			4: HEX5[6:0] = 7'b0011001;
			5: HEX5[6:0] = 7'b0010010;
			6: HEX5[6:0] = 7'b0000010;
			7: HEX5[6:0] = 7'b1111000;
			8: HEX5[6:0] = 7'b0000000;
			9: HEX5[6:0] = 7'b0010000;
			default: HEX5[6:0] = 7'b1111111;
		endcase
	end
	
endmodule
