#include <stdio.h>
#include <string.h>

void change_words(char *a, char *b){
    char aux[100];
    strcpy(aux, a);
    strcpy(a, b);
    strcpy(b, aux); // mas por que do outro jeito não funciona?
}

int main(void) {
    char words[10][100];                                  //* 4 strings de 20 caracteres no maximo
    for(int i = 0; i < 10; i++) gets(words[i]);          //* recebe cada string
    change_words(words[0], words[1]);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++){
            if (strcmp(words[i], words[j]) == 0) j++; 
            else if(strcmp(words[i], words[j]) > 0 && i < j) change_words(words[i], words[j]); //& strcmp(str1, str2); 
            else if(strcmp(words[i], words[j]) < 0 && i > j) change_words(words[i], words[j]); //^ é maior que zero se ordem da string1 maior que da string2
        }                                                                                      //^ é menor que zero se ordem da string1 menor que da string2
    }
    for(int i = 0; i < 10; i++) printf("%s ", words[i]);
}

/* 
~ RESUMO:
^   *p1 é o que está no endereço apontado (ou seja indica o conteúdo).
^   p1 é o número do endereço, & é um operador para obter um endereço. 
^   a declaração <tipo> *<nome do ponteiro> armazena um endereço. 

p1 = p2;

• Esse exemplo fará com que p1 aponte para o mesmo lugar que p2. Ou seja, 
usar p1 será equivalente a usar p2 após essa atribuição.

*p1 = *p2;

• Nesse caso, estamos igualando os valores apontados 
pelos dois ponteiros: alteraremos o valor apontado por p1 para o valor 
apontado por p2
*/