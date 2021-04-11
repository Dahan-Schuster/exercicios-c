#include <stdio.h>

void removeExtremos(int *n, int *pri, int *ult)
{
    int tn, pot = 1;
    tn = *n;
    while (tn >= 10)
    {
        tn = tn / 10;
        pot *= 10;
    }
    *pri = *n / pot;
    *ult = *n % 10;
    *n = *n % pot;
    *n = *n / 10;
}

/**
 * Verifica se um dado número é palíndromo utilizando a função removeExtremos
 * 
 * @author Dahan Schuster
 */
int main()
{
    int n, pri, ult;
 
    // considera por padrão que o número é palíndromo
    int isPalindromo = 1;

    // lê um número da entrada padrão
    scanf("%d", &n);

    // enquanto n for diferente de 0
    while (n)
    {
        // remove o primeiro e o último dígito do número
        // os valores de n, pri e ult serão modificados dentro da função
        removeExtremos(&n, &pri, &ult);

        // se eles diferem entre si, n não pode ser palíndromo
        if (pri != ult) {
            isPalindromo = 0;

            // quebra o loop para evitar processamento adicional
            break;
        }
    }

    if (isPalindromo)
        printf("É palíndromo!");
    else
        printf("Não é palíndromo!");

    printf("\n");
    return 0;
}