/**
 * Reverte uma string dada
 * 
 * @param char *str - o vetor de chars que representa a string
 * @return void - Manipula a string por referência
 * 
 * @author Dahan Schuster
 */
void reverterString(char *str)
{

    int tam;
    for (tam = 0; str[tam] != '\0'; tam++); // conta o tamanho da string

    int i, j;
    char aux;

    // Faz o loop pela direita e esquerda ao mesmo tempo, até o meio da string
    // Substitui o valor da esquerda pelo da direita e vice-versa
    for (i = 0, j = tam - 1; i < tam / 2 && j > tam / 2; i++, j--)
    {
        // substituição básica de valores usando um auxiliar
        aux = str[j];
        str[j] = str[i];
        str[i] = aux;
    }
}