#define PICO 1
#define VALE 2
#define SUBIDA 3
#define DESCIDA 4

int leProximoDado();
void registraPadrao(int posicao, int tipo);

/**
 * Procura por padrões em sequências de três valores
 * 
 * @author Dahan Schuster
 */
int main()
{
    // incializa as variáveis de controle
    int anterior = leProximoDado(),
        atual = leProximoDado(),
        proximo = leProximoDado();

    // Tipo de padrão encontrado. 0 representa nenhum
    int tipo = 0;

    // Posição onde o padrão foi encontrado
    // Como o pivô é sempre o valor do meio, a posição começa por 2
    int posicao = 2;

    // Repete enquanto houver uma combinação de três valores positivos
    while (anterior > -1 && atual > -1 && proximo > -1)
    {
        // o valor do meio é maior que seus vizinhos
        if (atual > anterior && atual > proximo)
        {
            tipo = PICO;
        }
        // o valor do meio é menor que seus vizinhos
        else if (atual < anterior && atual < proximo)
        {
            tipo = VALE;
        }
        // o valor do meio forma uma crescente com seus vizinhos
        else if (atual > anterior && atual < proximo)
        {
            tipo = SUBIDA;
        }
        // o valor do meio forma uma decrescente com seus vizinhos
        else if (atual < anterior && atual > proximo)
        {
            tipo = DESCIDA;
        }

        // se um tipo de padrão foi encontrado...
        if (tipo)
        {
            registraPadrao(posicao, tipo);
        }

        // Prepara as variáveis para a próxima iteração
        posicao++; // atualiza o valor da posição do próximo pivô
        tipo = 0;  // redefine o padrão encontrado para nenhum

        // Move a sequência para a esquerda
        anterior = atual;
        atual = proximo;
        proximo = leProximoDado();
    }
}