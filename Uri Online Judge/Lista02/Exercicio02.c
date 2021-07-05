#include <stdio.h>


int main(){
    int x, z, n, i = 1;
    scanf("%i", &x);
    do
    {
        scanf("%i", &z);
    } while (z <= x);

    n = x;
    
    while (n <= z){
        n += x+i;
        i++;    
    }

    printf("%i\n", i);
}