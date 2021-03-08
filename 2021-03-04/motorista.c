#include <stdio.h>

int main()
{
    int velocidadeMaxima, velocidadeMotorista, excedentes, multa;

    printf("Olá! Este programa verifica se multas devem ser pagas por um motorista. Shall we begin?\n\n");

    printf("Para começar, digite a velocidade máxima da pista e, depois, a velocidade do motorista\n");

    printf("Velocidade máxima: ");
    scanf("%d", &velocidadeMaxima);

    printf("Velocidade motorista: ");
    scanf("%d", &velocidadeMotorista);

    excedentes = velocidadeMotorista - velocidadeMaxima;

    if (excedentes <= 0)
    {
        printf("\nNão há multas a serem pagas! A velocidade estava dentro do permitido");
    }
    else
    {
        multa = 50 * excedentes;
        printf("\nO motorista excedeu %d Km/h a mais que o permitido, e deverá pagar R$ %d,00 de multa.", excedentes, multa);
    }

    printf("\n");
    return 0;
}