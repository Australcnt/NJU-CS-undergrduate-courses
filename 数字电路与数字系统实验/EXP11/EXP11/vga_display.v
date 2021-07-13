module vga_display(clk, clrn, press_flag, special_char, char_ascii, h_addr, v_addr, vga_data);
   
	input clk;
	input clrn;
	input press_flag;
   input [3:0] special_char;
   input [7:0] char_ascii;
   input [9:0] h_addr;
	input [9:0] v_addr;
	
   output reg [11:0] vga_data;//VGA颜色数据
   
   reg flush_clk;//屏幕刷新时钟
	integer flush_cnt;
	reg cursor_blink;//光标是否闪烁
	integer blink_cnt;
	parameter blink_freq = 2;//光标闪烁频率
	
	reg [29:0] line_flag;//是否显示该行
   reg [6:0] now_x;//当前x坐标指针
	reg [6:0] now_y;//当前y坐标指针
   reg [6:0] now_max_x;//文末x坐标指针
	reg [6:0] now_max_y;//文末y坐标指针
   reg [7:0] screen[0:29][0:69];//字符ascii矩阵
   reg [1:0] color[0:29][0:69];//字符颜色矩阵
	reg [11:0] real_color = 0;//当前字符实际颜色
	
   reg [11:0] vga_font[4095:0];//字模点阵
   reg [7:0] cmd[cmd_size - 1:0];//命令行开头字符
   parameter cmd_size = 10;//命令行开头字符长度
	
	wire [9:0] char_x;//30×70矩阵x坐标
	wire [9:0] char_y;//30×70矩阵y坐标
   wire [3:0] matrix_x;//字模点阵x坐标
   wire [11:0] matrix_y;//字模点阵y坐标
   wire [11:0] matrix_line;//当前字模点阵行号
   wire [7:0] cur_char;//当前字符的acsii
   wire [1:0] cur_color;//当前字符颜色
   wire [9:0] cursor_area_h;//光标像素横坐标
	wire [9:0] cursor_area_v;//光标像素纵坐标
	
   integer i;
	integer j;
	
   //初始化操作
   initial 
	begin
	   //读入字模点阵
	   $readmemh("C:/Digital_Experiment/EXP11/vga_font.txt", vga_font, 0, 4095);
	   //无字符
		for (i = 0; i < 30; i = i + 1)
		  for (j = 0; j < 70; j = j + 1)
			 screen[i][j] = 8'b0;
	   //全黑色
		for (i = 0; i < 30; i = i + 1)
		  for (j = 0; j < 70; j = j + 1)
			 color[i][j] = 2'b0;
		//Welcome!界面
	   screen[0][0] = 8'h57; color[0][0] = 2'b11;
		screen[0][1] = 8'h65; color[0][1] = 2'b11;
	   screen[0][2] = 8'h6C; color[0][2] = 2'b11;
		screen[0][3] = 8'h63; color[0][3] = 2'b11;
	   screen[0][4] = 8'h6F; color[0][4] = 2'b11;
		screen[0][5] = 8'h6D; color[0][5] = 2'b11;
	   screen[0][6] = 8'h65; color[0][6] = 2'b11;
		screen[0][7] = 8'h21; color[0][7] = 2'b11;
		//NAN@NAN:~$
	   cmd[0] = 8'h4E;
		cmd[1] = 8'h41;
		cmd[2] = 8'h4E;
		cmd[3] = 8'h40;
		cmd[4] = 8'h4E;
		cmd[5] = 8'h41;
		cmd[6] = 8'h4E;
		cmd[7] = 8'h3A;
		cmd[8] = 8'h7E;
		cmd[9] = 8'h24;
	   //每行开头设为NAN@NAN:~$
	   for (i = 0; i < cmd_size; i = i + 1)
		   screen[2][i] = cmd[i];
		//一开始只显示第一个命令行
	   line_flag = 30'b000000000000000000000000000100;
	   //屏幕刷新
	   flush_clk = 0;
	   flush_cnt = 0;
	   //当前字符指针和文末字符指针
	   now_x = cmd_size;
		now_y = 2;
	   now_max_x = cmd_size;
		now_max_y = 2;
	   //光标闪烁
	   cursor_blink = 0;
	   blink_cnt = 0;
   end
   
   assign char_x = h_addr / 9;//30×70矩阵x坐标
   assign char_y = v_addr / 16;//30×70矩阵y坐标
   assign cur_char = h_addr < 10'd630 ? screen[char_y][char_x] : 8'b0;//当前字符的ascii
   assign cur_color = h_addr < 10'd630 ? color[char_y][char_x] : 2'b0;//当前字符颜色
   assign matrix_x = h_addr % 9;//字模点阵x坐标
   assign matrix_y = {cur_char[7:0], v_addr[3:0]};//字模点阵y坐标
   assign matrix_line = vga_font[matrix_y];//字模点阵当前行的数据
   assign cursor_area_h = {now_x[6:0], 3'b0} + now_x;//光标像素横坐标
   assign cursor_area_v = {now_y[5:0], 4'b0};//光标像素纵坐标
   
	//根据对应的color选择对应的颜色
   always @(*)
	begin
	   if (cur_color == 2'b00)//黑色
	   	real_color = 12'h000;
		else// if(cur_color == 2'b11)//白色
		   real_color = 12'hFFF;
	end
	
	//输出当前像素颜色
   always @(posedge clk)
	begin
      if (clrn == 0)
		begin
         vga_data <= 12'h0;
      end
	   else
		begin
         if ((h_addr >= cursor_area_h && h_addr < cursor_area_h + 9)
			&& (v_addr >= cursor_area_v && v_addr < cursor_area_v + 16)
			&& (cursor_blink == 1))
            vga_data <=  12'hFFF;//光标闪烁时,置为全白色
			else
            vga_data <= matrix_line[matrix_x[3:0]] ? 12'hFFF : real_color;//字模点阵当前行
      end
   end
	
   //屏幕刷新时钟
   always @(posedge clk)
	begin
      if (clrn == 0)
		begin
         flush_clk <= 0;
         flush_cnt <= 0;
      end
		else if (flush_cnt == 4500000)
		begin
         flush_cnt <= 0;
         flush_clk <= ~flush_clk;
      end
		else
		   flush_cnt <= flush_cnt + 1;
   end
	
   always @(posedge flush_clk)
	begin
      if (!press_flag)//若没有键被按下，则光标闪烁
		begin 
         if (blink_cnt == blink_freq)
			begin 
            blink_cnt <= 0;
            cursor_blink <= ~cursor_blink;
         end
			else
			blink_cnt <= blink_cnt + 1;
      end
		else if (special_char)//若有特殊的字符被按下
		begin
         cursor_blink <= 1;
         case (special_char)
            1: //左移
					begin 
					if (!(line_flag[now_y] && now_x == cmd_size))//不在命令行行首
						begin
						if (now_x == 0)//在非命令行行首，则回到上一行行末
							begin
								if (now_y != 2)
								begin 
									now_y <= now_y - 1;
									now_x <= 69;
								end
							end
							else//正常情况，左移一个字符
								now_x <= now_x - 1;
						end
					end
            4: //右移
					begin 
					if (now_y < now_max_y || (now_y == now_max_y && now_x < now_max_x))//不在文末才能右移
						begin
							if (now_x == 69)
							begin
								now_x <= 0;
								now_y <= now_y + 1;
							end
							else
								now_x <= now_x + 1;
						end
					end
				6: //删除
					begin 
						if ((now_x == now_max_x && now_y == now_max_y)//在文末才能删除
						&& (now_x != 0 || now_y != 2)//不在整个屏幕行首
						&& (now_x != cmd_size || !line_flag[now_y]))//不在命令行行首
						begin
							if (now_x == 0)//在非命令行行首
							begin
								screen[now_y - 1][69] <= 8'b0;
								now_x <= 69;
								now_y <= now_y - 1;
								now_max_x <= 69;
								now_max_y <= now_y - 1;
							end
							else//正常情况
							begin
								screen[now_y][now_x - 1] <= 8'b0;
								now_x <= now_x - 1;
								now_max_x <= now_x - 1;
							end
						end
					end
            5: //回车
					begin 
						if (now_max_y == 29)//屏幕满时，则自动滚动屏幕
						begin
							for (i = 0; i < 29; i = i + 1)
								for (j = 0; j < 70; j = j + 1)
									screen[i][j] = screen[i + 1][j];
							for (i = 0; i < cmd_size; i = i + 1)
								screen[29][i] <= cmd[i];
							for (i = cmd_size; i < 70; i = i + 1)
								screen[29][i] = 0;
							now_x <= cmd_size;
							now_y <= 29;
							now_max_x <= cmd_size;
							now_max_y <= 29;
						end
						else
						begin
							for (i = 0; i < cmd_size; i = i + 1)
								screen[now_max_y + 1][i] <= cmd[i];
							line_flag[now_max_y + 1] <= 1;
							now_x <= cmd_size;
							now_y <= now_max_y + 1;
							now_max_x <= cmd_size;
							now_max_y <= now_max_y + 1;
						end
					end
            default:
					begin
						now_x <= now_x;
						now_y <= now_y;
					end
         endcase
      end
		else//正常输入
		begin 
         if (now_x == 69)//行末
			begin
            if (now_y == 29)//屏底
				begin
               screen[29][69] <= char_ascii;
               for (i = 0; i < 29; i = i + 1)//自动滚动屏幕
                  for (j = 0; j < 70; j = j + 1)
                     screen[i][j] = screen[i + 1][j];
				   for (i = 0; i < 70; i = i + 1)
					   screen[29][i]=0;
               now_x <= 0;
               now_y <= 29;
               now_max_x <= 0;
               now_max_y <= 29;
            end
				else
				begin
               screen[now_y][now_x] <= char_ascii;
               now_x <= 0;
               now_y <= now_y + 1;
               if (now_max_y == now_y && now_max_x == now_x)//是否在文末输入
					begin
                  now_max_x <= 0;
                  now_max_y <= now_y + 1;
               end
            end
         end
			else
			begin
            screen[now_y][now_x] <= char_ascii;
            now_x <= now_x + 1;
            if (now_max_y == now_y && now_max_x == now_x)//是否在文末输入
				   now_max_x <= now_x + 1;
         end
      end
      
   end

endmodule
