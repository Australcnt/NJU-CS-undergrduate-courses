module get_panel(
	input[7:0] ps_data;//键盘传入的ascii码
	input[9:0] cur_x_ascii;
	input[9:0] cur_y_ascii;
	input ready;//来自ps2_keyboard的信号
	input fail;
	input succ;
	input clk;
	input reset_n;
	output reg[7:0] ascii_out;
	output reg[1:0] mode;
	output reg[3:0] difficulty;
	output reg[23:0]username;
	output reg[23:0] color;
	output reg is_start;//是否开始游戏

);

wire[15:0] name_addr;
wire[7:0] panel_ascii;
wire[15:0] panel_addr;
wire[15:0] write_addr;

reg is_game_end;//游戏是否结束
reg username_flag;
reg is_in2 = 0;
reg out_ofg;//不在游戏中
reg temp_ready;
reg[7:0] ascii_data;
reg is_in1 = 0;
reg[15:0] offset;//切换不同界面的偏移量
reg[1:0] temp_mode;//暂存所选择的界面
reg[2:0] count;//当前输入用户名第几个字符

assign panel_addr = cur_x_ascii + cur_y_ascii * 70 + offset;//在all_panels中的位置
assign name_addr = cur_x_ascii + cur_y_ascii * 70;//用户名的地址

initial
begin
mode = 0;
difficulty = 0;
is_start = 0;
temp_mode = 0;
count = 0;
is_game_end = 0;
out_ofg = 1;
end

all_panels A(panel_addr, clk, panel_ascii);

always @ (clk)
	begin
	case(cur_y_ascii % 5 )
	0:
		color = 24'hFF7F00;
	1:
		color = 24'h0000FF;
	2:
		color = 24'h8B00FF;
	3:
		color = 24'hFFFF00;
	4:
		color = 24'h00FF00;
		endcase
	end
		
scancode2ascii(ps_data, ascii_data);

