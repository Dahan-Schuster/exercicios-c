#include <stdio.h>
#include <math.h>

/** 
 * Este foi o maior múmero que gerou resultados em uma quantidade aceitável de 
 * tempo. 99999999 e 999999999 demoraram muito para responder 
 * Com 9999999 iterações, o valor de PI obtido foi:
 *      pi = 3.14159239571668535973
 * Sendo
 *      M_PI = 3.14159265358979311600 
 * 
 * O que resultou em uma precisão de seis casas decimais para 9999999 termos, 
 * ou seja, pi == M_PI apenas quando M_PI == 3.141592 
 * 
 * @author Dahan Schuster
*/
#define N_TERMOS 99999999

/*
    Calcula pi através da série de Leibniz, que diz que:
    pi/4 = 1 - 1/3 + 1/5 - ... + 1/n
    
    Logo,
    pi = 4(1 - 1/3 + 1/5 - ... + 1/n), ou
    pi = 4*(1/1) - 4*(1/3) + 4*(1/5) - ... + 4*(1/n)
*/
int main()
{
    // define um multiplicador para inverter o sinal da conta
    float i, multiplicador = 1;

    double pi;

    // itera entre os N termos, incrementando sempre 2 valores
    for (i = 1; i <= N_TERMOS; i += 2)
    {
        // aproveita o formato distribuído da fórmula ( pi = 4*(1/1) - 4*(1/3) ... )
        // para incremetar o valor de pi a cada iteração
        pi += multiplicador * 4 * (1 / i);

        // inverte o valor do multiplicador
        multiplicador *= -1;
    }

    printf("PI equivale a aproximadamente %.20lf\n", pi);

    printf("\nCom %d iterações... ", N_TERMOS);

    if (pi == M_PI)
        printf("pi == M_PI");
    else
        printf("pi != M_PI");

    printf("\n");
    return 0;
}