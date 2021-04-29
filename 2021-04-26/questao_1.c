#include <stdio.h>

#define N_LINHAS 7
#define N_COLUNAS 5

/**
 * Preenche e imprime uma matriz em formato de tabela
 * 
 * @author Dahan Schuster
 */
int main()
{
    int m[N_LINHAS][N_COLUNAS];
    
    int i, j;

    // imprime os índices das colunas no cabeçalho da tabela
    printf("    |");
    for (j = 0; j < N_COLUNAS; j++)
        printf(" %02d |", j);
    printf("\n-----");

    // imprime uma separação entre o cabeçalho e o corpo da tabela
    for (j = 0; j < N_COLUNAS; j++)
        printf("-----");
    printf("\n");

    // imprime o corpo da tabela
    for (i = 0; i < N_LINHAS; i++) {
        // imprime o índice da linha em cada loop
        printf(" %02d |", i);
        
        // define o valor do elemento m[i][j] e o imprime
        for (j = 0; j < N_COLUNAS; j++) {
            m[i][j] = i * j;
            printf(" %02d ,", m[i][j]);
        }
        
        printf("\n");
    }


    return (0);
}

/**
 *        Teste de mesa:
 * 
 *   | 00 | 01 | 02 | 03 | 04
 * --------------------------
 * 0 | 00 , 00 , 00 , 00 , 00
 * 1 | 00 , 01 , 02 , 03 , 04
 * 2 | 00 , 02 , 04 , 06 , 08
 * 3 | 00 , 03 , 06 , 09 , 12
 * 4 | 00 , 04 , 08 , 12 , 16
 * 5 | 00 , 05 , 10 , 15 , 20
 * 6 | 00 , 06 , 12 , 18 , 24
 * 
 */