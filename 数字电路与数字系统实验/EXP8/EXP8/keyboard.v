module EXP8(
clk, clrn, ps2_clk, ps2_data, ready, overflow, capital, shift, ctrl,
HEX0, HEX1, HEX2, HEX3, HEX4, HEX5,
);
   input clk;
	input clrn;
	input ps2_clk;
	input ps2_data;
	
	output ready;
	output overflow;
	
	output [6:0]HEX0;
	output [6:0]HEX1;
	output [6:0]HEX2;
	output [6:0]HEX3;
	output [6:0]HEX4;
	output [6:0]HEX5;
	
	output reg capital;
	output reg shift;
	output reg ctrl;

	reg capslock;
	reg capslock_flag;
	
	reg predata; //是否持续按键
	reg nextdata_n;
	wire [7:0] data; //接收从ps2_keyboard中得到的8位键码，作为实例化的wire输出
	reg [7:0] my_data; //接收8位键码
	reg [6:0] press_count; //存储按键次数   
	wire [7:0] ascii1; //存储小写ascii码
	wire [7:0] ascii2; //存储大写ascii码
	
	reg clk_large; //扩大了250倍的时钟
	reg [8:0]count_clk; //用作分频器
	
	initial
	begin
	   predata = 1;
		nextdata_n = 1;
		clk_large = 0;
		count_clk = 0;
		press_count = 0;
		my_data = 0;
		capital = 0;
		capslock = 0;
		capslock_flag = 0;
		shift = 0;
		ctrl = 0;

	end

	ps2_keyboard keyboard(clk, clrn, ps2_clk, ps2_data, data, ready, nextdata_n, overflow);
	ROM1 rom1(.address(my_data), .clock(clk), .q(ascii1));
	ROM2 rom2(.address(my_data), .clock(clk), .q(ascii2));
	display_scancode display1(predata, my_data, HEX0, HEX1);
	display_ascii display2(predata, capital, shift, my_data, ascii1, ascii2, HEX2, HEX3);
	display_presscount display3(press_count, HEX4, HEX5);

always @(posedge clk)
	begin
		if(count_clk == 500)
		begin
			count_clk <= 0;
			clk_large <= ~clk_large;
		end
		else
		count_clk <= count_clk + 1;
	end

always @(posedge clk_large)
begin
   if(ready == 1)
	begin
	   //capslock识别
		if(data[7:0] == 8'h58)    
		begin
			if(predata == 1 && capslock == 0)
			begin
				capital = ~capital;
				capslock = 1;
			end
			else if(predata == 0)
			begin
				capslock = 0;
				capslock_flag = ~capslock_flag;
		   end
		end
		//shift识别
		if(data[7:0] == 8'h12 || data[7:0] == 8'h59)    
		begin
			if(predata == 1 && shift == 0)
			begin
			   if(capital == 0)
				begin
				   capital = ~capital;
				end
				shift = 1;
			end
			else if(predata == 0)
			begin
			   if(capital == 1 && capslock_flag == 0)
			   begin
				   capital = ~capital;
				end
				shift = 0;
			end
		end
		//ctrl的识别
		if(data[7:0] == 8'h14)         
		begin
			if(predata == 1 && ctrl == 0)
			begin
				ctrl = 1; 
			end
			else if(predata == 0)
			begin
				ctrl = 0;
			end
		end
			
		if(data[7:0] != 8'hF0 && predata == 1)
		begin
			predata = 1;
			my_data = data;
		end
		else if(data[7:0] == 8'hF0)
		begin
			predata = 0;
			press_count = (press_count + 1) % 100;
			my_data = data; 
		end
		else if(predata == 0)    
		begin
			predata = 1;
		end

		nextdata_n = 0;
	end
		
	else 
	begin
		nextdata_n = 1;
	end
end
	
endmodule
