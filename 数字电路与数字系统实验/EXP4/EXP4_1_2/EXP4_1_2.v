module EXP4_1_2(in_data, clk, in_en, out_unlock1, out_unlock2);
    input in_data;
	 input clk;
	 input in_en;
	 
	 output reg out_unlock1;
	 output reg out_unlock2;
	 
	 always @ (posedge clk)
	 
	   if(in_en)
		  begin
		    out_unlock1 <= in_data;
			 out_unlock2 <= out_unlock1;
		  end
		else
		  begin
		    out_unlock1 <= out_unlock1;
			 out_unlock2 <= out_unlock2;
		  end

endmodule
