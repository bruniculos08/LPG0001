#include <stdio.h>
#include <string.h>

int main(void){
    FILE *entrada;
    entrada = fopen("arquivoentrada01.txt","rt");
    FILE *saida;
    saida = fopen("arquivosaida01.txt","w");

    int v[100], zeros = 0, numeros_por_linha[100], numeros_passados = 0, total_numeros, i = 0, j = 0, n;
    do                                     //& lê todos os números do arquivo e armazena no vetor
    {
        fscanf(entrada, "%i ", &v[i]);
        i++;
        total_numeros = i;
    }while(!feof(entrada));
    fclose(entrada);

    printf("\nTotal de numeros = %i\n", total_numeros);
    
    for (i = 0; i < total_numeros; i = i + v[i] + 1)
    {
        numeros_por_linha[j] = v[i];
        j++;
    }

    int total_linhas = j ;

    printf("Total de linhas = %i\n", total_linhas);

    for (i = 0, j = 0, n = numeros_por_linha[0]; i < total_numeros; i++){ 
        printf("%i ", v[i]);
        fprintf(saida, "%i ", v[i]);
        if (i == n)
        {
            printf("\n");
            j++;
            n = n + numeros_por_linha[j] + 1;
            fprintf(saida, "\n");
        }        
    }
}