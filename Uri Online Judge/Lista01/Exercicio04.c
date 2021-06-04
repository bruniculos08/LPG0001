#include <stdio.h>
 

int main() {
    int t,v,s; 
    
    scanf("%i", &t);
    scanf("%i", &v);
    
    s = t*v;
    double gasoline = s/12.0;
    
    
    printf("%.3lf\n", gasoline);
    return 0;

}