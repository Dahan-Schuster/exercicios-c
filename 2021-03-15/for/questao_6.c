#include <stdio.h>

/**
 * Verifica se um número é perfeito, isto é, a soma de seus divisores
 * é igual a ele mesmo
 * Ex.: 1 + 2 + 3 = 6 ∴ 6 é perfeito
 * 
 * @author Dahan Schuster
*/
int main()
{
    int i, num;

    // inicializa a soma dos divisores com valor 1
    // isto exclui o primeiro loop, já que 1 é divisor universal
    int soma = 1;

    scanf("%d", &num);

    printf("1 ");

    // itera entre os divisores de n antes dele próprio,
    // sendo o maior deles igual a n/2
    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0) {
            soma += i;
            printf("+ %d ", i);
        }
    }

    printf("= %d ∴ %d é ", soma, num);

    // n será perfeito se for igual à soma de seus divisores
    if (soma == num) {
        printf("perfeito");
    } else {
        printf("imperfeito");
    }

    printf("\n");

    return 0;
}