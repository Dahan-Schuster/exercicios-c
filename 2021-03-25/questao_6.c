#include <stdio.h>

/**
 * Gera um losango de caracteres ASCII
 * 
 * Para chegar ao algoritmo, alguns exemplos de triângulo foram desenhados no
 * papel no formato de matriz, com os valores 0 para espaços e 1 para caracteres
 * A partir desa representação, tentei encontrar padrões que levassem em conta
 * a coluna e a linha de cada célula da matriz
 * 
 * Observei que existem fórmulas que dão o valor 0 ou 1 pertencente a cada
 * célula, e que estas fórmulas variam de acordo com o quadrante em questão,
 * mas todas seguem o mesmo princípio: quantor maior a distância da linha para
 * a linha central, menor será a quantidade de colunas pertencentes ao losango
 *
 * A diferença entre cada fórmula consiste em normalizar os valores para chegar
 * ao mesmo resultado
 * 
 * @author Dahan Schuster
 */
int main()
{
    int n;
    char caractere, lixo;

    scanf("%c%c", &caractere, &lixo);
    scanf("%d", &n);

    int linha, coluna;
    int largura = 2 * n + 1;

    // a altura do losango é igual à sua altura, então
    // cada iteração do for externo será uma linha
    for (linha = 0; linha < largura; linha++)
    {
        // cada iteração do for interno será uma coluna
        for (coluna = 0; coluna < largura; coluna++)
        {
            // O cálculo é separado por quadrantes
            // O primeiro if verifica os quadrantes da esquerda
            // Em cada if interno, a primeira condição verifica o quadrante
            // superior e a segunda verifica o quadrante inferior (linha >= n)
            if (coluna <= n)
            {
                if (coluna < (n - linha) || (linha >= n && coluna < (linha - n)))
                {
                    printf("  ");
                }
                else
                {
                    printf("%c ", caractere);
                }
            }
            else
            {
                if (coluna > (n + linha) || (linha >= n && coluna > n + linha - ((linha - n) * 2)))
                {
                    printf("  ");
                }
                else
                {
                    printf("%c ", caractere);
                }
            }
        }
        printf("\n");
    }

    return 0;
}