
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name clock_divideBy3 -dir "F:/CEDT projects/color_mixer_fpga/references/clock_divideBy3/planAhead_run_2" -part xc3s50antqg144-4
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "clkBy3.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {clkBy3.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top clkBy3 $srcset
add_files [list {clkBy3.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s50antqg144-4
