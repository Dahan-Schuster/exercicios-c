#include "lista_20.h"

/**
 * Verifica se uma dada matriz de caracteres é um palíndromo perfeito, ou seja,
 * possui 5 palavras que podem ser lidas da direita para a esquerda, cima para
 * baixo e vice-versa
 * 
 * @author Dahan Schuster
 */
int isPalindromoPerfeito(char matriz[][NC], int tam)
{
    int i, j;
    int iInverso, jInverso;

    for (i = 0; i < tam / 2; i++)
    {
        for (j = i; j < tam - i; j++)
        {
            iInverso = tam - 1 - i;
            jInverso = tam - 1 - j;

            if (matriz[i][j] != matriz[j][i] ||
                matriz[i][j] != matriz[iInverso][jInverso] ||
                matriz[i][j] != matriz[jInverso][iInverso])
                return 0;
        }
    }

    return 1;
}