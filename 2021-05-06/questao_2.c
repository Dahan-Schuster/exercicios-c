typedef struct
{
    int h;
    int m;
    int s;
} Horario;

int segundosEntre (Horario h1, Horario h2)
{
    int segH2, segH1;

    segH1 = h1.h * 3600 + h1.m * 60 + h1.s;
    segH2 = h2.h * 3600 + h2.m * 60 + h2.s;

    return segH2 - segH1;
}