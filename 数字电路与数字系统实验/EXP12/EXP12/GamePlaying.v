module GamePlaying(
	input clk,                    
	input mode,               //游戏模式（无尽/生存）
	input start,              //游戏开始
	input restart,            //状态重置
	input ready,              //有按键松开
	input[3:0] difficulty,        //游戏难度值
	input[7:0] scancode,	      //键盘输入字符的扫描码
	input[9:0] v_addr,           //480*630像素点的纵坐标
	input[6:0] h_ascii, 	      //30*70的横坐标
	output fail,                  //游戏失败
	output succ,                  //游戏成功
	output[3:0] left_life,        //生命值
	output[3:0] v_font,          //16*9字模内的行数
	output[7:0] cur_ascii,	      //当前需要显示的ascii
	output reg[9:0] target,      //目标分数
	output reg[9:0] speed,  //字符下滑速度
	output reg[9:0] score        //游戏分数
);

initial
begin
score = 0;
end

//游戏界面相关屏幕参数
parameter max_col = 50; //横向50个字符
parameter max_row = 31; //纵向31个字符行（多一个是用于产生新的随机字符）
parameter pixel_line = max_row * 16; //纵向31*16个像素行

wire clk_5s;
wire[9:0] random_speed;
wire clk_offset;//Clock for offset changing
wire[4:0] v_ascii;
wire[3:0] newLine;//用于产生新的随机行
wire[9:0] cur_v_addr;//计算带上偏移量后的v_addr
wire[7:0] random_ascii;
wire[4:0] NowLine;//即将进入屏幕的那个字符行
wire[10:0] read_addr;        
wire[10:0] write_addr;
wire[6:0] random_col64;      
wire[10:0] read_addr2; 
wire[7:0] cur_ascii2;     
wire[6:0] random_col;
wire[3:0] random_num;
wire[7:0] my_ascii;

//键盘按下，KEYCLEAN状态
reg[7:0] keyascii; //将要清除的字符的ascii码

reg clean=0; //字符清除状态
reg[10:0] clean_addr=0; //31*50清除字符所在地址
reg[31:0] clean_count=0; //处于GO_CLEAN的时钟周期数
reg life_deduct; //为真时表示错过了字符，应当life减少
reg[3:0] newLine2;
reg restart2=0;
reg ready2=0;
reg[9:0] random_addr=0; //读随机表的地址
reg[6:0] random_count; //记录对新行随机写入的次数
reg[6:0] num_max=1; //写入新行时的最大字符数
reg[3:0] life=9; //生命值
reg key_matched = 0;//是否匹配到输入字符
reg[8:0] offset=0; //偏移量
reg[7:0] newascii=0;           //准备写入31*50RAM的数据值
reg wren=0;	 
reg[6:0] col_index; 
reg[3:0] stage=0; 

parameter WAITING = 0;  			   
parameter GAMERESET = 4;
parameter KEYCLEAN = 3;		
parameter CREATENEW = 2;
parameter LINECLEAN = 1;

assign fail = ((mode==0) ? (0) : (life == 0)) || keyascii == 8'h08; 
assign succ = (target <= score) || restart; 
assign left_life = (life <= 9) ? (life) : (0); //控制只显示 0~9 的生命值
assign v_ascii = (cur_v_addr % pixel_line) >> 4; //30*70的纵坐标
assign cur_v_addr = pixel_line + v_addr - offset; 
assign v_font = cur_v_addr & 4'b1111; 
assign read_addr = v_ascii * max_col + h_ascii; //31*50RAM的读地址
assign NowLine = (pixel_line - offset) >> 4; 
assign newLine = offset[3:0];
assign random_col = random_col64 % max_col;
assign write_addr = (stage != KEYCLEAN && stage != GAMERESET) ? (NowLine * max_col + col_index):(clean_addr) ;
assign read_addr2 = (stage != KEYCLEAN && stage != GAMERESET) ? (write_addr):(clean_addr);


clk_second my_clk_second(clk,reset,~reset,clk_5s);

clk_speed my_clk_speed(clk,reset,~reset,speed,clk_offset);//Change offset

random8Bits my_random8Bits2(random_addr, clk_5s, random_speed);//模式、难度值的翻译：
           
Gameascii my_game_ascii1(clk,newascii,read_addr,write_addr,wren,cur_ascii); //写使能

Gameascii my_game_ascii2(clk,newascii,read_addr,write_addr,wren,cur_ascii);//RAM显存,写操作与1号完全一致，而读操作是独立的，目的是增加一个自由读出的端口

random8Bits my_random8Bits(random_addr, clk, random_num);

random64 my_random64(random_addr, clk, random_col64);

randomascii my_randomascii(random_addr, clk, random_ascii);

scancode2ascii(scancode, my_ascii);

