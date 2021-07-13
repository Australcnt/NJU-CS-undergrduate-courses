module keyboard(clk, clrn, ready, data, nextdata_n, count, ascii, scancode, press_flag, shift_flag, ctrl_flag, capslock_flag, capital_flag, special_char);
	
	input clk;
	input clrn;
	input ready;
	input [7:0] data;
	
	output reg nextdata_n;
	output reg [7:0] count = 0;
	output reg [7:0] ascii;
	output reg [7:0] scancode;
	output reg press_flag;
	output reg shift_flag;
	output reg ctrl_flag;
	output reg capslock_flag;
	output reg capital_flag;
	output reg [3:0] special_char;
	
	reg predata = 1; //是否持续按键
	reg [7:0] const = 8'hE0;
	reg [6:0] count_clk = 0;
	reg clk_large = 0;
	
	wire [7:0] ascii_copy; 
	
	(* ram_init_file = "zero.mif" *) reg helper[255:0];
	scancode2ascii my_ascii(data, ascii_copy);
	
	always @(posedge clk)
	begin
		if(count_clk == 100)
		begin
			count_clk <= 0;
			clk_large <= ~clk_large;
		end
		else
			count_clk <= count_clk + 1;
	end
	
	always @(posedge clk_large)
	begin
		if (ready)
		begin
			if(data != 8'hf0 && predata == 1)
			begin
				scancode <= data;
				if(helper[data] == 0) 
				begin
					helper[data] <= 1;
					count <= count + 1;
				end
				ascii <= ascii_copy;
				if (ascii_copy >= 65 && ascii_copy <= 90 || ascii_copy >= 97 && ascii_copy <= 122) 
				   if (capslock_flag || shift_flag)
					   ascii <= ascii_copy - 32;
				if (shift_flag)
				begin
					case (ascii_copy)
					   8'h60: ascii <= 8'h7E;
						8'h31: ascii <= 8'h21;
						8'h32: ascii <= 8'h40;
						8'h33: ascii <= 8'h23;
						8'h34: ascii <= 8'h24;
						8'h35: ascii <= 8'h25;
						8'h36: ascii <= 8'h5E;
						8'h37: ascii <= 8'h26;
						8'h38: ascii <= 8'h2A;
						8'h39: ascii <= 8'h28;
						8'h30: ascii <= 8'h29;
						8'h2D: ascii <= 8'h5F;
						8'h3D: ascii <= 8'h2B;
						8'h5B: ascii <= 8'h7B;
						8'h5D: ascii <= 8'h7D;
						8'h5C: ascii <= 8'h7C;
						8'h3B: ascii <= 8'h3A;
						8'h27: ascii <= 8'h22;
						8'h2C: ascii <= 8'h3C;
						8'h2E: ascii <= 8'h3E;
						8'h2F: ascii <= 8'h3F;
						8'h7F: ascii <= 8'h2E;
					endcase
				end
				predata <= 1;
				press_flag <= 1;
				
				if (data == 8'h12 || data == 8'h59) //shift的识别
				begin 
				   if (capital_flag == 0)
					begin
					   capital_flag = 1;
					end
					shift_flag <= 1;
					special_char <= 7;
				end
				else if (data == 8'h58) //capslock的识别
				begin
					if (capital_flag == 0)
					begin
					   //capslock_flag <= capslock_flag + 1;
					   capital_flag = 1;
					end
					capslock_flag <= 1;
					special_char <= 7;
				end
				else if (data == 8'h14) //ctrl的识别
				begin 
					ctrl_flag <= 1;
					special_char <= 7;
				end
				else if (data == 8'h66) //backspace的识别
					special_char <= 6;
				else if (data == 8'h5A) //enter的识别
					special_char <= 5;
				else if (helper[const] == 1 && data == 8'h6B) //左
					special_char <= 1;
				else if (helper[const] == 1 && data == 8'h74) //右
				   special_char <= 4;
				else if (helper[const] == 1 && data == 8'h72) //下
					special_char <= 2;
				else if (helper[const] == 1 && data == 8'h75) //上
					special_char <= 3;
				else
					special_char <= 0;
			end
			else if (data == 8'hf0)//释放
			begin
				scancode <= data;
				ascii <= ascii_copy;
				predata <= 0;
				press_flag <= 0;
			end
			else if(!predata)
			begin
				if(data == 8'h12 || data == 8'h59) 
				   shift_flag <= 0;
				if(data == 8'h58) 
				   capslock_flag <= 0;
				if(data == 8'h14) 
				   ctrl_flag <= 0;
				if(shift_flag == 0 && capslock_flag == 0)
				   capital_flag = 0;
				helper[data] <= 0;
				scancode <= data;
				ascii <= ascii_copy;
				predata <= 1;
				press_flag <= 0;
			end
			nextdata_n <= 0;
		end
		else
		begin
			nextdata_n <= 1;
		end
	end
	
	
endmodule
