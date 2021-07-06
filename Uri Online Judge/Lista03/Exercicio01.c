#include <stdio.h>
#include <string.h>

int main(){
    char nome[20]; 

    double total, salario, vendas;

    gets(nome); 
    scanf("%lf", &salario);
    scanf("%lf", &vendas);

    total = salario + 0.15*vendas;
    printf("TOTAL = R$ %.2lf\n", total);
}