`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:40:49 05/01/2021 
// Design Name: 
// Module Name:    adc 
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
module adc4pwm(compared_value, reset, clk, pwm, discharge);
	input [3:0] compared_value;		//compared[3:0] = 3--red, 2--g, 1--b, 0--i
	input reset, clk;
	output [3:0] pwm;
	output [3:0] discharge;
	
	wire clk256,clk64;
	clk_divider clk1_2(clk,clk256,clk64);
	adc #(.N(8)) red(compared_value[3], reset, clk, clk256, pwm[3], discharge[3]);
	adc #(.N(8)) green(compared_value[2], reset, clk, clk256, pwm[2], discharge[2]);
	adc #(.N(8)) blue(compared_value[1], reset, clk, clk256, pwm[1], discharge[1]);
	adc #(.N(6)) intensity(compared_value[0], reset, clk, clk64, pwm[0], discharge[0]);
	
endmodule

//Complete Single ADC with PWM
module adc #(parameter N = 8)(compared_value, reset, clk, clkslow, pwm, discharge);
//	parameter N = 8;
	input compared_value, reset, clk, clkslow;
	output pwm;
	output reg discharge;
	
	//Control signals
	reg latch_en, delay_en, reset_counter;
	wire delay_completed, of_r;
	parameter S0 = 2'b00, S1 = 2'b01, S2 = 2'b10;
	reg[1:0] present_state = S0, next_state;
	
	//type enum {S0, S1, S2} state;
	//state present_state, next_state;
	
	//Signals for connection of data path elements
	wire [N-1:0] adc_count,latched_value;
	
	delay10us DelayForDischarge(clk, delay_en, delay_completed);
	adc_counter #(.N(N)) C1(clkslow, reset_counter, compared_value, adc_count, of_r);
	latch #(.N(N)) LR(adc_count, latch_en, latched_value);
	pwm #(.N(N)) p(clk, latched_value, pwm);
	
	//---------------Control Path-------------------//

	always@(posedge clk, negedge reset)
		begin
			if(!reset)	present_state <= S0;
			else			present_state <= next_state;
		end

	// Next State Logic
	always@(*)
		begin
			case(present_state)
				S0: begin
						if(delay_completed) next_state <= S1;
						else next_state <= S0;
					 end
				S1: begin
						if(compared_value || of_r) next_state <= S2;
						else next_state <= S1;
					 end
				S2: begin
						next_state <= S0;
					 end
				default: next_state <= S0;
			endcase 
		end
		
	// Output Logic
	always@(present_state)
		begin
			case(present_state)
				S0 : begin discharge = 1; latch_en = 0; delay_en = 1; reset_counter = 0; end
				S1 : begin discharge = 0; latch_en = 0; delay_en = 0; reset_counter = 1; end
				S2 : begin discharge = 0; latch_en = 1; delay_en = 0; reset_counter = 1; end
			endcase
		end

endmodule

module delay10us(clk,en,of);		// delay block for discharging capacitor
	input clk,en;							// a mod-120 counter
	output reg of=0;
	reg [6:0] count=0;
	
	always@(posedge clk)
		begin
			if(en)
				begin
					if(count == 119)
						begin 
							of 	<= 1;
							count <= 0;
						end
					else
						begin
							of    <= 0;
							count <= count+1;
						end
				end
		end
endmodule 

module adc_counter #(parameter N = 8)(clk, reset, compStatus, count, of);		//counter for adc -- 1.33Mhz clk, 8 bit by default
//	parameter N = 8;
	input clk, compStatus, reset;
	output reg [N-1:0] count = 0;
	output reg of;
	
	always@(posedge clk, negedge reset)
		begin
			if(!reset) 
				begin 
					count <= 0;
					of 	<= 0;
				end
			else if(!compStatus)
				begin 
					if(count == ((2**N)-1))
							of <= 1;
					else
						begin
							of <= 0;
							count <= count+1;
						end
				end
			else
				count<=count;
		end
endmodule 

module latch #(parameter N = 8)(data, en, out);		//latch for storing counter value for pwm
//	parameter N = 8;					//8-bit by default
	input [N-1:0] data;
	input en;
	output reg [N-1:0] out;
	
	always@(posedge en)
		begin
			out <= data;
		end
endmodule 

module clk_divider(clk,clk_out1,clk_out2);
	parameter WIDTH = 5;
	parameter N = 18;
 
	input clk;
	output clk_out1,clk_out2;
	reg [WIDTH-1:0] pos_count = 0, neg_count = 0;
	reg [1:0]count = 0;
 
	always @(posedge clk)
		begin
			if (pos_count == N-1) pos_count <= 0;
			else pos_count<= pos_count +1;
		end
		
	always @(negedge clk)
		begin
			if (neg_count == N-1) neg_count <= 0;
			else neg_count<= neg_count +1;
		end
	
	assign clk_out1 = ((pos_count > (N>>1)) | (neg_count > (N>>1))); 
	
	always @(posedge clk_out1)
		begin
			count<=count+1;
		end
		
	assign clk_out2 = count[1];

endmodule

module pwm #(parameter N = 8)(clk, dutycycle, pwm_out);
//	parameter N = 8;
	input clk;
	input [N-1:0] dutycycle;
	output pwm_out;
	reg [N-1:0] count = 0;
	
	always@(posedge clk)
		begin 
			count <= count + 1;
		end
	assign pwm_out = count < dutycycle ? 1:0;
endmodule 