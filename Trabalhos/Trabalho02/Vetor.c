#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char aniversarianteMes(int dia, int mes);
char** vetor();

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct pessoa{
    char nome[50];
    Data nascimento;
} Pessoa;

int main(){
    char **p;
    p = vetor();
    printf("%s\n", &p[0][0]);
    printf("%s\n", &p[1][0]);
}

char **vetor(){
   char **vetorsup;                            // equivale à vetorsup[50][50]
                                               // vetor de ponteiros para ponteiro de strings
   vetorsup = malloc(sizeof(char *) * 50);     // endereço sup alocando memoria para 50 ponteiros de char

   for (int i = 0; i < 50; i++)                // 50 endereços de ponteiros de char alocando espaço para vetor de 50 char cada
   {                                           // ponteiro de ponteiro de char -> ponteiro de char -> vetor de char
       vetorsup[i] = malloc(sizeof(char) * 50);
   }
   strcpy(&vetorsup[0][0], "teste0");          // a string tem que ser escrita no início do vetor
   strcpy(&vetorsup[1][0], "teste1");          // ou seja endereço vetorsup[posicaoponteirodechar][posicaoinicialdastring] 

   return vetorsup;                           // retorna o endereço do vetor de ponteiros de ponteiros de char
} 