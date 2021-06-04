#include <stdio.h>
#include <math.h>

int primo(int n);
int main() {
   
    int N, X, i;
    do scanf("%i", &N); while (N < 1 || N > 100);
    for (i = 0; i < N; i++)
    {
        do scanf("%i", &X); while (X < 1 || X > pow(10, 7));
        if (primo(X) == 0) printf("%i eh primo\n", X);
        else if (primo(X) == 1) printf("%i nao eh primo\n", X);
    }
}

int primo(int n) {
    int j, k = 1;
    if (n%2 == 0 && n != 2) return 1;
    for (j = 3; j < n; j = j + 2){
        if (n%j == 0 && (n != j)) return 1;
    }

    return 0;
}