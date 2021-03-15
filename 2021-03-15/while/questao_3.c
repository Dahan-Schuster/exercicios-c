#include <stdio.h>

/**
 * Imprime a média entre 10 números inteiros menores que 20
 * 
 * @author Dahan Schuster
*/
int main()
{
    int qteNumerosValidos = 0;
    float media, num, soma = 0;

    int i = 0;
    while (i < 10)
    {
        printf("Digite o %dº número: ", i + 1);
        scanf("%f", &num);

        if (num < 20)
        {
            qteNumerosValidos++;
            soma += num;
        }

        i++;
    }

    media = soma / qteNumerosValidos;

    printf("Média entre os %d números menores que 20: %.2f\n", qteNumerosValidos, media);

    return 0;
}