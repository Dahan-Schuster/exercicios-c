#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "diretivas.h"
#include "main.h"

#include "tabuleiro.c"
#include "jogador.c"

/**
 * Jogo: Caçador de Esmeraldas
 * 
 * @author Dahan Schuster
 */
int main()
{
    // define o tamanho do tabuleiro e a quantidade de esmeraldas
    int lins, cols, qteEsmeraldas;
    getConfiguracoesIniciais(&lins, &cols, &qteEsmeraldas, 0);

    // cria as variáveis de estado do jogo
    int recorde = 0, movimentos, iAtual, jAtual, esmeraldasRestantes;
    char proxMovimento = 0;

    // enquanto o jogador informar valores positivos para a 
    while (lins > 0 && cols > 0 && qteEsmeraldas > 0)
    {
        /* INÍCIO DA PARTIDA */

        // cria um novo tabuleiro e reseta o estado
        char **tabuleiro = criarTabuleiro(lins, cols, qteEsmeraldas);
        movimentos = iAtual = jAtual = 0;
        esmeraldasRestantes = qteEsmeraldas;

        while (esmeraldasRestantes > 0)
        {
            while (proxMovimento == 0)
            {
                imprimirEstadoAtual(tabuleiro, lins, cols, recorde, movimentos);
                proxMovimento = lerProximoMovimento();
            }

            // processa as regras de movimento do jogador
            moverJogador(
                proxMovimento,
                tabuleiro,
                lins,
                cols,
                &iAtual,
                &jAtual,
                &esmeraldasRestantes,
                &movimentos);

            // redefine o valor do próximo movimento
            proxMovimento = 0;
        }

        // o jogador venceu

        imprimirEstadoAtual(tabuleiro, lins, cols, recorde, movimentos);
        finalizarPartida(movimentos, &recorde);
        destruirTabuleiro(tabuleiro, lins);

        /* FIM DA PARTIDA */

        // Reinicia o jogo
        getConfiguracoesIniciais(&lins, &cols, &qteEsmeraldas, 1);
    }

    return 0;
}

void getConfiguracoesIniciais(
    int *lins, int *cols, int *qteEsmeraldas, int isPrimeiraPartida)
{
    if (isPrimeiraPartida)
        printf("Informe novas configurações para jogar novamente\n");
    else
        printf("Informe as configurações da primeira partida\n");
    
    printf("Informar 0 encerra o jogo\n");

    printf("Nº de linhas: ");
    scanf("%d", lins);
    if (*lins <= 0)
        return;

    printf("Nº de colunas: ");
    scanf("%d", cols);
    if (*cols <= 0)
        return;

    printf("Nº de esmeraldas: ");
    scanf("%d", qteEsmeraldas);
}

char lerProximoMovimento()
{
    char c;

    printf("Próximo movimento: ");
    c = getchar();
    fflush(0);

    if (c != CIMA && c != BAIXO && c != ESQUERDA && c != DIREITA)
        return 0;

    return c;
}

void imprimirEstadoAtual(char **t, int lins, int cols, int recorde, int mov)
{
    system("clear");
    imprimirTabuleiro(t, lins, cols);
    printf("Melhor desempenho: %d\n", recorde);
    printf("Movimentos: %d\n", mov);
}

void finalizarPartida(int movimentos, int *recorde)
{
    printf("\nParabéns! Você ganhou!\n");

    if (movimentos < *recorde || *recorde == 0)
    {
        *recorde = movimentos;
        printf("Seu novo recorde é de %d movimentos\n", *recorde);
    }
}
