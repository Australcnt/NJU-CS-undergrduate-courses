module EXP5_2(
clk, count_clk, clk_1s, count_scd, count_min, count_hour, 
digit0, digit1, digit2, digit3, digit4, digit5, 
HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, 
pause, shift_scd, shift_min, shift_hour, 
alarm, alarm_set, alarm_shift_min, alarm_shift_hour, 
alarm_min, alarm_hour, alarm_digit2, alarm_digit3, alarm_digit4, alarm_digit5,
alarm_min_set, alarm_hour_set, alarm_flag, alarm_remind,
clk2, count_clk2, clk2_1s, clk2_1ms, count_mscd2, count_scd2, count_min2,
chrono, chrono_start_and_pause, chrono_clear,
chrono_digit0, chrono_digit1, chrono_digit2, chrono_digit3, chrono_digit4, chrono_digit5
);

    input clk;
	 input pause;
	 input shift_scd;
	 input shift_min;
	 input shift_hour;
	 input alarm;
	 input alarm_set;
	 input alarm_shift_min;
	 input alarm_shift_hour;
	 input clk2;
	 input chrono;
	 input chrono_start_and_pause;
	 input chrono_clear;
	 
	 output reg [24:0] count_clk = 0;
	 output reg clk_1s = 0;
	 output reg [5:0] count_scd = 0;
	 output reg [5:0] count_min = 0;
	 output reg [4:0] count_hour = 0;
	 output reg [3:0] digit0 = 0;
	 output reg [3:0] digit1 = 0;
	 output reg [3:0] digit2 = 0;
	 output reg [3:0] digit3 = 0;
	 output reg [3:0] digit4 = 0;
	 output reg [3:0] digit5 = 0;
	 output reg [6:0] HEX0 = 64;
	 output reg [6:0] HEX1 = 64;
	 output reg [6:0] HEX2 = 64;
	 output reg [6:0] HEX3 = 64;   
	 output reg [6:0] HEX4 = 64;
	 output reg [6:0] HEX5 = 64;
	 output reg [5:0] alarm_min = 0;
	 output reg [4:0] alarm_hour = 0;
	 output reg [3:0] alarm_digit2 = 0;
	 output reg [3:0] alarm_digit3 = 0;
	 output reg [3:0] alarm_digit4 = 0;
	 output reg [3:0] alarm_digit5 = 0;
	 output reg [5:0] alarm_min_set = 0;
	 output reg [4:0] alarm_hour_set = 0;
	 output reg alarm_flag = 0;
	 output reg [9:0] alarm_remind = 0;
	 output reg [24:0] count_clk2 = 0;
	 output reg clk2_1s = 0;
	 output reg clk2_1ms = 0;
	 output reg [9:0] count_mscd2 = 0;
	 output reg [5:0] count_scd2 = 0;
	 output reg [5:0] count_min2 = 0;
	 output reg [3:0] chrono_digit0 = 0;
	 output reg [3:0] chrono_digit1 = 0;
	 output reg [3:0] chrono_digit2 = 0;
	 output reg [3:0] chrono_digit3 = 0;
	 output reg [3:0] chrono_digit4 = 0;
	 output reg [3:0] chrono_digit5 = 0;
	 
	always @(posedge clk)
	begin
     if (pause == 1)
	  begin
	    if (shift_scd == 1)
		 begin
			if (count_clk == 25000000)
	      begin
	        count_clk <= 0;
	        clk_1s <= ~clk_1s;
		     if (clk_1s == 1)
		       count_scd <= (count_scd + 1) % 60;
		     digit0 = count_scd % 10;
		     digit1 = count_scd / 10;
			end
			else
			  count_clk <= count_clk + 1;
		 end
		 if (shift_min == 1)
		 begin
			if (count_clk == 25000000)
	      begin
	        count_clk <= 0;
	        clk_1s <= ~clk_1s;
		     if(clk_1s == 1)
		       count_min <= (count_min + 1) % 60;
		     digit2 = count_min % 10;
		     digit3 = count_min / 10;
			end
			else
			  count_clk <= count_clk + 1;
		 end
		 if (shift_hour == 1)
		 begin
			if (count_clk == 25000000)
	      begin
	        count_clk <= 0;
	        clk_1s <= ~clk_1s;
		     if(clk_1s == 1)
		       count_hour <= (count_hour + 1) % 24;
		     digit4 = count_hour % 10;
		     digit5 = count_hour / 10;
			end
			else
			  count_clk <= count_clk + 1;
		 end
	  end
	  else if (count_clk == 25000000)
	  begin
	    count_clk <= 0;
	    clk_1s <= ~clk_1s;
		 if (clk_1s == 1)
		   count_scd <= (count_scd + 1) % 60;
		 if(clk_1s == 1 && count_scd == 59)
		   count_min <= (count_min + 1) % 60;
		 if(clk_1s == 1 && count_min == 59 && count_scd == 59)
		   count_hour <= (count_hour + 1) % 24;
		 digit0 = count_scd % 10;
		 digit1 = count_scd / 10;
		 digit2 = count_min % 10;
		 digit3 = count_min / 10;
		 digit4 = count_hour % 10;
		 digit5 = count_hour / 10;
	  end
	  else
	    count_clk <= count_clk + 1;
	  if (alarm == 1)
	  begin
	    if (alarm_shift_min == 0 && count_clk == 25000000)
		   alarm_min <= (alarm_min + 1) % 60;
		 if (alarm_shift_hour == 0 && count_clk == 25000000)
		   alarm_hour <= (alarm_hour + 1) % 24;
		 alarm_digit2 = alarm_min % 10;
		 alarm_digit3 = alarm_min / 10;
		 alarm_digit4 = alarm_hour % 10;
		 alarm_digit5 = alarm_hour / 10;
		 if (alarm_set == 0)
		 begin
		   alarm_min_set = alarm_min;
			alarm_hour_set = alarm_hour;
		   alarm_flag = 1;
		 end
	  end
	  else if (chrono == 0 && alarm_flag == 1)
	  begin
	    if (count_min == alarm_min_set && count_hour == alarm_hour_set)
		  begin
		    if (clk_1s == 1)
			   alarm_remind <= 1023;
			 else
			   alarm_remind <= 0;
		  end
	  end
	  if (count_min != alarm_min_set || count_hour != alarm_hour_set)
	    alarm_remind <= 0;
	end
	
	
	always @(posedge clk2)
	begin
	  if (chrono == 1)
	  begin
	    if ( chrono_start_and_pause == 1)
		 begin
		   if (count_clk2 % 25000 == 0)
	      begin
	        clk2_1ms <= ~clk2_1ms;
		     if (clk2_1ms == 1)
		       count_mscd2 <= (count_mscd2 + 1) % 1000;
		     chrono_digit0 = (count_mscd2 % 100) / 10;
		     chrono_digit1 = count_mscd2 / 100;
		   end
		   if (count_clk2 == 25000000)
	      begin
	        count_clk2 <= 0;
	        clk2_1s <= ~clk2_1s;
		     if (clk2_1s == 1)
		       count_scd2 = (count_scd2 + 1) % 60;
		     if (clk2_1s == 0 && count_scd2 == 59)
		       count_min2 <= (count_min2 + 1) % 60;
		     chrono_digit2 = count_scd2 % 10;
		     chrono_digit3 = count_scd2 / 10;
		     chrono_digit4 = count_min2 % 10;
		     chrono_digit5 = count_min2 / 10;
		   end
			else
	        count_clk2 <= count_clk2 + 1;
		 end
		 if (chrono_clear == 1)
		 begin
		   count_clk2 <= 0;
			clk2_1ms <= 0;
			clk2_1s <= 0;
			count_mscd2 <= 0;
			count_scd2 <= 0;
			count_min2 <= 0;
			chrono_digit0 = 0;
			chrono_digit1 = 0;
			chrono_digit2 = 0;
			chrono_digit3 = 0;
			chrono_digit4 = 0;
			chrono_digit5 = 0;
		 end
	  end
	  else
	  begin
	  chrono_digit0 = 0;
     chrono_digit1 = 0;
	  chrono_digit2 = 0;
	  chrono_digit3 = 0;
	  chrono_digit4 = 0;
	  chrono_digit5 = 0;
	  end
	end
	
	always @(*)
	begin
	  if (alarm == 1)
	  begin
	    HEX0 = 71;
	    HEX1 = 8;
	    case (alarm_digit2)
		   0: HEX2 = 64;
	      1: HEX2 = 121;
		   2: HEX2 = 36;
		   3: HEX2 = 48;
		   4: HEX2 = 25;
		   5: HEX2 = 18;
		   6: HEX2 = 2;
		   7: HEX2 = 120;
		   8: HEX2 = 0;
		   9: HEX2 = 16;
		   default: HEX2 = 64;
	    endcase
	    case (alarm_digit3)
		   0: HEX3 = 64;
		   1: HEX3 = 121;
		   2: HEX3 = 36;
		   3: HEX3 = 48;
		   4: HEX3 = 25;
		   5: HEX3 = 18;
		   6: HEX3 = 2;
		   7: HEX3 = 120;
		   8: HEX3 = 0;
		   9: HEX3 = 16;
		   default: HEX3 = 64;
	    endcase
	    case (alarm_digit4)
		   0: HEX4 = 64;
		   1: HEX4 = 121;
		   2: HEX4 = 36;
		   3: HEX4 = 48;
		   4: HEX4 = 25;
		   5: HEX4 = 18;
		   6: HEX4 = 2;
		   7: HEX4 = 120;
		   8: HEX4 = 0;
		   9: HEX4 = 16;
		   default: HEX4 = 64;
	    endcase
	    case (alarm_digit5)
		   0: HEX5 = 64;
		   1: HEX5 = 121;
		   2: HEX5 = 36;
		   3: HEX5 = 48;
		   4: HEX5 = 25;
		   5: HEX5 = 18;
		   6: HEX5 = 2;
		   7: HEX5 = 120;
		   8: HEX5 = 0;
		   9: HEX5 = 16;
		   default: HEX5 = 64;
	    endcase
	  end
	  else if (chrono == 1)
	  begin
	    case (chrono_digit0)
		   0: HEX0 = 64;
		   1: HEX0 = 121;
		   2: HEX0 = 36;
		   3: HEX0 = 48;
		   4: HEX0 = 25;
		   5: HEX0 = 18;
		   6: HEX0 = 2;
		   7: HEX0 = 120;
		   8: HEX0 = 0;
		   9: HEX0 = 16;
		   default: HEX0 = 64;
	    endcase
	    case (chrono_digit1)
		   0: HEX1 = 64;
		   1: HEX1 = 121;
		   2: HEX1 = 36;
		   3: HEX1 = 48;
		   4: HEX1 = 25;
		   5: HEX1 = 18;
		   6: HEX1 = 2;
		   7: HEX1 = 120;
		   8: HEX1 = 0;
		   9: HEX1 = 16;
		   default: HEX1 = 64;
	    endcase
	    case (chrono_digit2)
		   0: HEX2 = 64;
	      1: HEX2 = 121;
		   2: HEX2 = 36;
		   3: HEX2 = 48;
		   4: HEX2 = 25;
		   5: HEX2 = 18;
		   6: HEX2 = 2;
		   7: HEX2 = 120;
		   8: HEX2 = 0;
		   9: HEX2 = 16;
		   default: HEX2 = 64;
	    endcase
	    case (chrono_digit3)
		   0: HEX3 = 64;
		   1: HEX3 = 121;
		   2: HEX3 = 36;
		   3: HEX3 = 48;
		   4: HEX3 = 25;
		   5: HEX3 = 18;
		   6: HEX3 = 2;
		   7: HEX3 = 120;
		   8: HEX3 = 0;
		   9: HEX3 = 16;
		   default: HEX3 = 64;
	    endcase
	    case (chrono_digit4)
		   0: HEX4 = 64;
		   1: HEX4 = 121;
		   2: HEX4 = 36;
		   3: HEX4 = 48;
		   4: HEX4 = 25;
		   5: HEX4 = 18;
		   6: HEX4 = 2;
		   7: HEX4 = 120;
		   8: HEX4 = 0;
		   9: HEX4 = 16;
		   default: HEX4 = 64;
	    endcase
	    case (chrono_digit5)
		   0: HEX5 = 64;
		   1: HEX5 = 121;
		   2: HEX5 = 36;
		   3: HEX5 = 48;
		   4: HEX5 = 25;
		   5: HEX5 = 18;
		   6: HEX5 = 2;
		   7: HEX5 = 120;
		   8: HEX5 = 0;
		   9: HEX5 = 16;
		   default: HEX5 = 64;
	    endcase
	  end
	  else
	  begin
       case (digit0)
		   0: HEX0 = 64;
		   1: HEX0 = 121;
		   2: HEX0 = 36;
		   3: HEX0 = 48;
		   4: HEX0 = 25;
		   5: HEX0 = 18;
		   6: HEX0 = 2;
		   7: HEX0 = 120;
		   8: HEX0 = 0;
		   9: HEX0 = 16;
		   default: HEX0 = 64;
	    endcase
	    case (digit1)
		   0: HEX1 = 64;
		   1: HEX1 = 121;
		   2: HEX1 = 36;
		   3: HEX1 = 48;
		   4: HEX1 = 25;
		   5: HEX1 = 18;
		   6: HEX1 = 2;
		   7: HEX1 = 120;
		   8: HEX1 = 0;
		   9: HEX1 = 16;
		   default: HEX1 = 64;
	    endcase
	    case (digit2)
		   0: HEX2 = 64;
		   1: HEX2 = 121;
		   2: HEX2 = 36;
		   3: HEX2 = 48;
		   4: HEX2 = 25;
		   5: HEX2 = 18;
		   6: HEX2 = 2;
		   7: HEX2 = 120;
		   8: HEX2 = 0;
		   9: HEX2 = 16;
		   default: HEX2 = 64;
       endcase
	    case (digit3)
		   0: HEX3 = 64;
		   1: HEX3 = 121;
		   2: HEX3 = 36;
		   3: HEX3 = 48;
		   4: HEX3 = 25;
		   5: HEX3 = 18;
		   6: HEX3 = 2;
		   7: HEX3 = 120;
		   8: HEX3 = 0;
		   9: HEX3 = 16;
		   default: HEX3 = 64;
	    endcase
	    case (digit4)
		   0: HEX4 = 64;
		   1: HEX4 = 121;
		   2: HEX4 = 36;
		   3: HEX4 = 48;
		   4: HEX4 = 25;
		   5: HEX4 = 18;
		   6: HEX4 = 2;
		   7: HEX4 = 120;
		   8: HEX4 = 0;
		   9: HEX4 = 16;
		   default: HEX4 = 64;
	    endcase
	    case (digit5)
		   0: HEX5 = 64;
		   1: HEX5 = 121;
		   2: HEX5 = 36;
		   3: HEX5 = 48;
		   4: HEX5 = 25;
		   5: HEX5 = 18;
		   6: HEX5 = 2;
		   7: HEX5 = 120;
		   8: HEX5 = 0;
		   9: HEX5 = 16;
		   default: HEX5 = 64;
       endcase
	  end 
   end
	
endmodule
