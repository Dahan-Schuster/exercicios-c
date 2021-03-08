#include <stdio.h>

int main()
{
    int anoAtual, anoNascimento, anoInicioINSS;
    int idade, contribuicaoINSS;

    printf("Olá! Este programa verifica se um poderá se aposentar ao final do ano. Shall we begin?\n\n");

    printf("Para começar, informe...\n");

    printf("O ano atual: ");
    scanf("%d", &anoAtual);

    printf("O ano de nascimento do empregado: ");
    scanf("%d", &anoNascimento);

    printf("O ano em que o empregado começou a contribuir para o INSS: ");
    scanf("%d", &anoInicioINSS);

    idade = anoAtual - anoNascimento;
    contribuicaoINSS = anoAtual - anoInicioINSS;

    char *resultado = "NÃO PODERÁ se aposentar";

    if (idade >= 60)
    {
        if (idade >= 65)
        {
            if (contribuicaoINSS >= 30)
                resultado = "PODERÁ se aposentar";
        }
        else if (contribuicaoINSS >= 25)
            resultado = "PODERÁ se aposentar";
    }

    printf("\nAo final do ano, o empregado terá %d anos, tendo contribuído por %d anos para o INSS e, portanto, %s\n", idade, contribuicaoINSS, resultado);
    return 0;
}