/**
 * Retorna o primeiro número da série de Fibonacci que é maior ou igual a n
 * 
 * @author Dahan Schuster
 */
int proxFibonacci(int n)
{
    // inicializa os três primeiros números da série
    int anterior = 0, atual = 1;
    int proximo = atual + anterior;

    // progride na série de Fibonacci até achar um número >= n
    while (proximo < n)
    {
        anterior = atual;
        atual = proximo;
        proximo = atual + anterior;
    }

    return proximo;
}