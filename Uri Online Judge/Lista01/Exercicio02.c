#include <stdio.h>
#include <math.h>
 
int main() {
    double r, area;
    
    scanf("%lf", &r);
    area = 3.14159*(pow(r,2));
    printf("A=%.4lf\n", area);
    return 0;
}