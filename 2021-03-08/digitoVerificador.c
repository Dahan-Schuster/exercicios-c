#include <stdio.h>

int * separarDigitos(int numero)
{
    static int digitos[3];
    
    digitos[0] = (numero % 10);
    digitos[1] = (numero % 100 / 10);
    digitos[2] = (numero / 100);

    return digitos;
}

int inverterNumero(int numero)
{
    int *digitos = separarDigitos(numero);
    return digitos[0] * 100 + digitos[1] * 10 + digitos[2];
}

int main()
{
    int numeroConta;

    printf("Olá! Este programa calcula o dígito verificado para o número de uma conta corrente. Shall we begin?\n\n");

    printf("Primeiro, digite o número da conta (três dígitos): ");
    scanf("%d", &numeroConta);

    if (numeroConta < 100 || numeroConta > 999)
    {
        printf("Número inválido!");
        return 0;
    }

    int numeroInvertido = inverterNumero(numeroConta),
        soma = (numeroConta + numeroInvertido) % 1000,
        
        *digitos = separarDigitos(soma),
        somaDosDigitosMultiplicados =
            digitos[0] * 1 +
            digitos[1] * 2 +
            digitos[2] * 3,

        digitoVerificador = somaDosDigitosMultiplicados % 10;

    printf("Conta com dígito verificador: %d-%d\n", numeroConta, digitoVerificador);

    return 0;
}
