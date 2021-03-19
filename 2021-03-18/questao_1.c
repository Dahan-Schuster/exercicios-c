#include <stdio.h>

/**
 * Calcula a quantidade de anos necessária para Barano ser maior que Foolano
 * Utiliza força bruta para fazer o cálculo
 * 
 * @author Dahan Schuster
 */
int main()
{
    float foolano = 1.5, barano = 1.1;
    int i;

    // incrementa o contato e ambos os tamanhos até que barano seja maior
    for (i = 0; barano <= foolano; i++)
        foolano += 0.2, barano += 0.3;

    printf("%d Anos.\n--------\n", i);
    printf("Barano: %.2fm\n", barano);
    printf("Foolano: %.2fm\n", foolano);

    return 0;
}