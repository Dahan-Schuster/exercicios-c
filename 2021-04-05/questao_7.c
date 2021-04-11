#include <stdio.h>

/**
 * Lê n números e verifica se a sequência formada por eles é composta 
 * alternadamente por segmentos de tamanho k de números pares e ímpares
 * Ex.: "1 3 2 4 5 7" é 2-alternante, pois alterna entre 2 ímpares e 2 pares
 * 
 * @author Dahan Schuster
 */
int isSequenciaKAlternante(int tamanho, int *k)
{
    int i;
    
    // número lido em cada iteração
    int n;

    // lê o primeiro número da sequência e guarda a informação de se ele é par
    scanf("%d", &n);
    int isUltimoNumeroPar = n % 2 == 0;

    int isNumeroAtualPar;

    // Guarda o tamanho do segmento atual de números pares ou ímpares
    int tamSegmentoAtual = 1;

    // Inicializa *k com valor 0, que também representa false
    // Caso *k == true, um valor para *k já foi definido, ou seja, o tamanho de
    // um segmento já foi calculado e todos os outros devem ter o mesmo tamanho
    // Do contrário, a sequência não é k-alternante
    *k = 0;

    for (i = 0; i < tamanho - 1; i++)
    {
        // Lê um novo número por iteração
        scanf("%d", &n);
        isNumeroAtualPar = n % 2 == 0;

        // Verifica se ambos os números são pares ou ímpares
        if (isNumeroAtualPar == isUltimoNumeroPar)
            tamSegmentoAtual++; // se sim, o segmento apenas cresce
        else                    // se não, é hora de verificar a k-alternância
        {
            // se já foi definido um valor para k e ele é diferente do tamanho
            // do último segmento calculado, então a sequência não é k-alt
            if (*k && tamSegmentoAtual != *k)
            {
                *k = 0;
                return 0;
            }

            // se nenhum valor de k foi definido, ou se os segmentos até agora
            // tiveram o mesmo tamanho k, continua verificando
            *k = tamSegmentoAtual;

            // redefine o tamanho do segmento
            tamSegmentoAtual = 1;
        }

        isUltimoNumeroPar = isNumeroAtualPar;
    }
    
    // garante que o valor de k será atualizado mesmo que a sequência não tenha
    // alternado em nenhum momento (nesse caso, k == tamanho)
    *k = tamSegmentoAtual;

    // se a função não retornou 0 em nenhum momento, a sequência é k-alternante
    return 1;
}

#define N 3

int main()
{

    int k;
    int k_alternante = isSequenciaKAlternante(N, &k);
    printf("%d, %d\n", k_alternante, k);

    return 0;
}