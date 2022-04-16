#include <stdio.h>
#include <stdlib.h>
#include "unit_tests.h"
#include "main.h"

void tests_read_array(void)
{
	int neg_cnt = 0, pos_cnt = 0, test_neg = 7, test_pos = 2;
	//
	// Передача пустого файла или несуществующего файла
    //
	{
		int a[MAX_NUMBERS];
		int n = 0;
		
        if (read_array(fopen("unit_tests/neg_tests_1.txt", "r"), a, &n) != FILE_IS_EMPTY)
			neg_cnt++;
        
        if (read_array(NULL, NULL, NULL) != ERR_INVALID_PARAM)
           neg_cnt++;
        
		if (read_array(NULL, a, &n) != ERR_INVALID_PARAM)
            neg_cnt++;
    
		n = -10;
        if (read_array(fopen("unit_tests/pos_tests_1.txt", "r"), a, &n) != ERR_INVALID_PARAM)
            neg_cnt++;	
	}
	//
	// Передача некоректно записанных файлов
	//
	{
		int a[MAX_NUMBERS];
		int n = 0;
		
		if (read_array(fopen("unit_tests/neg_tests_2.txt", "r"), a, &n) != IN_FILE_SYMBOLS)
            neg_cnt++;
        n = 0;
		if (read_array(fopen("unit_tests/neg_tests_3.txt", "r"), a, &n) != IN_FILE_DOUBLE)
			neg_cnt++;
        n = 0;
		if (read_array(fopen("unit_tests/neg_tests_4.txt", "r"), a, &n) != FULL_MAX)
			neg_cnt++; 
	}
	//
	// Передача корректных данных
	//
	{
		int a[MAX_NUMBERS];
		int n = 0;
		
		if (read_array(fopen("unit_tests/pos_tests_1.txt", "r"), a, &n) != EXIT_SUCCESS && n > 0)
            pos_cnt++;
        n = 0;
		if (read_array(fopen("unit_tests/pos_tests_2.txt", "r"), a, &n) != EXIT_SUCCESS && n > 0)
			pos_cnt++;
	}
	
	printf("\n===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
	printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");
}

void tests_sum_of_figure(void)
{
	int pos_cnt = 0, test_pos = 5, neg_cnt = 0, test_neg = 0;
	//
	// Проверка корректности функции
	//
	{	
		if (sum_of_figure(123) != 6)
            pos_cnt++;
		if (sum_of_figure(456) != 15)
            pos_cnt++;
		if (sum_of_figure(890) != 17)
            pos_cnt++;
	}
	printf("\n===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
	printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");
}

void tests_check_sum(void)
{
	int pos_cnt = 0, test_pos = 5, neg_cnt = 0, test_neg = 0;
	//
	// Проверка корректности функции
	//
	{	
		if (check_sum(6) != 1)
            pos_cnt++;
		if (check_sum(-15) != 0)
            pos_cnt++;
		if (check_sum(-102) != 1)
            pos_cnt++;
		if (check_sum(89102) != 1)
            pos_cnt++;
	}
	printf("\n===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
	printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");
}

void tests_converting_to_binarycod(void)
{
	int pos_cnt = 0, test_pos = 5, neg_cnt = 0, test_neg = 4;
	//
	// Проверка корректности функции
	//
    {
        int b[MAX_NUMBERS];
        int n = 0, num = 121;
        if (converting_to_binarycod(num, NULL, NULL) != ERR_INVALID_PARAM)
            neg_cnt++;
        if (converting_to_binarycod(num, b, NULL) != ERR_INVALID_PARAM)
            neg_cnt++;
        if (converting_to_binarycod(num, NULL, &n) != ERR_INVALID_PARAM)
            neg_cnt++;
        n = -10;
        if (converting_to_binarycod(num, b, &n) != ERR_INVALID_PARAM)
            neg_cnt++;
    }
	{	
		int a[MAX_NUMBERS];
		long long unsigned cod ;		
		int n = 0;
        int rc;
        // 1 тест
		cod = 0;
		rc = converting_to_binarycod(121, a, &n);
		for (int i = 0; i < n; i++)
			cod = cod * 10 + a[i];
		if (cod != 1111001 || n != 8 || rc != EXIT_SUCCESS)
            pos_cnt++;
		// 2 тест
		cod = 0;
        n = 0;
		rc = converting_to_binarycod(5, a, &n);
		for (int i = 0; i < n; i++)
			cod = cod * 10 + a[i];
		if (cod != 101 || n != 4 || rc != EXIT_SUCCESS)
            pos_cnt++;
		// 3 тест
		cod = 0;
        n = 0;
		rc = converting_to_binarycod(-46, a, &n);
		for (int i = 0; i < n; i++)
			cod = cod * 10 + a[i];
		if (cod != 1101110 || n != 7 || rc != EXIT_SUCCESS)
            pos_cnt++;
        // 4 тест
		cod = 0;
        n = 0;
		rc = converting_to_binarycod(23256, a, &n);
		for (int i = 0; i < n; i++)
			cod = cod * 10 + a[i];
		if (cod != 101101011011000 || n != 16 || rc != EXIT_SUCCESS)
            pos_cnt++;
		// 5 тест
		cod = 0;
        n = 0;
		rc = converting_to_binarycod(-23256, a, &n);
		for (int i = 0; i < n; i++)
			cod = cod * 10 + a[i];
		if (cod != 1101101011011000 || n != 16 || rc != EXIT_SUCCESS)
            pos_cnt++;
	}
    
	printf("\n===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
	printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");
}

void tests_reverse_number(void)
{
	int pos_cnt = 0, test_pos = 5, neg_cnt = 0, test_neg = 1;
	//
	// Проверка корректности функции
	//
    {
        int num = 121;
        if (reverse_number(num, NULL) != ERR_INVALID_PARAM)
            neg_cnt++;
    }
	{	
		int reverse, rc;
		rc = reverse_number(122, &reverse);
		if (reverse != 221 || rc != EXIT_SUCCESS)
            pos_cnt++;
		rc = reverse_number(247, &reverse);
		if (reverse != 742 || rc != EXIT_SUCCESS)
            pos_cnt++;
		rc = reverse_number(-47, &reverse);
		if (reverse != -74 || rc != EXIT_SUCCESS)
            pos_cnt++;
		rc = reverse_number(2345787, &reverse);
		if (reverse != 7875432 || rc != EXIT_SUCCESS)
            pos_cnt++;
		rc = reverse_number(-982377, &reverse);
		if (reverse != -773289 || rc != EXIT_SUCCESS)
            pos_cnt++;
	}
    
	printf("\n===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
	printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");
}
