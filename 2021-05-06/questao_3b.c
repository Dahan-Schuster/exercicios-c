typedef struct {
    float maior;
    float meio;
    float menor;
} MaMeMe;

void classifica (MaMeMe* valores)
{  
    float n1 = valores->maior;
    float n2 = valores->meio;
    float n3 = valores->menor;

    if (n1 > n2) {
        if (n1 > n3) {
            valores->maior = n1;
            
            if (n2 > n3) {
                valores->meio = n2;
                valores->menor = n3;
            } else {
                valores->meio = n3;
                valores->menor = n2;
            }
        } else {
            valores->maior = n3;
            valores->meio = n1;
            valores->menor = n2;
        }
    } else {
        if (n1 < n3) {
            valores->menor = n1;

            if (n2 < n3) {
                valores->maior = n3;
                valores->meio = n2;
            } else {
                valores->maior = n2;
                valores->meio = n3;
            }
        } else {
            valores->maior = n2;
            valores->meio = n1;
            valores->menor = n3;
        }
    }
}