/**
 * Copia os elementos de v1 em v2 sem repetição
 * 
 * @param int *v1 - o vetor original
 * @param int *v2 - o vetor destino
 * @return int - A quantidade de elementos inseridos em v2
 * 
 * @author Dahan Schuster
 */
int removerElementosRepetidos(int *v1, int *v2, int n)
{

    int i, j;
    int elRepetido;
    int tamV2 = 0;

    for (i = 0; i < n; i++)
    {
        elRepetido = 0;

        // verifica se v1[i] está entre os elementos já inseridos em v2
        for (j = 0; j < tamV2 && !elRepetido; j++)
            elRepetido = v2[j] == v1[i];

        // se não, colocamos v1[i] na próxima posição de v2
        if (!elRepetido) {
            v2[tamV2] = v1[i];
            tamV2++;
        }
        
    }
    
    return tamV2;
}