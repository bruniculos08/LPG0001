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
    saida = fopen("arquivotextosaida", "w+b"); //^Sobrescreve arquivo "arquivotextosaida", com endereço armazenado na variavel "saida" 

    fseek(saida, 0, SEEK_SET);                  //^ coloca o leitor na posição 0 em relação ao início (SEEK_SET) 
    fwrite(&Teste, sizeof(Estrutura), 1, saida);//^ Escreve o que está no endereço de Teste ou seja, a variável teste, que tem temanho de uma Estrutura,
                                                //^ no arquivo de endereço armazenado em "saida"

    Estrutura p;                                //^ variável p do tipo estrutura
    fseek(saida, 0, SEEK_SET);                  //^ coloca o leitor na posição 0 em relação ao início (SEEK_SET)
    fread(&p, sizeof(Estrutura), 1, saida);     //^ copia para a variável "p" o que está sendo lido no arquivo de endereço armazenado em saida
                                                //^ tendo esse algo o tamanho de uma estrutura (1)

    printf("%s", p.nome);                       //^ printa algo(nome) da estrutura que foi copiada para a variável "p"
}
