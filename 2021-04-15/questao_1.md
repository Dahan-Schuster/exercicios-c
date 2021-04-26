# Teste de mesa do código da questão 1

## Aluno: Dahan Schuster

---

## Código para análise

``` c
#include <stdio.h>

#define N 7

int main()
{
    int i, j;
    char b[N * 2 + 1];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N * 2; j++)
            b[j] = 'x';
        b[N * 2] = '\0';

        for (j = 0; j <= i; j++)
        {
            b[j] = '1';
            b[N * 2 - j - 1] = '0';
        }

        /* %s é a sequência de escape para strings. */
        printf("%s\n", b);
    }
    return (0);
}
```

## Testes de mesa

i = 0: 1xxxxxxxxxxxx0\0
i = 1: 11xxxxxxxxxx00\0
i = 2: 111xxxxxxxx000\0
i = 3: 1111xxxxxx0000\0
i = 4: 11111xxxx00000\0
i = 5: 111111xx000000\0
i = 6: 11111110000000\0
