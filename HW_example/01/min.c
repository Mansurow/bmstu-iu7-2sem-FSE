#include <stdio.h>


int find_imin(const int *a, int n)
{
    int imin = 0;

    if (a == NULL || n <= 0)
        return -1;

    for (int i = 1; i < n; i++)
        if (a[i] < a[imin])
            imin = i;

    return imin;
}


int main(void)
{
    int a[] = {3, 2, 4, 1, 5};

    printf("imin = %d\n", find_imin(a, sizeof(a) / sizeof(a[0])));
    printf("imin = %d\n", find_imin(a, 0));
    printf("imin = %d\n", find_imin(a, -5));

    return 0;
}