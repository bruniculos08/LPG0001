#include <stdio.h>
#include <math.h>

int main() {
    int N, X, sumdiv = 0, i, j;//, numbers[N], result[N];

    do scanf("%i", &N); while (N < 1 || N > 20);
    //for (i = 0; i < N; i++) scanf("%i ", &numbers[i]);
    for (i = 0; i < N; i++)
    {
        //X = numbers[i];
        do scanf("%i", &X); while(X < 1 || X > pow(10,8));
        for (j = 1; j < X; j++)
        {
            if (X%j == 0) sumdiv += j;
            else if (sumdiv > X) break;
        }
        //if (sumdiv == X) result[i] = 0;
        //else result[i] = 1;
        if (sumdiv == X) printf("%i eh perfeito\n", X);
        else printf("%i nao eh perfeito\n", X);
        sumdiv = 0;
    }
    //for (i = 0; i< N; i++) if (result[i] == 0) printf("%i eh perfeito\n", numbers[i]);
    //else printf("%i nao eh perfeito\n", numbers[i]);
    
    return 0;
}