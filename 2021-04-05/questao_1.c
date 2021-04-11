#include <stdio.h>

/**
 * Imprime na saída padrão os seguintes dados (nesta ordem):
 * - O valor e o endereço de uma variável
 * - O valor, o valor para qual aponta e o endereço do ponteiro que aponta para
 *   a variável
 * 
 * @author Dahan Schuster 
 */
int main()
{
    int variavel,
        *ponteiro;

    variavel = 42;
    ponteiro = &variavel;

    printf("%d\n", variavel);
    printf("%p\n", &variavel);
    printf("%p\n", ponteiro);
    printf("%d\n", *ponteiro);
    printf("%p\n", &ponteiro);

    return 0;
}