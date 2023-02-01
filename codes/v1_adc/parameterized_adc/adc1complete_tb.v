`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:22:30 05/02/2021
// Design Name:   adc
// Module Name:   F:/CEDT projects/color_mixer_fpga/codes/v1_adc/parameterized_adc/adc1complete_tb.v
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

module adc1complete_tb;

	// Inputs
	reg compared_value;
	reg reset;
	reg clk;

	// Outputs
	wire pwm;
	wire discharge;

	// Instantiate the Unit Under Test (UUT)
	adc uut (
		.compared_value(compared_value), 
		.reset(reset), 
		.clk(clk), 
		.pwm(pwm), 
		.discharge(discharge)
	);

	always #50 clk = ~clk;
	
	initial begin
		// Initialize Inputs
		compared_value = 0;
		reset = 0;
		clk = 0;

		// Wait 100 ns for global reset to finish
		#100;
		
		//#50000 compared_value = 1;
		
		//#200 compared_value = 0;
		// Add stimulus here

	end
      
endmodule

