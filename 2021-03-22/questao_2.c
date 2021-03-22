#include <stdio.h>

int main()
{
    int i, anterior, proximo;

    scanf("%d", &anterior);

    for (i = 1; anterior > 1; i++)
    {
        printf("%d ", anterior);

        if (anterior % 2 == 0) {
            proximo = anterior / 2;
        } else {
            proximo = 3 * anterior + 1;
        }

        anterior = proximo;
    }

    printf("%d\n", proximo);
    printf("%d\n", i);
    return 0;
}