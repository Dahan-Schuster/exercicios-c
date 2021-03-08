#include <stdio.h>

int main()
{
    int numero;
    int centena, dezena, unidade;

    printf("Olá! Este programa recebe um número entre 100 e 999 e o retorna na ordem inversa (UDC). Shall we begin?\n\n");

    printf("Digite um número entre 100 e 999: ");
    scanf("%d", &numero);

    unidade = numero % 10;
    dezena = numero % 100 / 10;
    centena = numero / 100;

    if (unidade > 0)
    {
        printf("%d", unidade);
        printf("%d", dezena);
    }
    else if (dezena > 0)
        printf("%d", dezena);

    printf("%d\n", centena);

    return 0;
}