#include <stdio.h>
#include <math.h>

int isLadoValido(int a, int b, int c)
{
    return (fabs(b - c) < a) && (a < b + c);
}

int main()
{
    float ladoA, ladoB, ladoC;

    printf("Olá! Este programa verifica se três valores podem formar um triângulo. Shall we begin?\n\n");

    printf("Para começar, informe...\n");

    printf("Lado A: ");
    scanf("%f", &ladoA);

    printf("Lado B: ");
    scanf("%f", &ladoB);

    printf("Lado C: ");
    scanf("%f", &ladoC);

    // (|b-c| < a < b + c) && (|a-c| < b < a + c) && (|a-b| < c < a + b)
    if (isLadoValido(ladoA, ladoB, ladoC) &&
        isLadoValido(ladoB, ladoA, ladoC) &&
        isLadoValido(ladoC, ladoA, ladoB))
    {
        if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC)
        {
            if (ladoB == ladoC && ladoC == ladoA)
                printf("Triângulo Equilátero");
            else
                printf("Triângulo Isósceles");
        }
        else
            printf("Triângulo Escaleno");
    }
    else
    {
        printf("Triângulo inválido!");
    }

    printf("\n");
    return 0;
}