#include <stdio.h>

/**
 * Verifica se um dígito x está incluso em um número n
 * 
 * Bug não resolvido a tempo: caso n possua um dítigo 0 dentro dele,
 * o programa pára o loop naquele 0
 * 
 * @author Dahan Schuster
 */
int main()
{

    int n, digito;

    printf("n: ");
    scanf("%d", &n);

    printf("Dígito: ");
    scanf("%d", &digito);

    // armazena o valor do dígito de n que está sendo verificado em cada loop
    int digitoAtual = 1;
    
    // o dígito atual é calculado ao dividir (n % mod) por div
    // a cada iteração, o valor de div e mod incrementa em 10 unidades
    int div = 1, mod = 10;

    int nContemDigito = 0;

    // caso div possua uma ordem de grandeza maior que n,
    // o digitoAtual terá valor 0 e o loop é quebrado
    while (digitoAtual != 0)
    {
        // Ex.: na segunda iteração, com n = 4562, teremos que:
        // 4562 % 100 == 62
        // 62   / 10  == 2
        // 2 será o dígito atual
        digitoAtual = n % mod / div;
    
        // atualiza os valores de mod e div para que na próxima iteração
        // o resultado do cálculo seja o dígito imediatamente à esquerda
        mod *= 10;
        div *= 10;

        if (digito == digitoAtual) {
            nContemDigito = 1;
            digitoAtual = 0; // quebra o loop para evitar processamento desnecessário
        }
    }
    
    if (nContemDigito)
    {
        printf("%d está em %d", digito, n);
    }
    else
    {
        printf("%d não está em %d", digito, n);
    }

    printf("\n");
    return 0;
}