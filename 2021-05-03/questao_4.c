#include <stdlib.h>
#include "lista_21.h"

#define MIN 15
#define MAX 18

#define FACES 6
#define ROLAGENS 100

int *criarVetor(int tamanho)
{
    return (int *)calloc(tamanho, sizeof(int));
}

/**
 * Verifica se todos os valores [1, FACES] de um dado foram sorteados
 * dentro do intervalo [MIN, MAX] após n rolagens
 * 
 * As diretivas FACES, MIN e MAX determinam, respectivamente, a quantidade de
 * faces de cada dado e os limites mín e máx de ocorrências de cada valor
 * 
 * @param int* rolagens - o vetor de rolagens do dado
 * @param int qteRolagens - quantas vezes cada dado foi jogado
 * @return 1 caso o dado seja aprovado, 0 do contrário 
 * @author Dahan Schuster
 */
int validarDado(int *rolagens, int qteRolagens)
{
    // o vetor valores associa cada valor do dado ao seu índice + 1
    int i, valores[FACES] = {0};

    // incrementa as ocorrências de cada valor enquanto itera pelas rolagens
    for (i = 0; i < qteRolagens; i++)
        valores[rolagens[i] - 1]++;

    // valida a quantidade de ocorrências de cada valor
    for (i = 0; i < FACES; i++)
        if (valores[i] < MIN || valores[i] > MAX)
            return 0;

    return 1;
}

/**
 * Valida todos os dados na matriz in e verifica a existência de
 * erros de alinhamento ou produção
 * 
 * @param int*** in - matriz 3d: cada elemento [i][j] é um vetor de 100 posições
 * @param int largura - quantidade de colunas na matriz
 * @param int altura - quantidade de linhas na matriz
 * @param int** out - matriz 2d: cada elemento [i][j] informa se o dado nesta
 * posição é válido
 * @return 1 se for detectado um erro de produção ou alinhamento da máquina
 *         0 do contrário
 * @author Dahan Schuster
 */
int analisa(int ***in, int largura, int altura, int **out)
{
    int erroDetectado = 0;

    int *errosPorLinha = criarVetor(altura),
        *errosPorColuna = criarVetor(largura);

    int maxErrosPorLinha = largura / 2,
        maxErrosPorColuna = altura / 2;

    int i, j, k, dadoValido;
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            dadoValido = validarDado(in[i][j], ROLAGENS);
            out[i][j] = dadoValido;

            if (!dadoValido)
            {
                errosPorLinha[i]++;
                errosPorColuna[j]++;

                if (errosPorColuna[j] >= maxErrosPorColuna)
                    erroDetectado = 1;
            }
        }

        if (errosPorLinha[i] >= maxErrosPorLinha)
            erroDetectado = 1;
    }

    return erroDetectado;
}