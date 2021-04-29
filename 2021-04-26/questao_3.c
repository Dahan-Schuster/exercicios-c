#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_LINHAS 3
#define N_COLUNAS 4

/**
 * Gera uma matriz MxN pseudo-aleatória e sua transposta NxM,
 * depois imprime ambas
 * 
 * @author Dahan Schuster
 */
int main()
{
    srand(time(0));

    int matriz[N_LINHAS][N_COLUNAS],
        transposta[N_COLUNAS][N_LINHAS];

    int i, j;
    for (i = 0; i < N_LINHAS; i++)
        for (j = 0; j < N_COLUNAS; j++)
            matriz[i][j] = transposta[j][i] = rand() % 20 + 1;

    printf("* Matriz: \n");
    for (i = 0; i < N_LINHAS; i++) {
        for (j = 0; j < N_COLUNAS; j++)
            printf("%02d, ", matriz[i][j]);
        printf("\n");
    }

    printf("\n* Transposta: \n");
    for (i = 0; i < N_COLUNAS; i++) {
        for (j = 0; j < N_LINHAS; j++)
            printf("%02d, ", transposta[i][j]);
        printf("\n");
    }

    return (0);
}