always @ (name_addr)//显示用户名
begin
if (mode == 2'b01)//输入用户名界面
	begin
	case(name_addr)
	16'h480:
	ascii_out = username[7:0];
	16'h482:
	ascii_out = username[15:8];
	16'h484:
	ascii_out = username[23:16];
	default:
		ascii_out = panel_ascii;
			endcase
			end
else
ascii_out = panel_ascii;
end


always @(posedge clk)//清零
		begin
			begin
			if (is_game_end && fail && ascii_data == 8'h0D||ascii_data==8'h08)
			begin
			offset = 16'h20d0;
			is_game_end = 0;
			end
			else if (is_game_end && succ && ascii_data == 8'h0D||ascii_data==8'h08)
			begin
			offset = 16'h2904;
			is_game_end = 0;
			end
			else
			begin
			case(mode)
			
			2'b01:
				offset = 16'h189c;
			2'b11
				offset = 16'h1068;
			2'b00:
				offset = 16'h0;
			2'b10:
			offset = 16'h834;
			endcase
			end
		is_game_end=0;
		end
		if (reset_n==0)
		begin
		mode = 0;
		difficulty = 0;
		is_start = 0;
		out_ofg = 1;
		temp_mode = 0;
		count = 0;
		is_game_end = 0;	
		end
else if (reset_n && ascii_data != 0)//键盘输入不为0
begin
if (succ == 1'b1)//游戏成功，闯关模式
	begin
	out_ofg = 1;
	is_start = 1'b0;
	is_game_end = 1;
	if (ascii_data == 8'h08)//backspace
		begin
		mode = 2'b0;//返回开始界面
		difficulty = 0;
		end
	else if (ascii_data == 8'h0D)//enter
		mode = 2'b11;//返回模式选择
		end
		
	else if (fail == 1'b1)//游戏失败
		begin
		out_ofg = 1;
		is_start = 1'b0;
		is_game_end = 1;

		if (mode == 2'b10&&ascii_data==8'h08)//无尽模式，backspace
			begin
			mode = 2'b0;//返回开始界面
			difficulty = 0;
		end

		else if (mode == 2'b11)
			begin
			if (ascii_data == 8'h08)//backspace
				begin
				mode = 0;
				difficulty = 0;
				end
			else if (ascii_data == 8'h0D)//enter
				begin
				mode = 2'b11;//返回模式选择
				difficulty = 0;
				end
				end

			else//其他状态，默认返回主页面
				begin
				mode = 2'b0;
				difficulty = 4'b0;
				end
				end

		else if (reset_n && ascii_data != 0 && is_game_end == 0)//键盘输入不为0,且游戏没结束
				begin
				if (mode == 2'b11&&(out_ofg==1))//闯关模式难度选择界面
					begin
					if(ascii_data==8'h31)
					begin
					difficulty = 4'h1;
					is_start = 1;
					out_ofg = 0;
					end
					else if(ascii_data==8'h32)
					begin
					difficulty = 4'h2;
					is_start = 1'b1;
					out_ofg = 0;
					end
					else if(ascii_data==8'h33)
					begin
					difficulty = 4'h3;
					is_start = 1'b1;
					out_ofg = 0;
					end
					else if(ascii_data==8'h34)
					begin
					difficulty = 4'h4;
					is_start = 1'b1;
					out_ofg = 0;
					end
					else if(ascii_data==8'h35)
					begin
					difficulty = 4'h5;
					is_start = 1'b1;
					out_ofg = 0;
					end
					else if(ascii_data==8'h36)
					begin
					difficulty = 4'h6;
					is_start = 1'b1;
					out_ofg = 0;
					end
					else if(ascii_data==8'h37)
					begin
					difficulty = 4'h7;
					is_start = 1'b1;
					out_ofg = 0;
					end
					else if(ascii_data==8'h38)
					begin
					out_ofg = 0;
					difficulty = 4'h8;
					is_start = 1;
					end
					else if(ascii_data==8'h08)
					begin
					difficulty = 0;
					is_start = 0;
					mode = 0;
					end
				else
					begin
						difficulty = 0;
						out_ofg = 0;
					end
				end


				else if (mode == 2'b10&&(out_ofg==1))//无尽模式难度选择界面
					begin
					if(ascii_data==8'h31)
					begin
					difficulty = 4'h1;
					is_start = 1'b1;//开始游戏
					out_ofg = 0;
					end
					else if(ascii_data==8'h32)
					begin
					difficulty = 4'h2;
					is_start = 1'b1;
					out_ofg = 0;
					end
					else if(ascii_data==8'h33)
					begin
					difficulty = 4'h3;
					is_start = 1'b1;
					out_ofg = 0;
					end
					else if(ascii_data==8'h08)
					begin
					difficulty = 4'b0;
					is_start = 1'b0;
					mode = 2'b0;
					end
					else
						begin
							difficulty = 4'h0;
							out_ofg = 1'b0;
						end
						
					end
				end

				else if (!mode&&(out_ofg==1))
					begin
					case(ascii_data)
					8'h31:
						begin
						temp_mode = 2'b10;
						mode = 2'b1;
						end
					8'h32:
						begin
						temp_mode = 2'b11;
						mode = 2'b1;
						end
					endcase
						username_flag = 0;
					end
					else if (out_ofg == 1)//输入用户名界面
						begin
						if (ascii_data == 8'h0D)//enter
							//实现用户名输入
							mode = temp_mode;//切换到所选的界面
							end

							begin//输入名字
							if (mode == 2'b1)
								begin
								if (username_flag&&!temp_ready&&ascii_data != 8'h0D&&ready&&is_in1==0)
									is_in1 = 1;
								else if (username_flag&&!temp_ready&&ready&&is_in1==1&&ascii_data != 8'h0D)
										begin
											case(count)
											3'b0:
												username[7:0] = ascii_out;
											3'b1:
												username[15:8] = ascii_out;
											3'b10:
												begin 
												username[23:16] = ascii_out; 
												is_in1 = 0; 
												end
											default:;
											endcase
											end
											else
												begin
												username_flag = 0;
												username[7:0] = ascii_out;
												count = 0;
												end
												count = count + 1;
												end
										else
												username_flag = 1;
end
end

temp_ready = ready;
end
end

endmodule

