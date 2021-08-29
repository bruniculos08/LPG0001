#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    FILE *entrada;
    entrada = fopen("arquivoentrada01.txt","rt");
    FILE *saida;
    saida = fopen("arquivosaida01.txt","w");

    int *v;
    v = malloc(sizeof(int));
    int total_linhas = 0, total_numeros, num_linha, posicao_num = 0;

    do                                              //* lê todos os números do arquivo e armazena no vetor
    {
        fscanf(entrada, "%i ", &v[posicao_num]);
        posicao_num++;
        v = realloc(v, (posicao_num+1)*sizeof(int));
        printf("realocando com tamanho %i\n", posicao_num);
        total_numeros = posicao_num;

    } while(!feof(entrada));
    fclose(entrada);


    int *numeros_por_linha;
    int *positive_numbers;
    int *negative_numbers;

    numeros_por_linha = malloc(100*sizeof(int));
    positive_numbers = malloc(sizeof(int));
    negative_numbers = malloc(sizeof(int));

    for (int i = 0, j = 0; i < total_numeros; i = i + v[i] + 1) {
        
        numeros_por_linha[j] = v[i];
        numeros_por_linha = realloc(numeros_por_linha, (1+i)*sizeof(int));

        if (numeros_por_linha[j] == 0) break;

        else if (numeros_por_linha[j] != 0) {
            positive_numbers[j] = 0;
            negative_numbers[j] = 0;
            
            for(int k = 0; k < v[i]; k++) {
                if (v[i+k+1] > 0) positive_numbers[j]++;
                if (v[i+k+1] < 0) negative_numbers[j]++;
            }

            
            j++;
            positive_numbers = realloc(positive_numbers, (j+1)*sizeof(int));   
        }
        total_linhas = j;
    }

    for (int i = 0; i < total_linhas; i++) { 
        printf("%i negativos e %i positivos\n", negative_numbers[i], positive_numbers[i]);
        fprintf(saida, "%i negativos e %i positivos\n", negative_numbers[i], positive_numbers[i]);
    }

    free(v);
    free(numeros_por_linha);
    free(positive_numbers);
    free(negative_numbers);

}