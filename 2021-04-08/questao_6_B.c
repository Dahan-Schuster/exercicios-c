#include <stdio.h>


/**
 * Conta a quantidade de cada dígito de 0 a 9 em n
 * Retorna um vetor de 10 posições em que cada índice i representa
 * a quantidade do dígito i em n 
 * 
 * @author Dahan Schuster
 */
int contarOcorrenciaDigito(int n, int digito)
{
    int digitoAtual = 1, count = 0;
    int div = 1, mod = 10;

    // mesma lógica utilizada na questão 6A para pegar o dígito atual
    while ((div + n) % div != n)
    {
        digitoAtual = n % mod / div;

        // incrementa a quantidade de ocorrências do dígito em n1
        if (digitoAtual == digito)
            count++;

        // atualiza os valores de mod e div para que na próxima iteração
        // o resultado do cálculo seja o dígito imediatamente à esquerda
        mod *= 10;
        div *= 10;
    }

    return count;
}


int ehParDeFoolano(unsigned int n1, unsigned int n2)
{
    int i, parDeFoolano = 1;
    int countDigitoN1, countDigitoN2;

    // conta a quantidade de cada dígito em n1 e n2
    for (i = 0; i < 10 && parDeFoolano; i++)
    {
        countDigitoN1 = contarOcorrenciaDigito(n1, i);
        countDigitoN2 = contarOcorrenciaDigito(n2, i);

        if (countDigitoN1 != countDigitoN2)
            parDeFoolano = 0;
    }

    return parDeFoolano;
}

#define N1 123
#define N2 124

int main()
{
    printf("%d\n", ehParDeFoolano(N1, N2));
    return 0;
}