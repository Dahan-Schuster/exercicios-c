/**
 * Arrendonda um número decimais para o seu inteiro mais próximo
 * 
 * @author Dahan Schuster
 */
int arredonda(double x)
{
    // guarda o valor inteiro do número decimal
    int xInteiro = (int)x;

    // isola as casas decimais ao subtrair o inteiro do decimal
    double decimais = x - xInteiro;

    // verifica se os decimais são negativos, se sim transfora em positivos
    if (decimais < 0)
        decimais *= -1;

    // Para valores maiores que 0.5, arrendonda para o maior inteiro absoluto
    if (decimais >= 0.5)
        return x >= 0       /* Verifica se x é positivo */
                   ? x + 1  /* Sim. Ex.: x =  1.5 → return  2 */
                   : x - 1; /* Não. Ex.: x = -1.5 → return -2 */

    // Para valores menores que 0.5, retorna a parte inteira de x
    else
        return xInteiro;
}