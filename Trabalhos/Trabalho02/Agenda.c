//? usar getchar() antes de fgets(...) se der problema
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct endereco{
    char rua[40], numero[5], complemento[20], bairro[20], cep[20], cidade[20], estado[20], pais[20];
} Endereco;

typedef struct telefone{
    int DDD;
    char numero[9];
} Telefone;

typedef struct pessoa{
    char nome[50], email[50];
    Telefone telefone;
    Data nascimento;
    Endereco endereco;
} Pessoa;

Pessoa *p;
int n;

void buscaDados(char nome[]);
void imprimeAniversarianteDia(int dia, int mes);
void imprimeAniversarianteMes(int mes);
void inserePessoa();
void removePessoa(char nome[]);

int main(){
    printf("Type the number of people: ");
    scanf("%i", &n);
    p = malloc(n*sizeof(Pessoa));
    for (int i = 0; i < n; i++){
        printf("Type the name: ");
        scanf("%s", (p+i)->nome);
        printf("Type the day: ");
        scanf("%i", &(p+i)->nascimento.dia);
        printf("Type the month: ");
        scanf("%i", &(p+i)->nascimento.mes);
        printf("Type the year: ");
        scanf("%i", &(p+i)->nascimento.ano);
        printf("Type the DDD: ");
        scanf("%i", &(p+i)->telefone.DDD);
        printf("Type the telefone number: ");
        scanf("%s", (p+i)->telefone.numero);
        printf("Type the street: ");
        scanf("%s", (p+i)->endereco.rua);
        printf("Type the number: ");
        scanf("%s", (p+i)->endereco.numero);
        printf("Type the complement: ");
        scanf("%s", (p+i)->endereco.complemento);
        printf("Type the neighbourhood: ");
        scanf("%s", (p+i)->endereco.bairro);
        printf("Type the CEP: ");
        scanf("%s", (p+i)->endereco.cep);
        printf("Type the city: ");
        scanf("%s", (p+i)->endereco.cidade);
        printf("Type the state: ");
        scanf("%s", (p+i)->endereco.estado);
        printf("Type the country: "); 
        scanf("%s", (p+i)->endereco.pais);
        printf("Type the email: ");
        scanf("%s", (p+i)->email);
    }

    int option;
    
    do
    {
        char nome[50];
        int dia, mes;

        printf("\nOptions(type the number):\n0. Search somebody \n1. Insert somebody\n2. Remove somebody\n3. Month Birthdays\n4. Day Birthdays\n5. Exit\n");
        scanf("%i", &option);
        
        switch (option){
        case 0: printf("Type the name: "); scanf("%s", nome); buscaDados(nome); break;
        case 1: inserePessoa(); option = 0; break;
        case 2: printf("Type the name: "); scanf("%s", nome); removePessoa(nome); option = 0; break;
        case 3: printf("Type the month: "); scanf("%i", &mes); imprimeAniversarianteMes(mes); option = 0; break;
        case 4: printf("Type the day: "); scanf("%i", &dia); printf("Type the month: "); scanf("%i", &mes); imprimeAniversarianteDia(dia, mes); option = 0; break;
        case 5: break;
        }
    } while (option < 1 || option > 5);
    

    for (int i = 0; i < n; i++){
        printf("%s\n", (p+i)->nome);
    }
}

void buscaDados(char nome[]){ 
    printf("\nResult:\n");
    for (int i = 0; i < n; i++){
        if (strcmp((p+i)->nome, nome) == 0) 
        {
            printf("%s\n", (p+i)->nome);
            printf("%s\n", (p+i)->email);
            printf("%i %s\n", (p+i)->telefone.DDD, (p+i)->telefone.numero);
        }
    }
}

void imprimeAniversarianteMes(int mes){
    //n = sizeof(p)/sizeof(Pessoa);
    for (int i = 0; i < n; i++)
    {
        if((p+i)->nascimento.mes == mes){
            printf("%s\n", (p+i)->nome);
        }
    }
}

void imprimeAniversarianteDia(int dia, int mes){
    //n = sizeof(p)/sizeof(Pessoa);
    for (int i = 0; i < n; i++)
    {
        if((p+i)->nascimento.mes == mes && (p+i)->nascimento.dia == dia){
            printf("%s\n", (p+i)->nome);
        }
    }
}

void inserePessoa(){
        n = n+1;
        p = realloc(p, n*sizeof(Pessoa));
        printf("Type the name: ");
        scanf("%s", (p+n-1)->nome);
        printf("Type the day: ");
        scanf("%i", &(p+n-1)->nascimento.dia);
        printf("Type the month: ");
        scanf("%i", &(p+n-1)->nascimento.mes);
        printf("Type the year: ");
        scanf("%i", &(p+n-1)->nascimento.ano);
}

void removePessoa(char nome[]){
    Pessoa *newp;
    newp = malloc((n-1) * sizeof(Pessoa));

    for (int i = 0, j = 0; i < n; i++)
    {   
        if (strcmp((p+i)->nome, nome)){
            *(newp+j) = *(p+i);
            j++;
        }
        else {
            free(p+i);
        }
    }
    //for (int i = 0; i < n; i++) free(p+i);
    free(p);
    p = malloc((n-1) * sizeof(Pessoa));
    for (int i = 0; i < n-1; i++) *(p+i) = *(newp+i);
    free(newp);
    n = n-1;
}