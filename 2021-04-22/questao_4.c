#include <stdlib.h>
#include <stdio.h>

/**
 * Recebe duas strings e retorna uma string contendo ambas concatenadas
 * 
 * @param char* s1 - a primeira string
 * @param char* s2 - a segunda string
 * @return char* - as strings concatenadas em uma
 * @author Dahan Schuster
 */
char* concatenaStrings (char* s1, char* s2)
{
    int tam1, tam2, tam3;
    for (tam1 = 0; s1[tam1] != '\0'; tam1++);
    for (tam2 = 0; s1[tam2] != '\0'; tam2++);
    
    tam3 = tam1 + tam2;
    char *s3 = (char *)malloc(sizeof (char) * tam3);

    int i, k = 0;
    for (i = 0; i < tam1; i++, k++)
        s3[k] = s1[i];
        
    for (i = 0; i < tam2; i++, k++)
        s3[k] = s2[i];    

    return s3;
}

int main()
{
    char *s3 = concatenaStrings("foo", "bar");
    printf("%s\n", s3);
    
    free(s3);
    return 0.;
}