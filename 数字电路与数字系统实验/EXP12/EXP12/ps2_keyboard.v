module ps2_keyboard(clk,clr,ps2_clk,ps2_data,data,
			ready); 
			input clk,clr,ps2_clk,ps2_data; 
			
			output reg [7:0] data; 
			output reg ready; 
			
			
			// internal signal, for test 
			reg [9:0] buffer; // ps2_data bits 
		
		
			reg [3:0] count; // count ps2_data bits 
			// detect falling edge of ps2_clk 
			reg [2:0] ps2_clk_sync; 
			
			always @(posedge clk) begin 
				ps2_clk_sync <= {ps2_clk_sync[1:0],ps2_clk}; 
			end 
			
			wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1]; 
			
			always @(posedge clk)
			begin
				if (clr == 1)
				begin // reset 
					count <= 0; 
				//	overflow <= 0; 
					ready<= 0; 
				end 
				else if (sampling)
					  begin 
							if (count == 4'd10)
							begin 
								if ((buffer[0] == 0) && // start bit 
									(ps2_data) && // stop bit 
									(^buffer[9:1]))
								begin // odd parity 
										data <= buffer[8:1]; // kbd scan code 
										if(data==8'hF0)
											ready <= 1'b1; 
								//		overflow <= overflow | (r_ptr == (w_ptr + 3'b1)); 
								end 
								count <= 0; // for next 
							end 
							else
							begin 
								buffer[count] <= ps2_data; // store ps2_data 
								count <= count + 3'b1;
								ready <= 0;
							end 
					  end 
						
			end		 
		
 endmodule
 