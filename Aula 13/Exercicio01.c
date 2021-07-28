#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct estrutura{
    char nome[10], email[20], telefone[11];
    
} Estrutura;


int main(){
    Estrutura Teste;
    strcpy(Teste.nome, "teste");

    FILE *saida;
    saida = fopen("arquivotextosaida", "a+b");

    fseek(saida, 0, SEEK_SET);
    fwrite(&Teste, sizeof(Estrutura), 1, saida); 

    Estrutura p;
    fseek(saida, 0, SEEK_SET);
    fread(&p, sizeof(Estrutura), 1, saida);

    printf("%s", p.nome);
}
