#include <stdlib.h>
#include "lista_21.h"


/**
 * Gera um triângulo de pascal com grau*grau posições
 * 
 * @author Dahan Schuster
 */
int **geraTrianguloDePascal(int grau)
{
    int **matriz, i, j;

    matriz = (int **)malloc(grau * (sizeof(int *)));

    for (i = 0; i < grau; i++)
    {
        matriz[i] = (int *)calloc(grau, sizeof(int));

        // inicializa os primeiros elementos e os da diagonal principal com 1
        matriz[i][0] = matriz[i][i] = 1;
    }

    // Soma cada elemento da matriz com seus vizinhos superior e
    // superior esquerdo, partindo dos índices [2][1], porque de
    // [0][0] a [2][0] todos os valores são 1
    for (i = 2; i < grau; i++)
        for (j = 1; j < i; j++)
            matriz[i][j] = matriz[i - 1][j] + matriz[i - 1][j - 1];

    return matriz;
}