#include <stdio.h>

 
 int main(void){
// & Conversão de tipos 
    
// ^ 1) Entre tipos que armazenam uma quantidade diferente de bytes

/*  
*    • No código abaixo, ao escrever i = w, essa não é uma
*    atribuição comum, pois o compilador precisa gerar
*    código extra para converter o char para int. Esta
*    conversão é feita de maneira implícita e silenciosa pelo
*    compilador porque qualquer valor de char pode ser
*    armazena em um int. */

    int i; 
    char w;
    w = 64; 
    printf("\nw = %c", w);
    i = w;
    printf("\ni = %i", i);

/*  
*    • Ao se escrever w = i, alguns compiladores gerarão aviso
*    indicando a perda de informação, isto porque
*    normalmente valores de int (4 bytes) não podem
*    armazenados em um char de apenas 1 byte. */

    i = 64321;
    printf("\ni = %i", i);
    w = i;
    printf("\nw = %c", w);
    
    
// & Operações com números inteiros 

// ^ 1) Modo com erro de precisão devido a diferentes tipos

    int a, b;
    a = 4;
    b = 7;
    float x;
    x = (a+b)/2;
    printf("\nx = %f", x);

// ^ 2) Modo sem erro devido a diferentes tipos:

    x = (float)(a+b)/2;
    printf("\nx = %f", x);

// & Operações com números reais

/*
*   • Devido ao problema em relação à precisão dos tipos usados pelo computador, também
*    é preciso tomar cuidado com valores reais, principalmente em relação à comparação (condição de if's, while's, for,...). */

    if (1.8 == (1.8/3.0)*3.0)
    printf("Iguais");
    else
    printf("Diferentes");

/*
*  • Para resolver esse problema, em vez de fazer a comparação com igualdade, verifica-se se a diferença entre ambos os
*  valores é mínima. Esta diferença dependerá da precisão desejada na aplicação. */
    
//   ~ fabs (indica módulo)

    if (fabs(1.8 - (1.8/3.0)*3.0) < 0.00001)
    printf("Iguais");
    else
    printf("Diferentes");

//& Operador Ternário

//~ Exp1 ? Exp2 : Exp3
/* 
*   • Se Exp1 é verdadeira, o resultado da expressão é Exp2.
*   • Se Exp1 é falsa, o resultado da expressão é Exp3.  */

    int e, h, maior, menor;
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &e, &h);
    maior = (e>h) ? e : h;
    menor = (e<h) ? e : h;
    printf("%d é maior e %d é menor.\n", maior, menor);
    
//& Operador Switch

/*
~    switch(expressão){
~       case constante1:
~           comandos;
~       break;
~       case constante2:
~           comandos;
~       break;
~       ...
~       default:
~           comandos; 
~    }

*   • Valor da expressão testado, na ordem, contra os valores das
*   constantes especificados nos comandos case.
    • Quando encontrar coincidência, os comandos associados ao
    case são executados.
    • Comando default é executado se nenhuma coincidência for
    detectada.
*   • Default é opcional.
    • Comando switch, diferente do if, só pode testar igualdade.
*   • Duas constantes case no mesmo switch não podem ter valores
*   idênticos.
*   • Constantes de caracteres em um switch são automaticamente
*   convertidas para seus valores inteiros.
*/
}