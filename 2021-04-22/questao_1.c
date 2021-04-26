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

/**
 * Cria dois vetores com tamanhos inseridos na entrada padrão e inicializados
 * com números aleatórios, e os imprime na saída padrão junto a um terceiro
 * vetor contendo os produtos dos elementos dos dois vetores iniciais
 * 
 * @author Dahan Schuster
 */
int main()
{
    int tamV1, tamV2, tamV3;
    scanf("%d %d", &tamV1, &tamV2);

    // v3 irá conter a multiplicação dos elementos do v1 pelos do v2
    // ex.: v1 = {1, 2} ; v2 = {0, 1, 2}; v3 = {0, 1, 2, 0, 2, 4}
    tamV3 = tamV1 * tamV2;

    int *v1 = criarVetor(tamV1, 1);
    int *v2 = criarVetor(tamV2, 1);
    int *v3 = criarVetor(tamV3, 0);

    // i itera por v1; j itera por v2; k itera por v3
    // k não pode ser reinicializado com 0 a cada loop, e deve ser incrementado
    // junto ao loop mais interno para ir do início ao fim do v3
    int i, j, k = 0;
    for (i = 0; i < tamV1; i++)
        for (j = 0; j < tamV2; j++, k++)
            v3[k] = v1[i] * v2[j];

    printVetor(v1, "v1", tamV1);
    printVetor(v2, "v2", tamV2);
    printVetor(v3, "v3", tamV3);

    // libera o espaço alocado para cada vetor
    free(v1);
    free(v2);
    free(v3);

    return 0;
}