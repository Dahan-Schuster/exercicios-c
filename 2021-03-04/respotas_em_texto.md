# Respostas das questões que não pedem código

## Info

* Aluno: Dahan Schuster
* Aula : 04
* Obs. : Abrir preferencialmente com um visualizador de Markdown

&nbsp;

## 7ª Questão

### a)

A saída será exatamente igual à entrada: `1 2 3`

---

### b)

A saída será: `10 20 30`

### c)

O código realiza uma organização dos números em ordem crescente, usando uma
espécie de bubble sort limitada a apenas três números.

Após receber os três números, o algoritmo verifica se o número do centro é maior
que o último e, caso positivo, troca ambos de posição, deixando-os em ordem
crescente. Depois é realizada a mesma operação com o primeiro e o segundo número

Então é verificada novamente a necessidade de inverter o segundo e o terceiro
número, para caso o primeiro, que agora está no lugar do segundo, seja maior que
o terceiro.
