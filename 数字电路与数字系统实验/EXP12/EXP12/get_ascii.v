module get_ascii(
	input start,
	input[7:0] game_ui_ascii,
	input[7:0] game_ascii,
	input [7:0] main_ascii,
	input [9:0] h_addr,
	output reg [7:0] ascii);//输入键码，返回ASCII码
	
always@(*)
begin
	
	if(start&&((h_addr/9)<20))
		ascii=game_ui_ascii;
	else if(start)
		ascii=game_ascii;
	else
		ascii=main_ascii;
end	

endmodule
