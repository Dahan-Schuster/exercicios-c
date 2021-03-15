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

    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Digite o %dº número: ", i + 1);
        scanf("%f", &num);

        // só inclui na soma os números menores que 20
        if (num < 20)
        {
            // salva em outro iterador a quantidade de números menores que 20
            qteNumerosValidos++;
            soma += num;
        }
    }

    media = soma / qteNumerosValidos;

    printf("Média entre os %d números menores que 20: %.2f\n", qteNumerosValidos, media);

    return 0;
}