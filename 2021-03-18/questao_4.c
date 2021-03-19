#include <stdio.h>

/**
 * Verifica se uma sequência de n números informados é crescrente, descrescente
 * ou nenhum
 * 
 * @author Dahan Schuster
 */
int main()
{

    int n, i;

    printf("n: ");
    scanf("%d", &n);

    int anterior,
        atual;

    printf("1º: ");
    scanf("%d", &anterior);

    int isCrescente = 0, isDecrescente = 0;
    for (i = 2; i <= n; i++)
    {
        printf("%dº: ", i);
        scanf("%d", &atual);

        // verifica isoladamente cada sequência de dois números
        // e guarda se a lista neste ponto é crescente ou decrescente

        if (atual > anterior)
            isCrescente = 1;
        else if (atual < anterior)
            isDecrescente = 1;

        anterior = atual;
    }

    // caso os valores sejam igual, significa que:
    // a) ou os valores foram todos iguais
    // b) a lista foi tanto crescente como descrescente em pontos diferentes
    if (isCrescente == isDecrescente)
    {
        printf("Nem crescente nem descrescente");
    }
    else if (isCrescente)
    {
        printf("Crescente");
    }
    else
    {
        printf("Decrescente");
    }

    printf("\n");
    return 0;
}