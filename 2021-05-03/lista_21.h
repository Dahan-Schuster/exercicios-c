/*============================================================================*/
/* CSF13 - 2020.2 - Lista 21                                                  */
/*----------------------------------------------------------------------------*/
/* Dahan Schuster                                                             */
/*============================================================================*/

#ifndef _LISTA_21_H_
#define _LISTA_21_H_

int** geraTrianguloDePascal (int grau);

void destroiTrianguloDePascal (int** t, int grau);

int validarDado(int *rolagens, int qteRolagens);
int analisa(int ***in, int largura, int altura, int **out);

#endif /* _LISTA_21_H_ */