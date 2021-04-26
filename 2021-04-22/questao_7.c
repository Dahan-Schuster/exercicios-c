#include <stdlib.h>
#include <stdio.h>

/**
 * Recebe um buffer contendo uma string e retorna a string comprimida
 * 
 * Versão modificada da original (questao_3.c), para remover a quebra
 * de linha (\n)
 * 
 * @param char* string - o buffer contendo uma string
 * @return char* - a string comprimida
 * @author Dahan Schuster
 */
char *empacotaString(char *string)
{
    int tam;
    for (tam = 0; string[tam] != '\n'; tam++);

    tam++; // adiciona um espaço para o char nulo (\0) 
    char *stringPontoZip = (char *)malloc(sizeof(char) * tam);

    int i;
    for (i = 0; i < tam - 1; i++)
        stringPontoZip[i] = string[i];
    
    stringPontoZip[tam-1] = '\0';
    return stringPontoZip;    
}
/**
 * Lê e imprime strings na saída padrão,
 * mostrando sempre apenas as últimas três 
 * 
 * @author Dahan Schuster
 */
int main()
{
    // cria um buffer padrão
    char buffer[BUFSIZ];

    /* leitura das três string principais */

    fgets(buffer, BUFSIZ, stdin);
    char *string1 = empacotaString(buffer);

    fgets(buffer, BUFSIZ, stdin);
    char *string2 = empacotaString(buffer);

    fgets(buffer, BUFSIZ, stdin);
    char *string3 = empacotaString(buffer);

    // a string3 sempre armazenará a última lida
    // continua a ler até que o usuário insira uma string vazia
    while (string3[0] != '\0')
    {
        // limpa o console a cada loop
        system("clear");
        // imprime as três últimas strings lidas
        printf("%s\n%s\n%s\n", string1, string2, string3);

        // move os valores uma posição para trás
        string1 = string2;
        string2 = string3;
        
        // lê uma nova string
        fgets(buffer, BUFSIZ, stdin);
        string3 = empacotaString(buffer);
    }

    return 0;
}