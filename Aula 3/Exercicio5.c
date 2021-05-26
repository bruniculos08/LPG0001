#include <stdio.h>


/* 
Escrever um algoritmo que escreve 
os números primos entre 100 e 200, 
bem como a soma destes números. 
*/


int prime(int x);

int main(void){
    printf("Started\n");
    int sum = 0;
    for (int k = 100; k <=200; k++){
        if (prime(k) == 0){
            printf("\n%i", k);
            sum = sum + k;
        }
    }
    printf("\nsum of the prime numbers between 100 and 200 = %i", sum);
}

int prime(int x){
    int n = 0, i;
    for (i = 2; i < x; i = (2*n) + 1){
        n = n+1;
        if (x%i == 0)
        {
            return 1;
        }
    }
    return 0;
}