# Teste de mesa do código da questão 4

## Aluno: Dahan Schuster

---

## Código para análise

``` c
#define W 6
void main()
{
    int p1 = 0, p2 = W - 1;
    int c1 = 1, c2 = -1;

    /*
         i | p1 | p2 | c1 | c2
        ----------------------
         0 | 0  | 5  |  1 | -1
         1 | 1  | 4  |  1 | -1
         2 | 2  | 3  |  1 | -1
         3 | 3  | 2  |  1 | -1
         4 | 4  | 1  |  1 | -1
         5 | 5  | 0  | -1 |  1
         6 | 4  | 1  | -1 |  1
         7 | 3  | 2  | -1 |  1
         8 | 2  | 3  | -1 |  1
         9 | 1  | 4  | -1 |  1
        10 | 0  | 5  |  1 | -1
        11 | 1  | 4  |  1 | -1
    */
    while (1)
    {
        int i;
        for (i = 0; i < W; i++)
        {
            if (i == p1)
                pontoRolo1();
            else if (i == p2)
                pontoRolo2();
            else
                moveAgulha();
        }
        p1 += c1;
        p2 += c2;
        if (!p1 || p1 == W - 1)
            c1 *= -1;
        if (!p2 || p2 == W - 1)
            c2 *= -1;
        resetaAgulha();
        rolaTecido();
    }
}
```

## Padrão Feito pela Máquina

```txt
|v    a    v    a    v    a    v    a    v    a    v    a    v|(...)
| v  a a  v v  a a  v v  a a  v v  a a  v v  a a  v v  a a  v |(...)
|  va   av   va   av   va   av   va   av   va   av   va   av  |(...)
|  av   va   av   va   av   va   av   va   av   va   av   va  |(...)
| a  v v  a a  v v  a a  v v  a a  v v  a a  v v  a a  v v  a |(...)
|a    v    a    v    a    v    a    v    a    v    a    v    a|(...)

____________________________________________________________________
```
