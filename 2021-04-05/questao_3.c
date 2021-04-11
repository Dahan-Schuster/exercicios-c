#include <stdio.h>

/**
 * Converte uma certa quantidade de segundos em horas, minutos e segundos
 * Recebe o valor do total de segundos e os endereços para as variáveis
 * que guardam as horas, minutos e segundos
 * 
 * @author Dahan Schuster
 */
void segundosParaHMS (int total_segundos, int *h, int *m, int *s)
{
    int total_minutos = total_segundos / 60;

    *s = total_segundos % 60;
    *m = total_minutos % 60;
    *h = (total_minutos / 60) % 24;
}

#define TOTAL_SEGUNDOS 10000

int main()
{
    int h, m, s;
    segundosParaHMS(TOTAL_SEGUNDOS, &h, &m, &s);

    printf("%02d:%02d:%02d\n", h, m, s);

    return 0;
}