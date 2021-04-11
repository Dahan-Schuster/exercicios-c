#include <stdio.h>

#define N 10

/**
 * Lê N números e os imprime na ordem inversa
 * 
 * @author Dahan Schuster
 */
int main()
{

    int valores[N], i;

    for (i = 0; i < N; i++)
        scanf("%d", &valores[i]);

    printf("---\n");

    for (i = N - 1; i >= 0; i--)
        printf("%d\n", valores[i]);

    return 0;
}