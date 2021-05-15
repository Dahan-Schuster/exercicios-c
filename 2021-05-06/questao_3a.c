
typedef struct
{
    float maior;
    float meio;
    float menor;
} MaMeMe;

MaMeMe classifica(float n1, float n2, float n3)
{
    MaMeMe mmm;

    if (n1 > n2)
    {
        if (n1 > n3)
        {
            mmm.maior = n1;

            if (n2 > n3)
            {
                mmm.meio = n2;
                mmm.menor = n3;
            }
            else
            {
                mmm.meio = n3;
                mmm.menor = n2;
            }
        }
        else
        {
            mmm.maior = n3;
            mmm.meio = n1;
            mmm.menor = n2;
        }
    }
    else
    {
        if (n1 < n3)
        {
            mmm.menor = n1;

            if (n2 < n3)
            {
                mmm.maior = n3;
                mmm.meio = n2;
            }
            else
            {
                mmm.maior = n2;
                mmm.meio = n3;
            }
        }
        else
        {
            mmm.maior = n2;
            mmm.meio = n1;
            mmm.menor = n3;
        }
    }

    return mmm;
}