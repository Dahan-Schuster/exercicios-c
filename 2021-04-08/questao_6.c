#include <stdio.h>


/**
 * Conta a quantidade de cada dígito de 0 a 9 em n
 * Recebe por referência um vetor de 10 posições em que cada
 * índice i representa a quantidade do dígito i em n 
 * 
 * @author Dahan Schuster
 */
void contarDigitos(int n, int *digitos)
{
    // armazena o valor do dígito de n que está sendo verificado em cada loop
    int digitoAtual = 1;

    // o dígito atual é calculado ao dividir (n % mod) por div
    // a cada iteração, o valor de div e mod incrementa em 10 unidades
    int div = 1, mod = 10;

    /**
     * Quando div chega a uma ordem de grandeza maior que n1, por exemplo,
     * div == 1000 && n1 == 123,  [(div + n1) % div] será igual a n1, por quê:
     * 1000 + 123 == 1123;
     * 1123 % 1000 == 123;
     * 
     * Por outro lado, se a ordem de grandeza de div não for maior, temos que:
     * 100 + 123 == 223;
     * 223 % 100 == 23;
     *
     * Dessa forma, enquanto o resultado da conta for diferente de n1,
     * continua devemos continuar o loop
     * (isto resolve o bug descrito na questão 6 da lista do dia 18/03)
     **/
    while ((div + n) % div != n)
    {
        digitoAtual = n % mod / div;

        // incrementa a quantidade de ocorrências do dígito em n1
        digitos[digitoAtual]++;

        // atualiza os valores de mod e div para que na próxima iteração
        // o resultado do cálculo seja o dígito imediatamente à esquerda
        mod *= 10;
        div *= 10;
    }
}


int ehParDeFoolano(unsigned int n1, unsigned int n2)
{
    // cada índice do vetor irá representar a quantidade do dígito i em n
    // ex.: digitos[2] == 3, então n contém 3 dígitos 2
    int digitosN1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        digitosN2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // conta a quantidade de cada dígito em n1 e n2
    contarDigitos(n1, digitosN1);
    contarDigitos(n2, digitosN2);

    int i, parDeFoolano = 1;

    // itera por ambos os arrays verificando a igualdade
    // da quantidade de cada dígito de n1 em n2
    // parDeFoolano está na condição do for porque, se esse valor
    // for definido como falso, não é necessário continuar o loop
    for (i = 0; i < 10 && parDeFoolano; i++)
        if (digitosN1[i] != digitosN2[i])
            parDeFoolano = 0;

    return parDeFoolano;
}

#define N1 1441
#define N2 4141

int main()
{
    printf("%d\n", ehParDeFoolano(N1, N2));
    return 0;
}