#include <stdio.h>
#include <math.h>

/**
 * Calcula a potência de um número com expoente positivo
 */
float _potencia(float base, float expoente)
{
    // chamada recursiva até chegar ao expoente 1
    if (expoente > 1)
        return base * _potencia(base, expoente - 1);
    return base;
}

/**
 * Retorna um número x elevado a y
 * @author Dahan Schuster
 */
float potencia(float base, float expoente)
{
    if (expoente == 0)
        return 1;

    int isExpoenteNegativo;

    // verifica se o expoente é negativo (1 == Sim, 0 == Não)
    if (expoente < 0)
    {
        isExpoenteNegativo = 1;
        expoente = expoente * -1; // se o expoente for negativo, transforma em positivo
    }
    else
        isExpoenteNegativo = 0;

    float resultado = _potencia(base, expoente);

    // se o expoente for negativo, retorna o inverso do resultado
    return isExpoenteNegativo == 1 ? 1 / resultado : resultado;
}

float calcularVolumeEsfera(float raio)
{
    return (4 * M_PI * potencia(raio, 3)) / 3;
}

int main()
{
    float raio, volume;

    printf("Olá! Este programa calcula o volume de uma esfera. Shall we begin?\n\n");

    printf("Para começar, digite o valor do raio (r) da esfera: ");
    scanf("%f", &raio);

    volume = calcularVolumeEsfera(raio);

    printf("O volume de uma esfera de raio %.2f é aproximadamente: %f.", raio, volume);

    return 0;
}