module EXP6_1(clk, sel, in, set, Q, count_clk, out_eight);
	 input clk;
	 input [2:0] sel;
	 input in;
	 input [7:0] set;
	 
	 output reg [7:0] Q = 0;
	 output reg [3:0] count_clk = 0;
	 output reg [7:0] out_eight = 0;
	 
	 always @(posedge clk)
	 begin
	   case (sel)
		  0: begin Q <= 0; count_clk = 0; end
		  1: begin Q <= set; count_clk = 0; end
		  2: begin Q <= {1'b0, Q[7:1]}; count_clk = 0; end
		  3: begin Q <= {Q[6:0], 1'b0}; count_clk = 0; end
		  4: begin Q <= {Q[7], Q[7:1]}; count_clk = 0; end
		  5: ;
		  6: begin Q <= {Q[0], Q[7:1]}; count_clk = 0; end
		  7: begin Q <= {Q[6:0], Q[7]}; count_clk = 0; end
		  default: Q <= Q;
		endcase
		if (sel == 5)
		begin
		  out_eight[count_clk] = in;
		  if(count_clk == 7)
		    Q <= out_eight;
		  count_clk = (count_clk + 1) % 8;
		end
	 end
		
endmodule
