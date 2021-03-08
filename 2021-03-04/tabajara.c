#include <stdio.h>

int main()
{
    float precoLitroAlcool, precoLitroGasolina;
    float kmPorLitroComAlcool, kmPorLitroComGasolina;

    printf("Olá! Este programa calcula a forma mais econômica de abastecer um carro bicombustível. Shall we begin?\n\n");

    printf("Para começar, digite o valor do litro de cada combustível (R$)\n");

    printf("Gasolina: ");
    scanf("%f", &precoLitroGasolina);

    printf("Álcool: ");
    scanf("%f", &precoLitroAlcool);

    printf("\nAgora, para finalizar, vamos aos Km por Litro que o carro roda com cada um destes combustíveis.\n");

    printf("Gasolina: ");
    scanf("%f", &kmPorLitroComGasolina);

    printf("Álcool: ");
    scanf("%f", &kmPorLitroComAlcool);

    float valorGasolinaPorKm = (1 / kmPorLitroComGasolina) * precoLitroGasolina;
    float valorAlcoolPorKm = (1 / kmPorLitroComAlcool) * precoLitroAlcool;

    char *melhorCombustivel;

    if (valorGasolinaPorKm <= valorAlcoolPorKm)
    {
        melhorCombustivel = "Gasolina";
    }
    else
    {
        melhorCombustivel = "Álcool";
    }

    printf("\nCálculo feito! É mais enconômico usar %s!\n", melhorCombustivel);

    return 0;
}