#include <stdio.h>

/**
 * Calcula a média truncada de seis notas, que leva em conta apenas as
 * quatro notas entre a menor e a maior
 * 
 * @author Dahan Schuster
 */
int main()
{
    // Define o valor inicial da menor nota como sendo o maior valor possível,
    // assim a primeira nota < 10 que for informada será considerada a menor
    // O mesmo vale para a maior nota, de forma inversa
    float menorNota = 10,
          maiorNota = 0,
          soma = 0,
          nota, media;

    int i = 1;
    // pede seis números ao usuário
    while (i <= 6)
    {
        printf("Nota %d: ", i);
        scanf("%f", &nota);
        soma += nota; // armazena todas as notas em uma soma total

        // verifica a menor e a maior nota (uma condição não anula a outra)
        if (nota < menorNota) menorNota = nota;
        if (nota > maiorNota) maiorNota = nota;

        i++;
    }

    // remove a maior e a menor nota da soma total
    soma -= maiorNota + menorNota;

    media = soma / 4;

    printf("%.2f\n", media);

    return 0;
}