module display_ascii(predata, capital, shift, my_data, ascii1, ascii2, HEX2, HEX3);
	input predata;
	input capital;
	input shift;
	input [7:0]my_data;
	input [7:0]ascii1;
	input [7:0]ascii2;
	
	output reg [6:0]HEX2;
	output reg [6:0]HEX3;
	
	reg [7:0] ascii;
	
	always @(*)
	begin
		if(predata == 1 && my_data[7:0] != 8'hf0)	
		begin	
			
			if(capital == 1)
			begin
				ascii = ascii2;
			end
			else
			begin
				ascii = ascii1;
			end
		
		   if(shift == 1)
			   begin
				   case(ascii)
					   8'h60: ascii = 8'h7E;
						8'h31: ascii = 8'h21;
						8'h32: ascii = 8'h40;
						8'h33: ascii = 8'h23;
						8'h34: ascii = 8'h24;
						8'h35: ascii = 8'h25;
						8'h36: ascii = 8'h5E;
						8'h37: ascii = 8'h26;
						8'h38: ascii = 8'h2A;
						8'h39: ascii = 8'h28;
						8'h30: ascii = 8'h29;
						8'h2D: ascii = 8'h5F;
						8'h3D: ascii = 8'h2B;
						8'h5B: ascii = 8'h7B;
						8'h5D: ascii = 8'h7D;
						8'h5C: ascii = 8'h7C;
						8'h3B: ascii = 8'h3A;
						8'h27: ascii = 8'h22;
						8'h2C: ascii = 8'h3C;
						8'h2E: ascii = 8'h3E;
						8'h2F: ascii = 8'h3F;
						8'h7F: ascii = 8'h2E;
						endcase
				end
			
			case(ascii[3:0])
			   0: HEX2[6:0] = 7'b1000000;
			   1: HEX2[6:0] = 7'b1111001;
			   2: HEX2[6:0] = 7'b0100100;
			   3: HEX2[6:0] = 7'b0110000;
			   4: HEX2[6:0] = 7'b0011001;
			   5: HEX2[6:0] = 7'b0010010;
			   6: HEX2[6:0] = 7'b0000010;
			   7: HEX2[6:0] = 7'b1111000;
			   8: HEX2[6:0] = 7'b0000000;
			   9: HEX2[6:0] = 7'b0010000;
			   10:HEX2[6:0] = 7'b0001000;
			   11:HEX2[6:0] = 7'b0000011;
			   12:HEX2[6:0] = 7'b1000110;
			   13:HEX2[6:0] = 7'b0100001;
			   14:HEX2[6:0] = 7'b0000110;
			   15:HEX2[6:0] = 7'b0001110;
				default:HEX2[6:0] = 7'b1111111;
			endcase
		
			case(ascii[7:4])
			   0: HEX3[6:0] = 7'b1000000;
			   1: HEX3[6:0] = 7'b1111001;
			   2: HEX3[6:0] = 7'b0100100;
			   3: HEX3[6:0] = 7'b0110000;
			   4: HEX3[6:0] = 7'b0011001;
			   5: HEX3[6:0] = 7'b0010010;
			   6: HEX3[6:0] = 7'b0000010;
			   7: HEX3[6:0] = 7'b1111000;
			   8: HEX3[6:0] = 7'b0000000;
			   9: HEX3[6:0] = 7'b0010000;
			   10:HEX3[6:0] = 7'b0001000;
			   11:HEX3[6:0] = 7'b0000011;
			   12:HEX3[6:0] = 7'b1000110;
			   13:HEX3[6:0] = 7'b0100001;
			   14:HEX3[6:0] = 7'b0000110;
			   15:HEX3[6:0] = 7'b0001110;
				default:HEX3[6:0] = 7'b1111111;
			endcase
		end
		else
		
		begin
			HEX2[6:0] = 7'b1111111;
			HEX3[6:0] = 7'b1111111;
		end
		
	end
	
endmodule
