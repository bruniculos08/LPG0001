#include <stdio.h>
#include <math.h>

int main(){
    double q, p, j=0, h = 0;
    int n;
    scanf("%lf", &q);
    scanf("%lf", &p);
    scanf("%i", &n);

    for(int i=1; h = 1; i++) {
        j = j + 0.00000001;
        if (fabsl(q - ((p/j)*(1-powl(1.000000+j,-n)))) <= 0.000001)
        {
            printf("j = %.10lf", j); //demora bastante tempo só pra avisar
            break;
        }
    }
}