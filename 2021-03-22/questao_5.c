#include <stdio.h>

int main()
{
    int pontos = 0;
    int placarTimeA, placarTimeB;
    int apostaTimeA, apostaTimeB;
    scanf("%dx%d", &apostaTimeA, &apostaTimeB);
    scanf("%dx%d", &placarTimeA, &placarTimeB);

    if (apostaTimeA == placarTimeA)
        pontos += 5;
    if (apostaTimeB == placarTimeB)
        pontos += 5;

    if (placarTimeA >= placarTimeB && apostaTimeA >= apostaTimeB)
        pontos += 10;
    else if (placarTimeB > placarTimeA && apostaTimeB > apostaTimeA)
        pontos += 10;

    printf("%d\n", pontos);
    return 0;
}