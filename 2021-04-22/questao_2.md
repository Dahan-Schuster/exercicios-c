# Análise do código da questão 2

## Aluno: Dahan Schuster

---

## Código para análise

``` c
#define TAM 10
void copiaVetor(int *vetor, int *vetor2)
{
    int vetor_aux [TAM], i;
    for (i = 0; i < TAM; i++)
        vetor_aux [i] = vetor [i];
    vetor2 = vetor_aux;
}
void imprimeVetor(int *vetor)
{
    int i;
    for (i = 0; i < TAM; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}
int main()
{
    int vet[TAM], vet2[TAM];
    int i;
    for (i = 0; i < TAM; i++)
        scanf("%d", &vet[i]);
    copiaVetor(vet, vet2);
    printf("Vetor:\n");
    imprimeVetor(vet);
    printf("Copia:\n");
    imprimeVetor(vet2);
    return (0);
}
```

## Problemas

O problema mais óbvio que pode-se observar é a associação do vetor auxiliar ao
vetor2 usando o operador `=`. A copia de vetores deve ser feita índice a índice,
e pode inclusive dispensar o uso de uma variável auxiliar.

O código desta parte poderia ser reescrito da seguinte forma:

```c
void copiaVetor(int *vetor, int *vetor2)
{
    int i;
    for (i = 0; i < TAM; i++)
        vetor2 [i] = vetor [i];
}
```

O segundo problema, talvez não tão óbvio, é a falta da inclusão do cabeçalho
`<stdio.h>`, o que geraria *warnings* ao usar as funções `prinf` e `scanf`.

Para consertar, bastar incluir...

```c
#include <stdio.h> // essa linha
#define TAM 10
```
