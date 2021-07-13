module HEX(press_flag, scancode, hex);
	
	input press_flag;
	input [3:0] scancode;
	
	output reg [6:0] hex;
	
	always @(*)
	begin
	   if (press_flag)
	   begin
	   case (scancode)
	      4'b0000: hex = 7'b1000000;
			4'b0001: hex = 7'b1111001;
			4'b0010: hex = 7'b0100100;
			4'b0011: hex = 7'b0110000;
			4'b0100: hex = 7'b0011001;
			4'b0101: hex = 7'b0010010;
			4'b0110: hex = 7'b0000010;
			4'b0111: hex = 7'b1111000;
			4'b1000: hex = 7'b0000000;
			4'b1001: hex = 7'b0010000;
			4'b1010: hex = 7'b0001000;
			4'b1011: hex = 7'b0000011;
			4'b1100: hex = 7'b1000110;
			4'b1101: hex = 7'b0100001;
			4'b1110: hex = 7'b0000110;
			4'b1111: hex = 7'b0001110;
			default: hex = 7'b1111111;
		endcase
	   end
		else
		begin
			hex = 7'b1111111;
		end
	end
	
endmodule
