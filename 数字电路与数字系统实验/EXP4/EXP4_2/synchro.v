module synchro(in_data, clk, clr, in_en, out_unlock);
    input in_data;
	 input clk;
	 input clr;
	 input in_en;
	 
	 output reg out_unlock;
	 
	 always @ (posedge clk)
	 
	   if(!in_en)
		  out_unlock <= out_unlock;
		else
		  begin
	       if(clr)
		      out_unlock = 0;
		    else
		      out_unlock <= in_data;
		  end

endmodule
