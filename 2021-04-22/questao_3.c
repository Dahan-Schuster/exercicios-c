#include <stdlib.h>
#include <stdio.h>

/**
 * Recebe um buffer contendo uma string e retorna um
 * vetor com memória dinamicamente alocada com o
 * tamanho específico da string dentro do buffer
 * 
 * @param char* string - o buffer contendo uma string
 * @return char* - a string comprimida
 * @author Dahan Schuster
 */
char *empacotaString(char *string)
{
    int tam;
    for (tam = 0; string[tam] != '\0'; tam++);
        
    char *stringPontoZip = (char *)malloc(sizeof(char) * tam);

    int i;
    for (i = 0; i < tam; i++)
        stringPontoZip[i] = string[i];

    return stringPontoZip;    
}

int main()
{
    char buffer[BUFSIZ];
    fgets(buffer, BUFSIZ, stdin);

    char *stringPontoZip = empacotaString(buffer);

    printf("%s\n", stringPontoZip);

    free(stringPontoZip);

    return 0;
}