#include <stdio.h>


/* Escrever um algoritmo que gere e escreva os números
múltiplos de 11 entre 100 e 200. */

int main (void){
    int i = 0;

    while (i*11 <= 200){
        if (11*i >= 100 && 11*i <=200){
            printf("%i\n", 11*i);
        }
        else if (11*i > 200){
            break;
        }
        
        i++;
    }
}