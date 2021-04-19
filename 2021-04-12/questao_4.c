#define TAM_ALFBT 26

/**
 * Mostra a quantidade de cada caracter em uma string
 * 
 * @author Dahan Schuster
 * 
 */
void contaCaracteres(char *str)
{
    // cria um vetor do tamanho do alfabeto inicializado com zeros
    int ocorrencias[TAM_ALFBT] = {0};

    // guarda a posição referente ao char no vetor de ocorrências
    // Ex.: aA -> 0; bB -> 1; zZ -> 25 
    int posicaoChar = 0;
    
    int i;
    // para cada char != null na string... 
    for (i = 0; str[i] != '\0'; i++)
    {
        // verifica se o char é uma letra maiúscula
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            // a posição do char no vetor de ocorrências será a diferença entre
            // ele e a letra 'A' na tabela ASCII
            posicaoChar = str[i] - 'A';
            
            // incrementa a quantidade de ocorrências do char
            ocorrencias[posicaoChar]++;
        }
        // verifica se o char é uma letra minúscula
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            // segue a mesma lógica, porém considerando o alfabeto minúsculo
            posicaoChar = str[i] - 'a';
            ocorrencias[posicaoChar]++; // 'A' terá a mesma posição que 'a'
        }
    }

    /* Após a contagem, imprime os resultados */ 

    // imprime os dados em duas colunas
    int metade = TAM_ALFBT / 2;
    for (i = 0; i < metade; i++) {
        printf("%c: %d\t", i + 'A', ocorrencias[i]);
        printf("%c: %d\n", i + 'A' + metade, ocorrencias[i + metade]);
    }
}