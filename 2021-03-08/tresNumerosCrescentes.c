#include <stdio.h>

int main()
{
    int num1, num2, num3;

    printf("Olá! Este programa recebe três números e os exibe em ordem crescente. Shall we begin?\n\n");

    printf("Para começar, informe...\n");

    printf("Número 1: ");
    scanf("%d", &num1);

    printf("Número 2: ");
    scanf("%d", &num2);

    printf("Número 3: ");
    scanf("%d", &num3);

    if (num1 > num2)
    {
        if (num1 > num3)
        {
            if (num3 > num2)
                printf("%d < %d < %d", num2, num3, num1);
            else
                printf("%d < %d < %d", num3, num2, num1);
        }
        else
        {
            printf("%d < %d < %d", num2, num1, num3);
        }
    }
    else
    {
        if (num3 > num1)
        {
            if (num3 > num2)
                printf("%d < %d < %d", num1, num2, num3);
            else
                printf("%d < %d < %d", num1, num3, num2);
        }
        else
        {
            printf("%d < %d < %d", num3, num1, num2);
        }
    }

    printf("\n");
    return 0;
}