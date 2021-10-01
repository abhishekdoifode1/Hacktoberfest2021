//Ring Counter as FSM
module ring_FSM(output reg [3:0] Y, input CLK, RESET);
parameter s0= 2'd0;
parameter s1= 2'd1;
parameter s2= 2'd2;
parameter s3= 2'd3;
reg [1:0] ps, ns;

initial 
begin
	ps <= s0;
	ns <= s0;
end

always @ (posedge CLK)
begin
	if(RESET)
		ns<= s0;
	else
	begin
		case(ps)
		s0 : ns<=s1;
		s1 : ns<=s2;
		s2 : ns<=s3;
		default : ns<=s0;
		endcase
	ps<= ns;
        end
end

always @(posedge CLK)
begin
	if(RESET)
		Y<= 4'b1000;
	else
	begin
		case(ps)
		s0 : Y<=4'b1000;
		s1 : Y<=4'b0100;
		s2 : Y<=4'b0010;
		default : Y<=4'b0001;
		endcase 
	
end
end
endmodule 

		
module test_ringFSM;
wire [3:0] Y;
reg CLK= 1'b1;
reg RESET= 1'b0;
ring_FSM j1( Y, CLK, RESET);
always 
#5 CLK =~ CLK;

initial 
begin
#100 RESET = 1'b0;
#50 RESET = 1'b0;
end
endmodule 
