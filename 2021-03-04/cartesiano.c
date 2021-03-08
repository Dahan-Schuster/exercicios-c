#include <stdio.h>

int main()
{
    float x, y;
    char *posicao;

    printf("Olá! Este programa calcula a posição de um ponto no planto cartesiano. Shall we begin?\n\n");

    printf("Para começar, digite as coordenadas do ponto\n");

    printf("x: ");
    scanf("%f", &x);

    printf("y: ");
    scanf("%f", &y);

    if (x == 0 || y == 0)
    {
        if (x == y)
            posicao = "Origem";
        else
            posicao = x == 0 ? "Eixo Y" : "Eixo X";
    }
    else if (x < 0)
        posicao = y < 0 ? "Q3" : "Q2";
    else 
        posicao = y < 0 ? "Q4" : "Q1";

    printf("\nO ponto está em: %s\n", posicao);

    return 0;
}