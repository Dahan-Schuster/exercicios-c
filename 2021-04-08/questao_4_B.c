#include <stdio.h>

#define N 1024

/**
 * Recebe o valor de N pela enrada padrão e
 * lê N números, depois os imprime na ordem inversa
 * 
 * @author Dahan Schuster
 */
int main()
{

    int valores[N], i;
    int tam = N + 1;

    while(tam > N) {
        printf("MAX %d: ", N);
        scanf("%d", &tam);
    }

    for (i = 0; i < tam; i++)
        scanf("%d", &valores[i]);

    printf("---\n");

    for (i = tam - 1; i >= 0; i--)
        printf("%d\n", valores[i]);

    return 0;
}