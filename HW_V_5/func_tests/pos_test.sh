#!/bin/bash
./app.exe < "file_names/pos_$1.txt" > "output_file_unnes.txt"
rc=$?
python main.py "output_file.txt"
python main.py "pos_$1_out.txt"

if fc "extract_output_file.txt" "extract_pos_$1_out.txt" && [ $rc == 0 ]
then
echo -e POS_"$1": "\e[32mPASSED\e[0m"
else
echo -e POS_"$1": "\e[31mFAILED\e[0m"
fi
rm "extract_output_file.txt" "extract_pos_$1_out.txt" "output_file_unnes.txt"
