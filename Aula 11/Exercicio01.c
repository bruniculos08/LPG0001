#include <stdio.h>


typedef struct 
{
    int idade, numero_filhos;
    float salario;
    char sexo;
} Pessoa;

int main(){
    Pessoa entrevistados[20];

    for (int i=0; i < 20; i++){
        printf("Type the age number: ");
        scanf("%i", &entrevistados[i].idade);
        printf("Type the salary: ");
        scanf("%i", &entrevistados[i].salario);
        //printf("Type the")
    }
}
