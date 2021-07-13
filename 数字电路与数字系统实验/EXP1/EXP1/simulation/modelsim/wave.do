onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand /EXP1_vlg_tst/X0
add wave -noupdate -expand /EXP1_vlg_tst/X1
add wave -noupdate -expand /EXP1_vlg_tst/X2
add wave -noupdate -expand /EXP1_vlg_tst/X3
add wave -noupdate -expand /EXP1_vlg_tst/Y
add wave -noupdate -expand /EXP1_vlg_tst/F
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ps} 0}
quietly wave cursor active 0
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ps} {1680 ns}
