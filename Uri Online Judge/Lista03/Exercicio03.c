#include <stdio.h>
#include <string.h>

int main(){
    int D, N;
    do
    {
        D = 0;
        N = 0;
        do
        {
            scanf("%i %i", &D, &N);
            if (D == 0 && N == 0) break;
        } while ((D < 1 || D > 9) && (N < 1 || N > 10000));
        if (D == 0 && N == 0) continue;
        
        char number[10], digit[1]; 
        sprintf(number, "%i", N);
        sprintf(digit, "%i", D);

        int L = strlen(number);
        int result = 0;
        
        for (int i = 0, n = 1; i < L; i++){
            if (number[i] != digit[0]){
                result += (number[i]-'0')*n;
                n = n*10;
            }
        }
        printf("%i\n", result); 

        
    } while (D!=0 || N!=0);
}