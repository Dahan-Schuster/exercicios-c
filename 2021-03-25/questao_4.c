#include <stdio.h>
#define N 5

/**
 * Calcula a soma dos N primeiros números primos a partir de 1 (exclusive)
 * 
 * @author Dahan Schuster
 */
int main()
{
    int i, div;
    int isPrimo = 1,
        primos = 0, // contador para quebrar o for independente do i
        soma = 0;   // soma dos números primos encontrados

    for (i = 2; primos <= N; i++)
    {
        isPrimo = 1;    // reinicializa a flag para todo número 

        // tenta dividir o número por todos os números entre 1 (exclusive)
        // e ele mesmo (exclusive)
        for (div = 2; div < i; div++)
        {
            if (i % div == 0) // caso a divisão tenha resto 0...
            {
                isPrimo = 0;  // ...o número não é primo
                break;  // não é mais necessário continuar a verificação
            }
        }

        // ao final da verificação, caso o número seja primo
        if (isPrimo) {
            soma += i; // soma o número ao total
            primos++;  // incrementa o contador de primos que irá quebrar o for externo
        }
    }

    printf("%d\n", soma);
    return 0;
}