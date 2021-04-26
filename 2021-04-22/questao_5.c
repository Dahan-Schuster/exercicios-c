#include <stdlib.h>

/**
 * Copia os elementos de vetor em novo_vetor sem repetição de elementos
 * Aloca dinamicamente o espaço de memória do novo_vetor
 * 
 * 
 * @param int *vetor - o vetor original
 * @param int tam_vetor - o tamanho do vetor original
 * @param int **novo_vetor - ponteiro para o vetor destino
 * @return int - A quantidade de elementos inseridos no novo_vetor
 * @author Dahan Schuster
 */
int removeRepeticoes (int* vetor, int tam_vetor, int** novo_vetor)
{
    int i, j;
    int elem_repetido;
    int tam_novo_vetor = 0;

    // define o espaço inicial do novo vetor como o mesmo do vetor original
    (*novo_vetor) = (int *)malloc(sizeof (int) * tam_vetor);

    for (i = 0; i < tam_vetor; i++)
    {
        elem_repetido = 0;

        // verifica se vetor[i] está entre os elementos já inseridos no novo_vetor
        for (j = 0; j < tam_novo_vetor && !elem_repetido; j++)
            elem_repetido = (*novo_vetor)[j] == vetor[i];

        // se não, colocamos vetor[i] na próxima posição do novo_vetor
        if (!elem_repetido) {
            (*novo_vetor)[tam_novo_vetor] = vetor[i];
            tam_novo_vetor++;
        }
        
    }


    // após saber o tamanho real do novo vetor, realoca o espaço de memória
    // dedicado a ele
    (*novo_vetor) = realloc((*novo_vetor), sizeof (int) * tam_novo_vetor);
    return tam_novo_vetor;
}