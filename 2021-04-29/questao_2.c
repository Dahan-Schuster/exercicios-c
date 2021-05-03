#include "lista_20.h"

/**
 * Retorna 1 se a matriz dada for simétrica, e 0 do contrário
 * 
 * @author Dahan Schuster
 */
int ehSimetrica(int matriz[N][N], int tam)
{
    int i, j;

    /* Itera com o i até a penúltima linha apenas, pois o índice m[j][i]
        alcança a última linha quando j == tam - 1 */
    for (i = 0; i < tam - 1; i++)
        /* Itera pela diagonal superior da matriz (j == 1 + i), comparando o
            elemento m[i][j] ao seu reflexo na diagonal inferior m[j][i] */
        for (j = 1 + i; j < tam; j++)
            if (matriz[i][j] != matriz[j][i])
                return 0;

    /* A diagonal principal m[i][i] não entra na comparação, pois ela não
        interfere na simetria da matriz  */

    return 1;
}