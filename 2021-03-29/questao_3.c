/**
 * Retorna as casas decimais de um número
 * Isola as casas decimais ao subtrair o inteiro do decimal
 * 
 * @author Dahan Schuster
 */
double casasDecimais (double x)
{   
    int xInteiro = (int)x;
    return x - xInteiro; 
}