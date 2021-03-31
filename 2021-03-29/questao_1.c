/**
 * Retorna se um dado ano é bissexto ou não
 * 
 * @author Dahan Schuster
 */
int ehBissexto(int ano)
{
    if (ano % 100 != 0 && ano & 4 == 0)
        return 1;

    return 0;
}