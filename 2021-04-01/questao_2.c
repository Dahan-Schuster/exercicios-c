#define LARGURA_FAIXA 6 /* Largura da faixa de tecido, em cm. */

void pontoRolo1();
void pontoRolo2();
void resetaAgulha();
void rolaTecido();
void moveAgulha();

void main()
{
    int i, j;
    int qtePontosRolo2;
    
    /* Funciona até desligar ou o tecido acabar. */
    while (1)
    {
        for (i = 0; i <= LARGURA_FAIXA; i++)
        {
            // Guarda a quantidade de pontos azuis na coluna
            qtePontosRolo2 = LARGURA_FAIXA;

            // Imprime pontos vermelhos na mesma proporção do valor do i
            // Na primeira iteração j == i, portanto não há pontos vermelhos
            for (j = 0; j < i; j++)
            {
                pontoRolo1();
                // para cada ponto vermelho feito, menos um ponto azul
                qtePontosRolo2--;
            }

            // Imprime os pontos azuis no restante do tecido
            for (qtePontosRolo2; qtePontosRolo2 > 0; qtePontosRolo2--)
            {
                pontoRolo2();
            }

            resetaAgulha();
            rolaTecido();
        }
    }
}
