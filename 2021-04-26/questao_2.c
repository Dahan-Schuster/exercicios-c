#include <stdio.h>

#define N_LINHAS 3
#define N_COLUNAS 4

/**
 * Calcula e imprime a soma dos elementos de uma dada linha e coluna da matriz
 * 
 * @author Dahan Schuster
 */
int main()
{
    int m[N_LINHAS][N_COLUNAS]= { {1, 2, 3, 4},
                                  {2, 4, 6, 8},
                                  {3, 6, 9, 5} };
    int i, lin, col, soma = 0;
    scanf("%d, %d", &lin, &col);

    // soma os elementos da coluna iterando pelas linhas
    for (i = 0; i < N_LINHAS; i++)
        soma += m[i][col];

    // soma os elementos da linha iterando pelas colunas
    for (i = 0; i < N_COLUNAS; i++)
        soma += m[lin][i];

    // subtrai o elemento na posição [lin][col], pois ele foi considerado duas
    // vezes na soma (uma em cada loop)
    soma -= m[lin][col];
    
    printf("%d\n", soma);

    return (0);
}