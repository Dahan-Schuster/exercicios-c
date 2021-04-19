/**
 * Itera por uma string e retorna se a mesma é um palíndromo
 * Recebe como parâmetro o ponteiro do vetor string e o tamanho máximo
 * do vetor, que pode ser definido por uma diretiva, para evitar seg faults
 * 
 * Retorna 1 se for palíndromo, 0 do contrário
 * 
 * @author Dahan Schuster
 */
int isPalindromo(char *str, int buffSize)
{
    int i, j;
    int tamStr = 0;

    // conta o tamanho da string
    for (i = 0; str[i] != '\0' && i < buffSize; i++)
        tamStr = i + 1;

    // itera de forma simultânea partindo do início e do fim da string
    // se os chars espelhados forem diferentes entre si, não é palíndromo
    for (i = 0, j = tamStr - 1;
         i < tamStr && j >= 0;
         i++, j--)
        if (str[i] != str[j])
            return 0;

    return 1;
}