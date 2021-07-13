module EXP3_1(x, y, my, cin, result, cf, of, zf);
  input [3:0] x;
  input [3:0] y;
  input cin;

  output reg [3:0] my;
  output reg [3:0] result;
  output reg cf;
  output reg of;
  output reg zf;
  
  always @ (*)
  begin
  
    my = {4{cin}} ^ y;
	 {cf, result} = x + my + cin;
	 cf = cf ^ cin;
	 of = (x[3] == my[3]) && (result[3] != x[3]);
	 zf = ~(| result);
  end

endmodule
  