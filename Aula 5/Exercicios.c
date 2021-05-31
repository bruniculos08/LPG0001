#include <stdio.h>


/* 
• Na linguagem C, existe a função pow que recebe dois valores e realiza o cálculo de
potenciação (exponenciação), ou seja, eleva o primeiro valor à potencia indicada pelo 
segundo e retorna a resposta calculada. Implemente uma função recursiva para
cálculo de exponenciação utilizando apenas operadores aritméticos de soma, subtração,
multiplicação e divisão.
*/

int power(int a, int n){
    if (n < 1){
        return 1;
    }

    return a * power(a, n-1);    
}

/* 
• Crie um programa em C que peça um número inteiro ao usuário e retorne a soma de todos os números 
de 1 até o valor informado pelo usuário, ou seja: 1+2+3+...+n. Utilize recursividade.
 */

int factorialsum(int n){
    if (n == 1) return 1;
    return n + factorialsum(n-1);
}

/* 
Faça uma função que calcule o n-ésimo termo da sequência de Fibonacci e depois refaça a função anterior usando recursividade.
f(1) = 1
f(2) = 1
f(n) = f(n-1) + f(n-2)
*/

int fibonacci(int n){
    if (n == 2 || n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}



int main(void){
    int a, b, i;
    printf("\n1-power \n2-factorialsum \n3-fibonacci \nChoose the function you want to use: ");
    scanf("%i", &i);
    
    switch (i)
    {
    case 1:
        printf("You chose power. Type the power (like a^b): ");
        scanf("%i^%i", &a, &b);
        printf("result = %i", power(a,b));
        break;
    case 2:
        printf("You chose factorialsum. Type the number: ");
        scanf("%i", &a);
        printf("result = %i", factorialsum(a));
        break;
    case 3:
        printf("You chose fibonacci. Type the number: ");
        scanf("%i", &a);
        printf("result = %i", fibonacci(a));
        break;
    default:
        printf("You chose an invalid function.");
        break;
    }
}