#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int N;
    do
    {
        scanf("%i", &N);
    } while (N < 1 || N > 10000);
    for(int i = 0; i <= N; i++){
        char phrase[10000], phrase_alterated[10000], aux[10000], aux1[10000];
        gets(phrase);
        int L = strlen(phrase);

        for (int j = 0; j < L; j++)
        {
           if ((phrase[j] >= 97 && phrase[j] <= 122)||(phrase[j] >= 65 && phrase[j] <= 90)){
                phrase_alterated[j] = phrase[j]+3;
           }
           else phrase_alterated[j] = phrase[j];
        }
        for (int j = L-1; j >= 0; j--)
        {
           aux[L-j-1] = phrase_alterated[j];
        }
        strcpy(phrase_alterated, aux);
        for (int j = (L/2); j < L; j++)
        {
            phrase_alterated[j] = phrase_alterated[j]-1;
        }
        printf("%s", phrase_alterated);
        for (int k = 0; k < strlen(aux); k++) {
            phrase_alterated[k] = '\0'; 
            aux[k] = '\0';
            phrase[k] = '\0';
        }
    }
    printf("\n");
}