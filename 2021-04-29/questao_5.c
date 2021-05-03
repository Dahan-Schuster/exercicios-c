#include <stdio.h>
#include "lista_20.h"

/**
 * Recebe uma matriz e imprime seu reflexo nos 4 quadrantes
 * 
 * @author Dahan Schuster
 */
void printMatrizEspelhada(char matriz[][NC], int lins, int cols)
{
    int i, j;

    // imprime os quandrantes superiores (1 e 2)
    for (i = 0; i < lins; i++)
    {
        // quadrante 2 (superior esquerdo)
        for (j = 0; j < cols; j++)
            printf("%c", matriz[i][j]);
        // quadrante 1 (superior direito)
        for (j = cols - 1; j >= 0; j--)
            printf("%c", matriz[i][j]);
        printf("\n");
    }

    // imprime os quandrantes inferiores (3 e 4)
    for (i = lins - 1; i >= 0; i--)
    {
        // quadrante 3 (inferior esquerdo)
        for (j = 0; j < cols; j++)
            printf("%c", matriz[i][j]);
        // quadrante 4 (inferior direito)
        for (j = cols - 1; j >= 0; j--)
            printf("%c", matriz[i][j]);
        printf("\n");
    }
}

/**
 * Recebe uma matriz e gera uma outra representando seu reflexo nos 4 quadrantes
 * 
 * @author Dahan Schuster
 */
void geraMatrizEspelhada(
    char matriz[NL][NC],
    char matriz_espelho[NL * 2][NC * 2],
    int lins,
    int cols)
{
    int dobroLins = lins * 2;
    int dobroCols = cols * 2;

    int i, j;
    for (i = 0; i < lins; i++)
        for (j = 0; j < cols; j++)
        {
            // copia cada elemento da matriz quatro vezes para a matriz espelho,
            // uma cópia para cada quadrante
            matriz_espelho[i][j] = matriz[i][j];
            matriz_espelho[i][dobroCols - 1 - j] = matriz[i][j];
            matriz_espelho[dobroLins - 1 - i][j] = matriz[i][j];
            matriz_espelho[dobroLins - 1 - i][dobroCols - 1 - j] = matriz[i][j];
        }
}