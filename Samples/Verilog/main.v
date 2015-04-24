`timescale 1ns / 1ps

module main(
    input [3:0] sw,
    input clk,
    input reset,
    input btn,
    output [7:0] sseg,
	 output [3:0] an,
	 output led
    );
	 
	wire [15:0] fn;
	reg [15:0] dfn;
	wire done;
	 
	disp_hex_mux disp(
		.clk(clk),
		.reset(reset),
		.hex3(dfn[15:12]),
		.hex2(dfn[11:8]),
		.hex1(dfn[7:4]),
		.hex0(dfn[3:0]),
		.dp_in(0),
		.an(an),
		.sseg(sseg)
	);
	babbage_engine calc (
		.clk(clk),
		.reset(reset),
		.start(btn),
		.i(sw),
		.fn(fn),
		.done_tick(done),
		.ready(led)
	);
	always @(posedge done) dfn <= fn;
endmodule
