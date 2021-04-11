#include <stdio.h>
#define LARGURA_FAIXA 6 /* Largura da faixa de tecido, em cm. */

void pontoRolo1();
void pontoRolo2();
void resetaAgulha();
void rolaTecido();
void moveAgulha();

void main()
{
    int i, n = 0;
    int qtePontos,
        pontoAtual = 2;

    /* Funciona até desligar ou o tecido acabar. */
    while (n < 10)
    {
        for (i = 1; i <= LARGURA_FAIXA; i++)
        {
            for (qtePontos = 1; qtePontos <= i; qtePontos++)
            {
                if (pontoAtual == 1)
                {
                    pontoRolo1();
                }
                else if (pontoAtual == 2)
                {
                    pontoRolo2();
                }

                if (qtePontos == LARGURA_FAIXA)
                {
                    pontoAtual = pontoAtual == 2 ? 1 : 2;
                }
            }

            resetaAgulha();
            rolaTecido();
        }
        n++;
    }
}

void pontoRolo1()
{
    printf("v\n");
}

void pontoRolo2()
{
    printf("a\n");
}

void moveAgulha()
{
    printf("|\n");
}

void resetaAgulha()
{
    printf(" ↑\n");
}

void rolaTecido()
{
    printf(" →\n");
}
