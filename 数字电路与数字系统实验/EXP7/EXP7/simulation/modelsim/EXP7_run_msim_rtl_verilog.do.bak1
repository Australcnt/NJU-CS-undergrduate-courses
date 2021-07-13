transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Digital_Experiment/EXP7 {C:/Digital_Experiment/EXP7/ram2port.v}
vlog -vlog01compat -work work +incdir+C:/Digital_Experiment/EXP7 {C:/Digital_Experiment/EXP7/EXP7.v}
vlog -vlog01compat -work work +incdir+C:/Digital_Experiment/EXP7 {C:/Digital_Experiment/EXP7/ram1.v}

vlog -vlog01compat -work work +incdir+C:/Digital_Experiment/EXP7/simulation/modelsim {C:/Digital_Experiment/EXP7/simulation/modelsim/EXP7.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cyclonev_ver -L cyclonev_hssi_ver -L cyclonev_pcie_hip_ver -L rtl_work -L work -voptargs="+acc"  EXP7_vlg_tst

add wave *
view structure
view signals
run -all
