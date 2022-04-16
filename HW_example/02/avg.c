#include <stdio.h>


#define OK                   0
#define ERR_INVALID_PARAM   -1
#define ERR_NO_DATA         -2


int calc_avg(const int *a, int n, double *avg)
{
    double sum = 0;

    if (a == NULL || n < 0 || avg == NULL)
        return ERR_INVALID_PARAM;

    if (n == 0)
        return ERR_NO_DATA;

    for (int i = 0; i < n; i++)
        sum += a[i];

    *avg = sum / n;

    return OK;
}


int main(void)
{
    int a[] = {1, 5, 4, 2, 3};
    double avg;
    int rc;

    rc = calc_avg(a, sizeof(a) / sizeof(a[0]), &avg);

    if (rc == OK)
    {
        printf("avg = %.3f\n", avg);
    }
    if (rc == ERR_INVALID_PARAM)
    {
        printf("ERR_INVALID_PARAM\n");
    }
    else if (rc == ERR_NO_DATA)
    {
        printf("ERR_NO_DATA\n");
    }


    return rc;
}