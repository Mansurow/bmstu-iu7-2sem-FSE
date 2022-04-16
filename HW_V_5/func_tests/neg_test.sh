#!/bin/bash
./app.exe < "file_names/neg_$1.txt" > "output_file.txt"
rc=$?
python main.py "output_file.txt"
python main.py "neg_$1_out.txt"

if fc "extract_output_file.txt" "extract_neg_$1_out.txt" && [ $rc != 0 ]
then
echo -e NEG_"$1": "\e[32mPASSED\e[0m"
else
echo -e NEG_"$1": "\e[31mFAILED\e[0m"
fi
rm "extract_output_file.txt" "extract_neg_$1_out.txt"