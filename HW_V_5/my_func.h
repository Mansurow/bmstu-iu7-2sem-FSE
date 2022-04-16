/**
 * \file my_func.h
 * \brief Модуль с функциями
 */
#ifndef _MY_FUNC_H_
#define _MY_FUNC_H_
#include <stdio.h>
#include <stdlib.h>
/**
 * \def FILE_OPEN_ERR
 * \brief Ошибка открытия файла
 */
#define FILE_OPEN_ERR 1
/**
 * \def ARR_OVERFLOW
 * \brief Ошибка переполнения массива
 */
#define ARR_OVERFLOW 2
/**
 * \def INVALID_INPUT
 * \brief Ошибка некорректного ввода
 */
#define INVALID_INPUT 3
/**
 * \def EMPTY_FILE
 * \brief Ошибка пустого файла
 */
#define EMPTY_FILE 4

/**
 * \def ARR_LEN_MAX
 * \brief Максимальный размер массива
 */
#define ARR_LEN_MAX 100
/**
 * \def SIZE_OF_NAME_FILE
 * \brief Максимальный размер имени файла
 */
#define SIZE_OF_NAME_FILE 50

int read_arr_from_file(FILE *f, int *arr, size_t *size);
int write_arr_to_file(FILE *f, int *arr, size_t size);
void odd_to_right(int *arr, size_t size);
void bubble_sort(int *arr, size_t size);
#endif