/**
 * Verifica o tipo de um dado caractere, verificando seu valor numérico na
 * tabela ASCII
 * 
 * @return 1 se c for uma vogal maiúscula
 * @return 2 se c for uma vogal minúscula
 * 
 * @return 3 se c for uma consoante maiúscula
 * @return 4 se c for uma consoante minúscula
 * 
 * @return 5 se c for um dígito
 * 
 * @author Dahan Schuster
 */
int testaTipoChar (char c)
{
    if (c >= 65 && c <= 90) // c é uma letra maiúscula
    {
        // verifica se c é uma das 5 vogais maiúsculas
        if (c == 65 || c == 69 || c == 73 || c == 79 || c == 85)
            return 1;
        // se não, c é uma consoante maiúscula
        else
            return 3;
    }
    else if (c >= 97 && c <= 122) // c é uma letra minúscula
    {
        // verifica se c é uma das 5 vogais minúsculas
        if (c == 97 || c == 101 || c == 105 || c == 111 || c == 117)
            return 2;
        // se não, c é uma consoante minúscula
        else
            return 4;
    }
    else if (c >= 48 && c <= 57) // c é um dígito
    {
        return 5;
    }
}