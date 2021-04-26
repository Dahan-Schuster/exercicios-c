/**
 * Retorna o tamanho da maior sequência não drescente em um vetor de inteiros
 * 
 * @param int *val - o vetor de inteiros
 * @param int n - o tamanho do vetor
 * @param int *inicio - ponteiro para uma variável que guarda o índice do início
 * da sequência
 * @param int *fim - ponteiro para uma variável que guarda o índice do fim da
 * sequência
 * 
 * @return int - O tamanho da maior sequência
 * 
 * @author Dahan Schuster
 */
int tamMaiorSeqNDec(int *val, int n, int *inicio, int *fim)
{
    int tamSeq = 1, // o tamanho de cada sequência
        tamMaiorSeq = 0, // o tamanho da maior sequência
        inicioUltimaSeq = 0, // o ínidice no qual a última sequência começou
        atual = val[0], // o valor do índice i do vetor
        proximo,        // o valor do índice i+1 do vetor
        i;

    // o loop vai até o final do vetor
    for (i = 0; i < n; i++)
    {
        // caso estejamos no final do vetor, não podemos acessar v[i+1]
        proximo = i + 1 < n ? val[i + 1] : 0;

        // verifica se i + 1 não ultrapassa o último índice e se valor atual
        // é menor que o próximo 
        if (i + 1 < n && proximo >= atual) {
            if (tamSeq == 1)         // se estiver iniciando uma nova sequência
                inicioUltimaSeq = i; // guarda o valor do índice

            tamSeq++;

        }
        // caso seja a última iteração (i + 1 == n), ou a sequência tenha sido
        // quebrada, atualiza os contadores
        else
        {
            if (tamSeq > tamMaiorSeq) {
                tamMaiorSeq = tamSeq;
                *inicio = inicioUltimaSeq;
                *fim = i;
            }

            tamSeq = 1;
        }

        atual = proximo;
    }

    return tamMaiorSeq;
}