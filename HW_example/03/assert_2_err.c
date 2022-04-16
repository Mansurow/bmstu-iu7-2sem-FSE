#include <stdio.h>
#include <assert.h>

#define OK           0
#define ERR_IO      -1
#define ERR_NEG     -2

long long int power(int base, int n)
{
    long long int mul = 1;

    for (int i = 0; i < n; i++)
        mul *= base;

    return mul;
}

int main(void)
{
    int base, n, rc;

    printf("Enter base, n: ");
    if (scanf("%d%d", &base, &n) == 2)
    {
        assert(n >= 0);

        printf("%d^%d=%lld\n", base, n, power(base, n));

        rc = OK;
    }
    else
    {
        printf("IO error\n");

        rc = ERR_IO;
    }

    return rc;
}
