/*============================================================================*/
/* CSF13 - 2020.2 - Lista 21 - Questão5 5: Jogo Caçador de Esmeraldas         */
/*----------------------------------------------------------------------------*/
/* Dahan Schuster                                                             */
/*============================================================================*/

#ifndef _JOGADOR_H
#define _JOGADOR_H

void moverJogador(
    char movimento,
    char **t,
    int lins,
    int cols,
    int *iAtual,
    int *jAtual,
    int *qteEsmeraldas,
    int *movimentos);

#endif /* _JOGADOR_H */