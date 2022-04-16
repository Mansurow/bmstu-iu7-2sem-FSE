/**
 * \file main.c
 * \brief Документация к РК-02
 *
 * Дан файл содержащий строки текста. Слова разделены одним или 
 * несколькими пробелом. 
 * Подсчитать среднюю длину слова в каждой строке текстового файла. 
 * Результат решения задачи сохранить в новый файл.
 * \authors Мансуров Владислав ИУ7-26Б
 */
#include <stdio.h>
#include <string.h>
/**
 * \def MAX_STR
 * \brief Максимальное значение для строки
 */
#define MAX_STR 257

#define ERR -1
#define OK 0
/**
 * \fn int findavgstr(char (*words)[MAX_STR], int n, int *avg)
 * \brief Функция преобразует число в обратный порядок следования
 *
 * \param [in] words массив слов (указатель)
 * \param [in] n размер массива
 * \param [out] avg указатель на мреднее значение длины слов
 * \return Возвращает код ошибки 0 или -1
 */
int findavgstr(char (*words)[MAX_STR], int n, int *avg)
{
    if (words == NULL || n <= 0 || avg == NULL || *avg < 0)
        return ERR;
    int i = 0;
    int len = 0;
    while (i < n)
    {
        len = strlen(words[i]);
        (*avg) += len;
        i++;
    }
    (*avg) /= n;
    return OK;
}

void test(void)
{
    int pos_r = 0, neg_r = 0, pos_test = 2, neg_test = 1;
    {
        if (findavgstr(NULL, 0, NULL) != ERR)
            neg_r++;
    }
    {
        char words[5][MAX_STR] = {"Hi", "Gleb!", "Gleb!", "Gleberer"};
        int avg = 0;
        if (findavgstr(words, 5, &avg) != OK || avg != 4)
            pos_r++;
    }
    {
        char words[1][MAX_STR] = {"Hi"};
        int avg = 0;
        if (findavgstr(words, 1, &avg) != OK || avg != 2)
            pos_r++;
    }
    printf("\n===%s:\n -Негативные тесты: %d of %d - %s", __func__,neg_test - neg_r, neg_test, neg_r ? "FAILED" : "SUCCESS");
	printf("\n -Позитивные тесты: %d of %d - %s", pos_test - pos_r, pos_test, pos_r ? "FAILED" : "SUCCESS");
}
/**
 * \fn int main(void)
 * \brief Главная функция кода
 *
 * \return Возвращает код ошибки если все прошло успешно то 0, если нет то числа неравные 0
 */
int main()
{
    char words[2][MAX_STR] = {"Hi", "Gleb!"};
    int avg = 0;
    int n = 2;
    if (findavgstr(words, n, &avg) != OK)
        return ERR;
    printf("\nСреднее значение слова в строке: %d\n", avg);
    test();
    return OK;
}


