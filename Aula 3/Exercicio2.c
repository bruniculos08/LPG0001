#include <stdio.h>


/* 
Escrever um algoritmo que lê 5 valores, um de cada vez, e
conta quantos destes são negativos, escrevendo esta
informação.
*/


int main (void){
    int i, count = 0;
    double b;
    for (i = 0; i < 5; i++){
        printf("Type the number %i: ", (i+1));
        scanf("%lf", &b);

        if (b < 0){
            count++;
        }
        
        b = 0;
    }
    printf("number of negative numbers = %d", count);
}