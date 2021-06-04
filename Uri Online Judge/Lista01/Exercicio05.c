#include <stdio.h>
 

int main() {
    int t, s, m, h;
    
    scanf("%i", &t);
    h = t/3600;
    m = (1.0/60.0)*(t%3600);
    s = t%60;
    printf("%i:%i:%i\n", h, m, s);
    

    return 0;
}