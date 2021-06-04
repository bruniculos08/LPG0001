#include <stdio.h>


int main() {
    float exam, average = 0, N[4], Weights[4] = {2, 3, 4, 1};
    
    int i;
    for(i = 0; i < 4; i++){
        scanf("%f", N+i); //scanf("%f", N[i]); //um vetor não deveria precisar de "&" pois já é um endereço, certo?
        average += ((Weights[i]*N[i])/10.0)-0.001;
    }
    printf("Media: %.1f\n", average);
    if (average >= 7) printf("Aluno aprovado.\n");
    else if (average+0.01 < 5) printf("Aluno reprovado.\n"); //somando 0.01 devido ao arredondamento
    else {
        printf("Aluno em exame.\n");
        scanf("%f", &exam);
        printf("Nota do exame: %.1f\n", exam);
        average = ((average+exam)/2.0);
        if (average >= 5) printf("Aluno aprovado.\n");
        else printf("Aluno reprovado.\n");
        printf("Media final: %.1f\n", average);
    }
    return 0;
}