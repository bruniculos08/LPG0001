#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct horario {
    int hora, minuto;
} Horario;

typedef struct evento{
    Data data_evento;
    Horario hora_inicial, hora_final;
    char descricao[50], local[20];
} Evento;

Horario add_horario(int h){
    Horario nova_hora;
    if (h == 0)
    {
        printf("Type the inicial hour: ");
        do
        {
            scanf("%i", &nova_hora.hora);
        } while (nova_hora.hora > 23 || nova_hora.hora < 0);
        
        printf("Type the inicial minute: ");
        do
        {
            scanf("%i", &nova_hora.minuto);
        } while (nova_hora.minuto > 59 || nova_hora.minuto < 0);
        return nova_hora;
    }
    else if (h == 1){
        printf("Type the final hour: ");
        do
        {
            scanf("%i", &nova_hora.hora);
        } while (nova_hora.hora > 23 || nova_hora.hora < 0);
        
        printf("Type the final minute: ");
        do
        {
            scanf("%i", &nova_hora.minuto);
        } while (nova_hora.minuto > 59 || nova_hora.minuto < 0);
        return nova_hora;
    }
}

Evento add_evento(){

    Evento novo_evento;
    
    printf("Type the event year: ");
    scanf("%i", &novo_evento.data_evento.ano);
    
    printf("Type the event month: ");
    scanf("%i", &novo_evento.data_evento.mes);
    
    printf("Type the event day: ");
    scanf("%i", &novo_evento.data_evento.dia);

    novo_evento.hora_inicial = add_horario(0);
    novo_evento.hora_final = add_horario(1);

    printf("Type the event description: ");
    scanf("%s", novo_evento.descricao);

    printf("Type the event local: ");
    scanf("%s", novo_evento.local);

    return novo_evento;
}

/* void cadastrar(Evento *agenda){
    Evento novo_evento = add_evento();
    agenda = realloc(agenda, sizeof(*agenda) + sizeof(Evento));
    agenda[sizeof(*agenda)/sizeof(Evento)-1] = novo_evento;
} */

int compara_data(Evento evento_0, Evento evento_1){
    if (evento_0.data_evento.ano > evento_1.data_evento.ano) return 1;
    if (evento_0.data_evento.ano < evento_1.data_evento.ano) return 0;
    if (evento_0.data_evento.ano == evento_1.data_evento.ano){
        if (evento_0.data_evento.mes > evento_1.data_evento.mes) return 1;
        if (evento_0.data_evento.mes < evento_1.data_evento.mes) return 0;
        if (evento_0.data_evento.mes < evento_1.data_evento.mes) {
            if (evento_0.data_evento.dia > evento_1.data_evento.dia) return 1;
            if (evento_0.data_evento.dia < evento_1.data_evento.dia) return 0;
            if (evento_0.data_evento.dia == evento_1.data_evento.dia) {
                if (evento_0.hora_inicial.hora > evento_1.hora_inicial.hora) return 1;
                if (evento_0.hora_inicial.hora < evento_1.hora_inicial.hora) return 0;
                if (evento_0.hora_inicial.hora == evento_1.hora_inicial.hora) {
                    if (evento_0.hora_inicial.minuto > evento_1.hora_inicial.minuto) return 1;
                    if (evento_0.hora_inicial.minuto < evento_1.hora_inicial.minuto) return 0;
                    if (evento_0.hora_inicial.minuto == evento_1.hora_inicial.minuto) {
                        return 0;
                    }    
                }    
            }
        }
    }
}

Evento ordenar_vetor(Evento agenda[]){
    Evento aux_evento;
    printf("ordenando");
    for (int i = 0; i < (sizeof(*agenda)/sizeof(Evento)); i++)
    {
        for (int j = 0; j < (sizeof(*agenda)/sizeof(Evento)); j++)
        {
            if (compara_data(agenda[i], agenda[j]) == 1 && i!=j)
            {
                aux_evento = agenda[i];
                agenda[i] = agenda[j];
                agenda[j] = aux_evento;
            }
        }
    }
    return agenda[sizeof(*agenda)/sizeof(Evento)];
}

void todos_eventos(Evento *agenda){
    int exist = 1;
    for (int i = 0; i < sizeof(*agenda)/sizeof(Evento); i++){
        if (agenda == NULL) printf("Error, this schedule is empty.\n");
        else printf("Evento: %s\nLocal: %s\n", agenda[i].descricao, agenda[i].local);
    }
}

Evento cadastrar(Evento *agenda){
    Evento novo_evento = add_evento();
    agenda = realloc(agenda, sizeof(*agenda) + sizeof(Evento));
    agenda[sizeof(*agenda) + sizeof(Evento)-1] = novo_evento;
    *agenda = ordenar_vetor(agenda);
    return *agenda;
}

void remover(Evento *agenda, Data data_evento, Horario hora_inicial){
    Evento *nova_agenda;    
    nova_agenda = malloc(((sizeof(*agenda)/sizeof(Evento))-1)*sizeof(Evento));

    for (int i = 0, j = 0; i < (sizeof(*agenda)/sizeof(Evento)); i++){
        if (data_evento.dia == agenda[i].data_evento.dia && data_evento.mes == agenda[i].data_evento.mes && data_evento.ano == agenda[i].data_evento.ano && hora_inicial.hora == agenda[i].hora_inicial.hora && hora_inicial.minuto == agenda[i].hora_inicial.minuto){

        }
        else *(nova_agenda+i) = *(agenda+i);
    }
    free(agenda);
    agenda = malloc(((sizeof(*nova_agenda)/sizeof(Evento)))*sizeof(Evento));
    for (int i = 0; i < (sizeof(*nova_agenda)/sizeof(Evento)); i++) *(agenda+i) = *(nova_agenda+1);
    free(nova_agenda);
}

int main (void){
    FILE *arquivo_agenda;
    arquivo_agenda = fopen("teste.txt", "r+b");
    Evento *agenda = malloc(sizeof(Evento));

    if (arquivo_agenda == NULL){
        printf("Error\n");
    }
    else{
        for (int i = 0; i < sizeof(*agenda)/sizeof(Evento); i++) {
            fread(&agenda[i], sizeof(Evento), 1, arquivo_agenda);
            agenda = realloc(agenda, sizeof(*agenda) + sizeof(Evento));
        }
    }
    todos_eventos(agenda);
    fclose(arquivo_agenda);
    arquivo_agenda = fopen("teste.txt", "wb");
    fseek(arquivo_agenda, 0, SEEK_SET);

    *agenda = cadastrar(agenda);
    todos_eventos(agenda);

    
    printf("%s", agenda[0].descricao);
    for (int i = 0; i <= sizeof(*agenda)/sizeof(Evento); i++) fwrite(&agenda[i], sizeof(Evento), 1, arquivo_agenda);

}