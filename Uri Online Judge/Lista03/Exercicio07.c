#include <stdio.h>
#include <string.h>

int main(){
    int N;

    scanf("%i", &N);
    for(int h = 0; h < N; h++){
        char A[1000], B[1000];
        scanf("%s %s", &A, &B);
        int b = strlen(B), a = strlen(A), v = 0;
    

        if (a < b){
            printf("nao encaixa\n");
            v= 1;
        }
        else {
            for (int i = a-(b), j = 0; i < a; i++, j++) {
                if (A[i] != B[j]){
                    printf("nao encaixa\n"); 
                    v = 1;
                    break;
                }
            }
        }
        if (v == 0) printf("encaixa\n");
    }
}