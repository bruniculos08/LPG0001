#include <stdio.h>
#include <math.h>

int main(){
    double q, p, j, n;
    scanf("%lf, %lf, %lf", &p, &j, &n);

    q = (p/j)*(1-powf(1+j,-n));
    printf("q = %.6lf", q);
}