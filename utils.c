#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Cria e retorna um vetor alocado dinamicamente
 * 
 * @param int tamanho - o tamanho do vetor a ser criado
 * @param boolean initRand - inicializar ou não o vetor com números aleatórios  
 * @return int* - o vetor dinamicamente alocado
 */
int *criarVetor(int tamanho, int initRand)
{
    srand(time(0) * tamanho);

    int i, *vetor;

    vetor = (int *)malloc(tamanho * sizeof(int));

    if (initRand)
        for (i = 0; i < tamanho; i++)
            vetor[i] = rand() % 10;

    return vetor;
}

/**
 * Imprime um vetor na saída padrão
 * 
 * @param int* v - o vetor a ser impresso
 * @param char* nome - o label do vetor
 * @param int tam - o tamanho do vetor
 * @return void
 */
void printVetor(int *v, char *nome, int tam)
{
    printf("%s = { ", nome);

    int i;
    for (i = 0; i < tam; i++)
        printf("%d, ", v[i]);

    printf("}\n");
}