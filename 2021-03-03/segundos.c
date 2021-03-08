#include <stdio.h>

int main()
{
    int dias, horas, minutos, segundos;
    int totalMinutos, totalHoras, totalSegundos;

    printf("Olá! Este programa converte uma certa quantidade de segundos em dias, horas, minutos e segundos. Shall we begin?\n\n");

    printf("Informe a quantidade de segundos que deseja converter: ");

    scanf("%d", &totalSegundos);

    segundos = totalSegundos % 60;

    totalMinutos = totalSegundos / 60;
    minutos = totalMinutos % 60;

    totalHoras = totalMinutos / 60;
    horas = totalHoras % 24;

    dias = totalHoras / 24;

    printf("%d dia(s), %d hora(s), %d minutos(s) e %d segundo(s)", dias, horas, minutos, segundos);

    return 0;
}