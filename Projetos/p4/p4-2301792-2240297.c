/*============================================================================*/
/* CSF13 - 2020-2 - PROJETO 4                                                 */
/*----------------------------------------------------------------------------*/
/* Gabriel Franco - 2240297                                                   */
/* Dahan Schuster - 2301792                                                   */
/*============================================================================*/
/** Funções pedidas para o 4º projeto da disciplina Fundamentos de Programação
 * 1, 2º semestre de 2020, prof. Bogdan T. Nassu e Leyza E. B. Dorini,
 * Universidade Tecnológica Federal do Paraná.
/*============================================================================*/

#include <stdio.h>
#include <math.h>
#include "projeto4.h"

#define L 1

/**
 * Altera o ganho de uma dada faixa de áudio multiplicando
 * cada amostra por um mesmo valor
 * 
 * @param double dados - o vetor de amostras do áudio
 * @param int n_amostras - o número de amostras
 * @param double - o valor pelo qual cada amostra deve ser multiplicado
 * 
 * @author Grabiel Franco
 * @author Dahan Schuster
 */
void mudaGanho(double *dados, int n_amostras, double ganho)
{
    int i;

    // Multiplica pelo ganho cada valor do vetor
    for (i = 0; i < n_amostras; i++)
        dados[i] = dados[i] * ganho;
}

/**
 * Percorre uma série de amostras de um áudio e retorna a quantidade
 * de valores que passaram do limite absoluto 
 * 
 * @param double dados - o vetor de amostras do áudio
 * @param int n_amostras - o número de amostras
 * @return int - a quantidade de amostras saturadas
 *
 * @author Grabiel Franco
 * @author Dahan Schuster
 */
int contaSaturacoes(double *dados, int n_amostras)
{

    int i, saturados = 0;

    //Percorre o vetor e soma se for saturado
    for (i = 0; i < n_amostras; i++)
        if (dados[i] > L || dados[i] < -L)
            saturados++;

    return saturados;
}

/**
 * Satura uma faixa de áudio com a técnica hard clipping: limita todas
 * as amostras a um limite absoluto
 * 
 * @param double dados - o vetor de amostras do áudio
 * @param int n_amostras - o número de amostras
 * @param int limite - o valor máximo absoluto
 * @return int - a quantidade de amostras saturadas
 *
 * @author Grabiel Franco
 * @author Dahan Schuster
 */
int hardClipping(double *dados, int n_amostras, double limite)
{
    int i, modificadas = 0;

    for (i = 0; i < n_amostras; i++)

        //Só entra se for saturado
        if (fabs(dados[i]) > fabs(limite))
        {
            //Se a amostra tiver mesmo sinal que o limite então amostra recebe limite
            if ((dados[i] < 0 && limite < 0) || (dados[i] > 0 && limite > 0))
                dados[i] = limite;
            //Senão recebe o valor inverso
            else
                dados[i] = -limite;

            modificadas++;
        }

    return modificadas;
}

/**
 * 
 * Aplica um limiter numa dada faixa de áudio, ajustando sempre n_passos à
 * esquerda e direita de cada pico que ultrapasse o limite constante L 
 * 
 * @param double dados - o vetor de amostras do áudio
 * @param int n_amostras - o número de amostras
 * @param int n_passos - a quantidade de ítens à esquerda e direita de um pico
 * para aplicar o limiter
 *
 * @author Grabiel Franco
 * @author Dahan Schuster
 */
void limitaSinal(double *dados, int n_amostras, int n_passos)
{
    int i, j;
    double ganho, var_ganho;

    for (i = 0; i < n_amostras; i++)
    {
        //Entra se for saturado
        if (fabs(dados[i]) > L)
        {
            //ganho necessário para esse valor ser igual ao
            // limite L (1)
            ganho = L / dados[i];

            //variação de ganho necessária para que depois
            //de n_passos + 1, o ganho seja 1
            var_ganho = (1 - ganho) / (n_passos + 1);

            //Multiplica pelo ganho para entrar no limite
            dados[i] *= ganho;

            //Vai multplicar para os vizinhos
            for (j = 1; j <= n_passos; j++)
            {
                //Atualiza ganho
                ganho += var_ganho;

                //Multiplica os anteriores
                if (i - j >= 0)
                    dados[i - j] *= ganho;

                //Multiplica os próximos
                if (i + j <= n_amostras)
                    dados[i + j] *= ganho;
            }
        }
    }
}

/**
 * Gera uma onda quadrada (amostras = {1, -1}) a partir da taxa de amostragem e
 * da frequência dadas
 * 
 * @param double dados - o vetor de amostras do áudio
 * @param int n_amostras - o número de amostras a gerar
 * @param int taxa - taxa de amostragem, em Hz
 * @param double freq - frequência da onda, em Hz
 *
 * @author Grabiel Franco
 * @author Dahan Schuster
 */
void geraOndaQuadrada(double *dados, int n_amostras, int taxa, double freq)
{
    // a quantidade de períodos (crista+vale) dentro da faixa
    double periodo = taxa / freq;
    double meio_periodo = periodo / 2;
    double ciclos = n_amostras / periodo;

    // i - conta os ciclos passados
    // j - conta as amostras passadas dentro de um meio-período
    // k - conta o total de amostras geradas
    int i, j, k = 0;

    // o valor que será dado a cada amostra dentro de um meio-período
    int valor_amostra = 1;

    // A diferença entre o valor arredondado do meio-período e o original
    double diferenca = meio_periodo - ((int)meio_periodo);

    // Quantidade de amostras no meio-período
    // Varia a cada período de acordo com a variável diferenca
    double amostras = meio_periodo;

    // o cálculo do núḿero de amostras no meio-período
    // soma ou subtrai a variável diferenca
    int sinalSoma = -1;

    // Itera pelo dobro de ciclos, pois preenche sempre
    // meio-período a cada loop
    // O primeiro meio-período do ciclo terá o valor da
    // quantidade de amostras arrendondado para baixo
    // Já o segundo terá o valor arrendado para cima
    for (i = 0; i < 2 * ciclos; i++)
    {
        // soma ou subtrai a var diferenca
        // em caso de valores decimais, amostras terá
        // o valor arrendondado para baixo quando sinalSoma = -1,
        // e será igual ao meio_periodo quando sinalSoma = 1
        amostras = meio_periodo + (sinalSoma * diferenca);

        // caso o meio-período seja um valor decimal,
        // amostras será arredondado para cima
        if (sinalSoma > 0 && diferenca != 0)
            amostras = ((int)amostras) + 1;

        // Preenche o meio-período com as amostras de valor 1 ou -1
        for (j = 0; j < amostras; j++, k++)
            dados[k] = valor_amostra;

        // inverte o valor da amostra e do sinal da soma
        valor_amostra *= -1;
        sinalSoma *= -1;
    }
}
