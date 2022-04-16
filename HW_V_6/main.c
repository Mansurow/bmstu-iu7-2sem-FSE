/**
 * \file main.c
 * \brief Документация к домашней работе по ОПИ -DOXYGEN-
 *
 * На вход в программу поступует имя файла.Файл содержит только целые числа и в файле не содержатся больше 100 чисел.
 * Находит сумму цифр каждого числа и если она четная то число перводит в двоичный код, при этом первый бит отвечает
 * за знак числа; если же нечетная сумма цифр числа то число преобразуется в обратном порядке следования.
 * Результат программы выводится в консоль.Каждое число через пробел.
 * \authors Мансуров Владислав ИУ7-26Б
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_tests.h"

/**
 * \def MAX_NUMBERS
 * \brief Максимальное значение для количетва чисел в файле
 */
#define MAX_NUMBERS 100 
/**
 * \def SIZE_OF_NAME_FILE
 * \brief Максимальное значение для строки в которой лежит путь и название файла
 */
#define SIZE_OF_NAME_FILE 50
/**
 * \def ERR_INVALID_PARAM
 * \brief Ошибка передачи в функцию неверных параметров
 */
#define ERR_INVALID_PARAM -1
/**
 * \def FULL_MAX
 * \brief Ошибка переполнения файла числами
 */
#define FULL_MAX          -2
/**
 * \def NOT_FOUND_FILE 
 * \brief Ошибка несуществующий файл
 */
#define NOT_FOUND_FILE    -3
/**
 * \def FILE_IS_EMPTY
 * \brief Ошибка передан пустой файл
 */
#define FILE_IS_EMPTY     -4
/**
 * \def IN_FILE_SYMBOLS 
 * \brief Ошибка передан некоррестный файл с символами и буквами
 */
#define IN_FILE_SYMBOLS   -5
/**
 * \def IN_FILE_DOUBLE 
 * \brief Ошибка передан некоректный файл с вещественными числами
 */
#define IN_FILE_DOUBLE    -6
/**
 * \fn int read_array(FILE *my_file,int a[MAX_NUMBERS], int *n);
 * \brief Функция читает из файл числа и записывает в массив 
 *     
 * \param [out] f указатель на файл, то есть пути к нему
 * \param [out] a указатель на массив куда записываются числа
 * \param [out] n указатель на размерность массива
 * \return Возвращает код ошибки если все прошло успешно то 0, если нет то числа неравные 0
 */
int read_array(FILE *f,int a[MAX_NUMBERS], int *n);

/**
 * \fn int sum_of_figure(int number)
 * \brief Функция считает сумму цифр числа
 *
 * \param [in] number число, цифры которые нужно сложить
 * \return sum - сумму цифр числа
 */
int sum_of_figure(int number);

/**
 * \fn int check_sum(int number);
 * \brief Функция проверяет четность числа
 *
 * \param [in] number число, которое нужно проверить на четность
 * \return response - признак True или False
 */
int check_sum(int number);

/**
 * \fn int converting_to_binarycod(int number, int b[MAX_NUMBERS], int *nb);
 * \brief Функция преобразует число в двоичный код
 *
 * \param [in] number число, которое нужно преобразовать в двоичный кода
 * \param [out] b указатель на массив
 * \param [out] nb указатель на размерность
 * \return Возвращает код ошибки 0 или -1
 */
int converting_to_binarycod(int number, int b[MAX_NUMBERS], int *nb);

/**
 * \fn int reverse_number(int number, int *reverse)
 * \brief Функция преобразует число в обратный порядок следования
 *
 * \param [in] number число, которое нужно поставить в обратном порядке следования
 * \param [out] reverse указатель на результат функции
 * \return Возвращает код ошибки 0 или -1
 */
int reverse_number (int number, int *reverse);

/**
 * \fn void print_error(int rc)
 * \brief Функция вывода сообщения взависимости от кода ошибки
 *
 * \param [in] rc код ошибки
 */
void print_error(int rc);

/**
 * \fn int main(void)
 * \brief Главная функция кода
 *
 * \return Возвращает код ошибки если все прошло успешно то 0, если нет то числа неравные 0
 */
