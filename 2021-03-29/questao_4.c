/**
 * Verifica se a sequência de números n1 a n4 forma um progressão aritimética
 * 
 * @return 0 caso não seja PA; caso contrário, a razão da PA
 * @author Dahan Schuster
 */
int ehProgressaoAritmetica(int n1, int n2, int n3, int n4)
{
    // a razão é a diferença entre dois termos consecutivos
    int razao = n2 - n1;

    // se as demais razões diferirem da primeira calculada, não é PA
    if (n3 - n2 != razao || razao != n4 - n3)
        return 0;

    // caso contraio, é PA. Retorna a razão
    return razao;
}