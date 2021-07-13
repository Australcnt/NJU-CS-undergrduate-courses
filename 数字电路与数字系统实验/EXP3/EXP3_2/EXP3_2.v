module EXP3_2(sel, a, b, mb, result, cf, of, HEX_result0, HEX_result1, HEX_result2, HEX_result3, HEX_cf, HEX_of);
  input [2:0] sel;
  input [3:0] a;
  input [3:0] b;
  
  output reg [3:0] mb;
  output reg [3:0] result;
  output reg cf;
  output reg of;
  output reg [6:0] HEX_result0;
  output reg [6:0] HEX_result1;
  output reg [6:0] HEX_result2;
  output reg [6:0] HEX_result3;
  output reg [6:0] HEX_cf;
  output reg [6:0] HEX_of;
  
  always @ (*)
  begin
  
    cf = 0;
	 of = 0;
	 mb = 0;
    if(sel == 0)//a+b
    begin
	   {cf, result} = a + b;
	   of = (a[3] == b[3]) && (result[3] != a[3]);	
	 end
    else if(sel == 1)//a-b
	 begin
		mb = ~b;
	   {cf, result} = a + mb + 1;
		cf = ~cf;
	   of = (a[3] == mb[3]) && (result[3] != a[3]);
	 end
	 else if(sel == 2)//not a
	 begin
	   result = ~a;
	 end
	 else if(sel == 3)//a and b
	 begin
	   result = a & b;
		end
	 else if(sel == 4)//a or b
	 begin
	   result = a | b;
	 end
	 else if(sel == 5)//a xor b
	 begin
	   result = a ^ b;
	 end
	 else if(sel == 6)//If a > b then result = 1; else result = 0; 
	 begin
	   if(a[3] == 0 && b[3] == 1)
		  result = 1;
		else if(a[3] == 0 && b[3] == 0 && a > b)
		  result = 1;
		else if(a[3] == 1 && b[3] == 1 && a > b)
		  result = 1;
		else
		  result = 0;
	 end
	 else//If a == b then result = 1; else result = 0;
	 begin
	   if(a == b)
		  result = 1;
		else
		  result = 0;
	 end
	 if(result[0] == 0)
	   HEX_result0 = 64;
	 else
	   HEX_result0 = 121;
	 if(result[1] == 0)
	   HEX_result1 = 64;
	 else
	   HEX_result1 = 121;
	 if(result[2] == 0)
	   HEX_result2 = 64;
	 else
	   HEX_result2 = 121;
	 if(result[3] == 0)
	   HEX_result3 = 64;
	 else
	   HEX_result3 = 121;
	 if(cf == 0)
	   HEX_cf = 64;
	 else
	   HEX_cf = 121;
	 if(of == 0)
	   HEX_of = 64;
	 else
	   HEX_of  = 121;
  end

endmodule
