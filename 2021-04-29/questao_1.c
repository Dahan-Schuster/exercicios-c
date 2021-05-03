#include <stdlib.h>
#include "lista_20.h"

/**
 * Retorna 1 caso uma matriz dada possua ao menos um elemento repetido, 0 do
 * contrário 
 * 
 * @author Dahan Schuster
 */
int contemElementoRepetido(int matriz[][NC], int lins, int cols)
{
    /* cria um vetor para armazenar os valores da matriz de forma linear */
    int *vetor = (int *)malloc((lins * cols) * sizeof(int));

    /* guarda a quantidade de elementos postos no vetor auxiliar */
    int tamVetor = 0;
    int i, j, v = 0;

    for (i = 0; i < lins; i++)
        for (j = 0; j < cols; j++)
        {
            /* itera pelo vetor verificando se o índice [i][j] está duplicado */
            for (v = 0; v < tamVetor; v++)
                if (matriz[i][j] == vetor[v])
                    return 1;

            /* se não estiver, o adiciona no vetor */
            vetor[tamVetor] = matriz[i][j];
            tamVetor++;
        }

    free(vetor);
    return 0;
}