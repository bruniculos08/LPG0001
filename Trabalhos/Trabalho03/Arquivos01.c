#include <stdio.h>
#include <string.h>

int main(void){
    FILE *entrada;
    entrada = fopen("arquivoentrada01.txt", "rt");
    FILE *saida;
    saida = fopen("arquivosaida01.txt","w");

    int n[100], i = 0;
    do
    {
        fscanf(entrada, "%i ", &n[i]);
        i++;
    } while (!feof(entrada));
    
}