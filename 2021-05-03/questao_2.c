#include <stdlib.h>
#include "lista_21.h"

/**
 * Desaloca uma matriz quadradada da memória
 * 
 * @author Dahan Schuster
 */
void destroiTrianguloDePascal(int **t, int grau)
{
    int i;
    for (i = 0; i < grau; i++)
        free(t[i]);

    free(t);
}