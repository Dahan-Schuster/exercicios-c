/**
 * Verifica se um número b corresponde ao últimos digitos de a
 * 
 * @author Dahan Schuster
 */
int bFinalizaA(int a, int b)
{   
    /* Nos exemplos, considere a == 123 e b == 23 */

    // Armazena a ordem de grandeza de b
    int mod = 1;

    // incrementa a grandeza enquanto b % mod for diferente de b
    // ex.: 23 %    1 == 0;
    //      23 %   10 == 3; 
    //      23 %  100 == 23;
    //      mod == 100;
    while (b % mod != b)
        mod *= 10;

    // dividindo a por mod, teremos os últimos n dígitos de a, sendo n
    // a quantidade de dígitos de b. Se b corresponder aos últimos
    // dígitos de a, então a % mod == b
    // ex.: 123 % 100 == 23
    if (a % mod == b)
        return 1;

    return 0;
}
