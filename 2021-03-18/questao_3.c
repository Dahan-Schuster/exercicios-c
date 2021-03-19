#include <stdio.h>

/**
 * Calcula a fatorial de um número informado (n!)
 * 
 * @author Dahan Schuster
 */
int main()
{

    int n;

    printf("n: ");
    scanf("%d", &n);

    // Por definição, apenas números naturais positivos possuem fatorial
    if (n < 0)
    {
        printf("Erro! n < 0\n");
        return 0;
    }

    int aux = n,      // guarda o valor pelo qual o fatorial será multiplicado em cada loop
        fatorial = 1; // inicializa o valor do fatorial como 1, pois 0! = 1

    while (aux > 1) // caso n = 0, não faz a multiplicação (evita que 0! = 0)
    {
        fatorial *= aux;
        aux--; // decrementa o auxiliar até chegar a 1
    }

    printf("%d\n", fatorial);

    return 0;
}