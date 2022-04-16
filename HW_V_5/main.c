/**
 * \file main.c
 * \brief Документация к домашней работе по ОПИ
 *
 * В сроках текстового файла содержатся целые числа. 
 * Преобразовать строки файла следующим образом: вначале должны идти четные 
 * чилсла, упорядоченные по возврастанию, а затем нечетные, упорядоченные по 
 * убыванию.
 * \authors Мырзабеков Рамис ИУ7-24Б
 */
#include "my_func.h"
/**
 * \fn int main(void)
 * \brief Главная функция кода
 *
 * \return Возвращает код ошибки если все прошло успешно то 0, если нет то числа неравные 0
 */
int main(void)
{
    FILE *f = NULL;
	char filename[SIZE_OF_NAME_FILE];
    int arr[ARR_LEN_MAX];
    size_t size = 0;
    int rc;
	
	setbuf(stdout, NULL);
    printf("Enter the file name: ");
    scanf("%s", filename);
    f = fopen(filename, "r");
    rc = read_arr_from_file(f, arr, &size);
    fclose(f);
    if (rc == EXIT_SUCCESS)
    {
        bubble_sort(arr, size);
        odd_to_right(arr, size);
        f = fopen(filename, "w");
        if (f == NULL)
        {
            printf("File open error (write)");
            return FILE_OPEN_ERR;
        }
        rc = write_arr_to_file(f, arr, size);
        fclose(f);
    }
	else
	{
		if (rc == FILE_OPEN_ERR)
			printf("File open error (read)");
		if (rc == ARR_OVERFLOW)
			printf("Limit exceeded (more than 100 numbers in file)");
		if (rc == INVALID_INPUT)
			printf("Invalid input data");
		if (rc == EMPTY_FILE)
			printf("File is empty");
	}
	
    return rc;
}
