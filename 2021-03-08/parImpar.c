#include <stdio.h>

int main()
{
    int numero;

    printf("Olá! Este programa verifica se um número é par maior que 10 ou ímpar menor que 50. Shall we begin?\n\n");

    printf("Digite o número: ");
    scanf("%d", &numero);

    if ((numero % 2 == 0 && numero > 10) || (numero % 2 != 0 && numero < 50))
        printf("SIM");
    else
        printf("NÃO");
    

    printf("\n");
    return 0;
}