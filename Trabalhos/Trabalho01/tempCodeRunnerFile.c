#include <stdio.h>
#include <math.h>

float poison(int k);
float fat(int k);

float poison(int k){
    float u = 300;
    int fatk = fat(k);
    float e = 2.71828;
    float P = 1.0*((pow(e, -u))*(pow(u, k)))/(fat(k));
    return P;
}

// µ = numero de ocorrencias esperadas, nesse caso, em média 300 lampadas por dia 
// k = numero de ocorrencia que se queira verificar a possibilidade, sendo 290 ou 320 no proximo dia

float fat(int k){
    while (k > 2) return k*(fat(k-1));
    return k;
}

int main(){
    printf("P(290, 300) = %f \n", poison(290));
    printf("P(320, 300) = %f \n", poison(320));
    printf("P(290, 300) = %f \n", fat(100));
}