#include <stdio.h>

/**
 * Verifica quais números de quatro dígitos apresentam a seguinte característica
 * encontra no número 3025:
 * 
 * 30 + 25 = 55
 * 55 * 55 = 3025
 * 
 * @author Dahan Schuster
*/
int main()
{
    int i;
    
    int milhar, dezena, soma, quadradoDaSoma;

    // itera entre os números de quatro dígitos
    for (i = 1000; i <= 9999; i++)
    {
        // separa as partes esquerda e direita do número
        milhar = i / 100;           // 3025 -> 30
        dezena = i % 1000 % 100;    // 3025 -> 25
        soma = milhar + dezena;     // soma ambos os números (30 + 25 == 55)
        quadradoDaSoma = soma*soma; // quadrado = 55 * 55

        if (quadradoDaSoma == i) {  // 55*55 == 3025
            printf("%d\n", i);
        }
    }


    return 0;
}