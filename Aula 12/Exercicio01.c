#include <stdio.h>
#include <string.h>

int ordenavetor(int v);

int main(){
    FILE *entrada;
    
    entrada = fopen("arquivotexto.txt", "rt");
    if(entrada == NULL) printf("Error");

    FILE *saida;
    saida = fopen("arquivotextosaida.txt", "w");
    int v[10], i = 0;

    while(!feof(entrada)){
        fscanf(entrada, "%i", &v[i]);
        i++;
    }
    
    fclose(entrada);
    for (i = 0; i<10; i++){
        fprintf(saida," %i", v[i]);
    }
}

//int ordenavetor