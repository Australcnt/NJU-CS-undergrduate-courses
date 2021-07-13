module EXP1(X0, X1, X2, X3, Y, F);
    input [1:0] X0;
	 input [1:0] X1;
	 input [1:0] X2;
	 input [1:0] X3;
    input [1:0] Y;
	 output reg [1:0] F;
	 
    always @ (X0 or X1 or X2 or X3 or Y)
      case (Y)
        0: F = X0;
        1: F = X1;
        2: F = X2;
        3: F = X3;
        default: F = 2'b00;
    endcase
	 
endmodule
