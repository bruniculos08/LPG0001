#include <stdio.h>
#include <ctype.h>

int main(){
    double M[12][12], result = 0;
    char O;
    int n = 0;

    scanf("%c", &O);
    for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) scanf("%lf", &M[i][j]);

    if (toupper(O) == 'S'){
        for (int i = 0; i < 12; i++) if(i <= 5) {
            for (int j = 11; j >= 12-i; j--) result += M[i][j];
        }

        else if (i > 5) for (int j = 11; j > i; j--) result += M[i][j];
    }

    if (toupper(O) == 'M'){
        for (int i = 0; i < 12; i++) if(i <= 5) for (int j = 11; j >= 12-i; j--){
            result += M[i][j];
            n++;
        }
        else if (i > 5) for (int j = 11; j > i; j--) result += M[i][j];
        result = (result/n);
    }

    printf("%.1lf\n", result);
}