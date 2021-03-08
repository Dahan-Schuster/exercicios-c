#include <stdio.h>

int main() {
    int valor = 218;


    printf("Para completar R$ %d, serão necessárias ", valor);
    printf("%d notas de R$ 50, ", valor / 50);
    printf("%d notas de R$ 5 e ", valor % 50 / 5);
    printf("%d notas de R$ 1. ", valor % 50 % 5);

    return 0;
}
