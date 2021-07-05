#include <stdio.h>


unsigned long long int fib(unsigned long long int n);

int main(){
    unsigned int t, i;
    scanf("%u", &t);
    unsigned long long int x[t], n[t];

    for (i = 0; i < t; i++)
    {
        do
        {
            scanf("%llu", &n[i]);        
        } while (n[i] < 0 || n[i] > 60);
        x[i] = fib(n[i]);
        //printf("Fib(%d) = %d\n", n[i], x[i]);   
    }
    for (i = 0; i < t; i++) printf("Fib(%llu) = %llu\n", n[i], x[i]);
}

unsigned long long int fib(unsigned long long int n){
    unsigned long long int fib1 = 1, fib2 = 1, k, result;
    if (n>2){
        for (k = 3; k <= n; k++){
            result = fib1 + fib2;
            fib1 = fib2;
            fib2 = result;
        }
        return fib2;
    }
    else if (n==0){
        return 0;
    }
    else if (n==1 || n==2){
        return 1;
    }
}

/*
^ Os 2 primeiros valores são 1 e 0 e cada próximo termo é a soma dos dois anteriores ao mesmo.
?              fib2 + fib1  =  fib1 + fib2|result               
TODO: Fb(4) = Fb(3) + Fb(2) = Fb(2) + Fb(1) + Fb(2) = 3
TODO: Fb(n) = Fb(n-1) + Fb(n-2) = Fb(n-2) + Fb(n-3) + Fb(n-3) + Fb(n-4)
?                   Fb(n)      =      Fb(n-1)      +      Fb(n-2)         
*/