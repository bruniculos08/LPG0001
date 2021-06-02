#include <stdio.h>


/* 
• Fazer um programa para ler um vetor (matriz
unidimensional) de 8 números inteiros. Imprimir na tela 
os conteúdos do vetor lido. 
*/

int lermatriz(void){
    int vector[8];
    printf("Type the vector: ");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", vector[i]);
    }
    for (int i = 0; i < 8; i++){
        printf("%d", vector[i]);
    }
}

/* 
Altere o primeiro exercício para também
mostrar a soma de seus elementos e apresentar quantos deles são positivos. 
*/

int summatriz(void){
    int vector[8], sum;
    printf("Type the vector: ");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", vector[i]);
    }
    for (int i = 0; i < 8; i++){
        sum += vector[i];
        printf("%d", vector[i]);
    }
    printf("\nsum = %d", sum);
}

int bigger(void){
    int vector[8];
    printf("Type the vector: ");
    for (int bigger = vector[0], i = 0; i < 8; i++)
    {   
        scanf("%d", vector[i]);
        if (bigger < vector[i]) bigger = vector[i];
    }
    printf("bigger = %i", bigger);
}


/* 
Escrever um algoritmo que leia dois vetores
de 5 posições e calcule o produto escalar entre
os dois vetores escrevendo a resposta. 
*/

int scalar_prod(void){
    int vector1[5], vector2[5];
    printf("Type the vector1: ");
    for (int i = 0; i < 5; i++)
    {   
        scanf("%d", vector1[i]);
    }

    printf("Type the vector2: ");
    for (int i = 0; i < 5; i++)
    {   
        scanf("%d", vector2[i]);
    }

}