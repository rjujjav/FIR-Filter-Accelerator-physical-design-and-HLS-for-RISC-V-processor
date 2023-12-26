# written for flow package DesignCompiler 
set sdc_version 1.7 

set_operating_conditions typical
set_wire_load_mode enclosed
set_load 11.234 [all_outputs]
## driver/slew constraints on inputs
set data_inputs [list axi_read_ar_val {axi_read_ar_msg[*]} axi_read_r_rdy axi_write_aw_val {axi_write_aw_msg[*]} axi_write_w_val {axi_write_w_msg[*]} axi_write_b_rdy]
set_driving_cell -no_design_rule -library NangateOpenCellLibrary -lib_cell DFFR_X1 -pin Q $data_inputs
set_units -time ns
# time_factor: 1.0

create_clock -name clk -period 2.0 -waveform { 0.0 1.0 } [get_ports {clk}]
set_clock_uncertainty 0.0 [get_clocks {clk}]

create_clock -name virtual_io_clk -period 2.0
## IO TIMING CONSTRAINTS
set_input_delay 0.0 -clock virtual_io_clk [get_ports {axi_read_ar_val}]
set_output_delay 0.0 -clock virtual_io_clk [get_ports {axi_read_ar_rdy}]
set_input_delay 0.0 -clock virtual_io_clk [get_ports {axi_read_ar_msg[*]}]
set_output_delay 0.0 -clock virtual_io_clk [get_ports {axi_read_r_val}]
set_input_delay 0.0 -clock virtual_io_clk [get_ports {axi_read_r_rdy}]
set_output_delay 0.0 -clock virtual_io_clk [get_ports {axi_read_r_msg[*]}]
set_input_delay 0.0 -clock virtual_io_clk [get_ports {axi_write_aw_val}]
set_output_delay 0.0 -clock virtual_io_clk [get_ports {axi_write_aw_rdy}]
set_input_delay 0.0 -clock virtual_io_clk [get_ports {axi_write_aw_msg[*]}]
set_input_delay 0.0 -clock virtual_io_clk [get_ports {axi_write_w_val}]
set_output_delay 0.0 -clock virtual_io_clk [get_ports {axi_write_w_rdy}]
set_input_delay 0.0 -clock virtual_io_clk [get_ports {axi_write_w_msg[*]}]
set_output_delay 0.0 -clock virtual_io_clk [get_ports {axi_write_b_val}]
set_input_delay 0.0 -clock virtual_io_clk [get_ports {axi_write_b_rdy}]
set_output_delay 0.0 -clock virtual_io_clk [get_ports {axi_write_b_msg[*]}]