int main(void)
{
	FILE *my_file;
    char filename[SIZE_OF_NAME_FILE];
    int arr[MAX_NUMBERS];
	int n = 0, nb = 0;
	int sum, reverse, rc = EXIT_SUCCESS;
	int binarycod[MAX_NUMBERS];
    
    setbuf(stdout, NULL);
    printf("Введите название файла: ");
    scanf("%s", filename);
	my_file = fopen(filename, "r");
	
	if (my_file != NULL)
	{
		rc = read_array(my_file, arr, &n);
	}else
		rc = NOT_FOUND_FILE;
		
	
	if (rc != EXIT_SUCCESS)
	{
		print_error(rc);
	} else
	{
		printf("\nПрочитанные числа, переведены в двоичный код или перевернуты:\n");
		for (int i = 0; i < n; i++)
		{
			sum = sum_of_figure(arr[i]);
			if (check_sum(sum))
			{
				rc = converting_to_binarycod(arr[i], binarycod, &nb);
                if (rc != EXIT_SUCCESS)
                {
                    print_error(rc);
                    return rc;
                }    
                    
				for (int i = 0; i < nb; i++)
				{
					if (i == 0)
					{
						printf(" %d", binarycod[i]);
					} else
					{
						printf("%d", binarycod[i]);
					}
				}
			} else 
			{
				rc = reverse_number(arr[i], &reverse);
				printf(" %d", reverse);
			}
		}
	}
	fclose(my_file);
    
	printf("\n\nUSER UNIT TEST:");
	tests_read_array();
	tests_sum_of_figure();
	tests_check_sum();
	tests_converting_to_binarycod();
	tests_reverse_number();
	return rc;
}

void print_error(int rc)
{
	if (rc == NOT_FOUND_FILE)
		printf("\nФайл не найден.");
	if (rc == FILE_IS_EMPTY)
		printf("\nПустой файл.");
	if (rc == FULL_MAX)
		printf("\nВ файле больше 100.");
	if (rc == IN_FILE_DOUBLE)
		printf("\nФайл записан некорректно. Содержит вещественные числа.");
	if (rc == IN_FILE_SYMBOLS)
		printf("\nФайл записан некорректно. Содержит буквы и символы.");
	if (rc == ERR_INVALID_PARAM)
		printf("\nВ функцию переданы некоректные параметры.");
}

int read_array(FILE *f, int a[MAX_NUMBERS], int *n)
{
	int num, error = EXIT_SUCCESS; 
	char sym;
	if (f == NULL || a == NULL || n == NULL || *n < 0)
	{
		error = ERR_INVALID_PARAM;
	} 
    else
	{
		int result_1 = fscanf(f, "%d", &num);
		int result_2 = fscanf(f, "%c", &sym);
		
		while (result_1 == 1 || result_2 == 1 || fgetc(f) != EOF)
		{
			if (sym == '.' || sym == ',')
			{
				error = IN_FILE_DOUBLE;
				(*n)++;
				break;
			}
			
			if ((sym != ' ' && sym != '\n' && (result_1 + result_2 == 1)) || (result_1 != 1 && result_2 == 0))
			{
				error = IN_FILE_SYMBOLS;
				(*n)++;
				break;
			}

			a[*n] = num;
			(*n)++;
			
			if (*n > MAX_NUMBERS)
			{
				error = FULL_MAX;
				break;
			}
			
			result_1 = fscanf(f, "%d", &num);
			result_2 = fscanf(f, "%c", &sym);
		}
		if (*n == 0)
			error = FILE_IS_EMPTY;
	}
	return error;
}

int sum_of_figure(int number)
{
	int sum = 0;
	number = abs(number);
	
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	
	return sum;
}

int check_sum(int number)
{
    int response;
    if (number % 2 == 0)
    {
        response = 1;
    } else
        response = 0;
    return response;
}

int converting_to_binarycod(int number, int b[MAX_NUMBERS], int *nb)
{
	if (b == NULL || nb == NULL || *nb < 0)
        return ERR_INVALID_PARAM;
    int sign;
	if (number < 0)
	{
		sign = 1;
	} else
	{
		sign = 0;
	}
	while (abs(number) > 0)
	{
		if (number % 2 == 0)
		{
			b[*nb] = 0;
		}else
		{
			b[*nb] = 1;
		}
		number /= 2;
		(*nb)++;
	}
	b[(*nb)++] = sign;
	int buff, i = *nb - 1;	
	while (i >= *nb / 2 && *nb != 1)
	{
		buff = b[*nb - 1 - i];
		b[*nb - 1 - i] = b[i];
		b[i] = buff;
		i--;
	}
    return EXIT_SUCCESS;
}

int reverse_number (int number, int *reverse)
{
    int error = EXIT_SUCCESS;
    if (reverse == NULL)
    {
       error = ERR_INVALID_PARAM;
    }
    else
    {
        *reverse = 0;
        while (abs(number) > 0)
        {
            *reverse = (*reverse) * 10 + number % 10;
            number /= 10;
        }
    }
    return error;
}
