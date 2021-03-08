#include <stdio.h>

int main()
{
    int horaInicial, minutoInicial, horaFinal, minutoFinal;

    int horasDuracao, minutosDuracao;
    char duracao[5];

    printf("Olá! Este programa calcula a duração de um jogo. Shall we begin?\n\n");

    printf("Para começar, digite as horas inicial e final do jogo\n");

    printf("Hora inicial (horas, minutos): ");
    scanf("%d, %d", &horaInicial, &minutoInicial);

    printf("Hora final (horas, minutos): ");
    scanf("%d, %d", &horaFinal, &minutoFinal);

    horasDuracao = horaFinal < horaInicial || (horaFinal == horaInicial && minutoFinal <= minutoInicial)
                       ? (horaFinal + 12) - (horaInicial - 12)
                       : horaFinal - horaInicial;

    if (minutoFinal >= minutoInicial)
        minutosDuracao = minutoFinal - minutoInicial;
    else
    {
        minutosDuracao = minutoFinal + (60 - minutoInicial);
        horasDuracao--;
    }

    if (horasDuracao == 24 && minutosDuracao > 0) {
        printf("Horas inválidas. A duração máxima do jogo é de 24h");
    } else if (horasDuracao == 0) {
        printf("Horas inválidas. A duração mínima do jogo é de 1h");
    } else {
        snprintf(duracao, 6, "%02dh%02d", horasDuracao, minutosDuracao);
        printf("\nO jogo durou %s", duracao);
    }

    printf("\n");
    return 0;
}