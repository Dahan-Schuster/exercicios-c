#include <stdio.h>

#define N 6

/**
 * Lê N valores do usuário e os imprime em ordem intercalada: índices pares
 * primeiro, índices ímpares depois
 * 
 * @author Dahan Schuster
 */
int main()
{

    int valores[N], i;

    for (i = 0; i < N; i++)
        scanf("%d", &valores[i]);

    // imprime de dois em dois valores a partir do primeiro (índices pares)
    for (i = 0; i < N; i+= 2)
        printf("%d ", valores[i]);

    // imprime de dois em dois valores a partir do segundo (índices ímpares)
    for (i = 1; i < N; i+= 2)
        printf("%d ", valores[i]);


    printf("\n");
    return 0;
}