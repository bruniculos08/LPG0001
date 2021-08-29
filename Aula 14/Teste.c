#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    FILE *entrada;
    entrada = fopen("arquivoentrada01.txt","rt");
    FILE *saida;
    saida = fopen("arquivosaida01.txt","w");

    int **v;
    v = malloc(sizeof(int));
    int total_linhas = 0, total_numeros, num_linha, linha = 0;

    do {
        fscanf(entrada, "%i ", &num_linha);         //* verificando quantos nº tem na linha
        if (num_linha == 0) break;                  //* se a linha tem 0 nºs então é a linha de final do arquivo


        v[linha] = malloc(num_linha * sizeof(int)); //* alocar nº de inteiros na linha
        v[linha][0] = num_linha;                    //* o primeiro nº de uma linha é o nº de nºs na linha
        printf("alocando na linha %i", num_linha); 

        for (int k = 1; k < num_linha; k++) {       //* adiciona os k nºs na linha
            fscanf(entrada, "%i", v[linha][k]);     
        }

        total_linhas = linha;
        linha++;                                    //* pulando para próxima linha
    } while (!feof(entrada));

    for(int i = 0; i < total_linhas; i++){          //* andando pelas linhas
        for(int j = 0; j < v[i][0]; j++){           //* andando pelosnúmero da linha nº i
            printf("%i", v[i][j]);
        }
    }
}