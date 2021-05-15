#include "diretivas.h"
#include "jogador.h"

void moverJogador(
    char movimento,
    char **t,
    int lins,
    int cols,
    int *iAtual,
    int *jAtual,
    int *qteEsmeraldas,
    int *movimentos)
{
    if ((movimento == CIMA && (*iAtual) > 0) ||
        (movimento == BAIXO && (*iAtual) < lins - 1) ||
        (movimento == ESQUERDA && (*jAtual) > 0) ||
        (movimento == DIREITA && (*jAtual) < cols - 1))
    {
        (*movimentos)++;

        t[(*iAtual)][(*jAtual)] = 0;

        if (movimento == CIMA)
            (*iAtual)--;
        else if (movimento == BAIXO)
            (*iAtual)++;
        else if (movimento == ESQUERDA)
            (*jAtual)--;
        else
            (*jAtual)++;

        // haviam esmeraldas aqui...
        if (t[(*iAtual)][(*jAtual)] != 0)
            *qteEsmeraldas -= t[(*iAtual)][(*jAtual)];

        t[(*iAtual)][(*jAtual)] = JOGADOR;
    }
}
