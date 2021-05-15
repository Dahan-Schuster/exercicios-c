/*============================================================================*/
/* CSF13 - 2020.2 - Lista 21 - Questão5 5: Jogo Caçador de Esmeraldas         */
/*----------------------------------------------------------------------------*/
/* Dahan Schuster                                                             */
/*============================================================================*/

#ifndef _MAIN_H
#define _MAIN_H

char lerProximoMovimento();
void getConfiguracoesIniciais(
    int *lins, int *cols, int *qteEsmeraldas, int isPrimeiraPartida);
void imprimirEstadoAtual(char **t, int lins, int cols, int recorde, int mov);
void finalizarPartida(int movimentos, int *recorde);

#endif /* _MAIN_H */