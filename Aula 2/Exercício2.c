#include <stdio.h>


int main (void){
    int i = 0;
    float scores[3], average;
    for(i = 0; i <= 2; i++){
        printf("type the score %i: ", i);
        scanf("%f", &scores[i]);
        average = average + (scores[i]/3);
    }

    if(average < 6){
        printf("Aluno reprovado.");
    }
    else{
        printf("Aluno aprovado.");
    }
}