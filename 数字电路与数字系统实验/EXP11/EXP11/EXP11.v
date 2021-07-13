module EXP11(

	input 		          		CLOCK_50,
	input 		     [9:0]		SW,
	input 		     [3:0]		KEY,
	
	output		     [9:0]		LEDR,

	output		     [6:0]		HEX0,
	output		     [6:0]		HEX1,
	output		     [6:0]		HEX2,
	output		     [6:0]		HEX3,
	output		     [6:0]		HEX4,
	output		     [6:0]		HEX5,

	output		          		VGA_CLK,
	output		     [7:0]		VGA_R,
	output		     [7:0]		VGA_G,
	output		     [7:0]		VGA_B,
	output		          		VGA_HS,
	output		          		VGA_VS,
	output		             	VGA_SYNC_N,
	output		          		VGA_BLANK_N,

	inout 		          		PS2_CLK,
	inout 		          		PS2_DAT
	
	);
	
   wire [11:0] vga_data;
   wire [7:0] vga_r;
   wire [7:0] vga_g;
   wire [7:0] vga_b;
   wire [9:0] h_addr;
   wire [9:0] v_addr;
	
   wire [7:0] data;
   wire [7:0] count;
   wire [7:0] ascii;
   wire [7:0] scancode;
   wire press_flag;
   wire [3:0] special_char;
   wire ready;
   wire nextdata_n;
   wire overflow;

   assign VGA_R = vga_r;
   assign VGA_G = vga_g;
   assign VGA_B = vga_b;
	assign VGA_SYNC_N = 0;

ps2_keyboard my_ps2_keyboard(CLOCK_50, SW[0], PS2_CLK, PS2_DAT, data, ready, nextdata_n, overflow);
keyboard my_keyboard(CLOCK_50, SW[0], ready, data, nextdata_n, count, ascii, scancode, press_flag, LEDR[9], LEDR[8], LEDR[7], LEDR[6], special_char);

HEX my_hex1(press_flag, scancode[3:0], HEX0);
HEX my_hex2(press_flag, scancode[7:4], HEX1);

clkgen #(.clk_freq(25000000)) my_clkgen(CLOCK_50, ~KEY[0], 1'b1, VGA_CLK);
vga_display my_vga_display(CLOCK_50, KEY[0], press_flag, special_char, ascii, h_addr, v_addr, vga_data);
vga_ctrl my_vga_ctrl(VGA_CLK, ~KEY[0], vga_data, h_addr, v_addr, VGA_HS, VGA_VS, VGA_BLANK_N, vga_r, vga_g, vga_b);

endmodule
