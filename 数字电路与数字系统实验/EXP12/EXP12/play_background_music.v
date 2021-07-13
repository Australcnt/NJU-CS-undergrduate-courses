module play_backgroumd_music(clk,mode,freq);
	input [1:0]mode;
	input clk;
	output wire [15:0]freq;
	reg [10:0] addr;
	reg [1:0] choice;
	
	always@(*)
	begin
		if(mode==0)//主页
			choice=2;
		else if(mode==1)//输入用户名
			choice=3;
		else//游戏中
			choice=1;
	end
	
	always@(negedge clk)
	begin
		case(choice)
		2'b00:begin//stop
				addr=0;
				end
		2'b01:begin
				if(addr<552)
					addr=addr+1;
				else 
					addr=0;							
				end
		2'b10:begin
				if(addr<1112 && addr>551)
					addr=addr+1;
				else 
					addr=552;							
				end
		2'b11:begin
				if(addr<1728 && addr>1111)
					addr=addr+1;
				else 
					addr=1112;							
				end						
		endcase
	end
background_music bgm_piano(addr,clk,freq);
endmodule
	