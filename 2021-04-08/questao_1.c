#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6

/**
 * Preenche um vetor com N números aleatórios e imprime aqueles
 * cujo valor é igual ao índice
 * 
 * @author Dahan Schuster
 */
int main()
{
    int numeros[N];
    int i;

    srand(time(0));

    for (i = 0; i < N; i++)
        numeros[i] = rand() % N;

    for (i = 0; i < N; i++)
        if (numeros[i] == i)
            printf("%d\n", numeros[i]);

    return 0;
}