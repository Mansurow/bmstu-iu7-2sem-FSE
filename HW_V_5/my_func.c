/**
 * \file my_func.с
 * \brief Файл с функциями
 */
#include "my_func.h"
/**
 * \fn int read_arr_from_file(FILE *f, int *arr, size_t *size)
 * \brief Функция считывания данных(целых чисел) из файла в массив
 *
 * \param [in] f файловая перменная (указатель)
 * \param [out] arr массив целых чисел (указатель)
 * \param [out] size размер массива (указатель)
 * \return Возвращает код ошибки 0 или не нулевой
 */
int read_arr_from_file(FILE *f, int *arr, size_t *size)
{
	//assert(f == NULL);
	if (f == NULL)
        return FILE_OPEN_ERR;
	//assert(*size > 0);
    int rc = 1;
    while (rc == 1)
    {
        if (*size > ARR_LEN_MAX)
            return ARR_OVERFLOW;
        rc = fscanf(f, "%d", &arr[*size]);
        if (rc != 1 && rc != EOF)
            return INVALID_INPUT;
        if (rc == EOF)
            break;
        (*size)++;
    }
    fclose(f);
    if (*size == 0)
        return EMPTY_FILE;
    return EXIT_SUCCESS;
}
/**
 * \fn int write_arr_to_file(FILE *f, int *arr, size_t size)
 * \brief Функция записи данных(целых чисел) в файл
 *
 * \param [in, out] f файловая перменная (указатель)
 * \param [in] arr массив целых чисел (указатель)
 * \param [in] size размер массива
 * \return Возвращает код ошибки 0
 */
int write_arr_to_file(FILE *f, int *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        fprintf(f, "%d ", arr[i]);
    return EXIT_SUCCESS;
}
/**
 * \fn void odd_to_right(int *arr, size_t size)
 * \brief Функция сдвигает нечетные числа отсортированного массива в конец массива(считывание начиная с конца)
 *
 * \param [in, out] arr массив целых чисел (указатель)
 * \param [in] size размер массива
 */
void odd_to_right(int *arr, size_t size)
{
    int buf;
    for (int i = size - 1; i > -1; i--)
        if (abs(arr[i]) % 2 == 1)
        {
            buf = arr[i];
            for (size_t j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
                if (j == size - 2)
                    arr[j + 1] = buf;
            }
        }
}
/**
 * \fn void bubble_sort(int *arr, size_t size)
 * \brief Функция сортировка методом пузырька
 *
 * \param [in, out] arr массив целых чисел (указатель)
 * \param [in] size размер массива
 */
void bubble_sort(int *arr, size_t size)
{
    int buf;
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = 0; j < size - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                buf = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = buf;
            }
}