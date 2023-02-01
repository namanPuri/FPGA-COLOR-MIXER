`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:32:52 05/01/2021
// Design Name:   adc
// Module Name:   F:/CEDT projects/color_mixer_fpga/codes/v1_adc/parameterized_adc/datapath_simulation.v
// Project Name:  parameterized_adc
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: adc
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module datapath_simulation;

	// Inputs
	reg clk=0;
	reg counter_en;
	reg latch_en;
	reg delay_en;
	reg reset_counter;
	reg compared_value=1;

	// Outputs
	wire delay_completed;
	wire of_r;
	wire [7:0] pwm_r;

	// Instantiate the Unit Under Test (UUT)
	adc uut (
		.clk(clk), 
		.counter_en(counter_en), 
		.latch_en(latch_en), 
		.delay_en(delay_en), 
		.reset_counter(reset_counter), 
		.compared_value(compared_value), 
		.delay_completed(delay_completed), 
		.of_r(of_r), 
		.pwm_r(pwm_r)
	);

	always #50 clk = ~clk;
/*	
	initial begin
		// Initialize Inputs
		clk = 0;
		counter_en = 0;
		latch_en = 0;
		delay_en = 0;
		reset_counter = 0;
		compared_value = 0;

		// Wait 100 ns for global reset to finish
		//s1				
		// Add stimulus here
		
	//	#10000 $finish;
	end
*/
	initial begin
		
		while(delay_completed == 0)
			counter_en = 0; latch_en = 0; delay_en = 1; reset_counter = 1;
		
		//s2
		while(compared_value == 1)
			counter_en = 1; latch_en = 0; delay_en = 0; reset_counter = 0;

		//s3
		counter_en = 0; latch_en = 1; delay_en = 0; reset_counter = 0;

	end
	
	initial begin
		#250 compared_value = 0;
	end
endmodule
