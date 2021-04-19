#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Remove do vetor o elemento da posição idx
 * Recebe, além do vetor e do índice, o tamanho do array por referência
 * 
 * A remoção é feita ao copiar os valores do vetor uma posição à esquerda,
 * e depois diminuir o tamanho lógico do vetor em 1
 * 
 * O tamanho lógico se refere ao valor utilizado no programa como tamanho do
 * array, já que não há como dimnuir o espaço de memória alocado inicialmente
 * 
 * @author Dahan Schuster
 * 
 */
void deletarElemento(int *vetor, int idx, int *tam)
{
    // itera até o fim do vetor, partindo do índice a ser removido
    // não há necessidade de iterar pelos valores anteriores a idx
    for (idx; idx < *tam - 1; idx++)
        vetor[idx] = vetor[idx + 1]; // copia o valor da direita para a esquerda

    // após deslocar os valores para a esquerda, omite o último índice
    (*tam)--;
}

/**
 * Imprime na saída padrão todos os valores do vetor
 */
void imprimirVetor(int *v, int tam)
{
    printf("-> { ");
    int i;
    for (i = 0; i < tam; i++)
        printf("%d ", v[i]);

    printf("}\n");
}

#define N 5

/**
 * Gera um vetor com N elementos aleatórios, os apresenta ao usuário e espera
 * por um índice para remover
 * Repete essa operação até que não haja elementos no array, ou até o índice
 * escolhido seja inválido
 * 
 * @author Dahan Schuster
 */
int main()
{
    srand(time(0));

    // variável utilizada como tamanho lógico do vetor
    int tam = N;

    // inicializa o vetor com o tamanho inicial, porém as iterações usarão
    // o tamanho lógico
    int vetor[N];

    int i;
    for (i = 0; i < N; i++)
        vetor[i] = rand() % 10; // preenche com valores aleatórios de 0 a 9

    imprimirVetor(vetor, tam);

    // pede ao usuário o índice a remover
    int idxRemocao;
    scanf("%d", &idxRemocao);

    // enquanto houverem elementos no vetor e o índice for válido...
    while (tam > 0 && idxRemocao >= 0 && idxRemocao < tam)
    {
        deletarElemento(vetor, idxRemocao, &tam);
        imprimirVetor(vetor, tam);

        if (tam > 0)
            scanf("%d", &idxRemocao);
    }

    return 0;
}