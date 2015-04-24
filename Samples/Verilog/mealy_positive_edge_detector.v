`timescale 1ns / 1ps

module mealy_positive_edge_detector(input in, input clk, output y);
	 reg state = 0;
	 always @(posedge clk) state <= in;
	 assign y = {state, in} == 2'b01 ? 1 : 0;
endmodule
