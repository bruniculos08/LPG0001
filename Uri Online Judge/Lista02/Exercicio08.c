#include <stdio.h>
#include <stdlib.h>

int main(){
    double M[12][12], result = 0;
    char O;
    int n = 0;
    scanf("%c", &O);
    for(int i = 0; i < 12; i++) for(int j = 0; j < 12; j++) scanf("%lf", &M[i][j]);
    if (toupper(O) == 'S'){
        for (int i = 0; i < 12; i++) for(int j = 0; j <= 10-i; j++) result += M[i][j];
    }
    if (toupper(O) == 'M'){
        for (int i = 0; i < 12; i++) for(int j = 0; j <= 10-i; j++) {
            result += M[i][j];
            n++;
            }
        
        result = result/n;
    }
    printf("%.1lf\n", result);
}