/*============================================================================*/
/* CSF13 - 2020.2 - Lista 21 - Questão5 5: Jogo Caçador de Esmeraldas         */
/*----------------------------------------------------------------------------*/
/* Dahan Schuster                                                             */
/*============================================================================*/

#ifndef _TABULEIRO_H
#define _TABULEIRO_H

void imprimirTabuleiro(char **t, int lins, int cols);
char **criarTabuleiro(int lins, int cols, int qteEsmeraldas);
void posicionarEsmeraldas(char **t, int lins, int cols, int qteEsmeraldas);
void destruirTabuleiro(char **t, int lins);

#endif /* _TABULEIRO_H */