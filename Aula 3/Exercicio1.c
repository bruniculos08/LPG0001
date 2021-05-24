#include <stdio.h>


/* 
1.) Faça um programa que leia dois números inteiros. O
primeiro é o valor inicial de um contador, e o segundo é o
valor final do contador (o valor inicial fornecido é inferior
ao valor final). Usando o comando while, escreva na tela
uma contagem que comece no primeiro número lido,
escreva os números seguintes colocando apenas um número
em cada nova linha da tela, até chegar ao valor final
indicado.
 */


int main(void){
    int x, y; // initial value, final value

    printf("Type the initial and final value (type in order like: x, y): ");
    scanf("%i, %i", &x, &y);

    while (x <= y){
        printf("%i\n", x);
        ++x; // some people say that writing "++i" in order to "i++" is better to compile(faster) 
    }

}