#include <stdio.h>

float calcularMedia(int quantidade, float *valores)
{
    float soma = 0;

    for (int i = 0; i < quantidade; i++)
    {
        soma += valores[i];
    }

    return soma / quantidade;
}

int main()
{
    float numeros[5];
    float media;

    printf("Olá! Este programa calcula médias entre 5 números informados. Shall we begin?\n\n");

    printf("Para começar, digite cada um dos valores (separados por um ENTER):\n");

    scanf("%f", &numeros[0]);
    scanf("%f", &numeros[1]);

    media = calcularMedia(2, numeros);
    printf("%f\n", media);

    scanf("%f", &numeros[2]);

    media = calcularMedia(3, numeros);
    printf("%f\n", media);

    scanf("%f", &numeros[3]);

    media = calcularMedia(4, numeros);
    printf("%f\n", media);

    scanf("%f", &numeros[4]);

    media = calcularMedia(5, numeros);
    printf("%f\n", media);

    return 0;
}