module EXP2(X, Y, C0, C1, C2, C3, S, T, P);
    input [7:0] X;

	 output reg [3:0] Y;
	 output reg [6:0] C0;
	 output reg [6:0] C1;
	 output reg [6:0] C2;
	 output reg [6:0] C3;
	 output reg [2:0] S;
	 output reg [6:0] T;
	 output reg [6:0] P;
	 
	 integer i;
	 
	 always @ (*)
	 begin
		Y = 8;
	   for ( i = 0; i <= 7; i = i + 1 )
		  begin
		  if ( X[i] == 1 )  Y = i + 8;
	     if ( i == 7 && X[0] == 0 && Y == 8 )  Y = Y - 8;
		  end
		  
	   C0 = 127;
	   C1 = 127;
	   C2 = 127;
	   C3 = 127;
	   if ( Y[0] == 0 )  C0 =  64;
	   else  C0 = 121;
	   if ( Y[1] == 0 )  C1 =  64;
	   else  C1 = 121;
	   if ( Y[2] == 0 )  C2 =  64;
	   else  C2 = 121;
	   if ( Y[3] == 0 )  C3 =  64;
	   else  C3 = 121;
	 
	   S = 0;
		T = 127;
	   if (C0 == 121)  S = S + 1;
	   if (C1 == 121)  S = S + 2;
	   if (C2 == 121)  S = S + 4;
	 
	   case(S)
		  0 : T = 64;
		  1 : T = 121;
		  2 : T = 36;
		  3 : T = 48;
		  4 : T = 25;
		  5 : T = 18;
		  6 : T = 2;
		  7 : T = 120;
		  default : T = 127;
		endcase
		
		P = 127;
		
    end

endmodule
