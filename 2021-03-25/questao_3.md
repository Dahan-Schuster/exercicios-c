# Teste de mesa do código da questão 3

## Aluno: Dahan Schuster

---

## Código para análise

``` c
#include <stdio.h>
#define N 12
int main() {
    int a, b;

    for (a = 0; a < N / 2; a++) {
        for (b = 0; b < N; b++) {
            if ((a < N / 4 && b >= N / 2 && b < N / 2 + a * 2) ||
                (a >= N / 4 && b < N / 2 && b >= a - (N / 2 - 2 - a)))
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
    return (0);
}
```

## Testes de mesa

* a = 0: **0000 0000 0000**
* a = 1: **0000 0011 0000**
* a = 2: **0000 0011 1100**
* a = 3: **0011 1100 0000**
* a = 4: **0000 1100 0000**
* a = 5: **0000 0000 0000**

### Análise dos loops a < 3

* a = 0
  * N / 2 + a * 2 = 6
  * b = 0..5
    * b >= 6 = false
    * b < 6 = true
  * b = 6..11
    * b >= 6 = true
    * b < 6 = false

  * Resultado: **000000 000000**

* a = 1
  * N / 2 + a * 2 = 8
  * b = 0..5
    * b >= 6 = false
    * b < 8 = true
  * b = 6..7
    * b >= 6 = true
    * b < 8 = true
  * b = 8..11
    * b >= 6 = true
    * b < 8 = false

  * Resultado: **000000 11 0000**

* a = 2
  * N / 2 + a * 2 = 10
  * b = 0..5
    * b >= 6 = false
    * b < 10 = true
  * b = 6..9
    * b >= 6 = true
    * b < 10 = true
  * b = 10..11
    * b >= 6 = true
    * b < 10 = false

  * Resultado: **000000 1111 00**

### Análise dos loops a >= 3

* a = 3
  * a - (4 - a) = 2
  * b = 0..1
    * b < 6  = true
    * b >= 2 = false
  * b = 2..5
    * b < 6  = true
    * b >= 2 = true
  * b = 6..11
    * b < 6  = false
    * b >= 2 = true

  * Resultado: **00 1111 000000**

* a = 4
  * a - (4 - a) = 4
  * b = 0..1
    * b < 6  = true
    * b >= 4 = false
  * b = 4..5
    * b < 6  = true
    * b >= 4 = true
  * b = 6..11
    * b < 6  = false
    * b >= 4 = true

  * Resultado: **0000 11 000000**

* a = 5
  * a - (4 - a) = 6
  * b = 0..5
    * b < 6  = true
    * b >= 6 = false
  * b >= 6
    * b < 6  = false
    * b >= 6 = true

  * Resultado: **000000 000000**
