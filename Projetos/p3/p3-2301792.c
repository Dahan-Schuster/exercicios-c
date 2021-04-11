/*************
 * Função 1 *
 *************/


#define KG 1000

/**
 * Para que o programa funcione da forma padrão,
 * basta igualar largura_faixa ao peso
 * 
 * @author Dahan Schuster 
 */
float calculaValorDevido(
    float peso,
    float custo_fixo,
    float preco_kg,
    float largura_faixa,
    float desconto_faixa,
    float desconto_max)
{
    // Inicializa o valor devido com o custo fixo
    float valor_devido = custo_fixo;

    // Calcula o valor bruto (sem desconto) de cada faixa de peso
    float valor_bruto_faixa = preco_kg * largura_faixa / KG;

    // Conta quantas faixas o peso total preencheu
    // Ex.: peso = 200, largura_faixa = 80 -> faixas_peso = 2.5
    float faixas_peso = peso / largura_faixa;

    // Equivale ao valor do contador i na última iteração
    // Utilizado para garantir que valores de peso quebrados, isto é,
    // que não preenchem completamente todas as faixas, possuam seu valor
    // cobrado porporcionalmente
    int ultima_faixa = (int)faixas_peso;

    // Calcula quanto da última faixa o peso preenche
    // Ex.: largura = 80, peso = 200:
    //      faixa | p restante | % preenchida
    //        0   |      120   |     100%
    //        1   |       40   |     100%
    //        2   |        0   |      50% -> será cobrado 50% da última faixa
    float prct_peso_ultima_faixa = faixas_peso - ultima_faixa;

    // Guarda quantos % de desconto cada faixa terá
    float prct_desconto;

    int i;

    // Itera pelas faixas de peso preenchidas pelo peso total,
    // calculando o valor de cada uma
    for (i = 0; i < faixas_peso; i++)
    {
        // O desconto considera o loop atual. No primeiro loop não há desconto
        prct_desconto = (desconto_faixa * i);

        if (prct_desconto > desconto_max)
            prct_desconto = desconto_max;

        // Caso seja a última iteração, recalcula o valor bruto para ser
        // equivalente ao peso
        if (i == ultima_faixa)
            valor_bruto_faixa *= prct_peso_ultima_faixa;

        valor_devido += valor_bruto_faixa * (1 - prct_desconto);
    }

    return valor_devido;
}

/*************
 * Função 2 *
 *************/

#define BIT_INICIAL 0x01

/**
 * @author Dahan Schuster
 */
unsigned char calculaParidade(unsigned char b)
{
    int i;

    // guarda o valor do bit ativo em cada loop
    int bitAtivoEmI;

    // guarda a quantiadde de bits ativos em b
    int bitsAtivos = 0;

    /**
     * Em cada iteração, compara o bit ativo em i com os bits de b,
     * sendo i a posição de cada bit. Ou seja, verifica índex a índex
     * se os bits de b estão ativos
     * 
     *  i | bitAtivoEmI
     *  0 |  0000 0001
     *  1 |  0000 0010
     *  2 |  0000 0100
     *  3 |  0000 1000
    */    
    for (i = 0; i < 8; i++)
    {
        // o operador << move o bit inicial (0001) i vezes para a esquerda
        bitAtivoEmI = BIT_INICIAL << i;
        
        // O operador & irá comparar os bits de b com o bit ativo em i, e
        // retornar "true" (um valor != de zero que neste caso vale true)
        // caso o bit ativo em i esteja ativo também b 
        //
        //      b     | bitAtivoEmI | b & bitAtivoEmI
        //  0000 1000 |  0000 0001  |  0000 0000 == 0
        //  0000 1000 |  0000 1000  |  0000 1000 == 8  
        //  0101 0101 |  0001 0000  |  0001 0000 == 16
        if (b & bitAtivoEmI)
            bitsAtivos++;
    }

    
    return bitsAtivos % 2 != 0;
}

/*************
 * Função 3 *
 *************/

/**
 * @author Dahan Schuster
 */
unsigned int fourcc (char c1, char c2, char c3, char c4)
{
    return (c1 * 0x1) + (c2 * 0x100) + (c3 * 0x10000) + (c4 * 0x1000000);
}


/*************
 * Função Extra ???????? *
 *************/

#include <stdio.h>
int main()
{
    printf("%d\n", fourcc('D', 'I', 'V', 'X'));

    return 0;
}