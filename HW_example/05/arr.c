#include <stdio.h>
#include <math.h>


#define N 10


#define OK       0
#define ERR_IO  -1
#define ERR_VAL -2


int input(int *a, int *n)
{
    printf("Input number of elemets:\n");

    if (scanf("%d", n) != 1)
        return ERR_IO;

    if (*n < 0 || *n > 10)
        return ERR_VAL;


    printf("Enter elements:\n");

    for (int i = 0; i < *n; i++)
        if (scanf("%d", a + i) != 1)
            return ERR_IO;

    return OK;
}


void print(const int *a, int n)
{
    printf("Array:\n");
    
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}


int main(void)
{
    int arr[N];
    int n;
    int rc;

    rc = input(arr, &n);
    if (rc == OK)
        print(arr, n);
    else
        printf("Error: %d\n", rc);

    return 0;
}