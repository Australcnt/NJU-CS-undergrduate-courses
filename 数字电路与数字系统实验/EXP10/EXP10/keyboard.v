module keyboard(
   clk, 
	ps2_clk, 
	ps2_data, 
	freq
	);
	
	input clk;
   input	ps2_clk;
	input ps2_data;
	
	output reg [15:0] freq;
	
	reg nextdata_n;
	reg pre;
	reg [6:0] count_clk;
	reg clk_large;
	reg C5;
	reg D5;
	reg E5;
	reg F5;
	reg G5;
	reg A5;
	reg B5;
	reg C6;
	
	wire ready;
	wire overflow;
	wire [7:0] data;

	initial
	begin
		nextdata_n = 1;
		pre = 1;
		C5 = 0;
		D5 = 0;
		E5 = 0;
		F5 = 0;
		G5 = 0;
		A5 = 0;
		B5 = 0;
		C6 = 0;
	end

	ps2_keyboard key(clk, 1, ps2_clk, ps2_data, data, ready, nextdata_n, overflow);
	
	
	always @(posedge clk)
	begin
		if(count_clk == 100)
		begin
			count_clk <= 0;
			clk_large = ~clk_large;
		end
		else
			count_clk <= count_clk + 1;
	end
	
	
	
	always @(posedge clk_large)
	begin
		if (ready == 1)
		begin
			if (pre == 1)
			begin
				case(data)
					//8'h1C: freq = 523.25 * 65536 / 48000;
					//8'h1B: freq = 587.33 * 65536 / 48000;
					//8'h23: freq = 659.26 * 65536 / 48000;
					//8'h2B: freq = 698.46 * 65536 / 48000;
					//8'h34: freq = 783.99 * 65536 / 48000;
					//8'h33: freq = 880.00 * 65536 / 48000;
					//8'h3B: freq = 987.77 * 65536 / 48000;
					//8'h42: freq = 1046.5 * 65536 / 48000;
					8'h1C: C5 = 1;
					8'h1B: D5 = 1;
					8'h23: E5 = 1;
					8'h2B: F5 = 1;
					8'h34: G5 = 1;
					8'h33: A5 = 1;
					8'h3B: B5 = 1;
					8'h42: C6 = 1;
					default: freq = 0;
				endcase
				if(data[7:0] == 8'hF0)
				begin
					pre = 0;
				end
			end
			else if(pre == 0)    
			begin
				pre = 1;
				//freq = 0;
				case(data)
					8'h1C: C5 = 0;
					8'h1B: D5 = 0;
					8'h23: E5 = 0;
					8'h2B: F5 = 0;
					8'h34: G5 = 0;
					8'h33: A5 = 0;
					8'h3B: B5 = 0;
				   8'h42: C6 = 0;
					//default: freq = 0;
				endcase
			end
			
			if(C5 || D5 || E5 || F5 || G5 || A5 || B5 || C6)
		      freq = (C5 * 523 + D5 * 587 + E5 * 659 + F5 * 698 + G5 * 784 + A5 * 880 + B5 * 988 + C6 * 1047) 
	                 / (C5 + D5 + E5 + F5 + G5 + A5 + B5 + C6) * 65536 / 48000;
		   else
			   freq = 0;
			
			nextdata_n = 0;
			
		end
		
		else
			nextdata_n = 1;
	end
	
endmodule
