module scancode2ascii(address, ascii_copy);

	input [7:0] address;
	
	output reg [7:0] ascii_copy;
	
	(* ram_init_file = "keyboard.mif" *) reg [7:0] ascii_rom[255:0];
	
	always @(*)
	begin
		ascii_copy = ascii_rom[address];
	end

endmodule
