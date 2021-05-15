#include <stdio.h>

#include "diretivas.h"
#include "tabuleiro.h"
#include "tabuleiro.h"

void imprimirTabuleiro(char **t, int lins, int cols)
{
    int i, j;

    for (i = 0; i < lins; i++)
    {
        for (j = 0; j < cols; j++)
            printf("----");
        printf("-\n");

        for (j = 0; j < cols; j++)
        {
            if (t[i][j] == JOGADOR)
                printf("| %c ", t[i][j]);
            else if (t[i][j] != 0)
                printf("| %d ", t[i][j]);
            else
                printf("|   ");
        }

        printf("|\n");
    }

    for (i = 0; i < cols; i++)
        printf("----");
    printf("-\n");
}

char **criarTabuleiro(int lins, int cols, int qteEsmeraldas)
{
    srand(time(0));

    char **tabuleiro = (char **)malloc(lins * sizeof(char *));
    int i;
    for (i = 0; i < lins; i++)
        tabuleiro[i] = (char *)calloc(cols, sizeof(char));

    tabuleiro[0][0] = JOGADOR;
    posicionarEsmeraldas(tabuleiro, lins, cols, qteEsmeraldas);

    return tabuleiro;
}

void posicionarEsmeraldas(char **t, int lins, int cols, int qteEsmeraldas)
{
    int i, randLinha, randColuna;
    for (i = 0; i < qteEsmeraldas; i++)
    {
        randLinha = rand() % (lins - 1) + 1;
        randColuna = rand() % (cols - 1) + 1;

        t[randLinha][randColuna]++;
    }
}

void destruirTabuleiro(char **t, int lins)
{
    int i;
    for (i = 0; i < lins; i++)
        free(t[i]);

    free(t);
}
