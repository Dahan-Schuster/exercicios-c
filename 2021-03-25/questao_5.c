#include <stdio.h>

/**
 * Consulta o menor número divisível por todos os números entre 0 e N 
 * 
 * @author Dahan Schuster
 */
int main()
{
    int numero = 0, div, maximo;
    int isDivisivel = 0;

    scanf("%d", &maximo);


    // repete a verificação até achar um número divisível
    while (!isDivisivel)
    {
        numero++;
        isDivisivel = 1;

        // tenta dividir o número por todos os números entre 2 e N
        // sabemos que 1 é divisor universal, então podemos ignorá-lo
        for (div = 2; div <= maximo; div++)
        {
            if (numero % div != 0) // caso a divisão não tenha resto 0...
            {
                isDivisivel = 0;  // ...o número não é divisível
                break;  // não é mais necessário continuar a verificação
            }
        }
    }

    printf("%d\n", numero);
    return 0;
}