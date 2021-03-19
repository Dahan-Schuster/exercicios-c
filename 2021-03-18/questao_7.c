#include <stdio.h>

/**
 * Verifica a maior sequência crescente dentro de uma lista de números
 * 
 * @author Dahan Schuster
 */
int main()
{

    // armazena o valor do tamanho da sequência atual e da maior até agora
    int sequencia = 1, maiorSequencia = 0;

    // armazena o valor do número lido em cada loop e o do loop anterior
    int anterior, atual;

    // lê o primeiro número como sendo o anterior,
    // depois lê os próximos dentro do loop
    printf("-> ");
    scanf("%d", &anterior);

    while (anterior > 0)
    {
        printf("-> ");
        scanf("%d", &atual);

        // sendo o atual maior que o anterior, incrementa o tamanho da sequência
        if (atual > anterior)
            sequencia++;
        else
        {
            // quando a sequência é quebrada, analisa se ela foi a maior ...
            if (sequencia > maiorSequencia)
                maiorSequencia = sequencia;

            // ... e depois redefine o valor
            sequencia = 1;
        }


        // por fim salva o valor lido no loop atual como sendo o valor anterior
        anterior = atual;
    }

    printf("A maior sequência crescente tem %d número(s)\n", maiorSequencia);
    return 0;
}