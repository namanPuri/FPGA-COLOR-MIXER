
# PlanAhead Launch Script for Post-Synthesis pin planning, created by Project Navigator

create_project -name clock_divideBy3 -dir "F:/CEDT projects/color_mixer_fpga/references/clock_divideBy3/planAhead_run_5" -part xc3s50antqg144-4
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "F:/CEDT projects/color_mixer_fpga/references/clock_divideBy3/clkBy3.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {F:/CEDT projects/color_mixer_fpga/references/clock_divideBy3} }
set_param project.pinAheadLayout  yes
set_property target_constrs_file "clkBy3.ucf" [current_fileset -constrset]
add_files [list {clkBy3.ucf}] -fileset [get_property constrset [current_run]]
link_design
