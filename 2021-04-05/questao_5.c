// #define WINDOWS // Comente esta linha para usar no Linux/Unix!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef WINDOWS
#include <windows.h>
#endif // WINDOWS

#define POSICAO_CHEGADA 70

void moveTartaruga(int valor_sorteado, int *pos);
void moveLebre(int valor_sorteado, int *pos);
void imprimePosicoesAtuais(int pos_tartaruga, int pos_lebre);

int main()
{
    int tartaruga = 0, lebre = 0;
    srand(time(NULL));

    while (tartaruga < POSICAO_CHEGADA && lebre < POSICAO_CHEGADA)
    {
        moveTartaruga(rand() % 100, &tartaruga);
        moveLebre(rand() % 100, &lebre);
        imprimePosicoesAtuais(tartaruga, lebre);

#ifdef WINDOWS
        Sleep(100);
#else
        sleep(1);
#endif
    }

    if (tartaruga >= lebre)
        printf("Tartaruga ganhou!!!\n");
    else
        printf("Lebre Ganhou!!!\n");

    return 0;
}

#define T_PASSO_G 3
#define T_PASSO_P 1
#define T_ESCORREGAO -6

#define L_SONECA 0
#define L_SALTO_G 9
#define L_ESCORREGAO_G -12
#define L_SALTO_P 1
#define L_ESCORREGAO_P -2

/**
 * Recebe um valor de 0 a 99 representando o movimento da tartatura e o associa
 * a um tipo de movimento
 * A posição da tartaruga é atualizada via referência, depois de ser validada
 * 
 * 50% dos valores serão um Passo Grande
 * 20% dos valores serão um Escorregão
 * 30% dos valores serão um Passo Pequeno
 * 
 * @author Dahan Schuster
 */
void moveTartaruga(int valor_sorteado, int *pos)
{
    if (valor_sorteado <= 50)
        *pos += T_PASSO_G;
    else if (valor_sorteado <= 70)
        *pos += T_ESCORREGAO;
    else
        *pos += T_PASSO_P;

    // Valida a nova posição passando seu endereço de memória para a função.
    // Vomo pos, neste contexto, já é um endereço, não é necessário adicionar
    // o asterisco no parâmetro
    validarNovaPosicao(pos);
}

/**
 * Recebe um valor de 0 a 99 representando o movimento da lebre e o associa a
 * um tipo de movimento
 * A posição da lebre é atualizada via referência, depois de ser validada
 * 
 * 20% dos valores serão uma Soneca
 * 20% dos valores serão um Salto Grande
 * 10% dos valores serão um Escorregão Grande
 * 30% dos valores serão um Salto Pequeno
 * 20% dos valores serão um Escorregão Pequeno
 * 
 * @author Dahan Schuster
 */
void moveLebre(int valor_sorteado, int *pos)
{
    if (valor_sorteado <= 20)
        *pos += L_SONECA;
    else if (valor_sorteado <= 40)
        *pos += L_SALTO_G;
    else if (valor_sorteado <= 50)
        *pos += L_ESCORREGAO_G;
    else if (valor_sorteado <= 80)
        *pos += L_SALTO_P;
    else
        *pos += L_ESCORREGAO_P;

    validarNovaPosicao(pos);
}

/**
 * Valida a nova posição definida para um dos competidores
 * Recebe o valor da posição por referência e o atualiza dentro da função
 * 
 * Valores menores que 0 (partida) serão convertidos em 0
 * Valores maiores que o máximo (chegada) serão convertidos no valor máximo
 * Quaisquer outros valores serão mantidos
 * 
 * @author Dahan Schuster
 */
void validarNovaPosicao(int *pos)
{
    *pos = *pos > POSICAO_CHEGADA
               ? POSICAO_CHEGADA
               : (*pos < 0 ? 0 : *pos);
}

void imprimePosicoesAtuais(int pos_tartaruga, int pos_lebre)
{
    int i;
    system("cls||clear");
    printf("\t\t\tPos. Tartaruga: %2d | Pos. Lebre: %2d\n", pos_tartaruga, pos_lebre);
    printf("*******************************************************************************\n");
    // printf("\n _\n .-./*)\n_/___\\/\n U U");          // desenho tartaruga (base)
    // printf("\n \\\\ \n \\\\_ \n .---(')\no( )_-\\_"); // desenho coelho (base)
    for (i = 0; i < pos_tartaruga; i++)
        printf(" ");
    printf(" _\n");
    for (i = 0; i < pos_tartaruga; i++)
        printf(" ");
    printf(" .-./*)\n");
    for (i = 0; i < pos_tartaruga; i++)
        printf(" ");
    printf("_/___\\/\n");
    for (i = 0; i < pos_tartaruga; i++)
        printf(" ");
    printf(" U U");
    printf("\n*******************************************************************************\n");
    for (i = 0; i < pos_lebre; i++)
        printf(" ");
    printf(" \\\\ \n");
    for (i = 0; i < pos_lebre; i++)
        printf(" ");
    printf(" \\\\_ \n");
    for (i = 0; i < pos_lebre; i++)
        printf(" ");
    printf(" .---(')\n");
    for (i = 0; i < pos_lebre; i++)
        printf(" ");
    printf("o( )_-\\_");
    printf("\n*******************************************************************************\n");
}