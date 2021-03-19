#include <stdio.h>

/**
 * Verifica quantos valores informados estão dentro de uma determinada faixa
 * 
 * @author Dahan Schuster
 */
int main()
{
    /* Leitura dos limites da faixa */

    int min, max;

    printf("min: ");
    scanf("%d", &min);
    printf("max: ");
    scanf("%d", &max);

    // Valida se os limites são positivos
    if (min < 0 || max < 0)
    {
        printf("Erro! Os limites devem ser positivos.\n");
        return 0;
    }

    // Valida se os valores foram informados na ordem correta
    if (min > max)
    {
        printf("Erro! Informe primeiro o min e depois o max.\n");
        return 0;
    }

    /* Leitura de interteminados valores */

    int aux = 0, // guarda o valor lido em cada loop
        menor = max,
        maior = min,
        valoresValidos = 0;

    printf("Insira os valores. Digite -1 para finalizar\n");

    // Repete o loop até que um número negativo seja informado
    while (aux >= 0)
    {
        printf("-> ");
        scanf("%d", &aux);

        // Verifica se o valor lido está dentro da faixa informada
        if (min <= aux && aux <= max)
        {
            valoresValidos++; // incrementa a quatidade números válidos informados

            // verifica se o número é o maior e/ou o maior número válido informado
            if (aux < menor)
                menor = aux;
            if (aux > maior)
                maior = aux;
        }
    }

    if (valoresValidos > 0)
    {
        printf("-----\n");
        printf("%d valores válidos\n", valoresValidos);
        printf("Menor: %d\n", menor);
        printf("Maior: %d\n", maior);
    }
    else
    {
        printf("Erro! Nenhum número válido informado.\n");
    }

    return 0;
}