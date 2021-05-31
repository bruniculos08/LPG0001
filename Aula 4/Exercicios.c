#include <stdio.h>


/* 
• Escreva um programa em C que executa conversões de temperatura entre os sistemas
CELSIUS e FAHRENHEIT. Caso o usuário deseje converter de CELSIUS para FAHRENHEIT ele pressiona a tecla C; 
pressionando a tecla F o programa faz a conversão de FAHRENHEIT para CELSIUS. (F = C * (9/5) + 32). 
*/

int tofarenheit(double a);
int tocelsius(double a);


int main(void){
    double temp;
    char option;
    printf("\nType F to converte from farenheit to celsius\n Type F to converte from farenheit to celsius \nYour option: ");
    scanf("%c", option);
    switch (toupper(option))
    {
    case 'F':
        printf("Type the temperature value: ");
        scanf("%lf", &temp);
        tofarenheit(temp);        
        break;
    case 'C':
        printf("Type the temperature value: ");
        scanf("%lf", &temp);
        tocelsius(temp);
    default:
        printf("Invalid option");
        break;
    }
}

int tofarenheit(double a){
    return (9.0*a/5.0 + 32.0); 
}

int tocelsius(double a){
    return (9.0*a/5.0 + 32.0); 
}

/* 
• Altere o programa anterior incluindo duas funções: uma para converter de graus
Celsius para graus Fahrenheit (float CelsiusParaFahr(float)) e outra para converter de graus 
Fahrenheit para Celsius (float FahrParaCelsius(float)). 
*/