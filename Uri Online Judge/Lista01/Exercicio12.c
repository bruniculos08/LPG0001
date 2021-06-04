#include <stdio.h>
 
int main() {
     int i, j;
     float a, b;
    
    for (i = 0; i <= 20; i= i + 2)
    {
        for (j = 10 + i; j <= 30+i; j = j+10){
            if (i != 0.00 && i != 10 && i != 20 && i != 30){
                a = i/10.0;
                b = j/10.0;
                printf("I=%.1f J=%.1f\n", a, b);                
            }
            else printf("I=%i J=%i\n", i/10, j/10);
        }
    }


    return 0;
}