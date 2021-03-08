#include <stdio.h>

int main()
{
    int diaAtual, mesAtual, anoAtual;
    int diaNascimento, mesNascimento, anoNascimento;

    int idade;

    printf("Olá! Este programa calcula a idade de uma pessoa a partir da data atual. Shall we begin?\n\n");

    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &diaNascimento, &mesNascimento, &anoNascimento);

    printf("Digite a data atual (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &diaAtual, &mesAtual, &anoAtual);

    idade = anoAtual - anoNascimento;

    if (mesAtual < mesNascimento || (mesAtual == mesNascimento && diaAtual < diaNascimento)) {
        idade--;
    }

    printf("\nA idade calculada foi de %d anos.\n", idade);
    return 0;
}