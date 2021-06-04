#include <stdio.h>


int main() {
   float perimetro, area, A, B, C;
   
   scanf("%f %f %f", &A, &B, &C);
   if (A < B + C && B < A + C && C < A + B) {
       perimetro = A + B + C;
       printf("Perimetro = %2.1f\n", perimetro);
   }
   else {
       area = (A+B)*(C/02.0);
       printf("Area = %2.1f\n", area);
   }
   return 0;
}