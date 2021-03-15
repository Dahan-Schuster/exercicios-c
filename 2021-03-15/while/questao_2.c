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

    int i = num + 1;
    while (i <= num + 10)
    {
        printf("%d\n", i);
        i++;
    }

    return 0;
}