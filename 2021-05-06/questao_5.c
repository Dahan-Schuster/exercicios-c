#include <stdlib.h>
#include <stdio.h>

#define LARG 4
#define ALT 4

typedef struct
{
    int largura;
    int altura;
    unsigned char **dados;
} GSImage;

void destroiGSImage(GSImage *img)
{
    int i;
    for (i = 0; i < img->altura; i++)
        free(img->dados[i]);
    free(img->dados);
    free(img);
}

GSImage *criaGSImage(int largura, int altura)
{
    GSImage *img;

    img = (GSImage *)malloc(sizeof(GSImage));
    img->dados = (unsigned char **)malloc(altura * (sizeof(unsigned char *)));

    int i;
    for (i = 0; i < altura; i++)
        img->dados[i] = (unsigned char *)malloc(largura * sizeof(unsigned char));

    img->altura = altura;
    img->largura = largura;

    return img;
}

GSImage *reduzPelaMetade(GSImage *img)
{
    if (img->largura % 2 != 0 || img->altura % 2 != 0)
        return NULL;

    GSImage *imgReduzida = criaGSImage(img->largura / 2, img->altura / 2);

    int i, j, media;
    for (i = 0; i < img->altura; i += 2)
        for (j = 0; j < img->largura; j += 2)
        {
            media = img->dados[i][j] +
                    img->dados[i + 1][j] +
                    img->dados[i][j + 1] +
                    img->dados[i + 1][j + 1];
            media /= 4;

            imgReduzida->dados[i / 2][j / 2] = media;
        }

    return imgReduzida;
}

GSImage *montaGSImage()
{
    GSImage *img = criaGSImage(LARG, ALT);

    int i, j;
    for (i = 0; i < ALT; i++)
        for (j = 0; j < LARG; j++)
            img->dados[i][j] = i * j;
            
    GSImage *imgReduzida = reduzPelaMetade(img);

    float mediaImg = 0, mediaImgReduzida = 0;
    for (i = 0; i < ALT; i += 2)
        for ( j = 0; j < LARG; j += 2)
        {
            mediaImgReduzida += imgReduzida->dados[i / 2][j / 2];
            mediaImg += img->dados[i][j] +
                    img->dados[i + 1][j] +
                    img->dados[i][j + 1] +
                    img->dados[i + 1][j + 1];
        }

    mediaImgReduzida /= (ALT / 2) * (LARG / 2);
    mediaImg /= ALT * LARG;

    printf("%.2f\n%.2f\n", mediaImg, mediaImgReduzida);
}