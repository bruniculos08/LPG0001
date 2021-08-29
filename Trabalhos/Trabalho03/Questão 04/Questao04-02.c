#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    FILE *saida;

    saida = fopen("arquivoentrada01","w+b");
    int number_lines; 
    printf("Type the number of lines: ");
    scanf("%i", &number_lines);
    int number_per_line[number_lines];

    fseek(saida, 0, SEEK_SET);

    for (int i = 0; i < number_lines; i++)
    {
        printf("Type the number of numbers at the line %i (remember that a line that starts with 0 number is the same as end line): ", i);
        scanf("%i", &number_per_line[i]);
    }

    int *list[number_lines];
    for (int i = 0; i < number_lines; i++)
    {
        list[i] = malloc(sizeof(int)*(number_per_line[i]+1));
        list[i][0] = number_per_line[i];
        //fprintf(saida, "%i ", list[i][0]);
        fwrite(&list[i][0], sizeof(int), 1, saida);


        for (int j = 1; j < number_per_line[i]+1; j++) {

            printf("Type the %i number (at line %i): ", j, i);
            scanf("%i", &list[i][j]);
            fwrite(&list[i][j], sizeof(int), 1, saida);
        }
    }
    int last_line = 0;
    fwrite(&last_line, sizeof(int), 1, saida);
    //fprintf(saida, "0 0 0 0 0");
}