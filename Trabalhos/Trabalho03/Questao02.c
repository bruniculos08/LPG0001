#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    FILE *saida;

    saida = fopen("arquivoentrada01.txt","w");
    int number_lines; 
    printf("Type the number of lines: ");
    scanf("%i", &number_lines);
    int number_per_line[number_lines];
    
    for (int i = 0; i < number_lines; i++)
    {
        printf("Type the number of numbers at the line %i: ", i);
        scanf("%i", &number_per_line[i]);
    }

    int *list[number_lines];
    for (int i = 0; i < number_lines; i++)
    {
        list[i] = malloc(sizeof(int)*(number_per_line[i]+1));
        list[i][0] = number_per_line[i];
        fprintf(saida, "%i ", list[i][0]);
        for (int j = 1; j < number_per_line[i]+1; j++) {
            printf("Type the %i number (at line %i): ", j, i);
            scanf("%i", &list[i][j]);
            fprintf(saida, "%i ", list[i][j]);
        }
        fprintf(saida, "\n");
    }
}