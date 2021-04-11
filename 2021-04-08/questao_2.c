#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

/**
 * Preenche um vetor com N números aleatórios entre 20 e 80
 * Imprime a média dos valores do vetor, além de cada valor individual com sua
 * posição em relação à média (<, >) e por fim quantos valores foram maiores e
 * menores que a média
 * 
 * @author Dahan Schuster
 */
int main()
{
    int numeros[N];
    int i, soma = 0, media;

    srand(time(0));

    //   rand() % 61 == [00..60]
    // [00..60] + 20 == [20..80]
    for (i = 0; i < N; i++)
    {
        numeros[i] = rand() % 61 + 20;
        soma += numeros[i];
    }

    media = soma / N;
    printf("Média: %d\n", media);
    printf("---------\n");

    int maiores = 0, menores = 0;

    for (i = 0; i < N; i++)
    {
        printf("%d ", numeros[i]);
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
    
        printf(" %d\n", media);
    }

    printf("---------\n");
    printf("%d valores maiores que a média\n", maiores);
    printf("%d valores menores que a média\n", menores);

    return 0;
}