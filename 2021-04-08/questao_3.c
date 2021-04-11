#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

/**
 * Gera N números aleatórios entre -40 e 40 e preenche um vetor com os números
 * positivos dentre os gerados
 * Imprime a média dos valores do vetor, além de cada valor individual com sua
 * posição em relação à média (<, >) e por fim quantos valores foram maiores e
 * menores que a média
 * 
 * 
 * @author Dahan Schuster
 */
int main()
{
    srand(time(0));

    float numeros[N],
        randNum,
        soma = 0,
        media;

    int i, numsPositivos = 0;

    //   rand() % 81 == [00..80]
    // [00..80] - 40 == [-40..40]
    for (i = 0; i < N; i++)
    {
        randNum = (float)(rand() % 81 - 40);
        if (randNum >= 0)
        {
            numeros[numsPositivos] = randNum;
            soma += randNum;
            numsPositivos++;
        }
    }

    if (numsPositivos <= 0)
    {
        printf("Nenhum número positivo gerado.\n");
        return 1;
    }

    media = soma / numsPositivos;
    printf("Média dos positivos: %.2f\n", media);
    printf("---------\n");

    int maiores = 0, menores = 0;

    for (i = 0; i < numsPositivos; i++)
    {
        printf("%05.2f ", numeros[i]);
        if (numeros[i] < media)
        {
            printf("<");
            menores++;
        }
        else if (numeros[i] > media)
        {
            printf(">");
            maiores++;
        }
        else
            printf("=");

        printf(" %.2f\n", media);
    }

    printf("---------\n");
    printf("%d valores maiores que a média\n", maiores);
    printf("%d valores menores que a média\n", menores);

    return 0;
}