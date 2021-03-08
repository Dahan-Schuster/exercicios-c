# Respostas das questões que não pedem código

## Aluno: Dahan Schuster

&nbsp;  

Abrir preferencialmente com um visualizador de Markdown

&nbsp;  

## 1ª Questão

### a)

O caractere de quebra de linha não é inserido no texto, fazendo com que o próximo texto escrito fique na mesma linha

---

### b)

Um erro de sintaxe é gerado, pois a linguagem C, assim como a maioria das linguagens, trata cada linha como uma instrução isolada.

---

### c)

O texto ficará com uma quebra de linha entre as palavras, e irá imprimir algo como

```c
"Hello
world!"
```

---

### d)

O resultado visual do exemplo será o mesmo de usar um único `printf`, pois a primeira instrução não teve um `\n` no final (ver resposta da letra a)

&nbsp;  

## 3ª Questão

### Resposta: letra E

&nbsp;  

## 7ª Questão

No meu caso, o código foi problemático pois foi utilizado o formatador `%d`, que deve ser utilizado apenas para inteiros, foi usado para tentar formatar um `long int`, isto é, um tipo especial de inteiros que possuem um valor muito grande e, por isso, ocupam mais bits de memória (semelhante à diferença entre `float` e `double`)

&nbsp;  

## 8ª Questão

Acontece que a inclusão do ***.n*** entre os sinais ***%*** e ***f*** do formatador `%f` controla a quantidade de casas decimais do número a ser formatado, e também a forma como o mesmo é arredondado.

Quando o formatador é usado de forma pura (apenas `%f`), o valor mostrado terá seis casas decimais por padrão. Porém, quando se inclui ***.n***, sendo *n* um número inteiro maior que zero, o valor será arredondado para *n* casas decimais.

Por exemplo, `3.16` sendo formatado para `%.0f` ficaria `3`, e para `%.1f` ficaria `3.2`

&nbsp;  

## 9ª Questão

Não, os códigos não são inguais.

O primeiro apenas escreve uma `string` na tela, não fazendo numa operação a mais em relação ao segundo.

Já o segundo código faz duas operações a mais: define três valores numéricos e os inclui em uma string utilizando o formatador de inteiros. Por baixo dos panos, o que está sendo feito é uma formatação de valores dentro de uma string, que só então será escrita na tela.

No exemplo, o resultado visual pode ser o mesmo, mas basta alterar um pouco a escrita para ver que os programas são diferentes.

O que aconteceria se, ao invés de:

```c
printf("1, 2, 3\n)";
printf("%d, %d, %d\n", 1, 2, 3);
```

Tivéssemos o código abaixo?

```c
printf("1 + 2 + 3\n)";
printf("%d, %d, %d\n", 1 + 2 + 3);
```
