#include <stdio.h>

int main() {
    int penultimo = 0, atual = 1, proximo;    

    int i, tamanhoSequencia;
    scanf("%d", &tamanhoSequencia);

    printf("%d, %d", penultimo, atual);
    for (i = 2; i < tamanhoSequencia; i++)
    {
        proximo = atual + penultimo;
        penultimo = atual;
        atual = proximo;
        printf(", %d", proximo);
    }

    printf("\n");
    return 0;
}