#include <stdio.h>
#include <math.h>

float poison(int k);
unsigned int fat(int k);

float poison(int k){
    float u = 300;
    float e = 2.71;
    float pot1 = powf(2.71, -u);
    float pot2 = powf(u, k);
    float pro1 = pot1*pot2;
    float P = (pro1)/(fat(k));
    return P;
}

// µ = numero de ocorrencias esperadas, nesse caso, em média 300 lampadas por dia 
// k = numero de ocorrencia que se queira verificar a possibilidade, sendo 290 ou 320 no proximo dia

unsigned int fat(int k){
    while (k > 2) return k*(fat(k-1));
    return k;
}

int main(){
    printf("P(290, 300) = %f \n", poison(290));
    printf("P(320, 300) = %f \n", poison(320));
}