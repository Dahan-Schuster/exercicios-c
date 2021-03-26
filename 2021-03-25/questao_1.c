#include <stdio.h>

/**
 * Calcula a tabuada de 1 a 10 utilizando for's aninhados
 * 
 * @author Dahan Schuster
 */
int main()
{
    int i, j;

    for (i = 1; i <= 10; i++)
    {
        printf("=============\n");
        printf("Tabuada de %02d\n", i);
        printf("=============\n");

        // multiplica cada número de 1 a 10 pelos números 1 a 10
        for (j = 1; j <= 10; j++)
        {
            printf("%02d * %02d = %02d\n", i, j, i * j);
        }
        
        printf("\n");
    }
    
    return 0;
}