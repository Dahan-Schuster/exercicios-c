#include <stdio.h>

#define MIN_TERMO 0.2

int main()
{
    float termo = 1,
          total = 0,
          denomidador = 1;

    while (termo >= MIN_TERMO)
    {
        total += termo;
        printf("%f\t%f\n", termo, total);

        denomidador++;
        termo = 1 / denomidador;
    }

    return 0;
}