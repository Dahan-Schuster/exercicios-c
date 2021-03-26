#include <stdio.h>

#define MAX 1000

/**
 *  Algoritmo para advinhar um número x entre 0 e MAX
 * 
 * @author Dahan Schuster 
 */
int main()
{
    // guarda o resultado de cada palpite (<, > ou =)
    char resultadoPalpite;
    
    // o lixo evita problemas com a leitura de char
    char lixo;

    // o uso de float evita problemas com a divisão de números ímpares
    float palpite = MAX / 2,  // o primeiro palpite será a média entre o mínimo e o máximo
          extremoMaior = MAX, // os extremos indicam os valores máximo e mínimo do palpite
          extremoMenor = 0;   // extremoMenor < x < extremoMaior

    int tentativas = 0;

    // continua a palpitar até acertar...
    while (resultadoPalpite != '=')
    {
        printf("%.0f\n", palpite); // apresenta o primeiro palpite...
        scanf("%c%c", &resultadoPalpite, &lixo); // ... e lê seu resultado

        tentativas++;

        // caso o número x escolhido pelo usuário seja menor que o palpite...
        if (resultadoPalpite == '<')
        {
            extremoMaior = palpite; // sabemos que x < palpite
            palpite = (palpite + extremoMenor) / 2.0;
        }
        // caso x seja maior que o palpite...
        else if (resultadoPalpite == '>')
        {
            extremoMenor = palpite; // sabemos que palpite < x
            palpite = (palpite + extremoMaior) / 2.0;
        }
    }

    printf("%d\n", tentativas);

    return 0;
}