always @(*) begin
target = 599;
	if (mode==1) begin 
	case(difficulty) 
	4'h1:    
		begin 
		num_max = random_num & 4'b0011; 
		speed = 10 + random_speed % 5;   
		target = 30;  
		end
	4'h2:   
		begin 
		num_max = random_num & 4'b0011; 
		speed = 10 + random_speed % 10;  
		target = 40;  
		end
	4'h3:    
		begin 
		num_max = random_num & 4'b0011; 
		speed = 10 + random_speed % 15;  
		target = 50;  
		end
	4'h4:    
		begin 
		num_max = random_num & 4'b0011; 
		speed = 10 + random_speed % 20;  
		target = 70;  
		end
	4'h5:    
		begin 
		num_max = random_num & 4'b0011; 
		speed = 10 + random_speed % 30;  
		target = 90;  
		end
	4'h6:    
		begin 
		num_max = random_num & 4'b0011; 
		speed = 10 + random_speed % 40;  
		target = 110; 
		end
	4'h7:    
		begin 
		num_max = random_num & 4'b0011; 
		speed = 10 + random_speed % 50; 
		target = 130;
		end
	4'h8:   
		begin 
		num_max = random_num & 4'b0011; 
		speed = 10 + random_speed % 60;  
		target = 150; 
		end
	default:
		begin 
		num_max = random_num & 4'b0011; 
		speed = 25;  
		target = 30;                    
		end
		endcase
	end
else begin 
	case(difficulty)
	4'h1:    
		begin 
		num_max = random_num & 4'b0011; 
		speed = 10 + random_speed % 20;  
		target = 40;  
		end
	4'h2:  
		begin 
		num_max = random_num & 4'b0011; 
		speed = 10 + random_speed % 40; 
		target = 70; 
		end
	4'h3:    
		begin 
		num_max = random_num & 4'b0111; 
		speed = 10 + random_speed % 60;  
		target = 100; 
		end
	default: 
		begin 
		num_max = random_num & 4'b0011; 
		speed = 10;
		end
		endcase
	end
end


always @(posedge clk_offset)
begin
if (offset < pixel_line)
	offset = offset + 1;
else
offset = 0;
end
  
		
always @(negedge clk)
begin

if (clean==1) begin
clean_count = clean_count + 1;
end

if (10 * max_col * max_row <= clean_count) begin
clean_count = 0;
clean = 0;
end

if (clean==0 && ready2==0 && ready) begin
	clean = 1;
	key_ascii=my_ascii;
end


case(stage) 

LINECLEAN : begin
if (cur_ascii2) 
	life_deduct = 1;

if (col_index == max_col - 1) 
begin 
	if (life_deduct) 
	begin
		life = life - 1;
		life_deduct = 0;
	end
	random_count = 0;
	col_index = random_col;
	newascii = random_ascii;
	stage = CREATENEW;
	if (num_max <= random_count) 
	begin 
		stage = WAITING;
		col_index = 0;
		wren = 0;
	end
	random_addr = random_addr + 1;
	end
else begin 
	col_index = col_index + 1;
	end
end


WAITING: begin
if (newLine2 != newLine && newLine == 4'h1) 
	begin 
	newascii = 0;
	col_index = 0;
	stage = LINECLEAN;
	life_deduct = 0;
	wren = 1;
	end

if (clean==1 && keyascii) 
	begin 
	wren = 0;
	clean = 0;
	clean_addr = 0;
	stage = KEYCLEAN;
	end
	random_count = 0;
	wren = 0;
	clean_addr = 0;
if (start==0 || ( !restart2 && restart)) 
	begin
	stage = GAMERESET;
	newascii = 0;
	wren = 1;
	score = 0;
	life = 9;
	clean = 0;
	clean_addr = 0;
	end
end


KEYCLEAN : begin

	if (wren != 0 || cur_ascii2 != keyascii) 
		begin
		clean_addr = clean_addr + 1;
		wren = 0;
		end
	else 
		begin
		newascii = 0;
		score = score + 1;
		key_matched = 1;
		wren = 1;
		end
	clean = 0;
	if (max_col * max_row <= clean_addr) 
	begin
	wren = 0;
	clean = 0;
	clean_addr = 0;
	clean_count = 0;
	if (key_matched == 0)
		life = life - 1;
	else
		key_matched = 0;
	stage = WAITING;
	end
end


CREATENEW : 
begin
	random_count = random_count + 1;
	if (num_max<=random_count) 
	begin 
		wren = 0;
		stage = WAITING;
		col_index = 0;
		random_count = 0;
		end
	else begin 
		random_addr = random_addr + 1;
		col_index = random_col;
		newascii = random_ascii;
		end
end

GAMERESET : 
begin
	if (max_col * max_row <= clear_addr) 
	begin
		wren = 0;
		clean_addr = 0;
		stage = WAITING;
	end
	clean_addr = clean_addr + 1;
end


default: begin
	wren = 0;
	clean = 0;
	life_deduct = 0;
	stage = WAITING;
end

endcase

newLine2 = newLine;
ready2 = ready;
restart2 = restart;

end

endmodule

