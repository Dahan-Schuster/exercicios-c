# Respostas das questões que não pedem código

## Info

* Aluno: Dahan Schuster
* Aula : 03
* Obs. : Abrir preferencialmente com um visualizador de Markdown

&nbsp;

## 1ª Questão

``` c
#include <stdio.h>
int main ()
{
    int foo = 5, bar = 2;
    float foobar = 8.0;

    // 3 * 2 == 6
    // 5 + 6 == 11
    printf ("%d\n", foo + 3 * bar);         // 11
    
    // 5 + 3 == 8
    // 8 * 2 == 16
    printf ("%d\n", (foo + 3) * bar);       // 16
    
    // 5 * 2 == 10
    // (int) 10 / 8 == 1
    printf ("%d\n", (foo * bar) / 8);       // 1
    
    // 5 * 2 == 10
    // 10 / 8.0 == 1.25
    printf ("%f\n", (foo * bar) / foobar);  // 1.25
    
    return 0;
}
```

&nbsp;

## 2ª Questão

``` c
#include <stdio.h>
int main ()
{
    int a, b, c, d, e;
    float f;
    
    // 5 % 3 == 2
    // 2 * 2 == 4
    a = 5 % 3 * 2;      // a == 4 

    // (int) 5 / 2 == 2
    // 3 + 2 == 5
    b = 3 + a / 2;      // b == 5
    
    // 5 * 2 == 10
    // 10 / 2 == 5
    // 4 + 5 == 9
    c = a + b * 2 / 2;  // c == 9
    
    // (int) 9 / 2 == 4
    // 4 * 4 == 16
    d = c / 2 * a;      // d == 16
    
    // 5 * 2 == 10
    // 16 % 10 == 6
    e = d % (b * 2);    // e == 6
    
    // 6 * -2 == -12
    // -12 / 5.0 == -2.4
    f = e * -2 / 5.0;   // f == -2.4
    
    return 0;
}
```

&nbsp;

## 4ª Questão

``` c
#include <stdio.h>
int main ()
{
    int foo = 10, bar = 5;
    printf ("%d\n", foo + 10);  // 20
    printf ("%d\n", foo + 10);  // 20
    printf ("%d\n", foo + 10);  // 20
    bar = foo + 1;              // 11
    printf ("%d\n", foo);       // 10
    printf ("%d\n", bar);       // 11
    return 0;
}
```

&nbsp;

## 6ª Questão

``` c
#include <stdio.h>
int main ()
{
    float x1 = 5.0, x2 = 2.0;
    int x3;

    printf ("%f\n", x1 % x2);   // O operador % só aceita números inteiros
    
    printf ("%f\n", &x1);   // Está passando a variável x1 por referência para o
                            // printf que espera o valor da variável (não seu
                            // endereço, que é passado quando se usa &)
    
    x1 = x2     // Faltou o ;
    
    printf ("%d\n", x3);    // Está escrevendo um valor indefinido
                            // (x3 não foi incializado)
    
    X2 = 10;    // Está usando o nome da variável x2 em caixa alta
    
    x1 + 10.0;  // Está realizando um cálculo mas sem utilizar seu resultado
    
    x3 = 039;   // Pesquisando na Net, descobri que em C o 0 na frente de um
                // inteiro o transforma em um número octal (de base 8). No caso
                // desta linha de código, o erro é que 039 não é um número octal
                // válido, pois utiliza o dígito 9 (números octais usam apenas
                // os dígitos 0 a 7). Ex.: 01, 012, 0547, 0666 etc

    return 0;
}
```

&nbsp;

## 9ª Questão

Haverá casos em que iremos precisar apenas do valor inteiro, como foi o caso
da questão 7, em que o desafio era converter segundos em dias, horas, minutos e
segundos: nessa questão, para conseguir o valor de minutos, horas e dias,
precisamos fazer uma divisão inteira, isto é, realizar a divisão entre números
inteiros para considerar apenas o quociente inteiro da divisão

Haverão outros casos, também, onde tipos diferentes de variáveis serão necessários,
como o tipo string para texto, o tipo char para caracteres únicos, o tipo double
para números decimais com maior precisão, short ints para valores numéricos muito
baixos, ou até long ints para valores muito altos. Usar um único tipo de variável
num programa nunca foi uma boa opção

&nbsp;

## 10ª Questão

O operador ^ está na lista dos operadores bitwise da linguagem C, utilizados para
realizar operações lógicas comparando todos os bits de um valor (operações bit-a-bit).
O ^, em específico, representa o "Ou exclusivo", ou XOR que, segundo a tabela
verdade, irá resultar em verdadeiro se exclusivamente uma preposição (nesse caso,
bit) tiver valor verdadeiro (nesse caso, 1). O resultado final será a soma dos
bits em que a comparação retornou verdadeira

Operador XOR na tabela verdade:

* 0 ^ 0 == 0 (ou false XOR false = false)
* 0 ^ 1 == 1 (ou false XOR true = true)
* 1 ^ 1 == 0 (ou true XOR true = false)

Exemplo: Suponhamos duas variáveis, x = 1, y = 2.
Respectivamente, cada valor será representado pelos binários 0001 e 0010
A operação bit-a-bit irá comparar *cada bit*, isto é, cada 0 ou 1 de dois valores,
e retornar o resultado da soma de todos os bits cuja comparação foi verdadeira.

Vejamos na prática:

* x ^ y == 3, porque:

    1. x = 0001, y = 0010
    2. 0 ^ 0 = 0 (false)
    3. 0 ^ 0 = 0 (false)
    4. 0 ^ 1 = 1 (true) <- Guardamos o valor deste bit, que é 2
    5. 1 ^ 0 = 0 (true) <- Guardamos o valor deste bit, que é 1
    6. 2 + 1 == 3

Outros operadoes bitwise em C são: & (AND) e | (OR), dentre outros.

OBS.: Note que & é diferente de &&, assim como | é diferente de ||.
Os operadores lógicos && e || comparam o **VALOR** de uma variável, enquanto
os operadores bitwise & e | comparam os **BITS** de um valor

Mais operações com Bitwise no arquivo bitwise.c!
