int isLetra(char c);

/**
 * Conta a quantidade de palavras em uma string
 * Considera como espaço entre palavras tudo o que não for uma letra
 * 
 * @param char *str - o vetor de chars que representa a string
 * @return A quantidade de palavras na string
 * 
 * @author Dahan Schuster
 */
int contarPalavras(char *str)
{
    int i, qtePalavras = 0;

    char cAtual = str[0],
         cProximo;

    for (i = 0; str[i] != '\0'; i++)
    {
        cProximo = str[i + 1];
     
        if (isLetra(cAtual) && !isLetra(cProximo))
            qtePalavras++;

        cAtual = cProximo;
    }

    return qtePalavras;
}

/**
 * Verifica se um dado char é uma letra [aA-zZ]
 * 
 * @param char c - o char a ser verificado
 * @return 1 se c for uma letra, 0 do contrário
 * 
 * @author Dahan Schuster
 */
int isLetra(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}