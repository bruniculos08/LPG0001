#include <stdio.h>
#include <math.h>
 
int main() {
    double R, V;

    scanf("%lf", &R);
    V = (4.0*(pow(R,3)*3.14159)/3.0);
    printf("VOLUME = %.3lf\n", V);
    return 0;
}