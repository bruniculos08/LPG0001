#include <stdio.h>


/* • Calcular a média das notas de uma turma. 
Entrada do programa: o número de alunos da turma e as notas dos alunos. */


int main(void){
    int n;
    double average, score;

    printf("Type the numeber of students: ");
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Type the score of the student number %i: ", i+1);
        scanf("%lf", &score);

        average += (score/n);

    }
    

    printf("The average score is: %lf", average);
}