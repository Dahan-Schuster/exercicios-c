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

    int i = 1;
    // multiplica num pelo iterador i a cada loop até 10
    while (i <= 10)
    {
        // imprime o cálculo feito e seu resultado
        printf("%.2f x %d = %.2f;\n", num, i, num * i);
        i++;
    }

    return 0;
}