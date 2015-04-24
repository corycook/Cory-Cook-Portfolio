`timescale 1ns / 1ps

// Cory Cook
// Lab 4

module babbage_engine #(parameter N=4)(input clk, reset, start, input [N-1:0] i,
	output reg [2**N-1:0] fn, output reg done_tick, ready);
	
	localparam idle = 2'b00, calc = 2'b01, done = 2'b10;
	reg [2**N-1:0] gn = 0, nfn, ngn;
	reg [N-1:0] n = 0, nn;
	reg [1:0] state = idle, nstate;


	always @(posedge clk, posedge reset) 
		if (reset) begin
			fn <= 0;
			gn <= 0;
			n <= 0;
			state <= idle;
		end else begin
			fn <= nfn;
			gn <= ngn;
			n <= nn;
			state <= nstate;
		end
	
	always @* begin
		ready = 0;
		done_tick = 0;
		case(state)
			idle: 
				begin if (start) nstate <= calc;
					else nstate <= idle;
					nfn <= 5;
					ngn <= 5;
					nn <= i;
					ready = 1;
				end
			calc: 
				begin
					if (n > 0) nstate <= calc; 
					else nstate <= done;
					if (n > 1) ngn <= gn + 4;
					else ngn <= gn;
					nfn <= fn + gn;
					nn <= n - 1;
				end 
			done: 
				begin
					ngn <= gn;
					nfn <= fn;
					nn <= n;
					done_tick = 1;
					nstate <= idle;
				end
			default: begin
				nstate <= state;
				ngn <= gn;
				nfn <= fn;
				nn <= n;
			end
		endcase
	end
endmodule
