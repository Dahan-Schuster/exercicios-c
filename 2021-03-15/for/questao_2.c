#include <stdio.h>

/**
 * Recebe um número n e imprime os 10 números inteiros maiores que n
 * 
 * @author Dahan Schuster
*/
int main()
{
    float num;

    printf("Para começar, digite o número: ");
    scanf("%f", &num);

    int i;
    for (i = num + 1; i <= num + 10; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}