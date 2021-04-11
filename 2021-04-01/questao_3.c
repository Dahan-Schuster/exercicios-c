#define LARGURA_FAIXA 6 /* Largura da faixa de tecido, em cm. */

void pontoRolo1();
void pontoRolo2();
void resetaAgulha();
void rolaTecido();
void moveAgulha();

void main()
{
    int i;

    // Guarda o valor da quantidade de pontos a ser dada em cada coluna
    // Varia de 1 a LARGURA_FAIXA
    int qtePontos;

    // Guarda o valor do ponto sendo feito no momento (vermelho ou azul)
    int pontoAtual = 2;

    /* Funciona até desligar ou o tecido acabar. */
    while (1)
    {
        for (i = 1; i <= LARGURA_FAIXA; i++)
        {
            // em cada coluna irá imprimir i pontos
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

                // caso tenha feito pontos em todos os cm da largura da faixa,
                // troca o ponto para alternar o padrão
                if (qtePontos == LARGURA_FAIXA)
                {
                    pontoAtual = pontoAtual == 2 ? 1 : 2;
                }
            }

            resetaAgulha();
            rolaTecido();
        }
    }
}