#include <stdio.h>


int main() {
    float exam, average = 0, N[4], Weights[4] = {2, 3, 4, 1};
 
    int i = 0;
    while(i < 4){
        scanf("%f", &N[i]); //um vetor não deveria precisar de "&" pois já é um endereço, certo?
        average += ((Weights[i]*N[i])/10.0)-0.001;
        i++;
    }
    printf("Media: %.1f", average);
    if (average >= 7) printf("\nAluno aprovado.\n");
    else if (average+0.01 < 5) printf("\nAluno reprovado.\n");
    else {
        printf("\nAluno em exame.");
        printf("\nNota do exame: ");

        scanf("%f", &exam);
        average = ((average+exam)/2.0);
        if (average >= 5) printf("Aluno aprovado.\n");
        else printf("Aluno reprovado.\n");
        printf("Media final: %.1f\n", average);
    }
    
    return 0;
}