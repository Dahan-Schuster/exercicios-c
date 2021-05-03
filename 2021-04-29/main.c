#include <stdio.h>
#include "lista_20.h"

#include "questao_1.c"
#include "questao_2.c"
#include "questao_4.c"
#include "questao_5.c"

#include "../utils.c"

int main()
{
    int m1[NL][NC] = {{2, 4, 7}, {1, 0, 1}};
    int m2[N][N] = {{0, 2, 3},
                    {2, 1, 4},
                    {3, 4, 7}};

    char m5[NL][NC] = {{'A', 'B', 'C', 'D', 'E'},
                       {' ', 'B', 'C', 'D', 'E'},
                       {' ', ' ', 'C', 'D', 'E'},
                       {' ', ' ', ' ', 'D', 'E'},
                       {' ', ' ', ' ', ' ', 'E'}};
    char m5b[NL * 2][NC * 2];

    char m4[NC][NC] = {{'S', 'A', 'T', 'O', 'R'},
                       {'A', 'R', 'E', 'P', 'O'},
                       {'T', 'E', 'N', 'E', 'T'},
                       {'O', 'P', 'E', 'R', 'A'},
                       {'R', 'O', 'T', 'A', 'S'}};

    // int x = ehSimetrica(m2);
    // int x = contemElementoRepetido(m1, 2, 3);
    int x = isPalindromoPerfeito(m4, 5);
    printf("%d\n", x);

    // geraMatrizEspelhada(m5, m5b, 5, 5);
    // printMatrizEspelhada(m5b, 10, 10);

    // printMatrizChar(NL, NC, m5);

    return 0;
}