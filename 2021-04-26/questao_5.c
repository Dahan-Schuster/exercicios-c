#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 2
#define N 3

/**
 * Imprime uma matriz
 * 
 * @author Dahan Schuster
 */
void printMatriz(int lins, int cols, int matriz[lins][cols])
{
    int i, j;
    for (i = 0; i < lins; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%0d, ", matriz[i][j]);
        printf("\n");
    }
}

/**
 * Multiplica duas matrizes A[M][N] e B[N][M], gerando uma matriz P[M][M]
 * 
 * @author Dahan Schuster
 */
int main()
{
    srand(time(0));

    int matriz_a[M][N],
        matriz_b[N][M];

    // o produto possui o nº de linhas da primeira e de colunas da segunda
    int produto[M][M] = { 0 };

    // Cria contadores para as lins e cols das matrizes A e B, respectivamente i
    // e j, e um contador para ambas as cols de A e lins de B
    // Isso se deve ao fato da multiplicação de matrizes exigir que o nº de cols
    // de A seja igual ao de lins de B, então temos o contador k como um nó
    // entre as matrizes
    int i, j, k;

    // Preenche as matrizes com valores pseudo-aleatórios
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
        {
            matriz_a[i][j] = rand() % 5 + 1;
            matriz_b[j][i] = rand() % 5 + 1;
        }

    printMatriz(M, N, matriz_a);
    printf("\n");
    printMatriz(N, M, matriz_b);
    printf("\n");

    // Itera pelo número de linhas da matriz A
    for (i = 0; i < M; i++)
        // Itera pelo número de colunas da matriz B        
        for (j = 0; j < M; j++)
            // itera pelo número de colunas das matriz A e linhas da matriz B
            for (k = 0; k < N; k++)
                produto[i][j] += matriz_a[i][k] * matriz_b[k][j];
    

    printMatriz(M, M, produto);

    return (0);
}