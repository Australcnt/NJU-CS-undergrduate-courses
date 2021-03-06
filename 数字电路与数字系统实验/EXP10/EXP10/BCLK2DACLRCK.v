module BCLK2DACLRCK(AUD_BCLK, AUD_DACLRCK);
	input AUD_BCLK;
	output reg AUD_DACLRCK;
	reg [4:0] count_BCLK = 0;
	
   always @(posedge AUD_BCLK)
   begin
      if(count_BCLK == 16)
      begin
         count_BCLK <= 0;
         AUD_DACLRCK = ~AUD_DACLRCK;
      end
      else
         count_BCLK <= count_BCLK + 1;
   end
	
endmodule
