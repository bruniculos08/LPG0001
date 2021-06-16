#include <stdio.h>
#include <math.h>
long double poison(long double k);
long double fat(long double k);
long double poison(long double k){
    long double y = 300;
    long double e = 2.71828;
    long double pot1 = expl(-y);
    long double pot2 = powl(y, k);
    long double pro1 = pot1*pot2;
    long double fatk = fat(k);
    long double P = (pro1)/(fatk);
    return P;
}
// y = numero de ocorrencias esperadas, nesse caso, em média 300 lampadas por dia 
// k = numero de ocorrencia que se queira verificar a possibilidade, sendo 290 ou 320 no proximo dia
long double fat(long double k){
    long double result;
    long double i;
    for(i = 1; i <= k; i++ ) {
        result *= i;
    }
    return result;
}
int main(){
    printf("fat(k) = %Lf \n", fat(290)); 
    printf("P(2, 300) = %Lf \n", poison(1)); 
    printf("P(290, 300) = %Lf \n", poison(290));
    printf("P(320, 300) = %Lf \n", poison(320));
}