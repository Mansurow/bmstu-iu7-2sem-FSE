#!/bin/sh
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion my_func.c main.c -o app.exe