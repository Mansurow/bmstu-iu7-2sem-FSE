#include <stdio.h>
#include <assert.h>

int main(void)
{
    FILE *f = NULL;

    assert((f = fopen("test.txt", "r")) != NULL);

    if (f)
    {
        printf("File exists\n");

        fclose(f);
    }
    else
        printf("File does not exists\n");

    return 0;
}
