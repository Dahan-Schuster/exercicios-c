#include <stdio.h>

long long _potencia (int base, unsigned int expoente);

/**
 * Calcula a potência de um número
 * 
 * @author Dahan Schuster
 */
double potencia(int base, int expoente)
{
    if (expoente == 0)
        return 1;

    int isExpoenteNegativo;

    // verifica se o expoente é negativo (1 == Sim, 0 == Não)
    if (expoente < 0)
    {
        isExpoenteNegativo = 1;
        expoente = expoente * -1; // se sim, transforma em positivo
    }
    else
        isExpoenteNegativo = 0;

    float resultado = _potencia(base, expoente);

    // se o expoente for negativo, retorna o inverso do resultado
    return isExpoenteNegativo ? 1 / resultado : resultado;
}

/**
 * Calcula a potência de um número com expoente positivo
 * 
 * @author Dahan Schuster
 */
long long _potencia (int base, unsigned int expoente)
{
    // chamada recursiva até chegar ao expoente 1
    if (expoente > 1)
        return base * _potencia(base, expoente - 1);
    return base;
}

int main()
{
    int b, e;
    scanf("%d, %d", &b, &e);
    printf("%lf\n", potencia(b, e));

    return 0;
}