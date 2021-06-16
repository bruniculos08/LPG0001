#include <stdio.h>
#include <math.h>

long double poison(long int k);
double fat(int k);

long double poison(long int k){
    long double y = 300;
    long double e = 2.71828;
    long double pot1 = powl((1.0000/e), y);
    long double pot2 = powl(y, k);
    long double pro1 = pot1*pot2;
    long int fatk = fat(k);
    long double P = (pro1)/(fatk);
    return P;
}

// y = numero de ocorrencias esperadas, nesse caso, em média 300 lampadas por dia 
// k = numero de ocorrencia que se queira verificar a possibilidade, sendo 290 ou 320 no proximo dia

double fat(int k){
    double result;
    unsigned long long int i;
    for(i = 1; i <= k; i++ ) {
        result *= i;
    }
    return result;
}

int main(){
    printf("fat(k) = %lli \n", fat(290)); 
    printf("P(2, 300) = %Le \n", poison(1)); 
    printf("P(290, 300) = %Le \n", poison(290));
    printf("P(320, 300) = %Le \n", poison(320));
}