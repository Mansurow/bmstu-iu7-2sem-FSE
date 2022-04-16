#!/bin/bash
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion my_func.c unit_tests.c -o unit.exe && ./unit.exe
rm -rf unit.exe