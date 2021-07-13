module EXP9_1(clk, clken, reset, vga_clk, h_sync, v_sync, sync, valid, red, green, blue);
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
	
	wire temp_clk;
	wire [9:0] h_addr;
	wire [9:0] v_addr;
	
	assign vga_clk = temp_clk;
	
	clkgen #(25000000) my_vgaclk(clk, reset, 1'b1, temp_clk);

	vga_ctrl my_vgactrl(temp_clk, reset, data, h_addr, v_addr, h_sync, v_sync, valid, red, green, blue);
	
	
	always @(posedge vga_clk)
	begin
		if (h_addr <= 106)
			data = 24'hAA00000;
		else if (h_addr <= 212)
			data = 24'h0BB000;
		else if (h_addr <= 318)
			data = 24'h00CC00;
		else if (h_addr <= 424)
			data = 24'h000DD0;
		else if (h_addr <= 530)
			data = 24'h0000EE;
		else
			data = 24'hF0000F;
	end

endmodule
