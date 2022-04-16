@echo off
main.exe < name_file/neg_%1.txt > neg_out.txt
fc neg_out.txt neg_0%1_out.txt
pause