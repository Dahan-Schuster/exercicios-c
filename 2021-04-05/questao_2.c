/**
 * Recebe dois parâmetros por referência e
 * incrementa o primeiro e decrementa o segundo
 * 
 * @author Dahan Schuster 
 */
void incDec (int *a, int *b)
{
    (*a)--;
    (*b)++;
}

#include <stdio.h>
int main()
{

    int a = 1,
        b = 1;

    printf("%d, %d\n", a, b);
    incDec(&a, &b);
    printf("%d, %d\n", a, b);

    return 0;
}