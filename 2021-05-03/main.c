#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_21.h"

#include "questao_1.c"
#include "questao_2.c"

// sempre descomentar apenas 1, pois a função criarVetor conflita
// #include "questao_4.c"
#include "../utils.c"

#define GRAU 8

#define NL 3
#define NC 4

void testarQuestoes1e2();
void testarQuestao4();

int main()
{
    testarQuestoes1e2();
    return 0;
}

void testarQuestoes1e2() {
    int **triPascal = geraTrianguloDePascal(GRAU);
    printDinMatrizInt(GRAU, GRAU, triPascal);
    destroiTrianguloDePascal(triPascal, GRAU);
}

#ifndef ROLAGENS
#define ROLAGENS 100
#endif

void testarQuestao4()
{
    srand(time(0));
    int ***in = (int ***)malloc(NL * sizeof(int **));

    int i, j, k;
    for (i = 0; i < NL; i++)
    {
        in[i] = (int **)malloc(NC * sizeof(int *));
        for (j = 0; j < NC; j++)
        {
            in[i][j] = (int *)malloc(ROLAGENS * sizeof(int));
            for (k = 0; k < ROLAGENS; k++)
            {
                in[i][j][k] = rand() % 6 + 1;
            }
        }
    }

    int **out = (int **)malloc(NL * sizeof(int *));
    for (i = 0; i < NL; i++)
        out[i] = (int *)malloc(NC * sizeof(int));

    // int x = analisa(in, NC, NL, out);
    // printf("%d\n", x);

    // for (i = 0; i < NL; i++)
    // {
    //     for (j = 0; j < NC; j++)
    //         printf("%d, ", out[i][j]);
    //     printf("\n");
    // }
}