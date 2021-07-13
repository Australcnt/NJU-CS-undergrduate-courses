module EXP10(
	input 		          		CLOCK_50,
	input 		     [1:0]		VOLUME,
	input                      RST,

	output		     [9:0]		LEDR,

	output		     [6:0]		HEX0,
	output		     [6:0]		HEX1,
	output	 reg    [6:0]		HEX2,
	output	 reg    [6:0]		HEX3,
	output	 reg    [6:0]		HEX4,
	output	 reg    [6:0]		HEX5,
	
	inout 		          	   AUD_BCLK,
	output		          		AUD_DACDAT,
	inout 		         	   AUD_DACLRCK,
	output		          	   AUD_XCK,

	inout 		          		PS2_CLK,
	inout 		          		PS2_DAT,

	output		          		I2C_SCLK,
	inout 		          		I2C_SDAT
);


   wire clk_i2c;
   wire reset;
   wire [15:0] audio_data;
   wire [15:0] freq;
	wire [8:0] vol;

	assign reset = ~RST;
	
	initial
	begin
	   HEX2 = 7'b1111111;
	   HEX3 = 7'b1111111;
	   HEX4 = 7'b1111111;
	   HEX5 = 7'b1111111;
	end
	
   audio_clk my_aud_clk(CLOCK_50, reset, AUD_XCK, LEDR[9]);
	
	//XCK2BCLK my_bclk(AUD_XLK, AUD_BCLK);
	
	//BCLK2DACLRCK my_daclrck(AUD_XLK, AUD_BCLK);

   //I2C part

   clkgen #(10000) my_i2c_clk(CLOCK_50, reset, 1'b1, clk_i2c);  //10k I2C clock  

   I2C_Audio_Config my_i2c(clk_i2c, ~reset, I2C_SCLK, I2C_SDAT, VOLUME, vol);

   I2S_Audio my_i2s(AUD_XCK, ~reset, AUD_BCLK, AUD_DACDAT, AUD_DACLRCK, audio_data);

   Sin_Generator my_sin(AUD_DACLRCK, ~reset, freq, audio_data);

   keyboard my_keyboard(CLOCK_50, PS2_CLK, PS2_DAT, freq);

	display_volume my_vol(vol, HEX0, HEX1);
	
endmodule
