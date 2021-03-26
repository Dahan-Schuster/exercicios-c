#include <stdio.h>

/**
 * Calcula todas a possibilidades de resultado ao lançar três dados de seis lados
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
        // Como o inicializador do contador é sempre 1, possibilidades com
        // valor somatório igual (ex.: 1, 1, 2 e 2, 1, 1) serão mostradas
        for (dado2 = 1; dado2 <= 6; dado2++)
        {
            for (dado3 = 1; dado3 <= 6; dado3++)
            {
                printf("%d, %d, %d\t\t", dado1, dado2, dado3);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}