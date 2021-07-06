#include <stdio.h>


int main(){
    int N;
    do{
        int n = 0;
        do{
            scanf("%i", &N);
            if (N == 0) break;
        } while (N < 5 || N > 5000);
        
        if (N == 0) continue;
        int X[N];
        //printf("Start X\n");
        for (int i = 0 ; i < N ; i++){
            do {
                scanf("%i", &X[i]);
                if (X[i]!=0 && X[i]!=1) printf("Type 0 or 1\n");
            } while (X[i]!=0 && X[i]!=1);
        }

        //for (int i = 0 ; i < N; i++) printf("X[%i] = %i\n", i, X[i]);

        if (X[0] == 0 && X[N-1] == 0) n++;
        for (int i = 0, k = 0 ; i < N ; i++) {
            if (X[i] == 0) k++;
            if (X[i] == 1) k = 0;
            if (k==2){
                n++;
                k = 0;
            } 
        }

        printf("%i\n", n);

    } while (N!=0);
    printf("\n");
}
//^ Errado:   0 0 0 1 0 0 0 0 1 1 1 1 0 1 0 0 1
//* Certo:    "|1|"""""|1|"|1|"""""""""""""|1|"
//todo        (n+1)  (n+1)(n+1)           (n+1)