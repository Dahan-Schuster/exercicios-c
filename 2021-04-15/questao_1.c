#include <stdio.h>

#define N 7

int main()
{
    int i, j;
    char b[N * 2 + 1];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N * 2; j++)
            b[j] = 'x';
        b[N * 2] = '\0';

        for (j = 0; j <= i; j++)
        {
            b[j] = '1';
            b[N * 2 - j - 1] = '0';
        }

        /* %s é a sequência de escape para strings. */
        printf("%s\n", b);
    }
    return (0);
}