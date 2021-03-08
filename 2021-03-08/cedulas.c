#include <stdio.h>

int main()
{
    float valor;

    printf("Olá! Este programa calcula a quantidade de cédulas de cada nota necessárias para completar um valor. Shall we begin?\n\n");

    printf("Primeiro, digite o valor (R$): ");
    scanf("%f", &valor);

    int valorInteiro = (int)valor;

    int notasDeCem = valorInteiro / 100,
        restanteDeCem = valorInteiro % 100,

        notasDeCinquenta = restanteDeCem / 50,
        restanteDeCinquenta = restanteDeCem % 50,

        notasDeVinte = restanteDeCinquenta / 20,
        restanteDeVinte = restanteDeCinquenta % 20,

        notasDeDez = restanteDeVinte / 10,
        restanteDeDez = restanteDeVinte % 10,

        notasDeCinco = restanteDeDez / 5,
        restanteDeCinco = restanteDeDez % 5,

        notasDeDois = restanteDeCinco / 2,
        notasDeUm = restanteDeCinco % 2;

    printf("Para completar R$ %d, serão necessárias:\n", valorInteiro);
    printf("%d notas de R$ 100;\n", notasDeCem);
    printf("%d notas de R$ 50;\n", notasDeCinquenta);
    printf("%d notas de R$ 20;\n", notasDeVinte);
    printf("%d notas de R$ 10;\n", notasDeDez);
    printf("%d notas de R$ 5;\n", notasDeCinco);
    printf("%d notas de R$ 2 e\n", notasDeDois);
    printf("%d notas de R$ 1\n", notasDeUm);

    return 0;
}
