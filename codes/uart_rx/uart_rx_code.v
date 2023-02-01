`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:37:17 05/10/2021 
// Design Name: 
// Module Name:    uart_rx_code 
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
module uart_rx_code(reset, rx, clk, red, green, blue, intensity);			//Control Path
	input reset,rx,clk;									   							//active low reset
	output [7:0]red,blue,green;
	reg [7:0]rxdata;
	output [7:0]intensity;
	//Variables for data path elements connections
	wire clk10khz, clk1_25;
	wire [3:0] mux_out,count;
	reg [3:0] value4 = 4'b0100;
	reg [3:0] value8 = 4'b1000;
	reg [2:0] ram_addr;
	//Variables for control and status signals
	reg resetbg,mux_sel,resetdc;
	wire eq,of_dc;
	reg ram_write;
	reg [3:0]ram_data_in;
	//Data Path elements instantiation
	ram r(ram_addr, ram_write, ram_data_in, red[3:0], green[3:0], blue[3:0], intensity[3:0], red[7:4], green[7:4], blue[7:4], intensity[7:4]);
	clk_divider cd(clk, clk10khz, clk1_25);
	baudrate br(resetbg, clk10khz, count);
	mux m(value4, value8, mux_sel, mux_out);
	comparator c(count, mux_out, eq);
	datacounter dc(clk1_25, resetdc, of_dc);
	
	parameter S0 = 3'b000, S1 = 3'b001, S2 = 3'b010, S3 = 3'b011,
				 S4 = 3'b100, S5 = 3'b101, S6 = 3'b110, S7 = 3'b111;
	
	reg [2:0] present_state = S0, next_state;
	
	//--------CONTROL PATH--------//
	always@(posedge clk, negedge reset)
		begin
			if(reset == 0) 
				present_state <= S0;
			else 
				present_state <= next_state;
		end
	
	//Next State Logic
	always@(*)
		begin
			case(present_state)
				S0: begin
						if(reset == 0) next_state <= S0;
						else next_state <= S1;
					 end

				S1: begin
						if(rx == 1) next_state <= S1;
						else next_state <= S2;
					 end

				S2: begin
						if(eq == 0) next_state <= S2;
						else next_state <= S3;
					 end

				S3: begin
						if(rx == 0) next_state <= S4;
						else next_state <= S0;
					 end

				S4: begin
						if(eq == 0) next_state <= S4;
						else next_state <= S5;
					 end

				S5: begin
						if(of_dc == 0) next_state <= S4;
						else next_state <= S6;
					 end

				S6: begin
						if(rx == 1)
							next_state <= S0;
					 end
			endcase
		end
		
	always@(*)
		begin
			if(present_state == S5)
				if(of_dc == 0)
					rxdata = {rx,rxdata[7:1]};
			else
				rxdata = rxdata;
		end
		
	//Output Logic
	always@(present_state,rxdata)
		begin
			case(present_state)
				S0: begin 
						resetbg = 0; mux_sel = 1'bz; resetdc = 0;
						ram_addr = 3'bzzz; ram_write = 0; ram_data_in = 4'bzzzz;
					 end
				S1: begin 
						resetbg = 0; mux_sel = 1'bz; resetdc = 0;
						ram_addr = 3'bzzz; ram_write = 0; ram_data_in = 4'bzzzz; 
					 end
				S2: begin 
						resetbg = 1; mux_sel = 1'b0; resetdc = 0; 
						ram_addr = 3'bzzz; ram_write = 0; ram_data_in = 4'bzzzz; 
					 end
				S3: begin 
						resetbg = 0; mux_sel = 1'b1; resetdc = 0; 
						ram_addr = 3'bzzz; ram_write = 0; ram_data_in = 4'bzzzz; 
					 end
				S4: begin 
						resetbg = 1; mux_sel = 1'b1; resetdc = 1; 
						ram_addr = 3'bzzz; ram_write = 0; ram_data_in = 4'bzzzz; 
					 end
				S5: begin 
						resetbg = 0; mux_sel = 1'b1; resetdc = 1; 
						ram_addr = 3'bzzz; ram_write = 0; ram_data_in = 4'bzzzz; 
					 end
				S6: begin 
						resetbg = 0; mux_sel = 1'bz; resetdc = 0; 
						ram_addr = {rxdata[7],rxdata[5],rxdata[4]}; ram_write = 1; ram_data_in = rxdata; 
					 end
			endcase
		end
endmodule

module clk_divider(clk, divided_clk10, divided_clk1_25);
	input clk;
	output reg divided_clk10 = 0;
	output divided_clk1_25;
	reg [9:0]count = 0;
	reg [2:0]count2 = 0;
	
	always@(posedge clk)
		begin
			if(count == 499)
				begin
					divided_clk10 <= ~divided_clk10;
					count <= count + 1;
				end
			else if(count == 999)
				begin
					divided_clk10 <= ~divided_clk10;
					count		  <= 0;
				end
			else
				count <= count + 1;
		end
	always@(posedge divided_clk10)
		begin
			count2 <= count2 + 1;
		end
		
	assign divided_clk1_25 = count2[2];
endmodule

module baudrate(resetb,clk10khz,count);
	input resetb;							//activelow
	input clk10khz;								
	output reg [3:0]count = 0;
	
	always@(posedge clk10khz,negedge resetb)
		begin
			if(resetb == 0)
				count <= 0;
			else 
				count <= count + 1;
		end
endmodule 

module comparator(in1, in2, eq);
	input [3:0] in1;
	input [3:0] in2;
	output eq;
	
	assign eq = (in1 == in2) ? 1 : 0;
endmodule 

module mux(in_4, in_8, sel, out);		//input 0 = 4, input 1 = 8
	input [3:0]in_4;
	input [3:0]in_8;
	input sel;
	output [3:0] out;
	
	assign out = sel ? in_8 : in_4;
endmodule 

module datacounter(clk1_25,resetdc,of_dc);
	input clk1_25;
	input resetdc; 
	output reg of_dc = 0;
	reg [3:0]count = 0;
	
	always@(posedge clk1_25, negedge resetdc)
		begin
			if(resetdc == 0)
				begin
					count <= 0;
					of_dc <= 0;
				end
			else if(count == 8)
				of_dc <= 1;
			else
				begin
					count <= count + 1;
					of_dc <= 0;
				end
		end
endmodule 

module ram(addr, write, data_in, zero, one, two, three, four, five, six, seven);			//RAM with 8 locations, each location is 4 bit wide
	input [2:0]addr;
	input write;
	input [3:0] data_in;
	output [3:0] zero, one, two, three, four, five, six, seven;
	reg [3:0]memory[7:0];
	integer i;
	
	initial
		begin
			for( i=0; i<=7; i=i+1 ) begin
				memory[i] = 4'b0000; end
		end
	
	assign  zero  = memory[0];
	assign  one   = memory[1];	
	assign  two   = memory[2];
	assign  three = memory[3];	
	assign  four  = memory[4];
	assign  five  = memory[5];
	assign  six   = memory[6];
	assign  seven = memory[7];
	
	always@(*)
		begin
			if(write)
				begin
					memory[addr] = data_in;
				end
		end 
endmodule 