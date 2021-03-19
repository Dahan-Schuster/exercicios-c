#include <stdio.h>

/**
 * Calcula o quociente e o resto de uma divisão utilizando apenas soma e subtração
 * 
 * @author Dahan Schuster
 */
int main()
{

    int x, y;

    printf("x/y: ");
    scanf("%d/%d", &x, &y);

    if (x < 0 || y < 0)
    {
        printf("Erro! Apenas valores positivos\n");
        return 0;
    }

    int quociente = 0, resto = 0;
    int contaFinalizada = 0;

    while (!contaFinalizada)
    {
        // caso o numerador - denominador < 0, significa que não há mais como
        // dividir sem quebrar o número, então salva o resto e finaliza a conta
        if (x - y < 0)
        {
            contaFinalizada = 1;
            resto = x;
        } 
        else // caso contrário, continua a subtrair o denomidador do numerador
        {
            x -= y;
            quociente++; // a cada subtração, incrementa o quociente

            if (x == 0) // se a subtração resultou em zero, não há resto
                contaFinalizada = 1;
        }
    }

    printf("Quociente: %d\n", quociente);
    printf("Resto: %d\n", resto);

    return 0;
}