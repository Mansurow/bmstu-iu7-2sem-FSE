@echo off
main.exe < name_file/pos_%1.txt > pos_out.txt
fc pos_out.txt pos_0%1_out.txt
pause