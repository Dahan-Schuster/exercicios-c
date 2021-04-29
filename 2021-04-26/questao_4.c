#include <stdio.h>
#include <string.h>

#define N_STRINGS 4
#define TAM_STRING 128

/**
 * Lê N strings e às imprime na ordem inversa à lida
 * 
 * @author Dahan Schuster
 */
int main()
{

    char strings[N_STRINGS][TAM_STRING];

    int i, j, tam;
    for (i = 0; i < N_STRINGS; i++)
    {
        fgets(strings[i], TAM_STRING, stdin);

        // Troca o caractere de quebra de linha da string pelo char nulo
        tam = strlen(strings[i]);
        strings[i][tam - 1] = '\0';
    }

    printf("\n");

    for (i = N_STRINGS - 1; i >= 0; i--)
        printf("%s\n", strings[i]);

    return (0);
}