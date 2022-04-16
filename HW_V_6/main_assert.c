#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_NUMBERS 100

#define FULL_MAX         -2
#define NOT_FOUND_FILE   -3
#define FILE_IS_EMPTY    -4
#define IN_FILE_SYMBOLS  -5
#define IN_FILE_DOUBLE   -6

int read_array(FILE *my_file,int a[MAX_NUMBERS], size_t *n);

int sum_of_figure(int number);

int check_sum(int number);

void converting_to_binarycod(int number, int b[MAX_NUMBERS], size_t *nb);

void reverse_number(int number, int *reverse);

int main(void)
{
	FILE *my_file;
	my_file = fopen("data.txt", "r");
	int arr[MAX_NUMBERS];
	size_t n, nb;
	int sum, reverse, rc = EXIT_SUCCESS;
	int binarycod[MAX_NUMBERS];
	if (my_file == NULL)
		return NOT_FOUND_FILE;
	rc = read_array(my_file, arr, &n);
	

	for (size_t i = 0; i < n; i++)
	{
		sum = sum_of_figure(arr[i]);
		if (check_sum(sum))
		{
			converting_to_binarycod(arr[i], binarycod, &nb);
			for (int i = nb - 1; i >= 0; i--)
			{
				if (i == nb - 1)
				{
					printf(" %d", binarycod[i]);
				} else
				{
					printf("%d", binarycod[i]);
				}
			}
		} else 
		{
			reverse_number(arr[i], &reverse);
			printf(" %d", reverse);
		}
	}
	fclose(my_file);
	return rc;
}

int read_array(FILE *f, int a[MAX_NUMBERS], size_t *n)
{
	int num, error = EXIT_SUCCESS; 
	char sym;
	*n = 0;
	
	assert(f != NULL);
	
	int result = fscanf(f, "%d%c", &num, &sym);
		
	while (result == 2 || fgetc(f) != EOF)
	{
		assert((sym == ' ' || sym == '\n') && (sym != ',' || sym != '.'));
	    a[*n] = num;
		(*n)++;
		assert(*n <= MAX_NUMBERS);
		result = fscanf(f, "%d%c", &num, &sym);
	}
	assert(*n > 0);
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

void converting_to_binarycod(int number, int b[MAX_NUMBERS], size_t *nb)
{
	*nb = 0;
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
}

void reverse_number (int number, int *reverse)
{
	*reverse = 0;

	while (abs(number) > 0)
	{
		*reverse = (*reverse) * 10 + number % 10;
		number /= 10;
	}
}