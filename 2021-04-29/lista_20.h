/*============================================================================*/
/* CSF13 - 2020.2 - Lista 20                                                  */
/*----------------------------------------------------------------------------*/
/* Dahan Schuster                                                             */
/*============================================================================*/

#ifndef _LISTA_20_H_
#define _LISTA_20_H_

#define N 3
#define NL 5
#define NC 5

int contemElementoRepetido(int matriz[][NC], int lins, int cols);
int ehSimetrica (int matriz [N][N], int tam);

void geraMatrizInca (int matriz [N][N]);
int isPalindromoPerfeito(char matriz[][NC], int tam);

void printMatrizEspelhada(char matriz[][NC], int lins, int cols);
void geraMatrizEspelhada(
    char matriz[][NC],
    char matriz_espelho[NL * 2][NC * 2],
    int lins,
    int cols);

#endif /* _LISTA_20_H_ */