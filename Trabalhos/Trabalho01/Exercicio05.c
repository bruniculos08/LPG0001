#include <stdio.h>
#include <math.h>

int main(){
    double q, p, j, n;
    scanf("%lf, %lf, %lf", &p, &j, &n);

    q = (p/j)*(1-powf(1+j,-n));
    printf("q = %.6lf", q);

    if (fabs(q-(q/3.0)*3.0) < 0000.1){
        q = (p/j)*(1-powf(1+j,-n));
        printf("q = %.6lf", q);
    }
    else
    {
        q = (p/j)*(1-powf(1+j,-n));
        printf("q = %.6lf (erro de precisao!)", q);
    }
    
}