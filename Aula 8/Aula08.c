/*
& Ponteiros para funções

* O C permite que acessemos não só variáveis através de ponteiros. Podemos também acessar funções através de ponteiros.

* Pode-se desta forma passar uma função como argumento de uma outra função.

* Sintaxe: <tipo> (*<identificador>) (<parametros>);
*/
float (*func) (float, float);
/*
? Os parênteses em torno de *func são essenciais, pois sem eles o compilador entenderia o argumento como uma
? função que retorna um ponteiro para um inteiro.

* Pode-se também fazer um ponteiro para uma função que retorna um ponteiro:
*/
float* (*func2) (float, float);

// * Uma função que retorna aponta para funções que utilizam recebem 2 floats:

#include <stdio.h>

float plus( float a, float b) { return a + b; }

float minus( float a, float b) { return a - b; }

float times( float a, float b) { return a * b; }

float division( float a, float b) { return a / b; }

int main()
{
    float x, y;
    float (*operation)(float, float);
    
    scanf("%f %f", &x, &y);
    operation = plus;
 
    printf("%f + %f: %f\n", x, y, operation(x,y));
    operation = minus;
 
    printf("%f - %f: %f\n", x, y, operation(x,y));
    operation = times;
 
    printf("%f * %f: %f\n", x, y, operation(x,y));
    operation = division;
 
    printf("%f / %f: %f\n", x, y, operation(x,y));
    
    return 0;
}

// * Passando uma função como argumento a outra função

void ExecutaFuncao(float (*ptrFunc)(float, float))
{
 //^ execução da função apontada por ptrFunc
 float result = (*ptrFunc)(3.5, 2.7);
 printf("resultado da funcao: %.2f", result);
}
void ExecutaFuncoes()
{
 //^ passando por parâmetro a função
 ExecutaFuncao(&plus);
 ExecutaFuncao(&minus);
}
