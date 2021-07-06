#include <stdio.h>


int main(){
    int D, N;
    do {    
        int R = 1, n = 0;
        do
        {
            //printf("Type N: ");
            scanf("%i", &N);
        } while (N < 0 || N > 100);
        do
        {
            //printf("Type D: ");
            scanf("%i", &D);
            if (D == 0 && N == 0) break;
        } while (D < 1 || D > 500);

        if (D == 0 && N == 0) continue;

        int X[D][N];

        for (int i = 0; i < D; i++) for(int j = 0; j < N; j++){
            //printf("Type X[%i][%i]: ", i, j);
            scanf("%i", &X[i][j]);
        }

        for (int j = 0; j < N; j++){ 
            n = 0;
            for(int i = 0; i < D; i++) {
                if (X[i][j] == 1) n++;
                if (n == D) R = 0;
            }
        }

        if (R == 0) printf("yes\n");
        else printf("no\n");

    } while (D != 0 && N != 0);
}