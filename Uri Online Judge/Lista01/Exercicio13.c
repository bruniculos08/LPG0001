#include <stdio.h>
 

int main() {
    int X, Z, sum = 0, next, n = 1;

    scanf("%i", &X);
    do
    {
        scanf("%i", &Z);
    } while (Z <= X);
    

    for (n = 0; sum < Z; n++)
    {
        next = X + n;
        sum = sum + next;
    }

    printf("%i\n", n);
    return 0;
}