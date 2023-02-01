`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   00:50:58 05/11/2021
// Design Name:   uart_rx_code
// Module Name:   F:/CEDT projects/color_mixer_fpga/codes/uart_rx/uart_rx_tb.v
// Project Name:  uart_rx
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: uart_rx_code
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module uart_rx_tb;

	// Inputs
	reg reset;
	reg rx;
	reg clk;

	// Outputs
	wire [7:0] red, green, blue, intensity;

	// Instantiate the Unit Under Test (UUT)
	uart_rx_code uut (
		.reset(reset), 
		.rx(rx), 
		.clk(clk), 
		.red(red),
		.green(green),
		.blue(blue),
		.intensity(intensity)
	);

	initial begin
		// Initialize Inputs
		reset = 1;
		rx = 1;
		clk = 0;

		// Wait 100 ns for global reset to finish
        
		// Add stimulus here
	end
	
	always #50 clk = ~clk;
	
	task transmit_uart;
		input [7:0]data;
		
		begin
		#200
					rx = 0;
		#833300 	rx = data[0];
		#833300	rx = data[1];
		#833300	rx = data[2];
		#833300	rx = data[3];
		#833300	rx = data[4];
		#833300	rx = data[5];
		#833300	rx = data[6];
		#833300	rx = data[7];
		#833300	rx = 1;
		#833300;
		end
	endtask 

	initial begin
	
		transmit_uart(8'b00001111);
		transmit_uart(8'b10001111);
		
		transmit_uart(8'b00011010);
		transmit_uart(8'b10011010);
		
		transmit_uart(8'b00101111);
		transmit_uart(8'b10101111);
		
		transmit_uart(8'b00110110);
		transmit_uart(8'b10110110);

	end
endmodule 