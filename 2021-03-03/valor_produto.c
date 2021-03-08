#include <stdio.h>

int main()
{
    float valorDeFabrica, lucro, impostos, valorFinal;

    printf("Olá! Este programa calcula o valor final de um produto. Shall we begin?\n\n");

    printf("Para começar, digite o valor de fábrica do produto: ");
    scanf("%f", &valorDeFabrica);

    impostos = valorDeFabrica * 0.45;
    lucro = valorDeFabrica * 0.12;
    valorFinal = valorDeFabrica + impostos + lucro;

    printf("Para um produto que custa R$ %.2f para ser fabricado, você pagará:\n\n", valorDeFabrica);
    printf("R$ %.2f de impostos;\n", impostos);
    printf("R$ %.2f de lucro ao vendedor;\n", lucro);
    printf("\nTotalizando R$ %.2f de valor final\n", valorFinal);

    return 0;
}