#include <stdlib.h>

#define N_MAX 1000001

/**
 * Cria e retorna uma tabela usando o algorítmo do Crivo de Eratóstenes
 * O vetor da tabela é alocado dinamicamente e deve ser liberado pelo chamador
 * 
 * @return int* - uma tabela contendo true/false em cada índice, indicando se
 * aquele índice é um número primo ou não. Ex.: tabela[7] == 1, tabela[6] == 0
 * 
 * @author Dahan Schuster
 */
int *criarCrivoDeEratostenes()
{
    int *tabela = (int *)malloc(sizeof (int) * N_MAX);

    int i;
    for (i = 0; i < N_MAX; i++) // inicializa os valores com verdadeiro
        tabela[i] = 1;

    int j;
    for (i = 2; i < N_MAX; i++) // itera pela tabela começando pelo índice 2
        if (tabela[i])          // se achar um valor verdadeiro em i...
            for (j = i * 2; j < N_MAX; j += i)  // itera pelos múltiplos de i
                if (tabela[j])  // define os múltiplos de i como falso
                    tabela[j] = 0;

    return tabela;
}