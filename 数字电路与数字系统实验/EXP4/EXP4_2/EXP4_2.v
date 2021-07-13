module EXP4_2(in_data, clk, clr, in_en, out_unlock1, out_unlock2);
    input in_data;
	 input clk;
	 input clr;
	 input in_en;
	 
	 output out_unlock1;
	 output out_unlock2;
	 
    synchro a (in_data, clk, clr, in_en, out_unlock1);
    asynchro b (in_data, clk, clr, in_en, out_unlock2);


endmodule
