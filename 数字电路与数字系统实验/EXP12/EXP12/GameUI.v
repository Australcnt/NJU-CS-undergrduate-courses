module GameUI(
	input clk, 
	input[4:0] h_ascii,
	input[3:0] life, 
	input mode, 
	input[4:0] v_ascii,                  
	input[9:0] target,  
	output reg[7:0] cur_ascii	          
	input[9:0] score,             
	input[9:0] speed,  
	input[23:0] username           
);

  
wire[7:0] rom_ascii;        
wire[7:0] ascii_score0; //个位
wire[7:0] ascii_score1; //十位
wire[7:0] ascii_score2; //百位
wire[7:0] ascii_life;//剩余生命次数
wire[7:0] ascii_target0; //个位
wire[7:0] ascii_target1; //十位
wire[7:0] ascii_target2; //百位
wire[11:0] rom_addr;
wire[7:0] ascii_speed0; //下落速度值各个位的ascii，个位
wire[7:0] ascii_speed1; //十位
wire[7:0] ascii_speed2; //百位

Game_UI_Info my_GameUI_Info(rom_addr, clk, rom_ascii); //读取侧边栏中当前字符的ascii

assign rom_addr = (v_ascii << 4) + (v_ascii << 2) + h_ascii; //20*30侧边栏地址
assign ascii_score0 = (score % 10) + 8'h30;
assign ascii_score1 = ((score / 10) % 10) + 8'h30;
assign ascii_score2 = (score / 100) + 8'h30;
assign ascii_target0 = (target % 10) + 8'h30;//目标得分各个位的ascii
assign ascii_target1 = ((target / 10) % 10) + 8'h30;
assign ascii_target2 = (target / 100) + 8'h30;
assign ascii_speed0 = (speed % 10) + 8'h30;
assign ascii_speed1 = ((speed / 10) % 10) + 8'h30;
assign ascii_speed2 = (speed / 100) + 8'h30;
assign ascii_life = (mode==1) ? (life + 8'h30):(8'h02); //无穷/有限

always @(*)
begin
if(rom_addr==12'h238)
	cur_ascii = ascii_speed2;
else if(rom_addr==12'h239)
	cur_ascii = ascii_speed1;
else if(rom_addr==12'h23a)
	cur_ascii = ascii_speed0;
else if(rom_addr==12'h138)
	cur_ascii = ascii_life;
else if(rom_addr==12'h199)
	cur_ascii = ascii_score2;
else if(rom_addr==12'h19a)
	cur_ascii = ascii_score1;
else if(rom_addr==12'h19b)
	cur_ascii = ascii_score0;
else if(rom_addr==12'h0e8)
	cur_ascii = username[23:16];
else if(rom_addr==12'h0e6)
	cur_ascii = username[15:8];
else if(rom_addr==12'h0e4)
	cur_ascii = username[7:0];
else if(rom_addr==12'h211)
	cur_ascii = ascii_target2;
else if(rom_addr==12'h212)
	cur_ascii = ascii_target1;
else if(rom_addr==12'h213)
	cur_ascii = ascii_target0;
else
 cur_ascii = rom_ascii;
end

endmodule
