/**
 * \file main.h
 * \Файл для обращения к функциям в main.c
 * \authors Мансуров Владислав ИУ7-26Б 
 */
#define _MAIN_H_

#define MAX_NUMBERS 100

#define ERR_INVALID_PARAM -1
#define FULL_MAX          -2
#define NOT_FOUND_FILE    -3
#define FILE_IS_EMPTY     -4
#define IN_FILE_SYMBOLS   -5
#define IN_FILE_DOUBLE    -6

int read_array(FILE *my_file,int a[MAX_NUMBERS], int *n);

int sum_of_figure(int number);

int check_sum(int number);

int converting_to_binarycod(int number, int b[MAX_NUMBERS], int *nb);

int reverse_number (int number, int *reverse);

void print_error(int rc);