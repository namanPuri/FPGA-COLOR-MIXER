`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:05:46 04/21/2021 
// Design Name: 
// Module Name:    clkBy3 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module clkBy3(clk_in, clk_out);
	input clk_in;
	output clk_out;
	wire d_in;
	wire d_out;
	mod3counter C(clk_in, d_in);
	dff D(d_in, clk_in, d_out);
	or G1(clk_out, d_in, d_out);
endmodule

module mod3counter(clk, count);
	input clk;
	reg [1:0]countemp = 2'b0;
	output count;
	
	assign count = countemp[1];
	always@(posedge clk)
		begin
			countemp = countemp + 1'b1;
			if(countemp == 3)
				countemp = 2'b0;
		end
endmodule 

module dff(d, clk, q);
	input d;
	input clk;
	output reg q=0;
	always@(negedge clk)
		begin
			q = d;
		end
endmodule 