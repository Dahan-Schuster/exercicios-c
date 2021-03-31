/**
 * Calcula a potência de um número com expoente positivo
 * 
 * @author Dahan Schuster
 */
unsigned long long potencia (unsigned int base, unsigned int expoente)
{
    // chamada recursiva até chegar ao expoente 1
    if (expoente > 1)
        return base * potencia(base, expoente - 1);
    return base;
}