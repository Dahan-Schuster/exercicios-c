/**
 * Retorna a posição de um número no vetor de n posições,
 * ou -1 se o número não for encontrado
 * 
 * @author Dahan Schuster
 */
int buscaVetor(int *vetor, int n, int procurado)
{
    int i;
    for (i = 0; i < n; i++)
        if (procurado == vetor[i])
            return i;
    
    return -1;
}