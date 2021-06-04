#include <stdio.h>
#include <math.h> 

int main() {
    int i, T, PA, PB, n;

    float G1, G2;
    scanf("%i", &T);
    int years[T];
    for (i = 0; i < T; i++)
    {
        do
        {
            scanf("%i %i %f %f", &PA, &PB, &G1, &G2);
        } while (PA >= PB); // || 100 > PA || PA > 1000000 || PB > 1000000 || 0.1 > G1 || G1 > 10.0 || 0.0 > G2 || G2 > G1 || G2 > 10.0);
        for (n = 1; PA <= PB; n++)
        {   
            years[i] = n;  
            if (n > 100) break;
            PA = PA + floor((G1/100.0)*PA);
            PB = PB + floor((G2/100.0)*PB);
        }
    }
    for (i = 0; i < T; i++) if(years[i] <= 100) printf("%i anos.\n", years[i]); 
    else printf("Mais de 1 seculo.\n");
    return 0;
}