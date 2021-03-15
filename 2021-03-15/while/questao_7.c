#include <stdio.h>

/**
 * Realiza a soma de duas horas informadas no formato hh:mm:ss
 * Faz a validação dos minutos e segundos, que devem estar entre 00 e 59
 * para que o formato seja válido
 * 
 * @author Dahan Schuster
 */
int main()
{

    int horas, minutos, segundos;
    int horasTotais = 0,
        minutosTotais = 0,
        segundosTotais = 0;

    // armazena em um inteiro a informação da quantidade de leituras foram feitas
    int leiturasFeitas = 0;

    // faz a leitura de duas entradas e às valida
    while (leiturasFeitas < 2)
    {
        printf("H%d: ", leiturasFeitas + 1);
        // lê as horas no formato hh:mm:ss
        scanf("%d:%d:%d", &horas, &minutos, &segundos);

        // valida minutos e segundos
        if (minutos < 0 || minutos > 59 || segundos < 0 || segundos > 59)
            printf("Sorry, try again.\n\n");
        else
        {
            leiturasFeitas++;

            // soma separadamente cada valor lido na entrada
            horasTotais += horas;
            minutosTotais += minutos;
            segundosTotais += segundos;
        }
    }

    // calcula a soma das horas
    int somaSegundos = segundosTotais % 60;
    int somaMinutos = (minutosTotais % 60) + (segundosTotais / 60);
    int somaHoras = horasTotais + minutosTotais / 60;

    printf("\n%02d:%02d:%02d\n", somaHoras, somaMinutos, somaSegundos);

    return 0;
}