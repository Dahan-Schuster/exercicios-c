#include <stdio.h>

/**
 * Calcula a tabuada de um número n
 * 
 * @author Dahan Schuster
 */
int main()
{
    float num;

    printf("Para começar, digite o número: ");
    scanf("%f", &num);

    int i;
    for (i = 1; i <= 10; i++)
    {
        printf("%.2f x %d = %.2f;\n", num, i, num * i);
    }

    return 0;
}