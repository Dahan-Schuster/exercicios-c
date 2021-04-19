unsigned char calculaParidade(unsigned char b)
{
    int i;
    int bitAtivoEmI;
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