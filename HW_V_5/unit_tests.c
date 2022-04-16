#include "unit_tests.h"
#include "my_func.h"

int arr_cmp(int *arr1, int *arr2, size_t size)
{
	for (size_t i = 0; i < size; i++)
		if (arr1[i] != arr2[i])
			return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

void test_read_arr_from_file(void)
{
	int neg_cnt = 0, pos_cnt = 0, test_neg = 6, test_pos = 2;
	//
	// Передача пустого файла или несуществующего файла
	//
	{
		int arr[ARR_LEN_MAX];
		size_t size = 0;
		
		if (read_arr_from_file(fopen("unit_tests/neg_tests_1.txt", "r"), arr, &size) != EMPTY_FILE)
			neg_cnt++;
		
		if (read_arr_from_file(NULL, arr, &size) != FILE_OPEN_ERR)
			neg_cnt++;
	}
	//
	// Передача некоректно записанных файлов
	//
	{
		int arr[ARR_LEN_MAX];
		size_t size = 0;
		
		if (read_arr_from_file(fopen("unit_tests/neg_tests_2.txt", "r"), arr, &size) != INVALID_INPUT)
            neg_cnt++;
        size = 0;
		if (read_arr_from_file(fopen("unit_tests/neg_tests_3.txt", "r"), arr, &size) != INVALID_INPUT)
			neg_cnt++;
        size = 0;
		if (read_arr_from_file(fopen("unit_tests/neg_tests_4.txt", "r"), arr, &size) != ARR_OVERFLOW)
			neg_cnt++; 
	}
	//
	// Передача корректных данных
	//
	{
		int arr[ARR_LEN_MAX];
		size_t size = 0;
		
		if (read_arr_from_file(fopen("unit_tests/pos_tests_1.txt", "r"), arr, &size) != EXIT_SUCCESS && size > 0)
            pos_cnt++;
        size = 0;
		if (read_arr_from_file(fopen("unit_tests/pos_tests_2.txt", "r"), arr, &size) != EXIT_SUCCESS && size > 0)
			pos_cnt++;
	}
	
	printf("\n===%s:\n -Negative tests: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
	printf("\n -Positive tests: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");
}

void test_bubble_sort(void)
{
	int pos_cnt = 0, test_pos = 3, neg_cnt = 0, test_neg = 0;
	//
	// Проверка корректности функции
	//
	{
		size_t size = 0;
		
		int arr1[] = {5, 1, 8, 3, 2, 4, 7, 6};
		int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
		size = 8;
		bubble_sort(arr1, size);
		if (arr_cmp(arr1, arr2, size) != EXIT_SUCCESS)
            pos_cnt++;
		int arr3[] = {-5, 1, 8, -3, 2, 2, 0, 6};
		int arr4[] = {-5, -3, 0, 1, 2, 2, 6, 8};
		size = 8;
		bubble_sort(arr3, size);
		if (arr_cmp(arr3, arr4, size) != EXIT_SUCCESS)
            pos_cnt++;
		int arr5[] = {-5, -1, -8, -3, -2, -4, -7, -6};
		int arr6[] = {-8, -7, -6, -5, -4, -3, -2, -1};
		size = 8;
		bubble_sort(arr5, size);
		if (arr_cmp(arr5, arr6, size) != EXIT_SUCCESS)
            pos_cnt++;
	}
	printf("\n===%s:\n -Negative tests: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
	printf("\n -Positive tests: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");
}

void test_odd_to_right(void)
{
	int pos_cnt = 0, test_pos = 3, neg_cnt = 0, test_neg = 0;
	//
	// Проверка корректности функции
	//
	{
		size_t size = 0;
		
		int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
		int arr2[] = {2, 4, 6, 8, 7, 5, 3, 1};
		size = 8;
		odd_to_right(arr1, size);
		if (arr_cmp(arr1, arr2, size) != EXIT_SUCCESS)
            pos_cnt++;
		int arr3[] = {-5, -3, 0, 1, 2, 2, 6, 8};
		int arr4[] = {0, 2, 2, 6, 8, 1, -3, -5};
		size = 8;
		odd_to_right(arr3, size);
		if (arr_cmp(arr3, arr4, size) != EXIT_SUCCESS)
            pos_cnt++;
		int arr5[] = {-8, -7, -6, -5, -4, -3, -2, -1};
		int arr6[] = {-8, -6, -4, -2, -1, -3, -5, -7};
		size = 8;
		odd_to_right(arr5, size);
		if (arr_cmp(arr5, arr6, size) != EXIT_SUCCESS)
            pos_cnt++;
	}
	printf("\n===%s:\n -Negative tests: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
	printf("\n -Positive tests: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");
}

int main(void)
{
	printf("\nUSER UNIT TEST:\n");
	test_read_arr_from_file();
	test_bubble_sort();
	test_odd_to_right();
	return 0;
}