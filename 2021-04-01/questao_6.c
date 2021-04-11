#define ASEGB 1
#define BSEGA 2

int bFinalizaA(int a, int b);

/**
 * Verifica se o menor número entre os parâmetros é segmento do outro
 * 
 * @author Dahan Schuster
 */
int menorSegmentoMaior(int a, int b)
{
    int menor, maior;

    // Guarda a informação do número considerado como segmento do outro
    // Esta variável poderia ser removida, pois a variável menor faz seu
    // trabalho, mas seu nome deixa o código mais claro no final
    int segmento;

    if (a < b)
    {
        maior = b;
        menor = segmento = a;
    }
    else
    {
        maior = a;
        menor = segmento = b;
    }

    // Verifica se o menor número corresponde aos últimos dígitos do maior
    // Se sim, menor é segmento de maior
    // Se não, divide o maior por 10, removendo seu último dígito,
    // e verifica novamente
    int menorFinalizaMaior = 0;

    /* ex.:
        menor |   maior | menorFinalizaMaior
        ------------------------------------
         1243 | 2212435 |        0
         1243 |  221243 |        1
        ------------------------------------
          678 |  567890 |        0
          678 |   56789 |        0
          678 |    5678 |        1
        ------------------------------------
          235 |     236 |        0
          235 |      23 |        0
          235 |       2 |        0
          235 |       0 |        0
    */
    while (!menorFinalizaMaior && maior != 0)
    {
        menorFinalizaMaior = bFinalizaA(maior, menor);
        maior /= 10;
    }


    // Como visto na tabela de exemplo, menorFinalizaMaior fica com
    // valor 0 quando o segmento não foi encontrado
    if (!menorFinalizaMaior)
        return 0;

    else if (segmento == a)
        return ASEGB;

    return BSEGA;
}

/**
 * Verifica se um número b corresponde ao últimos digitos de a
 * 
 * @author Dahan Schuster
 */
int bFinalizaA(int a, int b)
{
    int mod = 1;

    while (b % mod != b)
        mod *= 10;

    if (a % mod == b)
        return 1;

    return 0;
}