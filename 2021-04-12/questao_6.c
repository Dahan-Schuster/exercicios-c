/**
 * Troca R por L numa string e armazena a string modificada num buffer
 * Recebe a string original, o buffer e o tamanho da string
 * 
 * @author Dahan Schuster 
 */
void stling(char *str, char *buf, int tam)
{
    int i;
    for (i = 0; i < tam - 1; i++)
    {
        buf[i] = str[i]; // preenche o buffer com as letras da string

        // se a letra atual for um 'r'
        if (str[i + 1] != ' ' && (str[i] == 'R' || str[i] == 'r'))
        {
            // troca o 'r' por 'l', mantendo maiúsculas e minúsculas
            buf[i] = (str[i] == 'R') ? 'L' : 'l';

            // verifica se a próxima letra também é um 'r'
            if (str[i + 1] == 'R' || str[i + 1] == 'r')
                i += 1; // pula mais uma letra, pois trocamos rr por l
        }
    }

    // Preenche a última letra do buffer, uma vez que o loop vai até i < tam - 1
    // para evitar segmentation fault nos acessos a str[i + 1]
    buf[tam - 1] = str[tam - 1];
}