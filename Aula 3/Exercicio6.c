#include <stdio.h>


/*  Ler um número inteiro e imprimir a seguinte estrutura:
 *
 **
 ***
 ****
 *****
 ****** 
 */


int main(void){
    int n;

    printf("Type the hight for the stairs: ");
    scanf("%i", &n);

    for ( int i = 1; i <= n; i++)
    {
        for ( int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}