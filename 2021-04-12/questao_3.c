/**
 * Receve um vetor de inteiros e retorna 1 se os valores estiverem em 
 * ordem estritamente crescente, ou 0 do contrário
 * 
 * @author Dahan Schuster
 */
int isEstritCrescente(int *vetor, int tam)
{
    int i;
    for (i = 1; i < tam; i++)
        if (vetor[i] <= vetor[i - 1])
            return 0;

    return 1;
}