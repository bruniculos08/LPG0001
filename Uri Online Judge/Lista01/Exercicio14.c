#include <stdio.h>
 

int main() {
    int i, j, sum = 0, N, sums[N], X, Y;

    scanf("%i", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%i %i", &X, &Y);
        if (X%2 == 0) X++; 
        for (j = 0; j < Y; j++)
        {
            sum = sum +(2*j + X);
        }
        sums[i] = sum;
        sum = 0;  
    }
    
    for (i = 0; i < N; i++) printf("%i\n", sums[i]);
    return 0;
}