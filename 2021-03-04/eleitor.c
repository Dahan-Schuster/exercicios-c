#include <stdio.h>

int main()
{
    int anoNascimento, anoAtual, idade;
    char *classeEleitoral;

    printf("Olá! Este programa verifica a classe eleitoral de uma pessoa, baseado na sua idade. Shall we begin?\n\n");

    printf("Para começar, digite seu ano de nascimento e, depois, o ano atual\n");

    printf("Ano de nascimento: ");
    scanf("%d", &anoNascimento);

    printf("Ano atual: ");
    scanf("%d", &anoAtual);

    idade = anoAtual - anoNascimento;

    if (idade < 16)
        classeEleitoral = "Não eleitor";
    else if (idade >= 18 && idade <= 65)
        classeEleitoral = "Eleitor obrigatório";
    else
        classeEleitoral = "Eleitor facultativo";

    printf("\nA idade calculada é de %d anos, o que configura um %s.\n", idade, classeEleitoral);

    return 0;
}