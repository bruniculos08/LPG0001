#include <stdio.h>
#include <stdlib.h>

// como os exercícios passados eram relativamente simples(apenas pra desenferrujar) fiz cada questão como uma função neste único arquivo
// assim já relembro um pouco de funções, ponteiros e endereços


int a, b, t;

int soma( int a, int b){
    return (a+b);    
}

int strangemedia(int a, int b){
    return ((a*4)+(b*0,6))/2;
}


void troca(int *a, int *b){ // void pois não retorna nada 
    int temp = *a;          // perceba que a função recebe os ponteiros que nesse caso devem ser os endereços &a e &b
    *a = *b;                // em uma variável "int *x" temos "*" que indica "pegar o que está no endereço 'x'('x' é uma variável que armazena um número de endereço)"
    *b = temp;              // um endereço de uma variável "y" é dado por "&y"  

}


double converteFahrenheit(double t){
    double t2 = ((9*t)/5 + 32);
    return ((9*t)/5 + 32);
}


int main(void){
    
    printf("\ninsert a: ");
    scanf("%i", &a);
    printf("\ninsert b: ");
    scanf("%i", &b);

    printf("\nsoma: %i \n", soma(a, b));

    printf("\nmedia estranha = %i \n", strangemedia(a, b));
 
    troca(&a, &b);
    printf("\ntroca: a = %d, b = %d\n", a, b);
    
    printf("\ndigite uma temperatura em graus celsius: ");
    scanf("%d", &t);

    printf("\ntemperatura em fahrenheit = %4.f", converteFahrenheit(t));

}