`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:13:30 04/05/2021 
// Design Name: 
// Module Name:    pwm 
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
module pwm(clk, dutycycle, out);
	input clk;
	input [7:0] dutycycle;
	output out;
	reg [7:0] count = 0;
	
	always@(posedge clk)
		begin 
			count <= count + 1;
		end
	assign out = count < dutycycle ? 1:0;
endmodule
