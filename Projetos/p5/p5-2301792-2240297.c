/*============================================================================*/
/* MÓDULO QUE DETECTA AS LUZES DO WII SENSOR BAR                              */
/*----------------------------------------------------------------------------*/
/* Autores: Dahan Schuster e Gabriel Franco                                   */
/*============================================================================*/

#include <stdlib.h>
#include <math.h>

#include "imagem.h"
#include "projeto5.h"

#define MIN_VAL 128
#define N_VIZINHOS 5


/*============================================================================*/
/* Struct usada para representar um conjunto de píxeis claros (v >= MIN_VAL)
 * separados por até N_VIZINHOS píxeis não-claros */

typedef struct
{
    int qteItens;
    float xCentro;
    float yCentro;
} Cluster;


/*============================================================================*/
/* Funões auxiliares (cabeçalhos) */

void newCluster(Cluster *c);
void encontraCluster(Imagem1C * img, Cluster *c, unsigned long row, unsigned long col);
void definirPontosEsqDir(Coordenada* l, Coordenada* r, Cluster c1, Cluster c2);

/*============================================================================*/
/* Função central do trabalho. */

/**
 * Detecta dois pontos de claridade numa imagem com 1 canal,
 * e retorna o ângulo entre os pontos e suas coordenadas
 */
double detectaSensorBar (Imagem1C* img, Coordenada* l, Coordenada* r)
{
    Cluster aux, maiorCluster, segMaiorCluster;
    newCluster(&maiorCluster);
    newCluster(&segMaiorCluster);

    unsigned long row, col;
    for (row = 0; row < img->altura; row++)
    {
        for (col = 0; col < img->largura; col++)
        {
            /* Verifica se cada píxel possui claridade suficiente */
            if (img->dados[row][col] >= MIN_VAL)
            {
                /* reinicaliza o cluster auxiliar antes de enviá-lo
                 * à função encontraCluster */
                newCluster(&aux);
                encontraCluster(img, &aux, row, col);

                /* verifica se o cluster encontrado é grande o suficiente */
                /* (queremos os dois maiores) */
                if (aux.qteItens > maiorCluster.qteItens)
                {
                    segMaiorCluster = maiorCluster;
                    maiorCluster = aux;
                }
                else if (aux.qteItens > segMaiorCluster.qteItens)
                {
                    segMaiorCluster = aux;
                }
            }
        }
    }

    /* Encontrados os pontos (dois maiores clusters), define suas
     * posições em relação ao eixo x e retorna o ângulo entre eles */
    definirPontosEsqDir(l, r, maiorCluster, segMaiorCluster);
    return atan2(r->y - l->y, r->x - l->x);
}

/*============================================================================*/
/* Funões auxiliares (implementações) */


/**
 * Construtor de uma variável do tipo Cluster
 */
void newCluster(Cluster *c)
{
    c->qteItens = 0;
    c->xCentro = 0;
    c->yCentro = 0;
}

/**
 * Busca por conjuntos de píxeis claros separados por até N_VIZINHOS píxeis não-claros
 * Utiliza recursão para extender a busca em cada nó (Tranverse Algorithm)
 * O cluster é passado por referência para que seus dados possam ser atualizados entre
 * as chamadas recursivas
 */
void encontraCluster(Imagem1C * img, Cluster *c, unsigned long row, unsigned long col)
{
    c->qteItens++;      /* incrementa a quantidade de píxeis no cluster */
    c->xCentro += col;  /* somatório das coordenadas x, será feita a média no final */
    c->yCentro += row;  /* somatório das coordenadas y */

    img->dados[row][col] = 0; /* "apaga" o píxel atual para evitar repetições */

    /* dx e dy indicam os índices do vizinho acessado em cada loop */
    int i, j, dx, dy;
    /* itera pelos N_VIZINHOS ao redor de img->dados[row][col] */
    for (i = -N_VIZINHOS; i <= N_VIZINHOS; i++)
        for (j = -N_VIZINHOS; j <= N_VIZINHOS; j++)
        {
            dy = row + i;
            dx = col + j;

            /* se os índices forem válidos... */
            if ((dx >= 0 && dx < img->largura) && (dy >= 0 && dy < img->altura))
            {
                /* verifica se o píxel vizinho também é claro e,
                 * portanto, deve fazer parte do cluster */
                if (img->dados[dy][dx] >= MIN_VAL)
                {
                    /* procura recursivamente nos vizinhos do vizinho */
                    return encontraCluster(img, c, dy, dx);
                }
            }
        }

    /* As coordenadas do Cluster são as médias das coordenadas de seus píxeis */
    c->xCentro /= c->qteItens;
    c->yCentro /= c->qteItens;
}

/**
 * Define as coordenadas l e r baseadas na posição dos clusters c1 e c2 no eixo x
 */
void definirPontosEsqDir(Coordenada* l, Coordenada* r, Cluster c1, Cluster c2)
{
    if (c1.xCentro < c2.xCentro)
    {
        l->x = c1.xCentro;
        l->y = c1.yCentro;
        r->x = c2.xCentro;
        r->y = c2.yCentro;
    }
    else
    {
        r->x = c1.xCentro;
        r->y = c1.yCentro;
        l->x = c2.xCentro;
        l->y = c2.yCentro;
    }
}