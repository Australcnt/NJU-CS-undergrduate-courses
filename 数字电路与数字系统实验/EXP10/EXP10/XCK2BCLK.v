module XCK2BCLK(AUD_XCK, AUD_BCLK);
	input AUD_XCK;
	output reg AUD_BCLK;
	reg [3:0] count_XCK = 0;
	
   always @(posedge AUD_XCK)
   begin
      if(count_XCK == 6)
      begin
         count_XCK <= 0;
         AUD_BCLK = ~AUD_BCLK;
      end
     else
         count_XCK <= count_XCK + 1;
   end
	
endmodule
