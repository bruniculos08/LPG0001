#include <stdio.h>
#include <string.h>


int main(void){
    
    char a;
    printf("type \"c\" for circle, \"s\" for square or \"t\" for triangle: ");
    scanf("%s", &a);

    switch(a) {
        float A, r, s, b, h;
        case 'C':
            printf("type it radius: ");
            scanf("%f", &r);
            A = (2*(3.14)*r);
            printf("area = %f", A);
        break;
        case 's':
            printf("type it side: ");
            scanf("%f", &s);
            A = s*s;
            printf("area = %f", A);
        break;
        case 't':
            printf("type the size of the base and of the height (like: base, height):");
            scanf("%f, %f", &b, &h);
            //scanf("%f,", &b);
            //scanf("%f", &h);
            A = (b*h)/2;
            printf("area = %f", A);
        break;

        default:
            printf("Not registered item.");
    }

}