module asynchro(in_data, clk, clr, in_en, out_unlock);
    input in_data;
	 input clk;
	 input clr;
	 input in_en;
	 
	 output reg out_unlock;
	 
	 always @ (posedge clk or posedge clr)
	 
	   if(clr)
		  begin
		    if(in_en)
			   out_unlock = 0;
			 else
			   out_unlock <= out_unlock;
		  end
		else
		  begin
	       if(in_en)
		      out_unlock <= in_data;
		    else
		      out_unlock <= out_unlock;
		  end

endmodule
