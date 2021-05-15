#include <string.h>
#include <stdio.h>

#define N_NOME 4
#define N_MESES 12

typedef struct
{
    int id;
    int dias;
    char nome[N_NOME];
} Mes;

void criaMes(Mes *aux, int id, int dias, char nome[])
{
    aux->id = id;
    aux->dias = dias;
    strcpy(aux->nome, nome);
}

int main()
{
    Mes meses[N_MESES];
    char nomes[N_MESES][N_NOME] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};
    int dias[N_MESES] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int i;
    for (i = 0; i < N_MESES; i++)
        criaMes(&meses[i], i, dias[i], nomes[i]);

    int n_mes = -1;
    while (n_mes < 1 || n_mes > 12)
    {
        printf("Digite o nº do mês (1, 12): ");
        scanf("%d", &n_mes);    
    }
    n_mes--;

    printf("Mês: %s\nDias: %d\n", meses[n_mes].nome, meses[n_mes].dias);
    return 0;
}
