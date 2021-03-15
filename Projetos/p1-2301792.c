/**
 * Projeto 1 de Fundamentos de Programação
 * 
 * @author Dahan Schuster - 2301792
 */

#include <stdio.h>

int main()
{
    int mes;
    float rendimento, impostoDevido = 0;
    float valorCalculoAliquota;

    // Porcentagem de imposto cobrado para cada faixa de rendimento
    float valorAliquotaFaixa2 = 0.075,
          valorAliquotaFaixa3 = 0.150,
          valorAliquotaFaixa4 = 0.225,
          valorAliquotaFaixa5 = 0.275;

    // Valor máximo de cada faixa de rendimento
    float faixaRendimento1 = 0,
          faixaRendimento2 = 0,
          faixaRendimento3 = 0,
          faixaRendimento4 = 0;

    scanf("%d", &mes);
    scanf("%f", &rendimento);

    // Definição dos valores dos limites das faixas de rendimento a partir do
    // mês informado
    if (mes >= 1 && mes <= 4) // janeiro..abril
    {
        faixaRendimento1 = 1200.25;
        faixaRendimento2 = 2300.50;
        faixaRendimento3 = 3500.75;
        faixaRendimento4 = 4000.00;
    }
    else if (mes >= 5 && mes <= 8) // maio..agosto
    {
        faixaRendimento1 = 1500.00;
        faixaRendimento2 = 2800.25;
        faixaRendimento3 = 3500.50;
        faixaRendimento4 = 4300.75;
    }
    else if (mes >= 9 && mes <= 12) // setembro...dezembro
    {
        faixaRendimento1 = 1875.00;
        faixaRendimento2 = 3400.50;
        faixaRendimento3 = 3900.25;
        faixaRendimento4 = 4600.25;
    }

    // A primeira faixa não possui impostos a serem cobrados
    if (rendimento > faixaRendimento1)
    {
        /* Cálculo do imposto referente à segunda faixa de rendimentos */

        // Caso o rendimento não passe da faixa atual, seleciona apenas a parte
        // de seu valor que está dentro da faixa. Este valor multiplicado pela
        // alíquota é somado ao imposto devido
        if (rendimento <= faixaRendimento2)
        {
            impostoDevido += (rendimento - faixaRendimento1) * valorAliquotaFaixa2;
        }

        // Caso contrário, é utilizado o valor exato da faixa
        // (basta subtrair seu valor máximo pelo da faixa anterior)
        else
        {
            impostoDevido += (faixaRendimento2 - faixaRendimento1) * valorAliquotaFaixa2;

            // Aqui já sabemos que o rendimento passou da faixa 2, então é
            // necessário continuar o cálculo para as próximas faixas, e para isto
            // basta repetir a lógica...

            /* Cálculo do imposto referente à terceira faixa de rendimentos */

            if (rendimento <= faixaRendimento3)
            {
                impostoDevido += (rendimento - faixaRendimento2) * valorAliquotaFaixa3;
            }
            else
            {
                impostoDevido += (faixaRendimento3 - faixaRendimento2) * valorAliquotaFaixa3;

                /* Cálculo do imposto referente à quarta faixa de rendimentos */

                if (rendimento <= faixaRendimento4)
                {
                    impostoDevido += (rendimento - faixaRendimento3) * valorAliquotaFaixa4;
                }
                else
                {
                    impostoDevido += (faixaRendimento4 - faixaRendimento3) * valorAliquotaFaixa4;

                    /* Cálculo do imposto referente à quinta faixa de rendimentos */
                    impostoDevido += (rendimento - faixaRendimento4) * valorAliquotaFaixa5;
                }
            }
        }
    }

    printf("%.2f\n", impostoDevido);

    return 0;
}