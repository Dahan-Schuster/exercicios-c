#include <limits.h>
#include <stdio.h>

int main()
{
    int maior = INT_MIN;
    int num1, num2, num3;

    printf("Olá! Este programa recebe três números e mostra o maior. Shall we begin?\n\n");

    printf("Digite os números:");

    printf("\nPrimeiro: ");
    scanf("%d", &num1);

    if (num1 > maior)
        maior = num1;

    printf("Segundo: ");
    scanf("%d", &num2);

    if (num2 > maior)
        maior = num2;

    printf("Terceiro: ");
    scanf("%d", &num3);

    if (num3 > maior)
        maior = num3;

    printf("\nMaior número: %d\n", maior);

    return 0;
}