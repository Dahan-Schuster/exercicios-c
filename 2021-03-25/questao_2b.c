#include <stdio.h>

/**
 * Calcula todas a possibilidades de resultado ao lançar três dados de seis lados
 * Não considera as possibiidades com valor igual em soma (ex.: 1, 1, 2 e 2, 1, 1)
 * 
 * @author Dahan Schuster
 */
int main()
{
    int dado1, dado2, dado3;

    // Para cada dado, considera a movimentação dos outros dois enquanto o
    // mesmo permanece com o mesmo valor. Depois incrementa seu valor em 1 e
    // repete o processo, até que todos os dados tenham mostrado suas 6 faces
    for (dado1 = 1; dado1 <= 6; dado1++)
    {
        // O inicializador dos contadores dos demais dados será sempre o valor
        // do contador imediatamente mais externo, o que evita a impressão de valores
        // reduntantes.
        // Ex.: se já foi impresso 1, 2, 1 em uma determinada iteração, não
        // será possível imprimir 2, 1, 1, pois o valor do segundo dado não
        // voltará mais a ser 1, começando então a partir de 2, 2, 1
        for (dado2 = dado1; dado2 <= 6; dado2++)
        {
            for (dado3 = dado2; dado3 <= 6; dado3++)
            {
                printf("%d, %d, %d\t\t", dado1, dado2, dado3);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}