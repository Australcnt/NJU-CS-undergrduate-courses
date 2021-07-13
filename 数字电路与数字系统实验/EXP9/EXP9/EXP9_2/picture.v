module EXP9_2(clk, clken, reset, vga_clk, h_sync, v_sync, sync, valid, red, green, blue);
	input clk;
	input clken;
	input reset;
	
	output vga_clk;
	output h_sync;
	output v_sync;
	output sync = 0;
	output valid;
	output [7:0] red;
	output [7:0] green;
	output [7:0] blue;
	
	reg [23:0] data = 24'b0;
	reg [18:0] rom_addr = 19'b0;
	
	wire temp_clk;
	wire [9:0] h_addr;
	wire [9:0] v_addr;
	wire [11:0] temp_color;
	
	assign vga_clk = temp_clk;
	
	clkgen #(25000000) my_vgaclk(clk, reset, 1'b1, temp_clk);
	vga_ctrl my_vgactrl(temp_clk, reset, data, h_addr, v_addr, h_sync, v_sync, valid, red, green, blue);
	ROM my_rom(rom_addr, temp_clk, temp_color);
	
	always @(posedge clk)
	begin
		data[3:0] = 4'b0000;
		data[7:4] = temp_color[3:0];
		data[11:8] = 4'b0000;
		data[15:12] = temp_color[7:4];
		data[19:16] = 4'b0000;
		data[23:20] = temp_color[11:8];
		rom_addr = {h_addr, v_addr[8:0]};
	end

endmodule
