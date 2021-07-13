module scancode2ascii(datain,ascii);

input [7:0] datain;
output reg [7:0] ascii;
(*ram_init_file="scancode.mif"*) reg [7:0]lut[255:0];

always @(*)
	begin
		ascii=lut[datain];
	if(ascii>=97&&ascii<=122)//up
		ascii=ascii-32;
endmodule
