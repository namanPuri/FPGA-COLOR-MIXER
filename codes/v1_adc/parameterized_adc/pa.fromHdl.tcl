
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name parameterized_adc -dir "F:/CEDT projects/color_mixer_fpga/codes/v1_adc/parameterized_adc/planAhead_run_2" -part xc3s50antqg144-4
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "adc4pwm.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {adc.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top adc4pwm $srcset
add_files [list {adc4pwm.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s50antqg144-4
